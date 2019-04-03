#include <QDateTime>
#include <QDebug>
#include "Windows.h"
#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::WindowFlags type)
    //setWindowFlag(Qt::WindowType flag, bool on = true)
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
    setWindowFlag(Qt::WindowStaysOnTopHint);

        connect(qApp,SIGNAL(applicationStateChanged(Qt::ApplicationState)),this,SLOT(m_ApplicationStateChange(Qt::ApplicationState)));

    m_RaiseWindowsTimer = new QTimer(this);
    connect(m_RaiseWindowsTimer,SIGNAL(timeout()),this,SLOT(m_RaiseTimerOver()));
    m_RaiseWindowsTimer->start(10000);

    initVW();
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

void MainForm::m_vw_saveLoc(const QString &id, const QPoint &p, const QSize &s)
{
    m_setting->beginGroup(id);
    m_setting->setValue(INI_POS,p);
    m_setting->setValue(INI_SIZE,s);
    m_setting->endGroup();
}

void MainForm::m_vw_loadLoc(vedioWidget *vw)
{
    m_setting->beginGroup(vw->getWidgetId());
    vw->move(m_setting->value(INI_POS).toPoint());
    vw->resize(m_setting->value(INI_SIZE).toSize());
    m_setting->endGroup();
}

void MainForm::m_vw_channelNames(const QString &id, const QStringList &names)
{
    m_setting->beginGroup(id);
    m_setting->setValue(INI_CHANNEL_NAMES,names);
    m_setting->endGroup();
}

void MainForm::initVW()
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
            m_setting->setValue(INI_CHANNEL_ID,INI_CHANNEL_ID_DEF);
        }
        vedioWidgetRef ref;
        ref.host      = m_setting->value(INI_HOST,INI_HOST_DEF).toString();
        ref.id        = id;
        ref.name      = m_setting->value(INI_NAME,INI_NAME_DEF).toString();
        ref.port      = m_setting->value(INI_PORT,INI_PORT_DEF).toUInt();
        ref.pwd       = m_setting->value(INI_PWD,INI_PWD_DEF).toString();
        ref.title     = m_setting->value(INI_TITLE,INI_TITLE_DEF).toString();
        ref.channelId = m_setting->value(INI_CHANNEL_ID,INI_CHANNEL_ID_DEF).toUInt();
        vedioWidget *vw = new vedioWidget(ref);
        connect(this,SIGNAL(m_close()),vw,SLOT(close()));//主窗口退出，其它一起退出
        connect(vw,SIGNAL(m_signals_loadLoc(vedioWidget *)),this,SLOT(m_vw_loadLoc(vedioWidget *)));
        connect(vw,SIGNAL(m_signals_saveLoc(const QString&,const QPoint&,const QSize&)),this,SLOT(m_vw_saveLoc(const QString&,const QPoint&,const QSize&)));
        connect(vw,SIGNAL(m_signals_channelNames(const QString&,const QStringList&)),this,SLOT(m_vw_channelNames(const QString&,const QStringList&)));
        vw->show();

        m_setting->endGroup();
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
    qDebug()<<"timer over";
    HWND  h = GetTopWindow(nullptr);
    if(h != (HWND)winId()){
        this->activateWindow();
        this->raise();
    }
}

void MainForm::m_ApplicationStateChange(Qt::ApplicationState state)
{
    qDebug()<<state;
}
