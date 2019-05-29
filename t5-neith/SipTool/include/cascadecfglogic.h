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
    //父级IP地址更改
    bool OnParentIPChanged(TNotifyUI& msg);

    //登陆连接响应
    bool OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle );
    //设置父级IP地址响应
    bool OnSetParentIPRsp( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //bool OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CString m_cstrParentIP;     //父级IP地址
};

#endif // !defined(AFX_CASCADECFG_H_)