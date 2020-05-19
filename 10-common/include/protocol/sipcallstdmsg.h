///  All right reserved
///  
///  @file        sipcallstdmsg.h 
///  @author      zgf
///  @version     1.0
///  @date        2018-3-1
///  @brief       sipcallstdmsg
///  @details     sipcallstdmsg interfaces describe here what it is all about.
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*  Start of sipcallstdmsg                                         */
/************************************************************************/

/**
 * @defgroup    sipcallstdmsg  
 * @brief       sipcallstdmsg   interfaces describe here what it is all about.
 * @{
 */
#ifndef _SIPCALLSTDMSG_H
#define _SIPCALLSTDMSG_H

#include "sipcallstdstruct.h"

/// ������Ϣ
enum EmSipCallMsgType 
{
	h_call_invalidInterface = 0,    ///< invaalid interface
	h_call_make				= 1,	///< �������
	h_call_incoming			= 2,	///< ���е���		
	h_call_answer			= 3,	///< ����(�ܾ�)���� 
	h_call_bye              = 4,    ///< ��������		
	h_call_connected        = 5,    ///< ���н���		 
	h_call_disconnected     = 6,    ///< ���жϿ�		 
	h_call_capsetnotify     = 7,    ///< ����������     
	h_dual_failed			= 8,    ///< dual failed
	h_call_roundtripdelay   = 9,    ///< roundtrip implemented by options method
	h_call_ack				= 10,   ///< ack
	h_call_reinvite			= 11,   ///< re-invite
	h_call_200OK			= 12,   ///< 200ok
	h_call_callidnotify		= 13,   ///< callid notify
	h_call_peeridnotify		= 14,   // add this for tps
	h_call_reinvitefailed   = 15,
};
/// sip reg ctrl msg type
enum EmSipRegCtrlMsgType
{
	h_sip_registration,          ///< sip registration
	h_sip_unregistration,        ///< sip unregistration
	h_sip_state2registered,      ///< registered
	h_sip_state2failed,          ///< failed
	h_sip_state2terminated,      ///< terminated
	h_sip_getreginfo,		     ///< ���regserver�ϵ�����ע����Ϣ����
	h_sip_reg_nonstandard_req,	 ///< SIP nonstandard messages between user agents and REGISTR
	h_sip_registration_ack,      ///< registration ack
	h_sip_register_create_failed ///< create register failed 
};
/// sip ums ctrl msg type
enum EmSipUMSCtrlMsgType
{
	h_ums_invalidInterface	= 0,    ///< invalid interface
	h_ums_registrationcmd	= 1,	///< RegisterRequest ע������ 
	h_ums_registrationind	= 2,	///< ע��ɹ���EmRegisterReason+TRegisterResponse��ע��ʧ�ܣ�EmRegisterReason (emRegFail); ע������ EmRegisterReason(emRegNameDup)+sizeof(s32)+TSipRegName ע����Ӧ
	h_ums_unregistrationcmd	= 3,	///< RegisterRequest+bool(if expire all) ȡ��ע������
	h_ums_unregistrationind	= 4,	///< EmRegisterReason ȡ��ע����Ӧ,ԭ��Ϊȡ���ɹ���ʧ��
	h_ums_query				= 5,	///< char(����) ��ѯ		h_ums_answer,      //EmRegisterReason+RegisterResponse ��Ӧ��ѯ
	h_ums_answer			= 6,	///< EmRegisterReason+RegisterResponse ��Ӧ��ѯ
	h_ums_option			= 7,	///< ��������ע���ն˷��Ͳ�ѯָ� ��option��Ϣ�� �ص�Ҳ��option��Ϣ,����regserver��ѯע���Ƿ�����
	h_ums_getregreq			= 8,	///< ums��cns��regserver�����õ�ǰ�ı���, buf������Ϊ��s32 nAppid, EmSIPRegNSMType
	h_ums_getregack			= 9,	///< regserver��Ӧ��, buf������Ϊ��s32 nAppid, TSipRegPackXml
	h_ums_getregack_B2		= 10,	///< regserver��Ӧ��, buf������Ϊ��s32 nAppid, TSipRegPackXmlB2, TSipRegInfoUms/TSipRegInfoCns				
	//h_sip_reg_nonstandard_rsp,	///< SIP nonstandard messages between user agents and REGISTRAR
};

/// Sip Arbitrary Msg Type
enum EmSipArbitraryMsgType
{
	h_sip_invalid,           ///< invalid
	h_sip_info,              ///< info
	h_sip_info_ack,          ///< info ack
	h_sip_options,           ///< options
	h_sip_options_ack,       ///< options ack
};

/**
* @}
*/
#endif