/*****************************************************************************
模块名      : siptoollib接口
文件名      : siptoolsysctrlif.h
相关文件    : 
文件实现功能: siptool配置
作者        : 叶良平
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2018/8/30   1.0         叶良平        创建
******************************************************************************/
#ifndef __SIPSYSCTRLIF_H__
#define __SIPSYSCTRLIF_H__

#include "kdvdispevent.h"
#include "siptoolstruct.h"
#include <vector>

class CSipToolSysCtrlIF : public CKdvDispEvent
{
public:
    /**
	*   Socket连接
	*/ 
    virtual u16 SocketConnect(s8* pchIP, u32 dwPort) = 0;
    /**
	*   Socket断开
	*/ 
    virtual u16 CloseSocket() = 0;
    /**
	*   设置父级ip及port
	*/ 
    virtual u16 SetParentIP(s8* szIp) = 0;
    /**
    *   设置一条邻居信息
    */ 
    virtual u16 SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo) = 0;
    /**
    *   删除一条邻居信息
    */ 
    virtual u16 DeleteNeighborInfo(s8* szAreaNum) = 0;
    /**
    *   设置本地区号
    */ 
    virtual u16 SetLocalAreaCode(s8* szLocalAreaCode) = 0;
    /**
    *   获取本地信息，包含邻居,父级和本地区号
    */
    virtual u16 GetLocalInfo() = 0;
    /**
    *   获取当前级联配置信息
    */ 
    virtual u16 GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo) = 0;
    /**
    *   获取当前所有的邻居信息
    */ 
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo) = 0;
    /**
    *   获取抢登者IP地址
    */ 
    virtual u16 GetForceIP(string &strForceIP) = 0;
	
};

#endif __SIPSYSCTRLIF_H__