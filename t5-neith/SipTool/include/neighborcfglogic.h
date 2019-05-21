/** @defgroup 级联配置逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_NEIGHBORCFG_H_)
#define AFX_NEIGHBORCFG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNeighborCfgLogic : public CNotifyUIImpl, public Singleton<CNeighborCfgLogic> 
{
public:
	CNeighborCfgLogic();
	~CNeighborCfgLogic();

    bool NeiRegServerItemAdd();
protected:
    //点击添加按钮
    bool OnNeighborCfgAddBtnClicked(TNotifyUI& msg);

    //bool OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //bool OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CListUI* m_pNeiRegServerList;
};

#endif // !defined(AFX_NEIGHBORCFG_H_)