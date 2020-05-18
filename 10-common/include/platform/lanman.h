#ifndef _LAN_MAN_H
#define _LAN_MAN_H

#include "kdvtype.h"


#ifdef _cplusplus
extern "C"
{
#endif

#define INVALID_LANID       (u8)0xFF
	
#define MAX_LAN_CAPTION     64
#define MAX_FILEPATH        128
#define MAX_LAN_PACKET      10
#define MAX_DLG_NUM         512
#define MAX_TEXT_NUM        1024

	
typedef struct tagLanInfo
{
	u8 LanID;
	s8 LanCaption[MAX_LAN_CAPTION];
	s8 RcFile[MAX_FILEPATH];
	s8 Textfile[MAX_FILEPATH];
	BOOL32 bIsLoaded;
//  public:
//  	tagLanInfo(){ memset( this, 0, sizeof( tagLanInfo ) );}
}TLanInfo, *PTLanInfo;

BOOL32 InitLanManager( char *pszLanCfgPath );
BOOL32 GetLanuageNum( u8 &byNum );
BOOL32 GetLanInfo( u8 byLanId, TLanInfo &tLanInfo );
s8* GetDlgCaption( u8 byLanId, u32 dwDlgId );
s8* GetCtrlCaption( u8 byLanId, u32 dwDlgId, u32 dwCtrlId );
s8* GetText( u8 byLanId, s8 *pszTextId );

/************************************************************************
�ַ�����ת�������ӿ�
����˵����pszInput����Ҫת�����ַ���
          ppszOutput:ת������ַ���ָ��
ע��������������º����󣬱����ֶ��ͷ�*ppszOutput��ָ��Ŀռ䣬
          ���������ڴ����
��  ��		�汾		�޸���		�߶���    �޸�����
20120326    1.0	    	���˿�                   ����
************************************************************************/
u32 utf8_to_gb2312( char* pszInput, char** ppszOutput );
u32 utf8_to_unicode( char* pszInput, char** ppszOutput );
u32 gb2312_to_unicode( char* pszInput, char** ppszOutput );
u32 gb2312_to_utf8( char* pszInput, char** ppszOutput );
u32 unicode_to_utf8( char* pszInput, char** ppszOutput );
u32 unicode_to_gb2312( char* pszInput, char** ppszOutput );
char *unicode_to_gb2312( char* pszInput, u32 dwLen );
char *unicode_to_utf8( char* pszInput, u32 dwLen );


/************************************************************************
�ַ�����ת��
����˵����pszInput����Ҫת�����ַ�ָ��
          pszOutput��ת������ַ���ָ��
ע���������ת����2048���ֽڵ��ַ�����ת���󳤶ȣ�
��  ��		�汾		�޸���		�߶���    �޸�����
20120326    1.0	    	���˿�                   ����
************************************************************************/
u32 utf8_to_gb2312( const char* pszInput, char* pszOutput, u32 dwOutLen );
u32 utf8_to_unicode( const char* pszInput, char* pszOutput, u32 dwOutLen );
u32 gb2312_to_unicode( const char* pszInput, char* pszOutput, u32 dwOutLen );
u32 gb2312_to_utf8( const char* pszInput, char* pszOutput, u32 dwOutLen );
u32 unicode_to_gb2312( const char* pszInput, char* pszOutput, u32 dwInLen, u32 dwOutLen );
u32 unicode_to_utf8( const char* pszInput, char* pszOutput, u32 dwInLen, u32 dwOutLen );



#ifdef _cplusplus
}
#endif


#endif /* _LAN_MAN_H */