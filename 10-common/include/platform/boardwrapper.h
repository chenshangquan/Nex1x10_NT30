/******************************************************************************
ģ����  �� BoardWrapper
�ļ���  �� BoardWrapper.h
����ļ���
�ļ�ʵ�ֹ��ܣ�BoardWrapperģ������ṩ����Ҫͷ�ļ�
����    ��������
�汾    ��1.0.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
10/24/2005  1.0         ������      ����
******************************************************************************/
#ifndef _BOARDWRAPPER_H
#define _BOARDWRAPPER_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#include "kdvtype.h"
#include "boardwrapperdef.h"
#include "boarddhcp.h"
#include "boardsntp.h"
#include <time.h>

/*��غ궨��*/

/*�������ӵİ汾�Ŷ���*/
#define VER_MTLinuxOsWrapperForKDV8010A  ( const s8 * )"BoardWrapperForKDV8010A 40.01.00.02.070413"
#define VER_LinuxOsWrapperForMDSC        ( const s8 * )"BoardWrapperForMDSC 40.01.00.01.070413"
#define VER_LinuxOsWrapperForHDSC        ( const s8 * )"BoardWrapperForHDSC 40.01.00.01.070413"   
#define VER_LinuxOsWrapperForKDV8010C    ( const s8 * )"BoardWrapperForKDV8010C 40.01.00.01.070413" 
#define VER_LinuxOsWrapperForKDV8010C1    ( const s8 * )"BoardWrapperForKDV8010C1 40.01.00.01.070413"     
#define VER_LinuxOsWrapperForCRI         ( const s8 * )"BoardWrapperForCRI 40.01.00.01.070413" 
#define VER_LinuxOsWrapperForMPC         ( const s8 * )"BoardWrapperForMPC 40.01.00.00.070413" 
#define VER_LinuxOsWrapperForDRI         ( const s8 * )"BoardWrapperForDRI 40.01.00.00.070413" 
#define VER_LinuxOsWrapperForAPU         ( const s8 * )"BoardWrapperForAPU 40.01.00.00.070413" 
#define VER_LinuxOsWrapperForKDM2000PLUS         ( const s8 * )"BoardWrapperForKDM2000PLUS 40.01.00.00.070413" 
#define VER_MTLinuxOsWrapperForKDV8000B  ( const s8 * )"BoardWrapperForKDV8000B 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForKDV8000BHD  ( const s8 * )"BoardWrapperForKDV8000BHD 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForKDV8000C  ( const s8 * )"BoardWrapperForKDV8000C 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForMMP       ( const s8 * )"BoardWrapperForMMP 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForDSC       ( const s8 * )"BoardWrapperForDSC 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForKDV8005   ( const s8 * )"BoardWrapperForKDV8005 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForDSI       ( const s8 * )"BoardWrapperForDSI 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForKDV8003   ( const s8 * )"BoardWrapperForKDV8003 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForVAS   ( const s8 * )"BoardWrapperForVAS 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperFor16E1   ( const s8 * )"BoardWrapperForDRI16 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForKDM2428   ( const s8 * )"BoardWrapperForKDM2428 40.01.00.00.070413"
#define VER_MTLinuxOsWrapperForVRI   ( const s8 * )"BoardWrapperForVRI 40.01.00.00.070413"


/*��ؽṹ�嶨��*/

/*SysSetUsrAppParam()�����õ��Ľṹ��*/

/* Ӧ��������Ϣ�ṹ��*/
typedef struct{
    u8 abyAppName[APP_NAME_MAX_LEN+1];  /* Ӧ�ó����ļ��� */
    u8 byAppType;                       /* Ӧ�ó�������,��:LOCAL_UNCOMPRESS_FILE�� */
}TAppInf;

typedef struct{
    u32 dwAppNum; /* Ӧ�ó���ĸ��� */
    TAppInf tAppInf[APP_MAX_NUM];
}TAppLoadInf;


/*������ݽṹ����*/
/* ������ݽṹ���� */
typedef struct{
    u8 byBrdID;                      /* ����ID�� */
    u8 byBrdLayer;                   /* �������ڲ�� */
    u8 byBrdSlot;                    /* �������ڲ�λ�� */
}TBrdPosition;

/*��̫����صĽṹ����*/
/* ��̫�������ṹ */
typedef struct{
    u32 dwIpAdrs;/*�����ֽ���*/
    u32 dwIpMask; /*�����ֽ���*/
    u8  byMacAdrs[6];
}TBrdEthParam;

/* ��̫�������ṹ */
typedef struct{
    u32 dwIpNum;/*��Ч��IP��ַ��*/
    TBrdEthParam atBrdEthParam[IP_ADDR_MAX_NUM];/*���IP��ַ����Ϣ������*/
}TBrdEthParamAll;

/* ����·�ɲ����ṹ */
typedef struct{
    u32 dwDesIpNet;      /* Ŀ�������������ֽ���	*/
    u32 dwDesIpMask;     /* ���룬�����ֽ���	*/
    u32 dwGwIpAdrs;      /* ����ip��ַ�������ֽ���*/
    u32 dwRoutePri;		/* ·�����ȼ�(1-255)��Ĭ��Ϊ0*/
}TBrdIpRouteParam;

/*���·�ɲ����ṹ */
typedef struct{
    u32 dwIpRouteNum;    /* �õ���ʵ��·�ɸ��� */
    TBrdIpRouteParam tBrdIpRouteParam[IP_ROUTE_MAX_NUM];
}TBrdAllIpRouteInfo;

/* ��̫��ƽ������æ״̬��Ϣ */
typedef struct{
    u8 byEthId;
    BOOL32  bSndBusy;
}TBrdEthSndBusyParam;

/*��̫��ƽ������æ�ص��������Ͷ���*/
typedef void ( *TEthSndBusyCallBack )(u32 dwUsrArg, TBrdEthSndBusyParam *ptParam);

/*ע���豸�����ص������Ļص���������---VxWorks�ϸú���������ϵͳ����ģ���Linux��Ϊ�˼���VxWorks���صض���ú�������*/
#ifdef _LINUX_
typedef void 		(*VOIDFUNCPTR) (void);	/* pfunction returning void */
#endif

/*IP��ַ��ͻ�ص��������Ͷ���*/
typedef void (*TIpConflictCallBack)(u8 *pbyMacAddr, u32 dwIpAdrs);

/*Ping�ص��������Ͷ���*/
/*����˵����
    nResult��ping���:0--�ɹ���1 ---��ʱ��2--����
    nTtl��ping�յ�ICMP�ذ���ttl����ttlֵ���Է�Ӧ����ping������������
    nTripTime��ping�յ�ICMP�ذ�������ʱ�䣬��λΪ΢�us��
    nUserID��ping��Я�����û����ݣ����������ֲ�ͬ���û�
    nErrType���յ�ICMP�ذ������ͣ��������ͽ϶࣬��ʱû�ж����������Ҫʱ���Բ��Ҷ���
    nErrCode���յ�ICMP�ذ��Ĵ��룬�������ͽ϶࣬��ʱû�ж����������Ҫʱ���Բ��Ҷ���
*/
typedef s32 (*TPingCallBack)(s32 nResult,s32 nTtl,s32 nTripTime,s32 nUserID,s32 nErrType,s32 nErrCode);


/*E1��صĽṹ����*/
/* E1��·����serial�ӿڲ����ṹ */
typedef struct{
    u32 dwUsedFlag;                  /* ��ǰserialͬ���ӿ�ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    u32 dwSerialId;                  /* serialͬ���ӿڱ�ţ�e1��·��16��ʼ����Ч��Χ16~62,���ɳ�ͻ */
    u32 dwE1Id;                      /* ��serialͬ���ӿڶ�Ӧ��e1��ţ������÷�Χ0~E1_MAXNUM-1, E1_MAXNUMȡ������ӦӲ��֧�ֵ�e1����,��kdv8010�ն� #define BRD_MT_E1_MAXNUM 4 */
    u32 dwE1TSMask;                  /* E1ʱ϶����˵��,����� */
    u32 dwE1ChanGroupId;             /* E1ʱ϶�������ڵı���ţ������÷�Χ0~7,��������һ��E1ʹ�õĻ���0�������ֵĻ������ÿ��ʱ϶�ν������α�� */
    u32 dwProtocolType;		/* �ӿ�Э���װ����,����ǵ�E1���ӿ���ָ��PPP/HDLC������Ƕ�E1�������ӱ�����PPPЭ�� */
    u32 dwEchoInterval;		/* ��Ӧserialͬ���ӿڵ�echo����ʱ��������Ϊ��λ����Ч��Χ0-256����Ĭ��ֵ2���� */
    u32 dwEchoMaxRetry;		/* ��Ӧserialͬ���ӿڵ�echo����ط���������Ч��Χ0-256����Ĭ��ֵ2���� */
}TBrdE1SerialInfo;
/******************************************************************************
* dwE1TSMaskʱ϶���䲹��˵����
*    ʱ����������룬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
* Ts0��Ϊͬ���źţ��û�����ʹ��, 0x0��0x1���ǷǷ��Ĳ�������Ч��Χ��0x2~0xfffffffe��
* ��: ʹ��TS1~TS5 5��ʱ϶ʱdwE1TSMask = 0x0000003e,ע��:Ts0=0; ��ʱ����= 64x5 = 320kbit
      ʹ��TS1~TS3,TS30~31 5��ʱ϶ʱdwE1TSMask = 0xc000000e,ע��:Ts0=0; ��ʱ����= 64x5 = 320kbit
******************************************************************************/

/* ��E1��·����ͨ�������ṹ */
typedef struct{
    u32 dwUsedFlag;                  /* ��ǰE1����·����ͨ��ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    u32 dwIpAdrs;                    /* ip��ַ�������� */
    u32 dwIpMask;                    /* ���룬������ */
    TBrdE1SerialInfo tE1SerialInfo;     /* ��Ӧserialͬ���ӿ���·���� */
}TBrdE1SingleLinkChanInfo;

/* ��E1��·��������ͨ�������ṹ */
typedef struct{
    u32 dwUsedFlag;                      /* ��ǰE1����·��������ͨ��ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    u32 dwIpAdrs;                        /* ip��ַ�������� */
    u32 dwIpMask;                        /* ���룬������ */
    u32 dwAuthenticationType;            /* PPP���ӵ���֤����PAP/CHAP,Ĭ����MP_AUTHENTICATION_PAP */
    u32 dwFragMinPackageLen;             /* ��С��Ƭ�������ֽ�Ϊ��λ����Χ20~1500��Ĭ����20 */
    s8  chSvrUsrName[MP_STRING_MAX_LEN]; /* ������û����ƣ�������֤�Զ˵����� */
    s8  chSvrUsrPwd[MP_STRING_MAX_LEN];  /* ������û����룬������֤�Զ˵����� */
    s8  chSentUsrName[MP_STRING_MAX_LEN];/* �ͻ����û����ƣ��������Զ���֤ */
    s8  chSentUsrPwd[MP_STRING_MAX_LEN]; /* �ͻ����û����룬�������Զ���֤ */
    TBrdE1SerialInfo tE1SerialInfo[E1_SINGLE_LINK_CHAN_MAX_NUM];/* ÿ���������serialͬ���ӿ���·���� */
}TBrdE1MultiLinkChanInfo;

/* ����һ��ͨ����Ҫ����Ĳ����ṹ���� */
typedef struct{
    u32  dwBufNum;           /* ��Ϣ������buf������ */
    u16  wBufLength;         /* ��Ϣ������ÿ��buf�ĳ���,��Χ������ĺ궨�壬�ұ�����8�������� */
    u32  dwTimeSlotMask;     /* �������ʱ������ʹ��˵��*/
} TE1TransChanParam;

/********************************************************************************* 
* dwTimeSlotMask ʱ������ʹ��˵����
*    ʱ����������룬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
* Ts0��Ϊͬ���źţ��û�����ʹ�ã�Ts16����Ϊ���ݻ�����ڱ�ģ���и�ʱ϶���û�����ͨ������
* ʱ϶����ѡ���Ƿ�ʹ�ã�ʱ϶���佨��ӵ͵�����������ʱ϶����Ҫ��������������������ͨ��ϵ
* ͳ���ȶ���
* ��: ʹ��5��ʱ϶ʱdwTimeSlotMask = 0x0000003e,��ʱ����= 64x5 = 320kbit�� ע��:Ts0=0; 
**********************************************************************************/


/* �û�����ķ������ݲ����ṹ���� */
typedef struct{
    u8* pbyMsg;                  /* �û���Ϣָ�� */
    u32 dwMsgLen;                /* �û���Ϣ���� */
} TE1TransMsgParam;

/* ͨ�������շ�ͳ�ƽṹ���� */
typedef struct{
    u32 dwRxOnePacketLen;        /* ���յ��ĵ������ĳ��� */
    u32 dwRxPackets;             /* ��E1��·���յ��İ��� */
    u32 dwRxErrPackets;          /* �յ�����İ��� */
    u32 dwRxDropPackets;         /* �����ϲ��û������ж����İ��� */
    u32 dwRxSucSndPackets;       /* �ɹ������ϲ��û��İ��� */
    u32 dwTxSndPackets;          /* �ϲ�Ҫ���͵İ��� */
    u32 dwTxSucSndPackets;       /* �ϲ�ɹ����͵��İ��� */
    u32 dwTxSucSndPacketLen;     /* �ϲ�ɹ����͵����ܰ������ֽ�Ϊ��λ */
}TE1TransChanStat;

/* �ص��������Ͷ��� */
typedef void ( * TE1MsgCallBack )(u8 byE1ChanID, u32 dwState);

/*Flash��صĽṹ����*/
/* flash������Ϣ�ṹ���� */
typedef struct{
    u32  dwDiskSize;        /* flash�̵���������ByteΪ��λ */
    s8   achDiskNameStr[32];         /* flash�̵����� */
}TBrdDiskInfoDesc;

typedef struct{
    u8  byDiskNum;           /* ʵ��flash�̵ĸ��� */
    TBrdDiskInfoDesc atBrdDiskInfo[DISK_MAX_NUMBER];
}TBrdAllDiskInfo;

/*�ײ�澯��صĽṹ����*/
/* �ײ�V35�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bAlarmV35CDDown;     /* Carrier Detect, �ز����ʧ�� */
    BOOL32 bAlarmV35CTSDown;    /* Clear To Send, �������ʧ�� */
    BOOL32 bAlarmV35RTSDown;    /* Request To Send, ������ʧ�� */
    BOOL32 bAlarmV35DTRDown;    /* �����ն�δ���� */
    BOOL32 bAlarmV35DSRDown;    /* ����δ׼���� */
}TBrdV35AlarmDesc;

/* �ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bAlarmE1RUA1;     /* E1ȫ1�澯 */
    BOOL32 bAlarmE1RLOS;     /* E1ʧͬ���澯 */
    BOOL32 bAlarmE1RRA;      /* E1Զ�˸澯 */
    BOOL32 bAlarmE1RCL;      /* E1ʧ�ز��澯 */
    BOOL32 bAlarmE1RCMF;     /* E1��CRC��֡����澯 */
    BOOL32 bAlarmE1RMF;      /* E1��·��֡����澯 */
}TBrdE1AlarmDesc;

/* �����Դ�澯���ݽṹ */
typedef struct{
    BOOL32 bAlarmPowerDC48VLDown;     /* ���Դ-48V�쳣 */
    BOOL32 bAlarmPowerDC48VRDown;     /* �ҵ�Դ-48V�쳣 */
    BOOL32 bAlarmPowerDC5VLDown;      /* ���Դ+5V�쳣 */
    BOOL32 bAlarmPowerDC5VRDown;      /* �ҵ�Դ+5V�쳣 */
}TBrdMPCAlarmPowerDesc;

/* �����Դ���ȸ澯���ݽṹ */
typedef struct{
    BOOL32 bAlarmPowerFanLLDown;      /* ���Դ�����ͣת */
    BOOL32 bAlarmPowerFanLRDown;      /* ���Դ�ҷ���ͣת */
    BOOL32 bAlarmPowerFanRLDown;      /* �ҵ�Դ�����ͣת */
    BOOL32 bAlarmPowerFanRRDown;      /* �ҵ�Դ�ҷ���ͣת */
}TBrdMPCAlarmPowerFanDesc;

/* MPC����澯���ݽṹ���� */
typedef struct{
    BOOL32 bAlarmNetClkLockFailed;     /*  ���໷û����ס�ο�ʱ�� */
    TBrdMPCAlarmPowerDesc tBrdMPCAlarmPower; /* ��Դ�澯 */
    TBrdMPCAlarmPowerFanDesc tBrdMPCAlarmPowerFan; /* ��Դ���ȸ澯 */
}TBrdMPCAlarmVeneer;

/* SDH�澯�ṹ���� */
typedef struct{
    BOOL32 bAlarmLOS;         /* �źŶ�ʧ */
    BOOL32 bAlarmLOF;         /* ֡��ʧ */
    BOOL32 bAlarmOOF;         /* ֡ʧ�� */
    BOOL32 bAlarmLOM;         /* ��֡��ʧ */
    BOOL32 bAlarmAU_LOP;      /* ����Ԫָ�붪ʧ */
    BOOL32 bAlarmMS_RDI;      /* ���ö�Զ��ȱ��ָʾ */
    BOOL32 bAlarmMS_AIS;      /* ���öα���ָʾ */
    BOOL32 bAlarmHP_RDI;      /* �߽�ͨ��Զ��ȱ��ָʾ */
    BOOL32 bAlarmHP_AIS;      /* �߽�ͨ������ָʾ */
    BOOL32 bAlarmRS_TIM;      /* ������ͨ���ټ��ֽڲ�ƥ�� */
    BOOL32 bAlarmHP_TIM;      /* ��ͨ���ټ��ֽڲ�ƥ�� */
    BOOL32 bAlarmHP_UNEQ;     /* �߽�ͨ���źű���ֽ�δװ�� */
    BOOL32 bAlarmHP_PLSM;     /* �߽�ͨ���źű���ֽڲ�ƥ�� */

    BOOL32 bAlarmTU_LOP;      /* ֧·��Ԫָ�붪ʧ */
    BOOL32 bAlarmLP_RDI;      /* �ͽ�ͨ��Զ��ȱ��ָʾ */
    BOOL32 bAlarmLP_AIS;      /* �ͽ�ͨ������ָʾ */
    BOOL32 bAlarmLP_TIM;      /* �ͽ�ͨ���ټ��ֽڲ�ƥ�� */
    BOOL32 bAlarmLP_PLSM;     /* �ͽ�ͨ���źű���ֽڲ�ƥ�� */
}TBrdMPCAlarmSDH;

/* MPC�澯���ݽṹ���� */
typedef struct{
    TBrdMPCAlarmVeneer tBrdMPCAlarmVeneer;
    TBrdMPCAlarmSDH    tBrdMPCAlarmSDH;
}TBrdMPCAlarmAll;

typedef struct{
    BOOL32 bAlarmModuleOffLine;     /* ģ������ */
}TBrdCRIAlarmAll;

/* DRI�ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1AlarmDesc[8]; 
}TBrdDRIAlarmAll;

/* DRI16�ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1AlarmDesc[16]; 
}TBrdDRI16AlarmAll;

/* DSI�ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1AlarmDesc[4];
}TBrdDSIAlarmAll;

/* IMT�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bAlarmDSP1FanStop;     /* ͼ��������ͣת */
    BOOL32 bAlarmDSP2FanStop;     /* ͼ��������ͣת */
    BOOL32 bAlarmDSP3FanStop;     /* ��Ƶ��������ͣת */
}TBrdIMTAlarmAll;

/* KDV8010A�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bAlarmEth1LnkDown;     /* ��̫��1������ */
    BOOL32 bAlarmDSP1FanStop;     /* ͼ��������ͣת */
    BOOL32 bAlarmDSP2FanStop;     /* ͼ��������ͣת */
    BOOL32 bAlarmDSP3FanStop;     /* ��Ƶ��������ͣת */
    BOOL32 bAlarmSYS1FanStop;     /* �������1ͣת */
    BOOL32 bAlarmSYS2FanStop;     /* �������2ͣת */
    TBrdE1AlarmDesc tBrdE1AlarmDesc[4];     /* E1�澯 */
    TBrdV35AlarmDesc tBrdV35AlarmDesc;    /* V.35�澯 */
}TBrdMTAlarmAll;

/* KDV8018�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1Alarm;     /* E1�澯 */
}TBrdSMTAlarmAll;

/* KDM2400 2500�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1Alarm;     /* E1�澯 */
}TBrdKDM2000AlarmAll;


/* �澯״̬�����ṹ */
typedef struct {
    u32 dwAlmNum;             /* ʵ�ʸ澯��Ԫ���� */
    union {
        BOOL32 bAlmNo[BRD_ALM_NUM_MAX];
        TBrdMPCAlarmAll tBrdMPCAlarmAll;
        TBrdCRIAlarmAll tBrdCRIAlarmAll;
        TBrdDRIAlarmAll tBrdDRIAlarmAll;
        TBrdDRI16AlarmAll tBrdDRI16AlarmAll;
        TBrdDSIAlarmAll tBrdDSIAlarmAll;
        TBrdIMTAlarmAll tBrdIMTAlarmAll;
        TBrdMTAlarmAll  tBrdMTAlarmAll;
        TBrdSMTAlarmAll tBrdSMTAlarmAll;
        TBrdKDM2000AlarmAll tBrdKDM2000AlarmAll;
    } nlunion;
} TBrdAlarmState;

/*ָʾ�ƿ�����صĽṹ����*/
/* MPC��ָʾ�ƽṹ */
typedef struct{
    u8 byLedRUN;     /* ϵͳ���е� */
    u8 byLedDSP;     /* DSP���е� */
    u8 byLedALM;     /* ϵͳ�澯�� */
    u8 byLedMS;      /* ������ָʾ�� */
    u8 byLedOUS;     /* ousָʾ�� */
    u8 byLedSYN;     /* ͬ��ָʾ�� */
    u8 byLedLNK0;    /* ��̫��0���ӵ� */
    u8 byLedLNK1;    /* ��̫��1���ӵ� */
    u8 byLedNMS;     /* nmsָʾ�� */
    u8 byLedNORM;    /* �ư�������ָʾ�� */
    u8 byLedNALM;    /* �ư���һ��澯ָʾ�� */
    u8 byLedSALM ;   /* �ư������ظ澯ָʾ�� */
}TBrdMPCLedStateDesc;

/* CRIָʾ�ƽṹ */
typedef struct{
    u8 byLedRUN;      /* ϵͳ���е� */
    u8 byLedMRUN;     /* VOIP/DDNģ�����е� */
    u8 byLedSPD0;     /* ����0����ָʾ�� */
    u8 byLedLNK0;     /* ����0����ָʾ�� */
    u8 byLedACT0;     /* ����0�����շ���Чָʾ�� */
    u8 byLedSPD1;     /* ����1����ָʾ�� */
    u8 byLedLNK1;     /* ��̫��1���ӵ� */
    u8 byLedACT1;     /* ����1�����շ���Чָʾ�� */
    u8 byLedWERR;     /* ���������ݴ��� */
    u8 byLedMLNK;     /* ��MPC����ָʾ�� */
}TBrdCRILedStateDesc;

/* DRIָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedE1_ALM0;
    u8 byLedE1_ALM1;
    u8 byLedE1_ALM2;
    u8 byLedE1_ALM3;
    u8 byLedE1_ALM4;
    u8 byLedE1_ALM5;
    u8 byLedE1_ALM6;
    u8 byLedE1_ALM7;
    u8 byLedMLINK;
    u8 byLedLNK0;
    u8 byLedLNK1;
}TBrdDRILedStateDesc;

/* DRI16ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedE1_ALM0;
    u8 byLedE1_ALM1;
    u8 byLedE1_ALM2;
    u8 byLedE1_ALM3;
    u8 byLedE1_ALM4;
    u8 byLedE1_ALM5;
    u8 byLedE1_ALM6;
    u8 byLedE1_ALM7;
    u8 byLedE1_ALM8;
    u8 byLedE1_ALM9;
    u8 byLedE1_ALM10;
    u8 byLedE1_ALM11;
    u8 byLedE1_ALM12;
    u8 byLedE1_ALM13;
    u8 byLedE1_ALM14;
    u8 byLedE1_ALM15;
    u8 byLedMLINK;
    u8 byLedLNK0;
    u8 byLedLNK1;
}TBrdDRI16LedStateDesc;

/* DSIָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedE1_ALM0;
    u8 byLedE1_ALM1;
    u8 byLedE1_ALM2;
    u8 byLedE1_ALM3;
    u8 byLedE1_ALM4;
    u8 byLedE1_ALM5;
    u8 byLedE1_ALM6;
    u8 byLedE1_ALM7;
    u8 byLedMLINK;
    u8 byLedLNK0;
    u8 byLedLNK1;
}TBrdDSILedStateDesc;

/* IMTָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedDSP1;
    u8 byLedDSP2;
    u8 byLedDSP3;
    u8 byLedSYSALM;
    u8 byLedMLINK;
    u8 byLedLNK0;
    u8 byLedLNK1;
}TBrdIMTLedStateDesc;

/* KDV8000Bģ��DSCָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedLNK0;
    u8 byLedLNK1;
    u8 byLedALM;
}TBrdDSCLedStateDesc;

/* MMPָʾ�ƽṹ */
typedef struct{
    u8 byLedRUN; 
    u8 byLedDSPRUN1;
    u8 byLedDSPRUN2;
    u8 byLedDSPRUN3;
    u8 byLedDSPRUN4;
    u8 byLedDSPRUN5;
    u8 byLedALM;
    u8 byLedLNK;
    u8 byLedETH0;
    u8 byLedETH1;
}TBrdMMPLedStateDesc;

/* VASָʾ�ƽṹ */
typedef struct{
    u8 byLedRUN; 
    u8 byLedALM;
    u8 byLedMLNK;
    u8 byLedETHLNK;
}TBrdVASLedStateDesc;

/* �ն�KDV8010A�Լ�KDV8000Bǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedPower;
    u8 byLedALM;
    u8 byLedRun; 
    u8 byLedLINK;
    u8 byLedDSP1;
    u8 byLedDSP2;
    u8 byLedDSP3;
    u8 byLedETH1;
    u8 byLedETH2;
    u8 byLedETH3;
    u8 byLedIR;
}TBrdKDV8010LedStateDesc,TBrdMTLedStateDesc;

/* �ն�KDV8010Cǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedPower;
    u8 byLedALM;
    u8 byLedRun; 
    u8 byLedLINK;
    u8 byLedDSP1;
    u8 byLedDSP2;
    u8 byLedETH1;
    u8 byLedIR;
}TBrdKDV8010CLedStateDesc;

/* �ն�KDV8010C1ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedPower;
    u8 byLedALM;
    u8 byLedRun; 
    u8 byLedLINK;
    u8 byLedDSP1;
    u8 byLedDSP2;
    u8 byLedETH1;
    u8 byLedIR;
}TBrdKDV8010C1LedStateDesc;

/* KDV8005ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedLINK;
    u8 byLedETH0;
    u8 byLedETH1;
    u8 byLedV35;
}TBrdKDV8005LedStateDesc;

/* KDV8003ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedLINK;
    u8 byLedETH0;
    u8 byLedE1Alm;
}TBrdKDV8003LedStateDesc;

/* KDM2417ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedPower;
    u8 byLedALM;
    u8 byLedRun; 
    u8 byLedCDMA;
    u8 byLedWLAN;
    u8 byLedETH;
    u8 byLedDISK;
}TBrdKDM2417LedStateDesc;

/* KDV8008ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedALM;
    u8 byLedRun;
    u8 byLedETH;
}TBrdKDV8008LedStateDesc;

/* KDM2000PLUSǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedALM; 
    u8 byLedLINK;
    u8 byLedDSP;
    u8 byLedE1Alm;
    u8 byLedETH1;
    u8 byLedSPD1;
    u8 byLedETH2;
}TBrdKDM2000LedStateDesc;

/* KDM2428ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedPower;
    u8 byLedALM;
    u8 byLedRun; 
    u8 byLedLNK;
    u8 byLedETH;
    u8 byLedDISK;
}TBrdKDM2428LedStateDesc;

/* MDSCǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedALM; 
    u8 byLedETH1;
    u8 byLedETH2;
}TBrdMDSLedStateDesc;

/* HDSCǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun; 
    u8 byLedLos; 
    u8 byLedETH1;
    u8 byLedETH2;
}TBrdHDSLedStateDesc;

/* �ն�VRIǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRUN;     /* ϵͳ���е� */
    u8 byLedV35ALM0;  /* E10�澯ָʾ�� */
    u8 byLedV35ALM1;  /* E11�澯ָʾ�� */
    u8 byLedV35ALM2;  /* E12�澯ָʾ�� */
    u8 byLedV35ALM3;  /* E13�澯ָʾ�� */
    u8 byLedV35ALM4;  /* E14�澯ָʾ�� */
    u8 byLedV35ALM5;  /* E15�澯ָʾ�� */
    u8 byLedMLINK;   /* ϵͳ����ָʾ�� */
    u8 byLedLNK0;    /* Eth0������ָʾ�� */
}TVRILedStateDesc;


/* ָʾ��״̬�����ṹ */
typedef struct {
    u32 dwLedNum;                /* ʵ��ָʾ�Ƶĸ��� */
    union {
        u8 byLedNo[BRD_LED_NUM_MAX];
        TBrdMPCLedStateDesc tBrdMPCLedState;
        TBrdCRILedStateDesc tBrdCRILedState;
        TBrdDRILedStateDesc tBrdDRILedState;
        TBrdDRI16LedStateDesc tBrdDRI16LedState;
        TBrdDSILedStateDesc tBrdDSILedState;
        TBrdIMTLedStateDesc tBrdIMTLedState;
        TBrdDSCLedStateDesc tBrdDSCLedStateDesc;
        TBrdMMPLedStateDesc tBrdMMPLedState;
        TBrdVASLedStateDesc tBrdVASLedState;
        TBrdMTLedStateDesc  tBrdMTLedState;
        TBrdKDV8010CLedStateDesc tBrdKDV8010CLedState;
        TBrdKDV8010C1LedStateDesc tBrdKDV8010C1LedState;
        TBrdKDV8010LedStateDesc tBrdKDV8010LedStateDesc;
        TBrdKDV8005LedStateDesc tBrdKDV8005LedState;
        TBrdKDV8003LedStateDesc tBrdKDV8003LedState;
        TBrdKDM2417LedStateDesc tBrdKDM2417LedState;
        TBrdKDV8008LedStateDesc tBrdKDV8008LedState;
        TBrdKDM2000LedStateDesc tBrdKDM2000LedState;
        TBrdKDM2428LedStateDesc tBrdKDM2428LedStateDesc;
        TBrdMDSLedStateDesc     tBrdMDSLedStateDesc;
        TBrdHDSLedStateDesc     tBrdHDSLedStateDesc;
        TVRILedStateDesc        tVRILedStateDesc;
    } nlunion;
} TBrdLedState;

/*���ڿ�����صĽṹ����*/
/* 485��ѯ��������Ĳ����ṹ */
typedef struct {
    u32 dwDevType;           /* 485�豸���� */
    u32 dwRcvTimeOut;        /* �ȴ�485�豸��Ӧ�ĳ�ʱ,0ȡĬ��ֵ */
    u8  byDesAddr;           /* 485�豸Ŀ���ַ */
    u8  byCmd;               /* �������� */
} TRS485InParam;


/* IRAY����ֵ�ṹ */
typedef struct{
    u8 byCtrllerType;    /* ң�������� */
    u8 byKeyCode;        /* ���� */
}TIRAYRtnDataDesc;

typedef struct {
    BOOL32 bDevLnked;         /* 485�豸����״̬ */
    union {
        TIRAYRtnDataDesc tIRAYRtnData;
    } nlunion;
} TRS485RtnData;

/*BrdPing�ӿڴ�������ṹ��*/
typedef struct{
    s32 nPktSize;/*Ҫping�����ݱ��Ĵ�С�����ֽ�Ϊ��λ*/
    s32 nTimeOut;/*ping�ĳ�ʱֵ������Ϊ��λ*/
    s32 nTtl;/*TTLֵ*/
}TPingOpt;

/*BrdGetDeviceInfo �ӿڴ�������ṹ��*/
typedef struct{
    s8  achCPUInfo[CPU_TYPE_MAX_LEN];/*CPU����*/
    s8  achUBootInfo[UBOOT_VERSION_MAX_LEN];/*u-boot�汾��Ϣ*/
    s8  achKernelInfo[KERNEL_VERSION_MAX_LEN];/*�ں˲���ϵͳ�İ汾��Ϣ*/
    u32 dwMemSize;/*�����ڴ��С�����ֽ�Ϊ��λ*/
    u32 dwFlashSize;/*FLash��С�����ֽ�Ϊ��λ*/
    u32 dwCpuFreq;/*CPU����Ƶ*/
    u32 dwCpmFreq;/*CPM����Ƶ*/
    u32 dwBusFreq;/*���ߵ���Ƶ*/
    u32 dwEthNum;/*��̫���ĸ���*/
    u32 dwE1Num;/*�豸��ǰ���E1�ĸ���*/
    u32 dwV35Num;/*�豸��ǰ���V35�ĸ���*/    
}TBrdDeviceInfo;

/*BrdAddUser�ӿڴ�����û�����*/
typedef enum UserType
{
  USER_TYPE_CONSOLE = 0,     /*Console�û�*/
  USER_TYPE_CONSOLE_SUPER,     /*Console�߼��û�*/
  USER_TYPE_FTP,         /*FTP �û�*/
  USER_TYPE_TELNET,      /*TELNET�û�*/
  USER_TYPE_TELNET_SUPER,      /*TELNET �߼��û�*/
  USER_TYPE_PPP,         /*PPP��·�û�*/
  USER_TYPE_HTTP,	  /*HTTP�û�*/
  USER_TYPE_MAX,         /*�û����͵����ֵ*/
}TUserType;

/*RawFlash��صĽṹ�嶨��*/

/* ÿ�����������ṹ���� */
typedef struct{
    u32 dwPartitionType;                 /* �������� */
    u32 dwPartitionSize;                 /* �÷�������,�ֽ�Ϊ��λ */
}TOnePartnParam;

/* ���������ṹ���� */
typedef struct{
    BOOL32  bUseDefaultConf;                  /* �Ƿ�ʹ��Ĭ�ϵ����÷���,���ΪTRUE��ʹ��ÿ�����ӵ�Ĭ������������,�ڶ�������Ϣʱ����0����Ч���� */
    TOnePartnParam tOnePartitionParam[PARTITION_MAX_NUM];    /* ÿ��������Ϣ */
    u32 dwRamdiskSize;                   /* RAMDISK �Ĵ�С,�ֽ�Ϊ��λ */
}TFlPartnParam;



/*��������*/

/*���������ӿڶ���*/

/*��ȡ����״̬�Ľӿ�*/

/*================================
��������BrdInit 
���ܣ���ģ��ĳ�ʼ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdInit(void);

/*================================
��������BrdQueryPosition 
���ܣ������(ID����š���λ)��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ptBrdPosition�� �ɸú������ذ������Ϣ�Ľṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK�Ͱ������Ϣ��������TBrdPosition�ṹ����
==================================*/
STATUS BrdQueryPosition(TBrdPosition *ptBrdPosition);

/*================================
��������BrdGetBoardID
���ܣ��豸���ID��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� �磺��������ID�ź궨��
==================================*/
u8  BrdGetBoardID(void);

/*================================
��������BrdGetFuncID
���ܣ��豸����ID��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ���幦��ID
==================================*/
u8  BrdGetFuncID(void);

/*================================
��������BrdQueryHWVersion 
���ܣ�Ӳ���汾�Ų�ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� Ӳ���汾�ţ�4��BITλ��ȡֵ��Χ0~16
==================================*/
u8  BrdQueryHWVersion (void);

/*================================
��������BrdQueryFPGAVersion 
���ܣ�FPGA��EPLD�汾�Ų�ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� FPGA��EPLD�汾�ţ�4��BITλ��ȡֵ��Χ0~16
==================================*/
u8  BrdQueryFPGAVersion (void);

/*================================
��������BrdEthPrintEnable
���ܣ������Ƿ���̫��״̬��ӡ��Ч
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  
����ֵ˵���� �ޡ�
==================================*/
void BrdEthPrintEnable(BOOL32 bEnable);

/*================================
��������BrdQueryOsVer
���ܣ��ṩ��ҵ�����õ�os�汾�Ų�ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  pchVer�� ��ȡ�汾���ַ���ָ��
                dwBufLen�����ַ����ĳ���
                pdwVerLen����ȡ�汾��ʵ���ַ������ȣ��ó��ȷ���֮ǰ�����dwBufLen�Ƚ��Ƿ����������ʱ�Ŷ�pVer��ֵ��

����ֵ˵���� �ޡ����ʵ���ַ������ȴ���dwBufLen��pVerLen��ֵΪ0
==================================*/
void  BrdQueryOsVer(s8 *pchVer, u32 dwBufLen,u32 *pdwVerLen);

/*================================
��������BrdGetBSP15Speed
���ܣ���ȡBSP-15����Ƶ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byDevID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� �ɹ�����BSP-15����Ƶ,ʧ�ܷ���ERROR
==================================*/
u8 BrdGetBSP15Speed(u8 byDevID);

/*================================
��������BrdGetBSP15SdramSize
���ܣ���ȡBSP-15��SDRAM�Ĵ�С
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byDevID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� �ɹ�����BSP-15SDRAM�Ĵ�С,ʧ�ܷ���ERROR
==================================*/
u8 BrdGetBSP15SdramSize(u8 byDevID);

/*���ڿ��ƽӿ�*/

/*================================
��������BrdOpenSerial
���ܣ��ṩ��ҵ����Rs232 Rs422 Rs485���⴮��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byPort���ڶ˿ں�
              #define SERIAL_RS232                 0
              #define SERIAL_RS422                 1
              #define SERIAL_RS485                 2
              #define BRD_SERIAL_INFRARED          3
����ֵ˵���� �򿪴��ڵľ��
==================================*/
s32 BrdOpenSerial(u8 byPort);

/*================================
��������BrdCloseSerial
���ܣ��ṩ��ҵ���ر�Rs232 Rs422 Rs485���⴮��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
����ֵ˵���� �ɹ�����0��ʧ�ܷ���ERROR
==================================*/
s32 BrdCloseSerial(s32 nFd);

/*================================
��������BrdReadSerial
���ܣ��ṩ��ҵ����ȡRs232 Rs422 Rs485����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
                pbyBuf��������ݵĻ�����ָ��
                nMaxbytes��Ҫ��ȡ�����ݵ�����ֽ���
����ֵ˵���� �ɹ����ض�ȡ���ݵ��ֽ�������Χ1~ nMaxbytes��0��ʾû�����ݣ�ʧ�ܷ���
            ERROR
==================================*/
s32  BrdReadSerial(s32 nFd, s8  *pbyBuf, s32 nMaxbytes);

/*================================
��������BrdWriteSerial 
���ܣ��ṩ��ҵ���дRs232 Rs422 Rs485���⴮��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
                pbyBuf��Ҫд������ݵĻ�����ָ��
                nBytes��Ҫд�����ݵ��ֽ���
����ֵ˵���� �ɹ�����д�����ݵ��ֽ������ҵ���nBytes����������Ч����ERROR��д��ֵ
             ������nBytes��ʾд�뷢������

==================================*/
s32 BrdWriteSerial (s32 nFd, s8  *pbyBuf, s32 nBytes);

/*================================
��������BrdIoctlSerial 
���ܣ��ṩ��ҵ������Rs232 Rs422 Rs485���ú��⴮�ڣ�ͬioctl����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
                nFunction�����������룬����صĴ��ڲ����궨��
                nArg������
����ֵ˵���� �ɹ�����OK����������Ч��ʧ�ܷ���ERROR
==================================*/
s32 BrdIoctlSerial (s32 nFd, s32 nFunction, s32 nArg);

/*================================
��������BrdRs485QueryData
���ܣ�Rs485��ѯ���ݣ��ȷ���ѯ֡������նԶ�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
		        ptRS485InParam�������������Ľṹָ�룻
		        ptRS485RtnData: ��ŷ�����Ϣ�Ľṹָ�롣
����ֵ˵����  485״̬��غ궨�� 
==================================*/
s32  BrdRs485QueryData (s32 nFd, TRS485InParam *ptRS485InParam,TRS485RtnData *ptRS485RtnData);

/*================================
��������BrdRs485TransSnd 
���ܣ�Rs485͸������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  nFd�������ļ�����������BrdOpenSerial��������
                pbyMsg�������͵����ݣ�
                dwMsgLen: ���ݳ���
����ֵ˵���� 485״̬��غ궨��
==================================*/
s32  BrdRs485TransSnd (s32 nFd, u8 *pbyMsg, u32 dwMsgLen);

/*================================
��������BrdLedStatusSet
���ܣ����õƵ�״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byLedID:�Ƶ�ID�ţ���BoardWrapper.h����صĶ��壩
                byState:�Ƶ�״̬����BoardWrapper.h����صĶ��壩
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
s32  BrdLedStatusSet(u8 byLedID, u8 byState);
  
/*================================
��������BrdQueryLedState
���ܣ�����ģʽ��ѯ 
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ptBrdLedState����ŵƵ�״̬�Ľṹ��ָ��
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
s32  BrdQueryLedState(TBrdLedState *ptBrdLedState);

/*================================
��������BrdQueryNipState
���ܣ�Nip״̬��ѯ 
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� ��
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
s32  BrdQueryNipState(void);

/*================================
��������SysRebootEnable 
���ܣ�����ϵͳ����exceptionʱ�Զ���λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ��
==================================*/
void  SysRebootEnable (void);

/*================================
��������SysRebootDisable
���ܣ���ֹϵͳ����exceptionʱ�Զ���λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ��
==================================*/
void  SysRebootDisable(void);

/*================================
��������BrdWakeup
���ܣ������豸
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� �ɹ�����OK ��ʧ�ܷ���ERROR
==================================*/
STATUS  BrdWakeup(void);

/*================================
��������BrdSleep 
���ܣ������豸
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� �ɹ�����OK ��ʧ�ܷ���ERROR
==================================*/
STATUS  BrdSleep (void);

/*================================
��������BrdHwReset
���ܣ�ϵͳӲ����λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ��
==================================*/
void  BrdHwReset(void);

/*================================
��������SysRebootHookAdd
���ܣ���λ�ص�ע�ắ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ָ��VOIDFUNCPTR���͵ĺ���ָ��
����ֵ˵���� �ɹ�����OK ��ʧ�ܷ���ERROR
==================================*/
STATUS SysRebootHookAdd(VOIDFUNCPTR ptRebootHookFunc);

/*================================
��������SysOpenWdGuard
���ܣ��ṩ��ҵ���3.0�汾�Ĵ�ϵͳ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwNoticeTimeout��֪ͨ��Ϣʱ�䣬���Ӧ�ó��򳬹����ʱ�仹û��֪ͨ����ϵͳ��Ϣ��ϵͳ����λ��ʱ�䵥λΪ�롣
					�������Ϊ0������ΪӦ�ó�����Ҫ��ʱ����֪ͨ��Ϣ������Ӧ�ó���Ľ���״̬�쳣ʱϵͳ��λ��
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
STATUS SysOpenWdGuard(u32 dwNoticeTimeout);

/*================================
��������SysCloseWdGuard
���ܣ��ṩ��ҵ���3.0�汾�Ĺر�ϵͳ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
STATUS SysCloseWdGuard(void);

/*====================================================================
������      : SysNoticeWdGuard
����        ���ṩ��ҵ���3.0�汾��Ӧ�ó���֪ͨ����ϵͳ��������״̬��ͬʱ��˸���еơ�����ϵͳ������
			  Ӧ�ó���ͱ�����ע�����趨��ʱ���ڵ�������ӿڣ��������ϵͳ����λϵͳ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ��������ERROR���ɹ�����OK��
====================================================================*/
STATUS SysNoticeWdGuard(void);

/*====================================================================
������      : SysWdGuardIsOpened
����        ���ṩ��ҵ���3.0�汾�Ļ�ȡϵͳ����״̬��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ���򿪷���TRUE���رշ���FALSE��
====================================================================*/
BOOL32 SysWdGuardIsOpened(void);

/*====================================================================
������      : BrdSetWatchdogMode
����        �����ÿ��Ź�����ģʽ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byMode:���¿��Ź��궨�� 
                #define WATCHDOG_USE_CLK            0x00   ʱ��Ӳ��ι�� 
                #define WATCHDOG_USE_SOFT           0x01    ���ι�� 
                #define WATCHDOG_STOP                0x02   ֹͣι�����豸����������
����ֵ˵��  ����
˵����������VxWorks����ҵ�����ι��Ƶ���������⣬��ˣ���Linux�����˵�����ι����һ����
ͳһ���������ṩ��ϵͳ������һ�׺����ӿڣ��ýӿ���Linux�ϲ����ṩ��
====================================================================*/
void   BrdSetWatchdogMode(u8 byMode);

/*====================================================================
������      : BrdFeedDog
����        ��ι������,1.6�������ٵ�һ�Σ�����ϵͳ�����������øú�������������ȼ�����ܸߣ�����Ϊ������ȼ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ����
˵����������VxWorks����ҵ�����ι��Ƶ���������⣬��ˣ���Linux�����˵�����ι����һ����
ͳһ���������ṩ��ϵͳ������һ�׺����ӿڣ��ýӿ���Linux�ϲ����ṩ��
====================================================================*/
void   BrdFeedDog(void);

/*====================================================================
������      : BrdAlarmStateScan
����        ���ײ�澯��Ϣɨ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ptBrdAlarmState:���صĸ澯��Ϣ
����ֵ˵��  ���򿪷���TRUE���رշ���FALSE��
====================================================================*/
STATUS BrdAlarmStateScan(TBrdAlarmState *ptBrdAlarmState);

/*====================================================================
������      : BrdSetFanState
����        ������ϵͳ��������״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byRunState��ģʽ
                #define BRD_FAN_RUN                  0       ����ת��
                #define BRD_FAN_STOP                 1       ����ͣת
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdSetFanState(u8 byRunState);

/*====================================================================
������      : BrdFanIsStopped
����        ����ѯָ�������Ƿ�ͣת
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ��TRUE=����ͣת / FALSE=��������
====================================================================*/
BOOL32   BrdFanIsStopped(u8 byFanId);

/*====================================================================
������      : BrdExtModuleIdentify
����        ���ն����ģ��ʶ����
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  �����ģ��ID�ţ�
            0ΪE1ģ�飬1Ϊ4E1ģ�飬2ΪV35DTEģ�飬3ΪV35DCEģ�飬4Ϊ����ģ�飬5Ϊ2E1ģ��,
            6ΪKDV8000Bģ��, 0xcΪDSCģ��,ĿǰMDSCҲ�����ID�ţ���һ���MDSC���ı�Ϊ0xd,0xeΪHDSCģ�飬
            0xf û�����ģ��
====================================================================*/
u8   BrdExtModuleIdentify(void);

/*====================================================================
������      : BrdVideoMatrixSet
����        ����Ƶ������������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ע��ѡ��Ķ˿ڷ�Χ�Ӿ�������Ͷ�����16x16������������˿�ȡֵ��Χ��1~16
            ����Ӳ������޷�ȫ��ʹ�ã�ֻʹ����15������8x8ȡֵ��Χ��1~8��
            videoInSelect = ��Ƶ����Դѡ�� 1~16/8����˿ڣ� 0xfb = ����Ӧ�������
            0xfc = ����Ӧ�������Ĭ�����е�����ڶ��Ǵ򿪵ģ����ҵ�����ر���ĳ
            ������ڣ�������ȴ��������ڣ�Ȼ�������ý���������������
            videoOutSelect = ��Ƶ����˿�ѡ��1~16/8��Ƶ����ӿ�
            ˵������KDV8010A�ϣ��豸����ϵ�6������/�����ڶ�Ӧ������/����˿ں��ǣ�2~7
����ֵ˵��  ����
====================================================================*/
void BrdVideoMatrixSet(u8 byInSelect, u8 byOutSelect);

/*====================================================================
������      : BrdTimeGet
����        ��ȡϵͳʱ�䣨�����RTC�л�ȡʱ�䣩
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ptGettm����ŷ���ʱ��Ľṹָ�룻tmΪϵͳ�����ݽṹ
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
˵����ҵ�����Ա��ӿڷ��ص�tm�ṹ�е�����±�������˴���֮����ܴ����û���
���崦��Ҫ���ǣ�tm�е���Ҫ����1900��tm�е���Ҫ������1
====================================================================*/
STATUS BrdTimeGet( struct tm* ptGettm );

/*====================================================================
������      : BrdTimeSet
����        ������ϵͳʱ�䣬�����RTC��ͬ������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ptGettm�����Ҫ���õ�ʱ��Ľṹָ�룻tmΪϵͳ�����ݽṹ
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
˵����ҵ������tm�ṹ�е�����±�������˴���֮����ܴ����ýӿڣ�
���崦��Ҫ���ǣ�tm�е���Ҫ���û����õ���ֵ��ȥ1900��tm�е���Ҫ���û����õ���ֵ��ȥ1
====================================================================*/
STATUS BrdTimeSet( struct tm* ptGettm );

/*====================================================================
������      : BrdGetAlarmInput
����        ����ȡ�ֳ��澯(KDM2400/2500ר��)
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byPort: �澯����˿ں�
              pbyState: ��Ÿ澯����ֵ״̬��ָ�루ֵ���壺0:�澯��1:������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
====================================================================*/
STATUS BrdGetAlarmInput(u8 byPort, u8* pbyState);

/*====================================================================
������      : BrdSetAlarmOutput
����        ������ֳ��澯
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byPort: �澯����˿ںţ�0,1,2��
              pbyState: 0:��������;1:�����ָ�
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
====================================================================*/
STATUS BrdSetAlarmOutput(u8 byPort, u8  byState);

/*====================================================================
������      : BrdGetSdramMaxSize
����        ��ȡ�����ڴ����ֵ,��MByteΪ��λ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ���ڴ����ֵ,��MByteΪ��λ
====================================================================*/
u32 BrdGetSdramMaxSize(void);

/*====================================================================
������      : BrdGetAllDiskInfo
����        ����ȡflash������Ϣ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ptBrdAllDiskInfo ��ָ��TbrdAllDiskInfo�ṹ��ָ��
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
====================================================================*/
STATUS BrdGetAllDiskInfo(TBrdAllDiskInfo *ptBrdAllDiskInfo);

/*====================================================================
������      : BrdGetFullFileName
����        ��ת���ļ���Ϊ��ȫ·�����ļ���
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  byPutDiskId:�̵�Id�� 
                pchInFileName:������ļ��� �������̷���
                pchRtnFileName:���صļ���Id���̷�ȫ·�����ļ���
����ֵ˵��  �����صļ���Id���̷����ļ����ĳ��ȣ����ֽ�Ϊ��λ��0Ϊ����
====================================================================*/
u32 BrdGetFullFileName(u8 byPutDiskId, s8 *pchInFileName, s8 *pchRtnFileName);

/*====================================================================
������      : BrdCopyFile
����        �������ļ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchSrcFile��Դ�ļ���������ȫ·��
                pchDesFile��Ŀ���ļ���������ȫ·��
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdCopyFile (s8 *pchSrcFile, s8 *pchDesFile);

/*====================================================================
������      : BrdBackupFile
����        �������ļ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchSrcFile��Դ�ļ���������ȫ·��
                pchDesFile��Ŀ���ļ���������ȫ·��
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdBackupFile (s8 *pchSrcFile, s8 *pchDesFile);

/*====================================================================
������      : BrdRestoreFile 
����        ����ԭ�ļ������Ŀ���ļ�������ֻ��������ǿ�и���
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchSrcFile��Դ�ļ���������ȫ·��
                pchDesFile��Ŀ���ļ���������ȫ·��
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdRestoreFile(s8 *pchSrcFile, s8 *pchDesFile);

/*====================================================================
������      : SysSetUsrAppParam
����        �������û����������������ã�Ϊ�˼���vx�ϵĽӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pbyFileName:Ӧ���ļ���
                byFileType :�����׺궨�壬������ͬ��Ϊ�˼�����ǰvx��
                #define LOCAL_UNCOMPRESS_FILE   0 ����δѹ�����ļ�
                #define LOCAL_COMPRESS_FILE  1 ����ѹ�����ļ�
                #define REMOTE_UNCOMPRESS_FILE 2 Զ��δѹ�����ļ�
                #define REMOTE_COMPRESS_FILE  3 Զ��ѹ�����ļ�
                #define LOCAL_ZIP_FILE  4 ����zipѹ�����е��ļ�
                pAutoRunFunc:Ϊ�˼�����ǰvx�Ͻӿڶ��裬��������Ч
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS SysSetUsrAppParam(s8 *pbyFileName, u8 byFileType, s8 *pAutoRunFunc);

/*====================================================================
������      : SysSetMultiAppParam
����        ������û����������������ã�Linux�������ӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  ptAppLoadInf:ָ��Ӧ��������Ϣ�����ݽṹ��ָ��
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS SysSetMultiAppParam(TAppLoadInf *ptAppLoadInf);

/*====================================================================
������      : BrdGetMemInfo
����        ����ѯ��ǰ�ڴ�ʹ����Ϣ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pdwByteFree: ��ŵ�ǰ���е��ڴ��С���ݵ�ָ�룬�ֽ�Ϊ��λ
                pdwByteAlloc: ��ŵ�ǰ�ѷ�����ڴ��С���ݵ�ָ�룬�ֽ�Ϊ��λ
����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdGetMemInfo(u32 *pdwByteFree, u32 *pdwByteAlloc);

/*====================================================================
������      : SysGetIdlePercent
����        ����ѯ��ǰcpu�Ŀ��аٷֱ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  ��
����ֵ˵��  ����ǰcpu�Ŀ��аٷֱ�
====================================================================*/
u8 SysGetIdlePercent(void);

/*====================================================================
������      : BrdGetDeviceInfo
����        ����ѯ��ǰ�豸��CPU���͡���Ƶ��u-boot���ں˰汾��Ϣ�Ľӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  ptBrdDeviceInfo:ָ��TBrdDeviceInfo�ṹ���ָ��
����ֵ˵��  ��OK/ERROR
====================================================================*/
STATUS BrdGetDeviceInfo (TBrdDeviceInfo* ptBrdDeviceInfo);

/*====================================================================
������      : BrdAddUser
����        ������ϵͳ�û�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchUserName��Ҫ���ӵĵ�½�û���
		        pchPassword��Ҫ���ӵ��û��ĵ�¼����
                tUserType��Ҫ���ӵ��û����ͣ�����صĽṹ�嶨��
����ֵ˵��  ��OK/ERROR
====================================================================*/
STATUS BrdAddUser (s8* pchUserName,s8* pchPassword, TUserType tUserType);

/*====================================================================
������      : BrdDelUser
����        ��ɾ��ϵͳ�û�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchUserName��Ҫɾ���ĵ�½�û���
		        pchPassword��Ҫɾ�����û��ĵ�¼����
                tUserType��Ҫɾ�����û����ͣ�����صĽṹ�嶨��
����ֵ˵��  ��OK/ERROR
====================================================================*/
STATUS BrdDelUser (s8* pchUserName,s8* pchPassword, TUserType tUserType);

/*====================================================================
������      : BrdUpdateAppFile
����        �����û�ָ���ĵ����ļ����µ�APP��(/usr/binĿ¼��)�Ľӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pchSrcFile��Ҫ���µ�Դ�ļ�������������·������֧�֡�./�������·������
		        pchDstFile��Ҫ���µ�Ŀ���ļ�������������·������֧�֡�./�������·������
����ֵ˵��  ��OK/ERROR
ʾ����BrdUpdateAppFile����/ramdisk/mp8000b��,��/usr/bin/mp8000b����
	��/ramdisk/Ŀ¼�µ�mp8000b������µ�ֻ����APP��(/usr/bin)������Ϊmp8000b
====================================================================*/
STATUS BrdUpdateAppFile (s8* pchSrcFile,s8* pchDstFile);

/*====================================================================
������      : BrdUpdateAppImage
����        �����û�ָ����ʹ��mkfs.jffs2�����İ��������ϲ�ҵ������Image�ļ����µ�APP��(/usr/binĿ¼��)�Ľӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  pImageFile��Ҫ���µ�Image�ļ�������������·������֧�֡�./�������·������
����ֵ˵��  ��OK/ERROR
ʾ����BrdUpdateAppImage����/ramdisk/mdsc.jffs2����
	��/ramdisk/Ŀ¼��ʹ��mkfs.jff2�����ĵİ���mdsc�����е�ҵ����������ļ���mdsc.jffs2�����ļ����µ�ֻ����APP��(/usr/bin)
ע�⣺������ú������豸���������¸���APP����������Ч	
====================================================================*/
STATUS BrdUpdateAppImage (s8* pImageFile);

/*================================
��������BrdGetBSP15CapturePort
���ܣ�BSP15ͼ��ɼ��˿ڲ�ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byBSP15ID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� BSP15ͼ��ɼ��˿ں궨��
==================================*/
u8  BrdGetBSP15CapturePort(u8 byBSP15ID);

/*================================
��������BrdGetSAA7114OutPort
���ܣ�BSP15ͼ������ӿڲ�ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byBSP15ID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� SAA7114ͼ����������˿ں궨��
==================================*/
u8  BrdGetSAA7114OutPort(u8 byBSP15ID);

/*================================
��������BrdGetCaptureChipType
���ܣ�BSP15ͼ��ɼ�оƬ��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byBSP15ID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� ͼ��ɼ�оƬ�ͺ�
==================================*/
u8  BrdGetCaptureChipType(u8 byBSP15ID);

/*================================
��������BrdGetAudCapChipType
���ܣ��ṩ��codec�ϲ��ѯBSP15��Ƶ�ɼ�оƬ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� byBSP15ID:BSP-15��ID��(��0��ʼ��
����ֵ˵���� ��Ƶ�ɼ�оƬ�ͺ�
==================================*/
u8  BrdGetAudCapChipType(u8 byBSP15ID);

/*================================
��������BrdBsp15GpdpIsUsed
���ܣ���ѯ��ЩBSP15��gpdp�˿ڵĻ�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� bsp15ʹ��gpdp����״�������룬ÿ��bitλ����һ��bsp15��0=��ʹ��/1=ʹ�ã�
��λΪ0��map�� ���֧��32��map����
==================================*/
u32 BrdBsp15GpdpIsUsed(void);

/*================================
��������BrdGetBSP15VGAConf
���ܣ���ȡָ��bsp15��vga����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� byDevId��bsp15���豸��
��λΪ0��map�� ��VGA���ú궨��
==================================*/
u8  BrdGetBSP15VGAConf(u8 byDevId);

/*================================
��������BrdStopVGACap
���ܣ�ֹͣ�ɼ�vga(8083)����(����fpga)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��
==================================*/
void BrdStopVGACap(void);

/*================================
��������BrdStartVGACap
���ܣ���ʼ�ɼ�vga(8083)����(����fpga)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byMode:�������VGA�ɼ�ģʽ�궨��
����ֵ˵���� ��
==================================*/
void BrdStartVGACap(u8 byMode);

/*================================
��������BrdSetVGACapMode
���ܣ���ʼ�ɼ�vga(8083)����(����fpga)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byMode:�������VGA�ɼ�ģʽ�궨��
����ֵ˵���� ��
==================================*/
void BrdSetVGACapMode (u8 byMode);

/*================================
��������BrdCloseVGA
���ܣ��رղ���ֹvga(8083)�ɼ�оƬ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��
==================================*/
void BrdCloseVGA(void);

/*================================
��������BrdOpenVGA
���ܣ��򿪲���ʼvga(8083)�ɼ�оƬ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��
==================================*/
void BrdOpenVGA(void);

/*================================
��������BrdSetBsp15GPIOMode
���ܣ�GPIO�����л������ź�,���Ե�11��kdv8010a��Ч
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byMode:ģʽ������صĺ궨��
����ֵ˵���� ��
==================================*/
void BrdSetBsp15GPIOMode(u8 byMode);

/*================================
��������BrdMapDevOpenPreInit
���ܣ���map����ʱ�����Ӳ���ĳ�ʼ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byBSP15ID��bsp15���豸��
����ֵ˵������
==================================*/
void BrdMapDevOpenPreInit(u8 byBSP15ID);

/*================================
��������BrdMapDevClosePreInit
���ܣ���map�ر�ʱ�����Ӳ���ĸ�λ�Ȳ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byBSP15ID��bsp15���豸��
����ֵ˵������
==================================*/
void BrdMapDevClosePreInit(u8 byBSP15ID);

/*====================================================================
������      : BrdAudioMatrixSet
����        ����Ƶ������������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����ע��byAudioInSelect = ����Դѡ��0~6 = 7������ӿڣ�0������Ӳ���ڲ�
          �ѽ���������ͼ�񣬶������Ρ�0xb = ����Ӧ�������0xc = ����Ӧ�������
          byAudioOutSelect = ��Ƶ����˿�ѡ��0~6 = 7����Ƶ����ӿڣ�
          0�����Ӳ���ڲ����ѽ�����������Դ���������Ρ����ౣ����
����ֵ˵��  ����
====================================================================*/
void  BrdAudioMatrixSet(u8 byAudioInSelect, u8 byAdioOutSelect);

#if 0 /*Linux�Ѿ������ṩ�ú���*/
/*====================================================================
������      : SysGetOsVer
����        ����ȡOS�汾���ͣ���Ϊ������ͬһ����������в�ͬ��OS����Ҫ����GKӦ��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ���궨�壺	
		    #define OS_CRI_FOR_MP       0
            #define OS_CRI_FOR_GK       1
====================================================================*/
u8 SysGetOsVer(void);
#endif
/*====================================================================
������      : BrdGetMatrixType
����        ����������Ͳ�ѯ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ����������ͣ������������ͺź궨��
====================================================================*/
u8 BrdGetMatrixType(void);

/*====================================================================
������      : BrdGetPowerVoltage
����        ����ȡ��ǰ��ѹֵ���Ժ���Ϊ��λ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����dwSampleTimes ����������0��ʾʹ��Ĭ��ֵ8
����ֵ˵��  ���ɹ����ص�ѹֵ���Ժ���Ϊ��λ����Ч����ERROR
====================================================================*/
s32 BrdGetPowerVoltage(u32 dwSampleTimes);

/*====================================================================
������      : BrdShutoffPower
����        ���رյ�Դ��Ӧ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ���ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdShutoffPower(void);

/*====================================================================
������      : BrdGetSwitchSel
����        ����ȡ����ѡ���״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵��  ��0 or 1
====================================================================*/
u8 BrdGetSwitchSel(void);

/*================================
��������BrdGetEthParam
���ܣ���ȡ��̫����������ip��mask��mac
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  u8 byEthId --- ��̫��ID�ţ�0~x��;
                TBrdEthParam *ptBrdEthParam --- �����̫����Ϣ�Ľṹָ�롣
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdGetEthParam(u8 byEthId, TBrdEthParam *ptBrdEthParam);

/*================================
��������BrdGetEthParam
���ܣ���ȡһ�����������е���̫�����������IP��ַ�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  u8 byEthId --- ��̫��ID�ţ�0~x��;
                BrdEthParamAll *ptBrdEthParamAll --- �����̫����Ϣ�Ľṹָ�롣
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdGetEthParamAll(u8 byEthId, TBrdEthParamAll *ptBrdEthParamAll);

/*================================
��������BrdSetEthParam
���ܣ���������̫������(��IP������)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
                byIpOrMac��Ϊ��������ѡ��(��BoardWrapper.h����صĺ궨��)
                ptBrdEthParam��ָ�����趨ֵ��TbrdEthParam���ݽṹ��ָ��
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdSetEthParam(u8 byEthId, u8 byIpOrMac, TBrdEthParam *ptBrdEthParam);

/*================================
��������BrdSetSecondEthParam
���ܣ����ô���̫������(��IP������)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
                byIpOrMac��Ϊ��������ѡ��(��BoardWrapper.h����صĺ궨��)
                ptBrdEthParam��ָ�����趨ֵ��TbrdEthParam���ݽṹ��ָ��
����ֵ˵���� ������ERROR���ɹ�����OK��
ע�⣺��Linux�£�һ�����ڿ������ö��IP��ַ��һ����������������5��IP��ַ��
==================================*/
STATUS BrdSetSecondEthParam(u8 byEthId, u8 byIpOrMac, TBrdEthParam *ptBrdEthParam);

/*================================
��������BrdDelEthParam
���ܣ�ɾ��ָ������̫���ӿ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
����ֵ˵���� ������ERROR���ɹ�����OK��
ע�⣺��Linux�£�һ�����ڿ������ö��IP��ַ���ýӿڻ�ɾ���ýӿ��ϵ�����IP��ַ��
==================================*/
STATUS BrdDelEthParam(u8 byEthId);

/*================================
��������BrdSetDefGateway
���ܣ�����Ĭ������ip
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwIpAdrs��Ĭ������ip��ַ�������ͣ�������
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdSetDefGateway(u32 dwIpAdrs);

/*================================
��������BrdGetDefGateway
���ܣ���ȡĬ������ip
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� ��
����ֵ˵���� ���󷵻�0���ɹ����س����͵�ip��ַ��������
==================================*/
u32 BrdGetDefGateway(void);

/*================================
��������BrdDelDefGateway
���ܣ�ɾ��Ĭ������ip
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdDelDefGateway(void);

/*================================
��������BrdGetNextHopIpAddr
���ܣ���ȡͨ��ָ��ip�ĵ�һ��·��ip��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwDstIpAddr��Ŀ��ip��ַ�������ͣ�������
		    dwDstMask��Ŀ�����룬�����ͣ�������
����ֵ˵���� ���󷵻�0���ɹ����ص�һ��·��ip��ַ��������
==================================*/
u32 BrdGetNextHopIpAddr(u32 dwDstIpAddr,u32 dwDstMask);

/*================================
��������BrdGetRouteWayBandwidth
���ܣ���ȡ��E1������·�Ĵ���ֵ����KbpsΪ��λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��·����ֵ����KbpsΪ��λ
==================================*/
u32 BrdGetRouteWayBandwidth(void);

/*================================
��������BrdAddOneIpRoute
���ܣ�����һ��·
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptBrdIpRouteParam��ָ����·����Ϣ��TBrdIpRouteParam�ṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdAddOneIpRoute(TBrdIpRouteParam *ptBrdIpRouteParam);

/*================================
��������BrdDelOneIpRoute
���ܣ�ɾ��һ��·
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptBrdIpRouteParam��ָ����·����Ϣ��TBrdIpRouteParam�ṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdDelOneIpRoute(TBrdIpRouteParam *ptBrdIpRouteParam);

/*================================
��������BrdGetAllIpRoute
���ܣ���ȡ����·����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptBrdAllIpRouteInfo��ָ���ŷ���·����Ϣ��TBrdAllIpRouteInfo�ṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetAllIpRoute(TBrdAllIpRouteInfo *ptBrdAllIpRouteInfo);

/*================================
��������BrdChkOneIpStatus
���ܣ����ָ��ip�������е�״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwIpAdrs��������ip��ַ��������
����ֵ˵���� ����ָ��ip�������е�״̬��
#define IP_SET_AND_UP	        1  ---address set and up 
#define IP_SET_AND_DOWN	        2  ---address set and down
#define IP_NOT_SET	            3  ---address not set
==================================*/
u32 BrdChkOneIpStatus(u32 dwIpAdrs);

/*================================
��������BrdSaveNipConfig
���ܣ�����nip�����������ļ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSaveNipConfig(void);

/*================================
��������BrdIpConflictCallBackReg
���ܣ�ע��ip��ַ��ͻʱ�ص�����,���豸��IP��ַ���ⲿ�豸��ͻʱ������øú���֪ͨҵ�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptFunc��ִ��ҵ�����ע��Ļص�����ָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdIpConflictCallBackReg (TIpConflictCallBack  ptFunc);

/*================================
��������BrdIpOnceConflicted
���ܣ���ѯϵͳ�Ƿ�����ip��ַ��ͻ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� TRUE or FALSE
==================================*/
BOOL32 BrdIpOnceConflicted (void);

/*================================
��������BrdPing
���ܣ���̫��ping�ӿ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����pchDestIP:Ping��Ŀ��IP��ַ
              ptPingOpt��Ping�Ĳ����ṹ��ָ��
              nUserID:�û�ID��־���û����ֲ�ͬ���û�����
              ptCallBackFunc:Ping����Ļص�����
����ֵ˵���� TRUE--����Ĳ����Ϸ����ú������óɹ������Ƿ�pingͨ��Ҫ�û�ע��Ļص��������ж�
             FALSE--����Ĳ����Ƿ����ú�������ʧ��
==================================*/
BOOL32 BrdPing(s8* pchDestIP,TPingOpt* ptPingOpt,s32 nUserID,TPingCallBack ptCallBackFunc);

/*================================
��������BrdGetEthActLnkStat
���ܣ���ʵ����̫������״̬���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthID��Ҫ��ѯ����̫��������
����ֵ˵���� 0=down/1=up
==================================*/
u8 BrdGetEthActLnkStat(u8 byEthID);

/*================================
��������BrdSetV35Param  
���ܣ�����v35�ӿڲ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwDevId��v35�ӿڵı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
                dwIpAdrs��Ϊip��ַ
                dwIpMask��Ϊ�����ַ
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdSetV35Param(u32 dwDevId, u32 dwIpAdrs, u32 dwIpMask);

/*================================
��������BrdGetV35Param
���ܣ���ȡv35�ӿڲ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwDevId��v35�ӿڵı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
pdwIpAdrs��ָ���ŷ���ip��ַ��ָ��
pdwIpMask: ָ���ŷ��������ַ��ָ��
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdGetV35Param(u32 dwDevId, u32 *pdwIpAdrs, u32 *pdwIpMask);

/*================================
��������BrdDelV35Param
���ܣ�ɾ��ָ����v35�ӿڵ�ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwDevId��v35�ӿڵı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ���
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdDelV35Param(u32 dwDevId);

/*================================
��������BrdLineIsLoop
���ܣ���鵱ǰE1��·�Ի�״̬(����ж��E1��·�Ի������ҵ���һ���Ի���E1��·������IP��ַ)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  pdwIpAddr����Žӿ�ip��ַ��ָ�룬���ڷ���ֵΪTRUEʱ��Ч
����ֵ˵���� �Ի��򷵻�TRUE ��û���Ի��򷵻�FALSE
==================================*/
BOOL32   BrdLineIsLoop(u32 *pdwIpAddr);

/*================================
��������BrdGetE1MaxNum
���ܣ���ѯ�豸�������õ�e1����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ������õ�e1����
==================================*/
u8 BrdGetE1MaxNum(void);

/*================================
��������BrdSetE1SyncClkOutputState
���ܣ�Ŀǰ����DRI��DSI��Ч����Ҫ���ô�E1��·����ȡ������ͬ���ο�ʱ���Ƿ������MPC�����ͬ����
      ͬһʱ�̾��Խ�ֹ��ͬ�İ���ͬʱ���ʱ�ӣ�����MPC�޷�ͬ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byMode����ͬ���ο�ʱ�����ģʽ���������£�
                #define E1_ CLK_OUTPUT_DISABLE   ((u8)0)   �����ֹ����ʱ���ź������MPC����
                #define E1_ CLK_OUTPUT_ENABLE    ((u8)1)   �������ʱ���ź������MPC����
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSetE1SyncClkOutputState (u8 byMode);

/*================================
��������BrdSetE1RelayLoopMode
���ܣ�Ŀǰ����DRI��DSI��KDV8010��Ч����Ҫ����E1��·�̵������أ��������ڻ����⻷��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ID��E1��·��ID�ţ����ֵ������豸��أ���������������E1�����궨��;
            byMode���̵�������ģʽ���ã��������£�
            #define BRD_RELAY_MODE_NORMAL     0    �̵�����ͨ
            #define BRD_RELAY_MODE_LOCLOOP    1    �̵����Ի�
            #define BRD_RELAY_MODE_OUTLOOP    2    �̵����⻷
            ˵����
            1����DRI��˵��ֻ���������ڻ����ã�
            2����DSI��˵��ֻ���������⻷���ã�
            3����MT��˵��ֻ���������ڻ����ã��Һ������ģ����ء�
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSetE1RelayLoopMode(u8 byE1ID,u8 byMode);

/*================================
��������BrdSelectE1NetSyncClk
���ܣ�Ŀǰ����DRI��DSI��Ч����Ҫ������ͬ���ο�ʱ�����ѡ��
ע�⣺�ù��ܱ�����BrdSetE1SyncClkOutputState������ͬ���ο�ʱ���������������²���Ч
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ID��E1��·��ID�ţ����ֵ������豸��أ���������������E1�����궨��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSelectE1NetSyncClk(u8 byE1ID);

/*================================
��������BrdQueryE1Imp
���ܣ�Ŀǰ����DRI��DSI��KDV8010��Ч����Ҫ��ȡָ��e1�迹ֵ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ID��E1��·��ID�ţ����ֵ������豸��أ���������������E1�����궨��
����ֵ˵���� ���󷵻�0xff���ɹ������迹ֵ�궨��
==================================*/
u8  BrdQueryE1Imp(u8 byE1ID);

/*================================
��������BrdGetE1AlmState
���ܣ���ȡָ��E1��·�ĸ澯״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ID��E1��·��ID�ţ����ֵ������豸��أ���������������E1�����궨��
����ֵ˵���� ����0Ϊ��������0�и澯
==================================*/
u8  BrdGetE1AlmState(u8 byE1Id);

/*================================
��������E1TransGetMaxE1Num
���ܣ���ȡ�豸ʵ��֧�ֵ�E1����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ���󷵻�0����ӡ������Ϣ���ɹ�, �����豸ʵ��֧�ֵ�E1����
==================================*/
u8 E1TransGetMaxE1Num(void);

/*================================
��������E1TransChanOpen
���ܣ���һ��E1͸������ͨ������ʼ����Ӧ��mcc_channel
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID���򿪵�ͨ����,����С�� E1_TRANS_CHAN_MAX_NUM
		      ptChanParam��ͨ���Ĳ�������
              ptE1MsgCallBack��ע��Ļص�����
����ֵ˵���� E1_TRANS_FAILURE/E1_TRANS_SUCCESS
==================================*/
s32 E1TransChanOpen( u8 byE1ChanID,TE1TransChanParam *ptChanParam,TE1MsgCallBack  ptE1MsgCallBack );

/*================================
��������E1TransChanClose
���ܣ��ر�mcc������һ��E1͸������ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID���򿪵�ͨ����,����С�� E1_TRANS_CHAN_MAX_NUM
����ֵ˵���� E1_TRANS_FAILURE/E1_TRANS_SUCCESS
==================================*/
s32 E1TransChanClose( u8 byE1ChanID);

/*================================
��������E1TransChanMsgSnd
���ܣ�����ģʽ�������ݰ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
		      tMsgParam:��Ϣ������Ϣָ��
����ֵ˵���� ��E1͸�����䲿�ֵķ���ֵ�궨��
==================================*/
s32 E1TransChanMsgSnd(u8 byE1ChanID, TE1TransMsgParam *ptMsgParam);

/*================================
��������E1TransTxPacketNumGet
���ܣ���ȡָ��ͨ�����ͻ����������д����͵����ݰ��ĸ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
����ֵ˵���� ������E1_TRANS_FAILURE���ɹ����ض����д����͵����ݰ��ĸ���
==================================*/
s32 E1TransTxPacketNumGet(u8 byE1ChanID);

/*================================
��������E1TransBufQHeadPtrInc
���ܣ��ƶ���ָ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
              dwOffset����ַƫ��
����ֵ˵���� ��E1͸�����䲿�ֵķ���ֵ�궨��
==================================*/
s32 E1TransBufQHeadPtrInc(u8 byE1ChanID, u32 dwOffset);

/*================================
��������E1TransBufMsgCopy
���ܣ����ж�ȡָ�����ȵ����ݵ�ָ�������������ƶ���ָ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
              pbyDstBuf:�������ݱ�����
              dwSize:������������
����ֵ˵���� ���󷵻�0���ɹ����ض������ֽ���
==================================*/
s32 E1TransBufMsgCopy(u8 byE1ChanID, u8 *pbyDstBuf, u32 dwSize);

/*================================
��������E1TransBufMsgLenGet
���ܣ���ѯ��ǰ�ɶ����ݵĳ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
����ֵ˵���� ���󷵻�0���ɹ����ؿɶ����ݳ���
==================================*/
s32 E1TransBufMsgLenGet(u8 byE1ChanID);

/*================================
��������E1TransBufMsgByteRead
���ܣ���ȡ��ǰ��ָ�뿪ʼָ��ƫ�Ƶ�һ���ַ������ƶ���ָ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
              dwOffset:��ַƫ��
              pbyRtnByte:���ֽ����ݵ�ָ��
����ֵ˵���� ��E1͸�����䲿�ֵķ���ֵ�궨��
==================================*/
s32 E1TransBufMsgByteRead(u8 byE1ChanID, u32 dwOffset, u8 *pbyRtnByte);

/*================================
��������E1TransChanLocalLoopSet
���ܣ���ָ��ͨ��������·�Ի�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
              bIsLoop���Ƿ񽫸���·����Ϊ�Ի�ģʽ
����ֵ˵���� ��E1͸�����䲿�ֵķ���ֵ�궨��
==================================*/
s32 E1TransChanLocalLoopSet(u8 byE1ChanID, BOOL32 bIsLoop);

/*================================
��������E1TransChanInfoGet
���ܣ���ȡָ��ͨ�������շ���ͳ����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byE1ChanID:�豸��
              ptInfo:��ͳ����Ϣ��ָ��
����ֵ˵���� ��E1͸�����䲿�ֵķ���ֵ�궨��
==================================*/
s32 E1TransChanInfoGet(u8 byE1ChanID, TE1TransChanStat *ptInfo);

/*================================
��������BrdOpenE1SingleLinkChan
���ܣ�����һ��E1����·����ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwChanID: ����·����ͨ���ţ���Χ0~ E1_SINGLE_LINK_CHAN_MAX_NUM -1����ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ��һ��ͨ�������ظ��򿪣������ȹر�
              ptChanParam:����·����ͨ�������ṹָ��
����ֵ˵���� E1_RETURN_OK/ERRCODE
==================================*/
STATUS BrdOpenE1SingleLinkChan(u32 dwChanID, TBrdE1SingleLinkChanInfo *ptChanParam);

/*====================================================================
������      : BrdCloseE1SingleLinkChan
����        ���ر�ָ����E1����·����ͨ��
�㷨ʵ��    ����
����ȫ�ֱ�������
�������˵����dwChanID: ����·����ͨ���ţ���Χ0~ E1_SINGLE_LINK_CHAN_MAX_NUM -1��
            ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ��
            ��ͨ���������Ѿ��򿪳ɹ��ģ����δ���򷵻�E1_ERR_CHAN_NOT_CONF;
����ֵ˵��  ��E1_RETURN_OK/ERRCODE��
====================================================================*/
STATUS BrdCloseE1SingleLinkChan(u32 dwChanID);

/*====================================================================
������      : BrdGetE1SingleLinkChanInfo
����        ����ȡָ����E1����·����ͨ����Ϣ
�㷨ʵ��    ������·�����ṩ��nipģ��Ľӿڡ�
����ȫ�ֱ�������
�������˵����dwChanID: ����·����ͨ���ţ���Χ0~ E1_SINGLE_LINK_CHAN_MAX_NUM -1��
            ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ��
            ��ͨ���������Ѿ��򿪳ɹ��ģ����δ���򷵻�E1_ERR_CHAN_NOT_CONF;
                ptChanInfo:����·����ͨ�������ṹָ��.
����ֵ˵��  ��E1_RETURN_OK/ERRCODE��
====================================================================*/
STATUS BrdGetE1SingleLinkChanInfo(u32 dwChanID, TBrdE1SingleLinkChanInfo *ptChanInfo);

/*====================================================================
������      : BrdOpenE1MultiLinkChan
����        ������һ��E1����·��������ͨ��
�㷨ʵ��    ������·�����ṩ��nipģ��Ľӿڡ�
����ȫ�ֱ�������
�������˵����dwChanID: ����·��������ͨ���ţ���Χ0~ dwMultiLinkChanNum -1��
            ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ��һ��ͨ�������ظ��򿪣�
            �����ȹر�;
             ptChanParam:����·��������ͨ�������ṹָ��.
����ֵ˵��  ��E1_RETURN_OK/ERRCODE��
====================================================================*/
STATUS BrdOpenE1MultiLinkChan(u32 dwChanID, TBrdE1MultiLinkChanInfo *ptChanParam);

/*====================================================================
������      : BrdCloseE1MultiLinkChan
����        ���ر�ָ����E1����·��������ͨ��
�㷨ʵ��    ����
����ȫ�ֱ�������
�������˵����dwChanID: ����·��������ͨ���ţ���Χ0~ dwMultiLinkChanNum -1��
            ��ID����Ψһ�ԣ�������ʶÿ������·��������ͨ�������ɳ�ͻ��
            ��ͨ���������Ѿ��򿪳ɹ��ģ����δ���򷵻�E1_ERR_CHAN_NOT_CONF;
����ֵ˵��  ��E1_RETURN_OK/ERRCODE��
====================================================================*/
STATUS BrdCloseE1MultiLinkChan(u32 dwChanID);

/*====================================================================
������      : BrdGetE1MultiLinkChanInfo
����        ����ȡָ����E1����·��������ͨ����Ϣ
�㷨ʵ��    ������·�����ṩ��nipģ��Ľӿڡ�
����ȫ�ֱ�������
�������˵����dwChanID: ����·��������ͨ���ţ���Χ0~ dwMultiLinkChanNum -1��
            ��ID����Ψһ�ԣ�������ʶÿ������·����ͨ�������ɳ�ͻ��
            ��ͨ���������Ѿ��򿪳ɹ��ģ����δ���򷵻�E1_ERR_CHAN_NOT_CONF;
            ptChanInfo:����·��������ͨ�������ṹָ��.
����ֵ˵��  ��E1_RETURN_OK/ERRCODE��
====================================================================*/
STATUS BrdGetE1MultiLinkChanInfo(u32 dwChanID, TBrdE1MultiLinkChanInfo *ptChanInfo);

/*RawFlash��صĺ�������*/

/*================================
�������� BrdRawFlashIsUsed
���ܣ���ѯ�Ƿ����rawflash����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����  ��
����ֵ˵���� TRUE:ʹ��/FALSE:��ʹ��
==================================*/
BOOL32   BrdRawFlashIsUsed(void);

/*================================
��������BrdGetFullRamDiskFileName
���ܣ�ת�����·�����ļ���Ϊramdisk�д�����·�����ļ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pInFileName:���·�����ļ���,��"webfiles/doc/www.html"; 
               pRtnFileName:��ŷ��ؾ���·���ļ����ĵ�ַָ�롣
               ��������ӻ����:"/ramdisk/webfiles/doc/www.html"
����ֵ˵���� ������·���ļ����ĳ��ȡ�
==================================*/
u32 BrdGetFullRamDiskFileName(s8 *pInFileName, s8 *pRtnFileName);

/*================================
��������BrdFpUnzipFile
���ܣ���ѹ���Ϸ�����ָ�����ļ����������ָ�����ļ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pUnzipFileName:����ѹ���ļ������ɺ����·������"/webfiles/doc/aaa.html"��
               pOuputFileName:��Ž�ѹ�����ݵ��ļ�����Ŀǰ�����ѹ��/ramdisk/�У���"/ramdisk/bbb.html"
����ֵ˵��  ��OK/ERROR��
==================================*/
STATUS BrdFpUnzipFile(s8 *pUnzipFileName, s8 *pOuputFileName);

/*================================
��������BrdFpUnzipFileIsExist
���ܣ���ѯ���Ϸ���ѹ������ָ����ѹ���ļ��Ƿ���ڡ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pUnzipFileName:����ѹ���ļ���
����ֵ˵���� TRUE/FALSE
==================================*/
BOOL32   BrdFpUnzipFileIsExist(s8 *pUnzipFileName);

/*================================
��������BrdFpPartition
���ܣ�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� ptParam��ָ��TFlPartnParam�ṹ��������ָ�롣
����ֵ˵���� OK/ERROR��
==================================*/
STATUS BrdFpPartition(TFlPartnParam *ptParam);

/*================================
��������BrdFpGetFPtnInfo
���ܣ���������Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� ptParam��ָ��TFlPartnParam�ṹ��������ָ�롣
����ֵ˵���� OK/ERROR��
==================================*/
STATUS BrdFpGetFPtnInfo(TFlPartnParam *ptParam);

/*================================
��������BrdFpGetExecDataInfo
���ܣ���ȡ�����ִ�г�������͡���ַ�ʹ�С 
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pdwExecAdrs:��������ִ��������Ե�ַ�Ļ�������ָ�룻
                pdwExeCodeType:��������ִ���������͵Ļ�������ָ�롣
����ֵ˵���� -1����/����ֵΪ�����ִ�����ݵĴ�С��
==================================*/
s32  BrdFpGetExecDataInfo(u32 *pdwExecAdrs, u32 *pdwExeCodeType);

/*================================
��������BrdFpReadExecData
���ܣ���ȡ�����ִ�г�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pbyDesBuf:��������ִ�����ݵĻ�������ָ��;
              dwLen: Ҫ��ȡ�����ݵĳ��ȡ�
����ֵ˵���� -1����/����ֵΪ��ȡ�����ִ�г������ݵĳ��ȡ�
==================================*/
s32  BrdFpReadExecData(u8 *pbyDesBuf, u32 dwLen);

/*================================
��������BrdFpUpdateExecData
���ܣ����������ִ�г�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pFile:FPGA�ļ�����
����ֵ˵���� OK/ERROR��
==================================*/
STATUS BrdFpUpdateExecData(s8* pFile);

/*================================
��������BrdFpWriteExecData
���ܣ�����ExeCode�����ִ�г�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� ��
����ֵ˵���� OK/ERROR��
==================================*/
STATUS BrdFpEraseExeCode(void);

/*================================
��������BrdFpUpdateAuxData
���ܣ�����IOS�����е�����(IOS�����е�������ɣ�kernel+ramdisk�����У�kernel��ramdisk��·���鷢����--update.linux)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵���� pFile:update.linux�ļ�����
����ֵ˵���� OK/ERROR��
==================================*/
STATUS BrdFpUpdateAuxData(s8* pFile);

/*================================
������      : BrdFpEraseAuxData
����        ����ȡ�û����ݷ����ĸ�����
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵�����ޡ�
����ֵ˵��  ���û������ĸ���
==================================*/
u8  BrdFpGetUsrFpnNum (void);

/*================================
������      : BrdFpWriteDataToUsrFpn
����        ��дָ�����������ݵ�ָ�����û����ݷ���
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byIndex���ڼ����û���������0��ʼ��
              pbyData��Ҫд�������ָ��
              dwLen��Ҫд�����ݵĳ���
����ֵ˵��  ��OK/ERROR��
==================================*/
STATUS BrdFpWriteDataToUsrFpn(u8 byIndex, u8 *pbyData, u32 dwLen);

/*================================
������      : BrdFpWriteDataToUsrFpn
����        ����ȡָ��������ָ����ָ�����ȵ���Ч���ݵ�������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byIndex���ڼ����û���������0��ʼ��
              pbyData��Ҫ����������ָ��
              dwLen��Ҫ�������ݵĳ���
����ֵ˵��  ��ʵ�ʶ�ȡ�����ݳ���
==================================*/
s32  BrdFpReadDataFromUsrFpn(u8 bySection, u8 *pbyDesBuf, u32 dwLen);

/*================================
������      : BrdMPCQueryAnotherMPCState
����        ���Զ�����������Ƿ���λ��ѯ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ���궨�壺
		  #define BRD_MPC_OUTOF_POSITION      ((u8)0)   //�Զ���������岻��λ
          #define BRD_MPC_IN_POSITION               ((u8)1)   //�Զ������������λ
==================================*/
u8 BrdMPCQueryAnotherMPCState(void);

/*================================
������      : BrdMPCQueryLocalMSState
����        ����ǰ���������������״̬��ѯ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ���궨�壺
		  #define BRD_MPC_RUN_MASTER      ((u8)0)   // ��ǰ�������������
          #define BRD_MPC_RUN_SLAVE               ((u8)1)   // ��ǰ��������屸�� 
==================================*/
u8 BrdMPCQueryLocalMSState (void);

/*================================
������      : BrdMPCSetLocalMSState
����        �����õ�ǰ���������������״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byState:
              #define BRD_MPC_RUN_MASTER          0      // ��ǰ�������������
              #define BRD_MPC_RUN_SLAVE           1      // ��ǰ��������屸�� 
����ֵ˵��  ��OK/ERROR
==================================*/
STATUS BrdMPCSetLocalMSState (u8 byState);

/*================================
������      : BrdMPCQuerySDHType
����        ����ģ�������ѯ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ���궨�壺
		#define BRD_MPC_SDHMODULE_NONE      ((u8)0x07)   // ��ǰ���������û�в�ģ�� 
        #define BRD_MPC_SDHMODULE_SOI1      ((u8)0x00)   // ��ǰ����������ģ��SOI1 
        #define BRD_MPC_SDHMODULE_SOI4      ((u8)0x01)   // ��ǰ����������ģ��SOI4  
==================================*/
u8 BrdMPCQuerySDHType (void);

/*================================
������      : BrdMPCQueryNetSyncMode
����        �����໷����ģʽ��ѯ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ���궨�壺
		#define SYNC_MODE_FREERUN           ((u8)0)   // �����񵴣�����MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ��
        #define SYNC_MODE_TRACK_SDH8K       ((u8)1)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����8Kʱ��
        #define SYNC_MODE_TRACK_SDH2M       ((u8)2)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����2Mʱ�� 
        #define SYNC_MODE_TRACK_DT2M        ((u8)4)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT����2Mʱ�� 
        #define SYNC_MODE_UNKNOWN           ((u8)0xff)// δ֪������ģʽ 
==================================*/
u8 BrdMPCQueryNetSyncMode (void);

/*================================
������      : BrdMPCSetNetSyncMode
����        �����໷��ͬ��ģʽѡ�����ã���֧��SDH����
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byMode�����໷��ͬ��ģʽ�������¶��壺
        #define SYNC_MODE_FREERUN           ((u8)0)   // �����񵴣�������MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ�� 
        #define SYNC_MODE_TRACK_SDH8K       ((u8)1)   //����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����8Kʱ�� 
        #define SYNC_MODE_TRACK_SDH2M       ((u8)2)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����2Mʱ�� 
        #define SYNC_MODE_TRACK_DT2M        ((u8)4)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT����2Mʱ��
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCSetNetSyncMode(u8 byMode);

/*================================
������      : BrdMPCSetAllNetSyncMode
����        �����໷��ͬ��ģʽѡ������,����sdh����
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byMode�����໷��ͬ��ģʽ�������¶��壺
        #define SYNC_MODE_FREERUN           ((u8)0)   // �����񵴣�������MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ�� 
        #define SYNC_MODE_TRACK_SDH8K       ((u8)1)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����8Kʱ�� 
        #define SYNC_MODE_TRACK_SDH2M       ((u8)2)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����2Mʱ�� 
        #define SYNC_MODE_TRACK_DT2M        ((u8)4)   // ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT����2Mʱ��
        dwSdhE1Id������ͬ��ģʽΪSYNC_MODE_TRACK_SDH8K��SYNC_MODE_TRACK_SDH2Mʱ����ָ��sdh��Ӧ��e1�ţ������SOI-1ģ
        �鷶ΧΪ241-301�������SIO-4ģ��ʱ��ΧΪ241-484
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCSetAllNetSyncMode(u8 byMode, u32 dwSdhE1Id);

/*================================
������      : BrdMPCResetSDH
����        ����ģ�鸴λ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCResetSDH (void);

/*================================
������      : BrdMPCReSetAnotherMPC
����        ����λ�Զ��������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCReSetAnotherMPC (void);

/*================================
������      : BrdMPCOppReSetDisable
����        ����ֹ�Զ����������λ���������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCOppReSetDisable (void);

/*================================
������      : BrdMPCOppReSetEnable 
����        ������Զ����������λ���������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCOppReSetEnable (void);

/*================================
������      : BrdMPCLedBoardSpeakerSet
����        �����õư���������������״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����byState��������״̬�����º궨��
        #define LED_BOARD_SPK_ON                ((u8)0x01)   //����������
        #define LED_BOARD_SPK_OFF               ((u8)0x00)   // �ر�������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCLedBoardSpeakerSet(u8 byState);

/*================================
������      : BrdFastLoadEqtFileIsEn
����        ���Ƿ�����bsp15��������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ��0=��ֹ��������bsp15����flash�������ٶȽ���;
              1=�����������bsp15�����ڴ澵���������ٶȽϿ죬��ռ�ý϶��ڴ�;
==================================*/
u8 BrdFastLoadEqtFileIsEn(void);

/*================================
������      : AtaApiMountPartion
����        �����ش��̷���---Linux�������Ĵ��̲����ӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����pchPartionName:Ҫ���صĴ��̷������ƣ���"/dev/hda0"
              pMntPath:Ҫ���ص�Ŀ��·������"/ramdisk/hda0"
����ֵ˵��  �����󷵻���ata����ģ����������������룻�ɹ�, ����ATA_SUCCESS.
==================================*/
s32 AtaApiMountPartion(s8* pchPartionName,s8* pMntPath);

/*================================
������      : BrdNipErase
����        ������NIP������Ϣ
�㷨ʵ��    ���������ã�����consoleģʽ�µ��øú�����
              telnet�ϵ��øú����ᵼ��telnet�޷���������
              ������nip��IP��ַ��������telnet�޷�������������
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdNipErase(void);

/*================================
������      : BrdMicAdjustIsSupport
����        ����ѯ��ǰmic�����Ƿ�֧��
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�FALSE���ɹ�����TRUE
==================================*/
BOOL32   BrdMicAdjustIsSupport(void);

/*================================
������      : BrdMicVolumeSet
����        ������mic��������
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����byTapPosition:���ף���Χ��0-127,������Ϊ���߼�
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMicVolumeSet(u8  byTapPosition);

/*================================
������      : BrdMicVolumeGet
����        ����ѯ��ǰmic�������� 
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ����ǰmic��������(0-127)/0xff=����
==================================*/
u8 BrdMicVolumeGet(void);
	

/*====================================================================
    ������      : BrdGetEthLinkStat
    ����        ����ȡ��̫���ӿ�����״̬
    �������˵����u8 byEthId ��̫���ӿںţ�
                  u8 *Link   ��ȡ����̫���ӿ�����״̬��
                             0-link down, 1-link up
    ����ֵ˵��  ��OK = �ɹ���ERROR = ʧ��
====================================================================*/
STATUS  BrdGetEthLinkStat(u8 byEthId, u8 *Link);

/*====================================================================
    ������      : BrdGetEthNegStat
    ����        ����ȡ��̫���ӿ�����״̬
    �������˵����u8 byEthId ��̫���ӿںţ�
                  u8 *AutoNeg ��̫��Э��״̬��1-��Э�̣�0-ǿ��
                  u8 *Duplex  ��̫��˫��״̬��1-ȫ˫����0-��˫��
                  u32 *Speed  ��̫���ӿ�����Mbps��10/100/1000
    ����ֵ˵��  ��OK = �ɹ���ERROR = ʧ��
====================================================================*/
STATUS  BrdGetEthNegStat(u8 byEthId, u8 *AutoNeg, u8 *Duplex, u32 *Speed);

/*====================================================================
    ������      : BrdSetEthNego
    ����        ����ȡ��̫���ӿ�����״̬
    �������˵����u8 byEthId ��̫���ӿںţ�
                  u8 Duplex  ��̫��˫��״̬��1-ȫ˫����0-��˫��, 2-��Э��
                  u32 Speed  ��̫���ӿ�����Mbps��10/100/1000��0-��Э��
    ����ֵ˵��  ��OK = �ɹ���ERROR = ʧ��
====================================================================*/
STATUS  BrdSetEthNego(u8 byEthId, u8 Duplex, u32 Speed);



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /*_BOARDWRAPPER_H*/
