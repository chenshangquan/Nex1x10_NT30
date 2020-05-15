/*****************************************************************************
   ģ����      : KDV type 
   �ļ���      : kdvtype.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: KDV�궨��
   ����        : κ�α�
   �汾        : V3.0  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2004/02/17  3.0         κ�α�      ����
   2012/08/21  4.0         ������      ������ض���
   2014/07/15  5.0         ������      ����s8����Ϊsigned char
   2017/07/27  5.1         Τ����      VS2010���ϰ汾ʹ��C99��׼���壬����MemId������ָ�����Ͷ���
******************************************************************************/
#ifndef _KDV_TYPE_H_
#define _KDV_TYPE_H_

#ifndef _MSC_VER
    #include <stdint.h>
#elif (_MSC_VER >= 1600)
    #include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	  /* Type definition */
/*-----------------------------------------------------------------------------
ϵͳ�����ļ���������Ա�Ͻ��޸�
------------------------------------------------------------------------------*/

/* if using visual studio compiler */
#if (defined(_MSC_VER) && _MSC_VER < 1600)
    /* "s8 = signed char" is the right choice, but our apps heavily use s8 as char,
       define as this will cause type conversion compile errors.
       So give up to set "s8 = char".

       This alias is fault in Linux ARM platform, where char == unsigned char
    */
    #ifdef KDVTYPE_LEGACY_H
		typedef char			s8;
	#else
	    #define s8             	char
	#endif

    typedef unsigned char       u8;
    typedef signed short        s16;
    typedef unsigned short      u16;
    typedef signed int          s32;
   
	#ifdef KDVTYPE_LEGACY_H
		typedef unsigned long	u32;
	#else
		typedef unsigned int    u32;
	#endif

    typedef __int64             s64;
    typedef unsigned __int64    u64;
/* if using gcc, xcoder, intel or other C99 support compiler, including VC2010 and upper version */
#else
    #ifdef KDVTYPE_LEGACY_H
		typedef char			s8;
	#else
	    #define s8				char
	#endif
    /* see comments above */
    //typedef int8_t            s8;
    typedef uint8_t             u8;
    typedef int16_t             s16;
    typedef uint16_t            u16;
    typedef int32_t             s32;

    #ifdef KDVTYPE_LEGACY_H
		typedef unsigned long	u32;
    #else
    	typedef uint32_t        u32;
    #endif

    typedef int64_t             s64;
    typedef uint64_t            u64;
#endif // end of _MSC_VER

typedef char                    kdvchar;
typedef s32                     BOOL32;
typedef void*                   MemId;
typedef void*					kdvHandle;

#ifndef _MSC_VER
    #ifndef LPSTR
        #define LPSTR           char *
    #endif //LPSTR
    #ifndef LPCSTR
        #define LPCSTR          const char *
    #endif //LPCSTR
#endif //_MSC_VER

#ifndef TRUE
    #define TRUE    1
#endif

#ifndef FALSE
    #define FALSE   0
#endif

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _KDV_def_H_ */

/* end of file kdvdef.h */
