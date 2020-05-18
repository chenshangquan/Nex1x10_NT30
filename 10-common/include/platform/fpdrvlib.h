/*****************************************************************************
ģ����      : flashDisk
�ļ���      : fpDrvLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  .
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/2/25  01a         �ŷ���      ����	
******************************************************************************/
#ifndef __INC_FP_DRVLIB_H
#define __INC_FP_DRVLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/* ͷ�ļ� */

/* �궨�� */
#define PARTITION_MAX_NUM           8       /* ���ݷ����������������������� */

#define PARTITION_TYPE_NOASSIGN     0       /* ��ʾΪδ����ķ��� */
#define PARTITION_TYPE_OS           1       /* ��ʾΪ����ϵͳ���ݷ������ݲ�֧�� */
#define PARTITION_TYPE_APP          2       /* ��ʾΪӦ�ó������ݷ������ݲ�֧�� */
#define PARTITION_TYPE_AUXDATA      3       /* ��ʾΪ����ϵͳӦ�ó��򸴺Ϸ��� */
#define PARTITION_TYPE_USRDATA      4       /* ��ʾΪ�û����ݷ��� */
#define PARTITION_TYPE_TFFS         5       /* ��ʾtffs�ļ�ϵͳ���� */

#define PARTITION_TYPE_MAXNUM       6       /* ��ʾ�������͵����� */

#define EXECODE_TYPE_NONE           0       /* �����ִ�г�����������ʹ�� */
#define EXECODE_TYPE_FPGA  0xfa002005       /* �����ִ�г������������fpga���� */

/* ÿ�����������ṹ���� */
typedef struct{
    UINT32 dwPartitionType;                 /* �������� */
    UINT32 dwPartitionSize;                 /* �÷�������,�ֽ�Ϊ��λ */
}TOnePartnParam;

/* ���������ṹ���� */
typedef struct{
    BOOL  bUseDefaultConf;                  /* �Ƿ�ʹ��Ĭ�ϵ����÷���,���ΪTRUE��ʹ��ÿ�����ӵ�Ĭ������������,�ڶ�������Ϣʱ����0����Ч���� */
    TOnePartnParam tOnePartitionParam[PARTITION_MAX_NUM];    /* ÿ��������Ϣ */
    UINT32 dwRamdiskSize;                   /* RAMDISK �Ĵ�С,�ֽ�Ϊ��λ */
}TFlPartnParam;


/* �������� */
BOOL   BrdRawFlashIsUsed(void);                    /* ��ѯ�Ƿ����rawflash���� */
UINT32 BrdGetFullRamDiskFileName(char *pInFileName, char *pRtnFileName);/* ת�����·�����ļ���Ϊramdisk�д�����·�����ļ��� */

STATUS BrdFpUnzipFile(char *pUnzipFileName, char *pOuputFileName);/* ��ѹָ�����ļ����������ָ�����ļ� */
BOOL   BrdFpUnzipFileIsExist(char *pUnzipFileName);/* ��ѯѹ������ָ����ѹ���ļ��Ƿ���� */

STATUS BrdFpPartition(TFlPartnParam *ptParam);     /* ���� */
STATUS BrdFpGetFPtnInfo(TFlPartnParam *ptParam);   /* ��������Ϣ */

INT32  BrdFpGetExecDataInfo(UINT32 *pdwExecAdrs, UINT32 *pdwExeCodeType);         /* ��ȡ�����ִ�г�������͡���ַ�ʹ�С */
INT32  BrdFpReadExecData(UINT8 *pbyDesBuf, UINT32 dwLen); /* ��ȡ�����ִ�г������� */
STATUS BrdFpWriteExecData(UINT32 dwExeCodeType, UINT8 *pbyData, UINT32 dwLen);  /* д�������ִ�г������� */
STATUS BrdFpEraseExeCode(void);    /* ����ExeCode�����ִ�г������� */

INT32  BrdFpGetAuxDataInfo(UINT32 *pdwDataOffset, char *pchOsName, char *pchAppName);
INT32  BrdFpReadAuxData(UINT8 *pbyDesBuf, UINT32 dwLen);/* ��ȡaux��ִ�г������� */
STATUS BrdFpWriteAuxData(UINT8 *pbyData, UINT32 dwLen, char *pchOsName, char *pchAppName);
STATUS BrdFpEraseAuxData(void);

UINT8  BrdFpGetUsrFpnNum (void);    /* ��ȡ�û����ݷ����ĸ��� */
STATUS BrdFpWriteDataToUsrFpn(UINT8 bySection, UINT8 *pbyData, UINT32 dwLen);/* дָ�����������ݵ��û����ݷ�����ָ���� */
INT32  BrdFpReadDataFromUsrFpn(UINT8 bySection, UINT8 *pbyDesBuf, UINT32 dwLen);/* ��ȡָ��������ָ����ָ�����ȵ���Ч���ݵ������� */

/* ����Ϊvx->linux��̬����ģ�鲿�ֵĽӿ� */
#define LINUX_PARTN_PTABLE      0  /* ������ */
#define LINUX_PARTN_IOS         1  /* ����ϵͳ���ݷ��� */
#define LINUX_PARTN_APP         2  /* Ӧ�ó������ݷ��� */
#define LINUX_PARTN_USRDATA     3  /* �û����ݷ��� */
#define LINUX_PARTN_LOGO        4  /* LOGO���ݷ��� */
#define LINUX_PARTN_JFFS2       5  /* ��ʾjffs2�ļ�ϵͳ���� */

STATUS  Vx2L_Init(void);
STATUS  Vx2L_ClearFlash(void);
STATUS  Vx2L_WrtFlashPartn(UINT8 byPartnID, char *pbySrcFile, char *pbyLinuxFile);
STATUS  Vx2L_UpdateBoot(char *pbyBootFile);

#ifdef __cplusplus
}
#endif

#endif /* __INC_FP_DRVLIB_H */