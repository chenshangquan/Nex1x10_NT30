/*****************************************************************************
ģ����      : DSPCCI
�ļ���      : dspcci_common.h
����ļ�    : 
�ļ�ʵ�ֹ���:  host��dsp˫��cciͨ��Э����صĺ�����ݽṹ���壬������ͬʱ������
              ע�⣺������ͷ�ļ�ǰ���������Ӧ����������ͷ�ļ���host����kdvtype.h
              dsp�����algorithmtype.h�����ɻ�����
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2008-2010 KEDACOM, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
10/24/2008  01a         �ŷ���     ����.	
******************************************************************************/

#ifndef __DSPCCI_COMMON_H
#define __DSPCCI_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif


/****************************** ģ��İ汾�������涨 *************************
�ܵĽṹ��mn.mm.ii.cc.tttt
     ��  Osp 1.1.7.20040318 ��ʾ
ģ������Osp
ģ��1�汾
�ӿ�1�汾
ʵ��7�汾
04��3��18���ύ

�汾�޸ļ�¼��
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.1.20081024
���ӹ��ܣ�����
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.2.20081225
���ӹ��ܣ��޸�dm647��DMA��д���������Ȳ���Ϊ��ʱ5��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.3.20090109
���ӹ��ܣ��޸�dm647��DMA��д����,ʹ��PRam1,���ƹ�ԭ����Pram0��QDMA��ͻ����
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.4.20090115
���ӹ��ܣ��޸�dm647��DMA��д����,��Ϊ������EDMA�ж�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.5.20090207
���ӹ��ܣ�����Ӳ����λDSPоƬ����,�Ӷ�����ر�647��ʱ����PSC��ʱʧ������
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.6.20090321
���ӹ��ܣ��޸�DM647��PCIͨ���õ�DMAͨ������TC0��ΪTC1���������Ƶ��ͻ���⡣
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.7.20090413
���ӹ��ܣ�1���ύ�޸�DM647��PCIͨ���õ�DMAͨ������TC0��ΪTC1���������Ƶ��ͻ���⡣
          2��֧�ִ���������VP����Ϊ����������������Ϣ���Զ�����VP��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.1.8.20090415
���ӹ��ܣ�1���޸Ĵ���������VP����Ϊ����������������Ϣ���Զ�����VP�ڲ��ԣ�
          2���ں�����·���޸ģ���Ҫͬ������һЩ·������
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.2.8.20090424
���ӹ��ܣ�1������DM647_HPI��DM6437_HPI��������
          2���޸�DSPCCI�ӿڣ�ʹ��ȫ��dwDspId����ʶ���е�DSP������647��6437��
             ��Ҫ�û�������DSP��ͨ�����ӵ�һ���������󶨡�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.2.9.20090506
���ӹ��ܣ�1���޸�DM647_HPI��DM6437_HPI��������CCIͳ����Ϣ�Ĵ���
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.2.10.20090522
���ӹ��ܣ�1���޸�DM647�����г�Ƶ�������õĴ���
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.2.11.20090612
���ӹ��ܣ�1������DSP��EDMA�Ĵ�����ӡ����
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.11.20090622
���ӹ��ܣ�1������DSP���ڴ���Թ��ܽӿ�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.12.20090803
���ӹ��ܣ�1�����ӷ�ֹ�û���DSPͨ��ʱ��ι黹��ϢBuf��У��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.13.20090804
���ӹ��ܣ���
�޸�ȱ�ݣ��޸�һ����ѯ���ն�����Ϣ���ͽ�����Ϣʱ�ж�������Ϣ�Ĳ�һ�µ�����
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.14.20090815
���ӹ��ܣ���
�޸�ȱ�ݣ��޸�CCIͨ�Ŷ��б��ƻ���Bug������inline��������궨����ʵ���ֽ���ת��
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.15.20090818
���ӹ��ܣ���
�޸�ȱ�ݣ��޸�CCIͨ�Ŷ������ж�ָ�벻ƥ������
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.16.20091124
���ӹ��ܣ����Ӷ�KDV7810��֧��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.17.20091126
���ӹ��ܣ����Ӷ�KDV7620��֧�֣��Ż���dsp�������û�ȡ�ӿ�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.18.20100224
���ӹ��ܣ���������dm647��DDRƵ�ʹ��ܣ���������266(Ĭ��)��300��333MHz��
        ! �������е�647����ͬһ��ʱ��Դ��������е�647оƬ����������ͬ��DDRƵ��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.19.20100701
���ӹ��ܣ�ÿ�δ�DM647��ʱ����0һ�����е�DDR��L2 Ram���Թ��DSP��ĳЩģ�鲻
          ��ʼ���Լ��ı������µ�һϵ����ֵ��쳣���⡣
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��DspCciLib 1.3.20.20110412
���ӹ��ܣ����dsp�����ݷ���magic number������ҵ�񲿹�������
�޸�ȱ�ݣ���
�ύ�ˣ�hechengjie

****************************************************************************/

/* �汾��Ϣ */
#define DSPCCI_MOD_VERSION              ( const char * )"DspCciLib 1.3.20.20110412"

/* ���޶��� */
#define DSPCCI_DSP_MAXNUM               5           /* ���֧�ֵ�DSP�ĸ��� */

/* ��Ϣ��ӡ�궨�� */
#if 1
#define DSPCCI_MAX_PRT_MSGS             100         /* ��ӡ��Ϣ�������� */
#define DSPCCI_MAX_PRT_MSGLEN           320         /* ��ӡ��Ϣ����󳤶� */
#else
#define DSPCCI_MAX_PRT_MSGS             32         /* ��ӡ��Ϣ�������� */
#define DSPCCI_MAX_PRT_MSGLEN           320         /* ��ӡ��Ϣ����󳤶� */
#endif

/* DSPCCIͨ����Ϣ���Եĺ궨�� */
#define DSPCCI_DN_MSGQ_MAX              256         /* ���������Ϣ������ */
#define DSPCCI_UP_MSGQ_MAX              256         /* ���������Ϣ������ */
#define DSPCCI_ERR_LOG_MAX_NUM          32          /* DSP�����¼�������� */
#define DSPCCI_MSG_ALIGN_BYTES 	        256         /* n�ֽڶ��룬Ҫ����TDspCciMsgHead�ṹ��С�������� */
#define DSPCCI_PROTOCOL_VERSION         1           /* DSPCCI��Э��汾�ţ�Э�鷢���ı�ʱ��1��HOST��DSP���뱣��һ�� */

/* �����궨�� */
#define DSPCCI_MAGIC_NUMBER             0xbeafbeaf
#define DSPCCI_START_MAGIC_NUMBER       0xdaaddeed

#define DSPCCI_HEAD_PAD                 0x55555555

/* ��Ϣ���ͺ궨�� */
#define DSPCCI_IS_USR_MSG               0           /* �û���Ϣ */
#define DSPCCI_IS_HOST_LOOPBACK_MSG     1           /* �����Ի�������Ϣ */
#define DSPCCI_IS_HOST_SEND_TEST_MSG    2           /* �������Ͳ�����Ϣ*/
#define DSPCCI_IS_DSP_SEND_TEST_MSG     3           /* DSP���Ͳ�����Ϣ */
#define DSPCCI_IS_DSP_PRINT_MSG         4           /* DSP��ӡ��Ϣ */

/* ����ֵ�궨�� */
#define DSPCCI_SUCCESS                  0           /* CCIͨ�����ӽ����ɹ� */
#define DSPCCI_PEER_CLOSED              1           /* CCIͨ����Զ���豸�Ͽ� */
#define DSPCCI_NOT_CONNECTED            2           /* CCIͨ��û�н��� */
#define DSPCCI_SMEM_CORRUPT             3           /* CCI�����ڴ������ƻ� */
#define DSPCCI_LENGTH_ERROR             4           /* CCIͨ����Ϣ���ȴ��� */
#define DSPCCI_QUEUE_FULL               5           /* CCI��Ϣ�������� */
#define DSPCCI_MSG_LOST                 6           /* CCI��Ϣ��ʧ */
#define DSPCCI_PARAM_ERR                7           /* �������� */
#define DSPCCI_NOT_SUPPORT              8           /* ��֧�ֵĲ��� */
#define DSPCCI_MULTI_OPEN               9           /* ��δ��豸 */
#define DSPCCI_NOT_OPEN                 10          /* �豸û�д� */
#define DSPCCI_OPEN_FAIL                11          /* �豸��ʧ�� */
#define DSPCCI_IOC_FAIL                 12          /* �豸ioctlʧ�� */
#define DSPCCI_NO_MEM                   13          /* �ڴ治�� */
#define DSPCCI_TIMEOUT                  14          /* ������ʱ */
#define DSPCCI_QUEUE_EMPTY              15          /* CCI��Ϣ���п� */
#define DSPCCI_FAILURE                  -1          /* CCI����ʧ�� */

/* CCIͨ����Ϣ���Եĺ궨�� */
#define DSPCCI_UPCHNL                   0           /* ����ͨ����� */
#define DSPCCI_DNCHNL                   1           /* ����ͨ����� */

#define DSPCCI_START_SHM_OFFSET         0x20        /* START�������RAM_BASE��ƫ��������ǰ��0x20�ռ䱣��
                                                       PCIͨ��ʱ����0x20��С����reset_vector�������������� */

/* ���Ͷ��� */
typedef void * HDspCciObj;                          /* DSPͨ�Ŷ������� */


/* START���ṹ���� */
typedef struct{
    volatile u32 dwCciStartMarker;           /* start���Ļ�����DSP�ȳ�ʼ��Ϊ0xdaaddeed,֮��������ʼ��Ϊ0xbeafbeaf */
    volatile u32 dwCciHostStartupFlag;       /* ����������־�� 1--���� */
    volatile u32 dwCciInfoAvailableFlag;     /* Info����Ч��־��������ʼ��Ϊ0����DSP������INFO���ڴ������Ϊ1 */
    volatile u32 dwCciInfoBaseAddr;          /* info������ַ��������ʼ��Ϊ0 */
    volatile u32 dwDspCciVer;                /* DSP��CCI�汾��,��DSP����д��������У���Ƿ��DSPCCI_PROTOCOL_VERSIONƥ�� */
    volatile u32 dwHostCciVer;               /* ������CCI�汾��,����������д��map��У���Ƿ��DSPCCI_PROTOCOL_VERSIONƥ�� */
    volatile u32 dwBrdID;                    /* ʹ��brdwrapperdef.h�е�������ID�ź궨�� */
    volatile u32 dwHwVer;                    /* Ӳ���汾�� */
    volatile u32 dwFpgaVer;                  /* EPLD/FPGA/CPLD�ĳ���汾�� */
    volatile u32 dwDspId;                    /* ��ʶ��ǰ����һ��dsp����0��ʼ��� */
}
TDspCciStartBuf;


/* ͨ��������Ϣ�ṹ���� */
typedef struct{
    volatile u32 dwBufBase;                  /* �ڴ�ػ���ַ, DSPCCI_MSG_ALIGN_BYTES���� */
    volatile u32 dwMaxMsgLen;                /* ��Ϣ����󳤶�(��BYTE��)��Ҫ��8�������� */
    volatile u32 dwMaxMsgs;                  /* ��໺�����Ϣ���� */
    volatile u32 dwBufSize;                  /* �ڴ�ش�С,Ϊ(dwMaxMsgLen*dwMaxMsgs)��DSPCCI_MSG_ALIGN_BYTES���� */
    volatile u32 dwReadPtr;                  /* �ڴ�ض�ָ��,Ϊ����ڴ�ػ���ַ��ƫ���� */
    volatile u32 dwWritePtr;                 /* �ڴ��дָ��,Ϊ����ڴ�ػ���ַ��ƫ���� */
    volatile u32 dwWriteNum;                 /* �Ѿ�д������ݰ����� */
    volatile u32 dwReadNum;                  /* �Ѿ����������ݰ����� */
    volatile u32 dwNextRcvMsgPtr;            /* ������һ��������Ϣ�ĵ�ַ */
    volatile u32 dwDspRxTxMsgs;              /* DSP����/�հ����� */
    volatile u32 dwDspRxErrOrTxOkMsgs;       /* DSP�ɹ�����/���մ������ */
    volatile u32 dwDspRxTxKBytes;            /* DSP����/����������KByte */
    volatile u32 dwDspRxTxBytes;             /* DSP����/����������Byte */
}
TDspCciChnlInfo;


/* INFO���ṹ���� */
typedef struct{
    volatile u32 dwCciInfoMarker;            /* INFO���Ļ���,��ЧֵΪ0xbeafbeaf */
    volatile u32 dwHostRdyFlag;              /* ����������־��1--�������ͨ����������3--�������ͨ���ڴ�أ�7--֪ͨdspͨ�Ŵ���ok */
    volatile u32 dwDspRdyFlag;               /* DSP������־��1--�ѷ���ͨ����������3--�ѷ���ͨ���ڴ�أ� */
    volatile u32 dwDspHeartBeat;             /* DSP��������DSP���������ۼӣ��������� */
    volatile u32 dwUpChnlNum;                /* ����ͨ������ */
    volatile u32 dwDnChnlNum;                /* ����ͨ������  */
    volatile u32 dwUpChnlInfoBase;           /* ����ͨ������������ַ */
    volatile u32 dwDnChnlInfoBase;           /* ����ͨ������������ַ  */

    volatile u32 dwDspPrtEn;                 /* �����ӡ��־  */
    volatile TDspCciChnlInfo tPrtChnlInfo;   /* ��ӡͨ��������Ϣ */

    volatile u32 dwDspErrLog[DSPCCI_ERR_LOG_MAX_NUM];/* DSP�����¼����DSP�������д */
}
TDspCciInfoBuf;


/* ��Ϣͷ���ṹ���� */
typedef struct{
    volatile u32 dwDebug[4];
    volatile u32 dwMsgMarker;                /* ��Ϣͷ����,��ЧֵΪ0xbeafbeaf */
    volatile u32 dwMsgType;                  /* ��Ϣ���ͣ��ο�: ��Ϣ���ͺ궨�� */
    volatile u32 dwMsgLen;                   /* ��Ϣ�峤�� */
    volatile u32 dwNextMsgAddr;              /* ��һ����Ϣ��ƫ�Ƶ�ַ(���dwBufBase)��DSPCCI_MSG_ALIGN_NUMBER�ֽڶ��� */
}
TDspCciMsgHead;

/* ��Ϣ�����ṹ���� */
typedef struct{
    u8* pbyMsg1;                    /* �û���Ϣ1ָ�� */
    u8* pbyMsg2;                    /* �û���Ϣ2ָ�룬����ʱ�ö���Ч */
    u32 dwMsg1Len;                  /* �û���Ϣ1���� */
    u32 dwMsg2Len;                  /* �û���Ϣ2���ȣ�����ʱ�ö���Ч */
    u32 dwMsgType;                  /* ��Ϣ���ͣ���: ��Ϣ���ͺ궨�� */
} TDspCciMsgDesc;

#ifdef __cplusplus
}
#endif

#endif /* __DSPCCI_COMMON_H */
