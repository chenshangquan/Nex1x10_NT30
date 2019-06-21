#include "stdafx.h"
#include "neighborcfglogic.h"
#include "mainframelogic.h"
#include "messageboxlogic.h"

template<> CNeighborCfgLogic* Singleton<CNeighborCfgLogic>::ms_pSingleton  = NULL;

APP_BEGIN_MSG_MAP(CNeighborCfgLogic, CNotifyUIImpl)
    MSG_CLICK(_T("NeiCfgAddBtn"), OnNeighborCfgAddBtnClicked)
    MSG_CLICK(_T("NeiCfgdelBtn"), OnNeighborCfgDelBtnClicked)

    //MSG_EDITCHANGE(_T("DeviceIPEdt"), OnDevIPEditTextChange)

    USER_MSG(UI_SIPTOOL_CONNECTED , OnUpdateNeighborInfoList)
    USER_MSG(UI_SIPTOOL_DELETENEIGHBORINFORSP , OnDeleteNeighborInfoList)
    //USER_MSG(UI_RKC_DISCONNECTED , OnRkcDisconnected)

APP_END_MSG_MAP()

CNeighborCfgLogic::CNeighborCfgLogic()
{
    m_pNeiRegServerList = NULL;
}

CNeighborCfgLogic::~CNeighborCfgLogic()
{
}

bool CNeighborCfgLogic::NeiRegServerItemAdd(TNeiRegServerInfo& tNeiRegServerInfo)
{
    s32 nCount = m_pNeiRegServerList->GetCount();

    CString str;
    CListTextElementUI* pListElement = new CListTextElementUI;
    if (pListElement)
    {
        pListElement->SetAttribute(_T("height"),_T("24"));
        pListElement->SetAttribute(_T("gdiplus"),_T("true"));
        pListElement->SetTag(nCount);
        m_pNeiRegServerList->Add(pListElement);

        str.Format(_T("%d"), nCount+1);
        pListElement->SetText(0, str);
        pListElement->SetText(1, (CA2T)tNeiRegServerInfo.m_achAreaCode);
        pListElement->SetText(2, (CA2T)tNeiRegServerInfo.m_achIpAddr);
        str.Format(_T("%d"), tNeiRegServerInfo.m_wPort);
        pListElement->SetText(3, str);
    }

    return true;
}

bool CNeighborCfgLogic::AreaCodeIsExist(TNeiRegServerInfo& tNeiRegServerInfo)
{
    s32 nCount = m_pNeiRegServerList->GetCount();
    for (s32 nIndex = 0; nIndex < nCount; nIndex++)
    {
        CListTextElementUI* pListElement = (CListTextElementUI*)m_pNeiRegServerList->GetItemAt(nIndex);
        if ( strcmp( (CT2A)pListElement->GetText(1), tNeiRegServerInfo.m_achAreaCode ) == 0 )// 区号相同
        {
            return false;
        }
    }

    return true;
}

bool CNeighborCfgLogic::OnNeighborCfgAddBtnClicked(TNotifyUI& msg)
{
    //CMainFrameLogic::GetSingletonPtr()->OnShowShadeWindow();
    WINDOW_MGR_PTR->ShowModal(g_stcStrNeiRegServerAddDlg.c_str());

    return true;
}

bool CNeighborCfgLogic::OnNeighborCfgDelBtnClicked(TNotifyUI& msg)
{
    if ( ShowMessageBox(_T("是否删除？"), 2) == true )
    {
        s32 nCurSel = m_pNeiRegServerList->GetCurSel();
        CListTextElementUI* pCurListElement = (CListTextElementUI*)m_pNeiRegServerList->GetItemAt(nCurSel);
        CString cstrAreaNum(pCurListElement->GetText(1));
        CSipToolComInterface->DeleteNeighborInfo( (CT2A)cstrAreaNum );
    }

    return true;
}

bool CNeighborCfgLogic::OnUpdateNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    vector<TNeiRegServerInfo> vNeighborInfo;

    if (bSuccess)
    {
        m_pNeiRegServerList = (CListUI*)ISipToolCommonOp::FindControl( m_pm, _T("NeiRegServerList") );
        m_pNeiRegServerList->RemoveAll();
        CSipToolComInterface->GetNeighborBackInfo(vNeighborInfo);
        u32 dwNeighborInfoSize = vNeighborInfo.size();

        CString str;
        for (u32 dwIndex = 0; dwIndex < dwNeighborInfoSize; dwIndex++)
        {
            CListTextElementUI* pListElement = new CListTextElementUI;
            if (pListElement)
            {
                pListElement->SetAttribute(_T("height"),_T("24"));
                pListElement->SetAttribute(_T("gdiplus"),_T("true"));
                pListElement->SetTag(dwIndex);
                m_pNeiRegServerList->Add(pListElement);

                str.Format(_T("%d"), dwIndex+1);
                pListElement->SetText(0, str);
                pListElement->SetText(1, (CA2T)vNeighborInfo[dwIndex].m_achAreaCode);
                pListElement->SetText(2, (CA2T)vNeighborInfo[dwIndex].m_achIpAddr);
                str.Format(_T("%d"), vNeighborInfo[dwIndex].m_wPort);
                pListElement->SetText(3, str);
            }

            //::delete pListElement;
            //pListElement = NULL;
        }  
    }

    return true;
}

bool CNeighborCfgLogic::OnDeleteNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    bool bSuccess = (bool)wparam;
    if (bSuccess)
    {
        CString strSerial;
        s32 nCurSel = m_pNeiRegServerList->GetCurSel();
        m_pNeiRegServerList->RemoveAt(nCurSel);

        //更新序号
        for (s32 nIndex = nCurSel; nIndex < m_pNeiRegServerList->GetCount(); nIndex++)
        {
            CListTextElementUI* pListElement = (CListTextElementUI*)m_pNeiRegServerList->GetItemAt(nIndex);
            strSerial.Format(_T("%d"), nIndex+1);
            pListElement->SetText(0, strSerial);
        }

        SHOWTIP(_T("邻居信息删除成功！"));
    }

    return true;
}

/*
bool CNeighborCfgLogic::OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle )
{
    CButtonUI *pBtn = (CButtonUI*)IRkcToolCommonOp::FindControl(m_pm, _T("SaveNetWorkBut"));
    if (pBtn)
    {
        pBtn->SetFocus();
    }
    return true;
}*/