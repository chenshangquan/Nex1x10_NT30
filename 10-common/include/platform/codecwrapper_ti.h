/*****************************************************************************
  ģ����      : Codecwrapper.a
  �ļ���      : codecwrapper_ti.h
  ����ļ�    : codecwrapperdef_ti.h
  �ļ�ʵ�ֹ���: 
  ����        : ������
  �汾        : V1.0  Copyright(C) 1997-2006 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2006/12/13  1.0         ������      ����
******************************************************************************/
#ifndef _CODECWRAPPER_TI_H_
#define _CODECWRAPPER_TI_H_

#include "codecwrapperdef_ti.h"


class CVideoEncProcess;
class CAudioEncProcess;
class CVideoDecProcess;
class CAudioDecProcess;

class CAVDecoder;

class CKdvEncoder
{
public:
	CKdvEncoder();
	~CKdvEncoder();
public:
	u16    CreateEncoder(TEncoder *pVidEncoder, TEncoder *pAudEncoder);
	u16    SetEncoderActive(u32 dwCpuMask, BOOL32 bVideo);
	
	/*��Ƶ���������뵥��ƵԴ˫������*/
    u16    AddVidEncToSingleCapGroup(u16  wAddtoChnNum);
	
	/*���;�̬ͼƬ*/
	u16    SetSendStaticPic(BOOL32  bSendStaticPic);

	/*��ȡ������Ƶ����*/
	u32    GetInputAudioPower();

	u16    ScaleVideoCap(u8 byType, u8 byValue); /* ��Ƶ�ɼ����� */

	/* ����¼�񡢷����Ľӿ� */
	u16 BindRecorder(u8 byRecorderId);
	
		//����ն���
	//����˫�ɼ�������ģʽ
	u16    SetDblCapOneStreamParameter(u16 dwInOut, u16 dwZoom, u16 dwXPos, u16 dwYPos);
	u16	   SetEncMoveMonitor(TMoveDetectParam *ptMoveDetectParam, u32 dwAreaNum);
	u16   SetEncMotionCallBack(TMotionAlarmInfo tMotionAlarmInfo, u32 dwContext);	
	
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);/*��ȡ������״̬*/ 		
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis );/*��ȡ��������ͳ����Ϣ*/

    u16    StartVideoCap(u8 byCapType = VIDCAP_CAPVIDEO);/*��ʼ�ɼ�ͼ��*/
    u16    StopVideoCap(); /*ֹͣ�ɼ�ͼ��*/

    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam );/*������Ƶ�������*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );       /*�õ���Ƶ�������*/
    u16    StartVideoEnc();/*��ʼѹ��ͼ��*/
    u16    StopVideoEnc(); /*ֹͣѹ��ͼ��*/
	
    u16    StartAudioCap(BOOL32 bAinMic = FALSE);/*��ʼ�����ɼ�*/
    u16    StopAudioCap(); /*ֹͣ�����ɼ�*/

    u16    SetAudioEncParam(u8 byAudioEncParam, 
                            u8 byMediaType=MEDIA_TYPE_PCMU,
                            u16 wAudioDuration = 30); /*��������ѹ������*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*�õ�����ѹ������*/

	u16    StartAudioEnc();/*��ʼѹ������*/
    u16    StopAudioEnc(); /*ֹͣѹ������*/
    u16    SetAudioMute( BOOL32 bMute );     //�����Ƿ���
    u16    SetAudioVolume(u8 byVolume ); /*���òɼ�����*/	
    u16    GetAudioVolume(u8 &byVolume );/*��ȡ�ɼ�����*/	
	
	/*���������ش�����*/
	u16    SetNetFeedbackVideoParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	//������Ƶ�ط�nSendTimes���ط�������nSendSpan��ÿ���ط������(0,0)�رա�
	//�ù�����Ҫ�ѷ����ش���, ���û�򿪣����Զ��򿪡�
	u16    SetNetAudioResend(s32 nSendTimes, s32 nSendSpan);

    u16    SetNetSndVideoParam(const TNetSndParam *ptNetSndParam);/*����ͼ������紫�Ͳ���*/	
    u16    SetNetSndAudioParam(const TNetSndParam *ptNetSndParam);/*�������������紫�Ͳ���*/
    u16    StartSendVideo(int  dwSSRC = 0);/*��ʼ����ͼ��*/	
    u16    StopSendVideo(); /*ֹͣ����ͼ��*/
    u16    StartSendAudio(int  dwSSRC = 0);/*��ʼ��������*/	
    u16    StopSendAudio(); /*ֹͣ��������*/	
	u16	   SetAudioDumb(BOOL32 bDumb); /*�����Ƿ�����*/	 
	
    u16    StartAec(u8 byType = 1);/*��ʼ��������*/
    u16    StopAec(); /*ֹͣ��������*/

	u16	   StartAgcSmp(); /*��ʼsmp����*/
	u16	   StopAgcSmp(); /*ֹͣsmp����*/
	u16	   StartAgcSin(); /*��ʼsin����*/
	u16	   StopAgcSin(); /*ֹͣsin����*/
	
	u16    SetFastUpata(BOOL32 bIsNeedProtect = TRUE);     /*����FastUpdata��MediaCtrl��75֡�ڱ�һ��I֡����*/


	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetVidFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
	u16    SetVidFecPackLen(u16 wPackLen );
	//�Ƿ�֡��fec
	u16    SetVidFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetVidFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetVidFecXY(s32 nDataPackNum, s32 nCrcPackNum);
	
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetAudFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
	u16    SetAudFecPackLen(u16 wPackLen );
	//�Ƿ�֡��fec
	u16    SetAudFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetAudFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetAudFecXY(s32 nDataPackNum, s32 nCrcPackNum);

	//���÷�תg7221c
	u16     SetReverseG7221c( BOOL32 bReverse );

	//��Ƶ��̬�غɵ�PTֵ���趨
	u16 SetAudioActivePT(u8 byLocalActivePT);
	
	//��Ƶ��̬�غɵ�PTֵ���趨
	u16 SetVideoActivePT(u8 byLocalActivePT );
	
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16    SetAudEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
	
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16    SetVidEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode ); 
public://add by flying
		//��ʼ̨����������
	int StartAddLogoInEncStream(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, 
								u32 dwHeight, TBackBGDColor tBackBGDColor , u32 dwClarity, u32 dwChnNum, u32 dwCapPrt = 2);
	//ֹ̨ͣ����������
	int StopAddLogoInEncStream(u32 dwChnNum, u32 dwCapPrt = 2);

	//��ʼ�����������
	int StartAddBannerInEncStream(u8 *pbyBmp/*ͼ��ָ��*/, u32 dwBmpLen/*ͼ���С*/, u32 dwChnNum/*ͨ����*/,	TAddBannerParam tAddBannerParam/*��������ṹ*/);
    //ֹͣ�����������
	int StopAddBannerInEncStream(u32 dwChnNum);
	
/*   ���÷���ɫ�����Ի���ʾɫ������
     dwTestPicType -- ɫ������ͼƬ�ţ�0--�ֱ��ʲ��ԣ�1--ɫ�Ȳ��ԣ�2--�ҶȲ��ԣ�255--ȡ������*/
	u16 SetSendTestPic(u32 dwTestPicType);
public://add by flying
	int SetVideoChanel(u32 dwChannel);
	int GetVideoChannel();
protected:
private:
	CVideoEncProcess *m_pVideoCodec;
	CAudioEncProcess *m_pAudioCodec;
};

class CKdvDecoder
{
public:
	CKdvDecoder();
	~CKdvDecoder();
public:
	u16	   CreateDecoder(TDecoder *pVidEncoder, TDecoder *pAudEncoder);
	u16    SetDecoderActive(u32 dwCpuMask, BOOL32 bVideo);
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*��ȡ������״̬*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*��ȡ��������ͳ����Ϣ*/	

	u16    SetVideoDecType(u8 byType); /*����ͼ�����������, ֻ���ڿ�ʼ����ǰ���ò���Ч*/
    u16    StartVideoDec();/*��ʼͼ�����*/
    u16    StopVideoDec(); /*ֹͣͼ�����*/
	u16	   SetVideoPlayFormat(BOOL32 bFormat); /* ������ʾ��ʽ TRUE: 16:9, FALSE: 4:3 */
	
	u16    SetAudioDecType(u8 byType); /*������������������, ֻ���ڿ�ʼ����ǰ���ò���Ч*/
    u16    StartAudioDec();/*��ʼ��������*/	
    u16    StopAudioDec(); /*ֹͣ��������*/	
    u16    SetAudioVolume(u8 byVolume );  /*���������������*/	
    u16    GetAudioVolume(u8 &pbyVolume );/*�õ������������*/	
    u16    SetAudioMute(BOOL32 bMute);/*���þ���*/
	
    u16    StartRcvVideo();/*��ʼ�������ͼ��*/
    u16    StopRcvVideo(); /*ֹͣ�������ͼ��*/
    u16    StartRcvAudio();/*��ʼ�����������*/	
    u16    StopRcvAudio(); /*ֹͣ�����������*/	
    u16    SetVideoNetRcvParam(const TLocalNetParam *ptLocalNetParam );/*����ͼ���������ղ���*/	
    u16    SetAudioNetRcvParam(const TLocalNetParam *ptLocalNetParam );/*����������������ղ���*/
	
	/*����ͼ��������ش�����*/
	u16    SetNetFeedbackVideoParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE);

	/*������������·������һ·����Map����win32������ƣ�һ·��������, ����NULL,��رպ�һ·��������Ӧ�׽����ͷ�*/
    u16    SetVidDecDblSend(const TNetSndParam *ptNetSndVideoParam, u16 wBitRate = 4<<10);
    u16    SetAudDecDblSend(const TNetSndParam *ptNetSndAudioParam); 



	//���� H.263+/H.264 �ȶ�̬��Ƶ�غɵ� Playloadֵ
	u16    SetVideoActivePT( u8 byRmtActivePT, u8 byRealPT );

	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetVidDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

	//���� ��̬��Ƶ�غɵ� Playloadֵ
	u16    SetAudioActivePT( u8 byRmtActivePT, u8 byRealPT );

	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16    SetAudDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

	/*������Ƶ�����������*/
	u16    SetVidDropPolicy(u8 byDropPolicy);

	//���÷�תg7221c
	u16     SetReverseG7221c( BOOL32 bReverse );
	
    u16    ClearWindow();  /*����*/
    u16    FreezeVideo();  /*��Ƶ����*/
    u16    UnFreezeVideo();/*ȡ����Ƶ����*/

	u16    SetDisplayType(u8 byDisplayType);/*���û�����ʾ����(VIDEO VGA)*/
    u16    SetDisplayMode(u8 byDisplayMode);     /*���û��л���ʾ��ʽ*/
    u16    SetDisplaySaturation(u8 bySaturation);/*������ʾ���Ͷ�*/
    u16    SetDisplayContrast(u8 byContrast);    /*������ʾ�Աȶ�*/
    u16    SetDisplayBrightness(u8 byBrightness);/*������ʾ����*/	
    u16    SetLittlePicDisplayParam(u16 dwXPos,u16 dwYPos,u16 dwWidth,u16 dwHeight);/*����С������ʾλ����ߴ�*/
    u16    SetGetVideoScaleCallBack(TDecodeVideoScaleInfo tDecodeVideoScaleInfo);
    u16    GetAlarmInfo(TAlarmInfo &tAlarmInfo);
	u16    SetVideoDecParam(TVideoDecParam *ptVidDecParam);
	
	/*����˫��Ƶ������*/
	u16    SetDoubleVidStreamParam(u32  dwZoomLevel, u32  dwXPos, u32  dwYPos);
	
	/*��ȡ�����Ƶ����*/
	u32    GetOutputAudioPower();

	//����ն���
	u16	   SetDecMoveMonitor(TMoveDetectParam *ptMoveDetectParam,u32 dwAreaNum);
	u16   SetDecMotionCallBack(TMotionAlarmInfo tMotionAlarmInfo,u32 dwContext);
	
	//��������
	u16   PlayRing(s8* pData = NULL);
	// ���ò���SVGA [7/17/2007]
	u16   SetPlaySVGA(BOOL32 bPlay);
public: // add by flying
	//��ʼ����ͼ�����̨��
	int StartAddIconInLocal(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, 
							u32 dwHeight, TBackBGDColor tBackBGDColor , u32 dwClarity, u32 dwChnNum);
	//ֹͣ����ͼ�����̨��
	int StopAddIconInLocal(u32 dwChnNum);
	//��ʼ������뱾��
	int StartAddBannerInLocal(u8 *pbyBmp/*ͼ��ָ��*/, u32 dwBmpLen/*ͼ���С*/, u32 dwChnNum/*ͨ����*/,	TAddBannerParam tAddBannerParam/*��������ṹ*/);
    //ֹͣ������뱾��
	int StopAddBannerInLocal(u32 dwChnNum);

/*   ���÷���ɫ�����Ի���ʾɫ������
     dwTestPicType -- ɫ������ͼƬ�ţ�0--�ֱ��ʲ��ԣ�1--ɫ�Ȳ��ԣ�2--�ҶȲ��ԣ�255--ȡ������*/
	u16 SetPlayTestPic(u32 dwMapId, u32 dwTestPicType);
protected:
private:
	CVideoDecProcess *m_pVideoCodec;
	CAudioDecProcess *m_pAudioCodec;
};

u16 HardCodecInitSlave(TSlaveInit* pInit);
u16 HardCodecInitMaster(TMasterInit* pInit);
u16 HardCodecDestroyMaster();
void InitScreen();
BOOL32 SetVideoSrcIndex(s32 nIndex);

API void SetMicVol(s32 dwVol);
API s32 GetMicVol();

u16  SendMTMsgToSlave(u32 dwID, void* pBuf, u32 dwBufSize);
void SetMTMsgFromSlaveNotify(MsgFromSlave fNotify);

//MC
API void McSwitch(BOOL32 bEnterMC);         //�л�mc״̬
API void SetMCParam(u8 abyMergeParam[]);    //����mc״̬ʱ��ͼ��ϳɲ���
API int SetMcAudDecType(BOOL bMixer, u32 dwMcAudDecMask);	//����mc״̬ʱ��Ƶ����·��

/*����PAL��NTSC��ʽ�ı���Ϣ֪ͨ*/
API void SetNtscPalChangeCallBack(CHANGECALLBACK pChangeProc);
/*   ���÷���ɫ�����Ի���ʾɫ������
     dwChnNum -- ����ͨ���ţ�=255ʱ��ʾ���б���ͨ��������ɫ������ͼƬ
     dwTestPicType -- ɫ������ͼƬ�ţ�0--�ֱ��ʲ��ԣ�1--ɫ�Ȳ��ԣ�2--�ҶȲ��ԣ�255--ȡ������*/
API BOOL32  SetSendTestPic(u32 dwMapId, u32 dwChnNum, u32 dwTestPicType);
API BOOL32  SetPlayTestPic(u32 dwMapId, u32 dwTestPicType);

//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API	int SetMediaTOS(int nTOS, int nType);
API	int GetMediaTOS(int nType);

//���ö���ʧЧ��
API void SetResendDrop(u32 dwInterval, u32 dwRatio);
//����оƬ����֪ͨ�ص�
API void SetCpuResetNotify(CpuResetNotify fNotify);
#endif
