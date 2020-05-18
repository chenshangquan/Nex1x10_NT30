/*****************************************************************************
ģ����      : 
�ļ���      : kdvmulpic_hd.h
����ļ�    : 
�ļ�ʵ�ֹ���: 
����        : ������
�汾        : V1.0  Copyright(C) 2008-2009 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2008/11/12    1.0         ������      ����
******************************************************************************/

#ifdef _MEDIACTRL_DM816x_

#include "dm816x/kdvmulpic_hd.h"

#else

#ifndef _KDVMULPIC_HD_H_
#define _KDVMULPIC_HD_H_

#include "codecwrapperdef_hd.h"

//�����붨��
#define HARD_MULPIC_OK         0
#define HARD_MULPIC_BASE       4000
#define MAX_VMP_DECCHANNEL       (u32)25
enum enMPUErr
{
    MulPic_Success = HARD_MULPIC_OK,

    MulPic_Err_Base = HARD_MULPIC_BASE,
    MulPic_Error_NoMem,
    MulPic_Error_NODev,
    MulPic_Error_NOCreate,
    MulPic_Error_Param,
    MulPic_Error_CreateAlready,
    MulPic_Error_NoVPLink,
};

//����ϳ����ͨ����
#define MULPIC_MAX_CHNS        25
enum enMulPicType
{
    MULPIC_TYPE_ONE  = 0,	//0 -������ ****�ݲ�֧��
    MULPIC_TYPE_VTWO = 1,	//1 -�����棺���ҷ�
    MULPIC_TYPE_THREE   ,	//2 -������
    MULPIC_TYPE_FOUR    ,	//3 -�Ļ���
    MULPIC_TYPE_SIX     ,	//4 -������
    MULPIC_TYPE_ITWO    ,	//5 -�����棺
    MULPIC_TYPE_SFOUR   ,	//6 -�����Ļ��棺һ����С
    MULPIC_TYPE_SEVEN   ,	//7 -�߻��棺������С
    MULPIC_TYPE_EIGHT   ,	//8 -�˻���
    MULPIC_TYPE_NINE    ,	//9 -�Ż���
    MULPIC_TYPE_TEN     ,	//10-ʮ���棺�����С
    MULPIC_TYPE_THIRTEEN,	//11-ʮ������
    MULPIC_TYPE_SIXTEEN ,	//12-ʮ������
    MULPIC_TYPE_TWENTY ,	//13-��ʮ����
	MULPIC_TYPE_TWENTYFIVE,	//14-��ʮ�廭��
    MULPIC_TYPE_NUM
};


typedef struct tagDspChnl
{
    u32  m_dwDspID;
    u32  m_dwVidEncNum;
    u32  m_dwVidDecNum;
    u32  m_dwAudEncNum;
    u32  m_dwAudDecNum;
}TDspChnl;

typedef struct tagMulCreate
{
    u32  m_dwStartDspID;  //ʹ�õ��ʼ��DSP��ţ���0��ʼ��
    u32  m_dwDSPNUM;      //ʹ�õ�DSP���� 1��4

}TMulCreate;

//״̬
typedef struct tagMulPicStatus
{
	BOOL32  bMergeStart; //�Ƿ�ʼ����ϳɣ�
	s32  byType; //����ϳ�����
	u8   byCurChnNum; //��ǰ����ϳɵ�ͨ����
	TVideoEncParam tVideoEncParam; //ͼ��������
}TMulPicStatus;

//ͳ��
typedef struct tagMulPicChnStatis
{
	u32  m_dwBitRate;        //����
	u32  m_dwPackNum;        //����
	u32  m_dwLosePackNum;    //ȱ�ٵİ���
    BOOL32 m_bWaitKeyFrame;
}TMulPicChnStatis;
   

typedef struct tagMulPicColor
{
	u8 RColor;    //R����
	u8 GColor;    //G����
	u8 BColor;    //B����
    u8 byDefualt;
}TMulPicColor;

typedef struct tagTIconRecordInfo
{
	BOOL32    bHasData;      //��¼MapHaltǰ�в���
	u8 *  pbyBmp;        //����ΪOsd��Ϣ
	u32   dwBmpLen; 
	u32   dwXPos; 
	u32   dwYPos; 
	u32   dwWidth; 
	u32   dwHeight; 
	TMulPicColor    tBackBGDColor; 
	u32   dwClarity; 
}TIconRecordInfo;

class CMulPic;
class CHardMulPic
{
public:
	CHardMulPic();
	~CHardMulPic();
public:
    /*�������� Create
      ��    �ܣ� 
	  ��    ���� const TMulCreate& tInit
	  �� �� ֵ��	s32 
	  ˵    ���� */
	s32 Create(const TMulCreate& tInit);


    /*�������� Destory
      ��    �ܣ� 
	  �� �� ֵ��s32 
	  ˵    ���� */
    s32 Destory(); 
    
    s32 SetData(s32 nChnl, const TFrameHeader& tFrame);
	s32 SetVidDataCallback(s32 nChnl, FRAMECALLBACK fVidData, void* pContext); /*������Ƶ���ݻص�*/
	
	s32 AddChannel(s32 nChnNo);
	s32 RemoveChannel(s32 nChnNo);
	
	s32 StartMerge(TVideoEncParam* ptVideoEncParam, s32 nEncNum);
	s32 StopMerge();
	
	s32 GetStatus(s32 nChnNo,TMulPicStatus &tMulPicStatus);
	s32 GetDecStatis(s32 nChnNo, TMulPicChnStatis &tMulPicStatis);
    s32 GetEncStatis(s32 nIndex, TMulPicChnStatis &tMulPicStatis);

	s32 SetMulPicType(s32 nNewType);

	s32 ChangeBitRate(s32 nIndex, u16  wBitRate/*kbps*/);
	s32 SetFastUpdata(s32 nIndex);

	/*���û���ϳɱ�����ɫtBGDColor,�Լ��߿���ɫtSlidelineColor[MULPIC_MAX_CHNS]��
	��Ҫ�ı�߿���ɫʱ��ֻҪ�ı�tSlidelineColor[]��Ӧͨ����ֵ����*/
	s32 SetBGDAndSidelineColor(TMulPicColor tBGDColor,
           TMulPicColor atSlidelineColor[MULPIC_MAX_CHNS], BOOL32 bAddSlideLine = FALSE);

	//�ɵ�������vipͨ���߿����ɫ����SetBGDAndSidelineColor��������ͬʱʹ��
	s32 SetVipChnl(TMulPicColor tVipSlideColor,u32 dwChnl);

	/*��ʼ����̨��*/
	s32 StartAddIcon(s32 nChnNo, u8 *pbyBmp, u32 dwBmpLen, u32 dwXPos, u32 dwYPos, u32 dwWidth,
								 u32 dwHeight, TBackBGDColor tBackBGDColor, u32 dwClarity);

	/* ֹͣ����̨�� */
	s32 StopAddIcon(s32 nChnNo);

	/*������ʱ��������, BakType(enNoStreamBack)*/
	s32 SetNoStreamBak(u32 BakType, u8 *pbyBmp = NULL, u32 dwChnlId=MAX_VMP_DECCHANNEL);

	u16 SetResizeMode(u32 dwMode);//ģʽ0:�Ӻڱߣ�1:�ñߣ�2:�ǵȱ����죬Ĭ��0
	u16 SetEncResizeMode(u32 dwMode);//ģʽ0:�Ӻڱߣ�1:�ñߣ�2:�ǵȱ����죬Ĭ��0
	u16 SetVidDropPolicy(u8 byDropPolicy);  //�趨�����������
	
	//����ĳ·����ͨ���ı���������˴����õı�����Ҫ��С��
	//����StartMergeʱ���õĿ��
	s32 SetEncChnlParam(TVideoEncParam *ptEncParam, s32 nChannel);  

private:
    CMulPic*  m_pMulPic;
};

s32 HardMPUInit(u32 nMode); //nMode:enInitMode
s32 HardMPUInitDev(u32 nEncTos, u32 nDecTos, u32 nDspNum);
s32 HardMPUDestroy();

//DSP��ʼ�������٣�MCU�û�����Ҫ����
s32 HardMPUInitDSP(TDspChnl* pChnl);
s32 HardMPUDestroy();
#endif
#endif /*_KDVMULPIC_HD_H_*/





















