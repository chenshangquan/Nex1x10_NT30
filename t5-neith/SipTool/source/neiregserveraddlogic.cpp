#include "stdafx.h"
#include "neiregserveraddlogic.h"
#include "neighborcfglogic.h"

template<> CNeiRegServerAddLogic* Singleton<CNeiRegServerAddLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeiRegServerAddLogic, CNotifyUIImpl)
    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCloseBtnClicked)

    //MSG_EDITCHANGE(_T("DeviceIPEdt"), OnDevIPEditTextChange)

    //USER_MSG(UI_RKC_IP_CHECK , OnRkcIPChecked)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CNeiRegServerAddLogic::CNeiRegServerAddLogic()
{
}

CNeiRegServerAddLogic::~CNeiRegServerAddLogic()
{
}

bool CNeiRegServerAddLogic::OnCloseBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);
    return true;
}

bool CNeiRegServerAddLogic::OnConfirmBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);
    return true;
}

bool CNeiRegServerAddLogic::OnCancelBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);
    return true;
}