/* creator: liujie data:30Oct2007
   this head file define the routine, struct need by outsize user mode application
 */
/******************************************************************************
ģ����  �� hpi
�ļ���  �� hpicm_host.h (PPC��)
����ļ��� hpicm.h
�ļ�ʵ�ֹ��ܣ�HPI����ʵ��PPC��DM6437��ͨѶ
����    ������
�汾    ��1.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
1/1/2008  1.0      ����      ����
5/21/2008  1.1    ������ �޸�
6/3/2008 1.2       �������޸�
******************************************************************************/

/****************************** ģ��İ汾�������涨 *************************
�ܵĽṹ��mn.mm.ii.cc.tttt
     ��  Osp 1.1.7.20040318 ��ʾ
ģ������Osp
ģ��1�汾
�ӿ�1�汾
ʵ��7�汾
04��3��18���ύ

�汾�޸ļ�¼��
----------------------------------------------------------------------------
ģ��汾��hpicm 1.2.1.20080521
���ӹ��ܣ�����PPC�˵��Խӿ���Ϣ
			
�޸�ȱ�ݣ�6437���ڴ�й¶
                           6437��CACHEȱ��
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��hpicm 1.3.1.20080603
���ӹ��ܣ���ȡPPC HPI LIB�汾�ӿ�API, ����RAW READ��д��ʽ�Թ�����
			      ����HPI WAIT����
�޸�ȱ�ݣ��ر�ͨ��ʱ����ڴ�й¶��û�ж�DEBUGͨ���ͷ�
�ύ�ˣ�������
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.1.20080714
���ӹ��ܣ�����6437���ȡͨ����������ӿ�
�޸�ȱ�ݣ�
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.2.20080808
���ӹ��ܣ�����Host��֧������dsp��Ƶ��DDR��Ƶ��Open�ӿڣ�
          �޸�Ĭ��DDRƵ����135��Ϊ162MHz�����Խ������������Ƶ�ɼ�����DMA�������⡣
�޸�ȱ�ݣ�
�ύ�ˣ��ŷ���
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.3.20080926
���ӹ��ܣ�Ϊdsp��ܵ�req/fin����У�飬�ź�������
�޸�ȱ�ݣ�
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.4.20081117
���ӹ��ܣ���
�޸�ȱ�ݣ����������ڽӿ��ظ����ó���û�аѶ����󳤶���0������
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.5.20081211
���ӹ��ܣ���
�޸�ȱ�ݣ���ppc���д��������˳���У��
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.6.20081218
���ӹ��ܣ���
�޸�ȱ�ݣ�162MHz�ڴ����ؼĴ��������޸�
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.7.20090110
���ӹ��ܣ���
�޸�ȱ�ݣ�ʹ��No cache���ڴ�������dsp��hpi�������б���
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.8.20090603
���ӹ��ܣ���
�޸�ȱ�ݣ��������鳤�ȣ������Ȳ����򶪰��ش�
�ύ�ˣ��ճϽ�
----------------------------------------------------------------------------
ģ��汾��hpicm 1.4.9.20091222
���ӹ��ܣ���
�޸�ȱ�ݣ�dm6437 DDR162��������
�ύ�ˣ��ճϽ�

****************************************************************************/

#ifndef __INC_KDC_HPICOMMUNICATION_MODULE_H__
#define __INC_KDC_HPICOMMUNICATION_MODULE_H__

#ifdef __cplusplus
extern "C" {
#endif   /* __cplusplus */


#define HPI_LIB_VERSION "hpicm 1.4.9.20091222"

/* 
   the user mode call-back routine example
   int cb_nexchan_example(int chanid, u32 cap, u32 type, void * data)
   {
   .....
   }
   chan id:the new channle's id
   u32 cap:channel capability
   u32 type:the type of data transfered in this channel
   void * data: the pointer(void * cbdata) set in "HPICM_Handle->set_newchan_cb"
 */

/*stats structures*/

typedef enum
{
	STAT_READ = 0,
	STAT_WRITE 
}TRANS_MODE_T;


/**********************************************************************
 *               HPI communication modules routine                    *
 *********************************************************************/
s32 hpicm_open(s32 devid, s8 * imagename, void ** ppHPIHandle);

/* dwDspFreq = 513/594(def)/702; dwDDRFreq = 189/135/162(def) */
s32 hpicm_open_ext(s32 devid, u32 dwDspFreq, u32 dwDDRFreq, s8 * imagename, void ** ppHPIHandle);

s32 hpicm_close(void * pHPIHandle);
s32 hpicm_read_log(void * pHPIHandle, s8 * buf, ssize_t bufsz);

s32 hpicm_read_klog(void * pHPIHandle, s8 * buf, ssize_t bufsz);

s32 hpicm_blockwrite(void * pHPIHandle, s8 * buf, ssize_t bufsz);

/**********************************************************************
 *                     HPI channel open/close routine                 *
 *********************************************************************/
/* open a channel, whose attr is set in hpi_attr attr */
s32 hpicm_create_chan(void * pHPIHandle, u8 chanid, hpi_attr attr, void ** ppChanHandle);

s32 hpicm_close_chan(void * pChanHandle);

/**********************************************************************
 *                     HPI channel routine                            *
 *********************************************************************/
s32 hpicm_chan_write(void * pChanHandle, s8 * buf, s32 len);
s32 hpicm_chan_write_dual(void * pChanHandle, s8 * pHeadBuf, s32 nHeadLen, s8 * pBuf, s32 nLen);

s32 hpicm_chan_read(void * pChanHandle, s8 * buf, s32 bufsz);

s32 hpicm_chan_clear(void * pChanHandle);


s32 hpicm_call_dsp_func(void * pHPIHandle, u8 id, u32 arg);

s32 hpcim_temp_debug(void * pHPIHandle, u32 idx, u32 *val);

s32 hpcim_temp_debug_write(void * pHPIHandle, u32 idx, u32 val);

s32 hpi_raw_write(void * pHPIHandle, u32 addr, u8 *pBuff, u32 size);

s32 hpi_raw_read(void *pHPIHandle, s32 addr, u8 *pBuff, u32 size);

s32 hpicm_get_version(s8 *buff, s32 len);

s32 hpicm_get_stats(void * pChanHandle, s32 mode, u32 *byte_count, u32 *success_times, u32 *error_times);


/**********************************************************************
 *                     HPI return info routine                        *
 *********************************************************************/
s8 * hpicm_errinfo(s32 ret);
void hpicm_perror(s32 ret);


#ifdef __cplusplus
}
#endif   /* __cplusplus */

#endif
