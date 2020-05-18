/******************************************************************************
ģ����  ��Kdm2x18Os
�ļ���	��kdm2x18Answer.h
����ļ�����
�ļ�ʵ�ֹ��ܣ�KDM2x18 ��������Ӧ���ܵĽӿڶ���
����	��ť����
�汾	��1.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��		�汾		�޸���       �߶���		�޸�����
08/23/2005	1.0         ť����       ��  ��     ��׼��
******************************************************************************/

#ifndef _KDM2X18ANSWER_H_
#define _KDM2X18ANSWER_H_ 

#define KDM2X18ANSWER_BIND_PORT       5512             /*�󶨶˿�*/
#define KDM2X18ANSWER_MSG_INQUIRE     "Who is online?" /*����̨���͵Ĳ�ѯ��Ϣ*/
#define KDM2X18ANSWER_MULTICAST_GROUP "224.16.32.1"    /*�鲥���ַ*/

/*����˷��ص���Ϣ�ṹ*/
#pragma pack(push, 4)
typedef struct tagAnswer
{
    u8  byDevId;       /*�豸�ţ�KDM2418=2,KDM2518=3*/
    u32 dwIp;          /*���ص�IP��ַ*/ 
    u8  byType;        /*Ĭ�� 0*/ 
    u8  abyNettype[2]; /*Ĭ�� 0*/
    u32 dwPppip[2];    /*Ĭ�� 0*/
    u16 wSrport[2];    /*Ĭ�� 0*/
    u8  bySinordou;    /*Ĭ�� 1*/
} TAnswer, *PTAnswer;
#pragma pack(pop)

#endif /*_KDM2X18ANSWER_H_*/
