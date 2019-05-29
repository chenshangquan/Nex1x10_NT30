#include "stdafx.h"
#include "siptoolsysctrl.h"
#include "siptoolevent.h"
#include "json.h"

CSipToolSysCtrl::CSipToolSysCtrl(CSipToolSession &cSession) : CSipToolSysCtrlIF()
{
    m_pSession = &cSession;
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
    jsParentInfo["ParentPort"] = 6668;

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
    REG_PFUN(MULTIPLEREGSIGNACK, CSipToolSysCtrl::OnConnected);
    REG_PFUN(SETPARENTIPACK, CSipToolSysCtrl::OnSetParentIPRsp);
    REG_PFUN(SETNEIGHBORINFOACK, CSipToolSysCtrl::OnSetNeighborInfoRsp);
    REG_PFUN(DELETENEIGHBORINFOACK, CSipToolSysCtrl::OnDeleteNeighborInfoRsp);
    REG_PFUN(SETLOCALAREACODEACK, CSipToolSysCtrl::OnSetLocalAreaCodeRsp);
}

void CSipToolSysCtrl::OnConnected(const CMessage& cMsg)
{
    OspPrintf(true, false, "MULTIPLEREGSIGNACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");
    TNeiRegServerInfo tNeighborInfo;
    string strTemp;

    //json 解析
    m_vNeighborInfo.clear();    //清空列表
    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        //获取登陆返回值
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }

        if ( strcmp(strRet.c_str(), _T("successful")) == 0)
        {
            nRet = 1;
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
        if (root["ParentIP"].isInt())
        {
            in_addr inaddr;
            inaddr.s_addr=root["ParentIP"].asInt();
            strncpy(m_tCasRegServerInfo.m_achIpAddr, inet_ntoa(inaddr), strlen(inet_ntoa(inaddr)));
        }

        if (root["ParentPort"].isInt())
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

    PostEvent( UI_SIPTOOL_CONNECTED, (WPARAM)nRet, 0 );

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetParentIPRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETPARENTIPACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETPARENTIPRSP, (WPARAM)nRet, 0);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetNeighborInfoRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETNEIGHBORINFOACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETNEIGHBORINFORSP, (WPARAM)nRet, 0);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnDeleteNeighborInfoRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "DELETENEIGHBORINFOACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_DELETENEIGHBORINFORSP, (WPARAM)nRet, 0);

    ::delete readerInfo;
    readerInfo = NULL;
}

void CSipToolSysCtrl::OnSetLocalAreaCodeRsp(const CMessage& cMsg)
{
    OspPrintf(true, false, "SETLOCALAREACODEACK:%s\r\n", cMsg.content);
    s32 nRet = 0;
    string strRet = _T("");

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value root;
    CString cstrRead(cMsg.content);
    if ( readerInfo->parse(cstrRead.GetBuffer(0), root) )
    {
        if (root["ret"].isString())
        {
            strRet = root["ret"].asString();
        }
    }

    if ( strcmp(strRet.c_str(), _T("successful")) == 0)
    {
        nRet = 1;
    }

    PostEvent(UI_SIPTOOL_SETLOCALAREACODERSP, (WPARAM)nRet, 0);

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