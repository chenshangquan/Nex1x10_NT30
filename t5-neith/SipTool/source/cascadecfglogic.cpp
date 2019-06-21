#include "stdafx.h"
#include "cascadecfglogic.h"
#include "mainframelogic.h"

template<> CCascadeCfgLogic* Singleton<CCascadeCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CCascadeCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("CasCfgSaveBtn"), OnCasCfgSaveBtnClicked)

    MSG_EDITCHANGE(_T("ParentIPEdt"), OnParentIPChanged)

    USER_MSG(UI_SIPTOOL_CONNECTED, OnSipToolConnected)
    USER_MSG(UI_SIPTOOL_SETPARENTIPRSP, OnSetParentIPRsp)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CCascadeCfgLogic::CCascadeCfgLogic()
{
    m_cstrParentIP = _T("");
}

CCascadeCfgLogic::~CCascadeCfgLogic()
{
}

bool CCascadeCfgLogic::OnCasCfgSaveBtnClicked(TNotifyUI& msg)
{
    CString cstrParentIP =( ISipToolCommonOp::GetControlText(m_pm ,_T("ParentIPEdt")) ).c_str();

    if ( !CMainFrameLogic::IsIpFormatRight(cstrParentIP) )
    {
        SHOWTIP(_T("服务器地址非法"));
        return false;
    }

    CSipToolComInterface->SetParentIP( CT2A(cstrParentIP) );
    
    return true;
}

bool CCascadeCfgLogic::OnParentIPChanged(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseParentIPChanged"));

    CString cstrParentIP =( ISipToolCommonOp::GetControlText(m_pm ,_T("ParentIPEdt")) ).c_str();
    if ( cstrParentIP.IsEmpty() )
    {
        m_pm->DoCase(_T("caseParentIPSaved"));
    }

    return true;
}

bool CCascadeCfgLogic::OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        TRegServerInfo tCasRegServerInfo;
        CSipToolComInterface->GetCasRegServerBackInfo(tCasRegServerInfo);
        m_cstrParentIP = tCasRegServerInfo.m_achIpAddr;
        if ( _tcscmp(m_cstrParentIP, _T("0.0.0.0")) == 0 )
        {
            ISipToolCommonOp::SetControlText(_T(""), m_pm ,_T("ParentIPEdt"));
        }
        else
        {
            ISipToolCommonOp::SetControlText(m_cstrParentIP, m_pm ,_T("ParentIPEdt"));
        }

        m_pm->DoCase(_T("caseParentIPSaved"));
    }

    return true;
}

bool CCascadeCfgLogic::OnSetParentIPRsp( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    //string strErr = *(string*)lparam;

    if (bSuccess)
    {
        m_pm->DoCase(_T("caseParentIPSaved"));
        SHOWTIP(_T("级联配置，保存成功！"));
    }
    else
    {
        /*CString cstrErr;
        cstrErr.Format(_T("%s"),(CA2T)strErr.c_str());
        ShowTip(cstrErr);*/
        SHOWTIP(_T("级联配置，保存失败！"));
    }

    return true;
}