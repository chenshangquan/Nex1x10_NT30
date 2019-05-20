#include "StdAfx.h"
#include "siptoolcommonop.h"
#include "loginlogic.h"
#include "mainframelogic.h"
#include "logoutlogic.h"
#include "cascadecfglogic.h"
#include "neighborcfglogic.h"
#include "localareanumcfglogic.h"

ISipToolCommonOp::ISipToolCommonOp(void)
{
}


ISipToolCommonOp::~ISipToolCommonOp(void)
{
}


void ISipToolCommonOp::RegLogics()
{
    REG_LOGIC(CLoginLogic);
	REG_LOGIC(CMainFrameLogic);
    REG_LOGIC(CLogoutLogic);
    REG_LOGIC(CCascadeCfgLogic);
    REG_LOGIC(CNeighborCfgLogic);
    REG_LOGIC(CLocalAreaNumCfgLogic);

	return ;
}

bool ISipToolCommonOp::NotifyMsg(u16 wMsgId, void *pData)
{
	TMsgParam Msg;
	Msg.wMsgId = wMsgId;
	Msg.pData = (UINT_PTR)pData;
	ISipToolMsgManager::GetSingletonPtr()->PostMsg(Msg);
	return true;
}

bool ISipToolCommonOp::NotifyMsg(u16 wMsgId, WPARAM wParam, LPARAM lParam)
{
	TMsgParam Msg;
	Msg.wMsgId = wMsgId;
	Msg.pData = (UINT_PTR)wParam;
	Msg.lParam = lParam;
	ISipToolMsgManager::GetSingletonPtr()->PostMsg(Msg);
	return true;
}


MbString ISipToolCommonOp::StringFormat(const char *format, ... )
{
	char str[1024] = { 0 };
	va_list pvlist;
	va_start(pvlist, format);
	vsnprintf((char *)str, 1024, format, pvlist);
	va_end(pvlist);
	return str;
}
