// rkcstruct.h: interface for the cmsstruct class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _h_siptoolstruct_h__
#define _h_siptoolstruct_h__

#include "siptoolconst.h"
#include "siptoolmessage.h"

//登录信息
typedef struct tagLoginInfo
{
	u32     m_dwIp;
	u16     m_wPort;
	s8      m_achName[MAX_ALIAS_LENGTH+1];
	s8      m_achPswd[MAX_ALIAS_LENGTH+1];

	tagLoginInfo()
	{
		memset( this, 0, sizeof(tagLoginInfo) );
	}
}TLoginInfo;

typedef struct tagNeiRegServerInfo
{
    s8      m_achAreaNum[MAX_AREANUM_LENGTH+1];
    s8      m_achIpAddr[MAX_IP_LENGTH+1];
    u16     m_wPort;

    tagNeiRegServerInfo()
    {
        memset( this, 0, sizeof(tagNeiRegServerInfo) );
    }
}TNeiRegServerInfo;

//#define ISIPFORMATRIGHT(pIpAddr)  do{\
//    u32 dwCount = 0;\
//    s32 i = 0;\
//    u32 dwA, dwB, dwC, dwD;\
//
//    // 检查是否只包含点和数字;
//    for (i = 0; pIpAddr[i] != '\0'; i++)\
//    {\
//        if (pIpAddr[i] > 256)\
//        {\
//            return FALSE;\
//        }\
//
//        if(!isdigit((int)pIpAddr[i]) && pIpAddr[i] != '.')\
//        {\
//            return FALSE;\
//        }\
//    }\
//
//    // 检查形式是否为X.X.X.X;
//    for (i = 0; pIpAddr[i+1] != '\0'; i++)\
//    {\
//        if (isdigit(pIpAddr[i]) && pIpAddr[i+1] == '.')\
//        {\
//            dwCount++;\
//        }\
//    }\
//    if (dwCount != 3)\
//    {\
//        return FALSE;\
//    }\
//
//    // 检查区间的合法性;
//    if ((swscanf(pIpAddr, L"%d.%d.%d.%d", &dwA, &dwB, &dwC, &dwD) == 4)\
//        &&(dwA >= 0 && dwA <= 255)\
//        &&(dwB >= 0 && dwB <= 255)\
//        &&(dwC >= 0 && dwC <= 255)\
//        &&(dwD >= 0 && dwD <= 255))\
//    {\
//        return TRUE;\
//    }\
//
//    return FALSE;\
//
//}while(0)

#endif 
