#include "stdafx.h"
#include "neiregserveraddlogic.h"
#include "neighborcfglogic.h"
#include "mainframelogic.h"

#define TIMER_LENGTH  4000
#define TIMER_SHOWTIP 200

//template<> CNeiRegServerAddLogic* Singleton<CNeiRegServerAddLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeiRegServerAddLogic, CNotifyUIImpl)
    //MSG_CREATEWINDOW(_T("NeiRegServerAddLayout"), OnCreate)
    MSG_INIWINDOW(_T("NeiRegServerAddLayout"), OnInit)
    MSG_WINDOWDESTORY(_T("NeiRegServerAddLayout"), OnDestroy)

    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnConfirmBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCancelBtnClicked)

	MSG_TIMER(_T("ShowTipLab"), OnShowTipTimer)  

    USER_MSG(UI_SIPTOOL_SETNEIGHBORINFORSP , OnSetNeighborInfoRsp)
    USER_MSG(UI_SIPTOOL_DISCONNECTED , OnSipToolDisconnected)

APP_END_MSG_MAP()

CNeiRegServerAddLogic::CNeiRegServerAddLogic()
{
    m_bAddNeiRegServerInfo = false;
}

CNeiRegServerAddLogic::~CNeiRegServerAddLogic()
{
}

bool CNeiRegServerAddLogic::OnCreate( TNotifyUI& msg )
{
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );

    return true;
}


bool CNeiRegServerAddLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CNeiRegServerAddLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CNeiRegServerAddLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    //WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
    WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDNO);
    return true;
}

bool CNeiRegServerAddLogic::OnConfirmBtnClicked(TNotifyUI& msg)
{
    memset(&m_tNeiRegServerInfo, 0, sizeof(TNeiRegServerInfo));
    CString strAreaNum = ( ISipToolCommonOp::GetControlText( m_pm ,_T("AreaNumEdt")) ).c_str();
    CString strIpAddr = ( ISipToolCommonOp::GetControlText( m_pm ,_T("IpAddrEdt")) ).c_str();
    CString strPort = ( ISipToolCommonOp::GetControlText( m_pm ,_T("PortEdt")) ).c_str();
    if( !CMainFrameLogic::IsIpFormatRight(strIpAddr) )
    {
        ShowTip(_T("IP地址非法"));
        return false;
    }
    if (strAreaNum.IsEmpty())
    {
        ShowTip(_T("请输入区号"));
        return false;
    }
    if(strPort.IsEmpty())
    {
        ShowTip(_T("请输入端口"));
        return false;
    }

    memcpy(m_tNeiRegServerInfo.m_achAreaCode, (CT2A)strAreaNum, MAX_AREACODE_LENGTH);
    memcpy(m_tNeiRegServerInfo.m_achIpAddr, (CT2A)strIpAddr, MAX_IP_LENGTH);
    m_tNeiRegServerInfo.m_wPort = _ttoi(strPort);

    m_bAddNeiRegServerInfo = true;
    CSipToolComInterface->SetNeighborInfo(m_tNeiRegServerInfo);

    return true;
}

bool CNeiRegServerAddLogic::OnCancelBtnClicked(TNotifyUI& msg)
{
    //WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
    WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDCANCEL);
    return true;
}

bool CNeiRegServerAddLogic::OnSetNeighborInfoRsp( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        if (m_bAddNeiRegServerInfo)
        {
            CNeighborCfgLogic::GetSingletonPtr()->NeiRegServerItemAdd(m_tNeiRegServerInfo);
            m_bAddNeiRegServerInfo = false;
            //WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
            WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDOK);
        }
    }
    else
    {
        //添加失败
    }

    return true;
}

bool CNeiRegServerAddLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
	if ( WINDOW_MGR_PTR->IsWindowVisible(g_stcStrNeiRegServerAddDlg.c_str()) )
	{
		//WINDOW_MGR_PTR->ShowWindow(g_stcStrShadeDlg.c_str(), false);
		WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDNO);
	}

	return true;
}

bool CNeiRegServerAddLogic::OnShowTipTimer(TNotifyUI& msg)
{
	m_pm->DoCase(_T("caseClsTip"));
	m_pm->KillTimer(msg.pSender, TIMER_SHOWTIP);
	return true;
}

void CNeiRegServerAddLogic::ShowTip(CString strTip)
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