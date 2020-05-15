#ifndef _CNCPORTDIAGNOSISIF_H_
#define _CNCPORTDIAGNOSISIF_H_

#include "kdvdispevent.h"

class CCncPortDiagCtrlIF : public CKdvDispEvent
{
public:	
	//��Ƶ�ӿ���Ϣ
	virtual TTpAudioPortInfo* GetAudioPortInfo() = 0;							
	virtual	u16 SetAudioPortInfoCmd( const TTpAudioPortInfo** atAudioPortInfo ) = 0;		
	virtual	u16 DefaultAudioPortCmd( const TTpAudioPortInfo** atAudioPortInfo ) = 0;
	
	//���綪����Ϣ
	virtual u16 LostPacketInfoReq() = 0;
	virtual const u8& GetLostPacketInfo()const = 0;			
	
	//�ϴ���������
	virtual const TTPUpDownSpeedInfo& GetUpDownstreamRate()const = 0;	
	
	//ѡ������Ƶ���󷽰�������
	virtual u16 SelAVMatrixCmd( const TTPVgaMixInfo& tVgaMixInfo ) = 0;
	//��ȡ�˿���Ͻ��
	virtual const TTPVideoDiagInfo& GetVideoDiagInfo()const = 0;
	virtual const TTPAudioDiagInfo& GetAudioDiagInfo()const = 0;
	
	//ֹͣ��ϲ�������
	virtual u16 StopAVMatrixReq() = 0;
	
	//Tpad�б�
	virtual	const TTPTPadList& GetTpadList()const = 0;								
	virtual	u16 UpdateTpadListReq() = 0;	

	//����Cns
	virtual u16 RebootCns() = 0;
	
	//����T300
	virtual u16 UpgradeCns( const TTPFTPFileInfo& tVerFileInfo ) = 0;
	
	//ά������ˢ�½�������
	virtual u16 ReqRefresh() = 0;
	
	//��Ƶ��������������
	virtual u16 AudiotMixerCmd( const u8** aAudioMixerInfo ) = 0;
	virtual u8* GetAudioMixerInfo() = 0;
	virtual u16 DefaultMixerCmd( const u8** aAudioMixerInfo ) = 0;
	
	//��Ƶ��������������
	virtual u16 AudioEqualizerCmd( const TTPEqualizer** atEqualizer ) = 0;
	virtual TTPEqualizer* GetAudioEqualizer() = 0;
	virtual u16 DefaultEqCmd( const TTPEqualizer** atEqualizer ) = 0;
	
	//���з�������ַ
	virtual u16 CallServerCmd( const TTPCallSerInfo& tCallSerInfo ) = 0;
	virtual const TTPCallSerInfo& GetCallServerInfo()const = 0;

	//������������ַ
	virtual u16 UpgradeSerCmd( const TTPUpgradeSer& tUpgradeSer ) = 0;
	virtual const TTPUpgradeSer& GetUpgradeSerInfo()const = 0;
	
	//̨���ļ��ϴ��ɹ�֪ͨ
	virtual u16 ConfSignCmd( const BOOL& bOk, u8 byIndex ) = 0;
	
	//������ѡ��ʽ
	virtual u16 VideoFormatCmd( const TTPVidForamt& tVidForamt ) = 0;
	virtual const TTPVidForamt& GetVideoFormatInfo()const = 0;
	
	//��ʾ��ѡ��ʽ
	virtual u16 DualVideoFormatCmd( const TTPVidForamt& tVidForamt ) = 0;
	virtual const TTPVidForamt& GetDualVideoFormatInfo()const = 0;
	
	//��������
	virtual u16 CallRateCmd( const u16 wCallRate ) = 0;
	virtual const u16 GetCallRate()const = 0;
	
	//��ʾ����
	virtual u16 DualCallRateCmd( const u16 wDualCallRate ) = 0;
	virtual const u16 GetDualCallRate()const = 0;
	
	//������ѯ
	virtual u16 ConfPollCmd( const TTPPollInfo& tPollInfo ) = 0;
	virtual const TTPPollInfo& GetConfPollInfo()const = 0;
	
	//��������
	virtual u16 ConfDisCmd( const BOOL& bDis ) = 0;
	virtual const BOOL& GetConfDisInfo()const = 0;
	
	//��Ƶ��ʽ
	virtual u16 AudioFormatCmd( const EmTpAudioFormat& emAudioFormat ) = 0;
	virtual const EmTpAudioFormat& GetAudioFormatInfo() const = 0;

	//Encryt������Ϣ
	virtual	u16 GetEncrytInfo( TTpEncryptKey& tEncryt ) = 0;
	virtual	u16 EncrytCmd( const TTpEncryptKey& tEncryt ) = 0;
			/** 
	* ����  	�õ�̨����Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual const TTPLogoInfo& GetLogoInfo()const = 0;
	/** 
	* ����  	�õ������Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual const TTPBannerInfo& GetBannerInfo()const = 0;

			/** 
	* ����  	̨������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 CnIsShowLogoCmd( const TTPLogoInfo& tTPLogoInfo  ) = 0;
	/** 
	* ����  	�������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 CnIsShowBannerCmd( const TTPBannerInfo& tTPBannerInfo ) = 0;
};

#endif 