#ifndef _WATCHDOGDEF_H_
#define _WATCHDOGDEF_H_

#include "kdvtype.h"
#include "kdvdef.h"
#include "osp.h"
#include "eventid.h"

//////////////////////////////// MDSC/HDSC APP ID ///////////////////////////////
#define  WD_SER_APP_ID             (AID_DSC_BGN+1)
#define  WD_CLT_APP_ID             (AID_DSC_BGN+2) 


//////////////////////////////// �궨�� ///////////////////////////////
//���������� 
#define  WD_SER_IP                 inet_addr( "127.0.0.1" )
#define  WD_SER_TCP_PORT           (u16) 3500
#define  WD_SER_TELNET_PORT        (u16) 3501

#define  WD_MODULE_NUM             (u16) 6 

//////////////////////////////// ��Ϣ���� ///////////////////////////////

/*EV_MODULECONCMD
  ��������
  ��Ϣ����: (ModuleParameter ��1)
*/
OSPEVENT(EV_MODULECONCMD,            (EV_DSCCONSOLE_BGN +1) );

/*ev_WatchDogConInd
  ���ӳɹ�����
  ���ݣ�
  */
OSPEVENT(EV_MODULECONIND,            (EV_DSCCONSOLE_BGN +2) );

/*ev_ModuleSetState
  ����״̬
  ���ݣ�(ModuleParameter ��1)
*/
OSPEVENT(EV_MODULESETSTATE,           (EV_DSCCONSOLE_BGN +5) );


//ģ�����
enum  emModuleType 
{
    emINVALIDMODULE  = -1,          //δ֪ģ��
    emGK             = 0,           //GK
    emT120           = 1,           //���ݻ���
    emFIREWALL       = 2,           //����ǽ
    emMP             = 3,           //MMP
    emMTADP          = 4,           //mtAdp
    emPRS            = 5            //PRS
};

//ģ��״̬
enum emModuleState
{
    emSTOP            = 0,          //ֹͣ
    emRUNNING         = 1           //����
};

//ģ�����
typedef struct tagModuleParameter
{
    tagModuleParameter() : emType(emINVALIDMODULE), emState(emSTOP) {}

    emModuleType    emType;     //ģ������
    emModuleState   emState;    //ģ��״̬
} IModuleParameter, *PIModuleParameter;

#endif
