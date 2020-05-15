// MemManger.cpp: implementation of the CMemManger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "memmanger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

template<> CMemoryManager* CSingleton<CMemoryManager>::m_psSingleton  = NULL;

CMemoryManager::CMemoryManager(int iItemSize,int iItemCount)
{
	m_WaitEvent =  ::CreateEvent(NULL,TRUE,FALSE,NULL);
	InitializeCriticalSection(&m_lock);
	
	if (!Init(iItemSize,iItemCount))
		AfxMessageBox(_T("�Զ����ڴ�������ʧ�ܣ�"));
};

CMemoryManager::~CMemoryManager()
{
	//::GlobalUnlock(hData);
	::GlobalFree(pData);
	DeleteCriticalSection(&m_lock); 
	CloseHandle(m_WaitEvent);
};

//��ʼ���ڴ�����Ԥ���ڴ�����
//iItemSize - ÿ���ֽ��� iItemCount - �ܿ���
BOOL CMemoryManager::Init(int iItemSize,int iItemCount)
{
	int iIndexAddr;
	
	m_ItemSize  = iItemSize;
	m_ItemCount = iItemCount;
	m_BlockSize = iItemSize + 9;
	
	
	pData = ::GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT,
		4 + iItemCount * (iItemSize + 9) +
        iItemCount * 4);
	if (!pData) return FALSE;
	
	//��ʼ�����п���Ϣ
	*((int *)pData) = iItemCount;
	m_FreeIndexAddr = (int)pData + 4 + iItemCount * (iItemSize + 9);
	for(int i=1;i<=m_ItemCount;i++)
	{
		*((int *)(m_FreeIndexAddr + (i-1)*4)) = i; //��������
		iIndexAddr = (int)pData + 4 + (i - 1) * m_BlockSize + m_ItemSize + 1;
		*((int *)iIndexAddr) = i;//��������
	}
	
	return TRUE;
}

void CMemoryManager::Lock()
{
	EnterCriticalSection(&m_lock); 
}

void CMemoryManager::UnLock()
{
	LeaveCriticalSection(&m_lock); 
}

//�����ڴ�����
LPVOID CMemoryManager::New(int Len)
{
	BOOL blnGet = FALSE;
	int iIndex;
	int iNext = 0;
	int iNeedCount;
	int iFreeCount;
	int iRefAddr;
	
	LPVOID p = NULL;
	
	//������Ҫ����Ŀ���
	iNeedCount = (int)(Len / m_ItemSize);
	if (iNeedCount * m_ItemSize < Len) iNeedCount++;
	
	while(!blnGet)
	{
		//����Ƿ�����㹻���п�
		Lock();
        iFreeCount = *((int *)pData);
		if (iFreeCount * m_ItemSize < Len) 
		{
			//�ռ䲻�㣬����ȴ�
			UnLock();
			WaitForSingleObject(m_WaitEvent,200);
		}
		else
		{
			for(int i=iFreeCount;i>=1;i--)
			{
				//��ȡ���п�����
				iIndex = *((int *)(m_FreeIndexAddr + (i-1)*4));
				iRefAddr = (int)pData + 4 + (iIndex - 1) * m_BlockSize + m_ItemSize;
				
				//д��ռ�ñ�־
				*((unsigned char *)iRefAddr) = 1;
				
				//���ٿ�������
				*((int *)pData) = *((int *)pData) - 1;
				
				//д��һ������
				*((int *)(iRefAddr+5)) = iNext;
				
				//��ȡ���׵�ַ
				p = (LPVOID)(iRefAddr - m_ItemSize);
				
				iNeedCount--;
				if (iNeedCount == 0) break;
				
				//���浱ǰ������
				iNext = iIndex;
			}
			
			UnLock();
			blnGet = TRUE;
		}
	}
	
	return p;
}

//�ͷ��ڴ�����
BOOL CMemoryManager::Delete(LPVOID p)
{
	unsigned char *pRef;
	int  *pNext;
	int  iNext = 1;
	
	if (p == NULL) return TRUE;
	
	while(iNext >= 1)
	{
		//������ݿ�����
		//ZeroMemory(p,m_ItemSize);
		
		Lock();
		
		//�������
		pRef = (unsigned char *)((int)p + m_ItemSize);
		//���ӿ����� д��������
		if (*pRef != 0)
		{
			int *pFree = (int *)pData;
			*pFree = *pFree + 1;
			*((int *)(m_FreeIndexAddr + (*pFree - 1) * 4)) = *((int *)((int)p + m_ItemSize + 1));
		}
		*pRef = 0;
		//��ȡ�������һ������
		pNext = (int *)((int)p + m_ItemSize + 5);
		iNext = *pNext;
		*pNext = 0;
		
		UnLock();
		
		//������һ���ַ
		if(iNext >= 1)
			p = (LPVOID)((int)pData + 4 + (iNext - 1) * (m_ItemSize + 5));
	}
	
	p = NULL;
	return TRUE;
}

//��ȡ���ݿ��ֽ���
int CMemoryManager::GetItemSize()
{
	return m_ItemSize;
}

//��ȡ�ܿ���
int CMemoryManager::GetItemCount()
{
	return m_ItemCount;
}

//��ȡ�ܿ�����
int CMemoryManager::GetFreeCount()
{
	int iCnt;
	Lock();
	CopyMemory(&iCnt,pData,4);
	UnLock();
	return iCnt;
}