/***************************************************************
ģ����      �� bfin_tunnel                     
�ļ���      �� bfin_tunnel.h
����ļ�    �� bfin_tunnel.c
�ļ�ʵ�ֹ��ܣ� ˫�˼�ͨ��ģ��
����        �� ��Ц��
�汾        �� 1.0   2005/10/26
------------------------------------------------------------------
�޸ļ�¼:
��  ��          �汾            �޸���          �޸�����

*****************************************************************/
#ifndef COMM_H
#define COMM_H

#include "selftype.h"

#define pCOMM_TUNNEL_DESC_START_ADDR (u8*)0xFEB1F000	//ͨ������������ʼ��ַ
#define pCOMM_TUNNEL_START_ADDR (TCommTunnel*)0xFEB1FF00	//ͨ�������ַ
#define pCOMM_TUNNEL_INITIALIZE (s32*)0xFEB1FFFC		//��ʼ����־��ַ

#define COMM_TUNNEL_NUMBER 10		//�ɴ�����ͨ����Ŀ
#define COMM_PER_TUNNEL_MAX_DESC 16 //ÿ��ͨ���������������

typedef enum{
	COMM_OK,
	COMM_INVALID_PARM,
	COMM_INSUFFICIENT_MEMORY,
	COMM_NOT_INITIALIZED,
	COMM_NOT_CREATE_TUNNEL,
	COMM_TUNNEL_TYPE_CREATE,
	COMM_NOT_IDLE_TUNNEL
} TCommError;

//Buffer״̬
typedef enum{
	CommBlankBuffer = 188,
	CommOperatingDone,
	CommFullBuffer,
	CommOperateFail
} TCommBufferStatus;

//ͨ��ģ���������ṹ
typedef struct CommDesc{
	struct CommDesc *ptNext;
	l32 *pdwDataAddr;
	TCommBufferStatus tStatus;
	u32 dwDataLength;
} TCommDesc;

typedef enum{
	CommVideoDownTunnel,
	CommAudioDownTunnel,
	CommAudioUpTunnel,
	CommPrintInfoTunnel,
	CommUnknowTunnel
} TCommTunnelType;

//ͨ��ģ�����ṹ
typedef struct{
	u32 dwTunnelNumber;
	TCommTunnelType tTunnelType;
	u32 dwBufferSize;
	u32 dwBufferBlock;
	TCommDesc *ptCommDescAddr;
	u32 dwIsUsed;
} TCommTunnel;

/*====================================================================
������      ��CommCreateTunnel
����        ������һ��ͨ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����dwBufferSizeͨ���Ļ�������С��dwBufferBlock ͨ������ȥ����
			  tType ͨ������**ptHandle�����ص�ͨ����Ϣ
����ֵ˵��  ��COMM������Ϣ
====================================================================*/
TCommError CommCreateTunnel(u32 dwBufferSize, u32 dwBufferBlock, \
							TCommTunnelType tType, TCommTunnel **ptHandle);

/*====================================================================
������      ��CommDisposeBuffer
����        ������һ��ͨ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����*ptHandle ���ٵ�ͨ����Ϣ
����ֵ˵��  ��COMM������Ϣ
====================================================================*/
TCommError CommDisposeTunnel(TCommTunnel *ptHandle);

/*====================================================================
������      ��CommGetDesc
����        ���õ�һ��������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����dwTunnelNumber ͨ���ţ�ptHandle���ص�������
����ֵ˵��  ��COMM������Ϣ
====================================================================*/
TCommError CommGetDesc(u32 dwTunnelNumber, TCommDesc **ptHandle);

/*====================================================================
������      ��CommFindTunnel
����        ������tType����ͨ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����tType���ҵ�ͨ�����ͣ�ptHandle���ص�������
����ֵ˵��  ��COMM������Ϣ
====================================================================*/
TCommError CommFindTunnel(TCommTunnelType tType, TCommTunnel **ptHandle);

/*====================================================================
������      ��CommInitialize
����        ����ʼ��ͨ��ģ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵��  ��
====================================================================*/
void CommInitialize(void);

#endif


