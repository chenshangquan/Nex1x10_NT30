/* ipohEnd.h */

/* Copyright 2001, Kdc  Co., Ltd. */

/*
modification history
--------------------
01a, 01/10/27, created zwj
*/

/*
DESCRIPTION
    Header file of ipoh driver.
    TBD , change the inter device driver and route table
*/

#ifndef __INCmotMccTransh
#define __INCmotMccTransh

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


/*#include"motmccHdlc.h" */
#include <stdio.h>
#include <stdlib.h>
#include <vxworks.h>
#include "semLib.h" 
#include "taskLib.h"
#include "msgQLib.h"
#include "iv.h"
/*#include "motMccHdlc.h" */

/* defines */
#define DEBUG


#ifdef DEBUG
    #define DBG_PRINTF(fmt, args...) \
        printf("[Drv debug]: ");\
        printf(fmt, ## args)                     /* ������Ϣ��ӡ */
#else
    #define DBG_PRINTF(fmt, args...) \
/*      if (eti_board_debug) printf(fmt, ## args)*/
#endif

#define ERR_PRINTF(fmt, args...) \
    printErr("[Drv ERR]: ");\
    printErr(fmt, ## args)                        /* ������Ϣ��ӡ */


#define MSG_PRINTF(fmt, args...) \
        printf(fmt, ## args)                    /* ��Ϣ��ʾ��ӡ */



/* Configuration items */
/* MCC_TRANSͨ��״̬ */
#define MCC_TRANS_SUCCESS          0    /* �����ɹ� */
#define MCC_TRANS_NOT_INIT         1    /* δ��ʼ�� */
#define MCC_TRANS_LENGTH_ERROR     2    /* ���ݳ��ȴ��� */
#define MCC_TRANS_NO_BUF           3    /* û�п��õ�BUF */
#define MCC_TRANS_FAILURE         -1    /*  ����ʧ�� */

#define MCC_TRANS_MAX_BUF_LEN   8000    /* ��Ϣ���������BUF�ĳ��� */
#define MCC_TRANS_MIN_BUF_LEN   800     /* ��Ϣ��������СBUF�ĳ��� */

#define MCC_TRANS_E1_TS16_USE     1     /* ʹ��TS16 */
#define MCC_TRANS_E1_TS16_NOTUSE  0     /* ��ʹ��TS16 */

/* ͬ����ʽ */
/*#define MCC_TRANS_SYNC_NO        0x7000   /* ���ͺͽ�����ͬ������ */
/*#define MCC_TRANS_SYNC_SLOT      0x7100   /* ���ͺͽ���ʹ��ʱ��ͬ�� */
/*#define MCC_TRANS_SYNC_PATTERN8  0x7200  /*  ���ղ���8λͬ���ַ�ͬ�� */
/*#define MCC_TRANS_SYNC_PATTERN16 0x7300  /*  ���ղ���16λͬ���ַ�ͬ�� */

/* ͬ����ʽ�����ֽڱ�����˳��������෴ */
#define MCC_TRANS_SYNC_NO        0x7400   /* ���ͺͽ�����ͬ������ */
#define MCC_TRANS_SYNC_SLOT      0x7500   /* ���ͺͽ���ʹ��ʱ��ͬ�� */
#define MCC_TRANS_SYNC_PATTERN8  0x7600  /*  ���ղ���8λͬ���ַ�ͬ�� */
#define MCC_TRANS_SYNC_PATTERN16 0x7700  /*  ���ղ���16λͬ���ַ�ͬ�� */

/* Max number of MCCTRANS units */
#define MAX_MCCTRANS_UNITS   128
#define MAX_E1_NUM             8

#define NULL_CHANNEL    65535   // NULL channel
#define ROUTE_TBL_SIZE     MOT_MCC_CHAN_NUM  /* 128 mean a mcc have a 128 channel */    
#define MAX_MCCTRANS_CHAN  MOT_MCC_CHAN_NUM

/* Range of maximum transfer unit   */

#define MCC_MAX_DEVS    256

#define MCC_TRANS_CCS    0         /* TS16������·����û�����ʹ�ô����� */
#define MCC_TRANS_CAS    1         /* TS16������·����û�����ʹ�ô����� */

#define MCC_TRANS_OPENED        0xabcddcba         /* MCC�������״λ�����ʼ����ɱ�־ */
#define UNUSED_CHAN_FLAG        0xff
  
/* Number of net buffers per unit */

typedef void ( * TMccMsgCallBack )( UINT8 byChanID, UINT32 wState);
 
/* typedefs */



 
/********************************************************************************* 
* ʱ������˵����
*    ʱ����������룬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
* Ts0��Ϊͬ���źţ��û�����ʹ�ã�Ts16����Ϊ���ݻ�����û����ڴ���ʱ����ģʽ��
* ʱ�����佨��ӵ͵�����������ʱ϶����Ҫ��������������������ͨ��ϵͳ���ȶ���
* ��: ʹ��5��ʱ϶ʱdwTimeSlotMask = 0x0000003e,ע��:Ts0=0; ��ʱ����= 64x5 = 320kbit
**********************************************************************************/
typedef struct{
    UINT32  dwBufNum;           /* ��Ϣ������buf������ */
    UINT16  wBufLength;         /* ��Ϣ������ÿ��buf�ĳ��� */
    UINT16  wE1ID;              /* E1�ı�ţ�0~7,��ģ���ͺŶ����� */
    UINT32  dwTimeSlotMask;     /* �����ϵ�ʱ������˵��*/
    UINT16  wTransSyncMode;     /* ͬ��ģʽ �����ͬ����ʽ�궨��*/
    UINT16  wTransSyncPattern;  /* ͬ���ַ� */
    UINT32 *pdwBufBaseAddr;     /* ��ŷ��صĹ����ڴ����ַ��ָ�� */
} TMccTransChanParam;

typedef struct{
    UINT8   byTS16RunMode;                                  /* TS16�Ĺ���ģʽ */
    TMccTransChanParam tMccTransChanParam[MCC_MAX_DEVS];    /* ÿ��ͨ���Ĳ������� */
} TMccTransOpenParam;



/* �û�����ķ�����Ϣ�����ṹ���� */
typedef struct{
        UINT8* pbyMsg;        /* �û���Ϣָ�� */
        UINT16 dwMsgLen;      /* �û���Ϣ���� */
} TMccTransMsgParam;



/* TCciHostStat �ṹ���� */
typedef struct{
    UINT32 dwRxPackets;
    UINT32 dwRxDropPackets;
    UINT32 dwRxErrPackets;
    UINT32 dwRxSucSndPackets;
    UINT32 dwTxSndPackets;
    UINT32 dwTxSucSndPackets;
}TMccTransChanStat;

typedef struct{
    UINT8  byMccTransChanCtrlID;              /* �豸���Ʊ�� */
    UINT8  byMccChan;                         /* ͨ���豸ʹ�õĳ��ŵ���mcc channel�ı�� */
    UINT32 dwMccTransChanHandle;              /* ͨ���豸���ƾ�� */

    UINT32 dwShMemBaseAddr;
    UINT32 dwHead;              /* ͷָ�� */
    UINT32 dwTail;              /* βָ�� */
    
    UINT8 *m_pbyStartPtr;//���λ���������ַ
    UINT8 *m_pbyEndPtr; //���λ�����β��ַ����ָ��Ŀռ䲻����
    UINT32 m_dwLen;             //���λ���������

    UINT8 *m_pbyReadPtr;//��ǰ��ָ��
    UINT8 *m_pbyWritePtr;//��ǰдָ��
	
    UINT32  dwBufNum;           /* ��Ϣ������buf������ */
    UINT16  wBufLength;        /* ��Ϣ������ÿ��buf�ĳ��� */
    TMccMsgCallBack  tMccMsgCallBack;

    /*TMccTransChanParam tMccTransChanParam;    /* ����ͨ���豸ʱ�ϲ㴫��Ĳ��� */
    TMccTransChanStat tMccTransChanStat;      /* ͨ�ŵ���Ϣͳ�� */
}TMccTransChanInfo;

typedef struct TMccTransCtlTag
{
    UINT32 dwTimeSlotUsed[MAX_E1_NUM];        /* �ܹ������ʱ�� */
    UINT32 dwDevChanUsedNum;                  /* �ܹ�ʹ�õ��豸ͨ������ */
    UINT32 dwMccTransSpecHandle;              /* û��ʹ�õ�ʱ�����󲢳�ʼ����õ��ľ�� */
    TMccTransChanInfo tMccTransChanInfo[MCC_MAX_DEVS];
} TMccTransCtl;



typedef struct TMccTransModuleTag
{
    UINT8  byExistE1Num;
    UINT32 dwMccTransOpened;
    UINT32 dwMccTransCtl;
} TMccTransModule; 
 

/* ����mcc������ */
INT32 MccTransOpen
(
    UINT8 byCrtChanNum,                         /* �������ٸ�ͨ�� */
    TMccTransOpenParam *ptMccTransOpenParam,    /* ͨ���Ĳ������� */
    TMccMsgCallBack  tMccMsgCallBack            /* �ص����� */
);

/* ����ָ��ͨ�������ڴ�����ͷָ�� */
INT32 MccTransBufQHeadPtrInc(UINT8 byDevChanID, UINT32 dwOffset);   

/* ����ts16�Ĺ���ģʽ */
INT32 MccTransSetTS16Mode(UINT8 byMode);   

/* �ر�mcc������ */
INT32 MccTransClose(void);                  
        
/* ��ȡָ��ͨ�������ڴ��ͷָ�� */
UINT8* MccTransGetBufQHeadPtr(UINT8 byDevChanID);   

/* ���ݷ��� */
INT32 MccTransMsgSnd(UINT8 byDevChanID, TMccTransMsgParam *ptMccTransMsgParam); 

/* ����ָ��ͨ�������ڴ�����ָ�����ȵ����ݵ�pbyDstBufָ����ڴ� */
UINT32 MccTransMsgCopy(UINT8 byDevChanID, UINT8 *pbyDstBuf, UINT32 dwSize); 

/* ��ȡָ��ͨ�������ڴ�����ȡ������ */
UINT32 MccTransGetMsgLen(UINT8 byDevChanID);    

/* ��ȡָ��ͨ�������ڴ����ӵ�ǰͷָ�뿪ʼƫ����ΪdwOffset����һ���ֽ� */
UINT8 MccTransReadOneByte(UINT8 byDevChanID, UINT32 dwOffset);  

/* E1�Ի� */
#define E1_LOCAL_LOOP_ON    0
#define E1_LOCAL_LOOP_OFF   1
void MccTransE1LoopConf(UINT8 byE1ID, UINT8 byLoopMode);

/* ����Ϊ�����õĺ��� */
BOOL MccTransHeaderInc(UINT8 byDevChanID, UINT32 *pdwHeadPtr, UINT32 dwTailPtr);
BOOL IsMccTransBufQEmpty(UINT8 byDevChanID, UINT32 dwHeadPtr, UINT32 dwTailPtr);
BOOL IsMccDevOpened(void);

void MccTransStatShow(UINT8 byDevChanID);
UINT32 MccTransGetTxDataNum(UINT8 byDevChanID);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */



#endif /* __INCmotMccTransh */
