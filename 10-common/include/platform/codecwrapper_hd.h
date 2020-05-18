/*****************************************************************************
  ģ����      : Codecwrapper.a
  �ļ���      : codecwrapper_hd.h
  ����ļ�    : codecwrapperdef_hd.h
  �ļ�ʵ�ֹ���: 
  ����        : ������
  �汾        : V4.0  Copyright(C) 2007-2008 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2007/11/28  4.0         ������      ����
******************************************************************************/
#ifndef _CODECWRAPPER_HD_H_
#define _CODECWRAPPER_HD_H_

#if defined(_MEDIACTRL_DM816x_)||defined(_MEDIACTRL_GMPU_)

#include "dm816x/codecwrapper_hd.h"

#else

#include "codecwrapperdef_hd.h"


class CVideoEncoder;
class CAudioEncoder;
class CVideoDecoder;
class CAudioDecoder;
class CLogoAdd;


class CKdvVidEnc
{
public:
	CKdvVidEnc();
	~CKdvVidEnc();
public:
	//���¼��ݣ�t300 ��ʹ��
	u16    CreateEncoder(TEncoder *pEncoder);                 /*HD1��ʹ��*/
    u16    Create(TVidEncInit* pEnc, void* pReserve = NULL);  /*���������ն���ʹ������ӿ�*/
	u16    CreateHD3(TVidEncHD3RD* pEnc);							/*��������ʹ������ӿ�*/

	/************************************************************************/
	/* ������:  Create                                                      */  
	/* ��������:                                                            */
	/*          TNetraCodecInfo*   pEnc    ������������ʵ��λ���Լ����     */
	/* ��������: �������Ĵ��� �����ɹ�����0 								*/
	/************************************************************************/	
    u16    Create(TVidEncHDX500* pEnc); 

	/*��ȡ������״̬*/
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);

	/*��ȡ��������ͳ����Ϣ*/
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis);

	/************************************************************************/
	/* ������:   SetVidDataCallback                                          */  
	/* ��������:                                                             */
	/*           FRAMECALLBACK fVidData     �ص�������ַ                     */
	/*           void* pContext             �ص������Ĳ���					*/
	/*																		*/
	/* ��������:	������Ƶ�������ݻص�									*/
	/************************************************************************/
	u16    SetVidDataCallback(FRAMECALLBACK fVidData, void* pContext); 

    /************************************************************************/
    /* ������:     SetEncQualityEnhance                                      */  
    /* ��������:                                                             */
    /*              BOOL32 bEnhance                                         */
    /* ��������:  ׷�ӱ��������Ƚӿڣ�										*/
	/*				TRUEΪ��������ȣ�FALSEΪ�ر������ȡ�����������ʧ	    */
    /************************************************************************/
	u16    SetEncQualityEnhance(BOOL32 bEnhance);
	
	/************************************************************************/
	/* ������:   SetVidCapPortType                                           */  
	/* ��������:                                                             */
	/*           u32 dwType                                                  */
	/* ��������:	���òɼ��ӿ�											*/
	/************************************************************************/
	u16    SetVidCapPortType(u32 dwType);

	/************************************************************************/
	/* ������:  SetVideoEncParam                                             */  
	/* ��������:                                                             */
	/*             TVideoEncParam *ptVideoEncParam                          */
	/* ��������: ���ñ�����������������е���								*/
	/************************************************************************/
    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam); 

	/*�õ���Ƶ�������*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );
	
	/*��ʼѹ��ͼ��*/
    u16    StartEnc();
	
	/*ֹͣѹ��ͼ��*/
    u16    StopEnc(); 
	
	/************************************************************************/
	/* ������:         GetVideoSrcInfo                                       */  
	/* ��������:                                                             */
	/*                 TVidSrcInfo& tInfo                                    */
	/* ��������:	��ȡ������Ƶ�ź���ʽ									*/
	/************************************************************************/
    u16    GetVideoSrcInfo(TVidSrcInfo& tInfo); /**/
	
	/************************************************************************/
	/* ������:      ScaleVideoCap											*/  
	/* ��������:															*/
	/*              u32 dwVidSrcPort :��Ƶ�ɼ�����							 */
	/*              u8 byType        :�������� VIDCAP_SCALE_BRIGHTNESS ��	*/
	/*				u8 byValue       :������ֵ 0~255; 0x80ΪĬ��ֵ			*/
	/* ��������:	������Ƶ�ɼ�����										*/
	/************************************************************************/
    u16    ScaleVideoCap(u32 dwVidSrcPort,u8 byType, u8 byValue); 
	
	/************************************************************************/
	/* ������:      SetFastUpata                                             */  
	/* ��������:                                                             */
	/*              BOOL32 bIsNeedProtect �Ƿ���1s�ڱ���                   */
	/* ��������:	ǿ�Ʊ�һ֡�ؼ�֡�����ü������1s						*/
	/************************************************************************/
	u16    SetFastUpata(BOOL32 bIsNeedProtect = TRUE);   
	
	/************************************************************************/
	/* ������:      SetSendStaticPic                                         */  
	/* ��������:                                                             */
	/*              BOOL32  bSendStaticPic                                   */
	/* ��������:	���;�̬ͼƬ											 */
	/************************************************************************/
	u16    SetSendStaticPic(BOOL32  bSendStaticPic);
	
	/************************************************************************/
	/* ������:         StartAddLogoInEncStream                              */  
	/* ��������:                                                            */
	/*                 TFullLogoParam &tLogoParm                            */
	/* ��������:	����̨�����������̨��									*/
	/************************************************************************/
    u16	   StartAddLogoInEncStream(TFullLogoParam &tLogoParm);
	
	/************************************************************************/
	/* ������:         StopAddLogoInEncStream                               */  
	/* ��������:                                                            */
	/* ��������:	�ر�̨��												*/
	/************************************************************************/
	u16    StopAddLogoInEncStream();

    u16 StartAddBannerInEncStream(TFullBannerParam &tBannerParam, BOOL32 bSpaceArea=TRUE/*ͼƬǰ���Ƿ���пհ���*/);

    //ֹͣ�����������
	u16 StopAddBannerInEncStream();
	
	/************************************************************************/
	/* ������:   SetVidEncResizeMode                                         */  
	/* ��������:                                                             */
	/*           s32 nMode    0-�ڱߣ� 1-�ñߣ� 2-�ǵȱ�����                 */
	/* ��������: ���ñ���ǰ������ԣ��Ӻڱߣ��ñߵȣ�						*/
	/************************************************************************/
    u16    SetVidEncResizeMode(s32 nMode);
	
	/************************************************************************/
	/* ������:   SetVidPlayPolicy                                            */  
	/* ��������:                                                             */
	/*           u32 dwTimeout     ��ʱ                                      */
	/*           u32 dwPlayType    ��ͼ���������         					*/
	/* ��������: ���ñ��ز��Ų��ԣ�֧�������;�̬ͼ							*/
	/************************************************************************/
    u16    SetVidPlayPolicy(u32 dwTimeout = 5, u32 dwPlayType = EN_PLAY_LAST);
	
	/************************************************************************/
	/* ������:      SetVidSrcCutLines                                       */  
	/* ��������:                                                             */
	/*             u32 dwLCutLine ���ñ���������16 ������                 */
	/*             u32 dwRCutline �Ҳ�ñ���������16 ������					*/
	/* ��������: �ɼ�ͼ�����Ҳñߣ���Ҫ���ڲɼ�ͼ�����ұ�Ե���������		*/
	/************************************************************************/
	u16    SetVidSrcCutLines(u32 dwLCutLine, u32 dwRCutline);
protected:
private:
	CVideoEncoder *m_pCodec;
};

class CKdvAudEnc
{
public:
	CKdvAudEnc();
	~CKdvAudEnc();
public:
	u16    CreateEncoder(TEncoder *pEncoder, u32 dwDevVersion=en_X500_Board);

	u16    SetAudDataCallback(FRAMECALLBACK fAudData, void* pContext);/*������Ƶ���ݻص�*/
	/*��ȡ������Ƶ����*/
	u32    GetInputAudioPower();
	
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);/*��ȡ������״̬*/ 		
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis );/*��ȡ��������ͳ����Ϣ*/    
	
    u16    StartAudioCap();/*��ʼ�����ɼ�*/
    u16    StopAudioCap(); /*ֹͣ�����ɼ�*/

    u16    SetAudioEncParam(u8 byMediaMode, 
                            u8 byMediaType=MEDIA_TYPE_PCMU,
                            u16 wAudioDuration = 30); /*��������ѹ������*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*�õ�����ѹ������*/

	u16    StartAudioEnc();/*��ʼѹ������*/
    u16    StopAudioEnc(); /*ֹͣѹ������*/

    u16    SetAudioMute( BOOL32 bMute );     //�����Ƿ�ྲ������

    u16    SetAudioVolume(u8 byVolume ); /*���òɼ�����*/	
    u16    GetAudioVolume(u8 &byVolume );/*��ȡ�ɼ�����*/
    
    u16    SetAudInPort(u32 dwAudPort, u32 dwAudMasterMic);  /*������Ƶ�ɼ��˿ڣ��������󣬼�������Ƶ��;�ڶ�������ֻ������������AEC���������ӿڲ���AEC����)*/	
	
    u16    StartAec();/*��ʼ��������*/
    u16    StopAec(); /*ֹͣ��������*/

	u16	   StartAgcSmp(); /*��ʼsmp����*/
	u16	   StopAgcSmp(); /*ֹͣsmp����*/
	u16	   StartAgcSin(); /*��ʼsin����*/
	u16	   StopAgcSin(); /*ֹͣsin����*/		
protected:
private:
	CAudioEncoder *m_pCodec;
};

class CKdvVidDec
{
public:
	CKdvVidDec();
	~CKdvVidDec();
public:
	//��֮ǰ���ݣ�t300 ppc�಻ʹ��
	u16	   CreateDecoder(TDecoder *pDecoer);   /*HDU, HD1��ʹ��*/
    u16    Create(TVidDecInit* pDec, void* pReserve = NULL); /*���������ն���ʹ������ӿ�*/
	u16    CreateHD3(TVidDecHD3RD* pDec);


	/************************************************************************/
	/* ������:    Create                                                    */  
	/* ��������:                                                            */
	/*            TNetraCodecInfo* pDec    ��������������                   */
	/* ��������:  ����������												*/
	/************************************************************************/
    u16    Create(TVidDecHDX500* pDec);

	/************************************************************************/
	/* ������:      SetData                                                 */  
	/* ��������:                                                             */
	/*              TFrameHeader& tFrameInfo                                */
	/* ��������:	������Ƶ��������										*/
	/************************************************************************/
	u16    SetData(const TFrameHeader& tFrameInfo);  
	
	/*��ʼͼ�����*/
    u16    StartDec();

	/*ֹͣͼ�����*/
    u16    StopDec(); 

	/*��ȡ������״̬*/
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);

	/*��ȡ��������ͳ����Ϣ*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);	


	/************************************************************************/
	/* ������:      SetVidPIPParam                                           */  
	/* ��������:                                                             */
	/*             enVideoPIPMode enMode ���л����                          */
	/*             enVideoPIPIndexEX enIndex[3] �ӻ�������           		*/
	/* ��������:	������Ƶ���л�ģʽ�����֧��3����ϳ�					*/
	/************************************************************************/
    u16 SetVidPIPParam(enVideoPIPMode enMode, enVideoPIPIndex enIndex[3]);
    

	/************************************************************************/
	/* ������:      SetPlayScale                                             */  
	/* ��������:                                                             */
	/*               u16 wWidth  :��ʾ�������0Ϊ�Զ�                       */
	/*               u16 wHeight :��ʾ�߱�����0Ϊ�Զ�						*/
	/* ��������:	���ò����豸����ʾ����									*/
	/*               ������ʽΪ16:9,����4:3��ͼ�����¼Ӻڱ�                 */
	/*               ������ʽΪ4:3,����16:9��ͼ�����ҼӺڱ�                 */
	/************************************************************************/
    u16    SetPlayScale(u16 wWidth, u16 wHeight);
    
	/************************************************************************/
	/* ������:      SetVidPlyPortType                                        */  
	/* ��������:                                                             */
	/*               u32 dwType   ���ſ�                                    */
	/* ��������:	���������벥�ſ�										*/
	/************************************************************************/
    u16    SetVidPlyPortType(u32* dwPortList, u32 dwNum);

	/************************************************************************/
	/* ������:      SetVideoPlyInfo                                          */  
	/* ��������:                                                             */
	/*               u32 dwOutType     ��Ƶ��ʽö��                          */
	/* ��������:	������Ƶ����ź���ʽ									 */
	/************************************************************************/
    u16    SetVideoPlyInfo(u32 dwOutType = VID_OUTTYPE_ORIGIN);

	/************************************************************************/
	/* ������:      SetVideoPlyInfo                                          */  
	/* ��������:                                                             */
	/*               TVidSrcInfo* ptInfo     ��Ƶ��ʽ                        */
	/* ��������:	������Ƶ����ź���ʽ									 */
	/************************************************************************/
    u16    SetVideoPlyInfo(TVidSrcInfo* ptInfo); 

	/*��ȡ�����Ƶ�ź���ʽ*/
    u16    GetVideoSrcInfo(TVidSrcInfo& tInfo);   

	/************************************************************************/
	/* ������:     SetVidDecResizeMode                                       */  
	/* ��������:                                                             */
	/*             s32 nMode     ������ԣ�0���Ӻڱߣ�1���ñ�; 2:�ǵȱ�      */
	/* ��������:   ���ý���������										*/
	/************************************************************************/
	u16	   SetVidDecResizeMode(s32 nMode);

	/************************************************************************/
	/* ������:     SetVidOutCallBack                                        */  
	/* ��������:                                                             */
	/*             VIDOUTTYPECALLBACK fVidOutType  �ص�������ַ             */
	/* ��������:	������Ƶ��ʽ�����ɹ���ص�����							*/
	/************************************************************************/
	u16	   SetVidOutCallBack(VIDOUTTYPECALLBACK fVidOutType);

	/************************************************************************/
	/* ������:      TestImage                                               */  
	/* ��������:                                                            */
	/*              BOOL32 bSet                                             */
	/* ��������:	����/�رյô�����										*/
	/************************************************************************/
	u16	   TestImage(BOOL32 bSet);

	/************************************************************************/
	/* ������:     SnapShot                                                  */  
	/* ��������:                                                             */
	/*             s8* pFileName    �ļ���ȫ·��                            */
	/* ��������:   ����һ֡����ͼ��Ϊjpeg�ļ�								*/
	/************************************************************************/
	u16    SnapShot(s8* pFileName);

	/************************************************************************/
	/* ������:     SnapShotView                                              */  
	/* ��������:                                                             */
	/*             s8* pFileName    �ļ���ȫ·��                             */
	/* ��������:	����ָ����jpegͼƬ�������ǿ���ͼ��ֹͣ					*/
	/************************************************************************/
	u16    SnapShotView(s8* pFileName);

	/************************************************************************/
	/* ������:     SetVidPlayPolicy                                          */  
	/* ��������:                                                             */
	/*           u32 dwTimeout     ��ʱ                                      */
	/*           u32 dwPlayType    ��ͼ���������         					*/
	/* ��������:	���ý��벥����ͼ����ʾ����								*/
	/************************************************************************/
	u16    SetVidPlayPolicy(u32 dwTimeout = 5, u32 dwPlayType = EN_PLAY_LAST);
protected:
private:
	CVideoDecoder *m_pCodec;
};

class CKdvAudDec
{
public:
	CKdvAudDec();
	~CKdvAudDec();
public:
	u16	   CreateDecoder(TDecoder *pDecoer, u32 dwDevVersion=en_X500_Board);
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);/*��ȡ������״̬*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);/*��ȡ��������ͳ����Ϣ*/	

    u16    SetData(const TFrameHeader& tFrameInfo); /*������Ƶ��������*/
    u16    SetAudioDecParam(const TAudioDecParam& tAudParam);/*��Ƶ���������AAC��Ч*/ 
    
    u16    SetAudOutPort(u32 dwAudPort);  /*������Ƶ���Ŷ˿�*/

    u16    StartDec();/*��ʼ��������*/	
    u16    StopDec(); /*ֹͣ��������*/	
    u16    SetAudioVolume(u8 byVolume );  /*���������������*/	
    u16    GetAudioVolume(u8 &pbyVolume );/*�õ������������*/	
    u16    SetAudioMute(BOOL32 bMute);/*���þ���*/
		
	/*��ȡ�����Ƶ����*/
	u32    GetOutputAudioPower();
	
	//�������� ������
	u16   PlayRing(s8* pData = NULL);
	u16   StopRing();
protected:
private:
	CAudioDecoder *m_pCodec;
};

///Osd�������

//����osd����,�����ſ���ʽ�����仯����Ҫ��������osd����
/*
typedef struct
{
	TVidSrcInfo tVid0Std;      //�����ſ���ʽ
	TVidSrcInfo tOsd0Std;      //�������ʽ
	u32  dwTransVal;       //͸����(0-255)��0:ȫ͸��255:��͸,128:��͸
	u32  dwTransKeyY;      //͸��ɫ
} TVidOsdParam;
*/
void SetOsdParam(TVideoOsdParam tOsdParam);

//osd��ʾ
void StartOsd();

//�ر�osd
void StopOsd();

//�ر���ָ���Ƶ��ʾ
void SetVideoShow(BOOL32 bShow);

//�趨��ǰ*.bin,*.out·����Ĭ��/usr/bin
void SetCodecAppDir(s8* szPath);
//ע��OSP����
void RegsterCommands();

//��ʼ��DSPоƬ
u16 HardCodecInitDSP(TDSPInit* pInit);
u16 HardCodecDestroyDSP(u32 dwDSPID);
//��ʼ��FPGA
u16 HardCodecDevInit(u32 nDecDevNum, u32 nEncDevNum);
u16 HardCodecDestroy();

//�ӿ�FPGA����
    /*�������� SetVideoOutFromVidIn
    ��    �ܣ� �л��������Ƶ��ָ������ӿ������
    ��    ���� u32 dwFromVidIn������ӿ�����VIDIO_HDMI0�ȣ�ֻ��ָ��һ���ӿ�
               u32 dwVidOut   ������ӿ�����VIDIO_HDMI0�ȣ���ָ������ӿ�
                                �磨VIDIO_YPbPr0|VIDIO_HDMI0��
               TVidSrcInfo* ptOutInfo:�����Ƶ��ʽ����ΪNULL
    �� �� ֵ�� u16 :0 �ɹ������� ʧ�ܡ�
    ˵    ���� ��һ�Զ࣬���ܶ�Զ����һ*/
u16 SetVideoOutFromVidIn(u32 dwFromVidIn, u32 dwVidOut, TVidSrcInfo* ptOutInfo = NULL);
    /*�������� SetVideoOutFromVidDec
    ��    �ܣ� �л���������������ݵ������ӿڡ�
    ��    ���� u32 dwFromDecVP����Ϊ����Ľ�������VPID (0 , 1, 2)
               u32 dwVidOut   ������ӿ�����VIDIO_HDMI0�ȣ���ָ������ӿ�
               TVidSrcInfo* ptOutInfo�������Ƶ��ʽ������ΪNULL
    �� �� ֵ�� u16 
    ˵    ���� */
u16 SetVideoOutFromVidDec(u32 dwFromDecVP, u32 dwVidOut, TVidSrcInfo* ptOutInfo);

API void SetMicVol(s32 dwVol);
API s32 GetMicVol();

/*�������� SetCanonPowerOn
��    �ܣ� ��ũ��˷�����ӿ�48v���翪�ؽӿ�ʵ��
��    ���� BOOL32 bEnable=TRUE
�� �� ֵ�� 
˵    ���� */
void SetCanonPowerOn(u32 dwAudPort, BOOL32 bEnable=TRUE);

//��ȡ���������״̬
API BOOL32 GetDigitalMicStatus(u32 dwAudPort);

//��ȡ3.5�ڲ���״̬  bIsAudIn = TRUE:�ɼ���  FALSE:���ſ�
API BOOL32 Get35InOrOutStatus(BOOL32 bIsAudIn);

API BOOL32 GetTRS635Status(u32 dwAudPort);

//��ȡHDMI��Ƶ��״̬
API BOOL32 GetAudHdmiStatus(u32 dwAudPort);

/*��ȡSDI�ӿ����� SDITYPE_ININ SDITYPE_INOUT*/
API u32 GetHDMtSDIIntType();
/*���ò��ŷֱ��ʸı���Ϣ֪ͨ*/
API void SetNtscPalChangeCallBack(CHANGECALLBACK pChangeProc);

//����оƬ����֪ͨ�ص�
API void SetCpuResetNotify(CpuResetNotify fNotify);

//�Ƿ�����ȫ��OSD
API void UseFullOSD(BOOL32 bFullOsd = TRUE);
//HDMI�����HDMI��DVI�ź�ѡ��
API void HDMIDVISwitch(BOOL32 bHDMI = TRUE);
//����SD�ź������ʽ
API void SetSDOutType(u32 dwOutType = VID_OUTTYPE_ORIGIN);	   //�����μ�codecwrapperdef_hd
//����������豸
API void RebootCodecDev(u32 dwDevID = CODECDEV_VIDENC);	   //�����μ�codecwrapperdef_hd

u16 HardEnvInitial(u32 dwHWtype);
s32 HardMPUInit(u32 nMode); //nMode:enInitMode
s32 HardMPUInitDev(u32 nEncTos, u32 nDecTos, u32 nDspNum);
s32 HardMPUDestroy();
#endif //MEDIACTRL_DM816x
#endif
