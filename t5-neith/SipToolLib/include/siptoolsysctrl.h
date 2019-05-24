#include "siptoolsession.h"
#include "siptoolstruct.h"

class CSipToolSysCtrl : public CSipToolSysCtrlIF 
{
	friend class CSipToolSession;
public:
	CSipToolSysCtrl(CSipToolSession &cSession);
	virtual ~CSipToolSysCtrl();
    //����Socket����
    virtual u16 SocketConnect(s8* pchIP, u32 dwPort);
    //�Ͽ�Socket����
    virtual u16 CloseSocket();
    //���ø���ip��port
    virtual u16 SetParentIP(s8* szIp);
    //����һ���ھ���Ϣ
    virtual u16 SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo);

    //��ȡ��ǰ���е��ھ���Ϣ
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo);

protected:
    void BuildEventsMap();

    //����
    void OnConnected(const CMessage& cMsg);
    //���ø���IP��Ϣ�ظ�
    void OnSetParentIPRsp(const CMessage& cMsg);
    //�����ھ���Ϣ��Ϣ�ظ�
    void OnSetNeighborInfoRsp(const CMessage& cMsg);
    //�Ͽ�����
    void OnDicconnected(const CMessage& cMsg);

    virtual void DispEvent(const CMessage &cMsg);
    virtual void OnTimeOut(u16 wEvent);

private:
    CSipToolSession    *m_pSession;
    vector<TNeiRegServerInfo> m_vNeighborInfo;
};
