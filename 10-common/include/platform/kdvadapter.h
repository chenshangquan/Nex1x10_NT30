 /*****************************************************************************
   ģ����      : HardAdapter
   �ļ���      : KdvAdapter.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: Ӳ�������������ϲ�API ��װ
   ����        : ���
   �汾        : V3.0  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���         �޸�����
   2003/12/03  3.0         ���           ����
******************************************************************************/
#ifndef _KDVADAPTER_H_
#define _KDVADAPTER_H_

#include "codeccommon.h"

//�궨��
#define MAX_VIDEO_ADAPT_CHANNUM       1
#define MAX_AUDIO_ADAPT_CHANNUM       3
#define MAX_ADAPT_CHNNUM              (MAX_VIDEO_ADAPT_CHANNUM+MAX_AUDIO_ADAPT_CHANNUM)

#define MAX_TRANS_VIDEO_ADAPT_CHANNUM       20
#define MAX_TRANS_AUDIO_ADAPT_CHANNUM       20

/*ͼ���������
#define  MEDIA_TYPE_MP4	     (u8)97//MPEG-4
#define  MEDIA_TYPE_H261	 (u8)31//H.261
#define  MEDIA_TYPE_H263	 (u8)34//H.263
//������������
#define	 MEDIA_TYPE_MP3	         (u8)96//mp3 mode 0-4
#define  MEDIA_TYPE_PCMA		 (u8)8//G.711 Alaw  mode 5
#define  MEDIA_TYPE_PCMU		 (u8)0//G.711 ulaw  mode 6
#define	 MEDIA_TYPE_G7231		 (u8)4//G.7231 reservation
#define	 MEDIA_TYPE_G728		 (u8)15//G.728 reservation
#define	 MEDIA_TYPE_G729		 (u8)18//G.729 reservation
*/

//Map ����
typedef struct
{
	u8    byMapId;   //Map��
    u32   dwCoreSpd; //Map�ں��ٶ�
    u32   dwMemSpd;  //�ڴ��ٶ�
    u32   dwMemSize; //�ڴ��С
}TAdapterMap;

//�����ַ
/*typedef struct
{
    u32   dwIp;     //Ip��ַ(������) 
	u16    wPort;    //�˿ں�(������) 
}TNetAddress;
*/

/*��Ƶ�������*/
typedef struct
{
    u8  byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u8  byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8  byMaxQuant;  /*�����������(2-31)*/
    u8  byMinQuant;  /*��С��������(2-31)*/
    u16  wBitRate;    /*���������(Kbps)*/
	u32 dwSndNetBand;/*���緢�ʹ���(��λ:Kbps,1K=1024)*/   
	u8  byFrameRate;  /*֡��(default:25)*/	
	u8  byImageQulity;/*ͼ��ѹ������(1-5)*/
	u16  wVideoWidth;  /*ͼ����(default:640)*/
	u16  wVideoHeight; /*ͼ��߶�(default:480)*/
}TAdapterVideoEncParam;

/* ��Ƶ������� */
typedef struct
{
	u8  byAudioEncMode; /*��������ģʽ*/
	u8  byAudioDuration;/*ʱ��*/
}TAdapterAudioEncParam;

/* ������������� */
typedef union
{
//   TAdapterVideoEncParam tVideoEncParam;
	TVideoEncParam          tVideoEncParam;
    TAdapterAudioEncParam   tAudioEncParam;
}TAdapterEncParam;

//����ͨ��
typedef struct
{
	u8 byChnNo;//ͨ����
	u8 byMediaType;//Ŀ����������(����ָ��)
	TAdapterEncParam  tAdapterEncParam; // �������
    TNetAddress tSrcNetAddr;   //ͨ��Դ��ַ
	TNetAddress tRtcpBackAddr;
	TNetAddress tDstNetAddr;   //ͨ��Ŀ�ĵ�ַ
	TNetAddress tBindAddr;     //�����ַ
}TAdapterChannel;

//������״̬
typedef struct
{
    BOOL32     bAdapterStart;      //�����Ƿ�ʼ
	u8     byCurChnNum;  //Ŀǰ���������ͨ����Ŀ
    TAdapterChannel atChannel[MAX_ADAPT_CHNNUM];  //���е�ͨ��
}TAdapterGroupStatus;

//ͨ��ͳ����Ϣ
typedef struct	
{
	u32  dwRecvBitRate;        //��������
    u32  dwRecvPackNum;        //�յ��İ���
	u32  dwRecvLosePackNum;    //������ն�����
    u32  dwSendBitRate;        //��������
	u32  dwSendPackNum;        //���͵İ���
	u32  dwSendLosePackNum;    //���Ͷ�����
	BOOL32 m_bVidCompellingIFrm;	//�Ƿ�Ҫǿ�ƹؼ�֡
}TAdapterChannelStatis;

typedef struct
{
	u32   dwDspNo;
	u32   dwCoreSpd; 
	u32   dwMemSpd;  
	u32   dwMemSize; 
	u32   dwChnNum;
}TAdapterCheckParam;

class CVideoEncoder;
class CAudioEncoder;
class CVideoDecoder;
class CAudioDecoder;

class CKdvAdapterGroup
{
public:
    CKdvAdapterGroup ();
    virtual ~ CKdvAdapterGroup ();

public:
	u16 CreateGroup(const TAdapterMap *ptAdapterMap, u8 byVideoChnNum, u8 byAudioChnNum);// ����������
	u16 StartGroup(void);//��ʼ����		   
   	u16 StopGroup(void);//ֹͣ����	
    u16 DestroyGroup(void);//�˳���

	u16 AddVideoChannel(const TAdapterChannel * ptAdpChannel); //���ͼ��ͨ��
	u16 RemoveVideoChannel(u8 byChnNo); //ɾ��ͼ��ͨ��
	u16 AddAudioChannel(const TAdapterChannel * ptAdpChannel); //�������ͨ��
	u16 RemoveAudioChannel(u8 byChnNo); //ɾ������ͨ��

    u16 GetGroupStatus(TAdapterGroupStatus &tAdapterGroupStatus); //�õ����״̬
    u16 GetAudioChannelStatis(u8 byChnNo, TAdapterChannelStatis &tAdapterChannelStatis); //�õ���Ƶͨ����ͳ����Ϣ
	u16 GetVideoChannelStatis(u8 byChnNo, TAdapterChannelStatis &tAdapterChannelStatis); //�õ���Ƶͨ����ͳ����Ϣ

	u16 ChangeVideoEncParam(u8 byChnNo, TVideoEncParam  * ptVidEncParam);     //�ı���Ƶ����������
	u16 ChangeAudioEncParam(u8 byChnNo, u8 byMediaType, TAdapterAudioEncParam * ptAudEncParam);     //�ı���Ƶ���������� 
	u16 ChangeVideoDecParam(u8 byChnNo, TVideoDecParam  * ptVidDecParam);     //�ı���Ƶ����������

	/*����ͼ�����������ش�����*/
	u16  SetNetRecvFeedbackVideoParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE);
	/*����ͼ������緢���ش�����*/
	u16  SetNetSendFeedbackVideoParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	/*������������������ش�����*/
	u16  SetNetRecvFeedbackAudioParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE);
	/*�������������緢���ش�����*/
	u16  SetNetSendFeedbackAudioParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	
	//������Ƶ�����غ�PTֵ
	u16  SetAudEncryptPT(u32 dwChnNo, u8 byEncryptPT);
	//������Ƶ�������key�ִ��Լ� ����ģʽ Aes or Des
	u16  SetAudEncryptKey(u32 dwChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );

	//������Ƶ�����غ�PTֵ
	u16  SetVidEncryptPT(u32 dwChnNo, u8 byEncryptPT);
	//������Ƶ�������key�ִ��Լ� ����ģʽ Aes or Des
	u16  SetVidEncryptKey(u32 dwChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );  
	
	//���� H.263+/H.264 �ȶ�̬��Ƶ�غɵ� Playloadֵ
	u16  SetVideoActivePT(u32 dwChnNo, u8 byRmtActivePT, u8 byRealPT );
	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16  SetVidDecryptKey(u32 dwChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
	
	//���� ��̬��Ƶ�غɵ� Playloadֵ
	u16  SetAudioActivePT(u32 dwChnNo, u8 byRmtActivePT, u8 byRealPT );
	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16  SetAudDecryptKey(u32 dwChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
	
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetVidFecEnable(u32 dwChnNo, BOOL32 bEnableFec);
	//����fec���а�����
	u16    SetVidFecPackLen(u32 dwChnNo, u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetVidFecIntraFrame(u32 dwChnNo, BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetVidFecMode(u32 dwChnNo, u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetVidFecXY(u32 dwChnNo, s32 nDataPackNum, s32 nCrcPackNum);
	

	void  ShowChnInfo(u32 chnNo, BOOL32 bVidChn);
	
	u16 SetFastUpdata();
	u16 VpuInitProc(const TAdapterMap *ptAdapterMap);

protected:
	CVideoEncoder    *m_apVideoEncoder[MAX_VIDEO_ADAPT_CHANNUM];
	CVideoDecoder    *m_apVideoDecoder[MAX_VIDEO_ADAPT_CHANNUM];
	CAudioEncoder    *m_apAudioEncoder[MAX_AUDIO_ADAPT_CHANNUM];
	CAudioDecoder    *m_apAudioDecoder[MAX_AUDIO_ADAPT_CHANNUM];

	CVideoEncoder    *m_apTransVideoEncoder[MAX_TRANS_VIDEO_ADAPT_CHANNUM];
	CVideoDecoder    *m_apTransVideoDecoder[MAX_TRANS_VIDEO_ADAPT_CHANNUM];
	CAudioEncoder    *m_apTransAudioEncoder[MAX_TRANS_AUDIO_ADAPT_CHANNUM];
	CAudioDecoder    *m_apTransAudioDecoder[MAX_TRANS_AUDIO_ADAPT_CHANNUM];

	u32 m_bAdapterStart;
	u32 m_dwMaxVidChnNum;
	u32 m_dwMaxAudChnNum;
	u32 m_dwNoDsp;
	s64 m_qwLastFastupdataTime;

	TAdapterChannel  m_tVidAdtGrpStat[MAX_VIDEO_ADAPT_CHANNUM];
	TAdapterChannel  m_tAudAdtGrpStat[MAX_AUDIO_ADAPT_CHANNUM];

	TAdapterChannel  m_tTransVidAdtGrpStat[MAX_TRANS_VIDEO_ADAPT_CHANNUM];
	TAdapterChannel  m_tTransAudAdtGrpStat[MAX_TRANS_AUDIO_ADAPT_CHANNUM];
};

API void adapterwrapperver(u32 dwMapId);

API void showchn(u32 chnNo, BOOL32 bVidChn);

#ifndef TOSFUNC
#define TOSFUNC
//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API int SetMediaTOS(int nTOS, int nType);
API int GetMediaTOS(int nType);
#endif

#endif /* _KDVADAPTER_H_ */