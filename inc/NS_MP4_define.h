#ifndef	NS_MP4_DEFINE_H 
#define	NS_MP4_DEFINE_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif 

#define NS_MP4_SUCCESS 0
#define NS_ERR_MP4_NOT_INITED   -1
#define NS_ERR_MP4_NO_SPS   -100
#define NS_ERR_MP4_OPEN     -101
#define NS_ERR_MP4_INIT     -102

    typedef struct 
    {
        double duration;                     //file duration
    }NS_MP4_FILE_INFO_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif