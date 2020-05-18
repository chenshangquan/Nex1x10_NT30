/*****************************************************************************
  ģ����      : 
  �ļ���      : kdvmixer_apu2.h
  ����ļ�    : 
  �ļ�ʵ�ֹ���: 
  ����        : ��ѩ��
  �汾        : V1.0  Copyright(C) 2008-2009 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/1   1.0         ��ѩ��      ����
2014/3/24   2.0         Ф����      �޸�
******************************************************************************/

#ifndef _KDVMIXER_APU2_H_
#define _KDVMIXER_APU2_H_

#include "codecwrapperdef_hd.h"
#include "kdvmedianet.h"

//��ʼ������
typedef struct tagKdvMixerInitParam
{
	u32 dwAudVersion;	//�汾��
	u32 dwAudDecMaxNum;	//�����������·��
	u32 dwAudMixDepth;	//�������
}TKdvMixerInitParam;

//ͨ����Ϣ
typedef struct tagKdvMixerChnlInfo
{
	u32 dwMixerId;	//������ID
	u32 dwChID;		//ͨ����
	BOOL32 bNMode;	//�Ƿ�Nģʽ�����ڻ�����
}TKdvMixerChnlInfo;

//�������
typedef struct tagKdvMixerTypeParam
{
	u32 dwAudType;	//��Ƶ��ʽ
	u32 dwAudMode;	//��Ƶ����ģʽ
}TKdvMixerTypeParam;

//������ͨ��״̬
typedef struct tagKdvMixChStatus
{
	BOOL32 bAddMixer;	//�Ƿ���������
	u32 dwMixChId;		//ʵ�����ڻ�����ͨ����
	TKdvMixerTypeParam tMixChnlType;
}TKdvMixerChStatus;

typedef TKdvMixerTypeParam TKdvAdaptTypeParam;
typedef struct tagKdvAdaptChStatus
{
	BOOL32 bAddChnl;	//ͨ���Ƿ����
	TKdvAdaptTypeParam tMixChnlType;
}TKdvAdaptChStatus;

//////////////////////////////////////////////////////////////////////////
#define MIXER_MAX_GROUP			4		//�����������
#define	MIXER_MAX_MIXDEPTH		8		//�������
#define	MIXER_MAX_DECCHNL		64		//������ͨ����
#define	MIXER_MAX_NMODE_ENCNUM	4		//���Nģʽ�������
//////////////////////////////////////////////////////////////////////////
//��Ƶ������
enum enAudioErrorCode
{
	Codec_Error_Audio_Create = (ERROR_CODE_BASE + 400),
	Codec_Error_Audio_Close,
	Codec_Error_Audio_Param,
	Codec_Error_Audio_Process,
	Codec_Error_Audio_GetMem,
	Codec_Error_Audio_GetData
};
//////////////////////////////////////////////////////////////////////////
//��������֡�ص�
typedef void (*MIXENCFRAMECALLBACK)(TKdvMixerChnlInfo* ptChnlInfo, PFRAMEHDR pFrmHdr, void* pContext);
//���������ص�
typedef void (*SPEECHACTIVECALLBACK)(TKdvMixerChnlInfo* ptChnlInfo, void* pContext);
//GMPU C6678�����ʱ�ص�
typedef void (*AudResOfflineNotify)(void* pContext);
//GMPU C6678���������ı�ص�
typedef void (*C6678NumChangeNotify)(u32 dwChipsNum, void* pContext);

typedef struct tagC6678Status
{
	u32 dwAllC6678Num;
	u32 dwFreeMixerNum;
    u32 dwFreeAdpterNum;
}TC6678Status;

/*
��������GetC6678Status
��	    �ܣ���ȡC6678���������û�������������������APU2��GMPUʹ��
��     ����
����ֵ��
˵     ����
*/
void GetC6678Status(TC6678Status &tC6678Status);

/*
��������SetC6678NumChangeCb
��	    �ܣ�����C6678������ʱ�Ļص�������GMPUʹ��
��     ����
����ֵ��
˵     ����
*/
void SetC6678NumChangeCb(C6678NumChangeNotify pCbFunction, void* pContext);

/*
��������Apu2Init
��	    �ܣ�APU2ģ���ʼ�����ڳ�������ʱ���ȵ��ã��ڴ����Ժλ���������ǰ���ã�APU2��GMPUʹ��
��     ����
����ֵ��
˵     ����
*/
u32 Apu2Init();

//////////////////////////////////////////////////////////////////////////
class CAudioMixProc;

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

	//��ͣ����
	u16 StartAudMix();
	u16 StopAudMix();

	//��ͣ��������
	u16 StartSpeechActive();
	u16 StopSpeechActive();

	//ͨ�����������
	//u32 dwChID��ͨ����Ϊ0 ~ MIXER_MAX_DECCHNL-1
	u16 AddChannel(u32 dwChID);

	//ͨ���˳�������
	//u32 dwChID��ͨ����Ϊ0 ~ MIXER_MAX_DECCHNL-1
	u16 DelChannel(u32 dwChID);

	//�����ڻ���������Ƶ�������
	//��addchannel�������ñ������
	//����ͨ���ţ�0 ~ MIXER_MAX_DECCHNL-1
	//nģʽͨ���ţ�0 ~ MIXER_MAX_NMODE_ENCNUM-1
	u16 SetAudEncParam(const TKdvMixerChnlInfo& tChnlInfo, const TKdvMixerTypeParam& tEncParam);

	//������Ƶ��������
	u16 SetAudDecData(u32 dwChID, const PFRAMEHDR pFrmHdr);

	//��Ƶ���������AAC_LC/LD��Ч
	u16 SetAudioDecParam(u32 dwChID, const TAudioDecParam& tAudParam);

	//������Ƶ����ص�
	//MIXENCFRAMECALLBACK fAudEncCB���ص�����ָ�룻void* pContext������
	u16 SetAudEncDataCallBack(MIXENCFRAMECALLBACK fAudEncCB, void* pContext);

	//�������������ص�
	//SPEECHACTIVECALLBACK fSpeechActiveCB���ص�����ָ�룻void* pContext������
	u16 SetSpeechActiveCallBack(SPEECHACTIVECALLBACK fSpeechActiveCB, void* pContext);

	//ǿ�ƻ���ͨ��(ǿ�ƻ���ͨ��ͬʱֻ��һ��)
	//u32 dwChID,��dwChIDδ���뵱ǰ��������ʱ����Ϊȡ��ǿ��ͨ��
	//��AddChannel��������ǿ�ƻ���ͨ��
	u16 SetForceChannel(u32 dwChID);

	//�������������ı���ʱ��
	//u32 dwKeepTime������ʱ�䣬��λms
	u16 SetSpeechActiveKeepTime(u32 dwKeepTime);

	//���û�������ͨ������
	u16 SetMixerDecChnlVol(u32 dwChID, u8 byVolume);

	// ȡ�û�������ͨ������
	u16 GetMixerDecChnlVol(u32 dwChID, u8& byVolume);

	//���û���������ʱ(ms)�����Դ���ͬ��
	u16 SetMixerDelay(u32 dwDelayTime=0);
	
	//���ÿ��ջ�����
	u16 SetMixerRcvBufs(u32 dwFastRcvBufs);

	//ȡ�û���������ͨ����ǰ״̬
	u16 GetMixerDecChnlStatus(const TKdvMixerChnlInfo& tDecChnlInfo, TKdvMixerChStatus& tDecChnlStatus);
	//ȡ�û���������ͨ����ǰ״̬
	u16 GetMixerEncChnlStatus(const TKdvMixerChnlInfo& tEncChnlInfo, TKdvMixerChStatus& tEncChnlStatus);

	//ȡ�û���������ͨ���ŵ�ǰͳ��
	u16 GetMixerDecChStatis(const TKdvMixerChnlInfo& tDecChnlInfo, TKdvDecStatis& tDecChnlStatis);
	//ȡ�û���������ͨ���ŵ�ǰͳ��
	u16 GetMixerEncChStatis(const TKdvMixerChnlInfo& tEncChnlInfo, TKdvEncStatis& tEncChnlStatis);

	//ȡ��ʵ�ʲ���������н���ͨ����
	//pdwChId������ռ��ϲ㿪�٣����������
	//dwChNum��ڱ�ʾ�����С�����ر�ʾ�����������ͨ����
	u16 GetMixerChID(u32* pdwChId, u32& dwChNum);

	//���û��������󲻿���ʱ�Ļص�������GMPUʹ��
	s32 SetResOfflineCallBack(AudResOfflineNotify fResOfflineCB, void* pContext);
	
private:
	CAudioMixProc*  m_pcMixProc;
};
//////////////////////////////////////////////////////////////////////////
#define AUDIO_ADAPTOR_MAX_CHNL		14		//��Ƶ�������ͨ����
#define	AUDIO_ADAPTOR_MAX_ENCNUM	4		//�������������
//////////////////////////////////////////////////////////////////////////
typedef TKdvMixerTypeParam TKdvAudioAdaptorTypeParam;

//��������֡�ص�
typedef void (*AUDADAPTENCFRAMECALLBACK)(u32* pdwChID, PFRAMEHDR pFrmHdr, void* pContext);
//////////////////////////////////////////////////////////////////////////
class CAudioAdaptProc;

class CKdvAudAdaptor
{
public:
	CKdvAudAdaptor();
	~CKdvAudAdaptor();

	//����
	u16 Create(u32 dwAudVersion=en_APU2_Board);
	//����
	u16 Destroy();
	
	u16 StartAdaptor(BOOL32 bStart=TRUE);
	
	//ͨ������������
	//u32 dwChID��ͨ����Ϊ0 ~ AUDIO_ADAPTOR_MAX_CHNL-1
	u16 AddChannel(u32 dwChID);
	
	//ͨ���˳�������
	//u32 dwChID��ͨ����Ϊ0 ~ AUDIO_ADAPTOR_MAX_CHNL-1
	u16 DelChannel(u32 dwChID);
	
	//��������Ƶ����������Ƶ�������
	//��addchannel�������ñ������
	//����ͨ���ţ�0 ~ AUDIO_ADAPTOR_MAX_CHNL-1
	//���������0~AUDIO_ADAPTOR_MAX_ENCNUM-1
	//dwChID��ʾ�ڼ�·������0 ~ AUDIO_ADAPTOR_MAX_CHNL-1��dwEncIndex��ʾ�����ı���·��0~AUDIO_ADAPTOR_MAX_ENCNUM-1
	u16 SetAudEncParam(const u32 dwChID, const u32 dwEncIndex, const TKdvAudioAdaptorTypeParam* ptEncParam);
	
	//������Ƶ��������
	u16 SetAudDecData(u32 dwChID, const PFRAMEHDR pFrmHdr);
	
	//��Ƶ���������AAC_LC/LD��Ч
	u16 SetAudioDecParam(u32 dwChID, const TAudioDecParam& tAudParam);
	
	//������Ƶ����ص�
	//AUDADAPTENCFRAMECALLBACK fAudEncCB���ص�����ָ�룻void* pContext������
	u16 SetAudEncDataCallBack(AUDADAPTENCFRAMECALLBACK fAudAdaptEncCB, void* pContext);

	//���ÿ��ջ�����
	u16 SetMixerRcvBufs(u32 dwFastRcvBufs);

	//ȡ������������ͨ����ǰ״̬
	u16 GetAdaptDecChnlStatus(const u32 dwChID, TKdvAdaptChStatus& tDecChnlStatus);
	//ȡ������������ͨ����ǰ״̬
	//dwChID��ʾ�ڼ�·������0 ~ AUDIO_ADAPTOR_MAX_CHNL-1��dwEncIndex��ʾ�����ı���·��0~AUDIO_ADAPTOR_MAX_ENCNUM-1
	u16 GetAdaptEncChnlStatus(const u32 dwChID, const u32 dwEncIndex, TKdvAdaptChStatus& tEncChnlStatus);
	
	//ȡ������������ͨ���ŵ�ǰͳ��
	u16 GetAdaptDecChStatis(const u32 dwChID, TKdvDecStatis& tDecChnlStatis);
	//ȡ������������ͨ���ŵ�ǰͳ��
	//dwChID��ʾ�ڼ�·������0 ~ AUDIO_ADAPTOR_MAX_CHNL-1��dwEncIndex��ʾ�����ı���·��0~AUDIO_ADAPTOR_MAX_ENCNUM-1
	u16 GetAdaptEncChStatis(const u32 dwChID, const u32 dwEncIndex, TKdvEncStatis& tEncChnlStatis);

	//���û��������󲻿���ʱ�Ļص�������GMPUʹ��
	s32 SetResOfflineCallBack(AudResOfflineNotify fResOfflineCB, void* pContext);
	
private:
	CAudioAdaptProc* m_pcAdaptorProc;
};
//////////////////////////////////////////////////////////////////////////
#endif
