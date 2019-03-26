#ifndef	NVR_NET_DEFINE_H 
#define	NVR_NET_DEFINE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#include "NS_NET_define.h"
#include "nvr_sdk.h"

#ifdef WIN32 //windows 编译, 在工程里指定了编译选项
#define NVR_OS_TYPE NVR_OS_WIN32
    typedef unsigned __int64  NVR_U64;
#else
#define NVR_OS_LINUX 1
#define NVR_OS_WIN32 2
#define NVR_OS_TYPE NVR_OS_LINUX
    typedef unsigned long long  NVR_U64;
#define SOCKET       int
#define SOCKET_ERROR (-1)
#endif

#define NVR_MAX_CHANNEL_NUM	64
    /************************************************************************/
    /*   通用宏定义                                                         */
    /************************************************************************/

    /************************************************************************/
    /* 服务器操作命令                                                   */
    /************************************************************************/
#define    NVR_CMD_REBOOT_DEVICE       0x00000001  //重启设备,Param:NVR_CMD_INFO_S

    /************************************************************************/
    /* 获取服务器参数命令                                                   */
    /************************************************************************/
#define    NVR_CMD_GET_DEV_INFO				0x50000001  //服务器信息,Param: sNvrSDKDevinfoRes
#define    NVR_CMD_GET_CHN_PARAM			0x50000002  //服务器信息,Param: sNvrSDKGetChnParam, sNvrSDKChnParam
#define    NVR_CMD_GET_SYS_TIME				0x50000003  //服务器信息,Param: sNvrSDKSysTime
#define    NVR_CMD_GET_NTP					0x50000004  //服务器信息,Param: sNvrSDKNtp
#define    NVR_CMD_GET_NETWORK				0x50000005  //服务器信息,Param: sNvrSDKNetReq,sNvrSDKNet
#define    NVR_CMD_GET_PPPOE				0x50000006  //服务器信息,Param: sNvrSDKPppoe
#define    NVR_CMD_GET_DDNS					0x50000007  //服务器信息,Param: sNvrSDKGetDdnsReq,sNvrSDKDdns
#define    NVR_CMD_GET_COM					0x50000008  //服务器信息,Param: sNvrSDKGetComReq,sNvrSDKCom
#define    NVR_CMD_GET_NET_PORT				0x50000009  //服务器信息,Param: sNvrSDKNetPort
#define    NVR_CMD_GET_IMAGE_PARAM			0x50000010  //服务器信息,Param: sNvrSDKGetImageParm, sNvrSDKImageParm
#define    NVR_CMD_GET_EMAIL				0x50000011  //服务器信息,Param: sNvrSDKEmail
#define    NVR_CMD_GET_RECORD				0x50000012  //服务器信息,Param: sNvrSDKGetRecord,sNvrSDKRecord
#define    NVR_CMD_GET_PUADDCFG				0x50000014  //服务器信息,Param: sNvrSDKGetPuAddCfg
#define    NVR_CMD_GET_ALARMCFG				0x50000015  //服务器信息,Param: sNvrSDKGetAlarm
#define    NVR_CMD_GET_PUALARMCFG			0x50000016  //服务器信息,Param: sNvrSDKGetPuAlarm
#define    NVR_CMD_GET_QUERY_RECORD			0x50000017  //服务器信息,Param: sNvrSDKRecordReq, sNvrSDKRecordRes
#define    NVR_CMD_GET_QUERY_LOG			0x50000018  //服务器信息,Param: sNvrSDKLogReq, sNvrSDKLogResp
#define    NVR_CMD_GET_TIMEREBOOT			0x50000019  //服务器信息,Param: sNvrSDKTimingReboot
#define    NVR_CMD_GET_DISKINFO				0x50000020  //服务器信息,Param: sNvrSDKDisks
#define    NVR_CMD_GET_UPDATEBAR			0x50000021  //服务器信息,Param: sNvrSDKUpdateBarRes
#define    NVR_CMD_GET_FORMAT_DISK			0x50000022  //服务器信息,Param: sNvrSDKFormatProgress
#define    NVR_CMD_GET_ALL_USER				0x50000023  //服务器信息,Param: sNvrSDKAllUserRes
#define    NVR_CMD_GET_USER					0x50000024  //服务器信息,Param: sNvrSDKUser
#define    NVR_CMD_GET_GENERAL_INFO			0x50000028  //服务器信息,Param: sNvrSDKGeneralCfg
#define    NVR_CMD_GET_P2P					0x50000029  //服务器信息,Param: sNvrSDKDnp2pCfg
#define    NVR_CMD_GET_JSTAR				0x50000030  //服务器信息,Param: sNvrSDKJstarCfg
#define    NVR_CMD_GET_UENV					0x50000031  //服务器信息,Param: sNvrUbootEnv
#define    NVR_CMD_GET_OSD					0x50000032  //服务器信息,Param: sNvrGetOsdReq
#define    NVR_CMD_GET_REC_STATUS			0x50000033  //服务器信息,Param: sNvrRecStatusReq
#define    NVR_CMD_GET_WIFI_CFG				0x50000034  //服务器信息,Param: sNvrWifiInfoS
#define    NVR_CMD_GET_WIFI_CONNECT_DEV		0x50000035  //服务器信息,Param: sNvrWifiConDevS
#define    NVR_CMD_GET_WIFI_RESETWIFI_BAR	0x50000036  //服务器信息,Param: sNvrWifiResetBarS
#define    NVR_CMD_GET_WIFI_UPDATEWIFI_BAR	0x50000037  //服务器信息,Param: sNvrWifiResetBarS

    /************************************************************************/
    /* 设置服务器参数命令                                                   */
    /************************************************************************/
#define    NVR_CMD_SET_CHN_PARAM			0x60000002  //服务器信息,Param: sNvrSDKChnParam
#define    NVR_CMD_SET_SYS_TIME				0x60000003  //服务器信息,Param: sNvrSDKSysTime
#define    NVR_CMD_SET_NTP					0x60000004  //服务器信息,Param: sNvrSDKNtp
#define    NVR_CMD_SET_NETWORK				0x60000005  //服务器信息,Param: sNvrSDKNetSetReq
#define    NVR_CMD_SET_PPPOE				0x60000006  //服务器信息,Param: sNvrSDKPppoe
#define    NVR_CMD_SET_DDNS					0x60000007  //服务器信息,Param: sNvrSDKDdns
#define    NVR_CMD_SET_COM					0x60000008  //服务器信息,Param: sNvrSDKSetComReq
#define    NVR_CMD_SET_NET_PORT				0x60000009  //服务器信息,Param: sNvrSDKNetPort
#define    NVR_CMD_SET_IMAGE_PARAM			0x60000010  //服务器信息,Param: sNvrSDKSetImageParm
#define    NVR_CMD_SET_EMAIL				0x60000011  //服务器信息,Param: sNvrSDKEmail
#define    NVR_CMD_SET_RECORD				0x60000012  //服务器信息,Param: sNvrSDKSetRecord
#define	   NVR_CMD_PTZ_CTRL					0x60000013  //服务器信息,Param: sNvrSDKPtzCtrl
#define    NVR_CMD_SET_PUADDCFG				0x60000014  //服务器信息,Param: sNvrSDKSetPuAddCfg
#define    NVR_CMD_SET_ALARMCFG				0x60000015  //服务器信息,Param: sNvrSDKSetAlarm0
#define    NVR_CMD_SET_PUALARMCFG			0x60000016  //服务器信息,Param: sNvrSDKSetPuAlarm
#define    NVR_CMD_SET_TIMEREBOOT			0x60000019  //服务器信息,Param: sNvrSDKTimingReboot
#define    NVR_CMD_SET_FORMAT_DISK			0x60000022  //服务器信息,Param: sNvrSDKDiskNo
#define    NVR_CMD_SET_ADD_USER				0x60000025  //服务器信息,Param: sNvrSDKUser
#define    NVR_CMD_SET_SET_USER				0x60000026  //服务器信息,Param: sNvrSDKUser
#define    NVR_CMD_SET_DEL_USER				0x60000027  //服务器信息,Param: sNvrSDKDelUser
#define    NVR_CMD_SET_GENERAL_INFO			0x60000028  //服务器信息,Param: sNvrSDKGeneralCfg
#define    NVR_CMD_SET_P2P					0x60000029  //服务器信息,Param: sNvrSDKDnp2pSet
#define    NVR_CMD_SET_JSTAR				0x60000030  //服务器信息,Param: sNvrSDKJstarCfg
#define    NVR_CMD_SET_UENV					0x60000031  //服务器信息,Param: sNvrUbootEnv
#define    NVR_CMD_SET_OSD					0x60000032  //服务器信息,Param: sNvrSetOsdReq
#define    NVR_CMD_SET_P2PID				0x60000034  //服务器信息

#define    NVR_CMD_SET_WIFI_SSIDPASSWD		0x60000035  //服务器信息,Param: sNvrWifiSetSPS
#define    NVR_CMD_SET_WIFI_WIFICHANNEL		0x60000036  //服务器信息,Param: sNvrWifiSetChanS
#define    NVR_CMD_SET_WIFI_RESET_WIFI		0x60000037  //服务器信息



    /************************************************************************/
    /* 服务器配置信息结构                                                   */
    /************************************************************************/
    //服务器信息NVR_CMD_GET_SERVER_INFO
    typedef struct tagNVR_SERVER_INFO
    {
        unsigned int   dwSize;
        char           DevID[NS_NAME_LEN];      //设备ID,每台设备唯一,AutoID也使用该ID
        char           model[NS_NAME_LEN];      //型号
        char           name[NS_NAME_LEN];       //服务器名称
        char           kernelver[NS_NAME_LEN];//Linux版本
        char           serverver[NS_NAME_LEN];//Server版本
        char           webver[NS_NAME_LEN];//web版本
        char           startdate[NS_NAME_LEN];  //系统启动日期时间,比如"2006.09.06.09.11.30"
        unsigned int   runtimes;                //系统已启动时长,单位:分钟
        unsigned int   channelnum;      //通道数量
        char           channels[NVR_MAX_CHANNEL_NUM][NS_NAME_LEN];//通道
    }NVR_SERVER_INFO_S,*PNVR_SERVER_INFO_S;

    /************************************************************************/
    /*    设备搜索返回的设备信息                                            */
    /************************************************************************/
    typedef struct 
    {
        char            id[NS_NAME_LEN];  
        char            dev_type[NS_NAME_LEN];  
        char            softver[NS_NAME_LEN];  
        char            ip[NS_NAME_LEN];  
        char            submask[NS_NAME_LEN];  
        char            gateway[NS_NAME_LEN];  
        char            mac[NS_NAME_LEN];  
        char            cpu[NS_NAME_LEN];  
        char            mem[NS_NAME_LEN]; 
        char            wifi[NS_NAME_LEN]; 	
        unsigned int    cmdport;
        unsigned int    rtspport;          
        unsigned int    webport;          
        unsigned int    channelnum;
        char            channels[NVR_MAX_CHANNEL_NUM][NS_NAME_LEN];          
    } NVR_SEARCH_DEV_INFO_S;
    typedef void (* NVR_ON_SEARCH_DEV_CALLBACK ) (const NVR_SEARCH_DEV_INFO_S* pDevInfo,void* pUserData);


    /************************************************************************/
    /*    错误码                                                            */
    /************************************************************************/
#define NVR_ERR_BASE                           -1000   
#define NVR_ERR_FAILURE					(NVR_ERR_BASE -1)
#define NVR_ERR_CONNECT					(NVR_ERR_BASE -2)
#define NVR_ERR_LOGIN					(NVR_ERR_BASE -3)
#define NVR_ERR_NULL_POINTER			(NVR_ERR_BASE -4)
#define NVR_ERR_SOCKET					(NVR_ERR_BASE -5)
#define NVR_ERR_TIMEOUT					(NVR_ERR_BASE -6)
#define NVR_ERR_DATA_OUT_SIZE			(NVR_ERR_BASE -7)
#define NVR_ERR_DATA_IN_SIZE			(NVR_ERR_BASE -8)
#define NVR_ERR_NCP_RESULT				(NVR_ERR_BASE -9)
#define NVR_ERR_NCP_DATA_LEN			(NVR_ERR_BASE -10)


    typedef struct
    {
        char szHost[NS_NAME_LEN];         /*服务器IP*/
        unsigned short u16Port;     /*服务器端口号*/
        int s32ConnectTimeout;/*网络连接超时时间，默认超时是5秒，单位是秒*/

        char szUsername[NS_NAME_LEN];     /*输入用户名*/
        char szPassword[NS_NAME_LEN];    /*输入密码*/
		unsigned char  password_type; 

        NS_NET_PROTOCOL_S stNetProtocol; /*网络协议*/
        NS_ON_EVENT_CALLBACK cbEventCallBack;/*事件回调，主要为网络连接状态*/
        userpassword_s userAuth; /*返回当前用户权限*/
        void* pUserData  ;        /*用户数据，会从事件回调函数中返回出来*/
    }NVR_LOGIN_INFO_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
