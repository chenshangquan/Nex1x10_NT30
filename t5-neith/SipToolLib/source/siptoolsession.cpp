#include "stdafx.h"
#include <string>
#include "siptoolsession.h"
#include "siptoolmsgrecver.h"
#include "siptoolsysctrl.h"
#include "siptoolprintctrl.h"
#include "json.h"

#pragma comment(lib, "lib_json.lib")

//�̺߳���
DWORD WINAPI GetConfTempThread(LPVOID pParam);

CSipToolSession::CSipToolSession():m_bInitOsp(FALSE)
{
    InitializeOsp();
    SetAppId( AID_SIPTOOL_APP );

    m_pSysCtrlIf = NULL;
   
    //�ڸ����У�new�����еĹ����࣬�ⲿͨ���ӿ�GetInterface()��ȡ
    #define NEW_REG(pCtrlIF, clsName)         \
    pCtrlIF = new clsName(*this);     \
    RegHandler(pCtrlIF);

    NEW_REG( m_pSysCtrlIf, CSipToolSysCtrl );
}

CSipToolSession::~CSipToolSession()
{

}

u16 CSipToolSession::InitializeOsp()
{
    // ��ʼ��OSP
    const u32 dwTelnetPort = 0;
    if( !IsOspInitd() )
    {

        BOOL bTelnet  = FALSE ;

#ifdef _DEBUG
        bTelnet = TRUE;
#endif

        if(!OspInit( bTelnet, dwTelnetPort))
        {
            return ERR_OSP_INIT;
        }
        else
        {
            m_bInitOsp = FALSE;
        }
    }
    else
    {
        m_bInitOsp = TRUE;
    }

    char szOspApp[] = "SipToolLib";
    const u32 dwPrior = 80;
    int nRet = g_SipToolApp.CreateApp(&szOspApp[0], AID_SIPTOOL_APP, dwPrior, 300, 200);
    ASSERT(nRet == 0);

    PrtSipToolMsg( "RkcLib osp�����ɹ�\n" );

    return NO_ERROR;
}

/*��ȡ�ӿ�ָ��*/
u16 CSipToolSession::RkcGetInterface(CSipToolSysCtrlIF **ppCtrl)
{
    if( m_pSysCtrlIf != NULL)
    {
        *ppCtrl = m_pSysCtrlIf;
        return NO_ERROR;
    }
    else
    {
        *ppCtrl = NULL;
        return ERR_SIPTOOL;
    }
}


/*��    �ܣ� �Ƿ��Ѻ�CNS����������*/
BOOL CSipToolSession::IsConnectedSip()
{
	return g_SipToolApp.GetNodeId() != INVALID_NODE;
}

/*��    �ܣ� ����*/
u16 CSipToolSession::ConnectSip(u32 dwIP, u32 dwPort, char* strUser, char* strPwd, BOOL32 bConnect /* = TRUE */)
{
    // ����TCP����
    if( IsConnectedSip() )
    { 
        //����Ѿ���¼�˸�IP����ֱ�ӷ��أ�����Ͽ�����
		if ( dwIP == m_dwSipIp )
		{
			return ERR_SIPTOOL_ACTIVE_CONNECT;
		}
		else
		{
			DisconnectSip();
			return ERR_SIPTOOL_ACTIVE_CONNECT;
		}
        
    }
    
    //ClearDisp();
    // �ع���Ϣ�ַ���
    //BuildEventsMap();
    
    //����Osp��TCP����,�õ����ػ�����IP��ַ
	u32 dwCnNodeId = 0;
	if ( bConnect )
	{
		dwCnNodeId = OspConnectTcpNode( htonl(dwIP), static_cast<u16>(dwPort), 5 , 3, 5000 );
		if( dwCnNodeId == INVALID_NODE )
		{
			return ERR_SIPTOOL_TCPCONNECT;
		}		
	}
	else
	{
		dwCnNodeId = 0;
	}

    g_SipToolApp.SetNodeId( dwCnNodeId );
    //������node�����ж�ʱ��֪ͨ��appid��InstId
    ::OspNodeDiscCBReg( dwCnNodeId, AID_SIPTOOL_APP, 1);

    // ��Ϣ��װ����
    Json::FastWriter jsWriterInfo;
    Json::Value jsLoginInfo;
    jsLoginInfo["user"] = strUser;
    jsLoginInfo["password"] = strPwd;
    
    string strLoginInfo = jsWriterInfo.write(jsLoginInfo);

    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(MULTIPLEREGSIGN, &strLoginInfo, strLoginInfo.length());
    
	return NO_ERROR;
}

/*��    �ܣ� �Ͽ�Sip����*/
u16 CSipToolSession::DisconnectSip()
{
    if( !IsConnectedSip() )
    {
        return NO_ERROR;
    }

    OspDisconnectTcpNode(g_SipToolApp.GetNodeId()); 
	m_dwSipIp = 0;
    
    return NO_ERROR;
}

void CSipToolSession::DispEvent(const CMessage &cMsg)
{
    DISP_FUN(CSipToolSession, cMsg);
}

void CSipToolSession::OnTimeOut(u16 wEvent)
{ 
}


