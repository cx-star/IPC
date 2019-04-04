#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMetaEnum>
#include <QWidget>
#include <QStringList>
#include <QMouseEvent>
#include <QMenu>
#include <QSettings>
#include <QApplication>
#include "inc/NS_NET_define.h"
#include "inc/NVR_NET_define.h"

//vector类型作为class的static成员，需要在class外 define。
static QStringList StringList_NS_NETSTAT_E,StringList_tagNS_VIDEO_FORMAT_E,StringList_NS_AUDIO_FORMAT_E,
                   StringList_NS_AUDIO_BITWIDTH_E,StringList_NS_AUDIO_SAMPLE_RATE_E,StringList_NS_SOUND_MODE_E;

#define DEV_TYPE_NUL "NULL"
#define DEV_TYPE_IPC "IPC"
#define DEV_TYPE_NVR "NVR"
struct vedioWidgetRef{
    QString id;//对应setting的group
    QString devType;// 0:IPC 1:NVR
    QString host;
    uint port;
    QString name;
    QString pwd;
    uint level;//码流序号
    QString title;//自定义名称
    uint nvr_chn;
};

class vedioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit vedioWidget(vedioWidgetRef ref, QWidget *parent = nullptr);//关键字explicit，可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生
    ~vedioWidget();

    QString getWidgetId();
    QString getWidgetTitle();
    bool isLogin();

    QStringList getChannelNames() const;

signals:
    void contextAt(vedioWidget* id);
    void m_signals_saveLoc(const QString& id,const QPoint& p,const QSize& s);
    void m_signals_loadLoc(vedioWidget *);
    void m_signals_channelNames(const QString& id,const QStringList& names);
private:
    void initEnumToStringList();

    NS_LOGIN_INFO_S loginInfo;
    NS_DEV_CAPS_S cfg_dev_caps;
    NS_CA_AO_INFO_S cfg_ca_ao_info;
    unsigned int m_u32DevHandle=0;//ipc nvr 通用
    unsigned int m_u32StreamHandle=0;//ipc nvr 通用
    unsigned int m_u32PlayerHandle=0;
    NS_STREAM_INFO_S m_stStreamInfo;//ipc nvr 通用
    NS_SERVER_INFO_S cfg_server_info;
    WId hwnd;

    QStringList channelNames;

    static bool isNSInit;
    bool isNSLogin=false;
    bool isNSStart=false;
    void NS_init();
    int NS_connect();
public slots:
    int NS_start();
    int NS_stop();
private:
    static int OnNetStatusFunc(unsigned int u32DevHandle, NS_NETSTAT_E u32Event, void *pUserData);

    static int OnStreamFunc(unsigned int u32ChnHandle,/* 通道句柄 */
                            unsigned int u32DataType,/* 数据类型，详见STREAM_TYPE_E 0x01-视频，0x02-音频*/
                            unsigned char* pu8Buffer,/* 数据包含帧头 */
                            unsigned int u32Length,  /* 数据长度 */
                            NS_U64 u64TimeStamp,    /* 时间戳*/
                            NS_STREAM_INFO_S *pStreamInfo,/*码流属性*/
                            void* pUserData);        /* 用户数据*/

    NVR_LOGIN_INFO_S nvr_login_info;
    sNvrSDKDevinfoRes nvr_dev_info;
    struct sNvrSDKNetPortAll{
        sNvrSDKNetPort port[NVR_PORT_END];
    }nvr_net_port;
    sNvrGetOsdReq nvr_osd_req;
    sNvrOsdCfg nvr_osd_cfg;

    static bool isNVRInit;
    bool isNVRLogin=false;
    bool isNVRStart=false;
    void NVR_init();
    int NVR_login();
    int NVR_logout();
public slots:
    int NVR_start();
    int NVR_stop();

private:
    //不带标题栏（FramelessWindowHint）的窗体移动及调整大小
    enum ResizeRegion
    {
        Default,
        North,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest
    };
    bool m_drag=false, m_move=false;
    QPoint dragPos, resizeDownPos;
    const int resizeBorderWidth = 5;
    ResizeRegion resizeRegion=Default;
    QRect mouseDownRect, DesktopWidgetRect;
    void setResizeCursor(ResizeRegion region);
    ResizeRegion getResizeRegion(QPoint clientPos);
    void handleMove(QPoint pt);
    void handleResize();

    vedioWidgetRef m_ref;

    QMenu *m_contextMenu;
    QAction *m_setAction,*m_saveLocAction,*m_loadLocAction,*m_delAction,*m_quitAction;
    void initContextMenu();
private slots:
    //菜单对应槽函数
    void m_setAction_triggered();
    void m_saveLocAction_triggered();
    void m_loadLocAction_triggered();
    void m_delAction_triggered();
    void m_quitAction_triggered();

    void m_ApplicationStateChange(Qt::ApplicationState state);
    void m_checkIsVisible();

    void testSlot(uint a,uint b,uint c,uint d,uint e);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MAINWIDGET_H
