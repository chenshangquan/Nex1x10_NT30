/******************************************************************************
ģ����  ��Kdm2x18Os
�ļ���	��Kdm2x18SNMP.h
����ļ�����
�ļ�ʵ�ֹ��ܣ�KDM2x18 SNMP�����ܵı�̽ӿ�
����	��ť����
�汾	��1.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��		�汾		�޸���       �߶���		�޸�����
10/18/2005	1.0         ť����       ��  ��     ����
******************************************************************************/

#ifndef _KDM2X18SNMP_H_
#define _KDM2X18SNMP_H_ 

#ifdef __cplusplus 
extern "C" { 
#endif

typedef int (* init_mibs_callback_t)(void);
typedef int (* snmp_config_callback_t)(void);

int snmp_start
    (
        init_mibs_callback_t init_mibs_callback,    /*�����û�ʵ�ֵ�MIBģ��Ļص�����*/
        snmp_config_callback_t snmp_config_callback /*����snmp�Ļص�����*/
    );

int snmp_config_comm_port_add
    (
        unsigned short port         /*AGENT ��NMSͨ�ŵĶ˿ںţ�1-65535*/
    );
    
int snmp_config_community_info_add
    (
        char *community_name,       /*��ͬ���������ȷ�ΧΪ1-32�ֽ�*/
        char *ipaddress ,           /*NMS��IP��ַ��Ӧ����A.B.C.D/M��ʽ*/
        char *view_name,            /*�빲ͬ�������������ͼ��*/
        unsigned int access_type,   /*��������ͼ���й��������Ȩ�ޣ�0-----read 1-----write*/
        unsigned int acl_num        /*acl ����� <1-99>*/
    );
    
int snmp_config_view_info_add
    (
        char *view_name,            /*��ͼ�������ȷ�ΧΪ1-32�ֽ�*/
        u_char included,            /*�����ͼ�Ƿ����mib_name������ 1----������0---������*/
        char *mib_name              /*��ͼ��Ҫ������mib���������ȷ�ΧΪ1-50�ֽ�*/
    );
    
int snmp_config_group_info_add
    (
        char *group_name,           /*���������ȷ�ΧΪ1-32�ֽ�*/
        u_char ver_type,            /*snmp�İ汾�ţ�0----v1,1-----v2c,2------v3 */
        u_char auth_type,           /*�Ƿ���Ҫ��֤�ͼ���0-��֤��1--����Ҫ��֤��2-��Ҫ��֤�ͼ���*/
        char *read_view,            /*��Ȩ�޵���ͼ�������ȷ�ΧΪ1-32�ֽ�*/
        char *write_view,           /*дȨ�޵���ͼ�������ȷ�ΧΪ1-32�ֽ�*/
        char *notify_view,          /*ͨ�����ͼ�������ȷ�ΧΪ1-32�ֽ�*/
        u_short acl_num             /*acl�Ĺ���ţ�1-99*/
    );
    
int snmp_config_user_info_add
    (
        char *user_name,            /*�û�����ͬ���������ȷ�ΧΪ1-32�ֽ�*/
        u_char auth_type,           /*�Ƿ���Ҫ��֤�ͼ���0-��֤��1--����Ҫ��֤��2-��Ҫ��֤�ͼ���*/
        u_char ver_type,            /*snmp�İ汾�ţ�0----v1,1-----v2c,2------v3 */
        char *group_name,           /*����û�����������飬���ȷ�ΧΪ1-32�ֽ�*/
        char *auth_paras,           /*��֤���������ȷ�ΧΪ1-32�ֽ�*/
        char *pri_paras,            /*���ܲ�������󳤶�Ϊ32�ֽ�*/
        u_short acl_num             /*acl����� 1-99*/
    );
    
int snmp_config_traphost_info_add
    (
        char *traphost_name,        /*trap����Ŀ�ĵص�IP��ַӦ��Ϊ1.1.1.1��ʽ����Ч��IP��ַ*/
        char *trap_security_name,   /* trap���ĵ��û���/��ͬ��,* ���ȷ�ΧΪ1-32�ֽ�*/
        u_short  trap_port,         /* trap����Ŀ�ĵصĶ˿ں�1-65535*/
        u_char  trap_ver,           /* trap���ĵİ汾0-v1,1-v2,3-v3*/
        u_char  trap_security_model /*�Ƿ���Ҫ��֤�ͼ���0-��֤��1--����Ҫ��֤��2-��Ҫ��֤�ͼ���*/
    );
    
int snmp_config_community_info_del
    (
        char *community_name        /*��ͬ���������ȷ�ΧΪ1-32�ֽ�*/
    );
    
int snmp_config_view_info_del
    (
        char *view_name             /*��ͼ�������ȷ�ΧΪ1-32�ֽ�*/
    );
    
int snmp_config_group_info_del
    (
        char *group_name,           /*���������ȷ�ΧΪ1-32�ֽ�*/
        u_char ver_type             /*snmp�İ汾�ţ�0----v1,1-----v2c,2------v3 */
    );
    
int snmp_config_user_info_del
    (
        char *user_name             /*�û�����ͬ���������ȷ�ΧΪ1-32�ֽ�*/
    );
    
int snmp_config_traphost_info_del
    (
        char *traphost_name,        /*trap����Ŀ�ĵص�IP��ַΪ1.1.1.1��ʽ����Ч��IP��ַ*/
        int trap_port               /* trap����Ŀ�ĵصĶ˿ں�<1-65535>*/
    );

#ifdef __cplusplus 
} 
#endif

#endif /*_KDM2X18SNMP_H_*/
