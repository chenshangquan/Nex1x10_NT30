/******************************************************************************
ģ����  �� PFC - Platform/Protocol foundation classes
�ļ���  �� pfc.h
����ļ���
�ļ�ʵ�ֹ���:   Origined from OSP(Ver: CBB 5.0 20170727) to implement both support for 32bit and 64 bit OS.
                For protocol team related modules use only.
                ultimate goal would be merge this module back into OSP whenever OSP is ready.
����    ��Τ����
�汾    ��1.0.0.1
---------------------------------------------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
09/15/98        1.0      ĳĳ        ------------
******************************************************************************/

#ifndef _PFC_H
#define _PFC_H

#include "protocolcommonpublic.h"

#if (defined(__APPLE__) && defined(__MACH__)) || (defined(macintosh) || defined(Macintosh)) || defined(__MACOSX__)
    #define _IOS_PLATFORM_
    #define _LINUX_
#endif // for ios

#ifdef _IOS_PLATFORM_

#if defined(_LP64) || defined(LP64_) || defined(LP64) || defined(_LP64_)
#ifndef PFC64BIT
#define PFC64BIT
#endif //PFC64BIT
#endif // LP64

#if defined(__LP64__) || defined(LP64) || defined(__LP64) || defined(LP64__)
#ifndef PFC64BIT
#define PFC64BIT
#endif //PFC64BIT
#endif // LP64

#endif //IOS


/**
 * @defgroup    pfc Platform/Protocol foundation classes
 * @brief       Platform/Protocol foundation interfaces.
 * @{
 */

//#define _ENABLE_SOCK5_API_
//#define _ENABLE_SERIAL_API_
#define PFC_ENABLE_IPV6

///////////////////////////////////////////////////////////////////
//	Linux ����ϵͳͷ�ļ�
///////////////////////////////////////////////////////////////////
#if (defined(_LINUX_) || defined(_IOS_PLATFORM_))
#ifdef PWLIB_SUPPORT
#include <ptlib.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#ifdef _IOS_PLATFORM_
#include <malloc/malloc.h>
#else
#include <malloc.h>
#endif
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/times.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <termios.h>
#include <signal.h>
#include "syslog.h"

/* 5.0�ϲ��� ����Androidƽ̨֧�� */
#if defined(_ANDROID_)
#include <sys/epoll.h>
#include <fcntl.h>
#elif (!(defined(_EQUATOR_) || defined(_IOS_PLATFORM_)))
#include <mqueue.h>
#include <sys/epoll.h>
#include <sys/resource.h>
#endif
#endif //_LINUX_

///////////////////////////////////////////////////////////////////
//	Vxworks ����ϵͳͷ�ļ�
///////////////////////////////////////////////////////////////////
#ifdef _VXWORKS_

#include <vxworks.h>
#include <tasklib.h>
#include <msgqlib.h>
#include <syslib.h>
#include <string.h>
#include <memLib.h>
#include <stdlib.h>
#include <string.h>
#include <sockLib.h>
#include <inetLib.h>
#include <stdioLib.h>
#include <strLib.h>
#include <hostLib.h>
#include <ioLib.h>
#include <assert.h>
#include <netdb.h>
#include <errno.h>
#include <sys/stat.h>
#include <taskHookLib.h>
#include <logLib.h>
//����֧��
#include "brddrvlib.h"

#endif // _VXWORKS_

///////////////////////////////////////////////////////////////////
//	Win32 ����ϵͳͷ�ļ�
///////////////////////////////////////////////////////////////////
#ifdef _MSC_VER
#pragma warning(disable:4127)
#pragma warning(disable:4996)
//lint -e728

#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif

#ifdef WINVER
#undef WINVER
#endif
/* vc is vs2005 and later */
#if (_MSC_VER >= 1400)
#define _WIN32_WINNT 0x0501 //support only winxp and above
#define WINVER 0x0501 //support only winxp and above
#else
#define _WIN32_WINNT 0x400
#define WINVER 0x0400
#endif

#include <malloc.h>
#include <time.h>
#include <process.h>
#ifdef _AFXDLL
#include <afx.h>
#include <afxwin.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#endif

#include <assert.h>
#pragma comment(lib,"Ws2_32.lib")

#endif  // _MSC_VER

#include "kdvtype.h"

///////////////////////////////////////////////////////////////////
//	����ϵͳ����������Ͷ���
///////////////////////////////////////////////////////////////////
#ifdef _LINUX_
    #define TRUE                    1                       ///< TRUE
    #define FALSE                   0                       ///< FALSE
    typedef void *(*LINUXFUNC)(void *);                     ///< Common callback function definition
    #define PFCSEMHANDLE            pthread_cond_t*         ///< PFC sem handle
    #define PFCTASKHANDLE           pthread_t               ///< PFC thread handle
    #define PFCTASKID				PFCTASKHANDLE           ///< PFC thread id
#endif  // _LINUX_

#ifdef _VXWORKS_
    #define PFCSEMHANDLE            SEM_ID                  ///< PFC sem handle for vxworks
    #define PFCTASKHANDLE           u32                     ///< PFC thread handle for vxworks
#endif  // _VXWORKS_

#ifndef _MSC_VER
    /* 5.0�ϲ��� ȥ��u64����, u64�Ѿ�������kdvtype.h��. */
    //	typedef unsigned long long    u64;
    #define PFCSOCKHANDLE           int                     ///< PFC socket handle
    #ifndef SOCKADDR
        #define SOCKADDR            sockaddr                ///< PFC sock address
    #endif
    #define SOCKADDR_IN             sockaddr_in             ///< PFC sockaddr_in
    #define SOCKADDR_IN6            sockaddr_in6            ///< PFC sockaddr_in6
#endif  // _MSC_VER

#ifdef _MSC_VER
    #define PFCSEMHANDLE            HANDLE                  ///< PFC sem handle
    #define PFCTASKHANDLE           HANDLE                  ///< PFC thread handle
    #define PFCSOCKHANDLE           SOCKET                  ///< PFC sock handle
#endif  // _MSC_VER

///////////////////////////////////////////////////////////////////
//	����ϵͳ��غ궨��
///////////////////////////////////////////////////////////////////
#ifdef _LINUX_
    #define SOCKET_ERROR          (-1)                      ///< SOCKET error
    #define INVALID_SOCKET        (-1)                      ///< Invalid socket handle
    #define OSP_NO_WAIT           0                         ///< no wait
    #define OSP_WAIT_FOREVER      (-1)                      ///< wait forever
#endif // _LINUX_

#ifdef _VXWORKS_
    #define SOCKET_ERROR          ERROR
    #define INVALID_SOCKET        ERROR
    #define INVALID_SERIALHANDLE  ERROR
    #define OSP_NO_WAIT           NO_WAIT
    #define OSP_WAIT_FOREVER      WAIT_FOREVER
#endif  // _VXWORKS_

#ifdef _MSC_VER
    #define INVALID_SERIALHANDLE  INVALID_HANDLE_VALUE
    #define OSP_NO_WAIT           ((int)0)
    #define OSP_WAIT_FOREVER      ((int)-1)
#endif  // _MSC_VER

///////////////////////////////////////////////////////////////////
//	����ϵͳ�޹غ궨��
///////////////////////////////////////////////////////////////////
// for Microsoft c++
#ifdef _MSC_VER

//������
#ifndef _EQUATOR_
#pragma pack(push)
#pragma pack(1)
#endif

#define API extern "C"          __declspec(dllexport)
#define PFC_API                 __declspec(dllexport)

// for gcc
#else

#define API extern "C"
#define PFC_API

#endif  // _MSC_VER


/// PFC�汾��Ϣ
#define PFCVERSION              "PFC.1.0.1.20170727"

/// PfcSockShutdown����
#define STOP_RECV               0
#define STOP_SEND               1
#define STOP_BOTH               2

#define PFC_VERSION_ID          0x52            ///< PFC�汾��

#ifndef MULTI_LISTEN_SOCKET_SUPPORT
    #define MULTI_LISTEN_SOCKET_SUPPORT 1       ///< 5.0�ϲ��� ԭ��ҵ���ԣ�֧��һ��PFC�������PFC server
#endif

#ifdef MULTI_LISTEN_SOCKET_SUPPORT
    const u32 PFC_MAX_LISTEN_SOCK_NUM    = 16;  ///< 5.0�ϲ��� ����֧�ֵ�PFC server����
#endif //MULTI_LISTEN_SOCKET_SUPPORT

/// ͬһ������Ӧ����
/* 5.0�ϲ���  ����app����, ��512����4096, ����app������AppPool�����ĸ����ڴ� */
const u16 PFC_MAX_APP_NUM            = 4096;
const u16 PFC_MAX_INST_NUM           = 65000;   ///< ͬһӦ�����ʵ����
const u16 PFC_MAX_TIMER_NUM          = 5000;    ///< ���ʱ����
const u8  PFC_MAX_SERIALPORT_NUM     = 10;      ///< ��󴮿���

#define INVALID_NODE             0              ///< ��Ч���ⲿ����
#define LOCAL_NODE               0              ///< ���ؽ���
#define INVALID_APP              0              ///< ��Ч��Ӧ�ú�
#define LOCAL_APP                0              ///< ����ȫ��Ӧ�ú�
#define INVALID_INS              0xfffb         ///< ��Ч��ʵ����
#define LOCAL_INS                0              ///< ����ʵ����
#define DEFAULT_TCP_HEARTBEAT_TIME      10      ///< Ĭ��TCP�������ʱ����(��)
#define DEFAULT_TCP_HEARTBEAT_NUM       3       ///< Ĭ��TCP����������(��μ���ʧ����Ϊ�Ѿ�����)
#define DEFAULT_STATUS_MSGOUT_TIME      3600    ///< Ĭ��OSPϵͳ״̬��ӡʱ����(��)
#define UNDETECT_TCP_HEARTBEAT          0       ///< ������TCP�������

#ifndef MINCHAR
    #define MINCHAR                 0x80
#endif

#ifndef MAXCHAR
    #define MAXCHAR                 0x7f
#endif

#ifndef MINSHORT
    #define MINSHORT                0x8000
#endif

#ifndef MAXSHORT
    #define MAXSHORT                0x7fff
#endif

#ifndef MINLONG
    #define MINLONG                 0x80000000
#endif

#ifndef MAXLONG
    #define MAXLONG                 0x7fffffff
#endif

#ifndef MAXBYTE
    #define MAXBYTE                 0xff
#endif

#ifndef MAXWORD
    #define MAXWORD                 0xffff
#endif

#ifndef MAXDWORD
    #define MAXDWORD                0xffffffff
#endif

#ifdef _ENABLE_SERIAL_API_
    #include "pfc_serial.h"
#endif

#if (defined(_MSC_VER) && (_MSC_VER > 1200)) || !defined(_MSC_VER)
/**
* @brief    PfcNetAddr
* @note     5.0�ϲ��� ����IP��ַ���͵Ķ���
* @pre      windows ҪVS2010����ʹ��ipv6
*/
typedef union tagPfcNetAddr
{
    struct sockaddr_in		v4addr;                 ///< ipv4��ַ
    struct sockaddr_in6		v6addr;                 ///< ipv6��ַ
    struct sockaddr_storage staddr;                 ///< socket��ʾ�ĵ�ַ
    u8  raw_addr[sizeof(struct sockaddr_storage)];  ///< socket�޷���ʾ��˽�е�ַ����
} TPfcNetAddr;
#else
/**
* @brief    PfcNetAddr
* @note     5.0֮ǰ�汾�����IP��ַ���͵Ķ���
*/
typedef union tagPfcNetAddr
{
    struct sockaddr_in		v4addr;                 ///< ipv4��ַ
    u8 raw_addr[128];                               ///< ���ַ��
} TPfcNetAddr;
#endif

/// ���ݽ��ţ�APP�źͱ���ʵ���Ź���ȫ��ʵ��ID
inline u32  PFC_MAKEIID( u16 app, u16 ins = 0 , u8 = 0 )
{
	return u32(app << 16) + ins;
}

/// ��ID�л��Ӧ�ú�
inline u16 PFC_GETAPP( u32 GlobIID )
{
	return (u16)(GlobIID >> 16);
}

/// ��ID�л�����غ�
inline u8 PFC_GETGATE( u32 = 0 )
{
	return 0;
}

/// ��ID�л��ʵ����
inline u16 PFC_GETINS( u32 GlobIID )
{
	return (u16)(GlobIID);
}

/// ��ID�л��ʵ���ŵĵ��ֽ�
inline u8 PFC_GETINSL( u32 GlobIID )
{
	return (u8)(GlobIID);
}

/// ��ID�л��ʵ���ŵĸ��ֽ�
inline u8 PFC_GETINSH(u32 GlobIID)
{
	return (u8)(GlobIID >> 8);
}

/// telnet�ն���ʾ����󳤶�
#define MAX_PROMPT_LEN          21

/// PFC������
enum EM_PFC_ERRORCODE
{
    PFC_ERROR_BASE              = 0,
    PFC_OK                      = (PFC_ERROR_BASE + 0),     ///< �����ɹ�
    PFC_ERROR                   = (PFC_ERROR_BASE + 1),     ///< ����ʧ��
    PFC_ERR_SEND_FAIL           = (PFC_ERROR_BASE + 2),     ///< δʹ��
    PFC_ERR_SEND_TIMEOUT        = (PFC_ERROR_BASE + 3),     ///< ����ͬ����Ϣ��ʱ
    PFC_ERR_SYNCACK_EXCEED      = (PFC_ERROR_BASE + 4),     ///< ͬ����ϢӦ�𳬳�
    PFC_ERR_ALIAS_REPEAT        = (PFC_ERROR_BASE + 5),     ///< ͬһӦ����ʵ�������Ѿ�����
    PFC_ERR_APP_REPEAT          = (PFC_ERROR_BASE + 6),     ///< δʹ��
    PFC_ERR_NODE_INVALID        = (PFC_ERROR_BASE + 7),     ///< �ⲿ������Ч
    PFC_ERR_ILLEGAL_PARAM       = (PFC_ERROR_BASE + 8),     ///< ������Ч
    PFC_ERR_PEER_NOT_RESPOND    = (PFC_ERROR_BASE + 9),     ///< ͬ����Ϣ�Զ���Ӧ��
};

#define MAX_MSG_LEN             (u16)0xffff                 ///< �����Ϣ���� /* 5.0�ϲ��� ����ԭ��ҵ���飬 ԭ��ҵ��Ϣ��󳤶�Ϊ0x8000*/
#define MAX_ALIAS_LEN           (u8)255                     ///< ʵ��������󳤶�
#define MAX_SYNCACK_LEN         MAX_MSG_LEN                 ///< ���ͬ����ϢӦ�𳤶�
#define MAX_DATA_LEN            (MAX_MSG_LEN+MAX_ALIAS_LEN+MAX_SYNCACK_LEN) ///< ������ݳ���(δʹ��)

/// PFC��Ϣ����
enum EM_PFC_MSGTYPE
{
    PFC_MSG_TYPE_ASYNC              = (u16)0,               ///< �첽��Ϣ
    PFC_MSG_TYPE_SYNC               = (u16)1,               ///< ͬ����Ϣ
    PFC_MSG_TYPE_SYNCACK            = (u16)2,               ///< ͬ��Ӧ����Ϣ
    PFC_MSG_TYPE_GSYNC              = (u16)3,               ///< ȫ��ͬ����Ϣ
    PFC_MSG_TYPE_GSYNCACK           = (u16)4,               ///< ȫ��ͬ��Ӧ����Ϣ
    PFC_MSG_TYPE_TIMEOUT            = (u16)5,               ///< ��ʱ��Ϣ
    PFC_MSG_TYPE_RAWMSG             = (u16)6,               ///< 5.0�ϲ��� ԭ��ҵ���ж��壬 raw��Ϣ����
};

#define PFC_NEXTSTATE(x)            NextState(x,#x)         ///< �л�ʵ��״̬��
#define PFC_OSP_USEREVENT_BASE      (u16)0x0400             ///< PFC �û��Զ�����Ϣ�¼��Ż�׼(С�ڸ�ֵ����ϢΪPFC������Ϣ���ϲ��ֹ���͸���Ϣ)
#define PFC_OSPEVENT(x,y)           const u16 x = y         ///< ������Ϣ�¼���

PFC_OSPEVENT(PFC_OSP_CONFIRM,       0xff);                  ///< δʹ��
PFC_OSPEVENT(PFC_OSP_POWERON,       0x100);                 ///< �����������
PFC_OSPEVENT(PFC_OSP_SWITCHMASTER,  0x101);                 ///< δʹ��
PFC_OSPEVENT(PFC_OSP_SWITCHSLAVE,   0x102);                 ///< δʹ��
PFC_OSPEVENT(PFC_OSP_OVERFLOW,      0x103);                 ///< ������޿���ʵ��
PFC_OSPEVENT(PFC_OSP_EXCEPTION_IND, 0x104);                 ///< δʹ��
PFC_OSPEVENT(PFC_OSP_INSNOTEXIST,   0x105);                 ///< δʹ��
PFC_OSPEVENT(PFC_OSP_DISCONNECT,    0x106);                 ///< ��Զ�˽���TCP��·�Ѷ�
PFC_OSPEVENT(PFC_OSP_BROADCASTACK,  0x107);                 ///< �㲥��Ϣȷ��Ӧ��
PFC_OSPEVENT(PFC_OSP_NODECLOSE,     0x108);                 ///< δʹ��
PFC_OSPEVENT(PFC_OSP_NETBRAECHO,    0x109);                 ///< �������̽����Ϣ
PFC_OSPEVENT(PFC_OSP_NETBRAECHOACK, 0x110);                 ///< �������̽����Ϣȷ��Ӧ��
PFC_OSPEVENT(PFC_OSP_QUIT,          0x120);                 ///< OSPж����Ϣ
PFC_OSPEVENT(PFC_OSP_NETSTATEST,    0x121);                 ///< ����ͨ�Ų�����Ϣ
PFC_OSPEVENT(PFC_OSP_NETSTATESTACK, 0x122);                 ///< ����ͨ�Ų�����Ϣȷ��Ӧ��
PFC_OSPEVENT(PFC_OSP_APPCONN_ACK,   0x123);                 ///< δʹ��

/// Trc���ٱ�־
typedef enum PFC_TRCOPTION
{
    PFC_TRCSTATE     = 1,                                   ///< ����״̬Ǩ��
	PFC_TRCEVENT     = 2,                                   ///< �����¼�
	PFC_TRCTIMER     = 4,                                   ///< ���ٶ�ʱ��
} PFC_TRCOPTION;

#define PFC_TRCALL     (u16)(PFC_TRCSTATE|PFC_TRCEVENT|PFC_TRCTIMER)    ///< ״̬ԾǨ���¼�����ʱ��������

/// 1.1���Ժ�֧��ͬ����Ϣ
#if (defined PFC_VERSION_ID) && (PFC_VERSION_ID >= 0x11)
#define PFC_SYNCMSG
#endif

#ifdef _LINUX_
/**
 * @brief       CTiPfcStream
 * @note        �������紫������������
 * �κ�һ���ṹҪ�������ϴ��䣬��д��һ�������������У�
 * Ȼ��Ѵ�����������OSP����OSP������
 * ��Ҫ��ֱ��ʹ�ô���һ���ṹ
 */
class CTiPfcStream
{
public:
    u32 m_dwCurrSize;                                   	///< ��ǰ���ݳ���
	u8 m_achData[MAX_MSG_LEN];                              ///< ��ǰ����

    /// Construction
	CTiPfcStream()
	{
		m_dwCurrSize = 0;
		memset(m_achData, 0, sizeof(m_achData));
	}
	/// 5.0�ϲ��� ԭ��ҵ���У� ����raw��Ϣ
	BOOL32 IsRawMsg()
	{
		return !memcmp(m_achData , "kedacom" , 7);
	}
    /// Get raw stream data length
	u32 GetRawLen()
	{
		u32 *pLen = (u32 *)(m_achData + 7);
		return htonl(*pLen);
	}

    /// Pack the stream element
	u32  PackElement(const u8 *pData, u32 dwLen);
    /// Unpack the stream element
	u32  ExtractElement(u8 *pData, u32 dwLen);
};

#define PackElement2(data)  PackElement((u8*)&data, sizeof(data))
#define ExtractElement2(data)   ExtractElement((u8*)&data, sizeof(data))

/// PFC��Ϣͷ���ṹ
class CTiMessage
{
public:
    u32 srcnode;                                            ///< Դ���
    u32 dstnode;                                            ///< Ŀ�Ľ��
    u32 dstid;                                              ///< Ŀ��Ӧ��ʵ��
    u32 srcid;                                              ///< ԴĿ��ʵ��
    u16 type;                                               ///< ��Ϣ����
    u16 event;                                              ///< ��Ϣ��
    u16 length;                                             ///< ��Ϣ�峤��
    u8 *content;                                            ///< ��Ϣ��

    /// ���֧��ͬ����Ϣ
#ifdef PFC_SYNCMSG
    u8 *output;                                             ///< ͬ����ϢӦ��
    u16 outlen;                                             ///< ͬ����ϢӦ�𳤶�
    u16 expire;                                             ///< δʹ��
#endif
    char *dstAlias;                                         ///< ʵ������
    u8 dstAliasLen;                                         ///< ʵ����������

#ifndef _MSC_VER
    /// �õ�PFC��Ϣͷ������
	static u32 GetPackedSize()
	{
		return sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u16) +
			   sizeof(u16) + sizeof(u16) + sizeof(u32) +
#ifdef PFC_SYNCMSG
			   sizeof(u32) + sizeof(u16) + sizeof(u16) +
#endif
			   sizeof(u32) + sizeof(u8);
	}
#elif defined(PFC64BIT)
	static u32 GetPackedSize()
	{    
		return sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u16) +
			sizeof(u16) + sizeof(u16) + sizeof(u32) +
#ifdef PFC_SYNCMSG
			sizeof(u32) + sizeof(u16) + sizeof(u16) +
#endif

			sizeof(u32) + sizeof(u8);
	}    
#else //32bit
    /// �õ�PFC��Ϣͷ������
	static u32 GetPackedSize()
	{
		return sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u16) +
			   sizeof(u16) + sizeof(u16) + sizeof(u8 *) +
#ifdef PFC_SYNCMSG
			   sizeof(u8 *) + sizeof(u16) + sizeof(u16) +
#endif
			   sizeof(char *) + sizeof(u8);
	}

#endif
    void Pack(CTiPfcStream &tStream);                       ///< OSP��Ϣͷ�����
    void Extract(CTiPfcStream &tStream);                    ///< PFC��Ϣͷ�����
};

#else
/// PFC��Ϣͷ���ṹ
typedef struct CTiMessage
{
    
    u32 srcnode;                                            ///< Դ���
    u32 dstnode;                                            ///< Ŀ�Ľ��
    u32 dstid;                                              ///< Ŀ��Ӧ��ʵ��
    u32 srcid;                                              ///< ԴĿ��ʵ��
    u16 type;                                               ///< ��Ϣ����
    u16 event;                                              ///< ��Ϣ��
    u16 length;                                             ///< ��Ϣ�峤��
    u8 *content;                                            ///< ��Ϣ��
    /// ���֧��ͬ����Ϣ
#ifdef PFC_SYNCMSG
    u8 *output;                                             ///< ͬ����ϢӦ��
    u16 outlen;                                             ///< ͬ����ϢӦ�𳤶�
    u16 expire;                                             ///< δʹ��
#endif
    char *dstAlias;                                         ///< ʵ������
    u8 dstAliasLen;                                         ///< ʵ����������
}

/// ������
#if defined(_VXWORKS_) || (defined(_LINUX_) && !defined(_EQUATOR_))
__attribute__ ((packed))
#endif
CTiMessage;
#endif

/// ʵ����Ҫ��Ϣ
typedef struct
{
	u32 state;                                              ///< State
	u16 insid;                                              ///< instance id
	u16 evtrcv;                                             ///< total received events
	u16 evtsnd;                                             ///< total sent events
} TTiInstInfo;

/// 5.0�ϲ��� ԭ��ҵ���нӿڣ���������Ϣ�����ڵ�Ļص�
typedef BOOL32 (*CB_FUNC_PFC_CREATE_RAW_NODE)(int nNodeId , u16 *pwAid, u32 dwAddr , u16 wPort);

/// 5.0�ϲ��� ԭ��ҵ���нӿڣ�����app��������Ϣ�Ļص�
typedef void (*CB_FUNC_PFC_RCV_RAW_MSG)(MemId dwContext, int nNodeId , const char *pchMsg , u32 dwLen );
#define MAX_INSTINFO_NUM           100                      ///< ����Ӧ���пɱ�������ʵ����Ҫ��Ϣ����

#if defined(PWLIB_SUPPORT) && defined(_LINUX_)
/// Ӧ�ó�����࣬��Ҫ���ڶ����û�Appģ��zTemplate
class CTiApp : public PThread
#else
/// Ӧ�ó�����࣬��Ҫ���ڶ����û�Appģ��zTemplate
struct PFC_API CTiApp
#endif
{
#if defined(PWLIB_SUPPORT) && defined(_LINUX_)
	PCLASSINFO(CTiApp, PThread);
#endif

public:
    u32 msgIncome;                                          ///< Ӧ�ý�����Ϣ����
    u32 msgProcessed;                                       ///< Ӧ���Ѵ�����Ϣ����
    u32 msgWaiting;                                         ///< Ӧ�������д��������Ϣ���� - δʹ��
    u32 msgWaitingTop;                                      ///< Ӧ�������д��������Ϣ������ֵ
    u32 timerProcessed;                                     ///< �Ѽ����Ķ�ʱ��Ϣ����
    u32 maxMsgWaiting;                                      ///< Ӧ�����������Ϣ����
    u32 msgdropped;                                         ///< ����������������Ϣ����
    char *pAppName;                                         ///< Ӧ�ñ���
    kdvHandle queSendId;                                    ///< Ӧ��������д���
    kdvHandle queRcvId;                                     ///< Ӧ������������

    /// Ϊ֧��ͬ����Ϣ�����ӵ���Ϣ���ݶ��У����ͬ����Ϣ���ͺ�Ӧ��ʱ��Ϣ
	/// ��Ӧ����Ϣ����֮ǰ��������Ϣ
    u32 bakQueMsgNum;                                       ///< Ӧ�ñ������е���Ϣ����
    kdvHandle bakQueSendId;                                 ///< Ӧ�ñ�����д���
    kdvHandle bakQueRcvId;                                  ///< Ӧ�ñ���������

    u32 taskID;                                             ///< Ӧ������ID

    CTiMessage *curMsgRcv;                                  ///< ��ǰ�յ�����Ϣ
    u16 scrnTraceFlag;                                      ///< ��Ļtrc��־
    u16 fileTraceFlag;                                      ///< �ļ�trc��־
    u16 appId;                                              ///< Ӧ��ID
    u16 wLastIdleInstID;                                    ///< Ӧ��ǰһ������ʵ����
    u16 curEvtSnd;                                          ///< ��ǰ���͵���Ϣ��
    u8 scrnLogFlag;                                         ///< ��Ļlog����
    u8 fileLogFlag;                                         ///< �ļ�log����

    PFCTASKHANDLE hAppTask;                                 ///< Ӧ��������
    PFCSEMHANDLE tSemMutex;                                 ///< Ӧ�������ź������

    u8 byAppPri;                                            ///< Ӧ���������ȼ�

    /// ���ڼ�¼ʵ�����״̬���յ����ݵĻ��л���
    u8 byInstInfoHead;                                      ///< loop buffer header
    u8 byInstInfoTail;                                      ///< loop buffer tail
    TTiInstInfo tInstInfo[MAX_INSTINFO_NUM];                ///< loop buffer

    /// 5.0�ϲ��� ԭ��ҵosp���нṹ�� ����raw��Ϣ
    CB_FUNC_PFC_RCV_RAW_MSG m_cbMsg;                        ///< raw msg call back function pointer
    MemId                 m_dwContext;                      ///< raw msg call back user context

    BOOL32 bDropFlag;                                       ///< drop msg indication

public:
    /// Construction
#if defined(_LINUX_) && defined(PWLIB_SUPPORT)
	CTiApp() : PThread(200 << 10)
#else
	CTiApp()
#endif
	{
		msgIncome = 0;
		msgProcessed = 0;
		timerProcessed = 0;
		maxMsgWaiting = 0;
		msgdropped = 0;
		msgWaitingTop = 0;
		pAppName = NULL;
		queSendId = 0;
		queRcvId = 0;
		bakQueMsgNum = 0;
		bakQueSendId = 0;
		bakQueRcvId = 0;
		taskID = 0;
		scrnTraceFlag = 0;
		fileTraceFlag = 0;
		scrnLogFlag = 0;
		fileLogFlag = 0;
		appId = INVALID_APP;
		byAppPri = 100;
		wLastIdleInstID = 0;
		hAppTask = 0;
#ifndef _LINUX_
		tSemMutex = NULL;
#endif
		byInstInfoHead = 0;
		byInstInfoTail = 0;

		curMsgRcv = NULL;
		curEvtSnd = 0;

		m_cbMsg = NULL;
		m_dwContext = 0;

		bDropFlag = FALSE;
	}

	virtual ~CTiApp()
	{
		scrnTraceFlag = 0;
		fileTraceFlag = 0;
		scrnLogFlag = 0;
		fileLogFlag = 0;
	}

	/// ����ʵ���Ų�ѯָ��ʵ��
	virtual class CTiInstance *GetInstance(u16 insid) = 0;
	/// �趨ʵ������
	virtual BOOL32 SetInstAlias(u16 insid, const char *pAlias, u8 len) = 0;
	/// ���ݱ�����ѯָ��ʵ��
	virtual class CTiInstance *FindInstByAlias(const char *pAlias, u8 len) = 0;
	/// �õ�Ӧ�����ʵ����
	virtual int GetInstanceNumber(void) = 0;
	/// �õ�ʵ��������󳤶�
	virtual u8 GetMaxAliasLen(void) = 0;
	/// ��ʼ��ʵ��������¼��Ϣ
	virtual BOOL32  InitAliasArray(void) = 0;
	/// ���ʵ��������¼��Ϣ
	virtual BOOL32  ClearInstAlias(u16 insid, const char *pAlias, u8 len) = 0;

    /// @brief          CreateApp
	/// @note           ����Ӧ��
	/// APP������ȼ�Ϊ80�����С��80��OSP��ǿ��Ϊ80���˺�, �û����Ե���PfcSetAppPriority��CApp::SetPriority�������ȼ�.
	/// @return         �ɹ�����PFC_OK��ʧ�ܷ���PFC_ERROR
	/// @pre            5.0�ϲ��� �޸�char* Ϊconst char*
	int CreateApp( const char *name, u16 aid, u8 pri, u16 queuesize = 80, u32 uStackSize = 200 << 10 );
	/** \pre 5.0�ϲ��� ԭ��ҵosp���нӿڣ���������Ϣ�ص����� **/
	void SetAppCallBack(CB_FUNC_PFC_RCV_RAW_MSG cbMsg , MemId dwContext);
	/// �趨Ӧ���������ȼ�
	BOOL32 SetPriority(u8 byPrior);
	/// ��ѯ�������ȼ�
	u8 GetPriority(void)
	{
		return byAppPri;
	}
    void QuitApp(void);	                                ///< Ӧ���˳�

    BOOL32 BakMsgNumInc(void);	                        ///< Ӧ�ñ�������Ϣ�������Ӳ�ѯ
    BOOL32 BakMsgNumDec(void);	                        ///< Ӧ�ñ�������Ϣ�������ٲ�ѯ
	u32 GetBakMsgNum(void);                             ///< Ӧ�ñ�������Ϣ����

    u32 GetMsgIncomeNum(void);	                        ///< Ӧ����������Ϣ����
    void MsgIncomeNumInc(void);	                        ///< Ӧ����������Ϣ������ѯ����
    void MsgIncomeNumDec(void);	                        ///< Ӧ����������Ϣ������ѯ����

    void MsgProcessedNumInc(void);	                    ///< Ӧ�ô�����Ϣ��������
    u32 GetMsgWaitingNum(void);	                        ///< ��ѯ���������Ϣ����
    void SetName(const char *pName);	                ///< Ӧ�ñ����趨
    char *NameGet(void);	                            ///< Ӧ�ñ�����ѯ

    void TimerProcessedIncrease(void);	                ///< ��ʱ������������
    void LogLevelSet(u8 file_level, u8 screen_level);	///< �趨�ļ���Ļlog����
    void TrcFlagSet(u16 file_flag, u16 screen_flag);	///< �趨�ļ���Ļtrc��־
    void InstInfoShow(void);	                        ///< ʵ����Ҫ��Ϣ��ӡ
    void InstInfoAdd(u16 ins, u32 state, u16 evtrcv, u16 evtsnd);	///< ʵ����Ҫ��Ϣ����
    void DropFlagSet(BOOL32 bDropFlag);	                ///< �����Ƿ�����Ϣ��־

#if defined(_LINUX_) && defined(PWLIB_SUPPORT)
	void Main(void);        ///< pwlib pure virtual function
#endif
};

/// ʵ����ʱ����Ϣ
typedef  struct TiTInstTimerInfo
{
	TiTInstTimerInfo *next ;        ///< next instance
	u32 timerId ;                   ///< timer id
	void *timerBlkAdrr ;            ///< timer block address
} TiTInstTimerInfo;

/// @pre 5.0�ϲ��� ԭ��ҵ��ʱ���ĵײ�ṹ��ʹ��ҵ�����ֱ�ӷ��ʵײ㶨ʱ��״̬
/// Timer block definition
struct TiTmBlk
{
	/// ��ʱ���ƿ�
	TiTmBlk *suc;		            ///< ��һ��ʱ����ƿ顣
	TiTmBlk *pre;		            ///< ��һ��ʱ����ƿ顣
	u64 tick;                       ///< Tick counter
	u16 appId;                      ///< Timer app id
	u16 instId;                     ///< Timer instance id
	u16 timerId;                    ///< Timer id
	u32 param;                      ///< param, user context? should it be a MemId typed variant?
	u32 settedTick;                 ///< Setted tick counter
	u16 timeToLeft;                 ///< Time left to be triggered
	time_t absTime;                 ///< ���Զ�ʱ��ʱʱ��
	BOOL32 bExtendMode;             ///< �Ƿ�ʹ����չģʽ��Ĭ�ϲ�ʹ��
	u8  *pExtContent;               ///< ��չ����
	u16  dwExtLength;               ///< ��չ���ݵĳ���
};

#define  PFCTIMERHANDLE  TiTmBlk*   ///< Timer block redifinition

/// CInstance�������淶��
/// ����Osp��Ӧ�ñ���Ӹ�CInstance��������һ�������Instance�࣬
/// ������һ��InstanceEntry()��Ա�����ľ���ʵ��
class PFC_API CTiInstance
{
public:
    /// Instance states
	enum
    {
        PENDING,		        ///< ����ʵ��
        EACH = 0xffff,		    ///< �㲥
        EACH_ACK = 0xfffe,		///< �㲥��Ҫ��ȷ��Ӧ��
        CONN_ACK = 0xfffd,		///< δʹ��
        DAEMON = 0xfffc,		///< �ػ�ʵ��
        INVALID = 0xfffb		///< Ŀ��ʵ��ʵ������Ч��������Ч
	};

public:
    u16 m_appId;	            ///< Ӧ�ú�
    u16 m_instId;	            ///< ʵ����
    char m_alias[MAX_ALIAS_LEN];///< ʵ������
    u8 m_aliasLen;	            ///< ʵ����������
    u8 m_maxAliasLen;	        ///< ʵ��������󳤶�
    u32 m_curState;	            ///< ��ǰ״̬��
    u32 m_lastState;	        ///< ��һ��״̬��

public:
	/// �ػ�ʵ����ں���
	virtual void DaemonInstanceEntry( CTiMessage *const, CTiApp *)
	{
		log( 0, (char *)"PFC: message received in default daemon instance of app %d.\nCheck your daemon implementation, please!\n", GetAppID() );
	}
	/// ʵ����ں���
	virtual void InstanceEntry( CTiMessage *const pMsg) = 0;
	/// ʵ����ӡ����
	virtual void InstanceDump(MemId lpParam = NULL)
	{
	}
	/// �ػ�ʵ����ӡ����
	virtual void DaemonInstanceDump(MemId lpParam = NULL)
	{
	}
	/// ʵ���˳�
	virtual void InstanceExit(void)
	{
	}

	/// �趨ʵ������
	int SetAlias(const char *pchAlias, u8 len);
	/// ɾ��ʵ������
	void DeleteAlias(void);
	/// ��ѯʵ������
	BOOL32 GetAlias(char *aliasBuf, u8 bufLen, u8 *aliasLen);
	/// ��ѯʵ����������
	u8 GetAliasLen(void);

	/// ��ѯ��һ��ʵ��״̬��
	u32         LastState();
	/// ��ѯ��ǰʵ��״̬��
	u32         CurState();

	/// ��ѯӦ�ú�
	u16         GetAppID();
	/// ��ѯʵ����
	u16         GetInsID();

	/// ��ʱ���ź���
	PFCSEMHANDLE      m_tSemTimerList;
	/// ��ʱ����Ϣ����
	TiTInstTimerInfo  m_timerInfoListHead;

	/// ���붨ʱ����Ϣ
	void AddInstTimerInfo(u32 nTimerNo , void *pTimerAddr);
	/// ɾ����ʱ����Ϣ
	void DelInstTimerInfo(u32 nTimerNo);
	/// ��ѯ��ʱ����Ϣ
	void *FindInstTimerInfo(u32 nTimerNo);
	/// ɾ�����ж�ʱ����Ϣ
	void DelAllInstTimerInfo();
	/* 5.0�ϲ��� ���������ӿ�����ҵ���нӿڣ� �ṩ��ʱ���ĵײ���� */
	/// ������Զ�ʱ
	int SetTimer(PFCTIMERHANDLE *pTimerHandle, u32 dwTimer, long uMilliSeconds, const void *content, u16 length );
	/// ȡ����ʱ
	int KillTimer(PFCTIMERHANDLE hTimerHandle);
protected:
	/// ������Զ�ʱ
	int SetTimer( u32 nTimer, long nMilliSeconds, u32 nPara = 0 );
	/// ���þ��Զ�ʱ
	int SetAbsTimer( u32 nTimer, u16 nYear, u8 nMon, u8 nDay, u8 nHour, u8 nMin, u8 nSec, u32 nPara = 0 );
	/// ȡ����ʱ
	int KillTimer(u32 nTimerNo);
	/// ȡ�����Զ�ʱ��
	int KillAbsTimer( u32 nTimerNo);
	/// ʵ����ӡ,�ɵ���PfcSetLogLevel�޸Ĵ�ӡ����
	void log(u8 level, const char *format, ...);
	/// �л�״̬��
	void NextState(u32 state, char *s = 0 );

	/// �����첽��Ϣ��Ŀ��ʵ������ʵ���ű�ʶ
	int post(u32 dstiid, u16 event, const void *content = 0, u16 length = 0, u32 dstnode = 0);
	/// �����첽��Ϣ(Ŀ��ʵ������ʵ��������ʶ)
	int post(const char *dstalias, u8 aliaslen, u16 dstapp, u16 event,
			 const void *content = 0, u16 length = 0, u32 dstnode = 0);

	/// ����ͬ����Ϣ��Ŀ��ʵ������ʵ���ű�ʶ
	int send(u32 dstiid, u16 event, const void *content = 0, u16 length = 0, u32 dstnode = 0,
			 void *ackbuf = NULL, u16 ackbuflen = 0, u16 *realacklen = NULL,
			 u16 timeout = 1000);
	/// ����ͬ����Ϣ��Ŀ��ʵ������ʵ��������ʶ
	int send(const char *dstalias, u8 aliaslen, u16 dstapp, u16 event,
			 const void *content = 0, u16 length = 0, u32 dstnode = 0,
			 void *ackbuf = NULL, u16 ackbuflen = 0, u16 *realacklen = NULL,
			 u16 timeout = 1000);

	/// ����ͬ����ϢӦ��
	int SetSyncAck(const void *ack = NULL, u16 ackLen = 0);
	/// ����ͬ����ϢӦ�𡣽���ʹ��SetSyncAck
	int reply(const void *ack = NULL, u16 ackLen = 0);
};

/// ���������û�App���ģ��
class CTiAppNoData
{
};

/// ʵ���������ٲ��Ҽ�¼����
typedef struct TTiInstAliasInfo
{
    u32  aliasRet;	            ///< ʵ������������ֵ��Ҳ�Ǵ�ŵ�λ���±�
    u32  nextLoc;	            ///< ��ͬ����ֵ����һ��ʵ�����λ��
    u16  instId;	            ///< ʵ����
} TTiInstAliasInfo;

/// Ӧ��ģ�塣ģ�����Ϊʵ���ļ̳����Լ����ʵ��ʵ����
template <class I, int maxins = 1, class A = CTiAppNoData, u8 maxAliasLen = 0>
class zTiTemplate: public CTiApp, public A
{
public:
	/// ����ʵ������
	BOOL32 SetInstAlias(u16 insid, const char *pchAlias, u8 len);
	/// ���ʵ��������¼��Ϣ
	BOOL32  ClearInstAlias(u16 insid, const char *pAlias, u8 len);

private:
	/// �ɾֲ�ʵ���Ų���ʵ��
	CTiInstance *GetInstance(u16 insid);
	/// �ɱ�������ʵ��
	CTiInstance *FindInstByAlias(const char *pchAlias, u8 len);
	/// �����ͨʵ������
	int GetInstanceNumber(void);
	/// �������������
	u8 GetMaxAliasLen(void);

private:
	/// daemonʵ��
	I daemIns;
	/// ��ͨʵ����
	I insarray[maxins];

	/// ʵ���������ٲ���
	/// ʵ��������¼��Ϣ��ͷ��
	TTiInstAliasInfo instAliasArray[maxins];
	/// ʵ��������¼��Ϣ���ñ���¼������ͬ��ʵ��
	TTiInstAliasInfo bakInstAliasArray[maxins];
	/// ��ǰ���ñ��м�¼��ʵ������
	u32 curBakArrayNum;

	/// ��ʼ��ʵ��������¼��Ϣ
	BOOL32 InitAliasArray();
	/// ʵ������ת����WORD32������
	u32 AliasToWord(char *pchAlias, u8 len);
	/// ȷ��ʵ��������Ϣ��������ñ����ڱ��ñ���
	BOOL32 IsInBakArray(u32 setRet);
};

/**
* @brief        PfcLog
* @note         ȫ��log��������������Ŀ�����Ӧ�ú�0������PfcSetLogLevel(0,xx)�Ϳ��Կ��Ƹú����Ĵ򿪻�ر�
* @param[in]    level   : log level
* @param[in]    format  : message format
* @return       void
*/
API void PfcLog(u8 level, const char *format, ...);

/**
* @brief        PfcMsgDumpSet
* @note         set long msg dump detail can/not be whole print, default is printf 10 lines
* @param[in]    LgMsgDumpEnbl : [in] enable or not
* @return       void
*/
API void PfcMsgDumpSet(BOOL32 LgMsgDumpEnbl);

/**
* @brief        PfcStatusMsgOutSet
* @note         set status message can or not be out put every timer
* @param[in]    OutMsgEnable : [in] enable or not
* @return       void
*/
API void PfcStatusMsgOutSet(BOOL32 OutMsgEnable);

/**
* @brief        PfcPrintf
* @note         ����Ӧ��������ʾ����Ļ,�洢���ļ�,��������
* @param[in]    bScreen     : �Ƿ��������Ļ,
* @param[in]    bFile       : �Ƿ�������ļ�,
* @param[in]    szFormat    : ��ʽ
*/
API void PfcPrintf(BOOL32 bScreen, BOOL32 bFile, const char *szFormat, ...);

/**
* @brief        PfcTelAuthor
* @note         ����Telnet����Ȩ�û��������롣vxworks���û���������Ϊ�ջ�����ʧ�ܡ�
* @param[in]    szUsername  : authorization user name
* @param[in]    szPassword  : password for the authorization user
*/
API void PfcTelAuthor(const char *szUsername = NULL , const char *szPassword = NULL );

/**
* @brief        pfcver
* @note         output compile version info to screen
*/
API void pfcver();

/**
* @brief        PfcCat
* @note         output file content to screen
* @param[in]    fname : [in] file to be opened
*/
API void PfcCat(const char  *fname);

#ifdef _LINUX_	
/// callback function pointer when PFC quit is triggered
typedef void (*PPfcQuitFunc)(int);
/**
* @brief        PfcRegQuitFunc
* @note         ע�������˳���������linux����Ч
* @param[in]    pQuitFunc  : �����˳�����
* @return       TRUE - ע��ɹ�
  ====================================================================*/
API BOOL32 PfcRegQuitFunc( PPfcQuitFunc pQuitFunc );

/**
* @brief        PfcRegTaskInfo
* @note         ע��������Ϣ����linux����Ч
* @param[in]    dwTaskId :�����
* @param[in]    szName : �������
*/
API void PfcRegTaskInfo(u64 dwTaskId, const char *szName);

/**
* @brief        PfcUnRegTaskInfo
* @note         ��ע��������Ϣ
* @param[in]    dwTaskId  : �����
*/
API BOOL32 PfcUnRegTaskInfo(u64 dwTaskId);

/**
* @brief        PfcTaskShow
* @note         ��ӡ������Ϣ����linux����Ч
*/
API void PfcTaskShow();

/**
* @brief        PfcRegCommand
* @note         ע�������Telnet��ִ�еĺ������ú�������linux����Ч��windows�²���ע�ᡣ
* @param[in]    szName : Telnet�����������
* @param[in]    pfFunc : ��Ӧ�ĺ���ָ��
* @param[in]    szUsage: ����İ�����Ϣ
*/
API void PfcRegCommand(const char *szName, void *pfFunc, const char *szUsage);
#endif

/**
* @brief        PfcNodeConnTest
* @note         test a node's network connection
* @param[in]    dwNodeId : [in] id of the node
*/
API void PfcNodeConnTest(u32 dwNodeId);

/**
* @brief        PfcNodeIpGet
* @note         ���ָ������Ip��ַ
* @param[in]    dwNodeId : [in] node id
* @return       �ɹ����ؽ��IP, ʧ�ܷ���0.
*/
API u32 PfcNodeIpGet(u32 dwNodeId);

/**
* @brief        PfcNodeLocalIpGet
* @note         ��ȡ�ڵ�ı��ص�ַ
* @pre          �����Ѿ����ӵ�tcp�ڵ㣬�ڱ��ش��ڶ����ַ������£���Ҫ֪���Է�ʵ�����ӵı���ip��ַ��
* @param[in]    dwNodeId : [in] node id
* @return       �ɹ����ؽ��IP, ʧ�ܷ���0.
*/
API u32 PfcNodeLocalIpGet(u32 dwNodeId);

/**
* @brief        PfcInstShow
* @note         ��ʾĳ��App�е�Instance��״̬��Ϣ
* @param[in]    aid : app id of the instance list
*/
API void PfcInstShow(u16 aid);

/**
* @brief        PfcInstShowAll
* @note         ��ʾ����Instance��״̬��Ϣ
*/
API void PfcInstShowAll(void);

/**
* @brief        PfcInstDump
* @note         ��ʾĳһinstance���Զ�����Ϣ�����ø�instance��dump������
* @param[in]    aid : [in] app id
* @param[in]    InstId : [in] instance id, 0:��ʾ���еģ�-1:��ʾ��IDLE��
* @param[in]    param : [in] reserved parameter
*/
API void PfcInstDump(u16 aid, u16 InstId, MemId param);

/**
* @brief        PfcNodeShow
* @note         ��ʾ����Node��״̬��Ϣ
*/
API void PfcNodeShow(void);

/**
* @brief        PfcAppShow
* @note         ��ʾApp��״̬��Ϣ
*/
API void PfcAppShow();

/**
* @brief        PfcDispatchShow
* @note         ��ʾDispatch task����Ϣ
*/
API void PfcDispatchShow();

/**
* @brief        PfcTimerShow
* @note         ��ʾtimer״̬��Ϣ
*/
API void PfcTimerShow(void);

/**
* @brief        PfcLogShow
* @note         ��ʾ��־ģ��״̬
*/
API void PfcLogShow(void);

/**
* @brief        PfcMemShow
* @note         ��ʾ�ڴ�����ջ����Ϣ����Ŀ
*/
API void PfcMemShow(void);

/**
* @brief        PfcAppEchoTest
* @note         Application echo testing
* @param[in]    AppId : [in] Application id
*/
API void PfcAppEchoTest(u16 AppId);

/**
* @brief        PfcAddEventDesc
* @note         ���ڽ��¼��������Ǽǵ���Ϣ����ϵͳ
* @param[in]    desc : [in]
* @param[in]    event : [in]
*/
API void PfcAddEventDesc (const char   *desc, u16 event);

/**
* @brief        PfcSendTrcOn
* @note         ��OSP��㷢�͸��ٱ�ʶ
*/
API void PfcSendTrcOn();

/**
* @brief        PfcSendTrcOff
* @note         �ر�OSP��㷢�͸��ٱ�ʶ
*/
API void PfcSendTrcOff();

/**
* @brief        PfcRcvTrcOn
* @note         ��OSP�����ո��ٱ�ʶ
*/
API void PfcRcvTrcOn();

/**
* @brief        PfcRcvTrcOff
* @note         �ر�OSP�����ո��ٱ�ʶ
*/
API void PfcRcvTrcOff();

/**
* @brief        PfcTrcAllOn
* @note         ��OSP����Ӧ�õĸ��ٱ���
*/
API void PfcTrcAllOn(void);

/**
* @brief        PfcTrcAllOn
* @note         ��OSP����Ӧ�õĸ��ٱ���
*/
API void PfcTrcAllOff(void);

/**
* @brief        PfcOpenLogFile
* @note         ����־�ļ�
* @param[in]    path : file path
* @param[in]    name : file name
* @param[in]    maxsize_KB : �ļ���С����
* @param[in]    maxfiles : [in]�ļ���Ŀ����
* @return       BOOL32 - true �ɹ�, false ʧ��
*/
API BOOL32 PfcOpenLogFile(const char   *path, const char   *name, u32 maxsize_KB, u32 maxfiles);

/**
* @brief        PfcCloseLogFile
* @note         �ر���־�ļ���
* @pre          �������PfcQuit������Ҫ���øú�����
*/
API void PfcCloseLogFile(void);

/**
* @brief        PfcSetLogLevel
* @note         ����һ��APP��CInstance::log�����ļ���
* @pre          ������PfcInit֮����øú���������Ч��PfcInit������Ӧ�õĸñ�־��0
* @param[in]    aid : [in] app id
* @param[in]    file_level : [in] file level
* @param[in]    screen_level : [in] screen level. if level=5, ��ô0~5 ��ӡ,  6~255 ����ӡ,����Ϊ3,��ֻ��log(0|1|2,"")�ĵ����ܹ������
*/
API void PfcSetLogLevel(u16 aid, u8 file_level, u8 screen_level);

/**
* @brief        PfcSetFileLogLevel
* @note         ����App���ļ���־�ȼ�
* @param[in]    wAid: App�ĵȼ�
* @param[in]    byFileLevel: �ļ�Log�ĵȼ�
*/
API void PfcSetFileLogLevel(u16 wAid, u8 byFileLevel);

/**
* @brief        PfcSetScrnLogLevel
* @note         ����App����Ļ��־�ȼ�
* @param[in]    wAid: App�ĵȼ�
* @param[in]    byScrnLevel: ��ĻLog�ĵȼ�
*/
API void PfcSetScrnLogLevel(u16 wAid, u8 byScrnLevel);

/**
* @brief        PfcSetTrcFlag
* @note         ����ÿ��Ӧ�õĸ��ٷ�Χ��Trace ��Ϊ Trace ״̬�� 1: ����Ϣ, 2: ����Ϣ, 4: �趨ʱ 8:�ն�ʱ 16:״̬ԾǨ
* @param[in]    wAid : [in] app id
* @param[in]    wFileFlag : [in] trace file flag
* @param[in]    wScrnFlag : [in] screen output flag
*/
API void PfcSetTrcFlag(u16 wAid, u16 wFileFlag, u16 wScrnFlag);

/**
* @brief        PfcSetFileTrcFlag
* @note         ����ĳ��Ӧ�õĸ��ٱ�־
* @param[in]    wAid: appl ����
* @param[in]    wFileFlag: �ļ����ٱ���
*/
API void PfcSetFileTrcFlag(u16 wAid, u16 wFileFlag);

/**
* @brief        PfcSetScrnTrcFlag
* @note         ����ĳ��Ӧ�õĸ��ٱ�־
* @param[in]    wAid: application ����
* @param[in]    wScreenFlag: ��Ļ���ٱ���
*/
API void PfcSetScrnTrcFlag(u16 wAid, u16 wScreenFlag);

/**
* @brief        PfcRegistModule
* @note         ��OSP�Ǽ�һ��ģ��
* @param[in]    szModuleName - ģ�飨.exe�ļ���������NULL��β���ַ�������"kdvmt.dll"��
* @return       �ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcRegistModule(const char *szModuleName);

/**
* @brief        PfcSetLogEventDataLength
* @note         ����ȫ�ֵ���Ϣ������ʾ�ĳ��ȡ�
* @param[in]    wLength : [in] length of log event data
* @return       u16 previous length
*/
API u16 PfcSetLogEventDataLength(u16 wLength);

/**
* @brief        PfcEnableBroadcastAck
* @note         ���������£��û����͹㲥��Ϣ������Ҫ�Է�����ȷ����Ϣ��ȱʡ����£�PIS������Ϣ�ķ����߷���OSP_BROADCASTACK��Ϣ�����ǿ���ͨ���ú����޸����ѡ��Ƿ���OSP_BROADCASTACK���ɽ��ܽڵ�����ġ�
* @param[in]    aid : [in] ��ʾ�㲥��Ϣ�Ľ�����AID��
* @param[in]    bEnable : [in] enable or not
* @return       BOOL32 - true Succeeded, false Failed
*/
API BOOL32 PfcEnableBroadcastAck(u16 aid, BOOL32 bEnable);

/**
* @brief        PfcStr2IpAddr
* @note         ip�ַ���ת����PFC_IPADDR�ṹ��
* @param[in]    Str : string of ip address
* @param[in]    port : ip port
* @param[out]    ptAddr : PFC IP address struct
* @return       BOOL32 - true Succeeded, false Failed
*/
API BOOL32 PfcStr2IpAddr(OUT PFC_IPADDR* ptAddr, IN const s8 *Str, IN u16 port = 0);

/**
* @brief        PfcIpAddr2Str
* @note         PFC_IPADDR�ṹ��ת����ip�ַ���
* @param[out]    Str : string of ip address
* @param[out]    port : ip port
* @param[in]    ptAddr : PFC IP address struct
* @return       BOOL32 - true Succeeded, false Failed
*/
API BOOL32 PfcIpAddr2Str(IN PFC_IPADDR const *ptAddr, OUT s8 *Str, OUT u16 &port);

/**
* @brief        PfcGetPID
* @note         ��ȡ����PID
* @param[out]    dwPID : The process of PID
*/
API void PfcGetPID(OUT u32 &dwPID);

/// PFC Node Address for IPv4
typedef struct
{
    u32 m_dwLocalIP;    ///< ������
    u32 m_dwPeerIP;     ///< ������
    u16 m_wLocalPort;   ///< ������
    u16 m_wPeerPort;    ///< ������
} TPfcNodeAddr;

/**
* @brief        PfcGetNodeAddr
* @note         ����PFC����ַ��������Զ��IP+Port����
* @param[in]    dwNodeId : [in] ���ID
* @param[out]   ptPfcNodeAddr : [out] ����ַ
* @return       FALSE - ��ѯ�ɹ� TRUE - ��ѯʧ��
*/
API BOOL32 PfcGetNodeAddr( u32 dwNodeId , TPfcNodeAddr *ptPfcNodeAddr );

#ifdef _ENABLE_SOCK5_API_
#include "pfc_sock5.h"
#endif

/** 5.0�ϲ��� ԭ��ҵosp���нӿڣ� ����һ��raw��Ϣosp server */
/**
* @brief        PfcCreateTcpNode
* @note         ����һ��TCP�ڵ㡣���Ժ�����ڵ���Ա����ӡ���ʹ��6682��Ϊport������
* @param[in]    dwAddr : [in] reserved
* @param[in]    wPort : [in] which port to use
* @param[in]    bTcpNodeReuse: [in] ������node�˳���˿��Ƿ����������û�������������ռ��
* @param[in]    cb_setappid: callback function pointer for the created TCP node
* @return       int - If no error occurs, CreateTcpNode returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned.
*/
API int PfcCreateTcpNode(u32 dwAddr, u16 wPort, BOOL32 bTcpNodeReuse = FALSE , CB_FUNC_PFC_CREATE_RAW_NODE cb_setappid = NULL);

/**
* @brief        PfcConnectTcpNode
* @note         �ڵ�ַuIpv4Addr�Ͷ˿�uTcpPort�����ӷ�����, �����ö���������.ȫ�ֱ�����g_cPfc
* @param[in]    dwIpv4Addr : [in] �������IP��ַ,
* @param[in]    wTcpPort : [in] ������������˿ں�,
* @param[in]    wHb: [in] �����������(��),
* @param[in]    byHbNum: [in] byHbNum��δ�����Ӽ��Ӧ�����Ϊ��·�ѶϿ�,
* @param[in]    dwTimeoutMs: [in] �����dwTimeOutMs���������Ӳ��ɹ�, ���س���. ȱʡֵ0,��ʾȡconnect��ʱ��ȱʡʱ��(75s).  �ò���Ŀǰ����VxWorks����Ч.
* @param[out]   pdwLocalIP: [out] ��ǰ�������õ�IP��ַ
* @param[in]    wAid: specify the app id
* @return       �ɹ�����һ����̬����Ľ���, �˺��û��ɽ���������ͨ��. ʧ�ܷ���INVALID_NODE.
*/
API int PfcConnectTcpNode(u32 dwIpv4Addr, u16 wTcpPort, u16 wHb = 10, u8 byHbNum = 3, u32 dwTimeoutMs = 0, u32 *pdwLocalIP = NULL , u16 wAid = 0);

/** 5.0�ϲ��� ԭ��ҵosp���нӿ� */
/**
* @brief        PfcConnectTcpNodeEx
* @note         �ڵ�ַuIpv4Addr�Ͷ˿�uTcpPort�����ӷ�����, �����ö���������.���ض˿ڰ󶨷�Χ��wMinPort~wMaxPort��.ȫ�ֱ�����g_cPfc
* @param[in]    dwIpv4Addr  : [in] �������IP��ַ,
* @param[in]    wTcpPort    : [in] ������������˿ں�,
* @param[in]    wHb         : [in] �����������(��),
* @param[in]    byHbNum     : [in] uHbNum��δ�����Ӽ��Ӧ�����Ϊ��·�ѶϿ�.
* @param[in]    dwTimeOutMs : [in] �����dwTimeOutMs���������Ӳ��ɹ�, ���س���. ȱʡֵ0.
* @param[in]    pdwLocalIP  : [out] ��ǰ�������õ�IP��ַ
* @param[in]    wMinPort    : [in] ָ�����ذ󶨶˿ڷ�Χ����Сֵ
* @param[in]    wMaxPort    : [in] ָ�����ذ󶨶˿ڷ�Χ�����ֵ
* @param[in]    wAid        : specify the app id
* @pre          ����󶨶˿���Сֵ�����ֵ��Ϊ0����ʾ���ѡ��˿ڣ�����
* @return       �ɹ�����һ����̬����Ľ���, �˺��û��ɽ���������ͨ��.ʧ�ܷ���INVALID_NODE.
*/
API int PfcConnectTcpNodeEx(u32 dwIpv4Addr, u16 wTcpPort, u16 wHb, u8 byHbNum, u32 dwTimeOutMs, u32 *pdwLocalIP, u16 wMinPort, u16 wMaxPort, u16 wAid = 0);

#ifdef PFC_ENABLE_IPV6
/// PFC Node Address for IPv6
typedef struct
{
    //in_addr6 m_tLocalIP;    ///< ������
    //in_addr6 m_tPeerIP;     ///< ������
	sockaddr_in6 m_tLocalIP;    ///< ������
	sockaddr_in6 m_tPeerIP;     ///< ������
    u16 m_wLocalPort;       ///< ������
    u16 m_wPeerPort;        ///< ������
} TPfcNodeAddr6;
/**
* @brief        PfcGetNodeAddr6
* @note         ����PFC����ַ��������Զ��IP+Port����
* @param[in]    dwNodeId : [in] ���ID
* @param[out]   ptPfcNodeAddr6 : [out] ����ַ
* @return       FALSE - ��ѯ�ɹ� TRUE - ��ѯʧ��
*/
API BOOL32 PfcGetNodeAddr6( u32 dwNodeId , TPfcNodeAddr6 *ptPfcNodeAddr6 );

/**
* @brief        PfcCreateTcpNode6
* @note         ����һ��TCP�ڵ㡣���Ժ�����ڵ���Ա����ӡ���ʹ��6682��Ϊport������
* @param[in]    ptAddr : [in] reserved
* @param[in]    wPort : [in] which port to use
* @param[in]    bTcpNodeReuse: [in] ������node�˳���˿��Ƿ����������û�������������ռ��
* @param[in]    cb_setappid: callback function pointer for the created the TCP node
* @return       int - If no error occurs, CreateTcpNode returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned.
*/
API int PfcCreateTcpNode6(PFC_IPADDR* ptAddr, u16 wPort, BOOL32 bTcpNodeReuse = FALSE , CB_FUNC_PFC_CREATE_RAW_NODE cb_setappid = NULL);

/**
* @brief        PfcConnectTcpNode6
* @note         �ڵ�ַuIpv4Addr�Ͷ˿�uTcpPort�����ӷ�����, �����ö���������.ȫ�ֱ�����g_cPfc
* @param[in]    ptIpv6Addr : [in] �������IP��ַ,
* @param[in]    wTcpPort : [in] ������������˿ں�,
* @param[in]    wHb: [in] �����������(��),
* @param[in]    byHbNum: [in] byHbNum��δ�����Ӽ��Ӧ�����Ϊ��·�ѶϿ�,
* @param[in]    dwTimeoutMs: [in] �����dwTimeOutMs���������Ӳ��ɹ�, ���س���. ȱʡֵ0,��ʾȡconnect��ʱ��ȱʡʱ��(75s).  �ò���Ŀǰ����VxWorks����Ч.
* @param[out]   ptLocalIP: [out] ��ǰ�������õ�IP��ַ
* @param[in]    wAid: specify the app id
* @return       �ɹ�����һ����̬����Ľ���, �˺��û��ɽ���������ͨ��. ʧ�ܷ���INVALID_NODE.
*/
API int PfcConnectTcpNode6(PFC_IPADDR* ptIpv6Addr, u16 wTcpPort, u16 wHb = 10, u8 byHbNum = 3, u32 dwTimeoutMs = 0, PFC_IPADDR *ptLocalIP = NULL , u16 wAid = 0);

/**
* @brief        PfcConnectTcpNodeEx6
* @note         �ڵ�ַuIpv4Addr�Ͷ˿�uTcpPort�����ӷ�����, �����ö���������.���ض˿ڰ󶨷�Χ��wMinPort~wMaxPort��.ȫ�ֱ�����g_cPfc
* @param[in]    ptIpv6Addr  : [in] �������IP��ַ,
* @param[in]    wTcpPort    : [in] ������������˿ں�,
* @param[in]    wHb         : [in] �����������(��),
* @param[in]    byHbNum     : [in] uHbNum��δ�����Ӽ��Ӧ�����Ϊ��·�ѶϿ�.
* @param[in]    dwTimeOutMs : [in] �����dwTimeOutMs���������Ӳ��ɹ�, ���س���. ȱʡֵ0.
* @param[out]   ptLocalIP   : [out] ��ǰ�������õ�IP��ַ
* @param[in]    wMinPort    : [in] ָ�����ذ󶨶˿ڷ�Χ����Сֵ
* @param[in]    wMaxPort    : [in] ָ�����ذ󶨶˿ڷ�Χ�����ֵ
* @param[in]    wAid: specify the app id
* @pre          ����󶨶˿���Сֵ�����ֵ��Ϊ0����ʾ���ѡ��˿ڣ�����
* @return       �ɹ�����һ����̬����Ľ���, �˺��û��ɽ���������ͨ��.ʧ�ܷ���INVALID_NODE.
*/
API int PfcConnectTcpNodeEx6(PFC_IPADDR* ptIpv6Addr, u16 wTcpPort, u16 wHb, u8 byHbNum, u32 dwTimeOutMs, PFC_IPADDR *ptLocalIP, u16 wMinPort, u16 wMaxPort, u16 wAid = 0);

/**
* @brief        PfcAddrListGet6
* @note         ��ȡ������ַ������
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @param[in]    atIPList[] : [in/out]�û���������ڵ�ַ�����ݵ�������׵�ַ
* @param[in]    wNum : [in]�û����������Ĵ�С
* @return       ���ر�����ַ���е�ַ����������ʱ����0
*/
API u16  PfcAddrListGet6(PFC_IPADDR atIPList[], u16 wNum);

/**
* @brief        PfcIsLocalHost6
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup
*               ��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @note         �ж��Ƿ��Ǳ���IP,Ŀ��֧��IPv4��IPv6
* @param[in]    ptIP: Input IP address
* @return       �Ƿ�Ϊ����IP
*/
API BOOL32 PfcIsLocalHost6(PFC_IPADDR* ptIP);

#endif  /// end of PFC_ENABLE_IPV6

/**
* @brief        PfcSetHBParam
* @note         ���ý��Ķ���������
* @param[in]    dwNodeID: ����,
* @param[in]    wHb: ��·�������(����Ϊ��λ),
* @param[in]    byHbNum: �������ping��uHbNum��û��Ӧ��, �����Ͽ�.
* @return       �ɹ�����TRUE, ʧ�ܷ���FALSE.
*/
API BOOL32 PfcSetHBParam(u32 dwNodeID, u16 wHb, u8 byHbNum);

/**
* @brief        PfcNodeDiscCBReg
* @note         ������node�����ж�ʱ��֪ͨ��appid��InstId
* @pre          Ŀǰ֧��֪ͨ���ʵ����ÿ�ε��øú�������ָֻ֪ͨ��ʵ����������ע���֪ͨʵ�����������
* @param[in]    dwNodeId : [in] node id
* @param[in]    wAppId : [in] application id
* @param[in]    wInsId : [in] instance id
* @return       �ɹ�����PFC_OK��ʧ�ܲμ�������
*/
API int PfcNodeDiscCBReg(u32 dwNodeId, u16 wAppId, u16 wInsId);

/**
* @brief        PfcNodeDiscCBRegQ
* @pre          ������node�����ж�ʱ��֪ͨ��appid��InstId
* @note         ÿ�ε��ô˺�����������һ��Ҫ֪ͨ��ʵ�������Ǵﵽ������
* @param[in]    dwNodeId : [in] node id
* @param[in]    wAppId : [in] application id
* @param[in]    wInsId : [in] instance id
* @return       �ɹ�����PFC_OK��ʧ�ܲμ�������
*/
API int PfcNodeDiscCBRegQ(u32 dwNodeId, u16 wAppId, u16 wInsId);

/**
* \brief        PfcNodeDelDiscCB
* \pre          ɾ����node�����ж�ʱ��֪ͨ��appid��InstId
* \note         ÿ�ε��ô˺�������ɾ��һ��Ҫ֪ͨ��ʵ����
* \param[in]    dwNodeId : [in] node id
* \param[in]    wAppId : [in] application id
* \param[in]    wInsId : [in] instance id
* \return       �ɹ�����PFC_OK��ʧ�ܲμ�������
*/
API int PfcNodeDelDiscCB(u32 dwNodeId, u16 wAppId, u16 wInsId);

/**
* \brief        PfcDisconnectTcpNode
* \pre          �Ͽ���һ��node�ϵ����ӡ�
* \note
* \param[in]    dwNodeId : [in] node id
* \return       BOOL32 - true Succeeded, false Failed
*/
API BOOL32 PfcDisconnectTcpNode(u32 dwNodeId);

/**
* \brief        PfcCloseTcpNode
* \pre          �ر�һ���׽��ֵļ�������Ӧ��PfcCreateTcpNode��������(Ŀǰ��linux����Ч)��
*               5.0�ϲ��� ԭ��ҵosp�Ľӿڣ� ֧��һ�����̴������osp server 
* \note
* \param[in]    nSocketFd : [in] �׽�����������һ��ΪPfcCreateTcpNode�ķ���ֵ
* \return       BOOL32 - true Succeeded, false Failed
*/
API BOOL32 PfcCloseTcpNode(int nSocketFd);

#ifdef _LINUX_
/**
* @brief        PfcDisconnectAllTcpNode
* @note         ֹͣ��ǰ�ļ���,���Ͽ����ϴ���ȫ������(Ŀǰ��linux����Ч)��
*/
API BOOL32 PfcDisconnectAllTcpNode(void);
#endif

/**
* @brief        PfcIsValidTcpNode
* @note         �ж�һ��TCP�ڵ��Ƿ���Ч��
* @param[in]    node_id: [in] node id
* @return       BOOL32 - Valid or not
*/
API BOOL32 PfcIsValidTcpNode (u32 node_id);

/**
* @brief        PfcIsNodeCheckEnable
* @note         �ж�ָ��������·��⹦���Ƿ�����
* @param[in]    dwNodeId: node id
* @return       BOOL32 - Valid or not
*/
API BOOL32 PfcIsNodeCheckEnable(u32 dwNodeId);

/**
* @brief        PfcEnableNodeCheck
* @note         ����ָ��������·��⹦��
* @param[in]    dwNodeId: node id
* @return       void
*/
API void PfcEnableNodeCheck(u32 dwNodeId);

/**
* @brief        PfcDisableNodeCheck
* @note         ����ָ��������·��⹦��
* @param[in]    dwNodeId: node id
* @return       void
*/
API void PfcDisableNodeCheck(u32 dwNodeId);

/**
* @brief        PfcSetAppPriority
* @note         ����App�ĵ������ȼ�
* @param[in]    wAppId: AppID
* @param[in]    byPrior: priority value
* @return       �ɹ�, ����TRUE; ʧ��, ����FALSE.
*/
API BOOL32 PfcSetAppPriority(u16 wAppId, u8 byPrior);

/**
* @brief        PfcGetAppPriority
* @note         ���ָ��App�ĵ������ȼ���
* @param[in]    wAppId: AppID
* @param[out]   pbyPrior: priority value
* @return       �ɹ�, ����TRUE; ʧ��, ����FALSE.
*/
API BOOL32 PfcGetAppPriority(u16 wAppId, u8 *pbyPrior);

/**
* @brief        PfcIsLocalHost
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup
*               ��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @note         �ж��Ƿ��Ǳ���IP����PfcIsLocalHost( inet_addr( "127.0.0.1" ) );
* @param[in]    dwIP: Input IP address
* @return       �Ƿ�Ϊ����IP
*/
API BOOL32 PfcIsLocalHost( u32 dwIP );

/**
* @brief        PfcPost
* @pre          �����첽��Ϣ
* @param[in]    dstid : [in] destination info
* @param[in]    event : [in] OSP_ event
* @param[in]    content : [in] message data
* @param[in]    length : [in] sizeof content in u8s
* @param[in]    dstnode : [in] destionation socket node
* @param[in]    srciid : [in] source info
* @param[in]    srcnode : [in] source node
* @param[in]    timeout : [in] message send timeout
* @return       0 Succeeded, others Failed
*/
API int PfcPost(u32 dstid, u16 event, const void *content = 0, u16 length = 0,
				u32 dstnode = 0, u32 srciid = PFC_MAKEIID(INVALID_APP, INVALID_INS), u32 srcnode = INVALID_NODE, int timeout = 2000);

/* used only in C++ environment */
/// �������޸�, ��Ӳ���timeout, Ĭ��ֵ2��
/**
* @brief        PfcPost
* @pre          �����첽��Ϣ
* @param[in]    dstalias : [in] destination info
* @param[in]    aliaslen: dst alias string length
* @param[in]    dstapp: dst app id
* @param[in]    event : [in] OSP_ event
* @param[in]    content : [in] message data
* @param[in]    length : [in] sizeof content in u8s
* @param[in]    dstnode : [in] destionation socket node
* @param[in]    srciid : [in] source info
* @param[in]    srcnode : [in] source node
* @param[in]    timout : [in] message send timeout
* @return       0 Succeeded, others Failed
*/
int PfcPost(const char *dstalias, u8 aliaslen, u16 dstapp, u16 event, const void *content = 0, u16 length = 0, u32 dstnode = 0, u32 srciid = PFC_MAKEIID(INVALID_APP, INVALID_INS), u32 srcnode = INVALID_NODE, int timout = 2000);

/**
* @brief        PfcSend
* @pre          ȫ��ͬ����Ϣ����
* @param[in]    dstiid : [in] destination info
* @param[in]    event : [in] OSP_ event
* @param[in]    content : [in] message data
* @param[in]    length : [in] sizeof content in u8s
* @param[in]    dstnode : [in] destionation socket node
* @param[in]    srciid : [in] source info
* @param[in]    srcnode : [in] source node
* @param[in]    ackbuf : ack buffer
* @param[in]    ackbuflen: ack buffer length
* @param[in]    realacklen: real ack len
* @param[in]    timeout: send time out parameter for the sending message
* @return       0 Succeeded, others Failed
*/
API int PfcSend(u32 dstiid, u16 event, const void *content = 0, u16 length = 0, u32 dstnode = 0,
				u32 srciid = PFC_MAKEIID(INVALID_APP, INVALID_INS), u32 srcnode = INVALID_NODE,
				void *ackbuf = NULL, u16 ackbuflen = 0, u16 *realacklen = NULL,
				u16 timeout = 1000);

/**
* @brief        PfcSend
* @pre          ȫ��ͬ����Ϣ����
* @param[in]    dstalias : [in] destination info
* @param[in]    aliaslen: dst alias length
* @param[in]    dstapp: dst app id
* @param[in]    event : [in] OSP_ event
* @param[in]    content : [in] message data
* @param[in]    length : [in] sizeof content in u8s
* @param[in]    dstnode : [in] destionation socket node
* @param[in]    srciid : [in] source info
* @param[in]    srcnode : [in] source node
* @param[in]    ackbuf: ack buffer
* @param[in]    ackbuflen: ack buffer length
* @param[in]    realacklen: real ack length
* @param[in]    timeout: send msg timeout
* @return       0 Succeeded, others Failed
*/
/* used only in C++ environment */
int PfcSend(const char *dstalias, u8 aliaslen, u16 dstapp, u16 event,
			const void *content = 0, u16 length = 0, u32 dstnode = 0,
			u32 srciid = PFC_MAKEIID(INVALID_APP, INVALID_INS), u32 srcnode = INVALID_NODE,
			void *ackbuf = NULL, u16 ackbuflen = 0, u16 *realacklen = NULL,
			u16 timeout = 1000);


//////////////////////////////////////////////////////////////////////////
//  Start of pfc_telnet_service wrapper
//////////////////////////////////////////////////////////////////////////
/**
 * @defgroup    pfc_telnet_service  PFC telnet service
 * @brief       PFC telnet service implementations.
 * @{
 */

/**
* @brief        IsPFCInitd
* @note         �ж�PFC�Ƿ��ѳ�ʼ������
* @return       PFC�ѳ�ʼ��������TRUE�����򷵻�FALSE
*/
API BOOL32 IsPFCInitd(void);


#define MAX_MODULE_NAME_LENGTH 63   ///< Max module name string length definition

/**
* @brief        PfcInit
* @note         initialize PFC module
* @param[in]    TelNetEnable : [in] start telnet.exe
* @param[in]    TelNetPort : [in] PFC telnet server port
* @param[in]    pchModuleName : [in] process module name��maxlength = 63
* @param[in]    dwMaxNodeNum: max socket nodes
* @param[in]    dwMaxDispatchMsg: maximun dispatch messages
* @return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcInit(BOOL32 TelNetEnable = FALSE, u16 TelNetPort = 0, const char *pchModuleName = NULL, u32 dwMaxNodeNum = 512, u32 dwMaxDispatchMsg = 1024 );

/**
* @brief        PfcQuit
* @pre          OSP�˳�֮������OSP���񽫲���ʹ�á�
* @note         �˳�PFC�����ñ�������APP������ʵ����InstanceExit�������˳�ʵ����
*               �Ͽ�����OSP��㣬��������OSP�������APP��Ȼ�󷵻ء�
* @return       void
*/
API void PfcQuit(void);

/**
* \brief        PfcSetPrompt
* \pre          
* \note         �����ն���ʾ��
* \param[in]    prompt: prompt title caption string
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcSetPrompt(const char *prompt);

/**
* \brief        PfcStopScrnLog
* \pre          
* \note         ��ͣ��Ļ��־���
* \return       void
*/
API void PfcStopScrnLog(void);

/**
* \brief        PfcResumeScrnLog
* \pre          
* \note         �ָ���Ļ��־���
* \return       void
*/
API void PfcResumeScrnLog(void);

/**
* \brief        PfcGetLocalID
* \pre          
* \note         ����ȫ�ֱ��
* \return       ����ȫ�ֱ��
*/
API int PfcGetLocalID(); // ����ȫ�ֱ��

/**
* \brief        PfcEventDesc
* \pre          
* \note         ������Ϣ������
* \param[in]    wEventID : [in]��Ϣ��ID
* \return       ��Ϣ�������������ϢID��Ч���߸���Ϣû�������ַ���������ֵ��ΪNULL��
*/
API const char *PfcEventDesc( u16 wEventID );

/**
 * \brief        PfcEventDescShow
 * \pre          
 * \note         Show/print event description for the specified eventid
 * \param[in]    wEventID : [in]��Ϣ��ID
 * \return       void
 */
API void PfcEventDescShow( u16 wEventID );

/**
* @}
*/
//////////////////////////////////////////////////////////////////////////
//  Group end of pfc_telnet_service wrapper
//////////////////////////////////////////////////////////////////////////




























//////////////////////////////////////////////////////////////////////////
//  Start of pfc_semhandle wrapper
//////////////////////////////////////////////////////////////////////////

/**
 * @defgroup    pfc_semhandle PFC semi-handle wrapper
 * @brief       PFC Semi-handle interfaces wrapper.
 * @{
 */

/**
* \brief        PfcSemBCreate
* \pre          
* \note         ����һ����Ԫ�ź���
* \param[out]   ptSemHandle ���ص��ź������
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcSemBCreate(PFCSEMHANDLE *ptSemHandle);

/**
* \brief        PfcSemCCreate
* \pre          
* \note         ���������ź���
* \param[out]   ptSemHandle ���ص��ź������
* \param[in]    initcount: ��ʼ����
* \param[in]    MaxSemCount: ������
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcSemCCreate(PFCSEMHANDLE *ptSemHandle, u32 initcount, u32 MaxSemCount);

/**
* \brief        PfcSemDelete
* \note         ɾ���ź���
* \param[in]    tSemHandle ��ɾ���ź����ľ��
* \return       return TRUE if success, otherwise return FALSE
*/
API  BOOL32 PfcSemDelete(PFCSEMHANDLE tSemHandle );

/**
* \brief        PfcSemTake
* \note         �ź���p����������ź��������ã�����������ʵ����������(APP)
* \param[in]    tSemHandle �ź����ľ��
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32  PfcSemTake(PFCSEMHANDLE tSemHandle );

/**
* \brief        PfcSemTakeByTime
* \note         ����ʱ���ź���p���������ź��������ã���ʱ������dwtime����󣬳�����
* \param[in]    tSemHandle �ź����ľ��
* \param[in]    dwtime ��ʱ���(��msΪ��λ)
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcSemTakeByTime(PFCSEMHANDLE tSemHandle, u32 dwtime);

/**
* \brief        PfcSemGive
* \note         �ź���v����
* \param[in]    tSemHandle �ź����ľ��
* \return       return TRUE if success, otherwise return FALSE
*/
API BOOL32 PfcSemGive(PFCSEMHANDLE tSemHandle );

/**
* @}
*/
//////////////////////////////////////////////////////////////////////////
//  End of pfc_semhandle wrapper
//////////////////////////////////////////////////////////////////////////





/** 5.0�ϲ��� ԭ��ҵosp���нӿ� */
/**
* @brief        PfcSetNodeAppId
* @note         Ϊ�ڵ����ù���appid
* @param[in]    nNodeId: �����õĽڵ��
* @param[in]    wAid: ���õ�appid
* @return       ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
*/
API BOOL32 PfcSetNodeAppId(int nNodeId, u16 wAid);







/************************************************************************/
/*  Start of pfc_thread wrapper                                          */
/************************************************************************/

/**
 * @defgroup    pfc_thread  PFC thread wrapper
 * @brief       SemHandle interfaces describe here what it is all about.
 * @{
 */

/**
* @brief           PfcTaskCreate
* @note            ������ִ��һ������
* @param[in]       pvTaskEntry: thread function pointer
* @param[in]       szName: thread name
* @param[in]       byPriority: thread priority
* @param[in]       dwStacksize: thread init stack size
* @param[in]       dwParam: user context for the thread
* @param[in]       wFlag: thread flag
* @param[out]      puTaskID: task id
* @return          return NULL if failed, otherwise success
*/
#ifdef _LINUX_
API PFCTASKHANDLE PfcTaskCreate(LINUXFUNC pvTaskEntry, const char *szName, u8 byPriority, u32 dwStacksize, MemId dwParam, u16 wFlag, u32 *puTaskID = NULL);
#else
API PFCTASKHANDLE PfcTaskCreate(void *pvTaskEntry, const char *szName, u8 byPriority, u32 dwStacksize, MemId dwParam, u16 wFlag, u32 *puTaskID = NULL);
#endif

#ifdef _MSC_VER
/**
* @brief           PfcTaskSetAffinity
* @note            ������ִ��һ������
* @param[in]       hTaskHandle      : windows�µ��̡߳����̵ľ����
* @param[in]       dwCpuId          : ��󶨵�CPU����0��ʼ����,��εݼ�
* @param[in]       byTaskType       ���󶨵��̡߳����̡���������ͣ�0--�̣߳�1-���̣�����-����linux��Ĭ��0����
* @param[in]       pdwPreviousBind  �����֮ǰ�ý��̡��̡߳����񱻰󶨵�ĳCPU����᷵�ظ�CPU�š���Solaris����Ч
* @return          return NULL if failed, otherwise success
*/
API BOOL32 PfcTaskSetAffinity( PFCTASKHANDLE hTaskHandle, u32 dwCpuId, u8 byTaskType = 0, u32 *pdwPreviousBind = NULL);
#else
/**
* @brief           PfcTaskSetAffinity
* @note            ������ִ��һ������
* @param[in]       hTaskId          : �󶨵��̡߳����̡������ID��
* @param[in]       dwCpuId          : ��󶨵�CPU����0��ʼ����,��εݼ�
* @param[in]       byTaskType       ���󶨵��̡߳����̡���������͡�0--�̣߳�1-���̣�����-����linux��Ĭ��0����
* @param[in]       pdwPreviousBind  �����֮ǰ�ý��̡��̡߳����񱻰󶨵�ĳCPU����᷵�ظ�CPU�š���Solaris����Ч
* @return          return NULL if failed, otherwise success
*/
API BOOL32 PfcTaskSetAffinity( u64 hTaskId, u32 dwCpuId, u8 byTaskType = 0, u32 *pdwPreviousBind = NULL);
#endif

/**
* @brief           PfcPostRaw
* @note            Post a raw data to the specified node
* @param[in]       nNodeId  : Node ID
* @param[in]       content  : Content need to be posted
* @param[in]       dwLen    ��Content length
* @return          return NULL if failed, otherwise success
*/
API int PfcPostRaw(int nNodeId , const void *content , u32 dwLen);

/**
* @brief        PfcTaskExit
* @note         �˳��������������˳�֮ǰ�û�Ҫע���ͷű�����������ڴ桢�ź�������Դ��
* @pre          ��װWindows��ExitThread(0)��vxWorks��taskDelete(0)��
* @return       �ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcTaskExit(void);

/**
* @brief        PfcTaskTerminate
* @note         ǿ����ָֹ������
* @pre          ��װWindows��ExitThread()��vxWorks��taskDelete()��
* @param[in]    handle: ��ɱ�����handle
* @return       ����ֵ˵�����ɹ�����TRUE, ʧ�ܷ���FALSE
*/
API BOOL32 PfcTaskTerminate(PFCTASKHANDLE handle);

/**
* @brief        PfcTaskSuspend
* @note         ����ǰ����
* @param[in]    handle: task handle
*/
API BOOL32 PfcTaskSuspend(PFCTASKHANDLE handle = 0);

/**
* @brief        PfcTaskResume
* @note         ����ǰ����
* @param[in]    handle: task handle
*/
API BOOL32 PfcTaskResume(PFCTASKHANDLE handle);

/**
* @brief        PfcTaskSetPriority
* @note         �ı���������ȼ���
* @param[in]    taskHandle: task handle
* @param[out]   newPriority: task priority
* @param[out]   newSchedPolicy: task scheduled policy
*/
API BOOL32 PfcTaskSetPriority(PFCTASKHANDLE taskHandle, u8 newPriority, int newSchedPolicy = 0);

/**
* @brief        PfcTaskGetPriority
* @note         �����������ȼ���
* @param[in]    taskHandle: task handle
* @param[out]   puPri: task priority
* @param[out]   SchedPolicy: task scheduled policy
*/
API BOOL32 PfcTaskGetPriority(PFCTASKHANDLE taskHandle, u8 *puPri, int *SchedPolicy = NULL);

/**
* @brief        PfcSetTaskPriorityByName
* @note         ͨ��������������������ȼ�linux����Ч
* @param[in]    name: task name
* @param[in]    priority: task priority
* @param[in]    newSchedPolicy: task scheduled policy
*/
API void PfcSetTaskPriorityByName(s8 *name , u8 priority, int newSchedPolicy = 0);

/// ���������, Linux��ʹ�õ�����task nice���ȼ��Ľӿ�.
/// ����ӿڿ���ȥ��, ���漰������Ѷ��һЩҵ�������޸�, ��ʱ�ȱ���. ���������پ���.
/**
* @brief        PfcSetTaskNiceByName
* @note         ͨ�����������������ʱ��Ƭ��С��linux����Ч
* @param[in]    name: task name
* @param[in]    nice: task nice value
*/
API void PfcSetTaskNiceByName(s8 *name , int nice);

/**
* @brief        PfcGetTaskPriorityByName
* @note         ͨ����������ȡ��������ȼ�
*/
API void PfcGetTaskPriorityByName(s8 *name , u8 *priority, int *newSchedPolicy = NULL);

/**
* @brief        PfcTaskSelfHandle
* @note         ��õ�������ľ��
*/
API PFCTASKHANDLE PfcTaskSelfHandle(void);

/**
* @brief        PfcTaskSelfHandle
* @note         ��õ��������ID
*/
API u32 PfcTaskSelfID(void);

/**
* @brief        PfcTaskHandleVerify
* @note         �ж�ָ�������Ƿ����
*/
API BOOL32 PfcTaskHandleVerify(PFCTASKHANDLE handle);

/**
* @brief        PfcTaskSafe
* @note         �����������񲻱��Ƿ�ɾ��
*/
API void PfcTaskSafe(void);

/**
* @brief        PfcTaskUnsafe
* @note         �ͷŵ��������ɾ��������ʹ�õ���������Ա���ȫɾ��
*/
API void PfcTaskUnsafe(void);

/**
* @brief        PfcTaskDelay
* @note         ������ʱ
* @param[in]    dwMseconds: ��ʱ���(ms)
*/
API void PfcTaskDelay(u32 dwMseconds);

/** redefinition PfcDelay */
#define PfcDelay                      PfcTaskDelay

/**
* @}
*/

/**
* @brief        PfcCreateMailbox
* @note         ������Ϣ����
* @param[in]    szName: mailbox name
* @param[in]    dwMsgNumber: max msg number for the creating mail box
* @param[in]    dwMsgLength: max msg length for the creating mail box
* @param[out]   puQueueIDRead: read handle for the created mail box
* @param[out]   puQueueIDWrite: write handle for the created mail box
*/
API BOOL32 PfcCreateMailbox(const char *szName, u32 dwMsgNumber, u32 dwMsgLength , kdvHandle *puQueueIDRead, kdvHandle *puQueueIDWrite);

/**
* @brief        PfcCloseMailbox
* @note         �ر�����
* @param[in]    dwQueueIDRead : ����Ķ���д���
* @param[in]    dwQueueIDWrite: ����Ķ���д���
*/
API void PfcCloseMailbox(kdvHandle dwQueueIDRead, kdvHandle dwQueueIDWrite);

/**
* @brief        PfcSndMsg
* @note         �����䷢��Ϣ
* @param[in]    tQueueID: ����ID,
* @param[in]    lpMsgBuf: ����ָ��,
* @param[in]    len     : ����,
* @param[in]    timeout : ��ʱֵms. Windows�¸ò�����Ч, ��������һֱ����ֱ���пյ�buffer. VxWorks��, ȱʡΪ2�롣OSP_NO_WAIT �������������أ�OSP_WAIT_FOREVER ����������ֱ���пյ�buffer.
* @return       �ɹ�����TRUE, ʧ�ܻ�ʱ����FALSE.
*/
API BOOL32 PfcSndMsg(kdvHandle tQueueID, const char *lpMsgBuf, u32 len, int timeout = 2000);

/**
* @brief        PfcRcvMsg
* @note         ����������Ϣ
* @param[in]    tQueueID:    ����ID
* @param[in]    dwTimeout:   ��ʱms
* @param[out]   lpMsgBuf:    ������Ϣ����ָ��
* @param[in]    len: max receive length
* @param[out]   pLenRcved: actual receive length
*/
API BOOL32 PfcRcvMsg(kdvHandle tQueueID, u32  dwTimeout, char *lpMsgBuf, size_t len, size_t *pLenRcved);

/**
* @brief        PfcClkRateGet
* @note         �õ�tick���ȣ�n ticks/sec
*/
API u32 PfcClkRateGet();

/**
* @brief        PfcTickGet
* @note         ȡ�õ�ǰ��tick��
*/
API u32 PfcTickGet();

/**
* @brief        PfcTickGet64
* @note         ȡ�õ�ǰ��tick��,64���ȣ�����������
*/
API u64 PfcTickGet64();

/**
* @brief        PfcCpuShow
* @note         show current CPU usage
*/
API void PfcCpuShow();

/// CPU��Ϣ
typedef struct
{
    u8 m_byIdlePercent;	                ///< ���аٷֱȣ�0��100
} TPfcCpuInfo;

/**
* @brief        PfcGetCpuInfo
* @note         ȡ�õ�ǰ��CPU��Ϣ
* @param[in]    ptCpuInfo: �û�CPU��Ϣ�ṹ
* @return       ����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
*/
API BOOL32 PfcGetCpuInfo( TPfcCpuInfo *ptCpuInfo );

/// �ڴ���Ϣ
typedef struct
{
    size_t m_dwPhysicsSize;	            ///< �����ڴ��С KByte
    size_t m_dwAllocSize;	            ///< ��ʹ���ڴ�   KBytes 
    size_t m_dwFreeSize;	            ///< �����ڴ�     KBytes
} TPfcMemInfo;

/**
* @brief        PfcGetMemInfo
* @note         ȡ�õ�ǰ��Mem��Ϣ
* @param[in]    ptMemInfo: �û�MEM��Ϣ�ṹ
* @return       ����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
*/
API BOOL32 PfcGetMemInfo( TPfcMemInfo *ptMemInfo );

/// ʱ����Ϣ
typedef struct
{
    u16 m_wYear;	                    ///< �� - 2006
    u16 m_wMonth;	                    ///< �� - 1--12
    u16 m_wDay;	                        ///< �� - 1--31
    u16 m_wHour;	                    ///< ʱ - 0--23
    u16 m_wMinute;	                    ///< �� - 0--59
    u16 m_wSecond;	                    ///< �� - 0--59
} TPfcTimeInfo;

/**
* @brief        PfcGetTimeInfo
* @note         ȡ�õ�ǰ��Time��Ϣ
* @param[in]    ptTimeInfo: ϵͳtime��Ϣ�ṹ
* @return       ����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
*/
API BOOL32 PfcGetTimeInfo( TPfcTimeInfo *ptTimeInfo );

/**
* @brief        PfcSetTimeInfo
* @note         ���õ�ǰ��Time��Ϣ
* @param[in]    ptTimeInfo: ϵͳtime��Ϣ�ṹ
* @return       ����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
*/
API BOOL32 PfcSetTimeInfo( TPfcTimeInfo *ptTimeInfo );

/// ���̷�����Ϣ
typedef struct
{
    u32 m_dwPhysicsSize;	            ///< ���̷�����С(MByte)
    u32 m_dwUsedSize;	                ///< ��ʹ�ô��̷�����С(MBytes)
    u32 m_dwFreeSize;	                ///< ���ô��̷�����С(MBytes)
} TPfcDiskInfo;

/// ���̷�����󳤶�
#define MAX_PARTION_NAME_LENGTH     255
/**
* @brief        PfcGetDiskInfo
* @note         ȡ�õ�ǰ�Ĵ��̷�����Ϣ
* @param[in]    pchPartionName: ������
                    win32 - "c:"
                    Vxworks - "/ata0/"
                    Linux - "/"
* @param[out]   ptDiskInfo: ϵͳ���̷�����Ϣ�ṹ
* @return       ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
*/
API BOOL32 PfcGetDiskInfo( s8 *pchPartionName , TPfcDiskInfo *ptDiskInfo );

//////////////////////////////////////////////////////////////////////
//	�׽��ַ�װ���û�ʹ���׽���ǰ�����ȵ���PfcSockInit()���׽��ֿ���г�ʼ����
//	ʹ����֮������Ҫ����PfcSockCleanup()�ͷŶ��׽��ֿ��ʹ�á�����vxWorks��
//	Windows�Ĺر��׽��ֵĺ�����ͬ�������ڵ���socket��connect�Ⱥ���ʱ������
//	ֵ����Ҳ��һ����OSPҲ�����˱�Ҫ�ķ�װ��ԭ���Ǳ�����Windows�»���һ�¡�
/////////////////////////////////////////////////////////////////////

/**
* @brief        PfcSockInit
* @note         �׽��ֳ�ʼ������װWindows�µ�WSAStartup��vxWorks�·���TRUE
* @return       ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcSockInit(void);

/**
* @brief        PfcSockShutdown
* @note         �Ը�ƽ̨shutdown�ļ򵥷�װ
* @param[in]    hSock: Ҫ�������׽��֣�
* @param[in]    dwMode: ����ģʽ, ��ȡֵΪSTOP_SEND, STOP_RECV��STOP_BOTH
* @return       ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcSockShutdown(PFCSOCKHANDLE hSock, u32 dwMode);

/**
* @brief        SockClose
* @note         �ر��׽��֣���װwindows�µ�closesocket��vxworks�µ�close.
* @param[in]    tSock: ���ر��׽��ֵľ��������socketʱ���أ���
* @return       ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcSockClose(PFCSOCKHANDLE tSock);

/**
* @brief        PfcSockCleanup
* @note         �׽������٣���װwindows��WSACleanup��vxWorks�·���TRUE
* @return       �ɹ�����TRUE��ʧ�ܷ���FALSE
*/
API BOOL32 PfcSockCleanup(void);

/**
* @brief        PfcAgentStart
* @note         ����һ��Osp���Դ���, ���а���һ�����Է�����APP��һ���ͻ���APP, ������Ҫ��ͬ��APP��, ��Ϣ������̶���һ����.
* @param[in]    port -- �˿ں�, ��������APP��������ڵ����øö˿ڴ���֮
*/
API int PfcAgentStart(u16 port);


//////////////////////////////////////////////////////////////////////////
// Start of PFC memory pool
//////////////////////////////////////////////////////////////////////////
/**
* @defgroup     PFC_MemoryPool PFC memory pool wrapper
* @brief        pfc memory pool wrapper interfaces.
* @{
*/

/**
* @brief        PfcAllocMem
* @note         ���ڴ���з����ڴ��
* @param[in]    size: ��������ڴ���С��
* @return       �ɹ�����ָ����䵽���ڴ���ָ�룬ʧ�ܷ���NULL.
*/
API void *PfcAllocMem(size_t size);

/**
* @brief        PfcFreeMem
* @note         �ͷ����ȷ�����ڴ��
* @param[in]    token: ָ����ͷŵ��ڴ���ָ�롣
*/
API void PfcFreeMem(void *token);

/**
* @}
*/
//////////////////////////////////////////////////////////////////////////
// End of PFC memory pool wrapper
//////////////////////////////////////////////////////////////////////////





/**
* @brief        PfcSetPriRealTime
* @note         �Ѷ�ʱ������Ϣ���͵�������ߵ���ϵͳnet���񻹸ߵ����ȼ�
*/
API void PfcSetPriRealTime();

/**
* @brief        PfcAddrListGet
* @note         ��ȡ������ַ������
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @param[in]    adwIPList[] : [in/out]�û���������ڵ�ַ�����ݵ�������׵�ַ
* @param[in]    wNum : [in]�û����������Ĵ�С
* @return       ���ر�����ַ���е�ַ����������ʱ����0
*/
API u16  PfcAddrListGet(u32 adwIPList[], u16 wNum);

/** 5.0�ϲ��� ԭ��ҵosp���нӿ� */
/**
* @brief        PfcGetTelServerPort
* @note         ��ȡtelnet server�Ķ˿ں�.
* @pre          ���û������telnet server, ����û�г�ʼ��Osp, ����-1
* @return       ����telnet server��listen�˿ں�, ���û������, ����-1
*/
API s32 PfcGetTelServerPort();

/**
* @brief        OspPton
* @note         IP address & string conversion
* @param[in]    af: socket type
* @param[in]    src: IP address string
* @param[out]   dst: IP address
*/
API s32 PfcPton(s32 af, const char *src, void *dst);

/**
* @brief        OspNtop
* @note         IP address & string conversion
* @param[in]    af: socket type
* @param[in]    src: ip address pointer
* @param[out]   dst: ip address string
* @param[in]    size: input ip address length
*/
API const char *PfcNtop(s32 af, const void *src, char *dst, size_t size);

#if (defined(_MSC_VER) && (_MSC_VER > 1200)) || !defined(_MSC_VER)

#define PFC_IS_VALID_LOCAL_ADDR(netaddr)   \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 && (netaddr)->v6addr.sin6_port)))

#define PFC_IS_VALID_REMOTE_ADDR(netaddr)    \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET &&    \
        (netaddr)->v4addr.sin_addr.s_addr && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 &&   \
        (netaddr)->v6addr.sin6_port)))

/**
* @brief        PFC_SET_NETADDR_ADDR
* @note         IPV4�����ֽ����ַ���õ�TNetAddr�ṹ��
* @pre          ֻ����IPV4������ĵ�ַ��ʱ
* @param[in]    netaddr: TPfcNetAddr�ṹ��
* @param[in]    type: AF_INET(ipv4) ���� AF_INET6(ipv6)
* @param[in]    address: u32�������ַ
*/
#define PFC_SET_NETADDR_ADDR(netaddr, type, address)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_addr.s_addr = (address);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/**
* @brief        PFC_NET_SET_NETADDR_ADDR
* @note         �����ֽ����ַ���õ�TNetAddr�ṹ��
* @param[out]    TPFCNetAddr * ����
* @param[in]   type: u16 ����, ȡֵ PFC_NET_FAMILY_INET (ipv4) / PFC_NET_FAMILY_INET6 (ipv6)
������
* @param[in]   address: u16 ���� ����, ������
*/
#define PFC_NET_SET_NETADDR_ADDR(netaddr, type, address)    \
    do {    \
    if (!(netaddr)) break; \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            memcpy(&(netaddr)->v4addr.sin_addr, &(address), sizeof((netaddr)->v4addr.sin_addr)); \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            memcpy(&(netaddr)->v6addr.sin6_addr, &(address), sizeof((netaddr)->v6addr.sin6_addr));\
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/**
* @brief        PFC_GET_NETADDR_ADDR
* @note         ��ȡTNetAddr�ṹ���е������ֽ����ַ��address,��ȡTNetAddr�ṹ���е�type��type
* @param[in]    netaddr: TOspNetAddr�ṹ��
* @param[out]   type: ������͵�ָ��
* @param[out]   address: ��ŵ�ַ��ָ��
*/
#define PFC_GET_NETADDR_ADDR(netaddr, type, address)    \
	do {	\
		switch((netaddr)->staddr.ss_family) {	  \
		case AF_INET:	\
			*(type) = (netaddr)->v4addr.sin_family;		\
			*(address) = (netaddr)->v4addr.sin_addr.s_addr;	 \
			break;		\
		case AF_INET6:	\
			*(type) = (netaddr)->v6addr.sin6_family; 	\
			break;	\
		default:	\
			break;	\
		}	\
	} while(0)

/**
* @brief        PFC_SET_NETADDR_ADDR_STR
* @note         ����ַ�ַ������õ�netaddr�ṹ��
* @param[in]    netaddr: TOspNetAddr�ṹ��
* @param[in]    type: AF_INET(ipv4) ���� AF_INET6(ipv6)
* @param[in]    address: ��ַ�ַ���ָ��
*/
#define PFC_SET_NETADDR_ADDR_STR(netaddr, type, address)    \
    do {    \
        switch(type) {      \
        case AF_INET:       \
            (netaddr)->v4addr.sin_family = (type);      \
            if (address)    \
                PfcPton(type, address, &((netaddr)->v4addr.sin_addr.s_addr));\
            else        \
                (netaddr)->v4addr.sin_addr.s_addr = INADDR_ANY;    \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            if (address)    \
                PfcPton(type, address, &((netaddr)->v6addr.sin6_addr.s6_addr));  \
            else    \
                memcpy(&(netaddr)->v6addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/**
* @brief        PFC_GET_NETADDR_ADDR_STR
* @note         ��ȡTNetAddr�ṹ���еĵ�ַ�ַ�����address,��ȡTNetAddr�ṹ���е�type��type
* @param[in]    netaddr: TOspNetAddr�ṹ��
* @param[out]   type: ������͵�ָ��
* @param[out]   address: ��ַ�ַ���ָ��
* @param[out]   size: address��ַ�ĳ���
*/
#define PFC_GET_NETADDR_ADDR_STR(netaddr, type, address, size)    \
	do {	\
		if (type)    \
		    *(type) = (netaddr)->staddr.ss_family;		\
		switch((netaddr)->staddr.ss_family) {		\
		case AF_INET:		\
			if (address)	\
				PfcNtop((s32)(*(type)), &((netaddr)->v4addr.sin_addr.s_addr), address, size);\
			break;		\
		case AF_INET6:	\
			if (address)	\
				PfcNtop((s32)(*(type)), &((netaddr)->v6addr.sin6_addr.s6_addr), address, size);  \
			break;	\
		default:	\
			break;	\
		}	\
	} while(0)

/**
* @brief        PFC_SET_NETADDR_PORT
* @note         �ṩ������˿ں����õ�TNetAddr ��
* @param[in]    netaddr: TPfcNetAddr�ṹ��
* @param[in]    type: AF_INET(ipv4) ���� AF_INET6(ipv6)
* @param[in]    port: ������˿ں�
*/
#define PFC_SET_NETADDR_PORT(netaddr, type, port)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_port = htons(port);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            (netaddr)->v6addr.sin6_port = htons(port);  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)


/**
* @brief        PFC_NET_SET_NETADDR_PORT
* @note         �ṩ������˿ں����õ�TNetAddr ��
* @param[in]    netaddr: TPfcNetAddr�ṹ��
* @param[in]    type: AF_INET(ipv4) ���� AF_INET6(ipv6)
* @param[in]    port: ������˿ں�
*/
#define PFC_NET_SET_NETADDR_PORT(netaddr, type, port)    \
	PFC_SET_NETADDR_PORT(netaddr, type, port)

/**
* @brief        PFC_GET_NETADDR_PORT
* @note         ��ȡTNetAddr�ṹ���ж˿ںŵ�port,��ȡTNetAddr�ṹ���е�type��type
* @param[in]    netaddr: TOspNetAddr�ṹ��
* @param[out]   type: ������͵�ָ��
* @param[out]   port: ���������˿ںŵ�ָ��
*/
#define PFC_GET_NETADDR_PORT(netaddr, type, port)    \
	do {	\
		if (type)    \
		    *(type) = (netaddr)->staddr.ss_family;    \
		switch((netaddr)->staddr.ss_family) {	  \
		case AF_INET:	\
			if (port)   \
			    *(port) = ntohs((netaddr)->v4addr.sin_port);	\
			break;		\
		case AF_INET6:	\
			if (port)   \
			    *(port) = ntohs((netaddr)->v6addr.sin6_port);	\
			break;	\
		default:	\
			break;	\
		}	\
	} while(0)

#endif

/// ϵͳ���Ʋ���
#define OSP_ETHERNET_ADAPTER_MAX_IP         16              ///< ÿ���ӿ�������ַ����
#define OSP_ETHERNET_ADAPTER_MAX_NUM        32              ///< ÿ���豸���ӿ���
#define OSP_ETHERNET_ADAPTER_NAME_LENGTH    64              ///< ÿ���ӿ�������󳤶�
#define OSP_ETHERNET_ADAPTER_MAC_LENGTH     6               ///< �ӿڵ�MAC��ַ����

/// ����״̬,��Ӧ��TOSPEthernetAdapterInfo �ṹ��nState�ֶ�
#define OSP_ETHERNET_ADAPTER_UNKNOWN        0               ///< unknown status
#define OSP_ETHERNET_ADAPTER_UP             1               ///< ethernet up
#define OSP_ETHERNET_ADAPTER_DOWN           2               ///< ethernet down

/// ����������Ϣ
typedef struct
{
	u32 nId;                                                ///< ������
	u32 nState;                                             ///< ����״̬
	u8  achName[OSP_ETHERNET_ADAPTER_NAME_LENGTH];          ///< ������
	u8  achDescription[OSP_ETHERNET_ADAPTER_NAME_LENGTH];   ///< ������Ϣ����
	u8  achMacAddr[OSP_ETHERNET_ADAPTER_MAC_LENGTH];        ///< �������ַ
	u32 nIpNum;                                             ///< ��ַ����
	u32 anIp[OSP_ETHERNET_ADAPTER_MAX_IP];                  ///< ��ַ
} TPfcEthernetAdapterInfo;

/// ���������Ϣ
typedef struct
{
	u32 nNum;                                               ///< ��������
	TPfcEthernetAdapterInfo atEthernetAdapter[OSP_ETHERNET_ADAPTER_MAX_NUM];///< ������Ϣ
} TPfcEthernetAdapterInfoAll;

/**
* @brief        PfcGetEthernetAdapterInfoAll
* @note         ��ȡ��ϵͳ������̫��������Ϣ
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @param[out]   ptEthernetAdapterInfoAll: ��������Ϣ�ṹ���ο����ݽṹ�Ķ���
* @return       TRUE/ FALSE �ɹ�/ʧ��
*/
API BOOL32 PfcGetEthernetAdapterInfoAll(TPfcEthernetAdapterInfoAll *ptEthernetAdapterInfoAll);

/**
* @brief        PfcGetEthernetAdapterInfo
* @note         ���������Ż�ȡ������Ϣ
* @pre          �������Windows��ʹ�ñ������������ȵ���PfcInit������WSAStartup��������Ч�ʽϵͣ���Ҫ�ظ����á�
* @param[in]    nEthAdapterId: �������0-ETHERNET_ADAPTER_MAX_NUM�����֧��16������
* @param[out]   ptEthernetAdapterInfo: ��������Ϣ�ṹ
* @return       TRUE/FALSE  �ɹ�/ʧ��
*/
API BOOL32 PfcGetEthernetAdapterInfo(u32 nEthAdapterId, TPfcEthernetAdapterInfo *ptEthernetAdapterInfo);

/**
* @brief        PfcSetMemCheck
* @note         ��ȡ�ڴ��ַ����
* @param[in]    pdwCheckMem :  Ҫ�����ڴ��ַ
* @param[in]    dwCheckValue ��  ��������ֵ
* @param[in]    bEqual ����������Ϊ��ʱ����ʾҪ�����ڴ��ַ���ݲ���������ֵʱ��Ҫ�澯
* @pre          ��������Ϊ��ʱ����ʾҪ�����ڴ��ַ���ݵ�������ֵʱ��Ҫ�澯
* @return       �ɹ�����TRUE, ʧ�ܷ���FALSE.
*/
API BOOL32  PfcSetMemCheck(u32 *pdwCheckMem, u32 dwCheckValue, BOOL32  bEqual);

/**
* @brief        pfchelp
* @pre          
* @note         inline help function of PFC module
* @return       void
*/
API void pfchelp(void);


/*=============================================================================
�� �� ����PfcTelSvrSetAddr
��    �ܣ�ָ��������ַ
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����void
�� �� ֵ��void
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/11/20  1.0
=============================================================================*/
API u16 PfcTelSvrSetAddr(TPfcNetAddr addr);

typedef enum {
	PFC_EVENT_CB_TIMEOUT           = 1,
	PFC_EVENT_CB_UNDEFINED         = 0
} PfcTelSvrEvtType;

typedef struct {
	PfcTelSvrEvtType     type;        //��Ҫ����Ļص�����
	void                *param;
} PfcTelSvrEvtCBParam;
typedef void (*PfcTelSvrSetCallback)(void *pContext, PfcTelSvrEvtCBParam *pCBEvtParam);
/*=============================================================================
�� �� ����PfcTelSvrSetTimeout
��    �ܣ�telnet��ʱ�Ͽ����
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����u32 timeout ��ʱʱ������Ϊ��λ ��timeout==0��ȡ����ʱ��
�� �� ֵ��void
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/11/20  1.0
=============================================================================*/
API u16 PfcTelSvrSetTimeout(u32 timeout);

/*=============================================================================
�� �� ����PfcTelSvrSetCB
��    �ܣ�telnet��ʱ�Ͽ��ص�
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����OspTelSvrSetCallback cb ��ʱ�ص����� ��pContext==NULL ��ȡ���ص�
�� �� ֵ��BOOL32
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/11/20  1.0
=============================================================================*/
API u16 PfcTelSvrSetCB(void *pContext, PfcTelSvrEvtCBParam *pCBEvtParam, PfcTelSvrSetCallback cb);

/*=============================================================================
�� �� ����PfcTelSvrStart
��    �ܣ�����PfcTelnet
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����
�� �� ֵ��u16  ����telnet�������ص�ǰtelnet״̬
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/11/20  1.0
=============================================================================*/
API u16 PfcTelSvrStart();

/*=============================================================================
�� �� ����PfcTelSvrStop
��    �ܣ��ر�PfcTelnet
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����
�� �� ֵ��u16 �ر�telnet�������ص�ǰtelnet״̬
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/11/20  1.0
=============================================================================*/
API u16 PfcTelSvrStop();

/*=============================================================================
�� �� ����PfcTelSvrInit
��    �ܣ�Pfc�ն˳�ʼ��
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����
�� �� ֵ��BOOL32
-------------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾  �޸���  �޸�����
2018/12/24  1.0
=============================================================================*/
API BOOL32 PfcTelSvrInit();






















/// ������Ա������ģ�����Ա������ʵ��
template <class I, int maxins, class A, u8 maxAliasLen>
BOOL32 zTiTemplate<I, maxins, A, maxAliasLen>::InitAliasArray()
{
	for(int i = 0; i < maxins; i++) {
		instAliasArray[i].instId = 0xFFFF;
		instAliasArray[i].aliasRet = 0;
		instAliasArray[i].nextLoc = 0xFFFF;

		bakInstAliasArray[i].instId = 0xFFFF;
		bakInstAliasArray[i].aliasRet = 0;
		bakInstAliasArray[i].nextLoc = 0xFFFF;
	}
	curBakArrayNum = 0;

	return TRUE;
}

template <class I, int maxins, class A, u8 maxAliasLen>
u32 zTiTemplate<I, maxins, A, maxAliasLen>::AliasToWord(char *pchAlias, u8 len)
{
	u32  ret = 0;
	for(u8 i = 0; i < len; i++ ) {
		ret =  (ret << 5) + ret + (*(pchAlias + i));
	}

	ret = ret & (maxins - 1);
	return  ret;
}

template <class I, int maxins, class A, u8 maxAliasLen>
BOOL32 zTiTemplate<I, maxins, A, maxAliasLen>::IsInBakArray(u32  setRet)
{
	/* ���ȼ�������� */
	if(instAliasArray[setRet].instId == 0xFFFF) {  /*�����������λ�û�û�б�ռ��*/
		return FALSE;     /*���ʵ����ŵ���������*/
	} else {     /*�����������λ�û��Ѿ���ռ��*/
		return TRUE;   /*���ʵ����ŵ�bak�����еĿ���λ��*/
	}
}

template <class I, int maxins, class A, u8 maxAliasLen>
int zTiTemplate<I, maxins, A, maxAliasLen>::GetInstanceNumber(void)
{
	return maxins;
}

template <class I, int maxins, class A, u8 maxAliasLen>
u8 zTiTemplate<I, maxins, A, maxAliasLen>::GetMaxAliasLen(void)
{
	return maxAliasLen;
}

template <class I, int maxins, class A, u8 maxAliasLen>
CTiInstance *zTiTemplate<I, maxins, A, maxAliasLen>::GetInstance(u16 insid)
{
	if(insid == CTiInstance::DAEMON)
		return &daemIns;

	if((insid > 0) && (insid <= maxins))
		return &insarray[insid - 1];

	return NULL;
}

template <class I, int maxins, class A, u8 maxAliasLen>
BOOL32 zTiTemplate<I, maxins, A, maxAliasLen>::SetInstAlias(u16 insid, const char *pchAlias, u8 len)
{
	u32  dwCycTime = 0;

	/*�ȰѼ�¼��Ϣ������ٲ���������*/
	if(insid != CTiInstance::DAEMON) {
		u32 setRet = AliasToWord((char *)pchAlias, len);    /*ͨ��������������ֵ*/
		if(setRet >= maxins)
			return FALSE;

		BOOL32  isBak = IsInBakArray(setRet);   /*ȷ�����λ��*/
		if( isBak == FALSE) {   /*�������������*/
			instAliasArray[setRet].aliasRet = setRet;
			instAliasArray[setRet].instId = insid;
			instAliasArray[setRet].nextLoc = 0xFFFF;   /*��ʼ��*/
		} else {     /*�����bak������*/
			u32 loc = curBakArrayNum;
			/*�����ݼ�¼��bak������Ӧλ����*/
			for(loc = 0; loc < maxins; loc++) {
				if(bakInstAliasArray[loc].instId == 0xFFFF)
					break;
			}
			if(loc >= maxins) {
				return FALSE;
			}

			bakInstAliasArray[loc].aliasRet = setRet;
			bakInstAliasArray[loc].instId = insid;
			bakInstAliasArray[loc].nextLoc = 0xFFFF;   /*��ʼ��*/

			/*����ͬ����ֵ�����ݿ���������*/
			if(instAliasArray[setRet].nextLoc == 0xFFFF) { /*����������δ����*/
				instAliasArray[setRet].nextLoc = loc;   /*ָ��bak�����д��λ��*/
			} else {
				TTiInstAliasInfo *tempAlias = &bakInstAliasArray[instAliasArray[setRet].nextLoc];
				if(tempAlias == NULL)
					return FALSE;

				dwCycTime = 0;
				while(tempAlias->nextLoc != 0xFFFF) {
					if(tempAlias->nextLoc >= maxins)
						return FALSE;

					tempAlias = &bakInstAliasArray[tempAlias->nextLoc];
					if(tempAlias == NULL)
						return FALSE;

					dwCycTime++;
					if(dwCycTime > maxins) {
						PfcPrintf(TRUE, FALSE, "SetInstAlias() return Cycle as dwCycTime=%d\n", dwCycTime);
						return FALSE;
					}
				}

				tempAlias->nextLoc = loc; /*�ҵ�bak���������һ����ͬ����ֵ��λ��*/
			}

			curBakArrayNum++;     /*bak�����Ÿ�������*/
		}
	}

	CTiInstance *pIns = GetInstance(insid);
	if( pIns != NULL && len <= maxAliasLen) {
		CTiInstance *pOtherIns = FindInstByAlias(pchAlias, len);
		if( (pOtherIns != NULL) && (pOtherIns->GetInsID() != pIns->GetInsID()) ) {
			return FALSE;
		}
		memcpy(pIns->m_alias, pchAlias, len);
		pIns->m_aliasLen = len;
		//return pIns->SetAlias(pchAlias, len);
	}
	return TRUE;
}

template <class I, int maxins, class A, u8 maxAliasLen>
CTiInstance *zTiTemplate<I, maxins, A, maxAliasLen>::FindInstByAlias(const char *pchAlias, u8 len)
{
	/* �ȿ��Ƿ���Daemonʵ�� */
	u8   aliasLen = 0;
	u32  dwCycTime = 0;

	if(maxAliasLen < len) {
		return NULL;
	}

	char aliasBuf[MAX_ALIAS_LEN];
	memset(aliasBuf, 0, MAX_ALIAS_LEN);

	CTiInstance *pIns = GetInstance(CTiInstance::DAEMON);
	if(pIns != NULL &&
	   pIns->GetAlias(aliasBuf, maxAliasLen, &aliasLen)) {
		if( (aliasLen == len) &&
			(memcmp(aliasBuf, pchAlias, len) == 0) ) {
			return pIns;
		}
	}

	/* �ٿ��Ƿ���ͨʵ�� */
	TTiInstAliasInfo *tempAlias = NULL;
	u32  setRet = AliasToWord((char *)pchAlias, len);
	/*�Ȳ���������*/
	if(setRet >= maxins)
		return NULL;

	tempAlias = &instAliasArray[setRet];
	if(tempAlias == NULL)
		return NULL;

	pIns = GetInstance(tempAlias->instId);
	if((pIns != NULL) && (pIns->GetAlias(aliasBuf, maxAliasLen, &aliasLen))) {
		if( (aliasLen == len) && (memcmp(aliasBuf, pchAlias, len) == 0) ) {
			return pIns;
		}
	}
	/*�ٲ���bak����*/
	do {
		if((tempAlias == NULL) || (tempAlias->nextLoc >= maxins))
			return NULL;

		tempAlias = &bakInstAliasArray[tempAlias->nextLoc];
		if(tempAlias == NULL)
			return NULL;

		CTiInstance *pIns = GetInstance(tempAlias->instId);
		if((pIns != NULL) && (pIns->GetAlias(aliasBuf, maxAliasLen, &aliasLen))) {
			if((aliasLen == len) && (memcmp(aliasBuf, pchAlias, len) == 0)) {
				return pIns;
			}
		}

		dwCycTime++;
		if(dwCycTime > maxins) {
			PfcPrintf(TRUE, FALSE, "FindInstByAlias() return Cycle as dwCycTime=%d\n", dwCycTime);
			return NULL;
		}
	} while(tempAlias->nextLoc != 0xFFFF);

	return NULL;
}

/*���ʵ��������¼��Ϣ*/
template <class I, int maxins, class A, u8 maxAliasLen>
BOOL32 zTiTemplate<I, maxins, A, maxAliasLen>::ClearInstAlias(u16 insid, const char *pAlias, u8 len)
{
	u32  dwCycTime = 0;

	if((maxAliasLen < len) || (insid == CTiInstance::DAEMON)) {
		return FALSE;
	}

	u32 setRet = AliasToWord((char *)pAlias, len);    /*ͨ��������������ֵ*/
	if(setRet >= maxins)
		return FALSE;

	/*�Ȳ��������飬�ٲ��ұ�������*/
	if(instAliasArray[setRet].instId == insid) {
		if(instAliasArray[setRet].nextLoc == 0xFFFF) { /*����������δ����*/
			instAliasArray[setRet].aliasRet = 0;       /*��ʼ��*/
			instAliasArray[setRet].instId = 0xFFFF;
			instAliasArray[setRet].nextLoc = 0xFFFF;
		} else {
			TTiInstAliasInfo *tempAlias = &instAliasArray[setRet];
			if(tempAlias == NULL)
				return FALSE;

			if(tempAlias->nextLoc >= maxins)
				return FALSE;

			TTiInstAliasInfo *relocAlias = &bakInstAliasArray[tempAlias->nextLoc];
			if(relocAlias == NULL)
				return FALSE;

			dwCycTime = 0;
			while(relocAlias->nextLoc != 0xFFFF) {
				tempAlias->aliasRet = relocAlias->aliasRet;    //����һ���¼��Ϣ��䱾���¼��Ϣ
				tempAlias->instId = relocAlias->instId;

				if(relocAlias->nextLoc >= maxins)
					return  FALSE;

				tempAlias = relocAlias;         //λ���Ƶ���һ��
				relocAlias = &bakInstAliasArray[relocAlias->nextLoc];
				if(relocAlias == NULL)
					return  FALSE;

				dwCycTime++;
				if(dwCycTime > maxins) {
					PfcPrintf(TRUE, FALSE, "ClearInstAlias(1) return Cycle as dwCycTime=%d\n", dwCycTime);
					return FALSE;
				}
			}

			tempAlias->aliasRet = relocAlias->aliasRet;    //�ѵ����һ���¼��Ϣ��
			tempAlias->instId = relocAlias->instId;
			tempAlias->nextLoc = 0xFFFF;

			relocAlias->aliasRet = 0;      //������һ���¼��
			relocAlias->instId = 0xFFFF;
			relocAlias->nextLoc = 0xFFFF;

			curBakArrayNum--;     /*bak�����Ÿ�������*/
		}
	} else {
		if(instAliasArray[setRet].nextLoc == 0xFFFF) { /*����������δ����*/
			return  FALSE;
		} else {
			TTiInstAliasInfo *tempAlias = &bakInstAliasArray[instAliasArray[setRet].nextLoc];
			if(tempAlias == NULL)
				return FALSE;

			TTiInstAliasInfo *relocAlias = &(instAliasArray[setRet]);

			dwCycTime = 0;
			while(tempAlias->instId != insid) {
				relocAlias = tempAlias;

				if(tempAlias->nextLoc != 0xFFFF) {
					if(tempAlias->nextLoc >= maxins)
						return  FALSE;

					tempAlias = &bakInstAliasArray[tempAlias->nextLoc];
					if(tempAlias == NULL)
						return FALSE;

					dwCycTime++;
					if(dwCycTime > maxins) {
						PfcPrintf(TRUE, FALSE, "ClearInstAlias(2) return Cycle as dwCycTime=%d\n", dwCycTime);
						return FALSE;
					}
				} else {
					return  FALSE;
				}
			}

			/*�ҵ�bak�����ж�Ӧʵ����¼λ�ã������λ�õļ�¼ֵ���Ѽ�¼������������*/
			if(tempAlias->nextLoc == 0xFFFF) {
				if(relocAlias != NULL)
					relocAlias->nextLoc = 0xFFFF;

				tempAlias->aliasRet = 0;     //��λ��Ϊ������ֵ�����һλ�ã�ֱ�����
				tempAlias->instId = 0xFFFF;
			} else {
				relocAlias = &bakInstAliasArray[tempAlias->nextLoc];
				if(relocAlias == NULL)
					return FALSE;

				dwCycTime = 0;
				while(relocAlias->nextLoc != 0xFFFF) {
					tempAlias->aliasRet = relocAlias->aliasRet;    //����һ���¼��Ϣ��䱾���¼��Ϣ
					tempAlias->instId = relocAlias->instId;

					if(relocAlias->nextLoc >= maxins)
						return  FALSE;

					tempAlias = relocAlias;         //λ���Ƶ���һ��
					relocAlias = &bakInstAliasArray[relocAlias->nextLoc];
					if(relocAlias == NULL)
						return  FALSE;

					dwCycTime++;
					if(dwCycTime > maxins) {
						PfcPrintf(TRUE, FALSE, "ClearInstAlias(3) return Cycle as dwCycTime=%d\n", dwCycTime);
						return FALSE;
					}
				}

				tempAlias->aliasRet = relocAlias->aliasRet;    //�ѵ����һ���¼��Ϣ��
				tempAlias->instId = relocAlias->instId;
				tempAlias->nextLoc = 0xFFFF;

				relocAlias->aliasRet = 0;      //������һ���¼��
				relocAlias->instId = 0xFFFF;
				relocAlias->nextLoc = 0xFFFF;
			}

			curBakArrayNum--;     /*bak�����Ÿ�������*/
		}
	}

	return  TRUE;
}

#if defined(_MSC_VER) && !defined(_EQUATOR_)
#pragma pack(pop)
#endif

/**
* @}
*/

#endif // _OSP_H
