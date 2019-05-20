#include "stdafx.h"
#include "localareanumcfglogic.h"
#include "mainframelogic.h"

template<> CLocalAreaNumCfgLogic* Singleton<CLocalAreaNumCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CLocalAreaNumCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("LocCfgSaveBtn"), OnLocCfgSaveBtnClicked)

    //MSG_EDITCHANGE(_T("DeviceIPEdt"), OnDevIPEditTextChange)

    //USER_MSG(UI_RKC_IP_CHECK , OnRkcIPChecked)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CLocalAreaNumCfgLogic::CLocalAreaNumCfgLogic()
{
}

CLocalAreaNumCfgLogic::~CLocalAreaNumCfgLogic()
{
}

bool CLocalAreaNumCfgLogic::OnLocCfgSaveBtnClicked(TNotifyUI& msg)
{
    return true;
}

/*
bool CLocalAreaNumCfgLogic::OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        m_pm->DoCase(_T("caseIPCheckOK"));
    }
    else
    {

    }
    return true;
}

bool CLocalAreaNumCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/