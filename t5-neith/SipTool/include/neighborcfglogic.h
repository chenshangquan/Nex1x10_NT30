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

    bool NeiRegServerItemAdd(TNeiRegServerInfo& tNeiRegServerInfo);
    //查找是否存在相同的区号
    bool AreaCodeIsExist(TNeiRegServerInfo& tNeiRegServerInfo);
protected:
    //点击添加按钮
    bool OnNeighborCfgAddBtnClicked(TNotifyUI& msg);
    //点击删除按钮
    bool OnNeighborCfgDelBtnClicked(TNotifyUI& msg);

    //更新邻居信息列表
    bool OnUpdateNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle );
    //更新邻居信息列表
    bool OnDeleteNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle );

    bool OnSipDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CListUI* m_pNeiRegServerList;
    TNeiRegServerInfo m_tNeiRegServerInfoAdd;    //待添加的邻居信息
};

#endif // !defined(AFX_NEIGHBORCFG_H_)