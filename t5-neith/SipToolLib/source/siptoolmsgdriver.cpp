#include "stdafx.h"
#include "siptoolmsgdriver.h"
#include "siptoolmsgrecver.h"
#include "siptoolprintctrl.h"

CSipToolMsgDriver* CSipToolMsgDriver::s_pMsgDriver = NULL;

CSipToolMsgDriver::CSipToolMsgDriver()
{
    // �����¼����Ʊ�
    MappingEventName();
    s_pMsgDriver = this;
}

CSipToolMsgDriver::~CSipToolMsgDriver()
{
}

COspMsg* CSipToolMsgDriver::GetOspMsgPtr(BOOL32 bClear)
{
    if (bClear) 
    {
        ZeroMemory(&m_tOspMsg, sizeof(COspMsg));
    }

    return &m_tOspMsg;
}
//ע��һ��������Ϣ�����ָ��
void CSipToolMsgDriver::RegHandler(CKdvDispEvent* const pDispEvnet)
{
    m_vpDispEvent.push_back(pDispEvnet);
}

void CSipToolMsgDriver::MappingEventName()
{
    
}

void CSipToolMsgDriver::PostCMsg(u16 wEvenId, void* pConent, u16 wLen)
{
    ZeroMemory(&m_cMsg, sizeof(CMessage));

    m_cMsg.event = wEvenId;
    if (pConent == NULL)
    {
        m_cMsg.content = NULL;
        m_cMsg.length = 0;
    }
    else
    {
        m_cMsg.content = (u8*)pConent;
        m_cMsg.length = wLen;
    }

    PostMsg(TYPE_CMESSAGE);
}

u16 CSipToolMsgDriver::PostMsg(u32 dwType)
{  
    u32 dwDesIID = MAKEIID(AID_SIPTOOL_SERVER_APP, CInstance::DAEMON);    //Ŀ��
    u32 dwSrcIID = MAKEIID(GetAppId());                   //Դ

    u16 wRet = NO_ERROR;
    u16 wEvent = 0;
    if (TYPE_TPMSG == dwType) 
    {  
        wRet = OspPost(MAKEIID(AID_SIPTOOL_APP,0), m_tOspMsg.GetEvent(),m_tOspMsg.GetBody(),m_tOspMsg.GetBodyLen());
    }
    else
    {
        wRet = OspPost(dwDesIID, m_cMsg.event, m_cMsg.content, m_cMsg.length,
            GetNodeId(), dwSrcIID);
        OspPrintf(true, false, "event:%d,content:%s, length:%d\r\n", m_cMsg.event, m_cMsg.content, m_cMsg.length);
    }

    return wRet;
}

void CSipToolMsgDriver::OnOspMessageComing(WPARAM wParam, LPARAM lParam)
{
    // ��OSP�ص��߳���ȡ��Ϣ
    CSipToolMsgHandler *pHandler = CSipToolMsgHandler::GetMsgHandler();
    if (!pHandler) 
    {
        return;
    }
    CSipToolMsgQueue cMsgQue;
    pHandler->PopAllMsg(cMsgQue);
    // �ַ���Ϣ
    while(!cMsgQue.IsEmpty())
    {
        const CMessage &cMsg = cMsgQue.Front();

        //��ӡ���
        CString strEvent = CSipToolPrintCtrl::GetPrintCtrl()->GetEventDescribe(cMsg.event); 

        PrtSipToolMsg(cMsg.event, "\n[SipToolLib]: �յ���Ϣ:%s(%u).", strEvent,cMsg.event);

        // ������Ϣ�ַ���
        vector<CKdvDispEvent*>::iterator itr = m_vpDispEvent.begin();
        BOOL bFind = FALSE;
        for(; itr != m_vpDispEvent.end(); itr++)
        {
            if ((*itr)->HasRegEvent(cMsg.event)) 
            {
                (*itr)->DispEvent(cMsg);
                bFind = TRUE;
            }
        }
        if (!bFind) 
        {	  	 
            PrtSipToolMsg( "[SipToolLib]: ��Ϣ:%s(%d)������,��Ϊû���ҵ�ƥ�����Ϣ������.\n", strEvent, cMsg.event);		
        }

        cMsgQue.Pop();
    }
}

