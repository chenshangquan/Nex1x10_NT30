#include "StdAfx.h"
#include "nmsinstance.h"
#include "NmsPrint.h"

CInstanceAssist* CNmsInstance::m_pBaseIntanceAssist = NULL;

// �����������ļ�
/*---------------------------------------------------------------------
* �� �� ����CreateInstanceAssist
* ��    �ܣ�����һ��Assist��ԭ��ģʽ��
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/20	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsInstance::CreateInstanceAssist()
{
	if ( m_pBaseIntanceAssist == NULL )
	{
		return FALSE;
	}
	m_pAssist = m_pBaseIntanceAssist->Clone();
	return TRUE;
}

/*---------------------------------------------------------------------
* �� �� ����SetInstanceAssistType
* ��    �ܣ�����ԭ��
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/20	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsInstance::SetInstanceAssistType( CInstanceAssist* pType )
{
	m_pBaseIntanceAssist = pType;
	return TRUE;
}

/*---------------------------------------------------------------------
* �� �� ����CheckMsg
* ��    �ܣ������ݽ���һЩ����ļ��
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/20	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CInstanceAssist::CheckMsg( CMessage *const pMsg )
{
	return TRUE;
}

/*---------------------------------------------------------------------
* �� �� ����SetInstanceParam
* ��    �ܣ����ӵ�ʱ�����ò���
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/23	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
void CInstanceAssist::SetInstanceParam(u32 dwDstAppId, u32 dwDstNode, u32 dwSrcAppId, u32 dwSrcNode )
{
	m_dwDstAppId	= dwDstAppId;
	m_dwDstNode		= dwDstNode;
	m_dwSrcAppId	= dwSrcAppId;
	m_dwSrcNode		= dwSrcNode;
	m_bConnected	= TRUE;
	int nCode = OspNodeDiscCBRegQ( m_dwDstNode, HIWORD16(m_dwSrcAppId), LOWORD16(m_dwSrcAppId) );
}

/*---------------------------------------------------------------------
* �� �� ����
* ��    �ܣ�
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/20	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CInstanceAssist::PostMsg( u16 wEvent, void* pBody /* = NULL */, u32 dwBodyLen /* = 0 */ )
{
	if ( m_bConnected == TRUE )
	{
		int nCode = OspPost( m_dwDstAppId ,wEvent, pBody, dwBodyLen, m_dwDstNode,m_dwSrcAppId, m_dwSrcNode );
		// ������Ϣ
		return TRUE;
	}	
	return FALSE;
}

/*---------------------------------------------------------------------
* �� �� ����DaemonInstanceEntry
* ��    �ܣ����������Ϣ
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/11	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
void CNmsInstance::DaemonInstanceEntry( CMessage *const pMsg, CApp* )
{
	try
	{
		if ( CanConnect( pMsg ) == TRUE )
		{
			OspPost( MAKEIID( GetAppID(), CInstance::PENDING ), pMsg->event, pMsg->content, pMsg->length, pMsg->dstnode, pMsg->srcid, pMsg->srcnode );
		}	
	}
	catch ( ... )
	{

	}
}

/*---------------------------------------------------------------------
* �� �� ����InstanceEntry
* ��    �ܣ�������Ϣ�������
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/11	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
void CNmsInstance::InstanceEntry( CMessage *const pMsg )
{
	try
	{
		// ����û�ж�Ӧ��Assist���󣬷���֮
		if ( m_pAssist == NULL )
		{
			if ( CreateInstanceAssist() == FALSE )
			{
				CNmsPrint::Printf( "Default", "�����������ʧ��!\n" );
				return;
			}
		}
		m_pAssist->TransData( this, pMsg );
	}
	catch (...) // һ������ע���Observer�Ѿ����ⲿdelete�ˣ�����ע�����һ������
	{
		OspPrintf( 1, 0, "Observer may be deleted \n" );
	}	
}

/*---------------------------------------------------------------------
* �� �� ����CanConnect
* ��    �ܣ�����һ�����ӵ�����
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/08/24	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsInstance::CanConnect( CMessage *const pMsg )
{
	return TRUE;
}

/*---------------------------------------------------------------------
* �� �� ����StartTimer
* ��    �ܣ�����һ��timer
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/09/09	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsInstance::StartTimer( u32 nTimer, long nMilliSeconds, u32 nPara /* = 0 */ )
{
	return SetTimer( nTimer, nMilliSeconds, nPara );
}

/*---------------------------------------------------------------------
* �� �� ����StopTimer
* ��    �ܣ�ֹͣһ��timer
* ����˵����
* �� �� ֵ��
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/09/09	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
BOOL32 CNmsInstance::StopTimer( u32 nTimer )
{
	return KillTimer( nTimer );
}