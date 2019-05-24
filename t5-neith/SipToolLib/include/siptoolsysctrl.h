#include "siptoolsession.h"
#include "siptoolstruct.h"

class CSipToolSysCtrl : public CSipToolSysCtrlIF 
{
	friend class CSipToolSession;
public:
	CSipToolSysCtrl(CSipToolSession &cSession);
	virtual ~CSipToolSysCtrl();
    //建立Socket连接
    virtual u16 SocketConnect(s8* pchIP, u32 dwPort);
    //断开Socket连接
    virtual u16 CloseSocket();
    //设置父级ip及port
    virtual u16 SetParentIP(s8* szIp);
    //设置一条邻居信息
    virtual u16 SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo);

    //获取当前所有的邻居信息
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo);

protected:
    void BuildEventsMap();

    //连接
    void OnConnected(const CMessage& cMsg);
    //设置父级IP消息回复
    void OnSetParentIPRsp(const CMessage& cMsg);
    //设置邻居信息消息回复
    void OnSetNeighborInfoRsp(const CMessage& cMsg);
    //断开连接
    void OnDicconnected(const CMessage& cMsg);

    virtual void DispEvent(const CMessage &cMsg);
    virtual void OnTimeOut(u16 wEvent);

private:
    CSipToolSession    *m_pSession;
    vector<TNeiRegServerInfo> m_vNeighborInfo;
};
