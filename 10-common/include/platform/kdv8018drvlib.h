/*****************************************************************************
ģ����      : mcu
�ļ���      : vasDrvLib.h
����ļ�    : drvMpcControl.c
�ļ�ʵ�ֹ���:  �ڲ�ʹ�õ�һЩ�궨��ͺ�������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/8/19   01a         �ŷ���      ����	
******************************************************************************/
#ifndef __INCKDV8018DrvLibh
#define __INCKDV8018DrvLibh


#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */


#include "time.h"
#include "timers.h"

/* �궨�� */
#define VER_KDV8018VxNIP  ( const char * )"KDV8018VxNIP 30.01.08.11.041016"

/* ��ָʾ�궨�� */
#define BRD_LED_ON       1  /* �� */
#define BRD_LED_OFF      2  /* �� */
#define BRD_LED_QUICK    3  /* ���� */
#define BRD_LED_SLOW     4  /* ���� */

/* �ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmE1RUA1;     /* E1ȫ1�澯 */
    BOOL bAlarmE1RLOS;     /* E1ʧͬ���澯 */
    BOOL bAlarmE1RRA;      /* E1Զ�˸澯 */
    BOOL bAlarmE1RCL;      /* E1ʧ�ز��澯 */
}TBrdE1AlarmDesc;

/* �ն�ǰ���ָʾ��״̬���ݽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedDSP;
    UINT8 byLedETH1;
    UINT8 byLedETH2;
    UINT8 byLedE1ALM;
    UINT8 byLedIR;
}TBrdSMTLedStateDesc;

STATUS BrdSMTQueryLedState(TBrdSMTLedStateDesc *ptBrdSMTLedState);   /* ����״̬��ȡ */


/* �ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1Alarm;     /* E1�澯 */
}TBrdSMTAlarmAll;

STATUS BrdSMTAlarmStateScan(TBrdSMTAlarmAll *ptBrdSMTAlarmAll);

/* �������� */
/*================================ʱ��ģ������====================================*/
/* ʱ��ṹ˵�� */
/*����ϵͳ��׼tm�ṹ���ɲο�tornado��ذ����ĵ�
int tm_sec;  seconds after the minute  - [0, 59] 
int tm_min;  minutes after the hour    - [0, 59] 
int tm_hour;  hours after midnight     - [0, 23] 
int tm_mday;  day of the month         - [1, 31] 
int tm_mon;  months since January      - [1-1, 12-1]    ע��: 0 = һ�£�������淶����
int tm_year;  years since 1900         - [1980-1900,2079-1900]  ע��:������淶����
int tm_wday;  days since Sunday        - [0, 6]   ��֧�֣�����0
int tm_yday;  days since January 1     - [0, 365] ��֧�֣�����0 
int tm_isdst;  Daylight Saving Time flag [ 0 ]    ��֧�֣�����0

/* ʱ�亯������ */

STATUS BrdTimeGet( struct tm* pGettm );             /* ��ȡRTCʱ�� */
STATUS BrdTimeSet( struct tm* pSettm );             /* ����RTC��ϵͳʱ�� */ 

STATUS BrdLedFlash(UINT8 byLedID, UINT8 byState);   /* ���ƿ��� */

/*==============================Ӳ����λ=============================*/  
void BrdHwReset(void);
STATUS sysRebootHookAdd(VOIDFUNCPTR rebootHook);    /* ��λע�ắ�� */

/*==============================nip�������ò���=============================*/
/* ��̫�������ṹ */
typedef struct{
    UINT32 dwIpAdrs;
    UINT32 dwIpMask;
    UINT8  byMacAdrs[6];
}TBrdEthParam;

/* BrdSetEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_IP_AND_MASK    0x01 /* ����IP��ַ���������� */
#define Brd_SET_MAC_ADDR       0x02 /* ����MAC��ַ */
#define Brd_SET_ETH_ALL_PARAM  0x03 /* ������̫����IP��ַ�����������MAC��ַ */

STATUS BrdSetEthParam(UINT8 byEthId, UINT8 byIpOrMac, TBrdEthParam *ptBrdEthParam); /* ������̫������ */
STATUS BrdGetEthParam(UINT8 byEthId, TBrdEthParam *ptBrdEthParam); /* ��ȡ��̫������ */
STATUS BrdDelEthParam(UINT8 byEthId);           /* ɾ��ָ������̫���ӿ� */

STATUS BrdSetDefGateway(UINT32 dwIpAdrs);       /* ����Ĭ������ip */
UINT32 BrdGetDefGateway(void);                  /* ��ȡĬ������ip */
STATUS BrdDelDefGateway(void);                  /* ɾ��Ĭ������ip */

UINT32 BrdGetNextHopIpAddr(UINT32 dwDstIpAddr); /* ��ȡͨ��ָ��ip�ĵ�һ��·��ip��ַ */



/* flash������Ϣ�ṹ���� */
#define DISK_MAX_NUMBER     8
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


/* vga info */
#define BSP15_VGA_NONE             0       /* vga����������ܾ�û�� */
#define BSP15_VGA_IN               1       /* ֻ��vga���빦�� */
#define BSP15_VGA_OUT              2       /* ֻ��vga������� */
#define BSP15_VGA_INOUT            3       /* vga����������ܶ��� */

UINT8  BrdGetBSP15VGAConf(UINT8 byDevId);        /* ��ȡָ��bsp15��vga���� */
void   BrdStopVGACap(void);                      /* ֹͣ�ɼ�vga(8083)����(����fpga) */
void   BrdStartVGACap(UINT8 byMode);             /* ��ʼ�ɼ�vga(8083)����(����fpga) */
void   BrdSetVGACapMode(UINT8 byMode);           /* ����fpga��VGA�ɼ���ģʽ(����fpga) */
void   BrdCloseVGA(void);                        /* �رղ���ֹvga(8083)�ɼ�оƬ���� */
void   BrdOpenVGA(void);                         /* �򿪲�����vga(8083)�ɼ�оƬ���� */



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif   /*INCDriverInith*/
