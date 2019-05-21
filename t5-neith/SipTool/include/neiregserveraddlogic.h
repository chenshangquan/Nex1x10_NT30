/** @defgroup 邻居regserver添加逻辑单元 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_NEIREGSERVERADD_H_)
#define AFX_NEIREGSERVERADD_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNeiRegServerAddLogic : public CNotifyUIImpl, public Singleton<CNeiRegServerAddLogic> 
{
public:
	CNeiRegServerAddLogic();
	~CNeiRegServerAddLogic();

    //bool OnSaveNetWorkButClicked();
protected:
    //点击关闭按钮
    bool OnCloseBtnClicked(TNotifyUI& msg);
    //点击确认按钮
    bool OnConfirmBtnClicked(TNotifyUI& msg);
    //点击取消按钮
    bool OnCancelBtnClicked(TNotifyUI& msg);

    //bool OnRkcIPChecked( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:

};

#endif // !defined(AFX_NEIREGSERVERADD_H_)