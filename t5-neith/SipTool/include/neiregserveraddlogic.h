/** @defgroup �ھ�regserver����߼���Ԫ 
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
    //���ȷ�ϰ�ť
    bool OnConfirmBtnClicked(TNotifyUI& msg);
    //���ȡ����ť
    bool OnCancelBtnClicked(TNotifyUI& msg);

    //�����ھ���Ϣ�ظ���Ϣ��Ӧ
    bool OnSetNeighborInfoRsp( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    TNeiRegServerInfo m_tNeiRegServerInfo;    //����ӵ��ھ���Ϣ
    bool m_bAddNeiRegServerInfo;              //�Ƿ�����ھ���Ϣ
};

#endif // !defined(AFX_NEIREGSERVERADD_H_)