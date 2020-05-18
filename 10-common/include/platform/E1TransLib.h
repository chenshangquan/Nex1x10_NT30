/*****************************************************************************
ģ����      : E1_TRANS_MODULE
�ļ���      : E1TransLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  E1_TRANS_MODULE �ϲ�ӿں궨��ͺ���������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���     �߶���       �޸�����
2005/05/25  01a        �ŷ���                  ����	
******************************************************************************/

#ifndef __INC_E1TransLib_H
#define __INC_E1TransLib_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


/* ================================= �궨�� ================================ */

/* E1͸������ģ�鷵��ֵ�ʹ��������� */
#define E1_TRANS_SUCCESS       (INT32)0                         /* �ɹ� */

#define E1_TRANS_FAILURE       (INT32)-1                        /* δ֪���쳣ʧ�� */
#define E1_TRANS_ERRCODE_BASE  (INT32)1                         /* �������ֵ */
#define E1_TRANS_NOT_INIT      (INT32)(E1_TRANS_ERRCODE_BASE+0) /* ͨ��δ�� */
#define E1_TRANS_LENGTH_ERROR  (INT32)(E1_TRANS_ERRCODE_BASE+1) /* ���ݳ��ȴ��� */
#define E1_TRANS_NO_BUF        (INT32)(E1_TRANS_ERRCODE_BASE+2) /* û�п��õ�BUF */

/* ���� wBufLength ��Χ���� */
#define E1_TRANS_BUF_MAX_LEN   (UINT32)8000 /* ���������������BUF�ĳ���,��λ�ֽ� */
#define E1_TRANS_BUF_MIN_LEN   (UINT32)800  /* ��������������СBUF�ĳ���,��λ�ֽ� */

#define E1_TRANS_CHAN_MAX_NUM  (UINT8)16    /* ���֧�ֵ�E1͸������ͨ���ĸ�����һ
                                               ��ͨ������Ӧ��һ������E1��· */


/* ============================== �ṹ�����Ͷ��� =========================== */

/* ����һ��ͨ����Ҫ����Ĳ����ṹ���� */
typedef struct{
    UINT32  dwBufNum;           /* ��Ϣ������buf������ */
    UINT16  wBufLength;         /* ��Ϣ������ÿ��buf�ĳ���,��Χ������ĺ궨�壬�ұ�����8�������� */
    UINT32  dwTimeSlotMask;     /* �������ʱ������ʹ��˵��*/
} TE1TransChanParam;

/********************************************************************************* 
* dwTimeSlotMask ʱ������ʹ��˵����
*    ʱ����������룬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
* Ts0��Ϊͬ���źţ��û�����ʹ�ã�Ts16����Ϊ���ݻ�����ڱ�ģ���и�ʱ϶���û�����ͨ������
* ʱ϶����ѡ���Ƿ�ʹ�ã�ʱ϶���佨��ӵ͵�����������ʱ϶����Ҫ��������������������ͨ��ϵ
* ͳ���ȶ���
* ��: ʹ��5��ʱ϶ʱdwTimeSlotMask = 0x0000003e,��ʱ����= 64x5 = 320kbit�� ע��:Ts0=0; 
**********************************************************************************/

/* �ص��������Ͷ��� */
typedef void ( * TE1MsgCallBack )(UINT8 byE1ChanID, UINT32 dwState);

/* �û�����ķ������ݲ����ṹ���� */
typedef struct{
    UINT8* pbyMsg;                  /* �û���Ϣָ�� */
    UINT32 dwMsgLen;                /* �û���Ϣ���� */
} TE1TransMsgParam;


/* ͨ�������շ�ͳ�ƽṹ���� */
typedef struct{
    UINT32 dwRxOnePacketLen;        /* ���յ��ĵ������ĳ��� */
    UINT32 dwRxPackets;             /* ��E1��·���յ��İ��� */
    UINT32 dwRxErrPackets;          /* �յ�����İ��� */
    UINT32 dwRxDropPackets;         /* �����ϲ��û������ж����İ��� */
    UINT32 dwRxSucSndPackets;       /* �ɹ������ϲ��û��İ��� */
    UINT32 dwTxSndPackets;          /* �ϲ�Ҫ���͵İ��� */
    UINT32 dwTxSucSndPackets;       /* �ϲ�ɹ����͵��İ��� */
    UINT32 dwTxSucSndPacketLen;     /* �ϲ�ɹ����͵����ܰ������ֽ�Ϊ��λ */
}TE1TransChanStat;


/* ================================= �������� ============================== */

/* ��ȡ�豸ʵ��֧�ֵ�E1���� */
UINT8 E1TransGetMaxE1Num(void);

/* ��һ��E1͸������ͨ�� */
INT32 E1TransChanOpen
(
    UINT8 byE1ChanID,               /* �򿪵�ͨ����,����С�� E1_TRANS_CHAN_MAX_NUM */
    TE1TransChanParam *ptChanParam, /* ͨ���Ĳ������� */
    TE1MsgCallBack  tE1MsgCallBack  /* ע��Ļص����� */
);

/* �ر�һ��E1͸������ͨ�� */
INT32 E1TransChanClose(UINT8 byE1ChanID);                  

/* ���ݷ��� */
INT32 E1TransChanMsgSnd(UINT8 byE1ChanID, TE1TransMsgParam *ptMsgParam); 

/* ��ȡָ��ͨ�����ͻ����������д����͵����ݰ��ĸ��� */
INT32 E1TransTxPacketNumGet(UINT8 byE1ChanID);

/* ����ָ��ͨ�������ڴ�����ͷָ��,����ΪdwOffset�ֽ� */
INT32 E1TransBufQHeadPtrInc(UINT8 byE1ChanID, UINT32 dwOffset);   

/* ����ָ��ͨ�������ڴ�����ָ�����ȵ����ݵ�pbyDstBufָ����ڴ�,���ض������ݵĳ��� */
UINT32 E1TransBufMsgCopy(UINT8 byE1ChanID, UINT8 *pbyDstBuf, UINT32 dwSize); 

/* ��ȡָ��ͨ�������ڴ�����ȡ�����ݳ��ȣ��ֽ�Ϊ��λ */
UINT32 E1TransBufMsgLenGet(UINT8 byE1ChanID);    

/* ��ȡָ��ͨ�������ڴ����ӵ�ǰͷָ�뿪ʼƫ����ΪdwOffset����һ���ֽ� */
INT32 E1TransBufMsgByteRead(UINT8 byE1ChanID, UINT32 dwOffset, UINT8 *pbyRtnByte);  

/* ��ָ��ͨ��������·�Ի� */
INT32 E1TransChanLocalLoopSet(UINT8 byE1ChanID, BOOL bIsLoop);

/* ��ȡָ��ͨ�������շ���ͳ����Ϣ */
INT32 E1TransChanInfoGet(UINT8 byE1ChanID, TE1TransChanStat *ptInfo);    

#ifdef __cplusplus 
} 
#endif /* __cplusplus */


#endif /* __INC_E1TransLib_H */
