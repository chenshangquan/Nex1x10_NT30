#include "stdafx.h"
#include "loginlogic.h"
#include "mainframelogic.h"

#define TIMER_LENGTH  4000
#define TIMER_SHOWTIP 200
#define TIMER_CONNECT_TIMEOUT  5000
#define TIMER_CONNECT  195

static UINT g_nTimerConnectTimeout = 0;  //5s检测登陆认证是否超时

template<> CLoginLogic* Singleton<CLoginLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CLoginLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("login"), OnCreate)
    MSG_INIWINDOW(_T("login"), OnInit)
    MSG_WINDOWDESTORY(_T("login"), OnDestroy)

    MSG_CLICK(_T("minbtn"), OnMinBtnClicked)
    MSG_CLICK(_T("closebtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("LoginBtn"), OnLoginBtnClicked)

    MSG_TIMER(_T("LoginBtn"), OnConnectTimeoutTimer)
    MSG_TIMER(_T("LoginTipLab"), OnShowTipTimer)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnSipToolConnected)
	USER_MSG(UI_SIPTOOL_DISCONNECTED, OnSipToolDisconnected)
    USER_MSG(UI_SIPTOOL_FORCELOGOUTNTY, OnForceLogoutNty)
APP_END_MSG_MAP()

CLoginLogic::CLoginLogic()
{
    m_bLogin = false;
    m_bForceLogout = false;
}

CLoginLogic::~CLoginLogic()
{
}

void CLoginLogic::InitLoginWindow()
{
    //配置文件里恢复上一次登录的信息
    CString strIniPath = GetIniFilePath();
    TCHAR tchLoginIP[MAX_NAME_LEN] = {0};
    TCHAR tchUserName[MAX_NAME_LEN] = {0};
    TCHAR tchPassWord[MAX_NAME_LEN] = {0};
    GetPrivateProfileString(_T("LoginInfo"),_T("LoginIP"),_T(""), tchLoginIP, MAX_NAME_LEN-1, strIniPath);
    GetPrivateProfileString(_T("LoginInfo"),_T("UserName"),_T(""), tchUserName, MAX_NAME_LEN-1, strIniPath);
    GetPrivateProfileString(_T("LoginInfo"), _T("PassWord"),_T(""), tchPassWord, MAX_NAME_LEN-1, strIniPath);

    ISipToolCommonOp::SetControlText(tchLoginIP, m_pm, _T("edtIP"));
    ISipToolCommonOp::SetControlText(tchUserName, m_pm, _T("edtUserName"));
    ISipToolCommonOp::SetControlText(tchPassWord, m_pm, _T("edtPassWord"));
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

    if( !CCallAddr::IsValidIpV4(CT2A(strIP)) )
    {
        ShowTip(_T("地址输入错误"));
        return false;
    }
    if (strUserName.IsEmpty())
    {
        ShowTip(_T("请输入账号、密码"));
        return false;
    }
    if(strPassWord.IsEmpty())
    {
        ShowTip(_T("请输入账号、密码"));
        return false;
    }

    u32 dwIp = ntohl( inet_addr( CT2A(strIP) ) );
    m_pm->DoCase(_T("caseIsLogining"));
    CSipToolComInterface->SocketConnect( dwIp, CT2A(strUserName), CT2A(strPassWord));

    //5s 认证消息无响应
    CButtonUI *pControl = (CButtonUI*)ISipToolCommonOp::FindControl( m_pm, _T("LoginBtn") );
    if (pControl)
    {
        m_pm->KillTimer(pControl, TIMER_CONNECT);
        g_nTimerConnectTimeout = m_pm->SetTimer(pControl, TIMER_CONNECT, TIMER_CONNECT_TIMEOUT);
    }

    return true;
}

bool CLoginLogic::OnConnectTimeoutTimer(TNotifyUI& msg)
{
    m_pm->KillTimer(msg.pSender, TIMER_CONNECT);
    g_nTimerConnectTimeout = 0;
    if ( !m_bLogin )
    {
        //CloseLink
        CSipToolComInterface->CloseLink();
        m_pm->DoCase(_T("caseNormal"));
        ShowTip(_T("连接消息未响应：已断开OSP连接"));
    }

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
            ShowTip(_T("未连接到服务器"));
        }
        else
        {
            ShowTip(_T("账号与密码不匹配"));
        }
    }
    else
    {
        m_bLogin = true;
        CString strIniPath = GetIniFilePath();

        TLoginInfo tLoginInfo;
        CSipToolComInterface->GetLoginInfo(tLoginInfo);
        in_addr tAddrIP;
        tAddrIP.S_un.S_addr = htonl(tLoginInfo.m_dwIp);
        CString strLoginIP = (CA2T)inet_ntoa(tAddrIP);
        CString strUserName = (ISipToolCommonOp::GetControlText( m_pm ,_T("edtUserName"))).c_str();
        CString strPassWord = (ISipToolCommonOp::GetControlText( m_pm ,_T("edtPassWord"))).c_str();
        WritePrivateProfileString(_T("LoginInfo"), _T("LoginIP"), strLoginIP, strIniPath);
        WritePrivateProfileString(_T("LoginInfo"), _T("UserName"), strUserName, strIniPath);
        WritePrivateProfileString(_T("LoginInfo"), _T("Password"), strPassWord, strIniPath);
    }
    return true;
}

bool CLoginLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    if ( !m_bLogin )
    {
        return true;
    }

    if (g_nTimerConnectTimeout != 0)
    {
        CButtonUI *pControl = (CButtonUI*)ISipToolCommonOp::FindControl( m_pm, _T("LoginBtn") );
        if (pControl)
        {
            m_pm->KillTimer(pControl, TIMER_CONNECT);
        }
    }

    m_pm->DoCase(_T("caseNormal"));
    if (m_bForceLogout)
    {
        CString strShowTip = _T("");
        string strForceIP;
        CSipToolComInterface->GetForceIP(strForceIP);
        strShowTip.Format( _T("您已被[%s]强制下线，该账户已在另一个地方登录"), (CA2T)strForceIP.c_str() );
        ShowTip(strShowTip);
    }
    else
    {
        ShowTip(_T("已与服务器断开连接"));
    }

    m_bLogin = false;
    m_bForceLogout = false;
    return true;
}

bool CLoginLogic::OnForceLogoutNty( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    if (g_nTimerConnectTimeout != 0)
    {
        CButtonUI *pControl = (CButtonUI*)ISipToolCommonOp::FindControl( m_pm, _T("LoginBtn") );
        if (pControl)
        {
            m_pm->KillTimer(pControl, TIMER_CONNECT);
        }
    }

    m_bForceLogout = true;
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
}

