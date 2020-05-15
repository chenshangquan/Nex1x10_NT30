// MemoryManage.cpp: implementation of the CMemoryManage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "MemoryManage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
	
#define DELARRAYPTR(p) if( NULL != p ) { delete []p;  p= NULL; }





CMemoryManage::CMemoryManage()//: CTAapater<CMemoryManage>()
{
	ResetVal();
}

CMemoryManage::~CMemoryManage()
{	
	ClearAllMemory();
	ResetVal();
}

void CMemoryManage::ResetVal()
{
	m_pCurrentBlock = NULL;
	m_pMemStart = NULL;
	m_pMemBlockStart = NULL;
	m_nMemoryTotalSize = 0;
	m_nBlockSize = 0;
	m_dwDropApplyTimes = 0;
	m_bReInting = FALSE;
	m_nMaxUsingBlocks = 0;
	m_nFreeBlock = 0;
}

void CMemoryManage::ClearAllMemory()
{
	DELARRAYPTR( m_pMemStart )
	DELARRAYPTR( m_pMemBlockStart )
}
/*=============================================================================
�� �� ��:  InitMemoryManage
��    ��:  ��ʼ���ڴ�
��    ��:  [in]blocksize ���С   [in]blocknum   �����Ŀ
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸����� 
2010/12/17  4.0     ��  ��    ����
    =============================================================================*/
EmMemoryError CMemoryManage::InitMemoryManage(int blocksize /*= DEFAULTBLOCKSIZE*/, int blocknum /*= DEFAULTBLOCKNUM*/)
{
	m_nMemoryTotalSize =  blocksize * blocknum ;
	if( m_nMemoryTotalSize <= 0 )
	{
		m_nMemoryTotalSize = 0;
		return emMemErrNewError;
	}
	m_nBlockSize = blocksize;

	m_pMemStart = new char [ blocksize * blocknum ] ;
	if( m_pMemStart == NULL )
	{
		return emMemErrNewError;
	}
	memset( m_pMemStart, 0, blocksize * blocknum );

	m_pMemBlockStart = new TMemBlock[ blocknum ];
	if( m_pMemBlockStart == NULL )
	{
		return emMemErrNewError;
	}
	memset(m_pMemBlockStart, 0, sizeof(TMemBlock) * blocknum );


	//��� TMemBlock����ʵ�ڴ�Ĺ�ϵ
	for( int  i = 0; i < blocknum - 1; i++ )
	{
		( (PTMemBlock)(m_pMemBlockStart + i) )->pBlock = m_pMemStart + blocksize * i;
		( (PTMemBlock)(m_pMemBlockStart + i) )->pNext =  (PTMemBlock)(m_pMemBlockStart + (1 + i)) ; 
	}

	( (PTMemBlock)(m_pMemBlockStart + blocknum - 1) )->pBlock = m_pMemStart + blocksize * (blocknum - 1);
	( (PTMemBlock)(m_pMemBlockStart + blocknum - 1) )->pNext = m_pMemBlockStart;//���һ��ָ���һ��

	m_pCurrentBlock = m_pMemBlockStart;

	m_nFreeBlock = blocknum;
	

	
	return emMemNoERROR;
}


EmMemoryError CMemoryManage::ReInit( int blocksize /*= DEFAULTBLOCKSIZE*/, int blocknum /*= DEFAULTBLOCKNUM*/ )
{
	m_bReInting = TRUE;
	int nBlockNum = m_nMemoryTotalSize / m_nBlockSize;
	int nBlockSize = m_nBlockSize;
	ClearAllMemory();
	ResetVal();
	EmMemoryError emRes =  InitMemoryManage(  nBlockSize,  nBlockNum );
	m_bReInting = FALSE;
	return emRes;
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
EmMemoryError CMemoryManage::InputData(char *pdata, int len, char **pout)
{
	if(m_bReInting)
	{
		return emMemErrReIniting;
	}
	int nBlockNum = 0;
	EmMemoryError emRes = CheckMemorySize( len , nBlockNum);
	if(  emRes != emMemNoERROR )
	{
		m_dwDropApplyTimes++;
		return emRes;
	}
	
	char *pPos = pdata;
	
	if( 1 == nBlockNum )
	{
		*pout = SetData(m_pCurrentBlock, 1, pdata, len );
		m_pCurrentBlock = m_pCurrentBlock->pNext;		
	}
	else//����1
	{
		for( int i = 0; i < nBlockNum - 1 ; i++ )
		{
			if( i == 0 )
			{
				*pout = SetData(m_pCurrentBlock, nBlockNum, pPos, m_nBlockSize );//������ĵ�һ������nOccupyBlockSize��ŵ���������ĸ���

			}
			else
			{
				SetData(m_pCurrentBlock, -1, pPos, m_nBlockSize );//������ķǵ�һ������nOccupyBlockSize��ŵ���-1
			}
			
			m_pCurrentBlock = m_pCurrentBlock->pNext;
			pPos += m_nBlockSize;
		}
		SetData(m_pCurrentBlock, -1, pPos, len - m_nBlockSize *(nBlockNum - 1)  ); 
		m_pCurrentBlock = m_pCurrentBlock->pNext;
	}
	

	//����ʹ����߷�ֵ
	int nOccupyBlocks = (m_nMemoryTotalSize / m_nBlockSize)  - m_nFreeBlock;
	if( nOccupyBlocks  >  m_nMaxUsingBlocks )
	{
		m_nMaxUsingBlocks = nOccupyBlocks;
	}
	return emMemNoERROR;
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
EmMemoryError CMemoryManage::GetData(char *pdata, char *pout, int &len)
{
	if(m_bReInting)
	{
		return emMemErrReIniting;
	}

	if( NULL == pdata || NULL == pout )
	{
		pdata = NULL;
		pout = NULL;
		len = 0 ;
		return emMemErrNotFound;
	}


	char *pGetOut = pout;

	PTMemBlock pBlock = FindPos(pdata);
	if( NULL != pBlock )
	{
		int nBlocks		= 0;
		int nDataSize	= 0;
		GetData(pBlock, pGetOut, nBlocks, nDataSize);
		pGetOut += nDataSize;
		

		

		if( 1 == nBlocks )
		{
			len = pGetOut - pout;
			return emMemNoERROR;
		}
		else if( nBlocks > 1 )
		{
			int nCopyBlocks  = 0;
			for( int i = 1; i < nBlocks; i++ )//�Ѿ�ȡ��һ���������� i=1
			{
				pBlock = pBlock->pNext;
				GetData(pBlock, pGetOut, nCopyBlocks, nDataSize);
				pGetOut += nDataSize;
			}

			len = pGetOut - pout;
			return emMemNoERROR;
		}
		else
		{
			pout = NULL;
			len = 0 ;
			return emMemErrNotFound;
		}		
	}

	pout = NULL;
	len = 0 ;
	return emMemErrNotFound;
}

/*=============================================================================
�� �� ��:  CheckMemorySize
��    ��:  ����ڴ��Ƿ�
��    ��:  [in]len Ҫ�������ݵĴ�С    [out]numblock ��Ҫ������ڴ�����
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2010/12/17  4.0     ��  ��    ����
    =============================================================================*/
EmMemoryError CMemoryManage::CheckMemorySize(int len, int &blockcount)
{
	if( len > m_nMemoryTotalSize )
	{
		return emMemErrNotEnoughError;
	}
	
	int nBlock = len / m_nBlockSize;
	if( nBlock * m_nBlockSize < len ) 
	{
		nBlock++;
	}
	
	if( m_nFreeBlock < nBlock  )
	{
		return emMemErrNotEnoughError;
	}

	blockcount = nBlock ;

	return emMemNoERROR;
}


/*=============================================================================
�� �� ��:  FindPos
��    ��:  ���ڴ�
��    ��:  [in]point Ҫ�ҵ��ڴ�ָ��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2010/12/17  4.0     ��  ��    ����
    =============================================================================*/
PTMemBlock CMemoryManage::FindPos(char *point)
{
	int nBlockCount = m_nMemoryTotalSize / m_nBlockSize;
	for( int i = 0; i < nBlockCount; i++ )
	{
		if( ( (PTMemBlock)(m_pMemBlockStart + i) )->pBlock == point )
		{
			return ( (PTMemBlock)(m_pMemBlockStart + i) );
		}
	}
	return NULL;
}
