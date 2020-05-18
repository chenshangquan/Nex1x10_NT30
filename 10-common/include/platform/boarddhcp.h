/******************************************************************************
ģ����  �� DHCP-CLIENT
�ļ���  �� boarddhcp.h
����ļ���
�ļ�ʵ�ֹ��ܣ�DHCP-CLIENTģ������ṩ�ĺ궨��ͷ�ļ�
����    ��������
�汾    ��1.0.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
07/14/2006  1.0         ������      ����
******************************************************************************/
#ifndef _BOARDDHCP_H
#define _BOARDDHCP_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


/*�궨��*/

/*DHCP�ص���������Ϣ���ַ*/
#define DHCP_MSG_BASE			                    (u32)30000
/*֪ͨ�û�DHCP��õ�IP��ַ�Ļص���Ϣ����Ϣ�壺TBrdDhcpNotify */
#define DHCP_GET_IP_MSG							    (u32)( DHCP_MSG_BASE+1)
/*֪ͨ�û��豸ʧȥDHCP��õ�IP��ַ�Ļص���Ϣ����Ϣ�壺TBrdDhcpNotify */
#define DHCP_LOSS_IP_MSG							(u32)( DHCP_MSG_BASE+2)
/*֪ͨ�û�����Լ���ڵ��ֵò�����ַԭ�����豸ʧȥDHCP��õ�IP��ַ�Ļص���Ϣ����Ϣ�壺TBrdDhcpNotify */
#define DHCP_RENEW_FAIL_MSG							(u32)( DHCP_MSG_BASE+3)

#define DHCP_IFDOWN_LOSS_IP_MSG						 (u32)(DHCP_MSG_BASE+4)
#define DHCP_IFERROR_LOSS_IP_MSG					 (u32)(DHCP_MSG_BASE+5)
#define DHCP_DNS_MAX_DNS_SERVER 64

/*�ṹ�嶨��*/

/*֪ͨ�û�DHCP��û���ʧȥ��IP��ַ�Ľṹ��*/
typedef struct{
u8 byEthId;/*ȡ��/ʧȥIP��ַ�����ں�*/
u32 dwIpAddrs;/*ȡ��/ʧȥ��IP��ַ�������ֽ���*/
u32 dwMask;/*ȡ��/ʧȥ��IP��ַ�������룬�����ֽ���*/
u32 dwGateWay;/*ȡ��/ʧȥ��Ĭ�����أ������ֽ����п���Ϊ0����Ϊ�е�DHCP-Server��һ��Ϊ�豸ָ��Ĭ������*/
u32 dwDnsNum;/*DNS Server �������Ϊ64�� */
u32 dwDnsServer[DHCP_DNS_MAX_DNS_SERVER];/*ȡ��/ʧȥ��DNS Server �������ֽ���*/
}TBrdDhcpNotify;

/*������DHCP-Client�˹��ܵ������ϻ�ȡ��IP��ַ����Լ�������Ϣ�ṹ��*/
typedef struct{
u8 byEthId;/*ȡ��IP��ַ�����ں�*/
u32 dwIpAddrs;/*ȡ�õ�IP��ַ�������ֽ���*/
u32 dwMask;/*ȡ�õ�IP��ַ�������룬�����ֽ���*/
u32 dwGateWay;/*ȡ�õ�Ĭ�����أ������ֽ����п���Ϊ0����Ϊ�е�DHCP-Server��һ��Ϊ�豸ָ��Ĭ������*/
u32 dwLeaseInfo;/*�ܵ���Լʱ�䣬����Ϊ��λ*/
u32 dwDnsNum;/*DNS Server �������Ϊ64�� */
u32 dwDnsServer[DHCP_DNS_MAX_DNS_SERVER];/*ȡ��/ʧȥ��DNS Server �������ֽ���*/
}TBrdDhcpLeaseInfo;

typedef struct
{
	u32 dwDhcpcIsRun;
}TBrdDhcpcState;

/*�ص��������Ͷ���*/

/*================================
��������BrdDhcpNotifyCallBack
���ܣ���DHCP���IP��ַ������ĳ��ԭ��ʧȥ�ѻ�õ�IP��ַʱ��֪ͨ�û��Ļص�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwMsgID���¼����ͣ����������Ϣ���Ͷ���
		      pMsg������¼�������ƥ�����Ϣ���ݣ���������Ϣ����˵��
����ֵ˵���� ��ʱ����Ϊ0���Ժ������չ
==================================*/
typedef int(*BrdDhcpNotifyCallBack) (u32  dwMsgID ,void*  pMsg);


/*�����ӿڶ���*/


/*================================
��������BrdDhcpStart
���ܣ���ָ���������Ͽ���DHCP-Client�˹���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthId��Ҫ����DHCP-Client�˹��ܵ����ں�(��0��ʼ)
		      ptDhcpCallBack���ϲ�ע��Ļص�����ָ��
              bSetDefautGate:  �ص������Ƿ���ΪĬ������
����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdDhcpStart (u8  byEthId,  BrdDhcpNotifyCallBack  ptDhcpCallBack, BOOL32 bSetDefautGate);

/*================================
��������BrdDhcpRenew
���ܣ��ڿ�����DHCP-Client�˹��ܵ��������������������Լ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthId��Ҫ������Լ�����ں�(��0��ʼ) 
����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdDhcpRenew (u8  byEthId);

/*================================
��������BrdDhcpGetLeaseInfo
���ܣ��ڿ�����DHCP-Client�˹��ܵ������ϻ�ȡ��Լ�������Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthId��������DHCP-Client�˹��ܵ����ں�(��0��ʼ) 
			  ptBrdDhcpLeaseInfo:���صİ�����Լ����Ϣ�Ľṹ��ָ��
����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdDhcpGetLeaseInfo (u8  byEthId, TBrdDhcpLeaseInfo*  ptBrdDhcpLeaseInfo);

/*================================
��������BrdDhcpStop
���ܣ���ָ���������Ϲر�DHCP-Client�˹���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthId��Ҫ�ر�DHCP-Client�˹��ܵ����ں�(��0��ʼ) 
����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdDhcpStop (u8  byEthId);

/*================================
��������BrdDhcpGetIfstate
���ܣ���ָ���������ϵ�dhcp��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEth�����ں�(��0��ʼ) 
����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdDhcpGetIfstate(u8 byEth, TBrdDhcpcState *tBrddhcpcIfState);



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /*_BOARDDHCP_H*/
