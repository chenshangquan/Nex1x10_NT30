#include "siptoolsession.h"

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

protected:
    void BuildEventsMap();

    //连接
    void OnConnected(const CMessage& cMsg);
    void OnDicconnected(const CMessage& cMsg);

    virtual void DispEvent(const CMessage &cMsg);
    virtual void OnTimeOut(u16 wEvent);

private:
    CSipToolSession    *m_pSession;
};
