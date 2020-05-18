/*****************************************************************************
   ģ����      : KDV system
   �ļ���      : eventid.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: KDV�¼���ͳһ����
   ����        : ����
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2002/03/01  0.9         ����        ����
   2004/03/11  3.0         κ�α�      ���ӵ�ַ����Ϣ
   2005/12/26  4.0	   zhangsh     ����DCS��MCUͨѶ��Ϣ
******************************************************************************/
#ifndef _EVENT_ID_H_
#define _EVENT_ID_H_

#define EV_KDV_BASE     10000

/*���ܿͻ����ڲ���Ϣ��10001-11000��*/
#define EV_CLT_BGN      EV_KDV_BASE + 1
#define EV_CLT_END      EV_CLT_BGN + 999

/*�������̨�ڲ���Ϣ��11001-12000��*/
#define EV_MC_BGN       EV_CLT_END + 1
#define EV_MC_END       EV_MC_BGN + 999

/*�ն˿���̨�ڲ���Ϣ��12001-13000��*/
#define EV_MTC_BGN      EV_MC_END + 1
#define EV_MTC_END      EV_MTC_BGN + 999

/*���ܿͻ��˷������ӿ���Ϣ��13001-14000��*/
#define EV_CLTSVR_BGN   EV_MTC_END + 1
#define EV_CLTSVR_END   EV_CLTSVR_BGN + 999

/*���ܷ������ڲ���Ϣ��14001-16000��*/
#define EV_SVR_BGN      EV_CLTSVR_END + 1
#define EV_SVR_END      EV_SVR_BGN + 1999

/*���ܷ���������ӿ���Ϣ��16001-18000��*/
#define EV_SVRAGT_BGN   EV_SVR_END + 1
#define EV_SVRAGT_END   EV_SVRAGT_BGN + 1999

/*�����ڲ���Ϣ��18001-20000��*/
#define EV_AGT_BGN      EV_SVRAGT_END + 1
#define EV_AGT_END      EV_AGT_BGN + 1999

/*�����ҵ��ӿ���Ϣ��20001-22000��*/
#define EV_AGTSVC_BGN   EV_AGT_END + 1
#define EV_AGTSVC_END   EV_AGTSVC_BGN + 1999

/*�������̨��MCUҵ��ӿ���Ϣ��22001-23000��*/
#define EV_MCSVC_BGN    EV_AGTSVC_END + 1
#define EV_MCSVC_END    EV_MCSVC_BGN + 999

/*�ն˿���̨��MTҵ��ӿ���Ϣ��23001-24000��*/
#define EV_MTCSVC_BGN   EV_MCSVC_END + 1
#define EV_MTCSVC_END   EV_MTCSVC_BGN + 999

/*MCU��MT��ҵ��ӿ���Ϣ��25001-26000��*/
#define EV_MCUMT_BGN    EV_MTCSVC_END + 1001
#define EV_MCUMT_END    EV_MCUMT_BGN + 999

/*MCU�������ҵ��ӿ���Ϣ��26001-27000��*/
#define EV_MCUEQP_BGN   EV_MCUMT_END + 1
#define EV_MCUEQP_END   EV_MCUEQP_BGN + 999

/*MCU�ڲ�ҵ����Ϣ��28001-29000��*/
#define EV_MCU_BGN      EV_MCUEQP_END + 1001
#define EV_MCU_END      EV_MCU_BGN + 999

/*MT�ڲ�ҵ����Ϣ��29001-30000��*/
#define EV_MT_BGN       EV_MCU_END + 1
#define EV_MT_END       EV_MT_BGN + 999

/*RECORDER�ڲ�ҵ����Ϣ��30001-30200��*/
#define EV_REC_BGN      EV_MT_END + 1
#define EV_REC_END      EV_REC_BGN + 199

/*�������ڲ�ҵ����Ϣ��30201-30400��*/
#define EV_MIXER_BGN    EV_REC_END + 1
#define EV_MIXER_END    EV_MIXER_BGN + 199

/*����ǽ�ڲ�ҵ����Ϣ��30401-30500��*/
#define EV_TVWALL_BGN   EV_MIXER_END + 1
#define EV_TVWALL_END   EV_TVWALL_BGN + 99

/*HDU�ڲ�ҵ����Ϣ��30501-30600��*/
#define EV_HDU_BGN   EV_TVWALL_END + 1
#define EV_HDU_END   EV_HDU_BGN + 99

/*���ݷ������ڲ�ҵ����Ϣ��30601-30700��*/
#define EV_DCSINTERNAL_BGN      EV_HDU_END + 1
#define EV_DCSINTERNAL_END      EV_DCSINTERNAL_BGN + 99

/*��������������ڲ�ҵ����Ϣ��30701-30800��*/
#define EV_BAS_BGN      EV_DCSINTERNAL_END + 1
#define EV_BAS_END      EV_BAS_BGN + 99

/*������Ϣ����(30801 - 34900)*/
#define GKOSPEVENT_START      EV_BAS_END+1
#define GKOSPEVENT_END        GKOSPEVENT_START + 4099

/*�û�������Ϣ����(34901 - 35000)*/
#define EV_UM_BGN      GKOSPEVENT_END+1
#define EV_UM_END      EV_UM_BGN + 99

/*��ַ����Ϣ����(35001 - 35100)*/
#define EV_ADDRBOOK_BGN    EV_UM_END+1
#define EV_ADDRBOOK_END    EV_ADDRBOOK_BGN + 99

/*VAS��Ϣ����(35101-36100)*/
#define EV_VAS_BGN    EV_ADDRBOOK_END+1
#define EV_VAS_END    EV_VAS_BGN + 999

/*RAS��Ϣ����(36101-36200)*/
#define EV_RAS_BGN    EV_VAS_END+1
#define EV_RAS_END    EV_RAS_BGN + 99

/*DCServer��DCConsole֮��ҵ��ӿ���Ϣ(36201-37000)*/
#define EV_DCSDCC_BGN         EV_RAS_END + 1
#define EV_DCSDCC_END         EV_DCSDCC_BGN + 799

/*MT���������Ϣ(37001-37100)*/
#define EV_MTDEV_BGN        EV_DCSDCC_END  + 1
#define EV_MTDEV_END        EV_MTDEV_BGN   + 99

/*DCServer��DCSGuard֮��ҵ��ӿ���Ϣ(37101-37200)*/
#define EV_DCSDCSGUARD_BGN         EV_MTDEV_END + 1
#define EV_DCSDCSGUARD_END         EV_DCSDCSGUARD_BGN + 99

/*Ŀ¼�����ҵ����Ϣ(37201-37700)*/
#define EV_LDAP_BGN         EV_DCSDCSGUARD_END + 1
#define EV_LDAP_END         EV_LDAP_BGN + 499

//����Ϣ�δ����ǰ汾��ֲ��������LDAP��ͻ���ݲ������

/*MCU��Modem֮��ҵ��ӿ���Ϣ(37201-37300)*/
#define EV_MODEM_BGN         EV_DCSDCSGUARD_END + 1
#define EV_MODEM_END         EV_DCSDCSGUARD_BGN + 99


/*���ݻ����ն�ҵ����Ϣ(37701-38200)*/
#define EV_DCMT_BGN         EV_LDAP_END + 1
#define EV_DCMT_END         EV_DCMT_BGN + 499


/*VODҵ����Ϣ(38201-38300) zhangsh added for vod message (liliqun and hualiang)*/
#define EV_VOD_BGN         EV_DCMT_END + 1
#define EV_VOD_END         EV_VOD_BGN + 99

/*DCSMCUҵ����Ϣ(38301-38500) xushilin asked*/
#define EV_DCSMCU_BGN         EV_VOD_END + 1
#define EV_DCSMCU_END         EV_DCSMCU_BGN + 199

/*mdsc hdsc watchdog ��Ϣ(38501-38600) hualiang add*/
#define EV_DSCCONSOLE_BGN         EV_DCSMCU_END + 1
#define EV_DSCCONSOLE_END         EV_DSCCONSOLE_BGN + 99

/*VMP ��Ϣ(38601-38700) xushiling add*/
#define EV_VMP_BGN         EV_DSCCONSOLE_END + 1
#define EV_VMP_END         EV_VMP_BGN + 99

/*PRS ��Ϣ(38701-38800) xushiling add*/
#define EV_PRS_BGN         EV_VMP_END + 1
#define EV_PRS_END         EV_PRS_BGN + 99

/*VMPTW ��Ϣ(38801-38900) xushiling add*/
#define EV_VMPTW_BGN         EV_PRS_END + 1
#define EV_VMPTW_END         EV_VMPTW_BGN + 99

/*VMPTW ��Ϣ(38901-39000) xushiling add*/
#define EV_MP_BGN         EV_VMPTW_END + 1
#define EV_MP_END         EV_MP_BGN + 99

/*Radius�Ʒ�ҵ�� ��Ϣ(39001-39100) guozhongjun add */
#define EV_RS_BGN      EV_MP_END + 1
#define EV_RS_END      EV_RS_BGN + 99

//�ļ��������������豸(MCU/MT/����)ҵ����Ϣ(39101-39200)  wanghao add 2006/12/28
#define EV_FILESRVDEV_BGN					  EV_RS_END + 1
#define EV_FILESRVDEV_END					  EV_FILESRVDEV_BGN + 99

//�ļ������������Ϳͻ���ҵ����Ϣ(39201-39400)  wanghao add 2006/12/28
#define EV_FILESRVCLIENT_BGN		    EV_FILESRVDEV_END + 1
#define EV_FILESRVCLIENT_END			  EV_FILESRVCLIENT_BGN + 199

//�ļ������������ڲ���Ϣ(39401-39600)  wanghao add 2007/1/4
#define EV_SUS_BGN		              EV_FILESRVCLIENT_END + 1
#define EV_SUS_END			            EV_SUS_BGN + 199

//mpuҵ����Ϣ���� ��Ϣ(39601-40000) zhangbaoqing add 2008/11/28
#define EV_MPU_BGN              EV_SUS_END + 1
#define EV_MPU_END              EV_MPU_BGN + 399

/* RTSP server ��Ϣ����(40001-40100) xsl add*/
#define EV_RTSP_BGN				EV_MPU_END + 1 
#define EV_RTSP_END				EV_RTSP_BGN + 100

//VCS��MCUͨ����Ϣ(40101-40300) fxh add          
#define EV_VCSVC_BGN                  EV_RTSP_END  + 1
#define EV_VCSVS_END                  EV_VCSVC_BGN + 199

//8000E WATCHDOG��Ϣ(40301- 40600) xueliang add
#define EV_WD8000E_BGN                EV_VCSVS_END + 1
#define EV_WD8000E_END                EV_WD8000E_BGN + 99

//pcdv2��MT֮��ӿ���Ϣ(40601-40800)
#define EV_MTPCDV2_BGN              EV_WD8000E_END + 1
#define EV_MTPCDV2_END              EV_MTPCDV2_BGN + 199

//FIXME: �����ǰ汾��ֲ��������NMC������Ϣ�г�ͻ���������

/* MT ����������ͨ����Ϣ������ϵͳ�ɵ������ṩ���ɸ��ģ�����Ϣ��Χ�� 50200��502300*/
#define EV_SATMTNMS_BGN             50200
#define EV_SATMTNMS_END             50300

/* MCU����������ͨ����Ϣ������ϵͳ�ɵ������ṩ���ɸ��ģ�����Ϣ��Χ�� 50400��50500*/
#define EV_SATMCUNMS_BGN            51100
#define EV_SATMCUNMS_END            51200	

//#define EV_SATMCUNMS_BGN            50400
//#define EV_SATMCUNMS_END            50500	



/* ����Ϊ������Ϣ */

#define EV_TEST_KDV_BASE     50000

/*���ܿͻ��˲�����Ϣ��50001-50500��*/
#define EV_TEST_CLT_BGN      EV_TEST_KDV_BASE + 1
#define EV_TEST_CLT_END      EV_TEST_CLT_BGN + 499

/*�������̨������Ϣ��50501-51000��*/
#define EV_TEST_MC_BGN       EV_TEST_CLT_END + 1
#define EV_TEST_MC_END       EV_TEST_MC_BGN + 499

/*�ն˿���̨������Ϣ��51001-51500��*/
#define EV_TEST_MTC_BGN      EV_TEST_MC_END + 1
#define EV_TEST_MTC_END      EV_TEST_MTC_BGN + 499

/*���ܷ�����������Ϣ��51501-52000��*/
#define EV_TEST_SVR_BGN      EV_TEST_MTC_END + 1
#define EV_TEST_SVR_END      EV_TEST_SVR_BGN + 499

/*���������Ϣ��52001-52500��*/
#define EV_TEST_AGT_BGN      EV_TEST_SVR_END + 1
#define EV_TEST_AGT_END      EV_TEST_AGT_BGN + 499

/*MCU������Ϣ��52501-53500��*/
#define EV_TEST_MCU_BGN      EV_TEST_AGT_END + 1
#define EV_TEST_MCU_END      EV_TEST_MCU_BGN + 999

/*MT������Ϣ��53501-54500��*/
#define EV_TEST_MT_BGN       EV_TEST_MCU_END + 1
#define EV_TEST_MT_END       EV_TEST_MT_BGN + 999

/*RECORDER������Ϣ��54501-54700��*/
#define EV_TEST_REC_BGN      EV_TEST_MT_END + 1
#define EV_TEST_REC_END      EV_TEST_REC_BGN + 199

/*������������Ϣ��54701-54900��*/
#define EV_TEST_MIXER_BGN    EV_TEST_REC_END + 1
#define EV_TEST_MIXER_END    EV_TEST_MIXER_BGN + 199

/*����ǽ������Ϣ��54901-55100��*/
#define EV_TEST_TVWALL_BGN   EV_TEST_MIXER_END + 1
#define EV_TEST_TVWALL_END   EV_TEST_TVWALL_BGN + 199

/*���ݷ�����������Ϣ��55101-55200��*/
#define EV_TEST_DCS_BGN     EV_TEST_TVWALL_END + 1
#define EV_TEST_DCS_END     EV_TEST_DCS_BGN + 99

/*�������������������Ϣ��55201-55300��*/
#define EV_TEST_BAS_BGN     EV_TEST_DCS_END + 1
#define EV_TEST_BAS_END     EV_TEST_BAS_BGN + 99

/*GK����̨������Ϣ��55301-55700��*/
#define EV_TEST_GKC_BGN     EV_TEST_BAS_END + 1
#define EV_TEST_GKC_END     EV_TEST_GKC_BGN + 399

/*���ݻ������̨������Ϣ��55701-56100��*/
#define EV_TEST_DCC_BGN     EV_TEST_GKC_END + 1
#define EV_TEST_DCC_END     EV_TEST_DCC_BGN + 399

/*���ݻ����ն˲�����Ϣ��56101-56600��*/
#define EV_TEST_DCMT_BGN     EV_TEST_DCC_END + 1
#define EV_TEST_DCMT_END     EV_TEST_DCMT_BGN + 499

/*����������Ϣ��56601��57600��*/
#define EV_TEST_DEV_BGN     EV_TEST_DCMT_END + 1
#define EV_TEST_DEV_END     EV_TEST_DEV_BGN + 999

/*hdu�Զ������Ϣ��57601��57700��*/  // by jianglb
#define EV_HDUAUTOTEST_BGN     EV_TEST_DEV_END + 1
#define EV_HDUAUTOTEST_END     EV_HDUAUTOTEST_BGN + 99

/*Mpu �Զ������Ϣ  (57701 - 57800) */
#define EV_MPUAUTOTEST_BGN	   EV_HDUAUTOTEST_END + 1
#define EV_MPUAUTOTEST_END	   EV_MPUAUTOTEST_BGN + 99

// #define EV_GKINTERWORK_BGN     EV_MPUAUTOTEST_END + 1
// #define EV_GKINTERWORK_END     EV_GKINTERWORK_BGN + 99

/* mtctrl ��Ϣ*/
#define EV_MTCTRL_BEG 60000
#define EV_MTCTRL_END EV_MTCTRL_BEG + 999


#endif /* _EVENT_ID_H_ */

/* end of file eventid.h */


