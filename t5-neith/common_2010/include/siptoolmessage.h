/******************************************************************************
ģ����  : scoketmanager
�ļ���  : siptoolmessage.h
����    : ��Ϣ��ʽͷ�ļ�
�汾    ��1.0.0
******************************************************************************/
#ifndef __SIPTOOLMESSAGE_H__
#define __SIPTOOLMESSAGE_H__

#include "multiplereg_common.h"

#define   RK_MAXLEN_MESSAGE          65535 //1024*64,  ��Ϣ��󳤶�64K

class CRkMessage
{
public:
    //��Ϣ��
    u8  m_abyMsg[RK_MAXLEN_MESSAGE];
    u16 m_wabyMsgLen;

    //�����Ϣ��ָ��
    u8*	GetBody(){ return m_abyMsg;}
    //�����Ϣ�峤��
    u16	GetBodyLen() { return m_wabyMsgLen; }

    //������Ϣ������
    BOOL SetBody(const void* buf ,u16 len )
    { 
        if( len > (u16)(RK_MAXLEN_MESSAGE) )
            return FALSE;
        if( NULL == buf || 0 == len )
        {
            m_wabyMsgLen = 0;
            return TRUE;
        }
        memcpy(m_abyMsg ,buf ,len);
        m_wabyMsgLen = len;
        return TRUE;
    }
    //������Ϣ������
    BOOL CatBody(const void* buf ,u16 len )
    {
        if( len + m_wabyMsgLen > (u16)(RK_MAXLEN_MESSAGE) )
            return FALSE;

        memcpy( m_abyMsg + m_wabyMsgLen ,buf ,len);
        m_wabyMsgLen += len;
        return TRUE;
    }

};
#endif