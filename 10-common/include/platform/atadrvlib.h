/*****************************************************************************
ģ����      : ATA_MODULE
�ļ���      : ataDrvLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  ATA_MODULE �ϲ�ӿں궨��ͺ���������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2005-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���     �߶���       �޸�����
2005/10/22  01a        �ŷ���                  ����	
******************************************************************************/

#ifndef __INC_ataDrvLib_H
#define __INC_ataDrvLib_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


/* ================================= �궨�� ================================ */

/* ata����ģ�鷵��ֵ�ʹ��������� */
#define ATA_SUCCESS             (INT32)0                    /* �ɹ� */
#define ATA_FAILURE             (INT32)-1                   /* δ֪���쳣ʧ�� */

#define ATA_ERRCODE_BASE        (INT32)1                    /* �������ֵ */
#define ATA_NOT_INIT            (INT32)(ATA_ERRCODE_BASE+0) /* �豸δ��ʼ�� */
#define ATA_PARAM_ERROR         (INT32)(ATA_ERRCODE_BASE+1) /* �����Ƿ� */

#define	ATA_IN_STANDBY          (UINT8)0x00	            /* ����״̬ */
#define	ATA_IN_IDLE             (UINT8)0x80	            /* ����״̬ */
#define	ATA_IN_ACTIVE           (UINT8)0xFF	            /* �״̬ */

/* ATA��Χ���� */
#define ATA_HD_MAX_NUM          (UINT8)4                    /* ���֧��4��Ӳ�� */
#define ATA_STRING_MAX_LEN      (UINT8)40                   /* �ַ�����󳤶ȶ��� */

#define ATA_HD_PARTION_MAX_NUM  (UINT8)4                    /* Ӳ������������ */

#define ATA_DOS_OPT_DEFAULT     (INT32)0                    /* Ӳ�̷��������� */

#define ATA_FSCHK_OPT_DEFAULT   (INT32)0                    /* Ӳ���ļ�ϵͳ��鹦���� */

#define ATA_STANDBY_MAX_IDLE_TIME   ((INT32)(18000))        /* Ӳ�̹���������ʱ��ֵΪ5Сʱ */

/* ============================== �ṹ�����Ͷ��� =========================== */

/* ����Ӳ����Ϣ�����ṹ���� */
typedef struct{
    BOOL   bHDiskExist;                       /* Ӳ�̴��ڱ�־ */
    char   achHDiskModel[ATA_STRING_MAX_LEN]; /* Ӳ���ͺ� */
    UINT32 dwHDiskMBytes;                     /* Ӳ����������MByteΪ��λ */
}TAtaHDiskInfo;


/* Ӳ�̷�����Ϣ�����ṹ���� */
typedef struct{
    BOOL   bFormated;                         /* ������ʽ����־����ȡʱ��Ч������ʱ������ */
    UINT32 dwPartionMBytes;                   /* ������������MByteΪ��λ */
    char   achPartionName[ATA_STRING_MAX_LEN];/* �����豸������ȡʱ��Ч������ʱ������ */
}TOnePartionInfo;

typedef struct{
    UINT32 dwPartionNum;                      /* Ӳ�̷�������,0~ATA_HD_PARTION_MAX_NUM-1 */
    TOnePartionInfo tPartionInfo[ATA_HD_PARTION_MAX_NUM]; /* Ӳ�̷�����Ϣ */
}THDiskPartionInfo;


/* ================================= �������� ============================== */

/* ��ȡָ��Ӳ�̵���Ϣ */
INT32 AtaApiGetHDiskInfo(UINT8 byHDiskId, TAtaHDiskInfo *ptAtaHDiskInfo);

/* Ӳ�̷��� */
INT32 AtaApiFdisk(UINT8 byHDiskId, THDiskPartionInfo *ptPartionInfo);

/* Ӳ�̷����ĸ�ʽ�� */
INT32 AtaApiPartnFormat(char *pPartionName, INT32 nOpt);

/* Ӳ�̷�����Ϣ��ѯ */
INT32 AtaApiGetPartnInfo(UINT8 byHDiskId, THDiskPartionInfo *ptPartionInfo);

/* Ӳ�̷����ļ�ϵͳ��� */
INT32 AtaApiChkdsk(char *pPartionName, INT32 nOpt);

/* Ӳ�̷���ʣ��������ѯ */
INT32 AtaApiGetPartnFreeSize(char *pPartionName, UINT32 *pdwFreeKbytes);

/*====================================================================
/*  ����        ��Ӳ���Զ��������� 
    �������˵����byHDiskId: Ӳ�̱�ţ���Χ 0~ ATA_HD_MAX_NUM-1
                 nIdleTimeSec��Ӳ����û�ж�д�����������ʱ�䣬��Ϊ��λ��
                               0Ϊ�������ߣ��������߼����һֱ��������״̬
                               ����ܳ���5Сʱ(ATA_STANDBY_MAX_IDLE_TIME)
    ����ֵ˵��  �����󷵻���ata����ģ����������������룻
                 �ɹ�, ����ATA_SUCCESS.
----------------------------------------------------------------------*/
INT32 AtaApiSetStandby(UINT8 byHDiskId, INT32 nIdleTimeSec);

/*====================================================================
    ����        ����ѯӲ�̵�ǰ����״̬��
    �������˵����byHDiskId: Ӳ�̱�ţ���Χ 0~ ATA_HD_MAX_NUM-1
                pbyPWRMode: ���Ӳ�̵�Դģʽ��ָ�룬�������ͣ�
                #define	ATA_IN_STANDBY          (UINT8)0x00 ����״̬
                #define	ATA_IN_IDLE             (UINT8)0x80 ����״̬
                #define	ATA_IN_ACTIVE           (UINT8)0xFF �״̬
    ����ֵ˵��  �����󷵻���ata����ģ����������������룻
                 �ɹ�, ����ATA_SUCCESS.
----------------------------------------------------------------------*/
INT32 AtaApiGetPWRMode(UINT8 byHDiskId, UINT8 *pbyPWRMode);

/*====================================================================
    ����        �����ݷ�����
    �������˵����device: Ҫ���ݵ�Ӳ���豸�ڵ�ţ���"/dev/hda0"    
    ����ֵ˵��  ���ɹ�, ����ATA_SUCCESS.
                  ʧ�ܣ�����ATA_FAILURE
----------------------------------------------------------------------*/
INT32 AtaApiBackupPartitionTable(char *device);

/*====================================================================
    ����        ����ԭ������
    �������˵����device: Ҫ��ԭ��Ӳ���豸�ڵ�ţ���"/dev/hda0"    
    ����ֵ˵��  ���ɹ�, ����ATA_SUCCESS.
                  ʧ�ܣ�����ATA_FAILURE
----------------------------------------------------------------------*/
INT32 AtaApiRestorePartitionTable(char *device);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */


#endif /* __INC_ataDrvLib_H */
