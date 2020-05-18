 /*****************************************************************************
   ģ����      : HardMulPic
   �ļ���      : KdvMulPic.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: Ӳ���໭��ϳ����ϲ�API ��װ
   ����        : ���
   �汾        : V3.0  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���         �޸�����
   2003/12/03  3.0         ���           ����
******************************************************************************/
#ifndef _KDVMULPIC_H_
#define _KDVMULPIC_H_

#include "codeccommon.h"

//�����붨��
#define HARD_MULPIC_OK         0
#define HARD_MULPIC_ERROR     -1

/*ͼ���������
#define  MEDIA_TYPE_MP4	     (u8)97//MPEG-4
#define  MEDIA_TYPE_H261	 (u8)31//H.261
#define  MEDIA_TYPE_H263	 (u8)34//H.263
*/

//����ϳ����Ͷ���
#define MULPIC_TYPE_VTWO       1 //�����棺���ҷ�
#define MULPIC_TYPE_THREE      2//������
#define MULPIC_TYPE_FOUR       3//�Ļ���
#define MULPIC_TYPE_SIX        4//������
#define MULPIC_TYPE_ONE        5//�����棨�ֳ�9�ݷ��ͣ�
#define MULPIC_TYPE_ITWO       6//�����棺 һ��һС������ֳ�9�ݷ��ͣ�
#define MULPIC_TYPE_SFOUR      7//�����Ļ��棺һ����С������ֳ�4�ݷ��ͣ�
#define MULPIC_TYPE_SEVEN      8//�߻��棺������С������ֳ�4�ݷ��ͣ�
#define MULPIC_TYPE_EIGHT      9//�˻���
#define MULPIC_TYPE_NINE       10//�Ż���
#define MULPIC_TYPE_TEN        11//ʮ���棺�����С������ֳ�4�ݷ��ͣ�
#define MULPIC_TYPE_THIRTEEN   12//ʮ������
#define MULPIC_TYPE_SIXTEEN    13//ʮ������

//����ϳ����ͨ����
#define MULPIC_MAX_CHNS        16
#define MULTIPIC_MAX_DSP_NUM   5

//����ϳɳ�ʼ������
typedef struct
{
	u8    byType; //����ϳ�����
	u32   dwTotalMapNum;//���뻭��ϳɵ�ͨ����
	u32   dwCoreSpd; //Map�ں��ٶ�
	u32   dwMemSpd;  //�ڴ��ٶ�
	u32   dwMemSize; //�ڴ��С
}TMulPicParam;
/* ע�⣺�ֶ�dwMapUseFlagΪ32λ��λģʽ��*/

//״̬
typedef struct
{
	BOOL32  bMergeStart; //�Ƿ�ʼ����ϳɣ�
	u8  byType; //����ϳ�����
	u32 dwTotalMapNum; //Mapʹ�ñ�־
	u8   byCurChnNum; //��ǰ����ϳɵ�ͨ����
	TVideoEncParam tVideoEncParam; //ͼ��������
	TNetAddress atNetSndAddr; //���緢�͵�ַ
	TNetAddress atNetRcvAddr[MULPIC_MAX_CHNS]; //��ͨ����������յ�ַ
}TMulPicStatus;

//ͳ��
typedef struct
{
	u32  m_dwRecvBitRate;          //��������
	u32  m_dwRecvPackNum;         //�յ��İ���
	u32  m_dwRecvLosePackNum;    //�������ȱ�ٵİ���
}TMulPicChnStatis;

typedef struct
{
	u32  m_dwSendBitRate;          //��������
	u32  m_dwSendPackNum;        //���͵İ���
	u32  m_dwSendDiscardPackNum;  //���Ͷ�����
    TMulPicChnStatis atMulPicChnStatis[MULPIC_MAX_CHNS];
}TMulPicStatis;     

typedef struct
{
	u32   dwTotalMapNum;
	u32   dwCoreSpd; 
	u32   dwMemSpd;  
	u32   dwMemSize; 
	u8    bDoubleVidType;
	void * picMerger;
}TMulPicCheckParam;

typedef struct 
{
	u8 RColor;    //R����
	u8 GColor;    //G����
	u8 BColor;    //B����	
}TMulPicColor;

typedef struct 
{
	BOOL32    bHasData;      //��¼MapHaltǰ�в���
	u8 *  pbyBmp;        //����ΪOsd��Ϣ
	u32   dwBmpLen; 
	u32   dwXPos; 
	u32   dwYPos; 
	u32   dwWidth; 
	u32   dwHeight; 
	TBackBGDColor    tBackBGDColor; 
	u32   dwClarity; 
}TIconRecordInfo;

class CVideoEncoder;
class CAudioEncoder;
class CVideoDecoder;
class CAudioDecoder;

class CHardMulPic
{
public:
	CHardMulPic();
	~CHardMulPic();
	
	int Initialize(TMulPicParam tMulPicParam, BOOL32 bDbVid = FALSE);
	int Quit(); 
	
	//int AddChannel(u8 byChnNo, TNetAddress  tNetRcvAddr);
	int AddChannel(u8 byChnNo, TNetAddress  tNetRcvAddr,TNetAddress tRtcpNetRcvAddr);
	int RemoveChannel(u8 byChnNo);
	
	int SetNetSndLocalAddr(TNetAddress atNetSndLocalAddr[2]);
	int StartMerge(TVideoEncParam tVideoEncParam[2], TNetAddress tNetSndAddr[2]);
	int StopMerge(void);
	
	int GetStatus(TMulPicStatus &tMulPicStatus);
	int GetStatis(TMulPicStatis &tMulPicStatis);

	int SetMulPicType(u8 byNewType);

	int ChangeBitRate(BOOL32 bSecondType, u16  wBitRate/*kbps*/);
	u16 SetFastUpdata();
	
	/*��ȡͨ������ͳ����Ϣ*/
	int GetVidRecvStatis(u8 byChn, TKdvDecStatis &tKdvDecStatis);	

	/*����ͼ�����������ش�����*/
	u16  SetNetRecvFeedbackVideoParam(TNetRSParam tNetRSParam, BOOL32 bRepeatSnd = FALSE, u8 byTotalNum = 0);
	/*����ͼ������緢���ش�����*/
	u16  SetNetSendFeedbackVideoParam(u16 wBufTimeSpan, BOOL32 bRepeatSnd = FALSE);
	
	//��Ƶ�Ƿ�ʹ��ǰ�����
	u16    SetVidFecEnable(u8 byChnNo, BOOL32 bEnableFec);
	//����fec���а�����
	u16    SetVidFecPackLen(u8 byChnNo, u16 wPackLen);
	//�Ƿ�֡��fec
	u16    SetVidFecIntraFrame(u8 byChnNo, BOOL32 bIntraFrame);
	//����fec�㷨 FEC_MODE_RAID5
	u16    SetVidFecMode(u8 byChnNo, u8 byAlgorithm);
	//����fec��x�����ݰ� + y�������
	u16    SetVidFecXY(u8 byChnNo, s32 nDataPackNum, s32 nCrcPackNum);
	
	//������Ƶ�����غ�
	u16  SetVidEncryptPT(u8 byChnNo, u8 byEncryptPT); 

	//������Ƶ�������key�ִ����Լ� ����ģʽ Aes or Des
	u16  SetVidEncryptKey(u8 byChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );  
	
	//���� H.263+/H.264 �ȶ�̬��Ƶ�غɵ� Playloadֵ
	u16  SetVideoActivePT(u8 byChnNo, u8 byRmtActivePT, u8 byRealPT );
	//���� ��Ƶ����key�ִ� �Լ� ����ģʽ Aes or Des
    u16  SetVidDecryptKey(u8 byChnNo, s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 
	
	/*���ϲ��û��ӿ�*/
	int SendVidFrameToMap(u8 byChn, u32 dwStreamType, u32 dwFrameSeq, u32 dwWidth,
		                  u32 dwHeight, u8 *pbyData, u32 dwDataLen);

	/*VPU�壬��ȫ����Map���ٰѵ�ƽ���ͣ������loadFile������MediaCtrl*/
	int VpuInitProc(TMulPicParam tMulPicParam, u32  dwFirstMapNum, u32 dwLastMapNum);

	/*���û���ϳɱ�����ɫtBGDColor,�Լ��߿���ɫtSlidelineColor[MULPIC_MAX_CHNS]��
	��Ҫ�ı�߿���ɫʱ��ֻҪ�ı�tSlidelineColor[]��Ӧͨ����ֵ����*/
	int SetBGDAndSidelineColor(TMulPicColor tBGDColor, TMulPicColor atSlidelineColor[MULPIC_MAX_CHNS], BOOL32 bAddSlideLine = FALSE);

	/*�����Ƿ񱳰����*/
	u16 SetBackBoardOut(BOOL32 bOut);

	/*��ʼ����̨��*/
	int StartAddIcon(u8 byChnNo, u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth,
								 u32 dwHeight, TBackBGDColor tBackBGDColor, u32 dwClarity);

	/* ֹͣ����̨�� */
	int StopAddIcon(u8 byChnNo);

	/*������ʾģʽ (video �� vga), DISPLAY_TYPE_PAL : 1, DISPLAY_TYPE_VGA : 3*/
	u16 SetDisplayType(u8 byDisplayType);

private:
	int InitOneDsp(TMulPicParam tMulPicParam);
	int InitTwoDsp(TMulPicParam tMulPicParam);
	int InitThreeDsp(TMulPicParam tMulPicParam);
	int InitFourDsp(TMulPicParam tMulPicParam);
	int InitFiveDsp(TMulPicParam tMulPicParam);

	int OnInitMapOpr(u8 byMapNo, TMulPicParam tMulPicParam, u32 dwTotalMapNo, 
		             u32 dwVidEncNum, u32 dwVidDecNum, u32 dwStartChn, u32 dwEndChn, BOOL32 bDbVid = FALSE);

	u32 GetPicMergeChn(u8  byPicMergeType);
	u8  GetRealChnNo(u8  byChnNo);
	u8  Get3MapRealChnNum(u8  byChnNo);
	u8  Get4MapRealChnNum(u8  byChnNo);
	u8  Get5MapRealChnNum(u8  byChnNo);

	/* �õ�����ϳ�ͨ���Ŷ�Ӧ��map�źͽ���ͨ���� */
	int  GetDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);
	int  Get5MapDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);	
	int  Get4MapDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);	
	int  Get3MapDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);	
	int  Get2MapDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);	
	int  Get1MapDspNoAndVidDecChn(u8 byChnNo, u8 *pbyDspNo, u8  *pbyVidDecChnNo);	

	CVideoDecoder    *m_pVidEncPlayer;
	CVideoEncoder    *m_pVideoEncoder;
	CVideoEncoder    *m_pSecondVideoEncoder;
	CVideoDecoder    *m_apVideoDecoder[MULPIC_MAX_CHNS];
	
public:
	u8  m_byMulPicType; 
	u32 m_dwTotalMapNum;
	u32 m_bPicMergerStart;
	u32 m_dwMaxVidChnNum;
	BOOL32  m_bDoubleVidType;
	TNetAddress m_atNetSndLocalAddr[2];
	TMulPicColor m_tBGDColor;
	TMulPicColor m_atSlidelineColor[MULPIC_MAX_CHNS];
	BOOL32	m_bAddSlideLine;
	BOOL32  m_bCheckEnd;

    BOOL32 m_bBackBoardOut;     //�Ƿ񱳰����
	
private:
   	s64    m_qwLastFastupdataTime;     //���һ��FastUpdata��ʱ��
	volatile u32 m_adwMulPicMapBuffer[4][4];  //Osd Buffer, ÿ��map��4·ͨ�������4��map
	TIconRecordInfo  m_atAddLogoInfo[MULPIC_MAX_CHNS];       //̨������������Ϣ
};

API void picmergever(u32 dwMapId);
API void setfilt(BOOL32 bFilt);

#ifndef TOSFUNC
#define TOSFUNC
//����ý��TOSֵ nType����0:ȫ�� 1:��Ƶ 2:��Ƶ 3: ����
API int SetMediaTOS(int nTOS, int nType);
API int GetMediaTOS(int nType);
#endif

#endif /*_KDVMULPIC_H_*/





















