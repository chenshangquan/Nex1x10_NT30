#include "stdafx.h"
#include "neiregserveraddlogic.h"
#include "neighborcfglogic.h"

template<> CNeiRegServerAddLogic* Singleton<CNeiRegServerAddLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeiRegServerAddLogic, CNotifyUIImpl)
    MSG_CLICK(_T("CloseBtn"), OnCloseBtnClicked)
    MSG_CLICK(_T("ConfirmBtn"), OnConfirmBtnClicked)
    MSG_CLICK(_T("CancelBtn"), OnCancelBtnClicked)

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
    TNeiRegServerInfo tNeiRegServerInfo;
    CString strAreaNum = ( ISipToolCommonOp::GetControlText( m_pm ,_T("AreaNumEdt")) ).c_str();
    CString strIpAddr = ( ISipToolCommonOp::GetControlText( m_pm ,_T("IpAddrEdt")) ).c_str();
    CString strPort = ( ISipToolCommonOp::GetControlText( m_pm ,_T("PortEdt")) ).c_str();
    memcpy(tNeiRegServerInfo.m_achAreaNum, (CT2A)strAreaNum, MAX_AREANUM_LENGTH);
    memcpy(tNeiRegServerInfo.m_achIpAddr, (CT2A)strIpAddr, MAX_IP_LENGTH);
    tNeiRegServerInfo.m_wPort = _ttoi(strPort);

    CNeighborCfgLogic::GetSingletonPtr()->NeiRegServerItemAdd(tNeiRegServerInfo);
    CSipToolComInterface->SetNeighborInfo(tNeiRegServerInfo);

    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);
    return true;
}

bool CNeiRegServerAddLogic::OnCancelBtnClicked(TNotifyUI& msg)
{
    WINDOW_MGR_PTR->ShowWindow(g_stcStrNeiRegServerAddDlg.c_str(), false);
    return true;
}