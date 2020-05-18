/*****************************************************************************
ģ����      : mcu
�ļ���      : mcuDrvLibh.h
����ļ�    : drvMpcControl.c
�ļ�ʵ�ֹ���:  mcuʹ�õ����к궨��Ͳ��ֹ�������������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/8/19   01a         �ŷ���      ����	
******************************************************************************/
#ifndef __INCmcuDrvLibh
#define __INCmcuDrvLibh


#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#ifdef IS_DSL8000_BRD_MPC
#include "DrvLibInc/mpc/drvMpcAlarm.h"
#include "DrvLibInc/mpc/drvMpcStateQuery.h"
#include "DrvLibInc/mpc/drvMpcControl.h"
#endif

#ifdef IS_DSL8000_BRD_CRI
#include "DrvLibInc/cri/drvCriAlarm.h"
#include "DrvLibInc/cri/drvCriStateQuery.h"
#include "DrvLibInc/cri/drvCriControl.h"
#endif

#ifdef IS_DSL8000_BRD_DTI
#include "E:/software/implement_h323/Driver/DrvDTI_860/DtiDrvLib/include/drvDtiAlarm.h"
#include "E:/software/implement_h323/Driver/DrvDTI_860/DtiDrvLib/include/drvDtiStateQuery.h"
#include "E:/software/implement_h323/Driver/DrvDTI_860/DtiDrvLib/include/drvDtiControl.h"
#include "E:/software/implement_h323/Driver/DrvDTI_860/DtiDrvLib/include/drvDtiInit.h"
#endif

#ifdef IS_DSL8000_BRD_DIC
#include "E:/software/implement_h323/Driver/DrvDIC_860/DicDrvLib/include/drvDicAlarm.h"
#include "E:/software/implement_h323/Driver/DrvDIC_860/DicDrvLib/include/drvDicStateQuery.h"
#include "E:/software/implement_h323/Driver/DrvDIC_860/DicDrvLib/include/drvDicControl.h"
#include "E:/software/implement_h323/Driver/DrvDIC_860/DicDrvLib/include/drvDicInit.h"
#endif

#ifdef IS_DSL8000_BRD_VAS
#include "DrvLibInc/vasDrvLib.h"
#endif

#ifdef IS_DSL8000_BRD_MMP
#include "DrvLibInc/mmpDrvLib.h"
#endif

#ifdef IS_DSL8000_BRD_DRI
#include "DrvLibInc/driDrvLib.h"
#endif

#ifdef IS_DSL8000_BRD_IMT
#include "DrvLibInc/imtDrvLib.h"
#endif

#ifdef IS_DSL8000_BRD_APU
#include "DrvLibInc/apuDrvLib.h"
#endif

#ifdef IS_DSL8000_BRD_DSI
#include "DrvLibInc/dsiDrvLib.h"
#endif

#ifdef IS_KDV8000B_BOARD
#include "DrvLibInc/kdv8000bDrvLib.h"
#endif


/* +++++++++++++++++++++++++++++ �궨�� +++++++++++++++++++++++++++++++++++++++*/
/* =========================== �����궨�� =====================================*/
/*  -> ��������ID�ź궨�� */  
#define  DSL8000_BRD_MPC      0            /* MPC�� */
#define  DSL8000_BRD_DTI      1            /* DTI�� */
#define  DSL8000_BRD_DIC      2            /* DIC�� */
#define  DSL8000_BRD_CRI      3            /* CRI�� */
#define  DSL8000_BRD_VAS      4            /* VAS�� */
#define  DSL8000_BRD_MMP      5            /* MMP�� */
#define  DSL8000_BRD_DRI      6            /* DRI�� */
#define  DSL8000_BRD_IMT      7            /* IMT�� */
#define  DSL8000_BRD_APU      8            /* APU�� */
#define  DSL8000_BRD_DSI      9            /* DSI�� */
#define  DSL8000_BRD_VPU      10           /* VPU�� */
#define  DSL8000_BRD_DEC5     11           /* DEC5�� */
#define  DSL8000_BRD_VRI      12           /* VRI�� */
#define  KDV8000B_BOARD       13           /* KDV8000B�� */
#define  DSL8000_BRD_MPU      66           /* MPU�� */  //��brdwrapperdef.h���ֵ����һ�� 
#define  DSL8000_BRD_EBAP     67           /* EBAP�� */
#define  DSL8000_BRD_EVPU     68           /* EVPU�� */
#define  DSL8000_BRD_HDU      70           /* HDU�� */

#define BRD_LED_ON                    1             /* �� */
#define BRD_LED_OFF                   2             /* �� */
#define BRD_LED_QUICK                 3             /* ���� */
#define BRD_LED_SLOW                  4             /* ���� */

#define E1_75_OHM   0              /* E1ģ���迹Ϊ75  ohm */
#define E1_120_OHM  1              /* E1ģ���迹Ϊ120 ohm */
#define E1_ERR_OHM  0xff           /* E1ģ���迹�޷�ʶ�� */

/* BrdSetEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_IP_AND_MASK    0x01 /* ����IP��ַ���������� */
#define Brd_SET_MAC_ADDR       0x02 /* ����MAC��ַ */
#define Brd_SET_ETH_ALL_PARAM  0x03 /* ������̫����IP��ַ�����������MAC��ַ */

/* �û����������������� */
#define UNCOMPRESS_FILE     0
#define COMPRESS_FILE       1

#define OS_CRI_FOR_MP       0
#define OS_CRI_FOR_GK       1

/* flash������Ϣ�ṹ���� */
#define DISK_MAX_NUMBER     8

/* ============================ MPC����صĺ궨�� ============================ */
/* -> ����ƺ궨�� */
#define BRD_MPC_ALARM_LED                 1          /* ϵͳ�澯�� */
#define BRD_MPC_SYN_LED                   2          /* ��ͬ��ָʾ�� */
#define BRD_MPC_OLAM_LED                  3          /* ��ģ��澯�� */

/* �ư�궨�� */
#define LED_BOARD_LED_NORM          0x01   /* �ư�������ָʾ�� */
#define LED_BOARD_LED_NALM          0x02   /* �ư���һ��澯ָʾ�� */
#define LED_BOARD_LED_SALM          0x04   /* �ư������ظ澯ָʾ�� */

#define LED_BOARD_LED_ON            0x01   /* �ư�ָʾ���� */
#define LED_BOARD_LED_OFF           0x00   /* �ư�ָʾ���� */

#define LED_BOARD_SPK_ON            0x01   /* ���������� */
#define LED_BOARD_SPK_OFF           0x00   /* �ر������� */

/* ���Ź��궨�� */
#define WATCHDOG_USE_CLK            0x00   /* ʱ��Ӳ��ι�� */
#define WATCHDOG_USE_SOFT           0x01   /* ���ι�� */
#define WATCHDOG_STOP               0x02   /* ֹͣι�� */

/* MPC ״̬��ѯ�궨�� */
#define BRD_MPC_IN_POSITION         0      /* �Զ������������λ  */
#define BRD_MPC_OUTOF_POSITION      1      /* �Զ���������岻��λ */

#define BRD_MPC_RUN_MASTER          0      /* ��ǰ������������� */
#define BRD_MPC_RUN_SLAVE           1      /* ��ǰ��������屸��  */

#define BRD_MPC_SDHMODULE_NONE      0x07   /* ��ǰ���������û�в�ģ�� */
#define BRD_MPC_SDHMODULE_SOI1      0x00   /* ��ǰ����������ģ��SOI1 */
#define BRD_MPC_SDHMODULE_SOI4      0x01   /* ��ǰ����������ģ��SOI4  */

#define SYNC_MODE_FREERUN           0      /* �����񵴣�������MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ�� */
#define SYNC_MODE_TRACK_SDH8K       1      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����8Kʱ�� */
#define SYNC_MODE_TRACK_SDH2M       2      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����2Mʱ�� */
#define SYNC_MODE_TRACK_DT2M        4      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT����2Mʱ�� */
#define SYNC_MODE_UNKNOWN           0xff   /* δ֪������ģʽ */

#define SYNC_CLOCK_UNLOCK                0          /* ����ģʽʱʱ��δ���� */
#define SYNC_CLOCK_LOCK                  1          /* ����ģʽʱʱ�������ɹ� */

/* ============================ CRI����صĺ궨�� ============================ */
#define BRD_CRI_MODULE_OFF          0
#define BRD_CRI_MODULE_ON           1

#define BRD_CRI_MLNK_LED                  0          /* CRI��mlink�Ƶı�� */

/* ============================ VAS����صĺ궨�� ============================ */
#define  VAS_MATRIX_16X16           0        /* 16X16�ľ���� */
#define  VAS_MATRIX_08X08           8        /*   8X8�ľ���� */

#define  VAS_MATRIX_OUTPUT_DISABLE  0xfb        /* ��ֹ����Ƶ����ĳ����˿� */
#define  VAS_MATRIX_OUTPUT_ENABLE   0xfc        /* ��������Ƶ����ĳ����˿� */

#define BRD_VAS_MLINK_LED                    2    /* VAS��mlink�Ƶı�� */

/* ============================ DRI����صĺ궨�� ============================ */
#define BRD_DRI_CLK_OUTPUT_DISABLE   0   /* �����ֹDRI����ʱ���ź������MPC���� */
#define BRD_DRI_CLK_OUTPUT_ENABLE    1   /* ����DRI����ʱ���ź������MPC���� */

#define BRD_DRI_RELAY_LOOP_DISABLE   0  /* �̵�����ͨ */
#define BRD_DRI_RELAY_LOOP_ENABLE    1  /* �̵����Ի� */

#define BRD_DRI_E1CHAIN_DISABLE      0  /* ����ĳ��E1��· */
#define BRD_DRI_E1CHAIN_ENABLE       1  /* ʹ��ĳ��E1��· */

#define BRD_DRI_E1_MAXNUM            8  /* DRI����8��E1��· */

#define BRD_DRI_MLINK_LED                    9   /* dri��mlink�Ƶı�� */

/* ============================ MMP����صĺ궨�� ============================ */
#define BRD_MMP_MLINK_LED                    7   /* MMP��mlink�Ƶı�� */

/*==============================IMT����صĺ궨��====================================*/
#define IMT_SYSALM_LED   1  /* ϵͳ�澯�ƣ��и澯ʱ�ɵ�õ� */
#define IMT_LINK_LED     5  /* ϵͳ���ӵƣ���MCU������ɵ�õ� */


/* ============================ DSI����صĺ궨�� ============================ */
#define BRD_DSI_CLK_OUTPUT_DISABLE   0   /* �����ֹDSI����ʱ���ź������MPC���� */
#define BRD_DSI_CLK_OUTPUT_ENABLE    1   /* ����DSI����ʱ���ź������MPC���� */

#define BRD_DSI_RELAY_SWITCH_IN      1  /* �̵��������������ָ��E1�л���8260 */
#define BRD_DSI_RELAY_SWITCH_OUT     0  /* �̵��������������ָ��E1�л���������Ӧ��E1��� */

#define BRD_DSI_E1_MAXNUM            4  /* DSI����4��E1��· */

#define BRD_DSI_MLINK_LED            9   /* dsi��mlink�Ƶı�� */


/* vga info */
#define BSP15_VGA_NONE             0       /* vga����������ܾ�û�� */
#define BSP15_VGA_IN               1       /* ֻ��vga���빦�� */
#define BSP15_VGA_OUT              2       /* ֻ��vga������� */
#define BSP15_VGA_INOUT            3       /* vga����������ܶ��� */


#ifndef WIN32 
/* (2) �������ݽṹ */
/*  a. ������ݽṹ���� */
typedef struct{
    UINT8 byBrdID;                      /* ����ID�� */
    UINT8 byBrdLayer;                   /* �������ڲ�� */
    UINT8 byBrdSlot;                    /* �������ڲ�λ�� */
}TBrdPosition;

/*  b. ��̫�������ṹ */
typedef struct{
    UINT32 dwIpAdrs;
    UINT32 dwIpMask;
    UINT8  byMacAdrs[6];
}TBrdEthParam;

/* ����Ϣ */
typedef struct{
    UINT32  dwDiskBaseAddr;       /* flash�̵Ļ���ַ */
    UINT32  dwDiskSize;           /* flash�̵���������ByteΪ��λ */
    char diskNameStr[32];         /* flash�̵����� */
}TBrdDiskInfoDesc;

typedef struct{
    UINT8  byDiskNum;           /* ʵ��flash�̵ĸ��� */
    TBrdDiskInfoDesc tBrdDiskInfo[DISK_MAX_NUMBER];
}TBrdAllDiskInfo;

STATUS BrdGetAllDiskInfo(TBrdAllDiskInfo *pBrdAllDiskInfo);
UINT32 BrdGetFullFileName(UINT8 byPutDiskId, char *pInFileName, char *pRtnFileName);
STATUS BrdRestoreFile(char *pSrcFile, char *pDesFile);/* ��ԭ�ļ� */
STATUS BrdBackupFile(char *pSrcFile, char *pDesFile); /* �����ļ� */


UINT8  BrdGetBSP15VGAConf(UINT8 byDevId);        /* ��ȡָ��bsp15��vga���� */
void   BrdStopVGACap(void);                      /* ֹͣ�ɼ�vga(8083)����(����fpga) */
void   BrdStartVGACap(UINT8 byMode);             /* ��ʼ�ɼ�vga(8083)����(����fpga) */
void   BrdSetVGACapMode(UINT8 byMode);           /* ����fpga��VGA�ɼ���ģʽ(����fpga) */
void   BrdCloseVGA(void);                        /* �رղ���ֹvga(8083)�ɼ�оƬ���� */
void   BrdOpenVGA(void);                         /* �򿪲�����vga(8083)�ɼ�оƬ���� */


/* (3) ������������ */
STATUS BrdQueryPosition(TBrdPosition *pTBrdPosition);   /* �����(ID����š���λ)��ѯ */
STATUS BrdLedFlash(UINT8 byLedID, UINT8 byState);       /* ����ƿ��� */
STATUS BrdLedStatusSet(UINT8 byLedID, UINT8 byState);   /* ����ƿ��� */
UINT8 BrdQueryHWVersion(void);                          /* Ӳ���汾�Ų�ѯ */
UINT8 BrdQueryFPGAVersion(void);                        /* FPGA�汾�Ų�ѯ */
STATUS BrdDrvLibInit(void);
STATUS sysRebootHookAdd(VOIDFUNCPTR rebootHook);    /* ��λע�ắ�� */
void BrdHwReset(void);                              /* ϵͳӲ����λ */
void SysRebootDisable(void);                        /* ��ֹϵͳ����excptionʱ�Զ���λ */
void SysRebootEnable(void);                         /* ����ϵͳ����excptionʱ�Զ���λ */

STATUS BrdSetEthParam(UINT8 byEthId, UINT8 byIpOrMac, TBrdEthParam *ptBrdEthParam); /* ������̫������ */
STATUS BrdGetEthParam(UINT8 byEthId, TBrdEthParam *ptBrdEthParam);                  /* ��ȡ��̫������ */
STATUS BrdDelEthParam(UINT8 byEthId);           /* ɾ��ָ������̫���ӿ� */

STATUS BrdSetDefGateway(UINT32 dwIpAdrs);       /* ����Ĭ������ip */
UINT32 BrdGetDefGateway(void);                  /* ��ȡĬ������ip */
STATUS BrdDelDefGateway(void);                  /* ɾ��Ĭ������ip */

UINT32 BrdGetNextHopIpAddr(UINT32 dwDstIpAddr); /* ��ȡͨ��ָ��ip�ĵ�һ��·��ip��ַ */

STATUS SysSetUsrAppParam(char *pFileName, UINT8 byFileType, char *pAutoRunFunc);/* �û����������������� */

UINT8 SysGetOsVer(void);        /* ��ȡOS�汾���ͣ���Ϊ������ͬһ����������в�ͬ��OS */
#endif  /* END #ifndef WIN32 */



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif   /*INCDriverInith*/
