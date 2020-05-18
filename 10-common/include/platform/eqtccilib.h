/*****************************************************************************
ģ����      : Cci
�ļ���      : eqtCciLib.h
����ļ�    : eqtCciLib.c
�ļ�ʵ�ֹ���:  This file contains some constants and routine declarations used by upper lever.
����        : ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
13jan2003   01a         ���        written. 
01mar2003, 01b         �ŷ���      ���ӽӿ�.	
******************************************************************************/

#ifndef __INCeqtCciLibh
#define __INCeqtCciLibh

#include "eqtbrdlib.h"
/*#include "eti_board.h"*/

#ifndef API

#if defined(__cplusplus) && defined(_MSC_VER)
#define API extern "C" __declspec(dllexport)
#endif /* defined(__cplusplus) && defined(_MSC_VER) */

#if !defined(__cplusplus) && defined(_MSC_VER)
#define API __declspec(dllexport)
#endif /* !defined(__cplusplus) && defined(_MSC_VER) */

#if defined(__cplusplus) && !defined(_MSC_VER)
#define API extern "C"
#endif /* defined(__cplusplus) && defined(_MSC_VER) */

#if !defined(__cplusplus) && !defined(_MSC_VER)
#define API
#endif /* defined(__cplusplus) && defined(_MSC_VER) */

#endif /* API */

/* �䳤cci������ƺ궨��,��ԭʱ������ú꼴�� */
#define CCI_USE_DYNAMIC_BUF

#define CCI_VERSION                    "Ver 4.0  build at 2009-09-09"
#define VER_MTCCILib            ( const char * )"HOSTCCILib 40.01.04.06.090909"
#define CCI_VER_FLAG            4

#ifdef  CCI_USE_DYNAMIC_BUF
 #undef  CCI_VER_FLAG
 #define CCI_VER_FLAG 	                5
 #define CCI_UPMSG_MAX_LEN       (512<<10)   /* ������������Ϣ���� */
#endif

/* CCIͨ��״̬��غ궨�� */
#define CCI_SUCCESS                     0    /* CCIͨ�����ӽ����ɹ� */
#define CCI_PEER_CLOSED                 1    /* CCIͨ����MAP�豸�Ͽ� */
#define CCI_NOT_CONNECTED               2    /* CCIͨ��û�н��� */
#define CCI_SMEM_CORRUPT                3    /* CCI�����ڴ������ƻ� */
#define CCI_LENGTH_ERROR                4    /* CCIͨ����Ϣ���ȴ��� */
#define CCI_QUEUE_FULL                  5    /* CCI��Ϣ�������� */
#define CCI_MSG_LOST                    6    /* CCI��Ϣ��ʧ */
#define CCI_FAILURE                    -1    /* CCI����ʧ�� */


/* CCIͨ����Ϣ���Եĺ궨�� */
#define DN_MSGQ_MAX                 1024      /* ���������Ϣ������ */
#define ERR_FLAG_MAX_NUM            16        /* MAP�����¼�������� */

#define IS_UPMSGQ                   0         /* ������Ϣ���б�� */
#define IS_DNMSGQ                   1         /* ������Ϣ���б�� */

#define BUF_IS_NORMAL               0         /* ��Ϣ�����п���BUF��δ�����趨ֵ */
#define BUF_WILL_FULL               1         /* ��Ϣ�����п���BUF�������趨ֵ */

#define CCI_MSGQ_FREE_RATE          20        /* ������Ϣ���еİٷ���������CCI_MSGQ_FREE_RATE%�澯 */

/* ���Ͷ��� */
typedef void * HMsg;    /* handle to CCI host state */
typedef void ( *TMsgCallBack )(HMsg hMsg, BYTE *pbyMsg, WORD32 dwLen,   \
                               BYTE *pbyContext, WORD16 wState);
typedef void ( *TMsgQBufChkCallBack )(BYTE byMapId, BYTE byUpDown,\
                                      BYTE byQueueId, BYTE byStatus); /* added by zfm 2003/7/15 05:42PM */

typedef void ( *TCciMsgPrtFunc )(char *pbyString);

/* �û��������Ϣ���в����ṹ���� */
typedef struct{
        WORD32 dwMaxMsgLen;    /*ÿ����Ϣ����󳤶�(��BYTE��)��ȱʡ128KB��󳤶� */
        WORD32 dwMaxMsgs;      /* �����е�buffer����, ȱʡΪ8 */
} TcciMsgQParamDes;

typedef struct{
        WORD32 dwDnMsgQs;    /*������Ϣ������ */
        TcciMsgQParamDes tCciDnMsgQParam[DN_MSGQ_MAX];   /*������Ϣ���в��� */
        TcciMsgQParamDes tCciUpMsgQParam;                /*������Ϣ���в��� */
} TCciMsgQParam;

/* �û�����ķ�����Ϣ�����ṹ���� */
typedef struct{
        const BYTE* pbyMsgHead;     /* �û���Ϣͷָ�� */
        const BYTE* pbyMsg;         /* �û���Ϣָ�� */
        WORD32 dwMsgHeadLen;        /* �û���Ϣͷ���� */
        WORD32 dwMsgLen;            /* �û���Ϣ���� */
        WORD32 byMsgType;           /* ��Ϣ���� */
} TcciMsgParam;

/* ȫ�ֺ������� */
API HMsg    EqtMsgOpen ( HBoard hBoard, TCciMsgQParam *ptCciMsgQParam ,  \
                     TMsgCallBack tMsgCallBack, BYTE *pbyContext);    
API SWORD32 EqtMsgSnd(HMsg hMsg, WORD32 dwChannel, TcciMsgParam *pTcciMsgParam);
API SWORD32 EqtMsgClose(HMsg hMsg);
API HBoard  EqtMsgGetBrdHandle(HMsg hMsg);
API SWORD32 EqtMsgGetBrdNo(HMsg hMsg);
API SWORD32 EqtMsgGetMapErrLog(HMsg hMsg, WORD32 dwErrId, WORD32 *pdwMapErrLog);
API SWORD32 EqtMsgGetMapHeartBeat(HMsg hMsg, WORD32 *pdwMapCnt);

API void CciPrintf(char *szFormat,...);
API void EqtMapPrtEnable(BYTE byBrdNo);     /* ����map��Ϣ��ӡ */
API void EqtMapPrtDisable(BYTE byBrdNo);    /* �ر�map��Ϣ��ӡ */

/* ģ�ⶪ��dwRecvOrSend�����궨�壬dwDropRate��1/10000Ϊ��λ */
#define CCI_RECV_DROP                    0    /* ���ý��ն��� */
#define CCI_SEND_DROP                    1    /* ���÷��Ͷ��� */
API SWORD32 EqtMsgSetDropRate( HMsg hMsg, WORD32 dwRecvOrSend, WORD32 dwDropRate );

/* cci��buf�����澯�ص�ע�ắ�� */
API void EqtMsgQBufChkCallBackReg(TMsgQBufChkCallBack ptMsgQBufChkCallBack);

/* cci�Ĵ�ӡ�ص�ע�ắ��,��ע��ʱ�ײ���printf��ӡ */
API void EqtMsgPrtFuncReg(TCciMsgPrtFunc ptCciMsgPrtFunc);
API void EqtMsgPrt(char *szFormat, ...);

/* cci��buf״̬��ѯ���� */
API SWORD32 EqtCciDnMsgQNumGet(BYTE byBrdNo);   /* ��ѯ��ǰmap[byBrdNo]�����ж���ʵ��ʹ�õĶ����� */
API SWORD32 EqtCciMsgQBufAlarmGet(BYTE byBrdNo, BYTE byUpOrDnMsgQ, WORD32 dwMsgQNo);

API void CciInfoShow(SWORD32 byBrdNo);
API void CciStatShow(BYTE byBrdNo);
API SWORD32 EqtCciLoopBack
(
    BYTE byBrdNo, 
    WORD32 wSendTimes,          /* ���ʹ��� */
    WORD32 dwSendIntval,        /* ����ʱ���� */
    WORD32 dwPacketsPerIntval    /* ÿʱ�������Ͱ��� */
);
API SWORD32 EqtCciTestTogether
(
    BYTE  byTestBrdNum,
    WORD32 wSendTimes,
    WORD32 dwSendIntval,        /* ����ʱ���� */
    WORD32 dwPacketsPerIntval    /* ÿʱ�������Ͱ��� */

);

API void EqtCciPrtTest();
API SWORD32 EqtCciHostSendTest(BYTE byBrdNo, WORD32 dwSndTimes);
API SWORD32 EqtCciMapSendTest(BYTE byBrdNo, WORD32 dwSndTimes);
API SWORD32 EqtCciMapPrtTest(BYTE byBrdNo, WORD32 bySndTimes);
API void EqtIncludeTestFun(void);
API void hostcciver(void);

#ifdef __cplusplus 
//} 
#endif /* __cplusplus */

#endif /* __INCeqtCciLibh */
