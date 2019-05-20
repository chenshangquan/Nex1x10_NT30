#pragma once

#ifndef _EVSIPLIB_20180920_H_
#define _EVSIPLIB_20180920_H_



//rkcLib中消息定义
enum EmUiRkcMsg
{

#define UI_SIPTOOL_MSG_BEGIN  	2000 + 0x1 

	/************************************************************************/
	/** 连接 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolConnect	= UI_SIPTOOL_MSG_BEGIN,
#define	UI_SIPTOOL_CONNECTED  ev_UISipToolConnect
	
	/************************************************************************/
	/** 已断开
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolDisconnected,
#define UI_SIPTOOL_DISCONNECTED	 ev_UISipToolDisconnected

    /************************************************************************/
	/** 注销
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UISipToolLogout,
#define UI_SIPTOOL_LOGOUT  ev_UISipToolLogout

    ev_UIRkcEnd,
#define	UI_RKC_MSG_END   ev_UIRkcEnd

};

#endif 
