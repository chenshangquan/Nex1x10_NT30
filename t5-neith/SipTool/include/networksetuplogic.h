/** @defgroup ���������߼���Ԫ 
 *  @version V1.0.0
 *  @author  csq
 *  @date    2019.4.25
 */
#if !defined(AFX_NETWORKSETUP_H_)
#define AFX_NETWORKSETUP_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNetworkSetupLogic : public CNotifyUIImpl, public Singleton<CNetworkSetupLogic> 
{
public:
	CNetworkSetupLogic();
	~CNetworkSetupLogic();

    bool OnSipToolConnected(WPARAM wparam);

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

    //�����С����ť
    bool OnMinBtnClicked(TNotifyUI& msg);
    //����رհ�ť
    bool OnCloseBtnClicked(TNotifyUI& msg);

    //Siptool connected
    bool OnSipToolConnected(WPARAM wparam, LPARAM lparam, bool& bHandle);

    APP_DECLARE_MSG_MAP()

private:

};

#endif // !defined(AFX_NETWORKSETUP_H_)