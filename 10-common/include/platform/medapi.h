/*========================================
ģ����	�� MEDAPI
�ļ���	�� MEDAPI.h
����ļ���  ��
�ļ�ʵ�ֹ��ܣ���������ײ�API�����ӿڡ�
����	�����ǿ
�汾	��V1.0
����    ��2004.03.23
===========================================*/
#ifndef __INCMEDAPIh
#define __INCMEDAPIh

#ifdef __cplusplus 
   #define  MEDAPI  extern "C"
#else if
   #define  MEDAPI  extern
#endif

/* ��̫�������ṹ */
typedef struct{
    UINT32 dwIpAdrs;
    UINT32 dwIpMask;
    UINT8  byMacAdrs[6];
}TBrdEthParam;
/*wjh:�����������ṩ����codece ��ĺ�����Ҫ���ӵĽṹ��/��ȵĶ���*/
/*wjh add */
#define BSP15_VGA_NONE  0    /*vga����������ܾ�û��*/
#define BSP15_VGA_IN    1    /*ֻ��vga���빦��*/
#define BSP15_VGA_OUT   2    /*ֻ��vga������� */
#define BSP15_VGA_INOUT 3    /*vga����������ܶ���*/
#define SAA7114_OUTPORT_NONE      0/*û��7114*/
#define SAA7114_OUTPORT_X         1/*��7114��X�����*/
#define SAA7114_OUTPORT_I         2/*��7114d��I�����*/
#define SAA7114_OUTPORT_XI        3/*��7114��X�ں�I��ͬʱ���*/
#define CAPTURE_FROM_NONE            0/*û�вɼ�оƬ*/
#define CAPTURE_FROM_SAA7114         1/*��7114оƬ�ɼ��ź�*/
#define CAPTURE_FROM_SAA7113         2/*��7113�ɼ��ź�*/
#define BSP15_VCAPTURE_FROM_NONE   0/*û��BSp15���ݲɼ�*/
#define BSP15_VCAPTURE_FROM_PORTA  1/*��BSP15��A�ڲɼ�����*/
#define BSP15_VCAPTURE_FROM_PORTB  2/*��BSP15��B�ڲɼ�����*/
#define BSP15_VCAPTURE_FROM_PORTAB  3/*��BSP15��A/B�ڲɼ�����*/

/* BSP15�����ɼ�оƬBrdGetAudCapChipType����ֵ�궨�� */
#define CAPTURE_AUDIO_FROM_NONE    0       /* audio capture from chip none  */
#define CAPTURE_AUDIO_FROM_5331    1       /* audio capture from chip 5331  */
#define CAPTURE_AUDIO_FROM_AIC23B  2       /*                        AIC23B */

/* ϵͳ��λ�ص�ע�ắ������ */
#define SYS_MAX_REBOOT_HOOK_NUM     10
typedef struct
{
    UINT32 dwFuncLogInNum;
    VOIDFUNCPTR pfRebootHookFuc[SYS_MAX_REBOOT_HOOK_NUM];
}TBrdRebootHookModule;
LOCAL UINT32 gdwMapFlashEnable; 
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

/*�ṩ��codec��ĺ�������*/
UINT8 BrdFastLoadEqtFileIsEn(void);
STATUS sysRebootHookAdd(VOIDFUNCPTR rebootHook);
STATUS BrdGetAllDiskInfo(TBrdAllDiskInfo *pBrdAllDiskInfo);
UINT32 BrdGetFullFileName(UINT8 byPutDiskId, char *pInFileName, char *pRtnFileName);
UINT8 BrdGetBSP15VGAConf(UINT8 byDevId);
void BrdStopVGACap(void);
void BrdOpenVGA(void);
UINT8 BrdGetSAA7114OutPort(UINT8 byBSP15ID);
void BrdSetVGACapMode(UINT8 byMode);
UINT8 BrdGetCaptureChipType(UINT8 byBSP15ID);
void BrdMapDevOpenPreInit(UINT8 byBSP15ID);
void BrdCloseVGA(void);
STATUS BrdAddEthBautRate(UINT8 byUnit, UINT32 dwBautRate);
BOOL  BrdEthSndUseTimer(void);
UINT8 BrdBsp15LedFlashMode(void);
UINT8 BrdGetBSP15Speed(UINT8 byDevId);
void BrdStartVGACap(UINT8 byMode);
void BrdMapDevClosePreInit(UINT8 byBSP15ID);
STATUS BrdMoveEthBautRate(UINT8 byUnit, UINT32 dwBautRate);
UINT8 BrdGetBSP15CapturePort(UINT8 byBSP15ID);


/*end wjh add*/
//��ʼ����������ײ�API�����ӿ�
MEDAPI STATUS MEDAPI_Init();
//��ȡӲ���汾
MEDAPI UINT8 MEDAPI_GetHardVer();
//��ȡEPLD�汾
MEDAPI UINT8 MEDAPI_GetEpldVer();
//��ȡ�豸��
MEDAPI UINT8 MEDAPI_GetDeviceID();
//��ȡOS�汾
MEDAPI UINT8 MEDAPI_GetOsVer();
//��ʼ������
MEDAPI void MEDAPI_InitSerial(UINT8);
//���ڶ˿ں��Զ�����
MEDAPI UINT8 MEDAPI_SerialPortAdapt(UINT8);
//���ô��ڵĲ�����
MEDAPI void MEDAPI_SetSerialBaud(UINT8,UINT16);
//��ȡ�ֳ���·�澯(����)
MEDAPI void MEDAPI_GetAlarmInput(UINT8*);
//����ֳ�����
MEDAPI void MEDAPI_SetAlarmOutput(UINT8,UINT8);
//ϵͳ����
MEDAPI void MEDAPI_SysReboot();
//����ϵͳ����
MEDAPI void MEDAPI_SetSysGuard(UINT8);
//��ȡϵͳ����
MEDAPI UINT8 MEDAPI_GetSysGuard();
//����ϵͳ����ָʾ��
MEDAPI void MEDAPI_SetSysLink(UINT8);
//����ϵͳ�澯ָʾ��
MEDAPI void MEDAPI_SetSysAlarm(UINT8);
//��ȡϵͳE1״̬
MEDAPI UINT8 MEDAPI_GetE1State(void);
//��ȡ�����ת״̬��ƽֵ
MEDAPI UINT8 MEDAPI_GetMotorState(void);
//�����ƵԴ����״̬
MEDAPI void MEDAPI_GetVidstate(UINT8* Vidstate);
//e1ģ�����û���
MEDAPI void MEDAPI_e1Loop(UINT8 byType,UINT8 byState, UINT16 byMin);
//e1ģ�鳷������
MEDAPI void MEDAPI_e1noLoop();
//ѹ���ļ���ѹ������flash��>sdram
MEDAPI int  MEDAPI_Decompfile( char* compfile, char* uncompfile, UINT8 byMemNo );
//�ͷ�ѹ���ļ�������ڴ�
MEDAPI void MEDAPI_DecompMemFree();
//����NIP��running.cfg�������
MEDAPI void MEDAPI_SetNIPConf(UINT8,char*,char*);
//������̫������
MEDAPI STATUS MEDAPI_SetEthParam(UINT8 byEthId, UINT8 byIpOrMac, TBrdEthParam *ptBrdEthParam);
//��ȡ��̫������
MEDAPI STATUS MEDAPI_GetEthParam(UINT8 byEthId, TBrdEthParam *ptBrdEthParam);

#endif

