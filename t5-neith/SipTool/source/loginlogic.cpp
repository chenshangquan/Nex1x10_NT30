#include "stdafx.h"
#include "loginlogic.h"
#include "mainframelogic.h"

#define TIMER_LENGTH  4000
#define TIMER_SHOWTIP 200

APP_BEGIN_MSG_MAP(CLoginLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("login"), OnCreate)
    MSG_INIWINDOW(_T("login"), OnInit)
    MSG_WINDOWDESTORY(_T("login"), OnDestroy)

    MSG_CLICK(_T("minbtn"), OnMinBtnClicked)
    MSG_CLICK(_T("closebtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("LoginBtn"), OnLoginBtnClicked)

    //MSG_SELECTCHANGE(_T("CheckAutoLogin"), OnCheckAutoLoginSel)
    //MSG_SELECTCHANGE(_T("CheckRemPassWord"), OnCheckRemPassWordSel)

    MSG_TIMER(_T("LoginTipLab"), OnShowTipTimer)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
    //USER_MSG(UI_RKC_DISCONNECTED , OnSipToolDisconnected)
APP_END_MSG_MAP()

CLoginLogic::CLoginLogic()
{
}

CLoginLogic::~CLoginLogic()
{
}

bool CLoginLogic::OnCreate( TNotifyUI& msg )
{
    s32 nTop = 0;
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );

    HWND hWnd = m_pm->GetPaintWindow();
    LONG styleValue = ::GetWindowLong(hWnd, GWL_STYLE);
    styleValue &= ~(WS_EX_APPWINDOW);
    ::SetWindowLong(hWnd, GWL_STYLE, styleValue);

    return false;
}


bool CLoginLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CLoginLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CLoginLogic::OnMinBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindowMinsize(g_stcStrMainFrameDlg.c_str());
    return true;
}

bool CLoginLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMainFrameDlg.c_str());
    TerminateProcess(GetCurrentProcess(), 0);
    return false;
}

bool CLoginLogic::OnLoginBtnClicked(TNotifyUI& msg)
{
    CString strIP =(ISipToolCommonOp::GetControlText( m_pm ,_T("edtIP"))).c_str();
    CString strUserName = (ISipToolCommonOp::GetControlText( m_pm ,_T("edtUserName"))).c_str();
    CString strPassWord = (ISipToolCommonOp::GetControlText( m_pm ,_T("edtPassWord"))).c_str();

    if( !CMainFrameLogic::IsIpFormatRight(strIP) )
    {
        ShowTip(_T("·þÎñÆ÷µØÖ··Ç·¨"));
        return false;
    }
    if (strUserName.IsEmpty())
    {
        ShowTip(_T("ÇëÊäÈëÕËºÅ¡¢ÃÜÂë"));
        return false;
    }
    if(strPassWord.IsEmpty())
    {
        ShowTip(_T("ÇëÊäÈëÕËºÅ¡¢ÃÜÂë"));
        return false;
    }

    u32 dwIp = ntohl( inet_addr( CT2A(strIP) ) );
    m_pm->DoCase(_T("caseIsLogining"));
    CSipToolComInterface->SocketConnect( dwIp, CT2A(strUserName), CT2A(strPassWord));

    //CMainFrameLogic::GetSingletonPtr()->OnSipToolConnected(1);
    return true;
}

bool CLoginLogic::OnShowTipTimer(TNotifyUI& msg)
{
    m_pm->DoCase(_T("caseCloseTip"));
    m_pm->KillTimer(msg.pSender, TIMER_SHOWTIP);
    return true;
}

bool CLoginLogic::OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    m_pm->DoCase(_T("caseNormal"));

    bool bIsLogin = (bool)wparam;
    if (bIsLogin == false )
    {
        if ( ERR_SIPTOOL_TCPCONNECT == (EmErrSipToolLib)lparam )
        {
            ShowTip(_T("Î´Á¬½Óµ½·þÎñÆ÷"));
        }
        else
        {
            ShowTip(_T("ÕËºÅÓëÃÜÂë²»Æ¥Åä"));
        }
    }
    else
    {
        
    }
    return true;
}

bool CLoginLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    m_pm->DoCase(_T("caseNormal"));
    return true;
}

void CLoginLogic::ShowTip(CString strTip)
{
    m_pm->DoCase(_T("caseShowTip"));
    CLabelUI *pControl = (CLabelUI*)ISipToolCommonOp::FindControl( m_pm, _T("LoginTipLab") );
    if (pControl)
    {
        pControl->SetText(strTip);
        m_pm->KillTimer(pControl, TIMER_SHOWTIP);
        m_pm->SetTimer(pControl, TIMER_SHOWTIP, TIMER_LENGTH);
    }
}

/*
CString CLoginLogic::GetIniFilePath()
{
    TCHAR tchPath[MAX_PATH] = {0};
    CString strIniFilePath;
    if (S_OK == SHGetFolderPathW(NULL,CSIDL_APPDATA,NULL,0,tchPath))
    {
        CString strIniFileDir(tchPath);
        strIniFileDir = strIniFileDir + _T("\\SipTool");		
        if(!PathFileExists(strIniFileDir))
        {
            CreateDirectory(strIniFileDir, NULL);
        }
        strIniFilePath = strIniFileDir + _T("\\conf.ini");
    }

    return strIniFilePath;
}*/

