#include "stdafx.h"
#include "messageboxlogic.h"

APP_BEGIN_MSG_MAP(CMessageBoxLogic, CNotifyUIImpl)
    MSG_CREATEWINDOW(_T("MessageBoxLayout"), OnCreate)
    MSG_INIWINDOW(_T("MessageBoxLayout"), OnInit)
    MSG_WINDOWDESTORY(_T("MessageBoxLayout"), OnDestroy)

    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnOKBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCancelBtnClicked)

    USER_MSG(UI_SIPTOOL_DISCONNECTED , OnSipToolDisconnected)
APP_END_MSG_MAP()

static u8       m_byBoxType = 0;//0 普通弹窗

static CString  m_strText = _T("");  //窗口提示信息
static u8       m_byType = 0;  //按钮数目

u8 showMessageBox(LPCTSTR lpstrText, u8 byType)
{
    if (WINDOW_MGR_PTR->IsWindowMinsize(g_stcStrMainFrameDlg.c_str()))
    {
        return 0;
    }

    m_strText = lpstrText;
    m_byBoxType = 0;
    m_byType = byType;

    return WINDOW_MGR_PTR->ShowModal(g_stcStrMessageBoxDlg.c_str());
}

CMessageBoxLogic::CMessageBoxLogic()
{
}

CMessageBoxLogic::~CMessageBoxLogic()
{
}

bool CMessageBoxLogic::OnCreate( TNotifyUI& msg )
{
    RECT rcParent;
    HWND hparent = GetParent(m_pm->GetPaintWindow());
    GetWindowRect(hparent,&rcParent);
    SetWindowPos( m_pm->GetPaintWindow(), HWND_TOP, rcParent.left, rcParent.top, 0, 0, SWP_NOSIZE |SWP_NOACTIVATE );

    return false;
}


bool CMessageBoxLogic::OnInit( TNotifyUI& msg )
{
    REG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());

    if (m_byBoxType == 0)//普通弹窗
    {
        switch (m_byType)
        {
        case 0:
            m_pm->DoCase(_T("caseTypeNoBtn"));
            break;
        case 1:
            m_pm->DoCase(_T("caseTypeOneBtn"));
            break;
        case 2:
            m_pm->DoCase(_T("caseTypeTwoBtn"));
            break;
        case 3:// the third button is close button
            m_pm->DoCase(_T("caseTypeThreeBtn"));
            break;
        default:
            break;
        }
        ISipToolCommonOp::SetControlText( m_strText, m_pm, _T("LabelTip") );
    }

    return true;
}

bool CMessageBoxLogic::OnDestroy( TNotifyUI& msg )
{
    UNREG_RCKTOOL_MSG_WND_OB(m_pm->GetPaintWindow());
    return true;
}

bool CMessageBoxLogic::OnCloseBtnClicked(TNotifyUI& msg)
{  
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMessageBoxDlg.c_str(),IDNO);  
    return false;
}

bool CMessageBoxLogic::OnOKBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMessageBoxDlg.c_str(),IDOK);  
    return false;
}

bool CMessageBoxLogic::OnCancelBtnClicked(TNotifyUI& msg)
{ 
    WINDOW_MGR_PTR->CloseWindow(g_stcStrMessageBoxDlg.c_str(),IDCANCEL);  
    return false;
}

bool CMessageBoxLogic::OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    //if (wcscmp( ISipToolCommonOp::GetControlText( m_pm, _T("LabelTip") ).c_str() , _T("账号已在其他地方登录") ) != 0)
    if ( WINDOW_MGR_PTR->IsWindowVisible(g_stcStrMessageBoxDlg.c_str()) )
    {
        //关闭弹窗
        WINDOW_MGR_PTR->CloseWindow(g_stcStrMessageBoxDlg.c_str(),IDCANCEL);  
    }
    return true;
}