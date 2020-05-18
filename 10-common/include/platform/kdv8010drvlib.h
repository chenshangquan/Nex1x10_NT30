
#ifndef INCDriverInith
#define INCDriverInith


#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#include "time.h"
#include "timers.h"


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

STATUS BrdTimeGet( struct tm* pGettm );        /* ��ȡRTCʱ�� */
STATUS BrdTimeSet( struct tm* pSettm );        /* ����RTC��ϵͳʱ�� */ 

/*==================================��̫��ģ������===============================*/
/* �����豸����netEquipUnit�궨�� */
#define NETEQUIP_IS_ETH1    1    /* ��̫��1�� ��Ӧ8265��FCC2 �� x86�ϵ��������� */
#define NETEQUIP_IS_ETH2    2    /* ��̫��2�� ��Ӧ8265��FCC1 �� x86�ϵ���������*/
#define NETEQUIP_IS_ETH3    3    /* ��̫��3�� ��Ӧ8265��SCC1 */
#define NETEQUIP_IS_IPOH    4    /* IPOH  ��  ��Ӧ8265��MCC1 */


/*����������IP��ַ��MAC��ַ����������*/
STATUS ethernetSet
    (
    int netEquipUnit,	 /* ���� */
    char *pIpAddrStr,    /* ip��ַ ��:"100.1.1.1" */
    int   netmask  ,     /* �������� ����:0xff000000 ;0 = �Զ�ʶ�� */
    char *pEtherMacAddr  /* mac��ַ��null -> ���ı䵱ǰֵ 
                         ����unsigned char sysFccEnetAddr [6] = {0x08, 0x00, 0x33, 0x02, 0x02, 0x51};*/
    );

/*#ifdef BOARD_KDV8010A*/

/*==============================��Χ�忨ģ�鲿��====================================*/
/* ----------------------------1�� E1��2E1��4E1����--------------------------------
/* ģ��궨�� */
#define KDV8010A_MODULE_E1     0        /* ���ģ��Ϊ: ��E1ģ��   */
#define KDV8010A_MODULE_4E1    1        /* ���ģ��Ϊ: 4E1ģ��    */
#define KDV8010A_MODULE_V35DTE 2        /* ���ģ��Ϊ: V35DTEģ�� */
#define KDV8010A_MODULE_V35DCE 3        /* ���ģ��Ϊ: V35DCEģ�� */
#define KDV8010A_MODULE_BRIDGE 4        /* ���ģ��Ϊ: ����ģ��   */
#define KDV8010A_MODULE_2E1    5        /* ���ģ��Ϊ: 2E1ģ��    */
#define KDV8010A_NO_MODULE     0xf     /* û�����ģ��  */
/* ģ�麯������ */
UINT8 BrdExtModuleIdentify(void);   /* ���ģ��ʶ���� */

/* �迹�궨�� */
#define KDV8010A_E1_75   0              /* E1ģ���迹Ϊ75  ohm */
#define KDV8010A_E1_120  0x40           /* E1ģ���迹Ϊ120 ohm */
/* ģ�麯������ */
UINT8  BrdE1ResGet(UINT8 no);           /* E1ģ���迹ʶ������no = 0~3,�ӵ�ǰʹ�õ�ģ��Ŷ��� 
                                           ����ֵ���Ϻ궨�� */


/* e1ͨ����������,����������ipoh��ip��ַǰ��ɣ�������Ч������������ļ���ȡ��
 * Ŀǰ�ݲ�֧�ֶ�̬���ã�Ҫ�ı�����������ϵͳʹ�øú������� ��
*/
STATUS BrdE1ChanTabSet
    (
    UINT8 e1No,         /* e1�豸��: 0~3,���ڵ�e1ģ��ֻ���e1[0]���� */
    UINT32 e1SlotMask   /* ʱ϶���䣬��Ts31 Ts30...Ts0����32λ���룬TSxΪ1ʱ��ʾʹ�ø�ʱ϶��Ϊ0ʱ��ʹ��
                           Ts0��Ϊͬ���źţ��û�����ʹ�ã�Ts16����Ϊ���ݻ������ϵͳҪ��Ts16�����
                           �û�����ʹ�ã��û�������0��Ts1����ʹ�ã�����ӵ͵�����������ʱ϶����Ҫ������������
                           ����ͨ��ϵͳ���ȶ�����: ʹ��5��ʱ϶ʱe1SlotMask = 0x0000003e,ע��:Ts0=Ts16=0;Ts1=1
                           ��ʱ����= 64x5 = 320kbit */
    );                                  

/* ����ipoh·��,����ipoh��ip ��ַ��������ã������޷�ͨ�� */
STATUS BrdIpohRouteSet
    (
    char *pDevName,     /* always use "ipoh" */
    int unitNo,         /* always use 0 */
    char *pIpDstAddr,   /* �Զ�ipohĿ��ip��ַ,��:"10.1.1.1"������������ļ���ȡ */
    UINT8 mccChanId     /* ��e1ģ��ʹ��1�����ౣ�� */
    );

/*==============================�ײ�澯ģ�鲿��====================================*/
/* �ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmE1RUA1;     /* E1ȫ1�澯 */
    BOOL bAlarmE1RLOS;     /* E1ʧͬ���澯 */
    BOOL bAlarmE1RRA;      /* E1Զ�˸澯 */
    BOOL bAlarmE1RCL;      /* E1ʧ�ز��澯 */
}TBrdE1AlarmDesc;

/* �ײ�V35�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL bAlarmV35CDDown;     /* Carrier Detect, �ز����ʧ�� */
    BOOL bAlarmV35CTSDown;    /* Clear To Send, �������ʧ�� */
    BOOL bAlarmV35RTSDown;    /* Request To Send, ������ʧ�� */
    BOOL bAlarmV35DTRDown;    /* �����ն�δ���� */
    BOOL bAlarmV35DSRDown;    /* ����δ׼���� */
}TBrdV35AlarmDesc;


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

    TBrdE1AlarmDesc tBrdE1AlarmDesc[4];     /* E1�澯 */

    TBrdV35AlarmDesc tBrdV35AlarmDesc;    /* V.35�澯 */
}TBrdMTAlarmAll;

/* ģ�麯������ */
STATUS BrdMTAlarmStateScan(TBrdMTAlarmAll *ptBrdMTAlarmAll);  /* �ײ�澯��Ϣɨ�� */


/*==============================����ģ�鲿��====================================*/
/* ��ָʾ�궨�� */
#define BRD_ALARM_LED    1  /* ϵͳ�澯�ƣ��и澯ʱ�ɵ�õ� */
#define BRD_LINK_LED     9  /* ϵͳ���ӵƣ���MCU������ɵ�õ� */

#define BRD_LED_ON       1  /* �� */
#define BRD_LED_OFF      2  /* �� */
#define BRD_LED_QUICK    3  /* ���� */
#define BRD_LED_SLOW     4  /* ���� */

/* ģ�麯������ */
void BrdMTLedFlash(UINT8 byLedID, UINT8 byState);   /* ���ƿ��� */


/*==============================����ת�ټ��ģ��====================================*/
/* ����ID�궨�� */
#define KDV8010A_DSP1FAN       0         /* ͼ�������� */
#define KDV8010A_DSP2FAN       1         /* ͼ�������� */
#define KDV8010A_DSP3FAN       2         /* ��Ƶ�������� */
#define KDV8010A_SYS1FAN       3         /* �������1 */
#define KDV8010A_SYS2FAN       4         /* �������2 */

/* ģ�麯������ */
UINT32 BrdFanSpeedGet(UINT8 fanID); /* ����ת�ټ�� */


/*==============================����ģ������====================================*/
/* �����궨�� */
#define KDV8010A_WAKEUP       0         /* ����ϵͳ */
#define KDV8010A_SLEEP        1         /* ����ϵͳ */

/* ģ�麯������ */
STATUS BrdRunStatSet(UINT8 state);      /* state���� */

/*==============================��Ƶ�л�����ģ������=============================*/
/* �궨�� */
#define KDV8010_MATRIX_OUTPUT_DISABLE      ((UINT8)0xfb)        /* ��ֹ����Ƶ����ĳ����˿� */
#define KDV8010_MATRIX_OUTPUT_ENABLE       ((UINT8)0xfc)        /* ��������Ƶ����ĳ����˿� */

/* ģ�麯������ */
void BrdVideoMatrixSet
    (
    UINT8 vedioInSelect,    /* ��Ƶ����Դѡ��1~7 = 7����Ƶ����ӿڣ�1������Ӳ���ڲ�
                                              �ѽ���������ͼ�񣬶������Ρ�
                                              ������Ӧ�������ʹ�����涨��ĺ� */
    UINT8 vedioOutSelect   /* ��Ƶ����˿�ѡ��1~7 = 7����Ƶ����ӿڣ�1�����Ӳ���ڲ�
                                              �ѽ�����������Դ���������Ρ����ౣ����*/
    );


/*==============================�ײ�Ӳ���汾��Ϣ=============================*/  
#define BOARD_VERSION         ((UINT8)0x00)
#define EPLD_VERSION          ((UINT8)0x01)

STATUS BrdVersionGet(UINT8 module, UINT8 *pVersion);    


/*==============================��ƵԴ���=============================*/  
/* �궨�� */
#define VIDEOIN_CHKERROR   -1   /* ��Ƶ����оƬMAP[1]û�д������������� */
#define VIDEOIN_OFF         0   /* ��ѡ���������ƵԴ���ź� */
#define VIDEOIN_ON          1   /* ��ѡ���������ƵԴ���ź� */

int BrdVideoInCheck(void);        /* ��ƵԴ���,����ֵ���Ϻ궨�� */

/*#endif   /* INC BOARD_KDV8010A */





/*#ifdef BOARD_MPC
/*==============================��ͬ��=============================*/  
/* ͬ��ģʽ�궨�� */
#define SYNC_MODE_FREERUN         0   /* �����񵴣�������MCUӦ����Ϊ��ģʽ�������¼���·ʱ�����MCUͬ�� */
#define SYNC_MODE_TRACK_2M_SLAVE  4   /* ����ģʽ����Ϊ�¼�MCUӦ����Ϊ��ģʽ������DT���Ĵ�2Mʱ�� */
#define SYNC_CLOCK_UNLOCK         0   /* ����ģʽʱʱ��δ���� */
#define SYNC_CLOCK_LOCK           1   /* ����ģʽʱʱ�������ɹ� */

/* �������� */
void BrdNetSyncModeSet(UINT8 mode);                 /* ��ͬ��ģʽ����
                                                       �������: ��ͬ��ģʽ�궨�� */
void BrdNetSyncSrcSelect(UINT8 dtiNo, UINT8 E1No);  /* ��ͬ��Դѡ��
                                                       �������: dtiNo ��Χ0~14��E1No��Χ0~7 */
int BrdNetSyncLock(void);                           /* �����ͬ������ģʽʱ�Ƿ�����ʱ��Դ
                                                       ���������#define SYNC_CLOCK_UNLOCK 0    ����ģʽʱʱ��δ���� 
                                                                #define SYNC_CLOCK_LOCK   1    ����ģʽʱʱ�������ɹ� 
                                                       ע��ֻ�е�ǰMCU��ɸ���ģʽʱ����Ч��������ʱ
                                                       MCU��������κ�ʱ�ӣ����ú�������Ч�ģ���Զ����δ���� */



/*#endif   /* INC BOARD_MPC */




#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif   /*INCDriverInith*/
