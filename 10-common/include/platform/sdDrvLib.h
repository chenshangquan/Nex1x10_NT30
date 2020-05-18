/*****************************************************************************
ģ����      : SD_MODULE
�ļ���      : sdDrvLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  SD_MODULE �ϲ�ӿں궨��ͺ���������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2005-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���     �߶���       �޸�����
2006/01/04  01a        �ŷ���                  ����	
******************************************************************************/

#ifndef __INC_SdDrvLib_H
#define __INC_SdDrvLib_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


/* ================================= �궨�� ================================ */

/* sd����ģ�鷵��ֵ�ʹ��������� */
#define SD_SUCCESS              (INT32)0                    /* �ɹ� */
#define SD_FAILURE              (INT32)-1                   /* δ֪���쳣ʧ�� */

#define SD_ERRCODE_BASE         (INT32)1                    /* �������ֵ */
#define SD_NOT_INIT             (INT32)(SD_ERRCODE_BASE+0)  /* �豸δ��ʼ�� */
#define SD_PARAM_ERROR          (INT32)(SD_ERRCODE_BASE+1)  /* �����Ƿ� */

/* sd��Χ���� */
#define SD_CARD_MAX_NUM         (UINT8)1                    /* ���֧��1��sd�� */
#define SD_STRING_MAX_LEN       (UINT8)16                   /* �ַ�����󳤶ȶ��� */

#define SD_DOS_OPT_DEFAULT      (INT32)0                    /* �ļ�ϵͳ��ʽ�������� */
#define SD_FSCHK_OPT_DEFAULT    (INT32)0                    /* �ļ�ϵͳ��鹦���� */

/* ============================== �ṹ�����Ͷ��� =========================== */

/* ����sd����Ϣ�����ṹ���� */
typedef struct{
    BOOL   bExist;                            /* sd�����ڱ�־ */
    BOOL   bFormated;                         /* sd����ʽ����־ */
    UINT32 dwSizeInMBytes;                    /* sd����������MByteΪ��λ */
    char   achModel[SD_STRING_MAX_LEN];       /* sd���ͺ� */
    char   achPartionName[SD_STRING_MAX_LEN]; /* �����豸�� */
} TOneSdCardInfo;

/* ����sd����Ϣ�����ṹ���� */
typedef struct{
    TOneSdCardInfo tSdInfo[SD_CARD_MAX_NUM];
} TSdCardInfo;



/* ================================= �������� ============================== */

/* ��ȡָ��sd������Ϣ */
INT32 SdApiGetDiskInfo(TSdCardInfo *ptSdInfo);

/* sd���ĸ�ʽ�� */
INT32 SdApiPartnFormat(char *pPartionName, INT32 nOpt);

/* sd�������ļ�ϵͳ��� */
INT32 SdApiChkdsk(char *pPartionName, INT32 nOpt);

/* sd��ʣ��������ѯ */
INT32 SdApiGetPartnFreeSize(char *pPartionName, UINT32 *pdwFreeKbytes);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */


#endif /* __INC_SdDrvLib_H */
