/*=======================================================================
ģ����      : ���ܹ���ģ���
�ļ���      : nmscommon.cpp
����ļ�    : 
�ļ�ʵ�ֹ���: 
����        : ���ǿ
�汾        : V4.0  Copyright(C) 2003-2005 Suzhou Keda Technology Co.Ltd
                    All rights reserved.
-------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾  �޸���  �޸�����
2004/07/16  3.0   ���ǿ  ����
2004/12/18  3.5   ���ǿ  ����TplArrayģ����
2005/01/26  3.5   ���ǿ  �޸�TplArray���������bug
=======================================================================*/

#include "stdafx.h"
#include "nmscommon.h"
#include "vccommon.h"
#include "AES.h"

#define NMSCOMMON_VER   (LPCSTR)"nmscommonver version: 40.30.01.01.20061020"

//////////////////////////////////////////////////////////////////////////
//
//     ��ȫע��ocx�ؼ��ĸ�������
//
// Helper function to create a component category and associated description
HRESULT CreateComponentCategory(CATID catid, WCHAR *catDescription)
{
    ICatRegister *pcr = NULL;
    HRESULT hr = S_OK;

    hr = CoCreateInstance( CLSID_StdComponentCategoriesMgr, 
                           NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister,
                           (void**)&pcr );
    if ( FAILED( hr ) )
    {
        return hr;
    }

    // Make sure the HKCR\Component Categories\{..catid...}
    // key is registered
    CATEGORYINFO catinfo;
    catinfo.catid = catid;
    catinfo.lcid = 0x0409; // english

    // Make sure the provided description is not too long.
    // Only copy the first 127 characters if it is
    size_t nLen = wcslen(catDescription);
    if ( nLen > 127 )
    {
        nLen = 127;
    }

    wcsncpy( catinfo.szDescription, catDescription, nLen );
    // Make sure the description is null terminated
    catinfo.szDescription[nLen] = '\0';

    hr = pcr->RegisterCategories( 1, &catinfo );
    pcr->Release();

    return hr;
}

// Helper function to register a CLSID as belonging to a component category
HRESULT RegisterCLSIDInCategory(REFCLSID clsid, CATID catid)
{
    // Register your component categories information.
    ICatRegister* pcr = NULL;
    HRESULT hr = S_OK;

    hr = CoCreateInstance( CLSID_StdComponentCategoriesMgr, 
                           NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister,
                           (void**)&pcr );
    if ( SUCCEEDED( hr ) )
    {
        // Register this category as being "implemented" by
        // the class.
        CATID rgcatid[1];
        rgcatid[0] = catid;
        hr = pcr->RegisterClassImplCategories( clsid, 1, rgcatid );
    }

    if ( pcr != NULL )
    {
        pcr->Release();
    }

    return hr;
}

// Helper function to unregister a CLSID as belonging to a component category
HRESULT UnRegisterCLSIDInCategory(REFCLSID clsid, CATID catid)
{
    ICatRegister* pcr = NULL;
    HRESULT hr = S_OK;

    hr = CoCreateInstance( CLSID_StdComponentCategoriesMgr, 
                           NULL, CLSCTX_INPROC_SERVER, IID_ICatRegister,
                           (void**)&pcr );
    if ( SUCCEEDED( hr ) )
    {
        // Unregister this category as being "implemented" by
        // the class.
        CATID rgcatid[1];
        rgcatid[0] = catid;
        hr = pcr->UnRegisterClassImplCategories( clsid, 1, rgcatid );
    }

    if (pcr != NULL)
    {
        pcr->Release();
    }

    return hr;
}

/*=============================================================================
�� �� ��:nmscommonver
��    ��:��ӡNmsCommon��İ汾��
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5     ���ǿ  ����
=============================================================================*/
API void nmscommonver(void)
{
    OspPrintf( TRUE, FALSE, "%s compile time: %s %s\n", NMSCOMMON_VER,
               __DATE__, __TIME__ );
}

/*=============================================================================
�� �� ��:GetConfBitrate
��    ��:��ȡ��������
��    ��:u32 **ppdwBitrate              [out]   ������������
         s32 &nNum                      [out]   �����С
         u32 dwMCUType                  [in]    MCU����
ע    ��:����Ҫ��ppdwBitrate����ռ�, �Ҳ���delete ppdwBitrate
         8000C MCUֻ֧�ֵ�4M
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/29  3.5     ���    ����
2007/04/25  4.0     ������  �޸�
=============================================================================*/
void GetConfBitrate(u32 **ppdwBitrate, s32 &nNum, u32 dwMCUType)
{
	static u32 adwBitrate8M[] = {384,
							512,
							768,
							1024,
							1216,
							1536,
							1792,
							2048,
							3072,
							4096,
							5120,
							6144,
							7168,
							8128};

	static u32 adwBitrate4M[] = {384,
							512,
							768,
							1024,
							1216,
							1536,
							1792,
							2048,
							3072,
							4096};

    if( MCU_TYPE_KDV8000C == dwMCUType)
    {
        *ppdwBitrate = adwBitrate4M;
        nNum = sizeof (adwBitrate4M) / sizeof (u32);
    }
	else
    {
        *ppdwBitrate = adwBitrate8M;
        nNum = sizeof (adwBitrate8M) / sizeof (u32);
    }
}

CString ExpandEnvPathString( LPCTSTR lpszPath )
{
	static TCHAR abyPath[32768]; 
	ExpandEnvironmentStrings( lpszPath, abyPath, _countof(abyPath) );
	return abyPath;
}


/*=============================================================================
�� �� ��:GetModuleFullPath
��    ��:��ȡģ�������ļ���ȫ·��, ��������\
��    ��:��
ע    ��:���� C:\
�� �� ֵ:�ļ����ַ���
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/10/26  3.5     ���    ����
=============================================================================*/
CString GetModuleFullPath(void)
{
	TCHAR achDllName[32768] = _T("");
	CString csPath = _T("");

	//AfxGetInstanceHandle()���ܻ�ȡʧ��
// 	GetModuleFileName( AfxGetInstanceHandle(), achDllName, MAX_PATH);

	MEMORY_BASIC_INFORMATION mbi;   
	static int dummy; 
	u32 dwLength = sizeof(mbi); 
	if ( dwLength == VirtualQuery( &dummy, &mbi, dwLength ) )
	{
		GetModuleFileName( reinterpret_cast<HMODULE>(mbi.AllocationBase), achDllName, _countof(achDllName) ); 
		size_t nBuffLen = GetLongPathName( achDllName, 0, 0 );
		if ( nBuffLen == _tcslen( achDllName ) )
		{
			csPath = achDllName;
		}
		else
		{
			TCHAR* pChar = new TCHAR[nBuffLen + 1];
			ZeroMemory( pChar, sizeof(TCHAR) * ( nBuffLen + 1 ) );
			GetLongPathName( achDllName, pChar, nBuffLen );
			csPath = pChar;
			delete[] pChar;
		}		
	}
    
	csPath = csPath.Left( csPath.ReverseFind(_T('\\')) + 1 );

	return csPath;
}

/*=============================================================================
�� �� ��:ModuleRegToOsp

��    ��:��OSPע�᱾ģ��
��    ��:��
ע    ��:��
�� �� ֵ:�ɹ���TRUE; ʧ�ܣ�FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/10/26  3.5     ���    ����
=============================================================================*/
BOOL32 ModuleRegToOsp(void)
{
	TCHAR achDllName[MAX_PATH] = _T("");
	GetModuleFileName( AfxGetInstanceHandle(), achDllName, _countof(achDllName) );
	return OspRegistModule( CT2A( achDllName ) );
}

/*=============================================================================
�� �� ��:GetUrl
��    ��:��ȡIE��ַ������
��    ��:const COleControl *pcCtrl          [in]    ocx�ؼ�
         CString &cstrUrl                   [out]   ��ַ������
ע    ��:��
�� �� ֵ:�ɹ�:TRUE; ʧ��:FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/11/08  4.0     ���    ����
=============================================================================*/
BOOL32 GetUrl(const LPOLECLIENTSITE pClientSite, CString &cstrUrl)
{
    if ( pClientSite == NULL )
    {
        return FALSE;
    }

	IWebBrowser2        *pBrowser = NULL;
    HRESULT             hr = S_OK;
    IServiceProvider    *pIsp1 = NULL;
    IServiceProvider    *pIsp2 = NULL;

    hr = pClientSite->QueryInterface( IID_IServiceProvider,
                                       reinterpret_cast<void**>(&pIsp1) );
    if ( FAILED(hr) )
    {
        return FALSE;
    }

    hr = pIsp1->QueryService( SID_STopLevelBrowser, IID_IServiceProvider,
                              reinterpret_cast<void**>(&pIsp2) );
    if ( FAILED(hr) )
    {
        pClientSite->Release();
        return FALSE;
    }

    hr = pIsp2->QueryService( SID_SWebBrowserApp, IID_IWebBrowser2,
                              reinterpret_cast<void**>(&pBrowser) );
    if ( FAILED(hr) )
    {
        pClientSite->Release();
        pIsp1->Release();
        return FALSE;
    }

    BSTR bstrUrl = NULL;
    pBrowser->get_LocationURL( &bstrUrl );
    cstrUrl = bstrUrl;
    ::SysFreeString( bstrUrl );

    pClientSite->Release();
//     pIsp1->Release();
//     pIsp2->Release();

    return TRUE;
}

/*=============================================================================
�� �� ��:EncryptPwd
��    ��:�������
��    ��:LPCSTR lpszPwd                     [in]    ԭʼ����, �32λ(����'/0')
         s8 aszEncryptedPwd[64]             [out]   ��������
�㷨˵��:�ַ��滻
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/11/21  4.0     ���    ����
2013/06/18	4.7		�޿���	�޸�ΪAES����
=============================================================================*/
#define STR_AESKEY "b^dBV%Zzgixr4uaL"

bool EncryptPwd( const s8* lpszPwd, s8 aszEncryptedPwd[64] )
{
	if ( !lpszPwd || strlen( lpszPwd ) > 31 )
	{
		return false;
	}
	// ����λ���Ϊ0
	s8 abyPsw[32];
	strncpy( abyPsw, lpszPwd, 32 );
	AES cAes;
	cAes.setMode( (u8*)STR_AESKEY, len16, len32, false );
	s8 aszTemp[32] = {0};
	u8 len = cAes.cipher( (u8*)abyPsw, (u8*)aszTemp );

	// һ��4�ֽڣ�һ��8��
	for ( int i = 0; i < 8; ++i )
	{
		sprintf( aszEncryptedPwd + (i*8),"%08X", *((u32*)( aszTemp + i*4 ) ) );
	}

	return true;
}

/*=============================================================================
�� �� ��:DecryptPwd
��    ��:�������
��    ��:s8 aszEncryptedPwd[64]             [in]    ��������
         LPSTR lpszPwd                      [out]   ԭʼ����, �32λ(����'/0')
�㷨˵��:�ַ��滻
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/11/21  4.0     ���    ����
2013/06/18	4.7		�޿���	�޸�ΪAES����
=============================================================================*/
bool DecryptPwd( const s8 aszEncryptedPwd[64], s8* lpszPwd)
{
	u8 abyPsw[32];
	// һ��4�ֽڣ�һ��8��
	for ( int i = 0; i < 8; ++i )
	{
		sscanf( aszEncryptedPwd + (i*8),"%8X", (u32*)( abyPsw + i*4 ) );
	}

	AES cAes;
	cAes.setMode( (u8*)STR_AESKEY, len16, len32, true );
	s8 aszTemp[32] = {0};
	cAes.invCipher( abyPsw, (u8*)aszTemp );
	strcpy( lpszPwd, aszTemp );
	return true;
}

/*========================================================================
�� �� ����CheckIEBHOAvailable
��    �ܣ����IE���Ƿ�����˺����ǵ�OCX�ؼ������ݵĲ��
ע    �⣺�����ڿؼ���InitInstance()�н��е��ã��緵��FALSE��ؼ��˳�
          ���磺
            BOOL CTestApp::InitInstance()
            {
	            BOOL bInit = COleControlModule::InitInstance();

	            if (bInit)
	            {
                    BOOL bBHOAvailable = CheckIEBHOAvailable( 0 );
                    if ( FALSE == bBHOAvailable )
                    {
                        return FALSE;
                    }
	            }

	            return bInit;
            }

��    ����LPCTSTR   [in]    ��ʾ��Ϣ
�� �� ֵ��TRUE��    û�в����ݵĲ�����û�ѡ��ж����Ӧ�Ĳ��
          FALSE��   ��⵽�в����ݵĲ�������û�ѡ��ж����Ӧ�Ĳ��
�����Ϣ��
--------------------------------------------------------------------------
�޸ļ�¼��
��      ��  �汾    �޸���  �޸�����
2007/11/07  1.0     ������    ����
2013/05/02	4.7		�޿���	�޸Ĳ�������֧���µĶ����Ի���
							ʹ��ѭ����֧�ֶ�������ݿؼ��ļ��
							����Unicode�£�ֻ�ܶ�ȡ���ļ�·���ĵ�һ���ַ�������
========================================================================*/
BOOL32 CheckIEBHOAvailable( LPCTSTR lpszInfo )
{
	// �����绹�з��ֲ����ݵĲ����ӵ��˴�
	
	// ���IE�������Ƿ��Ѿ�������FlashGet���
    const TCHAR paszBHO[][50] =
    {
	    
		// �ƺ�FlashGet�Ĳ���ᵼ�³���ر�ʱ��IE����0x0000005���� by zjl;
        _T("FlashGet BHO jccatch.dll")
    };


	const TCHAR paszSubKey[][256] = 
	{
		// jccatch.dll��GUID��FB5DA724-162B-11D3-8B9B-AA70B4B0B524
		_T("CLSID\\{FB5DA724-162B-11D3-8B9B-AA70B4B0B524}\\InprocServer32")
	};

    // ��ע����ж�ȡ������ļ���
    CString strInfo = lpszInfo;
    CString strBHOName;
	CString strModule;

	// ��һ�����飬�����������������ݲ���ĸ���
	HMODULE* arrayModule = new HMODULE[_countof(paszBHO)];
	memset( arrayModule, 0, sizeof( arrayModule ) );

	s32 nFindNum = 0;
	for ( s32 i = 0; i < _countof( paszSubKey ); ++i )
	{
		HKEY hKey = NULL;
	    LONG lRet = RegOpenKeyEx( HKEY_CLASSES_ROOT, paszSubKey[i],
                              0, KEY_READ, &hKey );

		if ( lRet == ERROR_SUCCESS )
		{
			TCHAR abyPath[MAX_PATH];
			DWORD dwSize = MAX_PATH;
			DWORD dwType = REG_SZ;
			lRet = RegQueryValueEx( hKey, NULL, NULL, &dwType, (LPBYTE)abyPath, &dwSize );
			if ( ERROR_SUCCESS == lRet )
			{
				strBHOName = abyPath;
				s32 nPos = strBHOName.ReverseFind( '\\' );
				strBHOName = strBHOName.Right( strBHOName.GetLength() - nPos - 1 );// .Left(nPos + 1);
			}
		}
		
		// ���IE�Ƿ��Ѿ�������
		HMODULE hModule = GetModuleHandle( strBHOName );

		if ( NULL != hModule )
		{
			arrayModule[ nFindNum ] = hModule;

			// ����һ����ʾ
			strModule.Format( _T("%d.%s\n"), ++nFindNum, paszBHO[i] );
			strInfo += strModule;
		}
	}

    if ( nFindNum > 0 )
    {
        int dwResult = AfxMessageBox( strInfo, MB_YESNO );
        if ( dwResult == IDNO )
        {
            return TRUE;
        }

		for ( s32 i = 0; i < nFindNum; ++i )
		{
			FARPROC pUninstall = GetProcAddress( arrayModule[i], "DllUnregisterServer" );

			if ( NULL != pUninstall )
			{
				// ж�ز��
				pUninstall();
			}
		}
        return FALSE;
    }
    return TRUE;
}

BOOL32 GetOsVersion( u32& dwMajorVer, u32& dwMinorVer )
{
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	
	if ( GetVersionEx(&osvi) )
	{
		dwMajorVer = osvi.dwMajorVersion;
		dwMinorVer = osvi.dwMinorVersion;
		return TRUE;
	}
	else
	{
		dwMajorVer = 0;
		dwMinorVer = 0;
		return FALSE;
	}
}
