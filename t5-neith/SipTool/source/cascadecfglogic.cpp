#include "stdafx.h"
#include "cascadecfglogic.h"
#include "mainframelogic.h"

template<> CCascadeCfgLogic* Singleton<CCascadeCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CCascadeCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("CasCfgSaveBtn"), OnCasCfgSaveBtnClicked)

    //MSG_EDITCHANGE(_T("DeviceIPEdt"), OnDevIPEditTextChange)

    //USER_MSG(UI_RKC_IP_CHECK , OnRkcIPChecked)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CCascadeCfgLogic::CCascadeCfgLogic()
{
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

/*
bool CCascadeCfgLogic::OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle )
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

bool CCascadeCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/