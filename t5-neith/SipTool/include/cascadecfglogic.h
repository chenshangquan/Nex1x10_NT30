/** @defgroup 级联配置逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_CASCADECFG_H_)
#define AFX_CASCADECFG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCascadeCfgLogic : public CNotifyUIImpl, public Singleton<CCascadeCfgLogic> 
{
public:
	CCascadeCfgLogic();
	~CCascadeCfgLogic();

    //bool OnSaveNetWorkButClicked();
protected:
    //点击级联配置保存按钮
    bool OnCasCfgSaveBtnClicked(TNotifyUI& msg);

    //bool OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //bool OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:

};

#endif // !defined(AFX_CASCADECFG_H_)