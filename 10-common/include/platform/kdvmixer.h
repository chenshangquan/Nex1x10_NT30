 /*****************************************************************************
   ģ����      : HardMixer
   �ļ���      : KdvMixer.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: ���ܻ������ϲ�API ��װ
   ����        : ���
   �汾        : V3.0  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���         �޸�����
   2003/12/03  3.0         ���           ����
******************************************************************************/
#ifndef _MIXER_H_
#define _MIXER_H_

#include "codeccommon.h"

#define MAX_CHANNEL_NUM     192//���ͨ����
#define MAX_MIXER_DEPTH     10 //�������

/*������������
#define	 MEDIA_TYPE_MP3	     (u8)96//mp3
#define  MEDIA_TYPE_PCMU	 (u8)0//G.711 ulaw
#define  MEDIA_TYPE_PCMA	 (u8)8//G.711 Alaw
#define	 MEDIA_TYPE_G7231	 (u8)4//G.7231
#define	 MEDIA_TYPE_G728	 (u8)15//G.728
#define	 MEDIA_TYPE_G729	 (u8)18//G.729
*/

//���������ص�������abyActiveChns��ǰ��ķ�0Ԫ�ر�ʾ��ǰ���������ͨ����, byExciteChn��ʾ��ǰ������ͨ����, Ϊ0��ʾû�м�����ͨ��
typedef void (*TMixerCallBack)(unsigned char* abyActiveChns, unsigned char byExciteChn, unsigned int dwContext);

//Map ����
typedef struct tagMixerMap
{         
    u32   m_dwCoreSpd; //Map�ں��ٶ�
    u32   m_dwMemSpd;  //�ڴ��ٶ�
    u32   m_dwMemSize; //�ڴ��С
    u8    m_byMapId;   //Map���
    u8    m_byPort;    //Map�˿ں�
}TMixerMap;

//����ͨ��
typedef struct tagMixerChannel
{
	u8     m_byChannelIndex;//ͨ��������
	TNetAddress m_tSrcNetAddr;     //ͨ��Դ��ַ(���ն���)
								   //ͨ��ԴRTCP��ַ����ͨ��Դ��ַ�Ķ˿ڼ�һ(���ն���)
    TNetAddress m_tRtcpBackAddr;   //ͨ��RTCP������ַ(���ն���)
    TNetAddress m_tLocalNetAddr;   //ͨ�����ص�ַ(���Ͷ���)
								   //ͨ������RTCP��ַ����ͨ�����ص�ַ�Ķ˿ڼ�һ(���Ͷ���)
    TNetAddress m_tDstNetAddr;     //ͨ��Ŀ�ĵ�ַ(���Ͷ���)
}TMixerChannel;

//������״̬
typedef struct tagMixerGroupStatus
{
    BOOL     m_bMixerStart;      //�����Ƿ�ʼ
    u8     m_byCurChannelNum;  //�������ͨ����
    TNetAddress m_tNModeDstAddr;    //Nģʽ�������ַ
    TMixerChannel m_atChannel[MAX_CHANNEL_NUM];  //���е�ͨ��	
}TMixerGroupStatus;

//ͨ��ͳ����Ϣ
typedef struct tagMixerChannelStatis
{
    u32  m_dwRecvBitRate;        //��������
    u32  m_dwRecvPackNum;        //�յ��İ���
    u32  m_dwRecvLosePackNum;    //�������ȱ�ٵİ���
    u32  m_dwSendBitRate;        //��������
    u32  m_dwSendPackNum;        //���͵İ���
    u32  m_dwMixerDiscardPackNum;//���������İ���
}TMixerChannelStatis;

class CAudioEncoder;
class CAudioDecoder;

class CKdvMixerGroup
{
public:
    CKdvMixerGroup();
    virtual ~CKdvMixerGroup();

public:
	u16 CreateMixerGroup(const TMixerMap* tMixerMap,u8 byChannelNum);//����������
	u16 DestroyMixerGroup();//ɾ��������
	u16 StartMixerGroup(u8 bAllMix=TRUE);//��ʼ������		
	u16 StopMixerGroup();//ֹͣ������	
	u16 AddMixerChannel(const TMixerChannel* tMixerChannel);//������Ļ���ͨ��
	u16 SetMixerNetFeedbackParam(u8 byChnIndex,  BOOL32 bFeedBackSnd, TNetRSParam tNetRSParam, BOOL32 bRepeatSnd, u16 wBufTimeSpan);//���û����ش�
	u16 DeleteMixerChannel(u8 byChannelIndex);//ɾ����Ļ���ͨ��
	u16 SetNModeOutput(const TNetAddress* tLocalAddr, const TNetAddress* tDstNetAddr);
	u16 SetNModeNetFeedbackParam(BOOL32 bRepeatSnd, u16 wBufTimeSpan);//����Nģʽ�����ش�
	
	u16 SetForceAudMix(u8 byChnNo); // ǿ�ƻ���
    u16 CancelForceAudMix(); // ȡ��ǿ��
    u16 SetMixerDepth(u8 byDepth);//���û������
    u16 SetMixerCallBack(TMixerCallBack tMixerCallBack, int dwContext);//���������ص�
    u16 GetActiveChns(u8 abyActiveChnsArr[], u8 byArrNum, u8 *pbyActiveNum); //��õ�ǰ���������ͨ��

	u16 SetMixerChannelVolume(u8 byChannelIndex,u8 byVolume);//����ͨ������
	u16 GetMixerGroupStatus(TMixerGroupStatus &tMixerGroupStatus);//�õ����״̬
	u16 GetMixerChannelStatis(u8 byChannelIndex,TMixerChannelStatis &tMixerChannelStatis);//�õ�ͨ����ͳ����Ϣ

	u16 SetMixerParam(TMixerParam  *ptMixPara);//�������ܻ���������

	u16 StopMixerSnd(BOOL32 bStopSnd);	//TRUE: ֹͣ���з���, FALSE: ��ʼ���з���
	u16 SetExciteKeepTime(u32 dwKeepTime);  //����������������ʱ����, ��λ����
	BOOL32 IsChnSelected(u8 byChannel, u8 byMixChnNum);	// �ж�ָ��ͨ���Ƿ�ѡ�������

	void MixerCallBackProc(u8 *pbyMediaMsg, u32 dwMediaMsgLen);
	u16 SetChnSelectTactic(void);		//���û���ͨ����ѡ����ԣ��Ƿ�����

	u16    SetMixChnStatus(u8  bChnStatus[192]);   //�����ֹ��������ģʽ�£���ͨ���Ƿ�������
	
	//������Ƶ�����غ�PTֵ
	u16  SetAudEncryptPT(u8 byChnNo, u8 byEncryptPT);
	//������Ƶ�������key�ִ��Լ� ����ģʽ Aes or Des
	u16  SetAudEncryptKey(u8 byChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
	u16  SetNetAudioResend(u8 byChnNo, s32 nSendTimes, s32 nSendSpan);
	
	//���� ��̬��Ƶ�غɵ� Playloadֵ
	u16  SetAudioActivePT(u8 byChnNo, u8 byRmtActivePT, u8 byRealPT );
	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16  SetAudDecryptKey(u8 byChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
    
    //���û�����ʱ(ms)
    u16 SetMixerDelay(u32 dwTime);
	
	//���ÿ�ʼ, ���ջ�����
	u16 SetMixerRcvBufs(u32 dwStartRcvBufs, u32 dwFastRcvBufs);

	/////////////////     ������    ////////////////
	u16 SendMsgToMap(u32 dwCciQueNo, u8 *pbyMsgHead, u32 dwMsgHeadLen, u8 *pbyMsgBody,
		u32 dwMsgBodyLen);	
	u16 H2MCmdSend(u32 type, u32 event, u32 channel, u8 *msg, u32 msgLen); 
	//////////////////////////////////////////////////////////////////////////

public:
	u8 m_abyMixingChns[MAX_MIXER_DEPTH];
	u8 m_byMixingChnNum;		// ��ǰ������ͨ����
	u8 m_byChannelNum;			// ���ѡ��ͨ����
	u32 m_adwEncoderId[MAX_CHANNEL_NUM + 1];
	u8 m_byMixerStart;
	u8 m_byMixDepth;			// �������
	u8 m_bChnStatus[192];		// �ֹ��������ģʽ�£���ͨ���Ƿ�������
	TMixerParam m_tMixerParam;	// ��������

private:
    CAudioEncoder *m_apMixerEncoder[MAX_CHANNEL_NUM+1];
    CAudioDecoder *m_apMixerDecoder[MAX_CHANNEL_NUM];
    u8 m_byChannelState[MAX_CHANNEL_NUM+1];
    TMixerGroupStatus m_tMixerGroupStatus;
	u8 m_byMapNo;
	u8 m_byForceMixChn;
	TMixerCallBack  m_tMixerCallBack;
	u32           m_dwCallBackCont;
	BOOL32		  m_bStopSnd;	//�Ƿ��ֹ����ͨ������	
	u8 m_byEnteredChnNum;		// �Ѽ����ͨ����	
	BOOL32	m_bUseExcite;	// �Ƿ������ܻ������� ��
};

API void mixerwrapperver(u32 dwMapId);
API void setmixersend(u32 dwMapNo, BOOL32 bStopSend);     //ֹͣ/��ʼ����������

#ifndef TOSFUNC
#define TOSFUNC
//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API int SetMediaTOS(int nTOS, int nType);
API int GetMediaTOS(int nType);
#endif

#endif
