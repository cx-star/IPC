#ifndef	NS_NET_H 
#define	NS_NET_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#if defined(WIN32)

#if defined(NS_NET_EXPORTS)
#define NS_NET_API      __declspec( dllexport )
#define NS_NET_APICALL  __stdcall

#elif	defined(NS_NET_LIB)
#define NS_NET_API      
#define NS_NET_APICALL  

#else 
#define NS_NET_API      __declspec( dllimport )
#define NS_NET_APICALL  __stdcall
#endif
#elif defined(LINUX)
#define NS_NET_API
#define NS_NET_APICALL
#else
#error "Please specify a design-in platform!"
#endif


#include "NS_NET_define.h"

    /************************************************************************/
    /* 媒体函数区                                                           */
    /************************************************************************/

    /* 初始化和去初始化只需调用一次  */
    NS_NET_API int NS_NET_APICALL NS_NET_Init();
    NS_NET_API int NS_NET_APICALL NS_NET_DeInit();

    /*  用户登录 */
    NS_NET_API int NS_NET_APICALL NS_NET_Login(
        unsigned int* pu32DevHandle, /*返回设备句柄,后续所有设备操作都基于该设备句柄进行*/
        const NS_LOGIN_INFO_S * pLoginInfo
    );           

    /* 用户登出*/
    NS_NET_API int NS_NET_APICALL NS_NET_Logout(unsigned int u32DevHandle);


    /* 开始流传输 */
    NS_NET_API int NS_NET_APICALL NS_NET_StartStream(unsigned int *pu32ChnHandle,/*返回通道句柄，后续所有通道操作都基于该通道句柄进行*/
        unsigned int u32DevHandle,/*输入设备句柄*/
        const char* psChannel,         /*通道*/
        unsigned int u32StreamType,/*流数据类型,详见NS_STREAM_TYPE_E
                                   0x01:NS_STREAM_TYPE_VIDEO,
                                   0x02:NS_STREAM_TYPE_AUDIO,
                                   0x03:NS_STREAM_VIDEO_AUDIO,
                                   0x04:NS_STREAM_MD_ONLY,
                                   0x08:NS_STREAM_SENSORIN_ONLY,
                                   0x10:NS_STREAM_SHELTER_ONLY,
                                   0x20:NS_STREAM_VIDEO_LOSS_ONLY,
                                   0x40:NS_STREAM_DISK_ERRO_ONLY,
                                   0xFF:NS_STREAM_ALL*/
                                   NS_STREAM_INFO_S *pstruStreamInfo,/*返回码流信息*/
                                   NS_ON_STREAM_CALLBACK cbStreamCallBack,/*码流回调*/
                                   NS_ON_DATA_CALLBACK cbDataCallBack,/*告警数据回调*/
                                   void* pUserData);/*用户数据*/
    /* 停止流传输  */
    NS_NET_API int NS_NET_APICALL NS_NET_StopStream(unsigned int u32DevHandle, unsigned int u32ChnHandle); /*输入通道句柄*/
    
	NS_NET_API int NS_NET_APICALL NS_NET_CancelLogin(unsigned int u32DevHandle); 

    /* 开始搜索设备  */
    NS_NET_API int NS_NET_APICALL NS_NET_StartSearchDevice(NS_ON_SEARCH_DEV_CALLBACK cb, void * pUserData );

    /* 停止搜索设备  */
    NS_NET_API int NS_NET_APICALL NS_NET_StopSearchDevice();

    /* 语音对讲*/
    NS_NET_API int NS_NET_APICALL NS_NET_StartTalk(unsigned int u32DevHandle,
        NS_ON_TALK_CALLBACK cbTalkCallBack,/*设置对讲音频数据回调:服务端->客户端*/
        void* pUserData);
    NS_NET_API int NS_NET_APICALL NS_NET_StopTalk(unsigned int u32DevHandle);


    /*配置服务器参数,dwCmd取值详见"设置服务器参数命令"*/
    NS_NET_API int NS_NET_APICALL NS_NET_SetServerConfig(unsigned int u32DevHandle, const char * psChannel, unsigned int dwCmd, void* lpData, unsigned int Size);

    /*获取服务器参数,dwCmd取值详见"获取服务器参数命令"*/
    NS_NET_API int NS_NET_APICALL NS_NET_GetServerConfig(unsigned int u32DevHandle, const char * psChannel, unsigned int dwCmd, void* lpData, unsigned int *pSize);

    NS_NET_API int NS_NET_APICALL NS_NET_ServerConfigAsync(const NS_SERVER_CONFIG_CMD_S * cmd);

    /*云台控制,dwPTZCmd取值详见"云台指令"*/
    NS_NET_API int NS_NET_APICALL NS_NET_PTZControl(unsigned int u32DevHandle, unsigned int dwPTZCmd, void* lpData, unsigned int Size);

    /*调用3D定位功能。
    **zoom 表示3D定位的时候是否执行ZOOM操作，0表示不执行，1表示执行
    **vw、vh 视频播放区域的宽度、高度   
    **x、y、w、h   3D定位功能框选框的x坐标、y坐标、宽度、高度
    **3D定位功能框选框的坐标系的定定义如下：
    **坐标原点在视频播放区域的左上角，y坐标向下，x坐标向右
    */
    NS_NET_API int NS_NET_APICALL NS_NET_PTZ_DirectTo(unsigned int u32DevHandle, unsigned int zoom, 
        unsigned int vw, unsigned int vh, unsigned int x, unsigned int y, unsigned int w,unsigned int h);

    /*获取网络库版本号*/
    NS_NET_API int NS_NET_APICALL NS_NET_GetVersion(char *pVersion);

    /*VOD接口*/

	/*暂停*/
    NS_NET_API int NS_NET_APICALL NS_VOD_Pause(unsigned int u32DevHandle, /*设备句柄*/
												unsigned int u32ChnHandle, /*VOD流句柄*/
												unsigned int bPause /*1 暂停， 0 取消暂停*/
												); 

	/*获取时长*/
    NS_NET_API int NS_NET_APICALL NS_VOD_GetDuration(unsigned int u32DevHandle, /*设备句柄*/
														unsigned int u32ChnHandle, /*VOD流句柄*/
														double * pDuration /*返回时长*/
														); 

	/*设置播放速度*/
    NS_NET_API int NS_NET_APICALL NS_VOD_SetSpeed(unsigned int u32DevHandle, /*设备句柄*/
													unsigned int u32ChnHandle, /*VOD流句柄*/
													NS_PLAY_SPEED_E  speed /*播放速度*/
													); 

	/*SEEK到指定位置*/
    NS_NET_API int NS_NET_APICALL NS_VOD_SetPlayPos(unsigned int u32DevHandle, /*设备句柄*/
														unsigned int u32ChnHandle, /*VOD流句柄*/
														double position /*位置（秒）*/
														); 

	/*返回当前播放的位置*/
    NS_NET_API int NS_NET_APICALL NS_VOD_GetPlayPos(unsigned int u32DevHandle, /*设备句柄*/
														unsigned int u32ChnHandle, /*VOD流句柄*/
														double * pPosition /*返回当前位置（秒）*/
														); 
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif