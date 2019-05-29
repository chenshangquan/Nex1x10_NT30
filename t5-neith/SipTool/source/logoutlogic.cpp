#include "stdafx.h"
#include "logoutlogic.h"
#include "mainframelogic.h"

APP_BEGIN_MSG_MAP(CLogoutLogic, CNotifyUIImpl)
    //MSG_CREATEWINDOW(_T("LogoutLayout"), OnCreate)
    MSG_INIWINDOW(_T("LogoutLayout"), OnInit)
    MSG_WINDOWDESTORY(_T("LogoutLayout"), OnDestroy)

    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnConfirmBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCancelBtnClicked)

    //USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
    //USER_MSG(UI_RKC_DISCONNECTED , OnSipToolDisconnected)
APP_END_MSG_MAP()

CLogoutLogic::CLogoutLogic()
{
}

CLogoutLogic::~CLogoutLogic()
{
}

bool CLogoutLogic::OnCreate( TNotifyUI& msg )
{
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );

    /*HWND hWnd = m_pm->GetPaintWindow();
    LONG styleValue = ::GetWindowLong(hWnd, GWL_STYLE);
    styleValue &= ~(WS_EX_APPWINDOW);
    ::SetWindowLong(hWnd, GWL_STYLE, styleValue);*/

    return false;
}

bool CLogoutLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CLogoutLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CLogoutLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    //WINDOW_MGR_PTR->CloseWindow(g_stcStrLogoutDlg.c_str(), IDNO);
    WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
    WINDOW_MGR_PTR->CloseWindow(g_stcStrLogoutDlg.c_str(), IDNO);
    return false;
}

bool CLogoutLogic::OnConfirmBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
    WINDOW_MGR_PTR->CloseWindow(g_stcStrLogoutDlg.c_str(), IDOK);
    NOTIFY_MSG( UI_SIPTOOL_LOGOUT, 0 , 0 );

    return true;
}

bool CLogoutLogic::OnCancelBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
    WINDOW_MGR_PTR->CloseWindow(g_stcStrLogoutDlg.c_str(), IDCANCEL);

    return true;
}

/*
bool CLogoutLogic::OnShowTipTimer(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseCloseTip"));
    m_pm->KillTimer(msg.pSender, TIMER_SHOWTIP);
    return true;
}

bool CLogoutLogic::OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    m_pm->DoCase(_T("caseNormal"));

    bool bIsLogin = (bool)wparam;
    if (bIsLogin == false )
    {
        ShowTip(_T("连接到主机失败"));
    }
    else
    {
        
    }
    return true;
}

bool CLogoutLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    m_pm->DoCase(_T("caseNormal"));
    return true;
}

void CLogoutLogic::ShowTip(CString strTip)
{
    m_pm->DoCase(_T("caseShowTip"));
    CLabelUI *pControl = (CLabelUI*)ISipToolCommonOp::FindControl( m_pm, _T("LoginTipLeb") );
    if (pControl)
    {
        pControl->SetText(strTip);
        m_pm->KillTimer(pControl, TIMER_SHOWTIP);
        m_pm->SetTimer(pControl, TIMER_SHOWTIP, TIMER_LENGTH);
    }
}*/

