/*****************************************************************************
ģ����      : RPCtrl
�ļ���      : RPCtrl.h
����ļ�    : RPCtrl.cpp
�ļ�ʵ�ֹ���: ¼������ṩ���ϲ��ͷ�ļ�
����        : ��С�¡�����
�汾        : V4.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/06/29  4.0         ��С��      ����
******************************************************************************/

/****************************************************************************************************************
								һЩ����

һ	·������ "/"��β���� "d:/asf/", ��Ҫ��"d:/asf"
	ֻ���ڿ�ʼ�ļ����ؽ��ղ����У��ļ���Ϊʵ�ʵ��ļ���(��a.asf)�����������ӦΪ�ļ�ǰ׺��(��a)

��	��ʼ¼��,��ʼʱ�����Ϊ����ʱ��(��Ϊ��λ),¼С�ļ�ʱ����Ϊ0��¼���ļ�����Ϊ0;
			 �����С�ļ�¼��ʱ����Ϊ[MIN_TIME_ITVL,MAX_TIME_ITVL];
			 ·�����ļ�������Ϊ��;
			 ¼С�ļ�ʱָ����Ŀ¼��������ڣ�¼���ļ�ʱָ����Ŀ¼���Դ���;

��	��ʼ����,��ʼʱ�����Ϊ����ʱ��(��Ϊ��λ),��С�ļ�ʱ����Ϊ0���Ŵ��ļ�ʱ����Ϊ0;
			 ����ʱ�����Ϊ����ʱ��(��Ϊ��λ),������ڿ�ʼʱ��,����Ϊ0����ʾ����������¼��;
			 ·�����ļ�������Ϊ��;

��  ��ʼ�ļ����ط���,��ʼʱ�����Ϊ����ʱ��(��Ϊ��λ),����Ϊ0;
			 ����ʱ�����Ϊ����ʱ��(��Ϊ��λ),������ڿ�ʼʱ��,����Ϊ0����ʾ����������¼��;
			 ·�����ļ�������Ϊ��;

��	ɾ���ļ���Ŀ¼Ϊ��Ԫ,Ŀ¼�������ļ���ɾ��,���ɾ��Ŀ¼;
  
��  Ϊ�˼�㣬TNetAddr�е�m_wPort��ָrtp�˿ڣ������ڲ���rtcp�˿�����Ϊm_wPort + 1, ��������m_wPort���������2

��  �������ԭΪ�ٷֱȣ�����֮���Ϊ����ʱ�䣨��Ϊ���ļ�����Ϊ�ļ������ʱ�䣩�����Ե���RPGetPlayerStatis
			�õ����ŵļ�ʱʱ�����ʱ�䣬�ϲ����ٷֱ�;

****************************************************************************************************************/

#ifndef _RPCTRL_H_
#define _RPCTRL_H_

#include "kdvtype.h"
#include "kdvdef.h"
#include "osp.h"
#include "kdvmedianet.h"

//�汾��
#define  VER_PRCTRL								( const char * )"rpctrl 40.20.00.40.090203"

//�����붨��
//RPCtrl�����ɹ�
#define RP_OK                 					(u16)0
//RPCtrl����ʧ��
#define RPERR_BASE								(u16)2000

//RPCtrl�Ѿ���ʼ��
#define RPERR_RP_ALREADY_INITIAL				(u16)(RPERR_BASE + 1)
//RPCtrlδ��ʼ��
#define RPERR_RP_NOT_INITIAL					(u16)(RPERR_BASE + 2)
//�ڴ治��
#define RPERR_NO_MEMORY							(u16)(RPERR_BASE + 3)
//ָ��Ϊ��
#define RPERR_NULL_POINT						(u16)(RPERR_BASE + 4)
//������������(255��)
#define RPERR_PARTION_NUM						(u16)(RPERR_BASE + 5)

#define RPERR_PARAM								(u16)(RPERR_BASE + 6)

//ָ��¼���������
#define RPERR_REC_NOT_EXIST						(u16)(RPERR_BASE + 10)
//�����ڸ�¼���״̬���ò���
#define RPERR_REC_STATUS_ERROR					(u16)(RPERR_BASE + 11)
//�Ҳ������е�¼���
#define RPERR_NO_FREE_REC  						(u16)(RPERR_BASE + 12)
//¼���·��������������
#define RPERR_REC_OVER_CAPACITY					(u16)(RPERR_BASE + 13)
//������ý������,��߸ı�
#define RPERR_MEDIATYPE_CHANGE					(u16)(RPERR_BASE + 14)
//�ȴ��ؼ�֡
#define RPERR_WAIT_KEYFRAME						(u16)(RPERR_BASE + 15)
//ʱ�������
#define RPERR_TIMESTAMP_ERR						(u16)(RPERR_BASE + 16)
//Ԥ¼ʱ��Ϊ0�����,����MAX_PREREC_TIME
#define RPERR_PREREC_TIME_INVALID				(u16)(RPERR_BASE + 17)
//С�ļ�ʱ���������Ϲ淶,Ӧ����[MIN_TIME_ITVL,MAX_TIME_ITVL]��Χ
#define RPERR_SMALL_FILE_INTERVAL_INVALID		(u16)(RPERR_BASE + 18)
//����¼��,�Ѿ����ڶ����澯
#define RPERR_ALREADY_ALARM_TWO					(u16)(RPERR_BASE + 19)

//ָ�������������
#define RPERR_PLAY_NOT_EXIST					(u16)(RPERR_BASE + 21)
//�����ڸ÷����״̬���ò���
#define RPERR_PLAY_STATUS_ERROR					(u16)(RPERR_BASE + 22)
//�Ҳ������еķ����
#define RPERR_NO_FREE_PLY  						(u16)(RPERR_BASE + 23)
//�����·��������������
#define RPERR_PLAY_OVER_CAPACITY				(u16)(RPERR_BASE + 24)
//�Ϸ�ʱ������ڿ�ʼʱ��ͽ���ʱ��֮��
#define RPERR_PLAY_DROG_TIME_INVALID			(u16)(RPERR_BASE + 25)
//�������Ȳ����Ϲ淶,Ӧ����[MIN_READ_CALLBACK_GRAN,MAX_READ_CALLBACK_GRAN]��Χ
#define RPERR_PLAY_GRAN_INVALID					(u16)(RPERR_BASE + 26)
//¼���ļ�����Ϊ0,Ӧ��¼��ʱ��ʱ������������
#define RPERR_PLAY_RECORD_LENGTH_ZERO			(u16)(RPERR_BASE + 27)
//�ѵ�����ʱ��
#define RPERR_PLAY_REACH_STOP_TIME				(u16)(RPERR_BASE + 28)

//����ѭ���������
#define RPERR_RPBUF_PARAM						(u16)(RPERR_BASE + 31)
//ѭ�������
#define RPERR_RPBUF_NULL						(u16)(RPERR_BASE + 32)
//ѭ���������
#define RPERR_RPBUF_INVALID						(u16)(RPERR_BASE + 33)
//ѭ��������
#define RPERR_RPBUF_FULL						(u16)(RPERR_BASE + 34)
//ѭ���������ݴ���
#define RPERR_RPBUF_DATA_ERR					(u16)(RPERR_BASE + 35)

//ý�����Ͳ�֧��
#define RPERR_MEDIATYPE_UNSUPPORT				(u16)(RPERR_BASE + 41)
//����Ų���ȷ
#define RPERR_STREAM_IDX_INVALID				(u16)(RPERR_BASE + 42)
//����������(Ϊ0)�����(����PARTION_NAME_LEN)
#define RPERR_PARTION_NAME_INVALID				(u16)(RPERR_BASE + 43)
//�澯�ٽ�ֵ����,Ϊ0��һ���澯ֵС�ڶ����澯ֵ
#define RPERR_ALARM_VALUE_INVALID				(u16)(RPERR_BASE + 44)
//��ʼʱ������Ǿ���ʱ��(���ٴ���0),�������ʱ�䲻Ϊ0������С�ڽ���ʱ��
#define RPERR_START_TIME_INVALID				(u16)(RPERR_BASE + 45)

//Ŀ¼�Ѵ���
#define RPERR_PATH_ALREADY_EXIST				(u16)(RPERR_BASE + 51)
//Ŀ¼������
#define RPERR_PATH_NOT_EXIST					(u16)(RPERR_BASE + 52)
//Ŀ¼����ʧ��
#define RPERR_PATH_CREATE_FAIL					(u16)(RPERR_BASE + 53)
//Ŀ¼ɾ��ʧ��
#define RPERR_PATH_DELETE_FAIL					(u16)(RPERR_BASE + 54)
//�ļ���������(Ϊ0)�����(����MAX_FILE_PATH_LEN)������'/'��β
#define RPERR_FILE_PATH_INVALID					(u16)(RPERR_BASE + 55)

//�ļ��Ѵ���
#define RPERR_FILE_ALREADY_EXIST				(u16)(RPERR_BASE + 61)
//�ļ�������
#define RPERR_FILE_NOT_EXIST					(u16)(RPERR_BASE + 62)
//�ļ�ɾ��ʧ��
#define RPERR_FILE_DELETE_FAIL					(u16)(RPERR_BASE + 63)
//�ļ�����ʧ��
#define RPERR_FILE_RENAME_FAIL					(u16)(RPERR_BASE + 64)
//�ļ�������(Ϊ0)�����(����MAX_FILE_NAME_LEN)
#define RPERR_FILE_NAME_INVALID					(u16)(RPERR_BASE + 65)

//reclog.txt�ļ�����ʧ��
#define RPERR_RECLOG_FILE_CREATE_FAIL			(u16)(RPERR_BASE + 71)
//reclog.txt�ļ�������
#define RPERR_RECLOG_FILE_NOT_EXIST				(u16)(RPERR_BASE + 72)
//reclog.txt�ļ�����ʧ��
#define RPERR_RECLOG_FILE_OP_FAIL				(u16)(RPERR_BASE + 73)
//Ԥ¼�ļ�����ʧ��
#define RPERR_PREREC_FILE_CREATE_FAIL			(u16)(RPERR_BASE + 74)

//�Ҳ������е����ؽ���ͨ��
#define RPERR_NO_FREE_FTPRCV  					(u16)(RPERR_BASE + 81)
//ָ�����ؽ���ͨ��������
#define RPERR_FTPRCV_NOT_EXIST  				(u16)(RPERR_BASE + 82)
//�����ڸ����ؽ���״̬���ò���
#define RPERR_FTPRCV_STATUS_ERROR  				(u16)(RPERR_BASE + 83)
//���ؽ�����Socket�ڼ���
#define RPERR_FTPRCV_LISTEN_SOCKET_ERROR		(u16)(RPERR_BASE + 84)
//������ʱ
#define RPERR_FTPRCV_LISTEN_TIMEOUT				(u16)(RPERR_BASE + 85)
//������ַ�Ͷ˿ڲ���Ϊ0
#define RPERR_IP_OR_PORT_MUST_NO_ZERO			(u16)(RPERR_BASE + 86)
//��������
#define RPERR_FTPRCV_LISTEN_ERROR  				(u16)(RPERR_BASE + 87)
//���տͻ������Ӵ���
#define RPERR_FTPRCV_ACCEPT_ERROR  				(u16)(RPERR_BASE + 88)
//�ͻ������Ӳ�ƥ��
#define RPERR_FTPRCV_CLIENT_ERROR  				(u16)(RPERR_BASE + 89)

//�Ҳ������е����ط���ͨ��
#define RPERR_NO_FREE_FTPSND  					(u16)(RPERR_BASE + 91)
//ָ�����ط���ͨ��������
#define RPERR_FTPSND_NOT_EXIST  				(u16)(RPERR_BASE + 92)
//�����ڸ����ط���״̬���ò���
#define RPERR_FTPSND_STATUS_ERROR  				(u16)(RPERR_BASE + 93)
//�������ط���Socketʧ��
#define RPERR_FTPSND_SOCKET_ERROR  				(u16)(RPERR_BASE + 94)
//�������ؽ��շ�ʧ��
#define RPERR_FTPSND_CONNECT_ERROR  			(u16)(RPERR_BASE + 95)


//add zhx ftp udp�����й�
#define		RP_ERR_FTP_PARAM					(u16)(RPERR_BASE+101)		//��������
#define		RP_ERR_FTP_SOCKET					(u16)(RPERR_BASE+102)		//socket����
#define		RP_ERR_FTP_TASK_CREATE				(u16)(RPERR_BASE+103)		//����task����
#define		RP_ERR_SND_SERVICE_NOT_START		(u16)(RPERR_BASE+104)		//û�д���snd task
#define		RP_ERR_FTP_NEW_OBJECT				(u16)(RPERR_BASE+105)		//�����������
#define		RP_ERR_FTP_MAX_CAPACITY				(u16)(RPERR_BASE+106)		//��������
#define		RP_ERR_FTP_DATA_SCARE				(u16)(RPERR_BASE+107)		//����ȱ��
#define		RP_ERR_FTP_PACK_NO_INDEX			(u16)(RPERR_BASE+108)		//������
#define		RP_ERR_OBJECT_NOT_EXIST				(u16)(RPERR_BASE+109)		//
#define		RP_ERR_FTP_STATUS_ERR				(u16)(RPERR_BASE+110)		//״̬����
#define		RP_ERR_FTP_TOOMUCH_PROXY_DATA		(u16)(RPERR_BASE+111)		//״̬����
//end add


//add zhx 06-04-18 �ļ�Ԥ¼�й�
#define RP_ERR_FILE_BUF_FILENULL				(u16)(RPERR_BASE + 120)//��������
#define RP_ERR_FILE_BUF_PARAM					(u16)(RPERR_BASE + 121)//��������
#define RP_ERR_FILE_BUF_FOPEN					(u16)(RPERR_BASE + 122)//fopen����
#define RP_ERR_FILE_BUF_NODATA					(u16)(RPERR_BASE + 123)//û�����ݴ���
#define RP_ERR_FILE_BUF_FREAD					(u16)(RPERR_BASE + 124)//fread����
#define RP_ERR_FILE_BUF_FWRITE					(u16)(RPERR_BASE + 125)//fwrite����
#define RP_ERR_FILE_BUF_FSEEK					(u16)(RPERR_BASE + 126)//fseek����
#define RP_ERR_FILE_BUF_DATAERR					(u16)(RPERR_BASE + 127)//���ݻ��Ҵ���
#define RP_ERR_FILE_BUF_NEW						(u16)(RPERR_BASE + 131)//���仺�����
//end add








//��������
//�ɼ�����������
#define		MAX_PARTION_NUM		255
//���̿ռ�ָ�����(�澯�ָ�)
#define	RP_DISK_RESUME_NORMAL					(u8)0
//һ�����̿ռ䲻��澯����ֹͣ¼��
#define	RP_DISK_ALARM_LEVEL_ONE					(u8)1
//�������̿ռ䲻��澯��ֹͣ����¼��
#define	RP_DISK_ALARM_LEVEL_TWO					(u8)2

//����¼���¼��(���������)ʱ��������գ����ͣ������·���������ĸ���
#define MAX_STREAM_NUM							(u8)3
//��Ч��¼�����ţ���ʼ¼��ʧ��ʱ���ظñ��
#define NULL_REC_NO								(u32)~0
//��Ч�ķ������ţ���ʼ����ʧ��ʱ���ظñ��
#define NULL_PLY_NO								(u32)~0
//��Ч�����ؽ��ձ�ţ���ʼ¼�����ؽ���ʱ���ظñ��
#define NULL_FTPRCV_NO							(u8)255
//��Ч�����ط��ͱ�ţ���ʼ¼�����ط���ʱ���ظñ��
#define NULL_FTPSND_NO							(u8)255
//8����ղ����������ӣ���ʱ
#define MAX_FTPRCV_LISTEN_TIMEOUT				(u32)8

//¼����������
#define MAX_RECORDER_CAPACITY					(u32)1024
//������������
#define MAX_PLAYER_CAPACITY						(u32)1024

//�������4·�ļ�����ͬʱ����
#define MAX_FTP_CHNS							(u8)4
//��������󳤶�
#define  MAX_PARTION_NAME_LEN					(u8)32
//�ļ�·����󳤶�
#define	MAX_FILE_PATH_LEN						(u8)255
//�ļ�����󳤶�
#define	MAX_FILE_NAME_LEN						(u8)255

//���Ԥ¼ʱ�䣨�룩
#define MAX_PREREC_TIME							(u32)30
//���Ԥ¼�����С
#define MAX_PREREC_SIZE							(u32)((MAX_PREREC_TIME * 25 * 8) << 10)
//���Ԥ¼֡��
#define MAX_PREREC_FRMN_NUM						(u32)10000

//����ű���
#define MAX_QUICKPLAY_TIMES						(u8)4
//������ű���
#define MAX_SLOWPLAY_TIMES						(u8)4

//�ļ��б�����ŵ��ļ���
#define MAX_FILE_NUMBER							(u32)1000

//��С�Ķ��ļ��ص�����(��)
#define MIN_READ_CALLBACK_GRAN					(u8)1
//Ĭ�ϵĶ��ļ��ص�����(��)
#define DEFAULT_READCB_GRAN						(u8)5
//���Ķ��ļ��ص�����(��)
#define MAX_READ_CALLBACK_GRAN					(u8)60

//��С��С�ļ�ʱ����(��)
#define MIN_TIME_ITVL							(u32)10
//Ĭ�ϵ�С�ļ�ʱ����(��)
#define DEFAULT_TIME_ITVL						(u32)60
//����С�ļ�ʱ����(��)
#define MAX_TIME_ITVL							(u32)600

//���л������
#define MAX_BUF_NUM								(s32)16
#define BUF_STARTREAD_NUM						(s32)1
#define BUF_FASTREAD_NUM						(s32)8

#define MAX_PLAY_TIME							(u32)-1


//  media callback 
enum
{
	RP_STREAM_PROPERTY = 0 ,
	RP_STREAM_DATA 	
} ;

typedef struct tagRpMediaStream
{
	u32		m_dwFrameSize;
	u8*		m_pbFrame;
	u32		m_dwTimeStamp;
	u32		m_dwDuration;
	BOOL32	m_bKeyFrame ;
	u8		m_byStreamId;
} TRpMediaStream ;
	

#if __Win32__ || WIN32
#pragma pack(push, 1)				//	��һ���ֽڵĽṹ���룬��ֹ��ͬ�ı��������´���
#endif	//WIN32

// ASF Audio Media Type
typedef struct tagRpAudioMediaInfo{
	u16		wCodecID_FormatTag;				// ��ƵCodec��ʶ
	u16		wNumberOfChannels;				// ��Ƶͨ����				
	u32		dwSamplesPerSecond;				// ������
	u32		dwAverageNumberOfBytesPerSecond;// ƽ������ Bytes / Second
	u16		wBlockAlignment;				// ������ֽ��� 
	u16		wBitsPerSample;					// ÿ�������ı�������Ϊ8����16
	u16		wCodecSpecificDataSize;			// ��ƵCodec��ʶ
	u8*		pbyCodecSpecificData;			// ��ƵCodec��ʶ
} TRpAudioMediaInfo
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif
;							// �൱�� WAVEFORMATEX �ṹ

// ASF Video Media Type
typedef struct tagRpFormatDataStruct{
	u32		dwFormatDataSize;				// ��Ƶ�������ݴ�С
	s32		dwImageWidth;					// ��Ƶ������
	s32		dwImageHeight;					// ��Ƶ����߶�
	u16		wReserved;						// ��������
	u16		wBitsPerPixelCount;				// ÿ���صı�����
	u32		dwCompressionID;				// ��Ƶѹ��Codec��ʶ
	u32		dwImageSize;					// ����ߴ�
	s32		nHorizontalPixelsPerMeter;		// ˮƽ�ֱ���
	s32		nVerticalPixelsPerMeter;		// ��ֱ����ֱ���
	u32		dwColorsUsedCount;				// ��ɫ��
	u32		dwImportantColorsCount;			// 
	u8*		pbyCodecSpecificData;			// Codec ��չ��Ϣ
} TRpFormatData
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif
;								// �൱�� BITMAPINFOHEADER �ṹ

typedef struct tagRpVideoMediaInfo{
	u32		dwEncodedImageWidth;			// ��Ƶ������
	u32		dwEncodedImageHeight;			// ��Ƶ�����
	u16		wFormatDataSize;				// ��Ƶ�������ݴ�С
	TRpFormatData 	tFormatData;			
} TRpVideoMediaInfo
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif
;

typedef struct tarRpOtherMediaInfo{
	u32		dwInfoLength;					// ����ý�����ݳ���
	u8		*pbyInfoData;					// ����ý������ָ��
} TRpOtherMediaInfo
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif
;


//  �����Խṹ 
typedef struct tagRpStreamProperty{
	u16		wStreamType;					// ������
	u8		byStreamNumber;					// �����
	u16		wErrorCorrectType;				// ������������	
	u32		dwErrorCorrectDataLength;		// ������������	
	u8		*pbyErrorCorrectData;			// ������������	
	BOOL32	bIsEncryptedContent;			// �Ƿ�����ݲ������ر���
	u32		dwAverageBitrate;				// ƽ��������  bits/s
	
	union{
		TRpAudioMediaInfo	 tAudioMediaInfo;   // ��Ƶ��������
		TRpVideoMediaInfo	 tVideoMediaInfo;	// ��Ƶ��������
		TRpOtherMediaInfo	 tOtherMediaInfo;	// ����ý����������
	};
} TRpStreamProperty
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif
;

#if __Win32__ || WIN32
#pragma pack(pop)
#endif	//WIN32

typedef void (*MediaStreamCallBack)(u32 dwRecorderId, u8 DataType, u8 * pBuf, u32 dwLength, u32 dwContext);


//ʣ��洢�ռ�澯�ص�����,ֻ�е������澯,ֹͣ¼��ʱ,¼����Ų�������,����һ������Ϊ255
typedef void (*FreeSpaceAlarmCallBack)( u8 byAlarmLevel, s8* pchPartionName, u32 dwRecorderId, u32 dwContext );

//�ļ����ؽ��Ȼص�����
//dwCurrentFtpTime,����Ϊ��λ(����ʱ��)
typedef void (*FtpFileRateCallBack)( u8 byFtpSndID, u32 dwCurrentFtpTime, u32 dwContext );

//¼��С�ļ������ص�(��Ҫ����ļ��л��ص�����,��Ȼ�ﲻ����Ҫ��Ĺ���)
typedef void (*RecFileEndCallBack)( u32 dwRecorderID, u32 dwStoptime, u32 dwContext );

//���ļ��л��ص�,s8* pchFileName:�л����ļ���ָ��(��Ҫ��С�ļ������ص�����,��Ȼ�ﲻ����Ҫ��Ĺ���)
typedef void (*RecBigFileSwCallBack)( u32 dwRecorderID, s8* pchFileName, u32 dwContext );

//���ļ����Ȼص�����
//dwCurrentPlayTime,����Ϊ��λ(����ʱ��),���ܴ�С�ļ���ͳһ��MAX_PLAY_TIME��Ϊ���Ž�����־
typedef void (*ReadFileRateCallBack)( u32 dwPlayerID, u32 dwCurrentPlayTime, u32 dwContext );

//�����ַ�ṹ
typedef  struct  tagTRPNetAddr 
{
	//��ַ
	u32  m_dwIp;
	//�˿ں�
	u16  m_wPort;
}TNetAddr;

//����ش���ַ�ṹ
typedef  struct  tagTNetBackAddr
{
	//��ַ
	u32  m_dwIp;
	//rtcp�˿ں�
	u16  m_wRtcpPort;
}TNetBackAddr;

//������յ�ַ��Ϣ�ṹ
typedef  struct  tagTRPNetRcvParam
{
	//ʵ�ʵĵ�ַ��
	u8        m_byNum;
	//��ַ���飬��0����ʾ��Ƶ����n����ʾ��n·��Ƶ��Ŀǰֻ֧����·��Ƶ
	TNetAddr  m_atAddr[MAX_STREAM_NUM];
	//�ش���ַ����
	TNetBackAddr m_atBackAddr[MAX_STREAM_NUM];
}TRPNetRcvParam;

//���緢�͵�ַ��Ϣ�ṹ
typedef  struct  tagTRPNetSndParam
{
	//ʵ�ʵĵ�ַ��
	u8        m_byNum;
	//���ص�ַ���飬��0����ʾ��Ƶ����n����ʾ��n·��Ƶ��Ŀǰֻ֧����·��Ƶ
	TNetAddr  m_atLocalAddr[MAX_STREAM_NUM ];
	//Զ�˵�ַ���飬��0����ʾ��Ƶ����n����ʾ��n·��Ƶ��Ŀǰֻ֧����·��Ƶ
	TNetAddr  m_atRemoteAddr[MAX_STREAM_NUM ];
	//���ʹ��raw socket,���ֶ�Ϊsrc ip/port
	TNetSession m_atAddrForRawSock[MAX_STREAM_NUM];
}TRPNetSndParam;

//�ļ��б�
typedef struct tagTListInfo
{
	u32 m_dwNum;
	s8	m_astrFileName[MAX_FILE_NUMBER][MAX_FILE_NAME_LEN];
}TListInfo;

//�غ���Ϣ
typedef struct tagPTInfo
{
	u8 m_byRmtActivePT;
	u8 m_byRealPT;
}TPTInfo;

//�غ���Ϣ�ṹ
typedef struct tagRemotePTParam
{
	//�غ�ֵ����
	TPTInfo   m_atPTInfo[MAX_STREAM_NUM];
}TRemotePTParam;

//�����غ���Ϣ�ṹ
typedef struct tagPTParam
{
	//�����غ�����
	u8		  m_abyLocalPt[MAX_STREAM_NUM];
}TLocalPTParam;

//���ܣ����ܣ���Ϣ
typedef struct tagEncDecInfo
{
	//���ܣ����ܣ�key�ִ�
	s8 *m_pszKeyBuf;
	//���ܣ����ܣ�key�ִ���С
	u16 m_wKeySize;
	//���ܣ����ܣ�ģʽ
	u8 m_byMode;
}TEncDecInfo;

//���ܣ����ܣ���Ϣ�ṹ
typedef struct tagTEncDecParam
{
	//ʵ�ʵĵ�ַ��
	u8	m_byNum;
	//���ܣ����ܣ���Ϣ����
	TEncDecInfo m_atEncDecInfo[MAX_STREAM_NUM];
}TEncDecParam;

//ý��ͳ��
typedef struct tagTMediaStatis
{
	//ý������
	u8  m_byMediaType;
	//�Ƿ�Ϊ��Ƶ
	BOOL32 m_bAud;
	//���գ����ͣ���֡��
	u32 m_dwNetFrmNum;
	//���գ����ͣ�֡��
	u32 m_dwNetFrmRate;
	//���������µĶ�����
	u32 m_dwBufFullLostFrmNum;
	//��֡���µĶ�����
	u32 m_dwErrFrmLostFrmNum;
	//����յĴ���
	u32 m_dwBufEmptyNum;
	//���һ֡�����
	u32 m_dwLastFrameId;
	//�Ƿ��ڵȴ��ؼ�֡
	BOOL32 m_bWaitForKeyFrame;
	//����ʱ��
	u32 m_dwDuration;
	//ʱ���
	u32 m_dwTimeStamp;
	//2���ڵ�asf�ļ��Ķ���д��֡��
	u32 m_dwAsfFrmNum;
	//2���ڵ�asf�ļ��Ķ���д��֡��
	u32 m_dwAsfFrmRate;
	//��Ƶ���(��Ƶʱ,������ֶ���������ģʽ)
	u32 m_dwWidth;
	//��Ƶ�߶�
	u32 m_dwHeight;
	//�Ƿ�263+
	BOOL32 m_bH263Plus;
	//ƽ��������06-05-18
	u32 m_dwAverageBitrate;
	//�Ƿ񲥷ţ�����ϲ㲻�������ַ������Ϊ��·���ǲ����ŵ�
	BOOL32 m_bPlayOut;
}TMediaStatis;

//¼������ʼ�������ṹ
typedef struct tagRPInitParam
{
	//��Ҫ��¼������·�������������������
	u32 m_dwInitialRecorderNum;
	//��Ҫ�ķ�������·�������������������
	u32 m_dwInitialPlayerNum;
	//һ���澯����Сʣ��洢�ռ䣨��ֹͣ¼��
	u32 m_dwRemainSpaceAlarmLevelOne;
	//�����澯����Сʣ��洢�ռ䣨ֹͣ����¼��
	u32	m_dwRemainSpaceAlarmLevelTwo;
	//ʣ��洢�ռ�澯
	FreeSpaceAlarmCallBack	m_pCallback;
	//�澯������
	u32 m_dwContext;	
}TRPInitParam;

//���ؽ���״̬
enum EMFtpRcvStatus{
	//ֹͣ���ؽ���
	FTP_RCV_STOP,
	//�������ؽ���
	FTP_RCV_RUNNING
};

//¼�����ؽ��ղ���
/*
¼�����أ����շ��ȴ����ͷ���������
�����ж����������������Ƿ��Ƿ��ͷ���
¼������ֻ¼���ļ�
*/
typedef struct tagFtpRcvParam
{
	//���ط��ͷ���ַ
	TNetAddr m_tFtpSndAddr;
	//���ؽ��շ���ַ
	TNetAddr m_tFtpListenAddr;
	//����¼���ļ���·��
	s8 m_achRecFilePath[MAX_FILE_PATH_LEN+1];
	//����¼���ļ����ļ���
    s8 m_achRecFileName[MAX_FILE_NAME_LEN+1];
}TFtpRcvParam;

//���ط���״̬
enum EMFtpSndStatus{
	//ֹͣ���ط���
	FTP_SND_STOP,
	//�������ط���
	FTP_SND_RUNNING
};

typedef struct tagFtpSndParam
{
	//���ط��ͷ���ַ�������ӽ��յ�ַ
	TNetAddr m_tFtpSndAddr;
	//���ؽ��շ���ַ
	TNetAddr m_tFtpRcvAddr;
	//��ʼʱ��
	u32 m_dwStartTime;
	//����ʱ��	
	u32 m_dwStopTime;
	//�������ļ���·��
    s8 m_achPlayFilePath[MAX_FILE_PATH_LEN+1];
	//�������ļ����ļ���
    s8 m_achPlayFileName[MAX_FILE_NAME_LEN+1];
	//���ļ����Ȼص�
	FtpFileRateCallBack m_pCallBack;
	//���ļ���������(����Ϊ��λ,Ӧ����[MIN_READ_CALLBACK_GRAN,MAX_READ_CALLBACK_GRAN]��Χ)
	u8 m_byRateGran;
	//�ص�������
	u32 m_dwContext;
}TFtpSndParam;

//¼����״̬
enum EMRecorderStatus{
	//ֹͣ¼��
	REC_STOP,
	//����¼��
	REC_RUNNING,
	//��ͣ¼��
	REC_PAUSE
};

//¼������ṹ
/*	¼������� m_dwStartTime ��ʼ�����ļ��� ��m_dwStartTime Ϊ 123000����� m_achRecFileName Ϊ NULL��
	���ļ�������Ϊ 123000.asf�� ���m_achRecFileName ��Ϊ NULL����"a"�������ļ�������Ϊ a123000.asf��
*/
typedef struct tagTRecParam
{
	//1������¼�񣻱���¼��Ҫ��codecwrapper�е���
	//0������¼��
	BOOL32 m_bLocalRec;
	//����¼���ļ���·��
    s8 m_achRecFilePath[MAX_FILE_PATH_LEN+1];
	//����¼���ļ����ļ���
    s8 m_achRecFileName[MAX_FILE_NAME_LEN+1];
	//��һ���ļ�����ʼʱ��
	u32 m_dwStartTime;
	//��һ���ļ�����Ƶ�ؼ�֡��ʼ��
	BOOL32 m_bVideoFirst;
	//1������ΪС�ļ���
	//0������Ϊ���ļ�
	BOOL32 m_bSmallFile;
	//����ΪС�ļ�ʱ��ʱ��������λ�룩
	u32 m_dwTimeInterval;
	union
	{
		//¼��С�ļ������ص�
		RecFileEndCallBack m_pRecEndCallBack;
		//���ļ��л��ص�
		RecBigFileSwCallBack m_pRecBigFileSwCB;
	};
	
	//�ص�������
	u32 m_dwContext;
}TRecParam;

//����¼�����Ƶ������
typedef struct tagStreamAverageBitrate
{
	//����Ӧ��ƽ�����ʣ�����0Ϊ��Ƶ��1��Ϊ��Ƶ��2Ϊ��Ƶ
	u32 m_adwStreamAverageBitrate[MAX_STREAM_NUM];
}TStreamAverageBitrate;


//¼�������״̬
typedef struct tagTRPRecStatus
{
	//Ԥ¼�Ƿ�ʼ
	BOOL32 m_bPreRecStart;
	//����״̬
	EMRecorderStatus m_tRecState;
}TRPRecStatus;

//¼���״̬
typedef struct tagTRecorderStatus
{
	//¼��״̬
	TRPRecStatus  m_tRecStatus;
	//¼�����
	TRecParam  m_tRecParam;
	//������ղ���
	TRPNetRcvParam	m_tNetparam;
	//�Ƿ�ֻ¼�ؼ�֡
	BOOL32 m_bOnlyRecIFrm;
	//¼�ؼ�֡�ļ��
	u32	m_dwFrmItvl;
}TRecorderStatus;

//¼���ͳ��
typedef struct tagTRecorderStatis
{
	//���ĸ���
	u8	m_byNum;
	//¼��ʱ��(��)
	u32 m_dwRecTime;
	//¼��ý��ͳ������
	TMediaStatis m_atMediaRecStatis[MAX_STREAM_NUM];
}TRecorderStatis;

//����״̬
enum EmPlayerStatus
{
	//ֹͣ����
	PLAYER_PLAY_STOP,
	//���ڷ���
	PLAYER_PLAY_START,
	//��ͣ����
	PLAYER_PLAY_PAUSE,
	//���
	PLAYER_PLAY_QUICK,
	//����
	PLAYER_PLAY_SLOW
};

//��������ṹ
/*	��ʼ������ʱ��,����Ϊ0;
	����ʱ�����������,����Ϊ0����ʾ���ŵ�����;
*/ 
typedef struct tagTPlayParam	
{
	//�������ļ���·��
    s8 m_achPlayFilePath[MAX_FILE_PATH_LEN+1];
	//�������ļ����ļ���
    s8 m_achPlayFileName[MAX_FILE_NAME_LEN+1];
	//��ʼʱ��(����ʱ�䣬����Ϊ0)
	u32 m_dwStartTime;
	//����ʱ��(����Ϊ0����Ϊ0ʱ������ʱ��)
	u32 m_dwStopTime;
	//1��¼���ļ�ΪС�ļ���0��¼���ļ�Ϊ���ļ�
	BOOL32 m_bSmallFile;
	//���ļ����Ȼص�
	ReadFileRateCallBack m_pCallBack;
	//���ļ���������(����Ϊ��λ,Ӧ����[MIN_READ_CALLBACK_GRAN,MAX_READ_CALLBACK_GRAN]��Χ)
	u8 m_byRateGran;
	//�ص�������
	u32 m_dwContext;
	//���緢�͵�ַ
	TRPNetSndParam	m_tNetSndParam;
	//�Ƿ�ֻ�Źؼ���
	BOOL32 m_bPlyOnlyIFrm;
}TPlayParam;

//�����״̬
typedef struct tagTPlayerStatus
{
	//����״̬
	EmPlayerStatus m_tPlyStatus;
	//���Ų���
	TPlayParam m_tPlayParam;
}TPlayerStatus;

//�����ͳ��
typedef struct tagTPlayerStatis
{
	//���ĸ���
	u8	m_byNum;
	//����ʱ��(��)
	u32 m_dwPlyTime;
	//�ļ��ܹ�ʱ��(��)
	u32 m_dwTotalPlyTime;
	//����ý��ͳ������
	TMediaStatis m_atMediaPlyStatis[MAX_STREAM_NUM];
	//��������飬��Ϊһ���ļ�����2��������ſ���Ϊ2��3, ����1��2,
	u8  m_abyStreamNoArr[MAX_STREAM_NUM];
}TPlayerStatis;

//�ļ���Ϣ
typedef struct tagTFileInfo
{
	//�ļ���С
	u32 m_dwSize;
	//����ʱ��
	u32 m_dwDuration;
}TFileInfo;

#define MAX_KEY_FRAME_HDR_LEN	(2048)  

typedef struct tagTKeyFrameHdr{
	u8	m_abyHdr[MAX_STREAM_NUM][MAX_KEY_FRAME_HDR_LEN];
	u32 m_adwHdrLen[MAX_STREAM_NUM];
}TKeyFrameHdr;

//�ļ��е�����Ϣ
typedef struct tagTMediaInfo
{
	//���ĸ���
	u8 m_byNum;
	//��������
	u8 m_abyMediaType[MAX_STREAM_NUM];
	u16	m_awWidth[MAX_STREAM_NUM];
	u16 m_awHeight[MAX_STREAM_NUM];
}TMediaInfo;

typedef struct tagTCBContext 
{
	u8 m_byIdx;
	u32 m_dwAddr;
}TCBContext; 

typedef struct tagTRPRecRSParam
{
	TRSParam m_atRsParam[MAX_STREAM_NUM];
	BOOL32	 m_abRepeatSnd[MAX_STREAM_NUM];
}TRPRecRSParam;

typedef struct tagTRPPlyRSParam
{
	u16		 m_awBufTimeSpan[MAX_STREAM_NUM];
	BOOL32	 m_abRepeatSnd[MAX_STREAM_NUM];
}TRPPlyRSParam;


//add zhx ftp udp�����й�
//���ط�ͬʱ������(��������趨Ϊ1)
#define			MAX_RP_FTP_RCV_NUM			32
//ftp���ͷ������ķ�����
#define			MAX_RP_FTP_SND_NUM			32


#define			MAX_FTP_RCV_USER_ID_LEN		32

typedef enum
{
		SND_STATUS_START = 1,					//��ʼ1
		SND_STATUS_STATUS_PROBE,				//̽��2
		SND_STATUS_WAITING_RCV_REQ,				//�ȴ�ack3
		SND_STATUS_WAITED_RCV_REQ,				//�յ�ack4
		SND_STATUS_SEND_STREAM_PROPERTY,		//������5
		SND_STATUS_WAIT_PROPERTY_ACK,			//�ȴ�������ack6
		SND_STATUS_SEND_FRAME_DATA,				//֡����7
		SND_STATUS_WAIT_FRAME_DATA_ACK,			//�ȴ�֡����ack8
		SND_STATUS_STOP
}TSndStatus;

//����״̬,�ص����(!!!��0)�Ľ��д���
typedef enum
{
		RCV_STATUS_START = 1,					//1��ʼ����
		RCV_STATUS_ADD_STREAM_ERROR,			//2д������
		RCV_STASTU_ADD_FRAME_ERROR,				//3д֡����
		RCV_STATUS_SND_REQ,						//4������������
		RCV_STATUS_WAIT_STREAM_PROPERTY,		//5�ȴ�������
		RCV_STATUS_SND_PROPERTY_ACK,			//6���������Ի���
		RCV_STATUS_WAIT_FRAME_DATA,				//7�ȴ�֡����
		RCV_STATUS_SND_FRAME_DATA_ACK,			//8����֡����
		RCV_STATUS_TIMEOUT,						//!!!9��ʱ
		RCV_STATUS_CLOSE,						//10�ر�
		Rcv_STATUS_RCV_END,						//!!!11���ؽ���
		RCV_STATUS_REQ_INVALID,					//!!!12������ز���(���ͷ���Ϊ��������������ܲ��Ϸ�)
		RCV_STATUS_PROBE						//
}TRcvStatus;


typedef void(*RpFtpRcvCallBack)(u32 dwStatusCode, u32 dwSSid, u32 dwCurTime, u32 dwUserdata);

//ftp���ͷ���˲����ṹ
typedef struct tagFtpSndServParam
{
	TNetAddr	m_tLocalAddr;			//���ص�ַ
}TFtpSndServParam;

//ftp����
typedef struct tagFtpUdpSndParam
{
	u32 m_dwStartTime;										//��ʼʱ��
	u32 m_dwStopTime;										//����ʱ��
	s8 m_abyFilePath[MAX_FILE_PATH_LEN];					//�ļ�·��
	s8 m_abyFileName[MAX_FILE_NAME_LEN];					//�ļ���
	BOOL32 m_bSmallFile;									//�Ƿ�С�ļ�
}TFtpUdpSndParam;

typedef struct tagFtpSndAllParam
{
	u32				m_dwSSid;			//�ͻ��˵�ssid
	TSndStatus		m_emSndStatus;		//ftp���Ͷ�״̬
	TNetAddr	m_tRemoteAddr;			//�ͻ���ip/port
	s8	m_abyUserId[MAX_FTP_RCV_USER_ID_LEN+1];//�û�id
}TFtpSndAllParam;


#define		MAX_PROXY_USER_DATA		16

//ftp�ͻ��˲����ṹ
typedef struct tagFtpUdpRcvParam
{
	s8	m_abyUserId[MAX_FTP_RCV_USER_ID_LEN+1];//�û�id
	TNetAddr m_tRcvLocalAddr;			//���ص�ַ
	TNetAddr m_tRcvRemoteAddr;			//���ط����ַ
	RpFtpRcvCallBack m_pRcvCallBack;	//�ص�
	u32 m_dwUserData;					//������
	s8 m_abyLocalFilePath[MAX_FILE_PATH_LEN];			//���ش洢·��
	s8 m_abyLocalFileName[MAX_FILE_NAME_LEN];			//���ش洢�ļ���
	u32 m_dwGran;						//�ص�����
	u32 m_dwStartTime;					//���ؿ�ʼʱ��
	u32 m_dwStopTime;					//���ؽ���ʱ��
	s8 m_abyRequestFilePath[MAX_FILE_PATH_LEN];			//Ҫ���ص��ļ�·��
	s8 m_abyRequestFileName[MAX_FILE_NAME_LEN];			//Ҫ���ص��ļ���
	BOOL32 m_bSmallFile;				//�Ƿ�С�ļ�
	u8	m_abyProxyUserData[MAX_PROXY_USER_DATA];//�����û�����
	u32 m_dwProxyUserDataLen;//�����û����ݳ���
	tagFtpUdpRcvParam()
	{
		m_dwProxyUserDataLen = 0;
	}
}TFtpUdpRcvParam;

//ftp���ͷ���˲�ѯ�ṹ
typedef struct tagFtpSndQuery
{
	u32 dwClientNum;					//�ͻ�����,Ҳ����������Ԫ�ظ���
	TFtpSndAllParam m_atFtpSndAllParam[MAX_RP_FTP_SND_NUM];//�ͻ����������ص���Ӧ����
	TFtpUdpSndParam m_tFtpUdpSndParam[MAX_RP_FTP_SND_NUM];//�ͻ����������ص���Ӧ����
}TFtpSndQuery;

//ftp�ͻ��˲�ѯ�ṹ
typedef struct tagFtpRcvQuery
{
	u32 dwStauts;						//Ŀǰ״̬
}TFtpRcvQuery;
//end add

/*====================================================================
������      :RPInit
����        :¼������ʼ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:const TRPInitParam *ptRPInitParam,¼������ʼ�������ṹ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/
u16 RPInit( const TRPInitParam *ptRPInitParam, BOOL32 bUsedRawSocket = FALSE);

/*====================================================================
������      :RPRelease
����        :�ͷ�¼�����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/
u16 RPRelease( );

/*====================================================================
������      :  RPSetCheckPartion
����        :  ���ô��̸澯��صķ���
�㷨ʵ��    :�ɶ��ʹ��,�������ͬ�ķ���,�򸲸�ǰһ�εĸ澯ֵ.��������ΪMAX_PARTION_NUM
����ȫ�ֱ���:
�������˵��:  s8 *pchPartionName�� ������
			   u32  dwAlarmLvlOne, һ���澯ֵ
			   u32  dwAlarmLvlTwo, �����澯ֵ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
06/01/24	4.0			fang hui        ����
====================================================================*/
u16 RPSetCheckPartion( s8 *pchPartionName , u32 dwAlarmLvlOne, u32 dwAlarmLvlTwo );

//���ô��̼��������λ��s ,�ڲ�Ĭ��Ϊ10s
u16 RPSetDiskCheckInterval( u32 dwInterval );

/*====================================================================
ɾ���������
s8* pchPartionName: ������,Ҫ��RPSetCheckPartion�������ݵķ�������ȫƥ��
��ȷ����rp_Ok
====================================================================*/
u16  RPDeleteCheckPartion( s8 *pchPartionName );

/*====================================================================
������      :RPCreateRec
����        :����¼������õ����õ�¼������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 *pbyRecoderID, ָ��¼�����ţ����ظ��û�			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/		
u16 RPCreateRec( u32 *pdwRecoderID );

/*====================================================================
������      :RPReleaseRec
����        :�ͷ�¼���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecoderID, ¼������	 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/		
u16 RPReleaseRec( u32 dwRecoderID );

/*====================================================================
������      :RPSetRecNetRcvParam
����        :����¼�����������ղ���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byRecorderID, ¼������
			  TRPNetRcvParam *ptNetRcvParam, �������	 

����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/10	4.0			fang hui    	  ����
====================================================================*/
u16 RPSetRecNetRcvParam( u32 dwRecorderID, const TRPNetRcvParam *ptNetRcvParam );

//��������ƽ�����ʣ���ȷ����rp_ok
u16 RPSetAverageBitrate(u32 dwRecorderID, const TStreamAverageBitrate& tStreamAverageBitrate);

/*====================================================================
������      :RPSetRemotePT
����        :���ý������� �� Playloadֵ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byRecoderID, ¼������
			  TRemotePTParam *ptPTParam, �غɽṹ	 

����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/10	4.0			fang hui    	  ����
====================================================================*/
u16 RPSetRemotePT( u32 dwRecoderID, const TRemotePTParam *ptPTParam );

/*====================================================================
������      :RPSetDecryptKey
����        :���� ����key�ִ� �Լ� ����ģʽ Aes or Des
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byRecorderID, ¼������
			  TEncDecParam *ptDecryptParam, ������Ϣ�ṹ	 

����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui    	  ����
====================================================================*/
u16 RPSetDecryptKey( u32 dwRecorderID, const TEncDecParam *ptDecryptParam );

/*====================================================================
������      :RPStartRec
����        :ʹ��ָ��¼�����ʼ¼��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������
			 const TRecParam * ptRecParam,¼������ṹ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/
u16 RPStartRec( u32 dwRecorderID , const TRecParam *ptRecParam );

/*====================================================================
������      :RPSetRecStreamSave
����        :����¼���¼��·��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������
			 u8 byStreamId, �����, 1-��Ƶ��2-��һ·��Ƶ��3-�ڶ�·��Ƶ
			 BOOL32 bSave, �Ƿ�洢
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/21	4.0			fang hui			  ����
====================================================================*/
u16 RPSetRecStreamSave( u32 dwRecorderID, u8 byStreamId, BOOL32 bSave );

/*====================================================================
������      :RPPauseRec
����        :��ͣ¼��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui			  ����
====================================================================*/
u16 RPPauseRec( u32  dwRecorderID );

/*====================================================================
������      :RPResumeRec
����        :����¼��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui			  ����
====================================================================*/
u16 RPResumeRec( u32 dwRecorderID );

/*====================================================================
������      :RPSetRecorderSaveMethod
����        :����¼����¼�Ʒ�������֡¼���������¼��,�����Ƶ֡����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������	
			 BOOL32 bOnlySaveKeyFrame, �Ƿ��ؼ�֡
			 u32 dwSaveFrameInterval��ÿ dwSaveFrameInterval ���ؼ�֡��һ֡
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui			  ����
====================================================================*/
u16 RPSetRecorderSaveMethod( u32 dwRecorderID, BOOL32 bOnlySaveKeyFrame = FALSE, u32 dwSaveFrameInterval = 1 );

/*====================================================================
������      :RPStopRec
����        :ָֹͣ��¼�����¼��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/
u16 RPStopRec( u32 dwRecorderID, u32 dwStopTime = 0 );

/*====================================================================
������      :RPSetRecRsParam
����        :����¼������ش�����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byRecorderID,¼������
			 TRPRecRSParam *ptRecRSParam��¼���ش��������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/09	4.0			fang hui			  ����
====================================================================*/
u16 RPSetRecRsParam( u32 dwRecorderID, TRPRecRSParam *ptRecRSParam );

/*====================================================================
������      :RPStartPreRec
����        :ʹ��ָ����¼�����ʼԤ¼
�㷨ʵ��    :Ҫʹ���ļ�Ԥ¼,�����ʹ��С�ļ���ʽ;��ʽ¼��֮�����ٵ���Ԥ¼;
			ֹͣ��ʽ¼���ͬʱҲֹͣԤ¼,
����ȫ�ֱ���:
�������˵��:u8 byRecorderID,¼������
			 BOOL32 bPreRecInMem,�Ƿ��ڴ�Ԥ¼
			 u32 dwPreRecTime��¼���Ԥ¼ʱ�䳤�ȣ���λ�룩
			 ptRecParam: �ļ�Ԥ¼����,ʹ����¼�񷽷�һ��,·�����ļ���Ҳ��Ϊ��ʽ¼��Ĳ���,��ʼʱ����ΪԤ¼�Ŀ�ʼʱ��,
			 ���ΪС�ļ��ļ��,¼��ʱС�ļ����ļ�����һ�ε���,�ϲ�Ӧ��ʱ�������֪��ʲôʱ������ʽ��ʼ¼��ʱ��;
			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/
u16 RPStartPreRec( u32 dwRecorderID , BOOL32 bPreRecInMem, u32 dwPreRecTimeInterval, const TRecParam *ptRecParam );

/*====================================================================
������      :RPStopPreRec
����        :ָֹͣ����¼�����Ԥ¼
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecorderID,¼������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPStopPreRec( u32 dwRecorderID );

/*====================================================================
������      :RPGetPreRecTime
����        :�õ���ǰԤ¼��ʱ��
�㷨ʵ��    :
����ȫ�ֱ���: 
�������˵��:u8 byRecorderID,¼������
			 u32& dwPreRecTime,Ԥ¼��ʱ�䣨��λ�룩
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/31	4.0			gie			  ����
====================================================================*/
u16 RPGetPreRecTime( u32 dwRecorderID , u32& dwPreRecTime );

/*====================================================================
������      :RPGetRecordTotalLength
����        :�õ���ǰд��¼�����ݳ���
�㷨ʵ��    :
����ȫ�ֱ���: 
�������˵��:u8 byRecorderID,¼������
			 u64& qwRecordTotalLength����λBytes��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/31	4.0			gie			  ����
====================================================================*/
u16 RPGetRecordTotalLength( u32 dwRecorderID , u64& qwRecordTotalLength );

/*====================================================================
������      :RPCreatePlay
����        :������������õ����õķ�������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 *pbyPlayerID, ָ��������ţ����ظ��û�			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/		
u16 RPCreatePlay( u32 *pdwPlayerID );

/*====================================================================
������      :RPReleasePlay
����        :�ͷŷ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID, ��������	 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/		
u16 RPReleasePlay( u32 dwPlayerID );

/*====================================================================
������      :RPSetReadCallBackGran
����        :�����ļ����Ȼص�������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID, ��������
			 u8 byGran, ���»ص��Ķ��ļ�����(����Ϊ��λ,Ӧ����[MIN_READ_CALLBACK_GRAN,MAX_READ_CALLBACK_GRAN]��Χ)
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/	
u16 RPSetReadCallBackGran( u32 dwPlayerID, u8 byGran );

/*====================================================================
������      :RPSetLocalPT
����        :���ñ������� �� Playloadֵ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byPlayerID, ��������
			  TLocalPTParam *ptPTParam, �غɽṹ	 

����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/10	4.0			fang hui    	  ����
====================================================================*/
u16 RPSetLocalPT (u32 dwPlayerID, const TLocalPTParam *ptPTParam );

/*====================================================================
������      :RPSetEncryptKey
����        :���� ����key�ִ� �Լ� ����ģʽ Aes or Des
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byPlayerID, ��������
			  TEncDecParam *ptEncryptParam, ������Ϣ�ṹ	 

����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui    	  ����
====================================================================*/
u16 RPSetEncryptKey( u32 dwPlayerID, TEncDecParam *ptEncryptParam );

/*====================================================================
������      :RPGetFileInfo
����        :�õ�ָ���ļ��е���Ϣ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 s8 *pchFullFileNam,�ļ�ȫ��
			 TMediaInfo *ptMediaInfo, ý����Ϣ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
09/03/27	1.0			ZYQ			  ����
====================================================================*/
u16 RPGetFileInfo( u32 dwPlayerID, s8 *pchFullFileName, TFileInfo *ptFileInfo );
/*====================================================================
������      :RPGetFileMediaInfo
����        :�õ�ָ���ļ��е�����Ϣ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 s8 *pchFullFileNam,�ļ�ȫ��
			 TMediaInfo *ptMediaInfo, ý����Ϣ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/08/11	4.0			fang hui			  ����
====================================================================*/
u16 RPGetFileMediaInfo( u32 dwPlayerID, s8 *pchFullFileName, TMediaInfo *ptMediaInfo );

/*====================================================================
������      :RPSetPlayNetParam
����        :����ָ���������ָ�������ķ��͵�ַ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 u8 byIndex�������������
			 const TNetSndParam& tSndPar,�����͵�ַ�����ṹ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
09/03/31	1.0			zyq			  ����
====================================================================*/
u16 RPSetPlayNetParam( u32 dwPlayerID , u8 byIndex, const TNetSndParam& tSndPar );

/*====================================================================
������      :RPStartPlay
����        :ʹ��ָ���ķ���������������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 const TPlayParam *ptPlayParam,��������ṹ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPStartPlay( u32 dwPlayerID , TPlayParam *ptPlayParam );

/*====================================================================
������      :RPGetFstKeyFrmHdr
����        :ʹ��ָ���ķ������ȡ���ŵ��ļ�������һ���ؼ�֡ͷ,
			�����ڵ���GetFileMediaInfo֮�����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 ptKeyFrameHdr,�ؼ�֡ͷ���ݽṹ
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPGetFstKeyFrmHdr(u32 dwPlayerID ,TKeyFrameHdr* ptKeyFrameHdr);

/*====================================================================
������      :RPRestartPlay
����        :ʹ��ָ���ķ�������¿�ʼ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPRestartPlay( u32 dwPlayerID );
/*====================================================================
������      :RPPausePlay
����        :��ָͣ����������������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPPausePlay( u32 dwPlayerID );


/*====================================================================
������      :RPSetSwitchFileNamePattern
����        :���ô��ļ��л�ʱ���ļ���ģ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byPlayerID����������
s8 * pchPattern���ļ���ģ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
07/07/10	4.0			baihao			  ����
====================================================================*/
u16 RPSetSwitchFileNamePattern( u8 byRecorderID, s8 * pchPattern );


/*====================================================================
������      :RPResumePlay
����        :�ָ�ָ����������������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPResumePlay( u32 dwPlayerID );

/*====================================================================
������      :RPStopPlay
����        :ָֹͣ����������������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPStopPlay( u32 dwPlayerID );

/*====================================================================
������      :RPSetPlyRsParam
����        :���÷�������ش�����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byPlayerID,��������
			 TRPPlyRSParam *ptPlyRSParam�������ش��������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/09	4.0			fang hui			  ����
====================================================================*/
u16 RPSetPlyRsParam( u32 dwPlayerID, TRPPlyRSParam *ptPlyRSParam );

/*====================================================================
������      :RPQuickPlay
����        :���ָ�����������������ٶ�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 u8 byQuickTimes,��߷�����ٶ�(2����4����)
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPQuickPlay( u32 dwPlayerID , u8 byQuickTimes );

/*====================================================================
������      :RPSlowPlay
����        :����ָ�����������������ٶ�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 u8 bySlowTimes,���ͷ�����ٶ�(=2--1/2����=4--1/4����)
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPSlowPlay( u32 dwPlayerID , u8 bySlowTimes );

/*====================================================================
������      :RPDragDropPlay
����        :����ʹ��ָ���������ָ��ʱ�俪ʼ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID,��������
			 u32 dwDragDropTime���Ϸ�Ŀ��ʱ�䣨��λ�룩
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPDragDropPlay( u32 dwPlayerID , u32 dwDragDropTime );

/*====================================================================
������      :RPGetRecorderStatus
����        :��ѯָ��¼�����¼��״̬
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecorderID��¼������
			 TRecorderStatus *ptRecorderStatus��¼���״̬
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPGetRecorderStatus( u32 dwRecorderID, TRecorderStatus *ptRecorderStatus );

/*====================================================================
������      :RPGetPlayerStatus
����        :��ѯָ��������ķ���״̬
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byPlayerID����������
			 TPlayerStatus *ptPlayerStatus�������״̬
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPGetPlayerStatus( u32 dwPlayerID, TPlayerStatus *ptPlayerStatus );

/*====================================================================
������      :RPGetRecorderStatis
����        :��ѯָ��¼�����¼��ͳ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecorderID��¼������
			 TRecorderStatis *ptRecorderStatis��¼���ͳ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPGetRecorderStatis( u32 dwRecorderID, TRecorderStatis *ptRecorderStatis );

/*====================================================================
������      :RPGetPlayerStatis
����        :��ѯָ��������ķ���ͳ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byPlayerID����������
			 TPlayerStatis *ptPlayerStatis�������ͳ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
u16 RPGetPlayerStatis( u32 dwPlayerID, TPlayerStatis *ptPlayerStatis );

/*====================================================================
������      :recstatus
����        :��ӡָ��¼�����¼��״̬
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecorderID��¼������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 recstatus( u32 dwRecorderID );

/*====================================================================
������      :plystatus
����        :��ӡָ��������ķ���״̬
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID����������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 plystatus( u32 dwPlayerID );

/*====================================================================
������      :recstatis
����        :��ӡָ��¼�����ý��ͳ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byRecorderID��¼������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 recstatis( u32 dwRecorderID );

/*====================================================================
������      :plystatis
����        :��ӡָ��������ķ���ͳ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byPlayerID����������
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 plystatis( u32 dwPlayerID );

/*====================================================================
������      :RPDumpFreeRP
����        :��ӡ���õ�¼������ı��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/05	4.0		   fang hui 		����
====================================================================*/
API u16 freerp();

/*====================================================================
������      :RPVersion
����        :��ӡ¼�����汾��Ϣ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 rpver();

/*====================================================================
������      :RPHelp
����        :¼��������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/30	4.0			gie			  ����
====================================================================*/
API u16 rphelp();

/*====================================================================
������      :recinfo
����        :¼��ȫ��ͳ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
06/07/20	4.0			gie			  ����
====================================================================*/
API u16 recinfo();

/*====================================================================
������      :savestream
����        :��¼������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: u8 byRecorderID: ¼������
			  u8 byStreamId���ڼ�·����
			  u32 dwFrmNum�� Ҫ���֡��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/12	4.0			fang hui		  ����
====================================================================*/
API u16 savestream( u32 dwRecorderID, u8 byStreamId, u32 dwFrmNum );

/*====================================================================
������      :RPListFile
����        :�о�ָ��Ŀ¼�µ��ļ�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: s8 *pchPath, ָ��Ŀ¼
			  TListInfo *ptListInfo�� �ļ��б�
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/07/19	4.0			fang hui		  ����
====================================================================*/
u16 RPListFile( s8 *pchPath, TListInfo *ptListInfo );

//�õ�С�ļ��ļ��в��ų���
//pchpath��С�ļ�·��
//dwplayduration�����ų���(��λ:s)
//!!!ֻ�����ڻ�ȡС�ļ��ļ��в��ų���
u16 RPGetPlayDuration(s8* pchPath, u32& dwPlayDuration );

/*====================================================================
������      :RPDeleteFile
����        :ɾ��¼���ļ�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: s8 *pchPath, �ļ�Ŀ¼
				s8* pchName = NUL, �ļ���,��.asf��׺
				BOOL32 bBigFile = FALSE, �Ƿ���ļ�,����Ǵ��ļ�,Ҫ�����·�����ļ���
				�����С�ļ�,ֻҪ����·��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
06/02/16	4.0			gie		  ����
====================================================================*/
u16 RPDeleteFile( s8 *pchPath, s8* pchName = NULL, BOOL32 bBigFile = FALSE);

/*====================================================================
������      :RPRenameFile
����        :������ָ���ļ�
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��: s8 *pchOldName, ���ļ���
			  s8 *pchNewName�����ļ��� 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/09/26	4.0			fang hui		  ����
====================================================================*/
u16 RPRenameFile(s8 *pchOldName, s8 *pchNewName);

/*====================================================================
������      :SetRPMediaTOS
����        :����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	int nTOS, tosֵ
				int nType������	
����ֵ˵��  :��
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/11/09	4.0			fang hui		  ����
====================================================================*/
int SetRPMediaTOS( int nTOS, int nType );

/*====================================================================
������      :GetRPMediaTOS
����        :�õ�ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	int nType������	
����ֵ˵��  :��
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/11/09	4.0			fang hui		  ����
====================================================================*/
int GetRPMediaTOS( int nType );

/*====================================================================
������      :RPCreateFtpRcv
����        :����¼�����أ��õ����õ����ؽ��ձ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 *pbyFtpRcvID, ָ�����ؽ��ձ�ţ����ظ��û�			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/		
u16 RPCreateFtpRcv( u8 *pbyFtpRcvID );

/*====================================================================
������      :RPReleaseFtpRcv
����        :�ͷ�¼������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byFtpRcvID, ���ؽ��ձ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/		
u16 RPReleaseFtpRcv( u8 byFtpRcvID );

/*====================================================================
������      :RPStartFtpRcv
����        :��ʼ���ؽ���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byFtpRcvID,���ؽ��ձ��
			 TFtpRcvParam *ptFtpRcvParam,¼�����ؽ��ղ���
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/
u16 RPStartFtpRcv( u8 byFtpRcvID , TFtpRcvParam *ptFtpRcvParam );

/*====================================================================
������      :RPStopFtpRcv
����        :ֹͣ���ؽ���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byFtpRcvID,���ؽ��ձ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/
u16 RPStopFtpRcv( u8 byFtpRcvID );

/*====================================================================
������      :RPCreateFtpSnd
����        :����¼�����ط��ͣ��õ����õķ��ͱ��
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 *pbyFtpSndID, ָ�����ط��ͱ�ţ����ظ��û�			 
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/		
u16 RPCreateFtpSnd( u8 *pbyFtpSndID );

/*====================================================================
������      :RPReleaseFtpSnd
����        :�ͷ�¼�����ط���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byFtpSndID, ���ط��ͱ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/		
u16 RPReleaseFtpSnd( u8 byFtpSndID );

/*====================================================================
������      :RPSetFtpReadCallBackGran
����        :�����ļ����ؽ��Ȼص�������
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8 byFtpSndID, ���ط��ͱ��
			 u8 byGran, ���»ص��Ķ��ļ�����(����Ϊ��λ,Ӧ����[MIN_READ_CALLBACK_GRAN,MAX_READ_CALLBACK_GRAN]��Χ)
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/06/29	4.0			gie			  ����
====================================================================*/	
u16 RPSetFtpReadCallBackGran( u8 byFtpSndID, u8 byGran );

/*====================================================================
������      :RPStartFtpSnd
����        :��ʼ���ط���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byFtpSndID,���ط��ͱ��
			 TFtpSndParam *ptFtpSndParam,¼�����ط��Ͳ���
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/
u16 RPStartFtpSnd( u8 byFtpSndID , TFtpSndParam *ptFtpSndParam );

/*====================================================================
������      :RPStopFtpSnd
����        :ֹͣ���ط���
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:u8  byFtpSndID,���ط��ͱ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/12/27	4.0			gie			  ����
====================================================================*/
u16 RPStopFtpSnd( u8 byFtpSndID );

/* ע�⣺����ӿڽ���codecwrapper���ã�����ģ�鲻Ҫ���� !!! */

/*====================================================================
������      :RecDataPrc
����        :¼�����ݴ���
�㷨ʵ��    :͸����������ص�,�ṩ��codecwrapper��
����ȫ�ֱ���:
�������˵��:	PFRAMEHDR pFrmHdr, ֡ͷ
				dwContext�� ������	
����ֵ˵��  :��
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/10/19	4.0			fang hui		  ����
====================================================================*/
void RecDataPrc( PFRAMEHDR pFrmHdr, u32 dwContext );

/*====================================================================
������      :GetRecAddr
����        :�õ�¼����ĵ�ַ
�㷨ʵ��    :
����ȫ�ֱ���:
�������˵��:	u8 byRecId, ¼������
				u32 *pdwAddr, ָ���ַ��ָ��
����ֵ˵��  :�����ɹ�����RP_OK,ʧ�ܷ��ش�����
----------------------------------------------------------------------
�޸ļ�¼    :
��  ��      �汾        �޸���        �޸�����
05/10/19	4.0			fang hui		  ����
====================================================================*/
u16 GetRecAddr( u32 dwRecId, u32 *pdwAddr );

/*====================
����Ϊftp udp��ؽӿ�
����ftp�����: �ȵ���RpFtpStartSndService����ftp���ͷ���,�ٵ���RpFtpSndProbePack����
̽���
add zhx 06-04-17
=====================*/
/*===================================================================
//����ftp ����˷���
TFtpSndServParam : ���ذ������ַ
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpStartSndService(TFtpSndServParam tFtpSndServParam);

/*===================================================================
//ֹͣftp����˷���
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpStopSndService();

/*===================================================================
//ftp����˷���̽����ӿ�
u8*: Ҫ�������ݻ���
u32: Ҫ�������ݳ���
TNetAddr: Ҫ���͵ĶԶ˵�ַ
u32 dwNatIntvl = 0: ����̽�����Ƶ��(��sΪ��λ)��=0ʱ���ϲ�Ļ��巢�ͣ���ֻ����һ�Σ�
					��0ʱΪ�ײ��Ƿ��Զ����͵ı�־���Һ����ϲ�Ļ�������
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpSndProbePack(u8* pBuf,	u32 dwBufLen, TNetAddr tRemoteAddr, u32 dwNatIntvl = 0);

/*===================================================================
//ftp����˲�ѯ
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpSndQuery(TFtpSndQuery& tFtpSndQuery);


/*
�ͻ���ʹ�ã��ȵ���RpFtpRcvCreate�������ض����ڵ���RpFtpRcvSndProbe����
̽���������nat�����ʡ�ԣ���Ȼ�����RpFtpStartRcv��ʼ����
*/
/*====================================================================
//�������ؿͻ���
tlocaladdr: ���ذ������ַ
pdwssid����ʶ��
��ȷ���أ�rp_ok
====================================================================*/
u16 RpFtpRcvCreate(TNetAddr& tLocalAddr, u32* pdwSsid );

/*====================================================================
//�ͻ��˷���̽���,  !!!!!ÿ����һ�Σ�ֻ����һ��,���Ҫ���������ϲ�ҲҪ��
�������ݷŵ�pbuf�ע����ϴ������ݳ��ȣ�rpctrlֻ��͸��ת��
dwssid: �ͻ��˱�ʶ��
tremoteaddr:�Զ������ַ
pbuf: �û�����
dwbuflen: �û����峤��
��ȷ����:rp_ok
====================================================================*/
u16 RpFtpRcvSndProbe(u32 dwSsid, TNetAddr& tRemoteAddr, u8* pBuf, u32 dwBufLen );

/*===================================================================
//ftp�ͻ����������ؽӿ�
TFtpUdpRcvParam: ���ز���
u32*: ����ssid��ʾ��
u32 dwNatIntvl = 0: ����̽�����Ƶ��(��sΪ��λ)��0ʱΪ����nat����0ʱΪ��nat
!!!!!!!ֻ�Զ�����̽���10�Σ����û�л�Ӧ������ʧ��
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpStartRcv(TFtpUdpRcvParam tFtpRcvParam, u32 dwSsid, u32 dwNatIntvl/*=0*/);

/*===================================================================
//ftp�ͻ��˽������ؽӿ�
dwSsid: ���ر�ʾ��
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpStopRcv(u32 dwSsid);

/*===================================================================
//ftp�ͻ��˲�ѯ
u32: ��ʾ��
TFtpRcvQuery: 
��ȷ����: rp_ok
====================================================================*/
u16 RpFtpRcvQuery(u32 dwSsid, TFtpRcvQuery& tFtpRcvQuery);

u16 RpSetMediaStreamCallback(u32 dwRecorderId, MediaStreamCallBack pfCB, u32 dwContext, BOOL32 bRec);

API void rpftpdebug(BOOL32 bDebug);

u16 RPSetFECEnable(u32 dwPlayerID, BOOL32 bEnable, u8 byStreamId);

u16 RPSetFECPackLEn(u32 dwPlayerID, u16 wLen, u8 byStreamId);

u16 RPSetFECInterFrame(u32 dwPlayerID, BOOL32 bInterFrame, u8 byStreamId);

u16	RPSetFECModeu32(u32 dwPlayerID, u8 byMode, u8 byStreamId);

u16 RPSetFECXY(u32 dwPlayerID, s32 nDataPackNum, s32 nCRCPackNum, u8 byStreamId);

#endif  //_RPCtrl_H_
