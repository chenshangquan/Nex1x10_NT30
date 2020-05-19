///  All right reserved
///  
///  @file        sipcallstdstruct.h 
///  @author      zgf
///  @version     1.0
///  @date        2018-3-1
///  @brief       sipcallstdstruct
///  @details     sipcallstdstruct interfaces describe here what it is all about.
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*  Start of sipcallstdstruct                                        */
/************************************************************************/

/**
 * @defgroup    sipcallstdstruct
 * @brief       sipcallstdstruct interfaces describe here what it is all about.
 * @{
 */
#ifndef _SIPCALLSTDSTRUCT_H
#define _SIPCALLSTDSTRUCT_H

#include "kdvcapset.h"
#include "kdvsipcommon.h"
#include "kdvdatanet.h"
#include "kdvsiphandle.h"
#include "sipconfnonstdmsg.h"

/// is valid host name address
#define IsValidHostNameAddr( hostname ) TRUE

#define MAX_MIX_EP_LIST_LEN                 64 ///< max mt count in list

/// sip tsx timeout
typedef struct tagSipTsxTimeout
{          
	u32 m_dwTsxTimer1;  ///< Transaction T1 timeout, in msec. Default value is PJSIP_T1_TIMEOUT 
	
	u32 m_dwTsxTimer2;  ///< Transaction T2 timeout, in msec. Default value is PJSIP_T2_TIMEOUT 
	
	u32 m_dwTsxTimer4;  ///< Transaction completed timer for non-INVITE, in msec. Default value is PJSIP_T4_TIMEOUT 
	
	u32 m_dwTsxTimerTD; ///< Transaction completed timer for INVITE, in msec. Default value is PJSIP_TD_TIMEOUT. 

	/**
    * \brief            tagSipTsxTimeout Constructor
    * \return           void.
    */
	tagSipTsxTimeout()
	{
		Clear();
	}
	/**
    * \brief            tagSipTsxTimeout init
    * \return           void.
    */
	void Clear()
	{
		m_dwTsxTimer1 = 500;	
		m_dwTsxTimer2 = 4000;	
		m_dwTsxTimer4 = 5000;	
		m_dwTsxTimerTD= 32000;	
	}
}TSipTsxTimeout;

typedef struct tagAdapterLogCfg
{
	s8 m_achLogPath[LOG_LOGPATH_LENGTH];			///< pfc log path
	u32 m_dwMaxSize;								//pfc log  size(KB)
	u32 m_dwMaxfiles;								//pfc file number
	tagAdapterLogCfg()
	{
		clear();
	}
	void clear()
	{
		MEMSET_CAST(m_achLogPath, 0, LOG_LOGPATH_LENGTH);
		m_dwMaxSize = 0;
		m_dwMaxfiles = 0;
	}
}TAdapterLogCfg;

/// sipadpater config
typedef struct tagSipAdapterCfg
{
	emEndpointType	m_emEndpointType;           ///< endpoint type
	BOOL32  m_bIfRegister;                      ///< if register 
	u32     m_dwMaxCalls;			            ///< ��������


	PFC_IPADDR m_tLocalAddrV4;                  ///for ipv4,tcp and udp
	PFC_IPADDR m_tLocalAddrV6;                  ///for ipv6,tcp and udp

	BOOL32  m_bManualAck;                       ///< manual ack
	u16     m_wRegClientNum;                    ///< reg client number
	u32     m_dwMaxSendReciveBufferSize;        ///< mx send and recv buffer size
	s8      m_achProduct[MAX_PRODUCTID_LEN];	///< ��Ʒ��Ϣ
	s8      m_achTerVer[MAX_PRODUCTID_LEN];		///< �汾��Ϣ
	u16		m_wPortRangeStart;                  ///< tcp or tls port range must be assigned by business, or random allocation
	u16		m_wPortRangeEnd;                    ///< range end

	BOOL32	m_bIsh460GW;			            ///< Ĭ��ֵFALSE,5.0gkӦ���ô�ֵΪTRUE,��adapter�оͲ�����kdvdatanet�ĵ���
	TSipTsxTimeout m_tTsxTimeout;               ///< tsx time out struct

	BOOL32	m_bUseTLS;                          ///< �Ƿ�����TLS����
	TTlsCfg m_tTlsCfg;                          ///< tls config

	BOOL32 m_bUseTLSDefConfig;	                ///< �Ƿ�����TLS Default Config
	BOOL32  m_bUseIpv6;							///< is use ipv6
	ALL_LOG_CALlBACK  m_fpLogCB;				///< add callback function for print
	TAdapterLogCfg m_tSipLog;                   ///< Let the business set the PfcOpenLogFile parameters
public:
	/**
    * \brief            tagSipAdapterCfg Constructor
    * \return           void.
    */
	tagSipAdapterCfg()
	{
		Clear();
		m_wPortRangeStart = KDV_PORTRANGE_DEFAULT_START;
		m_wPortRangeEnd	  = KDV_PORTRANGE_DEFAULT_FINISH;
		m_tTsxTimeout.Clear();
	}
	/**
    * \brief            tagSipAdapterCfg init
    * \return           void.
    */
	void Clear()
	{
		memset(this , 0 , sizeof(tagSipAdapterCfg) );
		m_emEndpointType			= emEndpointTypeUnknown;
		m_wRegClientNum				= 2;
		m_dwMaxSendReciveBufferSize = 20480;
		m_bIsh460GW					= FALSE;
		m_bUseTLS                   = FALSE;
		m_bUseTLSDefConfig          = FALSE;
		m_bUseIpv6                = TRUE;
		m_tTlsCfg.Clear();
		m_tLocalAddrV4.Clear();
		m_tLocalAddrV4.m_emType     = PFC_TRANSPORT_TYPE_IP;
		m_tLocalAddrV6.Clear();
		m_tLocalAddrV6.m_emType     = PFC_TRANSPORT_TYPE_IPV6;
		m_fpLogCB = NULL;
		m_tSipLog.clear();
	}
}TSipAdapterCfg;



/// stack init result
typedef struct tagStackInitRes
{
	TSipAdapterCfg tSipAdapterCfg;  ///< sipadapter config
	BOOL32 bSuc;                    ///< is successful
	/**
    * \brief            tagStackInitRes Constructor
    * \return           void.
    */
	tagStackInitRes()
	{
		memset((void*)&tSipAdapterCfg, 0, sizeof(tSipAdapterCfg));
		bSuc = TRUE;
	}
}TStackInitRes;

/// sipadapter callback
typedef struct tagSipAdapterCB
{
	/**
	* \brief            new call notify
	* \param[in]        haCall        :upper call handle
	* \param[in]        hsCall        :lower call handle
	* \param[in]        pBuf          :null
	* \param[in]        dwBufLen      :0
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyNewCall)(s32 haCall, s32 hsCall, const void *pBuf, u32 dwBufLen);

	/**
	* \brief            Notify Call Ctrl Msg
	* \param[in]        haCall        :upper call handle
	* \param[in]        hsCall        :lower call handle
	* \param[in]        wMsgType      :h_call_capsetnotify,h_call_connected,h_call_disconnected,h_call_callidnotify\n
	* \param[in]        pBuf          :h_call_capsetnotify - CSipCapSet + bool32 + CSipCapSet bool32�ж��Ƿ�Ϊ����\n
	                                   h_call_connected - TSipCallParam\n
                                              h_call_incoming - TSipCallParam + s32(nViaCount) + ( u8(TpType) + TSipHostAddress ) * nViaCount \n
	                                   h_call_disconnected - ���йҶ�ԭ��(u8)+sip��ͷCall-ID�ַ���(only mcu need callid)\n
	                                   h_call_callidnotify - sip��ͷCall-ID�ַ���
	* \param[in]        dwBufLen      :buffer length
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyCallCtrlMsg)(s32 haCall, s32 hsCall,u16 wMsgType, const void *pBuf,u32 dwBufLen);

	/**
	* \brief            �������������(uas)
	* \param[in]        haCall        :upper call handle
	* \param[in]        hsCall        :lower call handle
	* \param[in]        pHandle       :stack handle
	* \param[in]        pBuf          :sip��������(EmSipArbitraryMsgType) + �Ƿ���ڷǱ��ͷ(BOOL32) + �Ǳ��ͷ����(u8) 
	                                   + �Ǳ��ͷ��Чֵ(�Ǳ��ͷ���� * sizeof(TSipHead)) + ���峤��(u32) + ��������(From��To��Via)
	* \param[in]        dwBufLen      :buffer length
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyConfCtrlReqMsg)(s32 haCall, s32 hsCall, TSipUasHandle pHandle, const void *pBuf, u32 dwBufLen);

	/**
	* \brief            �������Ӧ����(uac)
	* \param[in]        haCall        :upper call handle
	* \param[in]        hsCall        :lower call handle
	* \param[in]        pHandle       :stack handle
	* \param[in]        pBuf          :buffer (if dwBufLen == 0 || pbuf == NULL, This means that the message has not been answered)
	* \param[in]        dwBufLen      :buffer length
	                    dwBufLen                        pBuf�����ݣ�
						sizeof(EmSipArbitraryMsgType)   --ArbitraryMsgType
						+ sizeof(BOOL32)                --bHaveNonStdHdr
						+ sizeof(u8);                   --byNonStdHdr�Ǳ�ͷ����
						+ NonStdHdrBody                 --byNonStdHdr* sizeof(TSipHead) �Ǳ�ͷ
						+ sizeof(u32)                   --dwBodyLen
						+ dwBodyLen                     --ptPjBody->data�������body�Ļ������
						+ sizeof(s32)                   --nStatusCode
						+ sizeof(TUriSip)               --tUriFrom
						+ sizeof(TUriSip)               --tUriTo
						+ sizeof(TUriSip)               --tUriVia
						+ sizeof(u32)                   --dwStatusReasonLen
						+ dwStatusReasonLen             --status.reason.ptr
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyConfCtrlRspMsg)(s32 haCall, s32 hsCall, TSipUacHandle pHandle, const void *pBuf, u32 dwBufLen);

	/**
	* \brief            ע�����֪ͨ����(uas)
	* \param[in]        pHandle       :stack handle
	* \param[in]        pBuf          :TRegReqInfo
	* \param[in]        dwBufLen      :buffer length
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyRegCtrlReqMsg)(TSipUasHandle pHandle, const void *pBuf, u32 dwBufLen);

	/**
	* \brief            ע�����֪ͨ����(uac)
	* \param[in]        haReg         :upper reg handle
	* \param[in]        hsReg         :lower reg handle
	* \param[in]        wMsgType      :h_sip_state2failed,h_sip_state2registered
	* \param[in]        pBuf          :h_sip_state2failed - ������(s32)\n
	                                   h_sip_state2registered - via��receive ip��u32��\n
	                                   �������ΪNULL
	* \param[in]        dwBufLen      :buffer length
	* \return           BOOL32, TRUE/FALSE
	*/
	s32 (PROTO_CALLBACK* cbNotifyRegCtrlRspMsg)(s32 haReg, s32 hsReg, u16 wMsgType, const void *pBuf, u32 dwBufLen);

	/**
    * \brief            tagSipAdapterCB Constructor
    * \return           void.
    */
	tagSipAdapterCB()
	{
		memset(this, 0, sizeof(tagSipAdapterCB));
	}

} TSipAdapterCB;

/// channel reason
enum EmSipChannelReason
{
	emSipChannelReasonBegin,        ///< channel reason begin
	emSipChannelDisconnectNormal,   ///< Channel Disconnect Normal
	emSipDualOffLine,               ///< Dual Off Line
	emSipChannelDisconnectForce,	///< ����˫����˫�������ͳɹ������յ��Զ˷�200Ok������Ӧ��
	emSipDualNotSend,	            ///< ˫��δ��Э��ջ���ͳ�ȥ����ǰ״̬����ȷ������Э��ջδ���ͣ�
};

/// ���йҶ�ԭ��
enum EmSipCallDisconReason
{
	emSipDiscon_Busy			= 1,	///< �Զ�æ
	emSipDiscon_Normal			= 2,	///< �����Ҷ�
	emSipDiscon_Rejected		= 3,	///< �Զ˾ܾ�
	emSipDiscon_Unreachable		= 4,	///< �Զ˲��ɴ�
	emSipDiscon_Local			= 5,	///< ����ԭ��
	emSipDiscon_unknown			= 6,	///< δ֪ԭ��
		
	emSipDiscon_AlredayInDualStream = 7,		///< ����˫���У��޷���������˫��
	emSipDiscon_Normal_Peer			= 8,        ///< �Է��Ҷ�
	emSipDiscon_Abnormal			= 9,        ///< ���˵��߹Ҷ�
	emSipDiscon_Abnormal_Peer		= 10,       ///< �Զ˵��߹Ҷ�
	emSipDiscon_MultiConfOver		= 11,       ///< ���������
	emSipDiscon_ConfAlredayExit		= 12,       ///< �����Ѿ�����
	emSipDiscon_InvalidDestAddr		= 13,		///< ��Ч��Ŀ�ĵ�ַ
		
	emSipDiscon_CallFull			= 14,		///< ���о������(���ܴ��ں��о��δ�ͷŵ�����)
	emSipDiscon_MaxMtNum            = 15,       ///< �����к����Ѵ�����

	emSipDisconnect_StreamEncryptKeyNotEqual = 16,    ///< ��������֧�ֵ��������ܣ���ʽ����Կ����һ��

	emSipDiscon_RmtReconnect = 100,   ///< ��������ȶԶ˵�  
	emSipDiscon_EncrypeErr,           ///< encrypt error
	emSipDiscon_AdaptBusy,            ///< adapter busy
	emSipDiscon_MccDrop,              ///< ��عҶ�     
	emSipDiscon_ChairDrop,            ///< ��ϯ�Ҷ�     
	emSipDiscon_MMcuDrop,             ///< �ϼ�����Ҷ�  
	emSipDiscon_ConfReleaseNoMt,      ///< ���ն��Զ����-1����   
	emSipDiscon_ConfReleaseNoJoinedMt,///< �������ն��Զ����-5����    
	emSipDiscon_ConfReleaseOnlyOneMt, ///< ��һ�������ն��Զ����-10����  
	emSipDiscon_Exception,            ///< �쳣�Ҷ�   
	emSipDiscon_MpDisconnect,         ///< mp����   

	emSipDiscon_DonotDisturb,         ///< �����
	
	emSipLoadTlsCertFailed,           ///< Tls Cert load failed

	emSipDiscon_AuthenticationErr,	  ///< MT Authenticate Failed
	emSipDiscon_OverMaxPortLicense,    ///< over max port license
	emSipDiscon_NonExistNum    ///< Number does not exist
};

/// regserver���͵Ĳ�ѯָ��
typedef struct tagRegOptionData		
{
	u32 m_dwtime;						///< ע����
	u32 m_ip;							///< �ն˵�ip	
	u16 m_port;					    	///< �ն˵�port
	/**
    * \brief            tagRegOptionData Constructor
    * \return           void.
    */
	tagRegOptionData()
	{
		memset(this, 0, sizeof(tagRegOptionData));
	}
}TRegOptionData;

/// reg state
enum EmRegState
{
	emRegIdle,         /// idle
	emRegRegistering,  /// registering
	emRegRegistered,   /// registered
	emRegFailed,       /// failed
	emUnReg,           /// unreg
};

/// call type
enum EmSipCallType
{
	emDirect = 0,					///< ֱ�Ӻ���
	emByRedirect,					///< ͨ���ض������������
	emByPxy,						///< ͨ���������������
};



/// register reason
enum EmRegisterReason
{
	emRegNone = 0,     ///< none
	emRegSuc,          ///< ע��ɹ�
	emRegFail,         ///< ע��ʧ��
	emRegNotFound,     ///< not found
	emRegNameDup,      ///< ע�����������ʱ������������������Ϣ
	emRegTimeOut,      ///< ע����������ɴ��ʱ
};

/// �ն���Ϣ����
typedef struct tagTerminalInformation 
{
	TTERLABEL	m_tTerLabel;                 ///< ter label
	s8			m_achTerID[LEN_TERID + 1];   ///< ter id
	
	/**
    * \brief            tagTerminalInformation Constructor
    * \return           void.
    */
	tagTerminalInformation()
	{
		Clear();
	}
	/**
    * \brief            tagTerminalInformation init
    * \return           void.
    */
	void Clear()
	{
		m_tTerLabel.Clear();
        memset( m_achTerID, 0, sizeof(m_achTerID) );        
	}	
	
	/**
	* \brief            �����ն˱��
	* \param[in]        ptLabel       :ter label
	*/
	void SetLabel(const PTTERLABEL ptLabel)
	{
		if (ptLabel != NULL)
		{
			memcpy( &m_tTerLabel, ptLabel, sizeof(m_tTerLabel) );
		}		
	}
	/**
	* \brief            set label
	* \param[in]        byMcuNo       :mcu no
	* \param[in]        byTerNo       :ter no
	*/
	void SetLabel(u8 byMcuNo, u8 byTerNo)
	{
		if (byMcuNo <= MAX_MT_NUM_IN_CONF && byTerNo <= MAX_MT_NUM_IN_CONF)
		{
			m_tTerLabel.SetTerminalLabel(byMcuNo, byTerNo);
		}
	}
	/**
	* \brief            get ter label
	* \return           TTERLABEL.
	*/
	TTERLABEL& GetTerlabel()
	{
		return m_tTerLabel;
	}
	/**
	* \brief            get label
	* \param[in]        byMcuNo       :mcu no
	* \param[in]        byTerNo       :ter no
	*/
	void GetLabel(u8& byMcuNo, u8& byTerNo)
	{
		m_tTerLabel.GetTerminalLabel( &byMcuNo, &byTerNo );
	}
	/**
	* \brief            get mcu no
	* \return           u8.
	*/
	u8 GetMcuNo() 
	{ 
		return m_tTerLabel.GetMcuNo();	
	}
	/**
	* \brief            get ter no
	* \return           u8.
	*/
	u8 GetTerNo() 
	{ 
		return m_tTerLabel.GetTerNo();	
	}
	
	 /**
	 * \brief            set name
	 * \param[in]        pchName  :name value
	 * \return           BOOL32, TRUE/FALSE
	 */
	BOOL32 SetName(const s8* pchName)
	{
		if (pchName != NULL)
		{
			strncpy( m_achTerID, pchName, LEN_TERID + 1 );
			m_achTerID[LEN_TERID] = '\0';
			return TRUE;
		}
		return FALSE;
	}
	/**
	 * \brief            get name
	 * \return           s8*
	 */
	s8* GetName()
	{
		return m_achTerID;
	}
	/**
    * \brief            tagTerminalInformation operator =
    * \return           void.
    */
	void operator = (tagTerminalInformation& tTerInfo)
	{
		m_tTerLabel.SetTerminalLabel( tTerInfo.m_tTerLabel.GetMcuNo(), 
			tTerInfo.m_tTerLabel.GetTerNo() );
		
		strncpy( m_achTerID,tTerInfo.GetName(), LEN_TERID + 1);
	}
	/**
    * \brief            tagTerminalInformation operator !=
    * \return           BOOL32, TRUE/FALSE
    */
	BOOL32 operator != (tagTerminalInformation& tTerInfo)
	{
		if ( m_tTerLabel.GetMcuNo() == tTerInfo.m_tTerLabel.GetMcuNo() && 
			m_tTerLabel.GetTerNo() == tTerInfo.m_tTerLabel.GetTerNo() &&
			strcmp( m_achTerID, tTerInfo.m_achTerID ) == 0 )
		{
			return FALSE;
		}
		return TRUE;
	}
	/**
    * \brief            tagTerminalInformation operator ==
    * \return           BOOL32, TRUE/FALSE
    */
	BOOL32 operator == (tagTerminalInformation& tTerInfo)
	{
		if ( m_tTerLabel.GetMcuNo() == tTerInfo.m_tTerLabel.GetMcuNo() && 
			m_tTerLabel.GetTerNo() == tTerInfo.m_tTerLabel.GetTerNo() &&
			strcmp( m_achTerID, tTerInfo.m_achTerID ) == 0 )
		{
			return TRUE;
		}
		return FALSE;
	}
}TTERINFO,*PTTERINFO;

/// ������ַ
typedef struct PROTO_API tagAliasTransAddress
{
	s8  m_achAlias[LEN_ALIAS + 1];			///< h323-Id ��������λΪ��
	/**
    * \brief            tagAliasTransAddress Constructor
    * \return           void.
    */
	tagAliasTransAddress()
	{
		Clear();
	}
	/**
    * \brief            tagAliasTransAddress init
    * \return           void.
    */
	void Clear()
	{
		memset( m_achAlias, 0, sizeof(m_achAlias) );
	}
	
	/**
	* \brief            set alias address
	* \param[in]        pAlias          :alias string
	* \return           BOOL32, TRUE/FALSE
	*/
	BOOL32 SetAliasAddr( const s8* pAlias )
	{
		memset( m_achAlias, 0, sizeof(m_achAlias) );
		s32 nLen = Minimum( (s32)strlen(pAlias), (s32)LEN_ALIAS );
		strncpy( m_achAlias, pAlias, nLen );
		m_achAlias[nLen] = '\0';
		return TRUE;
	}	
	
	/**
	* \brief            get alias address
	* \return           s8*
	*/
	s8* GetAliasName()  
	{
		return m_achAlias;	
	}
}TAliasTransAddress, *PTAliasTransAddress;

/// ����ʱ�ı�����ַ
typedef struct PROTO_API tagSipTransAddress
{
	CallAddrType        m_emType;		///< ��������
	PFC_IPADDR  	    m_tNetAddr;		///< IP����ʱʹ��	
	TAliasTransAddress	m_tAlias;		///< ��������ʹ��
	emProtocolType      m_emProtocolType;///<  Protocol Type

	/**
    * \brief            tagSipTransAddress  Constructor
    * \return           void.
    */
	tagSipTransAddress()
	{
		Clear();
	}
	/**
    * \brief            tagSipTransAddress init
    * \return           void.
    */
	void Clear()
	{
		m_emType         = emcat_err;
		m_emProtocolType = emTypeInvalid;
		m_tNetAddr.Clear();
		m_tAlias.Clear();
	}
	
}TSipTransAddress, *PTSipTransAddress;

/// goal type
typedef enum
{
    emCreate,                              ///< create 
	emJoin,                                ///< join
	emInvite,                              ///< invite
	emCapabilityNegotiation,               ///< capability negotiation
	emCallIndependentSupplementaryService, ///< Call Independent Supplementary Service
	emLastCG                               ///< last CG
} EmConfGoalType;

/// sip encrypt key
typedef struct PROTO_API tagTSipEncryptKey
{
	emEncryptType m_emEncryptType;        ///< encrypt type
	u8 m_byLen;                           ///< ��Կ����
	u8 m_abyKey[MAX_SIP_ENCRYPT_KEY_LEN]; ///< ��Կ����
	
public:
	/**
    * \brief            tagTSipEncryptKey init
    * \return           void.
    */
	void Clear()
	{
		memset( this, 0, sizeof(tagTSipEncryptKey) );
		m_emEncryptType = emEncryptTypeNone;
	}
	/**
    * \brief            tagTSipEncryptKey  Constructor
    * \return           void.
    */
	tagTSipEncryptKey()
	{
		Clear();
	}
	/**
    * \brief            tagTSipEncryptKey  Print
    * \return           void.
    */
	void Print()
	{
		PfcPrintf(TRUE, FALSE, "TSipEncryptKey:EncryptType=%d, m_byLen=%d, key:", m_emEncryptType, m_byLen);
		s32 nLen = Minimum(m_byLen, LEN_AES_KEY);
		if ( emEncryptTypeNone != m_emEncryptType )
		{
			for (int i = 0; i < nLen; i++)
			{
				PfcPrintf(TRUE, FALSE, "%c", m_abyKey[i]);
				if ( i == (nLen - 1))
				{
					PfcPrintf(TRUE, FALSE, "\n");
				}
			}
		}		
	}
}TSipEncryptKey;

/// sip poll info for tp
typedef struct PROTO_API tagTSipPollInfoTP
{
	BOOL32 m_bIsPoll;                  ///< is poll
	u16  m_wPollExpire;                ///< poll expire
	
	/**
    * \brief            tagTSipPollInfoTP init
    * \return           void.
    */
	void Clear()
	{
		memset( this, 0, sizeof(tagTSipPollInfoTP) );
	}
	/**
    * \brief            tagTSipPollInfoTP Constructor
    * \return           void.
    */
	tagTSipPollInfoTP()
	{
		Clear();
	}
}TSipPollInfoTP;

/// sip config aux mix info for tp
typedef struct PROTO_API tagTSipConfAuxMixInfoTP
{
	BOOL32 m_bStart;                            ///< is start
	u16	m_wConfID;                              ///< config id
	u16 m_wSpeakerIndex;					    ///< �������������
	u16	m_awList[MAX_SIP_CONF_AUDMIX_NUM_TP];	///< ����ID
	
	/**
    * \brief            tagTSipConfAuxMixInfoTP init
    * \return           void.
    */
	void Clear()
	{
		memset( this, 0, sizeof(tagTSipConfAuxMixInfoTP) );
		m_wConfID = SIP_INVALID_INDEX_TP;
		m_bStart = FALSE;
	}
	/**
    * \brief            tagTSipConfAuxMixInfoTP Constructor
    * \return           void.
    */
	tagTSipConfAuxMixInfoTP()
	{
		Clear();
	}
}TSipConfAuxMixInfoTP;

typedef struct PROTO_API tagTSipConfSpeechMixTP
{
	u32          m_mode;        //0:idle   1: smart   2:custom
	u16          m_wNum;
	u16          m_awMixEp[MAX_MIX_EP_LIST_LEN];
	BOOL32       m_bVacOn;

	void Clear()
	{
		memset(this, 0, sizeof(tagTSipConfSpeechMixTP));
	}

	tagTSipConfSpeechMixTP()
	{
		Clear();
	}
}TSipConfSpeechMixTP;

/// conference information
typedef struct PROTO_API tagTSipConfInfo
{
	s8	 m_achConfId[MAX_SIP_CONF_ID_LEN + 1];			///< conference ID
	s8	 m_achConfName[MAX_SIP_CONF_NAME_LEN + 1];		///< conference name
	s8	 m_achConfNumber[MAX_SIP_CONF_E164_LEN + 1];	///< conference number
	s8	 m_achConfPwd[MAX_SIP_PASSWORD_LEN + 1];	    ///< conference password
	BOOL32 m_bNeedPassword;                             ///< is need password
	u16  m_wConfDuration;							    ///< �������ʱ��		
	PayloadType   m_emVideoFormat;				        ///< ������Ƶ��ʽ(VIDEO_H261��)
	PayloadType   m_emAudioFormat;				        ///< ������Ƶ��ʽ(AUDIO_MP3��)
	emResolution  m_emResolution;					    ///< ������Ƶ�ֱ���(VIDEO_CIF��)
	u8 m_byProfile;									    ///< ����profile
	u8 m_byVidMPI;					                    ///< ����֡��
	BOOL32 m_bIsAutoVMP;								///< �Ƿ��Զ�����ϳ�
	BOOL32 m_bIsMix;	    							///< �Ƿ����
	PayloadType	m_emSecVideoFormat;			            ///< ˫����ʽ
	emResolution m_emSecVidRes;					        ///< ˫���ֱ���
	u8 m_bySecProfile;								    ///< ˫��profile
	u8 m_bySecVidMPI;					                ///< ˫��֡��
	u16 m_wCallRate;									///< ��������(kbps)
	u16	m_wDualCallRate;								///< ˫����������(kbps)
	TSipPollInfoTP  m_tPollInfo;                        ///< poll info
	TSipConfAuxMixInfoTP m_tConfAudMixInfo;             ///< config audio mix info
	TSipConfSpeechMixTP  m_tSpeechMixInfo;              ///< speech mix info
	
public:
	/**
    * \brief            tagTSipConfInfo Constructor
    * \return           void.
    */
	tagTSipConfInfo()
	{ 
		Clear();	
	}
	/**
    * \brief            tagTSipConfInfo init
    * \return           void.
    */
	void Clear()
	{
		memset( this, 0, sizeof(tagTSipConfInfo) );
		m_tPollInfo.Clear();
		m_tConfAudMixInfo.Clear();
		m_tSpeechMixInfo.Clear();
	}
	
}TSipConfInfo ,*PTSipConfInfo;

/// ������в���
typedef struct PROTO_API tagSipCallParam 
{
	BOOL32				m_bCreateConf;                          ///< is create conf
	EmConfGoalType		m_emConfGoalType;  						///< �����Ŀ������
	u32					m_dwCallRate;							///< ��������	(kbps)
	TSipUrl				m_tCalledAddress;						///< ���е�ַ
	TSipUrl				m_tCallingAddress;						///< ���е�ַ
	EmSipCallType		m_emCallType;							///< �������� (direct|by pxy|by redirect)
    THostName			m_tServerAddr;							///< pxy server| redirect server    
	EmSipConnection		m_emSipConnection;						///< ������������ tcp udp tls default udp
	s32					m_nProductIdSize;                       ///< productid size 
	u8					m_abyProductId[MAX_PRODUCTID_LEN];		///< ��Ʒ��
	s32					m_nVerIdSize;                           ///< version id size
	u8					m_abyVersionId[MAX_PRODUCTID_LEN];		///< �汾��
	emEndpointType		m_emSipTerType;                         ///< endpoint type
	
	/// ��������
	EmSipLevel			m_emSipLevel;							///< ����
	s32					m_nScreenNum;                           ///< ����
	u8					m_abyConfId[LEN_GUID];		            ///< �����,����16 octet
	u16					m_wConfId;                              ///< conf id
	u8					m_byTerNum;								///< �����ն˸���
	TSipTransAddress	m_atList[MAX_TERMINAL_NUM];				///< �����ն��б�
	TSipConfInfo		m_tConfInfo;							///< ������Ϣ
	
	BOOL32				m_bNatCall;								///< �����Ƿ��nat
	BOOL32				m_bAddTpAttr;							///< �Ƿ����TP���ԣ�sip��ͷ��sdp��������TP�Ǳ����ԣ�
	BOOL32				m_bSupportMmcu;							///< �Ƿ�֧�ֺϲ�����
	
	s8 m_achCallId[MAX_NUM_CALLID];								///< CALL-ID	
	TSipEncryptKey	    m_tStreamKey;							///< ��m_tStreamKey.m_emEncryptType=emEncryptTypeNone ��ʾ����������

    EmVendorProductId   m_emVendorId;                           ///< vendor id
	EmVendorProductId   m_emPeerVendorId;                       ///< peer vendor id

	u8 m_byNonStdHdrNum;	                                    ///< �Ǳ�sip��ͷ����
	TSipHead m_atNonStdHdr[MAX_SIP_NONSTD_HEADER_NUM];	        ///< �Ǳ�sip��ͷ

#ifdef _KDV_SRTP_SUPPORT_
	EmSrtpMode			m_emSrtpMode;	                        ///< None��Optional��Mandatory
#endif
	TSipUrl				m_tReqUri;                              ///< request uri

	s8 m_achPassword[MAX_PASSWORD_LEN+1];                       ///< ��֤����
	s8 m_achUsername[MAX_USER_NAME_LEN+1];	                    ///< ��֤�û���
	s8 m_achDomainName[MAX_DOMAIN_NAME_LEN+1];	                ///< ����

	EmTlsType m_emTlsType;                                      ///< TLS type
public:
	/**
    * \brief            tagSipCallParam  Constructor
    * \return           void.
    */
	tagSipCallParam()
	{
		memset(this, 0, sizeof(tagSipCallParam));
		m_tStreamKey.Clear();
		m_emSipConnection = emSipUdpConnection;
		m_emVendorId      = emKeda;
		m_emPeerVendorId  = emKeda;
#ifdef _KDV_SRTP_SUPPORT_
		m_emSrtpMode      = emSrtpModeNone;
#endif
		m_emTlsType       = emTlsNone;
	}
	
	/**
	* \brief            set conf id
	* \param[in]        pchConfId          :conf id string
	* \param[in]        byLen              :id length
	*/
	void SetConfId(const u8* pchConfId, u8 byLen)
	{
		if (pchConfId == NULL || (s32)byLen <= 0)
		{
			return;
		}
		
		s32 nReal = Minimum(Maximum((s32)LEN_1, (s32)byLen), (s32)LEN_GUID);
		memcpy(m_abyConfId, pchConfId, nReal);
	}
	
}TSipCallParam;

/// sip node info
typedef struct tagSipNodeInfo
{
    EmVendorProductId 	m_emVendorId;                         ///< vendor id
	BOOL32     			m_bMt;                                ///< is mt
	s8       			m_achProductId[MAX_PRODUCTID_LEN + 1];///< product id
	s8       			m_achVersion[MAX_PRODUCTID_LEN + 1];  ///< version id
	
	public:
		/**
        * \brief            tagSipNodeInfo  Constructor
        * \return           void.
        */
		tagSipNodeInfo()
		{ 
			Clear();
		}
		/**
        * \brief            tagSipNodeInfo  init
        * \return           void.
        */
		void Clear()
		{
			memset(this, 0, sizeof(tagSipNodeInfo));
		}
}TSipNodeInfo;

/// sdp session info
typedef struct tagSdpSessionInfo
{
    s8      m_achSessionName[SESSION_NAME_LEN + 1];     ///< session name

    s8      m_achOriginSID[SESSION_ID_LEN + 1];         ///< SessionId
    s8      m_achOriginUserName[MAX_PRODUCTID_LEN + 1]; ///< User name
    //s8      m_achOriginVer[SESSION_VERSION_LEN+1];    ///< session Version
	s32     m_nOriginVer;                               ///< origin ver
    s8      m_achOriginAddress[128];                    ///< Address-url
    s8      m_achTerVer[SESSION_INFO_LEN + 1];          ///< terminal ver
    
    u32     m_dwBandWidth;                              ///< band width
    u32     m_dwStartTime;                              ///< start time
    u32     m_dwEndTime;                                ///< end time
    u32     m_dwIP;                                     ///< ip
public:
	/**
    * \brief            tagSdpSessionInfo  Constructor
    * \return           void.
    */
	tagSdpSessionInfo(){ memset(this, 0, sizeof(tagSdpSessionInfo));}
} TSdpSessionInfo;

/// endpoint type
enum EmSipEndpointType
{
	emSipEndpointTypeUnknown  = 0,            ///< unknown
	emSipEndpointTypeCNS	  = 0x01,         ///< cns
	emSipEndpointTypeUMS	  = 0x02,         ///< ums
	emSipEndpointTypeRegister = 0x04          ///< register
};
/// sip register local info
typedef struct tagSipRegistLocalInfo
{
	EmSipEndpointType  m_emEndpointType;     ///< ������ums��cns
	u32 m_dwLocalIP;                         ///< ����IP��ַ
	s8  m_achSoftVersion[MAX_USER_NAME_LEN + 1];  ///< ����汾��
	s8  m_achCompileTime[MAX_USER_NAME_LEN + 1];  ///< ����ʱ�� 
public:
	/**
    * \brief            tagSipRegistLocalInfo  Constructor
    * \return           void.
    */
    tagSipRegistLocalInfo() 
    {memset(this, 0, sizeof(tagSipRegistLocalInfo));}
}TSipRegistLocalInfo, *PTSipRegistLocalInfo;
/// register info
typedef struct tagRegisterInfo
{
	TSipUrl m_tFromUrl;			                   ///< From �ֶ�URL
	TSipUrl m_tToUrl;			                   ///< To �ֶ�URL
	THostName m_tLocalAddr;		                   ///< ����������Ϣ,for via contact
	THostName m_tRegistrar;		                   ///< ע��server������Ϣ
	u32 m_dwExpires;			                   ///< ��ʱʱ��,��λ��
	TSipRegistLocalInfo			m_tSipRegLocalInfo;///< register local info
	EmSipConnection	m_emConnection;	               ///< ע���ַ����
	PFC_IPADDR m_tNatAddress;                      ///< nat address
	BOOL32 m_bPortReused;	                       ///< �Ƿ�˿ڸ���
	s8	m_achProductId[MAX_PRODUCTID_LEN + 1];     ///< product id
	s8	m_achVersionId[MAX_PRODUCTID_LEN + 1];     ///< version id
	emEndpointType	 m_emEndpointType;             ///< endpoint type
	EmVendorProductId m_emVendorId;                ///< vendor id
	EmTlsType         m_emTlsType;                 ///< tls type
	s8                m_achDevId[MAX_QT_ID_LEN];   ///< max length of device id for qt tls
	u8       m_byNonStdHdrNum;                          ///< max nonstandard header number
	TSipHead m_atNonStdHdr[MAX_SIP_NONSTD_HEADER_NUM];  ///< nonstandard header
	BOOL32            m_bAddTpAttr;                 /// istps 
public:	
	/**
    * \brief            tagRegisterInfo  Constructor
    * \return           void.
    */
	tagRegisterInfo()
	{ 
		memset(this, 0, sizeof(tagRegisterInfo));
		m_emConnection   = emSipUdpConnection;
		m_emEndpointType = emEndpointTypeMT;
		m_emVendorId     = emKeda;
		m_emTlsType      = emTlsNone;
	}
}TRegisterInfo;
/// sip register name
typedef struct tagSipRegName
{
	EmHostNameType m_emSipAddrType;
	s8     m_achUserName[MAX_USER_NAME_LEN + 1];         ///< ע����
	s8     m_achPassword[MAX_PASSWORD_LEN + 1];	        ///< ע������
	s8     m_achDisplayName[MAX_USER_NAME_LEN + 1];      ///< ��ʾ����

	s8     m_achPeerUserName[MAX_USER_NAME_LEN + 1];     ///< �Զ�ע����
	s8     m_achPeerDisplayName[MAX_USER_NAME_LEN + 1];  ///< �Զ���ʾ����
	/**
    * \brief            tagSipRegName  Constructor
    * \return           void.
    */
	tagSipRegName()
	{
		memset( this, 0, sizeof(tagSipRegName) );
	}
}TSipRegName, *PTSipRegName;
/// register request
typedef struct tagRegisterRequest
{
	TSipRegName      m_atSipRegName[MAX_NUM_REGNAME_SIZE]; ///< sip reg name
	s32				 m_nSipRegArraySize;                   ///< sip reg array size
	
	PFC_IPADDR       m_atContactAddr[MAX_NUM_CONTACT_ADDR];///< ע���ַ
	u32 m_dwExpires;                                       ///< ��ʱʱ��,��λ��
	s8 m_achCallId[MAX_NUM_CALLID];                        ///< ����ID
	s32 m_nCSqence;                                        ///< ���к� m_tRegistrar m_dwExpires m_aCallId m_nCSqence ��Ҫҵ��㱣�棬�Ա��ѯ
	EmSipConnection m_emSipConnection;                     ///< sip connection
    TSipRegistLocalInfo  m_tLocalInfo;                     ///< local info
	
public:
	/**
    * \brief            tagRegisterRequest  Constructor
    * \return           void.
    */
	tagRegisterRequest()
	{ 
		memset(this , 0 , sizeof(tagRegisterRequest));
		m_emSipConnection = emSipTcpConnection;
	}
}RegisterRequest;

/// register response
typedef struct tagRegisterResponse
{
	PFC_IPADDR       m_tContactAddr;    ///< contact address
	EmSipConnection  m_emSipConnection; ///< sip connection
	BOOL32 m_bSerchPrefix;              ///< �ж�regserver�Ƿ�����ǰ׺���ң������ǰ׺���ң��ظ���300�оͽ�achAliasд�뵽contact��ַ��
	s8 m_achAlias[MAX_USER_NAME_LEN + 1];    ///< alias
public:
	/**
    * \brief            tagRegisterResponse  Constructor
    * \return           void.
    */
	tagRegisterResponse()
	{
		memset(this, 0, sizeof(tagRegisterResponse));
		m_emSipConnection = emSipTcpConnection;
	}
}RegisterResponse;

/// sip alias type
enum EmSipAliasType
{
	sip_Alias_Unknow, ///<  sip alias unknown
	sip_Alias_e164,   ///<  e164
	sip_Alias_h323,   ///<  h323
	sip_Alias_IP,     ///<  ip
};
/// sip alias
typedef struct tagTSipAlias
{
	EmSipAliasType	m_emType;                         ///< sip alias type
	s8				m_achAlias[MAX_USER_NAME_LEN + 1];     ///< alias string
	/**
    * \brief            tagTSipAlias  Constructor
    * \return           void.
    */
    tagTSipAlias()
	{
		memset( this, 0, sizeof(tagTSipAlias) );
	}
}TSipAlias;
/// Sip reg Nsm Type
enum EmSIPRegNSMType
{
	emSipRegNSMType_CNS = 0,  ///< cns
	emSipRegNSMType_UMS,      ///< ums
	emSipRegNSMType_ALL,      ///< all
	emSipRegNSMType_CONF = 10,///< conf
	emSipRegNSMType_CONF_TLS ,///< don't add kdNstd-ApplicationHandle
};
/// sip reg NSM
typedef struct tagSIPRegNSM
{
	EmSIPRegNSMType m_emType;

	PFC_IPADDR m_tRegSeverAddr;      ///< ע���������ַ
	PFC_IPADDR m_tRegLocalAddr;      ///< ���ص�ַ

	TSipRegName	m_tSipRegName;		 ///< RegName: including user and display name for SIP header
	EmSipConnection m_emConn;	     ///< tcp/tls or udp

	BOOL32 m_bIsAddNonstHeader;      ///< if use Add Nonstd Header 
	TSipHead m_tNonstdAttr;          ///< if m_bIsAddNonstHeader is true,m_tNonstdAttr will be used
	/**
    * \brief            tagSIPRegNSM  Constructor
    * \return           void.
    */
	tagSIPRegNSM()
	{
		memset( this, 0, sizeof(tagSIPRegNSM) );
		m_tSipRegName.m_emSipAddrType = emUrlNone;
		m_emConn = emSipUdpConnection;
	}
}TSIPRegNSM;
/// sip reg pack info
typedef struct tagTSipRegPackInfo
{
	u16 m_wPackSeq;       ///< ����ţ���1��ʼ��0Ϊ��Чֵ
	u16 m_wTotalPackNum;  ///< ������
	/**
    * \brief            tagTSipRegPackInfo  Constructor
    * \return           void.
    */
	tagTSipRegPackInfo()
	{
		m_wPackSeq = 0;
		m_wTotalPackNum = 0;
	}
	
}TSipRegPackInfo, *PTSipRegPackInfo;
/// sip reg info
typedef struct tagTSipRegInfo
{
	u16		   m_wAliasNum;                           ///< alias number
	TSipAlias  m_atAlias[MAX_NUM_REGNAME_SIZE];       ///< ��ʱ��Ϊ���ֵΪ64������Ϊһ������
	EmSipEndpointType m_emSelfType;                   ///< ע�᷽ ��ϵͳ����(UMS��CNS)    
	/**
    * \brief            tagTSipRegInfo  Constructor
    * \return           void.
    */
	tagTSipRegInfo()
	{
		m_wAliasNum = 0;
		memset( m_atAlias, 0, sizeof( m_atAlias ) );
		m_emSelfType = emSipEndpointTypeUnknown;
	}
	
}TSipRegInfo;

/// sip reg pack xml
typedef struct tagTSipRegPackXml
{
	TSipRegPackInfo tPackInfo;    ///< pack info
	EmSIPRegNSMType emType;       ///< sip reg nsm type
	TSipRegInfo  tRegInfo;        ///< reg info
	/**
    * \brief            tagTSipRegPackXml  Constructor
    * \return           void.
    */
	tagTSipRegPackXml()
	{
		emType = emSipRegNSMType_ALL;
	}
}TSipRegPackXml;
/// sip reg info ums
typedef struct tagTSipRegInfoUms
{
	u16		   m_wAliasNum;                                ///< alias number
	TSipAlias  m_atAlias[MAX_NUM_REGNAME_SIZE];            ///< ��ʱ��Ϊ���ֵΪ64������Ϊһ������
	PFC_IPADDR   m_atContactAddr[MAX_NUM_CONTACT_ADDR];///< ע���ַ
	u32 m_dwExpires;                                       ///< ��ʱʱ��,��λ��
	EmSipConnection emSipConnection;                       ///< sip connection
	TSipRegistLocalInfo m_tSipRegistLocalInfo;             ///< sip register local info
	/**
    * \brief            tagTSipRegInfoUms  Constructor
    * \return           void.
    */
	tagTSipRegInfoUms()
	{
		Clear();
	}
	/**
    * \brief            tagTSipRegInfoUms  init
    * \return           void.
    */
	void Clear()
	{
		memset(this, 0, sizeof(tagTSipRegInfoUms));
	}
	
}TSipRegInfoUms;
/// sip reg info cns
typedef struct tagTSipRegInfoCns
{
	u16		   m_wAliasNum;                                ///< alias number
	TSipAlias  m_atAlias[MAX_NUM_REGNAME_SIZE_CNS];        ///< ��ʱ��Ϊ���ֵΪ64������Ϊһ������
	PFC_IPADDR   m_atContactAddr[MAX_NUM_CONTACT_ADDR];///< ע���ַ
	u32 m_dwExpires;                                       ///< ��ʱʱ��,��λ��
	EmSipConnection emSipConnection;                       ///< sip connection
	TSipRegistLocalInfo m_tSipRegistLocalInfo;             ///< sip register loacal info
	/**
    * \brief            tagTSipRegInfoCns  Constructor
    * \return           void.
    */
	tagTSipRegInfoCns()
	{
		Clear();
	}
	/**
    * \brief            tagTSipRegInfoCns  init
    * \return           void.
    */
	void Clear()
	{
		memset(this, 0, sizeof(tagTSipRegInfoCns));
	}
}TSipRegInfoCns;
/// sip reg pack xml b2
typedef struct tagTSipRegPackXmlB2
{
	TSipRegPackInfo m_tPackInfo;          ///< packet info
	EmSIPRegNSMType m_emType;             ///< sip reg nsm type
	EmSipEndpointType  m_emEndpointType;  ///< endpoint type
	u16	m_wTotalRegInfo;                  ///< total reg info
	/**
    * \brief            tagTSipRegPackXmlB2  Constructor
    * \return           void.
    */
	tagTSipRegPackXmlB2()
	{
		m_emType = emSipRegNSMType_ALL;
		m_wTotalRegInfo = 0;
	}
}TSipRegPackXmlB2;


/// sip nonstd data
typedef struct tagSipNonStdData
{
	EmSipConnection m_emConn;	                         ///< tcp or udp
	TSipUrl m_tLocalUrl;	                             ///< ���˵�ַ
	TSipUrl m_tRemoteUrl;	                             ///< �Զ˵�ַ
	u8 m_byNonStdHdrNum;	                             ///< �Ǳ�sip��ͷ����
	TSipHead m_atNonStdHdr[MAX_SIP_NONSTD_HEADER_NUM];	 ///< �Ǳ�sip��ͷ
	/**
    * \brief            tagSipNonStdData  init
    * \return           void.
    */
	void Clear()
	{
		memset(this, 0, sizeof(tagSipNonStdData));
	}
	/**
    * \brief            tagSipNonStdData  Constructor
    * \return           void.
    */
	tagSipNonStdData()
	{
		Clear();
	}
} TSipNonStdData;
/// register request info
typedef struct tagRegReqInfo
{
	TSipUri m_tLocalUri;	                                ///< Currently point to Request-URI ip address 
	s8 m_achCallId[MAX_SDP_ATTR_VALUE_LEN];                 ///< call id 
	s8 m_achRegName[MAX_USER_NAME_LEN + 1];	                    ///< Register name 
	TSipUri m_tUaAddress;	                                ///< Local ip address 
	TSipUri m_tUaNatAddress;	                            ///< Local real address with nat 
	s32	m_nExpires;	                                        ///< Expires parameter, otherwise -1 if not present. 
	BOOL32 m_bIsContactStar;	                            ///< The contact contains only a '*' character 
	s8 m_achProductId[MAX_PRODUCTID_LEN];                   ///< product id 
	s8 m_achVersionId[MAX_PRODUCTID_LEN];                   ///< version id 
	u8 m_byNonStdHeadNum;                                   ///< nonstd header number
	TSipHead m_atNonStdHead[MAX_SIP_NONSTD_HEADER_NUM];     ///< nonstd header array
	u8 m_byOtherParamNum;                                   ///< other parament number
	TSipParam m_atUriOtherParam[MAX_SIP_PARAM_NUM];///< other uri parament
	/**
    * \brief            tagRegReqInfo  Constructor
    * \return           void.
    */
	tagRegReqInfo()
	{ 
		memset(this, 0, sizeof(tagRegReqInfo));
		m_nExpires = -1;
	}
} TRegReqInfo;

/**
* \brief            GenerateChannelXml
* \param[in]        pbyInBuf          :h_chan_flowControl-stream_id(s32)+Bitrate(u16),sizeof(s32)+ sizeof(u16)\n 
                                       h_chan_fastupdate-stream_id(s32),sizeof(s32)\n
                                       Null-0
* \param[in]        wInLen            :buffer length
* \param[in]        emCtrlMsg         :h_chan_flowControl,h_chan_fastupdate
* \param[in]        pchOutBuf         :generate xml
* \param[in]        wOutLen           :the size of xml
*/
PROTO_API void GenerateChannelXml(u8* pbyInBuf, u16 wInLen, EmSipConfCtrlMsgType  emCtrlMsg , s8* pchOutBuf, u16 &wOutLen);

/**
* \brief            Parse NonStd Xml
* \param[in]        pbyInBuf          :h_chan_flowControl-stream_id(s32)+Bitrate(u16),sizeof(s32)+ sizeof(u16)\n 
                                       h_chan_fastupdate-stream_id(s32),sizeof(s32)\n
                                       Null-0
* \param[in]        wInLen            :buffer length
* \param[in]        emCtrlMsg         :h_chan_flowControl,h_chan_fastupdate
* \param[in]        pchOutBuf         :generate xml
* \param[in]        wOutLen           :the size of xml
*/
PROTO_API void ParseNonStdXml(s8* pchInBuf, u16 wInLen, EmSipConfCtrlMsgType  &emCtrlMsg , s8* pchOutBuf, u16 &wOutLen);

/**
* @}
*/
#endif
