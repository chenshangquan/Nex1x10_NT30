/*****************************************************************************
  ģ����      : ���������
  �ļ���      : codecwrapper_common.h
  ����ļ�    : 
  �ļ�ʵ�ֹ���: ���������
  ����        : ��С��
  �汾        : V1.0  Copyright(C) 1997-2009 KDC, All rights reserved.
  -----------------------------------------------------------------------------
  �޸ļ�¼:
  ��  ��      �汾        �޸���      �޸�����
  2009/03/16  V1.0        ��С��       ����
******************************************************************************/
#ifndef _CODECWRAPPER_COMMON_H_
#define _CODECWRAPPER_COMMON_H_

#include "algorithmtype.h"
#include "kdvdef.h"
#include "kdvtype.h"
#include "codeccommon_win32.h"
#include <memory.h>
#include "stdio.h"

#ifdef _LINUX_
    #define CODECWRAPPER_API

    #ifndef API
        #define API
    #endif
#endif

#ifdef WIN32
    #include "winsock.h"

    #ifndef CODECWRAPPER_API
        #define CODECWRAPPER_API __declspec(dllexport)
    #endif

    #ifndef API
        #define API __declspec(dllexport)
    #endif
#endif

#define QUALITY_PRIOR  0   //��������
#define SPEED_PRIOR  1     //�ٶ�����

//�������
typedef struct
{   
    u32 m_dwMaxKeyFrameInterval;//I֡�����P֡��Ŀ
    u32 m_dwBitRate;            //��������� (Kbit/s)
    u16 m_wEncVideoWidth;       //��������ͼ���
    u16 m_wEncVideoHeight;      //��������ͼ���
    u8  m_byEncQuality;         //ͼ���������ʿ��Ʋ���,�������Ȼ����ٶ���QUALITY_PRIOR / SPEED_PRIOR    
    u8  m_byMaxQuant;           //�����������
    u8  m_byMinQuant;           //��С��������
    u8  m_byEncType;            //ͼ���������  
	u8  m_byMaxFrameRate;       //���֡��
	u8  m_byMinFrameRate;		//��С֡��
}TVidEncParam;

typedef struct
{
    u32   dwIp;     //Ip��ַ(������) 
    u16    wPort;    //�˿ں�(������) 
}TNetAddress;

typedef struct
{
    u32  m_dwSendBitRate;          //��������
    u32  m_byVideoFrameRate;       //����֡��
    u32  m_dwSendFailCount;        //����ʧ�ܴ���
    u32  m_dwEncFailCount;         //����ʧ�ܴ���
}TVidSendStatis;

typedef struct
{
    u32	  m_dwVideoFrameRate;   //��Ƶ����֡��
    u32	  m_dwVideoBitRate;     //��Ƶ��������   (��λ��)bit/s*/
    u32   m_dwVideoRecvFrame;   //�յ�����Ƶ֡��
    u32   m_dwVideoLoseFrame;   //��ʧ����Ƶ֡��
    u32   m_dwFullLose;         //����֡								  
    u32   m_dwDecdWidth;	    //�����Ŀ�
    u32   m_dwDecdHeight;       //�����ĸ�
    u32   m_dwDecFailCount;     //����ʧ�ܴ���
    BOOL32 m_bRequestKeyFrame;   //�Ƿ�����I֡
}TVidRecvStatis;

#ifdef __cplusplus
extern "C"
{
#endif

/*************************************************************
������    : InitCodecWrapper
����      ����ʼ��CodecWrapper, �粻���д˺���CodecWrapper���й��ܲ�����
����˵��  ���� 

����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
**************************************************************/
BOOL32 CODECWRAPPER_API InitCodecWrapper(void);

BOOL32 CODECWRAPPER_API UninitCodecWrapper(void);

#ifdef __cplusplus
}
#endif
  

#ifdef _LINUX_
//void RegsterVidCommands();	
void RegsterAudCommands();	
#endif
//
#endif //end of _CODECWRAPPER_COMMON_H_
