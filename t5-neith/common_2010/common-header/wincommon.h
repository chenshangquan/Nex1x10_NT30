/*************************************************************************
ģ����      ��wincommon
�ļ���      ��wincommon.h
����ļ�    ��
�ļ�ʵ�ֹ��ܣ�һЩwindowsͨ�ú궨��
			���ڰ���window���ͷ�ļ�ǰ����
����        ���޿���
�汾        ��V4.0 Copyright(C) 2003-2005 KDC, All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼��
����			 �汾    �޸���    �޸�����
2013.04.10   4.7     �޿���     ����
**************************************************************************/

#pragma once

// ��ֹ��ʾ��ȫ��ʾ
#ifndef _CRT_SECURE_NO_DEPRECATE
	#define _CRT_SECURE_NO_DEPRECATE
#endif

// �Զ�������ȫ���ַ��������滻Ϊ_s�汾
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
	#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif

// ʹ��MS�ɰ汾��SWPRINTF������6.0
#ifndef _CRT_NON_CONFORMING_SWPRINTFS
	#define _CRT_NON_CONFORMING_SWPRINTFS 1
#endif

// ����֧�ֵ���͵�windows�汾
// VC 6.0 ��������_WIN32_WINNT 0x501���ᵼ��CFileDialog����ʱ����
// ��������VC 7.1���޸������֮ǰ�汾��_WIN32_WINNT ��Ӧ����0x501
// �����http://social.msdn.microsoft.com/forums/en-US/vcgeneral/thread/55664186-aae7-4ae9-a3e9-e38659335df6/
#ifndef _WIN32_WINNT
	#if( _MSC_VER <= 1300 )
		#define	_WIN32_WINNT 0x400
	#else
		#define _WIN32_WINNT 0x501
	#endif
#endif

// MS VC++ 10.0 _MSC_VER = 1600
// MS VC++ 9.0 _MSC_VER = 1500
// MS VC++ 8.0 _MSC_VER = 1400
// MS VC++ 7.1 _MSC_VER = 1310
// MS VC++ 7.0 _MSC_VER = 1300
// MS VC++ 6.0 _MSC_VER = 1200
// MS VC++ 5.0 _MSC_VER = 1100

// Minimum system required		_WIN32_WINNT
// Windows Server 2008			>=0x0600
// Windows Vista				>=0x0600
// Windows Server 2003			>=0x0502
// Windows XP                   >=0x0501
// Windows 2000                 >=0x0500
// Windows NT 4.0               >=0x0400
// Windows Me                   >=0x0500
// Windows 98                   >=0x0410
// Windows 95                   >=0x0400

//	ɾ������ָ��
#ifndef DEL_PTR
	#define DEL_PTR(p)              if (p != NULL) { delete p; p = NULL; }
#endif

//	ɾ������ָ��
#ifndef DEL_PTR_ARRAY
	#define DEL_PTR_ARRAY(p)        if (p != NULL) { delete [] p; p = NULL; }
#endif
