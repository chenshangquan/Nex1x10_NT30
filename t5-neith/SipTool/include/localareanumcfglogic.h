/** @defgroup 本地区号配置逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_LOCALAREANUMCFG_H_)
#define AFX_LOCALAREANUMCFG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLocalAreaNumCfgLogic : public CNotifyUIImpl, public Singleton<CLocalAreaNumCfgLogic> 
{
public:
	CLocalAreaNumCfgLogic();
	~CLocalAreaNumCfgLogic();

    //bool OnSaveNetWorkButClicked();
protected:
    //点击本地区号保存按钮
    bool OnLocCfgSaveBtnClicked(TNotifyUI& msg);
    //本地区号更改
    bool OnLocAreaNumChanged(TNotifyUI& msg);

    //登陆连接响应
    bool OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle );
    //设置本地区号回复消息响应
    bool OnSetLocalAreaCodeRsp( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //bool OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CString m_cstrAreaCode;      //本地区号
};

#endif // !defined(AFX_LOCALAREANUMCFG_H_)