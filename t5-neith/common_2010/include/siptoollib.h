#pragma once

#include "siptoolSessionCtrlIF.h"

class CSipToolLib  
{

public:
	CSipToolLib();
	virtual ~CSipToolLib();

	/*����	����ʵ���˽ӿ�SessionCtrlIF�Ķ���
	����	ppICnt	[out]�ɹ�����SessionCtrlIF�ӿ�,ʧ�ܷ���NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	�ӿ�ʹ����ɺ�,����DestroyInstance�������ٶ���*/
	static u16 CreateSession(CSipToolSessionCtrlIF **ppICnt);
	/*����	����ʵ���˽ӿ�SessionCtrlIF�Ķ���
	����	ppICnt	[in, out]�ӿ�SessionCtrlIF,�ɹ��󷵻�NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	ֻ��������CreateInstance���������Ķ���*/
	static u16 DestroySession(CSipToolSessionCtrlIF **ppICnt);

};

