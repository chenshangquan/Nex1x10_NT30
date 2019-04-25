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

#include "siptoolmsgrecver.h"
#include "siptoolmsgdriver.h"
//////////////////////////////////////////////////////////////////////////
//  COspAppBase
//

CSipToolAppBase::CSipToolAppBase()
{
    m_dwNodeId = INVALID_NODE;
}

CSipToolAppBase::~CSipToolAppBase()
{
}

void CSipToolAppBase::ClearOspMsg()
{
    CSipToolMsgHandler *pHandler = CSipToolMsgHandler::GetMsgHandler();
    if (pHandler) 
    {
        pHandler->ClearQueue();
    }
}

//////////////////////////////////////////////////////////////////////////
// CMsgQueue
// 
CSipToolMsgQueue::CSipToolMsgQueue()
{
}
CSipToolMsgQueue::~CSipToolMsgQueue()
{
    Clear();
}

void CSipToolMsgQueue::PushMsg(CMessage* const pMsg)
{
    CMessage cMsg;
    cMsg = *pMsg;
    cMsg.content = new u8[pMsg->length];
    memcpy(cMsg.content, pMsg->content, pMsg->length);
    m_queMsg.push(cMsg);
}

void CSipToolMsgQueue::PopMsg(CSipToolMsgQueue &cOutQue)
{
    CMessage *pMsg = &m_queMsg.front(); 
    cOutQue.PushMsg(pMsg);
    delete []pMsg->content;
    m_queMsg.pop();
}

void CSipToolMsgQueue::Clear()
{
    while (!m_queMsg.empty()) 
    {
        CMessage *pMsg = &m_queMsg.front();
        delete []pMsg->content;
        m_queMsg.pop();
    }
}

BOOL CSipToolMsgQueue::IsEmpty()
{
    return m_queMsg.empty();
}

////////////////////////////////////////////////////////////////////////////////
// ȫ��OspӦ�ó������
zTemplate<CSipToolMsgHandler, RKC_INSTANCE_COUNT, CSipToolAppBase> g_SipToolApp;

////////////////////////////////////////////////////////////////////////////////
// CMsgHandler

CSipToolMsgHandler* CSipToolMsgHandler::s_pMsgHandler = NULL;

CSipToolMsgHandler::CSipToolMsgHandler()
{
    InitializeCriticalSection(&m_csQueueOspMsg);
    s_pMsgHandler = this;
}

CSipToolMsgHandler::~CSipToolMsgHandler()
{
    s_pMsgHandler = NULL;
    DeleteCriticalSection(&m_csQueueOspMsg);
}

void CSipToolMsgHandler::InstanceEntry(CMessage *const pMsg)
{
    EnterCriticalSection(&m_csQueueOspMsg);
    if(m_cMsgQue.Size() == 0)
    {
        m_cMsgQue.PushMsg(pMsg);
        CSipToolMsgDriver::s_pMsgDriver->OnOspMessageComing( 0, 0 );
    }
    else
    {
        m_cMsgQue.PushMsg(pMsg);
    }
    LeaveCriticalSection(&m_csQueueOspMsg);
}

void CSipToolMsgHandler::PopAllMsg(CSipToolMsgQueue &cMsgQue)
{
    EnterCriticalSection(&m_csQueueOspMsg);
    while (!m_cMsgQue.IsEmpty()) 
    {
        m_cMsgQue.PopMsg(cMsgQue);
    }
    LeaveCriticalSection(&m_csQueueOspMsg);
}

void CSipToolMsgHandler::ClearQueue()
{
    EnterCriticalSection(&m_csQueueOspMsg);
    m_cMsgQue.Clear();
    LeaveCriticalSection(&m_csQueueOspMsg);
}
