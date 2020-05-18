/*****************************************************************************
ģ����      : dataswitch_kdm
�ļ���      : dataswitch_kdm.h
����ļ�    : dataswitch_kdm.cpp
�ļ�ʵ�ֹ���: ���ϵͳȫ������Ŀý��������
����		: gie
�汾        : V4.0
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾     �޸���      �޸�����
2005/11/02  4.0      gie         ����
******************************************************************************/

#ifndef __DATA_SWITCH_KDM_H__
#define __DATA_SWITCH_KDM_H__

#include "osp.h"
#include "kdmmedianet.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#pragma pack( push )
#pragma pack( 1 )
#endif

//DataSwitch_kdm�汾��
#define DSVERSION       "Dataswitch_kdm 40.10.06.06.051208"

//DataSwitch ����IP������
#define MAX_DS_IP_NUM						(u8)2

//DataSwitch�鲥��������
#define MAX_DS_MCGRP_NUM					(u16)256

//���ݰ���󳤶ȣ�����ͷ��
#define MAX_RTP_PACKET_LENGTH				(u32)1600

//��ʱ�ȴ�ʱ��
#define MAX_COMMAND_TIMEOUT					(u32)8

//�����ɹ�
#define DS_OK								(u32)0
//����������
#define DS_ERROR							(u32)10000

//DataSwitch�Ѿ��ɹ���ʼ��
#define DS_ALREADY_INITIAL					( DS_ERROR + 1 )
//DataSwitch��ʼ��IP��������
#define DS_INTERFACE_ERROR					( DS_ERROR + 2 )
//�����ڲ�ͨ��Socketʧ��
#define DS_CREATE_INTERIOR_SOCKET_FAILED	( DS_ERROR + 3 )
//DataSwitchδ�ɹ���ʼ��
#define DS_NOT_INITIAL						( DS_ERROR + 4 )
//�ӿڲ�����IP��Ч
#define DS_NOT_VALID_IP						( DS_ERROR + 5 )
//�ӿڲ�����Port��Ч
#define DS_NOT_VALID_PORT					( DS_ERROR + 6 )
//�ӿڲ�����IP����DataSwitch����IP
#define DS_NOT_DATASWITCH_IP				( DS_ERROR + 7 )
//�ӿڲ�����SessionID����
#define DS_INVALID_SESSION_ID				( DS_ERROR + 8 )

//��������ά�������ݽ�������ʧ��
#define DS_CREATE_DATASWITCHTASK_FAILED		( DS_ERROR + 10 )
//�����ڲ�ͨ���ŵ�ʧ��
#define DS_START_INTERIOR_CONNECT_FAILED	( DS_ERROR + 11 )
//������������ʧ��
#define DS_CREATE_TCPCONNECTTASK_FAILED		( DS_ERROR + 12 )
//ָ�����Ϊ��
#define DS_INVALID_NULL_POINTER				( DS_ERROR + 13 )
//��Ч��Socket������
#define DS_NO_MORE_VALID_SOCKET				( DS_ERROR + 14 )

//����������Ϣ������ά�������ݽ�������ʧ��
#define DS_SENDCOMMAND_SEND_FAILED			( DS_ERROR + 20 )
//������ȴ�����ά�������ݽ�������ظ���Ϣ��ʱ
#define DS_SENDCOMMAND_SELECT_TIMEOUT		( DS_ERROR + 21 )
//������ȴ�����ά�������ݽ�������ظ���Ϣʧ��
#define DS_SENDCOMMAND_SELECT_FAILED		( DS_ERROR + 22 )
//��������չ���ά�������ݽ�������ظ���Ϣʧ��
#define DS_SENDCOMMAND_RECV_FAILED			( DS_ERROR + 23 )

//�������ս��ʧ��(��ʱTCP���ս�㲻�ܸ���TCP���ͽ���Socket��UDP����)
#define DS_CREATE_RECVNODE_FAILED_REUSE		( DS_ERROR + 30 )
//�������ս��ʧ��(����Socketʧ��)
#define DS_CREATE_RECVNODE_FAILED_SOCKET	( DS_ERROR + 31 )
//�������ս��ʧ��(��ΪTCP����˼���ʧ��)
#define DS_CREATE_RECVNODE_FAILED_LISTEN	( DS_ERROR + 32 )
//�������ս��ʧ��(�������ʧ��)
#define DS_CREATE_RECVNODE_FAILED_NODE		( DS_ERROR + 33 )
//�������ս��ʧ��(�����鲥��ʧ��)
#define DS_CREATE_RECVNODE_FAILED_JOINMCGRP	( DS_ERROR + 34 )

//���ý��ʧ��(TCP��ַ����ͬʱ��Ϊ����˺Ϳͻ���)
#define DS_TCP_CANT_AS_SERVER_AND_CLIENT_SIMULTANEOUS			( DS_ERROR + 40 )
//���ý��ʧ��(TCP�ͻ��˲�����ͬʱ���Ӷ�������)
#define DS_TCP_CLIENT_CANT_CONNECT_MULTI_SERVER_SIMULTANEOUS	( DS_ERROR + 41 )
//���ý��ʧ��(�����鲥��ʧ��)
#define DS_REUSE_RECVNODE_FAILED_JOINMCGRP						( DS_ERROR + 41 )

//����Դ���ʧ��(�������ʧ��)
#define DS_CREATE_SRCNODE_FAILED_NODE		( DS_ERROR + 50 )

//�������ͽ��ʧ��(��ʱTCP���ͽ�㲻�ܸ���TCP���ս���Socket��UDP����)
#define DS_CREATE_SENDNODE_FAILED_REUSE		( DS_ERROR + 60 )
//�������ͽ��ʧ��(����Socketʧ��)
#define DS_CREATE_SENDNODE_FAILED_SOCKET	( DS_ERROR + 61 )
//�������ͽ��ʧ��(��ΪTCP����˼���ʧ��)
#define DS_CREATE_SENDNODE_FAILED_LISTEN	( DS_ERROR + 62 )
//�������ͽ��ʧ��(�������ʧ��)
#define DS_CREATE_SENDNODE_FAILED_NODE		( DS_ERROR + 63 )

//��������Ŀ����ʧ��(�������ʧ��)
#define DS_CREATE_SENDTOITEM_FAILED_ITEM	( DS_ERROR + 70 )
//��������Ŀ����ʧ��(��ֹ��ͬ�����飬��ͬ����Ŀ�ĵĹ���)
#define DS_CREATE_SENDTOITEM_FORBID_SAMERECV_SAMESENDTO	( DS_ERROR + 71 )
//��������Ŀ����ʧ��(��ֹ��ͬ������Ĺ���)
#define DS_CREATE_SENDTOITEM_FORBID_SAMESEND	( DS_ERROR + 72 )

//���ս�㲻����
#define DS_NO_EXIST_RECVNODE				( DS_ERROR + 80 )
//Դ��㲻����
#define DS_NO_EXIST_SRCNODE					( DS_ERROR + 81 )
//���ͽ�㲻����
#define DS_NO_EXIST_SENDNODE				( DS_ERROR + 82 )
//����Ŀ���㲻����
#define DS_NO_EXIST_SENDTOITEM				( DS_ERROR + 83 )

//���÷���UDP���ջظ�
#define DS_UDP_RECV_ACK_FAILED_RECVNODE		( DS_ERROR + 90 )

//����ʱ���������޸ĳ���
#define SENDMEM_MAX_MODLEN					(u8)32

//����������ս��ṹ,��ʾ���ն˵��׽��ֲ���
//һ����m_dwProtocol(=SOCK_DGRAM)ʱ,��ʾ���ղ���UDPЭ��,m_bTCPServer������:
//	1��Ҫ��m_dwRecvIP������dsCreate���������ӿ�IP������,����Ҫ��m_wRecvPort(!=0);
//	2��m_bUseSessionID(=FALSE),��ʾ��IP Port�Ա�ʾԴ:
//		a��m_dwSrcIP(=0) && m_wSrcPort(=0) ���˿�ת���Ĺ���;
//		b��m_dwSrcIP(!=0) && m_wSrcPort(!=0) ��Դת���Ĺ���;
//	3��m_bUseSessionID(=TRUE),��ʾ����SessionID��ʾԴ,����Ҫ��m_dwSrcSessionID(!=0);
//	4��m_dwMulticastGrpΪ�鲥��ַʱ,Ҫ���������鲥���������;
//	5�����������Ϲ淶;
//������m_dwProtocol(=SOCK_STREAM)ʱ,��ʾ���Ͳ���TCPЭ��,m_dwMulticastGrp������:
//	1��Ҫ��m_dwRecvIP������dsCreate���������ӿ�IP������,����Ҫ��m_wRecvPort(!=0);
//	2��m_bTCPServer(=FALSE),��ʾ��ΪTCP�ͻ���,m_bUseSessionID������:
//		Ҫ�� m_dwSrcIP(!=0) && m_wSrcPort(!=0);
//	3��m_bTCPServer(=TRUE),��ʾ��ΪTCP�����:
//		a��m_bUseSessionID(=FALSE),��ʾ��IP Port�Ա�ʾԴ,Ҫ�� m_dwSrcIP(!=0) && m_wSrcPort(!=0);
//		b��m_bUseSessionID(=TRUE),��ʾ����SessionID��ʾԴ,Ҫ�� m_dwSrcSessionID(!=0);
//	4�����������Ϲ淶;
struct TSwitchRecvPoint
{
	u32 m_dwProtocol;			//���ղ���Э��(SOCK_STREAM��ʾ����TCP,SOCK_DGRAM��ʾ����UDP)
	BOOL32 m_bTCPServer;		//������ΪTCP����˻���TCP�ͻ���
	BOOL32 m_bUseSessionID;		//�����Ƿ����SessionID��ʾԴ
	u32 m_dwRecvIP;				//���ؽ���IP
	u16 m_wRecvPort;			//���ؽ��ն˿�
	u32 m_dwMulticastGrp;		//������Ҫ������鲥��
	u32 m_dwSrcIP;				//ԴIP
	u16 m_wSrcPort;				//Դ�˿�
	u32 m_dwSrcSessionID;		//ԴSessionID
}
#ifndef _MSC_VER
__attribute__ ( (packed) )
#endif
;

//���������ͽ��ṹ,��ʾ���Ͷ˵��׽��ֲ���
//һ����m_dwProtocol(=SOCK_DGRAM)ʱ,��ʾ���Ͳ���UDPЭ��,m_bTCPServer������:
//	1��Ҫ��m_dwSendIP������dsCreate���������ӿ�IP������,����m_wSendPort(!=0);
//	2������UDPЭ�鷢��,ͬʱҪ�� m_dwSendtoIP(!=0) && m_wSendtoPort(!=0);
//	3�����������Ϲ淶;
//������m_dwProtocol(=SOCK_STREAM)ʱ,��ʾ���Ͳ���TCPЭ��:
//	1��Ҫ��m_dwSendIP������dsCreate���������ӿ�IP������,����m_wSendPort(!=0);
//	2��m_bTCPServer(=FALSE),��ʾ��ΪTCP�ͻ���,ͬʱҪ�� m_dwSrcIP(!=0) && m_wSrcPort(!=0);
//	3��m_bTCPServer(=TRUE),��ʾ��ΪTCP�����,ͬʱҪ�� m_dwSrcIP(!=0) && m_wSrcPort(!=0);
//	4�����������Ϲ淶;
struct TSwitchSendPoint
{
	u32	m_dwProtocol;			//���Ͳ���Э��(SOCK_STREAM��ʾ����TCP,SOCK_DGRAM��ʾ����UDP)
	BOOL32 m_bTCPServer;		//������ΪTCP����˻���TCP�ͻ���
	u32 m_dwSendIP;				//���ط���IP
	u16 m_wSendPort;			//���ط��Ͷ˿�
	u32 m_dwSendtoIP;			//����Ŀ��IP
	u16 m_wSendtoPort;			//����Ŀ��˿�
}
#ifndef _MSC_VER
__attribute__ ( (packed) )
#endif
;

//��������ṹ,��Ϊ�����������
//	a��UDP���ա�TCP��Ϊ����˽��� ���Բ���SessionID��ʾԴ
//	b��TCP��Ϊ�ͻ��˽��� ���ܲ���SessionID��ʾԴ
//	c������ ���ܲ���SessionID��ʾ����Ŀ��
struct TSwitchRule
{
	TSwitchRecvPoint m_tSwitchRecvPoint;	//���ս��
	TSwitchSendPoint m_tSwitchSendPoint;	//���ͽ��
}
#ifndef _MSC_VER
__attribute__ ( (packed) )
#endif
;

/*===================================================================================================
������      :	dsCreate
����        :	��ʼ��DataSwitch���ܿ�,ʹ��DataSwitch������ȵ��øýӿ�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	byIpNum	�����ӿ�IP��Ŀ(������ΪMAX_DS_IP_NUM);
				pdwIp	�����ӿ�IP;
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsCreate( u8 byIpNum , u32* pdwIp );

/*===================================================================================================
������      :	dsDestroy
����        :	ж��DataSwitch���ܿ�,����ʹ��ʱ����ñ��ӿ�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	��
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsDestroy( );

/*===================================================================================================
������      :	dsAddSwitchRule
����        :	������������;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	ptSwitchRule	��������
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsAddSwitchRule( const TSwitchRule* ptSwitchRule );

/*===================================================================================================
������      :	dsRemoveSwitchRule
����        :	ɾ����������;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	ptSwitchRule	��������
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsRemoveSwitchRule( const TSwitchRule* ptSwitchRule );

/*===================================================================================================
������      :	dsSetSendUDPRecvACK
����        :	���÷���UDP���ջظ�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	dwRecvIP	����IP
				wRecvPort	����Port
				bSendACK	�Ƿ��ͻظ�
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSetSendUDPRecvACK( u32 dwRecvIP , u16 wRecvPort , BOOL32 bSendACK = TRUE );

//����TCP��·״̬
enum TLinkStatus
{
	RECV_CONNECTING = 1,	//������·������
	RECV_CONNECTED,			//������·�Ѿ�����

	SEND_CONNECTING = 10,	//������·������
	SEND_CONNECTED,			//������·�Ѿ�����
};

/*===================================================================================================
������      :	LinkStatusCallBack
����        :	TCP��·�Ĵ�����ά���ص�����(������Ҫ�ڸú�������������ʱ�Ĳ���)
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	ptSwitchRule	��������
				tRuleStatus		��·״̬;
����ֵ˵��  :	��
=====================================================================================================*/
typedef void (*LinkStatusCallBack)( const TSwitchRule* ptSwitchRule, TLinkStatus tLinkStatus );

/*===================================================================================================
������      :	dsSetRuleStatusCallback
����        :	������·����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	pfRuleStatusCallback	��·�ص�����;
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSetRuleStatusCallback( LinkStatusCallBack pfLinkStatusCallback );

/*===================================================================================================
������      :	dsGetRecvPktCount
����        :	��ѯ���հ���;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	ptSwitchRule	��������
				dwRecvPktCount	���հ���
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsGetRecvPktCount( const TSwitchRule* ptSwitchRule , u32& dwRecvPktCount );

/*===================================================================================================
������      :	dsGetSendPktCount
����        :	��ѯ���Ͱ���;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	ptSwitchRule	��������
				dwSendPktCount	���Ͱ���
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsGetSendPktCount( const TSwitchRule* ptSwitchRule , u32& dwSendPktCount );

/*===================================================================================================
������      :	dsGetRecvBytesCount
����        :	��ѯ�������ֽ���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	
����ֵ˵��  :	���ؼ�ʱ�����ֽ���
=====================================================================================================*/
u32 dsGetRecvBytesCount( );

/*===================================================================================================
������      :	dsGetSendBytesCount
����        :	��ѯ�������ֽ���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	
����ֵ˵��  :	���ؼ�ʱ�ֽ���
=====================================================================================================*/
u32 dsGetSendBytesCount( );

/*===================================================================================================
������      :	dsinfo
����        :	��ʾ����ת������Ϳɶ�Socket��״̬;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	��
����ֵ˵��  :	��
=====================================================================================================*/
API void dsinfo();

/*===================================================================================================
������      :	dsver
����        :	��ӡ�汾��;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	��
����ֵ˵��  :	��
=====================================================================================================*/
API void dsver();

/*===================================================================================================
������      :	dsdebug
����        :	�л���ӡ����,��ʼ��ӡ�ر�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	��
����ֵ˵��  :	��
=====================================================================================================*/
API void dsdebug();

/*===================================================================================================
������      :	dshelp
����        :	��ӡDataSwitch֧�ֵ������ʹ�÷���;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	��
����ֵ˵��  :	��
=====================================================================================================*/
API void dshelp();

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif/*!__DATA_SWITCH_KDM_H__*/
