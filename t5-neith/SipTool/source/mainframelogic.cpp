#include "stdafx.h"
#include "mainframelogic.h"

template<> CMainFrameLogic* Singleton<CMainFrameLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CMainFrameLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("MainFrame"), OnCreate)
    MSG_INIWINDOW(_T("MainFrame"), OnInit)

	MSG_CLICK(_T("exitbutton"), OnExitBtnClicked)
	MSG_CLICK(_T("minbutton"), OnMinBtnClicked)
	MSG_CLICK(_T("closebutton"), OnCloseBtnClicked)

	MSG_SELECTCHANGE(_T("CascadeCfgOpt"), OnTabCascadeCfg)
	MSG_SELECTCHANGE(_T("NeighborCfgOpt"), OnTabNeighborCfg)
	MSG_SELECTCHANGE(_T("LocalAreaNumCfgOpt"), OnTabLocalAreaNumCfg)

    USER_MSG(UI_SIPTOOL_CONNECTED, OnSipToolConnected)
    USER_MSG(UI_SIPTOOL_LOGOUT, OnSipToolLogout)
APP_END_MSG_MAP()

    CMainFrameLogic::CMainFrameLogic()
{
}

CMainFrameLogic::~CMainFrameLogic()
{
}

bool CMainFrameLogic::OnCreate( TNotifyUI& msg )
{
    //HWND hWnd = m_pm->GetPaintWindow();
    //LONG styleValue = ::GetWindowLong(hWnd, GWL_STYLE);
    //styleValue |= (WS_EX_APPWINDOW);//当窗口可见时将一个顶层窗口放置在任务栏上
    //styleValue &= ~(WS_EX_TOOLWINDOW); //去掉工具栏窗口属性，使其在任务栏可见
    //::SetWindowLong(hWnd, GWL_STYLE, styleValue);

    s32 nTop = 0;
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );
    return false;
}


bool CMainFrameLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());

    WINDOW_MGR_PTR->ShowWindow(g_stcStrLogoutDlg.c_str(), false);
    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);

    ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
    ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());

    return true;
}

bool CMainFrameLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CMainFrameLogic::OnExitBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrLogoutDlg.c_str());
	return true;
}

bool CMainFrameLogic::OnMinBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindowMinsize(g_stcStrMainFrameDlg.c_str());  
    return true;
}

bool CMainFrameLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMainFrameDlg.c_str());  
    TerminateProcess(GetCurrentProcess(), 0); 
    return false;
}

bool CMainFrameLogic::OnTabCascadeCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_CascadeCfg);
	}

	return true;
}

bool CMainFrameLogic::OnTabNeighborCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_NeighborCfg);
	}

	return true;
}

bool CMainFrameLogic::OnTabLocalAreaNumCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_LocalAreaNumCfg);
	}

	return true;
}

bool CMainFrameLogic::OnSipToolConnected(WPARAM wparam)
{
    bool bIsLogin = (bool)wparam;
    //int emErr = lparam;
    if (bIsLogin)
    {
        //SetTimerOutTimer(true);
        //界面变更
        //m_pm->DoCase(_T("caseIsLogin"));

        ISipToolCommonOp::ShowControl( false, m_pm, _T("PageLogin") );
        ISipToolCommonOp::ShowControl( true, m_pm, _T("PageSipToolMain") );
        SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 864, 614, SWP_NOACTIVATE|SWP_NOMOVE );
        WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());
    }
    else
    {
        m_pm->DoCase(_T("caseIsnotLogin"));
    }
    return true;
}

bool CMainFrameLogic::OnSipToolConnected(WPARAM wparam, LPARAM lparam, bool& bHandle)
{
    bool bIsLogin = (bool)wparam;
    //int emErr = lparam;
    if (bIsLogin)
    {
        //SetTimerOutTimer(true);
        //界面变更
        m_pm->DoCase(_T("caseIsLogin"));

        //窗口变更
        //WINDOW_MGR_PTR->HideWindow(g_stcStrLoginDlg.c_str());
        WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());
    }
    else
    {
        m_pm->DoCase(_T("caseIsnotLogin"));
    }
    return true;
}

bool CMainFrameLogic::OnSipToolLogout(WPARAM wparam, LPARAM lparam, bool& bHandle)
{
    ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
    ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());

    return true;
}