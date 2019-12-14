#include <QDateTime>
#include <QDebug>
#include "Windows.h"
#include "tlhelp32.h"
#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::WindowFlags type)
    //setWindowFlag(Qt::WindowType flag, bool on = true)
    setWindowFlags((windowFlags() & ~Qt::WindowMinMaxButtonsHint) | Qt::WindowStaysOnTopHint);
    //setWindowFlag(Qt::WindowStaysOnTopHint);

    connect(qApp,SIGNAL(applicationStateChanged(Qt::ApplicationState)),this,SLOT(m_ApplicationStateChange(Qt::ApplicationState)));

    m_RaiseWindowsTimer = new QTimer(this);
    connect(m_RaiseWindowsTimer,SIGNAL(timeout()),this,SLOT(m_RaiseTimerOver()));
    m_RaiseWindowsTimer->start(5000);

    readIni();
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::closeEvent(QCloseEvent *event)//点击标题栏关闭不退出，只有点击退出按钮时才退出
{
    this->setWindowState(Qt::WindowMinimized);
    if(!isRealQuit)
        event->ignore();
}

void MainForm::m_vw_saveLoc(vedioWidget *vw, const QPoint &p, const QSize &s)
{
    QString curGroup = m_setting->group();
    m_setting->endGroup();

    m_setting->beginGroup(vw->getIniGroupId());
    if(vw->getDevType()==DEV_TYPE_IPC){
        m_setting->setValue(INI_POS,p);
        m_setting->setValue(INI_SIZE,s);
    }else if (vw->getDevType()==DEV_TYPE_NVR) {
        QList<QVariant> VL_size = m_setting->value(INI_SIZE).toList();
        QList<QVariant> VL_pos = m_setting->value(INI_POS).toList();
        if(VL_size.size() >= m_setting->value(INI_NUM).toInt()
                && VL_pos.size() >= m_setting->value(INI_NUM).toInt()){
            VL_size[static_cast<int>(vw->getNvrChn())] = s;
            VL_pos[static_cast<int>(vw->getNvrChn())] = p;
        }
        m_setting->setValue(INI_SIZE,VL_size);
        m_setting->setValue(INI_POS,VL_pos);
    }
    m_setting->endGroup();

    m_setting->beginGroup(curGroup);
}

void MainForm::m_vw_loadLoc(vedioWidget *vw)
{
    QString curGroup = m_setting->group();
    m_setting->endGroup();

    m_setting->beginGroup(vw->getIniGroupId());
    if(vw->getDevType()==DEV_TYPE_IPC){
        vw->move(m_setting->value(INI_POS).toPoint());
        vw->resize(m_setting->value(INI_SIZE).toSize());
    }else if (vw->getDevType()==DEV_TYPE_NVR) {
        QList<QVariant> VL_size = m_setting->value(INI_SIZE).toList();
        QList<QVariant> VL_pos = m_setting->value(INI_POS).toList();
        if(VL_size.size() >= m_setting->value(INI_NUM).toInt()
                && VL_pos.size() >= m_setting->value(INI_NUM).toInt()){
            vw->resize(VL_size[static_cast<int>(vw->getNvrChn())].toSize());
            vw->move(VL_pos[static_cast<int>(vw->getNvrChn())].toPoint());
        }
    }
    m_setting->endGroup();

    m_setting->beginGroup(curGroup);
}

void MainForm::m_vw_login(vedioWidget *vw)
{
    QString curGroup = m_setting->group();
    m_setting->endGroup();

    m_setting->beginGroup(vw->getIniGroupId());
    if(m_setting->value(INI_NAMES).toStringList()!=vw->getNames())
        m_setting->setValue(INI_NAMES,vw->getNames());
    if(m_setting->value(INI_NUM).toInt()!=vw->getNames().size())
        m_setting->setValue(INI_NUM,vw->getNames().size());
    m_setting->endGroup();

    m_setting->beginGroup(curGroup);
}

void MainForm::m_vw_recentedClicked(vedioWidget *vw)
{
    if(list.removeOne(vw)){
        list.append(vw);
    }
}

void MainForm::readIni()
{
    //QSettings的key、childGroups无法为中文
    m_setting = new QSettings(QCoreApplication::applicationDirPath()+"/set.ini",QSettings::IniFormat);
    m_setting->setIniCodec("UTF-8");

    QStringList IniWidgetIdList= m_setting->value(INI_ID_LIST).toStringList();//根据INI_ID_LIST初始化 静态列表
    if(IniWidgetIdList.isEmpty()){//表格为空
        IniWidgetIdList.append(QString("default"));
    }

    //对childGroups没有的 初始化
    QStringList iniIdList = m_setting->childGroups();//对于
    foreach (QString id, IniWidgetIdList) {
        m_setting->beginGroup(id);

        if(!iniIdList.contains(id)){
            m_setting->setValue(INI_HOST,INI_HOST_DEF);
            m_setting->setValue(INI_NAME,INI_NAME_DEF);
            m_setting->setValue(INI_PWD,INI_PWD_DEF);
            m_setting->setValue(INI_PORT,INI_PORT_DEF);
            m_setting->setValue(INI_TITLE,INI_TITLE_DEF);
            m_setting->setValue(INI_IPC_LEVEL,INI_IPC_LEVEL_DEF);
            m_setting->setValue(INI_DEV_TYPE,INI_DEV_TYPE_DEF);
        }
        vedioWidgetRef ref;
        ref.host      = m_setting->value(INI_HOST,INI_HOST_DEF).toString();
        ref.IniGroupId        = id;
        ref.name      = m_setting->value(INI_NAME,INI_NAME_DEF).toString();
        ref.port      = m_setting->value(INI_PORT,INI_PORT_DEF).toUInt();
        ref.pwd       = m_setting->value(INI_PWD,INI_PWD_DEF).toString();
        ref.title     = m_setting->value(INI_TITLE,INI_TITLE_DEF).toString();
        ref.devType   = m_setting->value(INI_DEV_TYPE,INI_DEV_TYPE_DEF).toString();
        if(ref.devType==DEV_TYPE_NVR){
            int num = m_setting->value(INI_NUM).toInt();
            QList<QVariant> list_levels =  m_setting->value(INI_NVR_LEVELs).toList();
            QList<QVariant> list_shows =  m_setting->value(INI_NVR_SHOWs).toList();
            if(list_levels.size()<num || list_shows.size()<num){
                qDebug()<<"配置错误:"<<ref.IniGroupId;
            }else{
                for(int i=0;i<num;i++){
                    if(list_shows.at(i).toBool()==INI_SHOW_TRUE){
                        ref.nvr_chn = static_cast<uint>(i);
                        ref.level = list_levels.at(i).toUInt();
                        initVW(ref);
                    }
                }
            }
        }else if(ref.devType==DEV_TYPE_IPC && m_setting->value(INI_IPC_SHOW).toBool()==INI_SHOW_TRUE){
            ref.level = m_setting->value(INI_IPC_LEVEL,INI_IPC_LEVEL_DEF).toUInt();
            initVW(ref);
        }
        m_setting->endGroup();
    }//end foreach
}

void MainForm::initVW(vedioWidgetRef ref)
{
    vedioWidget *vw = new vedioWidget(ref);
    list.append(vw);
    if(vw->isLogin()){
        connect(this,SIGNAL(m_close()),vw,SLOT(close()));//主窗口退出，VM一起退出
        connect(vw,SIGNAL(m_signals_loadLoc(vedioWidget *)),this,SLOT(m_vw_loadLoc(vedioWidget *)));
        connect(vw,SIGNAL(m_signals_saveLoc(vedioWidget *,const QPoint&,const QSize&)),this,SLOT(m_vw_saveLoc(vedioWidget *,const QPoint&,const QSize&)));
        connect(vw,SIGNAL(m_signals_login(vedioWidget *)),this,SLOT(m_vw_login(vedioWidget *)));
        connect(vw,SIGNAL(m_signals_mousePress(vedioWidget*)),this,SLOT(m_vw_recentedClicked(vedioWidget*)));
        m_vw_loadLoc(vw);
        vw->show();
        vw->start();
    }else{
        vw->close();
    }
}

void MainForm::on_pushButtonQuit_clicked()
{
    emit m_close();
    isRealQuit=true;
    this->close();
}

void MainForm::m_RaiseTimerOver()
{
    if(GetForegroundWindow()!=reinterpret_cast<HWND>(winId())){
        qDebug()<<"timer over and activateWindow";
        foreach(vedioWidget* vw,list){
            //qDebug()<<vw->windowFlags();
            vw->activateWindow();
            vw->raise();
        }

        this->activateWindow();
        this->raise();
    }
}

void MainForm::m_ApplicationStateChange(Qt::ApplicationState state)
{
    Q_UNUSED(state);
//    qDebug()<<state;
}

/*
//增加了过滤的版本：基本正确
BOOL CALLBACK lpEnumFunc(HWND h, LPARAM lParam)
{
    if (GetWindow(h,GW_OWNER)) return TRUE;
    if (!IsWindowVisible(h)) return TRUE;
    TCHAR cls[256];
    GetClassName(h,cls,256);
    if (QString::fromWCharArray(cls)==QString("Shell_TrayWnd")) return TRUE;
    if (QString::fromWCharArray(cls)==QString("Progman")) return TRUE;
    if (GetWindowTextLength(h)==0) return TRUE;
//    if (QString::fromWCharArray(cls)==QString("ApplicationFrameWindow")) return TRUE;//计算机不能显示
    if (QString::fromWCharArray(cls)==QString("Windows.UI.Core.CoreWindow")) return TRUE;

    DWORD ldwProID;
    DWORD dwTheardId = GetWindowThreadProcessId( h,&ldwProID);
    if (dwTheardId != 0)
    {
        HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 procinfo;
        procinfo.dwSize = sizeof(PROCESSENTRY32);
        BOOL more=::Process32First(handle,&procinfo);
        while(more)
        {
            if(procinfo.th32ProcessID==ldwProID)
            {
                TCHAR  tmp[100];
                GetWindowText(h,tmp,100);
                qDebug()<<QString::fromWCharArray( procinfo.szExeFile)<<" "<<ldwProID<<" "<<h <<
                          QString::fromWCharArray(cls)<<
                          GetWindow(h,GW_HWNDFIRST)<<GetWindow(h,GW_HWNDLAST)<<
                          GetWindow(h,GW_HWNDNEXT)<<GetWindow(h,GW_HWNDPREV)<<
                          IsWindow(h)<<IsWindowEnabled(h)<< (GetWindowLong(h, GWL_STYLE) & WS_VISIBLE)<<
                          " "<<GetWindowTextLength(h)<<QString::fromWCharArray(tmp);
                CloseHandle(handle);
                break;
            }
            more=Process32Next(handle,&procinfo);
        }
    }

    return 1;
}
*/
/*
    qDebug()<<winId();
    qDebug()<<GetForegroundWindow();//当前激活的窗口
    HWND  h = GetTopWindow(nullptr);//顶层窗口：很多
    if(h != reinterpret_cast<HWND>(winId())){
        qDebug()<<"timer over and activateWindow";
        this->activateWindow();
        this->raise();
    }
    qDebug()<<GetForegroundWindow();
    h = GetTopWindow(nullptr);
    while ( h )
    {
        DWORD ldwProID;
        DWORD dwTheardId = GetWindowThreadProcessId( h,&ldwProID);
        if (dwTheardId != 0)
        {
            HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
            PROCESSENTRY32 procinfo;
            procinfo.dwSize = sizeof(PROCESSENTRY32);
            BOOL more=::Process32First(handle,&procinfo);
            while(more)
            {
                if(procinfo.th32ProcessID==ldwProID)
                {
                    qDebug()<<QString::fromWCharArray( procinfo.szExeFile)<<" "<<ldwProID<<" "<<h;
                    CloseHandle(handle);
                    break;
                }
                more=Process32Next(handle,&procinfo);
            }
        }
        h = GetNextWindow( h , GW_HWNDNEXT);
    }
 * */
/*
BOOL CALLBACK lpEnumFunc(HWND h, LPARAM lParam)
{
    DWORD ldwProID;
    DWORD dwTheardId = GetWindowThreadProcessId( h,&ldwProID);
    if (dwTheardId != 0)
    {
        HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 procinfo;
        procinfo.dwSize = sizeof(PROCESSENTRY32);
        BOOL more=::Process32First(handle,&procinfo);
        while(more)
        {
            if(procinfo.th32ProcessID==ldwProID)
            {
                qDebug()<<QString::fromWCharArray( procinfo.szExeFile)<<" "<<ldwProID<<" "<<h;
                CloseHandle(handle);
                break;
            }
            more=Process32Next(handle,&procinfo);
        }
    }
    return 1;
}

    EnumWindows(lpEnumFunc,NULL);
 */
