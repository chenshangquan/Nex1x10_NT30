/** @defgroup 注销逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_LOGOUTLOGIC_H_)
#define AFX_LOGOUTLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLogoutLogic : public CNotifyUIImpl
{
public:
	CLogoutLogic();
	~CLogoutLogic();

protected:
	/** 窗口创建 
	*  @param[in] 消息
	*  @return 是否成功
	*/
	bool OnCreate(TNotifyUI& msg);

	/** 初始化消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
     */
    bool OnInit(TNotifyUI& msg);

    /** 关闭消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
     */
    bool OnDestroy(TNotifyUI& msg);

    //点击关闭按钮
    bool OnCloseBtnClicked(TNotifyUI& msg);
    //点击确定按钮
    bool OnConfirmBtnClicked(TNotifyUI& msg);
    //点击取消按钮
    bool OnCancelBtnClicked(TNotifyUI& msg);

    //显示提示定时器响应
    //bool OnShowTipTimer(TNotifyUI& msg);

    //bool OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    bool OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //void ShowTip(CString strTip);

    APP_DECLARE_MSG_MAP()

private:
};

#endif // !defined(AFX_LOGOUTLOGIC_H_)