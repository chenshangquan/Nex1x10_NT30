/******************************************************************************
ģ����  �� WEB SERVER
�ļ���  �� boardwebs.h
����ļ���
�ļ�ʵ�ֹ��ܣ�WEB-SERVERģ������ṩ�ĺ궨��ͷ�ļ�
����    ��zhanka
�汾    ��1.0.0.0.0
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
08/17/2007  1.0         zhanka      ����
******************************************************************************/
#ifndef _BOARDWEBS_H_
#define _BOARDWEBS_H_

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */

#define BRD_WEBS_ENABLE 1
#define BRD_WEBS_DISABLE 2

#define BRD_WEBS_INSPECT_ENABLE 3
#define BRD_WEBS_INSPECT_DISABLE 4

#define BRD_WEBS_ERR_BASE 100
//����ֵ����
#define BRD_WEBS_PORT_ERR   BRD_WEBS_ERR_BASE+1	//�˿ڰ󶨳���
/*================================
��������BrdWebsEnable
���ܣ�������ֹͣweb server
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwEnable :BRD_WEBS_ENABLE ����
                       :BRD_WEBS_DISABLE ֹͣ
����ֵ˵���� OK/ERROR/BRD_WEBS_PORT_ERR(BRD_WEBS_PORT_ERR:�ô���ֻ�����port
                �󶨳�������µķ���,�ϲ���Ҫ�������úϷ���port)
==================================*/
s32 BrdWebsEnable(u32 dwEnable);

/*================================
��������BrdWebsInspectEnable
���ܣ�������ֹͣweb server ��س���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwEnable :BRD_WEBS_INSPECT_ENABLE ����
                       :BRD_WEBS_INSPECT_DISABLE ֹͣ
����ֵ˵���� OK/ERROR
==================================*/
s32 BrdWebsInspectEnable(u32 dwEnable);

/*================================
��������BrdWebsSetPath
���ܣ�����web server  webroot
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����pchPath webroot Ĭ��Ϊ/usr/webroot
����ֵ˵���� OK/ERROR
==================================*/
s32 BrdWebsSetPath(char * pchPath);

/*================================
��������BrdWebsSetPort
���ܣ�����web server  port
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwPort == 0 : web����port�ָ���Ĭ�϶˿�80 
              �˿�ֵ����С��0�Ҳ��ܴ���65535
����ֵ˵���� OK/ERROR/BRD_WEBS_PORT_ERR(BRD_WEBS_PORT_ERR:�ô���ֻ�����port
                �󶨳�������µķ���,�ϲ���Ҫ�������úϷ���port)
==================================*/
s32 BrdWebsSetPort(int dwPort);
#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* _BOARDWEBS_H_ */

