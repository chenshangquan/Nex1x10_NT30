/*****************************************************************************
  ģ����      : Codecwrapper_eapu.a
  �ļ���      : kdvmixer_eapu.h
  ����ļ�    : codecwrapperdef_t3.h
  �ļ�ʵ�ֹ���: 
  ����        : ����
  �汾        : V4.0  Copyright(C) 2007-2008 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2009/11/01  1.0         ����     ����
******************************************************************************/
#ifndef _KDVMIXER_EAPU_H_
#define _KDVMIXER_EAPU_H_

#include "codecwrapperdef_hd.h"

//powerstatis ��������ֻ�����������ͳ�ƣ�
//����Create(const TKdvMixerInitParam& tInitParam)ʱ��
//dwAudEncDspID��ֵ������ΪDSPWORKMODE_POWERSTATIS
#define DSPWORKMODE_POWERSTATIS 0x00000050

//������ʽ
typedef struct tagKdvMixerInitParam
{
	u32 dwMaxChNum;      //�������ͨ����
	u32 dwAudDecDspID;   //��������dsp
	u32 dwAudEncDspID;	 //powerstatis ��������dsp�����ֻ������ͳ����ֵ������ΪDSPWORKMODE_POWERSTATIS
	u32 dwDModeChMum; //DMode���·��
	u32 dwReserve;
}TKdvMixerInitParam;

//������ʽ
typedef struct tagKdvMixerType
{
	u32 dwChID;      //����ͨ��
	BOOL32 bDMode;  //����DMode�����־
	u8 byAudType;	//��Ƶ��ʽ
	u8 byAudMode;   //��Ƶ����ģʽ
	u16 wReserve;
}TKdvMixerType;

//������ͨ��״̬
typedef struct tagKdvMixChStatus
{
	BOOL32 bAddMixer; //�Ƿ���������
	u32 dwChID;      //����ͨ��
	u32 dwMixChId; //ʵ�����ڻ�����ͨ����
	u8 byAudEncType;	//��Ƶ�����ʽ
	u8 byAudEncMode;   //��Ƶ��������ģʽ
	u8 byAudDecType;	//��Ƶ�����ʽ
	u8 byAudDecMode;   //��Ƶ��������ģʽ
}TKdvMixerChStatus;

//������ͳ����Ϣ�����м�ֵ
typedef struct tagSingleEncStatis
{
	u32   dwRealEncCount;   //ʵ�ʱ���֡��
	u32	  dwFrameCount;		// 1���ӱ���֡��
	u32   dwLoseRatio;	    //��֡��,��λ��% 	
	u32   dwAvrBitCount;	// 1��������ƽ������
	s32	  dwNextTimer;
	struct timeval tLastval;
}TSingleEncStatis;

//������ͳ����Ϣ�����м�ֵ
typedef struct tagSingleDecStatis
{
	u32	  dwFrameCount;		//����֡��
	u32   dwAvrBitCount;		// 1��������ƽ������
	u32   dwBitCount;		   // 2s����ƽ������
	u32   dwLastFrameID;
	u32   dwLastSSRC;
	u32   dwSSRCChangeProted;
	s32	  dwNextTimer;
	struct timeval tLastval;
}TSingleDecStatis;


//������ͨ��ͳ��
typedef struct tagKdvMixerChStatis
{
	u32 dwChID;      //ͨ��ID
	TKdvEncStatis tAudEncStatis;   //��Ƶ����ͳ��
	TSingleEncStatis tAudEncSingleData;  //����ͳ���м���Ϣ
	TKdvDecStatis tAudDecStatis;   //��Ƶ����ͳ��
	TSingleDecStatis tAudDecSingleData;  //����ͳ���м���Ϣ
}TKdvMixerChStatis;


//��������֡�ص�
typedef void ( *MIXENCFRAMECALLBACK)(TKdvMixerType* ptType, PTFrameHeader pFrameInfo, void* pContext);
//���������ص�
typedef void ( *VOLACTIVECALLBACK)(TKdvMixerType* ptType, void* pContext);
//powerstatis ����ͳ�ƻص�
typedef void (* POWERSTATISCALLBACK)(u32 dwChannel, u32 dwPower, void* pContext);

class CAudioMixer;

class CKdvMixer
{
public:
	CKdvMixer();
	~CKdvMixer();
public:
	//����������
	u16 Create(const TKdvMixerInitParam& tInitParam);
	//���ٻ�����
	u16 Destroy();
	//���´���������
	//����������ʹ��dsp�ı�ʱ�������´���
	u16 ReCreate(const TKdvMixerInitParam& tInitParam);
	//��ͣ����
	u16 StartAudMix();
	u16 StopAudMix();
	//��ͣ��������
	u16 StartVolActive();
	u16 StopVolActive();
	//ͨ�����������
	//u32 dwChID��ͨ����Ϊ0 ~ dwMaxChNum-1
	u16 AddChannel(u32 dwChID);
	//ͨ���˳�������
	//u32 dwChID��ͨ����Ϊ0 ~ dwMaxChNum-1
	u16 DelChannel(u32 dwChID);
	//�����ڻ���������Ƶ�������
	//DModeͨ������Ҫ��addchannel������ͨ��Ӧ��addchannel�������ñ������
	u16 SetAudEncParam(const TKdvMixerType& tType);
	//DModeͨ�����ñ������
	u16 SetDModeChannel(const TKdvMixerType& tType);
	//DModeͨ��ɾ��
	u16 DelDModeChannel(u32 dwDModeChID);
	//������Ƶ��������
	u16 SetAudDecData(u32 dwChID, const TFrameHeader& tFrameInfo);
	//������Ƶ����ص�
	//FRAMECALLBACK fAudData���ص�����ָ�룻void* pContext������
	u16 SetAudEncDataCallback(MIXENCFRAMECALLBACK fAudData, void* pContext);
	//�������������ص�
	//VOLACTIVECALLBACK fVolAct���ص�����ָ�룻void* pContext������
	u16 SetVolActiveCallback(VOLACTIVECALLBACK fVolAct, void* pContext);
	//ǿ�ƻ���ͨ��(ǿ�ƻ���ͨ��ͬʱֻ��һ��)
	//u32 dwChID,��dwChIDδ���뵱ǰ��������ʱ����Ϊȡ��ǿ��ͨ��
	u16 SetForceChannel(u32 dwChID);
	//���û������
	//u8 byDepth,�������Ŀǰ���Ϊ8������8ʱ�ײ�ǿ��Ϊ8
	u16 SetMixDepth(u8 byDepth);
	//�������������ı���ʱ��
	//u32 dwKeepTime������ʱ�䣬��λms
	u16 SetVolActKeepTime(u32 dwKeepTime);
	//���û���ͨ������
	u16 SetMixerChVol(BOOL32 bDMode, u32 dwChID, u8 byVolume);
	// ȡ�û���ͨ������
	u16 GetMixerChVol(BOOL32 bDMode, u32 dwChID, u8& byVolume);
	//ȡ�û�����ͨ����ǰ״̬
	u16 GetMixerChStatus(BOOL32 bDMode, u32 dwChID, TKdvMixerChStatus& tStatus);
	//ȡ�û��������ŵ�ǰͳ��
	u16 GetMixerChStatis(BOOL32 bDMode, u32 dwChID, TKdvMixerChStatis& tStatis);
	//���û�����ʱ(ms)
	u16 SetMixerDelay(u32 dwTime);
	//���ÿ�ʼ, ���ջ�����
	u16 SetMixerRcvBufs(u32 dwStartRcvBufs, u32 dwFastRcvBufs);
	//ȡ��ʵ�ʲ����������ͨ����
	//pdwChId������ռ��ϲ㿪�٣�
	//dwChNum��ڱ�ʾ�����С�����ر�ʾ�����������ͨ����
	u16 GetActiveChID(u32** pdwChId, u32& dwChNum);

	//powerstatis ��ø�ͨ��������ͳ��ֵ
	u16 GetPowerStatis(u32* pBuf, u32 dwBufSize);
	u16 SetPowerStatisCallBack(POWERSTATISCALLBACK fPower, void* pContext);
	
protected:
private:
	CAudioMixer*  m_pcMixer;
};


//�趨��ǰ*.bin,*.out·����Ĭ��/usr/bin
void SetCodecAppDir(s8* szPath);
//ע��ý����Ʋ�OSP��������
void RegsterCommands();

#endif
