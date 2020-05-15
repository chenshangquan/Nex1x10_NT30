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
    //删除一条邻居信息
    virtual u16 DeleteNeighborInfo(s8* szAreaNum);
    //设置本地区号
    virtual u16 SetLocalAreaCode(s8* szLocalAreaCode);
    //获取本地信息，包含邻居,父级和本地区号
    virtual u16 GetLocalInfo();

    //获取当前级联配置信息
    virtual u16 GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo);
    //获取当前所有的邻居信息
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo);
    //获取抢登者IP地址
    virtual u16 GetForceIP(string &strForceIP);

protected:
    void BuildEventsMap();

    //osp 断链
    void OnLinkBreak(const CMessage& cMsg);
    //连接
    void OnConnected(const CMessage& cMsg);
    //设置父级IP消息回复
    void OnSetParentIPRsp(const CMessage& cMsg);
    //设置邻居信息消息回复
    void OnSetNeighborInfoRsp(const CMessage& cMsg);
    //删除邻居信息消息回复
    void OnDeleteNeighborInfoRsp(const CMessage& cMsg);
    //设置本地区号消息回复
    void OnSetLocalAreaCodeRsp(const CMessage& cMsg);
    //设置本地信息消息回复
    void OnGetLocalInfoRsp(const CMessage& cMsg);
    //被迫下线通知
    void OnForceLogoutNty(const CMessage& cMsg);

    //断开连接
    void OnDicconnected(const CMessage& cMsg);

    virtual void DispEvent(const CMessage &cMsg);
    virtual void OnTimeOut(u16 wEvent);

private:
    CSipToolSession    *m_pSession;
    vector<TNeiRegServerInfo> m_vNeighborInfo;
    TRegServerInfo m_tCasRegServerInfo;
    string  m_strForceIP;
};
