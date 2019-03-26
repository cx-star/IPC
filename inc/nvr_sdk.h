/*
 * Copyright (C) by Jabsco Company
 *
 * File Name    :
 * Created Time : 2014-12-18
 * Version      : 1.0
 * Author       : luoshunfa
 * Description  :
 */


#ifndef _NVR_SDK_H_
#define _NVR_SDK_H_

#pragma warning (disable:4200)

#ifdef __cplusplus
extern "C" {
#endif

#define NVR_CMD_MAX_DATALEN    (128 * 1024)

#define NVR_MAX_LOG_DESC        128

#define NVR_SDK_MAX_PORT        NVR_PORT_END

#define NVR_MAX_ALARMINPUT      16

#define NVR_MAX_PRESET_NUM      255

#define NVR_MAX_TRACK_PRESETS   32

#define NVR_MAX_TRACK_NUM       16

    enum {
        NVR_CMD_HEARTBEAT_REQ   = 1,
        NVR_CMD_HEARTBEAT_RES   = 2,

        NVR_CMD_LOGIN_REQ       = 3,
        NVR_CMD_LOGIN_RES       = 4,

        NVR_CMD_GETDEVINFO_REQ  = 5,
        NVR_CMD_GETDEVINFO_RES  = 6,

        NVR_CMD_GETCHNPARAM_REQ = 7,
        NVR_CMD_GETCHNPARAM_RES = 8,

        NVR_CMD_SETCHNPARAM_REQ = 9,
        NVR_CMD_SETCHNPARAM_RES = 10,

        NVR_CMD_GETSYSTIME_REQ  = 11,
        NVR_CMD_GETSYSTIME_RES  = 12,

        NVR_CMD_SETSYSTIME_REQ  = 13,
        NVR_CMD_SETSYSTIME_RES  = 14,

        NVR_CMD_GETNTP_REQ      = 15,
        NVR_CMD_GETNTP_RES      = 16,

        NVR_CMD_SETNTP_REQ      = 17,
        NVR_CMD_SETNTP_RES      = 18,

        NVR_CMD_GETNETWORK_REQ  = 19,
        NVR_CMD_GETNETWORK_RES  = 20,

        NVR_CMD_SETNETWORK_REQ  = 21,
        NVR_CMD_SETNETWORK_RES  = 22,

        NVR_CMD_GETPPPOE_REQ    = 23,
        NVR_CMD_GETPPPOE_RES    = 24,

        NVR_CMD_SETPPPOE_REQ    = 25,
        NVR_CMD_SETPPPOE_RES    = 26,

        NVR_CMD_GETDDNS_REQ     = 27,
        NVR_CMD_GETDDNS_RES     = 28,

        NVR_CMD_SETDDNS_REQ     = 29,
        NVR_CMD_SETDDNS_RES     = 30,

        NVR_CMD_GETCOM_REQ      = 31,
        NVR_CMD_GETCOM_RES      = 32,

        NVR_CMD_SETCOM_REQ      = 33,
        NVR_CMD_SETCOM_RES      = 34,

        NVR_CMD_GETNETPORT_REQ  = 35,
        NVR_CMD_GETNETPORT_RES  = 36,

        NVR_CMD_SETNETPORT_REQ  = 37,
        NVR_CMD_SETNETPORT_RES  = 38,

        NVR_CMD_GEIMAGEPARM_REQ = 39,
        NVR_CMD_GEIMAGEPARM_RES = 40,

        NVR_CMD_SEIMAGEPARM_REQ = 41,
        NVR_CMD_SEIMAGEPARM_RES = 42,

        NVR_CMD_GETEMAIL_REQ    = 43,
        NVR_CMD_GETEMAIL_RES    = 44,

        NVR_CMD_SETEMAIL_REQ    = 45,
        NVR_CMD_SETEMAIL_RES    = 46,

        NVR_CMD_GETRECORD_REQ   = 47,
        NVR_CMD_GETRECORD_RES   = 48,

        NVR_CMD_SETRECORD_REQ   = 49,
        NVR_CMD_SETRECORD_RES   = 50,

        NVR_CMD_GETALARM_REQ    = 51,
        NVR_CMD_GETALARM_RES    = 52,

        NVR_CMD_SETALARM_REQ    = 53,
        NVR_CMD_SETALARM_RES    = 54,

        NVR_CMD_GETHDINFO_REQ   = 55,
        NVR_CMD_GETHDINFO_RES   = 56, //to do...

        NVR_CMD_GETPUALARM_REQ  = 57,
        NVR_CMD_GETPUALARM_RES  = 58,

        NVR_CMD_SETPUALARM_REQ = 59,
        NVR_CMD_SETPUALARM_RES = 60,

        NVR_CMD_GETPUADDCFG_REQ = 61,
        NVR_CMD_GETPUADDCFG_RES = 62,

        NVR_CMD_SETPUADDCFG_REQ = 63,
        NVR_CMD_SETPUADDCFG_RES = 64,

        NVR_CMD_QUERYLOG_REQ    = 65,
        NVR_CMD_QUERYLOG_RES    = 66,

        NVR_CMD_PTZCTRL_REQ     = 67,
        NVR_CMD_PTZCTRL_RES     = 68,

		NVR_CMD_RECQUERY_REQ    = 69,
		NVR_CMD_RECQUERY_RES    = 70,

		NVR_CMD_UPDATEBAR_REQ   = 71,
		NVR_CMD_UPDATEBAR_RES   = 72,

		NVR_CMD_GET_TIMEREBOOT_REQ = 73,
		NVR_CMD_GET_TIMEREBOOT_RES = 74,

		NVR_CMD_SET_TIMEREBOOT_REQ = 75,
		NVR_CMD_SET_TIMEREBOOT_RES = 76,

		NVR_CMD_GET_DISKINFO_REQ   = 77,
		NVR_CMD_GET_DISKINFO_RES   = 78,

		NVR_CMD_GET_ALLUSER_REQ    = 79,
		NVR_CMD_GET_ALLUSER_RES    = 80,

		NVR_CMD_SET_USER_REQ       = 81,
		NVR_CMD_SET_USER_RES       = 82,

		NVR_CMD_DEL_USER_REQ       = 83,
		NVR_CMD_DEL_USER_RES       = 84,

		NVR_CMD_ADD_USER_REQ       = 85,
		NVR_CMD_ADD_USER_RES       = 86,

		NVR_CMD_FIND_USER_REQ      = 87,
		NVR_CMD_FIND_USER_RES      = 88,

		NVR_CMD_FORMAT_DISK_REQ    = 89,
		NVR_CMD_FORMAT_DISK_RES    = 90,

		NVR_CMD_FORAT_GRESS_REQ    = 91,
		NVR_CMD_FORAT_GRESS_RES    = 92,

		NVR_CMD_GET_GENERAL_REQ     = 93,
		NVR_CMD_GET_GENERAL_RES     = 94,

		NVR_CMD_SET_GENERAL_REQ     = 95,
		NVR_CMD_SET_GENERAL_RES     = 96,

		NVR_CMD_GET_DNP2P_REQ       = 97,
		NVR_CMD_GET_DNP2P_RES       = 98,

		NVR_CMD_SET_DNP2P_REQ       = 99,
		NVR_CMD_SET_DNP2P_RES       = 100,

		NVR_CMD_GET_JSTAR_REQ       = 101,
		NVR_CMD_GET_JSTAR_RES       = 102,

		NVR_CMD_SET_JSTAR_REQ       = 103,
		NVR_CMD_SET_JSTAR_RES       = 104,

		NVR_CMD_GET_UENV_REQ        = 105,
		NVR_CMD_GET_UENV_RES        = 106,

		NVR_CMD_SET_UENV_REQ        = 107,
		NVR_CMD_SET_UENV_RES        = 108,

		NVR_CMD_SET_P2PID_REQ        = 109,
		NVR_CMD_SET_P2PID_RES        = 110,

		NVR_CMD_GET_OSD_REQ         = 111,
		NVR_CMD_GET_OSD_RES         = 112,

		NVR_CMD_SET_OSD_REQ         = 113,
		NVR_CMD_SET_OSD_RES         = 114,

		NVR_CMD_GET_REC_STATUS_REQ  = 115,
		NVR_CMD_GET_REC_STATUS_RES  = 116,

		NVR_CMD_GET_WIFI_CFG_REQ    = 117,
		NVR_CMD_GET_WIFI_CFG_RES    = 118,

		NVR_CMD_GET_CONNECT_DEV_REQ = 119,
		NVR_CMD_GET_CONNECT_DEV_RES = 120,

		NVR_CMD_SET_SSIDPASSWD_REQ  = 121,
		NVR_CMD_SET_SSIDPASSWD_RES  = 122,

		NVR_CMD_SET_WIFICHANNEL_REQ = 123,
		NVR_CMD_SET_WIFICHANNEL_RES = 124,

		NVR_CMD_RESET_WIFI_REQ      = 125,
		NVR_CMD_RESET_WIFI_RES      = 126,

		NVR_CMD_GET_RESETWIFI_BAR_REQ = 127,
		NVR_CMD_GET_RESETWIFI_BAR_RES = 128,

		NVR_CMD_GET_WIFI_UPDATEBAR_REQ= 129,
		NVR_CMD_GET_WIFI_UPDATEBAR_RES= 130,
    };

    typedef enum {
        NVR_QCIF = 0,
        NVR_QVGA,
        NVR_CIF,
        NVR_VGA,
        NVR_D1,
        NVR_720P,
        NVR_960P,
        NVR_UVGA,
        NVR_1080P,
        NVR_BUTT,
    } eNvrResolution;

    typedef enum {
        NVR_PORT_BEGIN = -1,
        NVR_PORT_WEB,       // http port
        NVR_PORT_FTP,       // ftp port
        NVR_PORT_RTSP,      // rtsp port
        NVR_PORT_VOICE,     // voice port
        NVR_PORT_UPDATE,    // update port
        NVR_PORT_END
    } eNvrSDKPort;

    typedef enum {
        NvrAlarm_DISK_FULL = 0,
        NvrAlarm_DISK_ERR = 1,
        NvrAlarm_IP_CONFLICT = 2,
        NvrAlarm_CABLE_PULLOUT = 3,
        NvrAlarm_INPUT_BGN = 4,
        NvrAlarm_INPUT_END = NvrAlarm_INPUT_BGN + NVR_MAX_ALARMINPUT - 1,
        NvrAlarm_LCL_END,

        NvrAlarm_CHN_MOTION,
        NvrAlarm_CHN_VIDEOMASK,
        NvrAlarm_CHN_VIDEOLOSS,
        NvrAlarm_CHN_INPUT    ,
        NvrAlarm_CHN_SESSION  ,
        NvrAlarm_END
    } eNvrSDKAlarmE;

    typedef enum {
        PU_VIDEO_LOSS = 0,
        PU_MOTION_DETECT,
        PU_VIDEO_HIDE,
        PU_ALARM_IN,
    } eNvrSDKPuAlarm;

    typedef enum {
        NVRSDK_INVALID = -1,
        NVRSDK_ONVIF,
        NVRSDK_JABSCO,
        NVRSDK_RTSP,
    } eNvrSDKVender;

    typedef enum {
        NVRSDK_PTZ_UP          = 0x00,
        NVRSDK_PTZ_DOWN        = 0x01,
        NVRSDK_PTZ_LEFT        = 0x02,
        NVRSDK_PTZ_RIGHT       = 0x03,

        NVRSDK_PTZ_ZOOM_IN     = 0x04,
        NVRSDK_PTZ_ZOOM_OUT    = 0x05,
        NVRSDK_PTZ_FOCUS_NEAR  = 0x06,
        NVRSDK_PTZ_FOCUS_FAR   = 0x07,
        NVRSDK_PTZ_IRIS_WIDE   = 0x08, //光圈+
        NVRSDK_PTZ_IRIS_DEC    = 0x09, //光圈-

        NVRSDK_PTZ_LEFT_UP     = 0x0A,
        NVRSDK_PTZ_RIGHT_UP    = 0x0B,
        NVRSDK_PTZ_LEFT_DOWN   = 0x0C,
        NVRSDK_PTZ_RIGHT_DOWN  = 0x0D,

        NVRSDK_PTZ_WIPER       = 0x0E,

        NVRSDK_PTZ_START_AUTO_RUN = 0x0F,
        NVRSDK_PTZ_STOP_AUTO_RUN = 0x10,

        NVRSDK_PTZ_SET_LEFTBORDER = 0x11,
        NVRSDK_PTZ_SET_RIGHTBORDER = 0x12,
        NVRSDK_PTZ_RUN_PAN        = 0x13,
        NVRSDK_PTZ_STOP_PAN       = 0x14,
        NVRSDK_PTZ_DEL_PAN        = 0x15,
        NVRSDK_PTZ_SET_PAN_SPEED  = 0x16,

        NVRSDK_PTZ_GOTO_PRESET = 0x17,
        NVRSDK_PTZ_SET_PRESET  = 0x18, //特殊处理结构体后面跟32字节的preset_name
        NVRSDK_PTZ_DEL_PRESET  = 0x19,

        NVRSDK_PRE_ADDTO_TRACK = 0x1A, //加入预置点到巡航
        NVRSDK_DEL_PRE_IN_TRACK = 0x1B,
        NVRSDK_PTZ_RUN_TRACK   = 0x1C,
        NVRSDK_PTZ_STOP_TRACK  = 0x1D,
        NVRSDK_PTZ_CLEAR_TRACK = 0x1E,

        NVRSDK_START_SET_SCAN = 0x1F,
        NVRSDK_STOP_SET_SCAN  = 0x20,
        NVRSDK_PTZ_RUN_SCAN   = 0x21,
        NVRSDK_PTZ_STOP_SCAN  = 0x22,
        NVRSDK_PTZ_DEL_SCAN   = 0x23,

        NVRSDK_PTZ_STOP_GUARD = 0x24,
        NVRSDK_SET_TRACK_GUARD = 0x25,
        NVRSDK_SET_SCAN_GUARD  = 0x26,
        NVRSDK_SET_PAN_GUARD  = 0x27,
        NVRSDK_SET_PRESET_GUARD = 0x28,
        NVRSDK_SET_GUARD_IDLE  = 0x29,

        NVRSDK_GET_PRESETS     = 0x30,
        NVRSDK_GET_TRACKS      = 0x31,

        NVRSDK_PTZ_STOP       = 0xFF
    } eNvrSDKPtzCtrl;

    typedef enum {
        SDKLOG_ALL       = 1,              //所有类型
        SDKLOG_ALARM     = 2,              //报警
        SDKLOG_ERROR     = 3,              //异常
        SDKLOG_OPERATE   = 4,              //操作
        SDKLOG_INFO      = 5,              //信息
    } eSDKLogMainType;

    typedef enum {
        SALARM_ALL           = 1,               //所有报警类型
        SALARM_IN            = 2,               //报警输入
        SALARM_OUT           = 3,               //报警输出
        SALARM_MOTION_START  = 4,               //移动侦测开始
        SALARM_MOTION_END    = 5,               //移动侦测结束
        SALARM_SHELTER_START = 6,               //遮挡报警开始
        SALARM_SHELTER_END   = 7,               //遮挡报警结束
    } eSDKLogAlarm;

    typedef enum {
        SERR_ALL            = 1,                //全部类型
        SERR_VIDEO_LOSS     = 2,                //视频丢失
        SERR_ILLEQAL_ACCESS = 3,                //非法访问
        SERR_DISK_FULL      = 4,                //磁盘满
        SERR_DISK_ERROR     = 5,                //磁盘错误
        SERR_CABLE_DISC     = 6,                //网线断开
        SERR_RECORD_ERROR   = 7,                //录像或抓拍异常
        SERR_IP_CONFLICT    = 8,                //NVR IP冲突
        SERR_VIDEO_SIGNAL   = 9,                //视频信号异常
        SERR_VIDEO_SIZE     = 10,                //视频输入输出制式异常
        SERR_IPC_CONNECT    = 11,               //IP Camera 未链接
        SERR_IPC_CONFLICT   = 12,               //IPC IP冲突
        SERR_IPC_RECORD     = 13,               //前端录像分辨率不匹配
    } eSDKLogError;

    typedef enum {
        SOPER_ALL               = 1,             //所有类型
        SOPER_POWER_ON          = 2,             //开机
        SOPER_LOCAL_SHUTDOWN    = 3,             //本地关机
        SOPER_LOCAL_REBOOT      = 4,             //本地重启
        SOPER_ABNORMAL_SHUTDOWN = 5,             //异常关机
        SOPER_LOCAL_LOGIN       = 6,             //本地登录
        SOPER_LOCAL_LOGOUT      = 7,             //本地注销
        SOPER_LOCAL_CONFIGURE   = 8,             //本地配置
        SOPER_LOCAL_UPGRADE     = 9,             //本地升级
        SOPER_LOCAL_START_RECORD= 10,             //本地启动录像
        SOPER_LOCAL_STOP_RECORD = 11,            //本地停止录像
        SOPER_LOCAL_START_CAPTURE=12,            //本地启动抓图
        SOPER_LOCAL_STOP_CAPTURE =13,            //本地停止抓图
        SOPER_LOCAL_PTZ_CTRL    = 14,            //本地PTZ控制
        SOPER_LOCAL_START_ALARM = 15,            //本地手动报警
        SOPER_LOCAL_INIT_HDD    = 16,            //本地初始化硬盘
        SOPER_LOCAL_PLAY_FILE   = 17,            //本地按文件回放
        SOPER_LOCAL_PLAY_TIME   = 18,            //本地按时间回放
        SOPER_LOCAL_ADD_NETHDD  = 19,            //本地添加网络盘
        SOPER_LOCAL_DEL_NETHDD  = 20,            //本地删除网络盘
        SOPER_LOCAL_SET_NETHDD  = 21,            //本地设置网络盘
        SOPER_LOCAL_RESET_ADMIN = 22,            //本地恢复管理员默认密码
        SOPER_LOCAL_ADD_IPC     = 23,            //本地添加IP通道
        SOPER_LOCAL_DEL_IPC     = 24,            //本地删除IP通道
        SOPER_LOCAL_SET_IPC     = 25,            //本地设置IP 通道

        SOPER_REMOTE_SHUTDOW    = 26,            //远程关机
        SOPER_REMOTE_REBOOT     = 27,            //远程重启
        SOPER_REMOTE_LOGIN      = 28,           //远程登录
        SOPER_REMOTE_LOGOUT     = 29,            //远程注销
        SOPER_REMOTE_CONFIGURE  = 30,            //远程配置
        SOPER_REMOTE_UPGRADE    = 31,            //远程升级
        SOPER_REMOTE_START_RECORD = 32,          //远程启动录像
        SOPER_REMOTE_STOP_RECORD = 33,           //远程停止录像
        SOPER_REMOTE_START_CAPTURE=34,           //远程启动抓图
        SOPER_REMOTE_STOP_CAPTURE =35,           //远程停止抓图
        SOPER_REMOTE_PTZ_CTRL    = 36,           //远程PTZ控制
        SOPER_REMOTE_START_ALARM = 37,           //远程手动报警
        SOPER_REMOTE_INIT_HDD    = 38,           //远程初始化硬盘
        SOPER_REMOTE_PLAY_FILE   = 39,           //远程按文件回放
        SOPER_REMOTE_PLAY_TIME   = 40,           //远程按时间回放
        SOPER_REMOTE_ADD_NETHDD  = 41,           //远程添加网络盘
        SOPER_REMOTE_DEL_NETHDD  = 42,           //远程删除网络盘
        SOPER_REMOTE_SET_NETHDD  = 43,           //远程设置网络盘
        SOPER_REMOTE_RESET_ADMIN = 44,           //远程恢复管理员默认密码
        SOPER_REMOTE_ADD_IPC        = 45,           //远程添加IP通道
        SOPER_REMOTE_DEL_IPC        = 46,           //远程删除IP通道
        SOPER_REMOTE_SET_IPC        = 47,           //远程设置IP 通道
    } eSDKLogOperate;

    typedef enum {
        SINFO_ALL                = 1,            //所有类型
        SINFO_HDD_INFO           = 2,            //本地磁盘信息
        SINFO_START_RECORD       = 3,            //开始录像
        SINFO_STOP_RECORD        = 4,            //停止录像
        SINFO_DEL_VIDEO_FILE     = 5,            //删除过期录像文件
        SINFO_NETHDD_INFO        = 6,            //网络硬盘信息
        SINFO_START_CAPTURE      = 7,            //开始抓图
        SINFO_STOP_CAPTURE       = 8,            //结束抓图
        SINFO_RUNNING_STATE      = 9,            //系统运行状态信息
        SINFO_TIME_CHANGE        = 10,           //本地改变时间
        SINFO_VIDEO_NORMAL       = 11,           //视频恢复        
    } eNvrSDKLogInfo;

	typedef enum {
		SDKREC_TYPE_MANUAL = 0,       //手动录像
		SDKREC_TYPE_TIMER = 1,        //定时录像
		SDKREC_TYPE_MOTION = 2,	      //动检录像
		SDKREC_TYPE_ALARM  = 3,		  //告警录像
	} eNvrSdkRecType;

	/* 磁盘格式类型 */
	typedef enum {
		SDKDISK_OK	 = 0,//正常/空闲，正常/正在使用 	  nomal/free  ,nomal/busy, nomal/full
		SDKDISK_ERROR_NOT_UMOUNT,//异常/未卸载			  error/unable_umount
		SDKDISK_ERROR_NO_SDISK_CFG,//异常/无磁盘配置文件   error/not_fount_sdisk_cfg
		SDKDISK_ERROR_NO_INDEX_CFG, //异常/无索引文件文件   error/not_fount_index_bin
		SDKDISK_ERROR_IO, //异常/磁盘IO错误	error/disk_io
		SDKDISK_ERROR_READ_ONLY, //异常/磁盘只读	error/disk_readonly
		SDKDISK_ERROR_NO_FS,//异常/无文件系统 			  error/none_filesys
	} eNvrSdkDiskStatus;

	/* 磁盘格式类型 */
	typedef enum {
		SDKSTOR_FS_NONE	= 0,
		SDKSTOR_FS_EXT4	= 1,
		SDKSTOR_FS_FAT32 = 2,
		SDKSTOR_FS_FILE	= 3,
		SDKSTOR_FS_BLOCK = 4,
		SDKSTOR_FS_EXT2	= 5,
		SDKSTOR_FS_MSDOS = 6,
		SDKSTOR_FS_NTFS	= 7,
		SDKSTOR_FS_UNREG = 8
	} eNvrSdkDiskFsType;

    typedef struct {
        unsigned char       flag;
        unsigned char       version;
        unsigned char       reserved1;
        unsigned char       reserved2;
        unsigned int        session_id;
        unsigned short      sequence;
        unsigned char       reserved3;
        unsigned char       reserved4;
        unsigned short      msgcmd;
        unsigned short      result;
        unsigned int        datalen;
        unsigned char       data[0];
    } sNvrSDKHead;

    typedef struct {
        char                username[16];
        char                password[16];

        unsigned char       password_type;
        unsigned char       client_type;
        unsigned char       reserved1;
        unsigned char       reserved2;
    } sNvrSDKLoginReq;

    typedef struct {
        unsigned char       device_type;
        unsigned char       chn_nums;
        unsigned char       reserved1;
        unsigned char       reserved2;

        unsigned int        session_id;
        unsigned int        heartbeat_time; // secends
    } sNvrSDKLoginRes;

    typedef struct {
        unsigned char       alarmin_chns;
        unsigned char       alarmout_chns;
        unsigned char       videoin_chns;
        unsigned char       eth_num;

        char                build_time[32];
        char                dev_type[32];
        char                software_version[32];
        char                dev_id[32];
    } sNvrSDKDevinfoRes;

    typedef struct {
        unsigned int        chn;  //0~MAX
    } sNvrSDKGetChnParam;

    typedef struct {
        unsigned int        resoluton; //eNvrResolution
        unsigned int        fps;
        unsigned int        bps;
        unsigned int        gop;

        unsigned char       enc_type; //0 : H264 1 : mpeg4
        unsigned char       stream_ctrl; //0 : 限定码流 1 : 可变码流
        unsigned char       reserve[2];
    } sNvrSDKChnParam0;

    typedef struct {
        unsigned int        chn;
        sNvrSDKChnParam0    main;
        sNvrSDKChnParam0    sub;
    } sNvrSDKChnParam;

    typedef struct {
        unsigned  int   year;
        unsigned  int   month; //1~12
        unsigned  int   day;
        unsigned  int   hour;
        unsigned  int   minute;
        unsigned  int   second;
		int tz_index;
    } sNvrSDKSysTime;

    typedef struct {
        unsigned int enable;
        unsigned int interval;
        char         server[64];
		unsigned int port;
    } sNvrSDKNtp;

    typedef struct {
        unsigned int  index;
    } sNvrSDKNetReq;

    typedef struct {
        unsigned int   dhcpen;
        char           nic[8];
        char           ip[16];
        char           mask[16];
        char           gateway[16];
        char           multicast[16];
        char           mac[20];
        char           dns1[16];
        char           dns2[16];
    } sNvrSDKNet;

    typedef struct {
        unsigned int  index;
        sNvrSDKNet    netcfg;
    } sNvrSDKNetSetReq;

    typedef struct {
        unsigned int     enable;
        unsigned int     nic_index;  // 0 : eth0  1 : eth1
        char             username[64];
        char             password[64];
    } sNvrSDKPppoe;

    typedef struct {
        unsigned int   index; //0 : 3322   1 : 9299
    } sNvrSDKGetDdnsReq;

    typedef struct {
        unsigned int  enable;
        char          user[64];
        char          passwd[64];
        char          domain[64];
    } sNvrSDKDdns;

    typedef struct {
        unsigned int   index;
        sNvrSDKDdns    ddns;
    } sNvrSDKSetDdnsReq;

    typedef struct {
        unsigned  int   index; //0 : RS232  1 : RS485
    } sNvrSDKGetComReq;

    typedef struct {
        unsigned int   baud;
        unsigned int   databit;
        unsigned int   stop;
        unsigned int   addr;
        char           parity[4];  // 'N' '0' 'S'
        char           protocol[16];
    } sNvrSDKCom;

    typedef struct {
        unsigned  int   index;
        sNvrSDKCom      com;
    } sNvrSDKSetComReq;

    typedef struct {
        unsigned int    upnp_en;
        unsigned int    internal_port;
        unsigned int    extern_port; //readOnly
    } sNvrSDKNetPort;

    typedef struct {
        unsigned int    channel;
    } sNvrSDKGetImageParm;

    typedef struct {
        unsigned char   brightness;         //亮度
        unsigned char   contrast;           //对比度
        unsigned char   saturation;         //饱和度
        unsigned char   hue;                //色度
        unsigned char   sharpness;          //锐度
        unsigned char   res[3];
    } sNvrSDKImageParm;

    typedef struct {
        unsigned int     channel;
        sNvrSDKImageParm param;
    } sNvrSDKSetImageParm;

    typedef struct {
        char      smtp_server[64];
        char      sendto[64];
        char      user[64];
        char      passwd[64];
    } sNvrSDKEmail;

    typedef struct {
        unsigned int   channel;
    } sNvrSDKGetRecord;

    typedef struct {
        unsigned int  hour0;
        unsigned int  min0;
        unsigned int  hour1;
        unsigned int  min1;
        unsigned int  normal_en;
        unsigned int  motion_en;
        unsigned int  alarm_en;
    } sNvrSDKRecTime;

    typedef struct {
        sNvrSDKRecTime  time[6];
    } sNvrSDKRecDay;

    typedef struct {
        unsigned int    prerecord;
        sNvrSDKRecDay   day[7];
    } sNvrSDKRecord;

    typedef struct {
        unsigned int   channel;
        sNvrSDKRecord  plan;
    } sNvrSDKSetRecord;

    typedef struct {
        unsigned int    alarm_type; //eNvrSDKAlarmE
        unsigned int    channel;   //对于本地报警此参数忽略
    } sNvrSDKGetAlarm;

    typedef struct {
        unsigned int    screen_osd_en;
        unsigned int    email_en;
        unsigned int    ptz_chn;
        unsigned int    ptz_type;
        unsigned int    ptz_param;
#ifdef WIN32
        __int64    record_chns;
        __int64    snapshot_chns;
        __int64    patrol_chns;     // 在画面之间进行切换
        __int64    relay_chns;      // 告警IO输出，低8位代表8个output使能，1时使能
#else
        unsigned long long    record_chns;
        unsigned long long    snapshot_chns;
        unsigned long long    patrol_chns;     // 在画面之间进行切换
        unsigned long long    relay_chns;      // 告警IO输出，低8位代表8个output使能，1时使能
#endif
        unsigned int    beep_en;
    } sNvrAlarm0;

    typedef sNvrAlarm0     sNvrSDKLocalAlarm;
    typedef sNvrAlarm0     sNvrSDKChnMotionAlarm;
    typedef sNvrAlarm0     sNvrSDKChnVideoMaskAlarm;
    typedef sNvrAlarm0     sNvrSDKChnVideoLossAlarm;
    typedef sNvrAlarm0     sNvrSDKChnInputAlarm;
    typedef sNvrAlarm0     sNvrSDKChnSessionAlarm;

    typedef struct {
        sNvrSDKGetAlarm    set_type;
        sNvrAlarm0         alarm;
    } sNvrSDKSetAlarm0;

    typedef sNvrSDKSetAlarm0   sNvrSDKSetLocalAlarm;
    typedef sNvrSDKSetAlarm0   sNvrSDKSetChnMotionAlarm;
    typedef sNvrSDKSetAlarm0   sNvrSDKSetChnVideoMaskAlarm;
    typedef sNvrSDKSetAlarm0   sNvrSDKSetChnVideoLossAlarm;
    typedef sNvrSDKSetAlarm0   sNvrSDKSetChnInputAlarm;
    typedef sNvrSDKSetAlarm0   sNvrSDKSetChnSessionAlarm;

    typedef struct {
        unsigned int     channel;
        unsigned int     type;  //eNvrSDKPuAlarm
    } sNvrSDKGetPuAlarm;

    typedef struct {
        unsigned char    begin_hour;
        unsigned char    begin_min;
        unsigned char    end_hour;
        unsigned char    end_min;
    } sNvrSDKPuTimeSpan;

    typedef struct {
        unsigned char      enable;
        unsigned char      sensitivity;
        unsigned char      res[2];
        unsigned char      map[18][22];
        sNvrSDKPuTimeSpan  time_span[7][6];//7 days each week , 6 time spans for each day
    } sNvrSDKPuAlarm;

    typedef sNvrSDKGetPuAlarm sNvrSDKPuAlarmSel;

    typedef struct {
        sNvrSDKPuAlarmSel pu_select;
        sNvrSDKPuAlarm    pu_alarm;
    } sNvrSDKSetPuAlarm;

    typedef struct {
        unsigned int   channel;
    } sNvrSDKGetPuAddCfg;

    typedef struct {
        unsigned char devname[64];
        unsigned int  vender;         // eNvrSDKVender
        unsigned int  preview_stream; // 0:main 1:sub 2:auto
        unsigned int  tcpip_protocol; // 0:TCP 1:UDP
        unsigned char user[32];
        unsigned char password[32];
        unsigned char ip[16];
        unsigned int  port;
    } sNvrSDKPuAddCfg;

    typedef struct {
        unsigned int     channel;
        sNvrSDKPuAddCfg  addcfg;
    } sNvrSDKSetPuAddCfg;

    typedef struct {
        unsigned int main_type;     //主类型 eSDKLogMainType
        unsigned int sub_type;      //次类型
        unsigned int begin_time;    //日志开始的时间
        unsigned int end_time;      //日志结束时间
        unsigned int new_query;     //第一次发起请求为1,当一次不能查询完毕继续查询该字段填0
    } sNvrSDKLogReq;

    typedef struct {
        unsigned int     time;       //本地时间
        unsigned int     main_type;  //eSDKLogMainType
        unsigned int     sub_type;
        char             user[32];
        char             ipaddr[16];
        char             desc[NVR_MAX_LOG_DESC];
    } sNvrSDKLogItem;

    typedef struct {
        unsigned  int    is_over;   //0 : 查询未完毕 1 : 查询完毕
        unsigned  int    item_count;
        char             items[0];   //sNvrSDKLogItem array
    } sNvrSDKLogResp;

    typedef struct {
        unsigned  int   channel;
        unsigned  char  cmd;    //eNvrSDKPtzCtrl
        unsigned  char  param1; //id
        unsigned  char  param2;
        unsigned  char  param3;
    } sNvrSDKPtzCtrl;

    typedef struct {
        unsigned char    id;
        unsigned char    stay_time;
        unsigned char    res[2];
        char             name[32];
    } sNvrSDKPreset;

    typedef struct {
        unsigned int     num;
        sNvrSDKPreset    presets[NVR_MAX_PRESET_NUM];
    } sNvrSDKPresetResp;

    typedef struct {
        unsigned int     num;    //preset number
        unsigned int     state; //Idle = 0, Touring = 1, Paused = 2, Extended = 3
        unsigned int     tour_token;
        sNvrSDKPreset    preset[NVR_MAX_TRACK_PRESETS];
    } sNvrSDKTrack;

    typedef struct {
        unsigned int     tour_num;
        sNvrSDKTrack     preset_tour[NVR_MAX_TRACK_NUM];
    } sNvrSDKTrackResp;

    typedef struct {
        unsigned int chn;     
        unsigned int tags;      //eNvrSdkRecType  '|'
        unsigned int begin_time;
        unsigned int end_time;
        unsigned int new_query; //第一次发起请求为1,当一次不能查询完毕继续查询该字段填0
    } sNvrSDKRecordReq;
	
    typedef struct {
		unsigned int     tags;  //eNvrSdkRecType  '|'
        unsigned int     stime; //段起始时间
		unsigned int     etime;
    } sNvrSDKRecSeg;

    typedef struct {
        unsigned  int    is_over;    //0 : 查询未完毕 1 : 查询完毕
        unsigned  int    item_count;
        char             segs[0];   //sNvrSDKRecSeg array
    } sNvrSDKRecordRes;

	typedef struct {
		unsigned int    bar;
	} sNvrSDKUpdateBarRes;

	typedef struct {
		int    enable;
		int    weekday; //0~7 0:Sunday 6:Saturday 7:Everyday
		int    hour;    //0~23
	} sNvrSDKTimingReboot;

	typedef struct {
		int       disk_no;		 //磁盘号
		int       disk_seq;		 //磁盘序号
		int       disk_status;	 //磁盘状态 eNvrSdkDiskStatus
		char      dev_name[16];		 //磁盘名称
#ifdef WIN32
		__int64 total_size; //磁盘容量(MB)
		__int64 free_size;  //可用容量(MB)
#else
		long long total_size; //磁盘容量(MB)
		long long free_size;  //可用容量(MB)
#endif
		int       disk_type;		 //磁盘类型eNvrSdkDiskFsType
		int       use_count;		 //磁盘被链接个数。
	} sNvrSDKDiskInfo;

	typedef struct {
		int      count;
		char     disks[0]; //sNvrSDKDiskInfo
	} sNvrSDKDisks;

    typedef struct {
        char user[32];
        char cryptpasswd[36];
        char digestpasswd[36];
        unsigned auth1;
        unsigned auth2;
    } sNvrSDKUser;

	typedef struct {
		int     count;
		char    users[0];
	} sNvrSDKAllUserRes;

	typedef struct {
		char  user[32]; 
	} sNvrSDKDelUser;

	typedef sNvrSDKDelUser sNvrSDKFindUser;

	typedef struct {
		int    disk_no;
	} sNvrSDKDiskNo;

	typedef struct {
		int    progress;
	} sNvrSDKFormatProgress;	

	typedef struct {
        char   dev_name[64];
        char   dev_num[32];
        int    diskfull_stop;    // 0 覆盖 1 停止		
	} sNvrSDKGeneralCfg;

	typedef struct {
		int    enable;
		int    online;       //ReadOnly
		char   id[64];       //ReadOnly
		char   bmp_path[64]; //ReadOnly
	} sNvrSDKDnp2pCfg;

	typedef struct {
		int    enable;
	} sNvrSDKDnp2pSet;	

    typedef struct {
        int     enable_flag;            /* 平台参数使能  0:不启用;  1:启用. */
        char    pu_id[64];              /* 设备ID */
        char    pu_name[64];            /* 设备名 */
        char    pu_passwd[64];          /* 设备密码 */
        int     csg_port;               /* csg 端口号 */
        int     mdu_port;               /* mdu端口号 */
        char    csg_ip[32];             /* csg ip地址 */
        char    mdu_ip[32];             /* mdu ip地址 */
        int     protocol_type;          /* 视频流类型  1:tcp 0:udp */
        int     offline_to_record;      /* 设备掉线录像 0:不启用; 1:启用. */
        int     offline_to_upload;      /* 设备掉线录像上传 0:不启用; 1:启用. */
    } sNvrSDKJstarCfg;

	
	typedef struct {
		char device_id[32];
	} sNvrUbootEnv;

	typedef struct {
		int     chn;
	} sNvrGetOsdReq;

	typedef struct {
		int  timeen;
		int  timeleft;
		int  timetop;
		int  bpsen;
		int  bpsleft;
		int  bpstop;
		int  nameen;
		int  nameleft;
		int  nametop;
		char name[64];
	} sNvrOsdCfg;

	typedef struct {
		int          chn;
		sNvrOsdCfg   osd;
	} sNvrSetOsdReq;

	typedef struct {
		int    chn;
	} sNvrRecStatusReq;

	typedef struct {
		int    is_record;	
	} sNvrRecStatusRes;

	typedef struct {
		char lan_mac[20];
		char lan_ip[20];
		char lan_mask[20];
		char dhcp_sip[20];
		char sec_mode[16];
		char wl_stand[16];

		int  dhcp_num;
		int  ssid_broad;
		int  channel; //0~14 0:自动 14:其他
		
		char ssid[64];
		char passwd[64];
		char version[64];
	} sNvrWifiParamS;

	typedef struct {
		int    num;
		char   devs[0]; //sNvrWifiDev
	} sNvrWifiConDevS;

	typedef	struct
	{
		float  rate;
		char   mac[20];
	} sNvrWifiDev;	

	typedef struct {
		sNvrWifiParamS param;
		
		sNvrWifiConDevS devs;
	} sNvrWifiInfoS;

	typedef struct {
		char ssid[64];
		char passwd[64];
	} sNvrWifiSetSPS;

	typedef struct {
		int  channel;
	} sNvrWifiSetChanS;

	typedef struct {
		int   value;  //value : 0~100, < 0 falied
	} sNvrWifiResetBarS;

	typedef sNvrWifiResetBarS sNvrWifiUpdateBarS;

    int nvr_sdk_init(int port);
    void nvr_sdk_uninit(void);

#ifdef __cplusplus
}
#endif

#endif

