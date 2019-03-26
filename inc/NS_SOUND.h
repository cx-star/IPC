
#ifndef	NS_SOUND_H 
#define	NS_SOUND_H

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

	typedef struct
	{
		unsigned int u32SampleRate;		// 采样率
		unsigned int u32BitWidth;		// 采样位宽
		unsigned int u32ChannNum;		// 声道模式，单声道或双声道
	} AUIDO_OUT_ATTR_S;

    // 初始化和去初始化只需调用一次
    NS_PLAYER_API int NS_PLAYER_APICALL NS_AUDIOOUT_Init();
    NS_PLAYER_API int NS_PLAYER_APICALL NS_AUDIOOUT_DeInit();

    // 打开播放器
	NS_PLAYER_API int NS_PLAYER_APICALL NS_AUDIOOUT_Open(
		unsigned int *pu32PlayerHandle,		// 返回播放器句柄,后续所有播放器操作都基于该播放器句柄进行
		AUIDO_OUT_ATTR_S *pAudioInfo		// 音频属性
    );

    // 输入媒体数据
    NS_PLAYER_API int NS_PLAYER_APICALL NS_AUDIOOUT_InputData(
		unsigned int u32PlayerHandle,	// 播放器句柄
		unsigned char* pu8Buffer,		// PCM数据
		unsigned int u32Length			// 数据长度
	);

    // 关闭播放器
    NS_PLAYER_API int NS_PLAYER_APICALL NS_AUDIOOUT_Close(
		unsigned int u32PlayerHandle	// 播放器句柄
    );

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
