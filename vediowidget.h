#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMetaEnum>
#include <QWidget>
#include <QStringList>
#include <QMouseEvent>
#include "inc/NS_NET_define.h"

namespace Ui {
class MainWidget;
}

//vector类型作为class的static成员，需要在class外 define。
static QStringList StringList_NS_NETSTAT_E,
StringList_tagNS_VIDEO_FORMAT_E,
StringList_NS_AUDIO_FORMAT_E,
StringList_NS_AUDIO_BITWIDTH_E,
StringList_NS_AUDIO_SAMPLE_RATE_E,
StringList_NS_SOUND_MODE_E;

class vedioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit vedioWidget(QWidget *parent = 0);
    ~vedioWidget();

private slots:
    void connect();

private:
    void initEnumToStringList();

    NS_LOGIN_INFO_S loginInfo;
    unsigned int m_u32DevHandle=0;
    unsigned int m_u32StreamHandle=0;
    unsigned int m_u32PlayerHandle=0;
    NS_STREAM_INFO_S m_stStreamInfo;
    NS_SERVER_INFO_S cfg_server_info;
    WId hwnd;

    void NS_init();
    int NS_connect();
    void init_loginInfo(NS_LOGIN_INFO_S& l);
    static int OnNetStatusFunc(unsigned int u32DevHandle, NS_NETSTAT_E u32Event, void *pUserData);

    static int OnStreamFunc(unsigned int u32ChnHandle,/* 通道句柄 */
                            unsigned int u32DataType,/* 数据类型，详见STREAM_TYPE_E 0x01-视频，0x02-音频*/
                            unsigned char* pu8Buffer,/* 数据包含帧头 */
                            unsigned int u32Length,  /* 数据长度 */
                            NS_U64 u64TimeStamp,    /* 时间戳*/
                            NS_STREAM_INFO_S *pStreamInfo,/*码流属性*/
                            void* pUserData);        /* 用户数据*/

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
    QRect mouseDownRect, desktop;
    void setResizeCursor(ResizeRegion region);
    ResizeRegion getResizeRegion(QPoint clientPos);
    void handleMove(QPoint pt);
    void handleResize();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MAINWIDGET_H
