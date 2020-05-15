// ��ͷ�ļ��а���һЩ����vista��64��32λ��������ĳ��ú���

#pragma once

// �޸Ĵ�����Ϣ�������������UIPI���½��̼䴰����Ϣ�޷����ݵ�����
// uMessageID Ҫ�޸ĵ���Ϣ��
// bAllow	  TRUE = �����ˣ�FALSE = ����
// ChageWindowMessageFilter ��Vista��֮���ϵͳ�д���
// ����ֵ	  TRUE = ���óɹ���FALSE = ����ʧ��
// �޸Ĵ�����Ϣ������
static BOOL ChangeWindowMessageFilterPort(UINT uMessageID, BOOL bAllow)
{
	BOOL bResult = FALSE;
#if(WINVER < 0x0600)
	typedef BOOL(WINAPI *ChangeWindowMessageFilterFun)(UINT, DWORD);
	HMODULE hUserMod = NULL;
	hUserMod = LoadLibrary(_T("user32.dll"));
	if (NULL != hUserMod)
	{
		ChangeWindowMessageFilterFun pChangeWindowMessageFilter = (ChangeWindowMessageFilterFun)GetProcAddress(hUserMod, "ChangeWindowMessageFilter");
		if (NULL != pChangeWindowMessageFilter)
		{
			bResult = pChangeWindowMessageFilter(uMessageID, bAllow ? 1 : 2);//MSGFLT_ADD: 1, MSGFLT_REMOVE: 2
		}
		::FreeLibrary(hUserMod);
	}
#else
	bResult = ChangeWindowMessageFilter(uMessageID, bAllow ? MSGFLT_ADD, MSGFLT_REMOVE);
#endif
	return bResult;
}

