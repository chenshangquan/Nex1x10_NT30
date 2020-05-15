/*****************************************************************************
ģ����      : cmc cnclib�ӿ�
�ļ���      : cncconfigif.h
����ļ�    : 
�ļ�ʵ�ֹ���: cns����
����        : Ф��Ȼ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/30   1.0         Ф��Ȼ        ����
******************************************************************************/
#ifndef __CNCCONFIGIF_H__
#define __CNCCONFIGIF_H__

#include "kdvdispevent.h"
#include "cncstruct.h"
#include <vector>

class CCncConfigIF : public CKdvDispEvent
{
public:
	/** ����  ע��SIP����
	 *  @param[in] tSipCfg ������Ϣ
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 RegSipService(const TTPSipRegistrarCfg& tSipCfg) = 0;

	/** ����  ע��SIP����
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UnRegSipService() = 0;

	/** ����   ���SIP����
	 *  @return TTPSipRegistrarCfg SIP��Ϣ
	 */
	virtual const TTPSipRegistrarCfg& GetSipRegCfg() const = 0;

	/** ����   �����������
	 *  @return tagTTPEthnetInfo ����������Ϣ
	 */
	virtual const TTPEthnetInfo& GetEthnetCfg() const = 0;

	/** ����   GK
	 *  @return tGkCfg ������Ϣ
	 */
    virtual u16 RegGk( const TTPGKCfg& tGkCfg ) = 0;

    /** ����   ���GK����
	 *  @return tagTTPEthnetInfo ����������Ϣ
	 */
	virtual  const TTPGKCfg& GetGkCfg() const = 0;

	/** ����   ������������
	 *  @param[in] cfg ��������
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateEthnetCfg( const TTPEthnetInfo& cfg ) = 0;

	
	/** ����   ��ñ���CNS��Ϣ
	 *  @return TTPCnsInfo CNS��Ϣ
	 */
	virtual const TTPCnsInfo& GetLocalCnsInfo() const = 0;

	/** ����   ��ñ���CNS�б�
	 *  @return vector<TTPCnsInfo> CNS�б�
	 */
	virtual const vector<TTPCnsInfo>& GetLocalCnsList() const = 0;

	/** ����   ����CNS��Ϣ
	 *  @param[in] tInfo CNS��Ϣ byIndex ��Ϣ��������(0Ϊcnc 1Ϊά������)
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateCnsInfo( const TTPCnsInfo& tInfo, u8 byIndex ) = 0;

	/** ����   ����CNS���᳡
	 *  @param[in] pbyRoomName �᳡��
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 SetMainCns( s8* pbyRoomName ) = 0;

	/** ����   ��ȡCNS���᳡��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */
	virtual const s8* GetMainCnsName() const = 0;
   
    /** ����   ����ϵͳʱ��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */
    virtual u16 UpdateSysTime( const TTPTime& time ) = 0;
       
    /** ����   ��ȡϵͳʱ��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */    
    virtual u16 ReqSysTime() = 0;

    /** ����   ���˫��Դ��Ϣ
	 *  @return TDualSrcInfo˫��Դ��Ϣ
	 */
    virtual const TDualSrcInfo& GetDualSrcInfo() const = 0;

    /** ����   �����ʾԴ����ӿ���Ϣ
	 *  @return TTPVgaMixInfo��ʾԴ����ӿ���Ϣ
	 */
    virtual const TTPVgaMixInfo& GetVgaMixInfo() const = 0;

    /** ����   ѡ��˫��Դ�˿�
	*  @param[out] emType ˫��Դ����
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SelDualInputPort( EmVgaType emType ) = 0;

    /** ����   ����˫��Դ��Ϣ
	*  @param[out] tVgaInfo ˫��Դ��Ϣ
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SetDualPortInfo( const TVgaInfo& tVgaInfo, BOOL bDefault = FALSE ) = 0;

	/** ����   ����NAT����
	 *  @param[in] cfg NAT����
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateNATCfg( const TTPNatCfg& cfg ) = 0;
	
	/** ����   ���NAT����
	 *  @return tagTTPNatCfg ����������Ϣ
	 */
	virtual const TTPNatCfg& GetNATCfg() const = 0;

	/** ����   ����ϵͳ������Ϣ
	*  @param[out] tTPSleepInfo ϵͳ������Ϣ
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SetSysSleepInfo( const TCenDevSleepInfo& tCenDevSleepInfo ) = 0;

	 /** ����   ���ϵͳ������Ϣ
	 *  @return TTPSleepInfo ϵͳ������Ϣ
	 */
    virtual const TCenDevSleepInfo& GetSysSleepInfo() const = 0;
	/**
    * ����:	 	        ���������������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtAddNMServerCmd
	*/
	virtual u16  NetMngAddCmd( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

    /**
    * ����:	 	        �����޸���������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtDelNMServerCmd
	*/
	virtual u16  NetMngModifyCmd( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

    /**
    * ����:	 	        ����ɾ����������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtModifyNMServerCmd
	*/
	virtual u16  NetMngDeleteCmd( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

	/** 
	* ����  ��ȡ������Ϣ
	* @param [in]  
	* @return  
	*/
	virtual void GetNetMngData( vector<TTPNMServerCfg> &vecTTPNMServerCfg )const = 0;

	/** 
	* ����  ����SIPע����Ϣ
	* @param [in]  emType ע������
	* @return  
	* @remarks 
	*/
	virtual u16 ReqSipRegInfo( EmGetRegInfoType emType ) = 0;

	/** 
	* ����  ��ȡCnsע����Ϣ
	* @return  vector<TTPAlias>  Cnsע����Ϣ
	* @remarks 
	*/
	virtual const vector<TAddrInfo>& GetCnsRegInfo() const = 0;

	/** 
	* ����  ��ȡUmsע����Ϣ
	* @return  vector<TTPAlias>  Umsע����Ϣ
	* @remarks
	*/
	virtual const vector<TTPAlias>& GetUmsRegInfo() const = 0;

	/**
	* ����   �װ����������
	* @param [in]  dwIP	IP��ַ
	* @param [in] 
	* @param [in] 
	* @return u16 
	*/  
    virtual u16 SetDataServerInfoCmd( u32 dwIp ) =0 ;

	//�װ��������ַ
	virtual const TTPDataConfInfo& GetWBSerIp()const = 0;

	/** 
	* ����  ����ƵԴ����
	* @param [in]  
	* @return  
	*/
	virtual u16 SetMainVideoPort( EmTPMtVideoPort emTPMtVideoPort, u8 wID ) = 0;
		/** 
	* ����  ����ƵԴ���
	* @param [in]  
	* @return  
	*/
	virtual const map<u16, EmTPMtVideoPort>& GetMainVideoPort() const = 0;

	 /** ����   ���ȫ���������Ϣ
	 *  @return TDualSrcInfoȫ���������Ϣ
	 */
    virtual const TPanCamInfo& GetPanCamInfo() const = 0;

	/** ����   ����ȫ���������ǰѡ�б��
	*  @param[in] wIndex ��ǰѡ�б��
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamSelectIndex( u8 wIndex ) = 0;

	/** ����   ȫ�����������PT
	*  @param[in] emDirection�� ����  emCnAction������
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamPT( EmDirection emDirection, EmCnAction emCnAction ) = 0;

			/** ����   ȫ���������Ұ����
	*  @param[in] 
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamView( EmZoom emZoom )= 0;

		/** ����   ȫ���������������
	*  @param[in] 
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamLight( EmPanCamBright emPanCamBright )= 0;

		/** ����   ȫ����������ڽ��� 
	*  @param[in] 
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamFocus( EmFocus emFocus, EmCnAction emCnAction )= 0;

	/** ����   ȫ��������Զ����ڽ��� 
	*  @param[in] 
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 SetPanCamAotoFocus()= 0;
	/** 
	* ����  ȫ�����������Ԥ��λ
    * @param [in]  wID  Ԥ��λ��
	* @return  
	* @remarks 
	*/
	virtual u16 SavePanCamPreset(  u8 wID ) = 0; 
	 /** 
	* ����  ȫ�����������Ԥ��λ
    * @param [in]  wID  Ԥ��λ��
	* @return  
	* @remarks 
	*/
	virtual u16 ImpelPanCamPreset(  u8 wID ) = 0;
		 /** 
	* ����  ȫ�������ɾ��Ԥ��λ
    * @param [in]  wID  Ԥ��λ��
	* @return  
	* @remarks 
	*/
	virtual u16 DeletePanCamPreset(  u8 wID ) = 0;
	/** 
	* ����  ȫ�������Ԥ��λ���޸�
    * @param [in]  wID  Ԥ��λ��
	* @return  
	* @remarks 
	*/
	virtual u16 SavePanCamPresetName(  u8 wID ,TPanCamName tPanCamName) = 0;
};

#endif