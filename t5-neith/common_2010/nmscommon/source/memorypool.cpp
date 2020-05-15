// MemoryPool.cpp: implementation of the CMemoryPool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemoryPool.h"
#include "osp.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CTAapater<CMemoryManage> *CNormalPolicy::Find(int len)
{
	int num = 0;
	for( int i = 0; i < MemoryManageNum; i++ )
	{
		if( emMemNoERROR == m_pcManager[i]->CheckMemory(len, num) )
		{
			return &m_pcManager[i];
		}
	}
	return NULL;
}

void CPolicyFactory::SetpManage( CTAapater<CMemoryManage> *p )
{
	m_pcManager = p;
}


CTAapater<CMemoryManage> *CPolicyFactory::FindSuitable( int len, EmFitPolicy emplc /*= emNormalP*/ )
{
	CTAapater<CMemoryManage> * pTmp = NULL;
	switch( emplc )
	{
	case emNormalP:
		{
			CNormalPolicy cNormalPlc(m_pcManager);
			pTmp = cNormalPlc.Find(len);
		}
		break;
	case emPerfectP:
		break;
	case emBadP:
		break;
	default:
		break;
	}
	
	return pTmp;
}






template<> CMemoryPool* CSingleton<CMemoryPool>::m_psSingleton  = NULL;


void CMemoryPool::Init()
{
	for(int i = 0 ; i < MemoryManageNum; i++ )
	{
		memset( &m_atBlockBorder[i], 0 , sizeof( TBlockBorder ) );
	}

	m_nDropApplyTimes = 0;
	m_nGetFailureTime = 0;
}


CMemoryPool::CMemoryPool():CSingleton<CMemoryPool>()
{
	Init();
}

CMemoryPool::~CMemoryPool()
{

}
/*=============================================================================
�� �� ��:  InitMemoryPool
��    ��:  ��ʼ���ڴ�
��    ��:  ά��ΪMemoryManageNum ��2�е����� ָ��
ע    ��:  ��ѵ�λ�ڴ�С�ķ��������ǰ��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸����� 
2010/12/17  4.0     ��  ��    ����
=============================================================================*/
EmMemoryError CMemoryPool::InitMemoryPool( int (*p)[2] )
{
	int nUnitMemoryLen = 0;
	int nUnitMemoryNum = 0;
	//��ʼʱ��ȷ����С�ķ�����ǰ��	

	int i = 0 ;
	for( i = 0; i < MemoryManageNum ; i++ )
	{
		nUnitMemoryLen = *(*(p+i) + 0);
		nUnitMemoryNum = *(*(p+i) + 1);
		if( emMemNoERROR != m_acMemManage[i]->InitMemoryManage(nUnitMemoryLen, nUnitMemoryNum) )
		{
			return emMemErrNewError;
		}
	}
		

	for( i = 0; i < MemoryManageNum ; i++ )
	{
		m_acMemManage[i]->GetBlockBorder(m_atBlockBorder[i]);
	}

	m_cMangePlc.SetpManage( m_acMemManage );

	return emMemNoERROR;
}



/*=============================================================================
�� �� ��:  InitMemoryPool
��    ��:  ��ʼ���ڴ�
��    ��:  
ע    ��:  
�� �� ֵ: 
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸����� 
2010/12/17  4.0     ��  ��    ����
=============================================================================*/
EmMemoryError CMemoryPool::InitMemoryPool()
{
	//��ʼʱ��ȷ����С�ķ�����ǰ��
	if( emMemNoERROR != m_acMemManage[0]->InitMemoryManage(10, 10) )
	{
		return emMemErrNewError;
	}
	
	if( emMemNoERROR != m_acMemManage[1]->InitMemoryManage(20, 5)	)
	{
		return emMemErrNewError;
	}
	
	if( emMemNoERROR != m_acMemManage[2]->InitMemoryManage(30, 3)	)
	{
		return emMemErrNewError;
	}
	
	if( emMemNoERROR != m_acMemManage[3]->InitMemoryManage(50, 2)	)
	{
		return emMemErrNewError;
	}
	
	if( emMemNoERROR != m_acMemManage[4]->InitMemoryManage(100, 1) )
	{
		return emMemErrNewError;
	}
	
	for( int i = 0; i < MemoryManageNum ; i++ )
	{
		m_acMemManage[i]->GetBlockBorder(m_atBlockBorder[i]);
	}
	
	m_cMangePlc.SetpManage( m_acMemManage );
	
	return emMemNoERROR;
}
/*=============================================================================
�� �� ��:  FindSuitable
��    ��:  ������Ӧģʽ���Һ����ڴ��
��    ��:  [in]len ���ݴ�С
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸����� 
2010/12/17  4.0     ��  ��    ����
=============================================================================*/
CTAapater<CMemoryManage>	*CMemoryPool::FindSuitable( int len)
{
	return m_cMangePlc.FindSuitable( len );
}
/*=============================================================================
�� �� ��:  InputData
��    ��:  �����ݵ��ڴ�
��    ��:  [in]pdata ����ָ��   [in]len Ҫ�������ݵĴ�С     [pout]  Ҫ�洢�������� ��������׵�ַ
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2010/12/17  4.0     ��  ��    ����
=============================================================================*/
EmMemoryError	CMemoryPool::InputData(char *pdata, int len, char **pout)
{
	CTAapater<CMemoryManage>	*p = FindSuitable( len );
	if( NULL != p )
	{
		EmMemoryError emRes = emMemNoERROR;		
		emRes = (*p)->InputData( pdata, len, pout );
		return emRes;
	}
	
	m_nDropApplyTimes++;
	return   emMemErrNotEnoughError;
}



/*=============================================================================
�� �� ��:  GettData
��    ��:  �������
��    ��:  [in]pdata Ҫ���ҵ�����ָ��    [out]pout ������ݵ�ָ�� [out]len�������
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2010/12/17  4.0     ��  ��    ����
=============================================================================*/
EmMemoryError	CMemoryPool::GetData(char *pdata, char *pout, int &len)
{
	EmMemoryError EmRes = emMemErrNotFound;
	for( int i = 0; i < MemoryManageNum; i++ )
	{
		if( m_atBlockBorder[i].startpos <= pdata &&  m_atBlockBorder[i].endpos >= pdata )
		{
			EmRes = m_acMemManage[i]->GetData(pdata, pout, len ) ;
			if( emMemErrNotFound == EmRes )
			{
				OspPrintf( 1, 0, "CMemoryPool::GetData  ʧ��\n ");
				continue;
			}
			else if( emMemNoERROR == EmRes )
			{
				return EmRes;
			}
		}
	}

	m_nGetFailureTime++;
	return EmRes;
}


void CMemoryPool::PrintManageInfo()
{
	int NowFreeBlock = 0;
	int MaxUsingBlocks = 0;
	for( int i = 0; i < MemoryManageNum; i++ )
	{
		m_acMemManage[i]->GetManageInfo(NowFreeBlock, MaxUsingBlocks);
		OspPrintf(TRUE, FALSE, "�ڴ����%d  \n freeblock = %d    maxpeek = %d\n",  i, NowFreeBlock, MaxUsingBlocks  );
	}

	OspPrintf(TRUE, FALSE, "\nPool Info \n �ڴ�����ʧ�ܴ��� %d  �ڴ��ȡʧ�ܴ��� %d\n", m_nDropApplyTimes, m_nGetFailureTime );
};
