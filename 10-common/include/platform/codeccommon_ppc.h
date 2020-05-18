/*****************************************************************************
   ģ����      : 
   �ļ���      : CodecCommon.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: ͨ�ö��塣
   ����        : ��ѩ��
   �汾        : V3.0  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���         �޸�����
   2004/02/07  3.0         ��ѩ��           ����
******************************************************************************/
#ifndef __COMMON_H_
#define __COMMON_H_

#define CODECVERSION               "CodecWrapper 40.10.05.74.060518"

typedef struct BackBGDColor
{
	u8 RColor;    //R����
	u8 GColor;    //G����
	u8 BColor;    //B����	
}TBackBGDColor;

typedef struct tagNetRSParam
{
    u16  m_wFirstTimeSpan;	  //��һ���ش�����
	u16  m_wSecondTimeSpan;  //�ڶ����ش�����
	u16  m_wThirdTimeSpan;   //�������ش�����
	u16  m_wRejectTimeSpan;  //���ڶ�����ʱ����
} TNetRSParam;

/*==================================������=======================*/

#ifndef DES_ENCRYPT_MODE
#define DES_ENCRYPT_MODE         (u8)0      //DES����ģʽ
#define AES_ENCRYPT_MODE         (u8)1      //AES����ģʽ
#define ENCRYPT_KEY_SIZE         (u8)32     //��Կ���� ȡ���еĽϴ�ֵ
#define DES_ENCRYPT_KEY_SIZE     (u8)8      //DES��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_A (u8)16  //AES Mode-A ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_B (u8)24  //AES Mode-B ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_C (u8)32  //AES Mode-C ��Կ����
#endif

#ifdef SOFT_CODEC
#define CODEC_NO_ERROR              (u16)0//�޴�
#define CODEC_ERROR_BASE            (u16)10000//
#define ERROR_CODEC_UNKNOWN	        (u16)10000//��֪���ı���������� 
#define ERROR_CODEC_PARAM           (u16)(CODEC_ERROR_BASE + 1)//��������;  
#define ERROR_DEC_DRAW_HDC	        (u16)(CODEC_ERROR_BASE + 2)//��������ͼ����DC����
#define ERROR_DEC_DRAW_DIBOPEN      (u16)(CODEC_ERROR_BASE + 3)//��������ͼ����򿪴���
#define ERROR_DEC_DRAW_DIBBEGIN     (u16)(CODEC_ERROR_BASE + 4)//��������ͼ��ʽ����
#define ERROR_DEC_DRAW_CLEARWINDOW  (u16)(CODEC_ERROR_BASE + 5)//��������������
#define ERROR_DEC_ICOPEN            (u16)(CODEC_ERROR_BASE + 6)//�������򿪽�����������
#define ERROR_DEC_DECOMPRESSBEGIN   (u16)(CODEC_ERROR_BASE + 7)//���������ý���������ʽ����
#define ERROR_DEC_SETTIMER          (u16)(CODEC_ERROR_BASE + 8)//���������ý��붨ʱ������
#define ERROR_DEC_NO_VIDEO          (u16)(CODEC_ERROR_BASE + 9)//������û�д�����Ƶ
#define ERROR_DEC_SOCKET_CALLBACK   (u16)(CODEC_ERROR_BASE + 10)//���������������¼��ص�����
#define ERROR_DEC_SOCKET_CREATE     (u16)(CODEC_ERROR_BASE + 11)//���������������׽��ִ���
#define ERROR_DEC_NO_AUDIO          (u16)(CODEC_ERROR_BASE + 12)//������û�д�����Ƶ 
#define ERROR_DEC_WAVEOPEN          (u16)(CODEC_ERROR_BASE + 13)//���������ܴ�����*
#define ERROR_DEC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 14)//���������ܴ�������������
#define ERROR_DEC_WAVEPREHEADER     (u16)(CODEC_ERROR_BASE + 15)//����������������Ƶ����ͷ
#define ERROR_DEC_WAVEWRITE         (u16)(CODEC_ERROR_BASE + 16)//����������������д��Ƶ����
#define ERROR_DEC_WAVE_ENCOPEN      (u16)(CODEC_ERROR_BASE + 17)//���������ܴ���Ƶ������*
#define ERROR_DEC_WAVE_ENCPREHEADER (u16)(CODEC_ERROR_BASE + 18)//����������������Ƶ����ͷ
#define ERROR_DEC_WAVE_ENCCONVERT   (u16)(CODEC_ERROR_BASE + 19)//��������Ƶ�������
#define ERROR_DEC_WAVESTART         (u16)(CODEC_ERROR_BASE + 20)//��������ʼ��Ƶ���Ŵ���
#define ERROR_DEC_WAVESTOP          (u16)(CODEC_ERROR_BASE + 21)//������ֹͣ��Ƶ���Ŵ���
#define ERROR_DEC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 22)//������������������
#define ERROR_DEC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 23)//��������ȡ��������
#define ERROR_DEC_MIXERMUTE         (u16)(CODEC_ERROR_BASE + 24)//���������þ�������
#define ERROR_DEC_AUDIOOUT_EXIT     (u16)(CODEC_ERROR_BASE + 25)//��������Ƶ�߳��˳�����
#define ERROR_DEC_HARDCREATE        (u16)(CODEC_ERROR_BASE + 26)//����������Ӳ��������ʧ��
#define ERROR_DEC_CREATE            (u16)(CODEC_ERROR_BASE + 27)//�������������� 
#define ERROR_DEC_NEW               (u16)(CODEC_ERROR_BASE + 28)//�������ɳ���
#define ERROR_DEC_SETAUDIO_ADDR     (u16)(CODEC_ERROR_BASE + 29)//������������Ƶ��ַ����  
#define ERROR_DEC_AUDIO_LEN         (u16)(CODEC_ERROR_BASE + 30)//��Ƶ���������ݳ��Ȳ���ȷ
#define ERROR_DEC_NO_MASK           (u16)(CODEC_ERROR_BASE + 31)//�Ȳ����������Ҳ����Ӳ������
#define ERROR_SOCKOBJ_NULL          (u16)(CODEC_ERROR_BASE + 32)//������ն��󲻴���
#define ERROR_DEC_NET_INVALIDPARAM  (u16)(CODEC_ERROR_BASE + 33)//��Ч��������ղ��� 
#define EROOR_DEC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 34)//�˹��ܻ���֧�� 
#define ERROR_DEC_SETSTATE          (u16)(CODEC_ERROR_BASE + 35)//���������ý�������״̬����

#define ERROR_ENC_CAPWIN            (u16)(CODEC_ERROR_BASE + 100)//�������������񴰿ڳ���
#define ERROR_ENC_CAPDRIVER         (u16)(CODEC_ERROR_BASE + 101)//������û�з��ֲ���
#define ERROR_ENC_DIBOPEN           (u16)(CODEC_ERROR_BASE + 102)//��������ͼ����򿪴���
#define ERROR_ENC_DRAWHDC           (u16)(CODEC_ERROR_BASE + 103)//��������ͼ���ڴ򲻿�
#define ERROR_ENC_ICOPEN            (u16)(CODEC_ERROR_BASE + 104)//�������������򿪳���
#define ERROR_ENC_DRAWPOS           (u16)(CODEC_ERROR_BASE + 105)//�������õ���ͼλ�ó���
#define ERROR_ENC_DIBBEGIN          (u16)(CODEC_ERROR_BASE + 106)//���������û�ͼ��ʽ����
#define ERROR_ENC_GET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 107)//�������õ�ͼ���ʽ����
#define ERROR_ENC_SET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 108)//����������ͼ���ʽ����
#define ERROR_ENC_GET_CAPSET        (u16)(CODEC_ERROR_BASE + 109)//�������õ��������ó���
#define ERROR_ENC_SET_CAPSET        (u16)(CODEC_ERROR_BASE + 110)//���������ò������ó���
#define ERROR_ENC_SET_AUDIOFORMATE  (u16)(CODEC_ERROR_BASE + 111)//������������Ƶ�����ʽ����
#define ERROR_ENC_STREAMOPEN        (u16)(CODEC_ERROR_BASE + 112)//����������Ƶ����������
#define ERROR_ENC_PREHEADER         (u16)(CODEC_ERROR_BASE + 113)//������׼����Ƶ����ͷ����
#define ERROR_ENC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 114)//�������������������������
#define ERROR_ENC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 115)//������������������
#define ERROR_ENC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 116)//�������õ���������
#define ERROR_ENC_ALREADY           (u16)(CODEC_ERROR_BASE + 117)//������״̬�Ѿ�����
#define ERROR_ENC_STOPCAP           (u16)(CODEC_ERROR_BASE + 118)//�������޷�ֹͣ����
#define ERROR_ENC_SETSTATE          (u16)(CODEC_ERROR_BASE + 119)//���������ñ����������
#define ERROR_ENC_ENCBEGIN          (u16)(CODEC_ERROR_BASE + 120)//���������ñ���֡��ʽ
#define ERROR_ENC_SETTIMER          (u16)(CODEC_ERROR_BASE + 121)//���������ö�ʱ������
#define ERROR_ENC_STOPVIDEOENC      (u16)(CODEC_ERROR_BASE + 122)//������ֹͣ��Ƶ�������
#define ERROR_ENC_NO_SETPARAM       (u16)(CODEC_ERROR_BASE + 123)//������û�����ò���
#define ERROR_ENC_STOPAUDIOENC      (u16)(CODEC_ERROR_BASE + 124)//��������Ƶ�������
#define ERROR_ENC_CREATESOCK        (u16)(CODEC_ERROR_BASE + 125)//���������õ��ص�ַ����
#define ERROR_ENC_STOPSENDVIDEO     (u16)(CODEC_ERROR_BASE + 126)//������ֹͣ������Ƶ����
#define ERROR_ENC_STOPSENDAUDIO     (u16)(CODEC_ERROR_BASE + 127)//������ֹͣ������Ƶ����
#define ERROR_ENC_AUDIOENC          (u16)(CODEC_ERROR_BASE + 128)//��������Ƶת������
#define ERROR_ENC_NO_CREATE         (u16)(CODEC_ERROR_BASE + 129)//�������������ɹ�  
#define ERROR_ENC_SOCK_INIT         (u16)(CODEC_ERROR_BASE + 130)//�����������׽��ֲ���2.2��
#define ERROR_ENC_STARTCAP          (u16)(CODEC_ERROR_BASE + 131)//�������޷���ʼ����
#define ERROR_ENC_CAP_WIDTH         (u16)(CODEC_ERROR_BASE + 132)//����������̫֡��
#define ERROR_DRAW_FORMATE          (u16)(CODEC_ERROR_BASE + 133)//��ͼ��ʽ��֧��
#define ERROR_HARDENC_FORMATE       (u16)(CODEC_ERROR_BASE + 134)//Ӳ����֧�ֵĻ�ͼ��ʽ
#define ERROR_ENC_CAP_FORMATE       (u16)(CODEC_ERROR_BASE + 135)//�ɼ���ʽ�ͱ����ʽ��ƥ��
#define ERROR_ENC_NEW               (u16)(CODEC_ERROR_BASE + 136)//�������ɳ���
#define ERROR_ENC_INVALID_PARAM     (u16)(CODEC_ERROR_BASE + 137)//��Ч�Ĳ���
#define ERROR_ENC_CREATE_EVENT      (u16)(CODEC_ERROR_BASE + 138)//���ܴ����¼� 
#define EROOR_ENC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 139)//�˹��ܻ���֧�� 
#define ERROR_ENC_GETSTATE          (u16)(CODEC_ERROR_BASE + 140)//�������õ������������
#define ERROR_DECENC_CREATE_THREAD  (u16)(CODEC_ERROR_BASE + 141)//���ܴ����߳�

#define ERROR_ENC_CAP_DESKTOP_FORMAT    (u16)(CODEC_ERROR_BASE + 142)//Ҫ��ı��������沶���ʽ����֧��
#define ERROR_ENC_CREATE_DESKTOP_MEMDC  (u16)(CODEC_ERROR_BASE + 143)//���������ڴ�dcʧ��
#define ERROR_ENC_CAP_DESKTOP_WIDTH     (u16)(CODEC_ERROR_BASE + 144)//��������������ֱ��ʸ��ڵ�ǰ����ʵ�ʷֱ���
#define ERROR_ENC_CAP_DESKTOP_BITCOUNT  (u16)(CODEC_ERROR_BASE + 145)//��������������λ����ڵ�ǰ����ʵ��λ��
#define ERROR_ENC_INVILAD_FILE      (u16)(CODEC_ERROR_BASE + 146)//�ṩ���ļ���Ч
#define ERROR_ENC_OPERATE_FILE     (u16)(CODEC_ERROR_BASE + 147)//�ļ���������ָ�����ļ�����ʧ��
#endif

#ifdef HARD_CODEC
#define ERROR_CODE_BASE             30000             
#define CODEC_NO_ERROR              (u16)0//�޴�
#define MAP_OPERATE_SUCCESS         (u16)0 /*MAP�����ɹ�*/

#define MAP_OPEN_FAILURE            (u16)(ERROR_CODE_BASE+1)/*MAP��ʧ��*/
#define MAP_DOWNFILE_FAILURE        (u16)(ERROR_CODE_BASE+2)/*MAP��������ʧ��*/
#define MAP_RUNAPP_FAILURE          (u16)(ERROR_CODE_BASE+3)/*MAP���г���ʧ��*/
#define MAP_OPENMSG_FAILURE         (u16)(ERROR_CODE_BASE+4)/*����Ϣͨ��ʧ��*/
#define MAP_CCI_FAILURE             (u16)(ERROR_CODE_BASE+5)/*CCIͨѶʧ��*/
#define MAP_CCI_PEER_CLOSED         (u16)(ERROR_CODE_BASE+6)/*CCI��ȡʧ��*/
#define MAP_CCI_NOT_CONNECTED       (u16)(ERROR_CODE_BASE+7)/*CCIδ����*/
#define MAP_CCI_SMEM_CORRUPT        (u16)(ERROR_CODE_BASE+8)/*CCI�ڴ���*/
#define MAP_CCI_LENGTH_ERROR        (u16)(ERROR_CODE_BASE+9)/*CCI���ȴ���*/
#define MAP_CCI_QUEUE_FULL          (u16)(ERROR_CODE_BASE+10)/*CCI������*/
#define MAP_CCI_MSG_LOST            (u16)(ERROR_CODE_BASE+11)/*CCI��Ϣ��ʧ*/
#define MAP_CCI_NOT_INIT            (u16)(ERROR_CODE_BASE+12)/*CCIδ��ʼ��*/
#define MAP_CCI_UNKNOWN_ERROR       (u16)(ERROR_CODE_BASE+13)/*CCIδ֪����*/
#define MAP_NOT_READY               (u16)(ERROR_CODE_BASE+14)/*MAPδ׼����*/
#define MAP_READ_SDRAM_FAIL         (u16)(ERROR_CODE_BASE+15)/*��MAP�ڴ�ʧ��*/
#define MAP_WRITE_SDRAM_FAIL        (u16)(ERROR_CODE_BASE+16)/*дMAP�ڴ�ʧ��*/

#define DECODER_OPERATE_SUCCESS     (u16)0/*����ɹ�����*/
#define DECODER_ALL_NOT_INIT        (u16)(ERROR_CODE_BASE+1001)/*������δ��ʼ��*/
#define DECODER_VIDEO_NOT_INIT      (u16)(ERROR_CODE_BASE+1002)/*��Ƶ������δ��ʼ��*/
#define DECODER_AUDIO_NOT_INIT      (u16)(ERROR_CODE_BASE+1003)/*����������δ��ʼ��*/
#define DECODER_VIDEO_TYPE_UNSPT    (u16)(ERROR_CODE_BASE+1004)/*��Ƶ���������Ͳ�֧��*/
#define DECODER_AUDIO_TYPE_UNSPT    (u16)(ERROR_CODE_BASE+1005)/*��Ƶ���������Ͳ�֧��*/
#define DECODER_ILLEGAL_MAPID       (u16)(ERROR_CODE_BASE+1006)/*MapId�Ƿ�*/
#define DECODER_VIDEO_INIT_FAIL     (u16)(ERROR_CODE_BASE+1007)/*��Ƶ��������ʼ��ʧ��*/
#define DECODER_AUDIO_INIT_FAIL     (u16)(ERROR_CODE_BASE+1008)/*��Ƶ��������ʼ��ʧ��*/
#define DECODER_SNAPSHOT_FAIL_H261  (u16)(ERROR_CODE_BASE+1009)/*h261���ղ�֧��*/

#define ENCODER_OPERATE_SUCCESS     (u16)0/*����ɹ�����*/
#define ENCODER_ALL_NOT_INIT        (u16)(ERROR_CODE_BASE+2001)/*������δ��ʼ��*/
#define ENCODER_VIDEO_NOT_INIT      (u16)(ERROR_CODE_BASE+2002)/*��Ƶ������δ��ʼ��*/
#define ENCODER_AUDIO_NOT_INIT      (u16)(ERROR_CODE_BASE+2003)/*����������δ��ʼ��*/
#define ENCODER_VIDEO_TYPE_UNSPT    (u16)(ERROR_CODE_BASE+2004)/*��Ƶ���������Ͳ�֧��*/
#define ENCODER_AUDIO_TYPE_UNSPT    (u16)(ERROR_CODE_BASE+2005)/*��Ƶ���������Ͳ�֧��*/
#define ENCODER_VIDEO_FRMTYPE_UNSPT (u16)(ERROR_CODE_BASE+2006)/*��Ƶ֡��ʽ��֧��*/
#define ENCODER_RTPHEADLEN_ERROR    (u16)(ERROR_CODE_BASE+2007)/*RTPͷ���ȴ�*/
#define ENCODER_ILLEGAL_MAPID       (u16)(ERROR_CODE_BASE+2008)/*MapId�Ƿ�*/
#define ENCODER_VIDEO_INIT_FAIL     (u16)(ERROR_CODE_BASE+2009)/*��Ƶ��������ʼ��ʧ��*/
#define ENCODER_AUDIO_INIT_FAIL     (u16)(ERROR_CODE_BASE+2010)/*��Ƶ��������ʼ��ʧ��*/
#define ENCODER_OTHER_LIB_ERR		(u16)(ERROR_CODE_BASE+2011)/*������Ĵ���*/ 
#define ENCODER_SNAPSHOT_FAIL_H261  (u16)(ERROR_CODE_BASE+2012)/*h261���ղ�֧��*/

#define SENDER_NOT_INIT             (u16)(ERROR_CODE_BASE+3003)/*����ģ��δ��ʼ��*/
#define RECEIVER_NOT_INIT           (u16)(ERROR_CODE_BASE+3004)/*����ģ��δ��ʼ��*/
#define PARAMETER_ERROR             (u16)(ERROR_CODE_BASE+3005)/*��������*/
#define HARDCODEC_NOT_INIT          (u16)(ERROR_CODE_BASE+3006)/*�������δ��ʼ��*/
#define HARDCODEC_INIT_FAIL         (u16)(ERROR_CODE_BASE+3007)/*���������ʼ��ʧ��*/
#define MAGIC_NUMBER_ERROR          (u16)(ERROR_CODE_BASE+3008)/*��δ����*/

#define MIXER_OPERATE_SUCCESS       (u16)0         /*���ܻ����������ɹ�*/

#define MIXER_NOT_INIT              (u16)(ERROR_CODE_BASE+4001)/*����������δ��ʼ��*/
#define MIXER_CHANNEL_INUSE         (u16)(ERROR_CODE_BASE+4002)/*ͨ����ʹ��*/
#define MIXER_CHANNEL_INIDLE        (u16)(ERROR_CODE_BASE+4003)/*ͨ����δʹ��*/
#define MIXER_SENDER_NOT_INIT       (u16)(ERROR_CODE_BASE+4004)/*����ģ��δ��ʼ��*/
#define MIXER_RECEIVER_NOT_INIT     (u16)(ERROR_CODE_BASE+4005)/*����ģ��δ��ʼ��*/
#define MIXER_START_NO_CHANNEL      (u16)(ERROR_CODE_BASE+4006)/*û��ͨ���Ϳ�ʼ����*/
#define MIXER_GROUP_FULL            (u16)(ERROR_CODE_BASE+4007)/*����*/ 
#define MIXER_CHANNEL_INVALID       (u16)(ERROR_CODE_BASE+4008)/*��Ч�����*/ 
#define MIXER_NO_FORCEMIX_CHANNEL   (u16)(ERROR_CODE_BASE+4009)/*û��ǿ�ƻ�����ͨ��*/
#define MIXER_PARAM_ERROR			(u16)(ERROR_CODE_BASE+4010)/*������*/

#define ADAPTER_NOT_INIT            (u16)(ERROR_CODE_BASE+5001)/*������δ����*/

#define PICMERGER_NOT_INIT          (u16)(ERROR_CODE_BASE+6001)/*ͼ��ϳ���δ����*/

#define OSD_OPERATE_SUCCESS              (u16)(ERROR_CODE_BASE+7001)/*�ɹ�����*/
#define OSD_INVALID_MENUID               (u16)(ERROR_CODE_BASE+7002)/*��Ч�Ĳ˵�ID*/
#define OSD_GETBUFFER_FAILURE            (u16)(ERROR_CODE_BASE+7003)/*�޷��õ�OSD�ڴ��ַ*/
#define OSD_WRITEDATA_FAILURE            (u16)(ERROR_CODE_BASE+7004)/*OSDд����ʧ��*/
#define OSD_MAPBUFFER_NOTREADY           (u16)(ERROR_CODE_BASE+7005)/*OSD�ڴ�δ����*/
#define OSD_INVALID_VOLUME               (u16)(ERROR_CODE_BASE+7006)/*��Ч������ֵ*/
#define OSD_INVALID_TRANSPARENT          (u16)(ERROR_CODE_BASE+7007)/*��Ч��͸����*/
#define OSD_INVALID_RUNSPEED             (u16)(ERROR_CODE_BASE+7008)/*��Ч�Ĺ����ٶ�*/  
#define OSD_INVALID_MAPID                (u16)(ERROR_CODE_BASE+7009)/*��Ч��MapId*/
#define OSD_MAP_NOT_INIT                 (u16)(ERROR_CODE_BASE+70010)/*Mapδ��ʼ��*/
#define OSD_REGIST_FAIL                  (u16)(ERROR_CODE_BASE+70011)/*��Mapע��OSDʧ��*/
#define OSD_CLOSE_FAIL                   (u16)(ERROR_CODE_BASE+70012)/*Osd�ر�ʧ��*/

#endif

#define  SNAPSHOT_DIRECTORY		"snapshot"	
#define  MAX_SNAPSHOT_FILENAME_LEN	50
#define  MAPX_SNAPSHOT_SAVE_SIZE    (5<<20)

#define  VIDCAP_SCALE_BRIGHTNESS    (u8)0	//����
#define  VIDCAP_SCALE_CONTRAST		(u8)1	//�Աȶ�	
#define  VIDCAP_SCALE_SATURATION    (u8)2   //���Ͷ� 

#define  VIDCAP_CAPVIDEO			(u8)1	//�ɼ�video
#define  VIDCAP_CAPVGA				(u8)2	//�ɼ�vga

//====================�ṹ����=====================================//
/*ͼ��ѹ�����ʿ��Ʋ���*/
#define	 RC_MODE_CONST_BITRATE	 (u8)0x0 /*������*/
#define  RC_MODE_VAR_BITRATE	 (u8)0x1 /*������*/

/*ͼ��ѹ���Ż����Ʋ���*/
#define	 QC_MODE_QUALITY	 (u8)0x1 /*��������*/
#define  QC_MODE_SPEED		 (u8)0x0 /*�ٶ�����*/

/*ͼ����ʽ*/
#define	 VID_ENC_USEPAL		 (u8)0x21     /*PAL��ʽ*/
#define	 VID_ENC_USENTSC	 (u8)0x22     /*NTSC��ʽ*/

/*������ʾ��ʽ*/
#define	DISPLAY_TYPE_PAL	     (u8)0x1 /*PAL video��ʾ*/
#define	DISPLAY_TYPE_NTSC	     (u8)0x2 /*NTSC video��ʾ*/
#define	DISPLAY_TYPE_VGA	     (u8)0x3 /*VGA ��ʾ*/
/*���л���ʾ��ʽ*/
#define	PIP_LOCAL_IN_REMOTE	     (u8)0x0 /*����ΪС���棬Զ��Ϊ����*/
#define	PIP_REMOTE_IN_LOCAL	     (u8)0x1 /*Զ��ΪС���棬����Ϊ����*/
#define	PIP_LOCAL_ONLY		     (u8)0x2 /*����ʾ���ػ���*/
#define	PIP_REMOTE_ONLY		     (u8)0x3 /*����ʾԶ�˻���*/
#define	PIP_LITTLE_PIC	         (u8)0x4 /*��ʾ����С����*/
#define	PIP_LEFT_AND_RIGHT       (u8)0x5 /*����������*/

#define  ASF_AUD_IDX			 (u8)0 /* asf�ļ��е���Ƶ��� */
#define  ASF_VID_IDX			 (u8)1 /* asf�ļ��е���Ƶ��� */

/*��Ƶ�������*/
typedef struct VideoEncParam
{
	u8  m_byEncType;   /*ͼ���������*/
    u8  m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u16  m_byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8  m_byMaxQuant;  /*�����������(1-31)*/
    u8  m_byMinQuant;  /*��С��������(1-31)*/
    u8  m_byReserved1; /*����*/
    u8  m_byReserved2; /*����*/
    u8  m_byReserved3; /*����*/
    u16  m_wBitRate;    /*���������(Kbps)*/
    u16  m_wReserved4;  /*����*/		
	u32 m_dwSndNetBand;/*���緢�ʹ���(��λ:Kbps,1K=1024)*/   
    u32 m_dwReserved5; /*����*/
#ifdef SOFT_CODEC
	u8  m_byQcMode; /*ͼ���������ʿ��Ʋ���,�������Ȼ����ٶ�����*/
    u8  m_byQI;
    u8  m_byQP;
#else
	u8    m_byPalNtsc;    /*ͼ����ʽ(PAL��NTSC)*/	
	u8    m_byCapPort;    /*�ɼ��˿ں�: 1~7��Ч����KDV8010�ϣ�S���Ӷ˿ں�Ϊ7��C���Ӷ˿ں�ȱʡΪ2*/
	u8	m_byFrameRate;  /*֡��(default:25)*/	
	u8    m_byImageQulity;/*ͼ��ѹ������,0:�ٶ�����;1:��������*/
	u8    m_byReserved6;  /*����*/
	u16	m_wVideoWidth;  /*ͼ����(default:640)*/
	u16	m_wVideoHeight; /*ͼ��߶�(default:480)*/
#endif

	u8  m_byFrameFmt; // �ֱ��� 0:���̶�����, 1: half cif, 2: 1 cif, 3: 2 cif,  4: 4 cif,  5: ����ͼ��ϳɱ���  
	u8	m_byFrmRateCanSet; //֡���Ƿ�������趨 ?
	u8  m_byFrmRateLittleThanOne; // ֡���Ƿ�С��1 ?
//	u8  m_byAutoDelFrm;			//�������Ƿ��Զ���֡ ?�������ã�����ֻ��Quality����
}TVideoEncParam;

/*vga�������*/
typedef struct VgaEncParam
{
	u8	m_byEncType;   /*ͼ���������*/
	u16 m_wBitRate;    /*���������(Kbps)*/
	u32	m_dwFrameRate;  /*֡��(default:25)*/	
    u32	m_dwMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
	u8	m_byImageQulity; /*ͼ��ѹ������(1-5)*/
    u8	m_byMaxQuant;  /*�����������(1-31)*/
    u8	m_byMinQuant;  /*��С��������(1-31)*/
	u32 m_dwSndNetBand; /*���緢�ʹ���(��λ:Kbps,1K=1024)*/   
	u8	m_byReserved1; /*����*/
    u8	m_byReserved2; /*����*/
    u8	m_byReserved3; /*����*/
	u8	m_byReserved4; /*����*/	
}TVgaEncParam;

/*vga����״̬*/
typedef struct VgaEncStatus
{
	u8 m_byVgaMode;		/* vgaģʽ�� ����ɹ�Ϊ 0--7֮�䣬 ���ɹ�Ϊ 255 */
	TVgaEncParam m_tVgaEncParam;
}TVgaEncStatus;

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

#ifdef HARD_CODEC
typedef struct VideoDisplayParam
{
	u8    m_byPIPMode;   /*���л���ʾ��ʽ*/
	u8    m_bySaturation;/*��ʾ���Ͷ�*/
	u8    m_byContrast;  /*��ʾ�Աȶ�*/
	u8    m_byBrightness;/*��ʾ����*/
	u16    m_dwPIPXPos;   /*���л�X����*/
	u16    m_dwPIPYPos;   /*���л�Y����*/
	u16    m_dwPIPWidth;  /*���л����*/
	u16    m_dwPIPHeight; /*���л��߶�*/    
	u32  m_dwPlayMode;   //��ʾģʽ��1-PAL��ʾ��2-NTSC��ʾ��3-VGA��ʾ
}TVideoDisplayParam;

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

typedef struct
{
	BOOL32  bSnapShot;  /*����� ?*/
	u32  dwSnapshotMaxSize;	/*���մ洢�����ռ�*/
    u32  dwSnapshotSaveSiz; /*�Ѵ���յĴ�С(byte)*/
    u32  dwSnapshotSavePicNum;/*�Ѵ���յ���Ŀ*/	
}TSnapShot;

typedef struct 
{
    BOOL32 bSnaping;    /* �Ƿ����ڿ��� */
    s8 achSnapFileName[128];   /* Ҫ����Ŀ����ļ��� */
}TSnaptoFile;

typedef struct
{
    u32   dwIp;     //Ip��ַ(������) 
	u16    wPort;    //�˿ں�(������) 
}TNetAddress;

/* ���������ṹ */
typedef struct
{
	u32  dwType;          // ��ͨ�����ͣ�
    u32  dwVolume;       //����
	u32  dwOutFequency;     // �������Ƶ��: 32000/44100/48000
	u32  dwOutPower;   // �����������
	u32  dwOutMode; // ��ͨ�������ģʽ��0-��������1-������
	u32  dwOutBitRate; //���������(kbps):����ЧֵΪ(32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320)
}TMixerParam;

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

typedef void ( *TMotionAlarmInfo)(u32 dwPort,TMoveCBParam *ptMoveCBParam,u32 dwAreaNum,u32 dwContext);
typedef void ( *TDecodeVideoScaleInfo)(u16 wVideoWidth, u16 wVideoHeight);
typedef void ( *TDebugCallBack )(char *pbyBuf, int dwBufLen);

API void mapver(u32 dwMapId);

typedef struct 
{
	u32 dwCoreSpd; 
	u32 dwMemSpd;  
	u32 dwMemSize;  
	u32 dwMaxVidEncNum;  
	u32 dwMaxVidDecNum; 
	u32 dwMaxAudEncNum;
	u32 dwMaxAudDecNum; 
	BOOL32  bVgaOut; 
	u16  wRefreshRate; 
	u32  dwMapId;
}TMapCheckParam;

/* ��Ƶ�ɼ����� */ 
typedef struct
{
	u8 byBrt;			//����    Ĭ��ֵ��128 
	u8 byCst;			//�Աȶ�  Ĭ��ֵ��68 	
	u8 byStn;			//���Ͷ�   Ĭ��ֵ��64 
	u8 byHue;			//ɫ��     Ĭ��ֵ��0 
}TVideoCapScale;


#ifdef _VXWORKS_
void  GetDiskInfo();
#endif

#ifdef _LINUX_
API void CodecWrapperPreInit(void); /* Ԥ��ʼ��codecwrapper��Ӧ�������������BrdInit��ospInit��
                                       ֮���������ŵ��øú�������ɿ����������������Ժ�����ע�� */

#endif

#endif

#endif





















