/* CodecLib.h - Codec API Header */ 

/* Copyright(C) 2001-2002 KDC, All rights reserved. 
˵��:CODEC�ϲ�API��װ����
����:������ κ�α�
*/

#ifndef __CODECLIB_H_
#define __CODECLIB_H_

#include "kdvdef.h"
#include "codeccommon.h"

/*=======================================����������ṹ�Ķ���=================================*/

#ifdef SOFT_CODEC

//ģ��汾��Ϣ�ͱ���ʱ�� �� �����Ŀ�İ汾�ͱ���ʱ��
API void kdvencoderver();
API void kdvdecoderver();

//ģ�������Ϣ �� �����Ŀ�İ�����Ϣ
API void kdvencoderhelp();
API void kdvdecoderhelp();

#endif


enum
{
	MC_CODERC_NULL = 0,
	MC_CODERCDEC_1,
	MC_CODERCDEC_2,
	MC_CODERCDEC_3,
	MC_CODERCDEC_4,
	MC_CODERCDEC_5,
	MC_CODERC_LOCAL,
	MC_CODERC_END
};

enum
{
	MC_PICMEGER_TYPE_ONE = 0,
	MC_PICMEGER_TYPE_TWO,
	MC_PICMEGER_TYPE_THREE,
	MC_PICMEGER_TYPE_FOUR,
	MC_PICMEGER_TYPE_FOUR_BIG,
	MC_PICMEGER_TYPE_SIX,
	MC_PICMEGER_TYPE_TWO_BIG
};

/*���������(Kbps)*/
#define  BIT_RATE_ZERO           (u16)0 

/*���緢�ʹ���(��λ:Kbps,1K=1024)*/   
//#define  SND_NET_BAND          (u8)100<<10

/*I֡�����P֡��Ŀ*/
#define  MAX_P_FARME_INTERNAL_I  (u8)75   /*I֡�����P֡Ϊ75*/

/*��������(1-31)*/
#define  MAX_QUANT_PARAM         (u8)31   /*�����������*/
#define  MIN_QUANT_PARAM         (u8)1    /*��С��������*/
#define  QUANT_PARAM_31          (u8)31   /*�����������*/
#define  QUANT_PARAM_1           (u8)1    /*��С��������*/

/*ͼ���С*/
#define  VIDEO_WIDTH_720         (u16)720  /*ͼ��߶�*/
#define  VIDEO_HEIGHT_576        (u16)576  /*ͼ����*/
#define  VIDEO_WIDTH_352         (u16)352  /*ͼ��߶�*/
#define  VIDEO_HEIGHT_288        (u16)288  /*ͼ����*/
#define  VIDEO_WIDTH_DEFAULT     (u16)640  /*ͼ��Ĭ�ϸ߶�*/
#define  VIDEO_HEIGHT_DEFAULT    (u16)480  /*ͼ��Ĭ�Ͽ��*/

/*֡��(default:25)*/
#define  FRAME_RATE_ONE          (u8)1    /*Ĭ��֡��*/
#define  FRAME_RATE_DEFAULT      (u8)25   /*Ĭ��֡��*/

/*ͼ��ѹ������(1-5)*/
#define  IMAGE_ENCODE_QUALITY_TWO  (u8)2   /*ѹ������2*/
#define  IMAGE_ENCODE_QUALITY_FOUR (u8)4   /*ѹ������4*/     

/*����ģʽ mp3*/
#define	 AUDIO_MODE_WORST        (u8)0/*���*/
#define	 AUDIO_MODE_BAD          (u8)1/*��  */
#define	 AUDIO_MODE_NORMAL       (u8)2/*һ��*/
#define	 AUDIO_MODE_FINE         (u8)3/*��  */
#define	 AUDIO_MODE_BEST         (u8)4/*���*/

/*��������*/
#define  AUDIO_VOLUME_2          (u8)2  
#define  AUDIO_VOLUME_25         (u8)25  

//G.711
#define  AUDIO_MODE_PCMA         (u8)5//a law
#define  AUDIO_MODE_PCMU         (u8)6//u law 
//G.723
#define AUDIO_MODE_G723_6        (u8)7 
#define AUDIO_MODE_G723_5        (u8)8
//G.728
#define AUDIO_MODE_G728		 (u8)9 
//G.722
#define AUDIO_MODE_G722		 (u8)10 
//G.729
#define AUDIO_MODE_G729		 (u8)11 
//G.7221
#define AUDIO_MODE_G7221		 (u8)12 
//adpcm
#define AUDIO_MODE_ADPCM		 (u8)13 

#define AUDIO_MODE_AACLC_32      (u8)14

#define AUDIO_MODE_AACLD_32      (u8)15

#define  MAX_LOCAL_IPADDR_LEN    (u8)30 /*����ip��ַ����*/

#ifndef  MAX_NETSND_DEST_NUM
#define  MAX_NETSND_DEST_NUM     (u8)5  /*����͵�Ŀ�ĵ���*/
#endif

#ifndef MEDIA_TYPE
#define MEDIA_TYPE
/*ͼ���������
#define  MEDIA_TYPE_MP4	         (u8)97//MPEG-4 
#define  MEDIA_TYPE_H261		 (u8)31//H.261  
#define  MEDIA_TYPE_H263		 (u8)34//H.263  reservation
//������������
#define	 MEDIA_TYPE_MP3	         (u8)96//mp3 mode 0-4
#define  MEDIA_TYPE_PCMA		 (u8)8//G.711 Alaw  mode 5
#define  MEDIA_TYPE_PCMU		 (u8)0//G.711 ulaw  mode 6
#define	 MEDIA_TYPE_G7231		 (u8)4//G.7231 reservation
#define	 MEDIA_TYPE_G728		 (u8)15//G.728 reservation
#define	 MEDIA_TYPE_G729		 (u8)18//G.729 reservation
*/
#endif//MEDIA_TYPE

#ifdef SOFT_CODEC
#define  CAP_AUDIO_ONLY          (u8)0x01 //��Ƶ            ���ݲ���
#define  CAP_CAMERA_ONLY         (u8)0x02 //      CAMERA��Ƶ���ݲ���
#define  CAP_AC_BOTH             (u8)0x03 //��Ƶ��CAMERA��Ƶ���ݾ����в���
#define  CAP_DESKTOP_ONLY        (u8)0x04 //	    DESKTOP������Ƶ���ݲ���
#define  CAP_AD_BOTH             (u8)0x05 //��Ƶ��DESKTOP������Ƶ���ݾ����в���
#define  CAP_FILE_AV_BOTH		 (u8)0x08 //��ָ���ļ���Ŀǰ֧��kdc¼���������asf�ļ�����
                                            //��Ƶ����Ƶѹ������Ϊ����Դ

#define  CTRL_AUDIO_ONLY          (u8)0x01 //��Ƶ(�����ɼ�������Ƶ�Լ��ļ�����Ƶ��)
#define  CTRL_VIDEO_ONLY          (u8)0x02 //��Ƶ(�����ɼ�������Ƶ�Լ��ļ�����Ƶ��)
#define  CTRL_AV_BOTH			  (u8)0x03 //����Ƶ����Ƶ��

#define  MAX_DECODER_NUM		 (u8)20   //����������Ŀ


#define  CAP_FRAME_BMP           (u8)0 //RGB24λͼ;
#define  CAP_FRAME_UYVY          (u8)1 //yuv4:2:2��ʽ
#define  CAP_FRAME_I420          (u8)2 //yuv4:2:0��ʽ
#define  SOFT_DEC_ONLY           (u8)0x01
#define  HARD_DEC_ONLY           (u8)0x02
#define  SOFTHARD_DEC_BOTH       (u8)0x03 
#define  AUDIO_MODE_ONLYDEC      (u8)0x01
#define  AUDIO_MODE_ONLYRCV      (u8)0x02
#define  AUDIO_MODE_PLAY         (u8)0x00                
#else

/*ͼ����ʾ����*/
#define MAX_DISPLAY_SATURATION   (u8)99  /*��󱥺Ͷ�*/
#define MAX_DISPLAY_CONTRAST     (u8)99  /*���Աȶ�*/
#define MAX_DISPLAY_BRIGHTNESS   (u8)99  /*�������*/

/*mpv4�������*/
#define FRAME_FORMAT_MERGEENC 				(u8)5      //����ͼ��ϳɱ���
#define FRAME_FORMAT_FOURCIF 				(u8)4      //�̶�ΪFOURCIF����
#define FRAME_FORMAT_TWOCIF 				(u8)3      //�̶�ΪTWOCIF����
#define FRAME_FORMAT_CIF 					(u8)2		//�̶�ΪCIF����
#define FRAME_FORMAT_HALFCIF 				(u8)1		//�̶�ΪHALFCIF����
#define FRAME_FORMAT_AUTO	 				(u8)0		//���̶��ֱ���

/*mpv4�������*/
#define POST_PROCESS_LEVEL_0				(u8)0		//��������
#define POST_PROCESS_LEVEL_1				(u8)1		//����dering�˲�
#define POST_PROCESS_LEVEL_2				(u8)2		//Y������dering�˲�
#define POST_PROCESS_LEVEL_3				(u8)3		//YUV��dering�˲� 

#define MOVEMONITORMATRIX					(u32)1584

#define ZOOM_LVL_ORIGN						(u32)0	//ԭʼ��С
#define ZOOM_LVL_QUATOR						(u32)1	//1/4��С
#define ZOOM_LVL_NINTH						(u32)2	//1/9��С
#define ZOOM_LVL_SIXTEENTH					(u32)3	//1/16��С
#define ZOOM_LVL_QUIT						(u32)4	//�˳�˫����
#define ZOOM_LVL_HIDE						(u32)5	//����

typedef void ( *TDecodeVideoScaleInfo)(u16 wVideoWidth, u16 wVideoHeight);
typedef void (*REBOOTCALLBACK)(u8 byMapId);
typedef void (*CHANGECALLBACK)();
#endif

/*
#ifndef DES_ENCRYPT_MODE
#define DES_ENCRYPT_MODE         (u8)0      //DES����ģʽ
#define AES_ENCRYPT_MODE         (u8)1      //AES����ģʽ
#define ENCRYPT_KEY_SIZE         (u8)32     //��Կ���� ȡ���еĽϴ�ֵ
#define DES_ENCRYPT_KEY_SIZE     (u8)8      //DES��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_A (u8)16  //AES Mode-A ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_B (u8)24  //AES Mode-B ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_C (u8)32  //AES Mode-C ��Կ����
#endif
*/

#ifndef TNETSTRUCT
#define TNETSTRUCT

#define MAX_USERDATA_LEN    16

/*�������*/
typedef struct tagNetSession
{
    tagNetSession(){m_dwRTPAddr=0; m_wRTPPort=0; m_dwRTCPAddr=0; m_wRTCPPort=0; \
                    m_dwRtpUserDataLen = 0; m_dwRtcpUserDataLen = 0;}
    
    u32   m_dwRTPAddr;  //RTP��ַ(������)
    u16   m_wRTPPort;   //RTP�˿�(������)
    u32   m_dwRTCPAddr; //RTCP��ַ(������)
    u16   m_wRTCPPort;  //RTCP�˿�(������)
    u32   m_dwRtpUserDataLen;   //Rtp�û����ݳ���,�����ڴ��������,��Ҫ��ÿ��udpͷǰ��ӹ̶�ͷ���ݵ����
    u8    m_abyRtpUserData[MAX_USERDATA_LEN]; //�û�����ָ��
    u32   m_dwRtcpUserDataLen;   //Rtcp�û����ݳ���,�����ڴ��������,��Ҫ��ÿ��udpͷǰ��ӹ̶�ͷ���ݵ����
    u8    m_abyRtcpUserData[MAX_USERDATA_LEN]; //�û�����ָ��
}TNetSession;

/*�����������*/
typedef struct tagLocalNetParam
{
	TNetSession  m_tLocalNet;
	u32        m_dwRtcpBackAddr;/*RTCP�ط���ַ*/
	u16         m_wRtcpBackPort; /*RTCP�ط��˿�*/        
}TLocalNetParam;

/*���緢�Ͳ���*/
typedef struct tagNetSndParam
{
	u8 m_byNum;
	TNetSession m_tLocalNet;
	TNetSession m_tRemoteNet[MAX_NETSND_DEST_NUM];
}TNetSndParam;

#endif

/*����������*/
typedef struct Encoder
{  
	u32   m_dwCpuId;/*CPU��ʶ*/
#ifdef SOFT_CODEC
	s32   m_nPriority;
	HWND    m_hwVideoPreview;
#else
	u32   m_dwCoreSpd;/*CPU�ٶ�*/
	u32   m_dwMemSpd; /*�ڴ��ٶ�*/
	u32   m_dwMemSize;/*�ڴ��С*/
	u8    m_byPort;   /*Map�˿ں�*/
#endif
}TEncoder;

/*��Ƶ����������*/
typedef struct VideoDecoder
{
	s32     m_nPriority;/*��Ƶ�����߳����ȼ�*/
	u32     m_dwCpuId;  /*��Ƶ�����CPU��ʶ*/
	s32     m_nVideoPlayBufNum;     /*��Ƶ�طŻ������*/
	s32     m_nVideoStartPlayBufNum;/*��Ƶ��ʼ�طŻ������*/
#ifdef SOFT_CODEC
	HWND    m_hwPlayVideo;
	BOOL32  m_bOverlay;//�Ƿ�Overlay;
	u8      m_byMask;  //0x01�������,0x02Ӳ������,0x03����ͬʱ����
    u16     m_wDecTimer;  //��ʱ���Ʋ��ŵ�ʱ��������λms��default 0������Ӧ������ʱ��
	//Ӳ�����벿�� 
	s32 	m_nBsp15Freq;//MHZ
	s32 	m_nMemFreq;  //MHZ
	u8      m_byChipType;
	u8	    m_byBoardId;//index from 0 
	u8	    m_byBufNum; //queue length, default 5 
	CHAR	m_achDemoFilePath[MAX_PATH];
#else
	u32   m_dwCoreSpd;/*CPU�ٶ�*/
	u32   m_dwMemSpd; /*�ڴ��ٶ�*/
	u32   m_dwMemSize;/*�ڴ��С*/
	u8    m_byPort;   /*Map�˿ں�*/
#endif
	
	u32	  m_dwPostPrcLvl;  /*mpv4����ļ���*/		 
}TVideoDecoder;

/*��Ƶ����������*/
typedef struct AudioDecoder
{
	s32   m_nPriority;       /*��Ƶ�����߳����ȼ�*/
	u32   m_dwCpuId;         /*��Ƶ�����CPU��ʶ*/
	s32   m_nAudioPlayBufNum;/*��Ƶ���Ż�����*/
	s32   m_nAudioStartPlayBufNum;/*��Ƶ��ʼ���Ż�����*/
#ifdef SOFT_CODEC
    u8    m_byAudioMode;
#else
	u32   m_dwCoreSpd; /*CPU�ٶ�*/
	u32   m_dwMemSpd;  /*�ڴ��ٶ�*/
	u32   m_dwMemSize; /*�ڴ��С*/
	u8    m_byPort;    /*Map�˿ں�*/
#endif
}TAudioDecoder;

#ifdef SOFT_CODEC

#define FRMRATE_CAL_BY_FPS  0 
#define FRMRATE_CAL_BY_SPF  1

typedef struct VideoCapParam
{
	u16	m_wVideoWidth; //��Ƶ����ͼ����(default:640)
	u16	m_wVideoHeight;//��Ƶ����ͼ��߶�(default:480)
	u8  m_byFrmRateLittleThanOne; // ֡���Ƿ�С��1 ?  
	u8	m_byFrameRate; //��Ƶ����֡��(default:25)   ��֡��>=1���� m_byFrameRate �� fps, ��֡��<1���� m_byFrameRate �� spf  
	u8  m_byFOURCC;    //��Ƶ����֡��ʽ(default:CAP_FRAME_BMP)
}TVideoCapParam;
#else

#endif

/*������״̬*/
typedef struct KdvEncStatus
{
	BOOL32 				m_bVideoSignal;			/*�Ƿ�����Ƶ�ź�*/
	BOOL32	        m_bVideoCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bVideoEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	u32           m_dwVideoBufLen;  /*��Ƶ���峤��*/
	u32           m_dwAudioBufLen;  /*��Ƶ���峤��*/ 
	TVideoEncParam	m_tVideoEncParam; /*��Ƶ�������*/
	u8            m_byAudioEncParam;/*��Ƶ����ģʽ*/
	u8			  m_byAudEncMediaType; /*��Ƶ����ý������*/	
	TNetSndParam    m_tVideoSendAddr; /*��Ƶ���͵�ַ*/
	TNetSndParam    m_tAudioSendAddr; /*��Ƶ���͵�ַ*/
#ifdef SOFT_CODEC
	u32           m_dwSetEncParam; //����Ӳ�������������
	u32           m_dwVideoSend;   //�ѷ��͵���Ƶ����
	u32           m_dwAudioSend;   //�ѷ��͵���Ƶ����
	u32           m_dwHardFrameNum;//Ӳ���ص�֡��
	u32           m_dwPrevFrameNum;//Ԥ��֡��
#else
	u32  m_dwVideoMapHeartBeat;
	u32  m_dwAudioMapHeartBeat;  
#endif
	
}TKdvEncStatus;

/*������ͳ����Ϣ*/
typedef struct KdvEncStatis
{
    u8   m_byVideoFrameRate;/*��Ƶ֡��*/
    u32  m_dwVideoBitRate;  /*��Ƶ�����ٶ�*/
    u32  m_dwAudioBitRate;  /*���������ٶ�*/
    u32  m_dwVideoPackLose; /*��Ƶ��֡��*/
    u32  m_dwVideoPackError;/*��Ƶ��֡��*/
    u32  m_dwAudioPackLose; /*������֡��*/
    u32  m_dwAudioPackError;/*������֡��*/
	u32  m_wAvrVideoBitRate;   /*1��������Ƶ����ƽ������*/
	u32	 m_wAvrAudioBitRate;   /*1��������������ƽ������*/
}TKdvEncStatis;


/*������״̬*/
typedef struct KdvDecStatus
{
	BOOL32	m_bVideoDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bAudioDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	u32	m_dwAudioBufLen; /*��Ƶ���Ż��峤��*/
	u32	m_dwVideoBufLen; /*��Ƶ���Ż��峤��*/
	TLocalNetParam   m_tAudioRcvAddr;/*��Ƶ���ص�ַ*/
	TLocalNetParam   m_tVideoRcvAddr;/*��Ƶ���ص�ַ*/
#ifdef SOFT_CODEC
	BOOL32	m_bAudioOutThread;/*�Ƿ����������̴߳��*/
	BOOL32	m_bMp4CodecThread;/*�Ƿ�Mp4�����̴߳��*/
#else      
	u32   m_dwVideoMapHeartBeat;//ͼ�����Map����
	u32   m_dwAudioMapHeartBeat;//��������Map����
	TVideoDisplayParam m_tVideoDisplayParam;//ͼ����ʾ����  
#endif
	u32   m_dwAudioDecType;     //��Ƶ��������
	u32   m_dwVideoDecType;     //��Ƶ��������
}TKdvDecStatus;

/*������ͳ����Ϣ   remove to codeccommon.h*/

//Ӳ���ɼ�оƬ����
#ifdef SOFT_CODEC
#define ENC_CHIP_TYPE_7111		1//7111
#define ENC_CHIP_TYPE_7114		2//7114 
#endif

/* �������(�������ҹ�)���� */
typedef struct
{
	u32 dwXPos;
    u32 dwYPos;//��ʾ�����Y����
    u32 dwWidth;//��ʾ����Ŀ�
    u32 dwHeight;//��ʾ����ĸ�
    u32 dwBMPWight;//BMPͼ���
    u32 dwBMPHeight;//BMPͼ���
    u32 dwBannerCharHeight;//����߶ȣ�����Ҫ�������¹���ʱ��ȷ��ͣ�ٵ�λ��
    TBackBGDColor tBackBGDColor;//����ɫ 
    u32 dwBGDClarity;//������ɫ͸����
    u32 dwPicClarity;//����ͼƬ͸����
    u32 dwRunMode;//����ģʽ������or����or��ֹ���궨�����ϣ�
    u32 dwRunSpeed;//�����ٶ� �ĸ��ȼ����궨�����ϣ�
    u32 dwRunTimes;//�������� 0Ϊ�����ƹ���
	u32 bRunForever;//�����ƹ���
	u32 dwHaltTime;//ͣ��ʱ��(��)�����¹���ʱ��ÿ����һ���ֵ�ͣ�ټ����0ʼ��ͣ�����뾲ֹ��ͬ�� 
}TAddBannerParam;

#define BANNER_SIZE          (10<<10)           /*����ߴ磬�ϲ㴫���ͼ�����ؿ��֮�����ô��ڴ�����*/

/*========================================��������붨��======================================*/

/*��Ƶ�����������*/
#define VID_DROP_PREFERRED_QUALITY      0    //�������ȣ�Ϊ��I֡����
#define VID_DROP_PREFERRED_FAST_SPEED   1    //�ٶ����ȿ쵵���Իָ������ж�����ֻ�ⲻ����֡��Ϊ1����
#define VID_DROP_PREFERRED_MID_SPEED    2    //�ٶ������е����Իָ������ж�����ֻ�ⲻ����֡��Ϊ2����
#define VID_DROP_PREFERRED_SLOW_SPEED   3    //�ٶ������������Իָ������ж�����ֻ�ⲻ����֡��Ϊ4����



#ifdef SOFT_CODEC
struct TEncoderRef;
struct TEncoderStatus;
class  CSoftEncoder;
class  CDrawWnd;
typedef void (*PAUDIOCALLBACK)(u8 buAudioMode, u8 *pBuf, s32 nSize, u32 dwContext);
typedef void (*PVOICECHECK)(CHAR cMode, u32 dwContext);
typedef void (*PDRAWCALLBACK)(u32 dwParam);
typedef void (*PSTATICPICCALLBACK)(u8 *pBuf, u32 dwSize, BITMAPINFOHEADER* pHead, u32 dwParam);


typedef struct tagVoiceCheck
{
	s32			m_nBGTime;
	s32			m_nThreshold;
	PVOICECHECK	m_pCallBack;
	u32         m_dwContext;
}TVoiceCheck;

typedef void (*PGETAUDIOPOWER)(u8 byAudioPower, u32 dwContext);

#define PIC_ENCODE_JPEG   (u8)1//
#define PIC_ENCODE_BMP    (u8)2//

#define MAX_LOGO_NAME_LEN (u8)32//

//̨�����������������Ϣ����
typedef struct tagLogoSetting
{
	u32 m_dwXPos;    //̨��λ��
	u32 m_dwYPos;    //̨��λ��
	u8  m_byClarity; //̨��͸����(0-255)
	u8  m_byLogoName[MAX_LOGO_NAME_LEN+3]; //�ն˱���
}TLogoSetting;

#else
class CVideoEncoder;
class CAudioEncoder;
typedef void ( *TDebugCallBack )(char *pbyBuf, int dwBufLen);
#endif

/*�ļ�������*/
class   CFileEncoder;


class CKdvEncoder/**/
{	
public:
    CKdvEncoder();
    virtual ~CKdvEncoder();
public:
	
#ifdef SOFT_CODEC      
    //��ʼ�����������
    u16    Create( HWND previewHwnd, 
		           s32 nPriority = THREAD_PRIORITY_NORMAL,
		           u8 byBindCpuId = 0, u8 byCapType = CAP_AC_BOTH );

    u16    SetVoiceCheck(BOOL32 bCheck,const TVoiceCheck *ptVoiceCheck);/*�������ʼ��*/	
	
	u16    StartCap(u8 byCapType = CTRL_AV_BOTH);//��ʼ����
    u16    StopCap(u8 byCapType =  CTRL_AV_BOTH); //ֹͣ����
    u16    SetPreviewHwnd( HWND hPrevWnd );
    u16    SelectVideoSource(const char *szFileName = NULL);//ѡ����ƵԴ
    u16    SetVideoIcon( BOOL32 bEnable );//bEnable,TRUEΪ���ã�FALSE���衣
    u16    SetVideoCapParam(const TVideoCapParam  *ptVideoCapParam );//����ͼ�񲶻����
    u16    SetAudioCapParam( u8 byMode );
    u16    GrabPic(CDrawWnd *pDrawWnd);//��pDrawWnd��Чʱ���ص��ӿڣ�����Ϊ��.
    u16    SaveAsPic(LPCSTR lpszFileName, u8 byEncodeMode);
	u16    SetAudioCallBack(PAUDIOCALLBACK pAudioCallBack, u32 dwContext);

	// ���� ��ȡ������Ƶ���� �Ļص�
	u16    SetInputAudioPowerCB(PGETAUDIOPOWER pGetInputAudioPowerCB, u32 dwContext);

	// ���� ̨���������� �Ŀ���
	u16    SetAddLogoIntoEncStream(TLogoSetting *ptLogoSetting);
	
	// ���� �������ı���Ԥ�� �Ŀ���
	u16    ShowPreview(BOOL32 bPreview);

    u16    GetAudioMute( BOOL32& bMute );     // �Ƿ��� [zhuyr][4/20/2005]
    
	//������Ƶ�������ش�����  [zhuyr][12/5/2005]
	//u16    SetNetFeedbackAudioParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
#else // vxworks
	u16    CreateEncoder(const TEncoder *ptVideoEncoder, 
							const TEncoder *ptAudioEncoder);/*��ʼ��������*/

	/*��Ƶ���������뵥��ƵԴ˫������*/
    u16    AddVidEncToSingleCapGroup(u16  wAddtoChnNum);
	
	/*���;�̬ͼƬ*/
	u16    SetSendStaticPic(BOOL32  bSendStaticPic);

	/*��ȡ����ץ��ͼƬ*/
	u16    SetSnapshotMaxSize(u32  dwSnapshotMaxSize);
	u16    Snapshot();
	u32    GetSnapshotSaveSize();
	u32    GetSnapshotSavePicNum();

	/*��ȡ������Ƶ����*/
	u32    GetInputAudioPower();

	u16    ScaleVideoCap(u8 byType, u8 byValue); /* ��Ƶ�ɼ����� */

	u16	   SetMpv4FrmPara(const TMpv4FrmParam *ptMpv4FrmPara);	/*����mpv4֡����*/ 
//	u16    SetVgaEncPara(TVgaEncParam *ptVgaEncPara);  /*����VGA�������*/

	/* ����¼�񡢷����Ľӿ� */
	u16 BindRecorder(u8 byRecorderId);
	
		//����ն���
	//����˫�ɼ�������ģʽ
	u16   SetDblCapOneStreamParameter(u16 dwInOut, u16 dwZoom, u16 dwXPos, u16 dwYPos);
	u16	   SetEncMoveMonitor(TMoveDetectParam *ptMoveDetectParam,u32 dwAreaNum,u32 dwPort);
	void   SetEncMotionCallBack(TMotionAlarmInfo tMotionAlarmInfo,u32 dwContext){m_ptMotionAlarmInfo = tMotionAlarmInfo;m_dwMotionContext = dwContext;}	
	TMotionAlarmInfo	m_ptMotionAlarmInfo;
	u32					m_dwMotionContext; //�ƶ����ص�������	
	
#endif

	u16    GetVgaMode(u32 *pdwWidth, u32 *pdwHeight, u32 *pdwRefreshRate);	//�õ�vga�ķֱ���
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);/*��ȡ������״̬*/ 		
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis );/*��ȡ��������ͳ����Ϣ*/
//#ifndef WIN32
    u16    StartVideoCap(u8 byCapType = VIDCAP_CAPVIDEO);/*��ʼ�ɼ�ͼ��*/
    u16    StopVideoCap(); /*ֹͣ�ɼ�ͼ��*/
//#endif
    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam );/*������Ƶ�������*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );       /*�õ���Ƶ�������*/
    u16    StartVideoEnc();/*��ʼѹ��ͼ��*/
    u16    StopVideoEnc(); /*ֹͣѹ��ͼ��*/
	
//#ifndef WIN32
    u16    StartAudioCap(BOOL32 bAinMic = FALSE);/*��ʼ�����ɼ�*/
    u16    StopAudioCap(); /*ֹͣ�����ɼ�*/
//#endif
    u16    SetAudioEncParam(u8 byAudioEncParam, 
                            u8 byMediaType=MEDIA_TYPE_MP3,
                            u16 wAudioDuration = 30); /*��������ѹ������*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*�õ�����ѹ������*/

	u16    StartAudioEnc();/*��ʼѹ������*/
    u16    StopAudioEnc(); /*ֹͣѹ������*/
    u16    SetAudioMute( BOOL32 bMute );     //�����Ƿ���
    u16    SetAudioVolume(u8 byVolume ); /*���òɼ�����*/	
    u16    GetAudioVolume(u8 &byVolume );/*��ȡ�ɼ�����*/	
	
	/*����ͼ��������ش�����*/
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
	u16    SetVidFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetVidFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetVidFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetVidFecXY(s32 nDataPackNum, s32 nCrcPackNum);

	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetAudFecEnable(BOOL32 bEnableFec);
	//����fec���а�����
	u16    SetAudFecPackLen(u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetAudFecIntraFrame(BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetAudFecMode(u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetAudFecXY(s32 nDataPackNum, s32 nCrcPackNum);
	
	//��Ƶ��̬�غɵ�PTֵ���趨
	u16 SetAudioActivePT(u8 byLocalActivePT);
	
	//��Ƶ��̬�غɵ�PTֵ���趨
	u16 SetVideoActivePT(u8 byLocalActivePT );
	
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16    SetAudEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
	
	//������Ƶ�������key�ִ������ܵ��غ�PTֵ �Լ� ����ģʽ Aes or Des
	u16    SetVidEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode ); 
	

#ifdef SOFT_CODEC
    VOID    GetLastError( u32 &dwErrorId );
#endif
	
private:
	s64    m_qwLastFastupdataTime;     //���һ��FastUpdata��ʱ��

protected:

#ifdef SOFT_CODEC
    CSoftEncoder     *m_pcKdvInterEnc;
    TEncoderRef      *m_ptRef;
    TEncoderStatus   *m_ptStatus;	
#else
	u32               m_dwMagicNum;
    CVideoEncoder    *pVideoEncoder;
    CAudioEncoder    *pAudioEncoder;
#endif
};

#ifdef SOFT_CODEC
class CKdvVideoDec;
class CKdvAudioDec;
struct TDecoderRef;
struct TDecoderStatus;
#else
class CVideoDecoder;
class CAudioDecoder;
#endif

class CKdvDecoder
{
public:
    CKdvDecoder();
    virtual ~CKdvDecoder();
	
public:
    u16    CreateDecoder(const TVideoDecoder *ptVideoDecoder,const TAudioDecoder *ptAudioDecoder);/*��ʼ��������*/	
    u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*��ȡ������״̬*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*��ȡ��������ͳ����Ϣ*/	

	u16    SetVideoDecType(u8 byType); /*����ͼ�����������, ֻ���ڿ�ʼ����ǰ���ò���Ч*/
    u16    StartVideoDec();/*��ʼͼ�����*/
    u16    StopVideoDec(); /*ֹͣͼ�����*/

#ifndef SOFT_CODEC
	u16    StartVideoPlay(); /* ��ʼͼ�񲥷� */
	u16    StopVideoPlay(); /* ֹͣͼ�񲥷� */
#endif

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


    u16    ClearWindow();  /*����*/
    u16    FreezeVideo();  /*��Ƶ����*/
    u16    UnFreezeVideo();/*ȡ����Ƶ����*/

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

#ifdef SOFT_CODEC
	//  [zhuyr][12/5/2005]������Ƶ�������ش�����
	//u16    SetNetFeedbackAudioParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE);

    //�ƶ����  [zhuyr][8/11/2005]
    u16    SetWatchMoveRect(LPRECT pRect, u8 bySize);
    u16    SetWatchColor(COLORREF crWatch);

    //�Ƿ�������綶�������������ٶȣ���ʱ������Ч��  [zhuyr][5/24/2005]
    u16    SetNetDithering(BOOL32 bUser);

    //�����  [zhuyr][5/18/2005]
    u16    RegStaticPicCallBack(PSTATICPICCALLBACK pCallBack, u32 dwParam);

    //���ý�����ͼ����õĻص�����  [zhuyr][4/25/2005]
    u16    SetDrawCallBack(PDRAWCALLBACK pFun, u32 dwParam);

    //�õ�����״̬  [zhuyr][4/20/2005]
    u16    GetAudioMute(BOOL32& bMute);

    //�õ�Wrapper�İ汾�ͱ�����Ϣ bysize��ò�С��128  [zhuyr][2/23/2005]
    u16    GetWrapperVer(s8 *pszVerBuffer, u8 bySize);
    
    //bAutoΪTRUEʱ��ǰ�ĸ�������ʾ�ĸ������ϱ��õĿ������CIFʱ��������;
    //�������ͼ���С�ı䡣
    //bAutoΪFALSeʱ��ǰ�ĸ������趨���������ͼ���С�ı䡣[zhuyr][3/17/2005]
    u16    SetShowMargins(s32 nLeft, s32 nTop, s32 nRight, s32 nBottom, BOOL32 bAuto = TRUE);
	u16    SetPlayHwnd( HWND hPlayWnd, BOOL32 bSaveLastFrame = FALSE );
	u16    RedrawLastFrame();/*�����ػ�*/
	
	/*��pDrawWnd��Чʱ���ص��˽ӿڣ�����Ϊ��.*/
	u16    GrabPic(CDrawWnd *pDrawWnd);//ץȡͼ��
    u16    SaveAsPic(LPCSTR lpszFileName, u8 byEncodeMode);//ͼ�񱣴�

	//�����Ƿ�ֻ��ؼ�֡ TRUEΪ���ã�FALSEΪȡ��
	u16    SetOnlyKeyFrame(BOOL32 bKeyFrame);

	u16    SetAudioCallBack(PAUDIOCALLBACK pAudioCallBack, u32 dwContext);
	// ���� ��ȡ�����Ƶ���� �Ļص�
	u16    SetOutputAudioPowerCB(PGETAUDIOPOWER pGetOutputAudioPowerCB, u32 dwContext);

    VOID   GetLastError( u32 &dwErrorId );
#else
	u16    SetDisplayType(u8 byDisplayType);/*���û�����ʾ����(PAL VGA)*/
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
	
	/*��ȡ����ץ��ͼƬ*/
	u16    SetSnapshotMaxSize(u32  dwSnapshotMaxSize);
	u16    Snapshot();
	u32    GetSnapshotSaveSize();
	u32    GetSnapshotSavePicNum();
	
	/*��ȡ�����Ƶ����*/
	u32    GetOutputAudioPower();
	u16    SetAudioRevBuf(u32 dwStartBufs, u32 dwFasterBufs);

	//����ն���
	u16	   SetDecMoveMonitor(TMoveDetectParam *ptMoveDetectParam,u32 dwAreaNum);
	void   SetDecMotionCallBack(TMotionAlarmInfo tMotionAlarmInfo,u32 dwContext){m_ptMotionAlarmInfo = tMotionAlarmInfo;m_dwMotionContext = dwContext;}	
	TMotionAlarmInfo	m_ptMotionAlarmInfo;
	u32					m_dwMotionContext; //�ƶ����ص�������	

#endif

protected:
#ifdef SOFT_CODEC
public:
    CKdvVideoDec       *m_pcKdvVideoDec;//����
    CKdvAudioDec       *m_pcKdvAudioDec;//����
    TDecoderRef	       *m_ptRef;   //����
    TDecoderStatus     *m_ptStatus;//����
protected:
    u8		       m_byFlag;
#else
	u32               m_dwMagicNum;
    CVideoDecoder       *pVideoDecoder;
    CAudioDecoder       *pAudioDecoder;
#endif

public:      /*�ļ�����������*/
    u16    CreateFileEncoder(char * pFielName);
	u16    DestroyFileEncoder();
	u16    StartFileEncoder();
	u16    StopFileEncoder();
	u16    PauseFileEncoder();
	u16    ContinueFileEncoder();

	u16 SendVidFrameToMap(u16 dwStreamType, u16 dwFrameSeq, u16 dwWidth,
		                   u16 dwHeight, u8 *pbyData, u16 dwDataLen);
	u16 SendAudFrameToMap(u16 dwStreamType, u16 dwFrameSeq,  u8 byAudioMode, 
		                   u8 *pbyData, u16 dwDataLen);
	
protected:
	CFileEncoder *  m_pcFileEncoder;
	BOOL32            m_bFileEcncoderInit;
	BOOL32            m_bFileEncoderStart;
	BOOL32            m_bFileEncoderPause;
	
};


#ifdef SOFT_CODEC
class CDrawWnd : public CStatic
{
	DECLARE_DYNAMIC(CDrawWnd)
public:
	CDrawWnd(BOOL32 bAlloc = FALSE/*�Ƿ�Ԥ���䱳��������*/);
	
	// Attributes
public:
	
    /*
    SetFullScreen
    ��    ���� u32 nMax    :��Ļ���ָ�ɼ���
               u32 nXIndex :ˮƽ������������1��ʼ
               u32 nYIndex :��ֱ������������1��ʼ
               u32 nCombine:�ϲ��߳���1��nMax��
    */
    BOOL32 SetFullScreen();   //����ȫ��,
    BOOL32 SetFullScreen(u32 nMax, u32 nXIndex, u32 nYIndex);
    BOOL32 SetFullScreen(u32 nMax, u32 nXIndex, u32 nYIndex, u32 nCombine);
    BOOL32 CancelFullScreen();//ȡ��ȫ��
/*ע�⣺
     ����������������Ҫ���µ��ñ���������û�ͼ���ں���
	 ����������SetPlayHwnd,��������SetPreviewHwnd.
*/
    BOOL32 SetBackBitmap(u8 *pBuf, s32 nSize, PBITMAPINFOHEADER pbmiHeader);
    BOOL32 SetFrontBmp(u8 * pFrontBuf);
    BOOL32 GetPicInfo(PBITMAPINFOHEADER pbih);
    BOOL32 SaveAsPic(LPCSTR lpszFileName, u8 byEncodeMode);//ͼ�񱣴�
    BOOL32 PrintfPic();
public:
    RECT m_rtPos;
	HWND m_hParentWnd;
	BOOL32 m_bFullScreen;
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawWnd)
public:
	virtual BOOL32 Create(LPCTSTR lpszWindowName, UINT dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID=0xffff, CCreateContext* pContext = NULL);
protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
	
private:
    void *m_pPriData;
public:
	virtual ~CDrawWnd();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CDrawWnd)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};

class CAVCapabilityList;
class CAVCapCheck  
{
public:
    CAVCapCheck();
    ~CAVCapCheck();
public:
	BOOL32 CheckAudInCap();
	BOOL32 CheckVidInCap();
	BOOL32 CheckAudOutCap();
	BOOL32 CheckVidOutCap();
	BOOL32 CheckAudEncCap(u8 byMediaType);
	BOOL32 CheckVidEncCap(u8 byMediaType);
	BOOL32 CheckAudDecCap(u8 byMediaType);
	BOOL32 CheckVidDecCap(u8 byMediaType);	

private:
	CAVCapabilityList *m_ptCAVCapList;
};

#endif

/* Ӳ�����������ʼ��������ض��� */
typedef struct 
{
	u32 dwCoreSpd;            /*�ں��ٶ�*/
	u32 dwMemSpd;             /*�ڴ��ٶ�*/
	u32 dwMemSize;            /*�ڴ��С*/
	u32 dwMaxVidEncNum;       /*�����Ƶ����·��*/
	u32 dwMaxVidDecNum;       /*�����Ƶ����·��*/
	u32 dwMaxAudEncNum;       /*�����Ƶ����·��*/
	u32 dwMaxAudDecNum;       /*�����Ƶ����·��*/
	BOOL32  bVgaOut;              /*ʹ��VGA��Ϊͼ����������ֶν����ֶ�dwMaxVidDecNum>0ʱ��Ч*/
	u16  wRefreshRate;         /*VGAɨ��Ƶ��(HZ)*/
}THardCodecInitParm;

/*Osd��Ϣ��¼*/
typedef struct 
{
	u8    bHasData;      //��¼MapHaltǰ�в���
	u8 *  pbyBmp;        //����ΪOsd��Ϣ
	u32   dwBmpLen; 
	u32   dwXPos; 
	u32   dwYPos; 
	u32   dwWidth; 
	u32   dwHeight; 
	u8    byBgdColor; 
	u32   dwClarity; 
}TOsdRecordInfo;

typedef struct 
{
	u8    bHasData;      //��¼MapHaltǰ�в���
	u8 *  pbyBmp;        //����ΪOsd��Ϣ
	u32   dwBmpLen; 
	u32   dwXPos; 
	u32   dwYPos; 
	u32   dwWidth; 
	u32   dwHeight; 
	TBackBGDColor    tBackBGDColor; 
	u32   dwClarity; 
}TOsdEncAndLocRecordInfo;//��̨������������������ʾ̨��ʱ���ı䱳��ɫΪ�ṹTBackBGDColor

typedef struct 
{
	u8    bHasData;      //��¼MapHaltǰ�в���
	u8 *  pbyBmp;        //����ΪOsd��Ϣ
	u32   dwBmpLen; 
	u32   dwChnNum;
	TAddBannerParam tAddBannerParam;
}TOsdEncAndLocBannerRecordInfo;//������ʾ���������������ն����߻��Ѻ󣬻ָ�����ṹ


//#include "EqtMap.h"

#define OSD_BUF_LEN       (u32)(800<<10)   //(u32)(1<<20)

//#define OSD_TIMER

#ifdef OSD_TIMER
#ifdef _VXWORKS_
#include "timers.h"
#include "time.h"
#endif
#endif

#define MAX_OSD_NUM          100
#define OSD_OK               0
#define OSD_ERROR            0xFFFF

#define RUNSPEED_VERYSLOW    0
#define RUNSPEED_SLOW        1
#define RUNSPEED_NORMAL      2
#define RUNSPEED_FAST        3
#define RUNSPEED_VERYFAST    4

#define RUNMODE_DOWN2UP      0
#define RUNMODE_LEFT2RIGHT   1
#define RUNMODE_STILL        2



typedef struct 
{
	BOOL32  bValid;
	u8  byType; //���ͣ�0--��̬Osd, 1--����Osd.
	u32 dwXPos;
	u32 dwYPos;
	u32 dwWidth;
	u32 dwHeight;
}TOsdDesc;

/*Osd����*/
typedef struct OsdParam
{
	u16 byOsdType;         /*Osd ����*/
	u8 *pbyHdrBuf;        /*ͷBuffer*/
	u32 dwHdrLen;         /*ͷ����*/
	u8 *pbyDataBuf;       /*����Buffer*/
	u32 dwDataLen;        /*���ݳ���*/
	u32 dwXPos;           /*X����*/
    u32 dwYPos;           /*Y����*/
    u32 dwHeight;         /*�߶�*/
    u32 dwWidth;          /*���*/
	u32 dwTansparentValue; /*͸����*/
	u32 dwOtherParam1;     /*��������1*/
	u32 dwOtherParam2;     /*��������2*/
}TOsdParam;

class CHardCodec;

class COsdMap
{
public:
    COsdMap();
    virtual ~COsdMap();
	
public:
	//��ʼ��
    u16 Initialize(u32 dwMapID);

	//��ʾOSD���ɹ����ر�Osd��ID�ţ�ʧ�ܷ���OSD_ERROR.
	int OsdShow(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, 
				 u8  byBgdColor, u32 dwClarity, BOOL32  bSlide=FALSE,u32 dwSlideTimes=1,
				 u32 dwSlideStride=10);

	//�ر�Osd, �ɹ�����OSD_OK; ʧ�ܷ���OSD_ERROR.
    int OsdClose(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, BOOL32 bSlide=FALSE);	
	
#ifdef SOFT_CODEC
	//��ʼ̨����������
	int StartAddLogoInEncStream(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, 
								u32 dwHeight, TBackBGDColor tBackBGDColor , u32 dwClarity, u32 dwChnNum);
	//ֹ̨ͣ����������
	int StopAddLogoInEncStream(u32 dwChnNum);
#else	
	//��ʼ̨����������
	int StartAddLogoInEncStream(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, 
								u32 dwHeight, TBackBGDColor tBackBGDColor , u32 dwClarity, u32 dwChnNum, u32 dwCapPrt = 2);
	//ֹ̨ͣ����������
	int StopAddLogoInEncStream(u32 dwChnNum, u32 dwCapPrt = 2);
#endif

	//��ʼ����ͼ�����̨��
	int StartAddIconInLocal(u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth, 
							u32 dwHeight, TBackBGDColor tBackBGDColor , u32 dwClarity, u32 dwChnNum);
	//ֹͣ����ͼ�����̨��
	int StopAddIconInLocal(u32 dwChnNum);
	
	//��ʼ������ʾ������Ļ(�������Ϲ�)
	int StartRunCaption(u8 *pbyBmp, u32 dwBmpLen, u32 dwTimes, u32 dwXPos, u32 dwSpeed, u32 dwWidth, 
		                u32 dwHeight, u8  byBgdColor, u32 dwClarity, u32 dwChnNum);

	//ֹͣ������ʾ������Ļ
	int StopRunCaption(u32 dwChnNum);

	//��ʼ�����������
	int StartAddBannerInEncStream(u8 *pbyBmp/*ͼ��ָ��*/, u32 dwBmpLen/*ͼ���С*/, u32 dwChnNum/*ͨ����*/,	TAddBannerParam tAddBannerParam/*��������ṹ*/);

    //ֹͣ�����������
	int StopAddBannerInEncStream(u32 dwChnNum);

	//��ʼ������뱾��
	int StartAddBannerInLocal(u8 *pbyBmp/*ͼ��ָ��*/, u32 dwBmpLen/*ͼ���С*/, u32 dwChnNum/*ͨ����*/,	TAddBannerParam tAddBannerParam/*��������ṹ*/);

    //ֹͣ������뱾��
	int StopAddBannerInLocal(u32 dwChnNum);

	//��ȡOsdBuf��ַ
	u16 GetOsdBufAddr();
	
#ifdef OSD_TIMER

#ifdef SOFT_CODEC
	int  StartTimeIconShow(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, 
						  TBackBGDColor tBackBGDColor, u32 dwClarity, u32 dwChnNum);
	int  StopTimeIconShow(u32 dwChnNum);
#else

	int  StartTimeIconShow(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, 
	            		  TBackBGDColor tBackBGDColor, u32 dwClarity, u32 dwChnNum, u32 dwCapPrt = 2);
	int	 AlarmTimeIconShow(u32 dwChnNum,u32 dwCapPrt,u32 dwAlarmTime);
	int  StopTimeIconShow(u32 dwChnNum, u32 dwCapPrt = 2);
#endif	
	int  CheckTImeIconProc();
	//ʱ��̨��ʱ�Ӵ�����
#ifdef _VXWORKS_
    friend void TimeIconTimerProcess(timer_t timerid, int Param);   
#endif

#endif

	/*Map������ָ�Osd��Ϣ*/
	void   RecoverOsdShow();
	void   RecoverAddLogo();
	void   RecoverAddIcon();
	void   RecoverAddBanner();
#ifdef OSD_TIMER
	void   RecoverTimeIcon();
#endif
	
private:
    int  CheckOsdBuf(u32 dwBufNo);

	TOsdRecordInfo  m_tOsdShowInfo;       //��ʾ��̬OSD��Ϣ
	TOsdEncAndLocRecordInfo  m_tAddLogoInfo;       //̨������������Ϣ
	TOsdEncAndLocRecordInfo  m_tAddIconInfo;       //����ͼ�����̨����Ϣ
	TOsdEncAndLocRecordInfo  m_tTimeIconInfo;      //ʱ��̨����Ϣ
	TOsdEncAndLocBannerRecordInfo m_tBannerLocInfo;   //���غ��
	TOsdEncAndLocBannerRecordInfo m_tBannerEncInfo;   //�������������Ϣ
private:
	TOsdDesc m_atOsdDesc[MAX_OSD_NUM];
    volatile u32 m_dwMapBuffer[2];  //Osd Buffer
    u8 m_byCurBufNum;      //��ǰBuffer���
	int nWaitTime;           //�ȴ�����
	
#ifdef OSD_TIMER
	//ʱ��ID
#ifdef _VXWORKS_
	timer_t m_timerId;      
#endif

#endif

	u32   m_dwAddLogoChn;
	u32   m_dwDrawOsdFailTimes; 
	CHardCodec *m_pcCodecMap;	
};


#ifdef HARD_CODEC


/* Ӳ�����������ʼ������, ������ʹ��Ӳ������������������ǰ����. �ɹ�����CODEC_NO_ERROR, ʧ�ܲμ������� */
extern "C" int HardCodecInit(int dwCpuId, THardCodecInitParm *ptCodecInitParam, BOOL32  bKdv8010 = TRUE);

/* Ӳ����������˳�����������֮���û��ٲ��ܶ���Ӧ������������κβ��� */
extern "C" void HardCodecQuit(int dwCpuId);

/* �����ʾ���庯�����û��ڵ���HardCodecQuit��������֮ǰ�ȵ��ñ������Խ��reboot����������� */
extern "C" void ClearPlayBuf();


API void codecwrapperver(u32 dwMapId);

/*   ���÷���ɫ�����Ի���ʾɫ������
     dwChnNum -- ����ͨ���ţ�=255ʱ��ʾ���б���ͨ��������ɫ������ͼƬ
     dwTestPicType -- ɫ������ͼƬ�ţ�0--�ֱ��ʲ��ԣ�1--ɫ�Ȳ��ԣ�2--�ҶȲ��ԣ�255--ȡ������*/
API BOOL32  SetSendTestPic(u32 dwMapId, u32 dwChnNum, u32 dwTestPicType);
API BOOL32  SetPlayTestPic(u32 dwMapId, u32 dwTestPicType);

/*ɾ�����п��մ洢���ļ�*/
API BOOL32  ClearSnapShotFile();

/*����Map����*/
API BOOL32  SetMapSleep(u32 dwMapId);
/*����Map����*/
API BOOL32  SetMapWakeup(u32 dwMapId);

/*����Map�����Ļص�*/
API void SetMapRebootCallBack(REBOOTCALLBACK pRebootProc);
/*����PAL��NTSC��ʽ�ı���Ϣ֪ͨ*/
API void SetNtscPalChangeCallBack(CHANGECALLBACK pChangeProc);
API int McSwitch(BOOL32 bEnterMc);	//�л�mc״̬
API int SetMcPicMergeParam(u8 abyMergeParam[]);	//����mc״̬ʱ��ͼ��ϳɲ���
API int SetMcAudDecType(BOOL bMixer, u8 byMcAudDecMask);	//����mc״̬ʱ��Ƶ����·��
API int SetVideoSendPacketLen(s32 dwMaxLen);

#ifndef TOSFUNC
#define TOSFUNC
//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API	int SetMediaTOS(int nTOS, int nType);
API	int GetMediaTOS(int nType);
#endif

#else

//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API	int SetMediaTOS(int nTOS, int nType);
API	int GetMediaTOS(int nType);

API void SetResendDrop(u32 dwInterval, u32 dwRatio);

#endif /* HARD_CODEC */

#endif /*__CODECLIB_H*/
















