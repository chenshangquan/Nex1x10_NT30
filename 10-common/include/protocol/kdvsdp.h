//////////////////////////////////////////////////////////////////////////
///  COPYRIGHT NOTICE
///  Copyright (C) 2018, ODDMETA
///  All right reserved
///  
///  @file        kdvsdp.h
///  @author      zgf
///  @version     1.0
///  @date        2018-3-5
///  @brief       sdp interfaces describe here what it is all about.
///  @details     Easy sdp ...
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*  Start of sdp                                          */
/************************************************************************/

/**
 * @defgroup    sdp
 * @brief       sdp interfaces describe here what it is all about.
 * @{
 */

#ifndef __KDVSDP_H__
#define __KDVSDP_H__

#include "sipcallstdstruct.h"
#include "kdvsiphandle.h"

/**
* \brief            ����sdp��������CSipCapSet����ת��ΪЭ��ջsdp������
* \param[in]        pcCap     :the capset set from module
* \param[in]        hHandle   :sdp handle for stack
* \return           BOOL32, TRUE/FALSE
*/
PROTO_API BOOL32 kdvsdp_create_sdp(CSipCapSet *pcCap, TSdpHandle hHandle, BOOL32 bUseStdH265, BOOL32 bTps);

/**
* \brief            ��ȡsdp��������Э��ջsdp����ת��ΪCSipCapSet����)
* \param[in]        hHandle   :sdp handle for stack
* \param[in]        pcCap     :the capset set from module
* \return           BOOL32, TRUE/FALSE
*/
PROTO_API BOOL32 kdvsdp_build_capset(TSdpHandle hHandle, CSipCapSet *pcCap, BOOL32 &bUseStdH265, BOOL32 bTps = FALSE);

/**
* \brief            sdp interface register to pfc for linux
* \return           BOOL32, TRUE/FALSE
*/
PROTO_API void sdpregfunlinux();

PROTO_API void SetSdpLogCB(ALL_LOG_CALlBACK  m_fpSdpLogCB);

/**
* \brief            whether EndpointType is ums or cns
* \param[in]        Endpoint Type;0-Unknown,1-MT,2-Mcu,4-Register,8-GK,16-CNS,32-UMS,64-GateWay,128-VRS
* \return           BOOL32, TRUE/FALSE
*/
PROTO_API BOOL32 sdpIsTps(emEndpointType m_emEndpointType);

/**
* \brief            sdp interface help
* \return           void.
*/
PROTO_EXTERN_API void sdphelp();

/**
* \brief            turn on all the print switches
* \param[in]        dwLevel     ;0-LOG_EXP,1-LOG_INFO,2-LOG_DEBUG
* \return           void.
*/
PROTO_EXTERN_API void sdplog(u32 dwLevel);

/**
* \brief            show kdvsdp version
* \return           void.
*/
PROTO_EXTERN_API void sdpver();

/**
* \brief            sdp log to telnet or stdout
* \param[in]        byFilter   ;1-emSipLogTelnet,2-emSipLogStdout,3-emSipLogAll
* \return           void.
*/
PROTO_EXTERN_API void sdplogto(u8 byFilter);

/**
* @}
*/

#endif