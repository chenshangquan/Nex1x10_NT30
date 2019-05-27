/*****************************************************************************
模块名      : rkclib接口
文件名      : rkcsysctrlif.h
相关文件    : 
文件实现功能: rkc配置
作者        : 叶良平
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2018/8/30   1.0         叶良平        创建
******************************************************************************/
#ifndef __RKCSYSCTRLIF_H__
#define __RKCSYSCTRLIF_H__

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
    *   获取当前级联配置信息
    */ 
    virtual u16 GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo) = 0;
    /**
    *   获取当前所有的邻居信息
    */ 
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo) = 0;
	
};

#endif __RKCSYSCTRLIF_H__