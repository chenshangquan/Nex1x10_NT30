/*****************************************************************************
ģ����      : MCA
�ļ���      : mca_lib.h
����ļ�    : 
�ļ�ʵ�ֹ���: mca lib head file
����        : Allen Wang
�汾        : V1.0  Copyright(C) 1995-2012 KEDACOM, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
3/16/2012  01.0         	Allen Wang	Creat	
3/23/2012  01.1         	Allen Wang	�޸������淶
4/17/2010  01.2 		Allen Wang      �޸���Ӧʵ�ּ�ע��
******************************************************************************/

#ifndef __MCA_LIB_
#define __MCA_LIB_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include "kdvtype.h"

#define MCA_MAX_CHIP_NUM				10		/*ϵͳ֧�ֵ�����оƬ��Ŀ*/
#define MCA_DATA_BUFF_MAX_NUM			100		/*����BUFF������*/
#define MCA_CMD_BUFF_MAX_NUM			32		/*����BUFF������*/

#define MCA_DATA_BUF_VAILD				1		/*ϵͳʹ������BUFF����*/
#define MCA_DATA_BUF_INVAILD			0		/*ϵͳ��ʹ������BUFF����*/


#define MCA_RCV_DABUF_FROM_USER		1		/*����BUFF���û��ṩ*/
#define MCA_RCV_DABUF_FROM_MCA		0		/*����BUFF��MCA�ṩ*/

#define MCA_INIT_RESTART_STRA			1		/*��λ���ԣ������һ��оƬδ�ɹ���������λ����ϵͳ*/
#define MCA_INIT_NORMAL_STRA			0		/*��ͨ����*/

#define MCA_MSG_DESC_VAILD				0x5a5a5a5a


#define MCA_CHIP_DM8168					1
#define MCA_CHIP_MPC8377				2
#define MCA_CHIP_P2020					3
#define MCA_CHIP_C6678					4


#define ERR_MCAINIT						-233		/*MCA��ʼ������*/
#define ERR_MCA_MSG_PEER_FULL			-234		/*�Զ�buff��*/
#define ERR_MCA_MSG_CHANNEL_BUSY		-235		/*��Ϣͨ��æ*/
#define ERR_MCA_MSG_NO_MSG			-236		/*û����Ϣ�ɶ�*/
#define ERR_MCA_NO_MORE_DATABUF		-238		/*û��buff�ɶ�*/
#define ERR_MCA_ERR_PARM				-239		/*��������*/
#define ERR_MCA_ERR_CALL				-240		/*����ĵ��á������API˵��*/
#define ERR_MCA_ERR_DMA_TRANS			-241		/*dma�������*/
#define ERR_MCA_ERR_CACHE_FLUSH			-242		/*dma�������*/
#define ERR_MCA_ERR_EDMA_2DFILL			-243		/*dma�������*/


/*dma����ˢcache��ʽ*/
#define 	SRC_NONFLUSH_DST_NONCOHERENT 0
#define 	SRC_FLUSH_DST_NONCOHERENT	1
#define 	SRC_NONFLUSH_DST_COHERENT	2
#define 	SRC_FLUSH_DST_COHERENT		3



typedef int  HMcaObj;

typedef void ( *TEPPrtFunc )(u32 dwEpid, u8 * pbyPrtBuff);

enum McaBufType
{
	MCA_BUF_CMD =0,
	MCA_BUF_DTA,
};

typedef struct ChipSet
{
	u32 dwType;		/*DM8168,MPC8377,P2020,C6678 etc...*/
	u32 dwIndex;	/*��ʾͬ����оƬ������*/
	u32 dwChipid;	/*Ψһ��chipid*/
} TChipSet;

typedef struct BufferDesc
{
	u32 dwPhysAddr;
	u32 dwVirAddr;
	u32 dwLen;
}TBufferDesc;


typedef struct McaParam
{
	u32 dwDBufVaild;	/*�Ƿ����������ݴ��ͣ�MCA_DATA_BUF_VAILD��ʾ����*/								
	u32 dwRcvDBufStra;	/*���û��ṩ����������buffer ����mca�ṩ������û��ṩ�Ļ���
						�����������ַ������buffer����4K���룬 ΪMCA_RCV_DABUF_FROM_USER��ʾ�û��ṩ*/
	u32 dwRcvDBufNum;	/*�û��ṩ��buffer������rcv_bufstraΪ1��Ч,<10*/
	TBufferDesc	 tRcvBuffer[MCA_DATA_BUFF_MAX_NUM];	/*�û��ṩ��buffer �������ַ�ͳ���*/
	u32 dwMaxCmdSize;	/*���������󳤶ȣ�buffer��mca�ṩ��Ϊ��Լ�ڴ棬��Ҫ����128K, ��С4K����*/
	u32 dwMaxDataSize;	/*���ݰ�����󳤶ȣ�buffer���û�����mca�ṩ�����8M*/
	u32 dwCmdBufNum;	/*����������������Ĭ��32��*/	
	u32 dwInitStra;	/*�������1��EPû�������ɹ���
						�Ƿ���Ҫ��λ����ϵͳ��MCA_INIT_RESTART_STRA��ʾ��λ��MCA_INIT_NORMAL_STRA��ʾ����λRC��Ч*/
}TMcaParam;	

typedef struct McaCapability
{
	u32 dwChipid;		/*��ǰоƬID��RCΪ0������ΪEP�����ܲ�����*/
	u32 dwChipNum;	/*����ϵͳоƬ����*/	
	TChipSet tMcaChip[MCA_MAX_CHIP_NUM];	/*ϵͳ�еĸ���оƬ*/
}TMcaCapability;


/*====================================================================
    ������      : McaGetCapbility
    ����        ����ȡmca������,ֻ����open֮�����
    �������˵����cab: ָ���������ṹ���ָ��
    ����ֵ˵��  ��0�����ߴ����
---------------------------------------------------------------------*/
s32 McaGetCapbility(HMcaObj * ptObj, TMcaCapability * ptCap);


/*====================================================================
    ������      : McaOpen
    ����        ����mca
    �������˵����param:����ָ��
    ����ֵ˵��  ��HMcaObj ָ�룬����NULL
---------------------------------------------------------------------*/
HMcaObj * McaOpen(TMcaParam * ptParam);


/*====================================================================
    ������      : McaClose
    ����        ���ر�mca
    �������˵����obj: ָ����mca_open�򿪵ľ��
    ����ֵ˵��  ��0�����ߴ����
---------------------------------------------------------------------*/
s32  McaClose(HMcaObj * ptObj);


/*====================================================================
    ������      : McaReinit
    ����        �����³�ʼ��MCA��Ŀǰֻ��dwDBufVaild��dwRcvDBufStra��dwRcvDBufNum
				tRcvBuffer ������Ч
    �������˵����obj: ָ����mca_open�򿪵ľ��
    					      ptParam:����ָ��
    ����ֵ˵��  ��0�����ߴ����
---------------------------------------------------------------------*/
s32  McaReinit(HMcaObj * ptObj, TMcaParam * ptParam);


/*==============================================================================
    ������      : McaReadCmdmsg
    ����        :��ȡһ��������Ϣ
    �������˵��: ptObj:       ���ƾ��
                  pbyBuf:       [I]�û������Buf��������Ŷ���������;
                  dwSize:      [IO]�û����䣬����ʱָ���û���Buf�Ĵ�С������㹻��
                  		���ȡ�ɹ�
                  nTimeout:     [I]��ʱֵ: 0=��������, -1=��Զ�ȴ�, >0=�ȴ�������                  			
    ����ֵ˵��  : 0�����ߴ���Ż���ʵ�ʶ�������
------------------------------------------------------------------------------*/
s32 McaReadCmdmsg(HMcaObj * ptObj, u8 *pbyBuf, u32 dwSize, s32 nTimeout);


/*==============================================================================
    ������      : McaWriteCmdmsg
    ����        :д��һ��������Ϣ
    �������˵��: ptObj:       ���ƾ��
    		dwChipid:	[O]���� ��Ϣ��chipid
                  pbyBuf:       [O]�û������Buf��������ŷ��͵�����;
                  dwSize:      [IO]�û����䣬����ʱָ���û���Buf�Ĵ�С
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
s32 McaWriteCmdmsg(HMcaObj * ptObj, u32 dwChipid, u8 *pbyBuf, u32 dwSize);


/*==============================================================================
    ������      : McaReadDataMsg
    ����        :��ȡһ��data��Ϣ����Ҫ�û������ݴ���
    �������˵��: ptObj:       ���ƾ��
                  pdwVirtaddr:		ָ�������ַ��ָ�룬����������ַΪ0����ʾʹ��Ԥ��
                  		����õ�buf����ȡ�ɹ��������Ὣ�����ַ���ȥ�����
                  		��Ϊ0�������´�����ݽ��������ַ
                  pdwSize:      [IO]�û����䣬ָ���С��ָ�룬����ʱָ���û���Buf�Ĵ�С��
                  		����㹻�����ȡ�ɹ�������ʱ�����Ὣ���ݴ�С���ȥ
		  pdwPhyaddr: ָ�������ַ��ָ�룬�����Ԥ�ȷ���õĵ�ַ����ȡ�ɹ���
		  		�Ὣ�����ַ���ȥ,���������Ԥ�ȷ����buf�����ù���		  
                  nTimeout:     [I]��ʱֵ: 0=��������, -1=��Զ�ȴ�, >0=�ȴ�������                  			
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
s32 McaReadDataMsg(HMcaObj * ptObj, u32 *pdwVirtaddr, u32 *pdwPhyaddr,u32 *pdwSize,  s32 nTimeout);


/*==============================================================================
    ������      : McaReadDataMsgDone
    ����        :��ȡ��һ��data��Ϣ�Ѿ�������ϣ������ַ������������
    			��һ�����ݵĽ��գ�ֻ�����û��ṩ������buf��ʱ������
    �������˵��: ptObj:       ���ƾ��
                  pbyBuf:       [I]Buf��ַ�������ַ��ֻ���û�bufʹ�ܵ�ʱ������
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
s32 McaReadDataMsgDone(HMcaObj * ptObj, u8 *pbyBuf);


/*==============================================================================
    ������      : McaWriteDataMsg
    ����        :дһ��������Ϣ����Ҫ�����û�������д
    �������˵��: ptObj:       ���ƾ��
                  pbyBuf:       [O]�û������Buf��������ŷ��͵�����;
                  dwChipid:  ������Ϣ��chipid
                  dwPhyaddr:buf�������ַ������������ַ������4K���룬����DMA����
                  dwSize:      [IO]�û����䣬����ʱָ���û���Buf�Ĵ�С
                  nTimeout:     [I]��ʱֵ: 0=��������, -1=��Զ�ȴ�, >0=�ȴ�������
     	 	       		����:	�ڶԶ��޷����յ������Ϊ����DMA��Դ�˷ѣ�
     	 	       		���˲��ᷢ������
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
s32 McaWriteDataMsg(HMcaObj * ptObj, u32 dwChipid, u8 *pbyBuf, u32 dwPhyaddr, u32 dwSize, s32 nTimeout);


/*==============================================================================
    ������      : mca_inc_heartbeat
    ����        : ���ӵ�ǰ���������������˲�ѯ
    �������˵��:  ptObj:       ���ƾ��
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
s32 McaIncHeartbeat(HMcaObj * ptObj);


/*==============================================================================
    ������      : mca_get_heartbeat
    ����        : ��ѯָ��������������������ۼӣ�˵��ͨ���Ѿ�����
    �������˵��:  ptObj:       ���ƾ��
    					dwChipid:	��Ҫ��ѯ��оƬ��id
    ����ֵ˵��  : ���������ߴ����
------------------------------------------------------------------------------*/
u32 McaGetHeartbeat(HMcaObj * ptObj, u32 dwChipid);

/*==============================================================================
    ������      : McaGetReservedMem
    ����        : ��ȡ�����������ַ�������ڴ棬������MCAopen֮�����
    			  ��ֻ�ܵ���һ�Σ���ȡ��mem�Ǵ�cache��mem
    �������˵��: 
    					dwPhyAddr:	��ȡreserved mem�������ַ������ʱдNULL
    					dwVirAddr:	��ȡreserved mem�������ַ������ʱдNULL
    					dwLen:	��Ҫ��ȡ�ĳ���
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
u32 McaGetReservedMem(u32 *dwPhyAddr, u32 *dwVirAddr, u32 dwLen);

/*==============================================================================
    ������      : McaDmaTransfer
    ����        : ����dma���䣬����֮ǰĬ�ϻ�ˢһ��cache
    �������˵��: 
    					dwSrcPhyAddr:		Դ�����ַ
    					dwSrcVirtAddr:		Դ�����ַ
    					dwDstPhyAddr:	Ŀ�������ַ
    					dwDstVirtAddr:		Ŀ�������ַ
    					dwLen:	���䳤�ȣ�4K����
    					dwCacheMode:	ˢcache��ʽ:
    									SRC_FLUSH_DST_NONCOHERENT:	ˢԴ��ַcache
    									SRC_NONFLUSH_DST_COHERENT:	ͬ��Ŀ�ĵ�ַcache
    									SRC_NONFLUSH_DST_NONCOHERENT :	�Բ���Ҫ
    									SRC_FLUSH_DST_COHERENT:����Ҫ    									
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
u32 McaDmaTransfer(u32 dwSrcPhyAddr, u32 dwSrcVirtAddr, u32 dwDstPhyAddr, u32 dwDstVirtAddr, u32 dwLen, u32 dwCacheMode);


/*====================================================================
    ������      : McaEdmaFill2D
    ����        ��Ti81xx Edma 2D Fill
    �������˵����pixPhyAddr: Դ�����ַ
    			  dstPhyAddr: Ŀ�������ַ
    			  width:	  2D����Ŀ�
    			  height:	  2D����ĸ�
    			  pitch:	  Ŀ��ͬ������
    			  bpp:		  �����ֽ���
    ����ֵ˵��  ��0�����ߴ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    13/05/24    1.0        ������        ����
====================================================================*/
u32 McaEdmaFill2D(u32 pixPhyAddr, u32 dstPhyAddr, u32 width, u32 height, u32 pitch, u32 bpp);


/*==============================================================================
    ������      : McaCacheFlush
    ����        : ˢһ��cache
    �������˵��: 
    					VirtAddr:		������ַ
    					dwLen:	���䳤�ȣ�4K����
    					dwCacheMode:	ˢcache��ʽ:
    									SRC_FLUSH_DST_NONCOHERENT:	ˢԴ��ַcache
    									SRC_NONFLUSH_DST_COHERENT:	ͬ��Ŀ�ĵ�ַcache
    ����ֵ˵��  : 0�����ߴ����
------------------------------------------------------------------------------*/
u32 McaCacheFlush(u32 VirtAddr, u32 dwLen, u32 dwCacheMode);


/*==============================================================================
    ������      : McaPrtEnable
    ����        : �����Ӧchipid�Ĵ�ӡ��Ϣ��ӡ��RC��ֻ��RC����
    �������˵��: dwChipid:	��Ҫ��ѯ��оƬ��id
    ����ֵ˵��  : ��
------------------------------------------------------------------------------*/
void McaPrtEnable(u32 dwChipid);


/*==============================================================================
    ������      : McaPrtDisable
    ����        : �������Ӧchipid�Ĵ�ӡ��Ϣ��ӡ��RC��ֻ��RC����
    �������˵��: dwChipid:	оƬ��id
    ����ֵ˵��  : ��
------------------------------------------------------------------------------*/
void McaPrtDisable(u32 dwChipid);


/*==============================================================================
    ������      : McaPrtFuncRegister
    ����        : ҵ��ע���ӡ����
    �������˵��: pfHookFunc--ҵ��Ĵ�ӡ����
    ����ֵ˵��  : ��
------------------------------------------------------------------------------*/
void McaPrtFuncRegister(TEPPrtFunc pfHookFunc);


/*==============================================================================
    ������      : McaPrtStart
    ����        : rc������log����߳�
    �������˵��: ptObj ���ƾ��
    ����ֵ˵��  : ��
------------------------------------------------------------------------------*/
void McaPrtStart(HMcaObj *ptObj);


/*==============================================================================
    ������      : McaEpPrintf
    ����        : ep��ӡ�������ú������Խ���ӡ���������̨��ep��log ring buffer
    �������˵��: ptObj:       ���ƾ��
		  fmt, ...:  ��ʽͨ�估����
    ����ֵ˵��  : ��
------------------------------------------------------------------------------*/
void McaEpPrintf(HMcaObj *ptObj, const char *fmt, ...);

#ifdef __cplusplus 
}
#endif /* __cplusplus */


#endif // __MCA_LIB_


