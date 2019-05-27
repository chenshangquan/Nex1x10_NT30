/*****************************************************************************
ģ����      : rkclib�ӿ�
�ļ���      : rkcsysctrlif.h
����ļ�    : 
�ļ�ʵ�ֹ���: rkc����
����        : Ҷ��ƽ
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2018/8/30   1.0         Ҷ��ƽ        ����
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
	*   Socket����
	*/ 
    virtual u16 SocketConnect(s8* pchIP, u32 dwPort) = 0;
    /**
	*   Socket�Ͽ�
	*/ 
    virtual u16 CloseSocket() = 0;
    /**
	*   ���ø���ip��port
	*/ 
    virtual u16 SetParentIP(s8* szIp) = 0;
    /**
    *   ����һ���ھ���Ϣ
    */ 
    virtual u16 SetNeighborInfo(TNeiRegServerInfo &tNeighborInfo) = 0;
    /**
    *   ��ȡ��ǰ����������Ϣ
    */ 
    virtual u16 GetCasRegServerBackInfo(TRegServerInfo &tCasRegServerInfo) = 0;
    /**
    *   ��ȡ��ǰ���е��ھ���Ϣ
    */ 
    virtual u16 GetNeighborBackInfo(vector<TNeiRegServerInfo> &vNeighborInfo) = 0;
	
};

#endif __RKCSYSCTRLIF_H__