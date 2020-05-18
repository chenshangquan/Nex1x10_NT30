/*****************************************************************************
   ģ����      : �·���ҵ��
   �ļ���      : EvRecservMT.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: REC SERVER��MT��ӿ���Ϣ����
                 *_REQ: ��Ӧ������
				 *_ACK, *_NACK: ����֮��
				 *_CMD: ����Ӧ������
				 *_NOTIF: ״̬֪ͨ
   ����        : mcu
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2010/07/21  1.0         Liu Xu      ��evmcueqp.h�зֳ���
******************************************************************************/
#ifndef _EV_RECSERVERMT_H_
#define _EV_RECSERVERMT_H_

#include "osp.h"
#include "eventid.h"
#include "vccommon.h"
#include "errorid.h"

#ifdef WIN32
#pragma comment( lib, "ws2_32.lib" ) 
#pragma pack( push )
#pragma pack( 1 )
#define window( x )	x
#else
#include <netinet/in.h>
#define window( x )
#endif

// Rec Server��App��, ��ʱ���壬�Ժ���ܻᱻ�޸�
#define RECSERV_APP_NO                  (AID_MCU_BGN + 49)
// Rec Server�����Ķ˿ں�
#define RECSERV_TELNET_PORT             (u16)(2500)

/*MCU��REC��ҵ��ӿ���Ϣ(26101-26300)*/
#define EV_MCUREC_BGN			EV_MCUEQP_BGN + 100
#define EV_MCUREC_END			EV_MCUREC_BGN + 199

//ע��Ϊ��֤������ȷ���У����гɹ���ʧ��Ӧ���ԭ��Ϣ�ŷֱ��1��2

/**********************************************************
 ����ΪREC���������ն�֮��ҵ��ӿ� (26101-26300)
**********************************************************/

//¼�����MCU����ע������REC->MCU����Ϣ��ΪTPeriEqpRegReq�ṹ
OSPEVENT( REC_MCU_REG_REQ,					EV_MCUREC_BGN );
//MCU����Ӧ��MCU->REC����Ϣ��Ϊ��Ϣ��ΪTPeriEqpRegAck
OSPEVENT( MCU_REC_REG_ACK,					EV_MCUREC_BGN + 1 );
//MCU�ܾ�Ӧ��MCU->REC������Ϣ��
OSPEVENT( MCU_REC_REG_NACK,					EV_MCUREC_BGN + 2 );

//MT������REC SERVER״̬����, MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_GETRECSTATUS_REQ,			EV_MCUREC_BGN + 5 );
//����REC SERVER״̬��REC SERVER->MT����Ϣ��TPeriEqpStatus
OSPEVENT( REC_MCU_GETRECSTATUS_ACK,			EV_MCUREC_BGN + 6 );
//�ܾ�����REC SERVER״̬��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_GETRECSTATUS_NACK,		EV_MCUREC_BGN + 7 );
//REC SERVER״̬֪ͨ��REC SERVER->MT����Ϣ��ΪTPeriEqpStatus
OSPEVENT( REC_MCU_RECSTATUS_NOTIF,			EV_MCUREC_BGN + 8 );

/*
 *¼���б�������Ϣ��
 *�ն��յ��������䷢��¼���ļ�֪ͨ��ȫ��������Ϻ���ACK��Ϣ
 *���ն˾ܾ������б��������NACK��Ϣ��
 */
//MT�����ն˸���¼���б����MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_LISTALLRECORD_REQ,		EV_MCUREC_BGN + 10 );
//REC SERVER��Ӧ��(���)��Ϣ��REC SERVER->MT,��Ϣ��ΪTEqp
OSPEVENT( REC_MCU_LISTALLRECORD_ACK,		EV_MCUREC_BGN + 11 );
//REC SERVER�ܾ�¼���б�����REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_LISTALLRECORD_NACK,		EV_MCUREC_BGN + 12 );
//¼����б�֪ͨ��Ϣ��REC SERVER->MT, ��Ϣ��ΪTEqp+TRecFileListNotify
OSPEVENT( REC_MCU_LISTALLRECORD_NOTIF,		EV_MCUREC_BGN + 13 );


//MT������REC SERVER¼��ͨ��״̬����, MT->REC SERVER, ��Ϣ��ΪTEqp���ŵ���λ����Ϣͷ��
OSPEVENT( MCU_REC_GETRECORDCHNSTATUS_REQ,	EV_MCUREC_BGN + 15 );
//����REC SERVER�ŵ�״̬��REC SERVER->MT����Ϣ��TEqp+TRecChnnlStatus
OSPEVENT( REC_MCU_GETRECORDCHNSTATUS_ACK,	EV_MCUREC_BGN + 16 );
//�ܾ�����REC SERVER�ŵ�״̬��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_GETRECORDCHNSTATUS_NACK,	EV_MCUREC_BGN + 17 );
//REC SERVER¼���ŵ�״̬֪ͨ��REC SERVER->MT����Ϣ��ΪTEqp+TRecChnnlStatus
OSPEVENT( REC_MCU_RECORDCHNSTATUS_NOTIF,	EV_MCUREC_BGN + 18 );

//MT������REC SERVER����ͨ��״̬����, MT->REC SERVER, ��Ϣ��ΪTEqp���ŵ���λ����Ϣͷ��
OSPEVENT( MCU_REC_GETPLAYCHNSTATUS_REQ,		EV_MCUREC_BGN + 20 );
//����REC SERVER�ŵ�״̬��REC SERVER->MT����Ϣ��TEqp+TRecChnnlStatus
OSPEVENT( REC_MCU_GETPLAYCHNSTATUS_ACK,		EV_MCUREC_BGN + 21 );
//�ܾ�����REC SERVER�ŵ�״̬��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_GETPLAYCHNSTATUS_NACK,	EV_MCUREC_BGN + 22 );
//REC SERVER�����ŵ�״̬֪ͨ��REC SERVER->MT����Ϣ��ΪTEqp+TRecChnnlStatus
OSPEVENT( REC_MCU_PLAYCHNSTATUS_NOTIF,		EV_MCUREC_BGN + 23 );


//��ȡ¼����ȣ�MT->REC SERVER, ��Ϣ�壺�� (�ŵ���λ����Ϣͷ)
OSPEVENT( MCU_REC_GETRECPROG_CMD,           EV_MCUREC_BGN + 24 );
//MT��ǰ¼�����֪ͨ��Ϣ��REC SERVER->MT����Ϣ��ΪTEqp+TRecProg���ŵ���λ����Ϣͷ
OSPEVENT( REC_MCU_RECORDPROG_NOTIF,			EV_MCUREC_BGN + 25 );

// MT��ȡ������ȣ�MT->REC SERVER����Ϣ�壺�� (�ŵ���λ����Ϣͷ)
OSPEVENT( MCU_REC_GETPLAYPROG_CMD,          EV_MCUREC_BGN + 26 );
//MT��ǰ�������֪ͨ��Ϣ��REC SERVER->MT����Ϣ��ΪTEqp+TRecProg���ŵ���λ����Ϣͷ
OSPEVENT( REC_MCU_PLAYPROG_NOTIF,			EV_MCUREC_BGN + 27 );
//MT�쳣֪ͨ��Ϣ��REC SERVER->MT����Ϣ��ΪTEqp���ŵ��źʹ�����λ����Ϣͷ
OSPEVENT( REC_MCU_EXCPT_NOTIF,				EV_MCUREC_BGN + 28 );


////////////////
//¼����Ϣ
//��Ϣ��ΪTEqp(��¼����ն�, ��������ͬ)
// + TEqp( ��Ҫʹ�õ�¼���) + TRecStartPara + TMediaEncrypt(video) +
//TDoublePayload(video) + TMediaEncrypt(audio) + TDoublePayload(video) +
//TMediaEncrypt(double video) + TDoublePayload(double video) + ¼���� + TCapSupportEx
// MT����¼��MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_STARTREC_REQ,				EV_MCUREC_BGN + 70 );
//REC SERVERͬ��MT¼������Ӧ��REC SERVER->MT����Ϣ��ΪTEqp�����ص��ŵ���λ����Ϣͷ
OSPEVENT( REC_MCU_STARTREC_ACK,				EV_MCUREC_BGN + 71 );
//�ܾ�MT¼��Ӧ��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_STARTREC_NACK,			EV_MCUREC_BGN + 72 );

// MT������ͣ¼��MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_PAUSEREC_REQ,				EV_MCUREC_BGN + 75 );
//REC SERVERͬ����ͣ¼������REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_PAUSEREC_ACK,				EV_MCUREC_BGN + 76 );
//REC SERVER�ܾ���ͣ¼������REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_PAUSEREC_NACK,			EV_MCUREC_BGN + 77 );

//����¼������MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_RESUMEREC_REQ,			EV_MCUREC_BGN + 80 );
//ͬ�����¼��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_RESUMEREC_ACK,			EV_MCUREC_BGN + 81 );
//�ܾ�����¼��,REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_RESUMEREC_NACK,			EV_MCUREC_BGN + 82 );

//ֹͣ¼������MT->REC SERVER����Ϣ��ΪTEqp
OSPEVENT( MCU_REC_STOPREC_REQ,				EV_MCUREC_BGN + 85 );
//ͬ��ֹͣ¼��Ӧ��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_STOPREC_ACK,				EV_MCUREC_BGN + 86 );
//�ܾ�ֹͣ¼��Ӧ��REC SERVER->MT����Ϣ��ΪTEqp
OSPEVENT( REC_MCU_STOPREC_NACK,				EV_MCUREC_BGN + 87 );


//�ı�¼��ģʽ����, ��Ϣ��TEqp �� u8( REC_MODE_NORMAL, REC_MODE_SKIPFRAME )
OSPEVENT( MCU_REC_CHANGERECMODE_REQ,		EV_MCUREC_BGN + 90 );
//ͬ�⣬REC SERVER->MT����Ϣ��Ϊ TEqp 
OSPEVENT( REC_MCU_CHANGERECMODE_ACK,		EV_MCUREC_BGN + 91 );
//���ԣ�REC SERVER->MT����Ϣ��Ϊ TEqp 
OSPEVENT( REC_MCU_CHANGERECMODE_NACK,		EV_MCUREC_BGN + 92 );


//MT����ɾ��REC SERVER�еļ�¼��MT->REC SERVER ,��Ϣ��ΪTEqp+��¼��(0��β�ַ���)
OSPEVENT( MCU_REC_DELETERECORD_REQ,			EV_MCUREC_BGN + 93 );
//REC SERVERͬ�Ⲣ�ɹ�ɾ��¼���ļ�Ӧ��, REC SERVER->MT
//��Ϣ��ΪTEqp
OSPEVENT( REC_MCU_DELETERECORD_ACK,			EV_MCUREC_BGN + 94);
//REC SERVER�ܾ�ɾ��¼�� ��Ϣ��TEqp
OSPEVENT( REC_MCU_DELETERECORD_NACK,		EV_MCUREC_BGN + 95 );


//MT�������REC SERVER��¼�ļ�, MT->REC SERVER
//��Ϣ��ΪTEqp + u8(�ɼ�¼������) + �ɼ�¼�� + u8(�¼�¼������) + �¼�¼��
OSPEVENT( MCU_REC_RENAMERECORD_REQ,			EV_MCUREC_BGN + 96 );
//ͬ�⣬��Ϣ��ΪTEqp
OSPEVENT( REC_MCU_RENAMERECORD_ACK,			EV_MCUREC_BGN + 97 );
//���ԣ���Ϣ��ΪTEqp
OSPEVENT( REC_MCU_RENAMERECORD_NACK,		EV_MCUREC_BGN + 98 );

//����¼������ MT->REC SERVER����Ϣ��ΪTEqp + u8(PUBLISH_LEVEL) + ¼����
OSPEVENT( MCU_REC_PUBLISHREC_REQ,			EV_MCUREC_BGN + 100 );
//ͬ�⣬REC SERVER->MT����Ϣ��Ϊ TEqp
OSPEVENT( REC_MCU_PUBLISHREC_ACK,			EV_MCUREC_BGN + 101 );
//���ԣ�REC SERVER->MT����Ϣ��Ϊ TEqp
OSPEVENT( REC_MCU_PUBLISHREC_NACK,			EV_MCUREC_BGN + 102 );

//ȡ������¼������ MT->REC SERVER����Ϣ��ΪTEqp +  ¼����
OSPEVENT( MCU_REC_CANCELPUBLISHREC_REQ,		EV_MCUREC_BGN + 105 );
//ͬ�⣬REC SERVER->MT����Ϣ��Ϊ TEqp
OSPEVENT( REC_MCU_CANCELPUBLISHREC_ACK,		EV_MCUREC_BGN + 106 );
//���ԣ�REC SERVER->MT����Ϣ��Ϊ TEqp
OSPEVENT( REC_MCU_CANCELPUBLISHREC_NACK,	EV_MCUREC_BGN + 107 );

//REC SERVER����ؼ�֡, REC SERVER->MT
OSPEVENT( REC_MCU_NEEDIFRAME_CMD,	        EV_MCUREC_BGN + 108 );


//�ն���¼�������������ע������MT->REC SERVER����Ϣ��ΪTMtRegReq�ṹ
OSPEVENT( MT_RECSERV_REG_REQ,			    EV_MCUREC_BGN  + 109);
//¼�������������Ӧ��REC SERVER->MT����Ϣ��Ϊ��Ϣ��ΪTMtRegAck
OSPEVENT( RECSERV_MT_REG_ACK,				EV_MCUREC_BGN + 110 );
//¼����������ܾ�Ӧ��REC SERVER->MT������Ϣ��
OSPEVENT( RECSERV_MT_REG_NACK,				EV_MCUREC_BGN + 111 );


#define     MAXNUM_RECORDER_CHNNL			32	//¼������ͨ������(��¼��ͷ���ͨ��)
#define		MAXLEN_EQP_ALIAS                16   //���������󳤶�
#define     MAXLEN_RECORD_NAME              64  //�ϱ�����״̬ʱ¼���ļ����ĳ���


// ¼����ظ�MT��ACK��Ϣ
struct TMtRegAck : public TEqp
{
protected:
	u32   		m_dwIpAddr;		//¼���IP��ַ
	u16 		m_wStartPort;	//¼�����ʼ���ն˿�
	u8  		m_byChannlNum;	//¼��������ŵ���
	s8          m_achAlias[MAXLEN_EQP_ALIAS];
    //4.0R3��չ�ֶ�
    u16         m_wVersion;     //�汾��Ϣ
    //4.5������չ�ֶ�
    BOOL        m_bHDEqp;       //�Ƿ�������裬 ��Чֵ

public:
    TMtRegAck(void) { memset(this, 0, sizeof(TMtRegAck)); }
    //¼�������IP��ַ
    //���룺IP��ַ(������)
	void SetPeriEqpIpAddr( const u32    &dwIpAddr )	{ m_dwIpAddr = dwIpAddr; }
    //���¼���IP��ַ
    //����ֵ��IP��ַ(������)
	u32    GetPeriEqpIpAddr() const	{ return m_dwIpAddr; }
	//����¼���������ʼ�˿�
	void SetStartPort( const u16  & wStartPort )	{ m_wStartPort = htons(wStartPort); }
	//���¼���������ʼ�˿�
	u16  GetStartPort() const	{ return ntohs( m_wStartPort ); }
	//����¼��������ŵ���Ŀ
	void SetChnnlNum( const u8   & byChannlNum )	{ m_byChannlNum = byChannlNum; }
	//���¼��������ŵ���Ŀ
	u8   GetChnnlNum() const	{ return m_byChannlNum; }

	void SetEqpAlias(char* szAlias)
	{
		strncpy( m_achAlias ,szAlias ,sizeof(m_achAlias) );
		m_achAlias[MAXLEN_EQP_ALIAS-1] ='\0';
	}

	LPCSTR GetEqpAlias()
	{
		return m_achAlias;
	}

    void SetVersion(u16 wVersion)
    {
        m_wVersion = htons(wVersion);
    }
    u16 GetVersion() const
    {
        return ntohs(m_wVersion);
    }
    void SetHDEqp(BOOL bHD)
    {
        m_bHDEqp = bHD;
    }
    
    BOOL IsHDEqp() const
    {
        return m_bHDEqp;
    }
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

//����MTע����Ϣ
struct TMtRegReq
{
protected:
	u32   		m_dwIpAddr;			//MT���յ�ַ
	u16 		m_wStartPort;		//MT������ʼ�˿ں�
    u32         m_dwAnotherMpcIp;   //����ʱ������һ��mpc���ַ���������������õı���mpc��ַ����У�飩
	u32         m_dwMsSSrc;         //����ʱ�����ڱ�עһ��ϵͳ���У�ֻҪ��ֵ�仯��˵������������ͬʱ����

public:
	//�õ��ϼ�MT������������IP��ַ
    u32    GetMcuIpAddr( void ) const { return ntohl(m_dwIpAddr); }

	//�����ϼ�MT������������IP��ַ
    void SetMcuIpAddr( u32    dwIpAddr ) { m_dwIpAddr = htonl(dwIpAddr); }

	//�õ��ϼ�MCU�����������ݶ˿ں�
    u16  GetMcuStartPort( void ) const { return ntohs(m_wStartPort); }

    //�����ϼ�MCU�����������ݶ˿ں�
    void SetMcuStartPort( u16  wPort ) { m_wStartPort = htons(wPort); }

    //����һ��mpc���ַ
    u32  GetAnotherMpcIp( void ) const { return ntohl(m_dwAnotherMpcIp); }
    void SetAnotherMpcIp( u32 dwIpAddr ) { m_dwAnotherMpcIp = htonl(dwIpAddr); }
    
    void SetMSSsrc(u32 dwSSrc)
    {
        m_dwMsSSrc = htonl(dwSSrc);
    }
    u32 GetMSSsrc(void) const
    {
        return ntohl(m_dwMsSSrc);
    }
    
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

struct TMTRegInfo
{
    TMtRegReq m_tMtRegReq;
    s8        m_aliase[MAXLEN_RECORD_NAME+1];
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

// �����Ӧ�Ƚ�С�������������
#define RECLIST_PACKSIZE    (u8)16
struct TRecFileListNotify
{
	u16 wListSize;//¼������ļ�����
	u16 wStartIdx;//��֪ͨ����ʼ�ļ����
	u16 wEndIdx;  //��֪ͨ�н����ļ����
    
	s8 achFileName[RECLIST_PACKSIZE][MAXLEN_CONFNAME+MAXLEN_RECORD_NAME+1];
	u8 abyStatus[RECLIST_PACKSIZE];
public:
	TRecFileListNotify()
	{
		wListSize = 0;
		wStartIdx = 0;
		wEndIdx   = 0;
		memset ( achFileName ,0,sizeof(achFileName) );
		memset( abyStatus ,0 ,sizeof(abyStatus) );
	}

	//��ȡ¼�����¼����
	u16 GetListSize()
	{
		return ntohs(wListSize);
	}
	
	//��ȡ��֪ͨ����ʼ�ļ����
	u16 GetStartIdx()
	{
		return ntohs(wStartIdx);
	}

	//��ȡ��֪ͨ����ʼ�ļ����
	u16 GetEndIdx()
	{
		return ntohs(wEndIdx);
	}

	//���ָ����ŵ��ļ���,�粻���ڷ���NULL
	char* GetFileName(u16 wIdx )
	{
		if( wIdx < GetStartIdx() || wIdx > GetEndIdx() )
			return NULL;
		return achFileName[wIdx - GetStartIdx()];
	}

	//�ж�ָ����ŵ��ļ��Ƿ񷢲�
	BOOL IsPublic(u16 wIdx)
	{
		if( wIdx < GetStartIdx() || wIdx > GetEndIdx() )
			return FALSE;
		return abyStatus[wIdx - GetStartIdx()]&0x1 ? TRUE:FALSE;
	}

	//����ָ����ŵ��ļ�����
	BOOL Public(u16 wIdx)
	{
		if( wIdx < GetStartIdx() || wIdx > GetEndIdx() )
			return FALSE;

		abyStatus[wIdx - GetStartIdx()] |=0x1;
		return TRUE;
	}

	/////////////////////////////////////////////
	//����¼�����¼����
	void Reset()
	{
		wListSize = 0;
	    wStartIdx =0;
	    wEndIdx =0;
	    memset( achFileName,0,sizeof(achFileName) );
		memset( abyStatus , 0,sizeof(abyStatus) );
	}
	void SetListSize( u16 wSize)
	{
		wListSize = htons(wSize);
	}
	
	//���ñ�֪ͨ����ʼ�ļ����
	void SetStartIdx( u16 wIdx)
	{
		wStartIdx = htons(wIdx);
	}

	//���ñ�֪ͨ����ʼ�ļ����
	void SetEndIdx( u16 wIdx)
	{
		wEndIdx = htons(wIdx);
	}

	// ����ļ�
	BOOL AddFile(char* filename ,BOOL bPublic = FALSE )
	{
		if ( IsFull() )
			return FALSE;

        u16 wIdx = GetEndIdx() - GetStartIdx();

		strncpy( achFileName[wIdx], filename ,sizeof(achFileName[wIdx]) - 1);
		achFileName[wIdx][sizeof(achFileName)-1]='\0';

		if ( bPublic ) 
        {
            abyStatus[wIdx] |=0x1;
        }
		else 
        {
            abyStatus[wIdx] &=~0x01;
        }

        // ����Զ�����
        SetEndIdx( GetEndIdx() + 1 );
		return TRUE;
	}

	//�жϻ����Ƿ�����
	BOOL32 IsFull()
	{
		u16 wSize = GetEndIdx() - GetStartIdx();
		if( wSize >= RECLIST_PACKSIZE )
			return TRUE;
		return FALSE;
	}

    BOOL32 IsEmpty()
    {
        return (GetEndIdx() == GetStartIdx());
    }
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

//¼����ŵ�״̬
struct TRecChnnlStatus
{
    /*ͨ����״̬*/
    enum ERecChnnlState
    {
        STATE_IDLE       = 0,	  /*������һ��δ��ͨ��*/
            
            STATE_RECREADY   = 11,	  /*׼��¼��״̬  */
            STATE_RECORDING  = 12,	  /*����¼��  */
            STATE_RECPAUSE   = 13,	  /*��ͣ¼��״̬*/
            
            STATE_PLAYREADY  = 21,	  /*׼������״̬ */
            STATE_PLAYREADYPLAY = 22,   /*���ò���׼��״̬*/
            STATE_PLAYING    = 23,	  /*���ڻ򲥷�*/
            STATE_PLAYPAUSE  = 24,	  /*��ͣ����*/
            STATE_FF         = 25,	  /*���(������ͨ����Ч)*/
            STATE_FB         = 26	  /*����(������ͨ����Ч)*/
    };
    
    /*ͨ�����Ͷ���*/
    enum ERecChnnlType
    {
        TYPE_UNUSE      =  0,	/*δʼ�õ�ͨ��*/
            TYPE_RECORD     =  1,	/*¼��ͨ��  */   
            TYPE_PLAY       =  2	/*����ͨ��  */
    };
    
    //¼��ʽ
    enum ERecMode
    {
        MODE_SKIPFRAME = 0,//��֡¼��
            MODE_REALTIME  = 1  //ʵʱ¼��
    };
public:
    u8  		m_byType;		//ͨ�����ͣ�ERecChnnlType
    u8  		m_byState;		//ͨ��״̬��ERecChnnlState
    u8          m_byRecMode;    //¼��ʽ:
    TRecProg	m_tProg;	//��ǰ¼���������
protected:
    char	m_achRecordName[MAXLEN_RECORD_NAME];//��¼��
    
public:
    //��ȡ��¼��
    LPCSTR GetRecordName( void ) const	{ return m_achRecordName; }
    //���ü�¼��
    void SetRecordName( LPCSTR lpszName ) 
    {
        strncpy( m_achRecordName, lpszName, sizeof( m_achRecordName ) );
        m_achRecordName[sizeof( m_achRecordName ) - 1] ='\0';
    }
    
    LPCSTR GetStatusStr( u8 eStatus )
    {
        switch(eStatus) 
        {
        case STATE_IDLE:
            return "IDLE";
            break;
        case STATE_RECREADY:
            return "REC Ready";
            break;
        case STATE_RECORDING:
            return "Recording";
            break;
        case STATE_RECPAUSE:
            return "REC Pause";
            break;
        case STATE_PLAYREADY:
            return "PLAY Ready";
            break;
        case STATE_PLAYING:
            return "Playing";
            break;
        case STATE_PLAYPAUSE:
            return "Play Pause";
            break;
        case STATE_FF:
            return "Play FF";
            break;
        case STATE_FB:
            return "Play FB";
        default:
            return "UNKOWN";
        }
    }
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

//˫�غ�
struct TDoublePayload
{
protected:
    u8  m_byRealPayload;    //ԭý���ʽ
    u8  m_byActivePayload;  //�ý���ʽ
public:
    TDoublePayload()
    {
        Reset();
    }
    void Reset()
    {
        m_byRealPayload = MEDIA_TYPE_NULL;
        m_byActivePayload = MEDIA_TYPE_NULL;
    }
    void SetRealPayLoad(u8 byRealPayload)
    {
        m_byRealPayload = byRealPayload;
    }
    u8 GetRealPayLoad()
    {
        return m_byRealPayload;
    }
    
    void SetActivePayload(u8 byActivePayload)
    {
        m_byActivePayload = byActivePayload;
    }
    
    u8 GetActivePayload()
    {
        return m_byActivePayload;
    }
    
    void Print() const
    {
        OspPrintf(TRUE, FALSE, "m_byRealPayload is %d, m_byActivePayload is %d\n",
            m_byRealPayload, m_byActivePayload);
    }
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;


//¼���״̬, size = 2412
struct TRecStatus
{
protected:
    u8  	m_byRecChnnlNum;		//¼���ŵ�������
    u8  	m_byPlayChnnlNum;		//�����ŵ�������
    u8      m_bSupportPublic;       // �Ƿ�֧�ַ���(TRUE: ֧��, FALSE:��֧��)
    u8      m_byRemain;             // ����
    u32   	m_dwFreeSpace;        //¼���ʣ����̿ռ�(��λΪMB)
    u32   	m_dwTotalSpace;		//¼����ܴ��̿ռ�(��λΪMB)
    TRecChnnlStatus m_tChnnlStatus[MAXNUM_RECORDER_CHNNL];	//��¼���ŵ�������ŵ�
    
public:
    //��ȡ¼��ͨ������
    u8   GetRecChnnlNum( void ) const	{ return( m_byRecChnnlNum ); }
    //��ȡ����ͨ������
    u8   GetPlayChnnlNum( void ) const	{ return( m_byPlayChnnlNum ); }
    //����ͨ������¼��ͷ���ͨ���������벻����MAXNUM_RECORDER_CHNNL
    //ʧ�ܷ���FALSE
    BOOL SetChnnlNum( u8   byRecChnnlNum, u8   byPlayChnnlNum )
    {
        if( byRecChnnlNum + byPlayChnnlNum <= MAXNUM_RECORDER_CHNNL )
        {
            m_byRecChnnlNum = byRecChnnlNum;
            m_byPlayChnnlNum = byPlayChnnlNum;
            return( TRUE );
        }
        else
        {
            OspPrintf( TRUE, FALSE, "TRecStatus: Exception - Wrong recorder and play channel number: %u and %u!\n", 
                byRecChnnlNum, byPlayChnnlNum );
            return( FALSE );
        }
    }
    /*====================================================================
    ����        ������¼���ʣ����̿ռ�
    �������˵����u32    dwFreeSpace  - ʣ��ռ��С(��λ Mb)
    ����ֵ˵��  ����
    ====================================================================*/
    void SetFreeSpaceSize( u32    dwFreeSpace )
    {
        m_dwFreeSpace  = htonl(dwFreeSpace);
    }
    
    /*====================================================================
    ����        ����ȡ¼���ʣ����̿ռ�
    �������˵������
    ����ֵ˵��  ��ʣ��ռ��С(��λ MB)
    ====================================================================*/
    u32    GetFreeSpaceSize( void ) const	{ return ntohl( m_dwFreeSpace ); }
    
    /*====================================================================
    ����        ������¼����ܴ��̿ռ�
    �������˵����u32    dwTotalSpace  - �ܿռ��С(��λ MB)
    ����ֵ˵��  ����
    ====================================================================*/
    void SetTotalSpaceSize( u32    dwTotalSpace )
    {
        m_dwTotalSpace  = htonl( dwTotalSpace );
    }
    // �Ƿ�֧�ַ���
    BOOL IsSupportPublic() const { return m_bSupportPublic;}
    // �����Ƿ�֧�ַ���
    void SetPublicAttribute(BOOL bSupportPublic ) { m_bSupportPublic = bSupportPublic;}
    
    /*====================================================================
    ����        ����ȡ¼����ܴ��̿ռ�
    �������˵������
    ����ֵ˵��  ���ܿռ��С(��λ MB)
    ====================================================================*/
    u32    GetTotalSpaceSize( void ) const	{ return ntohl( m_dwTotalSpace ); }
    
    //����¼����ŵ�״̬��Ϣ������������¼�����ŵ����ٵ��ô˺���
    BOOL SetChnnlStatus( u8   byChnnlIndex, u8   byChnnlType, const TRecChnnlStatus * ptStatus );
    //����¼����ŵ�״̬��Ϣ������������¼�����ŵ����ٵ��ô˺���
    BOOL GetChnnlStatus( u8   byChnnlIndex, u8   byChnnlType, TRecChnnlStatus * ptStatus ) const;
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

//��������״̬�ṹ, size = 2435(TRecStatus = 2412)
struct TPeriEqpStatus : public TEqp
{
public:
    u8  	m_byOnline;		//�Ƿ�����
    union UStatus
    {
        TRecStatus		tRecorder;
    } m_tStatus;
    
protected:
    char    m_achAlias[MAXLEN_EQP_ALIAS];
public:
    //constructor
    TPeriEqpStatus( void )
    {
        memset(this, 0, sizeof(TPeriEqpStatus));
    }
    
    //��ȡ�������
    const s8 * GetAlias() const 
    { 
        return m_achAlias;
    }
    
    //�����������
    void SetAlias(const s8 * lpszAlias)
    { 
        strncpy(m_achAlias, lpszAlias, sizeof(m_achAlias));
        m_achAlias[MAXLEN_EQP_ALIAS-1] = '\0';
    }
    
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;


struct TRecRtcpBack
{
protected:
    u32  m_tVideoIp;      //��ƵRTCP������ַ
    u16  m_tVideoPort;    //��ƵRTCP�����˿�
    u32  m_tAudioIp;      //��ƵRTCP������ַ
    u16  m_tAudioPort;    //��ƵRTCP�����˿�
    u32  m_tDStreamIp;    //˫��RTCP������ַ
    u16  m_tDStreamPort;  //˫��RTCP�����˿�
    
public:
    TRecRtcpBack(void)
    {
        Reset();
    }
    void Reset(void)
    {
        m_tVideoIp = 0xFFFFFFFF;
        m_tVideoPort = 0xFFFF;
        m_tAudioIp = 0xFFFFFFFF;
        m_tAudioPort = 0xFFFF;
        m_tDStreamIp = 0xFFFFFFFF;
        m_tDStreamPort = 0xFFFF;
    }
    
    void SetVideoAddr(u32 dwVideoIp, u16 wVideoPort)
    {
        m_tVideoIp = htonl(dwVideoIp);
        m_tVideoPort = htons(wVideoPort);
    }
    
    void GetVideoAddr(u32 &dwVideoIp, u16 &wVideoPort)
    {
        dwVideoIp = ntohl(m_tVideoIp);
        wVideoPort = ntohs(m_tVideoPort);
    }
    
    
    void SetAudioAddr(u32 dwAudioIp, u16 wAudioPort)
    {
        m_tAudioIp = htonl(dwAudioIp);
        m_tAudioPort = htons(wAudioPort);
    }
    
    void GetAudioAddr(u32 &dwAudioIp, u16 &wAudioPort)
    {
        dwAudioIp = ntohl(m_tAudioIp);
        wAudioPort = ntohs(m_tAudioPort);
    }
    
    
    void SetDStreamAddr(u32 dwDStreamIp, u16 wDStreamPort)
    {
        m_tDStreamIp = htonl(dwDStreamIp);
        m_tDStreamPort = htons(wDStreamPort);
    }
    
    void GetDStreamAddr(u32 &dwDStreamIp, u16 &wDStreamPort)
    {
        dwDStreamIp = ntohl(m_tDStreamIp);
        wDStreamPort = ntohs(m_tDStreamPort);
    }
}
#ifndef WIN32
__attribute__((packed))
#endif
;

#define MAX_REC_FILE_NAME 128
typedef struct tagTRecStartParam
{
public:
	//TEqp			TEqp;
    // �¼ӵ�
    TRecRtcpBack    tRecRtcpBack;
    // �¼ӵ�
    u8              byNeedPrs;          //�Ƿ��ش�
	
	TRecStartPara	tRecStartPara;
	TMediaEncrypt	tPriVideoEncrypt;
	TMediaEncrypt	tSecVideoEncrypt;
	TMediaEncrypt	tAudVideoEncrypt;
	TDoublePayload	tPriPayload;
	TDoublePayload	tSecPayload;
	TDoublePayload	tAudPayload;
	s8				achFileName[MAX_REC_FILE_NAME+1];
	TCapSupportEx	tCapSupportEx;
public:
    tagTRecStartParam()
    {
        memset( this->achFileName, 0, MAX_REC_FILE_NAME+1 );
    };
}TRecStartRaram
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

typedef struct tagErrInfo
{
protected:
    u16 m_wErrCode;                      // Nack����ʱ�Ĵ�����
public:
    //��ȡ������
    u16   GetErrorCode( void ) const	{ return ntohs( m_wErrCode ); }
    //���ô�����
    void  SetErrorCode(u16 wError) 	{ m_wErrCode = htons( wError ); }
}TErrorInfo
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

#define ERR_REC_NOERROR         ERR_REC_BGN + 0        //û�д���
#define ERR_REC_NORECORD        ERR_REC_BGN + 1        //û�м�¼
#define ERR_REC_OPENRECORD      ERR_REC_BGN + 2        //�򿪼�¼ʧ��
#define ERR_REC_UMMATCHCMD      ERR_REC_BGN + 3        //��ƥ������������һ�������豸��ʼ¼��
#define ERR_REC_VALIDCHN        ERR_REC_BGN + 4        //��Ч��ͨ��
#define ERR_REC_RECORDING       ERR_REC_BGN + 5        //����¼��
#define ERR_REC_PLAYING         ERR_REC_BGN + 6        //���ڲ���
#define ERR_REC_NOTPLAY         ERR_REC_BGN + 7        //����ͨ��û�ڲ��� 
#define ERR_REC_NOTRECORD       ERR_REC_BGN + 8        //¼��ͨ��û��¼��
#define ERR_REC_ACTFAIL         ERR_REC_BGN + 9        //ִ��ָ����������ʧ��
#define ERR_REC_CURDOING        ERR_REC_BGN + 10       //����Ķ�����ǰ����ִ��
#define ERR_REC_RCMD_TO_PCHN    ERR_REC_BGN + 11       //һ������ͨ�������¼��ͨ��
#define ERR_REC_PCMD_TO_RCHN    ERR_REC_BGN + 12       //һ��¼��ͨ�����������ͨ��
#define ERR_REC_DISKFULL        ERR_REC_BGN + 13       //������
#define ERR_REC_FILEDAMAGE      ERR_REC_BGN + 14       //�ļ���
#define ERR_REC_FILEEMPTY       ERR_REC_BGN + 15       //���ļ�
#define ERR_REC_FILEUSING       ERR_REC_BGN + 16       //ָ���ļ����ڱ�����
#define ERR_REC_FILENOTEXIST    ERR_REC_BGN + 17       //ָ���ļ�������
#define ERR_REC_PUBLICFAILED    ERR_REC_BGN + 18       //����ʧ��
#define ERR_REC_RENAMEFILE      ERR_REC_BGN + 19       //�ļ�����ͻ,�����ļ���ʧ��
#define ERR_REC_FILEEXISTED     ERR_REC_BGN + 20       //�ļ�����ͻ,�޷�¼��
#define ERR_REC_PLAYERRPAYLOAD  ERR_REC_BGN + 21       //�����ļ�ý���غ���������鲻ƥ��
#define ERR_REC_CALLLIBFAILED   ERR_REC_BGN + 22       //����¼���ʧ��,�������°�װ
#define ERR_REC_SETMOTHODFAILED ERR_REC_BGN + 23       //¼��ʽ����ʧ��
#define ERR_REC_PALYFILERES		ERR_REC_BGN + 24	   //¼���ļ��ֱ���ƫ��
#define ERR_REC_FILENAMETOOLONG ERR_REC_BGN + 25       //�����ļ�������, add by jlb  081026
#define ERR_REC_SERVER_BUSY     ERR_REC_BGN + 27       //�����ļ�������, add by liuxu 100725

#endif