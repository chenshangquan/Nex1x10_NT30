/******************************************************************************
ģ����	: OSPSMALL
�ļ���	: osp_small.h
����    : OSPSMALL���ͷ�ļ�
�汾	��4.0
******************************************************************************/
/***************************
ģ��汾��OSP.Small.KDV.4.0.1.1.0.20080628
���ӹ��ܣ�Э����OSP�汾����,����OSAPITickGet���������ⷵ��-1��ʼ�շ�����ȷ��tick
�޸�ȱ�ݣ���
�ύ�ˣ���һƽ
*****************************/

#ifndef _OSP_SMALL_H
#define _OSP_SMALL_H


#define OSAPI_TIMER_MAGIC                 0xFCA512B5 

#define OSAPI_TIMER_NUMBER				  100  

#define OSAPI_THREAD_NUMBER               100     

#define OSAPI_ERROR_CODE_BASE             25000


#define OSAPI_TIMER_NOT_INIT              (OSAPI_ERROR_CODE_BASE+1)
#define OSAPI_TIMER_PARAM_ERROR           (OSAPI_ERROR_CODE_BASE+2)
#define OSAPI_TIMER_HANDLE_ERROR          (OSAPI_ERROR_CODE_BASE+3)
#define OSAPI_TIMER_MEMALLOC_FAIL         (OSAPI_ERROR_CODE_BASE+4)
#define OSAPI_TIMER_SEM_CREATE_FAIL       (OSAPI_ERROR_CODE_BASE+4)
#define OSAPI_TIMER_TASK_CREATE_FAIL      (OSAPI_ERROR_CODE_BASE+4)
#define OSAPI_TIMER_NO_FREE               (OSAPI_ERROR_CODE_BASE+5)
#define OSAPI_TIMER_IS_FREE               (OSAPI_ERROR_CODE_BASE+6)
#define OSAPI_TIMER_DELETED               (OSAPI_ERROR_CODE_BASE+7)
#define OSAPI_TIMER_NO_USED               (OSAPI_ERROR_CODE_BASE+8)

#define OSAPI_TELNET_BIND_FAIL            (OSAPI_ERROR_CODE_BASE+9)
#define OSAPI_TELNET_LISTEN_FAIL          (OSAPI_ERROR_CODE_BASE+10)
#define OSAPI_TELNET_SEM_FAIL             (OSAPI_ERROR_CODE_BASE+11)
#define OSAPI_TELNET_TASK_FAIL            (OSAPI_ERROR_CODE_BASE+12)

#define OSAPI_TELNET_NOT_CONNECT          (OSAPI_ERROR_CODE_BASE+13)
#define OSAPI_TELNET_SERVER_FAIL          (OSAPI_ERROR_CODE_BASE+14)
#define OSAPI_TELNET_SEND_OVERFLOW        (OSAPI_ERROR_CODE_BASE+15)
#define OSAPI_TELNET_SOCK_ERROR           (OSAPI_ERROR_CODE_BASE+16)
#define OSAPI_TELNET_PARAM_ERROR          (OSAPI_ERROR_CODE_BASE+17)

/********************************************************************
    OSAPI module
********************************************************************/
//#ifdef _VXWORKS_
///*#include "brddrvlib.h"*/
//#endif
//
//#ifdef _ARM_
//#include "brdwrapper.h"
//#endif


/*****************************************************************
	Common header files
******************************************************************/

#include "kdvtype.h"



/******************************************************************************
	Linux header files
******************************************************************************/

#ifdef _LINUX_
#ifdef PWLIB_SUPPORT
#include <ptlib.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <malloc.h>
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
#include <sys/ioctl.h>
#include <sys/types.h>
typedef struct sockaddr * SOCKADDRPTR;  /* AL - 09/17/98 */
#define ioctlOnPtrTypeCast s32         /* AL - 10/28/98 */
 
typedef socklen_t sockaddr_namelen;

#define ERRNOGET errno
#define ERRNOSET(a) errno = a

#endif 

/*****************************************************************
	Win32 header files
******************************************************************/
#ifdef _MSC_VER

#include <malloc.h>
#include <stdio.h>
/*#include <windows.h>*/
#include <winsock2.h>

#include <assert.h>
#pragma comment(lib,"Ws2_32.lib")

typedef struct sockaddr * SOCKADDRPTR;  /* AL - 09/17/98 */
typedef unsigned long * ioctlOnPtrTypeCast;         /* AL - 11/25/98 */
typedef int sockaddr_namelen;
#define ioctl ioctlsocket
#define close closesocket

#define ERRNOGET GetLastError()
#define ERRNOSET(a) SetLastError(a)

#define EWOULDBLOCK             WSAEWOULDBLOCK
#define EINPROGRESS             WSAEINPROGRESS
#define EALREADY                WSAEALREADY
#define ENOTSOCK                WSAENOTSOCK
#define EDESTADDRREQ            WSAEDESTADDRREQ
#define EMSGSIZE                WSAEMSGSIZE
#define EPROTOTYPE              WSAEPROTOTYPE
#define ENOPROTOOPT             WSAENOPROTOOPT
#define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
#define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
#define EOPNOTSUPP              WSAEOPNOTSUPP
#define EPFNOSUPPORT            WSAEPFNOSUPPORT
#define EAFNOSUPPORT            WSAEAFNOSUPPORT
#define EADDRINUSE              WSAEADDRINUSE
#define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
#define ENETDOWN                WSAENETDOWN
#define ENETUNREACH             WSAENETUNREACH
#define ENETRESET               WSAENETRESET
#define ECONNABORTED            WSAECONNABORTED
#define ECONNRESET              WSAECONNRESET
#define ENOBUFS                 WSAENOBUFS
#define EISCONN                 WSAEISCONN
#define ENOTCONN                WSAENOTCONN
#define ESHUTDOWN               WSAESHUTDOWN
#define ETOOMANYREFS            WSAETOOMANYREFS
#define ETIMEDOUT               WSAETIMEDOUT
#define ECONNREFUSED            WSAECONNREFUSED
#define ELOOP                   WSAELOOP
#define ENAMETOOLONG            WSAENAMETOOLONG
#define EHOSTDOWN               WSAEHOSTDOWN
#define EHOSTUNREACH            WSAEHOSTUNREACH
#define ENOTEMPTY               WSAENOTEMPTY
#define EPROCLIM                WSAEPROCLIM
#define EUSERS                  WSAEUSERS
#define EDQUOT                  WSAEDQUOT
#define ESTALE                  WSAESTALE
#define EREMOTE                 WSAEREMOTE


#endif


/*****************************************************************
		OS dependent data type definitions
******************************************************************/


#ifdef _LINUX_
#ifndef BOOL_DEFINE
#define BOOL_DEFINE
typedef int 						 BOOL;
#endif
#ifndef TRUE
#define TRUE						 1
#endif
#ifndef FALSE
#define FALSE						 0
#endif

typedef void *(*OSAPILINUXFUNC)(void *);

/*#define OSAPISEMHANDLE					 sem_t *  */
#define OSAPISEMHANDLE					 pthread_cond_t *
#define OSAPITASKHANDLE					 pthread_t
#endif

#ifndef _MSC_VER
#ifndef u64
#define u64							 unsigned long long
#endif
#define OSAPISOCKHANDLE				 int
#define OSAPISERIALHANDLE			 int

#ifndef SOCKADDR
#define SOCKADDR					 struct sockaddr
#endif
#ifndef SOCKADDR_IN
#define SOCKADDR_IN 				 struct sockaddr_in
#endif
#endif

#ifdef _MSC_VER
#define OSAPISEMHANDLE					 HANDLE
#define OSAPITASKHANDLE					 HANDLE

#define OSAPISOCKHANDLE		    	 SOCKET
#define OSAPISERIALHANDLE			 HANDLE
#endif

/*****************************************************************
		OS dependent macro definitions
******************************************************************/

#ifdef _LINUX_
#ifndef SOCKET_ERROR
#define SOCKET_ERROR		  (-1)
#endif
#ifndef INVALID_SOCKET
#define INVALID_SOCKET		  (-1)
#endif
#ifndef INVALID_SERIALHANDLE
#define INVALID_SERIALHANDLE  (-1)
#endif

#define OSAPI_NO_WAIT 		  0
#define OSAPI_WAIT_FOREVER	  (-1)

/* �ں���SockShutdown��ʹ�õĺ� */
#ifndef STOP_RECV
#define STOP_RECV			  0
#endif
#ifndef STOP_SEND
#define STOP_SEND			  1
#endif
#ifndef STOP_BOTH
#define STOP_BOTH			  2
#endif

#endif /* _LINUX_  */


#ifdef _MSC_VER
#ifndef INVALID_SERIALHANDLE
#define INVALID_SERIALHANDLE  INVALID_HANDLE_VALUE
#endif
#define TOsApiCommTimeouts	  COMMTIMEOUTS
#define TOsApiDCB 			  DCB
#define TOsApiComStat 		  COMSTAT

#define OSAPI_NO_WAIT 		  ((int)0)
#define OSAPI_WAIT_FOREVER	  ((int)-1)

#endif


/*****************************************************************
		OS independent section
******************************************************************/

#define OSAPI						0x20

#ifdef _MSC_VER			/* for Microsoft c++ */

#ifndef _EQUATOR_
#pragma pack(push)
#pragma pack(1)
#endif	/* _EQUATOR__ */

#ifdef __cplusplus			/* for C++ */
#ifndef API
#define API  extern "C"			__declspec(dllexport)
#endif
#else						/* for C */
#ifndef API
#define API						__declspec(dllexport)
#endif
#endif  /*__cplusplus*/

#else							/* for gcc */

#ifdef __cplusplus			/* for C++ */
#ifndef API
#define API  extern "C"	
#endif
#else						/* for C */
#ifndef API
#define API	
#endif
#endif

#endif

#define OSAPIVERSION			 "OSP.Small.KDV.4.0.1.1.0.20080628"	/* OSAPI Version */
#define OSAPI_VERSION_ID			 0x40					 /* Version 3.0 */

#define  OSAPI_MAX_TIMER_NUM 		     5000;   /* only support for 1~5000, 5001~9999 reserved */
#define  OSAPI_MAX_SERIALPORT_NUM	     10      /* maxium serial port supported */
#define  OSAPI_MAX_LOG_MSG_LEN          6000    //ÿ����־����󳤶�


#define TCPDISCONNECTTIME		 10 /* seconds now just for debug */
#define UNDISCONNDETECT 		 0	/* unable disconnect detect */
#define TCPHBNUM				 3	/* disconnect heartbeat times */
#define STATUSMSGOUTTIME		 3600 /* the status message output timer seconds */


#ifndef OSAPIMINCHAR
#define OSAPIMINCHAR 				0x80	  
#endif

#ifndef OSAPIMAXCHAR
#define OSAPIMAXCHAR 				0x7f		
#endif

#ifndef OSAPIMINSHORT
#define OSAPIMINSHORT				0x8000		
#endif

#ifndef OSAPIMAXSHORT
#define OSAPIMAXSHORT				0x7fff		
#endif

#ifndef OSAPIMINLONG
#define OSAPIMINLONG 				0x80000000	
#endif

#ifndef OSAPIMAXLONG
#define OSAPIMAXLONG 				0x7fffffff	
#endif

#ifndef OSAPIMAXBYTE
#define OSAPIMAXBYTE 				0xff		
#endif

#ifndef OSAPIMAXWORD
#define OSAPIMAXWORD 				0xffff		
#endif

#ifndef OSAPIMAXDWORD
#define OSAPIMAXDWORD				0xffffffff	
#endif

#ifndef _MSC_VER


/* Provider capabilities flags. */


#define OSAPI_PCF_DTRDSR		  ((u32)0x0001)
#define OSAPI_PCF_RTSCTS		  ((u32)0x0002)
#define OSAPI_PCF_RLSD		      ((u32)0x0004)
#define OSAPI_PCF_PARITY_CHECK    ((u32)0x0008)
#define OSAPI_PCF_XONXOFF   	  ((u32)0x0010)
#define OSAPI_PCF_SETXCHAR  	  ((u32)0x0020)
#define OSAPI_PCF_TOTALTIMEOUTS   ((u32)0x0040)
#define OSAPI_PCF_INTTIMEOUTS     ((u32)0x0080)
#define OSAPI_PCF_SPECIALCHARS    ((u32)0x0100)
#define OSAPI_PCF_16BITMODE  	  ((u32)0x0200)


/* Comm provider settable parameters. */

#define OSAPI_SP_PARITY		  ((u32)0x0001)
#define OSAPI_SP_BAUD 		  ((u32)0x0002)
#define OSAPI_SP_DATABITS 	  ((u32)0x0004)
#define OSAPI_SP_STOPBITS 	  ((u32)0x0008)
#define OSAPI_SP_HANDSHAKING  ((u32)0x0010)
#define OSAPI_SP_PARITY_CHECK ((u32)0x0020)
#define OSAPI_SP_RLSD 		  ((u32)0x0040)


/* Settable baud rates in the provider. */


#if defined(_LINUX_) && !defined(_EQUATOR_)
#define OSAPI_BAUD_075		  ((u32)0x00000001)
#define OSAPI_BAUD_110		  ((u32)0x00000002)
#define OSAPI_BAUD_134_5	  ((u32)0x00000004)
#define OSAPI_BAUD_150		  ((u32)0x00000008)
#define OSAPI_BAUD_300		  ((u32)0x00000010)
#define OSAPI_BAUD_600		  ((u32)0x00000020)
#define OSAPI_OSAPI_BAUD_1200 ((u32)0x00000040)
#define OSAPI_BAUD_1800		  ((u32)0x00000080)
#define OSAPI_BAUD_2400		  ((u32)0x00000100)
#define OSAPI_BAUD_4800		  ((u32)0x00000200)
#define OSAPI_BAUD_7200		  ((u32)0x00000400)
#define OSAPI_BAUD_9600		  ((u32)0x00000800)
#define OSAPI_BAUD_14400	  ((u32)0x00001000)
#define OSAPI_BAUD_19200	  ((u32)0x00002000)
#define OSAPI_BAUD_38400	  ((u32)0x00004000)
#define OSAPI_BAUD_56K		  ((u32)0x00008000)
#define OSAPI_BAUD_128K		  ((u32)0x00010000)
#define OSAPI_BAUD_115200 	  ((u32)0x00020000)
#define OSAPI_BAUD_57600	  ((u32)0x00040000)
#define OSAPI_BAUD_USER		  ((u32)0x10000000)
#endif

/* Equator��ֻ�����ò����ʣ������Ķ��������� */
#ifdef _EQUATOR_
/*  ע�⣺�������Ϊ9600 */
#define OSAPI_BAUD_110		  (u16)110
#define OSAPI_BAUD_300		  (u16)300
#define OSAPI_BAUD_600		  (u16)600
#define OSAPI_BAUD_1200		  (u16)1200
#define OSAPI_BAUD_2400		  (u16)2400
#define OSAPI_BAUD_4800		  (u16)4800
#define OSAPI_BAUD_9600		  (u16)9600
#endif

/* DTR Control Flow Values. */

#define OSAPI_DTR_CONTROL_DISABLE		0x00
#define OSAPI_DTR_CONTROL_ENABLE		0x01
#define OSAPI_DTR_CONTROL_HANDSHAKE 	0x02


/* RTS Control Flow Values */

#define OSAPI_RTS_CONTROL_DISABLE		0x00
#define OSAPI_RTS_CONTROL_ENABLE		0x01
#define OSAPI_RTS_CONTROL_HANDSHAKE	    0x02
#define OSAPI_RTS_CONTROL_TOGGLE		0x03

#define OSAPI_NOPARITY				0
#define OSAPI_ODDPARITY				1
#define OSAPI_EVENPARITY			2
#define OSAPI_MARKPARITY			3
#define OSAPI_SPACEPARITY 			4

#define OSAPI_ONESTOPBIT			0
#define OSAPI_ONE5STOPBITS			1
#define OSAPI_TWOSTOPBITS 			2


/* Escape Functions */


#define OSAPI_SETXOFF 				1		// Simulate XOFF received
#define OSAPI_SETXON				2		// Simulate XON received
#define OSAPI_SETRTS				3		// Set RTS high
#define OSAPI_CLRRTS				4		// Set RTS low
#define OSAPI_SETDTR				5		// Set DTR high
#define OSAPI_CLRDTR				6		// Set DTR low
#define OSAPI_RESETDEV				7		// Reset device if possible
#define OSAPI_SETBREAK				8		// Set the device break line.
#define OSAPI_CLRBREAK				9		// Clear the device break line.


/* PURGE function flags. */

#define OSAPI_PURGE_TXABORT			0x0001	/*  Kill the pending/current writes to the comm port. */
#define OSAPI_PURGE_RXABORT			0x0002	/* Kill the pending/current reads to the comm port. */
#define OSAPI_PURGE_TXCLEAR			0x0004	/* Kill the transmit queue if there. */
#define OSAPI_PURGE_RXCLEAR			0x0008	/* Kill the typeahead buffer if there. */

typedef struct 
{  
	u32 ReadIntervalTimeout; 
	u32 ReadTotalTimeoutMultiplier; 
	u32 ReadTotalTimeoutConstant; 
	u32 WriteTotalTimeoutMultiplier; 
	u32 WriteTotalTimeoutConstant; 
} TOsApiCommTimeouts; 

typedef struct
{ 
	u32 DCBlength;			 /*  sizeof(DCB) */
	u32 BaudRate;			 /*  current baud rate */
	u32 fBinary: 1; 		 /*  binary mode, no EOF check */
	u32 fParity: 1; 		 /*  enable parity checking */
	u32 fOutxCtsFlow:1; 	 /*  CTS output flow control */
	u32 fOutxDsrFlow:1; 	 /*  DSR output flow control */
	u32 fDtrControl:2;		 /*  DTR flow control type */
	u32 fDsrSensitivity:1;	 /*  DSR sensitivity */
	u32 fTXContinueOnXoff:1; /* XOFF continues Tx */
	u32 fOutX: 1;			 /*  XON/XOFF out flow control */
	u32 fInX: 1;			 /*  XON/XOFF in flow control */
	u32 fErrorChar: 1;		 /*  enable error replacement */
	u32 fNull: 1;			 /*  enable null stripping */
	u32 fRtsControl:2;		 /*  RTS flow control */
	u32 fAbortOnError:1;	 /*  abort on error */
	u32 fDummy2:17; 		 /*  reserved */
	u32 wReserved;			 /*  not currently used */
	u16 XonLim; 			 /*  transmit XON threshold */
	u16 XoffLim;			 /*  transmit XOFF threshold */
	u8	ByteSize;			 /*  number of bits/Byte, 4-8 */
	u8	Parity; 			 /*  0-4=no,odd,even,mark,space */
	u8	StopBits;			 /*  0,1,2 = 1, 1.5, 2 */
	char XonChar;			 /*  Tx and Rx XON character */
	char XoffChar;			 /*  Tx and Rx XOFF character */
	char ErrorChar; 		 /*  error replacement character */
	char EofChar;			 /*  end of input character */
	char EvtChar;			 /*  received event character */
	u16  wReserved1;		 /* reserved; do not use */
}TOsApiDCB; 

typedef struct
{ 
	u32 fCtsHold : 1; 
	u32 fDsrHold : 1; 
	u32 fRlsdHold : 1; 
	u32 fXoffHold : 1; 
	u32 fXoffSent : 1; 
	u32 fEof : 1; 
	u32 fTxim : 1; 
	u32 fReserved : 25; 
	u32 cbInQue; 
	u32 cbOutQue; 
} TOsApiComStat; 

#endif /*#ifndef _MSC_VER */

/*=============================================================================
�� �� ����OsApi_help
��	  �ܣ�inline help function of OSP module
ע	  �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��	  ����const char * pszTopic : [in] which topic's help infomation to be shown
�� �� ֵ��void
-------------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾  �޸���  �޸�����
2002/05/23	1.0
=============================================================================*/
API void OsApi_help(void);

/*====================================================================
��������OsApi_SemBCreate
���ܣ�����һ����Ԫ�ź���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(out)ptSemHandle ���ص��ź������

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
====================================================================*/
API BOOL32 OsApi_SemBCreate(OSAPISEMHANDLE *ptSemHandle);

/*====================================================================
��������OsApi_SemCCreate
���ܣ����������ź���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(out)ptSemHandle �ź���������ز����� 
(in)initcount ��ʼ������
(in)MaxSemCount ������

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32 OsApi_SemCCreate(OSAPISEMHANDLE *ptSemHandle,u32 initcount,u32 MaxSemCount);

/*====================================================================
��������OsApi_SemDelete
���ܣ�ɾ���ź���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(in)tSemHandle ��ɾ���ź����ľ��

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
====================================================================*/
API  BOOL32 OsApi_SemDelete(OSAPISEMHANDLE tSemHandle );

/*====================================================================
��������OsApi_SemTake
���ܣ��ź���p����������ź��������ã�����������ʵ����������(APP)
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(in)tSemHandle �ź������

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32	OsApi_SemTake(OSAPISEMHANDLE tSemHandle );

/*====================================================================
��������OsApi_SemTakeByTime
���ܣ�����ʱ���ź���p���������ź��������ã���ʱ������dwtime����󣬳�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(in)tSemHandle �ź������, (in)dwtime ��ʱ���(��msΪ��λ)

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32	OsApi_SemTakeByTime(OSAPISEMHANDLE tSemHandle, u32 dwtime);

/*====================================================================
��������OsApi_SemGive
���ܣ��ź���v����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����(in)tSemHandle �ź������

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE.
====================================================================*/
API  BOOL32 OsApi_SemGive(OSAPISEMHANDLE tSemHandle );

/*====================================================================
��������OsApi_TaskCreate
���ܣ�������ִ��һ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
     �ϲ��ڵ��øú���ʱ��ͳһ�Ƚ�Ҫ����ĺ���ָ��ת��Ϊu32����ת��Ϊ(void *)�����磺
     
     API void MyTask(void)
     {...}

     ......
  
     OsApi_TaskCreate((void *)(u32)MyTask, ...);

 ����ֵ˵����
====================================================================*/
API OSAPITASKHANDLE OsApi_TaskCreate(void* pvTaskEntry, char* szName, u8 byPriority, u32 dwStacksize, u32 dwParam, u16 wFlag, u32 *puTaskID);

/*====================================================================
��������OsApi_TaskExit
���ܣ��˳��������������˳�֮ǰ�û�Ҫע���ͷű�����������ڴ桢�ź�������Դ��
��װWindows��ExitThread(0)��vxWorks��taskDelete(0)��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskExit(void);

/*====================================================================
��������OsApi_TaskWaitEnd
���ܣ��ȴ�ָ�����������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����handle--�����������handle

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskWaitEnd(OSAPITASKHANDLE handle);

/*====================================================================
��������OsApi_TaskTerminate
���ܣ�ǿ����ָֹ������
��װWindows��ExitThread()��vxWorks��taskDelete()��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����handle--��ɱ�����handle

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskTerminate(OSAPITASKHANDLE handle);

/*====================================================================
��������OsApi_TaskSuspend
���ܣ�����ǰ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskSuspend(OSAPITASKHANDLE handle);

/*====================================================================
��������OsApi_TaskResume
���ܣ�ʹ����ǰ������������ִ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskResume(OSAPITASKHANDLE handle);

/*====================================================================
��������OsApi_TaskSetPriority
���ܣ��ı���������ȼ���

 �㷨ʵ�֣�����ѡ�
 ����ȫ�ֱ�����
 �������˵����
 
  ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskSetPriority(OSAPITASKHANDLE taskHandle, u8 newPriority);

/*====================================================================
��������OsApi_TaskGetPriority
���ܣ������������ȼ���

 �㷨ʵ�֣�����ѡ�
 ����ȫ�ֱ�����
 �������˵����
 
  ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskGetPriority(OSAPITASKHANDLE taskHandle, u8 * puPri);

/*====================================================================
��������OsApi_TaskSelfHandle
���ܣ���õ�������ľ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API OSAPITASKHANDLE OsApi_TaskSelfHandle(void);

/*====================================================================
��������OsApi_TaskSelfID
���ܣ���õ��������ID
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API u32 OsApi_TaskSelfID(void);

/*====================================================================
��������OsApi_TaskHandleVerify
���ܣ��ж�ָ�������Ƿ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_TaskHandleVerify(OSAPITASKHANDLE handle);

/*====================================================================
��������OsApi_TaskSafe
���ܣ������������񲻱��Ƿ�ɾ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API void OsApi_TaskSafe(void);

/*====================================================================
��������OsApi_TaskUnsafe
���ܣ��ͷŵ��������ɾ��������ʹ�õ���������Ա���ȫɾ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API void OsApi_TaskUnsafe(void);

/*====================================================================
��������OsApi_TaskDelay
���ܣ�������ʱ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����uMseconds--��ʱ���(ms)

 ����ֵ˵����
====================================================================*/
#define OsApi_Delay					  OsApi_TaskDelay

API void OsApi_TaskDelay(u32 dwMseconds);

/*====================================================================
��������OsApi_CreateMailbox
���ܣ�������Ϣ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_CreateMailbox(char* szName,u32 dwMsgNumber,u32 dwMsgLength ,u32 *puQueueIDRead,u32 *puQueueIDWrite);

/*====================================================================
��������OsApi_CloseMailbox
���ܣ��ر�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����uQueueIDRead, uQueueIDWrite--����Ķ���д���

 ����ֵ˵����
====================================================================*/
API void OsApi_CloseMailbox(u32 dwQueueIDRead, u32 dwQueueIDWrite);

/*====================================================================
������		��OsApi_SndMsg
����		�������䷢��Ϣ
�㷨ʵ��	��
����ȫ�ֱ�������
�������˵����tQueueID: ����ID,
lpMsgBuf: ����ָ��,
len: ����,
timeout: ��ʱֵ(ms). Windows�¸ò�����Ч, ��������һֱ����ֱ���пյ�buffer.
VxWorks��, ȱʡΪ2��; 
OSP_NO_WAIT(0): ��������������;
OSP_WAIT_FOREVER(-1): ����������ֱ���пյ�buffer.

 ����ֵ˵��  ���ɹ�����TRUE, ʧ�ܻ�ʱ����FALSE. timeout=2000
====================================================================*/					
API BOOL32 OsApi_SndMsg(u32 tQueueID, const char *lpMsgBuf, u32 len, int timeout);

/*====================================================================
������		��OsApi_RcvMsg
����		������������Ϣ
�㷨ʵ��	��
����ȫ�ֱ�������
�������˵����
OSTOKEN tQueueID	����ID
u32  dwTimeout	 ��ʱ(����)
LPVOID *lpMsgBuf	������Ϣ����ָ��
����ֵ˵��	��
====================================================================*/
API BOOL32 OsApi_RcvMsg(u32 tQueueID,u32  dwTimeout,char * lpMsgBuf, u32 len, u32 * pLenRcved);

/*====================================================================
��������OsApi_ClkRateGet
���ܣ��õ�tick���ȣ�n ticks/sec
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API u32 OsApi_ClkRateGet();

/*====================================================================
��������OsApi_TickGet
���ܣ�ȡ�õ�ǰ��tick��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API u32 OsApi_TickGet();

/*====================================================================
	�׽��ַ�װ���û�ʹ���׽���ǰ�����ȵ���OsApi_SockInit()���׽��ֿ���г�ʼ����
	ʹ����֮������Ҫ����OsApi_SockCleanup()�ͷŶ��׽��ֿ��ʹ�á�����vxWorks��
	Windows�Ĺر��׽��ֵĺ�����ͬ�������ڵ���socket��connect�Ⱥ���ʱ������
	ֵ����Ҳ��һ����OSPҲ�����˱�Ҫ�ķ�װ��ԭ���Ǳ�����Windows�»���һ�¡�
====================================================================*/

/*====================================================================
��������OsApi_SockInit
���ܣ��׽��ֳ�ʼ������װWindows�µ�WSAStartup��vxWorks�·���TRUE
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
====================================================================*/
API BOOL32 OsApi_SockInit(void);


/*====================================================================
��������OsApi_SockClose
���ܣ��ر��׽��֣���װwindows�µ�closesocket��vxworks�µ�close.
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����tSock--���ر��׽��ֵľ��������socketʱ���أ���

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
====================================================================*/
API BOOL32 OsApi_SockClose(OSAPISOCKHANDLE tSock);

/*====================================================================
��������OsApi_SockCleanup
���ܣ��׽������٣���װwindows��WSACleanup��vxWorks�·���TRUE
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵�����ɹ�����TRUE��ʧ�ܷ���FALSE
====================================================================*/
API BOOL32 OsApi_SockCleanup(void);

/*====================================================================
��������IsOsApi_Initd
���ܣ��ж�OSP�Ƿ��ѳ�ʼ������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����OSP�ѳ�ʼ��������TRUE�����򷵻�FALSE.
====================================================================*/
API BOOL32 IsOsApi_Initd(void);

/*=============================================================================
�� �� ����OsApi_Init
��	  �ܣ�initialize OSP module
ע	  �⣺
�㷨ʵ�֣�OsApi_Init�ڲ��Զ���ʼ���˶�ʱ���߳�
ȫ�ֱ�����
��	  ����TelNetEnable,telnet�Ƿ���Ч��TelNetPort��telnet�˿ڣ����Ϊ��Ϊ0��ʾ��OSAPI�Զ�ѡ����ö˿ڣ�2500��ʼ��
�� �� ֵ���ɹ�����TRUE�����򷵻�FALSE
=============================================================================*/
API BOOL32 OsApi_Init(BOOL32 TelNetEnable, u16 TelNetPort);

/*====================================================================
��������OsApi_Quit
���ܣ��˳�OSP�����ñ�������APP������ʵ����InstanceExit�������˳�ʵ����
�Ͽ�����OSP��㣬��������OSP�������APP��Ȼ�󷵻ء�OSP�˳�֮��
����OSP���񽫲���ʹ�á�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API void OsApi_Quit(void);

/*=============================================================================
�� �� ����OsApi_AddrListGet
��	  �ܣ���ȡ������ַ������
ע	  �⣺�������Windows��ʹ�ñ������������ȵ���OsApi_Init������WSAStartup��
������Ч�ʽϵͣ���Ҫ�ظ����á�
�㷨ʵ�֣�
ȫ�ֱ�����
��	  ���� u32	 adwIP[] : [in/out]�û���������ڵ�ַ�����ݵ�������׵�ַ
u16   dNum : [in]�û����������Ĵ�С
�� �� ֵ�� ���ر�����ַ���е�ַ����������ʱ����0
=============================================================================*/
API u16  OsApi_AddrListGet(u32 adwIPList[], u16 dwNum);


/*=============================================================================
�� �� ����OsApi_VerPrintf, OsApi_ver
��	  �ܣ�output compile version info to screen
ע	  �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��	  ����
�� �� ֵ��void
-------------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾  �޸���  �޸�����
2002/05/23	1.0
=============================================================================*/
#define  OsApi_VerPrintf() \
OsApi_Printf(TRUE, TRUE, "OsApi version: %s  compile time: %s %s\n", OSAPIVERSION, __DATE__, __TIME__)
API  void OsApi_ver();

/*====================================================================
  ��������OsApi_RegCommand
  ���ܣ�ע�������Telnet��ִ�еĺ���
  �㷨ʵ�֣�
  ����ȫ�ֱ�����
  �������˵����
  	szName	- Telnet�����������
	pfFunc	- ��Ӧ�ĺ���ָ��
	szUsage	- ����İ�����Ϣ
  ����ֵ˵������
  ====================================================================*/
API void OsApi_RegCommand(const char* szName, void* pfFunc, const char* szUsage);

/* ���ڷ�װ����Windows���ڲ�������Ϊ׼����VxWorks���ṩ��Ӧ���� */
/*====================================================================
��������OsApi_SerialOpen
���ܣ���ָ���Ĵ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����byPort: ���򿪵Ĵ��ں�
Լ����console��ΪttyS0��com1��ΪttyS1��com2��ΪttyS2��...����������
����ֵ˵�����ɹ����ش򿪴��ڵľ����ʧ�ܷ���INVALID_SERIALHANDLE
====================================================================*/
API OSAPISERIALHANDLE OsApi_SerialOpen(u8 byport);

/*====================================================================
��������OsApi_SerialClose
���ܣ��ر�ָ���Ĵ���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_SerialClose(OSAPISERIALHANDLE hCom);

/*====================================================================
��������OsApi_SerialRead
���ܣ���ָ���Ĵ��ڶ�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����hCom: ���ھ��,
              pchBuf: ��Ŷ������ݵ�buffer,
              dwBytesToRead: Ҫ������u8��,
              pdwBytesRead: ����ʵ�ʶ�����u8��.

  ����ֵ˵�����ɹ�����TRUE, ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32 OsApi_SerialRead(OSAPISERIALHANDLE hCom, char *pchBuf, u32 dwBytesToRead, u32 *pdwBytesRead);

/*====================================================================
��������OsApi_SerialWrite
���ܣ���ָ���Ĵ���д����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����hCom: ���ھ��,
              pchBuf: ��д���ݵ�buffer,
              uBytesToWrite: Ҫд��u8��,
              puBytesWrite: ����ʵ��д���u8��.

  ����ֵ˵�����ɹ�����TRUE, ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32 OsApi_SerialWrite(OSAPISERIALHANDLE hCom, char *pchBuf, u32 dwBytesToWrite, u32 *pdwBytesWrite);

/*====================================================================
��������OsApi_SetCommTimeouts
���ܣ����ô��ڳ�ʱ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_SetCommTimeouts(OSAPISERIALHANDLE hCom, TOsApiCommTimeouts *ptCommTimeouts);

/*====================================================================
��������OsApi_GetCommState
���ܣ���ô���״̬
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_GetCommState(OSAPISERIALHANDLE hCom, TOsApiDCB *ptDCB);

/*====================================================================
��������OsApi_SetCommState
���ܣ����ô���״̬��linux��Ŀǰ�����ò����ʲ�����Ч����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_SetCommState(OSAPISERIALHANDLE hCom, TOsApiDCB *ptDCB);

/*====================================================================
��������OsApi_EscapeCommFunction
���ܣ�ʹ�ô�����չ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_EscapeCommFunction(OSAPISERIALHANDLE hCom, u32 dwFunc);

/*====================================================================
��������OsApi_PurgeComm
���ܣ���������δ�����ݣ���ֹ���ڶ�д����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_PurgeComm(OSAPISERIALHANDLE hCom, u32 dwFlags);

/*====================================================================
��������OsApi_ClearCommError
���ܣ���Windows��ClearCommError��ͬ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_ClearCommError(OSAPISERIALHANDLE hCom, u32 *pdwErrors, TOsApiComStat *ptStat);

/*====================================================================
��������OsApi_GetCommTimeouts
���ܣ�ȡ�ô򿪴��ڵĳ�ʱ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����

 ����ֵ˵����
====================================================================*/
API BOOL32 OsApi_GetCommTimeouts(OSAPISERIALHANDLE hCom, TOsApiCommTimeouts *ptCommTimeouts);

/********************************************************************
    Telnet module
********************************************************************/

/*====================================================================
��������OsApi_TcpOpen
���ܣ���ָ����ַ�Ͷ˿ڽ�������sock
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������

����ֵ˵�������ؼ�����socket
====================================================================*/
API OSAPISOCKHANDLE OsApi_TcpOpen(u32 dwIpAddr, u16 wPort);

/*====================================================================
��������OsApi_TcpListen
���ܣ���ָ��sock�Ͻ��м���
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������

����ֵ˵����0��ʾ�ɹ�,OSAPI_TELNET_LISTEN_FAIL��ʾʧ��
====================================================================*/
API s32 OsApi_TcpListen(OSAPISOCKHANDLE hSock, s32 nQueue);

/*====================================================================
��������OsApi_sockBytesAvailable
���ܣ�����ָ��sock��ÿ��recvʱ�ܹ���ȡ�����뻺��Ĵ�С
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵�������ڵ���0Ϊʵ���ܶ�ȡ�Ĵ�С��С��0Ϊ��Ӧ��ʧ�ܴ�����
====================================================================*/
API s32 OsApi_sockBytesAvailable(OSAPISOCKHANDLE hSocket);

/*====================================================================
��������OsApi_Printf
���ܣ�����Ӧ��������ʾ����Ļ,�洢���ļ�,��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����
bScreen: �Ƿ��������Ļ,
bFile: �Ƿ�������ļ�,
szFormat: ��ʽ,
����ֵ˵����
====================================================================*/
API void OsApi_Printf(BOOL32 bScreen, BOOL32 bFile, char *szFormat, ...);

/*====================================================================
��������OsApi_SetPrompt
���ܣ�����Telnet��ʾ��, Windows������; Ospȡģ����Ϊȱʡ��ʾ��.
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����g_Osp
�������˵����prompt: �µ���ʾ��

  ����ֵ˵�����ɹ�����TRUE, ʧ�ܷ���FALSE.
====================================================================*/
API BOOL32 OsApi_SetPrompt(const s8 *prompt);



/********************************************************************
    Timer Module
********************************************************************/
typedef void* HTIMERHANDLE;

typedef s32 (*OsApi_TimerHandler)(HTIMERHANDLE dwTimerId, void* param);

/*====================================================================
��������OsApi_TimerInit
���ܣ���ʱ����ʼ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����g_tTimerMgr
�������˵����hHandle: ��ʱ�����

����ֵ˵����0��ʾ��ʼ���ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerInit(s32 nTotalNum);

/*====================================================================
��������OsApi_TimerEnd
���ܣ���ֹ��ʱ���̡߳�
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵����0 ��ʾ��ֹ�ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerEnd();

/*====================================================================
��������OsApi_TimerNew
���ܣ������µ�OSP��ʱ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����g_tTimerMgr
�������˵����

����ֵ˵����0 ��ʾ����ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerNew(HTIMERHANDLE* pHandle);

/*====================================================================
��������OsApi_TimerDelete
���ܣ�ɾ��OSP��ʱ����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵����0 ��ʾɾ���ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerDelete(HTIMERHANDLE hHandle);

/*====================================================================
��������OsApi_TimerSet
���ܣ�����OSP��ʱ��������
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵����0 ��ʾ���óɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerSet(HTIMERHANDLE hHandle, u32 dwInterval, OsApi_TimerHandler pCallBack, void* context);


/*====================================================================
��������OsApi_TimerInfo
���ܣ����OSP��ʱ����Ϣ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵����0 ��ʾ��ȡ�ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerInfo(HTIMERHANDLE hHandle, u32* pdwInterval, OsApi_TimerHandler* pCallBack,
                     void** pcontext, u32* pState);

/*====================================================================
��������OsApi_TimerStop
���ܣ��ı�ָ�������OSP��ʱ��״̬Ϊֹͣ��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵����

����ֵ˵����0 ��ʾ�ı�״̬�ɹ�,����ֵ��ʾ������
====================================================================*/
API u16 OsApi_TimerStop(HTIMERHANDLE hHandle);

/*====================================================================
��������OsApi_TimerRunCount
���ܣ���ʱ����Ч���м�����
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�������
�������˵������
����ֵ˵�������ض�ʱ���߳���Ч����״̬ʱ�ڲ�����ֵ
====================================================================*/
API u32 OsApi_TimerRunCount();

/********************************************************************
    OSAPI module
********************************************************************/

/* CPU��Ϣ */
typedef struct
{
	/* ���аٷֱȣ�0��100 */
	u8 m_byIdlePercent;
}TOsApiCpuInfo;
/* �ڴ���Ϣ */
typedef struct
{
	/* �����ڴ��С(KByte) */
	u32 m_dwPhysicsSize;
	/* ��ʹ���ڴ�(KBytes) */
	u32 m_dwAllocSize;
	/* �����ڴ�(KBytes) */
	u32 m_dwFreeSize;
}TOsApiMemInfo;

/* ʱ����Ϣ */
typedef struct
{
	/* ��(2006) */
	u16 m_wYear;
	/* ��(1--12) */
	u16 m_wMonth;
	/* (1--31) */
	u16 m_wDay;
	/* ʱ(0--23) */
	u16 m_wHour;
	/* ��(0--59) */
	u16 m_wMinute;
	/* ��(0--59) */
	u16 m_wSecond;
}TOsApiTimeInfo;

typedef struct tagTThreadInfoRD
{
	char m_strThreadName[100];				/* �߳����� */
	u32  m_dwThreadId;						/* �߳�ID */
}TThreadInfoRecord;

/* getpid() --��õ�ǰ�߳�ID����*/
#ifdef WIN32
	#define  getpid() GetCurrentThreadId()
#else
#endif


/*====================================================================
��������OsApi_GetMemInfo
���ܣ�ȡ�õ�ǰ��Mem��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptMemInfo���û�MEM��Ϣ�ṹ
����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_GetMemInfo( TOsApiMemInfo* ptMemInfo );

/*====================================================================
��������OsApi_GetCpuInfo
���ܣ�ȡ�õ�ǰ��CPU��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptCpuInfo���û�CPU��Ϣ�ṹ
����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_GetCpuInfo( TOsApiCpuInfo* ptCpuInfo );

/*====================================================================
��������OsApi_GetTimeInfo
���ܣ�ȡ�õ�ǰ��Time��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptTimeInfo��ϵͳtime��Ϣ�ṹ
����ֵ˵����ΪTRUEʱ��ʾ��ȡ��Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_GetTimeInfo( TOsApiTimeInfo* ptTimeInfo );

/*====================================================================
��������OsApi_SetTimeInfo
���ܣ����õ�ǰ��Time��Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptTimeInfo��ϵͳtime��Ϣ�ṹ
����ֵ˵����ΪTRUEʱ��ʾ������Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_SetTimeInfo( TOsApiTimeInfo* ptTimeInfo );

/*====================================================================
��������OsApi_AddThreadInfo
���ܣ������߳���Ϣ��OSAPI��
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����ptThreadInfo���߳���Ϣ�ṹָ��
����ֵ˵����ΪTRUEʱ��ʾ������Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_AddThreadInfo( TThreadInfoRecord* ptThreadInfo );

/*====================================================================
��������OsApi_DelThreadInfo
���ܣ���OSAPI��ɾ��ָ���߳�ID����Ϣ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵����dwThreadId���߳�ID
����ֵ˵����ΪTRUEʱ��ʾɾ����Ϣ�ɹ��������ʾʧ��
====================================================================*/
API BOOL32 OsApi_DelThreadInfo( u32  dwThreadId );

/*====================================================================
��������OsApi_PrintThreadInfo
���ܣ�  ����ǰ�����õ�OSP�е��߳���Ϣ��ӡ��ʾ
�㷨ʵ�֣�����ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵������
====================================================================*/
API void OsApi_PrintThreadInfo();


#endif
