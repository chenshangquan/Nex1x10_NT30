#include "stdafx.h"
#include "siptoolinterface.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

UINT ThreadConnectSipTool(LPVOID lpParam)
{
    u16 re  = CSipToolComInterface->LinkSipServer();

    if ( re != NO_ERROR )
    {
        NOTIFY_MSG( UI_SIPTOOL_CONNECTED, false, re );
        return re;
    }

    return re;
}

u16 CSipToolInterface::SocketConnect( u32 dwIp, s8* szUser , s8* szPwd)
{
    if( NULL == m_pSipToolSession )
    {
        return ERR_SIPTOOL;
    }

    m_tLoginInfo.m_dwIp = dwIp;
    m_tLoginInfo.m_wPort = CONNETCT_SIPSERVER_PORT;

    strncpy(m_tLoginInfo.m_achName, szUser, sizeof(m_tLoginInfo.m_achName));
    strncpy(m_tLoginInfo.m_achPswd, szPwd, sizeof(m_tLoginInfo.m_achPswd));

    //Á¬½Ósiptool
    AfxBeginThread( ThreadConnectSipTool , NULL );

    return NO_ERROR;
}

u16 CSipToolInterface::LinkSipServer()
{
    u16 re =  ERR_SIPTOOL;
    if ( m_pSipToolSession != NULL )
    {
        re = m_pSipToolSession->ConnectSip( m_tLoginInfo.m_dwIp,  m_tLoginInfo.m_wPort, m_tLoginInfo.m_achName, m_tLoginInfo.m_achPswd );
    }
    return re;
}

u16 CSipToolInterface::CloseLink()
{
    u16 re =  ERR_SIPTOOL;
    if ( m_pSipToolSession != NULL )
    {
        re = m_pSipToolSession->DisconnectSip( );
    }

    return re;
    //return m_pSysCtrlIf->CloseSocket();
}

u16 CSipToolInterface::GetLoginInfo(TLoginInfo& tLoginInfo)
{
    tLoginInfo = m_tLoginInfo;
    return NO_ERROR;
}

u16 CSipToolInterface::SetParentIP(s8* szIp)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->SetParentIP(szIp);
}

u16 CSipToolInterface::SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->SetNeighborInfo(tNeighborInfo);
}

u16 CSipToolInterface::DeleteNeighborInfo(s8* szAreaNum)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->DeleteNeighborInfo(szAreaNum);
}

u16 CSipToolInterface::SetLocalAreaCode(s8* szLocalAreaCode)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->SetLocalAreaCode(szLocalAreaCode);
}

u16 CSipToolInterface::GetLocalInfo()
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->GetLocalInfo();
}

u16 CSipToolInterface::GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->GetCasRegServerBackInfo(tCasRegServerInfo);
}

u16 CSipToolInterface::GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->GetNeighborBackInfo(vNeighborInfo);
}

u16 CSipToolInterface::GetForceIP(string &strForceIP)
{
    if ( NULL == m_pSysCtrlIf )
    {
        return -1;
    }

    return m_pSysCtrlIf->GetForceIP(strForceIP);
}