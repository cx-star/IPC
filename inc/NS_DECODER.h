#ifndef	NS_DECODER_H 
#define	NS_DECODER_H


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 


#if defined(WIN32)

#if defined(NS_PLAYER_EXPORTS)
#define NS_DECODER_API      __declspec( dllexport )
#define NS_DECODER_APICALL  __stdcall

#elif	defined(NS_PLAYER_LIB)
#define NS_DECODER_API      
#define NS_DECODER_APICALL  

#else 
#define NS_DECODER_API      __declspec( dllimport )
#define NS_DECODER_APICALL  __stdcall
#endif
#elif defined(LINUX)
#define NS_DECODER_API
#define NS_DECODER_APICALL
#else
#error "Please specify a design-in platform!"
#endif

#include "NS_NET_define.h"
#include "NS_DECODER_define.h"

	/*解码器接口（只解码，解码后处理由用户完成）*/ 
    
	NS_DECODER_API int NS_DECODER_APICALL NS_DECODER_Init();
	
	NS_DECODER_API int NS_DECODER_APICALL NS_DECODER_DeInit();

	/*打开解码器*/
    NS_DECODER_API int NS_DECODER_APICALL NS_VIDEODECODER_Open(
        unsigned int* pu32DecHandle, /*返回视频解码器句柄*/
		NS_VIDEO_FORMAT_E enumVideoFormat,
		NS_VIDEODECODER_CALLBACK cbVideoDecoderCallback, /*视频解码器回调*/
		void* pUserData  /*用户数据*/
		);

	NS_DECODER_API int NS_DECODER_APICALL NS_VIDEODECODER_InputData(
		unsigned int pu32DecHandle,/*解码器句柄*/
		unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
								 0x01-视频，0x02-音频*/
								 unsigned char* pu8Buffer,/* 帧数据 */
								 unsigned int u32Length,  /* 数据长度 */
								 NS_U64 u64TimeStamp    /* 时间戳*/
								 );

	NS_DECODER_API int NS_DECODER_APICALL NS_VIDEODECODER_Close(
		unsigned int pu32DecHandle 
		);

    NS_DECODER_API int NS_DECODER_APICALL NS_AUDIODECODER_Open(
        unsigned int* pu32DecHandle, /*返回音频解码器句柄*/
		NS_AUDIO_FORMAT_E enumAudioFormat,
		NS_AUDIODECODER_CALLBACK cbAudioDecoderCallback, /*音频解码器回调*/
		void* pUserData  /*用户数据*/
		);

	NS_DECODER_API int NS_DECODER_APICALL NS_AUDIODECODER_InputData(
		unsigned int pu32DecHandle,/*解码器句柄*/
		unsigned int u32DataType,/* 数据类型，详见NS_STREAM_TYPE_E
								 0x01-视频，0x02-音频*/
								 unsigned char* pu8Buffer,/* 帧数据 */
								 unsigned int u32Length,  /* 数据长度 */
								 NS_U64 u64TimeStamp    /* 时间戳*/
								 );

	NS_DECODER_API int NS_DECODER_APICALL NS_AUDIODECODER_Close(
		unsigned int pu32DecHandle 
		);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif