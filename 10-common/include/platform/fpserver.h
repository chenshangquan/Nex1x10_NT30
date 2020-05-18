/*****************************************************************************
   ģ����      : raw flash
   �ļ���      : fpServer.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: 
   ����        : �ŷ���
   �汾        : V1.0  Copyright(C) 2003-2004 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2005/4/23    1.0         �ŷ���        ����
******************************************************************************/

#ifndef __INC_FP_SERVER_H
#define __INC_FP_SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* ͷ�ļ� */

/* �궨�� */
#define FS_SERVER_PORT     2910
#define FS_SERVER_IP       0x01010101   /* "1.1.1.1" */

#define FS_EVENT_MAGIC_NUMBER       0x5cc5c555

#define FS_EVENT_UPDATE_AUXDATA     1
#define FS_EVENT_UPDATE_FPGA        2
#define FS_EVENT_REBOOT             0xf515f717

#define FS_ACT_OPT_MSG_VALID             0xaa5555a5
#define FS_ACT_OPT_MSG_INVALID           0xee5555e5

#define FS_ACT_OPT_FINISH_OK             0x0
#define FS_ACT_OPT_ERR_PARAM_INVALID     0x1
#define FS_ACT_OPT_ERR_NOT_FOUND_FILE    0x2
#define FS_ACT_OPT_ERR_FILE_LEN_ERR      0x3
#define FS_ACT_OPT_ERR_NO_MEMORY         0x4
#define FS_ACT_OPT_ERR_WRT_FAILE         0x5
#define FS_ACT_OPT_ERR_UNKNOWN           -1

#define FS_OPT_FILE_NAME_MAXLEN          32
#define FS_OS_FILE_NAME_MAXLEN           16
#define FS_APP_FILE_NAME_MAXLEN          16

#define FS_OSORAPP_FILE_NAME_USE_DEF     "default"

/* struct */

/* �ͻ��˵�����˵���Ϣ�ṹ */
typedef struct 
{
    int  iMagic;                                 /* ��������ʾ���ҵ���Ϣ,��FS_EVENT_MAGIC_NUMBER */
    int  iEvent;                                 /* �¼�����ʾ��ͬ�Ĳ������� */
    char acOptFileName[FS_OPT_FILE_NAME_MAXLEN]; /* �������ļ�������ȫ·�� */
    char acOsFileName[FS_OS_FILE_NAME_MAXLEN];   /* os����ϵͳ���ļ�����defaultʱʹ��Ĭ��ֵ */
    char acAppFileName[FS_APP_FILE_NAME_MAXLEN]; /* appӦ�ó�����ļ�����defaultʱʹ��Ĭ��ֵ */
}TBootMsgFromClient;

/* ����˵��ͻ��˵���Ϣ�ṹ */
typedef struct 
{
    int  iMagic;           /* ��������ʾ���ҵ���Ϣ */
    int  iEvent;           /* �¼�����ʾ��ͬ�Ĳ������� */
    int  iOptRtn;          /* ������� */
}TBootMsgToClient;

#ifdef __cplusplus
}
#endif

#endif /* __INC_FP_SERVER_H */