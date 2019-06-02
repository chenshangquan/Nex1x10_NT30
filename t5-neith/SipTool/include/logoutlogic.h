/** @defgroup ע���߼���Ԫ 
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
	/** ���ڴ��� 
	*  @param[in] ��Ϣ
	*  @return �Ƿ�ɹ�
	*/
	bool OnCreate(TNotifyUI& msg);

	/** ��ʼ����Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
     */
    bool OnInit(TNotifyUI& msg);

    /** �ر���Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
     */
    bool OnDestroy(TNotifyUI& msg);

    //����رհ�ť
    bool OnCloseBtnClicked(TNotifyUI& msg);
    //���ȷ����ť
    bool OnConfirmBtnClicked(TNotifyUI& msg);
    //���ȡ����ť
    bool OnCancelBtnClicked(TNotifyUI& msg);

    //��ʾ��ʾ��ʱ����Ӧ
    //bool OnShowTipTimer(TNotifyUI& msg);

    //bool OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    bool OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //void ShowTip(CString strTip);

    APP_DECLARE_MSG_MAP()

private:
};

#endif // !defined(AFX_LOGOUTLOGIC_H_)