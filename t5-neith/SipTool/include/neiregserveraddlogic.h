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

class CNeiRegServerAddLogic : public CNotifyUIImpl
{
public:
	CNeiRegServerAddLogic();
	~CNeiRegServerAddLogic();

    //bool OnSaveNetWorkButClicked();
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
    //点击确认按钮
    bool OnConfirmBtnClicked(TNotifyUI& msg);
    //点击取消按钮
    bool OnCancelBtnClicked(TNotifyUI& msg);

    //设置邻居信息回复消息响应
    bool OnSetNeighborInfoRsp( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    TNeiRegServerInfo m_tNeiRegServerInfo;    //待添加的邻居信息
    bool m_bAddNeiRegServerInfo;              //是否添加邻居信息
};

#endif // !defined(AFX_NEIREGSERVERADD_H_)