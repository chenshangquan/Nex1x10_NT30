#include "stdafx.h"
#include "siptoolsysctrl.h"
#include "siptoolevent.h"
#include "json.h"

CSipToolSysCtrl::CSipToolSysCtrl(CSipToolSession &cSession) : CSipToolSysCtrlIF()
{
    m_pSession = &cSession;
    m_strForceIP = _T("0.0.0.0");
    BuildEventsMap();
}

CSipToolSysCtrl::~CSipToolSysCtrl()
{

}

u16 CSipToolSysCtrl::SocketConnect(s8* pchIP, u32 dwPort)
{
   
    return NO_ERROR;
}

u16 CSipToolSysCtrl::CloseSocket()
{
    return NO_ERROR;
}

u16 CSipToolSysCtrl::SetParentIP(s8* szIp)
{
    Json::Value jsParentInfo;
    jsParentInfo["ParentIP"] = szIp;
    if ( strcmp(szIp, "0.0.0.0") == 0 )
    {
        jsParentInfo["ParentPort"] = 0;
    }
    else
    {
        jsParentInfo["ParentPort"] = 6060;

    }

    string strParentInfo = jsParentInfo.toStyledString();
    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(SETPARENTIP, (char*)strParentInfo.c_str(), strlen(strParentInfo.c_str()));

    return NO_ERROR;
}

u16 CSipToolSysCtrl::SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo)
{
    Json::Value jsNeighborInfo;
    jsNeighborInfo["IP"] = tNeighborInfo.m_achIpAddr;
    jsNeighborInfo["Port"] = tNeighborInfo.m_wPort;
    jsNeighborInfo["areacode"] = tNeighborInfo.m_achAreaCode;

    string strNeighborInfo = jsNeighborInfo.toStyledString();
    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(SETNEIGHBORINFO, (char*)strNeighborInfo.c_str(), strlen(strNeighborInfo.c_str()));

    return NO_ERROR;
}

u16 CSipToolSysCtrl::DeleteNeighborInfo(s8* szAreaNum)
{
    Json::Value jsNeighborInfo;
    jsNeighborInfo["areacode"] = szAreaNum;

    string strNeighborInfo = jsNeighborInfo.toStyledString();
    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(DELETENEIGHBORINFO, (char*)strNeighborInfo.c_str(), strlen(strNeighborInfo.c_str()));

    return NO_ERROR;
}

u16 CSipToolSysCtrl::SetLocalAreaCode(s8* szLocalAreaCode)
{
    Json::Value jsLocalAreaCode;
    jsLocalAreaCode["LocalAreaCode"] = szLocalAreaCode;

    string strLocalAreaCode = jsLocalAreaCode.toStyledString();
    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(SETLOCALAREACODE, (char*)strLocalAreaCode.c_str(), strlen(strLocalAreaCode.c_str()));

    return NO_ERROR;
}

u16 CSipToolSysCtrl::GetLocalInfo()
{
    CSipToolMsgDriver::s_pMsgDriver->PostCMsg(GETLOCALINFO, NULL, 0);
    return NO_ERROR;
}

u16 CSipToolSysCtrl::GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo)
{
    strncpy(tCasRegServerInfo.m_achAreaCode, m_tCasRegServerInfo.m_achAreaCode, MAX_AREACODE_LENGTH);
    strncpy(tCasRegServerInfo.m_achIpAddr, m_tCasRegServerInfo.m_achIpAddr, MAX_IP_LENGTH);
    tCasRegServerInfo.m_wPort = m_tCasRegServerInfo.m_wPort;

    return true;
}

u16 CSipToolSysCtrl::GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo)
{
    vNeighborInfo.assign(m_vNeighborInfo.begin(), m_vNeighborInfo.end());
    return true;
}

void CSipToolSysCtrl::BuildEventsMap()
{
    REG_PFUN(OSP_DISCONNECT, CSipToolSysCtrl::OnLinkBreak);
    REG_PFUN(MULTIPLEREGSIGNACK, CSipToolSysCtrl::OnConnected);
    REG_PFUN(SETPARENTIPACK, CSipToolSysCtrl::OnSetParentIPRsp);
    REG_PFUN(SETNEIGHBORINFOACK, CSipToolSysCtrl::OnSetNeighborInfoRsp);
    REG_PFUN(DELETENEIGHBORINFOACK, CSipToolSysCtrl::OnDeleteNeighborInfoRsp);
    REG_PFUN(SETLOCALAREACODEACK, CSipToolSysCtrl::OnSetLocalAreaCodeRsp);
    REG_PFUN(GETLOCALINFOACK, CSipToolSysCtrl::OnGetLocalInfoRsp);
    REG_PFUN(FORCELOGOUT, CSipToolSysCtrl::OnForceLogoutNty);
}

void CSipToolSysCtrl::OnLinkBreak(const CMessage& cMsg)
{
    // OSP断链通知
    u32 u32NodeId = *(u32*)(cMsg.content);

    //PrtMsg( OSP_DISCONNECT, emEventTypeCnsRecv, "Link Break (NodeID: %d)", u32NodeId );

    //ClearWaiting();	// OSP断链后,尚未执行完的命令中断执行 
    //ClearAllCommand(); // 清空所有在队列中等待执行的命令
    //MsgTransDriver->ClearOspMsg();

    m_vNeighborInfo.clear();        //清空邻居信息
    m_tCasRegServerInfo.Clear();    //清空级联信息

    //SetNodeId(INVALID_NODE);

    PostEvent(UI_SIPTOOL_DISCONNECTED);
}

void CSipToolSysCtrl::OnConnected(const CMessage& cMsg)
{
    OspPrintf(true, false, "MULTIPLEREGSIGNACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    bool bForceLog = 0;
    string strRet = _T("");
    TNeiRegServerInfo tNeighborInfo;
    string strTemp = _T("");

    //json 解析
    m_vNeighborInfo.clear();    //清空列邻居信息
    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        //抢登消息
        if (root["ParentIP"].isString())
        {
            strTemp = root["ForceLog"].asString();
            if ( strcmp(strTemp.c_str(), _T("Yes")) == 0 )
            {
                bForceLog = true;
            }
        }

        //获取所有的邻居信息
        if (root["NeighborInfo"].isArray())
        {
            u32 dwArraySize = root["NeighborInfo"].size();
            for (u32 dwIndex = 0; dwIndex < dwArraySize; dwIndex++)
            {
                memset(&tNeighborInfo, 0, sizeof(TNeiRegServerInfo));

                strTemp = root["NeighborInfo"][dwIndex]["IP"].asString();
                strncpy( tNeighborInfo.m_achIpAddr, strTemp.c_str(), strlen(strTemp.c_str()) );
                tNeighborInfo.m_wPort = root["NeighborInfo"][dwIndex]["Port"].asInt();
                strTemp = root["NeighborInfo"][dwIndex]["areacode"].asString();
                strncpy( tNeighborInfo.m_achAreaCode, strTemp.c_str(), strlen(strTemp.c_str()) );

                m_vNeighborInfo.push_back(tNeighborInfo);
            }
        }

        //获取父级配置信息
        if (root["ParentIP"].isString())
        {
            strTemp = root["ParentIP"].asString();
            strncpy( m_tCasRegServerInfo.m_achIpAddr, strTemp.c_str(), strlen(strTemp.c_str()) );
        }

        if ( root["ParentPort"].isUInt() )
        {
            m_tCasRegServerInfo.m_wPort = root["ParentPort"].asUInt();
        }
        else if ( root["ParentPort"].isInt() )
        {
            m_tCasRegServerInfo.m_wPort = root["ParentPort"].asInt();
        }

        //获取本地区号配置信息
        if (root["LocalAreaCode"].isString())
        {
            string strLocalAreaCode = root["LocalAreaCode"].asString();
            strncpy(m_tCasRegServerInfo.m_achAreaCode, strLocalAreaCode.c_str(), strlen(strLocalAreaCode.c_str()));
        }

        //获取登陆返回值
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }

        if ( strcmp(strRet.c_str(), _T("successful")) == 0)
        {
            nRet = 1;
        }
    }

    PostEvent( UI_SIPTOOL_CONNECTED, (WPARAM)nRet, (LPARAM)bForceLog );

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetParentIPRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETPARENTIPACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");
    string strErr = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["error"].isString())
        {
            strErr = root["error"].asString();
        }

        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETPARENTIPRSP, (WPARAM)nRet, (LPARAM)&strErr);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetNeighborInfoRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETNEIGHBORINFOACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");
    string strErr = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["error"].isString())
        {
            strErr = root["error"].asString();
        }

        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETNEIGHBORINFORSP, (WPARAM)nRet, (LPARAM)&strErr);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnDeleteNeighborInfoRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "DELETENEIGHBORINFOACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");
    string strErr = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["error"].isString())
        {
            strErr = root["error"].asString();
        }

        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_DELETENEIGHBORINFORSP, (WPARAM)nRet, (LPARAM)&strErr);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetLocalAreaCodeRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETLOCALAREACODEACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");
    string strErr = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["error"].isString())
        {
            strErr = root["error"].asString();
        }

        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETLOCALAREACODERSP, (WPARAM)nRet, (LPARAM)&strErr);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnGetLocalInfoRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "GETLOCALINFOACK:%s\r\n", cMsg.content);

    TNeiRegServerInfo tNeighborInfo;
    string strTemp = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        //获取所有的邻居信息
        m_vNeighborInfo.clear();
        if (root["NeighborInfo"].isArray())
        {
            u32 dwArraySize = root["NeighborInfo"].size();
            for (u32 dwIndex = 0; dwIndex < dwArraySize; dwIndex++)
            {
                memset(&tNeighborInfo, 0, sizeof(TNeiRegServerInfo));

                strTemp = root["NeighborInfo"][dwIndex]["IP"].asString();
                strncpy( tNeighborInfo.m_achIpAddr, strTemp.c_str(), strlen(strTemp.c_str()) );
                tNeighborInfo.m_wPort = root["NeighborInfo"][dwIndex]["Port"].asInt();
                strTemp = root["NeighborInfo"][dwIndex]["areacode"].asString();
                strncpy( tNeighborInfo.m_achAreaCode, strTemp.c_str(), strlen(strTemp.c_str()) );

                m_vNeighborInfo.push_back(tNeighborInfo);
            }
        }

        //获取父级配置信息
        if (root["ParentIP"].isString())
        {
            strTemp = root["ParentIP"].asString();
            strncpy( m_tCasRegServerInfo.m_achIpAddr, strTemp.c_str(), strlen(strTemp.c_str()) );
        }

        if ( root["ParentPort"].isUInt() )
        {
            m_tCasRegServerInfo.m_wPort = root["ParentPort"].asUInt();
        }
        else if ( root["ParentPort"].isInt() )
        {
            m_tCasRegServerInfo.m_wPort = root["ParentPort"].asInt();
        }

        //获取本地区号配置信息
        if (root["LocalAreaCode"].isString())
        {
            string strLocalAreaCode = root["LocalAreaCode"].asString();
            strncpy(m_tCasRegServerInfo.m_achAreaCode, strLocalAreaCode.c_str(), strlen(strLocalAreaCode.c_str()));
        }
    }

    PostEvent(UI_SIPTOOL_GETLOCALINFORSP, TRUE, 0);

    ::delete readerInfo;
    readerInfo = NULL;
}

u16 CSipToolSysCtrl::GetForceIP(string &strForceIP)
{
    strForceIP = m_strForceIP;
    return true;
}

void CSipToolSysCtrl::OnForceLogoutNty(const CMessage& cMsg)
{
    OspPrintf(true, false, "FORCELOGOUT:%s\r\n", cMsg.content);

    m_strForceIP.clear();

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ClientIP"].isString())
        {
            m_strForceIP = root["ClientIP"].asString();
        }
    }
    
    PostEvent(UI_SIPTOOL_FORCELOGOUTNTY, 0, 0);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnDicconnected(const CMessage& cMsg)
{
    //发送界面提醒
    
}

void CSipToolSysCtrl::DispEvent(const CMessage &cMsg)
{
    DISP_FUN(CSipToolSysCtrl, cMsg);
}

void CSipToolSysCtrl::OnTimeOut(u16 wEvent)
{ 
}