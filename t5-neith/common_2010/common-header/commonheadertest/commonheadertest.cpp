// commonheadertest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "shareptrcontainertest.h"

void SharePtrContainerTest(){
	ObjectContainerForSharePtr shareptrContainer;
	ObjectWeakPtr ptr = shareptrContainer.add( 1 );
	shareptrContainer.add( 2 );

	ObjectContainerForWeakPtr weakptrContainer;
	weakptrContainer.add( 1, ptr );

	CFuncTest test(ptr);
	test.Print();

	cout << endl;
	shareptrContainer.traversal( &CDelegate<CFuncTest>( &test, &CFuncTest::PrintObjectByPtr) );
	cout << endl;
	// �ı�һ��ֵ
	test.ChangeData( 100 );
	cout << "============================weakptr container data ============================" << endl;
	weakptrContainer.traversal( &CDelegate<CFuncTest>( &test, &CFuncTest::PrintObjectByWeakPtr) );	
	cout << "============================sharptr container data ============================" << endl;
	shareptrContainer.traversal( &CDelegate<CFuncTest>( &test, &CFuncTest::PrintObjectByPtr) );
	cout << endl;

	// ���뿪�������ʱ��shareptrContainer���ͷ���Դ
	// �������õ�ֵ��ʧЧ��
}
int _tmain(int argc, _TCHAR* argv[])
{
	SharePtrContainerTest();
	system("pause");
	return 0;
}