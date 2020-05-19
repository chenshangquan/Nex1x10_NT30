//////////////////////////////////////////////////////////////////////////
///  ģ����      : KdvMediaNet
///  �ļ���      : KdvMediaNet.h
///  ����ļ�    : KdvMediaNet.cpp
///  �ļ�ʵ�ֹ���: KdvMediaSnd KdvMediaRcv�ඨ��
///  ����        : κ�α� ������
///  �汾        : V2.0  Copyright(C) 2003-2005 KDC, All rights reserved.

///  �޸ļ�¼:
///  ��  ��      �汾        �޸���      �޸�����
///  2003/06/03  2.0         κ�α�      Create
///  2003/06/03  2.0         κ�α�      Add RTP Option
///  2004/09/25  2.0         ����      ����linux�汾����֧��
///  2004/10/19  2.0         ����      ���붯̬�غ������Լ����ܽӿ�
///  2004/10/19  2.0         ����      ��������
///  2004/10/19  3.0         ����      ����DES����ģʽ֧��
///  2004/11/30  3.0         ����      ����AES����ģʽ֧��
///  2004/12/02  2.0         ����      ����֡�ϱ�ʱ��ʹ��m_dwContext�ֶ��ϱ����Ͷ˵� ԴIP��������
///  2004/12/02  2.0         ����      ȡ���ϱ�:����֡�ϱ�ʱ��ʹ��m_dwContext�ֶ��ϱ����Ͷ˵� ԴIP��������
///  2004/12/22  2.0         ����      ����֡�ϱ�ʱ��֡��Ϣ�ṹ������һ���ֶ��ϱ� ���Ͷ˵�ԴIP��������
//////////////////////////////////////////////////////////////////////////


#ifndef _KDVDATANET_0302_H_
#define _KDVDATANET_0302_H_

#include "kdvtype.h"
#include "kdvcommon.h"


/// Debugging function 
PROTO_EXTERN_API void h224ver();         ///< Show the version of thie module
PROTO_EXTERN_API void h224log(u8 level); ///< Be use to control the log level
PROTO_EXTERN_API void h224rtplen();       ///< To print the rtp pack length
PROTO_EXTERN_API void h224info();        ///< The information about send session and recv session
PROTO_EXTERN_API void h224help();        ///< The help information

#define  MAXWATCHDATASOCKPORT  (u16)10599      ///< max watchsock port
#define  MINWATCHDATASOCKPORT  (u16)10500      ///< min watchsock port

#define  DATA_PINHOLE_INTERVAL		10         //10s, The time interval of pinhole,defult value is ten second

/// The error number
#define  DATANET_NO_ERROR                   (u16)0                   ///< no error 
#define  ERROR_SND_FRAME                    (s32)-1;                 ///< error send frame
#define  ERROR_DATA_NET_BASE                (u16)16000               ///< the error base of data net
#define  ERROR_SND_PARAM		            (ERROR_DATA_NET_BASE+1)  ///< the param of send error 
#define  ERROR_SND_NOCREATE		            (ERROR_DATA_NET_BASE+2)  ///< the rtp module of send not be created 
#define  ERROR_SND_MEMORY		            (ERROR_DATA_NET_BASE+3)  ///< the memory of send module error
#define  ERROR_SND_CREATE_SOCK		        (ERROR_DATA_NET_BASE+4)  ///< creating socket of send error
#define  ERROR_RTP_SSRC                     (ERROR_DATA_NET_BASE+5)  ///< the SSRC of RTP error
#define  ERROR_LOOPBUF_CREATE               (ERROR_DATA_NET_BASE+6)  ///< ��״���崴������  
#define  ERROR_RTP_NO_INIT                  (ERROR_DATA_NET_BASE+7)  ///< RTP����Щ����û����
#define  ERROR_RTCP_NO_INIT                 (ERROR_DATA_NET_BASE+8)  ///< RTCP����Щ����û����
#define  ERROR_RTCP_SET_TIMER               (ERROR_DATA_NET_BASE+9)  ///< RTCP���ö�ʱ������
#define  ERROR_RTP_SSRC_COLLISION           (ERROR_DATA_NET_BASE+10) ///< RTP ͬ��Դ����
#define  ERROR_SOCK_INIT                    (ERROR_DATA_NET_BASE+11) ///< socket û�г�ʼ��
#define  ERROR_H261_PACK_NUM                (ERROR_DATA_NET_BASE+12) ///< H261�İ���������
#define  ERROR_PACK_TOO_LEN                 (ERROR_DATA_NET_BASE+13) ///< ���ݰ�̫��
#define  ERROR_H263_PACK_NUM                (ERROR_DATA_NET_BASE+14) ///< H263�İ���������
#define  ERROR_H263_PACK_TOOMUCH            (ERROR_DATA_NET_BASE+15) ///< H263�����ݰ�̫��

#define  ERROR_NET_RCV_PARAM                (ERROR_DATA_NET_BASE+100)///< ���ý���ģ���������
#define  ERROR_NET_RCV_NOCREATE             (ERROR_DATA_NET_BASE+101)///< ����ģ��û�д���
#define  ERROR_NET_RCV_MEMORY               (ERROR_DATA_NET_BASE+102)///< ����ģ���ڴ��������
#define  ERROR_RCV_RTP_CREATE               (ERROR_DATA_NET_BASE+103)///< ����ģ��RTP����ʧ��
#define  ERROR_RCV_RTP_CALLBACK             (ERROR_DATA_NET_BASE+104)///< ����ģ������RTP�ص�����ʧ��
#define  ERROR_RCV_RTP_SETREMOTEADDR        (ERROR_DATA_NET_BASE+105)///< ����ģ������RTPԶ�˵�ַʧ��
#define  ERROR_CREATE_LOOP_BUF              (ERROR_DATA_NET_BASE+106)///< ������״����ʧ��
#define  ERROR_RCV_NO_CREATE                (ERROR_DATA_NET_BASE+107)///< ����ģ����ն���û�д���
																	 
#define  ERROR_WSA_STARTUP                  (ERROR_DATA_NET_BASE+200)///< wsastartup error
#define  ERROR_CREATE_SEMAPORE              (ERROR_DATA_NET_BASE+201)///< create semapore error
#define  ERROR_SOCKET_CALL                  (ERROR_DATA_NET_BASE+202)///< ����socket() ��������
#define  ERROR_BIND_SOCKET                  (ERROR_DATA_NET_BASE+203)///< socket �󶨳���
#define  ERROR_CREATE_THREAD                (ERROR_DATA_NET_BASE+204)///< �����̳߳��� 
#define  ERROR_LOOPBUF_FULL                 (ERROR_DATA_NET_BASE+205)///< ѭ��������

#define  ERROR_SET_DECRYPTKEY               (ERROR_DATA_NET_BASE+210)///< ���ý���keyʧ��
#define  ERROR_DECRYPT_FRAME                (ERROR_DATA_NET_BASE+212)///< ����һ֡ʧ��
#define  ERROR_SET_ENCRYPTKEY               (ERROR_DATA_NET_BASE+213)///< ���ü���keyʧ��
#define  ERROR_ENCRYPT_FRAME                (ERROR_DATA_NET_BASE+215)///< ����һ֡ʧ��

/// about encrypt 
#ifndef DES_ENCRYPT_MODE
#define DES_ENCRYPT_MODE         (u8)0      ///< DES����ģʽ
#define AES_ENCRYPT_MODE         (u8)1      ///< AES����ģʽ
#define ENCRYPT_KEY_SIZE         (u8)32     ///< ��Կ���� ȡ���еĽϴ�ֵ
#define DES_ENCRYPT_KEY_SIZE     (u8)8      ///< DES��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_A (u8)16  ///< AES Mode-A ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_B (u8)24  ///< AES Mode-B ��Կ����
#define AES_ENCRYPT_KEY_SIZE_MODE_C (u8)32  ///< AES Mode-C ��Կ����
#endif

#ifndef  MAX_NETSND_DEST_NUM
	#define  MAX_NETSND_DEST_NUM   5    ///< maximum number of send destination
#endif

/////////////////////////////////////////////////FECC////////////////////////////////////////////////
#define MAX_FECC_LEN 256               ///< maximum length of fecc message

/// H323 Annex Q
/*   
 *   h.281 encoded in host bit order:
 *   +-------+---------+--------+---------+--------+---------+--------+---------+
 *   +   P   | R=1/L=0 |    T   | U=1/D=0 |    Z   | I=1/O=0 |    F   | I=1/O=0 |
 *   +-------+---------+--------+---------+--------+---------+--------+---------+
 */
/// The enum of fecc action
enum EmFeccAction
{
	emActionInvalid					= 0,     ///< invalid action
	emActionStart					= 0x01,  ///< ��ʼ
	emActionContinue				= 0x02,  ///< ����
	emActionStop					= 0x03,  ///< ֹͣ
	emActionSelectVideoSource		= 0x04,  ///< ѡ����ƵԴ
	emActionVideoSourceSwitched		= 0x05,  ///< �л���ƵԴ
	emActionStoreAsPreset			= 0x06,  ///< �洢Ԥ��λ
	emActionActivatePreset			= 0x07,  ///< �ָ���Ԥ��λ
	emActionAutoFocus				= 0x11,  ///< �Զ�����
};

/// PTFZ codes, parameters for action Start, continue and stop.
enum EmFeccPTFZRequest
{
	emRequestInvalid			= 0,    ///< invalid request
	emRequestPanLeft			= 0x80,	///< �����ƶ�
	emRequestPanRight			= 0xc0,	///< �����ƶ�
	emRequestTiltUp			    = 0x30,	///< �����ƶ�
	emRequestTiltDown			= 0x20,	///< �����ƶ�
	emRequestFocusIn			= 0x03,	///< ����
	emRequestFocusOut			= 0x02,	///< Զ��	
	emRequestZoomIn				= 0x0c,	///< ��Ұ��С
	emRequestZoomOut			= 0x08,	///< ��Ұ���										
	emRequestBrightnessUp		= 0x01,	///< ���ȼ�(nonstandard)
	emRequestBrightnessDown		= 0x04  ///< ���ȼ�(nonstandard)
};										

/// Զңģ�鷵��ֵ����
typedef enum
{
	annexQNotInited				= -20,  ///< not inited
	annexQBindError				= -15,	///< bind error
	annexQParamError			= -14,	///< param error
	annexQLockError				= -12,	///< lock error
	annexQCodingError			= -10,	///< coding error
	annexQSendError				= -9, 	///< send error
	annexQGeneralError			= -5, 	///< general error
	annexQOk					= 1	  	///< success
}annexQResult;

/// enum EmFeccVideoSourceNumber, for tanderg
enum EmFeccVideoSourceNumber
{
	emVideoSourceDefault               = 0,    ///< ��ǰ��ƵԴ
	emVideoSourceMainCamera            = 1,    ///< ����ƵԴ
	emVideoSourceAuxCamera             = 2,    ///< ������ƵԴ
	emVideoSourceDocCamera             = 3,    ///< �ļ�չʾ̨
	emVideoSourceAuxDocCamera          = 4,    ///< �����ļ�չʾ̨������̩��Ϊvcr
	emVideoSourceVideoPlaybackSource   = 5,    ///< vcr������̩��ΪPC
};

/// CME message type
enum EmCMEMsgType
{
	CMEInvalid,				///< ��Ч
	CMEClientListInfo,		///< �ͻ��б���Ϣ֪ͨ
	CMEClientListCommond,	///< ����ͻ��б�
	CMEExtraCapInfo,		///< ����������Ϣ֪ͨ
	CMEExtraCapCommond,		///< �����������

};

/// H323 Annex Q. the struct of fecc message
typedef struct PROTO_API tagFeccStruct
{
	BOOL32 m_bIsCMEMsg;		  ///<  if this message is a CME message  

	u8	m_byCMEMsgType;		  ///< ClientListInfo/Commond,ExtraCapInfo/Commond

	u8 m_byAction;			  ///< start, continue, stop, video source, preset	
	union
	{
		u8 m_byRequest;		  ///< for PTFZ operations
		u8 m_bySourceNo;      ///< for VIDEO SOURCE operations
		u8 m_byPresetNo;      ///< for PRESET operations
	}arguments;	
	u8 m_byTimeout;			  ///< for start action only ,unit 50ms, 0��ʾ800ms
public:
	tagFeccStruct()
	{
		m_bIsCMEMsg		= FALSE;
		m_byCMEMsgType	= CMEInvalid;
		m_byAction		= emActionInvalid;
		arguments.m_byRequest = 0;	
		m_byTimeout		= 0;
	}
}TFeccStruct, *PTFeccStruct;


#define FECC_ENDPOINTID_LEN 32 ///< �˿ڸ���ʱ��Ҫ����streamId��

/// the stread id information
typedef struct PROTO_API tagFeccStreamIdInfo
{
	s8  aszEndPointId[FECC_ENDPOINTID_LEN];	///< �ն˵�id, ��ǰ��֧��e164��
	u32 IdLen;				                ///< �ն�id�ĳ���
	u32 StreamId;			                ///< ��id
	BOOL32 bSendChan;		                ///< �Ƿ���Զң����ͨ��

public:
	tagFeccStreamIdInfo()
	{
		memset(aszEndPointId, 0, FECC_ENDPOINTID_LEN);
	}
}TFeccStreamIdInfo;


/**          
* \brief            kdvAnnexQInit, Զңģ���ʼ��
* \param[in]        dwMaxFeccChannels      :���FECCͨ����
* \param[in]		nDataPinhleAppID       :��app��id,Ĭ��ֵ��APPID_DATANET_PINHOLE	
* \param[in]		nMinPort			   :����watchdog socket��С�˿ں�
* \param[in]		nMaxPort			   :����watchdog socket���˿ں�
* \return           annexQOk if succeed, or other if fails
*/
PROTO_EXTERN_API s32 kdvAnnexQInit(u32 dwMaxFeccChannels, s32 nDataPinhleAppID=APPID_DATANET_PINHOLE, u16 dwMinPort=MINWATCHDATASOCKPORT, u16 dwMaxPort=MAXWATCHDATASOCKPORT);

/**
* \brief       kdvAnnexQEnd,�ر�Զң����
*/
PROTO_EXTERN_API void kdvAnnexQEnd();

/**
* \brief            NotifyFeccMsg,H.224, H.281���ܻص�����
* \param[in]        pContext         :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]		tFeccStruct      :Զң����(TFeccStruct)
* \param[in]		terSrc     	     :Դ���ն��б�
* \param[in]		terDst     	     :Դ���ն��б�
* \return           annexQOK:success, annexQParamError:failed
*/
typedef s32 (PROTO_CALLBACK *NotifyFeccMsg)(MemId pContext,  TFeccStruct tFeccStruct, TTERLABEL terSrc, TTERLABEL terDst);

/**
* \brief            kdvSetFeccCallBack,ע��Ӧ�ûص�����(�������ͨ������һ�Σ��ص�ָ��ȫ�ֱ���)
* \note             ƽ̨ʹ�ô˺������ûص�
* \param[in]        pNotifyFeccMsg         :�ص������ṹָ��
* \return           annexQOK:success, annexQParamError:failed
*/
PROTO_API s32  kdvSetFeccCallBack(IN NotifyFeccMsg pNotifyFeccMsg);

/**
* \brief            kdvSetFeccChanCallBack,ע��Ӧ�ûص�����(���ÿ��ͨ������һ�Σ��ص�ָ�뱣����ÿ��ͨ����Ϣ��)
* \param[in]        pContext               :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        pNotifyFeccMsg         :�ص������ṹָ��
* \return           annexQOK:success, annexQParamError:failed
*/
PROTO_API s32  kdvSetFeccChanCallBack( IN MemId pContext, IN NotifyFeccMsg pNotifyFeccMsg);

/**
* \brief            kdvAnnexQInitSendSession,Զң�ŵ����������ʼ��
* \note             only for ipv4
* \param[in]        pContext            :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        dwRemoteIp          :����ͨ�������ĶԶ˵�IP��ַ
* \param[in]        dwRemotePort        :����ͨ�������ĶԶ˵Ķ˿ں�
* \return           annexQOK:success, annexQParamError:failed
*/
PROTO_API s32 kdvAnnexQInitSendSession(IN MemId pContext, IN u32 dwRemoteIp, IN u16 dwRemotePort);

/**
* \brief            kdvAnnexQInitSendSession,Զң�ŵ����������ʼ��
* \note             for ipv4 and ipv6
* \param[in]        pContext            :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        tRemoteAddress      :����ͨ�������ĶԶ˵ĵ�ַ
* \return           annexQOK:success, annexQParamError:failed
*/
PROTO_API s32 kdvAnnexQInitSendSession(IN MemId pContext, IN PFC_IPADDR tRemoteAddress);

/**
* \brief            kdvAnnexQNewSendSession,����Զң����
* \note             only for ipv4
* \param[in]        pContext            :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        dwLocalIp           :����ͨ����ip
* \param[in]        wLocalPort          :����ͨ����port
* \param[in]        bSip                :�Ƿ���sip��Զҡ����
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQNewSendSession(IN MemId pContext, IN u32 dwLocalIp, IN u16 wLocalPort, IN BOOL32 bSip=FALSE);

/**
* \brief            kdvAnnexQNewSendSession,����Զң����
* \note             for ipv4 and ipv6
* \param[in]        pContext            :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        tLocalAddress       :����ͨ���ı��ص�ַ
* \param[in]        bSip                :�Ƿ���sip��Զҡ����
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQNewSendSession(IN MemId pContext, IN PFC_IPADDR tLocalAddress, IN BOOL32 bSip=FALSE);

/**
* \brief            kdvAnnexQDeleteSendSession,ɾ������Զң���ݵ��ŵ�
* \param[in]        pContext          :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����			  
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQDeleteSendSession(IN MemId pContext);

/**
* \brief            kdvAnnexQNewRecvSession,����Զң���ݵ��ŵ�
* \note             only for ipv4
* \param[in]        pContext           :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        dwLocalIp	       :����ͨ���ı���IP��ַ
* \param[in]        wLocalPort         :�˿ں�			  
* \param[in]        bSip               :�Ƿ���sip��Զҡ����
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQNewRecvSession(IN MemId pContext, IN u32 dwLocalIp, IN u16 wLocalPort, IN BOOL32 bSip=FALSE);

/**
* \brief            kdvAnnexQNewRecvSession,����Զң���ݵ��ŵ�
* \note             for ipv4 and ipv6
* \param[in]        pContext           :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        tLocalAddress	   :����ͨ�����ص�ַ			  
* \param[in]        bSip               :�Ƿ���sip��Զҡ����
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQNewRecvSession(IN MemId pContext, IN PFC_IPADDR tLocalAddress, IN BOOL32 bSip=FALSE);

/**
* \brief            kdvAnnexQDeleteRecvSession,ɾ������Զң���ݵ��ŵ�
* \param[in]        pContext          :ÿ��FECCͨ����Ψһ��ʶ�������ŵ���� 			  
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQDeleteRecvSession(IN MemId pContext); 

/**
* \brief            kdvAnnexQSetEncryptSendSession,���÷���Զң�����ŵ��ļ�����Ϣ
* \param[in]        pContext			:ÿ��FECCͨ����Ψһ��ʶ�������ŵ���� 
* \param[in]        ptEncryptSync		:������Ϣ(TEncryptSync)			  
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQSetEncryptSendSession(IN MemId pContext, IN TEncryptSync *ptEncryptSync);

/**
* \brief            kdvAnnexQSetDecryptRecvSession,���ý���Զң�����ŵ��ļ�����Ϣ
* \param[in]        pContext			:ÿ��FECCͨ����Ψһ��ʶ�������ŵ���� 
* \param[in]        ptEncryptSync		:������Ϣ(TEncryptSync)			  
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQSetDecryptRecvSession(IN MemId pContext, IN TEncryptSync *ptEncryptSync);


/**
* \brief            kdvFeccBind,�������а�Զң���󣬵�Ե����ʱ�����
* \param[in]        pContext          :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        localTer          :�����ն��б�(TTERLABEL)
* \param[in]        remoteTer	      :Զ���ն��б�(TTERLABEL)
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvFeccBind(IN MemId pContext, IN TTERLABEL localTer, IN TTERLABEL remoteTer, IN BOOL32 bSync = TRUE);

/**
* \brief            kdvSendFeccMsg,ͨ��h224ͨ������Զң����
* \param[in]        pContext	      :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        feccStruct	      :Զң����(TFeccStruct)
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvSendFeccMsg(IN MemId pContext, IN TFeccStruct tFeccStruct, IN BOOL32 bSync = TRUE);

/**
* \brief            kdvAnnexQSetStreamId,�˿ڸ���ʱ����Զң����id
* \param[in]        pContext           :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        EndPointId         :�ն˵�id, ��ǰ��֧��e164��
* \param[in]        IdLen       	   :�ն�id�ĳ���
* \param[in]        StreamId           :��id
* \param[in]        bSendChan		   :�Ƿ���Զң����ͨ��
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvFeccSetStreamId(IN MemId pContext, TFeccStreamIdInfo tFeccStreamIdInfo, IN BOOL32 bSync = TRUE);

/**
* \brief             kdvAnnexQSetKeepAliveAddress,����h460��Զң��
* \note              only for ipv4
* \param[in]         pContext           :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]         dwLocalIp          :KeepAliveͨ����ip
* \param[in]         wLocalPort  	    :KeepAliveͨ����port
* \param[in]         dwInterval         :KeepAliveͨ���Ĵ�ʱ����
* \return            annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQSetKeepAliveAddress(IN MemId pContext, IN u32 dwKeepAliveIp, IN u16 wKeepAlivePort, IN s32 nInterval=0, IN BOOL32 bSync = TRUE);

/**
* \brief             kdvAnnexQSetKeepAliveAddress,����h460��Զң��
* \note              for ipv4 and ipv6
* \param[in]         pContext           :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]         tKeepAliveAddr     :KeepAliveͨ���ĵ�ַ
* \param[in]         dwInterval         :KeepAliveͨ���Ĵ�ʱ����
* \return            annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvAnnexQSetKeepAliveAddress(IN MemId pContext, IN PFC_IPADDR tKeepAliveAddr, IN s32 nInterval=0, IN BOOL32 bSync = TRUE);

#ifdef _KDV_SRTP_SUPPORT_
/**
* \brief            kdvFeccSetSrtp,����Զҡͨ����srtp����
* \param[in]        pContext            :ÿ��FECCͨ����Ψһ��ʶ�������ŵ����
* \param[in]        bSend  	     	    :ͨ������TRUEΪ����ͨ����FALSEΪ����ͨ��
* \param[in]        tSrtpCrypto         :srtp�����Ϣ	      
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
PROTO_API s32 kdvFeccSetSrtp(IN MemId pContext, IN BOOL32 bSend, IN TMediaSrtpCrypto tSrtpCrypto, IN BOOL32 bSync=TRUE); 
#endif

/**
* \brief            kdvSetDataTOS,set the TOS value
* \param[in]        nTOS	      :the tos value which want to be set
* \return           nTOS
*/
PROTO_API s32 kdvSetDataTOS(s32 nTOS);  

/**
* \brief            kdvGetDataTOS,get the TOS value
* \return           g_st_nDatanetTOS
*/
PROTO_API s32 kdvGetDataTOS();         


/// Frame Header Structure
typedef struct tagH224Data
{
    u8     *m_pData;       ///< ���ݻ���
    u32     m_dwDataSize;  ///< m_pDataָ���ʵ�ʻ����С�����С
}TH224Data,*PTH224Data;

/// the h224 session,be used to create and extract fecc message
typedef struct PROTO_API tagH224Session
{
public:
	TTERLABEL	m_tSrcLabel;  ///< the source label
	TTERLABEL	m_tDstLabel;  ///< the destination label
	BOOL32      m_bSip;       ///< sip��323��Զҡ��������sip�޽��ǡ��ֽ��򲻷�ת������У��͡�������0����

public:
	tagH224Session()
	{	
		Clear();
	}
	~tagH224Session()
	{        
        Clear();
	}

	void Clear()
	{
		m_tSrcLabel.Clear();
		m_tDstLabel.Clear();
		m_bSip = FALSE;
	}

	/**
	* \brief            FeccBind,����FECC����Ϣ���������а�Զң���󣬵�Ե����ʱ�����
	* \param[in]        tSrcLabel	  	    :�����ն��б�(TTERLABEL)
	* \param[in]        tDstLabel           :Զ���ն��б�(TTERLABEL)       
	* \return           annexQOk if succeed, or annexQGeneralError if fails
	*/
    void FeccBind(IN TTERLABEL tSrcLabel, IN TTERLABEL tDstLabel );

/**
* \brief            kdvCreateFeccMsg,����FECC����Ϣ����TFeccStruct-->TH224Data
* \param[in]        FeccStruct	  	    :ҵ��ʹ�õ�Զң��Ϣ�ṹ��TFeccStruct
* \param[out]       tDataHdr            :FECC����Ϣ��RTP���ݲ���       
* \return           annexQOk if succeed, or annexQGeneralError if fails
*/
	BOOL32  kdvCreateFeccMsg( IN TFeccStruct &tFeccStruct, OUT TH224Data &tDataHdr);

/**
* \brief             kdvExtractFeccMsg,����FECC��Ϣ����TH224Data-->TFeccStruct
* \param[out]        tFeccStruct  	    :ҵ��ʹ�õ�Զң��Ϣ�ṹ��TFeccStruct
* \param[in]         TH224Data	        :FECC����Ϣ��RTP���ݲ���
* \return            annexQOk if succeed, or annexQGeneralError if fails
*/
	BOOL32  kdvExtractFeccMsg( OUT TFeccStruct &tFeccStruct, IN const TH224Data &tDataHdr);

private:
    u16 PackH224Payload(IN u8* h224Buf,  IN u16 h224Len, OUT u8* rawData, IN u32 rawBufLen);
	u32 ExtractH224Payload(IN u8* rawData, IN u32 rawLen, OUT u8* h224Buf, IN u16 h224BufLen);
	u16 GenCRC16Code( u8 *pbyBuff, u16 wBuffLen );
 	
}TH224Session;
  

#endif //_KDVDATANET_0302_H_

