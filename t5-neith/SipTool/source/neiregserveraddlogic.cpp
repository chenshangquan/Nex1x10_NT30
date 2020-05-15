#include "stdafx.h"
#include "neiregserveraddlogic.h"
#include "neighborcfglogic.h"
#include "mainframelogic.h"

#define TIMER_LENGTH  3000
#define TIMER_SHOWTIP 202

//template<> CNeiRegServerAddLogic* Singleton<CNeiRegServerAddLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeiRegServerAddLogic, CNotifyUIImpl)
    //MSG_CREATEWINDOW(_T("NeiRegServerAddLayout"), OnCreate)
    MSG_INIWINDOW(_T("NeiRegServerAddLayout"), OnInit)
    MSG_WINDOWDESTORY(_T("NeiRegServerAddLayout"), OnDestroy)

    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnConfirmBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCancelBtnClicked)

	MSG_TIMER(_T("ShowNeiAddTipLab"), OnShowTipTimer)  

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
    WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDNO);
    return true;
}

bool CNeiRegServerAddLogic::OnConfirmBtnClicked(TNotifyUI& msg)
{
    memset(&m_tNeiRegServerInfo, 0, sizeof(TNeiRegServerInfo));
    CString strAreaNum = ( ISipToolCommonOp::GetControlText( m_pm ,_T("AreaNumEdt")) ).c_str();
    CString strIpAddr = ( ISipToolCommonOp::GetControlText( m_pm ,_T("IpAddrEdt")) ).c_str();
    CString strPort = ( ISipToolCommonOp::GetControlText( m_pm ,_T("PortEdt")) ).c_str();

    if (strAreaNum.IsEmpty())
    {
        ShowTip(_T("区号不能为空"));
        return false;
    }
    if (strAreaNum.GetLength() < 3)
    {
        ShowTip(_T("区号长度错误"));
        return false;
    }

    if (strIpAddr.IsEmpty())
    {
        ShowTip(_T("IP地址不能为空"));
        return false;
    }
    if ( !CCallAddr::IsValidIpV4(CT2A(strIpAddr)) )
    {
        ShowTip(_T("地址输入错误"));
        return false;
    }

    if (strPort.IsEmpty())
    {
        ShowTip(_T("端口不能为空"));
        return false;
    }
    if (_ttoi(strPort) < 1024 || _ttoi(strPort) > 65535)
    {
        ShowTip(_T("端口有效范围：1024~65535"));
        return false;
    }

    memcpy(m_tNeiRegServerInfo.m_achAreaCode, (CT2A)strAreaNum, MAX_AREACODE_LENGTH);
    memcpy(m_tNeiRegServerInfo.m_achIpAddr, (CT2A)strIpAddr, MAX_IP_LENGTH);
    m_tNeiRegServerInfo.m_wPort = _ttoi(strPort);

    //区号不能重复
    if ( !CNeighborCfgLogic::GetSingletonPtr()->AreaCodeIsExist(m_tNeiRegServerInfo) )
    {
        ShowTip(_T("区号不能重复，请修改"));
        return false;
    }

    m_bAddNeiRegServerInfo = true;
    CSipToolComInterface->SetNeighborInfo(m_tNeiRegServerInfo);

    return true;
}

bool CNeiRegServerAddLogic::OnCancelBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDCANCEL);
    return true;
}

bool CNeiRegServerAddLogic::OnSetNeighborInfoRsp( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    //string strErr = *(string*)lparam;

    if (bSuccess)
    {
        if (m_bAddNeiRegServerInfo)
        {
            CNeighborCfgLogic::GetSingletonPtr()->NeiRegServerItemAdd(m_tNeiRegServerInfo);
            m_bAddNeiRegServerInfo = false;
            WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDOK);
        }
        SHOWTIP(_T("邻居信息添加成功！"));
    }
    else
    {
        /*CString cstrErr;
        cstrErr.Format(_T("%s"),(CA2T)strErr.c_str());
        ShowTip(cstrErr);*/
        ShowTip(_T("保存失败！"));
        m_bAddNeiRegServerInfo = false;
    }

    return true;
}

bool CNeiRegServerAddLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
	if ( WINDOW_MGR_PTR->IsWindowVisible(g_stcStrNeiRegServerAddDlg.c_str()) )
	{
		WINDOW_MGR_PTR->CloseWindow(g_stcStrNeiRegServerAddDlg.c_str(), IDNO);
	}

	return true;
}

bool CNeiRegServerAddLogic::OnShowTipTimer(TNotifyUI& msg)
{
	m_pm->DoCase(_T("caseNeiAddClsTip"));
	m_pm->KillTimer(msg.pSender, TIMER_SHOWTIP);
	return true;
}

void CNeiRegServerAddLogic::ShowTip(CString strTip)
{
	m_pm->DoCase(_T("caseNeiAddShwTip"));
	CLabelUI *pControl = (CLabelUI*)ISipToolCommonOp::FindControl( m_pm, _T("ShowNeiAddTipLab") );
	if (pControl)
	{
		pControl->SetText(strTip);
		m_pm->KillTimer(pControl, TIMER_SHOWTIP);
		m_pm->SetTimer(pControl, TIMER_SHOWTIP, TIMER_LENGTH);
	}
}
