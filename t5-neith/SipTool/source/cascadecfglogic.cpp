#include "stdafx.h"
#include "cascadecfglogic.h"
#include "mainframelogic.h"
#include "messageboxlogic.h"

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

bool CCascadeCfgLogic::IsCfgChanged()
{
    CButtonUI *pControl = (CButtonUI*)ISipToolCommonOp::FindControl(m_pm ,_T("CasCfgSaveBtn"));
    if ( pControl && pControl->IsEnabled() )
    {
        return SaveMsgBox();
    }

    return true;
}

bool CCascadeCfgLogic::IsCfgModify()
{
    CButtonUI *pControl = (CButtonUI*)ISipToolCommonOp::FindControl(m_pm ,_T("CasCfgSaveBtn"));
    if ( pControl && pControl->IsEnabled() )
    {
        return true;
    }

    return false;
}

bool CCascadeCfgLogic::SaveMsgBox()
{
    if ( ShowMessageBox(_T("配置项已修改，是否保存配置？"), 2) == true )
    {
        TNotifyUI msg;
        return OnCasCfgSaveBtnClicked(msg);
    }
    else
    {
        //还原当前配置项
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

bool CCascadeCfgLogic::OnCasCfgSaveBtnClicked(TNotifyUI& msg)
{
    CString cstrParentIP =( ISipToolCommonOp::GetControlText(m_pm ,_T("ParentIPEdt")) ).c_str();

    if ( cstrParentIP == _T("") )
    {
        CSipToolComInterface->SetParentIP( "0.0.0.0" );
        return true;
    }

    if ( !CCallAddr::IsValidIpV4(CT2A(cstrParentIP)) )
    {
        ShowMessageBox(_T("地址输入错误"));
        return false;
    }

    CSipToolComInterface->SetParentIP( CT2A(cstrParentIP) );
    
    return true;
}

bool CCascadeCfgLogic::OnParentIPChanged(TNotifyUI& msg)
{
    CString cstrParentIP =( ISipToolCommonOp::GetControlText(m_pm ,_T("ParentIPEdt")) ).c_str();
    if ( cstrParentIP.IsEmpty() )
    {
        cstrParentIP = _T("0.0.0.0");
    }

    if (cstrParentIP != m_cstrParentIP)
    {
        m_pm->DoCase(_T("caseParentIPChanged"));
    }
    else
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
        CString cstrParentIP =( ISipToolCommonOp::GetControlText(m_pm ,_T("ParentIPEdt")) ).c_str();
        if ( cstrParentIP.IsEmpty() )
        {
            cstrParentIP = _T("0.0.0.0");
        }
        m_cstrParentIP = cstrParentIP;

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