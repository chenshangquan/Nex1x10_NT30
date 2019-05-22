#include "stdafx.h"
#include "siptoolsysctrl.h"
#include "siptoolevent.h"

CSipToolSysCtrl::CSipToolSysCtrl(CSipToolSession &cSession) : CSipToolSysCtrlIF()
{
    m_pSession = &cSession;
    BuildEventsMap();
}

CSipToolSysCtrl::~CSipToolSysCtrl()
{

}

u16 CSipToolSysCtrl::SocketConnect(s8* pchIP, u32 dwPort)
{
   
    return NO_ERROR;
}

u16 CSipToolSysCtrl::CloseSocket()
{
    return NO_ERROR;
}

void CSipToolSysCtrl::BuildEventsMap()
{
    REG_PFUN(MULTIPLEREGSIGNACK, CSipToolSysCtrl::OnConnected);
}

void CSipToolSysCtrl::OnConnected(const CMessage& cMsg)
{
    PostEvent( UI_SIPTOOL_CONNECTED, 0, 0 ); 
    return;
}

void CSipToolSysCtrl::OnDicconnected(const CMessage& cMsg)
{
    //发送界面提醒
    
}

void CSipToolSysCtrl::DispEvent(const CMessage &cMsg)
{
    DISP_FUN(CSipToolSysCtrl, cMsg);
}

void CSipToolSysCtrl::OnTimeOut(u16 wEvent)
{ 
}