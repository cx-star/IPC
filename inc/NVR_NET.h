#ifndef	NVR_NET_H 
#define	NVR_NET_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#if defined(WIN32)

#if defined(NVR_NET_EXPORTS)
#define NVR_NET_API      __declspec( dllexport )
#define NVR_NET_APICALL  __stdcall

#elif	defined(NVR_NET_LIB)
#define NVR_NET_API      
#define NVR_NET_APICALL  

#else 
#define NVR_NET_API      __declspec( dllimport )
#define NVR_NET_APICALL  __stdcall
#endif
#elif defined(LINUX)
#define NVR_NET_API
#define NVR_NET_APICALL
#else
#error "Please specify a design-in platform!"
#endif


#include "NVR_NET_define.h"

    /************************************************************************/
    /* 媒体函数区                                                           */
    /************************************************************************/

    /* 初始化和去初始化只需调用一次  */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_Init();
    NVR_NET_API int NVR_NET_APICALL NVR_NET_DeInit();

    /*  用户登录 */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_Login(
        unsigned int* pu32DevHandle, /*返回设备句柄,后续所有设备操作都基于该设备句柄进行*/
        const NVR_LOGIN_INFO_S * pLoginInfo
    );           
	NVR_NET_API int NVR_NET_APICALL NVR_NET_CancelLogin(unsigned int u32DevHandle); 

    /* 用户登出*/
    NVR_NET_API int NVR_NET_APICALL NVR_NET_Logout(unsigned int u32DevHandle);


    /* 开始流传输 */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_StartStream(unsigned int *pu32ChnHandle,/*返回通道句柄，后续所有通道操作都基于该通道句柄进行*/
        unsigned int u32DevHandle,/*输入设备句柄*/
        const char* pszChannel,         /*通道*/
		unsigned int u32MediaPort,
        unsigned int u32StreamType,/*流数据类型,详见NVR_STREAM_TYPE_E
                                   0x01:NVR_STREAM_TYPE_VIDEO,
                                   0x02:NVR_STREAM_TYPE_AUDIO,
                                   0x03:NVR_STREAM_VIDEO_AUDIO,
                                   0x04:NVR_STREAM_MD_ONLY,
                                   0x08:NVR_STREAM_SENSORIN_ONLY,
                                   0x10:NVR_STREAM_SHELTER_ONLY,
                                   0x20:NVR_STREAM_VIDEO_LOSS_ONLY,
                                   0x40:NVR_STREAM_DISK_ERRO_ONLY,
                                   0xFF:NVR_STREAM_ALL*/
                                   NS_STREAM_INFO_S *pstruStreamInfo,/*返回码流信息*/
                                   NS_ON_STREAM_CALLBACK cbStreamCallBack,/*码流回调*/
                                   NS_ON_DATA_CALLBACK cbDataCallBack,/*告警数据回调*/
                                   void* pUserData);/*用户数据*/
    /* 停止流传输  */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_StopStream(unsigned int u32DevHandle, unsigned int u32ChnHandle); /*输入通道句柄*/

    /* 开始搜索设备  */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_StartSearchDevice(NVR_ON_SEARCH_DEV_CALLBACK cb, void * pUserData );

    /* 停止搜索设备  */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_StopSearchDevice();

    /*配置服务器参数,dwCmd取值详见"设置服务器参数命令"*/
    NVR_NET_API int NVR_NET_APICALL NVR_NET_SetNvrConfig(unsigned int u32DevHandle, unsigned int dwCmd, void* lpData, unsigned int nSize, void* lpDataOut, unsigned int nSizeOut, unsigned int *pSizeOut);

    /*获取服务器参数,dwCmd取值详见"获取服务器参数命令"*/
    NVR_NET_API int NVR_NET_APICALL NVR_NET_GetNvrConfig(unsigned int u32DevHandle, unsigned int dwCmd, void* lpData, unsigned int nSize, void* lpDataOut, unsigned int nSizeOut, unsigned int *pSizeOut);


    /*调用3D定位功能。
    **zoom 表示3D定位的时候是否执行ZOOM操作，0表示不执行，1表示执行
    **vw、vh 视频播放区域的宽度、高度   
    **x、y、w、h   3D定位功能框选框的x坐标、y坐标、宽度、高度
    **3D定位功能框选框的坐标系的定定义如下：
    **坐标原点在视频播放区域的左上角，y坐标向下，x坐标向右
    */
    NVR_NET_API int NVR_NET_APICALL NVR_NET_PTZ_DirectTo(unsigned int u32DevHandle, unsigned int zoom, 
        unsigned int vw, unsigned int vh, unsigned int x, unsigned int y, unsigned int w,unsigned int h);

    /*获取网络库版本号*/
    NVR_NET_API int NVR_NET_APICALL NVR_NET_GetVersion(char *pVersion);

	NVR_NET_API int NVR_NET_APICALL NVR_NET_StartSearch(NVR_ON_SEARCH_DEV_CALLBACK cb, void * pUserData );
	NVR_NET_API int NVR_NET_APICALL NVR_NET_StopSearch();

	/*暂停*/
    NVR_NET_API int NVR_NET_APICALL NVR_VOD_Pause(unsigned int u32DevHandle, /*设备句柄*/
		unsigned int u32ChnHandle, /*VOD流句柄*/
		unsigned int bPause /*1 暂停， 0 取消暂停*/
		); 
	
	/*设置播放速度*/
    NVR_NET_API int NVR_NET_APICALL NVR_VOD_SetSpeed(unsigned int u32DevHandle, /*设备句柄*/
		unsigned int u32ChnHandle, /*VOD流句柄*/
		NS_PLAY_SPEED_E  speed /*播放速度*/
		); 
	
	/*SEEK到指定位置*/
    NVR_NET_API int NVR_NET_APICALL NVR_VOD_SetPlayPos(unsigned int u32DevHandle, /*设备句柄*/
		unsigned int u32ChnHandle, /*VOD流句柄*/
		double position /*位置（秒）*/
		); 
	
	/*返回当前播放的位置*/
    NVR_NET_API int NVR_NET_APICALL NVR_VOD_GetPlayPos(unsigned int u32DevHandle, /*设备句柄*/
		unsigned int u32ChnHandle, /*VOD流句柄*/
		double * pPosition /*返回当前位置（秒）*/
		); 
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
