/*****************************************************************************
ģ����      : all board
�ļ���      : brdDrvLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  ����Ӳ��osʹ�õ����к궨��Ͳ��ֹ�������������.
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/8/19   01a         �ŷ���      ����	
******************************************************************************/
#ifndef __INCBrdDrvLibh
#define __INCBrdDrvLibh


#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#ifndef WIN32 
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
*/
#include "time.h"
#include "timers.h"
#endif

/* +++++++++++++++++++++++++++++ �����豸�������� ++++++++++++++++++++++++++++++++++*/
/* ============================= �����궨�� =====================================*/
/* OS�汾��Ϣ */
#define VER_MCUDRVLIB           ( const char * )"MCUDrvLib 40.01.01.01.050226"
#define VER_CRIDRVLIB           ( const char * )"CRIDrvLib 40.01.01.01.050318"
#define VER_APUVxNIP            ( const char * )"APUVxNIP 40.01.03.02.060412"
#define VER_MCUVXNIP            ( const char * )"MCUVXNIP 40.01.05.05.060412"
#define VER_CRIVxNIP            ( const char * )"CRIVxNIP 40.01.04.06.060925"
#define VER_DRIVxNIP            ( const char * )"DRIVxNIP 40.01.04.04.060610"
#define VER_DSIVxNIP            ( const char * )"DSIVxNIP 40.01.03.03.060610"
#define VER_KDV8000BVxNIP       ( const char * )"KDV8000BVxNIP 40.01.02.02.060412"
#define VER_MMPVxNIP            ( const char * )"MMPVxNIP  40.01.04.03.060412"
#define VER_VASVxNIP            ( const char * )"VASVxNIP 40.01.02.02.060412"
#define VER_MTVxNIPforKDV8010A  ( const char * )"MTVxNIPforKDV8010A 40.01.11.06.070806"
#define VER_KDV8018VxNIP        ( const char * )"KDV8018VxNIP 36.01.00.00.050226"
#define VER_IMTVxNIP            ( const char * )"IMTVxNIP 40.01.02.02.060412"
#define VER_KDV8005VxNIP        ( const char * )"KDV8005VxNIP 40.01.02.02.060412"
#define VER_KDV8010CVxNIP       ( const char * )"KDV8010CVxNIP 40.01.08.03.070309"
#define VER_VRIVxNIP            ( const char * )"VRIVxNIP 40.01.02.02.060812"
#define VER_DRI16VxNIP       	( const char * )"DRI16VxNIP 40.01.02.02.060412"
#define VER_16E1VxNIP       	( const char * )"16E1VxNIP 40.01.05.04.060610"
#define VER_KDV8003VxNIP       	( const char * )"KDV8003VxNIP 40.01.03.02.060510"
#define VER_KDM2417VxNIP       	( const char * )"KDM2417VxNIP 40.01.08.03.060412"
#define VER_KDV8008VxNIP       	( const char * )"KDV8008VxNIP 40.01.04.01.060302"
#define VER_MDSCVxNIP       	( const char * )"MDSCVxNIP 40.01.01.01.050824"
#define VER_KDM2000VxNIP       	( const char * )"KDM2000VxNIP 40.01.05.04.070202"
#define VER_KDM2428VxNIP       	( const char * )"KDM2428VxNIP 40.01.05.05.070809"

/* ��������ID�ź궨�� */  
#define DSL8000_BRD_MPC             0      /* MPC�� */
#define DSL8000_BRD_DTI             1      /* DTI�� */
#define DSL8000_BRD_DIC             2      /* DIC�� */
#define DSL8000_BRD_CRI             3      /* CRI�� */
#define DSL8000_BRD_VAS             4      /* VAS�� */
#define DSL8000_BRD_MMP             5      /* MMP�� */
#define DSL8000_BRD_DRI             6      /* DRI�� */
#define DSL8000_BRD_IMT             7      /* IMT�� */
#define DSL8000_BRD_APU             8      /* APU�� */
#define DSL8000_BRD_DSI             9      /* DSI�� */
#define DSL8000_BRD_VPU             10     /* VPU�� */
#define DSL8000_BRD_DEC5            11     /* DEC5�� */
#define DSL8000_BRD_VRI             12     /* VRI�� */
#define KDV8000B_MODULE             13     /* KDV8000Bģ�� */
#define  KDV8005_BOARD              14     /* KDV8005�� */
#define DSL8000_BRD_DRI16           15     /* DRI16�� */
#define DSL8000_BRD_MDSC          0x10     /* MDSC�� */
#define DSL8000_BRD_16E1          0x11     /* 16E1�� */
#define KDV8003_BOARD             0x12     /* KDV8003�� */

#define KDM2560_BOARD             0x31     /* KDM2560 */
#define KDV2400_BOARD               50     /* 2400�ն� */
#define KDV2500_BOARD               51     /* 2500B�ն� */
#define KDM2418_BOARD               52     /* 2418�ն� */
#define KDM2518_BOARD               53     /* 2518�ն� */
#define KDM2417_BOARD               54     /* 2417�ն� */
#define KDM2428_BOARD               56     /* 2428�ն� */

#define KDV8010_BOARD               100    /* KDV8010�ն� */
#define KDV8018_BOARD               101    /* KDV8018�ն� */
#define KDV8010A_BOARD              102    /* KDV8010A�ն� */
#define KDV8010B_BOARD              103    /* KDV8010B�ն� */
#define KDV8010C_BOARD              104    /* KDV8010C�ն� */
#define KDV8010D_BOARD              105    /* KDV8010D�ն� */
#define KDV8010E_BOARD              106    /* KDV8010E�ն� */
#define KDV8000B_BOARD              107    /* KDV8000B�ն� */
#define KDV8010A_10_BOARD           108    /* ��ʮ��KDV8010A�ն� */
#define KDV8008_BOARD               109    /* KDV8008�ն� */
#define KDV8010A_PLUS_BOARD         110    /* ��ʮһ��KDV8010A�ն� */

/* BrdLedStatusSet������ָʾ����˸״̬ */
#define BRD_LED_ON                  1      /* �� */
#define BRD_LED_OFF                 2      /* �� */
#define BRD_LED_QUICK               3      /* ���� */
#define BRD_LED_SLOW                4      /* ���� */

/* BrdLedStatusSet ������ָʾ�ƿ���ID */
#define LED_E1_ID_BASE               0xd0
#define LED_E1_ID(ix)                (LED_E1_ID_BASE+ix)      /* ģ����0��E1�澯��*/
#define LED_E1_ID0                   LED_E1_ID(0)/*0��E1�ĸ澯��*/
#define LED_E1_ID1                   LED_E1_ID(1)/*1��E1�ĸ澯��*/
#define LED_E1_ID2                   LED_E1_ID(2)/*2��E1�ĸ澯��*/
#define LED_E1_ID3                   LED_E1_ID(3)/*3��E1�ĸ澯��*/
#define LED_E1_ID4                   LED_E1_ID(4)/*4��E1�ĸ澯��*/
#define LED_E1_ID5                   LED_E1_ID(5)/*5��E1�ĸ澯��*/
#define LED_E1_ID6                   LED_E1_ID(6)/*6��E1�ĸ澯��*/
#define LED_E1_ID7                   LED_E1_ID(7)/*7��E1�ĸ澯��*/
#define LED_E1_ID8                   LED_E1_ID(8)/*8��E1�ĸ澯��*/
#define LED_E1_ID9                   LED_E1_ID(9)/*9��E1�ĸ澯��*/
#define LED_E1_ID10                  LED_E1_ID(10)/*10��E1�ĸ澯��*/
#define LED_E1_ID11                  LED_E1_ID(11)/*11��E1�ĸ澯��*/
#define LED_E1_ID12                  LED_E1_ID(12)/*12��E1�ĸ澯��*/
#define LED_E1_ID13                  LED_E1_ID(13)/*13��E1�ĸ澯��*/
#define LED_E1_ID14                  LED_E1_ID(14)/*14��E1�ĸ澯��*/
#define LED_E1_ID15                  LED_E1_ID(15)/*15��E1�ĸ澯��*/

#define LED_SYS_ALARM                0xe0      /* ϵͳ�澯�ƣ����а�����Ч */
#define LED_SYS_LINK                 0xe1      /* ϵͳ���ӵƣ����а�����Ч */
#define LED_BOARD_LED_NORM           0xe2      /* �ư�������ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_BOARD_LED_NALM           0xe3      /* �ư���һ��澯ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_BOARD_LED_SALM           0xe4      /* �ư������ظ澯ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_CDMA_LED      	         0xe5      /* KDM2417��CDMA�� */
#define LED_WLAN_LED      	         0xe6      /* KDM2417��WLAN�� */
#define LED_DISK_LED      	         0xe7      /* KDM2417�ϴ洢��ָʾ�� */
#define LED_MPC_OUS                  0xe8      /* mpc���ous���ߵƣ�����ͬ���ã�ͬ������� */

#define LED_BSP15_ID_BASE            0xf0
#define LED_BSP15_ID(ix)             (LED_BSP15_ID_BASE+ix)      /* bsp15ָʾ�� */
#define LED_BSP15_ID0                LED_BSP15_ID(0)      /* 0��bsp15ָʾ�� */
#define LED_BSP15_ID1                LED_BSP15_ID(1)      /* 1��bsp15ָʾ�� */
#define LED_BSP15_ID2                LED_BSP15_ID(2)      /* 2��bsp15ָʾ�� */
#define LED_BSP15_ID3                LED_BSP15_ID(3)      /* 3��bsp15ָʾ�� */
#define LED_BSP15_ID4                LED_BSP15_ID(4)      /* 4��bsp15ָʾ�� */
#define LED_BSP15_ID5                LED_BSP15_ID(5)      /* 5��bsp15ָʾ�� */


/* BrdSetEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_IP_AND_MASK         1      /* ����IP��ַ���������� */
#define Brd_SET_MAC_ADDR            2      /* ����MAC��ַ */
#define Brd_SET_ETH_ALL_PARAM       3      /* ������̫����IP��ַ�����������MAC��ַ */

/* ip��ַ����״̬ */
#define IP_SET_AND_UP	   1  /* address set and up */
#define IP_SET_AND_DOWN	   2  /* address set and down */
#define IP_NOT_SET	       3  /* address not set */

#define IP_ROUTE_MAX_NUM   64 /* ���֧�ֵ�·�ɸ��� */
#define KDV8005_V35__MAX_NUM   1 /* ���֧�ֵ�V35�ӿ��� */
#define VRI_V35_MAX_NUM   	   6 /* ���֧�ֵ�V35�ӿ��� */

/* SysSetAutoRunFile�������û����������������� */
#define LOCAL_UNCOMPRESS_FILE       0      /* ����δѹ�����ļ���һ����.out��β */ 
#define LOCAL_COMPRESS_FILE         1      /* ����ѹ�����ļ���һ����.z��β */ 
#define REMOTE_UNCOMPRESS_FILE      2      /* Զ��δѹ�����ļ���һ����.out��β */ 
#define REMOTE_COMPRESS_FILE        3      /* Զ��ѹ�����ļ���һ����.z��β */ 
#define LOCAL_ZIP_FILE              4      /* ����zipѹ�����е��ļ���һ����.out��β */ 

/* BrdSetWatchdogMode�����п��Ź��궨�� */
#define WATCHDOG_USE_CLK            0x00   /* ʱ��Ӳ��ι�� */
#define WATCHDOG_USE_SOFT           0x01   /* ���ι�� */
#define WATCHDOG_STOP               0x02   /* ֹͣι�� */

/* flash������Ϣ�궨�� */
#define DISK_MAX_NUMBER             8      /* ���֧�ֵĴ洢�豸���� */

/* BrdSetFanState�����з�������״̬�궨�� */
#define BRD_FAN_RUN                  0      /* ����ת�� */
#define BRD_FAN_STOP                 1      /* ����ͣת */

/* BrdFanIsStopped�����з���ID���ƺ궨�� */
#define BRD_FAN_MAX_NUM              8      /* ���������� */

/* BrdOpenSerial�����򿪴������ͺ궨�� */
#define BRD_SERIAL_RS232                 0
#define BRD_SERIAL_RS422                 1
#define BRD_SERIAL_RS485                 2
#define BRD_SERIAL_INFRARED              3



/* E1��·NIP��װ�ӿ���غ궨�� */
/*---------------------------------------------------------------------------*/
#define E1_SINGLE_LINK_CHAN_MAX_NUM 32 /* ���֧�ֵ�E1����·serialͬ���ӿڸ��� */
#define E1_MULTI_LINK_CHAN_MAX_NUM   8 /* ���֧�ֵ�E1����·��������ͨ��(��virtual����ģ��ӿ�)���� */

/* dwProtocolType�����궨�� */
#define INTERFACE_PROTOCOL_PPP       0 /* �ӿ�Э��PPP */
#define INTERFACE_PROTOCOL_HDLC      1 /* �ӿ�Э��HDLC */

/* dwAuthenticationType�����궨�� */
#define MP_AUTHENTICATION_NONE      0  /* ��������֤���� */
#define MP_AUTHENTICATION_PAP       1  /* PPP���ӵ���֤����PAP */
#define MP_AUTHENTICATION_CHAP      2  /* PPP���ӵ���֤����CHAP */

/* dwFragMinPackageLen ������Χ�궨�� */
#define MP_FRAG_MIN_PACKAGE_LEN_MIN_VAL  20
#define MP_FRAG_MIN_PACKAGE_LEN_MAX_VAL  1500

#define MP_STRING_MAX_LEN            32  /* ��ģ��ͨ���ַ������� */

/* dwSerialId ������Χ�궨�� */
#define E1_SERIAL_ID_MIN_VAL             16
#define E1_SERIAL_ID_MAX_VAL             62

/* dwE1ChanGroupId ������Χ�궨�� */
#define E1_CHAN_GROUP_ID_MIN_VAL         0
#define E1_CHAN_GROUP_ID_MAX_VAL         7

/* dwFragMinPackageLen dwSerialId dwE1ChanGroupId �����Զ����ú궨�� */
#define E1_PARAM_AUTO_CONFIG            0xffffffff

/* dwEchoInterval dwEchoMaxRetry �������ֵ�궨�� */
#define E1_SERIAL_ECHO_MAX_VAL           256

/* ����ֵ�������붨�� */
#define E1_RETURN_OK                    0                     /* �����ɹ� */
#define E1_ERRCODE_BASE                 10                    /* �������ֵ */
#define E1_ERR_UNKNOWN                  (E1_ERRCODE_BASE+0)   /* δ֪���� */
#define E1_ERR_PARAM_EXCEPTION          (E1_ERRCODE_BASE+1)   /* �����쳣 */
#define E1_ERR_SERIAL_ID_INVALID        (E1_ERRCODE_BASE+2)   /* SERIALͬ���ӿں���Ч */
#define E1_ERR_E1_ID_INVALID            (E1_ERRCODE_BASE+3)   /* E1�ӿں���Ч */
#define E1_ERR_E1_TSMASK_INVALID        (E1_ERRCODE_BASE+4)   /* E1ʱ϶������Ч */
#define E1_ERR_E1_CHANGROUP_ID_INVALID  (E1_ERRCODE_BASE+5)   /* E1ʱ϶�������ڵı������Ч */
#define E1_ERR_SERIAL_PROTOCOL_TYPE_INVALID  (E1_ERRCODE_BASE+6) /* �ӿ�Э���װ������Ч */
#define E1_ERR_SERIAL_ECHO_INTERVAL_INVALID  (E1_ERRCODE_BASE+7) /* ͬ���ӿڵ�echo����ʱ������Ч */
#define E1_ERR_SERIAL_ECHO_MAXRETRY_INVALID  (E1_ERRCODE_BASE+8) /* ͬ���ӿڵ�echo����ط�������Ч */
#define E1_ERR_STRING_LEN_OVERFLOW           (E1_ERRCODE_BASE+9) /* �ַ���������� */
#define E1_ERR_NIP_OPT_ERR                   (E1_ERRCODE_BASE+10)/* nip�ӿڵ���ʧ�� */
#define E1_ERR_CHAN_NOT_CONF                 (E1_ERRCODE_BASE+11)/* ָ����ͨ����δ��ʹ�� */
#define E1_ERR_CHAN_CONFLICT                 (E1_ERRCODE_BASE+12)/* ͨ���ų�ͻ��ָ����ͨ�����ѱ�ʹ�� */
#define E1_ERR_MP_AUTHEN_TYPE_INVALID        (E1_ERRCODE_BASE+13)/* PPP���ӵ���֤����������Ч */
#define E1_ERR_MP_FRAG_MIN_PACKAGE_LEN_INVALID (E1_ERRCODE_BASE+14)/* ��С��Ƭ������Ч */


/*---------------------------------------------------------------------------*/


#ifndef WIN32 
/* =============================== �������ݽṹ ================================*/
/* ������ݽṹ���� */
typedef struct{
    UINT8 byBrdID;                      /* ����ID�� */
    UINT8 byBrdLayer;                   /* �������ڲ�� */
    UINT8 byBrdSlot;                    /* �������ڲ�λ�� */
}TBrdPosition;

/* ��̫�������ṹ */
typedef struct{
    UINT32 dwIpAdrs;
    UINT32 dwIpMask;
    UINT8  byMacAdrs[6];
}TBrdEthParam;


/* ·�ɲ����ṹ */
typedef struct{
    UINT32 dwDesIpNet;      /* Ŀ������	*/
    UINT32 dwDesIpMask;     /* ����		*/
    UINT32 dwGwIpAdrs;      /* ����ip��ַ */
    UINT32 dwRoutePri;		/* ·�����ȼ���0ΪĬ�� */
}TBrdIpRouteParam;

typedef struct{
    UINT32 dwIpRouteNum;    /* �õ���ʵ��·�ɸ��� */
    TBrdIpRouteParam tBrdIpRouteParam[IP_ROUTE_MAX_NUM];
}TBrdAllIpRouteInfo;


/*--------------------E1��·NIP��װ�ӿ���ؽṹ����---------------------------*/
/* E1��·����serial�ӿڲ����ṹ */
typedef struct{
    UINT32 dwUsedFlag;                  /* ��ǰserialͬ���ӿ�ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    UINT32 dwSerialId;                  /* serialͬ���ӿڱ�ţ�e1��·��16��ʼ����Ч��Χ16~62,���ɳ�ͻ */
    UINT32 dwE1Id;                      /* ��serialͬ���ӿڶ�Ӧ��e1��ţ������÷�Χ0~E1_MAXNUM-1, E1_MAXNUMȡ������ӦӲ��֧�ֵ�e1����,��kdv8010�ն� #define BRD_MT_E1_MAXNUM 4 */
    UINT32 dwE1TSMask;                  /* E1ʱ϶����˵��,����� */
    UINT32 dwE1ChanGroupId;             /* E1ʱ϶�������ڵı���ţ������÷�Χ0~7,��������һ��E1ʹ�õĻ���0�������ֵĻ������ÿ��ʱ϶�ν������α�� */
    UINT32 dwProtocolType;		/* �ӿ�Э���װ����,����ǵ�E1���ӿ���ָ��PPP/HDLC������Ƕ�E1�������ӱ�����PPPЭ�� */
    UINT32 dwEchoInterval;		/* ��Ӧserialͬ���ӿڵ�echo����ʱ��������Ϊ��λ����Ч��Χ0-256����Ĭ��ֵ2���� */
    UINT32 dwEchoMaxRetry;		/* ��Ӧserialͬ���ӿڵ�echo����ط���������Ч��Χ0-256����Ĭ��ֵ2���� */
}TBrdE1SerialInfo;
/********************************************************************************* 
* dwE1TSMaskʱ϶���䲹��˵����
*    ʱ����������룬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
* Ts0��Ϊͬ���źţ��û�����ʹ��, 0x0��0x1���ǷǷ��Ĳ�������Ч��Χ��0x2~0xfffffffe��
* ��: ʹ��TS1~TS5 5��ʱ϶ʱdwE1TSMask = 0x0000003e,ע��:Ts0=0; ��ʱ����= 64x5 = 320kbit
      ʹ��TS1~TS3,TS30~31 5��ʱ϶ʱdwE1TSMask = 0xc000000e,ע��:Ts0=0; ��ʱ����= 64x5 = 320kbit
**********************************************************************************/

/* ��E1��·����ͨ�������ṹ */
typedef struct{
    UINT32 dwUsedFlag;                  /* ��ǰE1����·����ͨ��ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    UINT32 dwIpAdrs;                    /* ip��ַ�������� */
    UINT32 dwIpMask;                    /* ���룬������ */
    TBrdE1SerialInfo tE1SerialInfo;     /* ��Ӧserialͬ���ӿ���·���� */
}TBrdE1SingleLinkChanInfo;

/* ��E1��·��������ͨ�������ṹ */
typedef struct{
    UINT32 dwUsedFlag;                      /* ��ǰE1����·��������ͨ��ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч */
    UINT32 dwIpAdrs;                        /* ip��ַ�������� */
    UINT32 dwIpMask;                        /* ���룬������ */
    UINT32 dwAuthenticationType;            /* PPP���ӵ���֤����PAP/CHAP,Ĭ����MP_AUTHENTICATION_PAP */
    UINT32 dwFragMinPackageLen;             /* ��С��Ƭ�������ֽ�Ϊ��λ����Χ20~1500��Ĭ����20 */
    char   chSvrUsrName[MP_STRING_MAX_LEN]; /* ������û����ƣ�������֤�Զ˵����� */
    char   chSvrUsrPwd[MP_STRING_MAX_LEN];  /* ������û����룬������֤�Զ˵����� */
    char   chSentUsrName[MP_STRING_MAX_LEN];/* �ͻ����û����ƣ��������Զ���֤ */
    char   chSentUsrPwd[MP_STRING_MAX_LEN]; /* �ͻ����û����룬�������Զ���֤ */
    TBrdE1SerialInfo tE1SerialInfo[E1_SINGLE_LINK_CHAN_MAX_NUM];/* ÿ���������serialͬ���ӿ���·���� */
}TBrdE1MultiLinkChanInfo;
/*---------------------------------------------------------------------------*/


/* flash������Ϣ�ṹ���� */
typedef struct{
    UINT32  dwDiskBaseAddr;       /* flash�̵Ļ���ַ */
    UINT32  dwDiskSize;           /* flash�̵���������ByteΪ��λ */
    char diskNameStr[32];         /* flash�̵����� */
}TBrdDiskInfoDesc;

typedef struct{
    UINT8  byDiskNum;           /* ʵ��flash�̵ĸ��� */
    TBrdDiskInfoDesc tBrdDiskInfo[DISK_MAX_NUMBER];
}TBrdAllDiskInfo;

/* �ײ�V35�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmV35CDDown;     /* Carrier Detect, �ز����ʧ�� */
    BOOL bAlarmV35CTSDown;    /* Clear To Send, �������ʧ�� */
    BOOL bAlarmV35RTSDown;    /* Request To Send, ������ʧ�� */
    BOOL bAlarmV35DTRDown;    /* �����ն�δ���� */
    BOOL bAlarmV35DSRDown;    /* ����δ׼���� */
}TBrdV35AlarmDesc;

/* �ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmE1RUA1;     /* E1ȫ1�澯 */
    BOOL bAlarmE1RLOS;     /* E1ʧͬ���澯 */
    BOOL bAlarmE1RRA;      /* E1Զ�˸澯 */
    BOOL bAlarmE1RCL;      /* E1ʧ�ز��澯 */
    BOOL bAlarmE1RCMF;     /* E1��CRC��֡����澯 */
    BOOL bAlarmE1RMF;      /* E1��·��֡����澯 */
}TBrdE1AlarmDesc;


/* MPC��ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRUN;     /* ϵͳ���е� */
    UINT8 byLedDSP;     /* DSP���е� */
    UINT8 byLedALM;     /* ϵͳ�澯�� */
    UINT8 byLedMS;      /* ������ָʾ�� */
    UINT8 byLedOUS;     /* ousָʾ�� */
    UINT8 byLedSYN;     /* ͬ��ָʾ�� */
    UINT8 byLedLNK0;    /* ��̫��0���ӵ� */
    UINT8 byLedLNK1;    /* ��̫��1���ӵ� */
    UINT8 byLedNMS;     /* nmsָʾ�� */
    UINT8 byLedNORM;    /* �ư�������ָʾ�� */
    UINT8 byLedNALM;    /* �ư���һ��澯ָʾ�� */
    UINT8 byLedSALM ;   /* �ư������ظ澯ָʾ�� */
}TBrdMPCLedStateDesc;


/* CRIָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRUN;      /* ϵͳ���е� */
    UINT8 byLedMRUN;     /* VOIP/DDNģ�����е� */
    UINT8 byLedSPD0;     /* ����0����ָʾ�� */
    UINT8 byLedLNK0;     /* ����0����ָʾ�� */
    UINT8 byLedACT0;     /* ����0�����շ���Чָʾ�� */
    UINT8 byLedSPD1;     /* ����1����ָʾ�� */
    UINT8 byLedLNK1;     /* ��̫��1���ӵ� */
    UINT8 byLedACT1;     /* ����1�����շ���Чָʾ�� */
    UINT8 byLedWERR;     /* ���������ݴ��� */
    UINT8 byLedMLNK;     /* ��MPC����ָʾ�� */
}TBrdCRILedStateDesc;

/* DRIָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedE1_ALM0;
    UINT8 byLedE1_ALM1;
    UINT8 byLedE1_ALM2;
    UINT8 byLedE1_ALM3;
    UINT8 byLedE1_ALM4;
    UINT8 byLedE1_ALM5;
    UINT8 byLedE1_ALM6;
    UINT8 byLedE1_ALM7;
    UINT8 byLedMLINK;
    UINT8 byLedLNK0;
    UINT8 byLedLNK1;
}TBrdDRILedStateDesc;

/* DRI16ָʾ�ƽṹ *//*wjh:add*/
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedE1_ALM0;
    UINT8 byLedE1_ALM1;
    UINT8 byLedE1_ALM2;
    UINT8 byLedE1_ALM3;
    UINT8 byLedE1_ALM4;
    UINT8 byLedE1_ALM5;
    UINT8 byLedE1_ALM6;
    UINT8 byLedE1_ALM7;
    UINT8 byLedE1_ALM8;
    UINT8 byLedE1_ALM9;
    UINT8 byLedE1_ALM10;
    UINT8 byLedE1_ALM11;
    UINT8 byLedE1_ALM12;
    UINT8 byLedE1_ALM13;
    UINT8 byLedE1_ALM14;
    UINT8 byLedE1_ALM15;
    UINT8 byLedMLINK;
    UINT8 byLedLNK0;
    UINT8 byLedLNK1;
}TBrdDRI16LedStateDesc;

/* DSIָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedE1_ALM0;
    UINT8 byLedE1_ALM1;
    UINT8 byLedE1_ALM2;
    UINT8 byLedE1_ALM3;
    UINT8 byLedE1_ALM4;
    UINT8 byLedE1_ALM5;
    UINT8 byLedE1_ALM6;
    UINT8 byLedE1_ALM7;
    UINT8 byLedMLINK;
    UINT8 byLedLNK0;
    UINT8 byLedLNK1;
}TBrdDSILedStateDesc;

/* IMTָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedDSP1;
    UINT8 byLedDSP2;
    UINT8 byLedDSP3;
    UINT8 byLedSYSALM;
    UINT8 byLedMLINK;
    UINT8 byLedLNK0;
    UINT8 byLedLNK1;
}TBrdIMTLedStateDesc;

/* KDV8000Bģ��DSCָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedLNK0;
    UINT8 byLedLNK1;
}TBrdDSCLedStateDesc;

/* MMPָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRUN; 
    UINT8 byLedDSPRUN1;
    UINT8 byLedDSPRUN2;
    UINT8 byLedDSPRUN3;
    UINT8 byLedDSPRUN4;
    UINT8 byLedDSPRUN5;
    UINT8 byLedALM;
    UINT8 byLedLNK;
    UINT8 byLedETH0;
    UINT8 byLedETH1;
}TBrdMMPLedStateDesc;

/* VASָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRUN; 
    UINT8 byLedALM;
    UINT8 byLedMLNK;
    UINT8 byLedETHLNK;
}TBrdVASLedStateDesc;

/* �ն�KDV8010ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedDSP1;
    UINT8 byLedDSP2;
    UINT8 byLedDSP3;
    UINT8 byLedETH1;
    UINT8 byLedETH2;
    UINT8 byLedETH3;
    UINT8 byLedIR;
}TBrdMTLedStateDesc;


/* �ն�KDV8018ǰ���ָʾ��״̬���ݽṹ */
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

/* �ն�KDV8010Cǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedDSP1;
    UINT8 byLedDSP2;
    UINT8 byLedETH1;
    UINT8 byLedIR;
}TBrdKDV8010CLedStateDesc;

/* �ն�KDV8010A�Լ�KDV8000Bǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedDSP1;
    UINT8 byLedDSP2;
    UINT8 byLedDSP3;
    UINT8 byLedETH1;
    UINT8 byLedIR;
}TBrdKDV8010LedStateDesc;

/* KDV8005ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedETH0;
    UINT8 byLedETH1;
    UINT8 byLedV35;
}TBrdKDV8005LedStateDesc;

/* KDV8003ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedLINK;
    UINT8 byLedETH0;
    UINT8 byLedE1Alm;
}TBrdKDV8003LedStateDesc;

/* KDM2417ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedCDMA;
    UINT8 byLedWLAN;
    UINT8 byLedETH;
    UINT8 byLedDISK;
}TBrdKDM2417LedStateDesc;

/* KDV8008ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun;
    UINT8 byLedALM;
    UINT8 byLedETH0;
    UINT8 byLedETH1;
    UINT8 byLedSW;
}TBrdKDV8008LedStateDesc;

/* KDM2000PLUSǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedRun; 
    UINT8 byLedALM; 
    UINT8 byLedLINK;
    UINT8 byLedDSP;
    UINT8 byLedE1Alm;
    UINT8 byLedETH1;
    UINT8 byLedSPD1;
    UINT8 byLedETH2;
}TBrdKDM2000LedStateDesc;

/* KDM2428ǰ���ָʾ�ƽṹ */
typedef struct{
    UINT8 byLedPower;
    UINT8 byLedALM;
    UINT8 byLedRun; 
    UINT8 byLedLNK;
    UINT8 byLedETH;
    UINT8 byLedDISK;
}TBrdKDM2428LedStateDesc;

/* ָʾ��״̬�����ṹ */
#define BRD_LED_NUM_MAX     32      /* ���Ƶĸ��� */
typedef struct {
    UINT32 dwLedNum;                /* ʵ��ָʾ�Ƶĸ��� */
    union {
        UINT8 byLedNo[BRD_LED_NUM_MAX];
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
        TBrdSMTLedStateDesc tBrdSMTLedState;
        TBrdKDV8010CLedStateDesc tBrdKDV8010CLedState;
        TBrdKDV8010LedStateDesc tBrdKDV8010LedStateDesc;
        TBrdKDV8005LedStateDesc tBrdKDV8005LedState;
        TBrdKDV8003LedStateDesc tBrdKDV8003LedState;
        TBrdKDM2417LedStateDesc tBrdKDM2417LedState;
        TBrdKDV8008LedStateDesc tBrdKDV8008LedState;
        TBrdKDM2000LedStateDesc tBrdKDM2000LedState;
        TBrdKDM2428LedStateDesc tBrdKDM2428LedState;
    } nlunion;
} TBrdLedState;


/* �����Դ�澯���ݽṹ */
typedef struct{
    BOOL bAlarmPowerDC48VLDown;     /* ���Դ-48V�쳣 */
    BOOL bAlarmPowerDC48VRDown;     /* �ҵ�Դ-48V�쳣 */
    BOOL bAlarmPowerDC5VLDown;      /* ���Դ+5V�쳣 */
    BOOL bAlarmPowerDC5VRDown;      /* �ҵ�Դ+5V�쳣 */
}TBrdMPCAlarmPowerDesc;

/* �����Դ���ȸ澯���ݽṹ */
typedef struct{
    BOOL bAlarmPowerFanLLDown;      /* ���Դ�����ͣת */
    BOOL bAlarmPowerFanLRDown;      /* ���Դ�ҷ���ͣת */
    BOOL bAlarmPowerFanRLDown;      /* �ҵ�Դ�����ͣת */
    BOOL bAlarmPowerFanRRDown;      /* �ҵ�Դ�ҷ���ͣת */
}TBrdMPCAlarmPowerFanDesc;

/* MPC����澯���ݽṹ���� */
typedef struct{
    BOOL bAlarmNetClkLockFailed;     /*  ���໷û����ס�ο�ʱ�� */
    TBrdMPCAlarmPowerDesc tBrdMPCAlarmPower; /* ��Դ�澯 */
    TBrdMPCAlarmPowerFanDesc tBrdMPCAlarmPowerFan; /* ��Դ���ȸ澯 */
}TBrdMPCAlarmVeneer;

/* SDH�澯�ṹ���� */
typedef struct{
    BOOL bAlarmLOS;         /* �źŶ�ʧ */
    BOOL bAlarmLOF;         /* ֡��ʧ */
    BOOL bAlarmOOF;         /* ֡ʧ�� */
    BOOL bAlarmLOM;         /* ��֡��ʧ */
    BOOL bAlarmAU_LOP;      /* ����Ԫָ�붪ʧ */
    BOOL bAlarmMS_RDI;      /* ���ö�Զ��ȱ��ָʾ */
    BOOL bAlarmMS_AIS;      /* ���öα���ָʾ */
    BOOL bAlarmHP_RDI;      /* �߽�ͨ��Զ��ȱ��ָʾ */
    BOOL bAlarmHP_AIS;      /* �߽�ͨ������ָʾ */
    BOOL bAlarmRS_TIM;      /* ������ͨ���ټ��ֽڲ�ƥ�� */
    BOOL bAlarmHP_TIM;      /* ��ͨ���ټ��ֽڲ�ƥ�� */
    BOOL bAlarmHP_UNEQ;     /* �߽�ͨ���źű���ֽ�δװ�� */
    BOOL bAlarmHP_PLSM;     /* �߽�ͨ���źű���ֽڲ�ƥ�� */

    BOOL bAlarmTU_LOP;      /* ֧·��Ԫָ�붪ʧ */
    BOOL bAlarmLP_RDI;      /* �ͽ�ͨ��Զ��ȱ��ָʾ */
    BOOL bAlarmLP_AIS;      /* �ͽ�ͨ������ָʾ */
    BOOL bAlarmLP_TIM;      /* �ͽ�ͨ���ټ��ֽڲ�ƥ�� */
    BOOL bAlarmLP_PLSM;     /* �ͽ�ͨ���źű���ֽڲ�ƥ�� */
}TBrdMPCAlarmSDH;


/* MPC�澯���ݽṹ���� */
typedef struct{
    TBrdMPCAlarmVeneer tBrdMPCAlarmVeneer;
    TBrdMPCAlarmSDH    tBrdMPCAlarmSDH;
}TBrdMPCAlarmAll;

/* CRI�澯���ݽṹ */
typedef struct{
    BOOL bAlarmModuleOffLine;     /* ģ������,�Ժ���Ҫɾ�� */
}TBrdCRIAlarmVeneer;

typedef struct{
    BOOL bAlarmModuleOffLine;     /* ģ������ */
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
    BOOL bAlarmDSP1FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP2FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP3FanStop;     /* ��Ƶ��������ͣת */
}TBrdIMTAlarmAll;


/* KDV8010�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmEth1LnkDown;     /* ��̫��1������ */
    BOOL bAlarmEth2LnkDown;     /* ��̫��2������ */
    BOOL bAlarmEth3LnkDown;     /* ��̫��3������ */

    BOOL bAlarmDSP1FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP2FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP3FanStop;     /* ��Ƶ��������ͣת */
    BOOL bAlarmSYS1FanStop;     /* �������1ͣת */
    BOOL bAlarmSYS2FanStop;     /* �������2ͣת */

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
#define BRD_ALM_NUM_MAX     256  /* ���澯��Ԫ���� */
typedef struct {
    UINT32 dwAlmNum;             /* ʵ�ʸ澯��Ԫ���� */
    union {
        BOOL bAlmNo[BRD_ALM_NUM_MAX];
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

/* ��̫������æ״̬��Ϣ */
typedef struct{
    UINT8 byEthId;
    BOOL  bSndBusy;
}TBrdEthSndBusyParam;

typedef void ( *TEthSndBusyCallBack )(UINT32 dwUsrArg, TBrdEthSndBusyParam *ptParam);

typedef void ( *TIpConflictCallBack )(UINT8 *pbyMacAddr, UINT32 dwIpAdrs);

/* 485��ѯ��������Ĳ����ṹ */
typedef struct {
    UINT32 dwDevType;           /* 485�豸���� */
    UINT32 dwRcvTimeOut;        /* �ȴ�485�豸��Ӧ�ĳ�ʱ,0ȡĬ��ֵ */
    UINT8  byDesAddr;           /* 485�豸Ŀ���ַ */
    UINT8  byCmd;               /* �������� */
} TRS485InParam;


/* IRAY����ֵ�ṹ */
typedef struct{
    UINT8 byCtrllerType;    /* ң�������� */
    UINT8 byKeyCode;        /* ���� */
}TIRAYRtnDataDesc;

typedef struct {
    BOOL bDevLnked;         /* 485�豸����״̬ */
    union {
        TIRAYRtnDataDesc tIRAYRtnData;
    } nlunion;
} TRS485RtnData;


/* =============================== ������������ ================================*/
STATUS BrdQueryPosition(TBrdPosition *pTBrdPosition);  /* �����(ID����š���λ)��ѯ */
UINT8  BrdGetBoardID(void);                            /* �豸���ID��ѯ */
UINT8  BrdGetFuncID(void);                             /* �豸����ID��ѯ */
UINT8  BrdQueryHWVersion(void);                        /* Ӳ���汾�Ų�ѯ */
UINT8  BrdQueryFPGAVersion(void);                      /* FPGA�汾�Ų�ѯ */
void   BrdQueryOsVer(char *pVer, UINT32 dwBufLen, UINT32 *pVerLen);/* os�汾�Ų�ѯ */
STATUS BrdTimeGet( struct tm* pGettm );                /* ��ȡRTCʱ�� */
STATUS BrdTimeSet( struct tm* pSettm );                /* ����RTC��ϵͳʱ�� */ 
STATUS BrdLedStatusSet(UINT8 byLedID, UINT8 byState);  /* ����ƿ��� */
STATUS BrdSetEthParam(UINT8 byEthId, UINT8 byIpOrMac, TBrdEthParam *ptBrdEthParam); /* ������̫������ */
STATUS BrdGetEthParam(UINT8 byEthId, TBrdEthParam *ptBrdEthParam);                  /* ��ȡ��̫������ */
STATUS BrdDelEthParam(UINT8 byEthId);                  /* ɾ��ָ������̫���ӿ� */
STATUS BrdSetDefGateway(UINT32 dwIpAdrs);              /* ����Ĭ������ip */
UINT32 BrdGetDefGateway(void);                         /* ��ȡĬ������ip */
STATUS BrdDelDefGateway(void);                         /* ɾ��Ĭ������ip */
UINT32 BrdGetNextHopIpAddr(UINT32 dwDstIpAddr);        /* ��ȡͨ��ָ��ip�ĵ�һ��·��ip��ַ */
STATUS SysRebootHookAdd(VOIDFUNCPTR rebootHook);       /* ��λע�ắ�� */
void   BrdHwReset(void);                               /* ϵͳӲ����λ */
void   SysRebootDisable(void);                         /* ��ֹϵͳ����excptionʱ�Զ���λ */
void   SysRebootEnable(void);                          /* ����ϵͳ����excptionʱ�Զ���λ */
STATUS SysOpenWdGuard(UINT32 dwNoticeTimeout);         /* ��ϵͳ���� */
STATUS SysCloseWdGuard(void);                          /* �ر�ϵͳ���� */
STATUS SysNoticeWdGuard(void);                         /* ����һ��ϵͳ���� */
BOOL   SysWdGuardIsOpened(void);                       /* ��ѯϵͳ�����Ƿ�� */

UINT32 BrdGetSdramMaxSize(void);                       /* ȡ�����ڴ����ֵ,��MByteΪ��λ */
void   BrdSetWatchdogMode(UINT8 byMode);               /* ���ÿ��Ź�����ģʽ */
void   BrdFeedDog(void);                               /* ι������,1.6�������ٵ�һ�� */
STATUS BrdQueryLedState(TBrdLedState *ptBrdLedState);  /* ����ģʽ��ѯ */
STATUS BrdAlarmStateScan(TBrdAlarmState *ptBrdAlarmState);  /* �ײ�澯��Ϣɨ�� */
UINT32 BrdGetRouteWayBandwidth(void);                  /* ��ȡ��·����ֵ����KbpsΪ��λ */
STATUS SysSetAutoRunFile( char *pFileName, UINT8 byFileType, char *pAutoRunFunc,
                          char *pFtpSvrIp, char *pFtpUsr, char *pFtpPassWord ); /* �µ��û����������������� */

STATUS BrdGetAllDiskInfo(TBrdAllDiskInfo *pBrdAllDiskInfo); /* ��ȡflash������Ϣ */
UINT32 BrdGetFullFileName(UINT8 byPutDiskId, char *pInFileName, char *pRtnFileName); /* �ļ�������·���� */
STATUS BrdWakeup(void);      /* �豸���� */
STATUS BrdSleep(void);       /* �豸���� */
STATUS BrdRestoreFile(char *pSrcFile, char *pDesFile);/* ��ԭ�ļ� */
STATUS BrdBackupFile(char *pSrcFile, char *pDesFile); /* �����ļ� */
STATUS BrdSetFanState(UINT8 byRunState);              /* ����ϵͳ��������״̬ */
BOOL   BrdFanIsStopped(UINT8 byFanId);                /* ��ѯָ�������Ƿ�ͣת */

STATUS BrdSetV35Param(UINT32 dwDevId, UINT32 dwIpAdrs, UINT32 dwIpMask);    /* ����v35���� */
STATUS BrdGetV35Param(UINT32 dwDevId, UINT32 *pdwIpAdrs, UINT32 *pdwIpMask);/* ��ȡv35�ӿڲ��� */
STATUS BrdDelV35Param(UINT32 dwDevId);                           /* ɾ��v35�ӿ� */
STATUS BrdAddOneIpRoute(TBrdIpRouteParam *ptBrdIpRouteParam);    /* ����һ��·�� */
STATUS BrdDelOneIpRoute(TBrdIpRouteParam *ptBrdIpRouteParam);    /* ɾ��һ��·�� */
STATUS BrdGetAllIpRoute(TBrdAllIpRouteInfo *ptBrdAllIpRouteInfo);/* ��ȡ����·����Ϣ */
STATUS BrdSaveNipConfig(void);/* ����nip�����������ļ� */
STATUS BrdGetMemInfo(UINT32 *pdwByteFree, UINT32 *pdwByteAlloc);/* ��ѯ��ǰ�ڴ�ʹ����Ϣ */
/*--------------------------------------------------------------------------*/

/*--------------------E1��·NIP��װ�ӿ���ؽṹ����---------------------------*/
STATUS BrdOpenE1SingleLinkChan(UINT32 dwChanID, TBrdE1SingleLinkChanInfo *ptChanParam);  /* ����һ��E1����·����ͨ����dwChanID��Χ0~E1_SINGLE_LINK_CHAN_MAX_NUM-1 */
STATUS BrdOpenE1MultiLinkChan(UINT32 dwChanID, TBrdE1MultiLinkChanInfo *ptChanParam);    /* ����һ��E1����·��������ͨ����dwChanID��Χ0~E1_MULTI_LINK_CHAN_MAX_NUM-1 */
STATUS BrdCloseE1SingleLinkChan(UINT32 dwChanID); /* �ر�ָ����E1����·����ͨ����dwChanID��Χ0~dwSingleLinkChanNum-1 */
STATUS BrdCloseE1MultiLinkChan(UINT32 dwChanID);  /* �ر�ָ����E1����·��������ͨ����dwChanID��Χ0~dwMultiLinkChanNum-1 */
STATUS BrdGetE1SingleLinkChanInfo(UINT32 dwChanID, TBrdE1SingleLinkChanInfo *ptChanInfo);/* ��ȡָ����E1����·����ͨ����Ϣ��dwChanID��Χ0~dwSingleLinkChanNum-1 */
STATUS BrdGetE1MultiLinkChanInfo(UINT32 dwChanID, TBrdE1MultiLinkChanInfo *ptChanInfo);  /* ��ȡָ����E1����·��������ͨ����Ϣ��dwChanID��Χ0~dwSingleLinkChanNum-1 */
/*--------------------------------------------------------------------------*/

UINT32 BrdChkOneIpStatus(UINT32 dwIpAdrs);      /* ���ָ��ip�������е�״̬ */
BOOL   BrdLineIsLoop(UINT32 *pdwIpAddr);        /* ��鵱ǰE1��·�Ի�״̬ */
void   BrdEthSndBusyCallBackReg(UINT32 dwUsrArg, TEthSndBusyCallBack ptEthSndBusyCallBack);
BOOL   BrdEthSndUseTimer(void); /* ��ѯ�Ƿ�ʹ�ö�ʱ������̫������ */
STATUS BrdSetEthBautRate(UINT8 byUnit, UINT32 dwBautRate, UINT32 dwSmoothRate);
STATUS BrdMoveEthBautRate(UINT8 byUnit, UINT32 dwBautRate);
STATUS BrdAddEthBautRate(UINT8 byUnit, UINT32 dwBautRate);
STATUS BrdSetEthSpeedLimit(UINT8 byUnit, UINT32 dwLstBautRate,UINT32 dwHstBautRate);
UINT8  BrdGetEthActLnkStat(UINT8 byEthID);

STATUS BrdGetAlarmInput(UINT8 byPort, UINT8* pbyState);/* ��ȡ�ֳ��澯(KDM2400/2500ר��) */
STATUS BrdSetAlarmOutput(UINT8 byPort, UINT8  byState);/* ����ֳ��澯(KDM2400/2500ר��) */
INT32  BrdOpenSerial(UINT8 byPort);/* �ṩ��ҵ���3.0�汾�Ĵ�Rs232 Rs422 Rs485����  */ 
INT32  BrdCloseSerial(INT32 nFd);
INT32  BrdReadSerial(INT32 nFd, INT8 *pbyBuf, INT32 nMaxbytes);
INT32  BrdWriteSerial (INT32 nFd, INT8 *pbyBuf, INT32 nBytes);
INT32  BrdIoctlSerial (INT32 nFd, INT32 nFunction, INT32 nArg);
INT32  BrdRs485TransSnd(INT32 nFd, UINT8 *pbyMsg, UINT32 dwMsgLen);
INT32  BrdRs485QueryData(INT32 nFd, TRS485InParam *ptRS485InParam, TRS485RtnData *ptRS485RtnData);

BOOL BrdGetEthMacAddrFromRom(UINT8 byEthId, UINT8 *pbyMacAddr);/* ��ROM�л�ȡָ����̫����MAC��ַ */

STATUS BrdIpConflictCallBackReg (TIpConflictCallBack ptFunc); /* ע��ip��ַ��ͻʱ�ص����� */
BOOL   BrdIpOnceConflicted (void);    /* ��ѯϵͳ�Ƿ�����ip��ַ��ͻ */

INT32  BrdGetPowerVoltage(UINT32 dwSampleTimes); /* ��ȡ��ǰ��ѹֵ���Ժ���Ϊ��λ */
STATUS BrdShutoffPower(void);                   /* �رյ�Դ��Ӧ */
UINT8  BrdGetSwitchSel(void);         /* ��ȡ����ѡ���״̬, Ŀǰ����kdv8008˫���� */
UINT8  SysGetIdlePercent(void);       /* ��ѯ��ǰcpu�Ŀ��аٷֱ� */
#endif  /* end #ifndef WIN32 */


/* ===========���д�BSP15оƬ�ĵ��幫�������ݽṹ���궨���Լ������ӿ�=========== */
/* BSP15ͼ��ɼ��˿ں궨�� */
#define BSP15_VCAPTURE_FROM_NONE   0       /* video capture from port NULL */
#define BSP15_VCAPTURE_FROM_PORTA  1       /*                    port B    */
#define BSP15_VCAPTURE_FROM_PORTB  2       /*                    port B    */
#define BSP15_VCAPTURE_FROM_PORTAB 3       /*                    port AB   */

/* BSP15ͼ��ɼ�оƬBrdGetCaptureChipType����ֵ�궨�� */
#define CAPTURE_FROM_NONE          0       /* video or audio capture from chip none */
#define CAPTURE_FROM_SAA7114       1       /*                    SAA7114    */
#define CAPTURE_FROM_SAA7113       2       /*                    SAA7113    */
#define CAPTURE_FROM_AL240         3       /*                    AL240    */

/* BSP15�����ɼ�оƬBrdGetAudCapChipType����ֵ�궨�� */
#define CAPTURE_AUDIO_FROM_NONE    0       /* audio capture from chip none  */
#define CAPTURE_AUDIO_FROM_5331    1       /* audio capture from chip 5331  */
#define CAPTURE_AUDIO_FROM_AIC23B  2       /*                        AIC23B */
#define CAPTURE_AUDIO_FROM_CS5340  3       /*                        CS5340 */

/* SAA7114ͼ����������˿ں궨�� */
#define SAA7114_OUTPORT_NONE       0       /* SAA7114 vedio output port NULL */
#define SAA7114_OUTPORT_X          1       /*                      port X    */
#define SAA7114_OUTPORT_I          2       /*                      port I    */
#define SAA7114_OUTPORT_XI         3       /*                      port XI   */

/* VGA����������õĺ궨�� */
#define BSP15_VGA_NONE             0       /* vga����������ܾ�û�� */
#define BSP15_VGA_IN               1       /* ֻ��vga���빦�� */
#define BSP15_VGA_OUT              2       /* ֻ��vga������� */
#define BSP15_VGA_INOUT            3       /* vga����������ܶ��� */

/* VGA����ģʽ�궨�� */
#define VGAMODE_SVGA_60HZ  0               /* �ֱ���800x600  ˢ����60Hz */
#define VGAMODE_SVGA_75HZ  1               /* �ֱ���800x600  ˢ����75Hz */
#define VGAMODE_SVGA_85HZ  2               /* �ֱ���800x600  ˢ����85Hz */
#define VGAMODE_VGA_60HZ   3               /* �ֱ���640x480  ˢ����60Hz */
#define VGAMODE_VGA_75HZ   4               /* �ֱ���640x480  ˢ����75Hz */
#define VGAMODE_VGA_85HZ   5               /* �ֱ���640x480  ˢ����85Hz */
#define VGAMODE_XGA_60HZ   6               /* �ֱ���1024x768 ˢ����60Hz */
#define VGAMODE_XGA_75HZ   7               /* �ֱ���1024x768 ˢ����75Hz */

/* Ӳ����11��kdv8010aר�õ�gpioģʽ��BrdSetBsp15GPIOMode�� */
#define BSP_GPIO_MODE_1TO2  (0x00)  /* ����BSP15����Ƶ
                        ��������ӵ�����BSP15��GPIO�ڣ�ͬʱVGA�����BSP15����Ƶ
                        ��������ӵ�SAA7121����Ƶ�����,���Ե�11��kdv8010a��Ч */
#define BSP_GPIO_MODE_3TO2  (0x01)  /* VGA�����BSP15��
                        ��Ƶ��������ӵ�����BSP15��GPIO�� */

#ifndef WIN32
UINT8  BrdGetBSP15CapturePort(UINT8 byBSP15ID);  /* BSP15ͼ��ɼ��˿ڲ�ѯ */
UINT8  BrdGetSAA7114OutPort(UINT8 byBSP15ID);    /* SAA7114ͼ������˿ڲ�ѯ */
UINT8  BrdGetCaptureChipType(UINT8 byBSP15ID);   /* BSP15ͼ��ɼ�оƬ��ѯ */
UINT8  BrdGetAudCapChipType(UINT8 byBSP15ID);    /* BSP15��Ƶ�ɼ�оƬ��ѯ */
UINT32 BrdBsp15GpdpIsUsed(void);                 /* ��ѯ��ЩBSP15��gpdp�˿ڻ������� */
void   BrdSetBsp15GPIOMode(UINT8 byMode);        /* GPIO�����л������ź�,���Ե�11��kdv8010a��Ч */
UINT8  BrdGetBSP15Speed(UINT8 byDevId);          /* ȡָ��bsp15���ں˺��ڴ�Ƶ�� */
UINT8  BrdGetBSP15SdramSize(UINT8 byDevId);      /* ȡָ��bsp15���ڴ��С */   
UINT8  BrdFastLoadEqtFileIsEn(void);             /* �Ƿ��������װ��BSP15�Ŀ�ִ���ļ� */
UINT8  BrdBsp15LedFlashMode(void);               /* �ṩ��cci������BSP15�ĵ�Ƶ�ѡ������ */
UINT8  BrdGetBSP15VGAConf(UINT8 byDevId);        /* ��ȡָ��bsp15��vga���� */
void   BrdStopVGACap(void);                      /* ֹͣ�ɼ�vga(8083)����(����fpga) */
void   BrdStartVGACap(UINT8 byMode);             /* ��ʼ�ɼ�vga(8083)����(����fpga) */
void   BrdSetVGACapMode(UINT8 byMode);           /* ����fpga��VGA�ɼ���ģʽ(����fpga) */
void   BrdCloseVGA(void);                        /* �رղ���ֹvga(8083)�ɼ�оƬ���� */
void   BrdOpenVGA(void);                         /* �򿪲�����vga(8083)�ɼ�оƬ���� */
void   BrdMapDevOpenPreInit(UINT8 byBSP15ID);    /* ��map����ʱ�����Ӳ���ĳ�ʼ�� */
void   BrdMapDevClosePreInit(UINT8 byBSP15ID);   /* ��map�ر�ʱ�����Ӳ���ĳ�ʼ�� */

#endif /* end #ifndef WIN32 */

/*================ ���д�E1�ĵ��幫�������ݽṹ���궨���Լ������ӿ�=======================*/
/* E1�迹ֵ */
#define E1_75_OHM                   0      /* E1ģ���迹Ϊ75  ohm */
#define E1_120_OHM                  1      /* E1ģ���迹Ϊ120 ohm */
#define E1_ERR_OHM                  0xff   /* E1ģ���迹�޷�ʶ�� */

/* ��ͬ��ʱ���ź�������� */
#define E1_CLK_OUTPUT_DISABLE       0     /* �����ֹ�����ϲο�ʱ���ź������MPC���� */
#define E1_CLK_OUTPUT_ENABLE        1     /* ��������ϲο�ʱ���ź������MPC���� */

/* �̵�������ģʽ���� */
#define BRD_RELAY_MODE_NORMAL        0     /* �̵�����ͨ */
#define BRD_RELAY_MODE_LOCLOOP       1     /* �̵����Ի� */
#define BRD_RELAY_MODE_OUTLOOP       2     /* �̵����⻷ */

/* ���������E1���� */
#define BRD_E1_MAXNUM                16    /* һ���豸�����16��E1����ӿ� */
#define BRD_DRI_E1_MAXNUM            8     /* DRI����8��E1��· */
#define BRD_DSI_E1_MAXNUM            4     /* DSI����4��E1��· */
#define BRD_MT_E1_MAXNUM             4     /* KDV8010����4��E1��· */
#define BRD_DRI16_E1_MAXNUM          16    /* DRI16����16��E1��· */
#define BRD_16E1_E1_MAXNUM           16    /* 16E1����16��E1��· */
#define BRD_KDV8003_E1_MAXNUM        1     /* kdv8003����1��E1��· */
#define BRD_KDM2000_E1_MAXNUM        1     /* kdm2000�����1��E1��· */

#ifndef WIN32
UINT8  BrdGetE1MaxNum(void);                              /* ��ѯ�豸�������õ�e1���� */
STATUS BrdSetE1SyncClkOutputState (UINT8 mode);           /* ����E1��·ʱ���Ƿ������MPC�����ͬ�� */
STATUS BrdSetE1RelayLoopMode(UINT8 byE1ID, UINT8 mode);   /* E1��·���ü̵������أ��ڻ����⻷�� */
STATUS BrdSelectE1NetSyncClk(UINT8 byE1ID);               /* ��ͬ���ο�ʱ�����ѡ�� */
UINT8  BrdQueryE1Imp(UINT8 byE1ID);                       /* ��ȡe1�迹ֵ */
UINT8  BrdGetE1AlmState(UINT8 byE1Id);                    /* ��ȡָ��E1��·�ĸ澯״̬������0Ϊ��������0�и澯 */
#endif /* end #ifndef WIN32 */


/*============ ���д�����Ƶ����ĵ��幫�������ݽṹ���궨���Լ������ӿ�============*/
#define  MATRIX_OUTPUT_DISABLE  0xfb        /* ��ֹ����Ƶ����ĳ����˿� */
#define  MATRIX_OUTPUT_ENABLE   0xfc        /* ��������Ƶ����ĳ����˿� */

#ifndef WIN32
void  BrdVideoMatrixSet(UINT8 vedioInSelect, UINT8 vedioOutSelect); /* ������Ƶ���� */
void  BrdAudioMatrixSet(UINT8 audioInSelect, UINT8 audioOutSelect);  /* ������Ƶ���� */
#endif /* end #ifndef WIN32 */


/* ============================ MPC����صĺ궨�� ============================ */
/* �Զ�����������Ƿ���λ�궨�� */
#define BRD_MPC_IN_POSITION         0      /* �Զ������������λ  */
#define BRD_MPC_OUTOF_POSITION      1      /* �Զ���������岻��λ */

/* ��ǰ���������������״̬ */
#define BRD_MPC_RUN_MASTER          0      /* ��ǰ������������� */
#define BRD_MPC_RUN_SLAVE           1      /* ��ǰ��������屸��  */

/* ��ģ������ */
#define BRD_MPC_SDHMODULE_NONE      0x07   /* ��ǰ���������û�в�ģ�� */
#define BRD_MPC_SDHMODULE_SOI1      0x00   /* ��ǰ����������ģ��SOI1 */
#define BRD_MPC_SDHMODULE_SOI4      0x01   /* ��ǰ����������ģ��SOI4  */

/* ���໷����ģʽ */
#define SYNC_MODE_FREERUN           0      /* �����񵴣�������MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ�� */
#define SYNC_MODE_TRACK_SDH8K       1      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����8Kʱ�� */
#define SYNC_MODE_TRACK_SDH2M       2      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������SDH����2Mʱ�� */
#define SYNC_MODE_TRACK_DT2M        4      /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT����2Mʱ�� */
#define SYNC_MODE_UNKNOWN           0xff   /* δ֪������ģʽ */

/* KDV8000�������������غ궨�� */
#define LED_BOARD_SPK_OFF           0x00   /* �ر������� */
#define LED_BOARD_SPK_ON            0x01   /* ���������� */

/* ============================ CRI����صĺ궨�� ============================ */
#define OS_CRI_FOR_MP               0
#define OS_CRI_FOR_GK               1

/* ============================ VAS����صĺ궨�� ============================ */
#define  VAS_MATRIX_16X16           0        /* 16X16�ľ���� */
#define  VAS_MATRIX_08X08           8        /*   8X8�ľ���� */

/* ============================ DRI����صĺ궨�� ============================ */

/* ============================ MMP����صĺ궨�� ============================ */

/*==============================IMT����صĺ궨��====================================*/

/* ============================ DSI����صĺ궨�� ============================ */

/* ============================ KDV8000B����صĺ궨�� ============================ */

/*==============================KDV8010����صĺ궨��====================================*/
/* ģ��궨�� */
#define KDV8010A_MODULE_E1          0        /* ���ģ��Ϊ: ��E1ģ��   */
#define KDV8010A_MODULE_4E1         1        /* ���ģ��Ϊ: 4E1ģ��    */
#define KDV8010A_MODULE_V35DTE      2        /* ���ģ��Ϊ: V35DTEģ�� */
#define KDV8010A_MODULE_V35DCE      3        /* ���ģ��Ϊ: V35DCEģ�� */
#define KDV8010A_MODULE_BRIDGE      4        /* ���ģ��Ϊ: ����ģ��   */
#define KDV8010A_MODULE_2E1         5        /* ���ģ��Ϊ: 2E1ģ��    */
#define KDV8010A_MODULE_KDV8000B    6        /* ���ģ��Ϊ: KDV8000Bģ��    */
#define KDV8010A_MODULE_DSC         0xc      /* ���ģ��Ϊ: DSC(ͬKDV8000B)ģ�� */
#define KDV8010A_NO_MODULE          0xf      /* û�����ģ��  */

/* 485״̬��غ궨�� */
#define RS485_SUCCESS                     0    /* �����ɹ� */
#define RS485_NOT_OPENED                  1    /* RS485����û�д� */
#define RS485_NOT_CONNECTED               2    /* RS485�豸û������ */
#define RS485_SND_TIMEOUT                 3    /* RS485���Ͳ�����ʱ */
#define RS485_RCV_TIMEOUT                 4    /* RS485���ղ�����ʱ */
#define RS485_RCV_LENERR                  5    /* RS485���յ����ݳ��ȴ� */
#define RS485_RCV_ERRDATA                 6    /* RS485���յĴ�� */
#define RS485_ERROR                      -1    /* �������� */


#define RS485_SET_BAUDRATE      0   /* ����485���ڵĲ����� */
#define RS485_GET_BAUDRATE      1   /* ��ѯ485���ڵĲ����� */
#define RS485_SET_STOPBIT       2   /* ����485���ڵ�ֹͣλ */
#define RS485_GET_STOPBIT       3   /* ��ѯ485���ڵ�ֹͣλ */
#define RS485_SET_SND_TIMEOUT   4   /* ����485���ڲ����ķ��ͳ�ʱֵ */
#define RS485_GET_SND_TIMEOUT   5   /* ��ѯ485���ڲ����ķ��ͳ�ʱֵ */
#define RS485_SET_PARITY        6   /* ���ô��ڵ���żУ��λ */
#define RS485_GET_PARITY        7   /* ��ѯ���ڵ���żУ��λ */

#define RS485_PARITY_NONE       0   /* ��������żУ��λ */
#define RS485_PARITY_ODD        1   /* ������У�� */
#define RS485_PARITY_EVEN       2   /* ����żУ�� */
#define RS485_PARITY_MARK       3   /* ���ڱ��У�� */
#define RS485_PARITY_SPACE      4   /* ���ڿո�У�� */

/*������غ궨��*/
#define SIO_SET_BAUDRATE      0x2000   /* ���ô��ڵĲ����� */
#define SIO_GET_BAUDRATE      0x2001   /* ��ѯ���ڵĲ����� */
#define SIO_SET_STOPBIT       0x2002   /* ���ô��ڵ�ֹͣλ */
#define SIO_GET_STOPBIT       0x2003   /* ��ѯ���ڵ�ֹͣλ */
#define SIO_SET_DATABIT       0x2004   /* ���ô��ڵ�����λ */
#define SIO_GET_DATABIT       0x2005   /* ��ѯ���ڵ�����λ */
#define SIO_SET_PARITY        0x2006   /* ���ô��ڵ���żУ��λ */
#define SIO_GET_PARITY        0x2007   /* ��ѯ���ڵ���żУ��λ */
#define SIO_485_SET_SND_TIMEOUT 0x2008   /* ����485���ڲ����ķ��ͳ�ʱֵ */
#define SIO_485_GET_SND_TIMEOUT 0x2009   /* ��ѯ485���ڲ����ķ��ͳ�ʱֵ */

#define SIO_PARITY_NONE       0   /* ��������żУ��λ */
#define SIO_PARITY_ODD        1   /* ������У�� */
#define SIO_PARITY_EVEN       2   /* ����żУ�� */
#define SIO_PARITY_MARK       3   /* ���ڱ��У�� */
#define SIO_PARITY_SPACE      4   /* ���ڿո�У�� */

#define SIO_STOPBIT_1         1   /* ����1λֹͣλ */
#define SIO_STOPBIT_1_5       15  /* ����1.5λֹͣλ */
#define SIO_STOPBIT_2         2   /* ����2λֹͣλ */

/* =485�豸����= */
#define RS485DEV_IRAY           0   /* IRAY�豸 */

/* =����ң��������= */
#define IRAY_CTRL_BLACK         0   /* ��ɫ�ɰ��ң���� */
#define IRAY_CTRL_SILVERY       1   /* ����ɫ�°��ң���� */
#define IRAY_CTRL_UNKNOWN    0xff   /* δ֪��ң���� */

#define IRAY_RCV_NOKEY       0xfe   /* irayû���յ�ң������Ϣ */

#define IRAY_ADDR0           0x02   /* IRAY�豸��ַ1 */
#define IRAY_ADDR1           0x7f   /* IRAY�豸��ַ2 */
#define HOST_485DEV_ADDR     0x01   /* ���豸��ַ */

#define IRAY_CMD_QRY_LNKSTATE   0   /* ��ѯIRAY�豸�Ƿ����� */
#define IRAY_CMD_QRY_KEYCODE    1   /* ��ѯIRAY�豸���յļ��� */

/*==============================KDV8008����صĺ궨��====================================*/
#define DISPLAY_REMOTE_VGA  1   /* VGAѡ���źš�"1"Զ��VGA */
#define DISPLAY_LOCAL_VGA   0   /* VGAѡ���źš�"0"����VGA */

#ifndef WIN32


/* MPC��ĺ������� */
UINT8  BrdMPCQueryAnotherMPCState(void);               /* �Զ�����������Ƿ���λ��ѯ */
UINT8  BrdMPCQueryLocalMSState(void);                  /* ��ǰ���������������״̬��ѯ */
STATUS BrdMPCSetLocalMSState(UINT8 byState);           /* ���õ�ǰ���������������״̬ */
UINT8  BrdMPCQuerySDHType(void);                       /* ��ģ�������ѯ */
UINT8  BrdMPCQueryNetSyncMode(void);                   /* ���໷����ģʽ��ѯ */
STATUS BrdMPCSetNetSyncMode(UINT8 mode);               /* ���໷��ͬ��ģʽѡ������ */
STATUS BrdMPCSetAllNetSyncMode(UINT8 mode, UINT32 dwSdhE1Id);/* ���໷��ͬ��ģʽѡ������,����sdh���� */
STATUS BrdMPCResetSDH(void);                           /* ��ģ�鸴λ */
STATUS BrdMPCReSetAnotherMPC(void);                    /* ��λ�Զ�������� */
STATUS BrdMPCOppReSetDisable (void);                   /* ��ֹ�Զ����������λ��������� */
STATUS BrdMPCOppReSetEnable (void);                    /* ����Զ����������λ��������� */
STATUS BrdMPCLedBoardSpeakerSet(UINT8 state);          /* ����KDV8000�����ϵ������� */

/* CRI��ĺ������� */
UINT8  SysGetOsVer(void);            /* ��ȡOS�汾���ͣ���Ϊ������ͬһ����������в�ͬ��OS */

/* DRI�庯������ */

/* DSI�庯������ */

/* IMT�庯������ */

/* VAS�庯������ */
UINT8 BrdGetMatrixType(void);                                       /* ��������Ͳ�ѯ */

/* KDV8010�庯������ */
UINT8  BrdExtModuleIdentify(void);       /* ���ģ��ʶ���� */

INT32  Rs485Open(UINT8 byComPort);
STATUS Rs485Close(UINT8 byComPort);
STATUS Rs485ioctl(UINT8 byComPort, INT32 function, INT32 arg);
INT32  Rs485QueryData(UINT8 byComPort, TRS485InParam *ptRS485InParam, TRS485RtnData *ptRS485RtnData);
INT32  Rs485TransSnd(UINT8 byComPort, UINT8 *pbyMsg, UINT32 dwMsgLen);

BOOL   BrdMicAdjustIsSupport(void);/* ��ѯ��ǰmic�����Ƿ�֧�� */
STATUS BrdMicVolumeSet
(
    UINT8  byTapPosition   /* ���ף���Χ��0-127,������Ϊ���߼� */
);/* ����mic�������� */

UINT8  BrdMicVolumeGet(void);/* ��ѯ��ǰmic�������� */

#endif /* #ifndef WIN32 */



/**********************************************************************************/
/* ==================== Ϊ�˼���3.0��ǰ�汾���ұ������Ժ���Ҫɾ�� ====================*/
#define BRD_CRI_MODULE_OFF          0
#define BRD_CRI_MODULE_ON           1
#define BRD_CRI_MLNK_LED            0          /* CRI��mlink�Ƶı�� */

#define BRD_VAS_MLINK_LED           2          /* VAS��mlink�Ƶı�� */
#define VAS_MATRIX_OUTPUT_DISABLE  0xfb        /* ��ֹ����Ƶ����ĳ����˿� */
#define VAS_MATRIX_OUTPUT_ENABLE   0xfc        /* ��������Ƶ����ĳ����˿� */

#define BRD_DRI_CLK_OUTPUT_DISABLE   0   /* �����ֹDRI����ʱ���ź������MPC���� */
#define BRD_DRI_CLK_OUTPUT_ENABLE    1   /* ����DRI����ʱ���ź������MPC���� */

#define BRD_DRI_RELAY_LOOP_DISABLE   0  /* �̵�����ͨ */
#define BRD_DRI_RELAY_LOOP_ENABLE    1  /* �̵����Ի� */

#define BRD_DRI_E1CHAIN_DISABLE      0  /* ����ĳ��E1��· */
#define BRD_DRI_E1CHAIN_ENABLE       1  /* ʹ��ĳ��E1��· */

#define BRD_MMP_MLINK_LED                    7   /* MMP��mlink�Ƶı�� */

#define BRD_DSI_CLK_OUTPUT_DISABLE   0   /* �����ֹDSI����ʱ���ź������MPC���� */
#define BRD_DSI_CLK_OUTPUT_ENABLE    1   /* ����DSI����ʱ���ź������MPC���� */
#define BRD_DSI_RELAY_SWITCH_IN      1  /* �̵��������������ָ��E1�л���8260 */
#define BRD_DSI_RELAY_SWITCH_OUT     0  /* �̵��������������ָ��E1�л���������Ӧ��E1��� */
#define BRD_DSI_MLINK_LED            9   /* dsi��mlink�Ƶı�� */

#define UNCOMPRESS_FILE             0      /* ����δѹ�����ļ���һ����.out��β,�����Ϻ��� */ 
#define COMPRESS_FILE               1      /* ����ѹ�����ļ���һ����.z��β,�����Ϻ��� */ 

/* �����豸����netEquipUnit�궨�� */
#define NETEQUIP_IS_ETH1    1    /* ��̫��1�� ��Ӧ8265��FCC2 �� x86�ϵ��������� */
#define NETEQUIP_IS_ETH2    2    /* ��̫��2�� ��Ӧ8265��FCC1 �� x86�ϵ���������*/
#define NETEQUIP_IS_ETH3    3    /* ��̫��3�� ��Ӧ8265��SCC1 */
#define NETEQUIP_IS_IPOH    4    /* IPOH  ��  ��Ӧ8265��MCC1 */

#define BOARD_VERSION         ((UINT8)0x00)
#define EPLD_VERSION          ((UINT8)0x01)

/* ��ƵԴ���궨�� */  
#define VIDEOIN_CHKERROR   -1   /* ��Ƶ����оƬMAP[1]û�д������������� */
#define VIDEOIN_OFF         0   /* ��ѡ���������ƵԴ���ź� */
#define VIDEOIN_ON          1   /* ��ѡ���������ƵԴ���ź� */


#define IMT_DSP1FAN      0         /* ͼ�������� */
#define IMT_DSP2FAN      1         /* ͼ�������� */
#define IMT_DSP3FAN      2         /* ��Ƶ�������� */


/* �����궨�� */
#define KDV8010A_WAKEUP       0         /* ����ϵͳ */
#define KDV8010A_SLEEP        1         /* ����ϵͳ */

/* ��Ƶ�л�����ģ������ */
#define KDV8010_MATRIX_OUTPUT_DISABLE      ((UINT8)0xfb)        /* ��ֹ����Ƶ����ĳ����˿� */
#define KDV8010_MATRIX_OUTPUT_ENABLE       ((UINT8)0xfc)        /* ��������Ƶ����ĳ����˿� */


/* Ϊ�˼���3.0��ǰ�汾���ұ������Ժ���Ҫɾ�� */
#define KDV8010A_E1_75   0              /* E1ģ���迹Ϊ75  ohm */
#define KDV8010A_E1_120  0x40           /* E1ģ���迹Ϊ120 ohm */

/*==============================��ͬ��=============================*/  
/* ͬ��ģʽ�궨�� */
#define SYNC_MODE_TRACK_2M_SLAVE  4   /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT���Ĵ�2Mʱ�� */

#define SYNC_CLOCK_UNLOCK                0          /* ����ģʽʱʱ��δ���� */
#define SYNC_CLOCK_LOCK                  1          /* ����ģʽʱʱ�������ɹ� */

#ifndef WIN32

/* �ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmE1RUA1;     /* E1ȫ1�澯 */
    BOOL bAlarmE1RLOS;     /* E1ʧͬ���澯 */
    BOOL bAlarmE1RRA;      /* E1Զ�˸澯 */
    BOOL bAlarmE1RCL;      /* E1ʧ�ز��澯 */
}TBrdE1AlarmDescOld;

typedef struct{
    TBrdE1AlarmDesc tBrdE1AlarmDesc[8]; 
}TBrdAllE1Alarm;


/* �ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmEth1LnkDown;     /* ��̫��1������ */
    BOOL bAlarmEth2LnkDown;     /* ��̫��2������ */
    BOOL bAlarmEth3LnkDown;     /* ��̫��3������ */

    BOOL bAlarmDSP1FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP2FanStop;     /* ͼ��������ͣת */
    BOOL bAlarmDSP3FanStop;     /* ��Ƶ��������ͣת */
    BOOL bAlarmSYS1FanStop;     /* �������1ͣת */
    BOOL bAlarmSYS2FanStop;     /* �������2ͣת */

    TBrdE1AlarmDescOld tBrdE1AlarmDesc[4];     /* E1�澯 */

    TBrdV35AlarmDesc tBrdV35AlarmDesc;    /* V.35�澯 */
}TBrdMTAlarmAllOld;


/* �ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDescOld tBrdE1Alarm;     /* E1�澯 */
}TBrdSMTAlarmAllOld;


STATUS BrdDrvLibInit(void);
STATUS BrdLedFlash(UINT8 byLedID, UINT8 byState);      /* ����ƿ��� */
STATUS BrdMPCAlarmVeneerStateScan(TBrdMPCAlarmVeneer *pTBrdMPCAlarmVeneer); /* MPC����澯�������� */
STATUS BrdMPCAlarmSDHStateScan(TBrdMPCAlarmSDH *pTBrdMPCAlarmSDH);          /* MPC SDH�澯�������� */
STATUS BrdMPCQueryLedState(TBrdMPCLedStateDesc *ptBrdMPCLedState);  /* ����ģʽ��ѯ */
void   BrdMpcWatchdogMode(UINT8 data);
void   BrdMpcFeedDog(void);
STATUS BrdMPCLedBoardLedSet(UINT8 LedID, UINT8 state); /* ����KDV8000�����ϵ�ָʾ�� */
STATUS BrdCRIAlarmVeneerStateScan(TBrdCRIAlarmVeneer *pTBrdCRIAlarmVeneer); /* CRI ����澯�������� */
STATUS BrdCRIQueryLedState(TBrdCRILedStateDesc *ptBrdCRILedState);  /* ����ģʽ��ѯ */
STATUS BrdDRISetE1ChainMode(UINT8 byE1ID, UINT8 mode);          /* E1��·ʹ�ÿ������� */
STATUS BrdDRISetRelayLoop(UINT8 byE1ID, UINT8 mode);            /* E1��·���ü̵������أ��ڻ��� */
STATUS BrdDRISelectNetSyncClk(UINT8 byE1ID);                    /* DRI����ͬ���ο�ʱ�����ѡ�� */
STATUS BrdDRISetNetSyncMode(UINT8 mode);                        /* DRI����ͬ��ʱ��������� */
STATUS BrdDRIQueryLedState(TBrdDRILedStateDesc *ptBrdDRILedState);  /* ����ģʽ��ѯ */
STATUS BrdDRIAlarmE1StateScan(TBrdAllE1Alarm *ptBrdAllE1Alarm); /* DRI��·�澯�������� */
STATUS BrdDSISetRelayMode(UINT8 byE1ID, UINT8 mode);            /* E1��·���ü̵���ģʽ */
STATUS BrdDSISelectNetSyncClk(UINT8 byE1ID);                    /* DSI����ͬ���ο�ʱ�����ѡ�� */
STATUS BrdDSISetNetSyncMode(UINT8 mode);                        /* DSI����ͬ��ʱ��������� */
STATUS BrdDSIAlarmE1StateScan(TBrdAllE1Alarm *ptBrdAllE1Alarm); /* DSI��·�澯�������� */
STATUS BrdDSIQueryLedState(TBrdDSILedStateDesc *ptBrdDSILedState);  /* ����ģʽ��ѯ */
STATUS BrdIMTQueryLedState(TBrdIMTLedStateDesc *ptBrdIMTLedState);
STATUS BrdKDV8000BQueryLedState(TBrdDSCLedStateDesc *ptBrdKDV8000BLedState);  /* ����ģʽ��ѯ */
STATUS BrdMMPQueryLedState(TBrdMMPLedStateDesc *ptBrdMMPLedStateDesc);
STATUS BrdVASQueryLedState(TBrdVASLedStateDesc *ptBrdVASLedStateDesc);
STATUS BrdRunStatSet(UINT8 state);                               /* �豸�������� */
STATUS BrdMTAlarmStateScan(TBrdMTAlarmAllOld *ptBrdMTAlarmAll);  /* �ײ�澯��Ϣɨ�� */
STATUS BrdMTQueryLedState(TBrdMTLedStateDesc *ptBrdMTLedState);   /* ����״̬��ȡ */
STATUS BrdVersionGet(UINT8 module, UINT8 *pVersion);            /* �ײ�Ӳ���汾��Ϣ */  
STATUS BrdSMTQueryLedState(TBrdSMTLedStateDesc *ptBrdSMTLedState);   /* ����״̬��ȡ */
STATUS BrdSMTAlarmStateScan(TBrdSMTAlarmAllOld *ptBrdSMTAlarmAll);
STATUS sysRebootHookAdd(VOIDFUNCPTR rebootHook);
STATUS SysSetUsrAppParam(char *pFileName, UINT8 byFileType, char *pAutoRunFunc);/* �û����������������� */


#endif  /* END #ifndef WIN32 */



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif   /*INCDriverInith*/
