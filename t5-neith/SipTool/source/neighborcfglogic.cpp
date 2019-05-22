#include "stdafx.h"
#include "neighborcfglogic.h"

template<> CNeighborCfgLogic* Singleton<CNeighborCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeighborCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("NeiCfgAddBtn"), OnNeighborCfgAddBtnClicked)
    MSG_CLICK(_T("NeiCfgdelBtn"), OnNeighborCfgDelBtnClicked)

    //MSG_EDITCHANGE(_T("DeviceIPEdt"), OnDevIPEditTextChange)

    //USER_MSG(UI_RKC_IP_CHECK , OnRkcIPChecked)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CNeighborCfgLogic::CNeighborCfgLogic()
{
}

CNeighborCfgLogic::~CNeighborCfgLogic()
{
}

bool CNeighborCfgLogic::NeiRegServerItemAdd(TNeiRegServerInfo& tNeiRegServerInfo)
{
    m_pNeiRegServerList = (CListUI*)ISipToolCommonOp::FindControl( m_pm, _T("NeiRegServerList") );
    //CListContainerElementUI *pListContainer = (CListContainerElementUI*)CONTROLFACTORY()->GetControl( _T("PeripheralListItem") );
#if 0
    CString str;
    // 添加List列表内容，必须先Add(pListElement)，再SetText
    for (int i = 0; i < 50; i++)
    {
        CListTextElementUI* pListElement = new CListTextElementUI;
        pListElement->SetTag(i);
        m_pNeiRegServerList->Add(pListElement);

        str.Format(_T("%d"), i);
        pListElement->SetText(0, str);
        pListElement->SetText(1, _T("haha"));
        pListElement->SetText(2, _T("xixi"));
        pListElement->SetText(3, _T("hehe"));
    }
#else
    s32 nCount = m_pNeiRegServerList->GetCount();

    CString str;
    CListTextElementUI* pListElement = new CListTextElementUI;
    pListElement->SetTag(nCount);
    m_pNeiRegServerList->Add(pListElement);

    str.Format(_T("%d"), nCount);
    pListElement->SetText(0, str);
    pListElement->SetText(1, (CA2T)tNeiRegServerInfo.m_achAreaNum);
    pListElement->SetText(2, (CA2T)tNeiRegServerInfo.m_achIpAddr);
    str.Format(_T("%d"), tNeiRegServerInfo.m_wPort);
    pListElement->SetText(3, str);

#endif

    return true;
}

bool CNeighborCfgLogic::OnNeighborCfgAddBtnClicked(TNotifyUI& msg)
{
    //NeiRegServerItemAdd();
    WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNeiRegServerAddDlg.c_str());

    return true;
}

bool CNeighborCfgLogic::OnNeighborCfgDelBtnClicked(TNotifyUI& msg)
{
    CString str;
    s32 nCurSel = m_pNeiRegServerList->GetCurSel();
    m_pNeiRegServerList->RemoveAt(nCurSel);

    //更新序号
    for (s32 nIndex = nCurSel; nIndex < m_pNeiRegServerList->GetCount(); nIndex++)
    {
        CListTextElementUI* pListElement = (CListTextElementUI*)m_pNeiRegServerList->GetItemAt(nIndex);
        str.Format(_T("%d"), nIndex);
        pListElement->SetText(0, str);
    }

    return true;
}

/*
bool CNeighborCfgLogic::OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        m_pm->DoCase(_T("caseIPCheckOK"));
    }
    else
    {

    }
    return true;
}

bool CNeighborCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/