/*****************************************************************************
  ģ����      : 
  �ļ���      : CFxoServer.h
  ����ļ�    : 
  �ļ�ʵ�ֹ���: 
  ����        : �ŷ�
  �汾        : V1.0  Copyright(C) 1997-2006 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2007/1/19  1.0         �ŷ�      ����
******************************************************************************/

#ifndef INCLUDE_CFXOSERVER_H_HEADER_INCLUDED_BA50DB82
#define INCLUDE_CFXOSERVER_H_HEADER_INCLUDED_BA50DB82

#include "kdvtype.h"
#include "osp.h"


#ifdef _LINUX_
#define THREAD_VAL void*
#define THREAD_RTN NULL
#else
#define THREAD_VAL void
#define THREAD_RTN 
#endif

const u32 dwMaxPhoneLen = 32;

enum EMFxoAnswerMode { 
    // �ܾ�����		
    emFxoReject, 
	// ��ʾ����
	emFxoManu 
};
	
enum EMFxoState { 
	// ���������
	emFxoAlerting, 
	// ͨ����·����
	emFxoConnected, 
	// ���Ҷ�
	emFxoDisconnected,
	//ȡ��ʧ��
	emFxoError
};
		
typedef void (*TFxoCallIncoming)(void* pParam,u32 dwContext);
typedef void (*TFxoCallBack)(EMFxoState emState,void* pParam,u32 dwContext);
		

class CFxoServer
{

public:
	CFxoServer();
	// ����FXO�������
	// TDTMFCallBack  pProperty ��Ҫע������Իص�����
	// dwProcessContext    ���Իص������Ļ���
	// TDTMFCallIncoming ��Ҫע�������ص�����
	// dwIncomingContext   ����ص�������
	BOOL FxoInit(TFxoCallBack pfCallBack, u32 dwProcessContext, TFxoCallIncoming pfCallIncoming, u32 dwIncomingContext);
	virtual ~CFxoServer();
public:
	// ��������һ��FXO����
	// const s8* const szPhoneNumber �绰�����ַ���
	void MakeCall(const s8* const szPhoneNumber);

	// �ܾ�����
	void RejectCall();
	
	// �ں����в��ţ��ֻ��ȣ�
	// const s8* const szPhoneNumber �绰�����ַ���
	void DailInCall(const s8* const szPhoneNumber);
	

	// ժ��Ͳ����һ��FXOͨ��
	void AcceptCall();
	// �Ҷ�һ��һ��FXOͨ��
	void Hungup();
	// ����FXOӦ��ģʽ
	void FxoSetAnswerMode(EMFxoAnswerMode emMode);
protected:
	enum EMFxoRunState { 
		// FXO���ڿ���״̬
		emFxoSFree, 
		// FXOæ
		emFxoSBusy, 
		// FXO���ڽ�������
		emFxoSMakeCall, 
		// FXO���ڽ���״̬
		emFxoSAcceptCall, 
		// FXO���ڽ���״̬
		emFxoSRejectCall, 
		// FXO���ڹҶ�״̬
		emFxoSHangup 
	};
	// ����߳�
	static THREAD_VAL Excute(void* pParam);
	// ״̬��ת����
	BOOL Do();
	// ��������Ƿ������
	// TRUE��������
	// FALSE����û�н���
	BOOL RingIsEnd(BOOL bCleanRing);
protected:
	// �ں����в��ţ��ֻ��ȣ�
	// const s8* const szPhoneNumber �绰�����ַ���
	BOOL DialInCall();

	// ����һ��FXO����
	BOOL Pickup2Call();
	//����һ��FXO����
	BOOL Accept();
	//�Ҷ�һ��FXO����
	BOOL Deny();
	//�ܾ�һ��FXO����
	BOOL Reject();
protected:	
	// FXO����״̬
	volatile EMFxoRunState m_emFxoRunState;	
	//FXO����ģʽ
	volatile EMFxoAnswerMode  m_emFxoAnswerMode;
	// �绰����
	s8 m_achPhoneNumber[dwMaxPhoneLen+1];
	//�ź���������ȷ��״ֵ̬��ȷ
	SEMHANDLE m_hMutex;
private:
	// FXO״̬�ص�����
	TFxoCallBack m_pfCallBack;	
	// FXO�к��е����ص�����
	TFxoCallIncoming m_pfCallIncoming;	
	// FXO�к������ص�����������
	u32 m_dwCallIncomingContext;	
	// FXO״̬�ص�����������
	u32 m_dwCallBackContext;
private:
	//ת��״ֵ̬
	const s8* str_run_state(EMFxoRunState state);	
};


//һ��������������΢��������API���ʵ�
void SetCallIncomingInterval(u32 dwSecond);
void SetFxoThreadSleepInterval(u32 dwMacroSecond);

BOOL  GetFxoServerVersion(s8* szVerbuf, u8& dwLen);

		
#endif /* INCLUDE_CFXOSERVER_H_HEADER_INCLUDED_BA50DB82 */
