/** @defgroup ��ʾ�����߼���Ԫ 
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
    bool OnOKBtnClicked(TNotifyUI& msg);
    //���ȡ����ť
    bool OnCancelBtnClicked(TNotifyUI& msg);

    bool OnSipToolDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );
    
    APP_DECLARE_MSG_MAP()

private:
};

//0 û�а�ť��1 ȷ����ť��2 ȷ�� ȡ����ť, 3 ȷ�� ȡ�� �رհ�ť
u8 showMessageBox(LPCTSTR lpstrText, u8 byType = 1);
#define ShowMessageBox showMessageBox

#endif // !defined(AFX_MESSAGEBOXLOGIC_H_)