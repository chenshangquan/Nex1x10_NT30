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
#define DSVERSION       "Dataswitch_gep 40.10.07.07.060105"

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

//��ǰֻ֧��UDPЭ��
#define DS_ONLY_ALLOW_USE_UDP_CURRENT		( DS_ERROR + 100 )
//�ŵ������ڣ������ȴ���
#define DS_CHANNEL_NOT_EXIST				( DS_ERROR + 101 )
//�ŵ��Ѿ���ռ��
#define DS_CHANNEL_ALREADY_EXIST			( DS_ERROR + 102 )

//����ȫ����������Ϣʧ�ܣ�������д���
#define DS_SEND_GEP_COMMAND_LENGTH_ERROR	( DS_ERROR + 110 )
//����ȫ����������Ϣʧ�ܣ�Socket���ͳ���
#define DS_SEND_GEP_COMMAND_SOCK_ERROR		( DS_ERROR + 111 )

//����ʱ���������޸ĳ���
#define SENDMEM_MAX_MODLEN					(u8)32

//����������ս��ṹ,��ʾ���ն˵��׽��ֲ���
//һ����m_dwProtocol(=SOCK_DGRAM)ʱ,��ʾ���ղ���UDPЭ��,m_bTCPServer������:
//	1��Ҫ��m_dwRecvIP������dsCreate���������ӿ�IP������,����Ҫ��m_wRecvPort(!=0);
//	2��m_dwSrcIP(!=0) && m_wSrcPort(!=0),��ʾ��Դת���Ĺ���;
//	3��m_dwSrcIP(=0) && m_wSrcPort(=0),��ʾ���˿�ת���Ĺ���;
//	4�����������Ϲ淶;
//������m_dwProtocol(=SOCK_STREAM)ʱ,��ʾ���Ͳ���TCPЭ��,m_dwMulticastGrp������:
//	1��Ҫ��m_dwRecvIP������dsCreate���������ӿ�IP������,����Ҫ��m_wRecvPort(!=0);
//	2��m_bTCPServer(=FALSE),��ʾ��ΪTCP�ͻ���,m_bTCPServer(=TRUE),��ʾ��ΪTCP�����;
//	3������IP Port�Ա�ʾԴ,Ҫ�� m_dwSrcIP(!=0) && m_wSrcPort(!=0);
//	4�����������Ϲ淶;
struct TSwitchRecvPoint
{
	u32 m_dwProtocol;			//���ղ���Э��(SOCK_STREAM��ʾ����TCP,SOCK_DGRAM��ʾ����UDP)
	BOOL32 m_bTCPServer;		//������ΪTCP����˻���TCP�ͻ���
	u32 m_dwRecvIP;				//���ؽ���IP
	u16 m_wRecvPort;			//���ؽ��ն˿�
	u32 m_dwSrcIP;				//ԴIP
	u16 m_wSrcPort;				//Դ�˿�
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
������      :	GepCommandCallBack
����        :	������Ϣ�ص�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	dwProtocol ����Э��;
				dwLocalIP ����IP;
				wLocalPort ���ض˿�;
				dwPeerIP Զ��IP;
				wPeerPort Զ�˶˿�;
				pbyCommand ������Ϣ;
				dwCommandLength ������Ϣ����;
����ֵ˵��  :	��
=====================================================================================================*/
typedef void (*GepCommandCallBack)( u32 dwProtocol , u32 dwLocalIP , u16 wLocalPort ,
								   u32 dwPeerIP , u16 wPeerPort , u8* pbyCommand , u32 dwCommandLength );

/*===================================================================================================
������      :	dsSetGepCommandCallback
����        :	����������Ϣ�ص�����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	pfGepConnectCmdCallBack ���������ŵ�������Ϣ�ص�����;
				pfGepListenCmdCallBack ���������ŵ�������Ϣ�ص�����;
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSetGepCommandCallback( GepCommandCallBack pfGepConnectCmdCallBack ,
							GepCommandCallBack pfGepListenCmdCallBack );

/*===================================================================================================
������      :	dsSetupChannelConnect
����        :	����Զ�ˣ��������������ŵ�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	dwProtocol ����Э��;
				dwLocalIP ����IP;
				wLocalPort ���ض˿�;
				dwPeerIP Զ��IP(����TCPЭ��ʱ����Ҫ);
				wPeerPort Զ�˶˿�(����TCPЭ��ʱ����Ҫ);
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSetupChannelConnect( u32 dwProtocol , u32 dwLocalIP , u16 wLocalPort ,
						  u32 dwPeerIP , u16 wPeerPort );

/*===================================================================================================
������      :	dsSetupChannelListen
����        :	�ȴ�Զ�����ӣ��������������ŵ�;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	dwProtocol ����Э��;
				dwLocalIP ����IP;
				wLocalPort ���ض˿�;
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSetupChannelListen( u32 dwProtocol , u32 dwLocalIP , u16 wLocalPort );

/*===================================================================================================
������      :	dsSendGepCommand
����        :	����ȫ����������Ϣ;
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	dwProtocol ����Э��;
				dwLocalIP ����IP;
				wLocalPort ���ض˿�;
				dwPeerIP Զ��IP;
				wPeerPort Զ�˶˿�;
				pbyCommand ������Ϣ;
				dwCommandLength ������Ϣ����;
����ֵ˵��  :	DSOK	�����ɹ�
				����	����ʧ�ܵĴ�����
=====================================================================================================*/
u32 dsSendGepCommand( u32 dwProtocol , u32 dwLocalIP , u16 wLocalPort ,
					 u32 dwPeerIP , u16 wPeerPort ,
					 u8* pbyCommand , u32 dwCommandLength );

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
