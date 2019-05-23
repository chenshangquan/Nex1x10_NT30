#include "stdafx.h"
#include "siptoolsysctrl.h"
#include "siptoolevent.h"
#include "json.h"

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
    //REG_PFUN(CONNECTCONTROLACK, CSipToolSysCtrl::OnConnected);
}

void CSipToolSysCtrl::OnConnected(const CMessage& cMsg)
{
    OspPrintf(true, false, "MULTIPLEREGSIGNACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    Json::Reader *readerinfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerinfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ret"].isInt())
        {
            nRet = root["ret"].asInt();
        }
    }

    PostEvent( UI_SIPTOOL_CONNECTED, (WPARAM)nRet, 0 );
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