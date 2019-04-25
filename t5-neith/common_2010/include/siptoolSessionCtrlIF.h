#pragma once
#include "kdvdispevent.h"
#include "siptoolsysctrlif.h"
#include "siptoolstruct.h"

class CSipToolSessionCtrlIF : public CKdvDispEvent 
{
public:
    //��ȡ�ӿ� 
    virtual u16 RkcGetInterface(CSipToolSysCtrlIF **ppCtrl) = 0;

    //���ӵ�Sip
	virtual u16 ConnectSip(u32 dwIP, u32 dwPort,LPSTR strUser,LPSTR strPwd, BOOL32 bConnect = TRUE) = 0;

	//�Ͽ�CNS���� 
	virtual u16 DisconnectSip() = 0;

	//��ѯ�Ƿ�������
	virtual BOOL IsConnectedSip() = 0;
};
