#include "stdafx.h"
#include "neighborcfglogic.h"

template<> CNeighborCfgLogic* Singleton<CNeighborCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeighborCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("NeiCfgAddBtn"), OnNeighborCfgAddBtnClicked)

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

bool CNeighborCfgLogic::NeiRegServerItemAdd()
{
    m_pNeiRegServerList = (CListUI*)ISipToolCommonOp::FindControl( m_pm, _T("NeiRegServerList") );
    //CListContainerElementUI *pListContainer = (CListContainerElementUI*)CONTROLFACTORY()->GetControl( _T("PeripheralListItem") );
    
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

    return true;
}

bool CNeighborCfgLogic::OnNeighborCfgAddBtnClicked(TNotifyUI& msg)
{
    NeiRegServerItemAdd();
    //WINDOW_MGR_PTR->ShowWindowCenter(g_stcStrNeiRegServerAddDlg.c_str());

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