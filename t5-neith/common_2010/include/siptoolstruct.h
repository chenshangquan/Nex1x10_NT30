// rkcstruct.h: interface for the cmsstruct class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _h_siptoolstruct_h__
#define _h_siptoolstruct_h__

#include "siptoolconst.h"
#include "siptoolmessage.h"

//��¼��Ϣ
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

#endif 
