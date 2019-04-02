#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QStringList>
#include <QDateTime>
#include <QTimer>
#include "vediowidget.h"
#include "testform.h"

#include "Windows.h"

#include "inc/NS_NET.h"
#include "inc/NS_MP4.h"
#include "inc/NS_PLAYER.h"
#include "inc/nvr_sdk.h"
#include "inc/NVR_NET.h"
#include "inc/NVR_NET_define.h"

bool vedioWidget::isNSInit = false;
bool vedioWidget::isNVRInit = false;

vedioWidget::vedioWidget(vedioWidgetRef ref, QWidget *parent) :
    QWidget(parent),m_ref(ref)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    connect(qApp,SIGNAL(applicationStateChanged(Qt::ApplicationState)),this,SLOT(m_ApplicationStateChange(Qt::ApplicationState)));
    QTimer::singleShot(1000,this,SLOT(m_checkIsVisible()));
    this->setMouseTracking(true);//用来更改窗口大小
    DesktopWidgetRect = QApplication::desktop()->rect();//更改窗口大小时用

    initContextMenu();//右键菜单
    initEnumToStringList();//

    hwnd = this->winId();
    if(ref.devType == DEV_TYPE_IPC){
        NS_init();
        NS_connect();//测试
        NS_start();
    }else if(ref.devType == DEV_TYPE_NVR){
        NS_init();
        NVR_init();
        NVR_start();
    }
}

vedioWidget::~vedioWidget()
{
}

QString vedioWidget::getWidgetId()
{
    return m_ref.id;
}

QString vedioWidget::getWidgetTitle()
{
    return m_ref.title;
}

void vedioWidget::NS_init()
{

    if(isNSInit){
        qDebug()<<"ns init is true";
        return;
    }
    isNSInit = true;
    qDebug()<<"NS_NET_Init:"<<NS_NET_Init();
    qDebug()<<"NS_PLAYER_Init:"<<NS_PLAYER_Init();
    //qDebug()<<"NS_MP4_Init:"<<NS_MP4_Init();
}

bool vedioWidget::getIsStart()
{
    return isNSStart;
}

int vedioWidget::NS_connect()
{
    //初始化登陆结构体
    memset(&loginInfo,0,sizeof(NS_LOGIN_INFO_S));//清零
    qstrcpy(loginInfo.szHost,m_ref.host.toLocal8Bit().data());//
    qstrcpy(loginInfo.szUsername,m_ref.name.toLocal8Bit().data());
    qstrcpy(loginInfo.szPassword,m_ref.pwd.toLocal8Bit().data());
    //strcpy(loginInfo.szDevChn, m_strDVSChn);
    loginInfo.u16Port=static_cast<ushort>(m_ref.port);
    loginInfo.cbEventCallBack = OnNetStatusFunc;//网络消息 回调
    loginInfo.s32ConnectTimeout = 5;
    loginInfo.pUserData = this;
    loginInfo.stNetProtocol.eSocketType = SOCKET_TYPE_TCP;

    //登陆
    if( NS_NET_Login(&m_u32DevHandle, &loginInfo) != 0 ){
        return 2;
    }

    QString strChannel;
    unsigned int size = 0;

    memset(&cfg_server_info,0,sizeof(NS_SERVER_INFO_S));
    if( NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_SERVER_INFO, &cfg_server_info, &size) !=0 ){
        return 3;//stcChannel为空
    }
//    qDebug()<<"channelnum:"<<cfg_server_info.channelnum;
    channelNames.clear();
    for(uint i=0;i<cfg_server_info.channelnum;i++){
        channelNames<<cfg_server_info.channels[i];
    }
//    emit m_signals_channelNames(m_ref.id,channelNames);//构造函数内，无效

//    memset(&cfg_dev_caps,0,sizeof(NS_DEV_CAPS_S));
//    if(NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_DEV_CAPS, &cfg_dev_caps, &size) != 0 ){
//        return 4;
//    }
////    qDebug()<<"dwSize:"<<cfg_dev_caps.dwSize<<" devtype:"<<cfg_dev_caps.devtype<<" hasptz:"<<cfg_dev_caps.hasptz;

//    memset(&cfg_ca_ao_info,0,sizeof(NS_CA_AO_INFO_S));
//    if(NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_CA_AO_INFO, &cfg_ca_ao_info, &size) != 0 ){
//        return 5;
//    }
//    qDebug()<<"NS_CA_AO_INFO_S:"<<cfg_ca_ao_info.ao0<<" "<<cfg_ca_ao_info.ao1;

    return 0;
}

int vedioWidget::NS_start()
{
    const char * psChannel = cfg_server_info.channels[m_ref.channelId<cfg_server_info.channelnum?m_ref.channelId:0];
    if(NS_NET_StartStream(&m_u32StreamHandle, m_u32DevHandle, psChannel, 0, &m_stStreamInfo, OnStreamFunc, OnStreamFunc, this) != 0 ){
        return 2;
    }
    isNSStart = true;
    return 0;
    //    qDebug()<<psChannel<<StringList_NS_AUDIO_FORMAT_E[m_stStreamInfo.struAencChAttr.enAudioFormat]<<StringList_tagNS_VIDEO_FORMAT_E[m_stStreamInfo.struVencChAttr.enVideoFormat];
}

int vedioWidget::NS_stop()
{
    if( NS_NET_StopStream(m_u32DevHandle,m_u32StreamHandle) != 0 ){
        return 2;
    }
    isNSStart = false;
    return 0;
}

int vedioWidget::OnNetStatusFunc(unsigned int u32DevHandle, NS_NETSTAT_E u32Event, void* pUserData)
{
    Q_UNUSED(pUserData);

    qDebug()<<"Handle:"<<u32DevHandle<<" "<<u32Event<<" "<<StringList_NS_NETSTAT_E.at(u32Event);

    return 0;
}

int vedioWidget::OnStreamFunc(unsigned int u32ChnHandle, unsigned int u32DataType, unsigned char *pu8Buffer, unsigned int u32Length, NS_U64 u64TimeStamp,
                             NS_STREAM_INFO_S *pStreamInfo, void *pUserData)
{
    Q_UNUSED(u32ChnHandle) Q_UNUSED(pStreamInfo)
    vedioWidget* p = static_cast<vedioWidget*>(pUserData);
//    qDebug()<<"u32ChnHandle:"<<u32ChnHandle<<" u32DataType:"<<u32DataType<<" u64TimeStamp:"<<u64TimeStamp<<
//              " enAudioFormat:"<<StringList_NS_AUDIO_FORMAT_E[(int)pStreamInfo->struAencChAttr.enAudioFormat]<<
//              " enVideoFormat:"<<StringList_tagNS_VIDEO_FORMAT_E[(int)pStreamInfo->struVencChAttr.enVideoFormat];
    if (!p->m_u32PlayerHandle)//m_u32PlayerHandle未初始化
    {
        qDebug()<<"NS_PLAYER_Open:"<<NS_PLAYER_Open(&p->m_u32PlayerHandle, static_cast<uint>(p->hwnd), &p->m_stStreamInfo);
    }

    if( u32DataType == NS_STREAM_TYPE_VIDEO){
        /*int ret = */NS_PLAYER_InputData(p->m_u32PlayerHandle, u32DataType, pu8Buffer, u32Length, u64TimeStamp);
        //qDebug()<<"NS_PLAYER_InputData:"<<ret<<" u64TimeStamp:"<<u64TimeStamp;
    }
    return 0;
}

void vedioWidget::NVR_init()
{
    if(isNVRInit){
        qDebug()<<"nvr init is true";
        return;
    }
    isNVRInit = true;
    qDebug()<<"NVR_NET_Init:"<<NVR_NET_Init();

    memset(&nvr_login_info,0,sizeof(NVR_LOGIN_INFO_S));
    qstrcpy(nvr_login_info.szHost,QString("192.168.1.226").toLocal8Bit().data());
    qstrcpy(nvr_login_info.szUsername,QString("admin").toLocal8Bit().data());
    qstrcpy(nvr_login_info.szPassword,QString("cxstar").toLocal8Bit().data());
    nvr_login_info.u16Port=5540;
    nvr_login_info.cbEventCallBack = OnNetStatusFunc;//网络消息 回调
    nvr_login_info.s32ConnectTimeout = 5;
    nvr_login_info.pUserData = this;

    qDebug()<<"NVR_NET_Login:"<<NVR_NET_Login(&m_u32DevHandle,&nvr_login_info);
    uint sizeOut=0;
    qDebug()<<"NVR_NET_GetNvrConfig:"<<NVR_NET_GetNvrConfig(m_u32DevHandle, NVR_CMD_GET_DEV_INFO, nullptr, 0, &nvr_dev_info, sizeof(sNvrSDKDevinfoRes), &sizeOut);

    testForm *testF= new testForm;
    connect(testF,SIGNAL(ss(uint,uint,uint,uint,uint)),this,SLOT(testSlot(uint,uint,uint,uint,uint)));
    testF->show();

}

void vedioWidget::NVR_start()
{
    QString chn("media=0/channel=0&level=0");
    uint nPort=8110;
    NVR_NET_StartStream(&m_u32StreamHandle, m_u32DevHandle, chn.toLocal8Bit().data(), nPort, 0, &m_stStreamInfo, OnStreamFunc, OnStreamFunc, this);
}

void vedioWidget::initEnumToStringList()
{
    if(!StringList_NS_AUDIO_BITWIDTH_E.isEmpty())
        return;
    StringList_NS_NETSTAT_E<<"NS_NETSTAT_CONNING"<<
                             "NS_NETSTAT_CONNING_FAILED"<<
                             "NS_NETSTAT_LOGIN_FAILED"<<
                             "NS_NETSTAT_CONNED"<<
                             "NS_NETSTAT_ABNORMAL_DISCONNED"<<
                             "NS_NETSTAT_NORMAL_DISCONNED";
    StringList_tagNS_VIDEO_FORMAT_E<<"NS_VIDEO_FORMAT_H261"
                                    <<"NS_VIDEO_FORMAT_H263"
                                    <<"NS_VIDEO_FORMAT_MPEG2"
                                    <<"NS_VIDEO_FORMAT_MPEG4"
                                    <<"NS_VIDEO_FORMAT_H264"
                                    <<"NS_VIDEO_FORMAT_H265"
                                    <<"NS_VIDEO_FORMAT_MJPEG"
                                    <<"NS_VIDEO_FORMAT_BUTT";
    StringList_NS_AUDIO_FORMAT_E<<"0"<<
                                  "NS_AUDIO_FORMAT_G711A"<<
                                   "NS_AUDIO_FORMAT_G711Mu"<<
                                   "NS_AUDIO_FORMAT_ADPCM"<<
                                   "NS_AUDIO_FORMAT_G726"<<
                                   "NS_AUDIO_FORMAT_AMR"<<
                                   "NS_AUDIO_FORMAT_AMRDTX"<<
                                   "NS_AUDIO_FORMAT_AAC"<<
                                   "NS_AUDIO_FORMAT_BUTT";
    StringList_NS_AUDIO_BITWIDTH_E<<"NS_AUDIO_BITWIDTH_8"<<
                                   "NS_AUDIO_BITWIDTH_16"<<
                                   "NS_AUDIO_BITWIDTH_32"<<
                                   "NS_AUDIO_BITWIDTH_BUTT";
    StringList_NS_AUDIO_SAMPLE_RATE_E<<"NS_AUDIO_SAMPLE_RATE_8"<<
                                       "NS_AUDIO_SAMPLE_RATE_11025"<<
                                       "NS_AUDIO_SAMPLE_RATE_16"<<
                                       "NS_AUDIO_SAMPLE_RATE_22050"<<
                                       "NS_AUDIO_SAMPLE_RATE_24"<<
                                       "NS_AUDIO_SAMPLE_RATE_32"<<
                                       "NS_AUDIO_SAMPLE_RATE_441"<<
                                       "NS_AUDIO_SAMPLE_RATE_48"<<
                                       "NS_AUDIO_SAMPLE_RATE_64"<<
                                       "NS_AUDIO_SAMPLE_RATE_882"<<
                                       "NS_AUDIO_SAMPLE_RATE_96"<<
                                       "NS_AUDIO_SAMPLE_RATE_1764"<<
                                       "NS_AUDIO_SAMPLE_RATE_192"<<
                                       "NS_AUDIO_SAMPLE_RATE_BUTT";
    StringList_NS_SOUND_MODE_E<<"NS_SOUND_MODE_MOMO"<<
                                "NS_SOUND_MODE_STEREO"<<
                                "NS_SOUND_MODE_BUTT";
}

void vedioWidget::mousePressEvent(QMouseEvent *event)
{
//    qDebug()<<"mousePressEvent";
    if (event->button() == Qt::LeftButton) {
        this->m_drag = true;
        this->dragPos = event->pos();
        this->resizeDownPos = event->globalPos();
        this->mouseDownRect = this->rect();
//        qDebug()<<"resizeDownPos:"<<this->resizeDownPos<<" mouseDownRect:"<<this->mouseDownRect;
    }
}
void vedioWidget::mouseMoveEvent(QMouseEvent * event)
{
    if (resizeRegion != Default)
    {
        handleResize();
        return;
    }
    if(m_move) {
        move(event->globalPos() - dragPos);
        return;
    }
    QPoint clientCursorPos = event->pos();
    QRect r = this->rect();
    QRect resizeInnerRect(resizeBorderWidth, resizeBorderWidth, r.width() - 2*resizeBorderWidth, r.height() - 2*resizeBorderWidth);
    if(r.contains(clientCursorPos) && !resizeInnerRect.contains(clientCursorPos)) { //调整窗体大小
        ResizeRegion resizeReg = getResizeRegion(clientCursorPos);
        setResizeCursor(resizeReg);
        if (m_drag && (event->buttons() & Qt::LeftButton)) {
            resizeRegion = resizeReg;
            handleResize();
        }
    }
    else { //移动窗体
        setCursor(Qt::ArrowCursor);
        if (m_drag && (event->buttons() & Qt::LeftButton)) {
            m_move = true;
            move(event->globalPos() - dragPos);
        }
    }
}
void vedioWidget::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug()<<"mouseReleaseEvent";
    m_drag = false;
    if(m_move) {
        m_move = false;
        handleMove(event->globalPos()); //鼠标放开后若超出屏幕区域自动吸附于屏幕顶部/左侧/右侧
    }
    resizeRegion = Default;
    setCursor(Qt::ArrowCursor);
}
void vedioWidget::setResizeCursor(ResizeRegion region)
{
    switch (region)
    {
    case North:
    case South:
        setCursor(Qt::SizeVerCursor);
        break;
    case East:
    case West:
        setCursor(Qt::SizeHorCursor);
        break;
    case NorthWest:
    case SouthEast:
        setCursor(Qt::SizeFDiagCursor);
        break;
    default:
        setCursor(Qt::SizeBDiagCursor);
        break;
    }
}
vedioWidget::ResizeRegion vedioWidget::getResizeRegion(QPoint clientPos)
{
    if (clientPos.y() <= resizeBorderWidth) {
        if (clientPos.x() <= resizeBorderWidth)
            return NorthWest;
        else if (clientPos.x() >= this->width() - resizeBorderWidth)
            return NorthEast;
        else
            return North;
    }
    else if (clientPos.y() >= this->height() - resizeBorderWidth) {
        if (clientPos.x() <= resizeBorderWidth)
            return SouthWest;
        else if (clientPos.x() >= this->width() - resizeBorderWidth)
            return SouthEast;
        else
            return South;
    }
    else {
        if (clientPos.x() <= resizeBorderWidth)
            return West;
        else
            return East;
    }
}
void vedioWidget::handleMove(QPoint pt)
{
    QPoint currentPos = pt - dragPos;
//    qDebug()<<"currentPos:"<<currentPos;
    if(currentPos.x() < DesktopWidgetRect.x()) { //吸附于屏幕左侧
        currentPos.setX(DesktopWidgetRect.x());
    }
    else if ( (currentPos.x()+this->width()) > DesktopWidgetRect.width()) { //吸附于屏幕右侧
        currentPos.setX(DesktopWidgetRect.width()-this->width());
    }
    if(currentPos.y() < DesktopWidgetRect.y()) { //吸附于屏幕顶部
        currentPos.setY(DesktopWidgetRect.y());
    }
//    qDebug()<<"currentPos:"<<currentPos;
    move(currentPos);
}
void vedioWidget::handleResize()
{
    int xdiff = QCursor::pos().x() - resizeDownPos.x();
    int ydiff = QCursor::pos().y() - resizeDownPos.y();

//    qDebug()<<"xdiff:"<<xdiff<<" ydiff:"<<ydiff;

    switch (resizeRegion)
    {
    case East:
    {
        resize(mouseDownRect.width()+xdiff, this->height());
        break;
    }
    case West:
    {
        resize(mouseDownRect.width()-xdiff, this->height());
        move(resizeDownPos.x()+xdiff, this->y());
        break;
    }
    case South:
    {
        resize(this->width(),mouseDownRect.height()+ydiff);
        break;
    }
    case North:
    {
        resize(this->width(),mouseDownRect.height()-ydiff);
        move(this->x(), resizeDownPos.y()+ydiff);
        break;
    }
    case SouthEast:
    {
        resize(mouseDownRect.width() + xdiff, mouseDownRect.height() + ydiff);
        break;
    }
    case NorthEast:
    {
        resize(mouseDownRect.width()+xdiff, mouseDownRect.height()-ydiff);
        move(this->x(), resizeDownPos.y()+ydiff);
        break;
    }
    case NorthWest:
    {
        resize(mouseDownRect.width()-xdiff, mouseDownRect.height()-ydiff);
        move(resizeDownPos.x()+xdiff, resizeDownPos.y()+ydiff);
        break;
    }
    case SouthWest:
    {
        resize(mouseDownRect.width()-xdiff, mouseDownRect.height()+ydiff);
        move(resizeDownPos.x()+xdiff, this->y());
        break;
    }
    default:
        break;
    }
}

void vedioWidget::initContextMenu()
{
    m_contextMenu = new QMenu;
     //m_contextMenu->clear();

     m_setAction = new QAction("设置",m_contextMenu);
     m_saveLocAction = new QAction("保存位置",m_contextMenu);
     m_loadLocAction = new QAction("载入位置",m_contextMenu);
     m_delAction = new QAction("删除",m_contextMenu);
     m_quitAction = new QAction("退出",m_contextMenu);

     connect(m_setAction,SIGNAL(triggered(bool)),this,SLOT(m_setAction_triggered()));
     connect(m_saveLocAction,SIGNAL(triggered(bool)),this,SLOT(m_saveLocAction_triggered()));
     connect(m_loadLocAction,SIGNAL(triggered(bool)),this,SLOT(m_loadLocAction_triggered()));
     connect(m_delAction,SIGNAL(triggered(bool)),this,SLOT(m_delAction_triggered()));
     connect(m_quitAction,SIGNAL(triggered(bool)),this,SLOT(m_quitAction_triggered()));

     m_contextMenu->addAction(m_setAction);
     m_contextMenu->addAction(m_saveLocAction);
     m_contextMenu->addAction(m_loadLocAction);
     m_contextMenu->addAction(m_delAction);
     m_contextMenu->addAction(m_quitAction);
}

void vedioWidget::contextMenuEvent(QContextMenuEvent *event)
{
    m_contextMenu->exec(event->globalPos());
}


void vedioWidget::m_setAction_triggered()
{

}

void vedioWidget::m_saveLocAction_triggered()
{
    emit m_signals_saveLoc(m_ref.id,pos(),size());

}

void vedioWidget::m_loadLocAction_triggered()
{
    emit m_signals_loadLoc(this);
}

void vedioWidget::m_delAction_triggered()
{
}

void vedioWidget::m_quitAction_triggered()
{

}

void vedioWidget::m_ApplicationStateChange(Qt::ApplicationState state)
{
    qDebug()<<state;
    if(state==Qt::ApplicationInactive){
        this->activateWindow();
        this->raise();
    }
}

void vedioWidget::m_checkIsVisible()
{
//    SetWindowPos((HWND)this->winId(),HWND_TOPMOST,this->pos().x(),this->pos().y(),this->width(),this->height(),SWP_SHOWWINDOW);
    QTimer::singleShot(1000,this,SLOT(m_checkIsVisible()));
    this->activateWindow();
    this->raise();
}

void vedioWidget::testSlot(uint a, uint b, uint c, uint d, uint e)
{
    qDebug()<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
    uint sizeOut;
    //NVR_CMD_GET_QUERY_RECORD sNvrSDKRecordReq, sNvrSDKRecordRes
    sNvrSDKRecordReq req;
    req.chn=a;
    req.tags=b;
    req.begin_time=c;
    req.end_time=d;
    req.new_query=e;
    struct testStruct{
        uint d[(2+3*14)*4];
    };
    uint resMaxSize = sizeof(sNvrSDKRecordRes)+sizeof(sNvrSDKRecSeg)*100;
    sNvrSDKRecordRes *pRes=static_cast<sNvrSDKRecordRes *>(malloc(resMaxSize));//最大返回100条数据
    qDebug()<<"NVR_NET_GetNvrConfig"<<NVR_NET_GetNvrConfig(m_u32DevHandle,NVR_CMD_GET_QUERY_RECORD,&req,sizeof(sNvrSDKRecordReq),pRes,resMaxSize,&sizeOut);
    uint retOver= pRes->is_over;
    uint retCount = pRes->item_count;
    qDebug()<<"over:"<<retOver<<" count:"<<retCount<<" size:"<<sizeOut;
    for (uint i=0;i<retCount;i++) {
        qDebug()<<QDateTime::fromSecsSinceEpoch(static_cast<qint64>(reinterpret_cast<sNvrSDKRecSeg*>(pRes->segs)[i].stime)).toString("yy-MM-dd hh:mm:ss")
               <<"-"<<QDateTime::fromSecsSinceEpoch(static_cast<qint64>(reinterpret_cast<sNvrSDKRecSeg*>(pRes->segs)[i].etime)).toString("yy-MM-dd hh:mm:ss");
    }
    free(pRes);
    pRes=nullptr;
}

