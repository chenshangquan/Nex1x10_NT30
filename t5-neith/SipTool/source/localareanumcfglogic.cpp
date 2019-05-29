#include "stdafx.h"
#include "localareanumcfglogic.h"
#include "mainframelogic.h"

template<> CLocalAreaNumCfgLogic* Singleton<CLocalAreaNumCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CLocalAreaNumCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("LocCfgSaveBtn"), OnLocCfgSaveBtnClicked)

    MSG_EDITCHANGE(_T("LocalAreaCodeEdt"), OnLocAreaNumChanged)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
    USER_MSG(UI_SIPTOOL_SETLOCALAREACODERSP , OnSetLocalAreaCodeRsp)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CLocalAreaNumCfgLogic::CLocalAreaNumCfgLogic()
{
    m_cstrAreaCode = _T("");
}

CLocalAreaNumCfgLogic::~CLocalAreaNumCfgLogic()
{
}

bool CLocalAreaNumCfgLogic::OnLocCfgSaveBtnClicked(TNotifyUI& msg)
{
    CString cstrLocalAreaCode =( ISipToolCommonOp::GetControlText(m_pm ,_T("LocalAreaCodeEdt")) ).c_str();
    /*if ( !IsAreaNumRight() )
    {
        ShowTip(_T("服务器地址非法"));
        return false;
    }*/

    CSipToolComInterface->SetLocalAreaCode( CT2A(cstrLocalAreaCode) );

    return true;
}

bool CLocalAreaNumCfgLogic::OnLocAreaNumChanged(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseAreaCodeChanged"));
    return true;
}

bool CLocalAreaNumCfgLogic::OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        TRegServerInfo tCasRegServerInfo;
        CSipToolComInterface->GetCasRegServerBackInfo(tCasRegServerInfo);
        m_cstrAreaCode = tCasRegServerInfo.m_achAreaCode;
        ISipToolCommonOp::SetControlText(m_cstrAreaCode, m_pm ,_T("LocalAreaCodeEdt"));

        m_pm->DoCase(_T("caseAreaCodeSaved"));
    }
    else
    {
        return false;
    }

    return true;
}

bool CLocalAreaNumCfgLogic::OnSetLocalAreaCodeRsp( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        m_pm->DoCase(_T("caseAreaCodeSaved"));
    }

    return true;
}

/*
bool CLocalAreaNumCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/