/**
*   COPYRIGHT NOTICE
*   Copyright (C) 2018, KeDaCom
*   All right reserved
*   
*   @file        h323callstdstruct.h
*   @author      Sai
*   @version     V5.0_64bit
*   @date        2018-03-05
*   @brief       Provided messages struct for H323 protocol 
*   @details     
*/
#ifndef _H323CALLSTDSTRUCT_H
#define _H323CALLSTDSTRUCT_H

#include "protocolcommonpublic.h"
#include "kdv323common.h"
#include "kdvcapset.h"

/**��ǰƽ̨��֧�ֵ��б��ѯ����*/
enum emPlatformCap
{
	KdvPlatformCapStart						= 0,
	KdvPlatformCapTerLIst					= 1,	/**< �����ն��б� */
	KdvPlatformCapConfList					= 2,	/**< �����б� */
	KdvPlatformCapCreateConfwithTerlist	    = 3,	/**< �ټ��������� */
	KdvPlatformCapJoinCofByConfList			= 4,	/**< �μӻ������� */
	KdvPlatformCapGlobalAddrBook			= 5,	/**< ȫ�ֵ�ַ�� */
	KdvPlatformCapVideoRecordBroadcast	  	= 6,	/**< ¼������ */
	KdvPlatformCapEnd						= 7,
};

/**for PlatformCap Capability*/
typedef struct tagPlatformCap
{
	u32 m_dwCap;
	
	void Clear(){  m_dwCap = 0; } 

	BOOL32 SetAllCap( u32 dwCap );
	
	u32 GetAllCap()
	{
		return ntohl( m_dwCap );
	}

	BOOL32 AddCap( emPlatformCap emCap );

	BOOL32 RemoveCap( emPlatformCap emCap );

	BOOL32 IsSupport(emPlatformCap emCap );

}TPlatformCap;


/**for callmake error return */
enum CallMAkeErrReason 
{
    err_unknow				= -1,	/**< δ֪ԭ�� */
	err_full_call			= -2,	/**< �������� */
	err_set_param			= -3,	/**< ��������ò�������(������ַ) */
	err_null_ptr			= -4,	/**< ָ��ΪNULL��ָ���buffer��С��ƥ�� */	
	err_set_address			= -5,	/**<����ʱЭ��ջ�ڲ��жϵ�ַ�������� */	
	err_already_setup		= -6,	/**< �Ѿ����й� */	
	err_autoRas_PrepareARQ	= -7,	/**< ����ARQʧ�� */
	err_autoRas_Register	= -8,   /**< ע��ʧ�� */
	err_Q931_Connect		= -9,	/**< Q931����ʧ�� */
	err_iptype_notmatch		= -10,	/**< ����Դ��ַ��Ŀ�ĵ�ַ���Ͳ�һ��(����IP��) */
};


#ifndef CM_H
typedef enum
{
	cmCreate,
	cmJoin,
	cmInvite,
	cmCapabilityNegotiation,
	cmCallIndependentSupplementaryService,
	cmLastCG
}cmConferenceGoalType;

typedef enum
{
    cmCallTypeP2P,
	cmCallTypeOne2N,
	cmCallTypeN2One,
	cmCallTypeN2Nw
}cmCallType;

/**Equipment type*/
typedef enum
{
    cmEndpointTypeTerminal,
	cmEndpointTypeGateway,
	cmEndpointTypeMCU,
	cmEndpointTypeGK,
	cmEndpointTypeUndefined,
	cmEndpointTypeSET
}cmEndpointType;

/**RAS Disengage Reason*/
typedef enum
{
    cmRASDisengageReasonForcedDrop,
	cmRASDisengageReasonNormalDrop,
	cmRASDisengageReasonUndefinedReason
}cmRASDisengageReason;

/**RAS Unreg Reason*/
typedef enum
{
    cmRASUnregReasonReregistrationRequired,
	cmRASUnregReasonTtlExpired,
	cmRASUnregReasonSecurityDenial,
	cmRASUnregReasonUndefinedReason,
	cmRASUnregReasonMaintenance
}cmRASUnregReason;

/**RAS Reason*/
typedef enum
{
    cmRASReasonResourceUnavailable              = 0,		/**< GRJ, RRJ, ARJ, LRJ - gatekeeper resources exhausted */
    cmRASReasonInsufficientResources            = 1,		/**< BRJ */
    cmRASReasonInvalidRevision                  = 2,		/**< GRJ, RRJ, BRJ */
    cmRASReasonInvalidCallSignalAddress         = 3,		/**< RRJ */
    cmRASReasonInvalidRASAddress		        = 4,		/**< RRJ - supplied address is invalid */
    cmRASReasonInvalidTerminalType              = 5,		/**< RRJ */
    cmRASReasonInvalidPermission                = 6,		/**< ARJ - permission has expired */
															/**< BRJ - true permission violation */										 			/* LRJ - exclusion by administrator or feature */
    cmRASReasonInvalidConferenceID              = 7,		/**< BRJ - possible revision */
    cmRASReasonInvalidEndpointID                = 8,		/**< ARJ */
    cmRASReasonCallerNotRegistered              = 9,		/**< ARJ */
    cmRASReasonCalledPartyNotRegistered         = 10,	/**< ARJ - can't translate address */
    cmRASReasonDiscoveryRequired                = 11,	/**< RRJ - registration permission has aged */
    cmRASReasonDuplicateAlias                   = 12,	/**< RRJ - alias registered to another endpoint */
    cmRASReasonTransportNotSupported            = 13,	/**< RRJ - one or more of the transports */
    cmRASReasonCallInProgress                   = 14,	/**< URJ */
    cmRASReasonRouteCallToGatekeeper            = 15,	/**< ARJ */
    cmRASReasonRequestToDropOther               = 16,	/**< DRJ - can't request drop for others */
    cmRASReasonNotRegistered                    = 17,	/**< DRJ, LRJ, INAK - not registered with gatekeeper */
    cmRASReasonUndefined                        = 18,	/**< GRJ, RRJ, URJ, ARJ, BRJ, LRJ, INAK */
    cmRASReasonTerminalExcluded                 = 19,	/**< GRJ - permission failure, not a resource failure */
    cmRASReasonNotBound                         = 20,	/**< BRJ - discovery permission has aged */
    cmRASReasonNotCurrentlyRegistered           = 21,	/**< URJ */
    cmRASReasonRequestDenied                    = 22,	/**< ARJ - no bandwidrg available */
														/**< LRJ - cannot find location */
    cmRASReasonLocationNotFound                 = 23,	/**< LRJ - cannot find location */
    cmRASReasonSecurityDenial                   = 24,	/**< GRJ, RRJ, URJ, ARJ, BRJ, LRJ, DRJ, INAK */
    cmRASReasonTransportQOSNotSupported         = 25,	/**< RRJ */
    cmRASResourceUnavailable                    = 26,	/**< Same as cmRASReasonResourceUnavailable */
    cmRASReasonInvalidAlias                     = 27,	/**< RRJ - alias not consistent with gatekeeper rules */
    cmRASReasonPermissionDenied                 = 28,	/**< URJ - requesting user not allowed to unregister specified user */
    cmRASReasonQOSControlNotSupported           = 29,	/**< ARJ */
    cmRASReasonIncompleteAddress                = 30,	/**< ARJ, LRJ */
    cmRASReasonFullRegistrationRequired         = 31,	/**< RRJ - registration permission has expired */
    cmRASReasonRouteCallToSCN                   = 32,	/**< ARJ, LRJ */
    cmRASReasonAliasesInconsistent              = 33,	/**< ARJ, LRJ - multiple aliases in request identify distinct people */
    cmRASReasonAdditiveRegistrationNotSupported = 34,	/**< RRJ */
    cmRASReasonInvalidTerminalAliases           = 35,	/**< RRJ */
    cmRASReasonExceedsCallCapacity              = 36,	/**< ARJ - destination does not have the capacity for this call */
    cmRASReasonCollectDestination               = 37,	/**< ARJ */
    cmRASReasonCollectPIN                       = 38,	/**< ARJ */
    cmRASReasonGenericData                      = 39,	/**< GRJ, RRJ, ARJ, LRJ */
    cmRASReasonNeededFeatureNotSupported        = 40,	/**< GRJ, RRJ, ARJ, LRJ */
    cmRASReasonUnknownMessageResponse           = 41,	/**< XRS message was received for the request */
    cmRASReasonHopCountExceeded                 = 42,	/**< LRJ */
}cmRASReason;

/**User Input Signal Rtp Struct*/
typedef struct
{
    int timestamp;      /**< -1 if optional; */
    int expirationTime; /**< -1 if optional;*/
    int logicalChannelNumber;
}cmUserInputSignalRtpStruct;

/**User Input Signal Struct*/
typedef struct
{
    char signalType;
    int duration;
    cmUserInputSignalRtpStruct cmUserInputSignalRtp;/**< if logicalchannel == 0 -optional*/
}cmUserInputSignalStruct;
#endif///CM_Hû�а���cm.h

#ifndef CMCTRL_H
/**Capability Direction*/
typedef enum 
{
    cmCapReceive=1,
    cmCapTransmit=2,
    cmCapReceiveAndTransmit=3
} cmCapDirection;
#endif///CMCTRL_H û�а���cm.h

/**H235 Type*/
typedef enum 
{
	emH235_None   =0x00,
	emH235_DES    =0x01,
	emH235_AES128 =0x02,
	emH235_AES256 =0x04
}emH235Type;

/**Disconnect Reason*/
enum CallDisconnectReason 
{
	reason_busy					 = 1,
	reason_normal				 = 2,
	reason_rejected				 = 3,
	reason_unreachable			 = 4,
	reason_local				 = 5,
	reason_unknown				 = 6,
								 
	reason_nobandwidth			 = 7,		/**< ARQ�ܾ���û�д��� */
	reason_nopermission			 = 8,		/**< �������ؾܾ� */
	reason_unreachablegatekeeper = 9,		/**< ���ز��ɴ�for ARQ */
	reason_mcuoccupy			 = 10,      /**< �ն�æ,���ն�Ŀǰ���ڻ���ļ��𼰻������� */
	reason_reconnect			 = 11,      /**< ������������ͣ���Զ���Զ��������� */
	reason_confholding			 = 12,      /**< ��MCU�����ٿ��������� */
	reason_hascascaded			 = 13,      /**< ��MCU�Ѿ��������߼���MCU���� */
								 
	reason_custom				 = 14,		/**< �����ֶ�u8+u8 = reason_custom + EmCallFailureReason �ķǱ���ʽ */
	reason_adaptivebusy			 = 15,      /**< ΪAGW��عҶ�ԭ�����Ӵ������ */
};

/**323�Ǳ�Ҷ�ԭ��*/
enum EmCallFailureReason
{
	emCallFailureReasonBegin               = 0,

	emCallFailureReasonTimeOut             = 1,      /**< ���г�ʱ */
	emCallFailureReasonNoIdleVPU           = 2,      /**< û���㹻�����Ŀ���ý�崦���� */
	emCallFailureMinMediaConfMtNum         = 3,		 /**< ����2.6�ն˻����к��е����Ѵ����� */
	emCallFailureReasonEncrypeErr          = 5,      /**< ��������ģʽ���� */
	
	emCallFailureReasonMccDrop             = 6,      /**< ��عҶ� */
	emCallFailureReasonChairDrop           = 7,      /**< ��ϯ�Ҷ� */
	emCallFailureReasonMMcuDrop            = 8,      /**< �ϼ�����Ҷ� */
	emCallFailureReasonConfRelease         = 9,      /**< ��������Ҷ� */
	
	emDisconnectCustom_PeerInConf          = 10,     /**< �Զ����ڻ��� */
	emDisconnectCustom_PeerInNoDisturb     = 11,     /**< �Զ������ */
	emDisconnectCustom_NotInPeerContact    = 12,     /**< ����ͨѶ¼�� */
	emDisconnectCustom_PeerNoP2PPermission = 13,     /**< �Զ��޵�Ե�Ȩ�� */
	emDisconnectCustom_PeerOnSleeping      = 14,     /**< �Զ����ڴ��� */
	emDisconnectCustom_MaxMtNum            = 15,     /**< �����к��е����Ѵ����� */

	emCallFailureReasonConfReleaseOnlyOneMt=17,      /**< ��һ�������ն��Զ����-10���� */
	emDisconnectCustom_Exception           =18,      /**< �쳣�Ҷ� */
	emDisconnectCustom_Eviction			   = 19,     /**< ǿ��ʽ�����˻� */
	emDisconnectCustom_ChannelNoAuth	   = 20,	 /**< ������Ʒδ����Ȩ */
	emDisconnectCustom_OverMaxLicenseNum   = 21,     /**< �˿ڻ����ն���������License��Ȩ���� */
	emDisconnectCustom_DssDisconnect	   = 22,     ///< ý��ת���쳣
	emCallFailureReasonEnd,
};


/**Facility Reason*/
enum FacilityReason 
{
	routeToGK,				
	callForward,				
	routeToMC,
	confListChoice,
	startH245,
	forwardedelements,	/**For us*/
	undefined,			/**For Guoke or HuaWei*/
	unknown
};

enum RrqAuthAlgType
{
	emRrqAuthAlgTypeMD5 = 0,   /**Standard MD5*/
	emRrqAuthAlgTypeGuoKe,	   /**Only for guoke*/
	emRrqAuthAlgTypeSM4		   /**National secret*/
};
/**���Ӿ������*/
enum MasterSlaveResult 
{
	msdse_master,		/**<����Ϊmaster*/
	msdse_slave,		/**<����Ϊslave */
    msdse_err = 0xff    
};

/**�����������*/
enum CapExchangeResult 
{
	cese_accept,		/**<�Զ˽��ܱ�������*/
	cese_reject,		/**<�Զ˾ܾ���������*/
    cese_err = 0xff
};

/**��������*/
enum  DataType 
{
	type_none = 0,
	type_audio,
	type_video,
	type_data,
};

#ifndef MCUCASC_ADAPTER_COMMON
#define MCUCASC_ADAPTER_COMMON

/**Judge Audio Type*/
#define PayloardIsAudioType( paylord )  \
( (emAudioTypeBegin < paylord && paylord < emAudioTypeEnd && paylord != emMpeg4 && paylord != emH262) )

/**Judge Video Type*/
#define PayloardIsVideoType( paylord )  \
( ( (emVideoTypeBegin < paylord && paylord < emVideoTypeEnd) || paylord == emMpeg4 || paylord == emH262) )

/**Judge Data Type*/
#define PayloardIsDataType( paylord )  \
( (emDataTypeBegin < paylord && paylord < emDataTypeEnd) )

#endif

/**������صĲ���*/
enum CallParamType
{
	cpt_ConferenceGoalType,					/**<�����Ŀ������ cmConferenceGoalType*/
	cpt_CallType,							/**<��������       cmCallType*/
	cpt_callId,								/**<����ID		 char[16]*/
	cpt_callCrv,							/**<����CRV		 int*/
	cpt_confId								/**<����ID		 char[16]*/
};

/**�ն�����ֵ*/
typedef enum
{
	emMsMT			= 50,
	emMsMT_MC		= 70,
	emMsMCU			= 190,
	emMsActiveMC	= 240,
}emMsTerminalType;


//////////////////////////  �����Ϣ�����Ժ�Ľṹ��  //////////////////
/**H239 Messages*/
typedef enum
{
    emH239InfoTypeInvalid		        = 0,

    emH239FlowControlReleaseRequest     = 1,
    emH239FlowControlReleaseResponse    = 2,
    emH239PresentationTokenRequest      = 3,
    emH239PresentationTokenResponse     = 4,
    emH239PresentationTokenRelease      = 5,
    emH239PresentationTokenIndicateOwner= 6,

    emH239InfoTypeEnd
}emH239InfoType;

/**Pic Style*/
typedef enum
{
	emStyle2p  = 0x07,
	emStyle3p  = 0x08,
	emStyle4p  = 0x00,
	emStyle6p  = 0x02,
	emStyle8p  = 0x04,
	emStyle9p  = 0x01,
	emStyle13p = 0x06,
	emStyle13  = 0x05,
	emStyle16p = 0x03,
	emStyleEnd
}emPicStyle;

/**log Channel Reject Cause*/
typedef enum
{
    emLogChanRejectUnspecified							= 0,
    emLogChanRejectUnsuitableReverseParameters			= 1,
    emLogChanRejectDataTypeNotSupported					= 2,
    emLogChanRejectDataTypeNotAvailable					= 3,
    emLogChanRejectUnknownDataType						= 4,
    emLogChanRejectDataTypeALCombinationNotSupported	= 5,
    emLogChanRejectMulticastChannelNotAllowed			= 6,
    emLogChanRejectInsuffientBandwdith					= 7,
    emLogChanRejectSeparateStackEstablishmentFailed		= 8,
    emLogChanRejectInvalidSessionID						= 9,
    emLogChanRejectMasterSlaveConflict					= 10,
    emLogChanRejectWaitForCommunicationMode				= 11,
    emLogChanRejectInvalidDependentChannel				= 12,
    emLogChanRejectReplacementForRejected				=13
}emlogChannelRejectCause;

/**Init Fail Reason*/
typedef enum
{
    emInitFailReasonSuccess           = 0x00,
    emInitFailReasonMemoryProblem     = 0x01,
    emInitFailReasonConfigProblem     = 0x02,
    emInitFailReasonNetWorkProblem    = 0x03,
    emInitFailReasonInitAgain         = 0x04,
    emInitFailReasonGenConfigFail     = 0x05,
    emInitFailReasonInitSemFail       = 0x06,
    emInitFailReasonNewConnInfoFail   = 0x07,
    emInitFailReasonSetCBFail         = 0x08,
    emInitFailReasonUnknown           = 0x09,
}emInitFailReason;

/**User Input Indication*/
typedef enum 
{
	emUserInputNonStandard=0,
	emUserInputAlphanumeric,
	emUserInputSupport,
	emUserInputSignal,
	emUserInputSignalUpdate,
	emUserInputExtendedAlphanumeric,
	emUserInputEncryptedAlphanumeric
}emUserInputIndication;

/**֧��ý�崩Խ*/
typedef enum
{
	emNotSupportNATFWTraversal,			/**<��֧��460��Խ*/
	emSupportNATFWTraversal,			/**<֧��460*/
	emSupportTransmitMulti,			    /**<֧�ֶ˿ڸ���*/
	emSupportMediaTraversal				/**<����Ϊ460������*/
}emNATFWTraversal;

/**���س���*/
enum AdpSwitchConstant
{
	Adp_turn_on,		/**<����*/
	Adp_turn_off		/**<�ر�*/
};

/**��ѯ����*/
enum AdpPollType
{
	Adp_poll_none,		/**<û����ѯ*/
	Adp_poll_vcb,		/**<�����㲥*/
	Adp_poll_vcs		/**<����ѡ��*/
};

/**��ѯ״̬*/
enum AdpPollStatus
{
	Adp_poll_status_none,    /**<δ��ѯ*/
	Adp_poll_status_normal,  /**<��ѯ������*/
	Adp_poll_status_pause    /**<��ѯ��ͣ*/
};

/**�������ͺ궨��*/
enum AdpOprType
{
    Adp_opr_start,		
	Adp_opr_stop
};

/**MCU�����ն˵��Զ���֪ͨ��Ϣ ��Ϣ��Ŷ���*/
enum AdpMcu2MtNtfMsgType
{
    emAdpNoneNtf           = 0,
	emAdpBePolledNextNtf   = 1           /**<��������ѯ�� ֪ͨ*/
};

/**H460 Features*/
typedef struct PROTO_API tagH460Features
{
	BOOL32 m_bPeerSupportH460;
	BOOL32 m_bPeerMediaTraversalServer;
	BOOL32 m_bPeerSupportTransMultiMedia;
	tagH460Features()
	{
		m_bPeerSupportH460 = FALSE;
		m_bPeerMediaTraversalServer = FALSE;
		m_bPeerSupportTransMultiMedia = FALSE;
	}
}TH460Features,*PTH460Features;


/**H323 TimeOut*/
typedef struct PROTO_API tagH323TimeOutParam
{
	u32 m_dwRasResponseTimeout;
	u32 m_dwRasMaxFail;
	u32 m_dwConfResponseTimeout;
	u32 m_dwConfConnectTimeout;
	u32 m_dwMasterSlaveTimeout;
	u32 m_dwCapabilityTimeout;
	u32 m_dwKeepAliveTime;

	tagH323TimeOutParam()
	{
		m_dwRasResponseTimeout = 3;
		m_dwRasMaxFail = 3;
		m_dwConfResponseTimeout = 15;
		m_dwConfConnectTimeout  = 100;
		m_dwMasterSlaveTimeout  = 90;
		m_dwCapabilityTimeout   = 90;
		m_dwKeepAliveTime       = 60;
	}
}TH323TimeOutParam,*PTH323TimeOutParam;

/**H221�Ǳ����*/
typedef struct PROTO_API tagH221NonStandard
{
	u8		m_byT35CountryCode;
	u8		m_byT35Extension;
	u16		m_wManufacturerCode;
	
	void Clear()
	{
		m_byT35CountryCode	 = 0;
		m_byT35Extension	 = 0;
		m_wManufacturerCode  = 0;
	}
	
	void SetH221NonStandard( u8 byCountryCode, u8 byExtension, u16 wManufacturerCode)
	{
		m_byT35CountryCode	= byCountryCode;
		m_byT35Extension	= byExtension;
		m_wManufacturerCode = wManufacturerCode;
	}
	u8 GetT35CountryCode()
	{
		return m_byT35CountryCode;
	}
	u8 GetT35Extension()
	{
		return m_byT35Extension;
	}
	u16 GetManufacturerCode()
	{
		return m_wManufacturerCode;
	}
}TH221NONSTANDARD,*PTH221NONSTANDARD;

/**���̱�ʶ��Ϣ*/
/**5.0�й淶��vendor��������ֶε�ʹ�ã���֮ǰ�����ṹ���й���vendor�ֶ���ȡ�Լ��ϲ����˽ṹ���*/
typedef struct PROTO_API tagVendorInfo
{
	TH221NONSTANDARD	m_tVendor;
	s32					m_nVenderid;					/**<����id*/

	s32					m_nProductIdSize;
	s8					m_achProductId[MAX_PRODUCTID_LEN+1];	/**<��Ʒ��*/

	s32					m_nVersionIdSize;
	s8					m_achVersionId[MAX_PRODUCTID_LEN+1];	/**<�汾��*/					

	tagVendorInfo()
	{
		Clear();
	}

	void Clear();

	void SetH221NonStandard( TH221NONSTANDARD &tVendor)
	{
		m_tVendor = tVendor;
	}
	TH221NONSTANDARD& GetH221NonStandard()
	{
		return m_tVendor;
	}

	/**���ó���ID*/
	void SetVenderId( s32 nVenderId)
	{
		m_nVenderid = nVenderId;
	}
	void SetVendorID( s8 *pProductId, s8 *pVersionId )
	{
		strncpy( m_achProductId, pProductId, Minimum(strlen(pProductId), sizeof(m_achProductId) - 1));
		strncpy( m_achVersionId, pVersionId, Minimum(strlen(pVersionId), sizeof(m_achVersionId) - 1));		
	}
	/**��ȡ����ID*/
	s32 GetVenderId()
	{
		return m_nVenderid;
	}


	/**��ȡ��Ʒ�ų���*/
	s32 GetProductIdSize()
	{
		return m_nProductIdSize;
	}
	void SetProductIdSize( s32 nProductSize )
	{
		m_nProductIdSize = nProductSize;
	}
	/**���ò�Ʒ��*/
	void SetProductId(s8 *pchId, s32 nLen);

	/**��ȡ��Ʒ��*/
	s32 GetProductId(s8 *pchId, s32 nLen);

	s8* GetProductID()
	{
		return m_achProductId;
	}

	/**��ȡ�汾�ų���*/
	s32 GetVersionIdSize()
	{
		return m_nVersionIdSize;
	}
	void SetVersionIdSize( s32 nVersionIdSize )
	{
		m_nVersionIdSize = nVersionIdSize;
	}
	/**���ð汾��*/	
	void SetVersionId(s8 *pchId, s32 nLen);

	/**��ȡ�汾��*/
	s32 GetVersionId(s8 *pchId, s32 nLen);

	s8* GetVersionID()
	{
		return m_achVersionId;
	}

}TVENDORINFO,*PTVENDORINFO;

/**��ҵ�����õĳ�ʼ�������������Ϣ�Ա���˿ڳ�ͻ*/
typedef struct PROTO_API tagMmcuInfo
{
    /**��ʼ��������ʱ���õ�watchdog�˿ڷ�Χ*/
    u16 m_wWatchPortFrom;
    u16 m_wWatchPortTo;

    /**�Ƿ��ʼ��������ָʾ*/
    BOOL32 m_bEnableMMCU;

    tagMmcuInfo()
    {
        Clear();
    }

    void Clear()
    {
        m_wWatchPortFrom = 0;
        m_wWatchPortTo = 0;
        m_bEnableMMCU = FALSE;
    }

    BOOL32 GetEnableMMCU()
    {
        return m_bEnableMMCU;
    }

    void SetEnableMMCU(BOOL32 bEnabled)
    {
        m_bEnableMMCU = bEnabled;
    }

    BOOL32 GetMMCUStartPort()
    {
        return m_wWatchPortFrom;
    }

    void SetMMCUStartPort(u16 wWatchPortFrom)
    {
        m_wWatchPortFrom = wWatchPortFrom;
    }

    BOOL32 GetMMCUEndPort()
    {
        return m_wWatchPortFrom;
    }

    void SetMMCUEndPort(u16 wWatchPortTo)
    {
        m_wWatchPortTo = wWatchPortTo;
    }

}TMMCUINFO,*PTMMCUINFO;

/**�ؼ����ò�������*/
typedef struct PROTO_API tagConfigs
{
	u32				m_dwSystem_maxCalls;				    /**<��������*/
	u32				m_dwSystem_maxChannels;					/**<ÿ�����д򿪵��߼�ͨ����*/

	u32             m_dwSystem_maxBufferSize;               /**<Э��ջ��Ϣ����buf*/
	
	emEndpointType  m_emTerminalType;						/**<�ն�������(emMt emMcu)*/
	BOOL32			m_bRas_manualRAS;						/**<�Ƿ��ֶ�RAS����*/
	BOOL32			m_bRas_manualRegistration;				/**<�Ƿ��ֶ�RASע��*/
	PFC_IPADDR      m_tRas_DefaultGkIp[MAX_MULTI_ADDR_NUM];	/**<ȱʡgk��ַ*/
	u16				m_wRas_defaultlocalPort;				/**<ȱʡ����RAS�˿�*/
	s8				m_achUsername[REG_NAME_LEN];			/**<ע���ʺ�(E164)*/
	s8				m_achPassword[REG_PWD_LEN];				/**<ע����Կ*/
	
	TVENDORINFO		m_tVendorInfo;							/**<��Ʒ�š��汾��*/

	TALIASADDR		m_atAlias[type_others];					/**<��������*/
		
	u16				m_wQ931_CallingPort;					/**<h225���ж˿�*/
	emMsTerminalType  m_emMsTerminalType;					/**<���Ӿ����ն�����*/   
	BOOL32			m_bH245_masterSlaveManualOperation;		/**<�Ƿ��ֹ���������ȷ��*/
	BOOL32			m_bH245_capabilitiesManualOperation;	/**<�Ƿ�����ֹ���������*/

    s32             m_nPortFrom;                            /**<�˿���ʼ*/
    s32             m_nPortTo;                              /**<�˿ڽ�ֹ*/

	PFC_IPADDR		m_tStackIp[MAX_MULTI_ADDR_NUM];			/**<Э��ջ����IP��Ipv4 and Ipv6 ������*/

	BOOL32		m_bOptimizeMem;								/**<stackģ���ʼ���ڴ��Ż���ز���*/

	u32			m_dwRasResponseTimeout;						/**<ras��Ϣ��timeoutʱ����Ĭ��ֵ3s*/

    TMMCUINFO   m_tMmcuInfo;                                /**<��ҵ�����õĳ�ʼ�������������Ϣ�Ա���˿ڳ�ͻ*/

	u16 m_wTosLevel;
	ALL_LOG_CALlBACK m_fpAllLogCallback;					/**<��ӡ��־�ص�*/
	TProtoLogCfg m_tH323Log;                                /**<��ҵ������PfcOpenLogFile����*/

	s8         byMultiAddrNum;                              /**<Multi IpAddr Num*/
	u32        m_dwRasMaxRetries;                           /**<ras��Ϣ������ش�������Ĭ��ֵ3��*/
	BOOL32     m_bManualCallProceeding;                     /**<manual Call Proceeding,Set only for network access test(WILKIE)*/
	tagConfigs()
	{
		Clear();
	}

	void Clear();
		
    u32 GetMaxBufferSize()
    {
        return m_dwSystem_maxBufferSize;
    }
	
	void SetMaxBufferSize(u32 maxBufferSize)
	{
		m_dwSystem_maxBufferSize = maxBufferSize;
		return;
	}

	/**������������������߼�ͨ����*/
	void SetMaxNum( u32 dwMaxCalls, u32 dwMaxChannels )
	{
        m_dwSystem_maxCalls = (dwMaxCalls>MIN_CALL_NUM && dwMaxCalls<MAX_CALL_NUM)?dwMaxCalls:MAX_CALL_NUM;
        m_dwSystem_maxChannels = (dwMaxChannels>MIN_CHANNEL_NUM && dwMaxChannels<MAX_CHANNEL_NUM)?dwMaxChannels:MIN_CHANNEL_NUM;
	}
	/**��ȡ��������*/
	u32 GetMaxCalls()
	{
		return m_dwSystem_maxCalls;
	}
	/**��ȡ���ͨ����*/
	u32 GetMaxChannels()
	{
		return m_dwSystem_maxChannels;
	}
	/**�����Ƿ�ʹ���ֶ�RAS*/
	void SetMannualRAS( BOOL32 bManualRAS, BOOL32 bManualReg )
	{
		m_bRas_manualRAS = bManualRAS;
		m_bRas_manualRegistration = bManualReg;
	}
	/**��ȡ�Ƿ��ֶ�RAS*/
	BOOL32 IsManualRAS()
	{
		return m_bRas_manualRAS;
	}
	/**��ȡ�Ƿ��ֶ�ע��*/
	BOOL32 IsManualReg()
	{
		return m_bRas_manualRegistration;
	}
	/**�����ն����͡����Ӿ����ն�����*/
	void SetTerminalType( emEndpointType emEpType, emMsTerminalType emMSTType )
	{
		m_emTerminalType = emEpType;
		m_emMsTerminalType = emMSTType;
	}
	/**��ȡ�ն�����*/
	emEndpointType GetEndpointType()
	{
		return m_emTerminalType;
	}
	/**��ȡ���Ӿ������ն�����*/
	emMsTerminalType GetMsTerminalType()
	{
		return m_emMsTerminalType;
	}
	
	/**�����û�����*/
	void SetUserInfo(s8* pszUserName, s8* pszPassword);

	/**ȡ�û���*/
	s8* GetUserName()
	{
		return m_achUsername;
	}
	/**ȡ����*/
	s8* GetPassword()
	{
		return m_achPassword;
	}

	/**���ñ���*/
	void SetAliasAddr( TALIASADDR &tAliasAddr, u32 dwAliasNo );

	/**��ȡ��������*/
	PTALIASADDR GetAliasAddr( u32 dwAliasNo );

	/**����h225���ж˿�*/
	void SetH225CallingPort( u16 wCallPort = CALLPORT )
	{
		m_wQ931_CallingPort = wCallPort;
	}

	/**��ȡh225���ж˿�*/
	u16 GetH225CallingPort()
	{
		return m_wQ931_CallingPort;
	}

    /**���ñ���RAS�˿�*/
    void SetLocalRASPort( u16 wRASPort = RASPORT )
    {
        m_wRas_defaultlocalPort = wRASPort;
    }
    /**��ȡ����RAS�˿�*/
    u16 GetLocalRASPort()
    {
        return m_wRas_defaultlocalPort;
    }
	/**�����Ƿ��ֶ�MSD��CSE*/
	void SetH245IsManual( BOOL32 bMsdManual, BOOL32 bCseManual )
	{
		m_bH245_masterSlaveManualOperation  = bMsdManual;
		m_bH245_capabilitiesManualOperation = bCseManual;
	}
	/**��ȡMSD�Ƿ��ֶ�����*/
	BOOL32 IsMasterSlaveManual()
	{
		return m_bH245_masterSlaveManualOperation;
	}
	/**��ȡCSE�Ƿ��ֶ�����*/
	BOOL32 IsCapabilitiesManual()
	{
		return m_bH245_capabilitiesManualOperation;
	}
    /**���ö˿ڷ�Χ*/
    void SetPortRange(s32 portFrom, s32 portTo)
    {
        m_nPortFrom = portFrom;
        m_nPortTo   = portTo;
    }
    /**�õ���ʼ�˿ں�*/
    s32 GetFirstPort()
    {
        return m_nPortFrom;
    }
    /**�õ����һ���˿ں�*/
    s32 GetLastPort()
    {
        return m_nPortTo;
    }

	/**����Э��ջ����IP*/
	void SetStackIP( PFC_IPADDR &tIPAddr, u8 addrNo )
	{
		if ( addrNo < MAX_MULTI_ADDR_NUM)
		{
			m_tStackIp[addrNo] = tIPAddr;
		}
	}

	/** ��ȡStack IP��ַ*/
	PFC_IPADDR GetStackIP( u8 addrNo )
	{
		if ( addrNo < MAX_MULTI_ADDR_NUM )
		{
			return m_tStackIp[addrNo];
		}
		return m_tStackIp[0];
	}

	/**����Э��ջ���� GK IP*/
	void SetGkIP( PFC_IPADDR &tIPAddr, u8 addrNo )
	{
		if ( addrNo < MAX_MULTI_ADDR_NUM)
		{
			m_tRas_DefaultGkIp[addrNo] = tIPAddr;
		}
	}

	/** ��ȡGK IP��ַ*/
	PFC_IPADDR GetGkIP( u8 addrNo )
	{
		if ( addrNo < MAX_MULTI_ADDR_NUM )
		{
			return m_tRas_DefaultGkIp[addrNo];
		}
		return m_tRas_DefaultGkIp[0];
	}

	void SetOptimizeMem(BOOL32 bOptimizeMem) 
	{
		m_bOptimizeMem = bOptimizeMem;
	}

	BOOL32 IsOptimizeMem()
	{
		return m_bOptimizeMem;	
	}

	void SetRasTimeout(u32 dwRasResponseTimeout)
	{
		m_dwRasResponseTimeout = dwRasResponseTimeout;
	}
	u32	GetRasTimeout()
	{
		return m_dwRasResponseTimeout;
	}

	void SetRasMaxRetries(u32 dwMaxRetries)
	{
		m_dwRasMaxRetries = dwMaxRetries;
	}
	u32	GetRasMaxRetries()
	{
		return m_dwRasMaxRetries;
	}

	void SetManualCallProceeding(BOOL32 bManual) 
	{
		m_bManualCallProceeding = bManual;
	}

	BOOL32 IsManualCallProceeding()
	{
		return m_bManualCallProceeding;	
	}
	

}TH323CONFIG,*PH323TH323CONFIG; 

/**h323stack additional config*/
typedef struct PROTO_API tagAdditionalConfig
{
	RrqAuthAlgType      m_emAuthAlgType;	        /**set RRQ Auth Type */
	FacilityReason      m_emH225FacilityReason;	    /**set facility reason for H460*/
	TStaticNATAddr		m_tNATAddress;				/**Static NAT AddrParis*/
	tagAdditionalConfig()
	{
		m_emAuthAlgType = emRrqAuthAlgTypeMD5;
		m_emH225FacilityReason = undefined;
		m_tNATAddress.Clear();
	}
	/**����NAT��ַ*/
	void SetNATAddress(TStaticNATAddr tNATAddress)
	{
		memcpy(&m_tNATAddress,&tNATAddress,sizeof(TStaticNATAddr));
	}
	/**�õ�NAT��ַ*/
	TStaticNATAddr& GetNATAddress()
	{
		return m_tNATAddress;
	}
	/**����RRQ��֤����*/
	void SetRrqAuthAlgType(RrqAuthAlgType emAuthAlgType)
	{
		m_emAuthAlgType = emAuthAlgType;
	}
	/**�õ�RRQ��֤����*/
	RrqAuthAlgType GetRrqAuthAlgType()
	{
		return m_emAuthAlgType;
	}

	/**����facility����*/
	void SetH225FacilityReason(FacilityReason emH225FacilityReason)
	{
		m_emH225FacilityReason = emH225FacilityReason;
	}
	/**�õ�facility����*/
	FacilityReason GetH225FacilityReason()
	{
		return m_emH225FacilityReason;
	}
}TAdditionalConfig;

/**���е�ַ*/
typedef struct PROTO_API tagCallAddr
{
private:
	CallAddrType    m_eType;
	PFC_IPADDR		m_tIPAddr;					
	TALIASADDR		m_tAliasAddr;
public:
	tagCallAddr()
	{
		Clear();
	}

	void Clear()
	{
		m_tIPAddr.Clear();
		m_tAliasAddr.Clear();
	}
	
	/**����CallAddrType*/
	void SetCallAddrType(CallAddrType emAddrType)
	{
		m_eType = emAddrType;
	}
	/**���CallAddrType*/
	CallAddrType GetCallAddrType()
	{
		return m_eType;
	}

	/**����IP��ַ�Ͷ˿ں�*/
	void SetIPAddr(u32 dwIp,u16 wPort = 0)
	{
		wPort = htons(wPort);
		m_tIPAddr.SetIpAddr(dwIp,wPort);
	}	
	/**���IP��ַ*/
	u32 GetIPAddr()  
	{	
		return m_tIPAddr.m_tAddr.m_tIPv4.m_dwIP;
	}

	/**��ö˿ں�*/
	u16 GetIPPort()  
	{	
		return ntohs( m_tIPAddr.m_wPort);	
	}
	/**����IPV6��ַ�Ͷ˿ں�*/
	void SetIPv6Addr(u8 abyIpv6[],u16 wPort = 0)
	{
		wPort = htons(wPort);
		m_tIPAddr.SetIpv6Addr(abyIpv6,wPort);
	}

	/**���IPV6��ַ*/
	void GetIPv6Addr(u8* abyIpv6,u16* pwPort)  
	{	
		m_tIPAddr.GetIpv6Addr(abyIpv6,pwPort);
	}
	/**����Alias��ַ*/
	void SetAliasAddr( AliasType emAliasType, const s8* sAlias );
	
	/**���TALIASADDR��type*/
	AliasType GetAliasType()
	{
		return m_tAliasAddr.m_emType;
	}
	/**���TALIASADDR�ı���*/
	s8* GetAliasName()  
	{
		return m_tAliasAddr.m_achAlias;	
	}	
}TCALLADDR,*PTCALLADDR;

/**connect��Ϣ����ʱ���ظ��ϲ�Ľṹ*/
typedef struct PROTO_API tagNodeInfo 
{
	u32                 m_dwEndpointType;                   /**< ��ֵ�ɴ��������ͣ�������emEndpointType�����Ա�Ļ����*/ 
	u8					m_bySubMtType;						/**<  ����/�绰/��ͨ*/ 
	s8					m_achName[LEN_DISPLAY_MAX+1];		/**<  �������*/ 
	BOOL32				m_bIsEncrypt;						/**<  �Ƿ�֧�ּ���*/ 
	TVENDORINFO			m_tVendorInfo;						/**<  ��Ʒ�š��汾��*/ 
	u32					m_dwCallRate;						/**<  ��������	(kbps)*/ 
	emNATFWTraversal	m_emMediaTraversal;					/**<  Media traversal*/ 
	TH460Features		m_tH460Features;					/**<  H.460 features*/ 
	TAliasAddr			m_atCallingAliasAddr[type_others+1];/**<  ���б�����ַ(������ַ+IP)*/ 
	TAliasAddr			m_atCalledAliasAddr[type_others+1]; /**<  ���б�����ַ(������ַ+IP)*/ 
	u8					m_abyCallID[LEN_GUID];				/**<  CallIdentifier, a global identifier for TrueLink to support EPs called by IP mode*/ 
	u32					m_dwStaticNATAddr;					/**< Static NAT*/ 
    emH235Type          m_emH235Type;                       /**< Encrypt Type*/ 
	tagNodeInfo()
	{
		Clear();
	}

	void Clear();

	/** Set CallID to TNodeInfo*/
	void SetCallID(IN const u8* pbyCallID, IN u8 byLen)
	{
		if (pbyCallID == NULL || byLen <= 0 )
		{
			return;
		}
		s32 nReal = Minimum(Maximum((s32)LEN_1, (s32)byLen), (s32)LEN_GUID);
		memcpy(m_abyCallID, pbyCallID, nReal);
	}

	/** Get CallID from TNodeINfo*/
	s32 GetCallID(OUT u8* pbyCallId, IN s32 nMaxOutLen)
	{
		if(pbyCallId == NULL|| nMaxOutLen <= 0 )
		{
			return 0;
		}
		
		s32 nReal = Minimum(Maximum((s32)LEN_1, nMaxOutLen), (s32)LEN_GUID);
		memcpy(pbyCallId, m_abyCallID, nReal);

		return nReal;
	}

	/** set Static NAT Addr*/
	void SetStaticNATAddr(u32 dwNATIP)
	{
		m_dwStaticNATAddr = dwNATIP;
	}
	
	u32 GetStaticNATAddr()
	{
		return m_dwStaticNATAddr;
	}

	/** �����ն�����*/
	void SetEndpointType(u32 dwEpType)
	{
		m_dwEndpointType = dwEpType;
	}
	/** ��ȡ�ն�����*/
	u32 GetEndpointType()
	{
		return m_dwEndpointType;
	}
	
	void SetSubMtType( u8 byMtType )
	{
		m_bySubMtType = byMtType;
	}
	u8  GetSubMtType( )
	{
		return m_bySubMtType;	
	}
		
	/** ����display name*/
	void SetName(s8 *pchName, s32 nLen);

	/** ��ȡdisplay name*/
	s8* GetName()
	{
		return m_achName;
	}
	/** �����Ƿ����*/
	void SetIsEncrypt( BOOL32 bIsEncrypt )
	{
		m_bIsEncrypt = bIsEncrypt;
	}
	/** ��ȡ�Ƿ����*/
	BOOL32 IsEncrypt()
	{
		return m_bIsEncrypt;
	}

	/**����H235��������*/
	void SetH235Type(emH235Type emType)
	{
		m_emH235Type = emH235Type(m_emH235Type | emType) ;
	}

	/**�õ�H235��������*/
	emH235Type GetH235Type()
	{
		return m_emH235Type;
	}
	
	void SetSupportMediaTraversal(emNATFWTraversal emNet)
	{
		m_emMediaTraversal = emNet;
	}
	emNATFWTraversal GetSupportMediaTraversal()
	{
		return m_emMediaTraversal;
	}
	void SetH460features( const TH460Features &th460features )
	{
		memcpy( &m_tH460Features, &th460features, sizeof(TH460Features) );
	}
	void GetH460features( TH460Features &th460features )
	{
		memcpy( &th460features, &m_tH460Features, sizeof(TH460Features) );
	}


	/** �������б�����ַ	��ΪԴ�˵���Ϣ*/
	void SetCallingAliasaddr( TAliasAddr &tAliasAddr, u8 addrNo )
	{
		if ( addrNo < type_others+1  )
		{
			m_atCallingAliasAddr[addrNo] = tAliasAddr;
		}
	}
	/** ��ȡ���б�����ַ*/
	PTAliasAddr GetCallingAliasaddr( u8 addrNo )
	{
		if ( addrNo < type_others+1  )
		{
			return &(m_atCallingAliasAddr[addrNo]);
		}
		return NULL;
	}
	
	/**���ñ��б�����ַ	��ΪĿ�Ķ˵���Ϣ*/
	void SetCalledAliasAddr( TAliasAddr &tAliasAddr, u8 byAddrNo )
	{
		if ( byAddrNo < type_others+1  )
		{
			m_atCalledAliasAddr[byAddrNo] = tAliasAddr;
		}		
	}
	/**��ȡ���б�����ַ*/
	PTAliasAddr GetCalledAliasAddr( u8 byAddrNo )
	{
		if ( byAddrNo < type_others+1  )
		{
			return &(m_atCalledAliasAddr[byAddrNo]);
		}
		return NULL;
	}
}TNODEINFO,*PTNODEINFO;

/**����H460���в���*/
typedef struct PROTO_API tagH460CallParam 
{
	cmTransportAddress   m_tCallSignalAddr;
	u8                   m_abyCallId[LEN_GUID];      /**<CallIdentifier*/

	tagH460CallParam()
	{
		memset(&m_tCallSignalAddr, 0, sizeof(cmTransportAddress));
		memset(m_abyCallId, 0, LEN_GUID);
	}
}TH460CALLPARAM, *PTH460CALLPARAM;


/**������в���*/
typedef struct PROTO_API tagCallParam 
{
	cmConferenceGoalType  m_emConfGoalType;  				  /**<�����Ŀ������*/
	cmCallType            m_emCallType;						  /**<�������� */
	u32                   m_dwEndpointType;					  /**<�˵����ͣ���ֵ�����Ƕ�����͵ĸ������ͣ���emEndpointType�����Ա��������� */
	u32					  m_dwCallRate;						  /**<��������	(kbps)*/
    TAliasAddr			  m_tCalledAddr;					  /**<���е�ַ�� ����ʱ,������Ϊ������ַ������ʱΪ���������ַ*/
    TAliasAddr			  m_tCallingAddr;					  /**<���е�ַ   ���������ַ*/
	TAliasAddr			  m_atCallingAliasAddr[type_others+1];/**<���б�����ַ(������ַ+IP) ��ȱʡ���������ļ�������*/
	TAliasAddr			  m_atCalledAliasAddr[type_others+1]; /**<���б�����ַ(������ַ+IP)*/
	u8					  m_abyConfId[LEN_GUID];		      /**<�����,����16 octet*/
	u8					  m_abyCallId[LEN_GUID];  
	s8					  m_achDisplay[LEN_DISPLAY_MAX+1];	  /**<������Ϣ*/

    /**UserInfo�ֶ��ݲ�ʹ��*/
    s32					  m_nUUSize; 
	u8					  m_abyUserInfo[LEN_USERINFO_MAX];	  /**<UserInfo��Ϣ���ȣ�2-131�ֽ�*/

	BOOL32				  m_bIsEncrypt;						  /**<�Ƿ����*/

    /**<����ԭ����UserInfo�ֶ�*/
	s32					  m_nNonStandLen;
	u8					  m_abyNonStandData[LEN_NONSTANDARD_MAX];
    
	TVENDORINFO			  m_tVendorInfo;		/**��Ʒ�š��汾��*/

	emNATFWTraversal	  m_bySupportMediaTraversal;
	TH460Features		  m_tH460Features;
    emH235Type            m_emH235Type;
	tagCallParam()
	{
		Clear();	
		CreateConfId();
	}

	void Clear();

    /**�����ն�����*/
    void SetEndpointType(u32 dwType)
    {
        m_dwEndpointType = dwType;
    }
    /**�õ��ն�����*/
    u32 GetEndpointType()
    {
        return m_dwEndpointType;
    }
    
	/**����H235��������*/
	void SetH235Type(emH235Type emType)
	{
		m_emH235Type = emH235Type(m_emH235Type | emType) ;
	}

	/**�õ�H235��������*/
	emH235Type GetH235Type()
	{
		return m_emH235Type;
	}

    /**�����������*/
    void SetCallRate( u32 dwCallRate )
    {
        m_dwCallRate = dwCallRate;
    }
    /**�õ��������*/
    u32 GetCallRate()
    {
        return m_dwCallRate;
    }

	/**���ñ��е�ַ*/
	void SetCalledAddr(TAliasAddr& tCalledAddr)
	{
		m_tCalledAddr = tCalledAddr;
	}

	/**��ȡ���е�ַ*/
	TAliasAddr& GetCalledAddr()
	{
		return m_tCalledAddr;
	}

	/**���ñ��е�ַ*/
	void SetCalledAddr(u32 dwIp,u16 wPort = CALLPORT)
	{
		PFC_IPADDR addr;
		addr.SetIpAddr(dwIp,wPort==0 ? CALLPORT : wPort );
		m_tCalledAddr.SetIPCallAddr( &addr );
	}

//add by yj for ipv6
	/**���ñ��е�ַ(ipv6)*/
//	void SetCalledAddr_Ipv6(u8* dwIp_ipv6, s16 swScopeId,u16 wPort = CALLPORT)
	void SetCalledAddr_Ipv6(u8* pbyIp_ipv6,u16 wPort = CALLPORT)
	{
		PFC_IPADDR addr;
		addr.SetIpv6Addr(pbyIp_ipv6,wPort==0 ? CALLPORT : wPort);
		m_tCalledAddr.SetIPCallAddr( &addr );
	}
	/**��ñ���IP(ipv6)*/
	u8* GetCalledIp_Ipv6()
	{
		return m_tCalledAddr.GetIPAddr_Ipv6(); 
	}

	/**��ñ���IP*/
	u32 GetCalledIp()
	{
		return m_tCalledAddr.GetIPAddr(); 
	}	
	/**��ñ��ж˿�*/
	u16 GetCalledPort() 
	{ 
		return m_tCalledAddr.GetIPPort(); 
	}

	/**���ñ��е�ַ*/
	void SetCalledAddr(AliasType eType,const s8* sAlias)
	{
		TALIASADDR aliasAddr;
		aliasAddr.SetAliasAddr( eType, sAlias );
		m_tCalledAddr.SetIPCallAddr( &aliasAddr );
	}
 
	/**�������е�ַ*/
	void SetCallingAddr( u32 dwIp,u16 wPort = 0 )
	{
		PFC_IPADDR addr;
        //Jacky Wei Replace port 0 with default CALLPORT for Bug00144938(Intercommunication problem with HUAWEI EP)
		/*addr.SetNetAddress( dwIp, (wPort==CALLPORT||wPort==TLCALLPORT)? 0 : wPort);*/
        //addr.SetNetAddress(dwIp, wPort == 0 ? CALLPORT : wPort);
		addr.SetIpAddr( dwIp, wPort == 0 ? CALLPORT : wPort);
		m_tCallingAddr.SetIPCallAddr( &addr );
		
	}
	/**�������IP*/
	u32 GetCallingIp()
	{
		return m_tCallingAddr.GetIPAddr();	
	}	
	/**������ж˿�*/
	u16 GetCallingPort()
	{
		return m_tCallingAddr.GetIPPort();	
	}
    /**�������е�ַ*/
    void SetCallingAddr(AliasType eType,const char* sAlias)
    {
        TALIASADDR aliasAddr;
        aliasAddr.SetAliasAddr( eType, sAlias );
        m_tCallingAddr.SetIPCallAddr( &aliasAddr );
    }

	//add by yj for ipv6
	/**�������е�ַ(ipv6)*/
//	void SetCallingAddr_Ipv6( u8* dwIp_ipv6,s16 swScopeId,u16 wPort = 0 )
	void SetCallingAddr_Ipv6( u8* dwIp_ipv6,u16 wPort = 0 )
	{
		PFC_IPADDR addr;
		addr.SetIpv6Addr(dwIp_ipv6, wPort == 0 ? CALLPORT : wPort);
		m_tCallingAddr.SetIPCallAddr( &addr );
	}
	/**�������IP(ipv6)*/
	u8* GetCallingIp_Ipv6()
	{
		return m_tCallingAddr.GetIPAddr_Ipv6(); 
	}

	/**�������е�ַ*/
	void SetCallingAddr(TAliasAddr& tCallingAddr)
	{
		m_tCallingAddr = tCallingAddr;
	}  

    /**��ȡ���е�ַ*/
    TAliasAddr& GetCallingAddr()
    {
        return m_tCallingAddr;
    }   

	/**�������б�����ַ	��ΪԴ�˵���Ϣ*/
	void SetCallingAliasaddr( TAliasAddr &tAliasAddr, u8 addrNo )
	{
		if ( addrNo < type_others+1  )
		{
			m_atCallingAliasAddr[addrNo] = tAliasAddr;
		}
	}
	/**��ȡ���б�����ַ*/
	PTAliasAddr GetCallingAliasaddr( u8 addrNo )
	{
		if ( addrNo < type_others+1  )
		{
			return &(m_atCallingAliasAddr[addrNo]);
		}
		return NULL;
	}
	
	/**���ñ��б�����ַ	��ΪĿ�Ķ˵���Ϣ*/
	void SetCalledAliasAddr( TAliasAddr &tAliasAddr, u8 byAddrNo )
	{
		if ( byAddrNo < type_others+1  )
		{
			m_atCalledAliasAddr[byAddrNo] = tAliasAddr;
		}		
	}
	/**��ȡ���б�����ַ*/
	PTAliasAddr GetCalledAliasAddr( u8 byAddrNo )
	{
		if ( byAddrNo < type_others+1  )
		{
			return &(m_atCalledAliasAddr[byAddrNo]);
		}
		return NULL;
	}

	/**���û����*/
	void SetConfId(const u8* pchConfId,u8 byLen);

	/**����ų���*/
	s32 GetConfIdSize()
	{
		return LEN_GUID;
	};
	/**��ȡ�����*/
	s32 GetConfId(u8* pbyConfId, s32 nLen);

	/**����һ�������*/
	void CreateConfId()
	{
		memcpy(m_abyConfId, KDV::utils::GetGUID(), LEN_GUID);
	}
	
	/**����һ��Callidentifier*/
	void CreateCallId()
	{
		memcpy(m_abyCallId, KDV::utils::GetGUID(), LEN_GUID);
	}
	/**���ú���ID*/
	void SetCallId(const u8* pbyCallId, u8 byLen);

	/**��ȡ����ID�ĳ���*/
	s32 GetCallIdSize()
	{
		return LEN_GUID;
	};
	/**��ȡ����ID*/
	s32 GetCallId(u8* pbyCallId, s32 nLen);

	/**������ʾ��Ϣ*/
	void SetDisplayInfo(const s8* pchInfo);

	/**�����ʾ��Ϣ*/
	s8* GetDisplayInfo()
	{
		return m_achDisplay;
	}
	
	/**����UserInfo*/
	void SetUserInfo(const u8* pchUserInfo, u8 byLen);
	
	/**���UserInfo����*/
	s32 GetUserInfoSize()
	{
		return m_nUUSize;
	}
	/**��ȡUserInfo*/
	s32 GetUserInfo(u8* pbyUserInfo, u8 byLen);

	/**���ü���*/
	void SetIsEncrypt( BOOL32 bIsEncrypt )
	{
		m_bIsEncrypt = bIsEncrypt;
	}
	/**�Ƿ����*/
	BOOL32 IsEncrypt()
	{
		return m_bIsEncrypt;
	}

	/**��ָ�븳ֵ�����ܱ��棬 С�ģ���������������*/
	BOOL32 SetNonStandData(u8 *pBuf, s32 nLen);

    /**��ȡָ�룬���ܱ���С�ģ���������������*/
	BOOL32 GetNonStandData(u8 **ppBuf, s32 *pnLen);

	void SetSupportMediaTraversal(emNATFWTraversal emNet)
	{
		m_bySupportMediaTraversal = emNet;
	}
	emNATFWTraversal GetSupportMediaTraversal()
	{
		return m_bySupportMediaTraversal;
	}
	void SetH460features( const TH460Features &th460features )
	{
		memcpy( &m_tH460Features, &th460features, sizeof(TH460Features) );
	}
	void GetH460features( TH460Features &th460features )
	{
		memcpy( &th460features, &m_tH460Features, sizeof(TH460Features) );
	}

}TCALLPARAM,*PTCALLPARAM;


/**���ŵ�����*/
typedef struct PROTO_API tagChannelParam 
{
	PFC_IPADDR	     m_tRtp;				/**<rtp��ַ ,incoming chanʹ��*/
	PFC_IPADDR	     m_tRtcp;				/**<rtcp��ַ,incoming and outgoing chanʹ��*/
	u16			     m_wPayloadType;		/**<ý��ͨ������*/	

	TKdvVideoCap	 m_tVideoCap;
	TKdvAudioCap	 m_tAudioCap;
	TKdvDataCap		 m_tDataCap;
	TKdvG7231Cap	 m_tG7231Cap;

	TKdvG7221Cap     m_tG7221Cap;
	TKdvOpusCap      m_tOpusCap;			

	BOOL32		     m_bFlowToZero;		/**<�Ƿ�Ҫ���Ͷ����ŵ�����ʱ����������*/
	TTERLABEL	     m_tSrcTer;
	TTERLABEL	     m_tDstTer;

	u8			     m_byDynamicPT;		/**<��̬�غ�����ֵ(96~127)*/
	emEncryptType    m_emEncryptType;		/**<��������*/
	TEncryptSync     m_tEncryptSync;       /**<master�����ô˽ṹ  */       

    BOOL32           m_bIsH239DStream;     /**<�ڴ���Ƶͨ��ʱָ���Ƿ�H239Э���˫��*/

    BOOL32           m_bSupportRSVP;       /**<�Ƿ�֧��RSVP��˫����֧��RSVP����ΪTRUE*/
    
    u8               m_byFECType;          /**<ǰ��������͡�����Ƶͨ������*/

    TKdvH264VideoCap m_tH264Cap;           /**<H.264������Ƶ��������m_tVideoCap���⣬ֻ����дһ������*/

    TKdvAACCap       m_tAacCap;            /**<AAC LC/LD ��Ƶ����*/
	
	PFC_IPADDR	     m_tKeepAliveAddr;		/**<460 server's rtp sending address for keep-alive channel added by wangxiaoyi 29 July 2010*/
	u16			     m_byKeepAlivePayload;	/**<�򶴰��غ�����(0~127)*/
	u32			     m_dwKeepAliveInterval; /**<�򶴰�����ʱ����*/

	TKdvH265VideoCap m_tH265Cap;
    
public:
	tagChannelParam()
	{
		Reset();
	};

	void Reset();

	void host2net(BOOL32 bhton);

    /**�����Ƿ�֧��RSVP*/
    void SetSupportRSVP(BOOL32 bSupportRSVP) 
    {	
        m_bSupportRSVP = bSupportRSVP; 
    }
    BOOL32 IsSupportRSVP() 
    {
        return m_bSupportRSVP;
    }

    /**����FEC����*/
    void SetFECType(u8 emType)
    {
        m_byFECType = emType;
    }
	/**��ȡFEC����*/
    u8 GetFECType() const
    {
        return m_byFECType;
    }
	
    /**����RTP����*/
	void SetRtp(PFC_IPADDR& rtp) 
	{ 
		m_tRtp = rtp; 
	}
    /**�õ�RTP����*/
	PFC_IPADDR& GetRtp() 
	{
		return m_tRtp; 
	};
	/**����KeepAliveAddr���� for h460 keepalivechannel*/
	void SetKeepAliveAddr(PFC_IPADDR& keepaliveaddr) 
	{ 
		m_tKeepAliveAddr = keepaliveaddr; 
	}
    /**�õ�KeepAliveAddr���� for h460 keepalivechannel*/
	PFC_IPADDR& GetKeepAliveAddr() 
	{
		return m_tKeepAliveAddr; 
	};

    /**����RTCP����*/
	void SetRtcp(PFC_IPADDR& rtcp) 
	{
		m_tRtcp = rtcp; 
	}
    /**�õ�RTCP����*/
	PFC_IPADDR& GetRtcp() 
	{
		return m_tRtcp; 
	}

    /**����FlowToZero*/
	void SetIsFlowToZero(BOOL32 bFlowToZero) 
	{	
		m_bFlowToZero = bFlowToZero; 
	}
	BOOL32 IsFlowToZero() 
	{
		return m_bFlowToZero;
	}
	
    /**���ü�������*/
    void SetEncryptType(emEncryptType emType)
	{
		m_emEncryptType = emType; 
	}
    /**�õ���������*/
	emEncryptType GetEncryptType()
	{
		return m_emEncryptType;
	}

    /**����Դ��TTERLABEL*/
	void SetSrcTerLabel( TTERLABEL& tTer) 
	{ 
		m_tSrcTer = tTer;
	}
    /**�õ�Դ��TTERLABEL*/
    TTERLABEL& GetSrcTerLabel() 
	{ 
		return m_tSrcTer; 
	}

    /**����Ŀ�Ķ�TTERLABEL*/
	void SetDstTerLabel( TTERLABEL& tTer) 
	{ 
		m_tDstTer = tTer;
	}
    /**�õ�Ŀ�Ķ�TTERLABEL*/
    TTERLABEL& GetDstTerLabel() 
	{ 
		return m_tDstTer; 
	}

    /**���ö�̬�غ�����*/
	BOOL32 SetDynamicPayloadParam( u8 byDynamicPT )
	{
		if ( byDynamicPT>=96 && byDynamicPT<=127 ) 
		{
			m_byDynamicPT = byDynamicPT;
			return TRUE;
		}
		return FALSE;
	}
	u8 GetDynamicPayloadParam()
	{
	    return m_byDynamicPT;
	} 
    /**�Ƿ�̬�غ����� */
    BOOL32 IsDynamicPayload()	
    { 
        return (m_byDynamicPT >= 96)&&(m_byDynamicPT <= 127); 
    }

    /**�õ��غ�����*/
    u16 GetPayloadType()
    {
        return m_wPayloadType; 
    }

    /**������Ƶ������������H.264 H.265*/
	BOOL32 SetPayloadParam(u16 wPayloadType, TKdvVideoCap &tVideoCap);

    /**�õ���Ƶ����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvVideoCap *ptVideoCap);

    /**����H.264��Ƶ����*/
    BOOL32 SetPayloadParam(u16 wPayloadType, TKdvH264VideoCap &tVideoCap);

    /**�õ�H.264��Ƶ����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvH264VideoCap *ptVideoCap);
	
	/**����H.265��Ƶ����*/
    BOOL32 SetPayloadParam(u16 wPayloadType, TKdvH265VideoCap &tVideoCap);

	/**�õ�H.265��Ƶ����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvH265VideoCap *ptVideoCap);

    /**������Ƶ������������G7231*/
	BOOL32 SetPayloadParam(u16 wPayloadType, TKdvAudioCap &tAudioCap);

    /**�õ���Ƶ������������G7231/AAC/7221*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvAudioCap *ptAudioCap);

    /**����G7231����*/
    BOOL32 SetPayloadParam(u16 wPayloadType, TKdvG7231Cap &tG7231Cap);

    /**�õ�G7231����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvG7231Cap *ptG7231Cap);
	
    /**����AAC����*/
    BOOL32 SetPayloadParam(u16 wPayloadType, TKdvAACCap &tAacCap);

    /**�õ�AAC����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvAACCap *ptAacCap);

    /**�������ݲ���*/
	BOOL32 SetPayloadParam(u16 wPayloadType, TKdvDataCap &tDataCap);

    /**�õ����ݲ���*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvDataCap *ptDataCap);
	
	/**����Opus����*/
    BOOL32 SetPayloadParam(u16 wPayloadType, TKdvOpusCap &tOpusCap);

    /**�õ�Opus����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvOpusCap *ptOpusCap);	

	/**����G7221����*/
	BOOL32 SetPayloadParam(u16 wPayloadType, TKdvG7221Cap &tG7221Cap);

    /**�õ�G7221����*/
    BOOL32 GetPayloadParam(u16 wPayloadType, TKdvG7221Cap *ptG7221Cap);
		
    /**���ü���ͬ����Ϣ*/
	void SetEncryptSync( TEncryptSync &tSync)
	{ 
		m_tEncryptSync = tSync; 
	}
    /**�õ�����ͬ����Ϣ*/
	TEncryptSync &GetEncryptSync() 
	{ 
		return m_tEncryptSync; 
	} 

	void SetKeepAlivePayload(u16 payload)
	{
		m_byKeepAlivePayload = payload;
	}
	u16 GetKeepAlivePayload()
	{
		return m_byKeepAlivePayload;
	}

	void SetKeepAliveInterval(u32 time)
	{
		m_dwKeepAliveInterval = time;
	}
	u32 GetKeepAliveInterval()
	{
		return m_dwKeepAliveInterval;
	}
	
}TCHANPARAM,*PTCHANPARAM;

typedef struct PROTO_API tagKeepAliveInfo
{
	PFC_IPADDR	m_tKeepAliveNet;
	u16			m_wKeepAlivePayload;
	u32			m_dwKeepAliveInterval;

	tagKeepAliveInfo()
	{
		Clear();
	}
	void Clear()
	{
		m_tKeepAliveNet.Clear();
		m_wKeepAlivePayload = 0;
		m_dwKeepAliveInterval = 0;
	}
}TKeepAliveInfo, *PTKeepAliveInfo;

typedef struct PROTO_API tagTTerminalInfo
{
	TTERLABEL	m_tTerLabel;					/**< �ն�ID*/
	u8			m_byType;						/**< �ն����ͣ���Ƶor�绰��*/
	s8			m_achE164[MAXLEN_E164+1];		/**< �ն�E164��*/
	s8			m_achAlias[LEN_TERID + 1];		/**< �ն˱���*/
	u8			m_byNone;						/**< �ն��Ƿ�ΪΪֻ������Ƶ���� 0-��ֻ������Ƶ��1-ֻ������Ƶ*/
	
	u8 GetMcuNo() 
	{ 
		return m_tTerLabel.GetMcuNo();	
	}
	/**����ն˺�*/
	u8 GetTerNo() 
	{ 
		return m_tTerLabel.GetTerNo();	
	}
	
	/**����ն�����*/
	s8* GetName()
	{
		return m_achAlias;
	}

	s8* GetE164()
	{
		return m_achE164;
	}
	
public:
	tagTTerminalInfo(){memset( this ,0 ,sizeof( struct tagTTerminalInfo) );}

public:
/**
	* \brief            �Խṹ����д�� 
	* \param[out]       pbyBuf	   :�ṹ��PACK����������������
	* \param[in]        dwBufSize  :pbyBuf�Ŀռ䳤��
	* \param[out]       dwBufSize  :����ʵ����Ҫ��BUF���ȣ����ṹ�������
	* \retval           success:TRUE
	* \retval           failed :FALSE
	* \par ʾ����
	* \code
					u32 dwBufSize = 0;
					u8 * pbyBuf = NULL;
					Pack(pbyBuf, dwBufSize);
					if ( dwBufSize > 0 )
					{
						pbyBuf = new u8[dwBufSize];
						Pack( pbyBuf, dwBufSize );
						...
						delete [] pbyBuf;
					}
	* \endcode

*/
    BOOL32 Pack( u8 * pbyBuf, u32 &dwBufSize ); 
/**
	* \brief            �Խṹ����н�� 
	* \param[in]        pbyBuf	   :�ṹ��PACK����������������
	* \param[out]       dwBufSize  :pbyBuf�ĳ���
	* \retval           success:TRUE
	* \retval           failed :FALSE
*/
    BOOL32 UnPack( u8 * pbyBuf, u32 dwBufSize );

}TTerminalInfo ,*PTTTerminalInfo;				

/**temporal spatial tradeoff*/
typedef struct PROTO_API tagTSTO
{
	u8  m_chIsCommand;     /**<�����ָʾ*/
    u8  m_chTradeoffValue; /**<The trade off value, between 0(high spatial resolution) to 31(a high frame rate)*/

    tagTSTO()
	{
		Clear();
	}

	void Clear()
	{
		m_chIsCommand = 0;
		m_chTradeoffValue = 0;
	}

	void SetIsCommand(BOOL32 bCommand)
	{
		m_chIsCommand = bCommand ? 1:0;
	}
	BOOL32 IsCommand()
	{
		return m_chIsCommand>0;
	}
	/**set The trade off value, between 0 to 31.*/
	void SetTradeoffValue(u8 byTradeoffValue)
	{
		if( byTradeoffValue > 31 )
		{
           return ;
		}
        m_chTradeoffValue = byTradeoffValue;
	}

	s8 GetTradeoffValue()
	{
		return m_chTradeoffValue;
	}
}TTSTO;

/**update GOB struct*/
typedef struct PROTO_API tagVFUGOB
{
	s32 m_nFirstGOB;
	s32 m_nNumOfGOB;

	tagVFUGOB()
	{
		Clear();
	}

	void Clear()
	{
		m_nFirstGOB = 0;
		m_nNumOfGOB = 0;
	}

    void host2net(BOOL32 bhton);

    void SetFirstGOB(s32 nFirstGOB)
	{
		m_nFirstGOB = nFirstGOB;
	}
	s32 GetFirstGOB()
	{
		return m_nFirstGOB;
	}
	void SetNumOfGOB(s32 nNumOfGOB)
	{
		//add by yj
		//m_nNumOfGOB = m_nNumOfGOB;
		m_nNumOfGOB = nNumOfGOB;
		//end
	}
	s32 GetNumOfGOB()
	{
		return m_nNumOfGOB;
	}

}TVFUGOB;

/**update MB struct*/
typedef struct PROTO_API tagVFUMB
{
	s32 m_nFirstGOB;
	s32 m_nFirstMB;
	s32 m_nNumOfMB;

	tagVFUMB()
	{
		Clear();
	}

	void Clear()
	{
		m_nFirstGOB = 0;
		m_nFirstMB	= 0;
		m_nNumOfMB	= 0;
	}

    void host2net(BOOL32 bhton);

    void SetFirstGOB(s32 nFirstGOB)
	{
		m_nFirstGOB = nFirstGOB;
	}
	s32 GetFirstGOB()
	{
		return m_nFirstGOB;
	}

	void SetFirstMB(s32 nFirstMB)
	{
		m_nFirstMB = nFirstMB;
	}
	s32 GetFirstMB()
	{
		return m_nFirstMB;
	}

	void SetNumOfMB(s32 nNumOfMB)
	{
		//add by yj
		//m_nNumOfMB = m_nNumOfMB;
		m_nNumOfMB = nNumOfMB;
		//end
	}
	s32 GetNumOfMB()
	{
		return m_nNumOfMB;
	}
	
}TVFUMB;

/**RRQ��Ϣ�ṹ*/
typedef struct PROTO_API tagRRQInfo
{
	PFC_IPADDR		m_tCallAddr;			/**<���������ַ*/
	PFC_IPADDR		m_tLocalRASAddr;		/**<����RAS��ַ*/
	cmEndpointType	m_eTerminalType;		/**<�ն�����,GK��*/
	TALIASADDR		m_atAlias[MAXALIASNUM];	/**<��GKע��ʱ�Ķ������������ӵ�0��������ʼ��ֵ*/
	s32				m_nTimetoLive;			/**<timetolive����λ����	(optional)*/
	BOOL32			m_bKeepAlive;			/**<������ע���־λ*/
	TALIASADDR		m_tEndpointID;			/**<�ն�ID,GK��			(optional)*/
	PFC_IPADDR		m_tGkAddr;				/**<GK��ַ*/
	TALIASADDR		m_tUserName;	             //ע���ʺ�(E164��h323id)
	s8				m_ach_Password[REG_PWD_LEN];			/**<ע����Կ*/
	TALIASADDR		m_tGKID;				/**<GK ID,GK��*/
	BOOL32          m_bSigTraversal;        /**<signalling traversal*/
 	BOOL32			m_bRequireGKPermison;

	TVENDORINFO		m_tVendorInfo;			/**<��Ʒ�š��汾��*/

	PFC_IPADDR        m_tParaAddr;          /**<NAT�����Դ��ַ*/
	
	BOOL32			m_bPortReused;   /**<�Ƿ�֧�ֶ˿ڸ���*/

	tagRRQInfo()
	{
		Clear();
	}

	void Clear();
	
    /**���ú��������ַ*/
    void SetCallAddr( PFC_IPADDR &tCallAddr )
    {
        m_tCallAddr = tCallAddr;
    }
    /**�õ����������ַ*/
    PFC_IPADDR& GetCallAddr()
    {
        return m_tCallAddr;
    }

    /**���ñ���RAS��ַ*/
    void SetLocalRASAddr( PFC_IPADDR &tLocalRASAddr )
    {
        m_tLocalRASAddr = tLocalRASAddr;
    }
    /**�õ�����RAS��ַ*/
    PFC_IPADDR& GetLocalRASAddr()
    {
        return m_tLocalRASAddr;
    }
    /**�����ն�����*/
    void SetTerminalType( cmEndpointType emTerminalType )
    {
        m_eTerminalType = emTerminalType;
    }
    /**�õ��ն�����*/
    cmEndpointType GetTerminalType()
    {
        return m_eTerminalType;
    }

    /**����ע�����*/
    void SetRRQAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atAlias[byAliasNo] = tAlias;
    }
    /**�õ�ע��ı���*/
    TALIASADDR& GetRRQAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atAlias[byAliasNo];
        else
            return m_atAlias[0];        
    }

    /**����TimetoLiveֵ*/
    void SetTimetoLive( s32 nTimetoLive )
    {
        m_nTimetoLive = nTimetoLive;
    }
    /**�õ�TimetoLiveֵ*/
    s32 GetTimetoLive()
    {
        return m_nTimetoLive;
    }

    /**�����Ƿ�������ע��*/
    void SetKeepAlive( BOOL32 bKeepAlive )
    {
        m_bKeepAlive = bKeepAlive;
    }
    /**�ж��Ƿ�������ע��*/
    BOOL32 IsKeepAlive()
    {
        return m_bKeepAlive;
    }

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }
	/**�����û�����*/
	void SetUserInfo(TALIASADDR* ptUserName, s8* pszPassword);

	/**ȡ�û���*/
	TALIASADDR* GetUserName()
	{
		return &m_tUserName;
	}
	/**ȡ����*/
	s8* GetPassword()
	{
		return m_ach_Password;
	}
    /**����GK��ַ*/
    void SetGKAddr( PFC_IPADDR &tGkAddr )
    {
        m_tGkAddr = tGkAddr;
    }
    /**�õ�GK��ַ*/
    PFC_IPADDR& GetGKAddr()
    {
        return m_tGkAddr;
    }
    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }
	
	/**����NAT Դ��ַ*/
    void SetParaAddr( PFC_IPADDR &tParamAddr )
    {
        m_tParaAddr = tParamAddr;
    }
    /**�õ�NAT Դ��ַ*/
    PFC_IPADDR& GetParaAddr()
    {
        return m_tParaAddr;
    }
	void SetBeH460Ep(BOOL32 bType)
	{
		m_bSigTraversal = htonl(bType);
	}
	BOOL32 GetBeH460Ep()
	{
		return ntohl(m_bSigTraversal);
	}

	/**�˿ڸ��ã�Ĭ��ֵ0���Ǳ괫��ʱ��ת��u8���ʹ���*/
	void SetPortReused(BOOL32 bPortReused)
	{
		m_bPortReused = bPortReused;
	}
	BOOL32 GetPortReused()
	{
		return m_bPortReused;
	}

}TRRQINFO, *PTRRQINFO;

/**RCF��Ϣ�ṹ*/
typedef struct PROTO_API tagRCFInfo
{
	PFC_IPADDR		m_tCallSignalAddr;		/**<GK���صĺ��������ַ*/
	TALIASADDR		m_atAlias[MAXALIASNUM];	/**<GK���صĶ������			(optional)*/
	TALIASADDR		m_tGKID;				/**<GK ID,GK��*/
	TALIASADDR		m_tEndpointID;			/**<�ն�ID,GK��*/
	s32				m_nTimetoLive;			/**<timetolive ��λ����		(optional)*/
	BOOL32			m_bWillRespondToIRR;	/**<�Ƿ���ӦIRR��Ϣ,GK��*/
	BOOL32          m_bIsKDVTSGK;           /**<�Ƿ���KDVTS��GK*/
	BOOL32          m_bSigTraversal;        /**<signalling traversal*/
	BOOL32          m_bIfAccess;            /**<�Ƿ���GK��Ȩ��û��usbkey��pcmt��Ҫ���GK��Ȩ������������*/

    // XXX
    u8              byNonAccessReason;      /**<���δ���GK��Ȩ������ֶ�������ԭ��*/

	tagRCFInfo()
	{
		Clear();
	}

	void Clear();

	void SetBeH460Ep(BOOL32 bType)
	{
		m_bSigTraversal = bType;
	}
	BOOL32 GetBeH460Ep()
	{
		return m_bSigTraversal;
	}			

    /**����GK���صĺ��������ַ*/
    void SetCallSignalAddr( PFC_IPADDR &tCallSignalAddr )
    {
        m_tCallSignalAddr = tCallSignalAddr;
    }
    /**�õ�GK���صĺ��������ַ*/
    PFC_IPADDR& GetCallSignalAddr()
    {
        return m_tCallSignalAddr;
    }

    /**����GK���صĶ������*/
    void SetRCFAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atAlias[byAliasNo] = tAlias;
    }
    /**�õ�GK���صĶ������*/
    TALIASADDR& GetRCFAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atAlias[byAliasNo];
        else
            return m_atAlias[0];
    }

    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }
    
    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**����TimetoLiveֵ*/
    void SetTimetoLive( s32 nTimetoLive )
    {
        m_nTimetoLive = nTimetoLive;
    }
    /**�õ�TimetoLiveֵ*/
    s32 GetTimetoLive()
    {
        return m_nTimetoLive;
    }

    /**�����Ƿ���ӦIRR��Ϣ*/
    void SetWillRespondToIRR( BOOL32 bKeepAlive )
    {
        m_bWillRespondToIRR = bKeepAlive;
    }
    /**�ж��Ƿ���ӦIRR��Ϣ*/
    BOOL32 IsWillRespondToIRR()
    {
        return m_bWillRespondToIRR;
    }
	void SetIsKDVTSGK(BOOL32 bIsKDVGK)
	{
		m_bIsKDVTSGK = bIsKDVGK;
	}
	BOOL32 GetIsKDVTSGK()
	{
		return m_bIsKDVTSGK;
    }
}TRCFINFO, *PTRCFINFO;

/**ARQ�ṹ��*/
typedef struct PROTO_API tagARQInfo
{
	cmCallType		m_eCallType;			    /**<��������,GK��*/
	cmCallModelType m_eCallModel;			    /**<GK����ģʽ,Ĭ��ֵΪֱ�Ӻ���	(optional)*/
	TALIASADDR		m_tEndpointID;			    /**<�ն�ID,GK��*/
	TALIASADDR		m_tDestAlias;			    /**<Ŀ�Ķ˱���*/
	PFC_IPADDR		m_tCalledAddr;			    /**<Ŀ�Ķ˵�ַ*/
	TALIASADDR		m_atSrcAlias[MAXALIASNUM];  /**<Դ�˱���*/
	PFC_IPADDR		m_tCallAddr;			    /**<Դ�˵�ַ,GK��(optional)*/
	s32				m_nBandWidth;			    /**<��λ��kbps*/
	s32				m_nCRV;					    /**<���вο�ֵ,GK��*/
	s8  			m_achConferenceID[LEN_GUID];/**<����ID,GK��*/
	BOOL32			m_bAnswerCall;			    /**<�Ƿ񱻽�,GK��*/
	s8  			m_achCallID[LEN_GUID];	    /**<����ID,GK��*/
	TALIASADDR		m_tGKID;				    /**<GK ID,GK��(optional)*/
	
	PFC_IPADDR		m_tGkAddr;				    /**<GK��ַ*/
	
	tagARQInfo()
	{
		Clear();
	}

	void Clear();

    /**���ú�������*/
    void SetCallType( cmCallType emCallType )
    {
        m_eCallType = emCallType;
    }
    /**�õ���������*/
    cmCallType GetCallType()
    { 
        return m_eCallType;
    }

    /**���ú���ģʽ*/
    void SetCallModelType( cmCallModelType emCallModel )
    {
        m_eCallModel = emCallModel;
    }
    /**�õ�����ģʽ*/
    cmCallModelType GetCallModelType()
    { 
        return m_eCallModel;
    }

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**����Ŀ�Ķ˱���*/
    void SetDestAlias( TALIASADDR &tDestAlias )
    {
        m_tDestAlias = tDestAlias;
    }
    /**�õ�Ŀ�Ķ˱���*/
    TALIASADDR& GetDestAlias()
    {
        return m_tDestAlias;
    }

    /**����Ŀ�Ķ˵�ַ*/
    void SetCalledAddr( PFC_IPADDR &tCalledAddr )
    {
        m_tCalledAddr = tCalledAddr;
    }
    /**�õ�Ŀ�Ķ˵�ַ*/
    PFC_IPADDR& GetCalledAddr()
    {
        return m_tCalledAddr;
    }

    /**����Դ�˱���*/
    void SetARQSrcAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atSrcAlias[byAliasNo] = tAlias;
    }
    /**�õ�Դ�˱���*/
    TALIASADDR& GetARQSrcAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atSrcAlias[byAliasNo];
        else
            return m_atSrcAlias[0];
    }

    /**����Դ�˵�ַ*/
    void SetCallAddr( PFC_IPADDR &tCallAddr )
    {
        m_tCallAddr = tCallAddr;
    }
    /**�õ�Դ�˵�ַ*/
    PFC_IPADDR& GetCallAddr()
    {
        return m_tCallAddr;
    }

    /**���ô���*/
    void SetBandWidth( s32 nBandWidth )
    {
        m_nBandWidth = nBandWidth;
    }
    /**�õ�����*/
    s32 GetBandWidth()
    {
        return m_nBandWidth;
    }

    /**���ú��вο�ֵ*/
    void SetCRV( s32 nCRV )
    {
        m_nCRV = nCRV;
    }
    /**�õ����вο�ֵ*/
    s32 GetCRV()
    {
        return m_nCRV;
    }

    /**���û���ID*/
    void SetConferenceID( s8 *pchConferenceID, u8 byLen );

    /**�õ�����ID*/
    s8* GetConferenceID()
    {
        return m_achConferenceID;
    }

    /**�����Ƿ񱻽�*/
    void SetAnswerCall( BOOL32 bAnswerCall )
    {
        m_bAnswerCall = bAnswerCall;
    }
    /**�ж��Ƿ񱻽�*/
    BOOL32 IsAnswerCall()
    {
        return m_bAnswerCall;
    }

    /**���ú���ID*/
    void SetCallID( s8 *pchCallID, u8 byLen );

    /**�õ�����ID*/
    s8* GetCallID()
    {
        return m_achCallID;
    }

    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }

    /**����GK��ַ*/
    void SetGKAddr( PFC_IPADDR &tGKAddr )
    {
        m_tGkAddr = tGKAddr;
    }
    /**�õ�GK��ַ*/
    PFC_IPADDR& GetGKAddr()
    {
        return m_tGkAddr;
    }    
}TARQINFO, *PTARQINFO;

/**ACF�ṹ��*/
typedef struct PROTO_API tagACFInfo
{
	s32				m_nBandWidth;			    /**<��λ��kbps*/
	cmCallModelType m_eCallModel;			    /**<GK����ģʽ,Ĭ��ֵΪֱ�Ӻ���*/
	PFC_IPADDR		m_tCalledAddr;			    /**<Ŀ�Ķ˵�ַ*/
	s32				m_nIRRFrequency;		    /**<IRR�ķ���Ƶ�ʣ���λ����	(optional)*/
	BOOL32			m_bWillResponseIRR;		    /**<��ӦIRR��Ϣ*/
	TALIASADDR		m_atDestAlias[MAXALIASNUM];	/**<GK���صĶ������(optional) */

	PFC_IPADDR        m_tP2PCheckAddr;            /**<add by zhanghb for kdvp2.0 P2P���м���ַ���Ǳ�*/			
	
	tagACFInfo()
	{
		Clear();
	}

	void Clear();

    /**���ô���*/
    void SetBandWidth( s32 nBandWidth )
    {
        m_nBandWidth = nBandWidth;
    }
    /**�õ�����*/
    s32 GetBandWidth()
    {
        return m_nBandWidth;
    }

    /**���ú���ģʽ*/
    void SetCallModelType( cmCallModelType emCallModel )
    {
        m_eCallModel = emCallModel;
    }
    /**�õ�����ģʽ*/
    cmCallModelType GetCallModelType()
    { 
        return m_eCallModel;
    }

    /**����Ŀ�Ķ˵�ַ*/
    void SetCalledAddr( PFC_IPADDR &tCalledAddr )
    {
        m_tCalledAddr = tCalledAddr;
    }
    /**�õ�Ŀ�Ķ˵�ַ*/
    PFC_IPADDR& GetCalledAddr()
    {
        return m_tCalledAddr;
    }

	/**����Ŀ�Ķ˵�ַ*/
    void SetP2PCallCheckAddr( PFC_IPADDR &tCalledAddr )
    {
        m_tP2PCheckAddr = tCalledAddr;
    }
    /**�õ�Ŀ�Ķ˵�ַ*/
    PFC_IPADDR& GetP2PCallCheckAddr()
    {
        return m_tP2PCheckAddr;
    }		


    /**����IRR�ķ���Ƶ��*/
    void SetIRRFrequency( s32 nIRRFrequency )
    {
        m_nIRRFrequency = nIRRFrequency;
    }
    /**�õ�IRR�ķ���Ƶ��*/
    s32 GetIRRFrequency()
    {
        return m_nIRRFrequency;
    }

    /**�����Ƿ���ӦIRR��Ϣ*/
    void SetWillResponseIRR( BOOL32 bWillResponseIRR )
    {
        m_bWillResponseIRR = bWillResponseIRR;
    }
    /**�ж��Ƿ���ӦIRR��Ϣ*/
    BOOL32 IsWillResponseIRR()
    {
        return m_bWillResponseIRR;
    }
    /**����GK���صĶ������*/
    void SetACFAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atDestAlias[byAliasNo] = tAlias;
    }
    /**�õ�GK���صĶ������*/
    TALIASADDR& GetACFAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atDestAlias[byAliasNo];
        else
            return m_atDestAlias[0];
    }
}TACFINFO, *PTACFINFO;

/**DRQ�ṹ��*/
typedef struct PROTO_API tagDRQInfo
{
	TALIASADDR		m_tEndpointID;			    /**<�ն�ID,GK��*/
	s8  			m_achConferenceID[LEN_GUID];/**<����ID,GK��*/
	s32				m_nCRV;					    /**<���вο�ֵ,GK��*/
	cmRASDisengageReason m_eReason;			    /**<DRQ��ԭ��*/		
	s8  			m_achCallID[LEN_GUID];	    /**<����ID,GK��*/
	TALIASADDR		m_tGKID;				    /**<GK ID,GK��(optional)*/
	BOOL32			m_bAnsweredCall;		    /**<�Ƿ�Ϊ���ж�,GK��*/

	PFC_IPADDR		m_tDestAddr;			    /**<DRQ�Ľ��ܶ˵�ַ*/
	
	tagDRQInfo()
	{
		Clear();
	}

	void Clear();

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**���û���ID*/
    void SetConferenceID( s8 *pchConferenceID, u8 byLen );

    /**�õ�����ID*/
    s8* GetConferenceID()
    {
        return m_achConferenceID;
    }

    /**���ú��вο�ֵ*/
    void SetCRV( s32 nCRV )
    {
        m_nCRV = nCRV;
    }
    /**�����вο�ֵ*/
    s32 GetCRV()
    {
        return m_nCRV;
    }

    /**����DRQ��ԭ��*/
    void SetDRQReason( cmRASDisengageReason emDRQReason )
    {
        m_eReason = emDRQReason;
    }
    /**�õ�DRQ��ԭ��*/
    cmRASDisengageReason GetDRQReason()
    { 
        return m_eReason;
    }

    /**���ú���ID*/
    void SetCallID( s8 *pchCallID, u8 byLen );

    /**�õ�����ID*/
    s8* GetCallID()
    {
        return m_achCallID;
    }
    
    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }

    /**�����Ƿ񱻽�*/
    void SetAnsweredCall( BOOL32 bAnsweredCall )
    {
        m_bAnsweredCall = bAnsweredCall;
    }
    /**�ж��Ƿ񱻽�*/
    BOOL32 IsAnsweredCall()
    {
        return m_bAnsweredCall;
    }
    
    /**����DRQ�Ľ��ܶ˵�ַ*/
    void SetDestAddr( PFC_IPADDR &tDestAddr )
    {
        m_tDestAddr = tDestAddr;
    }
    /**�õ�DRQ�Ľ��ܶ˵�ַ*/
    PFC_IPADDR& GetDestAddr()
    {
        return m_tDestAddr;
    }
}TDRQINFO, *PTDRQINFO;

/**URQ�ṹ��*/
typedef struct PROTO_API tagURQInfo
{
	PFC_IPADDR		m_tCallAddr;			/**<Դ�˺��������ַ*/
	TALIASADDR		m_atAlias[MAXALIASNUM];	/**<��GKע��ʱ�Ķ������(optional)*/
	TALIASADDR		m_tEndpointID;			/**<�ն�ID(optional)*/
	TALIASADDR		m_tGKID;				/**<GK ID(optional)*/
	cmRASUnregReason m_eReason;				/**<URQ��ԭ��(optional)*/
	
	PFC_IPADDR		m_tDestAddr;			/**<URQ�Ľ��ܶ˵�ַ*/
	
	tagURQInfo()
	{
		Clear();
	}

	void Clear();

    /**����Դ�˺��������ַ*/
    void SetCallAddr( PFC_IPADDR &tCallAddr )
    {
        m_tCallAddr = tCallAddr;
    }
    /**�õ�Դ�˺��������ַ*/
    PFC_IPADDR& GetCallAddr()
    {
        return m_tCallAddr;
    }

    /**������GKע��ʱ�Ķ������*/
    void SetURQAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atAlias[byAliasNo] = tAlias;
    }
    /**�õ���GKע��ʱ�Ķ������*/
    TALIASADDR& GetURQAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atAlias[byAliasNo];
        else
            return m_atAlias[0];
    }

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }

    /**����URQ��ԭ��*/
    void SetURQReason( cmRASUnregReason emURQReason )
    {
        m_eReason = emURQReason;
    }
    /**�õ�URQ��ԭ��*/
    cmRASUnregReason GetURQReason()
    { 
        return m_eReason;
    }

    /**����URQ�Ľ��ܶ˵�ַ*/
    void SetDestAddr( PFC_IPADDR &tDestAddr )
    {
        m_tDestAddr = tDestAddr;
    }
    /**�õ�URQ�Ľ��ܶ˵�ַ*/
    PFC_IPADDR& GetDestAddr()
    {
        return m_tDestAddr;
    }
}TURQINFO, *PTURQINFO;

/**BRQ�ṹ��*/
typedef struct tagBRQInfo
{
	TALIASADDR		m_tEndpointID;			    /**<�ն�ID,GK��*/
	s8			    m_achConferenceID[LEN_GUID];/**<����ID,GK��*/
	s32				m_nCRV;					    /**<���вο�ֵ,GK��*/
	cmCallType		m_eCallType;			    /**<��������,GK�ã�Ĭ��Ϊ��Ե�	(optional)*/
	s32				m_nBandWidth;			    /**<��λ��kbps*/
	
	s8			    m_achCallID[LEN_GUID];	    /**<����ID,GK��*/
	TALIASADDR		m_tGKID;				    /**<GK ID,GK��(optional)*/
	BOOL32			m_bAnsweredCall;		    /**<�Ƿ�Ϊ���ж�,GK��*/

	PFC_IPADDR		m_tDestAddr;			    /**<BRQ�Ľ��ܶ˵�ַ*/
	
	tagBRQInfo()
	{
		Clear();
	}

	void Clear();

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**���û���ID*/
    void SetConferenceID( s8 *pchConferenceID, u8 byLen );

    /**�õ�����ID*/
    s8* GetConferenceID()
    {
        return m_achConferenceID;
    }

    /**���ú��вο�ֵ*/
    void SetCRV( s32 nCRV )
    {
        m_nCRV = nCRV;
    }
    /**�õ����вο�ֵ*/
    s32 GetCRV()
    {
        return m_nCRV;
    }

    /**���ú�������*/
    void SetCallType( cmCallType emCallType )
    {
        m_eCallType = emCallType;
    }
    /**�õ���������*/
    cmCallType GetCallType()
    { 
        return m_eCallType;
    }

    /**���ô���*/
    void SetBandWidth( s32 nBandWidth )
    {
        m_nBandWidth = nBandWidth;
    }
    /**�õ�����*/
    s32 GetBandWidth()
    {
        return m_nBandWidth;
    }

    /**���ú���ID*/
    void SetCallID( s8 *pchCallID, u8 byLen );

    /**�õ�����ID*/
    s8* GetCallID()
    {
        return m_achCallID;
    }

    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }

    /**�����Ƿ񱻽�*/
    void SetAnsweredCall( BOOL32 bAnsweredCall )
    {
        m_bAnsweredCall = bAnsweredCall;
    }
    /**�ж��Ƿ񱻽�*/
    BOOL32 IsAnsweredCall()
    {
        return m_bAnsweredCall;
    }

    /**����BRQ�Ľ��ܶ˵�ַ*/
    void SetDestAddr( PFC_IPADDR &tDestAddr )
    {
        m_tDestAddr = tDestAddr;
    }
    /**�õ�BRQ�Ľ��ܶ˵�ַ*/
    PFC_IPADDR& GetDestAddr()
    {
        return m_tDestAddr;
    }
}TBRQINFO, *PTBRQINFO;

/**BCF�ṹ��*/
typedef struct tagBCFInfo
{
	s32				m_nBandWidth;			/**<��λ��kbps*/
	tagBCFInfo()
	{
		m_nBandWidth = 0;
	}

    /**���ô���*/
    void SetBandWidth( s32 nBandWidth )
    {
        m_nBandWidth = nBandWidth;
    }
    /**�õ�����*/
    s32 GetBandWidth()
    {
        return m_nBandWidth;
    }
}TBCFINFO, *PTBCFINFO;

/**LRQ�ṹ��*/
typedef struct tagLRQInfo
{
	TALIASADDR		m_tEndpointID;			/**<�ն�ID,GK��(optional)*/
	TALIASADDR		m_tDestAlias;			/**<Ŀ�Ķ˱���*/
	PFC_IPADDR		m_tReplyAddr;			/**<���Ͷ˵�ַ*/	
	TALIASADDR		m_tGKID;				/**<GK ID,GK��(optional)*/

	PFC_IPADDR		m_tResponseAddr;		/**<���ܶ˵�ַ*/

	tagLRQInfo()
	{
		Clear();
	}

	void Clear();

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**����Ŀ�Ķ˱���*/
    void SetDestAlias( TALIASADDR &tDestAlias )
    {
        m_tDestAlias = tDestAlias;
    }
    /**�õ�Ŀ�Ķ˱���*/
    TALIASADDR& GetDestAlias()
    {
        return m_tDestAlias;
    }

    /**���÷��Ͷ˵�ַ*/
    void SetReplyAddr( PFC_IPADDR &tReplyAddr )
    {
        m_tReplyAddr = tReplyAddr;
    }
    /**�õ����Ͷ˵�ַ*/
    PFC_IPADDR& GetReplyAddr()
    {
        return m_tReplyAddr;
    }
    
    /**����GK ID*/
    void SetGKID( TALIASADDR &tGKID )
    {
        m_tGKID = tGKID;
    }
    /**�õ�GK ID*/
    TALIASADDR& GetGKID()
    {
        return m_tGKID;
    }

    /**���ý��ܶ˵�ַ*/
    void SetResponseAddr( PFC_IPADDR &tResponseAddr )
    {
        m_tResponseAddr = tResponseAddr;
    }
    /**�õ����ܶ˵�ַ*/
    PFC_IPADDR& GetResponseAddr()
    {
        return m_tResponseAddr;
    }
}TLRQINFO, *PTLRQINFO;

/**LCF�ṹ��*/
typedef struct tagLCFInfo
{
	PFC_IPADDR		m_tCallAddr;			/**<���������ַ*/
	PFC_IPADDR		m_tRASAddr;				/**<RAS��ַ*/
	cmEndpointType	m_nDestinationType;		/**<�ն�����(optional)*/

	tagLCFInfo()
	{
		Clear();
	}

	void Clear();

    /**���ú��������ַ*/
    void SetCallAddr( PFC_IPADDR &tCallAddr )
    {
        m_tCallAddr = tCallAddr;
    }
    /**�õ����������ַ*/
    PFC_IPADDR& GetCallAddr()
    {
        return m_tCallAddr;
    }
    
    /**����RAS��ַ*/
    void SetRASAddr( PFC_IPADDR &tRASAddr )
    {
        m_tRASAddr = tRASAddr;
    }
    /**�õ�RAS��ַ*/
    PFC_IPADDR& GetRASAddr()
    {
        return m_tRASAddr;
    }
    
    /**�����ն�����*/
    void SetDestinationType( cmEndpointType emDestinationType )
    {
        m_nDestinationType = emDestinationType;
    }
    /**�õ��ն�����*/
    cmEndpointType GetDestinationType()
    {
        return m_nDestinationType;
    }
}TLCFINFO, *PTLCFINFO;

/**IRQ�ṹ��*/
typedef struct tagIRQInfo
{	
	s32				m_nCRV;					/**<���вο�ֵ*/
	s8  			m_achCallID[LEN_GUID];	/**<����ID*/

	HCALL			m_hsCall;				/**<���о��*/
	PFC_IPADDR		m_tPeerRasAddr;			/**<�Զ�RAS��ַ*/

	tagIRQInfo()
	{
		Clear();
	}

	void Clear();

    /**���ú��вο�ֵ*/
    void SetCRV( s32 nCRV )
    {
        m_nCRV = nCRV;
    }
    /**�õ����вο�ֵ*/
    s32 GetCRV()
    {
        return m_nCRV;
    }

    /**���ú���ID*/
    void SetCallID( s8 *pchCallID, u8 byLen );

    /**�õ�����ID*/
    s8* GetCallID()
    {
        return m_achCallID;
    }

    /**���ú��о��*/
    void SetHCALL( HCALL hsCall )
    {
        if ( hsCall != NULL )
            m_hsCall = hsCall;
    }
    /**�õ����о��*/
    HCALL GetHCALL()
    {
        return m_hsCall;
    }

    /**���öԶ�RAS��ַ*/
    void SetPeerRasAddr( PFC_IPADDR &tPeerRasAddr )
    {
        m_tPeerRasAddr = tPeerRasAddr;
    }
    /**�õ��Զ�RAS��ַ*/
    PFC_IPADDR& GetPeerRasAddr()
    {
        return m_tPeerRasAddr;
    }
}TIRQINFO, *PTIRQINFO;

/**IRR�ṹ��*/
typedef struct PROTO_API tagIRRInfo
{
	cmEndpointType	m_eEndpointType;		    /**<�ն�����,GK��*/
	TALIASADDR		m_tEndpointID;			    /**<�ն�ID,GK��*/
	PFC_IPADDR		m_tRASAddr;				    /**<����RAS��ַ*/
	PFC_IPADDR		m_tCallAddr;			    /**<���������ַ*/
	TALIASADDR		m_atAlias[MAXALIASNUM];	    /**<��GKע��Ķ������	(optional)	*/
	//perCallInfo
	s32				m_nCRV;					    /**<���вο�ֵ,GK��*/
	s8				m_achConferenceID[LEN_GUID];/**<����ID,GK��*/
	BOOL32			m_bOriginator;			    /**<�Ƿ�Ϊ����,GK��*/

	s8				m_achCallID[LEN_GUID];	    /**<����ID,GK��*/
	BOOL32			m_bNeedResponse;		    /**<�Ƿ���ӦIRR��Ϣ*/
	BOOL32			m_bIsUnsolicited;		    /**<Ĭ��ΪTRUE��������IRR��FALSE����ӦIRQ*/
											
	PFC_IPADDR		m_tGKAddr;				    /**<GK��ַ*/
	

	tagIRRInfo()
	{
		Clear();
	}

	void Clear();
	
    /**�����ն�����*/
    void SetEndpointType( cmEndpointType emEndpointType )
    {
        m_eEndpointType = emEndpointType;
    }
    /**�õ��ն�����*/
    cmEndpointType GetEndpointType()
    {
        return m_eEndpointType;
    }

    /**�����ն�ID*/
    void SetEndpointID( TALIASADDR &tEndpointID )
    {
        m_tEndpointID = tEndpointID;
    }
    /**�õ��ն�ID*/
    TALIASADDR& GetEndpointID()
    {
        return m_tEndpointID;
    }

    /**����RAS��ַ*/
    void SetRASAddr( PFC_IPADDR &tRASAddr )
    {
        m_tRASAddr = tRASAddr;
    }
    /**�õ�RAS��ַ*/
    PFC_IPADDR& GetRASAddr()
    {
        return m_tRASAddr;
    }

    /**���ú��������ַ*/
    void SetCallAddr( PFC_IPADDR &tCallAddr )
    {
        m_tCallAddr = tCallAddr;
    }
    /**�õ����������ַ*/
    PFC_IPADDR& GetCallAddr()
    {
        return m_tCallAddr;
    }

    /**����ע�����*/
    void SetIRRAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atAlias[byAliasNo] = tAlias;
    }
    /**�õ�ע��ı���*/
    TALIASADDR& GetIRRAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atAlias[byAliasNo];
        else
            return m_atAlias[0];
    }

    /**���ú��вο�ֵ*/
    void SetCRV( s32 nCRV )
    {
        m_nCRV = nCRV;
    }
    /**�õ����вο�ֵ*/
    s32 GetCRV()
    {
        return m_nCRV;
    }

    /**���û���ID*/
    void SetConferenceID( s8 *pchConferenceID, u8 byLen );
  
    /**�õ�����ID*/
    s8* GetConferenceID()
    {
        return m_achConferenceID;
    }
    
    /**�����Ƿ�����*/
    void SetOriginator( BOOL32 bOriginator )
    {
        m_bOriginator = bOriginator;
    }
    /**�ж��Ƿ�����*/
    BOOL32 IsOriginator()
    {
        return m_bOriginator;
    }

    /**���ú���ID*/
    void SetCallID( s8 *pchCallID, u8 byLen );

    /**�õ�����ID*/
    s8* GetCallID()
    {
        return m_achCallID;
    }
    
    /**�����Ƿ���ӦIRR��Ϣ*/
    void SetNeedResponse( BOOL32 bNeedResponse )
    {
        m_bNeedResponse = bNeedResponse;
    }
    /**�ж��Ƿ���ӦIRR��Ϣ*/
    BOOL32 IsNeedResponse()
    {
        return m_bNeedResponse;
    }

    /**�����Ƿ�Unsolicited��Ϣ*/
    void SetUnsolicited( BOOL32 bIsUnsolicited )
    {
        m_bIsUnsolicited = bIsUnsolicited;
    }
    /**�ж��Ƿ�Unsolicited��Ϣ*/
    BOOL32 IsUnsolicited()
    {
        return m_bIsUnsolicited;
    }
    
    /**����GK��ַ*/
    void SetGKAddr( PFC_IPADDR &tGkAddr )
    {
        m_tGKAddr = tGkAddr;
    }
    /**�õ�GK��ַ*/
    PFC_IPADDR& GetGKAddr()
    {
        return m_tGKAddr;
    }
    
}TIRRINFO, *PTIRRINFO;

/**GRQ�ṹ��*/
typedef struct tagGRQInfo
{	
	PFC_IPADDR		m_tRASAddr;				    /**<�ն�RAS��ַ*/
	cmEndpointType	m_eEndpointType;		    /**<�ն�����*/
	TALIASADDR		m_tGKID;				    /**<GK ID,GK��*/

	TVENDORINFO		m_tVendorInfo;				/**<��Ʒ��*/
	TALIASADDR		m_atAlias[MAXALIASNUM];	    /**<��GKע��ʱ�Ķ������*/

	tagGRQInfo()
	{
		Clear();
	}

	void Clear();

    /**����ע�����*/
    void SetRRQAlias( TALIASADDR &tAlias, u8 byAliasNo )
    {
        if ( byAliasNo >= MAXALIASNUM )
            return;
        
        m_atAlias[byAliasNo] = tAlias;
    }
    /**�õ�ע��ı���*/
    TALIASADDR& GetRRQAlias( u8 byAliasNo )
    {
        if ( byAliasNo < MAXALIASNUM ) 
            return m_atAlias[byAliasNo];
        else
            return m_atAlias[0];        
    }


}TGRQINFO, *PTGRQINFO;

/**GCF�ṹ��*/
typedef struct tagGCFInfo
{	
	TALIASADDR		m_tGKID;				    /**<GK ID,GK��*/
	PFC_IPADDR		m_tRASAddr;				    /**<GK��RAS��ַ*/

	tagGCFInfo()
	{
		Clear();
	}

	void Clear()
	{
		memset(&m_tGKID,0,sizeof(TALIASADDR));	
		m_tRASAddr.Clear();		
		//m_tRASAddr.SetNetAddress( 0, RASPORT );
	}
}TGCFINFO, *PTGCFINFO;

/**Service Control Session*/
typedef struct tagServiceControlSession
{
	u8       m_bySessionId;
    u8       m_byReason;
}TServiceControlSession, *PTServiceControlSession;

/**SCI for H460*/
typedef struct tagSCIInfo
{
	TServiceControlSession m_tServiceControlSession;
    PFC_IPADDR        m_tCallSignallingAddress;  /**<������е�ַ*/
	u8	            m_abyCallId[LEN_GUID];      /**<CallIdentifier*/
	
	tagSCIInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		memset(&m_tServiceControlSession, 0, sizeof(m_tServiceControlSession));
		m_tCallSignallingAddress.Clear();
		memset(m_abyCallId, 0, LEN_GUID);
	}
	
}TSCIINFO, *PTSCIINFO;


/**SCR for H460*/
typedef struct tagSCRINFO
{
	u16             m_wRequestSeqNum;           /**<�������б��*/
	TALIASADDR      m_tEndpointID;
	s8	            m_abyCallId[LEN_GUID];      /**<CallIdentifier*/
}TSCRINFO;

#ifdef WIN32
#pragma comment( lib, "ws2_32.lib" ) 
#pragma pack( push )
#pragma pack( 1 )
#define window( x )	x
#ifndef PACKED
#define PACKED
#endif
#else
#include <netinet/in.h>
#define window( x )
#if defined(__ETI_linux__)
#define PACKED
#else
#ifdef PACKED
#undef PACKED
#endif
#define PACKED __attribute__ ((packed))	/**< ȡ�����������Ż�����*/
#endif
#endif

/**Only for TPS*/
#ifdef CBB_FOR_TPS
typedef struct PROTO_API tagNSMInfo
{
	u32          m_dwNSMID;               /**<��Ϣ��*/
    u32          m_dwErrorCode;           /**<������ �ظ���Ϣʱ������*/
    u32          m_dwSequenceNumber;      /**<���к� ��ʱδ��*/
    u32          m_dwContentLen;          /**<��Ϣ�����ݳ���*/
    u32          m_dwStructNum;           /**<��Ϣ��Ľṹ����Ŀ*/
    BOOL32       m_bWillContinue;         /**<�Ƿ��к�������Ϣ��������Ϣ�峤��̫�������*/
	TALIASADDR   m_tMTAlias;              /**<�ն˱���Ŀǰֻ��E164��*/
	u8           m_bybuf[KDV_NSM_MAX_LEN];/**<��Ϣ��*/
	
    tagNSMInfo()
    {
        Clear();
    }
	
    void Clear()
	{
		m_dwNSMID            = 0;
		m_dwErrorCode        = 0;       
		m_dwSequenceNumber   = 0;
		m_dwContentLen       = 0;
		m_dwStructNum        = 0;
		m_bWillContinue      = FALSE;	
		memset(m_bybuf,0,KDV_NSM_MAX_LEN);
	}
	
	/**���ñ���*/
	void SetAliasAddr( TALIASADDR tAliasAddr )
	{		
		m_tMTAlias.SetAliasAddr(tAliasAddr.GetAliasType(),tAliasAddr.GetAliasName());
		m_tMTAlias.m_emType = (AliasType)htonl(tAliasAddr.m_emType);
	}
	/**��ȡ��������*/
    void GetAliasAddr( TALIASADDR &tAliasAddr)
	{
		tAliasAddr.m_emType = (AliasType)ntohl(m_tMTAlias.m_emType);
		tAliasAddr.SetAliasAddr(tAliasAddr.GetAliasType(),m_tMTAlias.GetAliasName());
	}
	void SetNSMID(u32 dwNSMID)
	{ 
		m_dwNSMID = htonl(dwNSMID);
	}
	u32 GetNSMID()
	{
		return ntohl(m_dwNSMID);
	}
	void SetErrorCode(u32 dwErrorCode)
	{
		m_dwErrorCode = htonl(dwErrorCode);
	}
	u32 GetErrorCode()
	{
		return ntohl(m_dwErrorCode);
	}
	void SetSQN(u32 dwSQN)
	{
		m_dwSequenceNumber = htonl(dwSQN);
	}
	u32 GetSQN()
	{
		return ntohl(m_dwSequenceNumber);
	}
	void SetStructNum(u32 dwMsgNum)
	{
		m_dwStructNum = htonl(dwMsgNum);
	}
	u32 GetStructNum()
	{
		return ntohl(m_dwStructNum);
	}
    void SetWillContinue(BOOL32 bWillContinue)
    {
        m_bWillContinue = htonl(bWillContinue);
    }
    BOOL32 IsWillContinue()
    {
        return ntohl(m_bWillContinue);
    }
    void SetContentLen(u32 dwContentLen)
    {
        m_dwContentLen = htonl(dwContentLen);
    }
    u32 GetContentLen()
    {
        return ntohl(m_dwContentLen);
    }
	u8* GetMsgData()
	{
		return (u8*)m_bybuf;
	}
	
	BOOL32 SetMsgData(u8 * pbuf,u32 dwMsgLen)
	{
		if (pbuf == NULL || dwMsgLen > KDV_NSM_MAX_LEN)
		{
			return FALSE;
		}
		memset( m_bybuf, 0, KDV_NSM_MAX_LEN );
		memcpy(m_bybuf,pbuf,dwMsgLen);
		return TRUE;
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
TNSMInfo,*PTNSMInfo;
#else
typedef struct PROTO_API tagNSMInfo
{
	u32          m_dwNSMID;               /**<��Ϣ��*/
    u32          m_dwErrorCode;           /**<������ �ظ���Ϣʱ������*/
    u32          m_dwSequenceNumber;      /**<���к� ��ʱδ��*/
    u32          m_dwContentLen;          /**<��Ϣ�����ݳ���*/
    u32          m_dwStructNum;           /**<��Ϣ��Ľṹ����Ŀ*/
    BOOL32       m_bWillContinue;         /**<�Ƿ��к�������Ϣ��������Ϣ�峤��̫�������*/
	TALIASADDR   m_tMTAlias;              /**<�ն˱���Ŀǰֻ��E164��*/
	u32          m_dwRas;                 /**<RAS���. The only meaning of its existence is to compatible to old MOVISION endpoints*/
	u8           m_bybuf[KDV_NSM_MAX_LEN];/**<��Ϣ��*/

    tagNSMInfo()
    {
        Clear();
    }
	
    void Clear()
	{
		m_dwNSMID            = 0;
		m_dwErrorCode        = 0;       
		m_dwSequenceNumber   = 0;
		m_dwContentLen       = 0;
		m_dwStructNum        = 0;
		m_bWillContinue      = FALSE;	
		m_dwRas				 = 0;
		memset(m_bybuf,0,KDV_NSM_MAX_LEN);
	}
   
	/**���ñ���*/
	void SetAliasAddr( TALIASADDR tAliasAddr )
	{		
		m_tMTAlias.SetAliasAddr(tAliasAddr.GetAliasType(),tAliasAddr.GetAliasName());
		m_tMTAlias.m_emType = (AliasType)htonl(tAliasAddr.m_emType);
	}
	/**��ȡ��������*/
    void GetAliasAddr( TALIASADDR &tAliasAddr)
	{
		tAliasAddr.m_emType = (AliasType)ntohl(m_tMTAlias.m_emType);
		tAliasAddr.SetAliasAddr(tAliasAddr.GetAliasType(),m_tMTAlias.GetAliasName());
	}
	void SetNSMID(u32 dwNSMID)
	{ 
		m_dwNSMID = htonl(dwNSMID);
	}
	u32 GetNSMID()
	{
		return ntohl(m_dwNSMID);
	}
	void SetErrorCode(u32 dwErrorCode)
	{
		m_dwErrorCode = htonl(dwErrorCode);
	}
	u32 GetErrorCode()
	{
		return ntohl(m_dwErrorCode);
	}
	void SetSQN(u32 dwSQN)
	{
		m_dwSequenceNumber = htonl(dwSQN);
	}
	u32 GetSQN()
	{
		return ntohl(m_dwSequenceNumber);
	}
	void SetStructNum(u32 dwMsgNum)
	{
		m_dwStructNum = htonl(dwMsgNum);
	}
	u32 GetStructNum()
	{
		return ntohl(m_dwStructNum);
	}
    void SetWillContinue(BOOL32 bWillContinue)
    {
        m_bWillContinue = htonl(bWillContinue);
    }
    BOOL32 IsWillContinue()
    {
        return ntohl(m_bWillContinue);
    }
    void SetContentLen(u32 dwContentLen)
    {
        m_dwContentLen = htonl(dwContentLen);
    }
    u32 GetContentLen()
    {
        return ntohl(m_dwContentLen);
    }
	u8* GetMsgData()
	{
		return (u8*)m_bybuf;
	}
	u32 GetRas()
	{
		return ntohl(m_dwRas);
	}
	void SetRas(u32 dwRas)
	{
		m_dwRas = htonl(dwRas );
	}

	BOOL32 SetMsgData(u8 * pbuf, u32 dwMsgLen)
	{
		if (pbuf == NULL || dwMsgLen > KDV_NSM_MAX_LEN)
		{
			return FALSE;
		}
		memset( m_bybuf, 0, KDV_NSM_MAX_LEN );
		memcpy(m_bybuf,pbuf,dwMsgLen);
		return TRUE;
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
TNSMInfo,*PTNSMInfo;
#endif //CBB_FOR_TPS

typedef struct tagNSM_MTList_RSP_BodyHead
{
private:
    cmEndpointType	m_emEndpointType;       /**<�ն�����*/
    PFC_IPADDR        m_tRasAddr;           /**<RAS��ַ*/
    u16				m_wCallAddrNum;         /**<���������ַ�ĸ��� */   
    u16				m_wAliasNum;            /**<��������*/
    u32             m_dwAliasBufLen;        /**<ѹ����ı���buf����*/
	
public:
	
    void SetTerminalType( cmEndpointType emEndpointType )
    {
        m_emEndpointType = (cmEndpointType)htonl(emEndpointType);
    }
    cmEndpointType GetTerminalType()
    {
        return (cmEndpointType)ntohl(m_emEndpointType);
    }
	
    void SetAliasNum( u16 wAliasNum )
    {
        m_wAliasNum = htons(wAliasNum);
    }
    u16 GetAliasNum()
    {
        return ntohs(m_wAliasNum);
    }
    
    void SetAliasBufLen( u32 dwAliasBufLen )
    {
        m_dwAliasBufLen = htonl(dwAliasBufLen);
    }
    u32 GetAliasBufLen()
    {
        return ntohl(m_dwAliasBufLen);
    }
	
    void SetRASAddr( PFC_IPADDR &tRASAddr )
    {
        m_tRasAddr = tRASAddr;
    }
    PFC_IPADDR* GetRASAddr()
    {
        return &m_tRasAddr;
    }
	
    void SetCallAddrNum( u16 wCallAddrNum )
    {
        m_wCallAddrNum = htons(wCallAddrNum);
    }
    u16 GetCallAddrNum()
    {
        return ntohs(m_wCallAddrNum);
    }
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
TNSM_MTList_RSP_BodyHead,*PTNSM_MTList_RSP_BodyHead;

#define KDVTS_ENTERPRISE	(u32)150
#define KDVTS_P1			(u32)160
#define KDVTS_P2			(u32)170


typedef struct tagNSM_TS_CATEGORY_RSP_Body
{
private:
	u32				m_dwTSCategory;     /**< ���ڱ�ʶ����ҵ�滹����Ӫ��*/
	s8				m_achBuf[128];      /**< ��ʱδ��*/
	
public:
	
    void SetTSCategory( u32 dwTSCategory )
    {
        m_dwTSCategory = htonl(dwTSCategory);
    }
    u32 GetTSCategory()
    {
        return ntohl(m_dwTSCategory);
    }
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
TNSM_TS_CATEGORY_RSP_Body, *PTNSM_TS_CATEGORY_RSP_Body;

#ifdef WIN32
#pragma pack( pop )
#endif

#endif //_H323CALLSTDSTRUCT_H
