#include "stdafx.h"
#include "networksetuplogic.h"

template<> CNetworkSetupLogic* Singleton<CNetworkSetupLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNetworkSetupLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("MainFrame"), OnCreate)
    MSG_INIWINDOW(_T("MainFrame"), OnInit)

	MSG_CLICK(_T("exitbutton"), OnExitBtnClicked)
	MSG_CLICK(_T("minbutton"), OnMinBtnClicked)
	MSG_CLICK(_T("closebutton"), OnCloseBtnClicked)

	MSG_SELECTCHANGE(_T("CascadeCfgOpt"), OnTabCascadeCfg)
	MSG_SELECTCHANGE(_T("NeighborCfgOpt"), OnTabNeighborCfg)
	MSG_SELECTCHANGE(_T("LocalAreaNumCfgOpt"), OnTabLocalAreaNumCfg)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
APP_END_MSG_MAP()

    CNetworkSetupLogic::CNetworkSetupLogic()
{
}

CNetworkSetupLogic::~CNetworkSetupLogic()
{
}

bool CNetworkSetupLogic::OnCreate( TNotifyUI& msg )
{
    //HWND hWnd = m_pm->GetPaintWindow();
    //LONG styleValue = ::GetWindowLong(hWnd, GWL_STYLE);
    //styleValue |= (WS_EX_APPWINDOW);//�����ڿɼ�ʱ��һ�����㴰�ڷ�������������
    //styleValue &= ~(WS_EX_TOOLWINDOW); //ȥ���������������ԣ�ʹ�����������ɼ�
    //::SetWindowLong(hWnd, GWL_STYLE, styleValue);

    s32 nTop = 0;
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );
    return false;
}


bool CNetworkSetupLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());

    ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
    ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());

    return true;
}

bool CNetworkSetupLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CNetworkSetupLogic::OnExitBtnClicked(TNotifyUI& msg)
{
	ISipToolCommonOp::ShowControl( true, m_pm, _T("PageLogin") );
	ISipToolCommonOp::ShowControl( false, m_pm, _T("PageSipToolMain") );
	SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 454, 282, SWP_NOACTIVATE|SWP_NOMOVE );
	WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());

	return true;
}


bool CNetworkSetupLogic::OnMinBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindowMinsize(g_stcStrMainFrameDlg.c_str());  
    return true;
}

bool CNetworkSetupLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMainFrameDlg.c_str());  
    TerminateProcess(GetCurrentProcess(), 0); 
    return false;
}

bool CNetworkSetupLogic::OnTabCascadeCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_CascadeCfg);
	}

	return true;
}

bool CNetworkSetupLogic::OnTabNeighborCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_NeighborCfg);
	}

	return true;
}

bool CNetworkSetupLogic::OnTabLocalAreaNumCfg(TNotifyUI& msg)
{
	CTabLayoutUI *pControl = (CTabLayoutUI*)ISipToolCommonOp::FindControl( m_pm, _T("SipToolSlideTab") );
	if (pControl)
	{
		pControl->SelectItem(emTabID_LocalAreaNumCfg);
	}

	return true;
}

bool CNetworkSetupLogic::OnSipToolConnected(WPARAM wparam)
{
    bool bIsLogin = (bool)wparam;
    //int emErr = lparam;
    if (bIsLogin)
    {
        //SetTimerOutTimer(true);
        //������
        //m_pm->DoCase(_T("caseIsLogin"));

        ISipToolCommonOp::ShowControl( false, m_pm, _T("PageLogin") );
        ISipToolCommonOp::ShowControl( true, m_pm, _T("PageSipToolMain") );
        SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, 0, 0, 862, 614, SWP_NOACTIVATE|SWP_NOMOVE );
        WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());
    }
    else
    {
        m_pm->DoCase(_T("caseIsnotLogin"));
    }
    return true;
}

bool CNetworkSetupLogic::OnSipToolConnected(WPARAM wparam, LPARAM lparam, bool& bHandle)
{
    bool bIsLogin = (bool)wparam;
    //int emErr = lparam;
    if (bIsLogin)
    {
        //SetTimerOutTimer(true);
        //������
        m_pm->DoCase(_T("caseIsLogin"));

        //���ڱ��
        //WINDOW_MGR_PTR->HideWindow(g_stcStrLoginDlg.c_str());
        WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNetworkSetupDlg.c_str());
    }
    else
    {
        m_pm->DoCase(_T("caseIsnotLogin"));
    }
    return true;
}
