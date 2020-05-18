/*****************************************************************************
  ģ����      : 
  �ļ���      : osdmap_ti.h
  ����ļ�    : 
  �ļ�ʵ�ֹ���: 
  ����        : �ŷ�
  �汾        : V1.0  Copyright(C) 1997-2006 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2007/1/5  1.0         �ŷ�      ����
******************************************************************************/

#ifndef COSDMAP_H
#define COSDMAP_H

#include "codecwrapperdef_ti.h"

class COsdActor;
class CVlynqTrans;


class COsdMap
{
public:
    COsdMap():
	m_pcVlynqTrans(NULL),
	m_pcOsdActor(NULL)
	{};
    virtual ~COsdMap();
	
public:
	//��ʼ��
    BOOL Initialize(u32 dwMapID);

	//��ʾOSD���ɹ����ر�Osd��ID�ţ�ʧ�ܷ���OSD_ERROR.
	int OsdShow(
		u8 *pbyBmp, 
		u32 dwBmpLen, 
		u32 dwXPos, 
		u32 dwYPos,
		u32 dwWidth,
		u32 dwHeight, 
		u8  byBgdColor, 
		u32 dwClarity,
		BOOL32  bSlide=FALSE,
		u32 dwSlideTimes=1,
		u32 dwSlideStride=10);

	//�ر�Osd, �ɹ�����OSD_OK; ʧ�ܷ���OSD_ERROR.
    int OsdClose(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, BOOL32 bSlide=FALSE);	


	//��ʼ������ʾ������Ļ(�������Ϲ�)
	int StartRunCaption(
		u8 *pbyBmp, 
		u32 dwBmpLen,
		u32 dwTimes,
		u32 dwXPos,
		u32 dwSpeed, 
		u32 dwWidth, 
		u32 dwHeight, 
		u8  byBgdColor, 
		u32 dwClarity, 
		u32 dwChnNum);

	//ֹͣ������ʾ������Ļ
	int StopRunCaption(u32 dwChnNum);
	//�ж��Ƿ�����ʾ������Ϣ
	BOOL IsOsdStop();


	int  StartTimeIconShow(u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight, 
	            		  TBGColor tBackBGDColor, u32 dwClarity, u32 dwChnNum, u32 dwCapPrt = 2);
	int	 AlarmTimeIconShow(u32 dwChnNum,u32 dwCapPrt,u32 dwAlarmTime);
	int  StopTimeIconShow(u32 dwChnNum, u32 dwCapPrt = 2);
	int  TransRect(u8 byTrans,u32 dwXPos, u32 dwYPos, u32 dwWidth, u32 dwHeight);

	//��ѯ�����õ�ǰmapid
	void SetMapId(u32 dwMapId = CWTI_CPUMASK_ALL, BOOL byReDraw = FALSE);
	static u32 GetMapId();
	
protected:
   COsdActor*   m_pcOsdActor;
   CVlynqTrans* m_pcVlynqTrans;

   //20070930
   static u32      m_dwMapId;
private:

};



#endif
