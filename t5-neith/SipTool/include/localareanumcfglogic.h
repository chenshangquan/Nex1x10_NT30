/** @defgroup �������������߼���Ԫ 
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
    //����������ű��水ť
    bool OnLocCfgSaveBtnClicked(TNotifyUI& msg);
    //�������Ÿ���
    bool OnLocAreaNumChanged(TNotifyUI& msg);

    //��½������Ӧ
    bool OnSipToolConnected( WPARAM wparam, LPARAM lparam, bool& bHandle );
    //���ñ������Żظ���Ϣ��Ӧ
    bool OnSetLocalAreaCodeRsp( WPARAM wparam, LPARAM lparam, bool& bHandle );

    //bool OnRkcDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CString m_cstrAreaCode;      //��������
};

#endif // !defined(AFX_LOCALAREANUMCFG_H_)