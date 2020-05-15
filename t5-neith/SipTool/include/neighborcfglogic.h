/** @defgroup ���������߼���Ԫ 
 *  @version V1.0.0
 *  @author  chenshangquan
 *  @date    2018.5.20
 */
#if !defined(AFX_NEIGHBORCFG_H_)
#define AFX_NEIGHBORCFG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNeighborCfgLogic : public CNotifyUIImpl, public Singleton<CNeighborCfgLogic> 
{
public:
	CNeighborCfgLogic();
	~CNeighborCfgLogic();

    bool NeiRegServerItemAdd(TNeiRegServerInfo& tNeiRegServerInfo);
    //�����Ƿ������ͬ������
    bool AreaCodeIsExist(TNeiRegServerInfo& tNeiRegServerInfo);
protected:
    //�����Ӱ�ť
    bool OnNeighborCfgAddBtnClicked(TNotifyUI& msg);
    //���ɾ����ť
    bool OnNeighborCfgDelBtnClicked(TNotifyUI& msg);

    //�����ھ���Ϣ�б�
    bool OnUpdateNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle );
    //�����ھ���Ϣ�б�
    bool OnDeleteNeighborInfoList( WPARAM wparam, LPARAM lparam, bool& bHandle );

    bool OnSipDisconnected( WPARAM wparam, LPARAM lparam, bool& bHandle );

    APP_DECLARE_MSG_MAP()

private:
    CListUI* m_pNeiRegServerList;
    TNeiRegServerInfo m_tNeiRegServerInfoAdd;    //����ӵ��ھ���Ϣ
};

#endif // !defined(AFX_NEIGHBORCFG_H_)