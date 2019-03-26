﻿#include <QDebug>
#include "vediowidget.h"
#include "inc/nvr_sdk.h"
#include "inc/NS_NET.h"
#include "inc/NS_MP4.h"
#include "inc/NS_PLAYER.h"

vedioWidget::vedioWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    initEnumToStringList();

    NS_init();
    connect();//测试
}

vedioWidget::~vedioWidget()
{
}

void vedioWidget::NS_init()
{
    qDebug()<<"NS_NET_Init:"<<NS_NET_Init();
    qDebug()<<"NS_PLAYER_Init:"<<NS_PLAYER_Init();
    qDebug()<<"NS_MP4_Init:"<<NS_MP4_Init();
    hwnd = this->winId();
}

int vedioWidget::NS_connect()
{
    init_loginInfo(loginInfo);//初始化登陆结构体
    //登陆
    if( NS_NET_Login(&m_u32DevHandle, &loginInfo) != 0 ){
        return 2;
    }

    QString strChannel;
    unsigned int size = 0;

    memset(&cfg_server_info,0,sizeof(NS_SERVER_INFO_S));
    if( NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_SERVER_INFO, &cfg_server_info, &size) !=0 ){
        return 3;
    }
    qDebug()<<"channelnum:"<<cfg_server_info.channelnum;
    for(uint i=0;i<cfg_server_info.channelnum;i++){
        qDebug()<<cfg_server_info.channels[i];
    }

    NS_DEV_CAPS_S cfg_dev_caps;
    memset(&cfg_dev_caps,0,sizeof(NS_DEV_CAPS_S));
    if(NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_DEV_CAPS, &cfg_dev_caps, &size) != 0 ){
        return 4;
    }
    qDebug()<<"dwSize:"<<cfg_dev_caps.dwSize<<" devtype:"<<cfg_dev_caps.devtype<<" hasptz:"<<cfg_dev_caps.hasptz;

    NS_CA_AO_INFO_S cfg_ca_ao_info;
    memset(&cfg_ca_ao_info,0,sizeof(NS_CA_AO_INFO_S));
    if(NS_NET_GetServerConfig(m_u32DevHandle, strChannel.toStdString().c_str(), NS_CMD_GET_CA_AO_INFO, &cfg_ca_ao_info, &size) != 0 ){
        return 4;
    }
    qDebug()<<"NS_CA_AO_INFO_S:"<<cfg_ca_ao_info.ao0<<" "<<cfg_ca_ao_info.ao1;

    const char * psChannel = cfg_server_info.channels[0];
    if(NS_NET_StartStream(&m_u32StreamHandle, m_u32DevHandle, psChannel, 0, &m_stStreamInfo, OnStreamFunc, OnStreamFunc, this) != 0 ){
        return 5;
    }
    qDebug()<<psChannel<<StringList_NS_AUDIO_FORMAT_E[m_stStreamInfo.struAencChAttr.enAudioFormat]<<StringList_tagNS_VIDEO_FORMAT_E[m_stStreamInfo.struVencChAttr.enVideoFormat];

    return 0;
}

int vedioWidget::OnNetStatusFunc(unsigned int u32DevHandle, /* 设备句柄 */
                           NS_NETSTAT_E u32Event,
                           void* pUserData)
{
    Q_UNUSED(pUserData);

    qDebug()<<"Handle:"<<u32DevHandle<<" "<<u32Event<<" "<<StringList_NS_NETSTAT_E.at(u32Event);

    return 0;
}

int vedioWidget::OnStreamFunc(unsigned int u32ChnHandle, unsigned int u32DataType, unsigned char *pu8Buffer, unsigned int u32Length, NS_U64 u64TimeStamp,
                             NS_STREAM_INFO_S *pStreamInfo, void *pUserData)
{
    Q_UNUSED(pUserData)
    vedioWidget* p = static_cast<vedioWidget*>(pUserData);
    qDebug()<<"u32ChnHandle:"<<u32ChnHandle<<" u32DataType:"<<u32DataType<<" u64TimeStamp:"<<u64TimeStamp<<
              " enAudioFormat:"<<StringList_NS_AUDIO_FORMAT_E[(int)pStreamInfo->struAencChAttr.enAudioFormat]<<
              " enVideoFormat:"<<StringList_tagNS_VIDEO_FORMAT_E[(int)pStreamInfo->struVencChAttr.enVideoFormat];
    if (!p->m_u32PlayerHandle)//m_u32PlayerHandle未初始化
    {
        qDebug()<<"NS_PLAYER_Open:"<<NS_PLAYER_Open(&p->m_u32PlayerHandle, (unsigned int)(p->hwnd), &p->m_stStreamInfo);
    }

    if( u32DataType == NS_STREAM_TYPE_VIDEO){
        qDebug()<<"NS_PLAYER_InputData:"<<NS_PLAYER_InputData(p->m_u32PlayerHandle, u32DataType, pu8Buffer, u32Length, u64TimeStamp);
    }
    return 0;
}

void vedioWidget::init_loginInfo(NS_LOGIN_INFO_S &l)
{
    memset(&l,0,sizeof(NS_LOGIN_INFO_S));//清零
    qstrcpy(l.szHost,"192.168.1.222");//
    qstrcpy(l.szUsername,"admin");
    qstrcpy(l.szPassword,"admin");
    //strcpy(loginInfo.szDevChn, m_strDVSChn);
    l.u16Port=554;
    l.cbEventCallBack = OnNetStatusFunc;//网络消息 回调
    loginInfo.s32ConnectTimeout = 5;
    l.pUserData = this;
    l.stNetProtocol.eSocketType = SOCKET_TYPE_TCP;
}

void vedioWidget::connect()
{
    NS_connect();
}

void vedioWidget::initEnumToStringList()
{
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
