#include "stdafx.h"
#include "mainframelogic.h"
#include "messageboxlogic.h"
#include "loginlogic.h"

#define TIMER_LENGTH  3000
#define TIMER_SHOWTIP 300

template<> CMainFrameLogic* Singleton<CMainFrameLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CMainFrameLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("MainFrame"), OnCreate)
    MSG_INIWINDOW(_T("MainFrame"), OnInit)

	MSG_CLICK(_T("exitbutton"), OnExitBtnClicked)
	MSG_CLICK(_T("minbutton"), OnMinBtnClicked)
	MSG_CLICK(_T("closebutton"), OnCloseBtnClicked)

    MSG_TIMER(_T("ShowTipLab"), OnShowTipTimer)

	MSG_SELECTCHANGE(_T("CascadeCfgOpt"), OnTabCascadeCfg)
	MSG_SELECTCHANGE(_T("NeighborCfgOpt"), OnTabNeighborCfg)
	MSG_SELECTCHANGE(_T("LocalAreaNumCfgOpt"), OnTabLocalAreaNumCfg)

    USER_MSG(UI_SIPTOOL_CONNECTED, OnSipToolConnected)
    USER_MSG(UI_SIPTOOL_DISCONNECTED, OnSipToolLogout)
    USER_MSG(UI_SIPTOOL_LOGOUT, OnSipToolLogout)
APP_END_MSG_MAP()

void showtip(CString strTip)
{
    CMainFrameLogic::GetSingletonPtr()->ShowTip(strTip);
}

CMainFrameLogic::CMainFrameLogic()
{
    m_bLogin = false;
}

CMainFrameLogic::~CMainFrameLogic()
{
}

bool CMainFrameLogic::IsIpFormatRight(LPCTSTR pIpAddr)
{
    u32 dwCount = 0;
    s32 i = 0;
    u32 dwA, dwB, dwC, dwD;

    // 检查是否只包含点和数字;
    for(i = 0; pIpAddr[i] != '\0'; i++)
    {
        if (pIpAddr[i] > 256)
        {
            return false;
        }

        if(!isdigit((int)pIpAddr[i]) && pIpAddr[i] != '.')
        {
            return false;
        }
    }

    // 检查形式是否为X.X.X.X;
    for (i = 0; pIpAddr[i+1] != '\0'; i++)
    {
        if (isdigit(pIpAddr[i]) && pIpAddr[i+1] == '.')
        {
            dwCount++;
        }
    }
    if (dwCount != 3)
    {
        return false;
    }

    // IP地址"0.0.0.0" 非法
    if ( _tcscmp(pIpAddr, _T("0.0.0.0")) == 0 )
    {
        return false;
    }

    // 检查区间的合法性;
    if ((swscanf(pIpAddr, L"%d.%d.%d.%d", &dwA, &dwB, &dwC, &dwD) == 4)
        &&(dwA >= 0 && dwA <= 255)
        &&(dwB >= 0 && dwB <= 255)
        &&(dwC >= 0 && dwC <= 255)
        &&(dwD >= 0 && dwD <= 255))
    {
        return true;
    }

    return false;
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
    return true;
}


bool CMainFrameLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());

    //WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);

    ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
    ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );

    //读取配置文件，初始化登陆窗口
    CLoginLogic::GetSingletonPtr()->InitLoginWindow();

    return true;
}

bool CMainFrameLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CMainFrameLogic::OnExitBtnClicked(TNotifyUI& msg)
{
    //OnShowShadeWindow();
    if (ShowMessageBox(_T("确定退出当前登陆？"), 3) == true)
    {
        NOTIFY_MSG( UI_SIPTOOL_LOGOUT, 0 , 0 );
    }

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

bool CMainFrameLogic::OnSipToolConnected(WPARAM wparam, LPARAM lparam, bool& bHandle)
{
    bool bIsLogin = (bool)wparam;
    bool bForceLogin = (bool)lparam;
    if (bIsLogin)
    {
        m_bLogin = true;
        m_pm->DoCase(_T("caseIsLogining"));

        //界面变更
        ISipToolCommonOp::ShowControl( false, m_pm, _T("PageLogin") );
        ISipToolCommonOp::ShowControl( true, m_pm, _T("PageSipToolMain") );
        SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 864, 614, SWP_NOACTIVATE|SWP_NOMOVE );
        WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrMainFrameDlg.c_str());

        //默认选中级联配置
        ISipToolCommonOp::OptionSelect(true, m_pm, _T("CascadeCfgOpt"));

        if (bForceLogin)
        {
            SHOWTIP(_T("您已抢登！！"));
        }
    }
    else
    {
        m_pm->DoCase(_T("caseIsnotLogin"));
    }

    return true;
}

bool CMainFrameLogic::OnSipToolLogout(WPARAM wparam, LPARAM lparam, bool& bHandle)
{
    if ( !m_bLogin )
    {
        return true;
    }

    ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
    ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrMainFrameDlg.c_str());
    m_bLogin = false;

    CSipToolComInterface->CloseLink();

    return true;
}

/*
bool CMainFrameLogic::OnShowShadeWindow(LPCTSTR lpstrName, bool bShow)
{
    // 遮罩窗口与主窗口的位置保持一致
    Window* pAppWindow = WINDOW_MGR_PTR->GetWindow(lpstrName);
    if ( pAppWindow != NULL && bShow )
    {
        RECT rcParent;
        HWND hparent = m_pm->GetPaintWindow();
        GetWindowRect(hparent,&rcParent);
        HWND hAppWind = FindWindow(NULL, g_stcStrShadeDlg.c_str());
        SetWindowPos(hAppWind, NULL, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );
    }

    WINDOW_MGR_PTR->ShowWindow(lpstrName, bShow);
    return false;
}*/

bool CMainFrameLogic::OnShowTipTimer(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseClsTip"));
    m_pm->KillTimer(msg.pSender, TIMER_SHOWTIP);
    return true;
}

void CMainFrameLogic::ShowTip(CString strTip)
{
    m_pm->DoCase(_T("caseShwTip"));
    CLabelUI *pControl = (CLabelUI*)ISipToolCommonOp::FindControl( m_pm, _T("ShowTipLab") );
    if (pControl)
    {
        pControl->SetText(strTip);
        m_pm->KillTimer(pControl, TIMER_SHOWTIP);
        m_pm->SetTimer(pControl, TIMER_SHOWTIP, TIMER_LENGTH);
    }
}