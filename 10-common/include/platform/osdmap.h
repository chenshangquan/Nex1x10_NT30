/*****************************************************************************
   ģ����      : CodecLib
   �ļ���      : OsdMap.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: Ӳ��Codec �ϲ�API ��װ
   ����        : ������
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���         �޸�����
   2003/03/23  0.9         Hu Changwei      ����
******************************************************************************/
#ifndef __COSDMAP_H_
#define __COSDMAP_H_

#include "eqtmap.h"

#define OSD_BUF_LEN          (u32)(1<<20)

/*************OSD CONTROL  0x7D0��ʼ********************/	
#define	H2M_OSD_LABEL                   0x7D1/*OSD ̨�꣬����Ϊ���ݳ���*/
#define	H2M_OSD_CAPTION                 0x7D2/*OSD��Ļ������˵�����ӿ�ʵ��*/	
#define	H2M_OSD_STATE                   0x7D3/*OSD״̬��ǣ�����Ϊ���ݳ���*/	
#define	H2M_OSD_MENU                    0x7D4/*OSD�˵�������˵�����ӿ�ʵ��*/	
#define	H2M_OSD_VOLUME                  0x7D5/*OSD������־*/
#define	H2M_OSD_CLOSE                   0x7D7/*OSD�رգ�����Ϊ��*/
#define	H2M_OSD_NEED_BUF                0x7D8/*����OSD Buffer �������󣬲���Ϊ��*/
#define H2M_OSD_OTHERBMP	        0x7D3/*OSD ����ͼ����BMP*/

/*OSD�رղ�������*/
#define	OSD_LABEL			0
#define	OSD_CAPTION			1
#define	OSD_STATE			2
#define	OSD_MENU			3
#define	OSD_VOLUME			4
#define	OSD_CYCLE			5

//#define OSD_TIMER

#ifdef OSD_TIMER
#ifdef _VXWORKS_
#include "timers.h"
#include "time.h"
#endif
#endif

#define MAX_OSD_NUM          100

#define OSD_OK               0
#define OSD_ERROR            -1

#define OSD_TYPE_STATIC      0
#define OSD_TYPE_SLIDE       1

typedef struct 
{
	BOOL  bValid;
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

/*Osd�رղ���*/
typedef struct OsdCloseParam
{
    BOOL bNeedClose;
    u16 wLeftSecond;
}TOsdCloseParam;

class CHardCodec;

#define _TOPAN_
#ifndef _TOPAN_
class COsdMap
{
public:
    COsdMap();
    virtual ~COsdMap();

public:
	//��ʼ��
    u16 Initialize(u8 byMapID);

	//��MapдOsd����
    u16 WriteOsdDataToMap(WORD byOsdType,/*OSD����*/
                           u8 *pbyHdrBuf,/*ͷ��ʼ��ַ*/
                           u32 dwHdrLen,/*ͷ����*/
                           u8 *pbyDataBuf,/*������ʼ��ַ*/
                           u32 dwDataLen,/*���ݳ���*/
                           u32 dwXPos,/*X����*/
                           u32 dwYPos,/*Y����*/
                           u32 dwHeight,/*�߶�*/
                           u32 dwWidth,/*���*/
                           u32 dwTansparentValue,/*͸����*/
                           u32 dwOtherParam1,
                           u32 dwOtherParam2);
	//�ر�Osd
    u16 OsdClose(u8 byOsdType);
	
    //Osd˫buffer��ַ��Map���͵�����֮��ͨ���������õ�
	void OsdBufBasesProc(u32 dwOsdBufBase0, u32 dwOsdBufBase1);

    //friend void GetOsdMsgFunc(u32 dwMsg, u32 dwParam[6],u8 *pbyContext);
    
    #ifdef OSD_TIMER
	//ʱ��
    friend void Timer(timer_t timerid,int Param);
    #endif

protected:
    u32 m_dwMapBuffer[2];  //Osd Buffer
    u8 m_byCurBufNum;      //��ǰBuffer���
    TOsdParam tOsdParam[10]; //Osd����
    BOOL m_bShow[10];        //Osd�Ƿ���ʾ
    BOOL m_bReset;           //�Ƿ��Reset
    int nWaitTime;           //�ȴ�����

    #ifdef OSD_TIMER
    TOsdCloseParam tOsdCloseParam[2];  //Osd�رղ���
    timer_t timerId;                   //ʱ��ID
    #endif

private:
	CHardCodec *m_pcCodecMap;
   
};

#else     /*define _TOPAN_*/

class COsdMap
{
public:
    COsdMap();
    virtual ~COsdMap();
	
public:
	//��ʼ��
    u16 Initialize(u32 dwMapID);

	//��ʾOSD���ɹ����ر�Osd��ID�ţ�ʧ�ܷ���OSD_ERROR.
	int OsdShow(u8 *pbyBmp, 
		         u32 dwBmpLen, 
				 u32 dwXPos, 
				 u32 dwYPos, 
				 u32 dwWidth, 
				 u32 dwHeight, 
				 u8  byBgdColor, 
				 u32 dwClarity, 
				 BOOL  bSlide=FALSE,
				 u32 dwSlideTimes=1,
				 u32 dwSlideStride=10,
				 BOOL  bAddLogo=FALSE,  /*�Ƿ��������ں�*/
				 u32 dwChnNum=0  /*�����ںϵ�ͨ����*/);

	//�ر�Osd, �ɹ�����OSD_OK; ʧ�ܷ���OSD_ERROR.
      int OsdClose(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, BOOL bSlide=FALSE, BOOL  bAddLogo=FALSE/*�Ƿ��������ں�*/, u32 dwChnNum=0  /*�����ںϵ�ͨ����*/);	
   
    #ifdef OSD_TIMER
	int  StartTimeIconShow(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, 
	            		  u8  byBgdColor, u32 dwClarity, u32 dwChnNum);
	int  StopTimeIconShow(u32 dwChnNum);
	int  CheckTImeIconProc();
	//ʱ��̨��ʱ�Ӵ�����
#ifdef _VXWORKS_
    friend void TimeIconTimerProcess(timer_t timerid, int Param);   
#endif
    #endif

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

	CHardCodec *m_pcCodecMap;	
};
#endif // _TOPAN_




#endif





















