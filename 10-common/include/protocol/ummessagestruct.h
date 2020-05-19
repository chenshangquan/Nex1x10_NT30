#ifndef _MESSAGESTRUCT_H_
#define _MESSAGESTRUCT_H_

#include "umconst.h"
#include "pfc.h"
#include "md5.h"
#include "protocolcommonpublic.h"

#ifdef WIN32
    #pragma pack( push )
    #pragma pack( 1 )
#endif
API void umver();
class CLoginRequest
{
private:
#ifndef KDVTYPE_LEGACY_H
	char		m_achname[MAX_CHARLENGTH + 1]; ///< �û���
	char		m_achpassword[MAX_CHARLENGTH + 1];///< ����
#else
    char		m_achname[MAX_CHARLENGTH]; ///< �û���
    char		m_achpassword[MAX_CHARLENGTH];///< ����
#endif
	CMD5Encrypt m_cMd5;
public:
	CLoginRequest()
	{
		memset(m_achname,0,sizeof(m_achname) );
		memset(m_achpassword,0,sizeof(m_achpassword) );
	}
	/// ���ú͵õ��û���
	char* GetName()
	{
		return m_achname;
	}
	void  SetName(char* pchbuf)
	{
		if(pchbuf == NULL)
		{
			return;
		}
		memset(m_achname,0,sizeof(m_achname));
#ifndef KDVTYPE_LEGACY_H
		int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH ? MAX_CHARLENGTH: strlen(pchbuf));
#else
        int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH-1 ? MAX_CHARLENGTH-1: strlen(pchbuf));
#endif
		memcpy(m_achname,pchbuf,nlength);
		m_achname[nlength] = '\0';
	};
	/// ���ú͵õ�����
	char* GetPassword()
	{
		return m_achpassword;
	}
	/// ��������Ϊ����
	void  SetPassword(char* pchbuf)
	{
		
		m_cMd5.GetEncrypted(pchbuf,m_achpassword);
#ifndef KDVTYPE_LEGACY_H
		m_achpassword[MAX_CHARLENGTH]='\0';
#else
        m_achpassword[MAX_CHARLENGTH-1]='\0';
#endif
	}
	/// ����������Ѿ�������
	void SetEncryptedPassword(char* pchbuf)
	{
		memcpy(m_achpassword,pchbuf,sizeof(m_achpassword));
#ifndef KDVTYPE_LEGACY_H
		m_achpassword[MAX_CHARLENGTH]='\0';
#else
        m_achpassword[MAX_CHARLENGTH-1]='\0';
#endif
	}
	void Empty()
	{
		memset(m_achname,0,sizeof(m_achname));
		memset(m_achpassword,0,sizeof(m_achpassword));
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;

class PROTO_API CUserFullInfo
{
// private:
public: // ��������Ա��С [pengguofeng 5/9/2013]
	CMD5Encrypt m_cMd5;
public:	
#ifndef KDVTYPE_LEGACY_H
	u32     m_dwGuid;	///< ÿ������Ψһ��Ӧһ��guid
	char		m_achname[MAX_CHARLENGTH+1]; ///< �û���
	char		m_achpassword[MAX_CHARLENGTH+1];///< ����
	u8			m_byActor;///< Ȩ��
	char		m_achfullname[MAX_CHARLENGTH+1];///< �����û���
	char		m_achdiscription[2*MAX_CHARLENGTH+1];///< �û�����
    u64         m_dwExpiryDate;///< ����ʧЧʱ��
#else
    char		m_achname[MAX_CHARLENGTH]; ///< �û���
    char		m_achpassword[MAX_CHARLENGTH];///< ����
    u8			m_byActor;///< Ȩ��
    char		m_achfullname[MAX_CHARLENGTH];///< �����û���
    char		m_achdiscription[2*MAX_CHARLENGTH];///< �û�����
#endif
public:
	CUserFullInfo()
	{
		Empty();
	}
	~CUserFullInfo(){};
	/// �õ��û���
	char* GetName()
	{
#ifndef KDVTYPE_LEGACY_H
		m_achname[MAX_CHARLENGTH] = '\0';
#else
        m_achname[MAX_CHARLENGTH-1] = '\0';
#endif
		return m_achname;
	}
	/// �����û���
	void  SetName(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achname,0,sizeof(m_achname));
		int nlength = (strlen(pchbuf) >= sizeof(m_achname)-1 ? sizeof(m_achname)-1: strlen(pchbuf));
		memcpy(m_achname,pchbuf,nlength);
		m_achname[nlength] = '\0';
	}
	/// �õ�����
	char* GetPassword()
	{
		return m_achpassword;
	}
	/// ��������
	void  SetPassword(char* pchbuf)
	{
		m_cMd5.GetEncrypted(pchbuf,m_achpassword);
#ifndef KDVTYPE_LEGACY_H
		m_achpassword[MAX_CHARLENGTH]='\0';
#else
        m_achpassword[MAX_CHARLENGTH-1]='\0';
#endif
	}
	/// �Ѿ����ܵ�����
	void  SetEncryptedPassword(char* pchbuf)
	{
		memcpy(m_achpassword,pchbuf,sizeof(m_achpassword));
#ifndef KDVTYPE_LEGACY_H
		m_achpassword[MAX_CHARLENGTH]='\0';
#else
        m_achpassword[MAX_CHARLENGTH-1]='\0';
#endif
	}
	/// �õ��û�������
	char* GetFullName()
	{
		return m_achfullname;
	}
	/// �����û�������
	void SetFullName(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achfullname,0,sizeof(m_achfullname));
		int nlength = (strlen(pchbuf) >= sizeof(m_achfullname)-1 ? sizeof(m_achfullname)-1: strlen(pchbuf));
		memcpy(m_achfullname,pchbuf,nlength);
		m_achfullname[nlength] = '\0';
	}
	/// �õ��û�����
	char* GetDiscription()
	{
		return m_achdiscription;
	}
	
	/// �����û�����
	void SetDiscription(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achdiscription,0, sizeof(m_achdiscription));
		int nlength = (strlen(pchbuf) >= sizeof(m_achdiscription)-1 ?  sizeof(m_achdiscription)-1: strlen(pchbuf));
		memcpy(m_achdiscription,pchbuf,nlength);
		m_achdiscription[nlength] = '\0';
	}
	/// �õ�Ȩ��
	unsigned char   GetActor(){return m_byActor;}
	/// ����Ȩ��
	void  SetActor(unsigned char byActor){ m_byActor = byActor;}
	/// ����ֵ
	const CUserFullInfo& operator=(const CUserFullInfo& cNewInfo)
	{
		if (this != &cNewInfo)
		{
			memcpy(this, &cNewInfo, sizeof(CUserFullInfo));
		}
		return *this;
	}

	///  ȡ���г�Ա�ĳ��� [pengguofeng 5/14/2013]
	unsigned char GetMemLen( const unsigned char &byMemId )
	{
		u8 byRet = 0;
		switch ( byMemId)
		{
		case 0:
			byRet = sizeof(m_cMd5.context.state);
			break;
		case 1:
			byRet = sizeof(m_cMd5.context.count);
			break;
		case 2:
			byRet = sizeof(m_cMd5.context.buffer);
			break;
		case 3:
			byRet = sizeof(m_achname);
			break;
		case 4:
			byRet = sizeof(m_achpassword);
			break;
		case 5:
			byRet = sizeof(m_byActor);
			break;
		case 6:
			byRet = sizeof(m_achfullname);
			break;
		case 7:
			byRet = sizeof(m_achdiscription);
			break;
#ifndef KDVTYPE_LEGACY_H
		case 8:
			byRet = sizeof(m_dwGuid);
			break;
		case 9:
			byRet = sizeof(m_dwExpiryDate);
			break;
#endif
		default:
			break;
		}

		return byRet;
	}
	/// �ж�ĳһ����Ա�Ƿ�Ϊ�ַ���,0 1 2����MD5����Ϣ�������޸�
	bool IsMemString(const unsigned char &byMemId)
	{
		if ( byMemId == 3
			|| byMemId == 4
			|| byMemId == 6
			|| byMemId == 7
		/*	|| byMemId == 8
			|| byMemId == 9
		*/
			)
		{
			return TRUE;
		}
		return FALSE;
	}
	/// �ж��û����Ƿ���ͬ
	bool IsEqualName(char* cNewName)
	{
		if (strlen(m_achname) != strlen(cNewName) || strlen(cNewName) == 0 )
			return FALSE;
		for (unsigned int dwIndex=0 ; dwIndex< strlen(m_achname) ; dwIndex++)
		{
			if (m_achname[dwIndex] != cNewName[dwIndex])
				return FALSE;
		}
		return TRUE;
	}	
	/// �жϿ����Ƿ���ͬ
	bool IsPassWordEqual(char* pchNewPass)
	{
		size_t dwLen = strlen( pchNewPass );
		if ( dwLen > strlen(m_achpassword) )
		{
			dwLen = strlen(m_achpassword);
		}
		for (size_t i=0 ; i< dwLen; i++)
		{
			if (m_achpassword[i] != pchNewPass[i])
				return FALSE;
		}
		return TRUE;
	}
	/// �ҵ��յ�
	bool IsEmpty()
	{
		/*if ( strlen(m_achpassword) > 16 )
		      return FALSE;*/
		for (int i=0; i<16; i++)
		{
			if (m_achpassword[i]!=0)
			{
				return FALSE;
			}
		}
		return TRUE;
	}
	/// ���
	void Empty()
	{
		memset(this, 0, sizeof(CUserFullInfo));
		m_byActor = UM_OPERATOR;
	}	

#ifndef KDVTYPE_LEGACY_H
    /// �����������ʱ��
    void SetOutdate(u64 dwExpiryDate)
    {
        m_dwExpiryDate = dwExpiryDate;
    }

    /// ��ȡ�������ʱ��
    u64 GetOutdate()
    {
        return m_dwExpiryDate;
    }
#endif

}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;
class CLongMessage
{
public:
	u8 m_uTotal; ///< ��Ϣ��֡��
	u8 m_uCurr;  ///< ��ǰָ֡ʾ
	u8 m_uNumUsr;///< ��ǰ֡�е��û���
public:
	CLongMessage()
	{
		Reset();
	}
	~CLongMessage(){};
public:
	void Reset()
	{
		m_uTotal = 0;
		m_uCurr =  0;
		m_uNumUsr = 0;
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;
#ifdef WIN32
#pragma pack( pop )
#endif
#endif
