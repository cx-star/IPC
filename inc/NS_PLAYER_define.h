#ifndef	NS_PLAYER_DEFINE_H 
#define	NS_PLAYER_DEFINE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#define NS_PLAYER_SUCCESS 0
#define NS_ERR_NOT_INITED   -1

    typedef enum
    {
        NS_SNAPSHOT_FORMAT_JPEG = 0,
        NS_SNAPSHOT_FORMAT_BMP,
    }NS_SNAPSHOT_FORMAT_E;

    typedef int (* NS_ON_SNAPSHOT_CALLBACK) ( 
        unsigned int u32PlayerHandle,/* 句柄 */
        NS_SNAPSHOT_FORMAT_E format,
        unsigned char* pu8Buffer,/* 数据包含帧头 */
        unsigned int u32Length,  /* 数据长度 */
        void* pUserData /*用户数据*/
        );

	typedef void(__stdcall  * NS_DRAW_CALLBACK  ) ( 
		long	nPort,
		long	hDc, 
		long	nUser
		);

	typedef struct{
		unsigned int overlay;  /*1 启用overlay/ 0 禁用overlay */
		unsigned int keycolor; /*  overlay的关键色*/
		unsigned int bufcount; /*  解码缓存大小*/
	}NS_PLAYER_ATTR;
	
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif