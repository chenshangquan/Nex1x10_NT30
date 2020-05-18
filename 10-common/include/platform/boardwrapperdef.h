/******************************************************************************
ģ����  �� BoardWrapper
�ļ���  �� BoardWrapperDef.h
����ļ���
�ļ�ʵ�ֹ��ܣ�BoardWrapperģ������ṩ�ĺ궨��ͷ�ļ�
����    ��������
�汾    ��1.0.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
03/09/2006  1.0         ������      ����
******************************************************************************/
#ifndef _BOARDWRAPPERDEF_H
#define _BOARDWRAPPERDEF_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

/* ��������ID�ź궨�� */  
#define DSL8000_BRD_MPC              0      /* MPC�� */
#define DSL8000_BRD_DTI              1      /* DTI�� */
#define DSL8000_BRD_DIC              2      /* DIC�� */
#define DSL8000_BRD_CRI              3      /* CRI�� */
#define DSL8000_BRD_VAS              4      /* VAS�� */
#define DSL8000_BRD_MMP              5      /* MMP�� */
#define DSL8000_BRD_DRI              6      /* DRI�� */
#define DSL8000_BRD_IMT              7      /* IMT�� */
#define DSL8000_BRD_APU              8      /* APU�� */
#define DSL8000_BRD_DSI              9      /* DSI�� */
#define DSL8000_BRD_VPU              10     /* VPU�� */
#define DSL8000_BRD_DEC5             11     /* DEC5�� */
#define DSL8000_BRD_VRI              12     /* VRI�� */
#define KDV8000B_MODULE              13     /* KDV8000Bģ�� */
#define KDV8000C_MODULE              19     /* KDV8000Cģ�� */
#define KDV8005_BOARD                14     /* KDV8005�� */
#define DSL8000_BRD_DRI16            15     /* DRI16�� */
#define DSL8000_BRD_MDSC             0x10     /* MDSC�� */
#define DSL8000_BRD_16E1             0x11     /* 16E1�� */
#define KDV8003_BOARD                0x12     /* KDV8003�� */
#define DSL8000_BRD_HDSC             0x14     /* HDSC�� */
#define KDV2400_BOARD                50     /* 2400�ն� */
#define KDV2500_BOARD                51     /* 2500B�ն� */
#define KDM2418_BOARD                52     /* 2418�ն� */
#define KDM2518_BOARD                53     /* 2518�ն� */
#define KDM2417_BOARD                54     /* 2417�ն� */
#define KDM2428_BOARD               56     /* 2428�ն� */

#define KDV8010_BOARD                100    /* KDV8010�ն� */
#define KDV8018_BOARD                101    /* KDV8018�ն� */
#define KDV8010A_BOARD               102    /* KDV8010A�ն� */
#define KDV8010B_BOARD               103    /* KDV8010B�ն� */
#define KDV8010C_BOARD               104    /* KDV8010C�ն� */
#define KDV8010D_BOARD               105    /* KDV8010D�ն� */
#define KDV8010E_BOARD               106    /* KDV8010E�ն� */
#define KDV8000B_BOARD               107    /* KDV8000B�ն� */
#define KDV8000BHD_BOARD              0x6E   /* KDV8000B-HD �������ײ�Ʒ */
#define KDV8000C_BOARD               108    /* KDV8000C�ն� */	
#define KDV8008_BOARD                109    /* KDV8008�ն� */
#define KDV8010A_PLUS_BOARD         110    /* ��ʮһ��KDV8010A�ն� */
//#define KDV8010C1_BOARD             111    /* KDV8010C1�ն� */    
#define KDV8010A_10_BOARD            254    /* ��ʮ��KDV8010A�ն� */  /*Ŀǰ�ѷ���*/
#define UNKNOWN_BOARD                255   /*δ֪�İ�������*/


/*��ؼ�ֵ�궨��*/
#define IP_ROUTE_MAX_NUM       64 /* ���֧�ֵ�·�ɸ��� */
#define KDV8005_V35__MAX_NUM   1 /* ���֧�ֵ�V35�ӿ��� */
#define VRI_V35_MAX_NUM   	   6 /* ���֧�ֵ�V35�ӿ��� */

/* flash������Ϣ�궨�� */
#define DISK_MAX_NUMBER             8      /* ���֧�ֵĴ洢�豸���� */

#define BRD_LED_NUM_MAX     32      /* ���Ƶĸ��� */

#define BRD_BSP_NUM_MAX     5       /* ���BSP�ĸ��� */

/* BrdLedStatusSet������ָʾ����˸״̬ */
#define BRD_LED_ON                  1      /* �� */
#define BRD_LED_OFF                 2      /* �� */
#define BRD_LED_QUICK               3      /* ���� */
#define BRD_LED_SLOW                4      /* ���� */

/* BrdLedStatusSet������ָʾ�ƿ���ID */
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

#define LED_V35_ID_BASE               0xc0
#define LED_V35_ID(ix)                (LED_V35_ID_BASE+ix)      /* ģ����0��V35�澯��*/
#define LED_V35_ID0                   LED_V35_ID(0)/*0��V35�ĸ澯��*/
#define LED_V35_ID1                   LED_V35_ID(1)/*1��V35�ĸ澯��*/
#define LED_V35_ID2                   LED_V35_ID(2)/*2��V35�ĸ澯��*/
#define LED_V35_ID3                   LED_V35_ID(3)/*3��V35�ĸ澯��*/
#define LED_V35_ID4                   LED_V35_ID(4)/*4��V35�ĸ澯��*/
#define LED_V35_ID5                   LED_V35_ID(5)/*5��V35�ĸ澯��*/


/* BrdSetEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_IP_AND_MASK         1      /* ������IP��ַ���������� */
#define Brd_SET_MAC_ADDR            2      /* ����MAC��ַ */
#define Brd_SET_ETH_ALL_PARAM       3      /* ������̫������IP��ַ�����������MAC��ַ */

/* BrdSetSecondEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_SEC_IP_AND_MASK     1      /* ���ô�IP��ַ���������� */
#define Brd_DEL_SEC_IP_AND_MASK     2      /* ɾ����IP��ַ���������� */
#define Brd_SET_SEC_ETH_ALL_PARAM   3      /* ������̫���Ĵ�IP��ַ�����������MAC��ַ */

/* ip��ַ����״̬ */
#define IP_SET_AND_UP	   1  /*ĳ��ָ��IP��ַ�Ѿ����ò��Ҷ˿ڴ���UP״̬ */
#define IP_SET_AND_DOWN    2  /*ĳ��ָ��IP��ַ�Ѿ����ò��Ҷ˿ڴ���DOWN״̬*/
#define IP_NOT_SET	       3  /*ĳ��ָ��IP��ַû������*/

/* SysSetAutoRunFile�������û����������������� */
#define LOCAL_UNCOMPRESS_FILE       0      /* ����δѹ�����ļ���һ����.out��β */ 
#define LOCAL_COMPRESS_FILE         1      /* ����ѹ�����ļ���һ����.z��β */ 
#define REMOTE_UNCOMPRESS_FILE      2      /* Զ��δѹ�����ļ���һ����.out��β */ 
#define REMOTE_COMPRESS_FILE        3      /* Զ��ѹ�����ļ���һ����.z��β */ 
#define LOCAL_ZIP_FILE              4      /* ����zipѹ�����е��ļ���һ����.out��β */ 
#define APP_MAX_NUM                     8   /* ����װ��Ӧ�ó��������� */
#define APP_NAME_MAX_LEN               31   /* Ӧ�ó����ļ�����󳤶� */

/* BrdSetWatchdogMode�����п��Ź��궨�� */
#define WATCHDOG_USE_CLK            0x00   /* ʱ��Ӳ��ι�� */
#define WATCHDOG_USE_SOFT           0x01   /* ���ι�� */
#define WATCHDOG_STOP               0x02   /* ֹͣι�� */

/* BrdSetFanState�����з�������״̬�궨�� */
#define BRD_FAN_RUN                  0      /* ����ת�� */
#define BRD_FAN_STOP                 1      /* ����ͣת */

/* BrdFanIsStopped�����з���ID���ƺ궨�� */
#define BRD_FAN_MAX_NUM              8      /* ���������� */


/*E1��صĺ궨��*/
/* E1�迹ֵ */
#define E1_75_OHM                   0      /* E1ģ���迹Ϊ75  ohm */
#define E1_120_OHM                  1      /* E1ģ���迹Ϊ120 ohm */
#define E1_ERR_OHM                  0xff    /* E1ģ���迹�޷�ʶ�� */

/* ��ͬ��ʱ���ź�������� */
#define E1_CLK_OUTPUT_DISABLE   0     /* �����ֹ�����ϲο�ʱ���ź������MPC���� */
#define E1_CLK_OUTPUT_ENABLE    1     /* ��������ϲο�ʱ���ź������MPC���� */

/* �̵�������ģʽ���� */
#define BRD_RELAY_MODE_NORMAL        0     /* �̵�����ͨ */
#define BRD_RELAY_MODE_LOCLOOP       1     /* �̵����Ի� */
#define BRD_RELAY_MODE_OUTLOOP       2     /* �̵����⻷ */

/* ���������E1���� */
#define BRD_E1_MAXNUM                16    /* һ���豸�����16��E1����ӿ� */
#define BRD_DRI_E1_MAXNUM            8     /* DRI����8��E1��· */
#define BRD_DSI_E1_MAXNUM            4     /* DSI����4��E1��· */
#define BRD_MT_E1_MAXNUM             4     /* KDV8010����4��E1��· */
#define BRD_DRI16_E1_MAXNUM          16    /* DRI����16��E1��· */
#define BRD_16E1_E1_MAXNUM           16    /* 16E1����16��E1��· */
#define BRD_KDV8003_E1_MAXNUM        1     /* kdv8003����1��E1��· */
#define BRD_KDM2000_E1_MAXNUM        1     /* kdm2000�����1��E1��· */

/* E1��·NIP��װ�ӿ���غ궨�� */
#define E1_SINGLE_LINK_CHAN_MAX_NUM  32 /* ���֧�ֵ�E1����·serialͬ���ӿڸ��� */
#define E1_MULTI_LINK_CHAN_MAX_NUM   8 /* ���֧�ֵ�E1����·��������ͨ��(��virtual����ģ��ӿ�)���� */

/*TBrdE1MultiLinkChanInfo�ṹ����dwProtocolType�����궨�� */
#define INTERFACE_PROTOCOL_PPP       0 /* �ӿ�Э��PPP */
#define INTERFACE_PROTOCOL_HDLC      1 /* �ӿ�Э��HDLC */

/* TBrdE1MultiLinkChanInfo�ṹ����dwAuthenticationType�����궨�� */
#define MP_AUTHENTICATION_NONE      0  /* ��������֤���� */
#define MP_AUTHENTICATION_PAP       1  /* PPP���ӵ���֤����PAP */
#define MP_AUTHENTICATION_CHAP      2  /* PPP���ӵ���֤����CHAP */

/* TBrdE1MultiLinkChanInfo�ṹ����dwFragMinPackageLen ������Χ�궨�� */
#define MP_FRAG_MIN_PACKAGE_LEN_MIN_VAL  20
#define MP_FRAG_MIN_PACKAGE_LEN_MAX_VAL  1500

#define MP_STRING_MAX_LEN            32  /* TBrdE1MultiLinkChanInfo�ṹ�����ַ�����󳤶� */

/* TBrdE1SerialInfo�ṹ����dwSerialId ������Χ�궨�� */
#define E1_SERIAL_ID_MIN_VAL             16
#define E1_SERIAL_ID_MAX_VAL             62

/* TBrdE1SerialInfo�ṹ����wE1ChanGroupId ������Χ�궨�� */
#define E1_CHAN_GROUP_ID_MIN_VAL         0
#define E1_CHAN_GROUP_ID_MAX_VAL         7

/* TBrdE1SerialInfo�ṹ����dwEchoInterval dwEchoMaxRetry �������ֵ�궨�� */
#define E1_SERIAL_ECHO_MAX_VAL           256

/* dwFragMinPackageLen dwSerialId dwE1ChanGroupId �����Զ����ú궨�� */
#define E1_PARAM_AUTO_CONFIG            0xffffffff

/* ���� wBufLength ��Χ���� */
#define E1_TRANS_BUF_MAX_LEN   (u32)8000 /* ���������������BUF�ĳ���,��λ�ֽ� */
#define E1_TRANS_BUF_MIN_LEN   (u32)800  /* ��������������СBUF�ĳ���,��λ�ֽ� */

#define E1_TRANS_CHAN_MAX_NUM  (u8)16    /* ���֧�ֵ�E1͸������ͨ���ĸ�����һ��ͨ������Ӧ��һ������E1��· */

/* E1ģ�鷵��ֵ�������붨�� */
#define E1_RETURN_OK                           0                     /* �����ɹ� */
#define E1_ERRCODE_BASE                        10                    /* �������ֵ */
#define E1_ERR_UNKNOWN                         (E1_ERRCODE_BASE+0)   /* δ֪���� */
#define E1_ERR_PARAM_EXCEPTION                 (E1_ERRCODE_BASE+1)   /* �����쳣 */
#define E1_ERR_SERIAL_ID_INVALID               (E1_ERRCODE_BASE+2)   /* SERIALͬ���ӿں���Ч */
#define E1_ERR_E1_ID_INVALID                   (E1_ERRCODE_BASE+3)   /* E1�ӿں���Ч */
#define E1_ERR_E1_TSMASK_INVALID               (E1_ERRCODE_BASE+4)   /* E1ʱ϶������Ч */
#define E1_ERR_E1_CHANGROUP_ID_INVALID         (E1_ERRCODE_BASE+5)   /* E1ʱ϶�������ڵı������Ч */
#define E1_ERR_SERIAL_PROTOCOL_TYPE_INVALID    (E1_ERRCODE_BASE+6) /* �ӿ�Э���װ������Ч */
#define E1_ERR_SERIAL_ECHO_INTERVAL_INVALID    (E1_ERRCODE_BASE+7) /* ͬ���ӿڵ�echo����ʱ������Ч */
#define E1_ERR_SERIAL_ECHO_MAXRETRY_INVALID    (E1_ERRCODE_BASE+8) /* ͬ���ӿڵ�echo����ط�������Ч */
#define E1_ERR_STRING_LEN_OVERFLOW             (E1_ERRCODE_BASE+9) /* �ַ���������� */
#define E1_ERR_NIP_OPT_ERR                     (E1_ERRCODE_BASE+10)/* nip�ӿڵ���ʧ�� */
#define E1_ERR_CHAN_NOT_CONF                   (E1_ERRCODE_BASE+11)/* ָ����ͨ����δ��ʹ�� */
#define E1_ERR_CHAN_CONFLICT                   (E1_ERRCODE_BASE+12)/* ͨ���ų�ͻ��ָ����ͨ�����ѱ�ʹ�� */
#define E1_ERR_MP_AUTHEN_TYPE_INVALID          (E1_ERRCODE_BASE+13)/* PPP���ӵ���֤����������Ч */
#define E1_ERR_MP_FRAG_MIN_PACKAGE_LEN_INVALID (E1_ERRCODE_BASE+14)/* ��С��Ƭ������Ч */

/* E1͸������ģ�鷵��ֵ�ʹ��������� */
#define E1_TRANS_SUCCESS       (s32)0                         /* �ɹ� */

#define E1_TRANS_FAILURE       (s32)-1                        /* δ֪���쳣ʧ�� */
#define E1_TRANS_ERRCODE_BASE  (s32)1                         /* �������ֵ */
#define E1_TRANS_NOT_INIT      (s32)(E1_TRANS_ERRCODE_BASE+0) /* ͨ��δ�� */
#define E1_TRANS_LENGTH_ERROR  (s32)(E1_TRANS_ERRCODE_BASE+1) /* ���ݳ��ȴ��� */
#define E1_TRANS_NO_BUF        (s32)(E1_TRANS_ERRCODE_BASE+2) /* û�п��õ�BUF */

/*���д�BSP15оƬ����ĺ궨��*/
/* BSP15ͼ��ɼ��˿ں궨�� */
#define BSP15_VCAPTURE_FROM_NONE   0       /* �����κοڲɼ���Ƶ���� */
#define BSP15_VCAPTURE_FROM_PORTA  1       /*��A�ڲɼ�����*/
#define BSP15_VCAPTURE_FROM_PORTB  2      /*��B�ڲɼ�����*/
#define BSP15_VCAPTURE_FROM_PORTAB 3      /* ͬʱ��A/B�ڲɼ�����*/

/* BSP15ͼ��ɼ�оƬBrdGetCaptureChipType����ֵ�궨�� */
#define CAPTURE_FROM_NONE           0       /*û����Ƶ�ɼ�оƬ */
#define CAPTURE_FROM_SAA7114        1       /*ͨ��SAA7114�ɼ���Ƶ����*/
#define CAPTURE_FROM_SAA7113        2       /*ͨ��SAA7113�ɼ���Ƶ����*/
#define CAPTURE_FROM_AL240          3       /*ͨ��AL240�ɼ���Ƶ����    */

/* BSP15�����ɼ�оƬBrdGetAudCapChipType����ֵ�궨�� */
#define CAPTURE_AUDIO_FROM_NONE     0       /* û����Ƶ�ɼ�оƬ*/
#define CAPTURE_AUDIO_FROM_5331     1       /* ��5331�ɼ���Ƶ����*/
#define CAPTURE_AUDIO_FROM_AIC23B   2       /*��AIC23B�ɼ���Ƶ����*/

/* SAA7114ͼ����������˿ں궨�� */
#define SAA7114_OUTPORT_NONE        0       /* SAA7114 û�д��κο���������*/
#define SAA7114_OUTPORT_X           1       /* SAA7114��X���������*/
#define SAA7114_OUTPORT_I           2       /* SAA7114��I���������*/
#define SAA7114_OUTPORT_XI          3       /* SAA7114ͬʱ��X/I���������*/

/* VGA����������õĺ궨�� */
#define BSP15_VGA_NONE              0       /* vga����������ܾ�û�� */
#define BSP15_VGA_IN                1       /* ֻ��vga���빦�� */
#define BSP15_VGA_OUT               2       /* ֻ��vga������� */
#define BSP15_VGA_INOUT             3       /* vga����������ܶ��� */

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
#define BSP_GPIO_MODE_1TO2  (0x00) /* ����BSP15����Ƶ                        ��������ӵ�����BSP15��GPIO�ڣ�ͬʱVGA�����BSP15����Ƶ                        ��������ӵ�SAA7121����Ƶ�����,���Ե�11��kdv8010a��Ч */
#define BSP_GPIO_MODE_3TO2  (0x01)  /* VGA�����BSP15��                        ��Ƶ��������ӵ�����BSP15��GPIO�� */

/*���д�����Ƶ���󵥰�ĺ궨��*/
#define  MATRIX_OUTPUT_DISABLE  0xfb        /* ��ֹ����Ƶ����ĳ����˿� */
#define  MATRIX_OUTPUT_ENABLE   0xfc        /* ��������Ƶ����ĳ����˿� */

/*����ĺ궨��*/
/*MPC����صĺ궨��*/
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

/*CRI����صĺ궨��*/
#define OS_CRI_FOR_MP               0 /*MP��OS�汾*/
#define OS_CRI_FOR_GK               1/*GK��OS�汾*/

/*VAS����صĺ궨��*/
#define  VAS_MATRIX_16X16           0        /* 16X16�ľ���� */
#define  VAS_MATRIX_08X08           8        /* 8X8�ľ���� */

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
#define KDV8010A_MODULE_MDSC         0xd      /* ���ģ��Ϊ: MDSC*/
#define KDV8010A_MODULE_HDSC         0xe      /* ���ģ��Ϊ: HDSC */
#define KDV8010A_NO_MODULE          0xf      /* û�����ģ��  */

/*������صĺ궨��*/
/* BrdOpenSerial�����򿪴������ͺ궨�� */
#define BRD_SERIAL_RS232             0
#define BRD_SERIAL_RS422             1
#define BRD_SERIAL_RS485             2
#define BRD_SERIAL_INFRARED          3

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

/*�����궨��*/
#define BRD_ALM_NUM_MAX         256  /* ���澯��Ԫ���� */

/*RawFlash��صĺ궨��*/
#define PARTITION_MAX_NUM           8       /* ���ݷ�������������ע�⣺�ײ�������֧��8�����������Ƿ������Boot�����û��ǲ��ɼ��ģ���ˣ��û�����������6������*/

#define PARTITION_TYPE_NOASSIGN     0       /* ��ʾΪδ����ķ��� */
#define PARTITION_TYPE_AUXDATA      1       /* ��ʾΪ����ϵͳӦ�ó��򸴺Ϸ��� */
#define PARTITION_TYPE_USRDATA      2       /* ��ʾΪ�û����ݷ��� */
#define PARTITION_TYPE_JFFS         4       /* ��ʾjffs�ļ�ϵͳ���� */
#define PARTITION_TYPE_BOOT         0x8     /* ��ʾBOOT���� */
#define PARTITION_TYPE_PTABLE       0x10    /* ��ʾ��ŷ�����ķ��� */
#define PARTITION_TYPE_APP          0x20    /* ��ʾAPPϵͳ���� */

#define PARTITION_TYPE_MAXNUM       6       /* ��ʾ�������͵����� */

#define EXECODE_TYPE_NONE           0       /* �����ִ�г�����������ʹ�� */
#define EXECODE_TYPE_FPGA  0xfa002005       /* �����ִ�г������������fpga���� */



/*��������ֵ����*/
#define OK						0
#define ERROR					-1
#define STATUS					int

/*����VxWorks�����Ͷ���*/
#define INT32 s32
#define UINT32 u32
#define INT16 s16
#define UINT16 u16
#define INT8 s8
#define UINT8 u8
#define BOOL BOOL32


/*ҵ��������ݴ��·��*/
#define USER_PATH               "/usr/bin/"
/*ҵ����򱸷����ݵ�Ŀ¼*/
#define USER_BAK_PATH           "/usr/bak/"
/*ramdisk·��*/
#define RAMDISK_PATH           "/ramdisk/"
/*RTCоƬ���Ͷ���*/
#define RTC_TYPE_NONE           0
#define RTC_TYPE_DS1337         1
#define  RTC_TYPE_DS12C887       2

/*CPU������Ϣ����󳤶�*/
#define CPU_TYPE_MAX_LEN        128
/*u-boot�汾��Ϣ����󳤶�*/
#define UBOOT_VERSION_MAX_LEN   128
/*�ں˰汾��Ϣ����󳤶�*/
#define KERNEL_VERSION_MAX_LEN  128

#define IP_ADDR_MAX_NUM	         16 /*��Linux��һ�����ڿ������õ�����IP��ַ*/

#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /*_BOARDWRAPPERDEF_H*/
