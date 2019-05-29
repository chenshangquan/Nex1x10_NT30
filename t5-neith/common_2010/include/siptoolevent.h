#pragma once

#ifndef _EVSIPLIB_20180920_H_
#define _EVSIPLIB_20180920_H_



//rkcLib����Ϣ����
enum EmUiRkcMsg
{

#define UI_SIPTOOL_MSG_BEGIN  	2000 + 0x1 

	/************************************************************************/
	/** ���� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolConnect	= UI_SIPTOOL_MSG_BEGIN,
#define	UI_SIPTOOL_CONNECTED  ev_UISipToolConnect
	
	/************************************************************************/
	/** �ѶϿ�
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolDisconnected,
#define UI_SIPTOOL_DISCONNECTED	 ev_UISipToolDisconnected

    /************************************************************************/
	/** ע��
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolLogout,
#define UI_SIPTOOL_LOGOUT  ev_UISipToolLogout

    /************************************************************************/
	/** ���ø���IP Rsp
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolSetParentIPRsp,
#define UI_SIPTOOL_SETPARENTIPRSP ev_UISipToolSetParentIPRsp

    /************************************************************************/
	/** �����ھ���Ϣ Rsp
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolSetNeighborInfoRsp,
#define UI_SIPTOOL_SETNEIGHBORINFORSP ev_UISipToolSetNeighborInfoRsp

    /************************************************************************/
	/** ɾ���ھ���Ϣ Rsp
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolDeleteNeighborInfoRsp,
#define UI_SIPTOOL_DELETENEIGHBORINFORSP ev_UISipToolDeleteNeighborInfoRsp

    /************************************************************************/
	/** ���ñ������� Rsp
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolSetLocalAreaCodeRsp,
#define UI_SIPTOOL_SETLOCALAREACODERSP ev_UISipToolSetLocalAreaCodeRsp

    ev_UIRkcEnd,
#define	UI_RKC_MSG_END   ev_UIRkcEnd

};

#endif 
