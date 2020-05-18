/******************************************************************************
ģ����  ��Kdm2x18Os
�ļ���	��kdm2x18.h
����ļ�����
�ļ�ʵ�ֹ��ܣ�KDM2x18 �����������ܵĽӿڶ���
����	��������
�汾	��2.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��		�汾		�޸���		�޸�����
11/17/2004	1.0         ������      ����
08/22/2005	2.0         ť����      ��׼��
******************************************************************************/

#ifndef _KDM2X18VERCTRL_H_
#define _KDM2X18VERCTRL_H_ 

#define KDM2X18VERCTRL_LISTEN_PORT        1721          /*�����˿�*/
#define KDM2X18VERCTRL_MAX_CONTENT_LEN    4000          /*��Ϣ�����󳤶�*/
#define KDM2X18VERCTRL_APP_NAME           "kdmvs"       /*Ӧ�ó�����*/

/*��Ϣ�ṹ����*/
#pragma pack(push, 1)
typedef struct tagMessage
{
	u8 byCode;                                   /*��Ϣ��*/
	u8 byReserved1;                              /*����*/
	u8 byReserved2;                              /*����*/
	u8 byReserved3;                              /*����*/
	u32 dwValidData;                             /*��Ϣ����*/
	u8 abyData[KDM2X18VERCTRL_MAX_CONTENT_LEN];  /*��Ϣ����*/
} TMessage, *PTMessage;
#pragma pack(pop)

/*��Ϣ�붨��*/
#define MESSAGE_BASE                           0                 /*��Ϣ��Ļ�ֵ*/

/*��ʼ�����ļ���Ϣ*/
#define CLIENT_AGENT_DOWN_START_REQ            MESSAGE_BASE+1
#define AGENT_CLIENT_DOWN_START_ACK            MESSAGE_BASE+2
#define AGENT_CLIENT_DOWN_START_NACK           MESSAGE_BASE+3

/*�����ļ���Ϣ*/
#define CLIENT_AGENT_DOWN_SND_DATA             MESSAGE_BASE+4
#define AGENT_CLIENT_DOWN_RCV_OK               MESSAGE_BASE+5
#define AGENT_CLIENT_DOWN_RCV_ERROR            MESSAGE_BASE+6

/*ֹͣ�����ļ���Ϣ*/
#define CLIENT_AGENT_DOWN_STOP_REQ             MESSAGE_BASE+7
#define AGENT_CLIENT_DOWN_STOP_ACK             MESSAGE_BASE+8
#define AGENT_CLIENT_DOWN_STOP_NACK            MESSAGE_BASE+9

/*������һ���ļ�֪ͨ��Ϣ*/
#define CLIENT_AGENT_DOWN_FINISHONE_NOTIFY     MESSAGE_BASE+10
#define AGENT_CLIENT_DOWN_FINISHONE_ACK        MESSAGE_BASE+11
#define AGENT_CLIENT_DOWN_FINISHONE_NACK       MESSAGE_BASE+12

/*����˱�����д�ļ�������Ϣ*/
#define AGENT_CLIENT_WRITE_PROCESS_NOTIFY      MESSAGE_BASE+13
#define CLIENT_AGENT_WRITE_PROCESS_ACK         MESSAGE_BASE+14
#define CLIENT_AGENT_WRITE_PROCESSE_NACK       MESSAGE_BASE+15

/*�������д��һ���ļ�֪ͨ��Ϣ*/
#define AGENT_CLIENT_WRITE_FINISH_NOTIFY       MESSAGE_BASE+16
#define CLIENT_AGENT_WRITE_FINISH_ACK          MESSAGE_BASE+17
#define CLIENT_AGENT_WRITE_FINISH_NACK         MESSAGE_BASE+18

/*�����������ļ�֪ͨ��Ϣ*/
#define CLIENT_AGENT_DOWN_FINISHALL_NOTIFY     MESSAGE_BASE+19
#define AGENT_CLIENT_DOWN_FINISHALL_ACK        MESSAGE_BASE+20
#define AGENT_CLIENT_DOWN_FINISHALL_NACK       MESSAGE_BASE+21

/*�������д�������ļ�֪ͨ��Ϣ*/
#define AGENT_CLIENT_WRITE_FINISHALL_NOTIFY    MESSAGE_BASE+22
#define CLIENT_AGENT_WRITE_FINISHALL_ACK       MESSAGE_BASE+23
#define CLIENT_AGENT_WRITE_FINISHALL_NACK      MESSAGE_BASE+24

/*�������дʧ��֪ͨ*/
#define AGENT_CLIENT_WRITE_FAILED_NOTIFY       MESSAGE_BASE+25

/*�ͻ������������ļ�����*/
#define CLIENT_AGENT_DOWN_CONFIG_START_REQ     MESSAGE_BASE+26
#define AGENT_CLIENT_DOWN_CONFIG_START_ACK     MESSAGE_BASE+27
#define AGENT_CLIENT_DOWN_CONFIG_START_NACK    MESSAGE_BASE+28

/*����˴��������ļ�������Ϣ*/
#define AGENT_CLIENT_DOWN_CONFIG_SND_DATA      MESSAGE_BASE+29
#define CLIENT_AGENT_DOWN_CONFIG_RCV_OK        MESSAGE_BASE+30
#define CLIENT_AGENT_DOWN_CONFIG_RCV_ERROR     MESSAGE_BASE+31

/*����˴��������ļ������Ϣ*/
#define AGENT_CLIENT_DOWN_CONFIG_FINISH_NOTIFY MESSAGE_BASE+32
#define CLIENT_AGENT_DOWN_CONFIG_FINISH_ACK    MESSAGE_BASE+33
#define CLIENT_AGENT_DOWN_CONFIG_FINISH_NACK   MESSAGE_BASE+34

/*�������������*/
#define CLIENT_AGENT_REBOOT_NOTIFY             MESSAGE_BASE+35

#endif /*_KDM2X18VERCTRL_H_*/
