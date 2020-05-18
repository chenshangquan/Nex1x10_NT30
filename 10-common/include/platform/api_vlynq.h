/*
 * auth: wangyuantao@kedacom.com
 * date: Tue Dec  5 17:41:33 CST 2006
 * descriptor: library head for vlynq community
 */
#ifndef __VLYNQ_INC_H__
#define __VLYNQ_INC_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * value = 1: enable
 * value = 0: disable
 * other value, ignore it !!!
 * default is 0
 */
int vlynq_enable_dma(int value);

/*************************************************************/
int vlynq_channel_create(const char *channel_name, int size, int crc_flag);
/*
 * ˵��������ͨ��
 * ������channel_name��ͨ���������12�ַ�����\0��
 *	 size: ͨ����С����λΪkb
 *	 crc_flag: crcЧ���ʶ��0Ϊ��ʹ��crc������ֵΪʹ��crc
 * ���أ�0Ϊ�ɹ�
 *	 -1ͨ���Ѵ���
 *	 -2ͨ��̫���޷�����
 *	 -3�Ӵ��������ܴ���ͨ��
 *	 -4vlynq��ʼ��ʧ�ܲ��ܴ���ͨ��
 *	 -5ͨ���Ѵ����������ܴ���
 *	 -6��������
 *	 -7��������
 * ע�⣺size ��kb��λ�������ڴ�ӳ��ʱҪ����ҳ�棬sizeֻ����4 �ı���
 */

int vlynq_channel_destroy(const char *channel_name);
/*
 * ˵����ɾ��ͨ��
 * ������ͨ����
 * ���أ�0Ϊ�ɹ�
 *	 -1ͨ��������
 *	 -2ɾ��ͨ��ʧ��
 */

int vlynq_channel_open(const char *channel_name);
/*
 * ˵������ͨ��
 * ������ͨ����
 * ���أ�ͨ�����
 * 	 ��0��ʾ��ͨ���ɹ�
 *	 0��ʾ��ͨ��ʧ��
 */

int vlynq_channel_close(int channel_handle);

/*
 * ˵�����رմ򿪵�ͨ��
 * ������ͨ�����
 * ���أ��ر�ͨ���ɹ�Ϊ0��ʧ��Ϊ-1
 */

/*************************************************************/
int vlynq_channel_package_num(int channel_handle);
/*
 * ˵������ȡ������ͨ���Ͽ��Զ�ȡ�����ݰ�������ͨ�������ڻ�ʧ�ܷ��أ�1����errno
 * ������ͨ�����
 * ���أ����ݰ�������0�����0�������ظ�����ʾʧ��
 */

int vlynq_channel_clear(int channel_handle);
/*
 * ˵�������ͨ���ϵ����ݰ�: ���Ӷ�������
 * ������ͨ�����
 * ���أ��ɹ�����0��ʧ�ܷ��ظ���
 */

int vlynq_channel_info(int channel_handle, char *name, int *size, int *crc_flag);
/*
 * ˵������ȡͨ����Ϣ��ͨ��������С���Ƿ�crcЧ�飩
 * ������
 * 	 ����� channel_handle: ͨ�����
 * 	 ���룺 name: ͨ����
 *		size: ͨ����С����λΪkb
 *		crc_flag: crcЧ���ʶ
 * ���أ��ɹ�����0��ʧ�ܷ��ظ���
 */

int vlynq_channel_freesize(int channel_handle);
/*
 * ˵������ȡͨ��ʣ��ռ�
 * ������ͨ�����
 * ���أ�ʧ�ܷ��ظ���, �ɹ����ؿ���д��ƫ��
 * ��λ��
 */

int vlynq_channel_write(int channel_handle, const char* buffer, int len, int wait_flag);
int vlynq_channel_write2(int channel_handle, const char* buffer1, int len1, const char* buffer2, int len2, 
		int wait_flag);
/*
 * ˵����д�����ݣ�����ʵ��д��������ʧ��
 * ������wait_flag����ʾ���û�п��пռ䣬�ȴ��ĳ�ʱʱ��
 *	 bufferҪ�������ݵĻ��� (buffer1, buffer2 ��һ�����ݰ��������ֻ���)
 *	 len�������ݳ���
 *	 wait_flag����ʱ���:   0ֱ�����ݷ����ɹ�Ϊֹ
 *				1�����������ȴ��������������ʱ���ڻ�δ���ͷ��س�ʱ
 *				-1����ʱ����������
 * ���أ�0������Ϊ���ͳɹ�����ʾ�ɹ����͵����ݰ�����
 *	 -1Ϊ��ʱ
 *	 -2ͨ�������㹻�Ŀռ�
 *	 -3��������
 */

int vlynq_channel_read(int channel_handle, char *buffer, int wait_flag);
/*
 * ˵������ȡ���ݣ�����ʵ�ʶ�ȡ������ʧ��
 * ������buffer: �������ݵĻ���
 * ���أ�0������Ϊ��ȡ���ݳɹ�����ʾ�ɹ���ȡ�����ݰ��ĳ���
 * 	 -1Ϊͨ���������ݰ�
 * 	 -2ΪcrcЧ�����
 * 	 -3Ϊ����
 */
int vlynq_dump_config();
int vlynq_apitest_master(void);
int vlynq_apitest_slave(void);
/*
 * ˵����vlynq����ģ����Խӿ�
 * ��������
 * ���أ�0Ϊ�ɹ�������Ϊʧ��
 * ���������ں�ģ����غ�������������vlynq_apitest_master��ӳ���ڴ�������г�ʼ����
 *       Ȼ������շ����ݣ�Ȼ��Ӵ���������vlynq_apitest_slave�����շ����ݲ��ԡ�
 *		 ����������û���Ⱥ�˳���������ӵ�ĳһ��״̬δ׼���ã�����������ֱ��������ȷ״̬��
 */

char *vlynq_version();
#define VLYNQ__VERSION	"VLYNQ 1.1.2.20071029"
/***************************
ģ��汾��VLYNQ 1.1.1.20070827
���ӹ��ܣ���
�޸�ȱ�ݣ��޸ĺ�����ʹ�õ���ȷ��ͨ��ʣ��ռ�
�ύ�ˣ���Զ��
*****************************/

/***************************
ģ��汾��VLYNQ 1.1.1.20070830
���ӹ��ܣ���
�޸�ȱ�ݣ��޸ĺ�����ʹ�õ���ȷ��ͨ��ʣ��ռ�
�ύ�ˣ���Զ��
*****************************/

/***************************
ģ��汾��VLYNQ 1.1.2.20070911
���ӹ��ܣ���
�޸�ȱ�ݣ���nipdebug��������ͬ��ȫ�ֱ���
�ύ�ˣ���Զ��
*****************************/

/***************************
ģ��汾��VLYNQ 1.1.2.20071025
���ӹ��ܣ���
�޸�ȱ�ݣ�����vlynq��д���ݣ��ر���д���˺ܶ��Ż�
�ύ�ˣ���Զ��
*****************************/

/***************************
ģ��汾��VLYNQ 1.1.2.20071029
���ӹ��ܣ���
�޸�ȱ�ݣ�������dmaʹ�ܼ���ش���
�ύ�ˣ���Զ��
*****************************/

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif

