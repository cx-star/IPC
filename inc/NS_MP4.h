#ifndef	NS_MP4_H 
#define	NS_MP4_H


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 


#if defined(WIN32)

#if defined(NS_PLAYER_EXPORTS)
#define NS_MP4_API      __declspec( dllexport )
#define NS_MP4_APICALL  __stdcall

#elif	defined(NS_PLAYER_LIB)
#define NS_MP4_API      
#define NS_MP4_APICALL  

#else 
#define NS_MP4_API      __declspec( dllimport )
#define NS_MP4_APICALL  __stdcall
#endif
#elif defined(LINUX)
#define NS_MP4_API
#define NS_MP4_APICALL
#else
#error "Please specify a design-in platform!"
#endif

#include "NS_NET_define.h"
#include "NS_MP4_define.h"

    /*录像接口*/

    /*初始化和去初始化只需调用一次*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_Init();
    NS_MP4_API int NS_MP4_APICALL NS_MP4_DeInit();

    /*打开录像文件（用于写）*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_Open(
        unsigned int* pu32Mp4Handle, /*返回MP4文件句柄,后续所有文件操作都基于该句柄进行*/
        const char *  pu8FileName,/*文件路径*/
        const NS_STREAM_INFO_S *pStreamInfo/*码流属性*/
         );

    /*写录像文件*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_Write(
        unsigned int u32Mp4Handle, /*MP4文件句柄*/
        unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
                                 0x01-视频，0x02-音频*/
         unsigned char* pu8Buffer,/* 帧数据 */
         unsigned int u32Length,  /* 数据长度 */
         NS_U64 u64TimeStamp    /* 时间戳*/
         );

    /*关闭录像文件*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_Close(
        unsigned int u32Mp4Handle /*MP4文件句柄*/
        );

    /*mp4文件修复*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_Repair(
        const char *  pu8FileName/*文件路径*/
        );

    /*mp4文件状态：0为正常， 非0为异常*/
    NS_MP4_API int NS_MP4_APICALL NS_MP4_GetStatus(
        const char *  pu8FileName/*文件路径*/
        );

    /*打开录像文件（用于回放）*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_StartPlay(
        unsigned int * pu32Mp4ReaderHandle, /*返回MP4文件句柄*/
		const  char * pszFileName,   /*MP4文件名称*/
		NS_MP4_FILE_INFO_S * pFileInfo, /*返回MP4文件信息*/
		NS_STREAM_INFO_S *pstruStreamInfo,/*返回码流信息*/
		NS_ON_STREAM_CALLBACK cbStreamCallBack,/*码流回调*/
		void* pUserData  /*用户数据*/
		);

    /*停止播放*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_StopPlay(
        unsigned int  u32Mp4ReaderHandle /*MP4文件句柄*/
		);

    /*设置播放速度*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_SetSpeed(
        unsigned int  u32Mp4ReaderHandle, /*MP4文件句柄*/
		NS_PLAY_SPEED_E  speed /*播放速度*/
		);
	
    /*暂停*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_Pause(
        unsigned int  u32Mp4ReaderHandle/*MP4文件句柄*/
		);
	
    /*SEEK到指定的位置*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_SetPlayPos(
        unsigned int  u32Mp4ReaderHandle, /*MP4文件句柄*/
		double  position /*位置（秒）*/
		);
	
    /*返回当前播放的位置*/
    NS_MP4_API int NS_MP4_APICALL NS_PLAYBACK_GetPlayPos(
        unsigned int  u32Mp4ReaderHandle, /*MP4文件句柄*/
		double * pPosition /*返回当前位置（秒）*/
		);
	
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif