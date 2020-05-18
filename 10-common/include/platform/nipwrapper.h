/******************************************************************************
ģ����	: nipwrapper
�ļ���	: nipwrapper.h
����    : NIPWRAPPER���ͷ�ļ�
�汾	��1.1
******************************************************************************/

#ifndef _NIP_WRAPPER_H
#define _NIP_WRAPPER_H


/*****************************************************************
	Common header files
******************************************************************/

#include "kdvtype.h"
#include "nipwrapperdef.h"
#include "brdwrapper.h"
#include "boarddhcp.h"
#include "boardsntp.h"
#include "atadrvlib.h"
#include "boardwebs.h"

//#ifndef _DAVINCI_
#include "pppoemodule.h"
//#endif

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*��غ궨��*/

/*errno define*/

#define BRD_API_ARGV_ERROR 					101		//��Ч���� 
#define BRD_API_COMM_ERROR 					102		//ͨ��ʧ�� 
#define BRD_API_IF_NOT_EXIST 				103		//�ӿڲ����� 
#define BRD_API_IF_ADDR_NOT_EXIST           104     //��ַ������ 
#define BRD_API_IF_MALFORMED_ERROR 			105		//��Ч�ĵ�ַ��ʽ
#define BRD_API_IF_HIGHEST_ADDR_ERROR		106		//����ֽڲ���Ϊ0 or 127
#define	BRD_API_IF_PREFIX_IS_ZERO 			107 	//MASK LEN ����Ϊ0
#define BRD_API_IF_ADDR_IS_MULTI  			108 	//����ֽ�ҪС��244
#define BRD_API_IF_CONFILICT_WITH_LOOPBACK  109		//��ַ��ػ���ַ��ͻ
#define BRD_API_IF_PREFIX_LEN_ERROR			110 	//MASK LEN ����Ϊ32 or 31
#define BRD_API_IF_PREFIX_ERROR				111 	//MASK����Ϊ�����ַ�͹㲥��ַ
#define BRD_API_IF_CONFLICT_WITH_OTHER		112 	//��ַ������ӿڵ�ַ��ͻ�
#define BRD_API_IF_CONFLICG_ADDR			113		//��ַ�ͱ��ӿڳ�ͻ
#define	BRD_API_IF_NO_MASTER_ADDR 			114		//����ַ������
#define BRD_API_IF_SET_ADRR_ERROR 			115		//����ip��ַʧ��
#define BRD_API_IF_ADDR_NOT_FOUND 			116		//�Ҳ�����ַ
#define BRD_API_IF_DELET_SECOND_ADDR_FIRST	116		//��ɾ����ip֮ǰ��ɾ���ڶ�ip
#define BRD_API_IF_DELET_ADDR_ERROR 		117		//ɾ����ַʧ��
#define BRD_API_IF_NOT_CONF_ADDDR 			119		//�������õĵ�ַ
#define BRD_API_IF_SECOND_REACH_MAX 		120		//�ڶ�ip�ﵽ���
#define BRD_API_IF_ADDR_IS_EXIST 			121		//ip�Ѿ�����
#define NIP_API_ADD_CFG     1                                  // E1��������
#define NIP_API_DEL_CFG     2                                  // E1ɾ������


/*add for username length*/
#define API_BRD_USERNAME_LEN 32

#define BRD_IF_UP				1
#define BRD_IF_DOWN				0

/*�������ӵİ汾�Ŷ���*/
#define VER_MTLinuxOsWrapperForKDV8010A  ( const s8 * )"NipWrapperForKDV8010A 40.01.00.02.061031"
#define VER_LinuxOsWrapperForMDSC        ( const s8 * )"NipWrapperForMDSC 40.01.00.01.061026"
#define VER_LinuxOsWrapperForHDSC        ( const s8 * )"NipWrapperForHDSC 40.01.00.01.061026"
#define VER_LinuxOsWrapperForKDV8010C    ( const s8 * )"NipWrapperForKDV8010C 40.01.00.01.061026"
#define VER_LinuxOsWrapperForKDV8010C1    ( const s8 * )"NipWrapperForKDV8010C1 40.01.00.01.061026"
#define VER_LinuxOsWrapperForCRI         ( const s8 * )"NipWrapperForCRI 40.01.00.01.061026"
#define VER_LinuxOsWrapperForMPC         ( const s8 * )"NipWrapperForMPC 40.01.00.00.061026"
#define VER_LinuxOsWrapperForDRI         ( const s8 * )"NipWrapperForDRI 40.01.00.00.061026"
#define VER_LinuxOsWrapperForAPU         ( const s8 * )"NipWrapperForAPU 40.01.00.00.061026"
#define VER_LinuxOsWrapperForKDM2000PLUS         ( const s8 * )"NipWrapperForKDM2000PLUS 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForKDV8000B  ( const s8 * )"NipWrapperForKDV8000B 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForMMP       ( const s8 * )"NipWrapperForMMP 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForDSC       ( const s8 * )"NipWrapperForDSC 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForKDV8005   ( const s8 * )"NipWrapperForKDV8005 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForDSI       ( const s8 * )"NipWrapperForDSI 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForKDV8003   ( const s8 * )"NipWrapperForKDV8003 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForVAS   ( const s8 * )"NipWrapperForVAS 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperFor16E1   ( const s8 * )"NipWrapperForDRI16 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForKDM2428   ( const s8 * )"NipWrapperForKDM2428 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForVRI   ( const s8 * )"NipWrapperForVRI 40.01.00.00.061026"
#define VER_MTLinuxOsWrapperForKDM2402   ( const s8 * )"NipWrapperForKDM2402 40.01.00.00.070117"
#define VER_MTLinuxOsWrapperForKDV7620   ( const s8 * )"NipWrapperForKDV7620 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForKDV7630   ( const s8 * )"NipWrapperForKDV7630 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForKDV7810   ( const s8 * )"NipWrapperForKDV7810 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForKDV7910   ( const s8 * )"NipWrapperForKDV7910 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForKDV7820   ( const s8 * )"NipWrapperForKDV7820 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForKDV7920   ( const s8 * )"NipWrapperForKDV7920 40.01.00.00.090413"
#define VER_MTLinuxOsWrapperForH600_H      ( const s8 * )"NipWrapperForH600_H 40.01.00.00.111020"
#define VER_MTLinuxOsWrapperForH600_L       ( const s8 * )"NipWrapperForH600_L 40.01.00.00.11120"
#define VER_MTLinuxOsWrapperForH700           ( const s8 * )"NipWrapperForH700 40.01.00.00.111020"
#define VER_MTLinuxOsWrapperForH800           ( const s8 * )"NipWrapperForH800 40.01.00.00.111020"
#define VER_MTLinuxOsWrapperForH900           ( const s8 * )"NipWrapperForH900 40.01.00.00.111020"
#define VER_MTLinuxOsWrapperForT300           ( const s8 * )"NipWrapperForT300 40.01.00.00.111020"


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


/*��̫����صĽṹ����*/
/* ��̫�������ṹ */
typedef struct{
    u32 dwIpAdrs;/*�����ֽ���*/
    u32 dwIpMask; /*�����ֽ���*/
    u8  byMacAdrs[6];
}TBrdEthParam;

/* ��̫��mac��ַ�ṹ*/
typedef struct{
    u8  byMacAdrs[6];
}TBrdEthMac;

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

/* ����E1·�ɲ����ṹ */
typedef struct{
    u32 dwDesIpNet;      /* Ŀ�������������ֽ���	*/
    u32 dwDesIpMask;     /* ���룬�����ֽ���	*/
    u32 dwGwIpAdrs;      /* ����ip��ַ�������ֽ���*/
    u32 dwRoutePri;		/* ·�����ȼ�(1-255)��Ĭ��Ϊ0*/
    char dwIfname[32];    /* ��������ӿ��� */
	u32 dwIfunit;         /* ��������ӿں� */   
}TBrdE1RouteParam;

/*���·�ɲ����ṹ */
typedef struct{
    u32 dwIpRouteNum;    /* �õ���ʵ��·�ɸ��� */
    TBrdIpRouteParam tBrdIpRouteParam[IP_ROUTE_MAX_NUM];
}TBrdAllIpRouteInfo;

/*���E1·�ɲ����ṹ */
typedef struct{
    u32 dwIpRouteNum;    /* �õ���ʵ��·�ɸ��� */
    TBrdE1RouteParam tBrdE1RouteParam[IP_ROUTE_MAX_NUM];
}TBrdAllE1RouteInfo;

/* ��̫��ƽ������æ״̬��Ϣ */
typedef struct{
    BOOL32  bSndBusy;
    u8 byEthId;
}TBrdEthSndBusyParam;

/*��̫��ƽ������æ�ص��������Ͷ���*/
typedef void ( *TEthSndBusyCallBack )(u32 dwUsrArg, TBrdEthSndBusyParam *ptParam);

/*ע���豸�����ص������Ļص���������---VxWorks�ϸú���������ϵͳ����ģ���Linux��Ϊ�˼���VxWorks���صض���ú�������*/
#ifdef _LINUX_
typedef void 		(*VOIDFUNCPTR) (void);	/* pfunction returning void */
#endif

/*��ַ��ͻ�¼����Ͷ���:IP��ַ��ͻ,MAC��ַ��ͻ*/
#define KDC_IP_CONFLICT			1
#define KDC_MAC_CONFLICT			2
/*IP/MAC��ַ��ͻ�ص��������Ͷ���*/
typedef void (*TIpConflictCallBack)(u32 conflictEvent, u8 *pbyMacAddr, u32 dwIpAdrs);

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

typedef struct 
{
	int ifStatus;	// 1 up 0 down
	char ifName[16]; //�ӿ���
}TBrdIfStatusCB;
/*interface status callback definition*/
typedef int(*BrdIfStatusCallBack) (TBrdIfStatusCB  *pMsg);
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
    u32  dwTimeSlotMask;     /* �������ʱ������ʹ��˵��*/
    u16  wBufLength;         /* ��Ϣ������ÿ��buf�ĳ���,��Χ������ĺ궨�壬�ұ�����8�������� */
}TE1TransChanParam;

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
}TE1TransMsgParam;

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
    TBrdDiskInfoDesc atBrdDiskInfo[DISK_MAX_NUMBER];
    u8  byDiskNum;           /* ʵ��flash�̵ĸ��� */
}TBrdAllDiskInfo;

/*BrdPing�ӿڴ�������ṹ��*/
typedef struct{
    s32 nPktSize;/*Ҫping�����ݱ��Ĵ�С�����ֽ�Ϊ��λ*/
    s32 nTimeOut;/*ping�ĳ�ʱֵ������Ϊ��λ*/
    s32 nTtl;/*TTLֵ*/
}TPingOpt;


/*BrdGetDeviceInfo �ӿڴ�������ṹ��*/
typedef struct{
    u32 dwMemSize;/*�����ڴ��С�����ֽ�Ϊ��λ*/
    u32 dwFlashSize;/*FLash��С�����ֽ�Ϊ��λ*/
    u32 dwCpuFreq;/*CPU����Ƶ*/
    u32 dwCpmFreq;/*CPM����Ƶ*/
    u32 dwBusFreq;/*���ߵ���Ƶ*/
    u32 dwEthNum;/*��̫���ĸ���*/
    u32 dwE1Num;/*�豸��ǰ���E1�ĸ���*/
    u32 dwV35Num;/*�豸��ǰ���V35�ĸ���*/
    s8  achCPUInfo[CPU_TYPE_MAX_LEN];/*CPU����*/
    s8  achUBootInfo[UBOOT_VERSION_MAX_LEN];/*u-boot�汾��Ϣ*/
    s8  achKernelInfo[KERNEL_VERSION_MAX_LEN];/*�ں˲���ϵͳ�İ汾��Ϣ*/
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
    BOOL32  bUseDefaultConf;                  /* �Ƿ�ʹ��Ĭ�ϵ����÷ֶ�������Ϣʱ����0����Ч���� */
    TOnePartnParam tOnePartitionParam[PARTITION_MAX_NUM];    /* ÿ��������Ϣ */
    u32 dwRamdiskSize;                   /* RAMDISK �Ĵ�С,�ֽ�Ϊ��λ */
}TFlPartnParam;

/*����û���������Ľṹ��*/
typedef struct
{
    s8 user_name[API_BRD_USERNAME_LEN + 1];
    s8 password[API_BRD_USERNAME_LEN + 1];
}TUserPass;

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
void  BrdQueryNipVersion(s8 *pchVer, u32 dwBufLen);

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
��������BrdQueryNipState
���ܣ�Nip״̬��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵���� ��
����ֵ˵���� �ɹ�����OK,ʧ�ܷ���ERROR
==================================*/
s32  BrdQueryNipState(void);

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
������      : BrdGetUser
����        ����ȡ�û���������
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  tUserPass:����û�������Ľṹ������
                dwArrayLen: ���鳤��
                tUserType���û����ͣ�����صĽṹ�嶨��
����ֵ˵��  ��OK/ERROR
====================================================================*/
STATUS BrdGetUser(TUserPass tUserPass[], s32 dwArrayLen, TUserType tUserType);

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
��������BrdGetEthMac
���ܣ���ȡ��̫��mac��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  u8 byEthId --- ��̫��ID�ţ�0~x��;
                TBrdEthMac *ptBrdEthMac  --- �����̫����Ϣ�Ľṹָ�롣
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdGetEthMac(u8 byEthId, TBrdEthMac *ptBrdEthMac);

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
��������BrdGetEthParamSecIP
���ܣ���ȡһ�����������еڶ�IP��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  u8 byEthId --- ��̫��ID�ţ�0~x��;
                BrdEthParamAll *ptBrdEthParamAll --- �����̫����Ϣ�Ľṹָ�룬�˽ṹ��
                ���ڷ��صڶ�IP��ַ�ģ����صĵ�ַ������dwIpNumָ�����ṹ�е�
                atBrdEthParam�����Աֻ��IP ��Mask��Ч, Mac ��ַû��Ч
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdGetEthParamSecIP(u8 byEthId, TBrdEthParamAll *ptBrdEthParamAll);

/*================================
��������BrdSetEthParam
���ܣ�������̫������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
                byIpOrMac��Ϊ��������ѡ��(��BoardWrapper.h����صĺ궨��),����
                                     ������IP,�ڶ�IP��Mac.
                                       Brd_SET_IP_AND_MASK         1      ����IP��ַ����������
                                       Brd_SET_MAC_ADDR            2       ����MAC��ַ
                                       Brd_SET_ETH_ALL_PARAM       3       ������̫����IP��ַ�����������MAC��ַ
                                       Brd_SET_ETH_SEC_IP         4   ������̫���ڶ�IP ��ַ
                ptBrdEthParam��ָ�����趨ֵ��TbrdEthParam���ݽṹ��ָ��
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdSetEthParam(u8 byEthId, u8 byIpOrMac, TBrdEthParam *ptBrdEthParam);

/*================================
��������BrdDelEthParamSecIP
���ܣ�ɾ���ڶ�IP��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����
                ptBrdEthParam��ָ�����趨ֵ��TbrdEthParam���ݽṹ��ָ��
                                           �ṹ��ֻ��IP�� Mask��Ч.
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdDelEthParamSecIP(u8 byEthId, TBrdEthParam *ptBrdEthParam);


/*================================
��������BrdDelEthParamIPAndMask
���ܣ�ɾ��all IP��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  byEthId����̫���ı�ţ�0 ~ X��X�Ӳ�ͬ���Ӷ�����               
����ֵ˵���� ������ERROR���ɹ�����OK��
==================================*/
STATUS BrdDelEthParamIPAndMask(u8 byEthId);


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
��������BrdGetIfStatus
���ܣ���ȡif ״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byEthId : �ӿڱ��
����ֵ˵���� ����ָ���ӿڵ�״̬

#define IF_UP			0
#define IF_DOWN		1
==================================*/
STATUS BrdGetIfStatus(u32 byEthId);
/*====================================================================
��������BrdSysReboot
���ܣ���������ϵͳ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵����
====================================================================*/
void BrdSysReboot();

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
��������BrdSaveNetConfig
���ܣ�����nip�����������ļ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSaveNetConfig(void);

/*================================
��������BrdIpConflictCallBackReg
���ܣ�ע��IP/MAC��ַ��ͻʱ�ص�����,���豸��IP/MAC��ַ���ⲿ�豸��ͻʱ������øú���֪ͨҵ�����
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
������      : BrdGetUpdateInfo
����        ����ȡ�汾������Ϣ
�㷨ʵ��    �����а忨�϶�֧��
����ȫ�ֱ�����
�������˵������
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetUpdateInfo(s8* pchFilename, s8* pchInfo);

/*================================
������      : BrdCheckUpdatePackage
����        ����֤Ҫ�������ļ�
�㷨ʵ��    �����а忨�϶�֧��
����ȫ�ֱ�����
�������˵����
����ֵ˵��  �����󷵻ش����
                  PID���ʧ�ܣ�CHK_PID_FAILURE
		  ��������   ��ERROR

	      �ɹ�����OK
==================================*/
int BrdCheckUpdatePackage(s8* pchFilename);

/*================================
������      : BrdMSSystemSwitch
����        ���л�����ϵͳ
�㷨ʵ��    �����а忨�϶�֧��
����ȫ�ֱ�����
�������˵����
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/

STATUS BrdMSSystemSwitch(void);

/*================================
������      : BrdSysUpdate
����        ������ϵͳ
�㷨ʵ��    ���������忨��֧��
����ȫ�ֱ�����
�������˵����
����ֵ˵��  ��SYSTEM_UPDATE_SUCCESS                ϵͳ�����ɹ�
              SYSTEM_VERSION_ERROR                 ϵͳ�汾У�����
              SYSTEM_UPDATEVERSION_COMPARE_ERROR   ϵͳ�����ȶ�У�����
==================================*/
u8 BrdSysUpdate(s8* pchFilename);

/*================================
������      : BrdAllSysUpdate
����        ������ϵͳ
�㷨ʵ��    �����еİ忨�϶�֧��
����ȫ�ֱ�����
�������˵����pchFilename : �������ļ���
              upboot��1:update boot
                      0: don't update boot
����ֵ˵��  ��0: update ok
 * 	     -1: error
 *	      1: app update error
 *	      2: os update error
 *	      3: boot update error
 *	      4: set update flag error
==================================*/
s8 BrdAllSysUpdate(s8* pchFilename, s32 upboot);

/*================================
������      : BrdSetSysRunSuccess
����        �����������ɹ���ʶ
�㷨ʵ��    �����а忨�϶�֧��
����ȫ�ֱ�����
�������˵����
����ֵ˵��  ��NO_UPDATE_OPERATION       	0  ��������������������
              UPDATE_VERSION_ROLLBACK	    1  ����ʧ�ܣ��汾�ع���
              UPDATE_VERSION_SUCCESS		2  �����ɹ���Ӧ���°汾�ɹ�
              SET_UPDATE_FLAG_FAILED		-1 ����ʧ��
==================================*/
s8 BrdSetSysRunSuccess(void);


/*Ӳ����Ͻӿڷ�װ����*/

/*================================
��������BrdSetMinUnitCheckable
���ܣ����ÿɼ����С���ݿ��С
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ֻ���������º궨�����С��С���ͣ��������ͷ���FALSE���Ƽ���С��64K�ֽ�Ϊ��λ
              MINSIZE_64K_BYTE  ------   64K
             MINSIZE_128K_BYTE ------   128K
              MINSIZE_512K_BYTE ------   512K
              MINSIZE_1024K_BYTE------   1024K
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdSetMinUnitCheckable(u8 byUnitSizeType);

/*================================
��������BrdGetWriteDataState
���ܣ���ȡд������������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwTotalLen:��д���ļ����Ȼ������ܳ���, dwCompleteLen:��д��flash���ݳ���
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdGetWriteDataState(u32* pdwTotalLen, u32* pdwCompleteLen);

typedef u32 (*FLASHFUNC)(u32*, u32*);
/*================================
��������BrdTestFlashStable
���ܣ�����flash��д�ȶ���   ����ָ��·��д��ָ����С���ļ�������ȡ���ݲ��ж������Ƿ�ΪԤ��
	  ֵ����������ǰ��ɾ�������ļ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����pchFlashPath: ������flash����·��, dwFileSize: �������ļ���С,
              dwRepeatTimes��������дflash����,pvCallbackEntry:�ϲ㴫���ײ���õĺ���ָ��
����ֵ˵���� �ɹ�����TRUE�����򷵻�FALSE
==================================*/
STATUS BrdTestFlashStable(s8* pchFlashPath,u32 dwFileSize, u32 dwRepeatTimes, FLASHFUNC pvCallbackEntry);

typedef struct{
	u32 dwBoudRate;  /*���ڲ����ʣ���Ч��Χ2400��115200������ǰ��ȷ��Ӳ�����֧�ָò����ʡ�*/
	u32 dwDataBits;  /*����λ����ЧֵΪ5��6��7��8*/
	u32 dwStopBits;  /*ֹͣλ����ЧֵΪ1��2*/
	u32 dwParity;    /*����У��ģʽ��0-.-no, 1---odd, 2---even, 3----space, 4----mark ��У�����͡�
						����ǰ��ȷ��Ӳ�����֧�ָ�У��ģʽ��*/
}TSerialAttribte;

/*================================
��������BrdTestUartFun
���ܣ�����ָ���������ô��ڣ�������/����100���ֽڵ����ݡ�
	  ��������Ϊָ���ļ��У����յ������ݽ������/usr/recv�ļ��У�
	  ��������Ա��Զ��豸�Ƚ��շ������Ƿ�һ�¡�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byPort���ڶ˿ں�
              #define SERIAL_RS232                 0
              #define SERIAL_RS422                 1
              #define SERIAL_RS485                 2
              #define BRD_SERIAL_INFRARED          3
			  tSerialAttribte :���ڵ���������
			  pchFileWholeName:�����͵Ĳ����ļ��� �磺/usr/send
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestUartFun(u8 byPort,TSerialAttribte tSerialAttribte,s8* pchFileWholeName);

/*================================
��������BrdChip2Start
���ܣ�ͨ��VLYNQ��UART2����CHIP2���ж�CHIP2�Ƿ�����������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdChip2Start(void);

/*================================
��������BrdTestLedFunc
���ܣ�ͨ��ָ����GPIO��EPLDʹ���д���led���ε���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwTime:��������ʱ�䣬����Ϊ��λ
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestLedFunc(u32 dwTime);

/*================================
��������BrdTestRelayFunc
���ܣ�����GPIO��������Ƽ̵�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestRelayFunc();

/*================================
��������BrdTestEpldFunc
���ܣ���EPLD��ȡ/д��������Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwCmd		��epld�������WRITE_CMD��0��READ_CMD��1
			  dwOffset	����������epld��ַ
			  dwValue	��д��/����������

����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestEpldFunc(u32 dwCmd, u32 dwOffset, s8* pchValue);

/*================================
��������BrdTestWatchdoFunc
���ܣ����ÿ��Ź��������豸��λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestWatchdoFunc();

/*����һЩ�պ���ͷͷ�ļ�,�Լ�������BoardWrapper��ͷ�ļ�*/
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

/*================================
��������SysRebootHookAdd
���ܣ���λ�ص�ע�ắ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ָ��VOIDFUNCPTR���͵ĺ���ָ��
����ֵ˵���� �ɹ�����OK ��ʧ�ܷ���ERROR
==================================*/
STATUS SysRebootHookAdd(VOIDFUNCPTR ptRebootHookFunc);

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
��������BrdGetRouteWayBandwidth
���ܣ���ȡ��E1������·�Ĵ���ֵ����KbpsΪ��λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��·����ֵ����KbpsΪ��λ
==================================*/
u32 BrdGetRouteWayBandwidth(void);

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
������      : BrdNipWrapperGetVersion
����        ����ȡnipwrapper�İ汾��
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����
�������˵����version����ΪNIPWRAPPER_VERSION_LEN���ַ���
����ֵ˵��  ��NULL ��汾��
==================================*/
LPSTR BrdNipWrapperGetVersion(LPSTR version);

/*================================
��������BrdDelE1IntfConf
���ܣ�ɾ��һ��E1�ӿ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwE1Id: E1 �ӿں�
����ֵ˵���� E1_RETURN_OK/ERRCODE
==================================*/
STATUS BrdDelE1IntfConf(u32 dwE1Id);

/*================================
��������BrdSetFtpPortRange
���ܣ�����ftp server��PASVģʽ�´�������ʹ�ö˿ڷ�Χ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����min: ��Сportֵ
					    max: ���portֵ
����ֵ˵����  OK/ERROR
==================================*/
STATUS BrdSetFtpPortRange(u32 dwmin, u32 dwmax);
/*================================
��������BrdEnableFtpd
���ܣ�����ftp ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵����  OK/ERROR
��ע: ���鿪��ftp������ǰ���ж�״̬������ʧ��
==================================*/
STATUS BrdEnableFtpd();
/*================================
��������BrdDisableFtpd
���ܣ��ر�ftp ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵����  OK/ERROR
��ע: ����ر�ftp������ǰ���ж�״̬������ʧ��
==================================*/
STATUS BrdDisableFtpd();
/*================================
��������BrdFtpdStatus
���ܣ���ȡftpd��״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵����  
	1 enable
	0 disable
==================================*/
STATUS BrdFtpdStatus();

/*================================
��������BrdInterfaceShutdown
���ܣ��ر���ѡ�ӿ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ifname:����������("ethernet","fastethernet","gigabitEthernet","serial","loopback","virtual")
					  ifunit :�������				

����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdInterfaceShutdown(char *ifname,int ifunit);

/*================================
��������BrdInterfaceNoShutdown
���ܣ�����ѡ�ӿ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ifname:����������("ethernet","fastethernet","gigabitEthernet","serial","loopback","virtual")
					  ifunit :�������				

����ֵ˵���� OK/ERROR
==================================*/
STATUS BrdInterfaceNoShutdown(char *ifname,int ifunit);

/*================================
��������BrdGetE1Bandwidth
���ܣ���ȡָ��E1�ӿڴ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����ifname: ָ���ӿ����� ifunit:ָ���ӿں�
����ֵ˵���� �ɹ�:dwBandWidth/ʧ��:0
==================================*/
u32 BrdGetE1Bandwidth(char *ifname , int ifunit);

/*================================
��������BrdGetAllE1Route
���ܣ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptBrdAllE1RouteInfo��ָ���ŷ���·����Ϣ��TBrdAllE1RouteInfo�ṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetAllE1Route(TBrdAllE1RouteInfo *ptBrdAllE1RouteInfo);

/*================================
��������BrdE1TransH221Start
���ܣ���ʼE1H221����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ���󷵻�ERROR���ɹ�, ����OK
==================================*/
STATUS BrdE1H221Start(void);

/*================================
��������BrdE1TransH221Stop
���ܣ�ֹͣE1H221����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ���󷵻�ERROR���ɹ�, ����OK
==================================*/
STATUS BrdE1H221Stop(void);

/*================================
��������BrdSetE1H221Inf
���ܣ�����E1H221�Ľӿں�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵��������͸����E1�ӿں�
����ֵ˵���� ���󷵻�ERROR���ɹ�, ����OK
==================================*/
STATUS BrdSetE1H221Inf(int e1);

/*================================
��������BrdUnsetE1H221Inf
���ܣ����E1H221�Ľӿں�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵��������͸����E1�ӿں�
����ֵ˵���� ���󷵻�ERROR���ɹ�, ����OK
==================================*/
STATUS BrdUnsetE1H221Inf(int e1);

/*================================
��������BrdSetE1Clock
���ܣ���ӻ�ɾ��E1��ʱ��ģʽ��dce����dte
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����e1ΪE1�ӿں�
              clockΪ("dce"��"dte")
              cmdΪNIP_API_ADD_CFG����1�����������
              cmdΪNIP_API_DEL_CFG����2����ɾ������
����ֵ˵���� ���󷵻�ERROR���ɹ�, ����OK
==================================*/
STATUS BrdSetE1Clock(int e1,char *clock,int cmd);

/*===============================
��������BrdTelnetOnOffSwitch
����:Telnet���غ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����telSwh = 0 :������ر�telnet  
                     = 1 :��������telnet
����ֵ˵��:      0 : ok
                -1 : error
================================*/
int BrdTelnetOnOffSwitch(unsigned char telSwh);

/*============================
FtpEnable
return OK/ERROR
=============================*/
STATUS BrdEnableFtpd();

/*============================
FtpDisable
return OK/ERROR
=============================*/
STATUS BrdDisableFtpd();

/*============================
FTP state query
return 1 enable
       0 disable
=============================*/
STATUS BrdFtpdStatus();

/*===========================
telnet status query
return 0 enable
      -1 disable
===========================*/
int telnet_status_query();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*_NIP_WRAPPER_H*/
