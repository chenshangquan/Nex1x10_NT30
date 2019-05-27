#include "stdafx.h"
#include "localareanumcfglogic.h"
#include "mainframelogic.h"

template<> CLocalAreaNumCfgLogic* Singleton<CLocalAreaNumCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CLocalAreaNumCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("LocCfgSaveBtn"), OnLocCfgSaveBtnClicked)

    MSG_EDITCHANGE(_T("LocalAreaNumEdt"), OnLocAreaNumChanged)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CLocalAreaNumCfgLogic::CLocalAreaNumCfgLogic()
{
    m_cstrAreaNum = _T("");
}

CLocalAreaNumCfgLogic::~CLocalAreaNumCfgLogic()
{
}

bool CLocalAreaNumCfgLogic::OnLocCfgSaveBtnClicked(TNotifyUI& msg)
{
    return true;
}

bool CLocalAreaNumCfgLogic::OnLocAreaNumChanged(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseEnableSaveBtn"));
    return true;
}

bool CLocalAreaNumCfgLogic::OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        TRegServerInfo tCasRegServerInfo;
        CSipToolComInterface->GetCasRegServerBackInfo(tCasRegServerInfo);
        m_cstrAreaNum = tCasRegServerInfo.m_achAreaNum;
        ISipToolCommonOp::SetControlText(m_cstrAreaNum, m_pm ,_T("LocalAreaNumEdt"));

        m_pm->DoCase(_T("caseIsSaved"));
    }
    else
    {
        return false;
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