/*=============================================================================
ģ   ��   ��: ���ܹ���ģ���
��   ��   ��: calladdr.cpp
�� ��  �� ��: calladdr.h
�ļ�ʵ�ֹ���: �����ն˵�ַ����ز�����
��        ��: ���ǿ
��        ��: V4.0  Copyright(C) 2003-2006 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2004/07/16  3.0     ���ǿ      ����
2005/12/08  4.0     ���        ����������ļ�
=============================================================================*/

#include "stdafx.h"
#include "calladdr.h"
#include <WINSOCK2.H>
#include "osp.h"
#include "vccommon.h"
#include "IPTypes.h"
#include "Ipexport.h"
#include <vector>
#include <ATLBASE.H>


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//u32 CCallAddr::s_dwError = CCallAddr::VALID_IPADDR;
s8 CCallAddr::s_cstrIpStr[MAX_IP_LEN] = { 0 };

static char g_szCallAddrErrDes[][2][256] =
    {
        "IP ��ַ��Ч��%d ����һ����Ч���ָ��һ������ 1 �� 223 ֮�����ֵ",
        "%d is not a valid entry. Please specify a value between 1 and 223.",

        "�� 127 ��ͷ�� IP ��ַ��Ч����ָ������ 1 �� 223 �������ĳ����Чֵ",
        "IP address starting with 127 are not valid because they are reserved for loopback address. Please specify some other valid value between 1 and 223.",

        "��Ч IP ��ַ����������ϲ�",
        "The combination of IP address and subnet mask is invalid. All of the bits in the host address portion of the IP address are set to 0. Please enter a valid combination of IP address and subnet mask."
    };

/*=============================================================================
�� �� ��:IsValidIpV4
��    ��:����IP��ַ�Ƿ���Ч
��    ��:LPCTSTR lptrIPStr              [in]    �ַ���ָ���͵ĵ�ַ
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5     ���ǿ  ��ע��
2005/08/31	4.0     �����  ������껵��㷨�޸�
=============================================================================*/
BOOL32 CCallAddr::IsValidIpV4( LPCSTR lptrIPStr )
{
    if ( lptrIPStr == NULL ) 
    {
        return FALSE;
    }

    s32 nDot    = 0;                        //  �Ѵ�����ַ�����ĵ����
    s32 nData   = 0;                        //  �Ѵ�����ַ��������ֵ
    s32 nPos	= 0;						//	����֮��ļ��
    s32 nLen    = strlen( lptrIPStr );     //  �ַ�������

    //  �ַ�������7λ�15λ, �Ҳ�����'0'��ͷ
    if ( nLen < 7 || nLen > 15 ) 
    {
        // 2004/05/19 ���ǿ *.*.*.*��***.***.***.***
//        s_dwError = ERROR_LEN;
        return FALSE;
    }

    if ( lptrIPStr[0] == '0'
         || ( lptrIPStr[0] == '2' && lptrIPStr[1] == '5'
              && lptrIPStr[2] == '5' ) )
    {
//        s_dwError = ERROR_ZERO_BEGIN;
        return FALSE;
    }

    if ( lptrIPStr[0] == '.' || lptrIPStr[nLen - 1] == '.' )
    {
//        s_dwError = ERROR_POINTSTART_OR_NOPONIT;
        return FALSE;
    }

    for ( s32 nCount = 0; nCount < nLen; ++nCount )
    {
        if ( lptrIPStr[nCount] >= '0' && lptrIPStr[nCount] <= '9' )//��������
        {
            nData = 10 * nData + lptrIPStr[nCount] - '0';     //������ֵ
		    ++nPos;
        }
        else if ( lptrIPStr[nCount] == '.' )     //  �������
        {
            nDot++;
            if ( nDot > 3 )  //  ���������3
            {
//                s_dwError = ERROR_EXTRA_POINT;
			    return FALSE;
            }
		    else if ( nPos > 3 )
		    {
//			    s_dwError = ERROR_POINT_POS;
			    return FALSE;
		    }
		    else if ( nData > 255 ) //��ֵ����255
		    {
//			    s_dwError = ERROR_VALUE;
			    return FALSE;
		    }
            else        //  �Ѵ�����ַ����Ϸ�
            {
                nData = 0;
			    nPos = 0;
            }
        }
        else            //  �����Ƿ��ַ�
        {
//            s_dwError = ERROR_NOT_NUM_OR_POINT;
		    return FALSE;
        }
    }

    if ( nDot != 3 )
    {
//	    s_dwError = ERROR_POINT_POS;
	    return FALSE;
    }
    
    // ����@2006.03.17 ������һ�������Ƿ�Ϸ�
    if ( nData > 255 ) //��ֵ����255
	{
//		s_dwError = ERROR_VALUE;
		return FALSE;
	}    

    return TRUE;
}

/*=============================================================================
�� �� ��:IsValidIpV4
��    ��:IP�ؼ��еĵ�ַ�Ƿ���Ч
��    ��:CIPAddressCtrl *pcIpCtrl       [in]    IP�ؼ���ָ��
ע    ��:���˵��鲥��ַ���鲥��ַΪ224.0.0.0-239.255.255.255��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5     ���ǿ  ��ע��
=============================================================================*/
BOOL32 CCallAddr::IsValidIpV4(CIPAddressCtrl *pcIpCtrl)
{
    ASSERT( pcIpCtrl != NULL );
    if ( pcIpCtrl == NULL ) 
    {
//        s_dwError = ERROR_INPUTNULL;
        return FALSE;
    }

    u8 byPos1 = 0;
    u8 byPos2 = 0;
    u8 byPos3 = 0;
    u8 byPos4 = 0;
    int nFileds = pcIpCtrl->GetAddress( byPos1, byPos2, byPos3, byPos4 );
    if ( nFileds < 4 )
    {
        return FALSE;
    }
    else if ( byPos1 == 0 || byPos1 == 255 )
    {
//        s_dwError = ERROR_ZERO_BEGIN;
        return FALSE;
    }
	else if ( byPos1 > 223 && byPos1 < 240)
	{
		return FALSE;
	}
    else
    {
//        s_dwError = VALID_IPADDR;
        return TRUE;
    }
}

/*=============================================================================
�� �� ��:IsValidIpV4
��    ��:����IP��ַ�Ƿ���Ч
��    ��:u32 dwIP                       [in]    u32�͵ĵ�ַ, ������
ע    ��:���˵��鲥��ַ���鲥��ַΪ224.0.0.0-239.255.255.255��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5     ���ǿ  ��ע��
=============================================================================*/
BOOL32 CCallAddr::IsValidIpV4(u32 dwIP)
{
    u8 byPos1 = HIBYTE( HIWORD( dwIP ) );
    if ( byPos1 == 0 || byPos1 == 255 )
    {
//        s_dwError = ERROR_ZERO_BEGIN;
        return FALSE;
    }
	else if ( byPos1 > 223 && byPos1 < 240)
	{
		return FALSE;
	}
    else
    {
//        s_dwError = VALID_IPADDR;
        return TRUE;
    }
}

/*=============================================================================
�� �� ��:IsValidIpMask
��    ��:����IP�Ƿ��ǺϷ�������
��    ��:LPCTSTR lptrIpMask             [in]    LPCTSTR��IP��ַ�ַ���
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/08/31  4.0     �����  ����
=============================================================================*/
BOOL32 CCallAddr::IsValidIpMask( LPCSTR lptrIpMask )
{
	BOOL32 bRet = IsValidIpV4( lptrIpMask );
	if ( !bRet )
	{
		return FALSE;
	}

	
	u32 dwAddr = ntohl( inet_addr( lptrIpMask ) ); 
	bRet = IsValidIpMask( dwAddr );
	return bRet;
}

/*=============================================================================
�� �� ��:IsValidIpMask
��    ��:����IP�Ƿ��ǺϷ�������
��    ��:CIPAddressCtrl *pcIpCtrl   [in]    IP�ؼ�ָ��
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/12/08  4.0     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidIpMask(CIPAddressCtrl *pcIpCtrl , BOOL32 bNeedFilter)
{
    ASSERT( pcIpCtrl != NULL );
    if ( pcIpCtrl == NULL ) 
    {
        return FALSE;
    }

    DWORD dwIpMask = 0;
    pcIpCtrl->GetAddress( dwIpMask );
    if (bNeedFilter && dwIpMask == ~0)
    {
        return TRUE;
    }
	BOOL32 bRet = IsValidIpMask( dwIpMask );
	return bRet;
}

/*=============================================================================
�� �� ��:IsValidIpMask
��    ��:����IP�Ƿ��ǺϷ�������
��    ��:u32 dwIpMask                   [in]    u32��IP��ַ, ������
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/08/31  4.0     �����  ����
=============================================================================*/
BOOL32 CCallAddr::IsValidIpMask(u32 dwIpMask)
{

	if ( dwIpMask == 0 )
	{
		return FALSE;
	}

	u32 dwTemp1 = ~dwIpMask;
	u32 dwTemp2 = dwIpMask - dwTemp1;
	return ( (dwTemp1 & dwTemp2) == 1 );
}

/*=============================================================================
�� �� ��:IsValidE164
��    ��:����E164���Ƿ���Ч
��    ��:LPCTSTR lptrE164Str            [in]    E164��
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/05/26  3.6     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidE164(LPCSTR lptrE164Str)
{
    s32 nLen = strlen( lptrE164Str );
    if ( nLen == 0 )
    {
        return FALSE;
    }

    s32 nIndex = strspn( lptrE164Str, "0123456789*,#" );

    return (nLen == nIndex) ? TRUE : FALSE;
}

/*=============================================================================
�� �� ��:IsValidH320ID
��    ��:����H320 ID�Ƿ���Ч
��    ��:LPCTSTR lptrH320ID             [in]    LPCTSTR��H320 ID
ע    ��:��
�� �� ֵ:�Ϸ�����TRUE,�Ƿ�����FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/07/04  3.6     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidH320ID( LPCSTR lptrH320ID )
{
    TMtAlias tMtAlias;
    u8 byLayer = 0;
    u8 bySlot = 0;
    u8 byChannel = 0;

    tMtAlias.m_AliasType = mtAliasTypeH320ID;
    strcpy( tMtAlias.m_achAlias, lptrH320ID );
    BOOL32 bRet = tMtAlias.GetH320Alias( byLayer, bySlot, byChannel );
    if ( !bRet )
    {
        return FALSE;
    }

    tMtAlias.SetH320Alias( byLayer, bySlot, byChannel );
    bRet = ( strcmp( tMtAlias.m_achAlias, lptrH320ID ) == 0 );

    return bRet;
}

/*=============================================================================
�� �� ��:GetIpStr
��    ��:�õ�IP��ַ���ִ�
��    ��:u32 dwIPAddr                   [in]    IP��ַ, ������
ע    ��:��
�� �� ֵ:IP��ַ���ִ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5     ���ǿ  ��ע��
2005/10/26  4.0     ���    ȡ��ʹ��inet_ntoa
=============================================================================*/
s8* CCallAddr::GetIpStr( u32 dwIPAddr )
{
    u16 wHigh   = HIWORD( dwIPAddr );
    u16 wLow    = LOWORD( dwIPAddr );
    sprintf( s_cstrIpStr, "%d.%d.%d.%d", 
			 HIBYTE( wHigh ), LOBYTE( wHigh ),
             HIBYTE( wLow ), LOBYTE( wLow ) );
    return s_cstrIpStr;
}

/*=============================================================================
�� �� ��:GetCallStrType
��    ��:�õ������ַ�������
��    ��:const CString &csCallAddr      [in]    ���е��ַ���
ע    ��:��
�� �� ֵ:��������           NORMAL_STR һ���ִ�
                            IP_STR      IP�ִ�
                            NUM164_STR  E164����
                            H323ID_STR  H323ID
                            H320ID_STR  H320ID
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2004/09/13  3.5   ���ǿ  ��ע��
2005/07/04  3.6   ���    ����H320 ID
=============================================================================*/
UINT CCallAddr::GetCallStrType( LPCSTR strCallAddr )
{
    if ( IsValidIpV4( strCallAddr ) )	
	{
		return IP_STR;
	}

    if ( IsValidE164( strCallAddr ) )
    {
        return NUM164_STR;
    }

	if ( strlen( strCallAddr ) == 0 )
	{
		return NORMAL_STR;
	}

    if ( IsValidH320ID( strCallAddr ) )
    {
        return H320ID_STR;
    }

	if ( strlen( strCallAddr ) >= MAXLEN_ALIAS )   //  wanghao 2004/10/26
	{
		return NORMAL_STR;
	}
	else
	{
		return H323ID_STR;
	}
}

typedef DWORD (WINAPI *GETADAPTERSINFO)(PIP_ADAPTER_INFO pAdapterInfo, PULONG pOutBufLen);
typedef DWORD (WINAPI *GETUNIDIRECTIONALADAPTERSINFO)(PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS pIPIfInfo, PULONG dwOutBufLen);

/*=============================================================================
�� �� ��:GetLocalIpAddr
��    ��:��ȡ���б���IP��ַ, ������127.0.0.1
��    ��:u32 *&pdwLocalIp               [out]   ����IP��ַ����, ������
         s32 &nIpNum                    [out]   �������
ע    ��:�����������pdwLocalIp�ռ�, ���ڵ������delete ����Ŀռ�
         ���þ���:
             u32 *pdwLocalIp = NULL;
             s32 nIpNum = 0;
             CCallAddr::GetLocalIpAddr( pdwLocalIp, nIpNum );
             DEL_PTR_ARRAY( pdwLocalIp );

         ���ص�IPΪ������
�� �� ֵ:�Ƿ��ȡ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/29  4.0   ���    ����
2007/05/09  4.0   ������  �޸�
=============================================================================*/
BOOL32 CCallAddr::GetLocalIpAddr(u32 *&pdwLocalIp, s32 &nIpNum)
{/*
    nIpNum = 0;

    s8 aszHostName[128] = {0};
    s32 nRet = gethostname( aszHostName, 128 );
    if ( nRet == 0 )
    {
        struct hostent *ptHost = gethostbyname( aszHostName );
        for ( nIpNum = 0; ptHost->h_addr_list[nIpNum] != NULL; nIpNum ++ );

        pdwLocalIp = new u32 [nIpNum];
        for ( s32 nIndex = 0; nIndex < nIpNum; nIndex ++ )
        {
            pdwLocalIp[nIndex]
                = ((struct in_addr *)ptHost->h_addr_list[nIndex])->s_addr;
            pdwLocalIp[nIndex] = ntohl( pdwLocalIp[nIndex] );
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
    */

    GETADAPTERSINFO GetAdaptersInfo = NULL;
    GETUNIDIRECTIONALADAPTERSINFO GetUniDirectionalAdapterInfo = NULL;

    HMODULE hModule = LoadLibrary( _T("Iphlpapi.dll") );
    if ( NULL == hModule )
    {
        return FALSE;
    }

    GetAdaptersInfo = (GETADAPTERSINFO)GetProcAddress( hModule, "GetAdaptersInfo" );
    GetUniDirectionalAdapterInfo = (GETUNIDIRECTIONALADAPTERSINFO)GetProcAddress( hModule, "GetUniDirectionalAdapterInfo" );
    if ( NULL == GetAdaptersInfo || NULL == GetUniDirectionalAdapterInfo )
    {
        FreeLibrary( hModule );
        return FALSE;
    }

    IP_ADAPTER_INFO *pAdptInfo = NULL;
    IP_ADAPTER_INFO *pNextAd = NULL;
    PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS ptIPIfInfo = NULL;
    ULONG ulLen = 0;
    DWORD dwRet = 0;

    dwRet = GetAdaptersInfo( pAdptInfo, &ulLen );
    if ( dwRet == ERROR_BUFFER_OVERFLOW )
    {
        pAdptInfo = reinterpret_cast<IP_ADAPTER_INFO*>(new u8[ulLen]);
        dwRet = GetAdaptersInfo( pAdptInfo, &ulLen );
    }
    u8 pbyBuf[4096] = {0};
    ulLen = 4096;
    memset( pbyBuf, 0, sizeof (pbyBuf) );
    ptIPIfInfo = reinterpret_cast<PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS>(pbyBuf);
    GetUniDirectionalAdapterInfo( ptIPIfInfo, &ulLen );


    //1. ��ȡ����������Ϣ
    vector<u32> vctIP;
    if ( dwRet == ERROR_SUCCESS )
    {
        // ȡ������Ϣ
        pNextAd = pAdptInfo;

        // ������������
        while ( pNextAd != NULL )
        {
            IP_ADDR_STRING *pIPStr = &(pNextAd->IpAddressList);
            if ( pNextAd->DhcpEnabled > 0 )
            {
                pIPStr = &(pNextAd->DhcpServer);
            }
            // ������������������IP
            while ( pIPStr != NULL )
            {
                const s8* lptrIpAddr = pIPStr->IpAddress.String;
                vctIP.push_back( inet_addr( lptrIpAddr ) );
                pIPStr = pIPStr->Next;
            }
            pNextAd = pNextAd->Next;
        }
    }

    FreeLibrary( hModule );
    hModule = NULL;

    //2. �ų�ֻ���ܲ����͵�IP
    for ( ulLen = 0; ulLen < ptIPIfInfo->NumAdapters; ulLen ++ )
    {
        vector<u32>::iterator itr = vctIP.begin();
        vector<u32>::iterator itrEnd = vctIP.end();
        for ( ; itr < itrEnd; itr ++ )
        {
            if ( (*itr) == ntohl( ptIPIfInfo->Address[ulLen] ) )
            {
                vctIP.erase( itr );
                break;
            }
        }
    }


    //3. �ų�127.0.0.1
    vector<u32>::iterator itr = vctIP.begin();
    vector<u32>::iterator itrEnd = vctIP.end();
    while ( itr < itrEnd )
    {
        if ( (*itr) == 0 || (*itr) == 0x0100007F )
        {
            itr = vctIP.erase( itr );
            itrEnd = vctIP.end();
        }
        else
        {
            itr ++;
        }
    }


    //4. ��ֵ
    nIpNum = vctIP.size();
    if ( nIpNum > 0 )
    {
        pdwLocalIp = new u32 [nIpNum];
    }
    else
    {
        pdwLocalIp = NULL;
    }

    s32 nIndex = 0;
    while ( nIndex < nIpNum )
    {
        pdwLocalIp[nIndex] = ntohl( vctIP[nIndex] );
        nIndex++;
    }

    delete [] (u8*)pAdptInfo;

    return TRUE;
}


/*=============================================================================
�� �� ��: IsValidCallIP
��    ��: �ж�IP��ַ�Ƿ�Ϊ�Ϸ�����IP
��    ��: u32 dwIP                          [in]    ������IP��ַ
          CString &cstrErrStr               [out]   ���������ַ���
          u8 byLanType                      [in]    ����������������(0: ��������; 1: Ӣ��)
ע    ��: ����IP��ַ����ΪIsValidIpV4�жϳ����ĺϷ���ַ��
          ��GetCallStrType֮��ʹ��
�� �� ֵ: BOOL
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2007/04/25  1.0     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidCallIP(u32 dwIP, s8* cstrErrStr, u8 byLanType)
{
    if ( byLanType > 1 )
    {
        byLanType = 1;
    }

    BOOL32 bRet = FALSE;
    u8 byFirstField = static_cast<u8>( dwIP >> 24 );
    do
    {
        if ( byFirstField == 127 )
        {
            cstrErrStr = g_szCallAddrErrDes[1][byLanType];
            break;
        }
    	else if ( byFirstField == 0 || byFirstField > 223 )
        {
            //cstrErrStr = g_szCallAddrErrDes[0][byLanType];
			//cstrErrStr.Format( g_szCallAddrErrDes[0][byLanType], byFirstField );
			sprintf( cstrErrStr, g_szCallAddrErrDes[0][byLanType], byFirstField );
            break;
        }

        bRet = TRUE;

    } while ( FALSE );


    return bRet;
}

/*=============================================================================
�� �� ��: IsValidMulticastIP
��    ��: �ж�IP��ַ�Ƿ�Ϊ�Ϸ��鲥IP
��    ��: u32 dwIP                          [in]    ������IP��ַ
ע    ��: ����IP��ַ����ΪIsValidIpV4�жϳ����ĺϷ���ַ
�� �� ֵ: BOOL
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2007/04/25  1.0     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidMulticastIP(u32 dwIP)
{
    u8 byFirstField = static_cast<u8>( dwIP >> 24 );
    if (    ( byFirstField >= 225 && byFirstField <= 231 )
         || ( byFirstField >= 233 && byFirstField <= 239 ) )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*=============================================================================
�� �� ��: IsValidDevIP
��    ��: �ж�IP��ַ�Ƿ�Ϊ�Ϸ��豸IP(�����豸����IP��ַ)
��    ��: u32 dwIP                          [in]    �������豸IP��ַ
          u32 dwMask                        [in]    ����������
          CString &cstrErrStr               [out]   ���������ַ���
          u8 byLanType                      [in]    ����������������(0: ��������; 1: Ӣ��)
ע    ��: �豸IP��ַ����ΪIsValidIpV4�жϳ����ĺϷ���ַ��
          �������ΪIsValidIpMask�жϳ����ĺϷ�����
�� �� ֵ: BOOL
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2007/04/25  1.0     ���    ����
=============================================================================*/
BOOL32 CCallAddr::IsValidDevIP(u32 dwIP, u32 dwMask, const s8* cstrErrStr,
                               u8 byLanType)
{
    if ( byLanType > 1 )
    {
        byLanType = 1;
    }

    BOOL32 bRet = FALSE;
    u8 byFirstField = static_cast<u8>( dwIP >> 24 );
    do
    {
        if ( byFirstField == 127 )
        {
            cstrErrStr = g_szCallAddrErrDes[1][byLanType];
            break;
        }
    	else if ( byFirstField == 0 || byFirstField > 223 )
        {
            cstrErrStr = g_szCallAddrErrDes[0][byLanType];
            break;
        }
        else
        {
            u32 dwTemp = dwIP & ( ~ dwMask );
            if ( dwTemp == dwMask || dwTemp == 0 )
            {
                cstrErrStr = g_szCallAddrErrDes[2][byLanType];
                break;
            }
        }

        bRet = TRUE;

    } while ( FALSE );


    return bRet;
}

/*
BOOL32 CCallAddr::SetPuInfo( s8* strName, const u32 dwIP, const s8* strAlis )
{
	memcpy( strName, &dwIP , sizeof(dwIP) );
	strcpy( strName + sizeof(dwIP), strAlis );	
	return TRUE;
}

BOOL32 CCallAddr::SetPuInfo( s8* strName, const s8* strIP, const s8* strAlis )
{
	u32 dwIp = inet_addr( strIP );
	return SetPuInfo( strName, dwIp, strAlis );
}

BOOL32 CCallAddr::GetPuInfo( const s8* strAlis, u32& dwIP, s8* strName )
{
	memcpy( &dwIP, strAlis, sizeof(u32) );
	strcpy( strName, strAlis + sizeof(u32) );
	return TRUE;
}

BOOL32 CCallAddr::GetPuInfo( const s8* strAlis, s8* strIP, s8* strName )
{
	in_addr inaddr;
	u32 dwIP = 0;
	if (  GetPuInfo( strAlis, dwIP, strName ) )
	{
		inaddr.s_addr = dwIP;
		strcpy( strIP, inet_ntoa( inaddr ) );
		return TRUE;
	}
	else
	{
		return FALSE;
	}	
}
*/
