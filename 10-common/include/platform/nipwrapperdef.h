/******************************************************************************
ģ����  �� NIPWrapper
�ļ���  �� NIPWrapperDef.h
����ļ���
�ļ�ʵ�ֹ��ܣ�BoardWrapperģ������ṩ�ĺ궨��ͷ�ļ�
����    ��������
�汾    ��1.1.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
03/09/2006  1.0         ������      ����
12/27/2007	1.1		����			��BoardWrapper��ֲE1��ز��ֺ궨������
******************************************************************************/
#ifndef _NIPWRAPPERDEF_H
#define _NIPWRAPPERDEF_H

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
#define KDM2401_BOARD                 0x39   /* 2401������ */
#define KDM2401S_BOARD                0x46   /* 2401S������ */
#define KDM2402_BOARD                 0x47   /* 2402������ */
#define KDM2402S_BOARD                0x48   /* 2402S������ */

#define KDV8010_BOARD                100    /* KDV8010�ն� */
#define KDV8018_BOARD                101    /* KDV8018�ն� */
#define KDV8010A_BOARD               102    /* KDV8010A�ն� */
#define KDV8010B_BOARD               103    /* KDV8010B�ն� */
#define KDV8010C_BOARD               104    /* KDV8010C�ն� */
#define KDV8010D_BOARD               105    /* KDV8010D�ն� */
#define KDV8010E_BOARD               106    /* KDV8010E�ն� */
#define KDV8000B_BOARD               107    /* KDV8000B�ն� */
#define KDV8010A_10_BOARD            108    /* ��ʮ��KDV8010A�ն� */
#define KDV8008_BOARD                109    /* KDV8008�ն� */
#define KDV8010A_PLUS_BOARD         110    /* ��ʮһ��KDV8010A�ն� */
#define KDV8010C1_BOARD             111    /* KDV8010C1�ն� */  

#define KDV7620_BOARD                 0x001f   /* KDV7620��Ƶ�ն� */
#define KDV7630_BOARD                 0x001f   /* KDV7630��Ƶ�ն� */
#define KDV7810_BOARD                 0x7b   /* KDV7810��Ƶ�ն� */
#define KDV7910_BOARD                 0x7c   /* KDV7910��Ƶ�ն� */
#define KDV7820_BOARD                 0x7d   /* KDV7820��Ƶ�ն� */
#define KDV7920_BOARD                 0x7e   /* KDV7920��Ƶ�ն� */  
#define H600_BOARD_H		    0x012C  /*H600 �߶���Ƶ�ն�*/
#define H600_BOARD_L		    0x012d  /*H600 �Ͷ���Ƶ�ն�*/
#define H700_BOARD			    0x012e /*H700��Ƶ�ն�*/	
#define H800_BOARD			    0x0161 /*H800��Ƶ�ն�*/
#define H900_BOARD			    0x012f /*H900��Ƶ�ն�*/
#define T300_BOARD			    0x0154 /*T300��Ƶ�ն�*/


/*��ؼ�ֵ�궨��*/
#define IP_ROUTE_MAX_NUM       64 /* ���֧�ֵ�·�ɸ��� */
#define KDV8005_V35__MAX_NUM   1 /* ���֧�ֵ�V35�ӿ��� */
#define VRI_V35_MAX_NUM   	   6 /* ���֧�ֵ�V35�ӿ��� */

/* flash������Ϣ�궨�� */
#define DISK_MAX_NUMBER             8      /* ���֧�ֵĴ洢�豸���� */
#define BRD_BSP_NUM_MAX     5       /* ���BSP�ĸ��� */


/* BrdSetEthParam������byIpOrMac����ֵ�ĺ궨�� */
#define Brd_SET_IP_AND_MASK         1      /* ����IP��ַ���������� */
#define Brd_SET_MAC_ADDR            2      /* ����MAC��ַ */
#define Brd_SET_ETH_ALL_PARAM       3      /* ������̫����IP��ַ�����������MAC��ַ */
#define Brd_SET_ETH_SEC_IP         4  /* ������̫���ڶ�IP ��ַ */

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

/* E1��·NIP��װ�ӿ���غ궨�� */
#define E1_SINGLE_LINK_CHAN_MAX_NUM  32 /* ���֧�ֵ�E1����·serialͬ���ӿڸ��� */
#define E1_MULTI_LINK_CHAN_MAX_NUM   8 /* ���֧�ֵ�E1����·��������ͨ��(��virtual����ģ��ӿ�)���� */
   

/*TBrdE1MultiLinkChanInfo�ṹ����dwProtocolType�����궨�� */
#define INTERFACE_PROTOCOL_PPP       0 /* �ӿ�Э��PPP */
#define INTERFACE_PROTOCOL_HDLC      1 /* �ӿ�Э��HDLC */
    
#define E1_SINGLE_LINK_CHAN_MAX_NUM  32 /* ���֧�ֵ�E1����·serialͬ���ӿڸ��� */
#define E1_MULTI_LINK_CHAN_MAX_NUM   8 /* ���֧�ֵ�E1����·��������ͨ��(��virtual����ģ��ӿ�)���� */


/* TBrdE1MultiLinkChanInfo�ṹ����dwAuthenticationType�����궨�� */
#define MP_AUTHENTICATION_NONE      0  /* ��������֤���� */
#define MP_AUTHENTICATION_PAP       1  /* PPP���ӵ���֤����PAP */
#define MP_AUTHENTICATION_CHAP      2  /* PPP���ӵ���֤����CHAP */


/*����BrdSetMinUnitCheckableȡֵ��*/
#define MINSIZE_64K_BYTE		0
#define MINSIZE_128K_BYTE		1
#define MINSIZE_512K_BYTE		2
#define MINSIZE_1024K_BYTE		3


/* TBrdE1MultiLinkChanInfo�ṹ����dwFragMinPackageLen ������Χ�궨�� */
#define MP_FRAG_MIN_PACKAGE_LEN_MIN_VAL  20
#define MP_FRAG_MIN_PACKAGE_LEN_MAX_VAL  1500

#define MP_STRING_MAX_LEN            32  /* TBrdE1MultiLinkChanInfo�ṹ�����ַ�����󳤶� */

/* Tranplanted from Boardwrapperdef.h by Gaoqi, 12/27/2007. */
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
/* Ended by Gaoqi */


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

/*BrdSysUpdate����ֵ˵��*/
#define SYSTEM_UPDATE_SUCCESS                 0         /*ϵͳ�����ɹ�*/
#define SYSTEM_FILE_CHECK_ERROR               1         /*ϵͳ�����ļ�У�����*/
#define SYSTEM_UPDATEVERSION_COMPARE_ERROR    2         /*ϵͳ�����ȶ�У�����*/
#define SYSTEM_FILENAME_NULL                  3         /*ϵͳ�����ļ�����*/    
#define CHK_PID_FAILURE         -11     //PID���ʧ��

/*BrdSetSysRunSuccess����ֵ˵��*/
#define NO_UPDATE_OPERATION       	0  /*��������������������*/
#define UPDATE_VERSION_ROLLBACK	    1  /*����ʧ�ܣ��汾�ع���*/
#define UPDATE_VERSION_SUCCESS		2  /*�����ɹ���Ӧ���°汾�ɹ�*/
#define SET_UPDATE_FLAG_FAILED		-1 /*����ʧ��*/


/*��������ֵ����*/
#ifndef OK
#define OK						0
#endif
#ifndef ERROR
#define ERROR					-1
#endif
#ifndef STATUS
#define STATUS					int
#endif

/* �汾�ų��ȶ��� */
#define NIPWRAPPER_VERSION_LEN  128


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

#endif /*_NIPWRAPPERDEF_H*/
