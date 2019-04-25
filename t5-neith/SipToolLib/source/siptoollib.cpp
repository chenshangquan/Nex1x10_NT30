#include "stdafx.h"
#include "siptoollib.h"
#include "siptoolsession.h"
#include "siptoolConst.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CSipToolLib::CSipToolLib()
{

}

CSipToolLib::~CSipToolLib()
{

}

/*=============================================================================
  �� �� ���� CreateSession
  ��    �ܣ� ����ʵ���˽ӿ�SessionCtrlIF�Ķ���
  �㷨ʵ�֣� �ӿ�ʹ����ɺ�,����DestroyInstance�������ٶ���
  ȫ�ֱ����� 
  ��    ���� SessionCtrlIF **ppICnt �ɹ�����SessionCtrlIF�ӿ�,ʧ�ܷ���NULL
  �� �� ֵ�� u16 
  -----------------------------------------------------------------------------
  �޸ļ�¼��
  ��  ��        �汾        �޸���        �߶���    �޸�����
 2018.02.26     1.0             ylp                     ����
=============================================================================*/
u16 CSipToolLib::CreateSession(CSipToolSessionCtrlIF **ppICnt)
{
    CSipToolSession *pConnect = new CSipToolSession();
    if(pConnect == NULL)
    {
        *ppICnt = NULL;
        return ERR_SIPTOOL_CREATINSTANCE;
    }
    else
    {
        *ppICnt = pConnect;
        return NO_ERROR;
    }
}

/*=============================================================================
  �� �� ���� DestroySession
  ��    �ܣ� ����ʵ���˽ӿ�SessionCtrlIF�Ķ���
  �㷨ʵ�֣� 
  ȫ�ֱ����� 
  ��    ���� SessionCtrlIF **ppICnt ����ӿ�SessionCtrlIF,�ɹ��󷵻�NULL
  �� �� ֵ�� u16 
  ˵    ���� ֻ��������CreateInstance���������Ķ���
  -----------------------------------------------------------------------------
  �޸ļ�¼��
  ��  ��        �汾        �޸���        �߶���    �޸�����
 2018.02.26     1.0              ylp                    ����
=============================================================================*/
u16 CSipToolLib::DestroySession(CSipToolSessionCtrlIF **ppICnt)
{
    CSipToolSession *pConnect = dynamic_cast<CSipToolSession*>(*ppICnt);
    if(pConnect == NULL)
    {
        return ERR_SIPTOOL_INTERFACE;
    }
    delete pConnect;
    *ppICnt = NULL;
    return NO_ERROR;
}