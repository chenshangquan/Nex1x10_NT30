/*****************************************************************************
ģ����      : CNC����̨
�ļ���      : cncConst.h
����ļ�    : 
�ļ�ʵ�ֹ���: ���������ʹ������,��cnc��UI���ֺ�cnclib���ֹ�ͬʹ��
����        : 
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��       �汾        �޸���      �޸�����
2014/12/20   1.4         Ф��Ȼ        ����
******************************************************************************/
#pragma once

#ifndef _SIPTOOLCONST_20190410_H_
#define _SIPTOOLCONST_20190410_H_

#include "kdvtype.h"
#include <map> 
using namespace std;

#define CONNETCT_SIPSERVER_PORT      60002                                     //sip�������˿ں� 

#define PrtSipToolMsg (CSipToolPrintCtrl::GetPrintCtrl()->PrintMsg)                        //��ӡCurl��Ϣ�ӿ�
#define SIPTOOLMAPPING_HELPER (CSipToolPrintCtrl::GetPrintCtrl()->MappingHelper)                  //ע���ӡ����Ϣ��

//------------------------------�����벿��------begin-------------------------------
/*�ն˿���̨����(27501 - 29500)*/
#define ERR_BGN		100
#define ERR_END		ERR_BGN + 1999

#define MAX_IP_LENGTH               16
#define MAX_ALIAS_LENGTH            32
#define MAX_SEARCH_TIME             10000

//rkcLib�еĴ�����
enum EmErrRkcLib
{

#define ERR_SIPTOOL_LIB_BEGIN  ERR_BGN

    // ����̨����
    errsiptool = ERR_SIPTOOL_LIB_BEGIN,
#define ERR_SIPTOOL                                 errsiptool

	// ����̨����
	err_siptool_creatinstance,
#define ERR_SIPTOOL_CREATINSTANCE                    err_siptool_creatinstance

    // ʵ����Ч
    errInterface,
#define ERR_SIPTOOL_INTERFACE                        errInterface

    //osp ��ʼ��ʧ��
    errOspInit,
#define  ERR_OSP_INIT                                errOspInit

    //��������
    errActiveConnect,
#define	ERR_SIPTOOL_ACTIVE_CONNECT                   errActiveConnect

    //TCP����ʧ��
    errTcpConnect,
#define	ERR_SIPTOOL_TCPCONNECT                       errTcpConnect


	errSipToolLibEnd,
#define ERR_SIPTOOL_LIB_END                         errSipToolLibEnd
		
};
 
#endif
