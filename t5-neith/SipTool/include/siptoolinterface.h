/** @defgroup siptool����siptoollib�Ĺ����ӿ� 
 *  @version V1.0.0
 *  @author  Ҷ��ƽ
 *  @date    2019.4.10
 */
#pragma once

#include "siptoollib.h"

class CSipToolInterface
{
public:
    /** ��ȡ�ӿ�ָ�� */
    static CSipToolInterface* GetCommIF();
    /** ���ٽӿ�ָ�� */
    void DestroyCommIF();

public:
    /** ��ȡ��Ƕ�Ĵ��ھ��
	*   @return HWND ���ش��ھ�� 
	*/
	HWND GetRecvWindow(){ return m_hRecvWnd;};
	/** �����Ự
	*   @return u16 �ɹ�����0;ʧ�ܷ��ط�0������ 
	*/
	void CreateSession();

	/** ���ٻỰ
	*   @return u16 �ɹ�����0;ʧ�ܷ��ط�0������ 
	*/
	void DesdroySession();

    /**
	*   ��¼Sip
	*/ 
    u16 SocketConnect( u32 dwIp, s8* szUser , s8* szPwd);
    /**
	*   ��ʼ����
	*/ 
    u16 LinkSipServer();
    /**
	*   ���ӶϿ�
	*/ 
    u16 CloseLink();

    

private:
    static  CSipToolInterface*  m_pMySelf;
    CSipToolInterface(void);
    HWND                 m_hRecvWnd;         // ��Ƕ������Ϣ�Ĵ���
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    WNDPROC              m_wndprocOld;       // ϵͳ���ڹ���

    CSipToolSessionCtrlIF   *m_pSipToolSession;       //url�Ự

    CSipToolSysCtrlIF  *m_pSysCtrlIf;

    TLoginInfo           m_tLoginInfo;//�����¼��IP �˿� �û��� ����
};

#define CSipToolComInterface  CSipToolInterface::GetCommIF()
