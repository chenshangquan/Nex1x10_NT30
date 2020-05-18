/******************************************************************************
ģ����  �� MSNDIO_DRV
�ļ���  �� MSNDio_api.h
����ļ��� MSNDio_api.c
�ļ�ʵ�ֹ��ܣ�����ý����Ƶ�ӿ�
����    ���ŷ���
�汾    ��1.0.0.0.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
07/12/2011  1.0         �ŷ���      ����
******************************************************************************/
#ifndef __MSND_AUDIO_API_H
#define __MSND_AUDIO_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* runtime include files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "kdvtype.h"


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
ģ��汾��MSND_AUDIO_DRV 1.1.1.20110712
���ӹ��ܣ�����
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------

****************************************************************************/
/* �汾�Ŷ��� */
#define VER_MSNDIO_DRV        (const s8*)"MSND_AUDIO_DRV 1.1.1.20110712" 

/* ����ģ�鷵��ֵ���� */
#define MSND_ELEN        -8   /**< len err (failure). */
#define MSND_ENOOPEN     -7   /**< IO no open (failure). */
#define MSND_EBUSY       -6   /**< An IO busy occured (failure). */
#define MSND_EINVAL      -5   /**< Invalid input arguments (failure). */
#define MSND_ENOMEM      -4   /**< No memory available (failure). */
#define MSND_EIO         -3   /**< An IO error occured (failure). */
#define MSND_ENOTIMPL    -2   /**< Functionality not implemented (failure). */
#define MSND_EFAIL       -1   /**< General failure code (failure). */
#define MSND_EOK          0   /**< General success code (success). */
#define MSND_EFLUSH       1   /**< The command was flushed (success). */
#define MSND_EPRIME       2   /**< The command was primed (success). */
#define MSND_EFIRSTFIELD  3   /**< Only the first field was processed (success)*/
#define MSND_EBITERROR    4   /**< There was a non fatal bit error (success). */
#define MSND_ETIMEOUT     5   /**< The operation was timed out (success). */
#define MSND_EEOF         6   /**< The operation reached end of file */
#define MSND_EAGAIN       7   /**< The command needs to be rerun (success). */

/* ����ֵ���� */
#define MSND_DEV_MAX_NUM  9   /* Ŀǰ���֧��5����Ƶ�豸 */
#define MSND_BUF_MAX_NUM  32  /* Ŀǰ�����������BUF���� */

/* ��Ƶ�豸��ģʽ����  */
#define MSND_IOM_INPUT    0   /* ����ģʽ�����ɼ� */
#define MSND_IOM_OUTPUT   1   /* ���ģʽ�������� */

/* MsndCtrl�����붨�� */
#define MSND_GET_RX_STAT  0   /* ��Ƶ����ͳ��״̬��ѯ */
#define MSND_GET_TX_STAT  1   /* ��Ƶ����ͳ��״̬��ѯ */

/* ���Ͷ��� */
typedef void * HMsndDev;

/* ��Ƶ���ݿڶ��壬����McAsp�豸��˵��Ч������ָ����ǰASP�豸�󶨵������������I2S��· */
#define MSND_SER0    (1 << 0)
#define MSND_SER1    (1 << 1)
#define MSND_SER2    (1 << 2)
#define MSND_SER3    (1 << 3)
#define MSND_SER4    (1 << 4)
#define MSND_SER5    (1 << 5)
#define MSND_SER6    (1 << 6)
#define MSND_SER7    (1 << 7)
#define MSND_SER8    (1 << 8)
#define MSND_SER9    (1 << 9)
#define MSND_SER10   (1 << 10)
#define MSND_SER11   (1 << 11)
#define MSND_SER12   (1 << 12)
#define MSND_SER13   (1 << 13)
#define MSND_SER14   (1 << 14)
#define MSND_SER15   (1 << 15)
#define MSND_SER16   (1 << 16)
#define MSND_SER17   (1 << 17)



typedef struct{
    u32	    dwFBufId;           /* ֡BUF�������ţ������ڲ�ʹ�ã��û������޸� */
    u8 *    pbyFBuf;            /* ֡BUF��ָ�룬ָ��֡����Buf��
                                    �û�����BufDescʱ�����NULL�Ļ������Զ�����1������BUF������ʹ���û�ָ���ĵ�ַ��Ϊ����BUF��
                                    !!! ������û����䣬
                                        1���û����뱣֤Buf�Ķ��룬����ʼ��ַ������128�ֽڶ���;
                                        ����BUF��С=dwBytesPerSample*dwSamplePerFrame*dwChanNum;
                                        2���ر��豸ʱ���������ͷ���Щ�ڴ� */
    BOOL32  bUseCache;          /* �������û�����Buf��Ч�������Զ������Ϊ��cache�ģ�
                                   ΪTRUE��ʾ�û������Buf��cache��������������ˢcache����
                                   ΪFALSEΪ����cache�ģ���������ˢcache���� */
    u32	    dwTimeStamp;        /* ֡��ʱ������ɼ�ʱ�û����Զ�ȡ��ǰ֡��ʱ��� */
} TMsndFBufDesc;

/* ��ƵIO�豸�����Ĳ����ṹ����
 *  ��buffer�� AUD_SER0 �� AUD_SERn ·�����ҽ���ֲ�������Ϊbuffer��n��֮1, 
    �޷����� AUD_SERn ��buffer�е�λ�á���ɼ�����SER1 SER2 �� SER3�����ڴ�����������Ϊ��
    SER1_L SER2_L SER3_L SER1_R SER2_R SER3_R ... ���DM647��ͬ
 *
 *  dwChnlCfg���ã�
 *  T300: 
 *       ��Ƶ����    
 *                  �����                ��������                    ��Ӧ��
 *                RCA_DIN1    2���������ӻ�������(���Ա������ұ�)    MSND_SER0
 *                3.5_DIN2    3.5mm�������1����(���Ա��������)     MSND_SER1
 *                3.5_DIN3    3.5mm�������2����                     MSND_SER2
 *                3.5_DIN4    3.5mm�������3����				     MSND_SER3
 *                3.5_DIN5    3.5mm�������4����                     MSND_SER4
 *                XLR1_2_DIN1     ��ũ1&��ũ2(���Ա��������)        MSND_SER5
 *                XLR3_4_DIN2     ��ũ3&��ũ4						 MSND_SER6
 *				  XLR5_6_DIN3     ��ũ5&��ũ6                        MSND_SER7
 *			      XLR7_8_DIN4     ��ũ7&��ũ8 						 MSND_SER8
 *                XLR9_10_DIN5    ��ũ9&��ũ10 						 MSND_SER9
 *				  RX1_DIN1		  ����MIC1                           MSND_SER10
 *				  RX2_DIN2		  ����MIC2                           MSND_SER11
 *				  RX3_DIN3		  ����MIC3                           MSND_SER12
 *                DVI-IN-5 6 7 8 ѡһ·                              MSND_SER13
 *                DVI-IN-9 10 11 ѡһ·                              MSND_SER14
 *                RCA-DIN1   �������������1(�ز�)					 MSND_SER15
 *                RCA-DIN2   �������������2(�ز�) 				     MSND_SER16
 *                RCA-DIN3   �������������3(�ز�)					 MSND_SER17
 *       ��Ƶ���
 *                  �����                ��������                    ��Ӧ��
 *				  RCA-DOUT1   �������������1 (���Ա��������)       MSND_SER0
 *				  RCA-DOUT2   �������������2                        MSND_SER1
 *				  RCA-DOUT3   �������������3                        MSND_SER2
 *				  RCA-DOUT4   �������������4                        MSND_SER3
 *				  RCA-DOUT5   �������������5                        MSND_SER4
 *				  SPEAKER     ������                                 MSND_SER5
 *                DVI-OUT1    DVI-OUT-1                              MSND_SER6
 *                DVI-OUT2    DVI-OUT-2                              MSND_SER7
 *                DVI-OUT3    DVI-OUT-3                              MSND_SER8
 *                DVI-OUT4    DVI-OUT-4                              MSND_SER9
 *                DVI-OUT5    DVI-OUT-5                              MSND_SER10
 *  
 */
typedef struct{
    u32   dwBytesPerSample;     /* һ���������ֽ�����1 2 4 */
    u32   dwSamplePerFrame;     /* һ֡���������� */
    u32   dwChnlNum;            /* ����������2������������n·��������1֡���ֽ���=dwBytesPerSample*dwSamplePerFrame*dwChanNum */
    u32   dwChnlCfg;            /* ��0��ʾ��Ĭ������serial���������·, ����ֵ��MSND_SER0�ȵļ����壬�߼��û�ʹ�� */
    u32   dwFrameNum;           /* ����Frame�ĸ�������Χ��2~MSND_BUF_MAX_NUM-1 */
    u32   dwSampleFreq;         /* 8000��48000��96000��192000Hz ... */
    TMsndFBufDesc *pBufDescs;  /* ָ���û������FBufDesc�ṹ����������׵�ַ���û������Լ���������Buf����ָ�봫�ݸ�����
                                    �������ΪdwFrameNum, ע�⣺��Ƶ��Ҫ128�ֽڱ߽���룻
                                    ���ڲ����Լ�����Buf���û���ΪNULLʱ���ɣ������ᰴ��ǰ��Ĳ����Զ�����BUF */
} TMsndDevParam;

/* ��Ƶ�ɼ�ͳ��״̬�ṹ���壬��Ӧ�����룺MSND_GET_RX_STAT */
typedef struct{
    u32   dwFragsTotal;         /* ����������ܻ������Ƶ����֡������ */
    u32   dwFragSize;           /* �����л���һ֡��Ƶ���ݵ��ֽ���,��·�������ܺ� */
    u32   dwFragments;          /* �������ܶ�ȡ����Ƶ����֡�ĸ��� */
    u32   dwBytesCanRd;         /* �������ܶ�ȡ����Ƶ�����ֽ�������������ʱҪ�� */
    u32   dwLostBytes;          /* ���ڲɼ���ʾ�������ֽ�����һ����û�п���bufʱ��������������ʱҪ�� */
    u32   dwDmaErr;             /* dma����Ĵ��� */
    u32   dwOverRunErr;         /* Overrun����Ĵ��� */
    u32   dwSyncErr;            /* ֡ͬ������Ĵ��� */
    u32   dwPingPongErr;        /* ping-pong��ת����Ĵ��� */
    u32   adwReserved[5];       /* reserved */
} TMsndRxStat;

/* ��Ƶ����״̬�ṹ���壬��Ӧ�����룺MSND_GET_TX_STAT */
typedef struct{
    u32   dwFragsTotal;         /* ����������ܻ������Ƶ����֡������ */
    u32   dwFragSize;           /* �����л���һ֡��Ƶ���ݵ��ֽ��� */
    u32   dwFragments;          /* ��������д�����Ƶ����֡�ĸ��� */
    u32   dwBytesCanWrt;        /* ��������д�����Ƶ�����ֽ�����dwFragsTotal*dwFragSize-dwBytesCanWrt=��ǰ�����ŵ���Ƶ�����ֽ��� */
    u32   dwMuteBytes;          /* ���ڲ��ű�ʾ���ž������ֽ�����һ����û����Ƶ����ʱ��������������ʱҪ�� */
    u32   dwDmaErr;             /* dma����Ĵ��� */
    u32   dwUnderRunErr;        /* Underrun����Ĵ��� */
    u32   dwSyncErr;            /* ֡ͬ������Ĵ��� */
    u32   dwPingPongErr;        /* ping-pong��ת����Ĵ��� */
    u32   adwReserved[5];       /* reserved */
} TMsndTxStat;


/*==============================================================================
    ������      : MsndOpen
    ����        ����ƵIO�豸�򿪣�1��dwDevId���Դ�2�Σ��ֱ�ΪINPUT/OUPUT
    �������˵����dwDevId: 0~MSND_DEV_MAX_NUM-1;
                  nMode: MSND_IOM_INPUT/MSND_IOM_OUTPUT
                  ptParam: �򿪵Ĳ���
                  phAudDev: ���ƾ��ָ��
    ����ֵ˵��  �����󷵻�MSND_EFAIL������룻�ɹ�����MSND_EOK�Ϳ��ƾ��
------------------------------------------------------------------------------*/
s32 MsndOpen(u32 dwDevId, s32 nMode, TMsndDevParam *ptParam, HMsndDev *phAudDev);

/*==============================================================================
    ������      : MsndClose
    ����        ����ƵIO�豸�رա�
    �������˵����hAudDev: MsndOpen�������صľ��;
    ����ֵ˵��  �����󷵻�MSND_EFAIL������룻�ɹ�����MSND_EOK
------------------------------------------------------------------------------*/
s32 MsndClose(HMsndDev hAudDev);

/*==============================================================================
    ������      : MsndRead
    ����        ����ƵIO�豸�����ݣ���ȡ���ȱ�����dwBytesPerSample*dwChanNum����������
    �������˵����hAudDev: ��MSND_IOM_INPUTģʽ����MsndOpen�������صľ��;
                 pBuf: ָ���û������Buf��������Ųɼ�����Ƶ����
                 size��Ҫ��ȡ�������ֽ���
                 nTimeoutMs: -1=wait forever; 0=no wait;������ֵΪ��ʱ������
    ����ֵ˵��  �����󷵻�MSND_EFAIL����ʱ����0���ɹ����ض������ֽ���(=size)
------------------------------------------------------------------------------*/
s32 MsndRead(HMsndDev hAudDev, void *pBuf, size_t size, s32 nTimeoutMs);

/*==============================================================================
    ������      : MsndWrite
    ����        ������ƵIO�豸д���ݣ������ֽ���������dwBytesPerSample*dwChanNum��������
    �������˵����hAudDev: ��MSND_IOM_OUTPUTģʽ����MsndOpen�������صľ��;
                 pData: ָ���û���Ŵ����ŵ���Ƶ����
                 size��Ҫ���ŵ������ֽ���
                 nTimeoutMs: -1=wait forever; 0=no wait;������ֵΪ��ʱ������
    ����ֵ˵��  �����󷵻�MSND_EFAIL����ʱ����0���ɹ�����д����ֽ���(=size)
------------------------------------------------------------------------------*/
s32 MsndWrite(HMsndDev hAudDev, void *pData, size_t size, s32 nTimeoutMs);

/*==============================================================================
    ������      : MsndFBufGet
    ����        ��ȡһ֡��ƵBUF�����ڲɼ��û��õ�������Ƶ����Buf�����ڲ����û�
                  �õ����ǿ�Buf���û����Զ�ε���ȡ���BUF��
                  # ����û�ʹ��read write�Ļ�����ʹ�øú���!!!
    �������˵����hAudDev: ����MsndOpen�������صľ��;
                  ptBufDesc: �û����䲢����ָ�룬������BUF��Ϣ�������û�
                  nTimeoutMs: -1=wait forever; 0=no wait;������ֵΪ��ʱ������
    ����ֵ˵��  �����󷵻�MSND_EFAIL������룻�ɹ�����MSND_EOK
------------------------------------------------------------------------------*/
s32 MsndFBufGet(HMsndDev hAudDev, TMsndFBufDesc *ptBufDesc, s32 nTimeoutMs);

/*==============================================================================
    ������      : MsndFBufPut
    ����        ���黹һ֡��ƵBUF
                  # ����û�ʹ��read write�Ļ�����ʹ�øú���!!!
    �������˵����hAudDev: ����MsndOpen�������صľ��;
                  ptBufDesc: �û�����MsndFBufGet�õ���BufDesc��Ϣ
    ����ֵ˵��  �����󷵻�MSND_EFAIL������룻�ɹ�����MSND_EOK
------------------------------------------------------------------------------*/
s32 MsndFBufPut(HMsndDev hAudDev, TMsndFBufDesc *ptBufDesc);

/*====================================================================
    ������      : MsndCtrl
    ����        ����ƵIO�豸���ƣ�Ŀǰ������
                    MSND_GET_RX_STAT: pArgsΪTMsndRxStat *
                    MSND_GET_TX_STAT: pArgsΪTMsndTxStat *
                  ......
    �������˵����hAudDev: ����MsndOpen�������صľ��;
                 nCmd: �����룻pArgs: ����ָ��
    ����ֵ˵��  �����󷵻�MSND_EFAIL������룻�ɹ�����MSND_EOK
---------------------------------------------------------------------*/
s32 MsndCtrl(HMsndDev hAudDev, s32 nCmd, void *pArgs);

/*====================================================================
    ������      : MsndGetVer
    ����        ��ģ��汾�Ų�ѯ��
    �������˵����pchVer�� �����Ĵ�Ű汾��Ϣ��bufָ��
                  dwBufLen������buf�ĳ���
    ����ֵ˵��  ���汾��ʵ���ַ������ȡ�С��0Ϊ����;
                 ���ʵ���ַ������ȴ���dwBufLen����ֵΪ0
--------------------------------------------------------------------*/
s32 MsndGetVer(s8 *pchVer, u32 dwBufLen);


#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* __MSNDIO_API_H */
