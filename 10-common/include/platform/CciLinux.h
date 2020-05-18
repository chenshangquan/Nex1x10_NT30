/******************************************************************************
ģ����  �� CciLinux
�ļ���  �� CciLinux.h
����ļ���
�ļ�ʵ�ֹ��ܣ�CciLinuxģ������ṩ����Ҫͷ�ļ�
����    ��������
�汾    ��1.0.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
06/20/2005  1.0         ������      ����
******************************************************************************/
#ifndef _CCILINUX_H
#define _CCILINUX_H

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#include "kdvtype.h"
#include <etilib/etiOsal.h>
#include <etilib/etiErrors.h>
#include <etilib/etiLocal.h>
#include <etilib/etiL2Load.h>
#include <etilib/etiL2PciLoad.h>

/*��غ궨��*/

/*��ģ��İ汾�Ŷ���*/
#define CCILINUXVER                     "CciLinux 40.01.00.02.051009"

/*���ӻ�֮��ͨ��ͨ�������Ľ��̺�,ע�⣺ҵ����������������̵�ID��Ϊ��ֵ*/
/*��������������ں���osalMain()֮ǰ��commProcessId_t   commProcessId = HOST_SLAVE_PROCESS_ID;*/
#define HOST_SLAVE_PROCESS_ID           (u32)0

/*����ͨ��*/
#define UP_CHANNEL                      (u32)0

/*����ͨ��*/
#define DOWN_CHANNEL                    (u32)1

/*˫��ͨ��ͨ����*/
#define UPDOWN_CHANNEL                  (u32)2                    

/*���֧�ֵ�BSP-15��Ŀ*/
#define MAX_BSP_NUM                     (u32)6

/*��С�Ľ��ջ�������С��ҵ������ڴ�ͨ��ָ��ͨ���Ľ��ջ�������Сʱ����С�ڸ�ֵ*/
#define MIN_RCV_BUFFER_SIZE             (u32)6*1024

/*�����Ŷ��壬�������Ŀ�İ���Ǹú�ʱ���ͽ��а������ݴ���1.0�汾�ݲ�֧��*/
#define CCI_LOCAL_BOARD_ID              (u32)(MAX_BSP_NUM)

/*�������ͨ����*/
#define MAX_UP_CHANNEL_NUM              (u32)8
   
/*�������ͨ����*/  
#define MAX_DOWN_CHANNEL_NUM            (u32)256  

/*�汾��Ϣ����󳤶�*/
#define MAX_VERSION_LEN                 (u32)255

/*CCIģ�鷢�͸�ҵ��������Ϣ���Ͷ���*/
/*CCIģ�鷢�͸�ҵ�������Ϣ�Ļ�ַ*/
#define CCICOMM_MSG_BASE                (u32)6000

/*����BSP-15��������ͨ��ͨ������֪ͨ��Ϣ����Ϣ���ݣ���*/
#define CCICOMM_HEARTBIT_CONN_LOST      (u32)(CCICOMM_MSG_BASE+1)

/*ĳ��ͨ���������������ٴδ򿪸�ͨ��ʱ��ӻ��෢�͵���Ϣ���ӻ����յ�����Ϣ��Ӧ�õ�����Ӧ�Ľӿ����´򿪸�ͨ��
��Ϣ����:�ṹ��TCCIConnLostMsg*/
#define CCICOMM_REOPEN_CHANNEL_REQUEST  (u32)(CCICOMM_MSG_BASE+2) 

/*�Զ˷��͹��������ݵ���֪ͨ��Ϣ*/
#define CCICOMM_PEERMSG_ARRIVED         (u32)(CCICOMM_MSG_BASE+3)

/*������ر�����ͨ��ͨ��֪ͨ��Ϣ���յ�����Ϣ�󣬴ӻ�������ͨ��ͨ�����Ѿ��رգ������ٽ�������ͨ��
��Ϣ����:��*/
#define CCICOMM_HOST_CLOSEALL_NOTIFY    (u32)(CCICOMM_MSG_BASE+4)

/*��ؽṹ�嶨��*/

/*�弶���ƽӿڷ���ֵ����*/
typedef enum {
    CCIBD_OK,                       /* û�д��󣬺���ִ�гɹ�*/
    CCIBD_NO_INIT,                  /*û�е��ó�ʼ������*/
    CCIBD_ERROR,                    /* �������ִ���.    */
    CCIBD_INVALID_PARM,             /* �����õĲ���.*/
    CCIBD_INSUFFICIENT_MEMORY,      /*�ڴ�����ʧ��*/
    CCIBD_OSAL_ERROR,               /* ִ����OSAL����.*/
    CCIBD_BSPDRV_ERROR,             /*ִ����BSPDRV����.    */
    CCIBD_INVALID_L2IMAGE,          /* �����õ�L2 image.*/
    CCIBD_COMM_ERROR,               /* ������COMM����.*/
    CCIBD_FILE_ERROR,               /* �ļ���������. */
    CCIBD_FS_ERROR,                 /* �ļ�ϵͳ����.       */
    CCIBD_IOMAP_ERROR,              /* IOMAP ����.       */
    CCIBD_BOARDID_ERROR,            /*��Ŵ���*/
    CCIBD_UIMAGE_ERROR,             /*�ں��ļ�����*/
    CCIBD_ALREADY_OPENED,           /*�����Ѿ���*/
    CCIBD_NOT_OPEN,                 /*����û�д�*/
    CCIBD_GETDEFSETUP_ERROR,        /*��ȡĬ�ϵĴ�BSP-15�����������*/
    CCIBD_LOAD_IMAGE_FAILED,        /*���õͲ�ӿڼ����ں��ļ�ʧ��*/
    CCIBD_UNLOAD_IMAGE_FAILED,      /*���õͲ�ӿ�ж���ں��ļ�ʧ��*/
    CCIBD_NOT_SUPPORT,              /*�������İ���Ǳ�ֵ�ڲ�ͨ�ŵ������ţ��򷵻ظ�ֵ��Ŀǰ�в�֧��*/
}TCCIBDError;

/*CCIͨ�Žӿڷ���ֵ����*/
typedef enum {
    CCICOMM_OK,			            /*û�д��󣬺���ִ�гɹ�*/
    CCICOMM_NOT_INIT,               /*û�е��ó�ʼ������*/
    CCICOMM_CHANNEL_ABORTED,        /*�ڲ�ʹ�ã��ⲿ���ɼ� */
    CCICOMM_OUT_OF_MEMORY,		    /*�ڴ�����ʧ��*/
    CCICOMM_NO_DRIVER,		        /*COMMOpenChannel����û���ҵ����õ�����*/
    CCICOMM_SIZE_TOO_LARGE,	        /*����Ϣ̫�󣬽��ջ������ɲ���*/
    CCICOMM_NO_ATTRIBUTES,		    /*COMMGetChannelAttributesû���ҵ����õ�ͨ������*/
    CCICOMM_OSAL_ERROR,		        /*��OSAL�㴫�ݵĴ���*/
    CCICOMM_OSAL_NOT_IMPLEMENTED,   /*��OSAL�㴫�ݵĴ���*/
    CCICOMM_ALREADY_OPENED,         /*ͨ��ͨ���Ѿ���*/    
    CCICOMM_NOT_OPEN,               /*ͨ��ͨ��û�д�*/    
    CCICOMM_WRONG_CHANNEL_ID,	    /*��Ч��ͨ����*/
    CCICOMM_WRONG_BOARD_ID,         /*��Ч�İ��*/
    CCICOMM_PARM_IS_NULL,           /*����յ�ָ��*/
    CCICOMM_NVALID_PARM,            /* ����Խ��*/
    CCICOMM_WAIT_ACK_TIMEOUT,       /*�ȴ��Է���Ӧ����Ϣ����*/
    CCICOMM_RCVBUFFER_TOO_SMALL,    /*���ջ������Ĵ�СС��2K*/
    CCICOMM_NOT_SUPPORT,            /*�������İ���Ǳ�ֵ�ڲ�ͨ�ŵ������ţ��򷵻ظ�ֵ��Ŀǰ�в�֧��*/
    CCICOMM_CONN_LOST,              /*�ϲ�ҵ�����Ҫ�������ݵ�ͨ��ǡ�ö�����*/
    CCICOMM_CONN_NOTLOST,           /*�ϲ�ҵ��������´�ͨ��ʱ�������ͨ��û�ж������򷵻ظô���*/
    CCICOMM_HOST_CLOSEALL,          /*����������ر������е�ͨ�����ӻ����ٵ��ýӿڷ������������*/
}TCCICommError;

/*��BSP-15ʱ��Ҫ����Ĳ����ṹ��*/
typedef struct CCIBDSetup {
    u8      *pbyExecFileName;   /* �����ص�BSP-15�ں��ļ�*/
    u32     dwFreqCore;         /* BSP-15�ں�Ƶ�ʣ�����0ʱ��Ĭ��ֵ��*/
    u32     dwFreqMem;          /* BSP-15�ڴ�Ƶ�ʣ�����0ʱ��Ĭ��ֵ��*/
    u32     dwMemSize;          /* BSP-15�ڴ��С�����ֽ�Ϊ��λ��������0ʱ��Ĭ��ֵ��*/
}TCCIBoardSetup;

/*CCIģ�鷢�͸�ҵ��������֪ͨ��Ϣ�Ľṹ��*/
typedef struct{
    u32     dwBoardID;          /*������ͨ�������ӵĶԶ˵İ��(0~5��CCI_LOCAL_BOARD_ID)*/
    u32     dwChannelID;        /*������ͨ����*/
    u8      byDnOrUp;           /*������ͨ�������л�������ͨ����UP_CHANNEL/DOWN_CHANNEL��*/
}TCCIConnLostMsg;

/*���������ͨ������������Ľṹ��*/
typedef struct{
    u32                 dwConnLostNum;      /*������ͨ��ͨ����(��صĶ�����Ϣ�洢���±ߵ�������,��Ч��Ϣ�±귶Χ0~(dwConnLostNum-1))*/
    TCCIConnLostMsg     atCCIConnLostMsg[MAX_UP_CHANNEL_NUM+MAX_DOWN_CHANNEL_NUM];        /*������ͨ����Ϣ*/
}TCCIChannelCheck;

/*ҵ�����ע��Ľ�����Ϣ�Ļص��������Ͷ���*/
typedef void (*PTCCIMessageCallback)(
    u32     dwBoardID,          /*��Ϣ��Դ���*/
    u32     dwMsgType,          /*��Ϣ����(���ϱߵ�CCIģ�鷢�͸�ҵ��������Ϣ���Ͷ��岿��*/
    u8      *pbyMessage,        /*ָ����Ϣ���ָ��*/
    u32     dwSize,             /* ��Ϣ�ĳ���*/
    u8      *pbyData            /* ҵ�����ע���˽������*/
);

/*ͨ���������ýṹ��*/
typedef struct {
    u32     dwReceiveCapacity;  /* ����ͨ����ͬʱ���ɵ������Ϣ��*/
    u32	    dwReceiveBufferSize;/* ����ͨ�����ջ����С(���ֽ�Ϊ��λ����СMIN_RCV_BUFFER_SIZE)*/
}TCCIChannelConfiguration;

/*��BSP-15ʱ����Ľ�Ҫ��ͨ������Ϣ�ṹ��*/
typedef struct{
    u32     dwDnMsgQs;    /*������Ϣ������ */
    u32     dwUpMsgQs;    /*������Ϣ������ */
    TCCIChannelConfiguration   atCciDnChannelQParam[MAX_DOWN_CHANNEL_NUM];/*������Ϣ���в��� */ 
    TCCIChannelConfiguration   atCciUpChannelQParam[MAX_UP_CHANNEL_NUM];/*������Ϣ���в��� */            
}TCCIChannelParam;

/*ͳ����Ϣ�ṹ����*/
typedef struct{
    u32     dwSendCount;        /*�ܵķ�������*/
    u32     dwSuccSendCount;    /*�ɹ���������*/
    u32     dwSuccRecvCount;    /*�ɹ��հ�����*/
    u32     dwSendByte;         /*�ɹ��������ֽ���*/
    u32     dwRecvByte;         /*�ɹ��������ֽ���*/
    u32     dwDownCount;        /*��������ͳ��*/
    u32     dwSendLost;         /*��Ϊͨ�����������·�������ʧ�ܵ�ͳ��*/
}TCCIStatInfo;

/*�汾��Ϣ�ṹ��*/
typedef struct{
    u8      abyVer[MAX_VERSION_LEN];
}TCCIVersion;

/*��������*/


/*================================
��������CciLinuxBrdOpen 
���ܣ�����ָ��BSP-15�Ĳ���ϵͳ��ʹ�䴦������״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)  ��BSP-15��ţ�0��5 ����CCI_LOCAL_BOARD_ID ��Ч��
                ptSetup(I)��   ָ��TCCIBoardSetup �ṹ�ı�����
����ֵ˵���� TCCIBDErrorö������
==================================*/
TCCIBDError CciLinuxBrdOpen (u32  dwBoardID  ,TCCIBoardSetup  *ptSetup);

/*================================
��������CciLinuxBrdClose 
���ܣ��رհ�����ָ����BSP-15
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)  ��BSP-15��ţ�0��5 ����CCI_LOCAL_BOARD_ID ��Ч��
����ֵ˵���� TCCIBDErrorö������
==================================*/
TCCIBDError CciLinuxBrdClose (u32  dwBoardID );

/*================================
��������CciLinuxPrintEnable
���ܣ�ʹ��BSP-15��Ĵ�ӡ��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)  ��BSP-15��ţ�0��5 ����CCI_LOCAL_BOARD_ID ��Ч��
����ֵ˵���� TCCIBDErrorö������
==================================*/
TCCIBDError CciLinuxPrintEnable (u32  dwBoardID );

/*================================
��������CciLinuxPrintDisable 
���ܣ��ر�BSP-15��Ĵ�ӡ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)  ��BSP-15��ţ�0��5 ����CCI_LOCAL_BOARD_ID ��Ч��
����ֵ˵���� TCCIBDErrorö������
==================================*/
TCCIBDError CciLinuxPrintDisable  (u32  dwBoardID);

/*================================
��������CciLinuxHostMsgOpen
���ܣ���CCIͨ��ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��Ŀ����
	            ptCCIChannelCallBack (I)��ע��Ľ�����Ϣ�Ļص�����
                ptCciChannelParam (I)��  ��ͨ����Ϣ�Ľṹ��ָ��
                pbyData(I):       ҵ�����ע���˽������
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxHostMsgOpen (u32  dwBoardID, PTCCIMessageCallback   ptCCIChannelCallBack, TCCIChannelParam  *ptCciChannelParam, u8* pbyData);

/*================================
��������CciLinuxHostMsgClose
���ܣ��ر���ð����ص�����CCIͨ��ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwBoardID (I)��Ŀ����
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxHostMsgClose (u32	dwBoardID);

/*================================
��������CciLinuxHostSendMessage
���ܣ�����ָ��ͨ����������ʽ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��    Ŀ����
                dwChanneID (I)�� ָ����ͨ����
                pbyFirstMessage (I)��ָ���һ�������͵���Ϣ��ָ��
                dwFirstMsgSize (I)����һ����������Ϣ�Ĵ�С���ֽڣ�
                pbySecondMessage (I)��ָ��ڶ��������͵���Ϣ��ָ��
                dwSecondMsgSize (I)���ڶ�����������Ϣ�Ĵ�С���ֽڣ�
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxHostSendMessage 
(
    u32  dwBoardID,
    u32	 dwChanneID,  
    u8  *pbyFirstMessage,
    u32  dwFirstMsgSize, 
    u8  *pbySecondMessage, 
    u32  dwSecondMsgSize
);

/*================================
��������CciLinuxHostTrySendMessage
���ܣ�����ָ��ͨ���Է�������ʽ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��    Ŀ����
                dwChanneID (I)�� ָ����ͨ����
                pbyFirstMessage (I)��ָ���һ�������͵���Ϣ��ָ��
                dwFirstMsgSize (I)����һ����������Ϣ�Ĵ�С���ֽڣ�
                pbySecondMessage (I)��ָ��ڶ��������͵���Ϣ��ָ��
                dwSecondMsgSize (I)���ڶ�����������Ϣ�Ĵ�С���ֽڣ�
                pbSendSuccess (O)��ָʾ���Ͳ���ʵ���Ƿ�ɹ�
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxHostTrySendMessage 
(
    u32  dwBoardID, 
    u32	 dwChanneID,  
    u8  *pbyFirstMessage,
    u32  dwFirstMsgSize ,
    u8  *pbySecondMessage, 
    u32  dwSecondMsgSize,
    BOOL32  *pbSendSuccess
);

/*================================
��������CciLinuxHostChannelCheck
���ܣ���������ͨ����������ĺ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��Ŀ����
                ptCCIChannelCheck (O):���صļ����
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError  CciLinuxHostChannelCheck (u32 dwBoardID, TCCIChannelCheck *ptCCIChannelCheck);

/*================================
��������CciLinuxHostGetMapHeartBeat
���ܣ����BSP-15��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��Ŀ����
                pdwHeartBeats (O):���ص�������
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError  CciLinuxHostGetMapHeartBeat (u32 dwBoardID, u32  *pdwHeartBeats);

/*================================
��������CciLinuxHostGetChannelStateInfo
���ܣ���������ָ��ͨ��ͳ����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)��Ŀ����
                byDnOrUp:       ���л�������ͨ����UP_CHANNEL/DOWN_CHANNEL��
                dwChanneID(I)��ָ����ͨ��,
                ptStateInfo(O)��ָ��ͳ����Ϣ�Ľṹ��ָ��
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxHostGetChannelStateInfo(u32   dwBoardID, u8 byDnOrUp, u32	dwChanneID, TCCIStatInfo *ptStateInfo);

/*================================
��������CciLinuxHostCCIInfoShow
���ܣ�����������Լ�ͨ����ϢDump�ӿ�,�ýӿ���Ҫҵ�����ע�ᵽOSP��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ��
==================================*/
void CciLinuxHostCCIInfoShow(void);

/*================================
��������CciLinuxHostReOpenUserChannel
���ܣ����������´��û�ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����ptCCIConnLostMsg---ָ��Ҫ��ͨ�������Ϣ�Ľṹ��ָ��
����ֵ˵���� TRUE--�ɹ�
             FALSE-ʧ��
==================================*/
BOOL32 CciLinuxHostReOpenUserChannel(TCCIConnLostMsg* ptCCIConnLostMsg);

/*================================
��������CciLinuxSlaveMsgOpen
���ܣ���CCI��Ϣͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵��: dwBoardID (I)��Ŀ����(Ŀ���ż������İ��ֻ��Ϊ0)
              ptCCIChannelCallBack (I)��ע��Ľ�����Ϣ�Ļص�����
              ptCciChannelParam (O)����������õ����������ͨ����Ϣ�Ľṹ��ָ��
              pbyData(I):       ҵ�����ע���˽������
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxSlaveMsgOpen (u32 dwBoardID, PTCCIMessageCallback   ptCCIChannelCallBack, TCCIChannelParam  *ptCciChannelParam, u8* pbyData);

/*================================
��������CciLinuxSlaveSendMessage 
���ܣ�����ָ��ͨ����������ʽ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��    Ŀ����(Ŀ���ż������İ��ֻ��Ϊ0)
                dwChanneID (I)�� ָ����ͨ����
                pbyFirstMessage (I)��ָ���һ�������͵���Ϣ��ָ��
                dwFirstMsgSize (I)����һ����������Ϣ�Ĵ�С���ֽڣ�
                pbySecondMessage (I)��ָ��ڶ��������͵���Ϣ��ָ��
                dwSecondMsgSize (I)���ڶ�����������Ϣ�Ĵ�С���ֽڣ�
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxSlaveSendMessage 
(
    u32  dwBoardID, 
    u32	 dwChanneID,    
    u8  *pbyFirstMessage,
    u32  dwFirstMsgSize, 
    u8  *pbySecondMessage, 
    u32  dwSecondMsgSize
);

/*================================
��������CciLinuxSlaveTrySendMessage
���ܣ�����ָ��ͨ���Է�������ʽ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID (I)��    Ŀ����(Ŀ���ż������İ��ֻ��Ϊ0)
                dwChanneID (I)�� ָ����ͨ����
                pbyFirstMessage (I)��ָ���һ�������͵���Ϣ��ָ��
                dwFirstMsgSize (I)����һ����������Ϣ�Ĵ�С���ֽڣ�
                pbySecondMessage (I)��ָ��ڶ��������͵���Ϣ��ָ��
                dwSecondMsgSize (I)���ڶ�����������Ϣ�Ĵ�С���ֽڣ�
                pbSendSuccess (O)��ָʾ���Ͳ���ʵ���Ƿ�ɹ�
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxSlaveTrySendMessage 
(
    u32  dwBoardID, 
    u32	 dwChanneID,  
    u8  *pbyFirstMessage,
    u32  dwFirstMsgSize ,
    u8  *pbySecondMessage, 
    u32  dwSecondMsgSize, 
    BOOL32 *pbSendSuccess
);

/*================================
��������CciLinuxSlaveSendMapHeartBeat
���ܣ��ӻ����������෢��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)��Ŀ����(Ŀ���ż������İ��ֻ��Ϊ0)
                dwHeartBit(I)��������
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxSlaveSendMapHeartBeat (u32    dwBoardID, u32	 dwHeartBit);

/*================================
��������CciLinuxGetChannelStateInfo
���ܣ��ӻ�����ָ��ͨ��ͳ����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  dwBoardID(I)��Ŀ����(Ŀ���ż������İ��ֻ��Ϊ0)
                byDnOrUp:       ���л�������ͨ����UP_CHANNEL/DOWN_CHANNEL)
                dwChanneID(I)��ָ����ͨ��,
                ptStateInfo(O)��ָ��ͳ����Ϣ�Ľṹ��ָ��
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError CciLinuxSlaveGetChannelStateInfo(u32   dwBoardID, u8 byDnOrUp, u32	dwChanneID, TCCIStatInfo *ptStateInfo);


/*================================
��������CciLinuxSlaveReOpenUserChannel
���ܣ��ӻ��������´��û�ͨ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����ptCCIConnLostMsg---ָ��Ҫ��ͨ�������Ϣ�Ľṹ��ָ��
����ֵ˵���� TRUE--�ɹ�
             FALSE-ʧ��
==================================*/
BOOL32 CciLinuxSlaveReOpenUserChannel(TCCIConnLostMsg* ptCCIConnLostMsg);

/*================================
��������CciLinuxSlaveCCIInfoShow
���ܣ��ӻ�������Լ�ͨ����ϢDump�ӿ�,�ýӿ���Ҫҵ�����ע�ᵽOSP��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ��
����ֵ˵���� ��
==================================*/
void CciLinuxSlaveCCIInfoShow(void);

/*================================
��������CciLinuxGetCCIVersion
���ܣ���õ�ǰCciLinuxģ��İ汾��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����  ptCCIVersion(O)����Ű汾��Ϣ��ָ��
����ֵ˵���� TCCICommErrorö������
==================================*/
TCCICommError  CciLinuxGetCCIVersion (TCCIVersion *ptCCIVersion );



#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /*_CCILINUX_H*/
