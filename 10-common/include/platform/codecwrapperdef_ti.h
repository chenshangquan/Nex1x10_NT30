/*****************************************************************************
  ģ����      : Codecwrapper.a
  �ļ���      : codecwrapperdef_ti.h
  ����ļ�    : codecwrapper_ti.h
  �ļ�ʵ�ֹ���: 
  ����        : ������
  �汾        : V1.0  Copyright(C) 1997-2006 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2006/12/13  1.0         ������      ����
******************************************************************************/
#ifndef _CODECWRAPPER_DEF_TI_H_
#define _CODECWRAPPER_DEF_TI_H_

//CPU��ʶ
#define CWTI_CPUMASK_MAIN   0x00000001
#define CWTI_CPUMASK_SUB    0x00000002
#define CWTI_CPUMASK_ALL    0x00000003

//������
#define ERROR_CODE_BASE             30000             
#define CODEC_NO_ERROR              0//�޴�

#include "kdvtype.h"
#include "osp.h"
#include "kdvmedianet.h"

enum enCodecErr
{
	Codec_Success = CODEC_NO_ERROR,

	Codec_Error_Base = ERROR_CODE_BASE,
	Codec_Error_Param,
	Codec_Error_CPUMask,
	Codec_Error_Video_NO_Create,
	Codec_Error_Audio_NO_Create,
	Codec_Error_Audio_CapInstance,
	Codec_Error_Audio_PlyInstance,
	Codec_Error_Video_CapInstance,
	Codec_Error_Video_PlyInstance,
	Codec_Error_Audio_CapInit,
	Codec_Error_Audio_PlyInit,
	Codec_Error_Video_CapInit,
	Codec_Error_Video_PlyInit,
	Codec_Error_GetCMem,
	Codec_Error_GetMem,
	Codec_Error_Not_Start_Send
};

#define CODECMAXCHANNELNUM         10
#define MAX_VIDENC_CHANNEL         CODECMAXCHANNELNUM
#define MAX_VIDDEC_CHANNEL         CODECMAXCHANNELNUM
#define MAX_AUDENC_CHANNEL         CODECMAXCHANNELNUM
#define MAX_AUDDEC_CHANNEL         CODECMAXCHANNELNUM

//�ɼ�����
#define  VIDCAP_CAPVIDEO			(u8)1	//�ɼ�video
#define  VIDCAP_CAPVGA				(u8)2	//�ɼ�vga

/*������ʾ��ʽ*/
#define DISPLAY_TYPE_PAL      (u8)0x1 /*PAL video*/
#define DISPLAY_TYPE_NTSC     (u8)0x2 /*NTSC video*/
#define DISPLAY_TYPE_VGA      (u8)0x3 /*VGA*/

/*ͼ����ʽ*/
#define	 VID_ENC_USEPAL		 (u8)0x21     /*PAL��ʽ*/
#define	 VID_ENC_USENTSC	 (u8)0x22     /*NTSC��ʽ*/

/*���л���ʾ��ʽ*/
#define	PIP_LOCAL_IN_REMOTE	     (u8)0x0 /*����ΪС���棬Զ��Ϊ����*/
#define	PIP_REMOTE_IN_LOCAL	     (u8)0x1 /*Զ��ΪС���棬����Ϊ����*/
#define	PIP_LOCAL_ONLY		     (u8)0x2 /*����ʾ���ػ���*/
#define	PIP_REMOTE_ONLY		     (u8)0x3 /*����ʾԶ�˻���*/
#define	PIP_LITTLE_PIC	         (u8)0x4 /*��ʾ����С����*/
#define	PIP_LEFT_AND_RIGHT       (u8)0x5 /*���������棬һ���룬һ����*/
#define	PIP_THREE_PIC            (u8)0x6 /*������*/
#define	PIP_SECOND_IN_MAIN	     (u8)0x7 /*����ΪС���棬Զ��Ϊ����*/
#define	PIP_MAIN_IN_SECOND	     (u8)0x8 /*Զ��ΪС���棬����Ϊ����*/
#define	PIP_LEFT_AND_RIGHT_DB    (u8)0x9 /*���������� ˫��ʱ����������*/
//MC ���������
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

//����ϳ�����
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


//Audio mode
enum
{
	AUDIO_MODE_PCMA = 5,
	AUDIO_MODE_PCMU,
	AUDIO_MODE_G723_6,
	AUDIO_MODE_G723_5,
	AUDIO_MODE_G728,
	AUDIO_MODE_G722,
	AUDIO_MODE_G729,
	AUDIO_MODE_G7221,
	AUDIO_MODE_ADPCM 
};


/* �����������*/
enum
{
	VID_DROP_PREFERRED_QUALITY   =   0, 
	VID_DROP_PREFERRED_FAST_SPEED,   
	VID_DROP_PREFERRED_MID_SPEED,
	VID_DROP_PREFERRED_SLOW_SPEED
};

const u32 con_horizontal = 0;
const u32 con_vertical   = 1;

/*ͼ�����*/
enum
{
	VIDCAP_SCALE_BRIGHTNESS = 0 ,
	VIDCAP_SCALE_CONTRAST  ,
	VIDCAP_SCALE_SATURATION
};

enum
{
	CPUTYPE_MASTER_ARM = 0,
	CPUTYPE_MASTER_DSP = 1,
	CPUTYPE_SLAVE_ARM  = 2,
	CPUTYPE_SLAVE_DSP  = 3
};

//�ӿڽṹ
typedef struct tagCodecInit
{
	u32 m_dwCpuMask;
	u32 m_dwVlynqChannel;  //ֻ��ʹ����Slave��ʼ�������õ�ID�ã�0��Max��1��
	s32 m_bUserMC;         //�Ƿ�ʹ��MC��ֻ����Ƶ��������Ч

	BOOL32 m_bMasterUseAec;       //��Ƶ����ʱָ�����豸�Ƿ�ʹ��Aec
}
TEncoder, TDecoder;

typedef struct tagSlaveInit
{
	u32  m_wVidEncNum;    //�ӻ���Ƶ����������
	u32  m_wVidDecNum;    //�ӻ���Ƶ����������
	u32  m_wAudEncNum;    //�ӻ���Ƶ����������
	u32  m_wAudDecNum;    //�ӻ���Ƶ����������
	BOOL32 m_bUseOsd;     //�ӻ����Ƿ���ʾOSD
	BOOL32 m_bUseMC;      //�Ƿ����ն���ǶMC����
	BOOL32 m_bHasFXO;     //�Ƿ�ʹ��FXO
}
TSlaveInit;

typedef struct tagTMasterInit
{
	u32  m_wVidEncNum;    //������Ƶ����������
	u32  m_wVidDecNum;    //������Ƶ����������
	BOOL m_bD1Splite;

	BOOL m_bAudMaster;   //�����ϴ�����Ƶ�����
}TMasterInit,*PTMasterInit;

typedef struct
{
	u32 dwFrmType;				//0:���̶�����, 1: half cif, 2: 1 cif, 3: 2 cif,  4: 4 cif,  5: ����ͼ��ϳɱ���
	u32 dwFrameRate;				//֡��
	u32 dwIFrmInterval;				//I֡���
	u32 dwBitRate;					//����
	BOOL32 bFrmRateLittleThanOne;	//����֡��С��1 ?
	BOOL32 bFramRateCanSet;			//����֡���Ƿ����ⲿ�趨? 1:�ǣ�0����
	BOOL32 bAutoDelFrame;			//�������Ƿ��Զ���֡1���ǣ�0����				
}TMpv4FrmParam;

//����ն����˶����
//������������
typedef struct tagDetectRect
{
	u32  dwXPos;//������򶥵������
	u32  dwYPos;//������򶥵�������
	u32  dwWidth;//���������
	u32  dwHeigth;//�������߶�
}TDetectRect;

//�ƶ��������ṹ
typedef struct tagMoveDetectParam
{
	BOOL32		bDetectEnable;//���ʹ��
	TDetectRect tDetectRect;  // �������
	u8			byAlarmRate;//�������澯�����ٷֱȣ����ڴ��ٽ�ֵ�澯,0-100��
	u8			byResumeRate;//�����澯���˶���Χ�ٷֱ�С�ڸ�ֵ��ָ��澯(��ֵС��byAlarmRate,0-100)
}TMoveDetectParam;

typedef struct tagMosaic
{
    BOOL32  bEnable;        //�Ƿ�ʹ��������
	u32     dwXPos;//���������� 4cif���㶥�������
	u32     dwYPos;//����������
	u32     dwWidth;//���
	u32     dwHeigth;//�߶�
    u32     dwGranularity;  //�����˿���
} TMosaic;

//�ƶ��ص������ṹ
typedef struct tagMoveCBParam
{
	BOOL32		bMoveAlarm;//�澯��ָ�
	//TDetectRect tDetectRect;//�������
    u32			dwAlarmRectNum;
}TMoveCBParam;

/*��Ƶ�������*/
typedef struct VideoEncParam
{
	u8    m_byEncType;   /*ͼ���������*/
    u8    m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/    
	u8    m_byMaxQuant;  /*�����������(1-31)*/
    u8    m_byMinQuant;  /*��С��������(1-31)*/

    u16   m_byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u16   m_wBitRate;    /*���������(Kbps)*/

	u32   m_dwSndNetBand;/*���緢�ʹ���(��λ:Kbps,1K=1024)*/   

	u8    m_byPalNtsc;    /*ͼ����ʽ(PAL��NTSC)*/	
	u8    m_byCapPort;    /*�ɼ��˿ں�: 1~7��Ч����KDV8010�ϣ�S���Ӷ˿ں�Ϊ7��C���Ӷ˿ں�ȱʡΪ2*/
	u8	  m_byFrameRate;  /*֡��(default:25)*/	
	u8    m_byImageQulity;/*ͼ��ѹ������,0:�ٶ�����;1:һ��;2:��������*/

	u16   m_wVideoWidth;  /*ͼ����(default:352)*/
	u16	  m_wVideoHeight; /*ͼ��߶�(default:288)*/

	u8  m_byFrameFmt; // �ֱ��� 0:���̶�����, 1: half cif, 2: 1 cif, 3: 2 cif,  4: 4 cif,  5: ����ͼ��ϳɱ���  
	u8	m_byFrmRateCanSet; //֡���Ƿ�������趨 ?
	u8  m_byFrmRateLittleThanOne; // ֡���Ƿ�С��1 ?
	u8  m_byReserved1;  /*����*/
//	u8  m_byAutoDelFrm;			//�������Ƿ��Զ���֡ ?�������ã�����ֻ��Quality����
}TVideoEncParam;

/*������״̬*/
typedef struct KdvEncStatus
{
	BOOL32 			m_bVideoSignal;			/*�Ƿ�����Ƶ�ź�*/
	BOOL32	        m_bVideoCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioCapStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bVideoEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bAudioEncStart; /*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32			m_bNetSndAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	u32				m_dwVideoBufLen;  /*��Ƶ���峤��*/
	u32				m_dwAudioBufLen;  /*��Ƶ���峤��*/ 
	TVideoEncParam	m_tVideoEncParam; /*��Ƶ�������*/
	u8				m_byAudioEncParam;/*��Ƶ����ģʽ*/
	u8				m_byAudEncMediaType; /*��Ƶ����ý������*/	
	TNetSndParam    m_tVideoSendAddr; /*��Ƶ���͵�ַ*/
	TNetSndParam    m_tAudioSendAddr; /*��Ƶ���͵�ַ*/
	u32				m_dwVideoMapHeartBeat;
	u32				m_dwAudioMapHeartBeat;  
	
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

typedef struct VideoDisplayParam
{
	u8    m_byPIPMode;   /*���л���ʾ��ʽ*/
	u8    m_bySaturation;/*��ʾ���Ͷ�*/
	u8    m_byContrast;  /*��ʾ�Աȶ�*/
	u8    m_byBrightness;/*��ʾ����*/
	u16   m_dwPIPXPos;   /*���л�X����*/
	u16   m_dwPIPYPos;   /*���л�Y����*/
	u16   m_dwPIPWidth;  /*���л����*/
	u16   m_dwPIPHeight; /*���л��߶�*/    
	u32   m_dwPlayMode;   //��ʾģʽ��1-PAL��ʾ��2-NTSC��ʾ��3-VGA��ʾ
}TVideoDisplayParam;


/*������״̬*/
typedef struct KdvDecStatus
{
	BOOL32	m_bVideoDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bAudioDecStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvVideoStart;/*�Ƿ�ʼ��Ƶ����*/
	BOOL32	m_bRcvAudioStart;/*�Ƿ�ʼ��Ƶ����*/
	u32		m_dwAudioBufLen; /*��Ƶ���Ż��峤��*/
	u32		m_dwVideoBufLen; /*��Ƶ���Ż��峤��*/
	TLocalNetParam   m_tAudioRcvAddr;/*��Ƶ���ص�ַ*/
	TLocalNetParam   m_tVideoRcvAddr;/*��Ƶ���ص�ַ*/
    
	u32   m_dwVideoMapHeartBeat;//ͼ�����Map����
	u32   m_dwAudioMapHeartBeat;//��������Map����
	TVideoDisplayParam m_tVideoDisplayParam;//ͼ����ʾ����  
	
	u32   m_dwAudioDecType;     //��Ƶ��������
	u32   m_dwVideoDecType;     //��Ƶ��������
}TKdvDecStatus;

/*������ͳ����Ϣ*/
typedef struct KdvDecStatis
{
	u8	  m_byVideoFrameRate;/*��Ƶ����֡��*/
	u16	  m_wVideoBitRate;   /*��Ƶ��������*/
	u16	  m_wAudioBitRate;   /*������������*/
	u32   m_dwVideoRecvFrame;/*�յ�����Ƶ֡��*/
	u32   m_dwAudioRecvFrame;/*�յ�������֡��*/
	u32   m_dwVideoLoseFrame;/*��ʧ����Ƶ֡��*/
	u32   m_dwAudioLoseFrame;/*��ʧ������֡��*/
    u16   m_wVideoLoseRatio;//��Ƶ��ʧ��,��λ��% 	
	u16   m_wAudioLoseRatio;//��Ƶ��ʧ��,��λ��% 	
	u32   m_dwPackError;/*��֡��*/ 
	u32   m_dwIndexLose;/*��Ŷ�֡*/
	u32   m_dwSizeLose; /*��С��֡*/
	u32   m_dwFullLose; /*����֡*/	
	u32   m_wAvrVideoBitRate;   /*1��������Ƶ����ƽ������*/
	u32	  m_wAvrAudioBitRate;   /*1��������������ƽ������*/
	BOOL32 m_bVidCompellingIFrm;  /*��Ƶǿ������I֡*/								  
	u32   m_dwDecdWidth;	/*�����Ŀ�*/
	u32   m_dwDecdHeight;   /*�����ĸ�*/
}TKdvDecStatis;

/* ͼ���������ṹ */
typedef struct
{
    u32 dwStartRecvBufs;         // ��ʼ����buffer��
    u32 dwFastRecvBufs;         // ����buffer��
	u32 dwPostPrcLvl;			// mpv4����ļ���		
}TVideoDecParam;


/*�澯��Ϣ*/
typedef struct AlarmInfo
{
	BOOL32 m_bMap0Halt;
	BOOL32 m_bMap1Halt;
	BOOL32 m_bMap2Halt;
	u32    m_dwMap0HaltTimes;         //Map0��������
	u32    m_dwMap1HaltTimes;         //Map1��������
	u32    m_dwMap2HaltTimes;         //Map2��������
	BOOL32 m_bNoVideoInput;
	BOOL32 m_bRecVideoNoBitStream;
	BOOL32 m_bRecAudioNoBitStream;
    BOOL32 m_bSendVideoLoseFrame;
    BOOL32 m_bSendAudioLoseFrame;
}TAlarmInfo;

typedef struct tagNetRSParam
{
    u16  m_wFirstTimeSpan;	  //��һ���ش�����
	u16  m_wSecondTimeSpan;  //�ڶ����ش�����
	u16  m_wThirdTimeSpan;   //�������ش�����
	u16  m_wRejectTimeSpan;  //���ڶ�����ʱ����
} TNetRSParam;

typedef struct BackBGDColor
{
	u8 RColor;    //R����
	u8 GColor;    //G����
	u8 BColor;    //B����	
}TBackBGDColor;

typedef TBackBGDColor TBGColor;

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
	u32 dwHaltTime;//ͣ��ʱ��(��)�����¹���ʱ��ÿ����һ���ֵ�ͣ�ټ����0ʼ��ͣ�����뾲ֹ��ͬ�� 
}TAddBannerParam;

typedef TAddBannerParam TDynimicPicInfo;

#define SPEED_FAST 8
#define SPEED_HIGH 6
#define SPEED_NORM 4
#define SPEED_LOW  2

#define UPDWON     1
#define LEFTRIGHT  2
#define STATIC     3

const u32 dwUpDownStep    = 16;
const u32 dwLeftRightStep = 16;


const u8  byOsdProcess_Priority  = 5;
const u32 dwOsdProcess_Stacksize = 0;
const u16  wOsdProcess_Flag      = 0;

const u8  byAllTransparent = 0x00; 
const u8  byNoneTransparent = 0xFF;
const u32 dwOsdDelayTimes = 100;

const u32 dwOsdBackgroudSize = 720 * 288 * 2;

typedef void ( *TMotionAlarmInfo)(u32 dwPort,TMoveCBParam *ptMoveCBParam,u32 dwAreaNum,u32 dwContext);
typedef void ( *TDecodeVideoScaleInfo)(u16 wVideoWidth, u16 wVideoHeight);
typedef void ( *TDebugCallBack )(char *pbyBuf, int dwBufLen);
typedef void ( *CHANGECALLBACK)();
typedef void ( *CpuResetNotify)(s32 nCpuType);  //CPUTYPE_MASTER_ARM ��
typedef void ( *MsgFromSlave)(u32 dwID, void* pBuf, u32 dwBufSize); 
#endif
