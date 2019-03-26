#ifndef	NS_DECODER_DEFINE_H 
#define	NS_DECODER_DEFINE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#define NS_DECODER_SUCCESS 0
#define NS_ERR_DECODER_NOT_INITED		-1
#define NS_ERR_FORMAT_NOT_SUPPORTED		-2

    /* 视频解码回调*/
    typedef int (*NS_VIDEODECODER_CALLBACK)(unsigned int nWidth,	/* 宽度*/
											unsigned int nHeight,	/* 高度*/
											unsigned char *in_Y,	/* Y分量*/
											unsigned int nYStride,	/* Y分量跨度*/
											unsigned char *in_U,	/* U分量*/
											int nUStride,			/* U分量跨度*/
											unsigned char *in_V,	/* V分量*/
											int nVStride,			/* V分量跨度*/
											NS_U64 u64TimeStamp,
                                 void* pUserData);        /* 用户数据*/

    /* 音频解码回调*/
    typedef int (*NS_AUDIODECODER_CALLBACK)(
		unsigned char * pu8Buffer,	/* PCM数据*/
		unsigned int u32Length,	/* PCM数据长度*/
		NS_U64 u64TimeStamp,
		void* pUserData);        /* 用户数据*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif