/***********************************************************************************************************
*											���ô�ӡģ��
*  Ŀ��: ��ҪΪ�˹���Osp��ӡ��
*  �÷�: ͨ����EmPrintRegUserName�������ע���û�ID���ڳ���ʼ֮������reguser��ע��
*  ��һ�� CNmsPrint::RegUser(NMSPRINT_ID_MuXingmao, "muxingmao") 
*  �ڶ��� CNmsPrint::Print() ������һ����ID������ĸ�OspPrintf����
************************************************************************************************************/
#include "StdAfx.h"
#include "nmsprint.h"
#include <time.h>

map< string, PTRegUserInfo > CNmsPrint::m_mapUserS; 
char* CNmsPrint::strNmsDefaultScrip = "NMS";
/*---------------------------------------------------------------------
* �� �� ����RegUserS
* ��    �ܣ����ַ�����Ϊkey
* ����˵����s8* pKey						[in]	��ֵ
			s8* pUserName					[in]	����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/12/16	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::RegUser( s8* pKey , s8* pUserName )
{
	map< string, PTRegUserInfo >::iterator begin = m_mapUserS.find( pKey );
	if ( begin == m_mapUserS.end() )
	{
		PTRegUserInfo ptRegUserInfo = new TRegUserInfo;
		strcpy( ptRegUserInfo->achName, pUserName );
		ptRegUserInfo->bLogOpen = FALSE;
		m_mapUserS.insert( map< string, PTRegUserInfo >::value_type( pKey, ptRegUserInfo) );
		return TRUE;
	}
	else
	{
		PTRegUserInfo ptRegUserInfo = begin->second;
		strcpy( ptRegUserInfo->achName, pUserName );
	}
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����OpenLog 
* ��    �ܣ��򿪿��� ͨ��������ס��ID��������ǵã������ȵ���showalluser
* ����˵����[in] dwUserID Ψһ��ʶID
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::OpenLog( u32 dwIndex )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( dwIndex );
	if ( pUserInfo != NULL )
	{
		pUserInfo->bLogOpen = TRUE;
		OspPrintf( 1, 0, "�û� %s �����Ѿ���!\n", pUserInfo->achName );
		return TRUE;
	}
	OspPrintf( 1, 0, "û�д��û� ,��ͨ��showalluser�鿴�����û�\n" );
	return FALSE;	
}

/*---------------------------------------------------------------------
* �� �� ����OpenLog
* ��    �ܣ�ͨ���û����򿪿���
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::OpenLog( s8* pUser )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( pUser );
	if ( pUserInfo != NULL )
	{
		pUserInfo->bLogOpen = TRUE;
		OspPrintf( 1, 0, "�û� %s �����Ѿ���!\n", pUserInfo->achName );
		return TRUE;
	}
	OspPrintf( 1, 0, "û�д��û� ,��ͨ��showalluser�鿴�����û�\n" );
	return FALSE;	
}

/*---------------------------------------------------------------------
* �� �� ����CloseLog
* ��    �ܣ��رտ���
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::CloseLog( u32 dwIndex )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( dwIndex );
	if ( pUserInfo != NULL )
	{
		pUserInfo->bLogOpen = FALSE;
		OspPrintf( 1, 0, "�û� %s �����Ѿ��ر�!\n", pUserInfo->achName );
		return TRUE;
	}
	OspPrintf( 1, 0, "û�д��û� ,��ͨ��showalluser�鿴�����û�\n" );
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����CloseLog
* ��    �ܣ��رտ���
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::CloseLog( s8* pUser )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( pUser );
	if ( pUserInfo != NULL )
	{
		pUserInfo->bLogOpen = FALSE;
		OspPrintf( 1, 0, "�û� %s �����Ѿ��ر�!\n", pUserInfo->achName );
		return TRUE;
	}
	OspPrintf( 1, 0, "û�д��û� ,��ͨ��showalluser�鿴�����û�\n" );
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����IsLogOpen
* ��    �ܣ������Ƿ��
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::IsLogOpen( s8* pUserName )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( pUserName );
	if ( pUserInfo != NULL )
	{
		return pUserInfo->bLogOpen;
	}
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����IsLogOpen
* ��    �ܣ������Ƿ��
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsPrint::IsLogOpen( u32 dwUserId )
{
	PTRegUserInfo pUserInfo = GetRegUserInfo( dwUserId );
	if ( pUserInfo != NULL )
	{
		return pUserInfo->bLogOpen;
	}
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����GetRegUserInfo
* ��    �ܣ����ע���û���Ϣ
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
PTRegUserInfo CNmsPrint::GetRegUserInfo( u32 dwIndex )
{
	u32 dwCount = m_mapUserS.size();
	u32 dwTemp = 0;
	if ( dwCount > dwIndex )
	{
		map< string, PTRegUserInfo >::iterator begin = m_mapUserS.begin();
		while ( begin != m_mapUserS.end() )
		{
			if ( dwTemp == dwIndex )
			{
				return begin->second;
			}	
			dwTemp++;
			begin++;
		}
	}
	return NULL;
}

/*---------------------------------------------------------------------
* �� �� ����GetRegUserInfo
* ��    �ܣ����ע���û���Ϣ
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/13	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
PTRegUserInfo CNmsPrint::GetRegUserInfo( s8* pUser )
{
	map< string, PTRegUserInfo >::iterator begin = m_mapUserS.find( pUser );
	if ( begin != m_mapUserS.end() )
	{
		return begin->second;
	}
	return NULL;
}

BOOL32 CNmsPrint::Printf( s8* pUser, const s8* pScrip , ... )
{   
	PTRegUserInfo ptRegUserInfo = GetRegUserInfo( pUser );
	// û���ҵ�ע��Ļ��������һ�ν��������������Ĭ��ע�ᣬ�����Ժ����ͨ��showalluser����һ���Լ���ǰд�ĵ��Դ���
	if ( ptRegUserInfo == NULL )
	{
		CNmsPrint::RegUser( pUser, pUser );
		return FALSE;
	}
	if ( ptRegUserInfo->bLogOpen == FALSE )
	{
		return FALSE;
	}

	s8 result[1024];

	va_list arg;
	va_start( arg, pScrip ); // ��ȡ�����б�
	_vsnprintf( result, sizeof(result), pScrip, arg );
	va_end( arg ); // ����
	
	time_t _t = time(NULL);
	
	struct tm* _tmp = localtime(&_t);
	
	OspPrintf( 1, 0, "[ %02d:%02d:%02d ] [%s] %s\n", _tmp->tm_hour, _tmp->tm_min, _tmp->tm_sec, ptRegUserInfo->achName, result );
	
	return TRUE;
}

// �رտ���
API void closelog( s8* pUser )
{
	try
	{
		CNmsPrint::CloseLog( pUser );
	}
	catch ( ... )
	{
		try
		{
			s64* pData = (s64*)&pUser;
			CNmsPrint::CloseLog( *pData );
		}
		catch (...)
		{
			OspPrintf( 1, 0, "[system] operate error\n");
		}		
	}
}

API void openalllog()
{
	map< string, PTRegUserInfo >::iterator begin2 = CNmsPrint::m_mapUserS.begin();
	while ( begin2 != CNmsPrint::m_mapUserS.end() )
	{
		PTRegUserInfo ptRegUserInfo = begin2->second;
		ptRegUserInfo->bLogOpen = TRUE;		
		begin2++;
	}

	OspPrintf( 1, 0, "[NmsPrint]  ���п����Ѿ���!\n" );
}

API void closealllog()
{
	map< string, PTRegUserInfo >::iterator begin2 = CNmsPrint::m_mapUserS.begin();
	while ( begin2 != CNmsPrint::m_mapUserS.end() )
	{
		PTRegUserInfo ptRegUserInfo = begin2->second;
		ptRegUserInfo->bLogOpen = FALSE;		
		begin2++;
	}
	OspPrintf( 1, 0, "[NmsPrint]  ���п����Ѿ��ر�!\n" );
}

// �򿪿���
API void openlog( s8* pUser )
{
	try
	{
		CNmsPrint::OpenLog( pUser );
	}
	catch ( ... )
	{
		try
		{
			s32* pData = (s32*)&pUser;		
			CNmsPrint::OpenLog( *pData );
		}
		catch (...)
		{
			OspPrintf( 1, 0, "[system] operate error\n");
		}		
	}
}

API void reguser( s8* pUser, s8* pInfo )
{
	try
	{
		CNmsPrint::RegUser( pUser, pInfo );
	}
	catch ( ... )
	{
		try
		{
			s32* pData = (s32*)&pUser;
			char buf[20] = {0};
			_itoa( *pData, buf, sizeof(buf) );
			CNmsPrint::RegUser( buf, pInfo );
		}
		catch (...)
		{
			OspPrintf( 1, 0, "[system] operate error\n");
		}		
	}
}

API void nmsprinthelp()
{
	OspPrintf( 1, 0, "===============================���ô�ӡ�ӿ�===============================\n");
	OspPrintf( 1, 0, "* ����: showalluser()      �鿴����ע���û�\n");
	OspPrintf( 1, 0, "* ����: openlog( s8* )	 �򿪿���\n");
	OspPrintf( 1, 0, "* ����: reguser(s8*,s8*)   ע���û�\n");
	OspPrintf( 1, 0, "* ����: closelog( s8* )	 ͨ��ID�رտ���\n");
	OspPrintf( 1, 0, "===========================================================================");
}

// ��ʾ����ע���û�
API void showalluser()
{
	OspPrintf( 1, 0 ,"[NmsPrint] ��ǰ�û�����: %d \n", CNmsPrint::m_mapUserS.size() );
	map< string, PTRegUserInfo >::iterator begin1 = CNmsPrint::m_mapUserS.begin();
	s32 nIndex = 0;
	while ( begin1 != CNmsPrint::m_mapUserS.end() )
	{
		PTRegUserInfo ptRegUserInfo = begin1->second;
		string str = begin1->first;
		OspPrintf( 1, 0, "[NmsPrint] [%d] ID= %s Desc= %s LogOption= %s \n", nIndex++, str.c_str(), ptRegUserInfo->achName, ptRegUserInfo->bLogOpen ? "open" : "close" );
		begin1++;
	}
}