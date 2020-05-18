/******************************************************************************
ģ����  �� BrdWrapper
�ļ���  �� brdwrapper.h
����ļ��� brdwrapperdef.h
�ļ�ʵ�ֹ��ܣ�BrdWrapperģ������ṩ�Ľṹ����ͺ����ӿ�ͷ�ļ������ļ�Ŀǰ��ҪӦ���ڼ�
            ���豸�弶�豸������
����    ���ŷ���
�汾    ��1.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
12/27/2006  1.0        �ŷ���      ����
******************************************************************************/
#ifndef __BRD_WRAPPER_H
#define __BRD_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "kdvtype.h"
#include "brdwrapperdef.h"
#include "api_vlynq.h"
#include <syslog.h>

#include <time.h>

/* -------------------------------- �궨�� ----------------------------------*/

/****************************** ģ��İ汾�������涨 *************************
�ܵĽṹ��mn.mm.ii.cc.tttt
     ��  Osp 1.1.7.20040318 ��ʾ
ģ������Osp
ģ��1�汾
�ӿ�1�汾
ʵ��7�汾
04��3��18���ύ

�汾�޸ļ�¼��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.1.1.20090413
���ӹ��ܣ�����BrdGetMasterVideoMode���ܽӿ�
�޸�ȱ�ݣ���
�ύ�ˣ����˲�
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.1.1.20070712
���ӹ��ܣ�����davinci resizer���ܽӿ�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.1.2.20070921
���ӹ��ܣ�����ts7210��kdm2820��̨�豸
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.1.2.20071019
���ӹ��ܣ�����kdm2100�豸
�޸�ȱ�ݣ���
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.1.3.20071210
���ӹ��ܣ�����kdv7810 ts7810�豸
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.0.20071214
���ӹ��ܣ�������̫���ӿ�����״̬��ѯ��Э��״̬��ѯ�ӿ�
�޸�ȱ�ݣ���
�ύ�ˣ�����
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.1.20071226
���ӹ��ܣ�������̫���ӿڹ���ģʽ���ýӿ�
�޸�ȱ�ݣ���
�ύ�ˣ�����
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.2.20071229
���ӹ��ܣ�����kdv7810�豸
�޸�ȱ�ݣ���
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.2.20080107
���ӹ��ܣ�����ѡ�����ң�صĽӿ�
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.2.20080118
���ӹ��ܣ���Ӱ汾�ţ�BIG_ENDIAN��davinci��Ĭ�϶����ˣ��ĳ���������
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.2.20080124
���ӹ��ܣ� ����TS6210E���豸����.
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.3.20080202
���ӹ��ܣ� ����HDMI��Ƶ��ѯ���趨�ӿ�.
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.4.20080311
���ӹ��ܣ�����kdv7810���֧��
�޸�ȱ�ݣ���
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.5.20080312
���ӹ��ܣ������豸����
�޸�ȱ�ݣ���
�ύ�ˣ�������

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.5.20080325
���ӹ��ܣ�non-block update msp430(ir.txt)
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.5.20080402
���ӹ��ܣ�����KDV8000BHD�豸����
�޸�ȱ�ݣ���
�ύ�ˣ�����

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.5.20080417
���ӹ��ܣ�����KDV7910 E1֧�ֺ�KDM2820ϵͳ��Ʒ֧��
�޸�ȱ�ݣ���
�ύ�ˣ�����

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.6.20080428
���ӹ��ܣ�����Davinciϵͳ�У����Ӵ�ϵͳ��ȡ��Ƶ���ģʽ�Ľӿ�
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.6.20080428
���ӹ��ܣ����ơ�����Davinciϵͳ�У����Ӵ�ϵͳ��ȡ��Ƶ���ģʽ�Ľӿڡ��Ĵ���
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.6.20080505
���ӹ��ܣ�����һЩǰ���豸�Ķ���
�޸�ȱ�ݣ���
�ύ�ˣ�ëһɽ
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.2.6.20080514
���ӹ��ܣ���
�޸�ȱ�ݣ��޸�KDV7810���ⵥƬ������BUG
�ύ�ˣ���ǭ��

--------------------------------------------------------6.20080515
���ӹ��ܣ�����һ�����߸澯�Ľӿ�
�޸�ȱ�ݣ���
�ύ�ˣ�ëһɽ

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.3.7.20080715
���ӹ��ܣ������л�vga/video�Ľӿ�BrdGetVgaVideoState()
�޸�ȱ�ݣ���
�ύ�ˣ���Զ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.3.7.20080801
�ύ�ˣ���ǭ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.3.7.20080813
���ӹ��ܣ�����KDV7810�澯�ṹ
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20080830
���ӹ��ܣ�����KDV7620������Ƶ������ƽӿ�
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20080909
���ӹ��ܣ�E2PROM��ؽӿ�����ʵ�֣���nipwrapper����ؽӿ���ֲ��brdwrapper�У�
�޸�ȱ�ݣ���
�ύ�ˣ�����
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20081120
���ӹ��ܣ�
		  (1)�����úͻ�ȡAD5246�������ȡ�ֻ��kdm2210��Ч
		  (2):  ����Ӳ���Ӱ汾�š�
		  (3): ����Ӳ����productid��ֻ��ʹ����E2PROM�Ĳ�Ʒ��Ч
�޸�ȱ�ݣ���
�ύ�ˣ�����

----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20081125
���ӹ��ܣ�����TS6610�Ļ�·��������ʵ��
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20081208
���ӹ��ܣ�����sysinfo��һ����ȡ�ڴ�cache��С���ֶ�
�޸�ȱ�ݣ���
�ύ�ˣ�����
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.7.20081216
���ӹ��ܣ��޸�bcsrFxoCtrl�����������·����ʵ�ִ��������ϲ�ҵ�񲻼�������
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.8.20090224
���ӹ��ܣ�����HDMPU���ʶ����
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.9.20090316
���ӹ��ܣ�����KDV7620��LED�ƽṹ����
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.9.20090403
���ӹ��ܣ��޸�KDV7620��E1ģ���ʶ��ȱ��
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.9.20090421
���ӹ��ܣ��޸�rebootʵ�ֽ��reboot���ܻᵼ������ʧ�ܵ�����
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.10.20090505
���ӹ��ܣ��޸�E2PROM �ṹ��غ궨��
�޸�ȱ�ݣ���
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.11.20090507
���ӹ��ܣ�����VIDINģ�齵֡�����VIDOUTģ����֡������
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.11.20090510
���ӹ��ܣ���makefile������NVR2860���ⵥƬ����������
�޸�ȱ�ݣ���
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.11.20090518
���ӹ��ܣ�����KDV7620 H221����֧��
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.11.20090908
���ӹ��ܣ�����KDV7820��LED�ƽṹ����
�޸�ȱ�ݣ���
�ύ�ˣ���ǭ��
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.4.12.20100330
���ӹ��ܣ�KDV7820�Ľӿ�FPGA����̨�깦��
�޸�ȱ�ݣ�KDV7820�Ľӿ�FPGA����˴󲿷�ͼ����������
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.5.12.20100506
���ӹ��ܣ�KDV7820�Ľӿ�FPGA���ӹ����������
�޸�ȱ�ݣ�KDV7820�Ľӿ�FPGA����˲���ͼ����������
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.5.13.20100608
���ӹ��ܣ�����VGA����ӿ���λ�˲����ڹ���
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.5.14.20100712
���ӹ��ܣ�����fpga��scale����,��Ҫ��6��ӿ�fpga֧��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.5.15.20100816
���ӹ��ܣ�����fpga��ѯ���������������,��Ҫ��6��ӿ�fpga֧��
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.15.20100826
���ӹ��ܣ����Ӳ�ѯ��ʾ�豸��Ϣ�Ĺ���
�޸�ȱ�ݣ���
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.16.20101221
���ӹ��ܣ�
�޸�ȱ�ݣ����fpga���غ���ļ�ʱ��̨��ײ���ʾ��ȫ������
�ύ�ˣ��Ż�
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.17.20101224
���ӹ��ܣ�
�޸�ȱ�ݣ����fpga���Ӻ��ʱ�������˱߽�����Ƶ���м�϶������
�ύ�ˣ��Ż�
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.18.20110409
���ӹ��ܣ�
�޸�ȱ�ݣ�����LM80��Ϣ�ɼ����澯����
�ύ�ˣ�	������
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.18.20110414
���ӹ��ܣ�
�޸�ȱ�ݣ�����E1����澯��Ϣ
�ύ�ˣ�	������
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.18.20110414
���ӹ��ܣ�
�޸�ȱ�ݣ������ն˸澯��Ϣ
�ύ�ˣ�	������
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.6.19.20110718
���ӹ��ܣ���ȡ�ں˴�ӡ��Ϣ
�޸�ȱ�ݣ���
�ύ�ˣ���鳬
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.7.19.20110926
���ӹ��ܣ�����mic��������
�޸�ȱ�ݣ���
�ύ�ˣ���鳬
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.8.19.20111028
���ӹ��ܣ�lm75�¶ȴ������澯�ӿ�
�޸�ȱ�ݣ���
�ύ�ˣ���鳬
----------------------------------------------------------------------------
----------------------------------------------------------------------------
ģ��汾��BrdWrapper 1.9.19.20111114
���ӹ��ܣ�����mic�汾�Ų�ѯ
�޸�ȱ�ݣ���
�ύ�ˣ���鳬
----------------------------------------------------------------------------


****************************************************************************/

/*�������ӵİ汾�Ŷ���*/
#define VER_Linux_BrdWrapper         (const s8*)"BrdWrapper 1.6.17.20101224"

#define BRD_ERR(fmt, args...) \
    {printf("[BRD_WRAPPER_ERR]:%s(%d): ",__func__,__LINE__);printf(fmt, ## args); \
     syslog(LOG_ERR,"[BRD_WRAPPER_ERR]:%s(%d): ",__func__,__LINE__);syslog(LOG_ERR,fmt, ## args);}

#define BRD_PRT(fmt, args...) \
    {printf("[BRD_WRAPPER_PRT]: ");printf(fmt, ## args);	\
    syslog(LOG_NOTICE,"[BRD_WRAPPER_PRT]: ");syslog(LOG_NOTICE,fmt, ## args);}


/* ------------------------------- ��ؽṹ�嶨�� ----------------------------*/

/* �豸�������� */
typedef struct {
    u32 byBoardID;   /*�豸ID��*/
    u32 byHwVer;     /*Ӳ���汾��*/
    u8 byFpgaVer;   /*FPGA�汾��*/
    u8 byCpldVer;   /*CPLD�汾�� */
    u8 byBoardType; /*�豸���:0--�ն���;1--�����1(�в�λ�źͲ��);2--�����2(�в�λ���޲��) */
    u8 byEthNum;    /*�豸��̫������*/
    u8 byEth0Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byEth1Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byEth2Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byE1Num;     /*�豸E1������0������豸��֧��E1*/
    u8 byV35Num;    /*�豸V35����,0������豸��֧��V35*/
    u8 byBspNum;    /*�豸BSP����,0������豸û��BSP-15ý��оƬ*/
    u8 byFanCtrlSupport;    /*�豸�Ƿ�֧�ַ��ȿ���:0---��֧�֣�1---֧��*/
    u8 byRTCType;   /*�豸RTCоƬ������:����صĺ궨��--RTC_TYPE_NONE/RTC_TYPE_DS1337/RTC_TYPE_DS12C887*/
    u8 abyRS232Name[TTY_NAME_MAX_LEN];/*�豸RS232���ڶ�Ӧ���豸��/MPC��console�ڶ�Ӧ���豸��*/
    u8 abyRS422Name[TTY_NAME_MAX_LEN];/*�豸RS422���ڶ�Ӧ���豸��/MPC��SCC2��Ӧ���豸��*/
    u8 abyRS485Name[TTY_NAME_MAX_LEN];/*�豸RS485���ڶ�Ӧ���豸��/MPC��SCC3��Ӧ���豸��*/
    u8 abyIrayName[TTY_NAME_MAX_LEN]; /*�豸���⴮�ڶ�Ӧ���豸��*/
    u8 abydigmic0RS232Name[TTY_NAME_MAX_LEN];/*����mic��Ӧ�Ĵ���0�豸��*/
    u8 abydigmic1RS232Name[TTY_NAME_MAX_LEN];/*����mic��Ӧ�Ĵ���1�豸��*/
    u8 abydigmic2RS232Name[TTY_NAME_MAX_LEN];/*����mic��Ӧ�Ĵ���2�豸��*/
/*The bottom member support  t300*/
    u8 abyRS422_0_Name[TTY_NAME_MAX_LEN];/*�豸RS422���ڶ�Ӧ���豸��*/
    u8 abyRS422_1_Name[TTY_NAME_MAX_LEN];/*�豸RS422���ڶ�Ӧ���豸��*/
    u8 abyRS422_2_Name[TTY_NAME_MAX_LEN];/*�豸RS422���ڶ�Ӧ���豸��*/
    u8 abyRS232_422_485_0_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
    u8 abyRS232_422_485_1_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
    u8 abyRS232_422_485_2_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
    u8 abyRS232_422_485_3_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
    u8 abyRS232_422_485_4_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
    u8 abyRS232_422_485_5_NAME[TTY_NAME_MAX_LEN];	/*�豸RS232/RS422/RS485���õ��豸��*/
/*For KDV9000A MSU*/
    u8 abyRS232_1_Name[TTY_NAME_MAX_LEN];/*�豸RS232���ڶ�Ӧ���豸��*/

}TBrdCapability;

/* ������ݽṹ���� */
typedef struct{
    u32 byBrdID;                      /* ����ID�� */
    u8 byBrdLayer;                   /* �������ڲ�ţ��豸��֧��ʱ����0������0�㴦�� */
    u8 byBrdSlot;                    /* �������ڲ�λ�ţ��豸��֧��ʱ����0������0�۴���;
                                        �����豸������֮�֣���slot�����֣�0=����1=�� */
}
__attribute__ ((packed))
TBrdPosition;

/* ������Ϣ�ṹ�� */
typedef struct {
    BOOL32 bPlugIn;             /* TRUE =�豸��λ(��Ҫ�ǲ�ѯ�ӿ���Ϣʱ�ã�������Զ����TRUE)��
                                   FALSE=�豸����λ(��ʱ�������Ϣ��Ч) */
	u32    dwBrdID;             /* ����ID�� */
	u32    dwHwVer;             /* Ӳ���汾�� */
	s8     abyDevSerial[STR_NAME_MAX_LEN];    /* �豸���кţ��ַ�����ʽ */
	s8     abyProductDate[STR_NAME_MAX_LEN];  /* �豸�������ڣ��ַ�����ʽ */
	s8     abyFlowCode[STR_NAME_MAX_LEN];     /* ��ˮ�߱��룬�ַ�����ʽ */
	u32    dwEthMacTotal;                     /* ��̫��MAC��ַ�ĸ��� */
	u8     abyMacAddrs[ETH_MAC_MAX_NUM][6];   /* ��̫��MAC��ֵַ */
}TBrdInfo;

/* HDMI��Ƶ��Ϣ�ṹ�� */
typedef struct {
    u32 dwSampleRate;           /* ����Ƶ��(Hz)��0=����Ƶ�������Ƶ; ����ֵΪ:8000,32000,48000,96000 */
    u32 dwSampleBits;           /* ����λ��16bit/20bit/24bit/32bit */
	u32 dwChnlNum;              /* ����������1/2/3(2.1)/6(5.1�űȻ���) */
}THdmiAudInfo;

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

/* KDM2401ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedETH;
}
__attribute__ ((packed))
TBrdKDM2401LedDesc;

/* KDM2402ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedSYSLNK;
    u8 byLedHD;     /* ����޷���⣬���س���״̬ */
    u8 byLedVLED0;
    u8 byLedVLED1;
}
__attribute__ ((packed))
TBrdKDM2402LedDesc;

/*KDM2401ESǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLNK;
    u8 byLedHD;     /* ����޷���⣬���س���״̬ */
    u8 byLedVLED0;
}
__attribute__ ((packed))
TBrdKDM2401ESLedDesc;

/*KDM2404Sǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLNK;
    u8 byLedHD;     /* ����޷���⣬���س���״̬ */
    u8 byLedVLED0;
    u8 byLedVLED1;
    u8 byLedVLED2;
    u8 byLedVLED3;
}
__attribute__ ((packed))
TBrdKDM2404SLedDesc;

/*KDM2501ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedACT;    /* ͬLINK�� */
    u8 byLedIR;     /* ����޷���⣬���س���״̬ */
}
__attribute__ ((packed))
TBrdKDM2501LedDesc;

/*KDM2820ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedETH;    /* ����޷���⣬���س���״̬ */
    u8 byLedHD;     /* ����޷���⣬���س���״̬ */
    u8 byLedIR;     /* ����޷���⣬���س���״̬ */
    u8 byLedALM;
}
__attribute__ ((packed))
TBrdKDM2820LedDesc;

/*V5ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedGreen;
    u8 byLedOrange;
}
__attribute__ ((packed))
TBrdV5LedDesc;

/*TS5210ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedGreen;
    u8 byLedOrange;
}
__attribute__ ((packed))
TBrdTS5210LedDesc;

/*TS7210ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedGreen;
    u8 byLedOrange;
}
__attribute__ ((packed))
TBrdTS7210LedDesc;

/* KDM200_MPUǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
}
__attribute__ ((packed))
TBrdKDM200_MPULedDesc;

/*TS6610ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedGreen;
    u8 byLedOrange;
}
__attribute__ ((packed))
TBrdTS6610LedDesc;

/* KDM2440ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
}
__attribute__ ((packed))
TBrdKDM2440LedDesc;

/* KDM2100ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedGreen; //FlashMode: on,off,quick,slow
    u8 byLedRed;
    u8 byLedOrange;
}
__attribute__ ((packed))
TBrdKDM2100LedDesc;

/*KDM201C04ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedVLED0;
    u8 byLedVLED1;
    u8 byLedVLED2;
    u8 byLedVLED3;
}
__attribute__ ((packed))
TBrdKDM201C04LedDesc;

/*KDV7810ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
    u8 byLedENC;
    u8 byLedDEC;
}
__attribute__ ((packed))
TBrdKDV7810LedDesc;

typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
    u8 byLedPWR;/*ֻ�ܲ�ѯ����������*/
    u8 byLedLAN;/*ֻ�ܲ�ѯ����������*/
    u8 byLedIR;/*ֻ�ܲ�ѯ����������*/
}
__attribute__ ((packed))
TBrdKDV7620LedDesc;


typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
    u8 byLedDSP;
    u8 byLedPWR;	/*ֻ�ܲ�ѯ����������*/
    u8 byLedLAN1;	/*ֻ�ܲ�ѯ����������*/
    u8 byLedLAN2;	/*ֻ�ܲ�ѯ����������*/
    u8 byLedIR;		/*ֻ�ܲ�ѯ����������*/
}
__attribute__ ((packed))
TBrdKDV7820LedDesc;


/*H600ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedPWR;
    u8 byLedLAN;
}__attribute__ ((packed))TBrdH600LedDesc;

/*H700ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct brd_h700_led_des
{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedLINK;
}
__attribute__ ((packed))
TBrdH700LedDesc;

/*H800ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct brd_h800_led_des
{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedLINK;
}
__attribute__ ((packed))
TBrdH800LedDesc;

/*H900ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct brd_h900_led_des
{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedLINK;
}
__attribute__ ((packed))
TBrdH900LedDesc;

/*HDMPUǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
    u8 byLedLINK0;
    u8 byLedLINK1;
}
__attribute__ ((packed))
TBrdHDMPULedDesc;


/*HDMPU2ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedLINK;
    u8 byLedALM;
    u8 byLedLINK0;
    u8 byLedLINK1;
}
__attribute__ ((packed))
TBrdHDMPU2LedDesc;

/*KDV8000Iǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct brd_kdv8000i_led_des
{
    u8 byLedRun;
    u8 byLedALM;
}
__attribute__ ((packed))
TBrdKDV8000ILedDesc;

/* KDV9000A SMM ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct brd_kdv9000a_smm_led_des
{
    u8 byLedHS; 
    u8 byLedRunG;
    u8 byLedRunR;
    u8 byLedALMG1; 
    u8 byLedALMR1;
    u8 byLedALMG2;
    u8 byLedALMR2; 
    u8 byLedALMG3;
    u8 byLedALMR3;
    u8 byLedPRes;
    u8 byLedOSSG;
    u8 byLedOSSR;	
}
__attribute__ ((packed)) 
TBrdKDV9000ASMMLedDesc;


/*MPC2ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedMS;
    u8 byLedOUS;
    u8 byLedSYN;
    u8 byLedNMS;
    u8 byLedLINK0;	/*LINK0��*/
    u8 byLedLINK1;    /*LINK1�� */
    u8 byLedNORM;    /* �ư�������ָʾ�� */
    u8 byLedNALM;    /* �ư���һ��澯ָʾ�� */
    u8 byLedSALM;   /* �ư������ظ澯ָʾ�� */
}
__attribute__ ((packed))
TBrdMPC2LedDesc;

/*CRI2 ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedRun;
    u8 byLedALM;
    u8 byLedLINK0;	/*LINK0��*/
    u8 byLedLINK1;   /*LINK1�� */
    u8 byLedMLINK;
    u8 byLedMS;
    u8 byLedFun1;
    u8 byLedFun2;
    u8 byLedFun3;
    u8 byLedFun4;
    u8 byLedFun5;
    u8 byLedFun6;
    u8 byLedFun7;
    u8 byLedFun8;
}
__attribute__ ((packed))
TBrdCRI2LedDesc;

/* �ն�DRI2ǰ���ָʾ�ƽṹ */
typedef struct{
    u8 byLedRun;     /* ϵͳ���е� */
    u8 byLedE1ALM0;  /* E10�澯ָʾ�� */
    u8 byLedE1ALM1;  /* E11�澯ָʾ�� */
    u8 byLedE1ALM2;  /* E12�澯ָʾ�� */
    u8 byLedE1ALM3;  /* E13�澯ָʾ�� */
    u8 byLedE1ALM4;  /* E14�澯ָʾ�� */
    u8 byLedE1ALM5;  /* E15�澯ָʾ�� */
    u8 byLedE1ALM6;  /* E16�澯ָʾ�� */
    u8 byLedE1ALM7;  /* E17�澯ָʾ�� */
    u8 byLedMLINK;   /* ϵͳ����ָʾ�� */
    u8 byLedLINK0;	/*LINK0��*/
    u8 byLedLINK1;    /*LINK1�� */
}
__attribute__ ((packed))
TBrdDRI2LedDesc;



/*IS3-MPC8313ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
/*�����Ա����1��run�ƺ�26������״̬�ƣ����ж������£�����Ԫ��λ�ã��������ʾ */
/*������5v,12v.  0-6:00-06;  7-13:08-14; 14:run;  15-16:mc0-mc1;  17-24:e0-e7; 25-26:G0-G1 */
#define MPC8313LED_00     0
#define MPC8313LED_06     6
#define MPC8313LED_08     7
#define MPC8313LED_14     13
#define MPC8313LED_RUN     14
#define MPC8313LED_MC0     15
#define MPC8313LED_MC1     16
#define MPC8313LED_E0     17
#define MPC8313LED_E7     24
#define MPC8313LED_G0     25
#define MPC8313LED_G1     26
typedef struct{
 	u8 byLedSwitch[27];
}
__attribute__ ((packed))
TBrdIS3MPC8313LedDesc;

/*IS3-MPC8548ǰ���ָʾ�ƽṹ����Ա����ֵ��궨�壺ָʾ��״̬ */
typedef struct{
    u8 byLedALM;
    u8 byLedMLINK;    /* MLK */
    u8 byLedLINK;
}
__attribute__ ((packed))
TBrdIS3MPC8548LedDesc;

/* ָʾ��״̬�����ṹ */
typedef struct {
    u32 dwLedNum;                       /* ��Ч��ָʾ�Ƶĸ��� */
    union {
        u8 byLedNo[BRD_LED_NUM_MAX];    /* ������Ч��ָʾ��״̬������dwLedNum�ĵ�ֵΪ0 */
        TBrdKDV8010CLedStateDesc tBrdKDV8010CLedState;
        TBrdKDV8010LedStateDesc  tBrdKDV8010LedStateDesc;
        TBrdMTLedStateDesc       tBrdMTLedState;
        TBrdKDM2401LedDesc       tBrdKDM2401Led;
        TBrdKDM2402LedDesc       tBrdKDM2402Led;
        TBrdKDM2401ESLedDesc     tBrdKDM2401ESLed;
        TBrdKDM2404SLedDesc      tBrdKDM2404SLed;
        TBrdKDM2501LedDesc       tBrdKDM2501Led;
        TBrdV5LedDesc            tBrdV5Led;
        TBrdTS5210LedDesc        tBrdTS5210Led;
        TBrdTS7210LedDesc        tBrdTS7210Led;
        TBrdKDM200_MPULedDesc    tBrdKDM200_MPULed;
        TBrdTS6610LedDesc        tBrdTS6610Led;
        TBrdKDM2440LedDesc 	     tBrdKDM2440Led;
        TBrdKDM2100LedDesc       tBrdKDM2100Led;
        TBrdKDM201C04LedDesc     tBrdKDM201C04Led;
	 TBrdKDM2820LedDesc       tBrdKDM2820Led;
        TBrdKDV7810LedDesc       tBrdKDV7810Led;
	 TBrdKDV7620LedDesc        tBrdKDV7620Led;
	 TBrdH600LedDesc			tBrdH600Led;
	 TBrdKDV7820LedDesc        tBrdKDV7820Led;
	 TBrdMPC2LedDesc	   tBrdMPC2LedState;
	 TBrdDRI2LedDesc    tBrdDRI2LedState;
	 TBrdHDMPULedDesc tBrdHDMPULedState;
	 TBrdHDMPU2LedDesc tBrdHDMPU2LedState;
	 TBrdCRI2LedDesc   tBrdCRI2LedState;
	 TBrdIS3MPC8313LedDesc  tBrdIS2XMpc8313LedState;
	 TBrdIS3MPC8548LedDesc  tBrdIS2XMpc8548LedState;
	 TBrdH700LedDesc		tBrdH700LedState;
	  TBrdH800LedDesc		tBrdH800LedState;
	 TBrdH900LedDesc		tBrdH900LedState;
	 TBrdKDV8000ILedDesc tBrdKDV8000ILedState;
	 TBrdKDV9000ASMMLedDesc tBrdKDV9000ASMMLedDesc;
    } nlunion;
} TBrdLedState;


/* ------------------------- �ײ�澯��صĽṹ����----------------------*/

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


/* KDV7810�ײ�澯��Ϣ�ṹ���� */
/*
typedef struct{
    BOOL32 bAlarmHighTemp;
    BOOL32 bAlarmVolatageError;
    BOOL32 bAlarmFan0Stop;
    BOOL32 bAlarmFan1Stop;
}TBrdKDV7810AlarmAll;
*/


/* KDV8018�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1Alarm;     /* E1�澯 */
}TBrdSMTAlarmAll;

/* KDM2400 2500�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    TBrdE1AlarmDesc tBrdE1Alarm;     /* E1�澯 */
}TBrdKDM2000AlarmAll;

/* KDM200_MPU�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bFan0Stop;     /* ����0ͣת */
    BOOL32 bFan1Stop;     /* ����1ͣת */
    BOOL32 bFan2Stop;     /* ����2ͣת */
}TBrdKDM200_MPUAlarm;

typedef struct {
	int temp;
	BOOL32 voltage_alm;
	u32	fan0_speed;
	u32 fan1_speed;
} TBrdSensor;

typedef struct{
	BOOL32 tempAlarm;  //����ת�ٳ���80��c
	BOOL32 voltageAlarm; //��ѹ��Χ����+_10%
	BOOL32 fan0Alarm;   //����ת�ٵ���2000ת
	BOOL32 fan1Alarm;	 //����ת�ٵ���2000ת
	}TBrdSensorAlarm;
/* KDV7820�ײ�澯��Ϣ�ṹ���� */
typedef struct{
    BOOL32 bAlarmHighTemp;     	/* �¶ȹ���(����80 ��) */
    BOOL32 bAlarmVolatageError;   /* ��ѹ�澯 */
    BOOL32 bAlarmFan0Stop;     	/* ����0 ͣת */
    BOOL32 bAlarmFan1Stop;     	/* ����1 ͣת */
}TBrdKDV7820larmAll;

typedef struct {
	TBrdSensorAlarm tBrdSensorAlarm; //lm75 alarm
}TBrdKDVH600AlarmAll,TBrdKDVH700AlarmAll,TBrdKDVH900AlarmAll;

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
        TBrdKDM200_MPUAlarm tKDM200_MPUAlarm;
//	TBrdKDV7810AlarmAll	tKDV7810AlarmAll;
		TBrdKDV7820larmAll tKDV7820Alarm;
        TBrdKDVH900AlarmAll tKDVH900Alarm;
      } nlunion;
}TBrdAlarmState;
typedef struct {
    u32 temp;
    u32 in0_3v3;
    u32 in1_2v5;
    u32 in2_1v8;
    u32 in3_1v8;
    u32 in4_1v2;
    u32 in5_1v2;
    u32 in6_1v0;
    u32 fan0_speed;
    u32 fan1_speed;
} TKdv7820Sensor;
typedef struct {
    u32 temp;
    u32 in0_3v3;
    u32 in1_2v5;
    u32 in2_5v0;
    u32 in3_1v8;
    u32 in4_12v0;
    u32 in5_1v5;
    u32 in6_1v2;
    u32 fan0_speed;
    u32 fan1_speed;
} TKdv7810Sensor;
typedef struct {
    int temp;
    u32 in0;
    u32 in1;
    u32 in2;
    u32 in3;
    u32 in4;
    u32 in5;
    u32 in6;
    u32 fan0_speed;
    u32 fan1_speed;
} TSensor;

typedef struct {
	int temp;
	u32 fan0_speed;
}TKdvH600Sensor;
typedef struct {
	int temp;
   	u32 fan0_speed;
    	u32 fan1_speed;
}TKdvH700Sensor,TKdvH900Sensor;
typedef struct{
	union{
		TSensor sensor;
		TKdv7810Sensor kdv7810sensor;
		TKdv7820Sensor kdv7820sensor;
		//TKdvH600Sensor kdvh600sensor;
		//TKdvH700Sensor kdvh700sensor;
		//TKdvH900Sensor kdvh900sensor;
		}union_t;
}TSensorAll;

/* ��E1ģ��DS21Q354���ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
	BOOL32 bAlarmE1RRAOld;      /* E1Զ�˸澯 mask:04*/
    BOOL32 bAlarmE1RUA1Old;     /* E1ȫ1�澯 mask:08*/
	BOOL32 bAlarmE1RLOSOld;     /* E1ʧͬ���澯 mask:01*/
	BOOL32 bAlarmE1RCLOld;      /* E1ʧ�ز��澯 mask:02*/
}TBrdE1AlarmDetail21354;

/*��E1 ģ��DS26534���ײ�E1�澯��Ϣ�ṹ���� */
typedef struct{
	BOOL32 bAlarmE1RRAI;	/* E1Զ�˸澯mask:08 */
	BOOL32 bAlarmE1RAIS;	 /* E1ȫ1�澯 mask:04*/
	BOOL32 bAlarmE1RLOF;    /* E1ʧͬ���澯mask:02 */
	BOOL32 bAlarmE1RLOS;	/*E1��ʧ�źŸ澯mask:01*/
}TBrdE1AlarmDetail26514;

/*��E1����E1 ģ����ϸ�澯��Ϣ*/
#define MAX__E1_PORT 8
typedef union {
		TBrdE1AlarmDetail21354 tBrdE1AlarmDetail21354;
		TBrdE1AlarmDetail26514 tBrdE1AlarmDetail26514;
		BOOL32 tBrdE1AlarmDetail[4];
		}TBrdE1AlarmDetail;

typedef struct {
	TBrdE1AlarmDetail tBrdE1AlarmDetail[MAX__E1_PORT];	   /* E1�澯 */
	BOOL32 E1Exist;					/*E1���ڷ���1�������ڷ���0*/
	BOOL32 E1PhyMod;				/*�ж��Ƿ�����E1ģ�飬��ģ��21354Ϊ1����ģ��26514Ϊ0*/
}TBrdE1AlarmAll;

/*�ײ�澯��Ϣ�ṹ����*/
typedef struct{
	TBrdSensorAlarm tBrdSensorAlarm; //lm80�澯��Ϣ
	TBrdE1AlarmAll tBrdE1AlarmAll;
}TBrdKDV7810_AlarmAll,TBrdKDV7820AlarmAll;

/*�ײ�澯��Ϣ�ṹ����*/
typedef struct{
	TBrdE1AlarmAll tBrdE1AlarmAll;
}TBrdKDV7620AlarmAll;

typedef struct{
		union{
			BOOL32 bAlmNo[BRD_ALM_NUM_MAX];
			TBrdKDV7810_AlarmAll tBrdKDV7810AlarmAll;
			TBrdKDV7820AlarmAll tBrdKDV7820AlarmAll;
			TBrdKDV7620AlarmAll tBrdKDV7620AlarmAll;
			TBrdKDVH600AlarmAll tBrdKDVH600AlarmAll;
			TBrdKDVH700AlarmAll tBrdKDVH700AlarmAll;
			TBrdKDVH900AlarmAll tBrdKDVH900AlarmAll;
	 		}nlunion;
	}TBrdKDVAlarm;


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

/*
typedef struct {
    u32 temp; // 1/1000 C
   u32 in0_3v3;	//mv
    u32 in1_2v5;    	//mv
    u32 in2_5v0;	//mv
    u32 in3_1v8;	//mv
    u32 in4_12v0;	//mv
    u32 in5_1v5;	//mv
    u32 in6_1v2;       //mv
    u32 fan0_speed; //rpm
    u32 fan1_speed; //rpm
} TBrdSensor;
*/

typedef struct {
	u32 updays;
	u8 uphours;
	u8 upmins;
	u8 loads_int[3]; /* 1, 5, and 15 minute load averages (int portion)*/
	u8 loads_frac[3]; /* 1, 5, and 15 minute load averages (frac portion) */
	u32 totalram; //k
	u32 freeram; //k
	u32 procs;
	u32 cached; /*cache*/

}TBrdSysInfo;

/* ��Ƶ��ʽ�ṹ���� */
typedef struct{
    u32	    dwWidth;                    /* ��Ƶ������Ϊ��λ,Ϊ0��ʾ���ź� */
    u32	    dwHeight;                   /* ��Ƶ�ߣ���Ϊ��λ,Ϊ0��ʾ���ź� */
    BOOL32  bProgressive;               /* ���л���У�TRUE=���У�FALSE=���� */
    u32     dwFrameRate;                /* ֡�ʣ�����ʱ=��Ƶ������ʱ=��Ƶ/2����60i=30P, Ϊ0��ʾ���ź�
                                           ���ֵ����1000������Ϊ����С�����3λ����59940��ʾ59.940Hz
                                           ���õ���60/1.001=59.940; 24/1.001=23.976; 30/1.001=29.970 */
    u32     dwColorSpace;               /* ���brdwrapperdef.h: ��Ƶ��ʽ���붨�� */
} TVidStd;

/* ��Ƶ��������ṹ���� */
typedef struct{
    u32       dwNsfLevel;                 /* ���: dwNfLevel�궨�� */
    u32       dwNsfType;                  /* ���: dwNsfType�궨�� */
	u32       dwNsfEnable;                /* 0-disable 1-enable */
    TVidStd   vidstd;                     /* ��Ƶ��ʽ */
} TVidNsfParam;

typedef struct{
	u32 zoom;					/* �������zoomֵ */
	u32 rdru_c_en;				/* ͼ��������ʹ�� 0-disable 1-enable */
	TVidStd vidstd;				/* ��Ƶ��ʽ */
} TVidRdRuParam;


/* OSD������ʽ�ṹ���� */
typedef struct{
    TVidStd	    tVid0Std;               /* ��Ƶ0����ʽ */
    TVidStd	    tOsd0Std;               /* OSD0����ʽ����ͼ����ߺ����л���б����Vid����ͬ */
    u32         dwTransVal;             /* ȫ��͸���ȣ���Χ: 0-0xff, Ϊ0ʱΪȫ͸��OSD�㲻����ϳɣ�Vid��ֱ��͸�� */
    u32         dwBackGroundY;          /* ȫ͸�ı���ɫY����ֵ����Χ: 0x10-0xf0, OSD��ÿ�����Yֵ���ڱ���ɫ�Ļ�
                                           ������ϳɣ�Vid��ֱ��͸���õ������ */
} TVidOsdParam;

typedef struct{
    u32 chip_id;
    u32 vp_id;
    TVidStd tVidStd;
}TVidIoConfigParam;

/* Resize������ʽ�ṹ���� */
typedef struct{
    u32         dwIntfIn;               /* Resizer��Դ�ӿ�ѡ�� */
    u32         dwMode;                 /* Resizer������ģʽѡ�� */
    TVidStd	    tVidInStd;              /* ����Resizer����Ƶ��ʽ */
    TVidStd	    tVidOutStd;             /* Resizer֮�����Ƶ��ʽ*/

    u32         dwScaledX;              /* ���ź�����Ե�ͼ�������n�����أ�����ͼ������ !ע�⣺������ż��!���ܳ�����ͼ��Χ */
    u32         dwScaledY;              /* ���ź�����Ե�ͼ��������n�У�����ͼ�����ƣ�ע�⣺���ܳ�����ͼ��Χ */
    u32         dwScaledWidth;          /* ��0��ʾ���ź����������ʽһ��,��0��ʾ���ź�ͼ��Ŀ�� !ע�⣺������ż��!���ܳ�����ͼ��Χ */
    u32         dwScaledHight;          /* ��0��ʾ���ź���ߺ������ʽһ��,��0��ʾ���ź�ͼ��ĸ߶� ע�⣺���ܳ�����ͼ��Χ */

    u8          *pbyCoef;               /* Resizer���˲�ϵ������ָ�룬ΪNULL��ʾʹ��Ĭ��ֵ */
    u32         dwCoefLen;              /* Resizer���˲�ϵ�������ֽ�����Ϊ0��ʾʹ��Ĭ��ֵ */
} TVidResizeParam;

/* ��Ƶͼ��ƫ�Ƶ��ڣ����������ڱ� */
typedef struct {
	int h_off;	/* horizontal video offset */
	int v_off;	/* vertical video offset */
} TVidOffsetParam;

/* ��������ӵ�TV��Ϣ�ṹ���� */
typedef struct{
    u32       dwEdidAvailable;        /* �����ӵ�TV��EDID��Ϣ�Ƿ���ã�1 = ���ã�0 = ������ */
    s8        edid_ver[2];            /* EDID�汾: ���ڰ汾1.3����edid_ver[0]=1, edid_ver[1]=3 */
    u32       dwTVIntf;               /* TV���ӵ���Ƶ�ӿ����ͣ���: ��Ƶ����ӿ����ͺ궨��
                                           ����VIDOUT_SHUT_DOWN��ʾ������, ����ֵΪ��Ч�ӿ����ͣ�
                                           ͬʱ���Ը����������ж������ӵ���Ƶ�ӿ�Ϊģ�⻹������ */
    s8        chName[16];             /* TV���� */
    s8        chManufacturer[16];     /* �������� */
    s8        product_code[2];        /* ��Ʒ���룬��ʽ: �������f036����product_code[0]=0xf0, product_code[1]=0x36 */
    s32       serial_num;             /* ���кţ� ��ʽ: 32λ�з������Σ�(��ѡ�������ַ�������ʽ����ʾ��ʱ�򣬴��������һ���ط�) */
    s8        serial_num_str[16];     /* ���ַ�����ʽ��ʾ�����кţ�����:"DCT3C14R27MM" */
    s32       production_date[2];     /* ��������: ��ݣ��ڼ������ڡ� ����2011���18�����ڣ���production_date[0]=2011,production_date[1]=18 */
    s8        screen_size[2];         /* TV����Ļ��С����λ���ף���ʽ: �� x ��  ==  screen_size[0] x screen_size[1] */
    s8        gamma;                  /* TV��gammaֵ����ʽ:  gamma = (��ʵ��٤��ֵ x 100) �C 100�� ���� 120 = (2.2 x 100) - 100 */

    s8        feature;                /* ��֧�ֵ�һЩ���ԣ�������������:
                                           bit[7]: 1 = Standby supported, 0 = not supported
                                           bit[6]: 1 = Suspend supported, 0 = not supported
                                           bit[5]: 1 = Active Off supported, 0 = not supported
                                           bit[4:3]: Bit 4    Bit 3
                                                     1         1         Undefined
                                                     1         0         Non-RGB Display
                                                     0         1         RGB Display
                                                     0         0         Monochrome Display
                                           bit[2]: 1 = sRGB supported, 0 = not supported
                                           bit[1]: 1 = preferred timing is indicated in first
                                                          detailed timing block (required),
                                                   0 = not indicated (not allowed)
                                           bit[0]: 1 = GTF supported, 0 = not supported */

    s8        range_limit[5];         /* range_limit[0] = Min Vertical Rate in Hz
                                           range_limit[1] = Max Vertical Rate in Hz
                                           range_limit[2] = Min Horizontal Rate in kHz
                                           range_limit[3] = Max Horizontal Rate in kHz
                                           range_limit[4] = Max Supported pixel clock rate in MHz/10 */

    u32       dwNumVidSupport;        /* ֧�ֵ���Ƶ��ʽ�ĸ����� �����ڶ���ʾ�豸EDID��Ϣ�ķ�����
                                           ͨ��XXXX-XXX-XXX��������ȡ�������ʽ����Ƶ��ʽ����һ����Ƶ��ʽ
                                           ���Ƽ��ķֱ���*/
    u32       dwAudioSupport;         /* EDID�������Ƶ��֧�����������0��ʾ��֧����Ƶ */
} TVidOutTVInfo;


/* ��Ƶ��������ṹ���� */
typedef struct{
    u32	    dwVDPort;                   /* ������Ƶ�����: 0=vp1 1=vp2... */
    u32	    dwMuxChnlNum;               /* ��·��Ƶ���ã���0�Ļ�Ĭ��Ϊ1· */
    u32	    dwMuxMode;                  /* ��Ƶ���÷�ʽ��0=pix Mux; 1=line Mux */
    u32	    dwMuxChnlMask;              /* ��Ƶ����ͨ������: D[3-0]=chnl1 D[7-4]=chnl2 ... */
} TVidInMuxOutput;

/* TitleGenͼƬ���ݸ�ʽ�ṹ���� */
typedef struct{
    u32	    dwPicId;                    /* ͼƬ������������0��ʼ��� */
    u32	    dwPicWidth;                 /* ͼƬ���ݴ��ڿ�����Ϊ��λ */
    u32	    dwPicHeight;                /* ͼƬ���ݴ��ڸߣ���Ϊ��λ */
    u32	    dwPicFmt;                   /* ͼƬ���ݸ�ʽ��0Ĭ��ΪUYVY��16λYUV422��ʽ,1=YV16��ʽ */
    void    *pbyPicData;                /* ͼƬ�������û��ռ�ĵ�ַ */
    u32     dwPicSize;                  /* ͼƬ���ݵ��ֽ��� */
} TVidTitlePicLoad;


typedef struct{
    u32       dwIntfIn;                   /* TitleGen��Դ�ӿ�ѡ�� */
    TVidStd   tVidStd;                    /* ��Ƶ����ʽ */

    u32	    dwOsdPosX;                  /* OSD����X�������꣬����Ϊ��λ */
    u32	    dwOsdPosY;                  /* OSD����Y�������꣬��Ϊ��λ */
    u32	    dwOsdWidth;                 /* OSD���ڿ�����Ϊ��λ */
    u32	    dwOsdHeight;                /* OSD���ڸߣ���Ϊ��λ */

    u32         dwTransVal;                 /* ȫ��͸���ȣ���Χ: 0-0xff, Ϊ0ʱΪȫ͸��OSD�㲻����ϳɣ�Vid��ֱ��͸�� */
    u32       dwBackGroundY;              /* ȫ͸�ı���ɫY����ֵ����Χ: 0x10-0xf0, OSD��ÿ�����Yֵ���ڱ���ɫ�Ļ�
                                            ������ϳɣ�Vid��ֱ��͸���õ������ */

    u32	      dwDrawPicId;                /* ��ʾָ��������ͼƬ��ǰ����ָ��������ͼƬ�Ѿ��ϴ��� */
    u32	      dwDrawMode;                /* ͼƬ��ʾģʽ��0=��ֹ; 1=���������������OSD */
    u32       dwDrawTimes;                /* dwDrawMode!=0ʱ��Ч��ѭ����ʾ����OSDͼƬ�Ĵ��� */

    /* movement's step in hor direction */
    u32       dwDrawMvStep;
    /* movement's step in ver direction */
    u32       dwPauseLines;
    /* a loop consist of  N windows, the interval time between the (N-1) windows */
    u32       dwDrawMvDelay;
    /* a loop consist of  N windows, the interval time between the (N-1)  and N  window*/
    u32       dwPauseInterval;


    /* contain displayed window's num per loop  */
    u32       disp_win_num;
    /* the interval time between displayed window */
    u32       loop_osd_intval;
} TVidTitlePicDraw;



/* TitleGenͼƬ��ʾ״̬�ṹ���� */
typedef struct{
    u32	    dwPicId;                    /* ͼƬ������������0��ʼ��� */
    u32     dwDrawedTimes;              /* dwDrawMode!=0ʱ��Ч��ָʾ�Ѿ�ѭ����ʾ������OSDͼƬ�Ĵ��������������޴ι���ʱ��Ч */
} TVidTitleStat;

/* ��Ƶ��ʽ�ṹ���� */
typedef struct{
    u32 dwSampleRate;                   /* ����Ƶ��(Hz)��0=����Ƶ�������Ƶ; ����ֵΪ:8000,32000,48000,96000 */
    u32 dwSampleBits;                   /* ����λ��16bit/20bit/24bit/32bit */
	u32 dwChnlNum;                      /* ����������1/2/3(2.1)/6(5.1�űȻ���) */
} TAudStd;

/* E2PROM �����ṹ�� */
typedef struct{
    u32 dwHardwareVersion;
    u32 dwDeviceCode;
    u32 dwProductId;
    u32 dwHWSubVersion;
    u32 dwProductDate;
    s8  chDeviceSerial[11];
    s8  chFlowCode[7];
}TBrdE2PromInfo;

/*����mic�ṹ��*/
typedef struct {
	int magicnum;						/*��ʾ��������0x646d7675*/
	int len;							/*�汾�ĳ���*/
	int crc;							/*�汾���ݵ�crcУ����*/
	int ex;								/*Ŀǰδ�ã���Ϊ��չ*/
}dig_mic;

/*lm75�¶ȴ������澯�ӿ�*/
typedef struct{
	u32 temp_alarm;
}tempalarm;
/*lm75�������ṹ��*/
typedef struct {
	int temp;
	u32 temp_os;
	u32 temp_hyst;
}lm75;

/*----------------     For KDV9000A SMM      ------------------*/

/*
 *  �����л�����
 *  1) ��������Ȩ: �Ƚ���������Ϊhost��Ȼ���ټ�Ȿ�������״̬��������Ϊhost��
 *     ���ʾ�ɹ���ȡ������Ȩ��������Ϊ����ʹ�á�
 *  2) ��������Ȩ: ֱ�ӽ���������Ϊslave������԰�ԭ��Ϊslave���������ھ���host��
 *     ��԰彫��ȡ������Ȩ�����԰���Ϊhost������԰�ԭ��Ϊhost�ģ����������֡�
 *
 *  ע��: ��ʼ�����������Ӷ�Ϊ���壬��ҵ����߿�����������������״̬���ơ�
 */
 
#define CMD_HOST_SLAVE_CTL_SET     1
#define CMD_HOST_SLAVE_CTL_GET     0
#define HOST_SLAVE_STATUS_HOST     1
#define HOST_SLAVE_STATUS_SLAVE	   0

typedef struct host_slave_ctl
{
	int act;   /* 1 - set, 0 - get */
	int status; /* 0 - slave, 1 - host */
}TBrdHostSlaveCtl;

/*
 *  �������������λ��Ϣ��ѯ��ÿһ�����ش���һ�����:
 *
 *  [0]~[5],[8]~[13] --- 1~6,9~14���λ��LPU ý���;
 *  [6]~[7] --- 7~8���λ��MSUý�彻����;
 *  [14]~[17] --- ����AC��Դ��PEM0PRES ~ PEM3PRES;
 *  [18] --- ������;
 *  [19] --- ����һ��SMM�����λ״̬��
 *  [20]~[25] --- ����ģ�飬FAN0_PRES ~ FAN5_PRES;
 */
 
#define BRD_IS_IN_PLACE(p_info, idx) (!!(((p_info)->info) & (0x1 << (idx))))
#define BRD_NUM 26
typedef struct brd_in_place_info
{
	unsigned int info; /* bit[0] -- board 0.....bit[31] -- board 31,
						  1 -- borad in place, 0 -- means not */
}TBrdPresInfo;

/*
 * �����彡��״̬��ѯ�����
 * 1) ���ñ���Ľ���״̬: ��������Ϊ�������߲��������������ɶ԰����ã�Ҳ������
 *    ���ö԰�Ľ���״̬��
 * 2) ��ѯ����Ͷ԰�Ľ���״̬: ���Բ�ѯ������߶԰�Ľ���״̬��
 */

#define CMD_BRD_HEALTH_CTL_SET     1
#define CMD_BRD_HEALTH_CTL_GET     0
#define BRD_HEALTH_STATUS_HEALTHY  0
#define BRD_HEALTH_STATUS_ILL	   1

typedef struct brd_health_ctl
{
	int act;   /* 1 -- set, 0 -- get */
	int host;  /* 0 means healthy, 1 means not */
	int slave; /* 0 means healthy, 1 means not */
}TBrdHealthCtl;

/*
 * �����Ȳ���źż��
 * 1) ����û������Ȳ�ΰ�ť�����⵽1�������⵽0��
 */
typedef struct brd_hotplug_ctl
{
	int status; /* 1 means hot plug operation detected, 0 means not */
}TBrdHotPlugCtl;

/*----------------  end  For KDV9000A SMM      ------------------*/


/* �ṹ������
  link:  0-fail;    1-pass
  duplex: 0-half;   1-full
  speed: 10-10Mbps; 100-100Mbps; 1000-1000Mbps)
*/
typedef struct{
    u8 Link;                      /* ��̫���ӿ�����״̬ */
    u8 AutoNeg;                   /* ��̫���ӿ�Э�̣���״̬���ϴ�,ֻ��Ϊ�˼��������豸 */
    u8 Duplex;                    /* ��̫���ӿ�˫�� */
    u32 Speed;                     /* ��̫���ӿ����� */
}TBrdEthInfo;
#define SW_ETH_MAXNUM 				26

struct SWEthInfoRaw
{
	TBrdEthInfo eth_info[SW_ETH_MAXNUM];
} ;

#define INSIDE_ETH_MAXNUM 		16
#define FRONT_PANE_ETH_MAXNUM 	2
#define BACK_PANE_ETH_MAXNUM 	8

/*����оƬ�ṩ������ӿڷ�Ϊ���ࣺ�ֱ����ڲ�����ӿڣ�ǰ�������ӿڣ������2���ӿڣ��������ΪIS3-8548������ӿڣ�����������ӿ� */
struct SWEthInfo
{
	TBrdEthInfo inside_eth_info[INSIDE_ETH_MAXNUM];
	TBrdEthInfo front_eth_info[FRONT_PANE_ETH_MAXNUM];
	TBrdEthInfo back_eth_info[BACK_PANE_ETH_MAXNUM];
};

/*����boardinfo��cpuinfo��meminfo�ṹ��������ѯ������Ϣ*/
#define SIZE_WORD 32
#define SIZE_DWORD 64
#define SIZE_BYTE 8
/*ϵͳproc�ļ���Ϣ��/proc/boardinfo,/proc/meminfo,/proc/cpuinfo*/
typedef struct {
	u8 boardName[SIZE_WORD];/*board name*/
	u8 cpuType[SIZE_WORD];/*cpu*/
	u8 bootVer[SIZE_DWORD];/*boot version*/
	u8 kernelVer[SIZE_DWORD];/*kernel version*/
	u32 memSize;/*memory size*/
	u32 flashSize;/*flash size*/
	u32 cpuFreq;/*cpu frequency*/
	u32 memFreq;/*memory frequency*/
	u32 CPLDVer;/*CPLD version*/
	u32 FPGAVer;/*FPGA version*/

	u8 cpuName[SIZE_WORD];/*Processor*/
	float cpuBogoMIPS;/*BogoMIPS*/
	u8 cpuFeatures[SIZE_DWORD];/*Features*/
	u8  cpuImplementer[SIZE_BYTE];/*CPU implementer*/
	u32 cpuArch;/*CPU architecture*/
	u8 cpuVariant[SIZE_BYTE];/*CPU variant*/
	u8 cpuPart[SIZE_BYTE];/*CPU part*/
	u32 cpuRevision;/*CPU revision*/

	u8 brdHardware[SIZE_WORD];/*Hardware*/
	u32 brdRevision;/*Revision*/
	u8 brdSerial[SIZE_WORD];/*Serial*/

	u32 sysMemToltal;/*MemTotal*/
	u32 sysMemFree;/*MemFree*/
	u32 sysMemBuffers;/*Buffers*/
	u32 sysMemCached;/*Cached*/
}TBrdSysProcInfo;

typedef struct {
	u32 dwIpAdrs;/*ip��ַ�������ֽ���*/
	u32 dwIpMask; /*�������룬�����ֽ���*/
	u8  byMacAdrs[6];/*MAC��ַ�������ֽ���*/

	u8 brdDhcpStatus;/*DHCP״̬��1Ϊ���ã�0Ϊ������*/
	u32 brdDefGateway;/*Ĭ������*/
}TBrdNetInfo;

typedef struct {
    u32 byBoardID;   /*�豸ID��*/
    u32 byHwVer;     /*Ӳ���汾��*/
    u8 byFpgaVer;   /*FPGA�汾��*/
    u8 byBoardType; /*�豸���:0--�ն���;1--�����1(�в�λ�źͲ��);2--�����2(�в�λ���޲��) */
    u8 byEthNum;    /*�豸��̫������*/
    u8 byEth0Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byEth1Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byEth2Name[INTERFACE_NAME_MAX_LEN];/*�豸��̫��0������*/
    u8 byE1Num;     /*�豸E1������0������豸��֧��E1*/
    u8 byV35Num;    /*�豸V35����,0������豸��֧��V35*/
    u8 byBspNum;    /*�豸BSP����,0������豸û��BSP-15ý��оƬ*/
    u8 byFanCtrlSupport;    /*�豸�Ƿ�֧�ַ��ȿ���:0---��֧�֣�1---֧��*/
    u8 byRTCType;   /*�豸RTCоƬ������:����صĺ궨��--RTC_TYPE_NONE/RTC_TYPE_DS1337/RTC_TYPE_DS12C887*/
    u8 abyRS232Name[TTY_NAME_MAX_LEN];/*�豸RS232���ڶ�Ӧ���豸��/MPC��console�ڶ�Ӧ���豸��*/
    u8 abyRS422Name[TTY_NAME_MAX_LEN];/*�豸RS422���ڶ�Ӧ���豸��/MPC��SCC2��Ӧ���豸��*/
    u8 abyRS485Name[TTY_NAME_MAX_LEN];/*�豸RS485���ڶ�Ӧ���豸��/MPC��SCC3��Ӧ���豸��*/
    u8 abyIrayName[TTY_NAME_MAX_LEN]; /*�豸���⴮�ڶ�Ӧ���豸��*/
    s32 brdSubCardStat; /*�Ƿ����ӿ�*/
}TBrdHwInfo;

typedef struct {
	TBrdE2PromInfo brdE2PromInfo;
	TBrdHwInfo brdHwInfo;
	TBrdPosition brdBrdPosition;
	TBrdSysProcInfo brdSysProcInfo;
	TBrdNetInfo brdNetInfo[ETH_MAC_MAX_NUM];
}TBrdAllInfo;

#if 1
#define FUNCDISABLE        1       /*״̬��ֹ  */
#define FUNCENABLE       0       /*״̬ʹ��  */

#define DISTORT_1BTYE   (unsigned char)0        /* ���书�ܵ�ַ */
#define END_1BTYE           DISTORT_1BTYE+1 /*��ֹ��ַ */

#endif
/* ----------------------------- �����ӿڶ��� -------------------------------*/

/*====================================================================
    ������      : BrdWrapperInit
    ����        ����ģ��ĳ�ʼ��������Ӧ�ñ������ȵ��øú�����ɱ�ģ��ĳ�ʼ
                  ����������������ĳЩ�������޷������������ú������Զ�ε��á�
    �������˵������;
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
---------------------------------------------------------------------*/
STATUS BrdWrapperInit(void);

/*====================================================================
    ������      : BrdQryCapability
    ����        ����ѯ�豸��������֮ǰ������BrdWrapperInit��ʼ����
    �������˵������
    ����ֵ˵��  �����󷵻�NULL��
                �ɹ����ر�ģ��ά�����豸��������Ϣ��ȫ�ֽṹ�����ĵ�ַ���û�
                ��Ҫ����д�������������ƻ��������Ϣ
---------------------------------------------------------------------*/
TBrdCapability * BrdQryCapability(void);

/*====================================================================
    ������      : BrdGetBrdWrapperVer
    ����        ����ģ��汾�Ų�ѯ��
    �������˵����pchVer�� �����Ĵ�Ű汾��Ϣ��bufָ��
                 dwBufLen������buf�ĳ���
                 pdwVerLen���汾��ʵ���ַ������ȣ��ó��ȷ���֮ǰ�����dwBufLen
                           �Ƚ��Ƿ����������ʱ�Ŷ�pchVer��ֵ��
    ����ֵ˵��  ���ޡ����ʵ���ַ������ȴ���dwBufLen��pdwVerLen��ֵΪ0
---------------------------------------------------------------------*/
void  BrdGetBrdWrapperVer(s8 *pchVer, u32 dwBufLen, u32 *pdwVerLen);

/*====================================================================
    ������      : BrdGetBoardID
    ����        ���豸���ID��ѯ��
    �������˵������;
    ����ֵ˵��  ���磺��������ID�ź궨��
---------------------------------------------------------------------*/
u32  BrdGetBoardID(void);

/*====================================================================
    ������      : BrdGetMasterVideoMode
    ����        ��Get Mater Video Mode on KDM2860
    �������˵����NULL
    ����ֵ˵��  �� mode=1 VGA mode
   		   mode=0 HDMI mode
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    09/4/9            1.0            zhaoweixing        add BrdGetMasterVideoMode()
====================================================================*/
int BrdGetMasterVideoMode(void);

/*====================================================================
    ������      : BrdGetAlarmMuteStatus
    ����        ��Get Alarm Mute Status on KDM2860
    �������˵����NULL
    ����ֵ˵��  :		1: Alarm mute
    				    2: NO mute
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    09/5/5            1.0            mayichang       ����
====================================================================*/
int BrdGetAlarmMuteStatus(void);

/*================================
��������BrdGetFuncID
���ܣ��豸����ID��ѯ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ���幦��ID
==================================*/
u8  BrdGetFuncID(void);

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
    ������      : BrdQueryHWVersion
    ����        ��Ӳ���汾�Ų�ѯ��
    �������˵������;
    ����ֵ˵��  ��Ӳ���汾��,0~0xff
---------------------------------------------------------------------*/
u8  BrdQueryHWVersion (void);

/*====================================================================
    ������      : BrdQueryFPGAVersion
    ����        ��FPGA��EPLD�汾�Ų�ѯ��
    �������˵������;
    ����ֵ˵��  ��FPGA��EPLD�汾��,0~0xff
---------------------------------------------------------------------*/
u8  BrdQueryFPGAVersion (void);

/*====================================================================
    ������      : BrdQueryCPLDVersion 
    ����        ��FPGA��EPLD�汾�Ų�ѯ��
    �������˵������;
    ����ֵ˵��  ��FPGA��EPLD�汾��,0~0xff
---------------------------------------------------------------------*/
 u8  BrdQueryCPLDVersion (void);

/*====================================================================
    ������      : BrdLedStatusSet
    ����        �����õƵ�״̬
    �㷨ʵ��    ������ѡ�
    ����ȫ�ֱ�������
    �������˵����byLedID:�Ƶ�ID�ţ���brdwrapperdef.h����صĶ��壩
                byState:�Ƶ�״̬����brdwrapperdef.h����صĶ��壩
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS BrdLedStatusSet(u8 byLedID, u8 byState);

/*====================================================================
    ������      : BrdQueryLedState
    ����        ��ָʾ������ģʽ��ѯ
    �������˵����ptBrdLedState����ŵƵ�״̬�Ľṹ��ָ��
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
---------------------------------------------------------------------*/
STATUS BrdQueryLedState(TBrdLedState *ptBrdLedState);

/*====================================================================
    ������      : SysOpenWdGuard
    ����        ����ϵͳ��������
    �������˵���� dwNoticeTimeout��֪ͨ��Ϣʱ�䣬���Ӧ�ó��򳬹����ʱ��
                  ��û�е���SysNoticeWdGuardι����ϵͳ����λ��ʱ�䵥λΪ�롣
				 �������Ϊ0������ΪӦ�ó�����Ҫι������ϵͳ�Զ�ι����
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
---------------------------------------------------------------------*/
STATUS SysOpenWdGuard(u32 dwNoticeTimeout);

/*====================================================================
    ������      : SysCloseWdGuard
    ����        ���ر�ϵͳ������������ϵͳ����ι��
    �������˵������
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
---------------------------------------------------------------------*/
STATUS SysCloseWdGuard(void);

/*====================================================================
    ������      : SysNoticeWdGuard
    ����        ��Ӧ�ó���֪ͨ����ϵͳ�������С�����ϵͳ������Ӧ�ó����
                 ������ע�����趨��ʱ���ڵ�������ӿڣ�����ϵͳ����λ��
    �������˵������
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
---------------------------------------------------------------------*/
STATUS SysNoticeWdGuard(void);

/*====================================================================
    ������      : SysWdGuardIsOpened
    ����        ����ȡϵͳ����״̬��
    �������˵������
    ����ֵ˵��  ���򿪷���TRUE���رշ���FALSE
---------------------------------------------------------------------*/
BOOL32 SysWdGuardIsOpened(void);

/*====================================================================
    ������      : BrdGetAlarmInput
    ����        ����ѯ�ֳ��澯״̬��
    �������˵����byPort: �澯����˿ں�(KDM2402��2���澯���룬0-1)
                 pbyState: ��Ÿ澯����ֵ״̬��ָ�루ֵ���壺0:�͵�ƽ��1:�ߵ�ƽ��
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
---------------------------------------------------------------------*/
STATUS BrdGetAlarmInput(u8 byPort, u8* pbyState);

/*====================================================================
    ������      : BrdSetAlarmOutput
    ����        �������ֳ��澯
    �������˵����byPort: �澯����˿ں�(KDM2402��1���澯���룬0)
                 byState: 0:�Ͽ��澯�����·;1:��ͨ�澯�����·
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
---------------------------------------------------------------------*/
STATUS BrdSetAlarmOutput(u8 byPort, u8  byState);


/*====================================================================
    ������      : SysRebootEnable
    ����        ������ϵͳ����exceptionʱ�Զ���λ,������
    �������˵������
    ����ֵ˵��  ����
--------------------------------------------------------------------*/
void  SysRebootEnable (void);

/*====================================================================
    ������      : SysRebootDisable
    ����        ����ֹϵͳ����exceptionʱ�Զ���λ,������
    �������˵������
    ����ֵ˵��  ����
--------------------------------------------------------------------*/
void  SysRebootDisable(void);

/*====================================================================
    ������      : BrdHwReset
    ����        ��ϵͳӲ����λ,������
    �������˵������
    ����ֵ˵��  ����
--------------------------------------------------------------------*/
void  BrdHwReset(void);

/*====================================================================
    ������      : BrdFxoCtrl
    ����        ������ָ����FXO�豸ִ�н�����Ӧ�Ĳ���
    �������˵����byDevID:  ��չ�ã�Ŀǰ���0��
                 dwCmd�� ��������ID��
                    #define FXO_SET_HANGUP       0x00  �һ�
                    #define FXO_SET_PICKUP2CALL  0x01  ժ������
                    #define FXO_SET_TALK         0x02  ͨ��
                    #define FXO_SET_RCV_RING     0x03  ��������
                    #define FXO_EN_REMOTE_SPEAK  0x04  ����Զ˵绰�û�����
                    #define FXO_DIS_REMOTE_SPEAK 0x05  ��ֹ�Զ˵绰�û�����
                    #define FXO_EN_REMOTE_LISTEN 0x06  ����Զ˵绰�û������᳡����
                    #define FXO_DIS_REMOTE_LISTEN 0x07 ��ֹ�Զ˵绰�û������᳡����
                    #define FXO_GET_STATE        0x80  ��ѯFXO��ǰ״̬
                    #define FXO_SET_RING_VOLUME_IN   0x09		 ��·��������(AD->��·)
                    #define FXO_SET_RING_VOLUME_OUT   0x0a		  ��·��������(��·->AD)
                 pArgs����������dwCmd��أ�Ŀǰ�õ���������£���������û���NULL��
                    1)	FXO_GET_STATE
                    �鹤��״̬ʱ�û���Ҫ����һ��u32���ͱ�����ָ�룬���ӿ�д��
                    ��ǰFXO����״̬���������ֵ�������£�
                    #define FXO_STATE_RING       0x00   ����
                    #define FXO_STATE_PICKUP     0x01   ժ��
                    #define FXO_STATE_HANGUP     0x02   �һ�
                    2)	FXO_SET_RING_VOLUME_IN          ��·��������(AD->��·)
                    		����ֵ: 1��2��3��4 ��ֵԽ������Խ��
                    3)  FXO_SET_RING_VOLUME_OUT          ��·��������(��·->AD)
												����ֵ: 1��2��3��4 ��ֵԽ������Խ��
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
---------------------------------------------------------------------*/
STATUS BrdFxoCtrl(u8 byDevID, u32 dwCmd, void *pArgs);

/*====================================================================
    ������      : BrdQueryPosition
    ����        �������(ID����š���λ)��ѯ
    �������˵����ptBrdPosition�� �ɸú������ذ������Ϣ�Ľṹָ��,�û�����
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK�Ͱ������Ϣ��������TBrdPosition�ṹ����
--------------------------------------------------------------------*/
STATUS BrdQueryPosition(TBrdPosition *ptBrdPosition);

/*====================================================================
    ������      : BrdWakeup
    ����        �������豸
    �������˵������
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS  BrdWakeup(void);

/*====================================================================
    ������      : BrdSleep
    ����        �������豸
    �������˵������
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS  BrdSleep (void);

/*====================================================================
    ������      : BrdSetSpeakerMode
    ����        ������������ͨ��ģʽ
    �������˵����byMode: 0=�رգ�1=��
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS  BrdSetSpeakerMode (u8 byMode);

/*====================================================================
    ������      : BrdAlarmStateScan
    ����        ���ײ�澯��Ϣɨ��
    �㷨ʵ��    ������ѡ�
    ����ȫ�ֱ�������
    �������˵����ptBrdAlarmState:���صĸ澯��Ϣ
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
====================================================================*/
STATUS BrdAlarmStateScan(TBrdAlarmState *ptBrdAlarmState);

/*====================================================================
    ������      : BrdGetWirelessInput
    ����        ����ȡ����ң�����
    �������˵����pbyState:�������ң�������ָ��
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    08/05/14    1.0         ëһɽ        ����
====================================================================*/
STATUS BrdGetWirelessInput(u8* pbyState);

/*====================================================================
    ������      : BrdResetSubCard
    ����        ����λָ�����Ӱ忨����Ҫ100msʱ��󷵻�
    �������˵����bySubCardID: �ӿ���ţ�MPU���֧��7���ӿ�����Χ: 0~6
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS BrdResetSubCard(u8 bySubCardID);

/*====================================================================
    ������      : BrdShutDownSubCard
    ����        ���򿪹ر�ָ�����Ӱ忨���ϵ��Ĭ�������ӿ������ϵ�״̬
    �������˵����bySubCardID: �ӿ���ţ�MPU���֧��7���ӿ�����Χ: 0~6
                 bShutDown: TRUE=�ص�/FALSE=�ϵ�
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS BrdShutDownSubCard(u8 bySubCardID, BOOL32 bShutDown);

/*====================================================================
    ������      : BrdGetSubCardInfo
    ����        ����ѯ�ӿ���Ϣ��ĿǰMPU֧�ָù��ܡ�
    �������˵����dwSubCardID: �ӿ���ID�ţ��͵����й�:
                              MPU: 0~(MPU_SUBCARD_NUM-1)
                 ptBrdInfo: ����ӿ���Ϣ���û�����buf����ָ��
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS BrdGetSubCardInfo(u32 dwSubCardID, TBrdInfo *ptBrdInfo);

/*====================================================================
    ������      : BrdSelConsole
    ����        ���л��ⲿ��console�ӿڵ�ָ����cpu��
    �������˵����byCpuId: ��TS5210 TS6610 TS7210��0=master;1=slave
    ����ֵ˵��  ���ɹ�����OK ��ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS BrdSelConsole(u8 byCpuId);

/*====================================================================
    ������      : MspUpdate
    ����        ����¼MSP��Ƭ������
                  ע�⣺���ӿ�ʹ���˺��⴮�ڣ���˵��øýӿ�ʱ�û���ò�Ҫ
                  �򿪺��⴮�ڡ�
    �������˵����byDevID: �豸ID����0��ʼ���
                 pbyFileName: ��Ƭ�������ļ���
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS MspUpdate(u8 byDevID, s8 *pbyFileName);

/*====================================================================
    ������      : MspStm8Update
    ����        ����¼���ⵥƬ������
                  ע�⣺���ӿ�ʹ���˺��⴮�ڣ���˵��øýӿ�ʱ�û���ò�Ҫ
                  �򿪺��⴮�ڡ�
    �������˵����byDevID: �豸ID����0��ʼ���
                 pbyFileName: ��Ƭ�������ļ���
    ����ֵ˵��  ���ɹ�����OK,ʧ�ܷ���ERROR
--------------------------------------------------------------------*/
STATUS MspStm8Update(u8 byDevID, s8 *pbyFileName);

/*====================================================================
    ������      : IRDisplayTest
    ����        ��IRDISPLAY���ⵥƬ����ʾ���Գ���
    �㷨ʵ��    ������ѡ�
    ����ȫ�ֱ�������
    �������˵������
    ����ֵ˵��  ���ɹ�����IRDISPLAY_OK��ʧ�ܷ���ϵͳ����Ĵ�����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    08/12/10    1.0         ��־��        ����
====================================================================*/
STATUS IRDisplayTest(char ver[]);
/*====================================================================
    ������      : SysLoadFpga
    ����        : װ��FPGA����
    �������˵�� : bForceLoad: TRUE=���ܵ�ǰfpga�Ƿ��г���ǿ������װ��
                            FALSE=����Ѿ����ع��������������أ���ʡʱ��
                 pbyFileName:
    ����ֵ˵��  : OK = �ɹ���ERROR = ʧ��
--------------------------------------------------------------------*/
STATUS SysLoadFpga(BOOL32 bForceLoad, u8 *pbyFileName);

/*====================================================================
    ������      : FpgaProgramOpen
    ����        : ׼����ʼfpga���
    �������˵�� : ��
    ����ֵ˵��  : OK = �ɹ���ERROR = ʧ��
--------------------------------------------------------------------*/
STATUS FpgaProgramOpen(void);

/*====================================================================
    ������      : FpgaProgramWrite
    ����        : ��fpgaд��һ�����ݣ����ε���ǰ�����ȵ���BcsrProgramFpgaOpen��
                  �ɶ�ε��ã�ֱ��д����������
    �������˵�� : pbyData:����ָ�룻dwSize:���ݴ�С
    ����ֵ˵��  : OK = �ɹ���ERROR = ʧ��
--------------------------------------------------------------------*/
STATUS FpgaProgramWrite(u8 *pbyData, u32 dwSize);

/*====================================================================
    ������      : BcsrProgramFpgaClose
    ����        : ����fpga��̣�ͬʱ����fpga
    �������˵�� : ��
    ����ֵ˵��  : OK = �ɹ���ERROR = ʧ��
--------------------------------------------------------------------*/
STATUS FpgaProgramClose(void);

/*====================================================================
    ������      : BrdDetectedHaltSignal
    ����        ����ѯ�Ƿ��⵽ϵͳ�����źţ�һ���ð���������
    �������˵������
    ����ֵ˵��  ��FALSE=������TRUE=��⵽ϵͳ�����ź�
--------------------------------------------------------------------*/
BOOL32 BrdDetectedHaltSignal(void);

/*====================================================================
    ������      : BrdDetectedWakeupSignal
    ����        ����ѯ�Ƿ��⵽ϵͳ�����źţ�һ���ð���������
    �������˵������
    ����ֵ˵��  ��FALSE=������TRUE=��⵽ϵͳ�����ź�
--------------------------------------------------------------------*/
BOOL32 BrdDetectedWakeupSignal(void);

/*====================================================================
    ������      : BrdDetectedDefaultSignal
    ����        ����ѯ�Ƿ��⵽ϵͳ�ָ�ȱʡ�����źţ�һ���ð���������
    �������˵������
    ����ֵ˵��  ��FALSE=������TRUE=��⵽ϵͳ�ָ�ȱʡ�����ź�
--------------------------------------------------------------------*/
BOOL32 BrdDetectedDefaultSignal(void);

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

/*====================================================================
    ������      : BrdGetHdmiRxAudInfo
    ����        ����ȡָ��HDMI�������ӿڵ���Ƶ��Ϣ��������ʡ�����λ��
    �������˵���� dwDevId: HDMI������0��ʼ��ţ�
                  ptInfo:  ָ��HDMI�ӿڵ���Ƶ��Ϣ,�û����䣬������д
    ����ֵ˵��  ��OK = �ɹ���ERROR = ʧ��
====================================================================*/
STATUS  BrdGetHdmiRxAudInfo(u32 dwDevId, THdmiAudInfo *ptInfo);

/*====================================================================
    ������      : BrdSetHdmiTxAudInfo
    ����        ������ָ��HDMI�������ӿڵ���Ƶ������������ʡ�����λ��
    �������˵���� dwDevId: HDMI������0��ʼ��ţ�
                  ptInfo:  ָ��HDMI�ӿڵ���Ƶ��Ϣ,�û�����
    ����ֵ˵��  ��OK = �ɹ���ERROR = ʧ��
====================================================================*/
STATUS  BrdSetHdmiTxAudInfo(u32 dwDevId, THdmiAudInfo *ptInfo);

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
STATUS BrdTimeGet( struct tm* ptTime);


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
STATUS BrdTimeSet( struct tm* ptTime );

/*====================================================================
    ������      : BcsrTi81xxEdma
    ����        ��Ti81xx Edma
    �������˵����srcPhyAddr: Դ�����ַ
    			  dstPhyAddr: Ŀ�������ַ
    			  size: ���ݴ�С
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    13/03/11    1.0        ������        ����
====================================================================*/
STATUS BcsrTi81xxEdma(u32 srcPhyAddr, u32 dstPhyAddr, u32 size);

/*====================================================================
    ������      : BcsrTi81xxGetReservedMem
    ����        ����ȡ����ռ�
    �������˵����dwPhyAddr: �����ַ
    			  dwVirAddr: �����ַ
    			  dwLen: ���ݴ�С
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    13/03/11    1.0        ������        ����
====================================================================*/
u32 BcsrTi81xxGetReservedMem(u32 *dwPhyAddr, u32 *dwVirAddr, u32 dwLen);

/*====================================================================
    ������      : BcsrTi81xxEdmaFill2D
    ����        ��Ti81xx Edma
    �������˵����srcPhyAddr: Դ�����ַ
    			  dstPhyAddr: Ŀ�������ַ
    			  width:	  2D����Ŀ�
    			  height:	  2D����ĸ�
    			  sync:	  	  ͬ������
    ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    13/05/20    1.0        ������        ����
====================================================================*/
STATUS BcsrTi81xxEdmaFill2D(u32 srcPhyAddr, u32 dstPhyAddr, u32 width, u32 height, u32 sync);

/*====================================================================
    ������      : BcsrTi81xxEdma2DFill
    ����        ��Ti81xx Edma 2D Fill
    �������˵����pixPhyAddr: Դ�����ַ
    			  dstPhyAddr: Ŀ�������ַ
    			  width:	  2D����Ŀ�
    			  height:	  2D����ĸ�
    			  pitch:	  Ŀ��ͬ������
    			  bpp:		  �����ֽ���
    ����ֵ˵��  ��0�����ߴ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    13/07/04    1.0        ������        ����
====================================================================*/
u32 BcsrTi81xxEdma2DFill(u32 pixPhyAddr, u32 dstPhyAddr, u32 width, u32 height, u32 pitch, u32 bpp);

/*================================
��������BrdSetRtcToSysClock
���ܣ���rtcʱ����Ϊϵͳʱ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdSetRtcToSysClock(void);

/*================================
��������BrdSetSysToRtcClock
���ܣ���ϵͳʱ����Ϊrtcʱ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdSetSysToRtcClock(void);


/*================================
��������BrdOpenSerial
���ܣ��ṩ��ҵ����Rs232 Rs422 Rs485���⴮��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byPort���ڶ˿ں�(t300�Ĵ��������������豸�࣬������һ�׶˿ں�)
              #define SERIAL_RS232                 0
              #define SERIAL_RS422                 1
              #define SERIAL_RS485                 2            H600����SE600Ҳ���øö˿�
              #define BRD_SERIAL_INFRARED          3
T300��Ӧ�Ķ˿ں�:
#define SERIAL_RS232                 	0
#define BRD_SERIAL_RS422_0	   4
#define BRD_SERIAL_RS422_1            5
#define BRD_SERIAL_RS422_2            6
#define BRD_SERIAL_232_422_485_0	7
#define BRD_SERIAL_232_422_485_1      8
#define BRD_SERIAL_232_422_485_2      9
#define BRD_SERIAL_232_422_485_3      10
#define BRD_SERIAL_232_422_485_4      11
#define BRD_SERIAL_232_422_485_5      12
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
Ŀǰ�����Ѳ�֧�ָýӿ�
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
Ŀǰ�����Ѳ�֧�ָýӿ�
==================================*/
s32  BrdRs485TransSnd (s32 nFd, u8 *pbyMsg, u32 dwMsgLen);


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
������      : BrdGetSensorStat
����        ����ѯ��ǰϵͳ��Ӧ����״̬
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����sensor��ŷ�����Ϣ�Ľṹָ�롣
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetSensorStat(lm75 * sensor);


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

/*================================
������      : BrdGetSysInfo
����        ����ѯ��ǰϵͳ��Ϣ
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����SysInfo��ŷ�����Ϣ�Ľṹָ�롣
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetSysInfo(TBrdSysInfo *SysInfo);


/*================================
������      : BrdSetIrPin
����        ����ѯ����ʹ���ĸ�����ң��
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����pin��0��7
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdSetIrPin(u8 pin);


/*================================
������      : BrdSlaveGetOutputMode
����        ����ϵͳ��ȡ��Ƶ���ģʽ
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ��  1 ��ʾN �ƣ�0 ��ʾP �ƣ�
					-1 ��ʾ��ϵͳ���ô˺���?					������ʾ����
==================================*/
STATUS BrdSlaveGetOutputMode(void);


/*================================
������      : BrdGetVgaVideoState
����        ��
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
����ֵ˵��  ��
==================================*/
s32 BrdGetVgaVideoState(void);

/* --------------------------------------��Ƶ�����������ģ��----------------------------------- */

/*====================================================================
    ������      : VidInApiMapIntfToVP
    ����        :ӳ��ָ��VP�ڶ�Ӧ����������ӿ�
    �������˵�� : dwCapChipId: ȡֵ��궨��: ��Ƶ�ɼ�оƬ����, �����������ɼ�оƬ
                   dwVPId: ��Ƶ�ɼ���������0�� ����������ͬ�ɼ�оƬ�ϲ�ͬ��VP��
                   dwInterface: ��Ӧ����Ƶ�ӿ����ƣ�
                                ȡֵ��:��Ƶ��������ӿ����ͺ궨��;
                                �����Ҫ������ڽ�֡����Ӧ����VID_DIV2��
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
---------------------------------------------------------------------*/
s32 VidInApiMapIntfToVP (u32 dwCapChipId, u32 dwVPId, u32 dwInterface);

/*====================================================================
    ������      : VidInApiCtrl
    ����        ����Ƶ�ɼ�оƬ���ƺ���
    �������˵�� :dwInterface: ��Ӧ����Ƶ�ӿ����ƣ��磺��Ƶ��������ӿ����ͺ궨��
                               �����Ҫ������ڽ�֡����ʱ����������ӿ���ʽ
                               cmd=VID_CTRL_SET_STDʱӦ����VID_DIV2��
		         cmd�����������: ��Ƶ��������豸�������ͺ궨�壻arg������
		         cmd = VID_CTRL_SET_STD/VID_CTRL_GET_STDʱarg��(TVidStd*)ָ��
		         cmd = ����������(int *)ָ��
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
--------------------------------------------------------------------*/
s32 VidInApiCtrl (u32 dwInterface, s32 cmd, void *arg);

/*====================================================================
    ������      : VidOutApiSelVidOutSrc
    ����        : ѡ��ָ����Ƶ����ڶ�Ӧ����ƵԴ�ӿ�
    �������˵�� :dwOutIntf: ��Ƶ����ӿڣ�ȡֵ�磺��Ƶ��������ӿ����ͺ궨��
                             �����Ҫ���������֡����Ӧ����VID_DBL2��
                 dwSrcIntf:  ��ƵԴ�Ľӿڣ�ȡֵ�磺��Ƶ��������ӿ����ͺ궨��
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
---------------------------------------------------------------------*/
s32 VidOutApiSelVidOutSrc (u32 dwOutIntf, u32 dwSrcIntf);

/*====================================================================
    ������      : VidOutApiCtrl
    ����        ����Ƶ����оƬ���ƺ���
    �������˵�� :dwInterface: ��Ӧ����Ƶ�ӿ����ƣ���:��Ƶ��������ӿ����ͺ궨��
                               �����Ҫ���������֡��������������ӿ���ʽ
                               cmd=VID_CTRL_SET_STDʱӦ����VID_DBL2��
		         cmd�����������: ��Ƶ��������豸�������ͺ궨�壻arg������
		         cmd = VID_CTRL_SET_STD/VID_CTRL_GET_STDʱarg��(TVidStd*)ָ��
		         cmd = ����������(int *)ָ��
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
--------------------------------------------------------------------*/
s32 VidOutApiCtrl (u32 dwInterface, s32 cmd, void *arg);


/* --------------------------------------��Ƶ�����������ģ��----------------------------------- */

/*====================================================================
    ������      : AudInApiCtrl
    ����        ����Ƶ�ɼ�оƬ���ƺ���
    �������˵�� :dwInterface: ��Ӧ����Ƶ�ӿ����ƣ��磺��Ƶ��������ӿ����ͺ궨��
		         cmd�����������: ��Ƶ��������豸�������ͺ궨��궨�壻arg������
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
--------------------------------------------------------------------*/
s32 AudInApiCtrl (u32 dwInterface, s32 cmd, void *arg);

/*====================================================================
    ������      : AudOutApiCtrl
    ����        ����Ƶ����оƬ���ƺ���
    �������˵�� :dwInterface: ��Ӧ����Ƶ�ӿ����ƣ��磺��Ƶ��������ӿ����ͺ궨��
		         cmd�����������: ��Ƶ��������豸�������ͺ궨��궨�壻arg������
    ����ֵ˵��  : ���󷵻�ERROR���ɹ�����OK
----------------------------------------------------------------------*/
s32 AudOutApiCtrl (u32 dwInterface, s32 cmd, void *args);


/*****************************************************************************
 ********************  E2PROM ����ģ�� ***************************************
 ****************************************************************************/

/*====================================================================
������      : BrdGetE2PromInfo
����        ����ѯ��ǰ�豸E2Prom��Ϣ�Ľӿ�
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����  ptBrdE2PromInfo:ָ��TBrdE2PromInfo�ṹ���ָ��
����ֵ˵��  ��OK/ERROR
====================================================================*/
STATUS BrdGetE2PromInfo (TBrdE2PromInfo* ptBrdE2PromInfo);


/*================================
��������BrdClearE2promTestFlag
���ܣ����eeprom����λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdClearE2promTestFlag(void);

/*================================
��������BrdSetE2promTestFlag
���ܣ����eeprom����λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdSetE2promTestFlag(void);

/*================================
��������BrdGetE2promTestFlag
���ܣ����eeprom����λ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� ��Ҫ���Է���TRUE�����򷵻�FALSE
==================================*/
BOOL32 BrdGetE2promTestFlag(void);

/*================================
��������BrdE2promGetUserdata
���ܣ���ȡ�û��Զ�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����cmd:���ܺţ�buf:���ص�����
����ֵ˵���� �ɹ�����0�����򷵻�-1
==================================*/
int BrdE2promGetUserdata(unsigned char cmd, void *buf);

/*================================
��������BrdE2promGetUserdata
���ܣ������û��Զ�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����0�����򷵻�-1
==================================*/
int BrdE2promSetUserData(unsigned char cmd , void * buf);

/*================================
��������BrdGetE2promIpAddr
���ܣ���ò����ڼ�ip��ַ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwIpAddr:�ص����ص�IP��ַ�����ֽ���
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdGetE2promIpAddr(u32* pdwIpAddr);


/*================================
��������BrdTestEEPromFunc
���ܣ���֤eeprom�Ķ�д���ܣ���ȫ��������eeprom��������д�롢���ݶ�ȡ��У�顣
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����OK�����򷵻�ERROR
==================================*/
STATUS BrdTestEEPromFunc(void);

/*================================
��������BrdEEPromGetPal
���ܣ���ȡ��pal����ntsc��ʽ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� pal����OK��ntsc����ERROR
==================================*/
STATUS BrdEEPromGetPal(void);

/*================================
��������BrdEEPromSetPal
���ܣ�������pal����ntsc��ʽ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����setֵΪ0��ʾpal�ƣ�Ϊ1��ʾntsc��
����ֵ˵���� �ɹ�����OK��ʧ�ܷ���ERROR
==================================*/
s32 BrdEEPromSetPal(s32 set);

/*================================
��������BrdEEPromGetOutputMode
���ܣ�������pal����ntsc��ʽ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����ֵ˵����
			����ֵΪ2��ʾ���ΪP�ƣ�4ΪN�ƣ�6ΪVGA��0��ʾ�������
			#define EEPROM_LOG_OUTPUT_NULL	0x00
			#define EEPROM_LOG_OUTPUT_PAL	0x02
			#define EEPROM_LOG_OUTPUT_NTSC	0x04
			#define EEPROM_LOG_OUTPUT_VGA	0x06
==================================*/
STATUS BrdEEPromGetOutputMode(void);


/*================================
��������BrdEEPromSetOutputMode
���ܣ�������pal����ntsc��ʽ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����setֵΪ��
				#define EEPROM_LOG_OUTPUT_NULL	0x00
				#define EEPROM_LOG_OUTPUT_PAL	0x02
				#define EEPROM_LOG_OUTPUT_NTSC	0x04
				#define EEPROM_LOG_OUTPUT_VGA	0x06

����ֵ˵���� �ɹ�����OK��ʧ�ܷ���ERROR
==================================*/
s32 BrdEEPromSetOutputMode(s32 set);

/*=========================================
��������BrdAd5246GetSensitivity
���ܣ�  get sensititvity from ad5246.
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����ֵ˵����
			0---127:valid
			other:invalid
==========================================*/
s32 BrdAd5246GetSensitivity(void);

/*=========================================
��������BrdAd5246SetSensitivity
���ܣ�  get sensititvity from ad5246.
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����valueֵΪ0--127 valid;
					    other invalid

����ֵ˵���� �ɹ�����OK��ʧ�ܷ���ERROR
==========================================*/
STATUS BrdAd5246SetSensitivity(int  value);
/*=========================================
��������BrdEEPromSetHwSubVersion
���ܣ� set hardware sub version in e2prom
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����hwsubver: hardware sub version

����ֵ˵���� �ɹ�����OK��ʧ�ܷ���ERROR
==========================================*/
STATUS BrdEEPromSetHwSubVersion(unsigned short hwsubver);

/*=========================================
��������BrdEEPRromSetProductid
���ܣ� set product id in e2prom
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����pid:product id

����ֵ˵���� �ɹ�����OK��ʧ�ܷ���ERROR
==========================================*/
STATUS BrdEEPRromSetProductid(unsigned int pid);

/* =====================================
��������BrdEEPromSetUserData
���ܣ��û��Զ�����������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����˵��
				pUserData: ָ���û��Զ�������
				length: ���ݳ���
����ֵ˵��  ��OK/ERROR
=====================================*/
STATUS BrdEEPromSetUserData(void *pUserData,u32 length);

/* =====================================
��������BrdEEpromGetFlagBit
���ܣ���ȡ��־λflagλpos״̬
����˵��:flagΪ0��ʾΪ��־λ0��flagΪ1��ʾ��־λΪ1
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����ֵ˵����
				��ȡʧ�ܷ���-1
				�ɹ��򷵻�״̬
=====================================*/
unsigned int BrdEEpromGetFlagBit(int flag, unsigned int pos);

/* =====================================
��������BrdEEpromSetFlagBit
���ܣ����ñ�־λflagλpos״ֵ̬value
����˵��:flagΪ0��ʾΪ��־λ0��flagΪ1��ʾ��־λΪ1
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����ֵ˵����
				����ʧ�ܷ���-1
				�ɹ��򷵻�0
=====================================*/
int BrdEEpromSetFlagBit(int flag, unsigned int pos, int value);

/* =====================================
��������BrdEEPromGetUserData
���ܣ���ȡ�û��Զ�������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
����ֵ˵����
				��ȡʧ�ܷ���NULL
				�ɹ��򷵻�void *
=====================================*/
void *BrdEEPromGetUserData(void);

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
��������BrdMPCFanBrdSetFanSpeed
���ܣ���Դ���ѹֵAD
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byState: 0~100��Ӧ�ٶȰٷֱȣ�Ӧ��10%���ϣ�
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCFanBrdSetFanSpeed(u8 bySpeed);

/*================================
��������MPCFanBrdSetSpeaker
���ܣ����Ȱ�Speaker����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byState :Bit0��1���죻0�����죻
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCFanBrdSetSpeaker(u8 byState);

/*================================
��������BrdMPCFanBrdGetVersion
���ܣ���ȡ�汾����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����	id :  	0��Ӧ��ذ壻1��Ӧ���Ȱ�
					    version: ���ذ汾��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCFanBrdGetVersion(u8 id, u16* version);

/*================================
��������BrdMPCLedBrdGetVoltage
���ܣ���Դ���ѹֵAD
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dbyVol5:  12V AD��ѹ=���ֽ�.���ֽڣ�V������0.1V��
					    dbyVol12: 5V AD��ѹ=���ֽ�.���ֽڣ�V������0.1V��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCLedBrdGetVoltage(u16* dbyVol5, u16* dbyVol12);

/*================================
��������BrdMPCLedBrdTempCheck
���ܣ���Դ���¶Ȳɼ�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����pbyPowerTempRst������״̬
					   0x02λ��ʾ�ҵ�Դ״̬��0���¶�������1���¶��쳣��
					   0x01λ��ʾ���Դ״̬��0���¶�������1���¶��쳣��

����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCLedBrdTempCheck(u8* pbyPowerTempRst);

/*================================
��������BrdMPCFanBrdGetFanSpeed
���ܣ���Դ���ѹֵAD
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byState : 0~7��Ӧ8������ID
					   *speed: �����ٶ�ָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdMPCFanBrdGetFanSpeed(u8 byState, u16* Speed);

/*================================
��������MPCFanBrdSetFanSpeed
���ܣ���Դ���ѹֵAD
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����bySpeed: 0~100��Ӧ�ٶȰٷֱȣ�Ӧ��10%���ϣ�
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS MPCFanBrdSetFanSpeed(u8 bySpeed);
/*================================
������      : BrdGetSensor
����        ����ѯ�������澯   :��ѹ�澯���¶�ת����Ϣ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�����g_tBrdCapability
�������˵����sensor��ŷ�����Ϣ�Ľṹָ��TSensorAll
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetSensor(TBrdSensor *sensor);
/*====================================================================
������      : BcsrE1AllAlmDetail
����        ���ж��豸���е�E1�ӿڵĸ澯��Ϣ
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵���� TBrdE1AlarmDetail ����E1����E1 ģ����ϸ�澯��Ϣ

����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
====================================================================*/
STATUS AllE1AlmDetail(TBrdE1AlarmAll *e1AlmArray);

/*================================
������      : BrdGetSensorAlarm
����        ����ѯ�豸��Ӧ���ĸ澯״̬����ѹ���¶ȣ�����ת�ٸ澯
�㷨ʵ��    ��
����ȫ�ֱ�������
�������˵����TSensorAll��sensor�澯��Ϣ�ṹָ��
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdGetSensorAlarm(TBrdSensorAlarm *sensorAlarm);
/*====================================================================
������      : BrdGetAlarm
����        ����ȡ�ն����и澯��Ϣ��E1����ѹ���¶ȡ�����ת��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����g_tBrdCapability
�������˵����TBrdKDVAlarm���ն˸澯��Ϣ�ṹ��ָ��
����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
====================================================================*/
STATUS BrdMtGetAlarm(TBrdKDVAlarm *Alarm);

/*====================================================================
������      : get_kernel_log
����        ����ȡ�ں˴�ӡ��Ϣ��
�������˵����buf������ָ�룻sizeΪbuf��С��pathnameΪ��ѡ��,ΪҪд����ļ���
����ֵ˵��  ��pathnameΪNULL���ɹ�����ret��pathname��ΪNULL���ɹ�����0.
====================================================================*/
STATUS get_kernel_log(char *buf, int size,char *pathname);

/*====================================================================
������      : update_dig_mic
����        ������mic��������
�������˵��: buffΪ���ݻ�����,lenΪ�汾����,uart_numΪ����mic�����豸�ţ�0 or 1��
����ֵ˵��  �������ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
STATUS update_dig_mic(char* buff, int len, int uart_num);

/*===================================================================
������      : get_lm75temp_alarm
����        ����ȡlm75�¶ȴ��������¶ȸ澯״̬
�������˵����sensoralarm Ϊ�����tempalarm�ṹ��ָ��
����ֵ˵��  ���ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
STATUS get_lm75temp_alarm(tempalarm *sensoralarm);

/*====================================================================
������      : get_digmic_ver
����        ������mic�汾�Ų�ѯ
�������˵��: ver_bufΪ���հ汾�ŵ�ָ��,uart_numΪ����mic���ں�(0 or 1)
����ֵ˵��  ����ѯ�ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
int get_digmic_ver(char *ver_buf, int uart_num);

/*================================
������      : BrdSwitchPort
����        ��H600�����л�UART2�Ĺ���
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������������ͷ��0������ͷ������1������mic������2.
==================================*/
s32 BrdSwitchPort(u8 mode);


/*================================
������      : BrdSwitchPort
����        ��MPU2��ѯ�Ƿ����ӿ�
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
==================================*/
s32 BrdMpu2HasEcard(void);

/*================================
������      : MspLpc2368Update
����        ��h600 Msp Lpc2368 update
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵������
==================================*/
STATUS MspLpc2368Update(s8 *pbyFileName);

/*===================================================================
������      : SwGetEthNego
����        ����ȡ����оƬ������״̬
�������˵����sw_eth_info Ϊ�����SWEthInfo�ṹ��ָ��
����ֵ˵��  ���ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
STATUS SwGetEthNego(struct SWEthInfo *sw_eth_info );

/*===================================================================
������      : DaughterBoardClockConfig
����        �������Ӱ�ʱ��,ֻ�� �������Խ׶ε��ã�Ŀǰֻ֧��APU2 KDV8000I
�������˵������
����ֵ˵��  ���ɹ�����OK��ʧ�ܷ���ERROR
====================================================================*/
STATUS DaughterBoardClockConfig(void);

/*====================================================================
������      : BcsrLogicIn
����        ����ȡ�߼���״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byPort,��Ӧ���߼���(0-7)
����ֵ˵������Ӧ���߼���״̬(0/1),0xff�򷵻�ʧ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
     12/11/21    1.0         ������          ����
====================================================================*/
u8 BcsrLogicIn(u8 byPort);

/*====================================================================
������      : BcsrLogicOut
����        ���趨�߼��ڵ�״̬
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byPort,��Ӧ���߼���(0-7);byState,��Ӧ���߼���״̬(0/1)
����ֵ˵���� 0Ϊ������-1Ϊ�쳣
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    12/11/21    1.0         ������          ����
====================================================================*/
STATUS BcsrLogicOut(u8 byPort, u8 byState);

/*================================
��������BrdTestUsb
���ܣ���Nip Usb ���Ժ���
�㷨ʵ�֣� 1.�Զ�������ǰ���ڵ�usb�豸��2.�Զ�mount ����usb�豸�ĵ�һ����������ʧ�ܽ�����error
           3.mount�ɹ��󣬽���ָ��Ŀ¼��д�ļ�������ļ��Ƿ���ȷ����ɾ�������ļ��������ļ�����ɾ���ļ�������error
		   4.umount usb�豸����
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �ɹ�����0�����򷵻�-1
==================================*/
STATUS BrdTestUsb(void);
/*====================================================================
������      : MicIndicate
����        ��micָʾ��״̬�趨����
�㷨ʵ��    ������ѡ�
����ȫ�ֱ�������
�������˵����byPort,��Ӧ��mic��ţ�(0-7);byState,��Ӧ��ָʾ��״̬(0,Ϩ��/1������)
����ֵ˵���� 0Ϊ������-1Ϊ�쳣
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    12/11/21    1.0         ������          ����
====================================================================*/
STATUS MicIndicate(u8 byPort, u8 byState);

/*================================
������      : BrdOpenKlog
����        ����syslogd
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdOpenKlog(void);


/*================================
������      : BrdCloseKlog(void)
����        ���ر�syslogd
�㷨ʵ��    ��
����ȫ�ֱ�����
�������˵����
����ֵ˵���� ���󷵻�ERROR���ɹ�����OK
==================================*/
STATUS BrdCloseKlog(void);

/*====================================================================
 ������      : BrdGetAllInfo
 ����        ��obtain board information
 �㷨ʵ��    ������ѡ�  �0�3�0�2
 �������˵����ptBrdAllInfo�ǰ��Ӱ���Ӳ�������磬ϵͳ��Ϣָ�룬��ȡ�������е���Ϣ
 ����ֵ˵��  �����󷵻�ERROR���ɹ�����OK
 ----------------------------------------------------------------------
 �޸ļ�¼    ����  ��      �汾        �޸���        �޸�����
               05/27/13    1.0          ��ר          ����
 ====================================================================*/
STATUS BrdGetAllInfo(TBrdAllInfo *ptBrdAllInfo);

/*====================================================================
 ������: BcsrGetMSUMainMode
 ����  : ��ȡmsu���ӵ�����״̬
 �������: isMain -- ���ڻ�ȡ����������ָ��
           #define BRD_MSU_STANDBY_MODE		0	isMainΪ0������Ϊ����
           #define BRD_MSU_MAIN_MODE		1	isMainΪ1������Ϊ����
           #define BRD_MSU_MAIN_MODE_ERR	0xFF	isMainΪ0xFF������״̬����                           
 ����ֵ˵��: 0Ϊ������-1Ϊ�쳣
 ----------------------------------------------------------------------
 �޸ļ�¼    ����  ��      �汾        �޸���        �޸�����
               05/27/14    1.0          ��ר          ����
 ====================================================================*/
/*KDV9000A MSU����״̬*/
#define BRD_MSU_STANDBY_MODE    0    /*MSU ����״̬*/ 
#define BRD_MSU_MAIN_MODE       1    /*MSU ����״̬*/
#define BRD_MSU_MAIN_MODE_ERR   0xFF /*MSU ����״̬����*/
STATUS BcsrGetMSUMainMode(u8 *isMain);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BRD_WRAPPER_H */

