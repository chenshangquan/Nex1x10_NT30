#pragma once


class ISipToolCommonOp : public ICommonOp
{
public:
	ISipToolCommonOp(void);
	~ISipToolCommonOp(void);

    /** ע���߼��� 
	 *  @param[in] 
	 *  @return �Ƿ�ɹ�
	 */
	static void RegLogics();

	/**  ���ͽ�����Ϣ
	 *  @param[in] ��ϢId����Ϣ����ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool NotifyMsg(u16 wMsgId, void *pData = NULL);

	static bool NotifyMsg(u16 wMsgId, WPARAM wParam, LPARAM lParam);

	/**  �ַ�����ʽ��
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	static MbString StringFormat(const char *format, ...);
};

