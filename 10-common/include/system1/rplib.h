/*****************************************************************************
ģ����      : RPLIB
�ļ���      : RPlib.h
����ļ�    : RPlib.cpp
�ļ�ʵ�ֹ���: ¼������ṩ���ϲ��ͷ�ļ�
����        : κ�α�
�汾        : V2.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2002/07/01  0.9         κ�α�      Create
2003/07/11  2.0         κ�α�      ����ע�����Ż�
2003/10/14  2.0         ����      ���ӽӿ�
******************************************************************************/

#ifndef _RPLib_H_
#define _RPLib_H_



//ģ��汾��Ϣ�ͱ���ʱ�� �� �����Ŀ�İ汾�ͱ���ʱ��
extern "C" __declspec( dllexport ) void rplibver();


//ģ�������Ϣ �� �����Ŀ�İ�����Ϣ
extern "C" __declspec( dllexport ) void rplibhelp();



#define  RP_MAX_RECORDER_NUMBER	            8//
#define  RP_MAX_PLAYER_NUMBER	            8//
#define  RP_MAX_RECORDER_AND_PLAYER_NUMBER  16//


#define  RECORDER_MIN_SPACE     		    (u32)200 // ¼��ı����ռ� 


#define  RP_OK                 		        (u16)0    // RP������ɹ� 
#define  RPERR_BASE_CODE       		        (u16)20000// �������׼ֵ

//¼�����������������ߣ��޷�����¼��������������
#define  RPERR_EXCEEDMAXRECORDER_PLAYERNUM  (u16)(RPERR_BASE_CODE + 1)
//�ڴ�������
#define  RPERR_OUTOFMEMORY                  (u16)(RPERR_BASE_CODE + 2)
//������Ϊ��,����û�г�ʼ��RP��
#define  RPERR_RPNULLPTRMANAGER             (u16)(RPERR_BASE_CODE + 3)
//��������Recorder��Ŀ
#define  RPERR_EXCEEDMAXRECORDERNUM         (u16)(RPERR_BASE_CODE + 4)
//��������Player��Ŀ
#define  RPERR_EXCEEDMAXPLAYERNUM           (u16)(RPERR_BASE_CODE + 5)
//�����ҵ�RecorderID, �����ID�����Ѿ��ͷ�
#define  RPERR_NOTFOUNDRECORDERID           (u16)(RPERR_BASE_CODE + 6)
//�����ҵ�PlayerID, �����ID�����Ѿ��ͷ�
#define  RPERR_NOTFOUNDPLAYERID             (u16)(RPERR_BASE_CODE + 7)
//����Ĵ���AVI�ļ�
#define  RPERR_FAILURECREATEAVIFILE         (u16)(RPERR_BASE_CODE + 8)
//����Ĵ�����ƵSocket
#define  RPERR_FAILURECREATEVIDEOSOCKET     (u16)(RPERR_BASE_CODE + 9) 
//����Ĵ�����ƵSocket
#define  RPERR_FAILURECREATEAUDIOSOCKET     (u16)(RPERR_BASE_CODE + 10)
//�Ƿ���Socke���
#define  RPERR_INVALIDSOCKETHANDLE          (u16)(RPERR_BASE_CODE + 11)
//ʧ�ܵ�����Socket���¼�
#define  RPERR_FAILURESETREADEVENT          (u16)(RPERR_BASE_CODE + 12)
//¼��������ʧ��
#define  RPERR_RECORDERSTARTFAILED          (u16)(RPERR_BASE_CODE + 13) 
//¼������ͣʧ��
#define  RPERR_RECORDERPAUSEFAILED          (u16)(RPERR_BASE_CODE + 14)
//¼��������ʧ��
#define  RPERR_RECORDERCONTINUEFAILED       (u16)(RPERR_BASE_CODE + 15)
//¼����ֹͣʧ��
#define  RPERR_RECORDERSTOPFAILED           (u16)(RPERR_BASE_CODE + 16)
//¼�����Ѿ���ɾ���ӹ�������
#define  RPERR_NOFOUNDRECORDER              (u16)(RPERR_BASE_CODE + 17)
//�Ƿ���¼��ģʽ
#define  RPERR_INVAIDRECORDEREMODE          (u16)(RPERR_BASE_CODE + 18)
//����AVI�ļ�  
#define  RPERR_BADAVIFILE                   (u16)(RPERR_BASE_CODE + 19)

#define RECORDER_ALREADY_EXIT               (u16)(RPERR_BASE_CODE + 20)
#define RECORDER_CANNOT_BE_FOUND            (u16)(RPERR_BASE_CODE + 21)

#define PLAYER_ALREADY_EXIT                 (u16)(RPERR_BASE_CODE + 22)
#define PLAYER_CANNOT_BE_FOUND              (u16)(RPERR_BASE_CODE + 23)
//����ȷ��recorder ID 
#define RPERR_INVALID_RECORDER_ID           (u16)(RPERR_BASE_CODE + 24)
//��ʱ����������ȷ    
#define RPERR_TIMER_SET_PARAM               (u16)(RPERR_BASE_CODE + 25)
//��ʱ��ע����߳���
#define RPERR_TIMER_FULL_THREAD             (u16)(RPERR_BASE_CODE + 26)
//socket startup error; 
#define RPERR_SOCK_INIT                     (u16)(RPERR_BASE_CODE + 27)
//¼���߳�Ϊ��
#define RPERR_REC_THREAD_NULL               (u16)(RPERR_BASE_CODE + 28)
//����Mediasignal param����ȷ
#define RPERR_MEDIA_SIGNAL_PARAM            (u16)(RPERR_BASE_CODE + 29)
//�����ڴ����
#define RPERR_NO_MEMORY                     (u16)(RPERR_BASE_CODE + 30)
//���������շ�ģ��error;
#define RPERR_MEDIANET_CREATE               (u16)(RPERR_BASE_CODE + 31)
//�����շ�ģ�����ò�������
#define RPERR_MEDIANET_SETPARAM             (u16)(RPERR_BASE_CODE + 32)
//Mediasignal ��������
#define RPERR_MEDIASIGNAL_CREATE            (u16)(RPERR_BASE_CODE + 33)
//����ѭ���������  
#define RPERR_RPBUF_PARAM                   (u16)(RPERR_BASE_CODE + 34)
//ѭ�������
#define RPERR_RPBUF_NULL                    (u16)(RPERR_BASE_CODE + 35)
//ѭ���������
#define RPERR_RPBUF_INVALID                 (u16)(RPERR_BASE_CODE + 36)
//ѭ��������
#define RPERR_RPBUF_FULL                    (u16)(RPERR_BASE_CODE + 37)
//��Ч�Ĳ���id;
#define RPERR_INVALID_PALYER_ID             (u16)(RPERR_BASE_CODE + 38)
//�����߳̿�
#define RPERR_PLAY_THREAD_NULL              (u16)(RPERR_BASE_CODE + 39)
//playsignal ��������
#define RPERR_PLAYSIGNAL_CREATE             (u16)(RPERR_BASE_CODE + 40)
//·���� 
#define RPERR_LISTTAPE_PATH_NULL            (u16)(RPERR_BASE_CODE + 41)
//�����·����
#define RPERR_LISTTAPE_PATH_INVALID         (u16)(RPERR_BASE_CODE + 42)
//Ŀǰ����֧��
#define RPERR_NO_SURPORT                    (u16)(RPERR_BASE_CODE + 43)
//��ȡ����ʣ��ռ����
#define RPERR_FREE_SPACE                    (u16)(RPERR_BASE_CODE + 44) 
//ɾ��һ��¼���ļ�����
#define RPERR_DELETE_ONE_FILE               (u16)(RPERR_BASE_CODE + 45) 
//����¼����¼�Ʒ�����������
#define RPERR_RECORD_METHOD_PARAM           (u16)(RPERR_BASE_CODE + 46) 

//�����ļ����������ݿ����������Ч
#define RPERR_OPEN_DB_PARAM		            (u16)(RPERR_BASE_CODE + 47) 
//�����ݿ����ӵĲ���ʧ��
#define RPERR_OPEN_DB			            (u16)(RPERR_BASE_CODE + 48) 
//���ݿ�û�н������Ӳ������Դ��ڹر�״̬
#define RPERR__DB_CLOSE_STATUS		        (u16)(RPERR_BASE_CODE + 49) 
//�����ļ�����ʧ��
#define RPERR__DB_INSERT_METHOD		        (u16)(RPERR_BASE_CODE + 50) 
//ȡ�������ļ�����ʧ��
#define RPERR__DB_CANCEL_METHOD		        (u16)(RPERR_BASE_CODE + 51) 
//��ѯ�ļ�����״̬����ʧ��
#define RPERR__DB_QUERY_METHOD		        (u16)(RPERR_BASE_CODE + 52) 

#define RPERR_SET_VID_ACTIVEPT              (u16)(RPERR_BASE_CODE + 53) // ������Ƶ��/����̬�غ�ʧ��
#define RPERR_SET_AUD_ACTIVEPT              (u16)(RPERR_BASE_CODE + 54) // ������Ƶ��/����̬�غ�ʧ��

#define RPERR_SET_VID_ENCRYPTKEY            (u16)(RPERR_BASE_CODE + 55) // ������Ƶ����keyʧ��
#define RPERR_SET_AUD_ENCRYPTKEY            (u16)(RPERR_BASE_CODE + 56) // ������Ƶ����keyʧ��
#define RPERR_SET_VID_DECRYPTKEY            (u16)(RPERR_BASE_CODE + 57) // ������Ƶ����keyʧ��
#define RPERR_SET_AUD_DECRYPTKEY            (u16)(RPERR_BASE_CODE + 58) // ������Ƶ����keyʧ��

// ¼�����ͷ������Ļص�֪ͨ����ֵ
enum EmRecordMode
{
	rVideoOnly = 1, 
	rAudioOnly = 2,
	rBoth      = 3,	
	rNothing   = 100,
};

// ״̬
enum EmState
{
	rRunning		= 10,	//¼��������
	rPausing		= 11,	//¼������ͣ
	rStopping		= 12,   //¼����ֹͣ
	
	pRunning		= 20,   //����������
	pPausing		= 21,   //��������ͣ 
	pStopping		= 22,   //¼����ֹͣ
	pEnding			= pStopping, 
	
	pForwarding		= 23,   //���
	pBackwarding	= 24,   //����
};

// ���������ļ�λ�õĻ�׼��
enum EMPlayerStartPoint
{
	BEGIN_POSITION = 0,
	CURRENT_POSITION = 1,
	END_POSITION = 2,
};


enum EMNotifyType
{
	emNotify_RecorderOK		    = 1,   //¼��״̬�ı�
	emNotify_RecorderFullDisk	= 2,   //������

	emNotify_PlayerOK       	= 1000,	//����״̬�ı� 
	emNotify_PlayerEmptyFile	= 1001, //���ļ�, �쳣
	emNotify_PlayerFinishTask	= 1002, //�������
	emNotify_PlayerPlayProcess	= 1003, //�������
};

typedef struct stMP4SourceInfo
{
	u8 SignalID;//��0��ʼ���
	//CString strSignalName;
	u16 wLocalAudioPort;
	u16 wLocalVideoPort;
	u32 dwVideoIPAddress;
	u16 wVideoPort;
	u32 dwAudioIPAddress;
	u16 wAudioPort;
	EmRecordMode emMode;
} MP4SOURCEINFO, *PMP4SOURCEINFO;

#define MAX_SIGNAL_NUMBERS 4

typedef struct stMP4Sources
{
	u8 SignalNumber;
	MP4SOURCEINFO m_MP4SourceInfo[MAX_SIGNAL_NUMBERS];
}MP4SOURCES;

/*ͳ����Ϣ*/
typedef struct tagRPLibKdvRcvStatistics
{
	u32      m_dwPackNum;/*�ѽ��յİ���*/
	u32      m_dwPackLose;/*�G����*/
}TRPLibKdvRcvStatistics;

// ¼����״̬
struct TRecorderStatus
{
	u16	RecorderID;
	u32	dwRecordSeconds;			//һ��¼��ʱ�䳤��(��λ��)
	s8	chCurrentRecordFileName[MAX_PATH];	//��ǰ����¼���ļ�������
	EmState emRecordState;			//״̬ö�ٱ���
	u32 	dwFileSize;				//file length already recorded	

	TRPLibKdvRcvStatistics tVideoRcvStatistics;
	TRPLibKdvRcvStatistics tAudioRcvStatistics;

	MP4SOURCES tRecordAddressInfo;  //����Ƶ�շ���ַ��Ϣ
};

// ������״̬
struct TPlayerStatus
{
	u16	PlayerID;
	u32	dwPlaySeconds;         //һ���ŵ�ʱ�䳤��(��λ��)
	s8	chCurrentPlayFileName[MAX_PATH]; //��ǰ���ڷŵ��ļ�������
	
	u32	dwVideoPacketNum;      //��Ƶ����Ŀ
	u32	dwAutioPacketNum;      //��Ƶ����Ŀ
	EmState emPlayerState;     // ״̬����Ϊ���С���ͣ��ֹͣ
	
	u32	dwTapeLengthInSeconds; //¼��ʱ�䳤��(��λ��)

	MP4SOURCES tPlayerAddressInfo; //����Ƶ�շ���ַ��Ϣ
};

struct TRPLibNotification
{
	EMNotifyType    emNotificationType;
	TRecorderStatus tRecorderStatus; 
	TPlayerStatus   tPlayerStatus; 
};

#ifndef DES_ENCRYPT_MODE
#define DES_ENCRYPT_MODE         (u8)0      //DES����ģʽ
#define AES_ENCRYPT_MODE         (u8)1      //AES����ģʽ
#define ENCRYPT_KEY_SIZE         (u8)32     //��Կ���� ȡ���еĽϴ�ֵ
#define DES_ENCRYPT_KEY_SIZE     (u8)8      //DES��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_A (u8)16  //AES Mode-A ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_B (u8)24  //AES Mode-B ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_C (u8)32  //AES Mode-C ��Կ����
#endif


/*
����¼�������Ļص�����
wRecorderID ¼������ID
emType ֪ͨ����
*/
typedef VOID (CALLBACK* RPCallBack) ( u16 wID, TRPLibNotification* pRPNotification, 
				                      u32 pParam );

//----------------------------------------------------------------------
u16 rpInit(u16 wMaxRecorder = 0x1, u16 wMaxPlayer = 0x1); //��ʼ��¼�����
u16 rpRelease(VOID); 					  //����¼�����--�������ü�����

/*
ע��¼�����ص�����
pCallBack ¼�����ص�����ָ��
*/
u16 rpRegisterRecorderCallBack(RPCallBack pCallBack, const u32 pParam); 

/*
����¼����
wRecorderID ¼����ID��
*/
//���ⲿ����ID
u16 rpCreateRecorder(u16 wRecorderID); 

/*
����¼����
wRecorderID ¼����ID��
*/
u16 rpDestroyRecorder(u16 wRecorderID); 


/*
��ʼ¼��
wRecorderID ¼����ID��
pFileName ¼���ļ�·�� and it includes directory info!! if there is no directory, then it will return fales.
dwIpAddress IP��ַ
wPort �˿ں�
RecorMode Recordģʽ
*/
u16 rpStartRecord(u16 wRecorderID, s8 *pszFileName, MP4SOURCES &tMP4Sources); 
u16 rpStartRecord(u16 wRecorderID, s8 *pszFileName, 
		          u32 dwVideoIPAddress, u16 wVideoPort, u32 dwAudioIPAddress, u16 wAudioPort, 
		          EmRecordMode emMode); 
u16 rpStartRecord(u16 wRecorderID, s8 *pszFileName, 
		          u32 dwIPAddress, u16 wPort, 
		          EmRecordMode emMode); 

/* 
���� ��Ƶ ��̬��Ƶ�غɵ� Playloadֵ
wRecorderID   ¼����ID��
byRmtActivePT ���յ��Ķ�̬�غɵ�Playloadֵ, �ɶԺ�ʱԼ��
byRealPT      �ö�̬�غ�ʵ�ʴ���ĵ�Playload���ͣ���ͬ�����Ƿ���ʱ��PTԼ��
*/
u16 rpSetVidRcvActivePT( u16 wRecorderID, u8 byRmtActivePT, u8 byRealPT );

/* 
���� ��Ƶ ��̬��Ƶ�غɵ� Playloadֵ
wRecorderID   ¼����ID��
byRmtActivePT ���յ��Ķ�̬�غɵ�Playloadֵ, �ɶԺ�ʱԼ��
byRealPT      �ö�̬�غ�ʵ�ʴ���ĵ�Playload���ͣ���ͬ�����Ƿ���ʱ��PTԼ��
*/
u16 rpSetAudRcvActivePT( u16 wRecorderID, u8 byRmtActivePT, u8 byRealPT );

/* 
���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
wRecorderID   ¼����ID��
pszKeyBuf     ������Կ����ָ��
pszKeyBuf     ������Կ����
byDecryptMode ����ģʽ
*/
u16 rpSetVidDecryptKey( u16 wRecorderID, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode );

/* 
���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
wRecorderID   ¼����ID��
pszKeyBuf     ������Կ����ָ��
pszKeyBuf     ������Կ����
byDecryptMode ����ģʽ
*/
u16 rpSetAudDecryptKey( u16 wRecorderID, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode );

/* 
��ͣ¼��
wRecorderID ¼����ID��
*/
u16 rpPauseRecord(u16 wRecorderID); 

/*
����¼��
wRecorderID ¼����ID��
*/
u16 rpResumeRecord(u16 wRecorderID); 

/*
ֹͣ¼��
wRecorderID ¼����ID��
*/
u16 rpStopRecord(u16 wRecorderID); 

/*
�õ�¼������״̬
wRecorderID ¼����ID��
tRecorderStatus ��¼ͳ��״̬
*/
u16 rpGetRecorderStatus(u16 wRecorderID, TRecorderStatus &tRecorderStatus); 

/*/*��ѯ�ļ������߼��������д�С
pszFileName �ļ�·��
nFreeSpace  ���صĿ��д�С,��λMb.
nTotalSpace  ���ص��ܴ�С,��λMb.
*/
u16 rpGetSpaceInfo(s8 *strPath, INT32 &nFreeSpace, INT32 &nTotalSpace);

/*
����¼����¼�Ʒ�������֡¼���������¼��,�����Ƶ֡����
�����趨��
wRecorderID ¼����ID��
bOnlySaveKeyFrame   �Ƿ���г�֡¼��ֻ��ȡ�ؼ�֡����¼��
dwSaveFrameInterval ��֡¼��Ĺؼ�֡��������� 0 �� ��ʾ�����, 1 �� ��ʾ���1֡�ؼ�֡
*/
u16 rpSetRecorderSaveMethod(u16 wRecorderID,
			    BOOL32 bOnlySaveKeyFrame = FALSE, 
			    u32 dwSaveFrameInterval = 0);
/*
����¼������Сʣ��Ŀռ�
����һ���趨ǰ���е�¼���������ô��趨ֵ
�����趨��
dwMinFreeSize   ��Сʣ��Ŀռ��С����λMB��,Ĭ��ֵ RECORDER_MIN_SPACE==200MB
*/
u16 rpSetMinFreeSpaceSize(u32 dwMinFreeSize = RECORDER_MIN_SPACE);


//¼���ļ������߷�������

/*
�����ݿ�����
�����趨��
szHostIP   ���ݿ�ip
szUserName ���ݿ�����������û���
szPwd      ���ݿ��������������,����Ϊ��
*/
u16 rpOpenDB(s8 *szHostIP, s8 *szUserName, s8 *szPwd);

/*
�ر����ݿ�����
*/
u16 rpCloseDB();

/*
����һ��¼���ļ�
�����趨��
szFilePath  ¼���ļ�������mms·�����������ļ�������չ��,��mms������������¼��
			��Ӧ����mms�û������� ��ʽΪmms://admin:admin/100.8.1.4/VodFtpPath��
szFileName  ¼���ļ����ļ�����������չ����
bSecret	    ¼���ļ��Ƿ񷢲�Ϊ�����ļ�,TRUE-��
*/
u16 rpPublishOneFile(s8 *szFilePath, s8 *szFileName, BOOL32 bSecret);

/*
ȡ��һ���Ѿ�������¼���ļ�
�����趨��
szFilePath  ¼���ļ�������mms·�����������ļ�������չ��,��mms������������¼��
	    ��Ӧ����mms�û������� ��ʽΪmms://admin:admin/100.8.1.4/VodFtpPath��
szFileName  ¼���ļ����ļ�����������չ����
*/
u16 rpCancelOnePublishedFile(s8 *szFilePath, s8 *szFileName);

/*
��ѯһ��¼���ļ��ķ���״̬
�����趨��
bPublished   �Ƿ��ڷ���״̬
szFilePath  ¼���ļ�������ftp·�����������ļ�������չ��,��ftp������������¼��
			��Ӧ����ftp�û������� ��ʽΪftp://admin:admin/100.8.1.4/VodFtpPath��
szFileName  ¼���ļ����ļ�����������չ����
*/
u16 rpQueryOneFileStauts(s8 *szFilePath, s8 *szFileName, BOOL32 &bPublished);

//---------------------------------------------------------------------------------


#define MAX_TAPE_NUMBER 100

struct TapeInfo
{
	s8      m_strFileNames[MAX_PATH]; // �ļ���
	u32     m_dwLength; //tape length in milliseconds
	time_t  m_ttFileTime;//���һ���޸�ʱ��
	u8      m_StreamNumber;
};

struct TapeInfoList
{
	u8 	 m_byNum;
	TapeInfo m_tTapeIfo[MAX_TAPE_NUMBER];
};

/*
¼����б�
strPath is the default directory of saved AVI files
pFileName ���ŵ��ļ���
*/

u16 rpListTapes(s8* strPath, TapeInfoList &TapeCollections); 

/*
����������
wPlayerID ������״̬
*/
u16 rpCreatePlayer(u16 wPlayerID); 

/*
���ٷ�����
wPlayerID ������ID
*/
u16 rpDestroyPlayer(u16 wPlayerID); 

/* 
���� ��Ƶ ��̬��Ƶ�غɵ� Playloadֵ
wPlayerID       ������ID
byLocalActivePT ���͵Ķ�̬�غɵ�Playloadֵ, �ɶԺ�ʱԼ��
*/
u16 rpSetVidSndActivePT( u16 wPlayerID, u8 byLocalActivePT );

/* 
���� ��Ƶ ��̬��Ƶ�غɵ� Playloadֵ
wPlayerID       ������ID
byLocalActivePT ���͵Ķ�̬�غɵ�Playloadֵ, �ɶԺ�ʱԼ��
*/
u16 rpSetAudSndActivePT( u16 wPlayerID, u8 byLocalActivePT );

/* 
���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
wPlayerID     ������ID
pszKeyBuf     ������Կ����ָ��
wKeySize      ������Կ����
byEncryptMode ����ģʽ
*/
u16 rpSetVidEncryptKey( u16 wPlayerID, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );

/* 
���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
wPlayerID     ������ID
pszKeyBuf     ������Կ����ָ��
wKeySize      ������Կ����
byEncryptMode ����ģʽ
*/
u16 rpSetAudEncryptKey( u16 wPlayerID, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );

/*
��ʼ����
wPlayerID ������ID
pFileName ���ŵ��ļ���
dwIpAddress ���͵�IP��ַ
wPort ���͵Ķ˿ں�
dwFileSeconds ���ļ���ָ����λ�ÿ�ʼ����
*/
u16 rpStartPlay(u16 wPlayerID, s8 *pszFileName, u16 wLocalPort, 
		u32 dwIpAddress, u16 wPort,
		EmRecordMode emMode, u32 dwFileSeconds = 0xffffffff); 
u16 rpStartPlay(u16 wPlayerID, s8 *pszFileName, 
		u16 wLocalAudioPort, u16 wLocalVideoPort, 
		u32 dwAudioIpAddress, u16 wAudioPort, 
		u32 dwVideoIpAddress, u16 wVideoPort,
		EmRecordMode emMode, u32 dwFileSeconds = 0xffffffff);
u16 rpStartPlay(u16 wPlayerID, s8 *pszFileName,
		MP4SOURCES &tMP4Sources, u32 dwFileSeconds = 0xffffffff);
				 
/*
��ͣ����
wPlayerID ������ID
*/
u16 rpPausePlay(u16 wPlayerID); 

/*
��ͣ����
wPlayerID ������ID
*/
u16 rpContinuePlay(u16 wPlayerID); 

/*
ֹͣ����
wPlayerID ������ID
*/
u16 rpStopPlay(u16 wPlayerID); 

/*
���ò���λ��
wPlayerID ������ID
wOffsetSeconds ƫ����
wBasePoint ��׼�� -- ��ʼ,��ǰ,�ļ�β.
if the current status is End/Pause, then it will???
*/
u16 rpSetPlayPosition(const u16 wPlayerID, const u16 wOffsetSeconds = 0, 
		      const EMPlayerStartPoint emBasePoint = BEGIN_POSITION); 

/*
������ǰ����(�����ؼ�֡)
wPlayerID ������ID
*/

u16 rpFastForward(u16 wPlayerID); 

/*
������󲥷�(�����ؼ�֡)
wPlayerID ������ID
*/
u16 rpFastBackward(u16 wPlayerID); 

/*
�õ�������״̬
wPlayerID ������ID
tPlayerStatus ������״̬
*/
u16 rpGetPlayerStatus(u16 wPlayerID, TPlayerStatus &tPlayerStatus); 

/*
ɾ��һ��asf¼���ļ�
pszFileName Ҫɾ�����ļ���
*/
u16 rpDeleteOneFile(s8 *pszFileName); 


#endif  //_RPLib_H_









