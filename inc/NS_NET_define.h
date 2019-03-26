#ifndef	NS_NET_DEFINE_H 
#define	NS_NET_DEFINE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#ifdef WIN32 //windows 编译, 在工程里指定了编译选项
#define NS_OS_TYPE NS_OS_WIN32
    typedef unsigned __int64  NS_U64;
#else
#define NS_OS_LINUX 1
#define NS_OS_WIN32 2
#define NS_OS_TYPE NS_OS_LINUX
    typedef unsigned long long  NS_U64;
#define SOCKET       int
#define SOCKET_ERROR (-1)
#endif

    /************************************************************************/
    /*   通用宏定义                                                         */
    /************************************************************************/
#ifndef MIN
#define MIN(a,b) (a)<(b)?(a):(b)
#endif
#define NS_MAX_PATH             256
#define NS_MAX_CHN_NUM        16
#define NS_MAX_DISK_NUM       8
#define NS_NAME_LEN           32
#define NS_ENCTRY_STR_LEN     NS_NAME_LEN
#define NS_EMAIL_NUM          3
#define NS_IP_LEN             36
#define NS_PATHNAME_LEN       128
#define NS_MAX_DOMAIN_NAME    64
#define NS_MAX_SENSOR_IN      16
#define NS_SENSOR_OUT         16
#define NS_MAX_PTZ_SPEED	  63
#define ASSIGN_FOUR_BYTES(number) (((number) + 3) / 4 * 4)
#define LIVE_CLIENT_INVALID_THD_ID    (0xFFFFFFFF)


#define NS_AUDIO_DECODER_BUF_SIZE       2048*4
#define NS_SPROP_PARAMETER_SETS_LEN     512
#define NS_DEV_RECORD_SCHEDULE_PARTS    24
#define NS_MAX_MOTION_DETECTION_NUM     4
#define NS_MAX_ALARM_HOST_NUM           10
#define NS_MAX_PRESET_NUM               209
#define NS_MAX_TRACK_NUM                16
#define NS_MAX_TRACK_NUM_NXP            4
#define NS_MAX_PRESETS_IN_TRACK         NS_MAX_PRESET_NUM
#define NS_MAX_PRESETS_IN_TRACK_NXP     32
#define NS_MAX_STAY_TIME                255
#define NS_MAX_PTZ_PROTOCOL_NUM         32
#define NS_MAX_CHANNEL_NUM              4
#define NS_MAX_VIDEO_ENCTYPE_NUM        8
#define NS_MAX_VIDEO_FORMAT_NUM         4
#define NS_MAX_VIDEO_STANDARD_NUM       3
#define NS_MAX_USER_NUM                 8
#define NS_MAX_DISK_NUM                 8
#define NS_MAX_VIDEO_MASK_NUM           8
#define NS_MIN_HOLD_TIME                10
#define NS_MIN_INTERVAL                 10
#define NS_FILE_NUM_PER_PAGE            100
#define NS_PTZ_CMD_PACKET_LEN           128
#define NS_PTZ20_CMD_RESULT_LEN         1024
#define NS_HD_VIDEO_WIDTH				1920
#define NS_HD_VIDEO_HEIGHT				1080

    /************************************************************************/
    /* 服务器操作命令                                                   */
    /************************************************************************/
#define    NS_CMD_REBOOT_DEVICE       0x00000001  //重启设备,Param:NS_CMD_INFO_S
#define    NS_CMD_RESTART_SERVICE     0x00000002  //重启设备的守护进程,Param:NS_CMD_INFO_S
#define    NS_CMD_RESTORE_SETTING     0x00000003  //恢复出场设置,Param:NS_CMD_INFO_S
#define    NS_CMD_DEV_RECORD_START    0x00000004  //开始前端录像,Param:NS_CMD_INFO_S
#define    NS_CMD_DEV_RECORD_STOP     0x00000005  //停止前端录像,Param:NS_CMD_INFO_S

    /************************************************************************/
    /* 获取服务器参数命令                                                   */
    /************************************************************************/
#define    NS_CMD_GET_GEN_CMD               0x20000000  //获取配置的通用处理
#define    NS_CMD_GET_SERVER_INFO           0x20000001  //服务器信息,Param:NS_SERVER_INFO_S
#define    NS_CMD_GET_AUDIO_INFO            0x20000002  //音频信息,Param:NS_AUDIO_INFO_S
#define    NS_CMD_GET_CA_SOUND_INFO         0x20000003  //报警联动：SOUND相关配置,Param:NS_CA_SOUND_INFO_S
#define    NS_CMD_GET_CA_FTP_INFO           0x20000004  //报警联动：FTP相关配置,Param:NS_CA_FTP_INFO_S
#define    NS_CMD_GET_CA_EMAIL_INFO         0x20000005  //报警联动：EMAIL相关配置,Param:NS_CA_EMAIL_INFO_S
#define    NS_CMD_GET_CA_CENTER_INFO        0x20000006  //报警联动：CENTER相关配置,Param:NS_CA_CENTER_INFO_S
#define    NS_CMD_GET_CA_RECORD_INFO        0x20000007  //报警联动：RECORD相关配置,Param:NS_CA_RECORD_INFO_S
#define    NS_CMD_GET_CA_MD_INFO            0x20000008  //报警联动：移动侦测相关配置,Param:NS_CA_MD_INFO_S
#define    NS_CMD_GET_CA_VL_INFO            0x20000009  //报警联动：视频丢失相关配置,Param:NS_CA_VL_INFO_S
#define    NS_CMD_GET_CA_AI_INFO            0x20000010  //报警联动：报警输入相关配置,Param:NS_CA_AI_INFO_S
#define    NS_CMD_GET_CA_AO_INFO            0x20000011  //报警联动：报警输出相关配置,Param:NS_CA_AO_INFO_S
#define    NS_CMD_GET_COLOR_INFO            0x20000012  //色彩相关配置,Param:NS_COLOR_INFO_S
#define    NS_CMD_GET_PTZ_INFO              0x20000014  //PTZ相关配置,Param:NS_PTZ_INFO_S
#define    NS_CMD_GET_DEV_RECORD_INFO       0x20000015  //设备录像相关配置,Param:NS_DEV_RECORD_INFO_S
#define    NS_CMD_GET_VIDEO_MASK_INFO       0x20000016  //区域覆盖相关配置,Param:NS_VIDEO_MASK_INFO_S
#define    NS_CMD_GET_MD_INFO               0x20000017  //移动侦测相关配置,Param:NS_MD_INFO_S
#define    NS_CMD_GET_NET3G_INFO            0x20000018  //3G网络相关配置,Param:NS_NET3G_INFO_S
#define    NS_CMD_GET_WIFI_INFO             0x20000019  //Wifi网络相关配置,Param:NS_WIFI_INFO_S
#define    NS_CMD_GET_ETHER_NET_INFO        0x20000020  //以太网络相关配置,Param:NS_ETHER_NET_INFO_S
#define    NS_CMD_GET_OSD_INFO              0x20000021  //OSD相关配置,Param:NS_OSD_INFO_S
#define    NS_CMD_GET_ALARM_HOST_INFO       0x20000022  //报警主机相关配置,Param:NS_ALARM_HOST_INFO_S
#define    NS_CMD_GET_GUARDER_INFO          0x20000023  //看守位相关配置,Param:NS_GUARDER_INFO_S
#define    NS_CMD_GET_PRESET_INFO           0x20000024  //预置位相关配置,Param:NS_PRESET_INFO_S
#define    NS_CMD_GET_TRACK_INFO            0x20000025  //轨迹相关配置,Param:NS_TRACK_INFO_S
#define    NS_CMD_GET_BPS_INFO              0x20000026  //码率相关配置,Param:NS_BPS_INFO_S
#define    NS_CMD_GET_VIDEO_INFO            0x20000027  //视频相关配置,Param:NS_VIDEO_INFO_S
#define    NS_CMD_GET_USER_INFO             0x20000028  //用户相关配置,Param:NS_USER_INFO_S
#define    NS_CMD_GET_AUTH_INFO             0x20000029  //权限校验模式,Param:NS_AUTH_INFO_S
#define    NS_CMD_GET_VIDEO_LOSS_INFO       0x20000032  //视频丢失,Param:NS_VIDEO_LOSS_INFO_S
#define    NS_CMD_GET_ALARM_IN_INFO         0x20000033  //报警输入,Param:NS_ALARM_IN_INFO_S
#define    NS_CMD_GET_PORT_INFO             0x20000034  //通讯端口,Param:NS_PORT_INFO_S
#define    NS_CMD_GET_UPNP_INFO             0x20000035  //UPNP配置,Param:NS_UPNP_INFO_S
#define    NS_CMD_GET_PPPOE_INFO            0x20000036  //PPPOE配置,Param:NS_PPPOE_INFO_S
#define    NS_CMD_GET_DDNS_INFO             0x20000037  //DDNS配置,Param:NS_DDNS_INFO_S
#define    NS_CMD_GET_TIME_INFO             0x20000038  //时间配置,Param:NS_TIME_INFO_S
#define    NS_CMD_GET_ENCRYPT_STR           0x20000041  //获取加密字符串,Param:NS_ENCRYPT_STR_S
#define    NS_CMD_GET_VIDEO_CHANNEL_INFO    0x20000042  //获取视频通道信息,Param:NS_VIDEO_CHANNEL_INFO_S
#define    NS_CMD_GET_VIDEO_SHELTER_INFO    0x20000044  //视频遮盖,Param:NS_VIDEO_SHELTER_S
#define    NS_CMD_GET_SAMBA_INFO            0x20000045  //时间配置,Param:NS_SAMBA_INFO_S
#define    NS_CMD_GET_DEV_CAPS				0x20000046  //时间配置,Param:NS_DEV_CAPS_S

#define    NS_CMD_GET_WA_IMAGE_PARAM        0x30000100  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_GET_WA_FOCUS_STATUS       0x30000101  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_GET_WA_CAMERA_INFO		0x30000107  //WENAN,Param:NS_WA_CAMERA_INFO_S


    /************************************************************************/
    /* 设置服务器参数命令                                                   */
    /************************************************************************/
#define    NS_CMD_SET_GEN_CMD               0x30000000  //设置配置的通用处理
#define    NS_CMD_SET_SERVER_INFO           0x30000001  //服务器信息,Param:NS_SERVER_INFO_S
#define    NS_CMD_SET_AUDIO_INFO            0x30000002  //音频信息,Param:NS_AUDIO_INFO_S
#define    NS_CMD_SET_CA_SOUND_INFO         0x30000003  //报警联动：SOUND相关配置,Param:NS_CA_SOUND_INFO_S
#define    NS_CMD_SET_CA_FTP_INFO           0x30000004  //报警联动：FTP相关配置,Param:NS_CA_FTP_INFO_S
#define    NS_CMD_SET_CA_EMAIL_INFO         0x30000005  //报警联动：EMAIL相关配置,Param:NS_CA_EMAIL_INFO_S
#define    NS_CMD_SET_CA_CENTER_INFO        0x30000006  //报警联动：CENTER相关配置,Param:NS_CA_CENTER_INFO_S
#define    NS_CMD_SET_CA_RECORD_INFO        0x30000007  //报警联动：RECORD相关配置,Param:NS_CA_RECORD_INFO_S
#define    NS_CMD_SET_CA_MD_INFO            0x30000008  //报警联动：移动侦测相关配置,Param:NS_CA_MD_INFO_S
#define    NS_CMD_SET_CA_VL_INFO            0x30000009  //报警联动：视频丢失相关配置,Param:NS_CA_VL_INFO_S
#define    NS_CMD_SET_CA_AI_INFO            0x30000010  //报警联动：报警输入相关配置,Param:NS_CA_AI_INFO_S
#define    NS_CMD_SET_CA_AO_INFO            0x30000011  //报警联动：报警输出相关配置,Param:NS_CA_AO_INFO_S
#define    NS_CMD_SET_COLOR_INFO            0x30000012  //色彩相关配置,Param:NS_COLOR_INFO_S
#define    NS_CMD_SET_PTZ_INFO              0x30000014  //PTZ相关配置,Param:NS_PTZ_INFO_S
#define    NS_CMD_SET_DEV_RECORD_INFO       0x30000015  //设备录像相关配置,Param:NS_DEV_RECORD_INFO_S
#define    NS_CMD_SET_VIDEO_MASK_INFO       0x30000016  //区域覆盖相关配置,Param:NS_VIDEO_MASK_INFO_S
#define    NS_CMD_SET_MD_INFO               0x30000017  //移动侦测相关配置,Param:NS_MD_INFO_S
#define    NS_CMD_SET_NET3G_INFO            0x30000018  //3G网络相关配置,Param:NS_NET3G_INFO_S
#define    NS_CMD_SET_WIFI_INFO             0x30000019  //Wifi网络相关配置,Param:NS_WIFI_INFO_S
#define    NS_CMD_SET_ETHER_NET_INFO        0x30000020  //以太网络相关配置,Param:NS_ETHER_NET_INFO_S
#define    NS_CMD_SET_OSD_INFO              0x30000021  //OSD相关配置,Param:NS_OSD_INFO_S
#define    NS_CMD_SET_ALARM_HOST_INFO       0x30000022  //报警主机相关配置,Param:NS_ALARM_HOST_INFO_S
#define    NS_CMD_SET_GUARDER_INFO          0x30000023  //看守位相关配置,Param:NS_GUARDER_INFO_S
#define    NS_CMD_SET_PRESET_ADD            0x30000024 //增加预置位
#define    NS_CMD_SET_PRESET_DEL            0x30000025 //删除预置位
#define    NS_CMD_SET_TRACK                 0x30000026 //设置轨迹
#define    NS_CMD_SET_BPS_INFO              0x30000027 //设置轨迹
#define    NS_CMD_SET_USER_ADD              0x30000028 //增加用户 Param:NS_USER_CMD_S
#define    NS_CMD_SET_USER_DEL              0x30000029 //删除用户 Param:NS_USER_CMD_S
#define    NS_CMD_SET_USER_SET              0x30000030 //设置用户 Param:NS_USER_CMD_S
#define    NS_CMD_SET_AUTH_INFO             0x30000031  //权限校验模式,Param:NS_AUTH_INFO_S
#define    NS_CMD_SET_VIDEO_LOSS_INFO       0x30000032  //视频丢失,Param:NS_VIDEO_LOSS_INFO_S
#define    NS_CMD_SET_ALARM_IN_INFO         0x30000033  //报警输入,Param:NS_ALARM_IN_INFO_S
#define    NS_CMD_SET_BALL_VIDEO_MASK       0x30000034  //报警输入,Param:NS_BALL_VIDEO_MASK_S
#define    NS_CMD_SET_PORT_INFO             0x30000035  //通讯端口,Param:NS_PORT_INFO_S
#define    NS_CMD_SET_UPNP_INFO             0x30000036  //UPNP,Param:NS_UPNP_INFO_S
#define    NS_CMD_SET_PPPOE_INFO            0x30000037  //PPPOE,Param:NS_PPPOE_INFO_S
#define    NS_CMD_SET_DDNS_INFO             0x30000038  //DDNS,Param:NS_DDNS_INFO_S
#define    NS_CMD_SET_TIME_INFO             0x30000039  //时间配置,Param:NS_TIME_INFO_S

#define    NS_CMD_UPDATE_DEVICE             0x30000040  //设备升级,Param:NS_UPDATE_DEVICE_S
#define    NS_CMD_SET_ENCRYPT_STR           0x30000041  //设置加密字符串,Param:NS_ENCRYPT_STR_S
#define    NS_CMD_SET_TIME_SYNC				0x30000042  //低成本设备时间同步,Param:NS_TIME_SYNC_S
#define    NS_CMD_SET_VIDEO_CHANNEL_INFO    0x30000043  //设置视频通道信息,Param:NS_VIDEO_CHANNEL_INFO_S
#define    NS_CMD_SET_VIDEO_SHELTER_INFO       0x30000044  //视频丢失,Param:NS_VIDEO_SHELTER_S
#define    NS_CMD_SET_SAMBA_INFO             0x30000045  //samba配置,Param:NS_SAMBA_INFO_S
#define    NS_CMD_SET_DEVICE_LANG             0x30000046  //设备语言配置,Param:NS_DEVICE_LANG_S

#define    NS_CMD_SET_WA_IMAGE_PARAM				0x30000100  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_IMAGE_PARAM_DEFAULT        0x30000101  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_SHUTTER_MODE				0x30000102  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_SHUTTER_SPEED				0x30000103  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_NORTH						0x30000104  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_SHOW_ANGLE					0x30000105  //WENAN,Param:NS_WA_IMAGE_PARAM_S
#define    NS_CMD_SET_WA_OSD_INFO					0x30000106  //WENAN,Param:NS_WA_OSD_INFO_S

    /************************************************************************/
    /* 云台指令                                                             */
    /************************************************************************/
#define    NS_CMD_PTZ_UP              0x40000001 //云台向上,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_DOWN            0x40000002 //云台向下,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_LEFT            0x40000003 //云台向左,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_RIGHT           0x40000004 //云台向右,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_LEFT_UP         0x40000005 //云台向左上,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_LEFT_DOWN       0x40000006 //云台向左下,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_RIGHT_UP        0x40000007 //云台向右上,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_RIGHT_DOWN      0x40000008 //云台向右下,fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_FOCUS_SUB       0x40000009 //Focus sub, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_FOCUS_ADD       0x4000000A //Focus add, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_ZOOM_SUB        0x4000000B //Zoom sub, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_ZOOM_ADD        0x4000000C //Zoom add, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_IRIS_SUB        0x4000000D //Iris sub, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_IRIS_ADD        0x4000000E //Iris add, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_BRUSH           0x4000000F //雨刷, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S
#define    NS_CMD_PTZ_AUTO            0x40000010 //自动, fun:NS_NET_PTZControl,Param:NS_PTZ_CMD_S

#define    NS_CMD_PTZ_PRESET          0x40000011 //调用预置位
#define    NS_CMD_PTZ_TRACK           0x40000012 //调用轨迹

#define    NS_CMD_PTZ20               0x40000013 //调用PTZ20

    typedef enum
    {
         NS_PTZ20_CMD_CODE_INVALID         = 0,
         NS_PTZ20_CMD_CODE_SEQUENCE_RUN         ,
         NS_PTZ20_CMD_CODE_SEQUENCE_STOP        ,
         NS_PTZ20_CMD_CODE_SEQUENCE_DEL         ,
         NS_PTZ20_CMD_CODE_SEQUENCE_CLR         ,
         NS_PTZ20_CMD_CODE_SEQUENCE_INS_PRES    ,
         NS_PTZ20_CMD_CODE_SEQUENCE_DEL_PRES    ,
         NS_PTZ20_CMD_CODE_SEQUENCE_DWELL_TIME  ,
         NS_PTZ20_CMD_CODE_SEQUENCE_SPEED       ,

         NS_PTZ20_CMD_CODE_AUTO_PAN_RUN         ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_STOP        ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_DEL         ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_LEFT_LIMIT  ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_RIGHT_LIMIT ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_CLEAN_TITLE ,
         NS_PTZ20_CMD_CODE_AUTO_PAN_SPEED       ,

         NS_PTZ20_CMD_CODE_PATTERN_RUN          ,
         NS_PTZ20_CMD_CODE_PATTERN_STOP         ,
         NS_PTZ20_CMD_CODE_PATTERN_DEL          ,
         NS_PTZ20_CMD_CODE_PATTERN_CREATE_BEGIN ,
         NS_PTZ20_CMD_CODE_PATTERN_CREATE_END   ,
         NS_PTZ20_CMD_CODE_PATTERN_CLEAN_TITLE  ,

         NS_PTZ20_CMD_CODE_IDLE_OFF             ,
         NS_PTZ20_CMD_CODE_IDLE_SEQUENCE        ,
         NS_PTZ20_CMD_CODE_IDLE_PATTERN         ,
         NS_PTZ20_CMD_CODE_IDLE_AUTO_PAN        ,
         NS_PTZ20_CMD_CODE_IDLE_PRESET          ,
         NS_PTZ20_CMD_CODE_IDLE_TIME            ,

         NS_PTZ20_CMD_CODE_REGION_LEFT          ,
         NS_PTZ20_CMD_CODE_REGION_RIGHT         ,
         NS_PTZ20_CMD_CODE_REGION_DEL           ,
         NS_PTZ20_CMD_CODE_REGION_CLEAN_TITLE   ,

         NS_PTZ20_CMD_CODE_TITLE_ALL_ENABLE1    ,
         NS_PTZ20_CMD_CODE_TITLE_ALL_EBABLE2    ,
         NS_PTZ20_CMD_CODE_TITLE_DOME           ,
         NS_PTZ20_CMD_CODE_TITLE_PRESET         ,
         NS_PTZ20_CMD_CODE_TITLE_AUTO_PAN       ,
         NS_PTZ20_CMD_CODE_TITLE_SEQUENCE       ,
         NS_PTZ20_CMD_CODE_TITLE_PATTERN        ,
         NS_PTZ20_CMD_CODE_TITLE_REGION         ,
         NS_PTZ20_CMD_CODE_TITLE_DIRECT         ,
         NS_PTZ20_CMD_CODE_TITLE_LENS           ,
         NS_PTZ20_CMD_CODE_TITLE_TEMPERATURE    ,
         NS_PTZ20_CMD_CODE_TITLE_DC_POWER       ,
         NS_PTZ20_CMD_CODE_TITLE_SYS_TIME       ,
         NS_PTZ20_CMD_CODE_TITLE_SYS_DATA       ,
         NS_PTZ20_CMD_CODE_TITLE_LIGHT_SENSOR   ,
         NS_PTZ20_CMD_CODE_TITLE_ARM            ,

         NS_PTZ20_CMD_CODE_DATA_PROCESS           ,
         NS_PTZ20_CMD_CODE_DOME_POS_FUN           ,
         NS_PTZ20_CMD_CODE_CLEAR_SCREEN           ,
         NS_PTZ20_CMD_CODE_IRLED_INDOOR_MODE      ,
         NS_PTZ20_CMD_CODE_IRLED_DRIVE_MODE       ,
         NS_PTZ20_CMD_CODE_AUTO_FI                ,
         NS_PTZ20_CMD_CODE_AUTO_FOCUS_TIME        ,
         NS_PTZ20_CMD_CODE_AUTO_IRIS_TIME         ,
         NS_PTZ20_CMD_CODE_OSD_COLOR              ,
         NS_PTZ20_CMD_CODE_OSD_POS_H              ,
         NS_PTZ20_CMD_CODE_OSD_POS_V              ,
         NS_PTZ20_CMD_CODE_IRLED_SENSOR_TYPE      ,
         NS_PTZ20_CMD_CODE_IRLED_OPEN_LIMIT       ,
         NS_PTZ20_CMD_CODE_DOME_MENU              ,
         NS_PTZ20_CMD_CODE_CAMERA_MENU            ,
         NS_PTZ20_CMD_CODE_DOME_TITLE_RANGE       ,
         NS_PTZ20_CMD_CODE_DOME_PSPEED_LEVEL_H    ,
         NS_PTZ20_CMD_CODE_DOME_PSPEED_LEVEL_V    ,
         NS_PTZ20_CMD_CODE_TEMPATURE_UNIT         ,
         NS_PTZ20_CMD_CODE_ZOOM_PT_SPEED          ,
         NS_PTZ20_CMD_CODE_DOOM_WIPERS            ,
         NS_PTZ20_CMD_CODE_DOME_FUN               ,
         NS_PTZ20_CMD_CODE_DOME_HEAT              ,
         NS_PTZ20_CMD_CODE_CLEAR_SCREEN_LINE      ,
         NS_PTZ20_CMD_CODE_TIMER_IRCUT_DAY        ,
         NS_PTZ20_CMD_CODE_TIMER_IRCUT_NIGHT      ,
         NS_PTZ20_CMD_CODE_DOOM_AUTO_BOOT_CLOSE   ,
         NS_PTZ20_CMD_CODE_DOOM_AUTO_BOOT_OPEN    ,
         NS_PTZ20_CMD_CODE_BOOT_INFO              ,

         NS_PTZ20_CMD_CODE_INQ_DARM_INPUT         ,
         NS_PTZ20_CMD_CODE_DRAM_OUTPUT_DRV        ,
         NS_PTZ20_CMD_CODE_DRAM_UPLOAD_MODE       ,
         NS_PTZ20_CMD_CODE_DRAM_ENABLE_MODE       ,
         NS_PTZ20_CMD_CODE_DRAM_ENABLE            ,
         NS_PTZ20_CMD_CODE_DRAM_INPUT_STATUS      ,
         NS_PTZ20_CMD_CODE_DRAM_PRESET            ,
         NS_PTZ20_CMD_CODE_DRAM_AUTO_PAN          ,
         NS_PTZ20_CMD_CODE_DRAM_SEQUENCE          ,
         NS_PTZ20_CMD_CODE_DRAM_PATTERN           ,
         NS_PTZ20_CMD_CODE_DRAM_OUTPUT_MODE       ,
         NS_PTZ20_CMD_CODE_DRAM_ACK_DELAY         ,
         NS_PTZ20_CMD_CODE_DRAM_ALARM_START_H     ,
         NS_PTZ20_CMD_CODE_DRAM_ALARM_START_M     ,
         NS_PTZ20_CMD_CODE_DRAM_ALARM_STOP_H      ,
         NS_PTZ20_CMD_CODE_DRAM_ALARM_STOP_M      ,

         NS_PTZ20_CMD_CODE_INQ_DOME_CONFIG        ,
         NS_PTZ20_CMD_CODE_INQ_DOME_STATUS        ,
         NS_PTZ20_CMD_CODE_INQ_PAN_POS            ,
         NS_PTZ20_CMD_CODE_INQ_PT_POS             ,
         NS_PTZ20_CMD_CODE_INQ_DOME_POS           ,
         NS_PTZ20_CMD_CODE_INQ_DOME_SN            ,
         NS_PTZ20_CMD_CODE_INQ_DOME_MODEL         ,
         NS_PTZ20_CMD_CODE_INQ_CAMERA_MODEL       ,
         NS_PTZ20_CMD_CODE_INQ_DOME_VERSION       ,
         NS_PTZ20_CMD_CODE_INQ_DOME_CLOCK         ,
         NS_PTZ20_CMD_CODE_INQ_TEMPERATURE        ,
         NS_PTZ20_CMD_CODE_INQ_VOLTAGE            ,
         NS_PTZ20_CMD_CODE_INQ_FUN_SPEED          ,
         NS_PTZ20_CMD_CODE_INQ_ILLUM              ,
         NS_PTZ20_CMD_CODE_INQ_DOME_TITLE         ,
         NS_PTZ20_CMD_CODE_INQ_PRESET_TITLE       ,
         NS_PTZ20_CMD_CODE_INQ_AUTO_PAN_TITLE     ,
         NS_PTZ20_CMD_CODE_INQ_SEUQENCE_TITLE     ,
         NS_PTZ20_CMD_CODE_INQ_PATTERN_TITLE      ,
         NS_PTZ20_CMD_CODE_INQ_REGION_TITLE       ,
         NS_PTZ20_CMD_CODE_INQ_CAMERA_VERSION     ,

         NS_PTZ20_CMD_CODE_SET_PAN_POS            ,
         NS_PTZ20_CMD_CODE_SET_PT_POS             ,
         NS_PTZ20_CMD_CODE_SET_DOME_POS           ,
         NS_PTZ20_CMD_CODE_SET_DOME_SN            ,
         NS_PTZ20_CMD_CODE_SET_DOME_CLOCK         ,
         NS_PTZ20_CMD_CODE_SET_DOME_TITLE         ,
         NS_PTZ20_CMD_CODE_SET_PRESET_TITLE       ,
         NS_PTZ20_CMD_CODE_SET_AUTO_PAN_TITLE     ,
         NS_PTZ20_CMD_CODE_SET_SEQUENCE_TITLE     ,
         NS_PTZ20_CMD_CODE_SET_PATTERN_TITLE      ,
         NS_PTZ20_CMD_CODE_SET_REGION_TITLE       ,
         NS_PTZ20_CMD_CODE_SET_PRIVACY            ,
         NS_PTZ20_CMD_CODE_SET_3D_POS_1           ,
         NS_PTZ20_CMD_CODE_SET_3D_POS_2           ,
         NS_PTZ20_CMD_CODE_SET_3D_POS_3           ,
         NS_PTZ20_CMD_CODE_SET_DOME_ALARM         ,
         NS_PTZ20_CMD_CODE_SET_OSD_INFO           ,
         NS_PTZ20_CMD_CODE_SET_DEV_LOGO           ,

         NS_PTZ20_CMD_CODE_CMR_DEFAULT            ,
         NS_PTZ20_CMD_CODE_CMR_RESET              ,
         NS_PTZ20_CMD_CODE_CMR_AE                 ,
         NS_PTZ20_CMD_CODE_CMR_BLC                ,
         NS_PTZ20_CMD_CODE_CMR_MODE_FUN           ,
         NS_PTZ20_CMD_CODE_CMR_IMAGE_POS_H        ,
         NS_PTZ20_CMD_CODE_CMR_IMAGE_POS_V        ,
         NS_PTZ20_CMD_CODE_CMR_PRIVACY            ,
         NS_PTZ20_CMD_CODE_CMR_PRIVACY_COLOR      ,

         NS_PTZ20_CMD_CODE_PRO_IMPORTANCE_CMD   = 1000,
         NS_PTZ20_CMD_CODE_PRO_CLEAR_EEPROM     ,
         NS_PTZ20_CMD_CODE_PRO_FAC_DEFAULT      ,
         NS_PTZ20_CMD_CODE_PRO_DEFAULT          ,
         NS_PTZ20_CMD_CODE_PRO_HARDWARE_TEST    ,
         NS_PTZ20_CMD_CODE_PRO_AGING_TEST       ,
         NS_PTZ20_CMD_CODE_PRO_TITLE_INIT       ,
         NS_PTZ20_CMD_CODE_PRO_SET_CAMERA_MODE  ,
         NS_PTZ20_CMD_CODE_PRO_SET_DOME_ID      ,
         NS_PTZ20_CMD_CODE_PRO_SET_WIPER_POS    ,
         NS_PTZ20_CMD_CODE_PRO_SET_TITLE_POS    ,
         NS_PTZ20_CMD_CODE_PRO_SET_LAGNUAGE     ,
         NS_PTZ20_CMD_CODE_PRO_HARDWARE_TEST_STOP    ,
         NS_PTZ20_CMD_CODE_PRO_AGING_TEST_STOP  ,
         NS_PTZ20_CMD_CODE_PRO_GET_TEST_REPORT  ,
    }NS_PTZ20_CMD_CODE_E;





    /************************************************************************/
    /* 服务器配置信息结构                                                   */
    /************************************************************************/
    //服务器信息NS_CMD_GET_SERVER_INFO
    typedef struct tagNS_SERVER_INFO
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
        char           channels[NS_MAX_CHANNEL_NUM][NS_NAME_LEN];//通道
    }NS_SERVER_INFO_S,*PNS_SERVER_INFO_S;

    typedef enum
    {
        NS_AUDIO_CODEC_FORMAT_BEGIN	= -1,
        NS_AUDIO_CODEC_FORMAT_PCM,				// Raw PCM
        NS_AUDIO_CODEC_FORMAT_G711A, 			// G.711 A
        NS_AUDIO_CODEC_FORMAT_G711U, 			// G.711 Mu
        NS_AUDIO_CODEC_FORMAT_ADPCM, 			// ADPCM
        NS_AUDIO_CODEC_FORMAT_G726, 			// G.726
        NS_AUDIO_CODEC_FORMAT_AMRNB, 			// AMR encoder format narrow band
        NS_AUDIO_CODEC_FORMAT_AMRWB, 			// AMR encoder formant wide band
        NS_AUDIO_CODEC_FORMAT_AAC, 			// AAC encoder 
        NS_AUDIO_CODEC_FORMAT_END
    } NS_AUDIO_CODEC_FORMAT_E;

    typedef enum NS_AMR_BPS_E										// 设备端Amr编码码率
    {
        NS_AMR_BPS_Unknown	= -1,
        NS_AMR_BPS_4K75		= 0,
        NS_AMR_BPS_5K15		= 1,
        NS_AMR_BPS_5K9		= 2,
        NS_AMR_BPS_6K7		= 3,
        NS_AMR_BPS_7K4		= 4,
        NS_AMR_BPS_7K95		= 5,
        NS_AMR_BPS_10K2		= 6,
        NS_AMR_BPS_12K2		= 7,
    }NS_AMR_BPS_E;

    typedef struct  
    {
        unsigned int dwSize;
    }NS_CMD_INFO_S;

    typedef struct  
    {
        unsigned int dwSize;
        unsigned int  bEnable;
        unsigned int  nVolumeInput;
        unsigned int  nVolumeOutput;
        NS_AUDIO_CODEC_FORMAT_E emArCodecType;
        NS_AMR_BPS_E emAmrBps;
    }NS_AUDIO_INFO_S;

    typedef struct
    {
        int bps;
        int maxbps;
        int brmode;  /*0:CBR, 1:VBR*/
        int preferfps; /*0:质量优先, 1:码率有限*/
        int fps;
        int maxfps;
        int gop;
    }NS_BPS_INFO_T;

    typedef struct
    {
        unsigned int dwSize;
        NS_BPS_INFO_T bps;
    }NS_BPS_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int lang;
    }NS_DEVICE_LANG_S;


    typedef enum 
    {
        NS_VENCODE_TYPE_UNKNOWN	= -1,
        NS_VENCODE_TYPE_QCIF	= 0,								// QCIF
        NS_VENCODE_TYPE_CIF		= 1,								// CIF
        NS_VENCODE_TYPE_D1		= 2,								// D1
        NS_VENCODE_TYPE_720P	= 3,								// 720P
        NS_VENCODE_TYPE_UVGA	= 4,								// UVGA
        NS_VENCODE_TYPE_1080P	= 5,								// 1080P
        NS_VENCODE_TYPE_QVGA	= 6,
        NS_VENCODE_TYPE_VGA		= 7,
        NS_VENCODE_TYPE_960P	= 8,
        NS_VENCODE_TYPE_3M		= 9,
        NS_VENCODE_TYPE_180P	= 10,
        NS_VENCODE_TYPE_360P	= 11,
        NS_VENCODE_TYPE_4M		= 12,
  } NS_VENCODE_TYPE_E;

    typedef enum 
    {
        NS_VENCODE_FORMAT_UNKNOWN	= -1,	
        NS_VENCODE_FORMAT_H261	= 0,								// H261
        NS_VENCODE_FORMAT_H263	= 1,								// H263
        NS_VENCODE_FORMAT_H264	= 2,								// H264
        NS_VENCODE_FORMAT_H265	= 3,								// H264
        NS_VENCODE_FORMAT_MPEG2	= 4,								// MPEG2
        NS_VENCODE_FORMAT_MPEG4	= 5,								// MPEG4
        NS_VENCODE_FORMAT_MJPEG	= 6,								// MOTION_JPEG
    } NS_VENCODE_FORMAT_E;

    typedef enum 
    {
        NS_VI_STANDARD_UNKNOWN	= -1,
        NS_VI_STANDARD_PAL		= 0,
        NS_VI_STANDARD_NTSC		= 1,
        NS_VI_STANDARD_AUTO		= 2,
    } NS_VI_STANDARD_E;

    typedef struct
    {
        char cmd[1024];
        char reply[1024];
    } NS_GEN_INFO_S;
    
    typedef struct NS_CHANNEL_INFO_T
    {
        NS_VENCODE_FORMAT_E	format;					// 视频压缩类型 (H264,MPEG4 ...)
        NS_VENCODE_TYPE_E	enctype;				// 编码器类型	(QCIF,CIF,D1 ...)
        NS_VI_STANDARD_E	standard;				// 视频制式		(PAL NTSC AUTO ...)
        unsigned int 		vi;				// 视频输入通道索引(0 -- n)
    } NS_CHANNEL_INFO_T;

    typedef struct
    {
        unsigned int validvinum;
        unsigned int validvenum;
        unsigned int enctypenum;
        NS_VENCODE_TYPE_E enctypes[NS_MAX_VIDEO_ENCTYPE_NUM];
        unsigned int formatnum;
        NS_VENCODE_FORMAT_E formats[NS_MAX_VIDEO_FORMAT_NUM];
        unsigned int standardnum;
        NS_VI_STANDARD_E standards[NS_MAX_VIDEO_STANDARD_NUM];
        unsigned int channelnum;
        NS_CHANNEL_INFO_T channels[NS_MAX_CHANNEL_NUM];
    }NS_VIDEO_INFO_T;

    typedef struct
    {
        unsigned int dwSize;
        NS_VIDEO_INFO_T videoinfo;
    }NS_VIDEO_INFO_S;

    typedef struct
    {
        unsigned int dwSize;

		unsigned int enable0;
		NS_VENCODE_FORMAT_E codec0;
		NS_VENCODE_TYPE_E vencsize0;

		unsigned int enable1;
		NS_VENCODE_FORMAT_E codec1;
		NS_VENCODE_TYPE_E vencsize1;
    }NS_VIDEO_CHANNEL_INFO_S;
	
    typedef enum
    {
        NS_USER_GROUP_ADMIN = 0,
        NS_USER_GROUP_OPERATOR,
        NS_USER_GROUP_GUEST,
    }NS_USER_GROUP_E;

    typedef struct  
    {
        char    user[NS_NAME_LEN];
        char    passwd[NS_NAME_LEN];
        NS_USER_GROUP_E group; 
    }NS_USER_T;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int usernum;
        NS_USER_T   users[NS_MAX_USER_NUM];
    }NS_USER_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        NS_USER_T   user;
    }NS_USER_CMD_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int enable;
    }NS_AUTH_INFO_S;

    typedef struct
    {
        int interval;
        int ai0en;
        int ai1en;
        int ai2en;
        int ai3en;
        int mden;
        int vlen;
    }NS_CA_COMMON_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        NS_CA_COMMON_INFO_S common;
        char achost[NS_NAME_LEN];
        int  acport;   
    }NS_CA_CENTER_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        NS_CA_COMMON_INFO_S common;

        char smtpserver[NS_NAME_LEN];
        char smtpuser[NS_NAME_LEN];
        char smtppasswd[NS_NAME_LEN];
        char toaddr[NS_NAME_LEN];
    }NS_CA_EMAIL_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        NS_CA_COMMON_INFO_S common;

        char host[NS_NAME_LEN];
        char user[NS_NAME_LEN];
        char passwd[NS_NAME_LEN];
        char path[NS_NAME_LEN];
        int  type;
    }NS_CA_FTP_INFO_S;


    typedef struct
    {
        unsigned int dwSize;
        NS_CA_COMMON_INFO_S common;

        int  recordtime;
    }NS_CA_RECORD_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        NS_CA_COMMON_INFO_S common;
    }NS_CA_SOUND_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int ao0;
        int ao1;
        int ao0alarm;
        int ao1alarm;
        int holdtime;
    }NS_CA_AO_INFO_S;

    typedef struct  
    {
        unsigned int dwSize;
        int interval;
        int acen;
        int emailen;
        int ao0en;
        int ao1en;
        int recorden;
        int sounden;
    }NS_CA_VL_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int interval;
        int acen;
        int emailen;
        int ao0en;
        int ao1en;
        int recorden;
        int sounden;
        int ftpen;
        int captureen;
    }NS_CA_MD_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int id;
        int interval;
        int acen;
        int emailen;
        int ao0en;
        int ao1en;
        int recorden;
        int sounden;
        int ftpen;
        int captureen;

        char preset[NS_NAME_LEN];
    }NS_CA_AI_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int bright;
        int contrast;
        int hue;
        int saturation;
        int lampfrequency;
        int reverse;
        int gain;
    }NS_COLOR_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int type;
        int baud;
        int data;
        int stop;
        int parity;
        int addr;
        int hreverse;
        int vreverse;
        char protocol[NS_NAME_LEN];
        int protocolCount;
        char protocols[NS_MAX_PTZ_PROTOCOL_NUM][NS_NAME_LEN];
    }NS_PTZ_INFO_S;

    typedef struct 
    {
        int bEnable[7];
        int schedule[7][NS_DEV_RECORD_SCHEDULE_PARTS];
    }NS_SCHEDULE_S;

    typedef enum 				// 前端录像 状态
    {
        NS_DEV_RECORD_STATUS_STOP	= 0,					// 前端录像 停止
        NS_DEV_RECORD_STATUS_MANUAL	= 1,				// 前端录像 手动录像
        NS_DEV_RECORD_STATUS_ALARM	= 2,				// 前端录像 报警录像
        NS_DEV_RECORD_STATUS_MD,                       // 正在移动录像
        NS_DEV_RECORD_STATUS_SCHEDULE,                 // 正在计划任务录像
        NS_DEV_RECORD_STATUS_SNAP,                     // 正在抓图
    } NS_DEV_RECORD_STATUS_E;

    typedef enum
    {
        NS_DEV_RECORD_SIZE_QCIF = 0,         // QCIF
        NS_DEV_RECORD_SIZE_CIF  = 1,         // CIF
        NS_DEV_RECORD_SIZE_D1   = 2,         // D1
        NS_DEV_RECORD_SIZE_720P = 3,         // 720P
        NS_DEV_RECORD_SIZE_UVGA = 4,         // UVGA
        NS_DEV_RECORD_SIZE_1080P = 5,        // 1080P
    } NS_DEV_RECORD_SIZE_E;

    typedef struct 				// 前端磁盘管理
    {
        char		diskname[NS_NAME_LEN];			// 磁盘名称
        unsigned int		disktotal;					// 磁盘总容量(M单位)
        unsigned int		diskfree;						// 磁盘剩余容量(M单位)
    }NS_DISK_INFO_S;

    typedef struct
    {
        unsigned int dwSize;//结构体大小
        int recordtime;		/*报警录像文件最大时长（秒）*/
        int diskreserve;	/*预留磁盘空间（兆）*/
        int diskstrategy;	/*磁盘策略*/
        int filetime;		/*报警录像文件最大时长（分钟）*/
        int filestrategy;	/*文件策略*/
        NS_DEV_RECORD_SIZE_E rcrdchn;	/*录像所用的通道*/
        int prerecorden;	/*预录像开关*/
        NS_DEV_RECORD_STATUS_E recordstatus0;	/*录像状态*/
        NS_SCHEDULE_S schedule;	/*录像计划*/
        int disknum;		/*磁盘数*/
        NS_DISK_INFO_S disks[NS_MAX_DISK_NUM];	/*磁盘信息*/
    }NS_DEV_RECORD_INFO_S;

#define NS_MOTION_DETECTION_GRID_COLUMN (352/16)
#define NS_MOTION_DETECTION_GRID_ROW    (288/16)
    typedef struct
    {
        unsigned int dwSize;
        int enable;
        int thresh;
        char grid[NS_MOTION_DETECTION_GRID_ROW][NS_MOTION_DETECTION_GRID_COLUMN];
        NS_SCHEDULE_S schedule;
    }NS_MD_INFO_S;

	typedef struct 
	{
		int    left;
		int    top;
		int    right;
		int    bottom;
	} NS_RECT_T;
	
	typedef struct
	{
		NS_RECT_T rects[NS_MAX_MOTION_DETECTION_NUM];
	}NS_MD_AREA_S;
	
    typedef enum 
    {
        NS_WEEK_SUNDAY		= 0,
        NS_WEEK_MONDAY		= 1,
        NS_WEEK_TUESDAY		= 2,
        NS_WEEK_WEDNESDAY	= 3,
        NS_WEEK_THURSDAY		= 4,
        NS_WEEK_FRIDAY		= 5,
        NS_WEEK_SATURDAY		= 6
    } NS_WEEK_DATE_E;

    typedef struct 								// 布防规则
    {	
        NS_WEEK_DATE_E	emDate;					// 布防日期
        int		bEnable;					// 启用该日期布防
        int			nTime;						// 布防时间段
    }NS_WEEK_TIME_S;

    typedef struct 							// 布防规则结构数组
    {
        NS_WEEK_TIME_S	eWeekTime[7];				// 布防规则
    }NS_WEEK_TIME_S_EX;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int enable;
        unsigned int thresh;
        NS_SCHEDULE_S schedule;
    }NS_VIDEO_LOSS_INFO_S;

	typedef NS_VIDEO_LOSS_INFO_S NS_VIDEO_SHELTER_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int ai0en;
        unsigned int ai1en;
        unsigned int ai2en;
        unsigned int ai3en;
        NS_SCHEDULE_S schedule;
        NS_SCHEDULE_S schedule1;
        NS_SCHEDULE_S schedule2;
        NS_SCHEDULE_S schedule3;
    }NS_ALARM_IN_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int rtsp;
        unsigned int web;
        unsigned int ftp;
        unsigned int audio;
        unsigned int update;
        unsigned int merge;
        unsigned int rtsp_upnp;
        unsigned int web_upnp;
        unsigned int ftp_upnp;
        unsigned int audio_upnp;
        unsigned int update_upnp;
    }NS_PORT_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int pppoeen;
        unsigned int nicsel;
        char pppoeuser[NS_NAME_LEN];
        char pppoepasswd[NS_NAME_LEN];
    }NS_PPPOE_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int ddnsen;
        unsigned int ddnsprovider;
        char ddnssupport0[NS_NAME_LEN];
        char ddnssupport1[NS_NAME_LEN];
        char ddnsuser[NS_NAME_LEN];
        char ddnspasswd[NS_NAME_LEN];
        char ddnsurl[NS_NAME_LEN];
        unsigned int status;
        char ddnsuser9299[NS_NAME_LEN];
        char ddnspasswd9299[NS_NAME_LEN];
        char ddnsurl9299[NS_NAME_LEN];
        unsigned int status9299;
    }NS_DDNS_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int rtspen;
        unsigned int httpen;
        unsigned int ftpen;
        unsigned int voiceen;
        unsigned int updateen;
    }NS_UPNP_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int time;
        unsigned int timezone;
        unsigned int ntpen;
        char ntphost[NS_NAME_LEN];
        unsigned int ntpport;
        unsigned int interval;
    }NS_TIME_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int enable;
        char path[NS_MAX_PATH];
        char user[NS_NAME_LEN];
        char passwd[NS_NAME_LEN];
    }NS_SAMBA_INFO_S;

    typedef enum
    {
        NS_BALL_VIDEO_MASK_ACTION_ADD = 0,
        NS_BALL_VIDEO_MASK_ACTION_DEL ,
        NS_BALL_VIDEO_MASK_ACTION_SET_COLOR ,
        NS_BALL_VIDEO_MASK_ACTION_SHOW ,
        NS_BALL_VIDEO_MASK_ACTION_HIDE ,
    }NS_BALL_VIDEO_MASK_ACTION_E;

    typedef enum
    {
        NS_BALL_VIDEO_MASK_ID_1 = 1,
        NS_BALL_VIDEO_MASK_ID_2 ,
        NS_BALL_VIDEO_MASK_ID_3 ,
        NS_BALL_VIDEO_MASK_ID_4 ,
    }NS_BALL_VIDEO_MASK_ID_E;

    typedef enum
    {
        NS_VIDEO_MASK_COLOR_1 = 1,
        NS_VIDEO_MASK_COLOR_2 ,
        NS_VIDEO_MASK_COLOR_3 ,
        NS_VIDEO_MASK_COLOR_4 ,
        NS_VIDEO_MASK_COLOR_5 ,
        NS_VIDEO_MASK_COLOR_6 ,
        NS_VIDEO_MASK_COLOR_7 ,
        NS_VIDEO_MASK_COLOR_8 ,
        NS_VIDEO_MASK_COLOR_9 ,
        NS_VIDEO_MASK_COLOR_10 ,
        NS_VIDEO_MASK_COLOR_11 ,
        NS_VIDEO_MASK_COLOR_12 ,
        NS_VIDEO_MASK_COLOR_13 ,
        NS_VIDEO_MASK_COLOR_14 ,
        NS_VIDEO_MASK_COLOR_15 ,
    }NS_VIDEO_MASK_COLOR_E;

    typedef struct
    {
        unsigned int dwSize;
        NS_BALL_VIDEO_MASK_ACTION_E action;
        NS_BALL_VIDEO_MASK_ID_E maskid;
        NS_VIDEO_MASK_COLOR_E maskcolor;
        unsigned int maskwidth;
        unsigned int maskheight;
    }NS_BALL_VIDEO_MASK_S;

    typedef struct
    {
        unsigned int masken;
        unsigned int left;
        unsigned int top;
        unsigned int right;
        unsigned int bottom;
        unsigned int color;
    }NS_VIDEO_MASK_S;

    typedef struct
    {
        unsigned int dwSize;
        unsigned int videomasknum;
        NS_VIDEO_MASK_S videomasks[NS_MAX_VIDEO_MASK_NUM];
    }NS_VIDEO_MASK_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        char eth0[NS_NAME_LEN];
        char ethip[NS_NAME_LEN];
        char ethmask[NS_NAME_LEN];
        char ethgw[NS_NAME_LEN];
        char dns[NS_NAME_LEN];
        char ethmac[NS_NAME_LEN];
        int		ethdhcp;
		int	ipadaen;
    }NS_ETHER_NET_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        char wifiname[NS_NAME_LEN];
        char wifiip[NS_NAME_LEN];
        char wifimask[NS_NAME_LEN];
        char wifimac[NS_NAME_LEN];
        char wifigw[NS_NAME_LEN];
        char ethmac[NS_NAME_LEN];
        char wifissid[NS_NAME_LEN];
        char apmacaddr[NS_NAME_LEN];
        char wifiweppass[NS_NAME_LEN];
        int		wifiexist;
        int		wifidhcp;
        int		wifien;
        int		wifimode;
        int		apstrategy;
        int		apchannel;
        int		wifisecen;
        int		wifiauthtype;
        int     wifisectype;
        int     wifiwepindex;
        int     wifiweptype;
    }NS_WIFI_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        char szname[NS_NAME_LEN];
        char apn[NS_NAME_LEN];
        char account[NS_NAME_LEN];
        char password[NS_NAME_LEN];
        char onlineaddr[NS_NAME_LEN];
        int		signal;
        int		pppstatus;
        int		hardwardstatus;
        int		initfailure;
        int		ben;
        int		rebooten;
        int		phonemmsen[8];
        int		onlinetype;
        NS_SCHEDULE_S schedule;
    }NS_NET3G_INFO_S;

    typedef struct
    {
        unsigned int dwSize;	/*结构体大小*/
        char name[NS_NAME_LEN];	/*叠加在视频上的通道名称*/
        int		timeen;			/*是否显示时间*/
        int		timeleft;		/*x坐标*/
        int		timetop;		/*y坐标*/
        int		bpsen;			/*是否显示码率*/
        int		bpsleft;		/*x坐标*/
        int		bpstop;			/*y坐标*/
        int		nameen;			/*是否显示通道名*/
        int		nameleft;		/*x坐标*/
        int     nametop;		/*y坐标*/
        int		gpsen;			/*是否显示GPS*/
        int		gpsleft;		/*x坐标*/
        int		gpstop;			/*y坐标*/
        int		osdcolormode;	/*颜色*/
    }NS_OSD_INFO_S;

    typedef struct  
    {
        int		enable;
        char    desc[NS_NAME_LEN];
    }NS_ALARM_HOST_S;

    typedef struct
    {
        unsigned int dwSize;
        int						hostnum;
        NS_ALARM_HOST_S			hosts[NS_MAX_ALARM_HOST_NUM];
        NS_SCHEDULE_S			schedule;
    }NS_ALARM_HOST_INFO_S;

    typedef struct
    {
        unsigned int dwSize;
        int	enable;
        int time;
        int preset;
    }NS_GUARDER_INFO_S;

    typedef struct 
    {
        unsigned int 		id;				
        char                name[NS_NAME_LEN];
        unsigned int        stayTime;
    } NS_PRESET_S;

    typedef struct 
    {
        unsigned int 		dwSize;	
        unsigned int   count;
        NS_PRESET_S    presets[NS_MAX_PRESET_NUM];
    } NS_PRESET_INFO_S;

    typedef struct 
    {
        unsigned int 		id;				
        unsigned int        presetCount;
        NS_PRESET_S         presets[NS_MAX_PRESETS_IN_TRACK];
    } NS_TRACK_S;

    typedef struct 
    {
        unsigned int 		dwSize;	
        unsigned int        count;
        NS_TRACK_S          tracks[NS_MAX_TRACK_NUM];
    } NS_TRACK_INFO_S;
    //云台控制结构体,详见"云台指令"
    typedef struct tagNS_PTZ_CMD
    {
        unsigned int  dwSize;
        unsigned int  bStart;
        unsigned int  bStep;
        unsigned int  speed;  
    }NS_PTZ_CMD_S;

    typedef struct tagNS_PTZ20_CMD
    {
        unsigned int  dwSize;
        NS_PTZ20_CMD_CODE_E ptz20; 
        unsigned int  data1;
        unsigned int  data2;
        char          packet[NS_PTZ_CMD_PACKET_LEN];
        char          result[NS_PTZ20_CMD_RESULT_LEN];
    }NS_PTZ20_CMD_S;


    typedef struct tagNS_PTZ_PRESET_CMD
    {
        unsigned int  dwSize;
        unsigned int  id;
        char  name[NS_NAME_LEN];
    }NS_PTZ_PRESET_CMD_S;

    typedef struct tagNS_PTZ_TRACK_CMD
    {
        unsigned int  dwSize;
        NS_TRACK_S track;
    }NS_PTZ_TRACK_CMD_S;

    /************************************************************************/
    /*    设备搜索返回的设备信息                                            */
    /************************************************************************/
    typedef struct 
    {
        char            id[NS_NAME_LEN];  
        char            devtype[NS_NAME_LEN];  
        char            kernelver[NS_NAME_LEN];  
        char            serverver[NS_NAME_LEN];  
        char            ip[NS_NAME_LEN];  
        char            submask[NS_NAME_LEN];  
        char            gateway[NS_NAME_LEN];  
        char            mac[NS_NAME_LEN];  
        char            wifiip[NS_NAME_LEN];  
        char            wifisubmask[NS_NAME_LEN];  
        char            wifigateway[NS_NAME_LEN];  
        char            wifimac[NS_NAME_LEN];  
        unsigned int    nettype;
        unsigned int    rtspport;          
        unsigned int    webport;          
        unsigned int    channelnum;
        char            channels[NS_MAX_CHANNEL_NUM][NS_NAME_LEN];          
    } NS_SEARCH_DEV_INFO_S;
    typedef void (* NS_ON_SEARCH_DEV_CALLBACK) (const NS_SEARCH_DEV_INFO_S* pDevInfo,void* pUserData);


    typedef struct
    {

    }NS_UPDATE_DEVICE_S;

	typedef enum
	{
		NS_PLAY_SPEED_NORMAL	= 0,
		NS_PLAY_SPEED_FAST_2 ,
		NS_PLAY_SPEED_FAST_4 ,
		NS_PLAY_SPEED_FAST_8 ,
		NS_PLAY_SPEED_FAST_16,
		NS_PLAY_SPEED_FAST_32,
		NS_PLAY_SPEED_SLOW_2 ,
		NS_PLAY_SPEED_SLOW_4 ,
		NS_PLAY_SPEED_SLOW_8 ,
		NS_PLAY_SPEED_SLOW_16,
		NS_PLAY_SPEED_SLOW_32,
	}NS_PLAY_SPEED_E;


	typedef struct
	{
        unsigned int dwSize;
		unsigned int brightness;
		unsigned int contrast;
		unsigned int saturation;
		unsigned int sharpness;
		unsigned int agc;
		unsigned int shuttermode;
		unsigned int shutterspeed;
		unsigned int focusstatus;
		unsigned int showangle;
		unsigned int iris;
		unsigned int gain;
	}NS_WA_IMAGE_PARAM_S;

	typedef struct
	{
		unsigned int dwSize;
		unsigned int index;
		unsigned int show;
		unsigned int left;
		unsigned int top;
		char  content[NS_NAME_LEN];
	}NS_WA_OSD_INFO_S;

	typedef struct
	{
		unsigned int dwSize;
		double multiple; //摄像头倍率
	}NS_WA_CAMERA_INFO_S;
	
	
	typedef struct
	{
		unsigned int dwSize;
		unsigned int id;
		char  str[NS_ENCTRY_STR_LEN];
	}NS_ENCRYPT_STR_S;
	
	typedef struct
	{
		unsigned int dwSize;
		int time;
	}NS_TIME_SYNC_S;
	
	// 文件播放状态
	typedef enum 
	{
		NS_PLAYER_STATUS_STOP		= 0,		// 停止状态
		NS_PLAYER_STATUS_INIT		,			// 初始化状态
		NS_PLAYER_STATUS_PLAY		,			// 开始播放状态
		NS_PLAYER_STATUS_PAUSE		,			// 暂停状态
	}NS_PLAYER_STATUS_E;
    /************************************************************************/
    /*    错误码                                                            */
    /************************************************************************/
#define NS_SUCCESS                           0   //成功
#define NS_ERR_FAILURE                      -1   //内部错误
#define NS_ERR_PARA                         -2   //参数错误
#define NS_ERR_POINT_NULL                   -3   //指针为空
#define NS_ERR_NOT_SUPPORT_CMD              -4   //不支持的命令
#define NS_ERR_NET_ERRO                     -5   //网络错误
#define NS_ERR_NEED_FREE                    -6   //需要释放内存
#define NS_ERR_SERVER_USER_OPRATE           -7   //服务器用户正在操作
#define NS_ERR_BADURL                       -11
#define NS_ERR_CONN_FAILED                  -12
#define NS_ERR_SOCKREAD_FAILED              -13
#define NS_ERR_METHOD_ERR                   -14
#define NS_ERR_PARSE_ERROR                  -15
#define NS_ERR_SEQ                          -16
#define NS_ERR_ALREADY_RUNNING              -17
#define NS_ERR_START_FAILED                 -18
#define NS_ERR_INLGAL_PARAM                 -19
#define NS_ERR_ALREAD_START                 -20
#define NS_ERR_MALLOC_FAILED                -21
#define NS_ERR_ERROR_PROTOCAL               -22
#define NS_ERR_RESP_UNSTANDARD              -23
#define NS_ERR_RESP_NO_CSEQ                 -24
#define NS_ERR_RESP_CSEQ_ERR                -25
#define NS_ERR_RESP_NO_SESSION              -26
#define NS_ERR_RESP_SESSION_ERR             -27
#define NS_ERR_RESP_NO_TRANSPORT            -28
#define NS_ERR_RESP_TRANSPORT_ERR           -29
#define NS_ERR_RESP_NO_VIDEO_ATTR           -30
#define NS_ERR_RESP_VIDEO_ATTR_ERR          -31
#define NS_ERR_RESP_UNRECOGNIZE_VIDEO_ATTR  -32
#define NS_ERR_RESP_NO_AUDIO_ATTR           -33
#define NS_ERR_RESP_AUDIO_ATTR_ERR          -34
#define NS_ERR_START_RECV_THREAD_FAILED     -35
#define NS_ERR_RESP_UNRECOGNIZE_AUDIO_ATTR  -36
#define NS_ERR_VIDEO_ALREADY_PAUSED         -37
#define NS_ERR_AUDIO_ALREADY_PAUSED         -38
#define NS_ERR_DATA_ALREADY_PAUSED          -39
#define NS_ERR_VIDEO_ALREADY_PLAYED         -40
#define NS_ERR_AUDIO_ALREADY_PLAYED         -41
#define NS_ERR_DATA_ALREADY_PLAYED          -42
#define NS_ERR_ERROR_TRANSTYPE              -43
#define NS_ERR_INVALID_USER                 -44
#define NS_ERR_OVER_SERVER_CONNECTION_NUM   -45
#define NS_ERR_PAUSE_FAILED                 -46
#define NS_ERR_REPLAY_FAILED                -47
#define NS_ERR_SOCKSEND_FAILED              -48
#define NS_ERR_USER_OR_PASSWORD             -49
#define NS_ERR_STREAM_INFO                  -50
#define NS_ERR_NO_PTZ						-51

#define NS_ERR_DEVICE_CMD_CODE                     -100 //设备控制命令码错误

    /************************************************************************/
    /*   码流点播数据结构                                                   */
    /************************************************************************/

    /*网络协议*/
    typedef enum tagSTREAM_TRANS_PROTOCOL /*媒体传输协议类型*/
    {
        TRANS_PROTOCOL_RTSP          = 0, /*RTSP协议*/
        TRANS_PROTOCOL_RTSP_OVER_HTTP= 1, /*RTSP Over Http网络协议*/
        TRANS_PROTOCOL_HTTP          = 2, /*HTTP协议*/
   }STREAM_TRANS_PROTOCOL_E;
    typedef enum tagNET_SOCKET_TYPE/*数据流的底层传输类型*/
    {
        SOCKET_TYPE_TCP = 0, /*在tcp上传输*/
        SOCKET_TYPE_UDP = 1, /*在udp上传输*/
        SOCKET_TYPE_MUDP = 2, /*udp广播*/
    }NET_SOCKET_TYPE_E;
    typedef enum tagCONTROL_PROTOCOL_TYPE/*控制协议类型*/
    {
        CTL_PROTOCOL_TYPE_PRIVATE = 0, /*私有控制协议,暂时只支持私有协议*/
        CTL_PROTOCOL_TYPE_ONVIF   = 2, /*ONVIF控制协议*/
    }CONTROL_PROTOCOL_TYPE_E;
    typedef struct tagNS_NET_PROTOCOL/*网络协议*/
    {
        STREAM_TRANS_PROTOCOL_E eStreamTransProtocol;/*流媒体传输协议*/
        NET_SOCKET_TYPE_E       eSocketType;  /*数据流的底层传输类型*/
        CONTROL_PROTOCOL_TYPE_E eControlProtocol;/*控制协议类型*/
    }NS_NET_PROTOCOL_S;

    /*流数据类型 : 视频音频或其他告警数据*/
    typedef enum tagSTREAM_TYPE_E
    {
        NS_STREAM_TYPE_VIDEO     = 0x01,/*视频*/
        NS_STREAM_TYPE_AUDIO     = 0x02,/*音频*/
        NS_STREAM_VIDEO_AUDIO    = 0x03,/*音视频*/
        NS_STREAM_MD_ONLY        = 0x04,/*移动侦测告警数据*/
        NS_STREAM_SENSORIN_ONLY  = 0x08,/*探头输入告警数据*/
        NS_STREAM_SHELTER_ONLY   = 0x10,/*视频遮挡告警数据*/
        NS_STREAM_VIDEO_LOSS_ONLY= 0x20,/*视频丢失告警数据*/
        NS_STREAM_NET_ERRO_ONLY = 0x40,/*网线断开告警数据*/
        NS_STREAM_IP_ERRO_ONLY  = 0x80,/*IP冲突告警数据*/
        NS_STREAM_DISK_FULL_ONLY  = 0x100,/*磁盘满告警数据*/
        NS_STREAM_DISK_ERR_ONLY  = 0x200,/*磁盘错误告警数据*/
        NS_STREAM_ALL            = 0xFF,/*所有码流以及告警数据*/
    }NS_STREAM_TYPE_E;

    /* 网络连接状态*/
    typedef enum tagLIVE_NET_STAT
    {
        NS_NETSTAT_CONNING = 0,    /*正在连接*/
        NS_NETSTAT_CONNING_FAILED, /*连接不上*/
        NS_NETSTAT_LOGIN_FAILED,   /*用户密码错误*/
        NS_NETSTAT_CONNED,         /*已连接*/
        NS_NETSTAT_ABNORMAL_DISCONNED, /*已连接上的链接异常断开*/ 
        NS_NETSTAT_NORMAL_DISCONNED,   /*链接由用户发起主动断开*/
    }NS_NETSTAT_E;


    /*码流属性定义*/
    typedef enum tagNS_VIDEO_FORMAT_E/*视频编码格式*/
    {
        NS_VIDEO_FORMAT_H261  = 0,  /*H261  */
        NS_VIDEO_FORMAT_H263  = 1,  /*H263  */
        NS_VIDEO_FORMAT_MPEG2 = 2,  /*MPEG2 */
        NS_VIDEO_FORMAT_MPEG4 = 3,  /*MPEG4 */
        NS_VIDEO_FORMAT_H264  = 4,  /*H264  */
        NS_VIDEO_FORMAT_H265  = 5,  /*H265  */
        NS_VIDEO_FORMAT_MJPEG = 6,  /*MOTION_JPEG*/
        NS_VIDEO_FORMAT_BUTT
    }NS_VIDEO_FORMAT_E;
    typedef enum tagNS_AUDIO_FORMAT_E/*音频编码格式*/
    {
        NS_AUDIO_FORMAT_G711A   = 1,   /* G.711 A            */
        NS_AUDIO_FORMAT_G711Mu  = 2,   /* G.711 Mu           */
        NS_AUDIO_FORMAT_ADPCM   = 3,   /* ADPCM              */
        NS_AUDIO_FORMAT_G726    = 4,   /* G.726              */
        NS_AUDIO_FORMAT_AMR     = 5,   /* AMR encoder format */
        NS_AUDIO_FORMAT_AMRDTX  = 6,   /* AMR encoder formant and VAD1 enable */
        NS_AUDIO_FORMAT_AAC     = 7,   /* AAC encoder        */
        NS_AUDIO_FORMAT_BUTT
    }NS_AUDIO_FORMAT_E;
    typedef enum tagNS_AUDIO_BITWIDTH_E/*音频编码格式*/
    {
        NS_AUDIO_BITWIDTH_8   = 0,   /* Bit width is 8 bits   */
        NS_AUDIO_BITWIDTH_16  = 1,   /* Bit width is 16 bits  */
        NS_AUDIO_BITWIDTH_32  = 2,   /* Bit width is 32 bits */ 
        NS_AUDIO_BITWIDTH_BUTT
    } NS_AUDIO_BITWIDTH_E;
    typedef enum tagNS_AUDIO_SAMPLE_RATE_E/*音频采样率*/
    {
        NS_AUDIO_SAMPLE_RATE_8     = 0,   /* 8K Sample rate     */
        NS_AUDIO_SAMPLE_RATE_11025 = 1,   /* 11.025K Sample rate*/
        NS_AUDIO_SAMPLE_RATE_16    = 2,   /* 16K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_22050 = 3,   /* 22.050K Sample rate*/
        NS_AUDIO_SAMPLE_RATE_24    = 4,   /* 24K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_32    = 5,   /* 32K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_441   = 6,   /* 44.1K Sample rate  */
        NS_AUDIO_SAMPLE_RATE_48    = 7,   /* 48K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_64    = 8,   /* 64K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_882   = 9,   /* 88.2K Sample rate  */
        NS_AUDIO_SAMPLE_RATE_96    = 10,  /* 96K Sample rate    */
        NS_AUDIO_SAMPLE_RATE_1764  = 11,  /* 176.4K Sample rate */
        NS_AUDIO_SAMPLE_RATE_192   = 12,  /* 192K Sample rate   */
        NS_AUDIO_SAMPLE_RATE_BUTT
    } NS_AUDIO_SAMPLE_RATE_E;
    typedef enum tagNS_SOUND_MODE_E/*声音单双声道*/
    {
        NS_SOUND_MODE_MOMO =0,          /*单声道*/
        NS_SOUND_MODE_STEREO =1,        /*双声道*/
        NS_SOUND_MODE_BUTT    
    }NS_SOUND_MODE_E;
    typedef struct tagSTREAM_AUIDO_ATTR_S
    {
        NS_AUDIO_FORMAT_E    enAudioFormat;  /*音频格式*/         
        unsigned int u32SampleRate;/*采样率 */        
        unsigned int u32BitWidth;      /*采样位宽 */        
        unsigned int u32ChannNum;     /*声道模式，单声道或双声道*/
        unsigned int payload_type;
    }STREAM_AUIDO_ATTR_S;
    typedef struct tagSTREAM_VIDEO_ATTR_S
    {
        NS_VIDEO_FORMAT_E enVideoFormat;     /*视频编码格式*/
        unsigned int     u32PicWidth;        /*视频图像的宽*/
        unsigned int     u32PicHeight;       /*视频图像的高*/
        char    sprop_parameter_sets[NS_SPROP_PARAMETER_SETS_LEN];
        unsigned int payload_type;
		double fps;
    } STREAM_VIDEO_ATTR_S;
    typedef struct tagNS_STREAM_INFO /*码流属性*/
    {
        STREAM_VIDEO_ATTR_S struVencChAttr;  /* 视频编码属性 */
        STREAM_AUIDO_ATTR_S struAencChAttr;  /* 音频编码属性 */
    }NS_STREAM_INFO_S;

	typedef enum
	{
		NS_SERVER_CONFIG_CMD_GET,
		NS_SERVER_CONFIG_CMD_SET,
	}NS_SERVER_CONFIG_CMD_TYPE_E;

#define NS_SERVER_CONFIG_DATA_LEN 4096
	typedef struct  {
		NS_SERVER_CONFIG_CMD_TYPE_E type;
		unsigned int hwnd;
		unsigned int u32DevHandle;
		char  channel[NS_NAME_LEN];
		unsigned int msg;
		unsigned int dwCmd;
		char data[NS_SERVER_CONFIG_DATA_LEN];
		unsigned int size;
		int result;
	}NS_SERVER_CONFIG_CMD_S;


    /* 事件回调*/
    typedef int (*NS_ON_EVENT_CALLBACK)(unsigned int u32ChnHandle, /* 通道句柄 */
        NS_NETSTAT_E u32Event,     
        void* pUserData);

    /* 码流回调*/
    typedef int (*NS_ON_STREAM_CALLBACK)(unsigned int u32ChnHandle,/* 通道句柄 */
        unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
                                 0x01-视频，0x02-音频*/
                                 unsigned char* pu8Buffer,/* 帧数据 */
                                 unsigned int u32Length,  /* 数据长度 */
                                 NS_U64  u64TimeStamp,    /* 时间戳*/
                                 NS_STREAM_INFO_S *pStreamInfo,/*码流属性*/
                                 void* pUserData);        /* 用户数据*/

    /* 告警回调*/
    typedef int (*NS_ON_DATA_CALLBACK)(unsigned int u32ChnHandle,/* 通道句柄 */
        unsigned int u32DataType, /* 数据类型,详见NS_STREAM_TYPE_E
                                  0x04-MD告警数据,
                                  0x08-探头输入告警数据,
                                  0x10-视频遮挡告警数据,
                                  0x20-视频丢失告警数据,
                                  0x40-磁盘错误告警,
                                  0x80-系统错误告警*/
        unsigned char*  pu8Buffer,/* 数据,MD告警数据为
                                "Alarm:报警矩形区域号-左上角X坐标-左上角Y坐标-宽-高|报警矩形区域号-左上角X坐标-左上角Y坐标-宽-高|",
                                比如"Alarm:1-558-461-120-120|2-520-0-120-120|3-0-360-120-120|4-520-360-120-120|"*/
        unsigned int u32Length,          /* 数据长度 */
        NS_U64  u64TimeStamp,    /* 时间戳*/
        NS_STREAM_INFO_S *pStreamInfo,/*码流属性*/
        void* pUserData);                /* 用户数据*/

    /* 对讲音频回调*/
    typedef int (*NS_ON_TALK_CALLBACK)(unsigned int u32DevHandle,/* 设备句柄 */
        unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
                                 0x02-音频*/
                                 unsigned char* pu8Buffer,/* 帧数据 */
                                 unsigned int u32Length,  /* 数据长度 */
                                 NS_U64  u64TimeStamp,    /* 时间戳*/
                                 NS_STREAM_INFO_S *pStreamInfo,/*码流属性*/
                                 void* pUserData);        /* 用户数据*/



    /************************************************************************/
    /* 搜索前端录像                                                         */
    /************************************************************************/
#define    NS_CMD_SEARCH_DEV_RECORD         0x4001000  //搜索前端录像,Param:NS_SEARCH_DEV_RECORD_S

    typedef enum
    {
        NS_DEV_TYPE_BASE = 0,
        NS_DEV_TYPE_FULL,
    }NS_DEV_TYPE_E;

    typedef struct 
    {
        unsigned int dwSize;
        NS_DEV_TYPE_E devtype;		
        unsigned int hasptz;
    }NS_DEV_CAPS_S;

    typedef struct 
    {
        unsigned int year;			
        unsigned int month;		
        unsigned int day;
        unsigned int week;
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
    }NS_TIME_S;

    typedef enum
    {
        NS_DEV_RECORD_TYPE_ALL = 0,
        NS_DEV_RECORD_TYPE_MANUAL,
        NS_DEV_RECORD_TYPE_SCHEDULE,
        NS_DEV_RECORD_TYPE_ALARM,
    }NS_DEV_RECORD_TYPE_E;

    typedef enum
    {
        NS_SEARCH_DEV_RECORD_ACTION_START = 1,
        NS_SEARCH_DEV_RECORD_ACTION_NEXT_PAGE,
    }NS_SEARCH_DEV_RECORD_ACTION_E;

    typedef struct  
    {
        unsigned int            dwSize;
        NS_DEV_RECORD_TYPE_E    type;    
        NS_TIME_S               begin;   
        NS_TIME_S               end;     
        NS_SEARCH_DEV_RECORD_ACTION_E    action;
        unsigned int            filenum;
        char files[NS_FILE_NUM_PER_PAGE][NS_MAX_PATH];
        unsigned    int         hasmore;
    }NS_SEARCH_DEV_RECORD_S;

    typedef struct _userpri_s
    {
        unsigned char byLocalRight[10]; /* 权限 */
        /*数组1: 录像*/
        /*数组2: PTZ控制*/
        /*数组3: 录像回放/备份*/
        /*数组4: 设置参数*/
        /*数组5: 升级/重启/维护/格式化/恢复参数*/
        /*数组6: 静音/开音*/
        /*数组7:PIP画面*/
        /*数组8:自动轮循*/
        /*数组9:电子放大*/
        unsigned char byRemoteRight[10]; /* 权限 */
        /*数组1: 云台控制*/
        /*数组2: 录像/抓拍*/
        /*数组3: 回放/下载*/
        /*数组4: 设置参数*/
        /*数组5: 开/关音*/
        unsigned char byLocalPreviewRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)]; //本地可以预览的通道 0-有权限，1-无权限
        unsigned char byRemotePreviewRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//远程可以预览的通道 0-有权限，1-无权限
#if 0
        unsigned char byLocalPlaybackRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//本地可以回放的通道 0-有权限，1-无权限
        unsigned char byRemotePlaybackRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//远程可以回放的通道 0-有权限，1-无权限
        unsigned char byLocalRecordRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)]; //本地可以录像的通道 0-有权限，1-无权限
        unsigned char byRemoteRecordRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//远程可以录像的通道 0-有权限，1-无权限
        unsigned char byLocalPTZRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//本地可以PTZ的通道 0-有权限，1-无权限
        unsigned char byRemotePTZRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//远程可以PTZ的通道 0-有权限，1-无权限
        unsigned char byLocalBackupRight[ASSIGN_FOUR_BYTES(NS_MAX_CHN_NUM)];//本地备份权限通道 0-有权限，1-无权限
#endif
    }userpri_s;

    typedef struct _userpassword_s
    {
        char 		  UserName[NS_NAME_LEN];/*用户名[名字长度]*/
        char 		  UserPsw[NS_NAME_LEN];/*用户密码*/	
        userpri_s 	  UserPri;
        char 		  DeviceID1[NS_NAME_LEN];	/*本机编号*/
        unsigned char DeviceID;		/*本机编号*/
        unsigned char  bHavePwd;		/*是否使用密码，0表示不使用，1表示使用*/
        unsigned char  bUserPrew;	/*是否启用预览权限*/
    }userpassword_s;

    typedef struct
    {
        char szUsername[NS_NAME_LEN];     /*输入用户名*/
        char szPassword[NS_NAME_LEN];    /*输入密码*/
        char szHost[NS_NAME_LEN];         /*服务器IP*/
        unsigned short u16Port;     /*服务器端口号*/
        char szDevChn[NS_NAME_LEN];
        NS_NET_PROTOCOL_S stNetProtocol; /*网络协议*/
        int s32ConnectTimeout;/*网络连接超时时间，默认超时是5秒，单位是秒*/
        NS_ON_EVENT_CALLBACK cbEventCallBack;/*事件回调，主要为网络连接状态*/
        userpassword_s userAuth; /*返回当前用户权限*/
        void* pUserData  ;        /*用户数据，会从事件回调函数中返回出来*/
    }NS_LOGIN_INFO_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif