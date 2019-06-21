/** @defgroup 提示弹窗逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2019.6.13
 */
#if !defined(AFX_MESSAGEBOXLOGIC_H_)
#define AFX_MESSAGEBOXLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMessageBoxLogic : public CNotifyUIImpl
{
public:
	CMessageBoxLogic();
	~CMessageBoxLogic();

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
    bool OnOKBtnClicked(TNotifyUI& msg);
    //点击取消按钮
    bool OnCancelBtnClicked(TNotifyUI& msg);

    bool OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );
    
    APP_DECLARE_MSG_MAP()

private:
};

//0 没有按钮，1 确定按钮，2 确定 取消按钮, 3 确定 取消 关闭按钮
u8 showMessageBox(LPCTSTR lpstrText, u8 byType = 1);
#define ShowMessageBox showMessageBox

#endif // !defined(AFX_MESSAGEBOXLOGIC_H_)