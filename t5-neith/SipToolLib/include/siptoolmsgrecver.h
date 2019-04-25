/*=======================================================================
ģ����      : RCKʵ��App��
�ļ���      : msgrecver.h
����ļ�    : 
�ļ�ʵ�ֹ���: ��������OSP��Ϣ�����CInstance������
����        : Ҷ��ƽ
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2018/8/29   3.0         Ҷ��ƽ        ����
=======================================================================*/

#include "stdafx.h"
#include <queue>
#include "osp.h"

#define RKC_INSTANCE_COUNT	1	// ������Ϣ��ʵ������Ŀ

/************************************************************************/
/*                        ��Ϣ���ж���                                  */
/************************************************************************/
class CSipToolMsgQueue
{
public:
    CSipToolMsgQueue();
    ~CSipToolMsgQueue();
    // ��һ����Ϣѹ�������
    void PushMsg(CMessage* const pMsg);
    // �Ӷ�����ȡ��һ����Ϣ
    void PopMsg(CSipToolMsgQueue &cOutQue);
    // �Ӷ����е���һ����Ϣ
    void Pop() 
    { 
        CMessage *pMsg = &m_queMsg.front(); 
        delete []pMsg->content;
        m_queMsg.pop(); 
    }
    // �����Ƿ�Ϊ��
    BOOL IsEmpty();
    // ��ն���
    void Clear();
    // �õ�������ǰ��Ԫ��
    CMessage& Front() { return m_queMsg.front();}
    // �õ����еĴ�С
    s32 Size() { return m_queMsg.size(); }
private:
    queue<CMessage> m_queMsg;
};

/************************************************************************/
/*                        OSPʵ������                                  */
/************************************************************************/
class CSipToolMsgHandler : public CInstance  
{
public:
    CSipToolMsgHandler();
    ~CSipToolMsgHandler();

    // ʵ��CInstance�еĴ��鷽��(�̰߳�ȫ)
    virtual void InstanceEntry(CMessage *const pMsg);
    // ��ȡ�������Ϣ����(�̰߳�ȫ)
    void PopAllMsg(CSipToolMsgQueue &cMsgQue);
    // �����Ϣ����
    void ClearQueue();

public:
    static CSipToolMsgHandler* GetMsgHandler() { return s_pMsgHandler; }
protected:
    // ��Ϣ������м��䱣���ؼ���
    CSipToolMsgQueue       m_cMsgQue;
    CRITICAL_SECTION m_csQueueOspMsg;
private:
    static CSipToolMsgHandler *s_pMsgHandler;
};

class CSipToolAppBase
{
public:
    CSipToolAppBase();
    ~CSipToolAppBase();
    // ��ȡ��ǰ���ӽڵ�ı�ʶ(�̰߳�ȫ)
    u32 GetNodeId(){ return m_dwNodeId;}
    // ���õ�ǰ���ӽڵ�ı�ʶ(�̰߳�ȫ)
    void SetNodeId(u32 dwId) { m_dwNodeId = dwId; }
    //�����Ϣ����
    void ClearOspMsg();
protected:
    u32                     m_dwNodeId;     // ��ǰ�������ӵĽڵ��ʶ
};

extern zTemplate<CSipToolMsgHandler, RKC_INSTANCE_COUNT, CSipToolAppBase> g_SipToolApp;