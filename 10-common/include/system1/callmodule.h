#ifndef _CALLMODULE_H
#define _CALLMODULE_H

#include "osp.h"
#include "h323adapter.h"

namespace CallModule
{
	//=======================================
	//��������
	//=======================================
	//����ֵ
	const u32 RET_OK = 1;
	const u32 RET_ERR = 0;

	//�����������
	const u32 MAX_CAP_NUM	 = 16;

	

	//=======================================
	//ö������
	//========��==============================
	//��ӡ����
	enum LOG_LEVLE
	{
		LOG_ERROR = 0,
		LOG_IMPORTANT = 1,
		LOG_HINT = 224,
		LOG_DETAIL = 255,
	};
	
	//=======================================
	//�ṹ����
	//=======================================
	//����������
	typedef struct tagCapDes
	{
	public:
		//��������(enum PayloadType)
		u32 m_capName;
		//�������
		u32 m_maxBitrate;
	public:
		tagCapDes()
		{
			Reset();
		}
		void Reset()
		{
			m_capName = 0;
			m_maxBitrate = 0;
		}
	}TCapDes;
	//�ص���Ϣ����
	typedef struct tagCallBackEvent
	{
	public:
		//�ص���Ϣ����app id
		u32 m_callbackAid;	
		//Э��ջ��ʼ�����		��Ϣ��TRUE/FALSE
		u16 m_eventStackInit;	
		//ע����֪ͨ			��Ϣ��TRUE/FALSE
		u16 m_eventRegResult;	
		//�Զ�����֪ͨ			��Ϣ��TParamPeerCap
		u16 m_eventPeerCapTable;
		//�Զ�RTCP/RTP��ַ֪ͨ  ��Ϣ��TParamPeerAddr
		u16 m_eventPeerDataAddr;
		//�����º���			��Ϣ��TCallHandle
		u16 m_eventNewCallCreate;
		//�º��е���			��Ϣ��TParamNewCall
		u16 m_eventNewCallComing;
		//��������֪ͨ			��Ϣ��TCallHandle
		u16 m_eventCallConnected;
		//���жϿ�֪ͨ			��Ϣ��TCallHandle
		u16 m_eventCallDisconnected;
		//�µ��ŵ�����			��Ϣ��TCallHandle
		u16 m_eventNewChanCreate;

	public:
		tagCallBackEvent()
		{
			Reset();
		}
		void Reset()
		{
			m_callbackAid = 0;	
			m_eventStackInit = 0;
			m_eventRegResult = 0;
			m_eventPeerCapTable = 0;
			m_eventPeerDataAddr = 0;
			m_eventNewCallCreate = 0;
			m_eventNewCallComing = 0;
			m_eventCallConnected = 0;
			m_eventCallDisconnected = 0;
			m_eventNewChanCreate = 0;
		}
	}TCallBackEvent;

	//���о��
	typedef struct tagTCallHandle
	{
	private:
		HCALL		m_hsCall;
		HCHAN		m_hsChan;
		HAPPCALL	m_haCall;
		HAPPCHAN	m_haChan;
	public:
		tagTCallHandle()
		{
			m_hsCall = 0;
			m_hsChan = 0;
			m_haCall = 0;
			m_haChan = 0;
		}
	public:
		void SetHCall(HCALL hsCall)
		{
			m_hsCall = hsCall;
		}

		HCALL GetHCall() const
		{
			return m_hsCall;
		}
		
		void SetHaCall(HAPPCALL haCall)
		{
			m_haCall = haCall;
		}

		HAPPCALL GetHaCall() const
		{
			return m_haCall;
		}
		
		void SetHChan(HCHAN hsChan)
		{
			m_hsChan = hsChan;
		}

		HCHAN GetHChan() const
		{
			return m_hsChan;
		}
		void SetHaChan(HAPPCHAN haChan)
		{
			m_haChan = haChan;
		}

		HAPPCHAN GetHaChan() const
		{
			return m_haChan;
		}
	}TCallHandle;

	typedef struct tagParamNewCall : public TCallHandle
	{
	private:
		TCALLPARAM m_tCallParam;
	public:
		void SetCallParam(const TCALLPARAM&  tCallParam)
		{
			memcpy(&m_tCallParam,&tCallParam,sizeof(TCALLPARAM));
		}
		void  GetCallParam(TCALLPARAM& tCallParam) const 
		{
			memcpy(&tCallParam,&m_tCallParam,sizeof(TCALLPARAM));
		}
	}TParamNewCall;
	
	typedef struct tagParamPeerAddr : public TCallHandle
	{
	private :
		TNETADDR m_netAddr;
	public :
		void SetNetAddr(const TNETADDR&  tAddr)
		{
			m_netAddr = tAddr;
		}
		void  GetNetAddr(TNETADDR& tAddr) const 
		{
			tAddr = m_netAddr;
		}
	}TParamPeerAddr;

	typedef struct tagParamPeerCap : public TCallHandle
	{
	private :
		TCapSet m_tCap;
	public :
		void SetCap(const TCapSet&  tCap)
		{
			m_tCap = tCap;
		}
		void  GetCap(TCapSet& tCap) const 
		{
			tCap = m_tCap;
		}
	}TParamPeerCap;
	//=======================================
	//�ඨ��
	//=======================================
	//������Ϣ
	class  CCallInfo
	{
	private:
		HCALL m_hsCall;
		BOOL  m_bCaller;
	public:
		CCallInfo()
		{
			Reset();
		}
		BOOL IsHcallMatch(HCALL hsCall)
		{
			if(hsCall == NULL)
			{
				return FALSE;
			}
			else
			{
				return hsCall == m_hsCall;
			}
		}
		BOOL IsCaller()
		{
			return m_bCaller;
		}
		void Reset()
		{
			m_bCaller = FALSE;
			m_hsCall = NULL;
		}
		BOOL IsNull()
		{
			if (m_hsCall == NULL)
				return TRUE;
			return FALSE;
		}

		void SetHCall(HCALL hsCall)
		{
			m_hsCall = hsCall;
		}
		void SetCaller(BOOL bCaller = TRUE)
		{
			m_bCaller = bCaller;
		}
	};

	class CCallInfoArray
	{
	private:
		CCallInfo* m_pCallInfoArray;
		u32 m_arraySize;
	public:
		CCallInfoArray(){m_pCallInfoArray = NULL;}
		BOOL NewArray(u32 size)
		{
			m_pCallInfoArray = new CCallInfo[size];
			m_arraySize = size;
			return (BOOL)m_pCallInfoArray;
		}
		void  DestoryArray(){delete[] m_pCallInfoArray;}
		BOOL IsCaller(HCALL hsCall)
		{
			if (m_pCallInfoArray == NULL)
			{
				return FALSE;
			}
			for (u32 i = 0 ; i < m_arraySize; i++)
			{
				if (m_pCallInfoArray[i].IsHcallMatch(hsCall))
				{
					return m_pCallInfoArray[i].IsCaller();
				}

			}
			return FALSE;
		}

		BOOL RemoveCallInfo(HCALL hsCall)
		{
			if (m_pCallInfoArray == NULL)
			{
				return FALSE;
			}
			for (u32 i = 0 ; i < m_arraySize; i++)
			{
				if (m_pCallInfoArray[i].IsHcallMatch(hsCall))
				{
					m_pCallInfoArray[i].Reset();
					return TRUE;
				}

			}
			return FALSE;
		}

		BOOL AddCallInfo(HCALL hsCall,BOOL bCaller)
		{
			if (m_pCallInfoArray == NULL)
			{
				return FALSE;
			}
			for (u32 i = 0 ; i < m_arraySize; i++)
			{
				if (m_pCallInfoArray[i].IsNull())
				{
					m_pCallInfoArray[i].SetHCall(hsCall);
					m_pCallInfoArray[i].SetCaller(bCaller);
					return TRUE;
				}

			}
			return FALSE;
		}

		BOOL  SetCaller(HCALL hsCall)
		{
			if (m_pCallInfoArray == NULL)
			{
				return FALSE;
			}
			for (u32 i = 0 ; i < m_arraySize; i++)
			{
				if (m_pCallInfoArray[i].IsHcallMatch(hsCall))
				{
					m_pCallInfoArray[i].SetCaller();
					return TRUE;
				}

			}
			return FALSE;
		}
		
	};

	//����ģ��
	class CCallModule
	{
	protected:
		static TCallBackEvent m_tCallbackEvent;	//�ص���Ϣ�ṹ
		static BOOL			  m_bStackRun;		//Э��ջ�Ƿ�����
		static BOOL			  m_isRegistered;	//�Ƿ�ע����GK
		static TCapSet 		  m_tCap;			//��������
		static TNETADDR		  m_tRtpAddr;		//����T120RTP��ַ
		static CCallInfoArray m_cCallArray;		//������Ϣ
	public:
		CCallModule();
		~CCallModule();
	public:
		//====================================
		//��ʼ���ӿ�
		//====================================
		//��ʼ������ģ��
		u32 InitCallModule();

		//====================================
		//���ýӿ�
		//====================================
		//�����߼��ŵ���ַ
		u32 SetChanAddress(const TNETADDR& rtpAddr);

		//����������
		u32 SetCapabilityTable(const TCapSet& tCap);

		//���ûص�Ӧ�ú���Ϣ
		u32 SetCallbackEvent(const TCallBackEvent& tCallbackEvent);

		//====================================
		//���ƽӿ�
		//====================================
		//��GKע��
		u32 UnRegisterToGK();

		//��GKע��
		u32 RegisterToGK(TRRQINFO& rasRegisterInfo);

		//�������
		u32 MakeCall(const TParamNewCall & tCallParam);

		//���պ���
		u32 AnswerCall(const TCallHandle& tCallHandle);

		//�ҶϺ���
		u32 HangUp(const TCallHandle& tCallHandle);

	public:
		//=====================================
		//Э��ջ����,�����ڵ����߳��е���Э��ջ����
		//=====================================
		//��ʼ��Э��ջ
		static u32 InitH323Stack(u16 CallingPort=1720, u16 LocalRasPort=1719);
		//����Э��ջ
		static u32 DestoryH323Stack();

	public:
		//=====================================
		//����ص�����
		//=====================================
		static int KDVCALLBACK EvChanCtrlMsg(HAPPCALL haCall,
												HCALL hsCall,
												HAPPCHAN haChan,
												HCHAN hsChan,
												u16 msgType, 
												const void* pBuf,
												u16 nBufLen
		);
		
		static int KDVCALLBACK EvConfCtrlMsg(HAPPCALL haCall, 
												HCALL hsCall,
												u16 msgType,
												const void* pBuf,
												u16 nBufLen);

		static int KDVCALLBACK EvNewCall(HCALL hsCall,
											LPHAPPCALL lphaCall);

		static int KDVCALLBACK EvNewChan(HAPPCALL haCall,
											HCALL hsCall,
											HCHAN hsChan,
											LPHAPPCHAN lphaChan);

		static int KDVCALLBACK EvCallCtrlMsg(HAPPCALL haCall,
												HCALL hsCall,
												u16 msgType,
												const void* pBuf,
												u16 nBufLen);

		static int KDVCALLBACK EvRasCtrlMsg(    HAPPCALL haCall,
												HCALL hsCall,
			                                    HAPPRAS haRAS,
												HRAS hsRas,
												u16 msgType,
												const void* pBuf,
												u16 nBufLen);


		//�ص���Ϣ
		static void NotifyCallBackApp(u16 msgId,void* pContent,u32 len);




	};
}
#endif 
