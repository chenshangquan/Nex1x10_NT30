#include "stdafx.h"
#include "cascadecfglogic.h"
#include "mainframelogic.h"

template<> CCascadeCfgLogic* Singleton<CCascadeCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CCascadeCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("CasCfgSaveBtn"), OnCasCfgSaveBtnClicked)

    MSG_EDITCHANGE(_T("ParentIPEdt"), OnParentIPChanged)

    USER_MSG(UI_SIPTOOL_CONNECTED, OnSipToolConnected)
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

    //if ( !IsIpFormatRight(cstrParentIP) )
    //{
    //    //ShowTip(_T("服务器地址非法"));
    //    return false;
    //}

    CSipToolComInterface->SetParentIP( CT2A(cstrParentIP) );
    
    return true;
}

bool CCascadeCfgLogic::OnParentIPChanged(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseEnableSaveBtn"));
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
        ISipToolCommonOp::SetControlText(m_cstrParentIP, m_pm ,_T("ParentIPEdt"));

        m_pm->DoCase(_T("caseIsSaved"));
    }
    else
    {
        return false;
    }

    return true;
}

/*
bool CCascadeCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/