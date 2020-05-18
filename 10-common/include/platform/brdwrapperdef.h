/******************************************************************************
ģ����  �� BrdWrapper
�ļ���  �� brdwrapperdef.h
����ļ���
�ļ�ʵ�ֹ��ܣ�BrdWrapperģ������ṩ�ĺ궨��ͷ�ļ������ļ�Ŀǰ��ҪӦ���ڼ���豸�弶��
            ��������
����    : �ŷ���
�汾    ��1.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
12/27/2006  1.0        �ŷ���      ����
******************************************************************************/
#ifndef __BRD_WRAPPER_DEF_H
#define __BRD_WRAPPER_DEF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* ��������ID�ź궨�� */
#define UNKNOWN_BOARD               0xff  /* δ������豸 */

#define BRD_KDM2418                 0x02  /* ���ǰ���豸 */
#define BRD_KDM2518                 0x03  /* ���ǰ���豸 */

#define BRD_KDM2400P                0x10  /* ���ǰ���豸 */

#define BRD_KDM2464LS               0x22  /* ���ǰ���豸 */
#define BRD_KDM2110                 0x23  /* ���ǰ���豸 */
#define BRD_KDM2422S                0x24  /* ���ǰ���豸 */
#define BRD_KDM2422LS               0x25  /* ���ǰ���豸 */
#define BRD_KDM2421S                0x26  /* ���ǰ���豸 */
#define BRD_KDM2421LS               0x27  /* ���ǰ���豸 */
#define BRD_KDM2110L                0x28  /* ���ǰ���豸 */
#define BRD_KDM2300                 0x29  /* ���ǰ���豸 */
#define BRD_KDM2300P                0x2a  /* ���ǰ���豸 */

#define BRD_KDM2561                 0x30  /*  ���ǰ���豸 */
#define BRD_KDM2401                 0x39   /* KDM2401������ */
#define BRD_KDM2401ES               0x3a   /* KDM2401ES������ */
#define BRD_KDM2424LS               0x3b  /*  ���ǰ���豸 */
#define BRD_KDM2501                 0x3c   /* KDM2501������ */
#define BRD_KDM2401S                0x46   /* 2401S������ */
#define BRD_KDM2402                 0x47   /* 2402������ */
#define BRD_KDM2402S                0x48   /* 2402S������ */
#define BRD_KDM2401L                0x49   /* 2402S������ */
#define BRD_KDM2461                 0x4a   /* 2461������ */
#define BRD_KDM2461L                0x4b   /* 2461L������ */
#define BRD_KDM2401LS               0x4c   /* 2401LS������ */
#define BRD_KDM2402L                0x4d   /* 2402L������ */
#define BRD_KDM2402LS               0x4e   /* 2402LS������ */
#define BRD_KDM201C04               0x4f  /*  ���ǰ���豸 */
#define BRD_KDM201C04L              0x50   /* KDM201C04L������ */
#define BRD_KDM201D04               0x51   /* KDM201D04������ */

#define BRD_KDM2440                 0x52   /* KDM2440������ */
#define BRD_KDM2440P                0x53   /* KDM2440P������ */
#define BRD_KDM2462                 0x54   /* ��KDM2402��ͬ */
#define BRD_KDM2462L                0x55   /* ��KDM2402L��ͬ */
#define BRD_KDM2462S                0x56   /* ��KDM2402S��ͬ */
#define BRD_KDM2462LS               0x57   /* ��KDM2402LS��ͬ */
#define BRD_KDM2461LS               0x58   /* ��KDM2401LS��ͬ */
#define BRD_KDM2461S                0x59   /* ��KDM2401S��ͬ */
#define BRD_KDM2100                 0x5a  /*  ���ǰ���豸 */
#define BRD_KDM2100W                0x5b  /*  ���ǰ���豸 */
#define BRD_KDM2100P                0x5c  /*  ���ǰ���豸 */

#define BRD_KDM2820                 0x20   /* KDM2820 */
#define BRD_KDM2820_4               0x2B   /*KDM2820*/
#define BRD_KDM2820_9               0x2C   /*KDM2820*/
#define BRD_KDM2820_16              0x2D   /*KDM2820*/
#define BRD_KDM2820E_9              0x2E   /*KDM2820*/
#define BRD_KDM2820E_16             0x2F   /*KDM2820*/
#define BRD_KDM2404S                0x3b   /* KDM2404S������ */
#define BRD_KDM200_MPU              0x3d   /* KDM200�����е�MPU�� */

#define BRD_KDM200_APC              0x42   /* KDM200�����е�APC�� */

#define BRD_KDV8000BHD              0x6E   /* KDV8000B-HD �������ײ�Ʒ */

#define BRD_TS6610                  0x70   /* TS6610��Ƶ�ն�, KDV8220A���������� */
#define BRD_TS5210                  0x71   /* TS5210��Ƶ�ն�, KDV8220B���������� */
#define BRD_V5                      0x72   /* V5��Ƶ�ն�, KDV8220C���������� */
#define BRD_TS6610E                 0x73   /* TS6610E��Ƶ�ն� */
#define BRD_TS6210                  0x74   /* TS6210��Ƶ�ն� */
#define BRD_TS6210E                 0x80   /* TS6210E��Ƶ�ն� */

#define BRD_TS3210                  0xa0   /* TS3210��Ƶ�ն� */
#define BRD_TS5610                  0x75   /* TS5610��Ƶ�ն� */
#define BRD_TS3610                  0x76   /* TS3610��Ƶ�ն� */
#define BRD_TS7210                  0x77   /* TS7210��Ƶ�ն� */
#define BRD_TS7610                  0x78   /* TS7610��Ƶ�ն� */
#define BRD_KDV7810                 0x7b   /* KDV7810��Ƶ�ն� */
#define BRD_KDV7910                 0x7c   /* KDV7910��Ƶ�ն� */

#define BRD_KDVM26401               0xf0   /* KDVM26401�豸 */
#define BRD_KDVM26402               0xf1   /* KDVM26402�����壬�ǹ�˾���壬�Ժ�ɾ�� */
#define BRD_MPC8247_2DM642          0x96   /* MPC8247_2DM642�����壬�ǹ�˾���壬�Ժ�ɾ�� */

/******************************************************************/
/***     New Board Type defines (PID/HID)                       ***/
/******************************************************************/
#define BRD_HWID_KDM2421E           0x003E
#define BRD_HWID_KDM2210            0x0040
#define BRD_HWID_KDM2700	    			0x0041  /*  ���ǰ���豸 */
#define BRD_HWID_DSL8000_MPU        0x0042
#define BRD_HWID_EBAP               0x0043
#define BRD_HWID_EVPU               0x0044
#define BRD_HWID_MAU                0x0045
#define BRD_HWID_KDM200_HDU         0x0046
#define BRD_HWID_KDM2310            0x004A  /*  ���ǰ���豸 */
#define BRD_HWID_KDM2311            0x004B  /*  ���ǰ���豸 */
#define BRD_HWID_KDV7620            0x001F  /* KDV7620��Ƶ�ն� */
#define BRD_HWID_KDV7820            0x0021  /* KDV7820��Ƶ�ն� */
#define BRD_HWID_H600_H 	   		0x012c  /* KDV_H600�߶���Ƶ�ն� */
#define BRD_HWID_H600_L	   	  		0x012d  /* KDV_H600�Ͷ���Ƶ�ն� */
#define BRD_HWID_H700 	            0x012E  /* KDV_H700��Ƶ�ն� */
#define BRD_HWID_H800 	            0x0161  /* KDV_H800��Ƶ�ն� */
#define BRD_HWID_H850 	            0x01bb  /* KDV_H850��Ƶ�ն� */
#define BRD_HWID_H900 	            0x012F  /* KDV_H900��Ƶ�ն� */
#define BRD_HWID_MPU2				0x0134
#define BRD_HWID_HDU2				0x0135
#define BRD_HWID_APU2				0x0136	/* APU2�� */
#define BRD_HWID_KDV8000I			0x0147  /*KDV8000I*/
#define BRD_HWID_T300               0x0154  /* T300 BOARD */
#define BRD_HWID_IPA100             0x0100  /*  NVR���ǰ���豸 */
#define BRD_HWID_IPA101             0x0067  /*  NVR���ǰ���豸 */
#define BRD_HWID_IPC201             0x006A  /*  NVR���ǰ���豸 */
#define BRD_HWID_NVR2860            0x0101  /*NVR2860*/
#define BRD_HWID_MPC2   		 	0x010C      /* MPC2�� */
#define BRD_HWID_DRI2   		 	0x010E      /* DRI2�� */
#define BRD_HWID_CRI2			 	0x010D 	    /*CRI2��*/
#define BRD_HWID_IS2_1   		 	0x010F  /* IS2.1�� ��ӦMPC8313ϵͳ*/
#define BRD_HWID_IS2_2   		 	0x0110  /* IS2.2�� ��ӦMPC8548ϵͳ*/
#define BRD_HWID_EAPU			 0x0111	/*EAPU��*/
#define BRD_HWID_KDV9000A_SMM		0x222	/* KDV9000A SMM���ذ� */
#define BRD_HWID_KDV9000A_MSU		0x333	/* KDV9000A MSU���ذ� */


/* ָʾ�Ʋ��ֺ궨�� */
#define BRD_LED_NUM_MAX             32     /* ָʾ�Ƽ��޸��� */

#define BRD_LED_ON                  1      /* ָʾ��״̬: �� */
#define BRD_LED_OFF                 2      /* ָʾ��״̬: �� */
#define BRD_LED_QUICK               3      /* ָʾ��״̬: ����(0.25����->0.25����->0.25����...) */
#define BRD_LED_SLOW                4      /* ָʾ��״̬: ����(1����->1����->1����...) */
#define BRD_LED_STANDBY             5      /* ָʾ��״̬: standby(2����->2����->2����...) */

/* BrdLedStatusSet������ָʾ�ƿ���ID */
#define LED_E1_ID_BASE              0xd0
#define LED_E1_ID(ix)               (LED_E1_ID_BASE+ix)      /* ģ����0��E1�澯��*/
#define LED_E1_ID0                  LED_E1_ID(0)/*0��E1�ĸ澯��*/
#define LED_E1_ID1                  LED_E1_ID(1)/*1��E1�ĸ澯��*/
#define LED_E1_ID2                  LED_E1_ID(2)/*2��E1�ĸ澯��*/
#define LED_E1_ID3                  LED_E1_ID(3)/*3��E1�ĸ澯��*/
#define LED_E1_ID4                  LED_E1_ID(4)/*4��E1�ĸ澯��*/
#define LED_E1_ID5                  LED_E1_ID(5)/*5��E1�ĸ澯��*/
#define LED_E1_ID6                  LED_E1_ID(6)/*6��E1�ĸ澯��*/
#define LED_E1_ID7                  LED_E1_ID(7)/*7��E1�ĸ澯��*/
#define LED_E1_ID8                  LED_E1_ID(8)/*8��E1�ĸ澯��*/
#define LED_E1_ID9                  LED_E1_ID(9)/*9��E1�ĸ澯��*/
#define LED_E1_ID10                 LED_E1_ID(10)/*10��E1�ĸ澯��*/
#define LED_E1_ID11                 LED_E1_ID(11)/*11��E1�ĸ澯��*/
#define LED_E1_ID12                 LED_E1_ID(12)/*12��E1�ĸ澯��*/
#define LED_E1_ID13                 LED_E1_ID(13)/*13��E1�ĸ澯��*/
#define LED_E1_ID14                 LED_E1_ID(14)/*14��E1�ĸ澯��*/
#define LED_E1_ID15                 LED_E1_ID(15)/*15��E1�ĸ澯��*/

#define LED_SYS_ALARM               0xe0   /* ϵͳ�澯�ƣ����а�����Ч */
#define LED_SYS_LINK                0xe1   /* ϵͳ���ӵ�(���ְ���ȡ��ACT)�����а�����Ч */
#define LED_BOARD_LED_NORM          0xe2   /* �ư�������ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_BOARD_LED_NALM          0xe3   /* �ư���һ��澯ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_BOARD_LED_SALM          0xe4   /* �ư������ظ澯ָʾ�ƣ�����KDV8000����ư���Ч */
#define LED_CDMA_LED                0xe5   /* KDM2417��CDMA�� */
#define LED_WLAN_LED                0xe6   /* KDM2417��WLAN�� */
#define LED_DISK_LED                0xe7   /* KDM2417�ϴ洢��ָʾ�� */
#define LED_MPC_OUS                 0xe8   /* mpc���ous���ߵƣ�����ͬ���ã�ͬ������� */
#define LED_VIDEO_IN0               0xe9   /* ��Ƶ����ָʾ��0 */
#define LED_VIDEO_IN1               0xea   /* ��Ƶ����ָʾ��1 */
#define LED_VIDEO_IN2               0xeb   /* ��Ƶ����ָʾ��2 */
#define LED_VIDEO_IN3               0xec   /* ��Ƶ����ָʾ��3 */
#define LED_SYS_RUN                 0xef   /* ϵͳ���еƣ����а�����Ч */
#define LED_ENCODER_RUN             0xf0   /* KDV7810 ENCODER LED */
#define LED_DECODER_RUN             0xf1   /* KDV7810 DECODER LED */
#define LED_MPC_SYN				0xf2   /*mpcǰ����syn ָʾ�� */
#define LED_CRI2_MS				0xf3   /*CRI2������*/


/* KDV9000A SMM����ָʾ�ƶ��� */
#define LED_HOT_PLUG				0x1		/* �Ȳ��ָʾ�� */
#define LED_RUN_G					0X2		/* ������ɫָʾ�� */
#define LED_RUN_R					0x3		/* ���к�ɫָʾ�� */
#define LED_OSS_G					0x4		/* ����״̬��ɫָʾ�� */
#define LED_OSS_R					0x5		/* ����״̬��ɫָʾ�� */
#define LED_ALM_1_G					0x6		/* �澯1��ɫָʾ�� */
#define LED_ALM_1_R					0x7		/* �澯1��ɫָʾ�� */
#define LED_ALM_2_G					0x8		/* �澯2��ɫָʾ�� */
#define LED_ALM_2_R					0x9		/* �澯2��ɫָʾ�� */
#define LED_ALM_3_G					0xa		/* �澯3��ɫָʾ�� */
#define LED_ALM_3_R					0xb		/* �澯3��ɫָʾ�� */
#define LED_PRES					0xc		/* ������λ�� */


/*-----------------T2ָʾ��˵��-------------------------------
     |   ����        ����        ����           ��
-------------------------------------------------------------
�̵�    |   ��������    ң���ź�     ����������
�ȵ�    |   ����        ����         ������         ��������
*/
#define LED_GREEN                   0xed   /* ��ɫָʾ�� */
#define LED_ORANGE                  0xee   /* ��ɫָʾ��,���̵�ͬʱҲ��ʱ������ɫ�ڸ� */
#define LED_RED                     0xef   /* ��ɫָʾ�� */

#define LED_DSP_ID_BASE             0xf0
#define LED_DSP_ID(ix)              (LED_DSP_ID_BASE+ix) /* DSPָʾ�� */
#define LED_DSP_ID0                 LED_DSP_ID(0)   /* 0��DSPָʾ�� */
#define LED_DSP_ID1                 LED_DSP_ID(1)   /* 1��DSPָʾ�� */
#define LED_DSP_ID2                 LED_DSP_ID(2)   /* 2��DSPָʾ�� */
#define LED_DSP_ID3                 LED_DSP_ID(3)   /* 3��DSPָʾ�� */
#define LED_DSP_ID4                 LED_DSP_ID(4)   /* 4��DSPָʾ�� */
#define LED_DSP_ID5                 LED_DSP_ID(5)   /* 5��DSPָʾ�� */

/*CRI2 ǰ��幦��ָʾ��fun1 ~ fun8*/
#define LED_FUN_ID_BASE              0xc0
#define LED_FUN_ID(ix)               (LED_FUN_ID_BASE+ix)   /* ģ����0��E1�澯��*/
#define LED_FUN_ID1                  	LED_FUN_ID(0)		/*1�Ź���ָʾ��*/
#define LED_FUN_ID2                  	LED_FUN_ID(1)		/*2�Ź���ָʾ��*/
#define LED_FUN_ID3                  	LED_FUN_ID(2)		/*3�Ź���ָʾ��*/
#define LED_FUN_ID4                  	LED_FUN_ID(3)		/*4�Ź���ָʾ��*/
#define LED_FUN_ID5                  	LED_FUN_ID(4)		/*5�Ź���ָʾ��*/
#define LED_FUN_ID6                  	LED_FUN_ID(5)		/*6�Ź���ָʾ��*/
#define LED_FUN_ID7                  	LED_FUN_ID(6)		/*7�Ź���ָʾ��*/
#define LED_FUN_ID8                  	LED_FUN_ID(7)		/*8�Ź���ָʾ��*/



/*KDV8000A ������Ȱ�ָʾ��1 ~ 8*/
#define FAN_LED_FUN_ID_BASE              0xa0
#define FAN_LED_FUN_ID(ix)               (FAN_LED_FUN_ID_BASE+ix)   /* ģ����0��E1�澯��*/
#define FAN_LED_FUN_ID1                  	FAN_LED_FUN_ID(0)		/*1�Ź���ָʾ��*/
#define FAN_LED_FUN_ID2                  	FAN_LED_FUN_ID(1)		/*2�Ź���ָʾ��*/
#define FAN_LED_FUN_ID3                  	FAN_LED_FUN_ID(2)		/*3�Ź���ָʾ��*/
#define FAN_LED_FUN_ID4                  	FAN_LED_FUN_ID(3)		/*4�Ź���ָʾ��*/
#define FAN_LED_FUN_ID5                  	FAN_LED_FUN_ID(4)		/*5�Ź���ָʾ��*/
#define FAN_LED_FUN_ID6                  	FAN_LED_FUN_ID(5)		/*6�Ź���ָʾ��*/
#define FAN_LED_FUN_ID7                  	FAN_LED_FUN_ID(6)		/*7�Ź���ָʾ��*/
#define FAN_LED_FUN_ID8                  	FAN_LED_FUN_ID(7)		/*8�Ź���ָʾ��*/

/* KDV8000�������������غ궨�� */
#define LED_BOARD_SPK_OFF           0x00   /* �ر������� */
#define LED_BOARD_SPK_ON            0x01   /* ���������� */


/*RTCоƬ���Ͷ���*/
#define RTC_TYPE_NONE               0
#define RTC_TYPE_DS1337             1
#define RTC_TYPE_DS12C887           2
#define RTC_TYPE_PCF8563            3

/* ��������ֵ���� */
#define OK                          0
#define ERROR                       -1
#define STATUS                      int

/* ���õļ���ֵ���� */
#define INTERFACE_NAME_MAX_LEN      10     /* �ӿ����Ƶ���󳤶� */
#define TTY_NAME_MAX_LEN            20     /* �����豸������󳤶� */
#define STR_NAME_MAX_LEN            16     /* �����ַ�������󳤶� */
#define ETH_MAC_MAX_NUM             8      /* ��̫��MAC��ַ�������� */
#define MPU_SUBCARD_NUM             7      /* MPU��֧�ֵ��ӿ����� */

/* FXOģ���������ID */
#define FXO_SET_HANGUP              0x00   /* �һ� */
#define FXO_SET_PICKUP2CALL         0x01   /* ժ������ */
#define FXO_SET_TALK                0x02   /* ͨ�� */
#define FXO_SET_RCV_RING            0x03   /* �������� */
#define FXO_EN_REMOTE_SPEAK         0x04   /* ����Զ˵绰�û����� */
#define FXO_DIS_REMOTE_SPEAK        0x05   /* ��ֹ�Զ˵绰�û����� */
#define FXO_EN_REMOTE_LISTEN        0x06   /* ����Զ˵绰�û������᳡���� */
#define FXO_DIS_REMOTE_LISTEN       0x07   /* ��ֹ�Զ˵绰�û������᳡���� */
#define FXO_GET_STATE               0x80   /* ��ѯFXO��ǰ״̬ */
#define FXO_SET_RING_VOLUME_IN      0x09   /*��·��������(AD->��·)*/
#define FXO_SET_RING_VOLUME_OUT     0x0a   /* ��·��������(��·->AD)*/

/* FXO����״̬ */
#define FXO_STATE_RING              0x00   /* ���� */
#define FXO_STATE_PICKUP            0x01   /* ժ�� */
#define FXO_STATE_HANGUP            0x02   /* �һ� */

/* ���Ź��궨�� */
#define WATCHDOG_USE_CLK            0x00   /* ʱ��Ӳ��ι�� */
#define WATCHDOG_USE_SOFT           0x01   /* ���ι�� */
#define WATCHDOG_STOP               0x02   /* ֹͣι�� */

/* ϵͳ�澯�궨�� */
#define BRD_ALM_NUM_MAX             256    /* ���澯��Ԫ���� */

/*----- ��չ����Ƶ�ӿں궨��,��dwInterface|VIDOUT_INTF_EXP��ʾ��Ч----
  ----- ��ʱadwExtIntf��������ʹ������ʾһ��оƬ֧�ֵĶ��ֽӿ�   ---- */
#define VID_INTF_EXP                  0x20000000  /* ��չ��������Ƶ�ӿڵı�־ */
#define VID_INTF_TYPE                 0x0f000000  /* ��Ƶ�ӿ��������� */
#define VID_INTF_ID                   0x000000ff  /* ��Ƶ�ӿ��������� */
#define VID_INTF_HDMI                 0x01000000  /* HDMI��Ƶ�ӿڱ�ʶ */
#define VID_INTF_VGA                  0x02000000  /* VGA��Ƶ�ӿڱ�ʶ */
#define VID_INTF_YPbPr                0x03000000  /* YPbPr��Ƶ�ӿڱ�ʶ */
#define VID_INTF_SDI                  0x04000000  /* SDI��Ƶ�ӿڱ�ʶ */
#define VID_INTF_C                    0x05000000  /* C������Ƶ�ӿڱ�ʶ */
#define VID_INTF_S                    0x06000000  /* S������Ƶ�ӿڱ�ʶ */
#define VID_INTF_DVI                  0x07000000  /* DVI��Ƶ�ӿڱ�ʶ */

#define VID_INTF_HDMI_(x)             (VID_INTF_EXP | VID_INTF_HDMI  | (x&VID_INTF_ID))
#define VID_INTF_VGA_(x)              (VID_INTF_EXP | VID_INTF_VGA   | (x&VID_INTF_ID))
#define VID_INTF_YPbPr_(x)            (VID_INTF_EXP | VID_INTF_YPbPr | (x&VID_INTF_ID))
#define VID_INTF_SDI_(x)              (VID_INTF_EXP | VID_INTF_SDI   | (x&VID_INTF_ID))
#define VID_INTF_C_(x)                (VID_INTF_EXP | VID_INTF_C     | (x&VID_INTF_ID))
#define VID_INTF_S_(x)                (VID_INTF_EXP | VID_INTF_S     | (x&VID_INTF_ID))
#define VID_INTF_DVI_(x)              (VID_INTF_EXP | VID_INTF_DVI   | (x&VID_INTF_ID))
/* --------------------------------------------------------------- */


/* ---------------- ��Ƶ��������ӿ����ͺ궨�� ---------- */
/* ����ӿ� */
#define VID_SHUT_DOWN                 0x00000000
#define VID_HDMI0                     0x00000001
#define VID_HDMI1                     0x00000002
#define VID_HDMI2                     0x00000004
#define VID_HDMI3                     0x00000008
#define VIDIN_HDMI4                   0x00800000  /* S���Ӽ���ʹ�ã�����һ�� */
#define VID_HDMI_81xx                 0x00400000


//#define VID_PE1005S                   0x0d    /* HD HDMI/VGA/YPbPr receiver */
//#define VID_SE600                     0x10    /* SE600��о����ӦH600-L�ͺ� */

#define VID_VGA0                      0x00000010
#define VID_VGA1                      0x00000020
#define VID_VGA2                      0x00000040
#define VID_VGA3                      0x00000080
#define VID_YPbPr0                    0x00000100
#define VID_YPbPr1                    0x00000200
#define VID_YPbPr2                    0x00000400
#define VID_YPbPr3                    0x00000800
#define VID_SDI0                      0x00001000
#define VID_SDI1                      0x00002000
#define VID_SDI2                      0x00004000
#define VID_SDI3                      0x00008000
#define VID_C0                        0x00010000
#define VID_C1                        0x00020000
#define VID_C2                        0x00040000
#define VID_C3                        0x00080000
#define VID_S0                        0x00100000
#define VID_DVI0                      0x01000000
#define VID_DVI1                      0x02000000
#define VID_DVI2                      0x04000000
#define VID_DVI3                      0x08000000
#define VID_CAMERA0               	  0x10000000

/* ����ͷ��о���� */
#define VIDIN_PE1005S                   0x0d
#define VIDIN_SE600                     0x10
#define VIDIN_PE1005					0x12


/* �ӿڱ�־ */
#define VID_DIV2                      0x40000000  /* ��Ҫ����֡����ʱ����ӿ���Ҫ���ϸú� */
#define VID_DBL2                      0x40000000  /* ��Ҫ����֡����ʱ����ӿ���Ҫ���ϸú� */

/* �����豸��VP���������DSP����Ƶ����VP�� */
#define VID_PLAY0_VP0                 0x80000000   /* h900�У�8168����vout0����� */
#define VID_PLAY0_VP1                 0x80000001   /* h900�У�8168����HDMI����� */
#define VID_PLAY0_VP2                 0x80000002
#define VID_PLAY0_VP3                 0x80000003
#define VID_PLAY0_VP4                 0x80000004

#define VID_PLAY1_VP0                 0x80010000
#define VID_PLAY1_VP1                 0x80010001
#define VID_PLAY1_VP2                 0x80010002
#define VID_PLAY1_VP3                 0x80010003
#define VID_PLAY1_VP4                 0x80010004

#define VID_PLAY2_VP0                 0x80020000
#define VID_PLAY2_VP1                 0x80020001
#define VID_PLAY2_VP2                 0x80020002
#define VID_PLAY2_VP3                 0x80020003
#define VID_PLAY2_VP4                 0x80020004

#define VID_PLAY3_VP0                 0x80030000
#define VID_PLAY3_VP1                 0x80030001
#define VID_PLAY3_VP2                 0x80030002
#define VID_PLAY3_VP3                 0x80030003
#define VID_PLAY3_VP4                 0x80030004

/* ������������VP�� */
#define VID_DEC0_VP0                  0x80100000
#define VID_DEC0_VP1                  0x80100001
#define VID_DEC0_VP2                  0x80100002
#define VID_DEC0_VP3                  0x80100003
#define VID_DEC0_VP4                  0x80100004
#define VID_DEC0_VP5                  0x80100005
#define VID_DEC0_VP6                  0x80100006
#define VID_DEC0_VP7                  0x80100007

#define VID_DEC1_VP0                  0x80110000
#define VID_DEC1_VP1                  0x80110001
#define VID_DEC1_VP2                  0x80110002
#define VID_DEC1_VP3                  0x80110003
#define VID_DEC1_VP4                  0x80110004
#define VID_DEC1_VP5                  0x80110005
#define VID_DEC1_VP6                  0x80110006
#define VID_DEC1_VP7                  0x80110007

#define VID_DEC2_VP0                  0x80120000
#define VID_DEC2_VP1                  0x80120001
#define VID_DEC2_VP2                  0x80120002
#define VID_DEC2_VP3                  0x80120003
#define VID_DEC2_VP4                  0x80120004
#define VID_DEC2_VP5                  0x80120005
#define VID_DEC2_VP6                  0x80120006
#define VID_DEC2_VP7                  0x80120007

#define VID_DEC3_VP0                  0x80130000
#define VID_DEC3_VP1                  0x80130001
#define VID_DEC3_VP2                  0x80130002
#define VID_DEC3_VP3                  0x80130003
#define VID_DEC3_VP4                  0x80130004
#define VID_DEC3_VP5                  0x80130005
#define VID_DEC3_VP6                  0x80130006
#define VID_DEC3_VP7                  0x80130007

/* ����OSD���Ӻ��VP�� */
#define VID_FPGAOSD_VP0               0x80200000    /* ������ЩVP�ڲ���ϳ��Ӱ��Ӷ��� */

/* Resizer���VP�� */
#define VID_RESIZER_VP0               0x80300000

/* TITLE��Ļ���Ӻ��VP�� */
#define VID_TITLE_VP0                 0x80400000

/* ��Ƶ�ɼ�оƬ���� */
#define VID_CAP_VP_DSP                0x00000000    /* DSP��Ƶ�ɼ�оƬ��DSP����DM6437 DM647
                                                       ���ͬһ�������ͬʱ���ڶ���DSP�Ļ����ڴ�����˵��
                                                       ÿһƬDSP������ֵ������ǵ�����DSP�Ļ�����0��ʼ��� */
#define VID_CAP_VP_ENC                0x00010000    /* ��������Ƶ�ɼ�оƬ������������FPGA_ENCODER, TAOS;
                                                       ���ͬһ�������ͬʱ���ڶ��ֱ������Ļ����ڴ�����˵��
                                                       ÿһƬ������������ֵ������ǵ����ͱ������Ļ�����0��ʼ���*/

#define VID_CAP_VP_DM8168           0x00020000    /* DM8168 */

#define VID_CAP_VP_DSP0               (VID_CAP_VP_DSP | 0x00) /* h900�У�8168оƬ�� */
#define VID_CAP_VP_DSP1               (VID_CAP_VP_DSP | 0x01)
#define VID_CAP_VP_DSP2               (VID_CAP_VP_DSP | 0x02)
#define VID_CAP_VP_DSP3               (VID_CAP_VP_DSP | 0x03)

#define VID_CAP_VP_ENC0               (VID_CAP_VP_ENC | 0x00)
#define VID_CAP_VP_ENC1               (VID_CAP_VP_ENC | 0x01)
#define VID_CAP_VP_ENC2               (VID_CAP_VP_ENC | 0x02)
#define VID_CAP_VP_ENC3               (VID_CAP_VP_ENC | 0x03)


/* ��Ƶ��������豸�������ͺ궨�� */
#define VID_CTRL_SET_BRIGHTNESS         1   /* �������� */
#define VID_CTRL_SET_CONTRAST           2   /* ���öԱȶ� */
#define VID_CTRL_SET_HUE                3   /* ����ɫ�� */
#define VID_CTRL_SET_SATURATION         4   /* ���ñ��Ͷ� */
#define VID_CTRL_SET_STD                5   /* ������Ƶ��ʽ��arg����Ϊ��TVidStd */
#define VID_CTRL_GET_STD                6   /* ��ѯ��Ƶ��ʽ��arg����Ϊ��TVidStd */
#define VID_CTRL_GET_INTF_TYPE          7   /* ��ѯ���ýӿڵ�ǰ������, Դ���뿪�粢��������Ӧ�Ľӿ� */
#define VID_CTRL_SET_SHARPNESS          8   /* ������� */
#define VID_CTRL_SET_NOISEFILT          9   /* ���ý���ϵ�� */
                                            /* ����OSD������dwInterface = VID_FPGAOSD_VP0 */
#define VID_CTRL_SET_OSD                10  /* ���ýӿ�FPGA��OSDģ�飬arg����Ϊ��TVidOsdParam */
#define VID_CTRL_START_OSD              11  /* ����OSDģ��ϳ������arg����Ϊ��NULL */
#define VID_CTRL_STOP_OSD               12  /* ֹͣOSDģ��ϳ������arg����Ϊ��NULL */

                                            /* ����Resizer������dwInterface = VID_RESIZER_VP0 */
#define VID_CTRL_SET_RESIZER            13  /* ���ýӿ�FPGA��OSDģ�飬arg����Ϊ��TVidResizeParam */
#define VID_CTRL_START_RESIZER          14  /* ����RESIZERģ�������arg����Ϊ��NULL */
#define VID_CTRL_STOP_RESIZER           15  /* ֹͣRESIZERģ�������arg����Ϊ��NULL */

#define VID_CTRL_LOAD_TITLE_PIC         16  /* ������ĻͼƬ���ݣ�arg����Ϊ��TVidTitlePicLoad */
#define VID_CTRL_START_TITLE            17  /* ��ʼ��Ļ���ӣ�arg����Ϊ��TVidTitlePicDraw */
#define VID_CTRL_STOP_TITLE             18  /* �ر���Ļ���ӣ�arg����Ϊ��(u32 *)&dwPicId */
#define VID_CTRL_GET_TITLE_STAT         23  /* ��ѯ��Ļ��ʾ״̬��arg����Ϊ��TVidTitleStat */

#define VID_CTRL_SET_CLK_PHASE          19  /* ����VGA����ģʽʱʱ����λ��arg����Ϊ��(u32 *)
                                               ��λֵ,��Χ0-31��Ч�������������ȣ��������嶶����
                                               ����ɫ������ */
#define VID_CTRL_GET_CLK_PHASE          20  /* ��ѯVGA����ģʽʱʱ����λ��arg����Ϊ��(u32 *) */
#define VID_CTRL_SET_FILT               21  /* ����ͼ���˲���arg����Ϊ��(u32 *)
                                               0=�ر� ��0=�򿪣��򿪺�ͼ��������ģ��һЩ��
                                               ���ǿ��Խ�һ���������嶶�����⣻�رպ�ͼ����������� */
#define VID_CTRL_GET_FILT               22  /* ��ѯͼ���˲���arg����Ϊ��(u32 *) */
/*#define VID_CTRL_GET_TITLE_STAT       23     ��ѯ��Ļ��ʾ״̬��arg����Ϊ��TVidTitleStat */

#define VID_CTRL_GET_TV_INFO            24  /* ��ѯ��������ӵ�TV��Ϣ��arg����Ϊ: TVidOutTVInfo */

#define VID_CTRL_INIT_VIDEO_INFO        25  /* initiate video configure to fpga */
#define VID_CTRL_SET_MUXOUT_MODE        26  /* ������Ƶ�������ģʽ��arg����Ϊ: TVidInMuxOutput */
#define VID_CTRL_SEL_CAMERA             27 /* Select different camera on different h600 board */
#define VID_CTRL_GET_FOCUS              28  /* ��ȡ����ͷ�Խ� */
#define VID_CTRL_SET_FOCUS              29  /* ��������ͷ�Խ� */
#define VID_CTRL_SET_BACKLIGHT          30  /* ��������ͷ���ⲹ�� */
#define VID_CTRL_SET_ZOOM               31  /* ��������ͷ���� */
#define VID_CTRL_GET_ZOOM               32  /* ��ȡ����ͷ���� */
#define VID_CTRL_SET_DENOISE            33  /* ��������ͷȥ�� */
#define VID_CTRL_SET_POWER              34  /* ��������ͷ��Դ�������߹ر� */
#define VID_CTRL_CAN_FPGA_DO_TITILE_BANNER 35 /* ���FPGA�ܷ����̨�������� */
#define VID_CTRL_SET_ISO                36  /* ���û�оISO */
#define VID_CTRL_GET_ISO                37  /* ��ȡ��оISO */
#define VID_CTRL_SET_WHITE_BALANCE      38  /* ���ð�ƽ�� */
#define VID_CTRL_GET_WHITE_BALANCE      39  /* ��ȡ��ƽ�� */
#define VID_CTRL_SET_SCENE_MODE         40  /* ���ó���ģʽ */
#define VID_CTRL_GET_SCENE_MODE         41  /* ��ȡ����ģʽ */
#define VID_CTRL_SET_EXPOSURE_MODE      42  /* �����ع�ģʽ */
#define VID_CTRL_GET_EXPOSURE_MODE      43  /* ��ȡ�ع�ģʽ */
#define VID_CTRL_SET_FPGA_NF            44  /* set fpga to de-noise */
#define VID_CTRL_SET_ACE                45  /* set auto contrast enhance */
#define VID_CTRL_GET_STD_SUPPORT        46  /* ��ȡEDID��֧�ֵ���ʽ */
#define VID_CTRL_SET_FPGA_RDRU_CORRECTION 47 /* set fpga  */
#define VID_CTRL_SET_VIDEO_OFFSET		48  /* offset adjustment for video at horizontal and vertical direction */


/* ����ͷ�ع�ģʽ���� */
#define VID_EXP_MODE_MANUAL                0    /* �ֶ��ع� */
#define VID_EXP_MODE_PROGRAMMED_AE         1    /* ��ʽ�Զ��ع� */
#define VID_EXP_MODE_APERTURE_AE           2    /* ��Ȧ�����Զ��ع� */
#define VID_EXP_MODE_SHUTTER_AE            3    /* ���������Զ��ع� */


/* ����ͷ����ģʽ���� */
#define VID_SCENE_MODE_OFF                    0           /* ����ģʽ�ر� */
#define VID_SCENE_MODE_NIGHT_AUTO_CHANGE      1           /* ҹ�� */
#define VID_SCENE_MODE_NIGHT_NO_AUTO_CHANGE   2           /* ҹ�� */
#define VID_SCENE_MODE_AUTO                   3           /* �Զ� */
#define VID_SCENE_MODE_WDR                    4           /* ��̬ */
#define VID_SCENE_MODE_HI_COLOR_TMP           5           /* ��ɫ�� */

/* ����ͷISO�趨 */
#define VID_ISO_MODE_AUTO             0
#define VID_ISO_MODE_MANUAL           1
#define VID_ISO_MKCMD(mode, val)      \
                    (((mode) & 0xffff) | (((val) & 0xffff) << 16))
#define VID_ISO_GET_MODE(cmd)         ((cmd) & 0xffff)
#define VID_ISO_GET_VAL(cmd)          (((cmd) >> 16) & 0xffff)

/* ����ͷ��ƽ���趨 */
#define VID_WBA_MODE_AUTO             0       /* �Զ� */
#define VID_WBA_MODE_DAY              1       /* ���� */
#define VID_WBA_MODE_CLOUDY           2       /* ���� */
#define VID_WBA_MODE_SHADE            3       /* ���� */
#define VID_WBA_MODE_FLUORESCENT_W    4       /* ӫ��� */
#define VID_WBA_MODE_FLUORESCENT_N    5
#define VID_WBA_MODE_FLUORESCENT_D    6
#define VID_WBA_MODE_TUNGSTEN         7       /* �׳�� */




#define VID_CTRL_DBG_WR_REG             100 /* �����ֶΣ�ֱ��дָ���Ĵ��� */
#define VID_CTRL_DBG_RD_REG             101 /* �����ֶΣ�ֱ�Ӷ�ָ���Ĵ��� */

/* ��Ƶ��ʽ���붨�� */
#define VID_STD_MASK_EMBSYNC            0x80000000  /* ͬ��ģʽ���룬1=����ͬ����0=��ͬ�� */
#define VID_STD_MASK_SD_16BIT           0x40000000  /* ����ֱ��ʲ���16λ��ʽ�����־�����576i/480i */
#define VID_STD_MASK_COLORSPACE         0x000000ff  /* ɫ�ȿռ����룬ռ�õ�8λ */
#define VID_COLORSPACE_YUV422           0           /* YUV422��ʽ */
#define VID_COLORSPACE_RGB888           1           /* RGB888��ʽ */
#define VID_COLORSPACE_RGB444           2           /* RGB444��ʽ */
#define VID_COLORSPACE_RAW16BIT         3           /* 16λ�����ݸ�ʽ */

/* ��Ƶ��������ӿ����ͺ궨�� */
#define AUDIN_35                       0x00000040
#define AUDOUT_35                     0x00000080


/* ��Ƶ�ӿ����ͺ궨�� */
#define AUD_NONE                       0x00000000
#define AUD_HDMI0                      0x00000001
#define AUD_HDMI1                      0x00000002
#define AUD_HDMI2                      0x00000004
#define AUD_HDMI3                      0x00000008
#define AUD_HDMI4                  	   0x00100000
#define AUD_HDMI5                      0x00200000
#define AUD_HDMI6                      0x00400000
#define AUD_HDMI7                      0x00800000
#define AUD_HDMI8                      0x00020000
#define AUD_HDMI9                      0x00040000
#define AUD_HDMI10                     0x00080000
#define AUD_LINE0                      0x00000010  /* RCA & 3.5/6.5�������ӿ� */
#define AUD_LINE1                      0x00000020
#define AUD_LINE2                      0x00000040  /* ���ó�6.35�ӿ� */
#define AUD_LINE3                      0x00000080
#define AUD_LINE4                      0x00010000
#define AUD_LINE5                      0x00004000  /* ��sdi���ã�2��һ�㲻��ͬʱ�� */
#define AUD_MIC0                       0x00000100  /* ��ũ&��˷�Ƚӿ� */
#define AUD_MIC1                       0x00000200
#define AUD_MIC2                       0x01000000
#define AUD_MIC3                       0x02000000
#define AUD_MIC4                       0x04000000
#define AUD_DMIC0                      0x00000400  /* ����mic */
#define AUD_DMIC1                      0x00000800
#define AUD_DMIC2                      0x08000000
#define AUD_FXO0                       0x00001000  /* �绰 */
#define AUD_SPEAKER0                   0x00002000  /* ������ */
#define AUD_SDI0                       0x00004000
#define AUD_SDI1                       0x00008000

/* digital mic detect: macro definition */
#define AUDIN_DIGIMIC_PLUGIN   0x1
#define AUDIN_DIGIMIC_UNPLUGIN 0x0
/* h800 hdmi 2ѡ1���루ֻ��ѡ������·���ѡ�񣨿ɶ�ѡ��,��900����ͻ*/
#define HDMI_AUD_IN_SEL              	0x80000004  /*  */
#define TRI_AUD_OUT_SEL              	0x80000005
/* DSP�豸����Ƶ�ڶ��壬���λD31Ϊ1������������Ƶ�ӿ� */
#define AUDIN_DSP0_ASP0_S0              0x80000000  /*  */
#define AUDIN_DSP0_ASP0_S1              0x80000001
#define AUDIN_DSP0_ASP0_S3              0x80000003

/* DSP�豸Դ�л��궨��˵��
 * C6747_FPGA_AXR0 				AUDIN_DSPx_ASPi_Sn(1, 1, 0)
 * C6747_FPGA_AXR1 				AUDIN_DSPx_ASPi_Sn(1, 1, 1)
 * C6747_FPGA_AXR2 				AUDIN_DSPx_ASPi_Sn(1, 1, 2)
 * C6747_FPGA_AXR3 				AUDIN_DSPx_ASPi_Sn(1, 1, 3)
 * C6747_FPGA_AXR4 				AUDIN_DSPx_ASPi_Sn(1, 1, 4)
 * C6747_FPGA_AXR5 				AUDIN_DSPx_ASPi_Sn(1, 1, 5)
 * C6747_FPGA_AXR6 				AUDIN_DSPx_ASPi_Sn(1, 0, 13)
 * C6747_FPGA_AXR7 				AUDIN_DSPx_ASPi_Sn(1, 0, 12)
 * C6747_FPGA_AXR8 				AUDIN_DSPx_ASPi_Sn(1, 0, 10)
 */
#define AUDIN_DSPx_ASPi_Sn(x, i, n)     (0x80000000 | ((x&0xff)<<16) | ((i&0xff)<<8) | ((n&0xff)<<0))


/* ��Ƶ��������豸�������ͺ궨�� */
#define AUD_CTRL_SET_STD                1   /* ������Ƶ��ʽ��arg����Ϊ��(TAudStd *) */
#define AUD_CTRL_GET_STD                2   /* ��ѯ��Ƶ��ʽ��arg����Ϊ��(TAudStd *) */
#define AUD_CTRL_SET_MIC_VOL            3   /* ����MIC������ arg����Ϊ��(int *) */
#define AUD_CTRL_GET_MIC_VOL            4   /* ��ѯMIC������ arg����Ϊ��(int *) */
#define AUD_CTRL_SEL_INTF               5   /* ѡ����Ƶ�ӿڣ�arg����Ϊ��(int *)on=1 off=0 */
#define AUD_CTRL_SET_MIC_48V            6   /* ����MIC��48V���翪�أ�arg����Ϊ��(int *)on=1 off=0 */
#define AUD_CTRL_SET_LEFT_VOL           7   /* ��������������, arg����Ϊ��(int *)0~100% */
#define AUD_CTRL_SET_RIGHT_VOL          8   /* ��������������, arg����Ϊ��(int *)0~100% */
#define AUD_CTRL_GET_LEFT_VOL           9   /* ��ѯ����������, arg����Ϊ��(int *)0~100% */
#define AUD_CTRL_GET_RIGHT_VOL          10   /* ��ѯ����������, arg����Ϊ��(int *)0~100% */
#define AUD_CTRL_GET_DIGIMIC_STATUS     11
#define AUD_CTRL_GET_35IN_STATUS        12
#define AUD_CTRL_GET_35OUT_STATUS       13
#define AUD_CTRL_GET_635OUT_STATUS      14
#define AUD_CTRL_SEL_FPGA_INTF		    15	/* �л�h900FPGA��Ƶ�ӿ� */
#define AUD_CTRL_SEL_CPLD_INTF		    16	/* �л�h800CPLD��Ƶ�ӿ� */

/* ��չģ��궨�� */
#define EXT_MODULE_E1                   0   /* ���ģ��Ϊ: ��E1ģ��   */
#define EXT_MODULE_4E1                  1   /* ���ģ��Ϊ: 4E1ģ��    */
#define EXT_MODULE_V35DTE               2   /* ���ģ��Ϊ: V35DTEģ�� */
#define EXT_MODULE_V35DCE               3   /* ���ģ��Ϊ: V35DCEģ�� */
#define EXT_MODULE_BRIDGE               4   /* ���ģ��Ϊ: ����ģ��   */
#define EXT_MODULE_2E1                  5   /* ���ģ��Ϊ: 2E1ģ��    */
#define EXT_MODULE_KDV8000B             6   /* ���ģ��Ϊ: KDV8000Bģ��    */
#define EXT_MODULE_DSC                  0xc /* ���ģ��Ϊ: DSC(ͬKDV8000B)ģ�� */
#define EXT_MODULE_MDSC                 0xd /* ���ģ��Ϊ: MDSC*/
#define EXT_MODULE_HDSC                 0xe /* ���ģ��Ϊ: HDSC */
#define EXT_NO_MODULE                   0xf /* û�����ģ��  */


/* -----------------------------�����Ǽ������豸��һЩ�궨��---------------------- */
/*KDV8010A����صĺ궨��*/
/* ģ��궨�� */
#define KDV8010A_MODULE_E1          0        /* ���ģ��Ϊ: ��E1ģ��   */
#define KDV8010A_MODULE_4E1         1        /* ���ģ��Ϊ: 4E1ģ��    */
#define KDV8010A_MODULE_V35DTE      2        /* ���ģ��Ϊ: V35DTEģ�� */
#define KDV8010A_MODULE_V35DCE      3        /* ���ģ��Ϊ: V35DCEģ�� */
#define KDV8010A_MODULE_BRIDGE      4        /* ���ģ��Ϊ: ����ģ��   */
#define KDV8010A_MODULE_2E1         5        /* ���ģ��Ϊ: 2E1ģ��    */
#define KDV8010A_MODULE_KDV8000B    6        /* ���ģ��Ϊ: KDV8000Bģ��    */
#define KDV8010A_MODULE_DSC         0xc      /* ���ģ��Ϊ: DSC(ͬKDV8000B)ģ�� */
#define KDV8010A_MODULE_MDSC        0xd      /* ���ģ��Ϊ: MDSC*/
#define KDV8010A_MODULE_HDSC        0xe      /* ���ģ��Ϊ: HDSC */
#define KDV8010A_NO_MODULE          0xf      /* û�����ģ��  */


/*������صĺ궨��*/
/* BrdOpenSerial�����򿪴������ͺ궨�� */
#define BRD_SERIAL_RS232             0
#define BRD_SERIAL_RS422             1
#define BRD_SERIAL_RS485             2
#define BRD_SERIAL_INFRARED          3

/*T300��Ӧ�Ķ˿ں�*/
#define BRD_SERIAL_RS422_0	   4
#define BRD_SERIAL_RS422_1            5
#define BRD_SERIAL_RS422_2            6
#define BRD_SERIAL_232_422_485_0	7
#define BRD_SERIAL_232_422_485_1      8
#define BRD_SERIAL_232_422_485_2      9
#define BRD_SERIAL_232_422_485_3      10
#define BRD_SERIAL_232_422_485_4      11
#define BRD_SERIAL_232_422_485_5      12

/*KDV 9000A MSU���ڶ���*/
#define BRD_SERIAL_RS232_1	   13

/* 485״̬��غ궨�� */
#define RS485_SUCCESS                     0    /* �����ɹ� */
#define RS485_NOT_OPENED                  1    /* RS485����û�д� */
#define RS485_NOT_CONNECTED               2    /* RS485�豸û������ */
#define RS485_SND_TIMEOUT                 3    /* RS485���Ͳ�����ʱ */
#define RS485_RCV_TIMEOUT                 4    /* RS485���ղ�����ʱ */
#define RS485_RCV_LENERR                  5    /* RS485���յ����ݳ��ȴ� */
#define RS485_RCV_ERRDATA                 6    /* RS485���յĴ�� */
#define RS485_ERROR                       -1    /* �������� */

#define RS485_SET_SND_TIMEOUT   4   /* ����485���ڲ����ķ��ͳ�ʱֵ */
#define RS485_GET_SND_TIMEOUT   5   /* ��ѯ485���ڲ����ķ��ͳ�ʱֵ */

/*ͨ�ô�����غ궨��*/
#define SIO_SET_BAUDRATE        0x2000   /* ���ô��ڵĲ����� */
#define SIO_GET_BAUDRATE        0x2001   /* ��ѯ���ڵĲ����� */
#define SIO_SET_STOPBIT         0x2002   /* ���ô��ڵ�ֹͣλ */
#define SIO_GET_STOPBIT         0x2003   /* ��ѯ���ڵ�ֹͣλ */
#define SIO_SET_DATABIT         0x2004   /* ���ô��ڵ�����λ */
#define SIO_GET_DATABIT         0x2005   /* ��ѯ���ڵ�����λ */
#define SIO_SET_PARITY          0x2006   /* ���ô��ڵ���żУ��λ */
#define SIO_GET_PARITY          0x2007   /* ��ѯ���ڵ���żУ��λ */
#define SIO_485_SET_SND_TIMEOUT 0x2008   /* ����485���ڲ����ķ��ͳ�ʱֵ */
#define SIO_485_GET_SND_TIMEOUT 0x2009   /* ��ѯ485���ڲ����ķ��ͳ�ʱֵ */

#define SIO_PARITY_NONE       0   /* ��������żУ��λ */
#define SIO_PARITY_ODD        1   /* ������У�� */
#define SIO_PARITY_EVEN       2   /* ����żУ�� */
#define SIO_PARITY_MARK       3   /* ���ڱ��У�� */
#define SIO_PARITY_SPACE      4   /* ���ڿո�У�� */

#define SIO_STOPBIT_1         0   /* ����һ��ֹͣλ */
#define SIO_STOPBIT_2         1   /* ��������ֹͣ*/

/* =485�豸����= */
#define RS485DEV_IRAY           0   /* IRAY�豸 */

/* =����ң��������= */
#define IRAY_CTRL_BLACK         0   /* ��ɫ�ɰ��ң���� */
#define IRAY_CTRL_SILVERY       1   /* ����ɫ�°��ң���� */
#define IRAY_CTRL_UNKNOWN       0xff   /* δ֪��ң���� */

#define IRAY_RCV_NOKEY          0xfe   /* irayû���յ�ң������Ϣ */

#define IRAY_ADDR0              0x02   /* IRAY�豸��ַ1 */
#define IRAY_ADDR1              0x7f   /* IRAY�豸��ַ2 */
#define HOST_485DEV_ADDR        0x01   /* ���豸��ַ */

#define IRAY_CMD_QRY_LNKSTATE   0   /* ��ѯIRAY�豸�Ƿ����� */
#define IRAY_CMD_QRY_KEYCODE    1   /* ��ѯIRAY�豸���յļ��� */


/*KDV7810��صĺ궨��*/
/* ģ��궨�� */
#define KDV7810_MODULE_E1          0        /* ���ģ��Ϊ: ��E1ģ��   */
#define KDV7810_MODULE_4E1         1        /* ���ģ��Ϊ: 4E1ģ��    */
#define KDV7810_MODULE_2E1         5        /* ���ģ��Ϊ: 2E1ģ��    */
#define KDV7810_NO_MODULE          0xf      /* û�����ģ��  */

/* E2PROM ������� */
#define EEPROM_LOG_OUTPUT_NULL  0x00
#define EEPROM_LOG_OUTPUT_PAL   0x02
#define EEPROM_LOG_OUTPUT_NTSC  0x04
#define EEPROM_LOG_OUTPUT_VGA   0x06

/* ��ͬ��ʱ���ź�������� */
#define E1_CLK_OUTPUT_DISABLE   0     /* �����ֹ�����ϲο�ʱ���ź������MPC���� */
#define E1_CLK_OUTPUT_ENABLE    1     /* ��������ϲο�ʱ���ź������MPC���� */

#define BCSR_OPT_GET_E1ISNEW	     (BCSR_OPT_BASE + 0x33)  /*�ж��Ƿ�����E1ģ��DS26514*/
#define BCSR_OPT_GET_E1ALMDTL	     (BCSR_OPT_BASE + 0x34)  /*��ȡE1�澯ϸ��*/
/*��E1ģ��澯λ����궨��*/
#define E1_ALARM_RUA1_OLD           0x08
#define E1_ALARM_RRA_OLD            0x04
#define E1_ALARM_RCL_OLD            0x02
#define E1_ALARM_RLOS_OLD           0x01
/*��E1ģ��澯λ����궨��*/
#define E1_ALARM_RRAI_MASK          0x08
#define E1_ALARM_RAIS_MASK          0x04
#define E1_ALARM_RLOS_MASK          0x02
#define E1_ALARM_RLOF_MASK          0x01

#define BCSR_OPT_SWITCH_PORT		(BCSR_OPT_BASE + 0x29)
#define BCSR_OPT_LCP2368_RESET                  (BCSR_OPT_BASE + 0x2a)


//FOR MPU2
#define BCSR_OPT_GET_ECARD_INFO		(BCSR_OPT_BASE + 0x28)

//for kdv8000i apu2
#define BCSR_CDCE62005_CLOCK_CONFIG 				(BCSR_OPT_BASE + 0x35)

//For t300
#define BCSR_LOGIC_IN 									(BCSR_OPT_BASE + 0x36)
#define BCSR_LOGIC_OUT								(BCSR_OPT_BASE + 0x37)
#define BCSR_OPT_MIC_INDICATE				(BCSR_OPT_BASE + 0x3c)

//For DMIC300
#define SIGVERLEN (14)
#define ALLVERLEN (SIGVERLEN * 4)

// For KDV9000A SMM
#define BCSR_OPT_BOARD_HOST_SLAVE_CTL    (BCSR_OPT_BASE + 0x3d)  /* �����л����� */
#define BCSR_OPT_BOARD_IN_PLACE_INFO_GET (BCSR_OPT_BASE + 0x3e)  /* ������λ��Ϣ��ѯ */
#define BCSR_OPT_BOARD_HOSTPLUG_CTL      (BCSR_OPT_BASE + 0x3f)  /* �����Ȳ����Ϣ��� */
#define BCSR_OPT_BOARD_HEALTH_CTL        (BCSR_OPT_BASE + 0x40)  /* ���ӽ�����Ϣ���� */

//For KDV9000A MSU
#define BCSR_OPT_BOARD_GET_MSU_MAIN_MODE (BCSR_OPT_BASE + 0x50)  /* ��������״̬��ѯ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BRD_WRAPPER_DEF_H */
