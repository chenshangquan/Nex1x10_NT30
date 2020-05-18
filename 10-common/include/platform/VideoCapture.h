/*******************************************************************************
 * ģ����      : TiVidDrv
 * �ļ���      : Vidcapture.h
 * ����ļ�    : 
 * �ļ�ʵ�ֹ���: ��Ƶ�ɼ��Ľӿڶ��壨MediaCtrl��
 * ����        : ť���ҩI
 * �汾        : V1.0 Copyright(C) 1995-2006 KEDACOM, All rights reserved.
 * -----------------------------------------------------------------------------
 * �޸ļ�¼:
 * ��  ��       �汾        �޸���      �޸�����
 * 2006/05/14   1.0a        ť����      ����	
*******************************************************************************/
#ifndef VIDCAPTURE_H
#define VIDCAPTURE_H 1

#ifdef __cplusplus
    extern "C" {
#endif

#include "DM642VPort.h"

enum
{
    VIDCAP_OK = 0,
    VIDCAP_INV_PARAM,
    VIDCAP_OPEN_FAILED,
    VIDCAP_IS_CLOSED,
    VIDCAP_VPORT_FAILED,
    VIDCAP_NO_VALID_FRAME
};

/* A/D ת��оƬ���ƶ���*/
#define VIDCAP_ADV7180    VPORT_CHIP_ADV7180
#define VIDCAP_ADV7181    VPORT_CHIP_ADV7181

typedef struct {
    u8   portNo;             /*ģ��˿ںţ����ڳ�ʼ��ʹ�ã����Զ�̬�޸ģ�����VidCapSetParam��������0��ʼ*/
    u8   bUsePal;            /*pal��ntsc���ɶ�̬�޸�,���ǲ��Ƽ�����Ϊʵ�ʻ����³�ʼ��*/
    u8   chipName;           /*��Ƶ�źŽ���оƬ���ţ�Ĭ��VCAP_SAA7114�����ܶ�̬�޸�*/
    u8   chipIicAddr;        /*��ʹ�ã����ּ��ݣ�*/
    l32  maxFrameSize;       /*һ���������Ĵ�С һ��720��576��2����ETI_MAX_FRAMESIZE�����ܶ�̬�޸�*/
    l32  iWidth;             /*def 720*/
    l32  iHeight;            /*def 576(pal) 480(ntsc)*/
    
    u16  bufNum;             /*��ʹ�ã����ּ��ݣ�*/
    u16  bUseIport;          /*��ʹ�ã����ּ��ݣ�*/
    
} VCAP_PARAM;

typedef struct {
    u32 dwFrameDropped;
    
	u32 dwCapComplete;
	u32 dwCapOverrun;
	u32 dwCapSyncByteErr;
	u32 dwCapShortFieldDetect;
    u32 dwCapLongFieldDetect;

} VIDCAP_STATUS;

typedef struct {
	u64 qwVal;
	
} VIDCAP_TIMESTAMP;

/*====================================================================
	������	    ��VidCapInit
	����        ����Ƶ�ɼ���ʼ��
	����˵��    ��nChanNoIn:        ͨ���ţ�1��2��
	              ptVcapInitParam:  ��ʼ������
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VidCapInit(l32 nChanNoIn, VCAP_PARAM *ptVcapInitParam);

/*====================================================================
	������      ��VidCapInput
	����        ����Ƶ�ɼ����룬���ɼ��������ݷŵ�*ppBuf��
	����˵��    ��chanNo��ͨ���ţ�1��2��
	              ppBuf����������ָ��
	              iTimeOut����ʱ���ã�BUF_NO_WAIT��0�����ȴ���BUF_INFINITE_WAIT����1�����޵ȴ�������ֵ���ȴ��ĺ�����
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VidCapInput(l32 nChanNoIn, u8 **ppbyBuf, l32 nTimeOut, VIDCAP_TIMESTAMP *ptTimeStamp);

/*====================================================================
	������	    ��VidCapSetParam
	����        ����Ƶ�ɼ�������̬�޸�
	����˵��    ��chanNo��ͨ���ţ�1��2
	              pVcapParam���޸ĺ�Ĳ���
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VideoCapSetParam(l32 nChanNoIn, VCAP_PARAM *ptVcapParam);

/*====================================================================
	������      ��VidCapAvailBufs
	����        ����Ƶ�ɼ��Ѿ����Ļ���������
	����˵��    ��chanNo��ͨ���ţ�1��2
	              bufNum������������
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VidCapAvailBufs(l32 nChanNoIn, l32 *pnbufNum);

/*====================================================================
	������	    ��VidCapClose
    ����        ����Ƶ�ɼ��ر�
    ����˵��    ��chanNo��ͨ���ţ�0��1
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VidCapClose(l32 nChanNo);

/*====================================================================
	������	    ��VidCapGetStatus
    ����        ��ȡ����Ƶ�ɼ�������״̬ͳ����Ϣ
    ����˵��    ��ptVidCapStatus��
	����ֵ˵��  ��ETIDRV_OK���ɹ�
                  С��0��    ʧ��
====================================================================*/
l32 VidCapGetStatus(VIDCAP_STATUS *ptVidCapStatus);

/*====================================================================
	������	    ��VidCapResetStatus
	����        ��������Ƶ�ɼ�������״̬ͳ����Ϣ
	����˵��    ����
	����ֵ˵��  ��VIDCAP_OK��       �ɹ�
                  ����ֵ��          ʧ��
====================================================================*/
l32 VidCapResetStatus(void);

#ifdef __cplusplus
    }
#endif

#endif /*VIDCAPTURE_H*/
