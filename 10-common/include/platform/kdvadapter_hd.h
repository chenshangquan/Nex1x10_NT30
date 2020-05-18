/*****************************************************************************
  ģ����      : Codecwrapper.a
  �ļ���      : codecwrapper_hd.h
  ����ļ�    : codecwrapperdef_hd.h
  �ļ�ʵ�ֹ���: 
  ����        : ������
  �汾        : V4.0  Copyright(C) 2007-2008 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2007/11/28  4.0         ������      ����
******************************************************************************/


#ifdef _MEDIACTRL_DM816x_

#include "dm816x/kdvadapter_hd.h"

#else

#ifndef _CODEADAPTER_HD_H_
#define _CODEADAPTER_HD_H_
#include "codecwrapperdef_hd.h"

class CAdapterChannel;

class CKdvAdapterGroup
{
public:
    CKdvAdapterGroup ();
    virtual ~ CKdvAdapterGroup ();

public:
    u16 CreateGroup(u32 dwGroupID);// ����������,������codecwrapperdef_hd.h
    u16 StartGroup(void);//��ʼ����		   
   	u16 StopGroup(void);//ֹͣ����	
    u16 DestroyGroup(void);//�˳���

	u16 SetFpgaErrReboot(u32 dwErrCount);

    u16 AddVideoChannel(const TAdapterChannel * ptAdpChannel, u8& byChnNo); //���ͼ��ͨ��
    u16 RemoveVideoChannel(u8 byChnNo); //ɾ��ͼ��ͨ��

    u16 GetGroupStatus(TAdapterGroupStatus &tAdapterGroupStatus); //�õ����״̬
    u16 GetVideoChannelStatis(u8 byChnNo, TAdapterChannelStatis &tAdapterChannelStatis); //�õ���Ƶͨ����ͳ����Ϣ
	
	    /*�������� GetVideoCodecType
    ��    �ܣ� 
    ��    ���� u8 byChnNo
               u32 dwID  : 0:��һ����(FPGA)��1�ڶ�����(FPGA or DSP)��2����(FPGA)
               u32& dwType :VID_CODECTYPE_FPGA �� VID_CODECTYPE_DSP
    �� �� ֵ�� u16 
    ˵    ���� */
    u16 GetVideoCodecType(u8 byChnNo, u32 dwID, u32& dwType);

    u16 ChangeVideoEncParam(u8 byChnNo, TVideoEncParam  * ptVidEncParam, u32 dwEncNum = 1);     //�ı���Ƶ����������
    u16 ChangeVideoDecParam(u8 byChnNo, TVideoDecParam  * ptVidDecParam);     //�ı���Ƶ����������

    u16 SetVidDataCallback(u8 byChnNo, u32 dwID, FRAMECALLBACK fVidData, void* pContext); /*������Ƶ���ݻص���������*/
    u16 SetData(u32 chnNo, const TFrameHeader& tFrameInfo);        /*������Ƶ�������ݣ�������*/
    
    void  ShowChnInfo(u32 chnNo, BOOL32 bVidChn);
	
    u16 SetFastUpdata(u32 dwID);
    
    u16 SetVidEncResizeMode(s32 nMode);

    u16 ClearVideo(); /*�������ˢ����״̬*/
	u16 SetResizeMode(u32 dwMode);//ģʽ0:�Ӻڱߣ�1:�ñߣ�2:�ǵȱ����죬Ĭ��0
	
    u16 SetVidDropPolicy(u8 byDropPolicy);  //�趨�����������

protected:
    CAdapterChannel* m_pCodec;
};

u16 HardInitAdapter(TAdapterInit* pInit);
u16 HardDestroyAdapter();
#endif //_MEDIACTRL_DM816x_
#endif
