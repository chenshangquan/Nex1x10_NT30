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
    if ( cstrLocalAreaCode.GetLength() < 3 )
    {
        SHOWTIP(_T("区号只能输入3~5位数字"));
        return false;
    }

    CSipToolComInterface->SetLocalAreaCode( CT2A(cstrLocalAreaCode) );

    return true;
}

bool CLocalAreaNumCfgLogic::OnLocAreaNumChanged(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseAreaCodeChanged"));

    CString cstrLocalAreaCode =( ISipToolCommonOp::GetControlText(m_pm ,_T("LocalAreaCodeEdt")) ).c_str();
    if ( cstrLocalAreaCode.GetLength() < 3 )
    {
        m_pm->DoCase(_T("caseAreaCodeSaved"));
    }

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
        if ( _tcscmp(m_cstrAreaCode, _T("0")) == 0 )
        {
            ISipToolCommonOp::SetControlText(_T(""), m_pm ,_T("LocalAreaCodeEdt"));
        }
        else
        {
            ISipToolCommonOp::SetControlText(m_cstrAreaCode, m_pm ,_T("LocalAreaCodeEdt"));
        }

        m_pm->DoCase(_T("caseAreaCodeSaved"));
    }

    return true;
}

bool CLocalAreaNumCfgLogic::OnSetLocalAreaCodeRsp( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    //string strErr = *(string*)lparam;

    if (bSuccess)
    {
        m_pm->DoCase(_T("caseAreaCodeSaved"));
        SHOWTIP(_T("本地区号配置，保存成功！"));
    }
    else
    {
        /*CString cstrErr;
        cstrErr.Format(_T("%s"),(CA2T)strErr.c_str());
        ShowTip(cstrErr);*/
        SHOWTIP(_T("本地区号配置，保存失败！"));
    }

    return true;
}