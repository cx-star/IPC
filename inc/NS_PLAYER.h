#ifndef	NS_PLAYER_H 
#define	NS_PLAYER_H


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 


#if defined(WIN32)

#if defined(NS_PLAYER_EXPORTS)
#define NS_PLAYER_API      __declspec( dllexport )
#define NS_PLAYER_APICALL  __stdcall

#elif	defined(NS_PLAYER_LIB)
#define NS_PLAYER_API      
#define NS_PLAYER_APICALL  

#else 
#define NS_PLAYER_API      __declspec( dllimport )
#define NS_PLAYER_APICALL  __stdcall
#endif
#elif defined(LINUX)
#define NS_PLAYER_API
#define NS_PLAYER_APICALL
#else
#error "Please specify a design-in platform!"
#endif

#include "NS_NET_define.h"
#include "NS_PLAYER_define.h"
    /* 初始化和去初始化只需调用一次  */
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_Init();
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_DeInit();

    /*打开播放器*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_Open(
            unsigned int* pu32PlayerHandle, /*返回播放器句柄,后续所有播放器操作都基于该播放器句柄进行*/
            unsigned int  u32WndHandle,/*播放窗口句柄*/
            const NS_STREAM_INFO_S *pStreamInfo/*码流属性*/
        );

    /*设置播放器属性*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_SetAttr(
            unsigned int u32PlayerHandle,/*播放器句柄*/
			const NS_PLAYER_ATTR * pPlayerAttr
         );

    /*输入媒体数据*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_InputData(
            unsigned int u32PlayerHandle,/*播放器句柄*/
            unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
             0x01-视频，0x02-音频*/
            unsigned char* pu8Buffer,/* 数据包含帧头 */
            unsigned int u32Length,  /* 数据长度 */
            NS_U64 u64TimeStamp    /* 时间戳*/
        );

    /*关闭播放器*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_Close(
            unsigned int u32PlayerHandle/*播放器句柄*/
         );

    /*打开声音*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_TurnOnAudio(
        unsigned int u32PlayerHandle/*播放器句柄*/
        );

    /*关闭声音*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_TurnOffAudio(
        unsigned int u32PlayerHandle/*播放器句柄*/
        );

    /*重画最后一幅图*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_RedrawLastPicture(
        unsigned int u32PlayerHandle/*播放器句柄*/
        );

    /*抓拍*/
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_SnapShot(
        unsigned int u32PlayerHandle,/*播放器句柄*/
        NS_SNAPSHOT_FORMAT_E format,/*图片格式*/
        unsigned int nQuality,  /*图片质量*/
        NS_ON_SNAPSHOT_CALLBACK cb,
        void * pUserData
        );

    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_SetVideoZoomRect(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		unsigned int left,
		unsigned int top,
		unsigned int right,
		unsigned int bottom
        );

    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_SetAssistWnd(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		unsigned int u32AssistWndHandle
        );

    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_ShowMotionDetectionGrid(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		unsigned int show,
		const char * mdinfo

		/* mdinfo为描述移动侦测网格的字符串，共22*18个字符，每行用逗号分开
		"0000000000000000000000,"
		"0100000000000000000000,"
		"0000000011000000000000,"
		"0000000011000000000000,"
		"0000000011000000000000,"
		"0000000011000000000000,"
		"0000000011000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"
		"0000000000000000000000,"*/
        );

    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_ShowMotionDetectionArea(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		unsigned int show, 
		const NS_MD_AREA_S * pstMDArea);

    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_SetDrawCallback(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		NS_DRAW_CALLBACK cb, 
		void * pUserData);
	
    NS_PLAYER_API int NS_PLAYER_APICALL NS_PLAYER_EnableDisplay(
        unsigned int u32PlayerHandle,/*播放器句柄*/
		unsigned int u32Enable
        );
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif