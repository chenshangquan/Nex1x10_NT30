#ifdef _PFC_ENABLE_SOCK5_API_

#if defined(_MSC_VER) || defined(_LINUX_)

//sock5����汾��
#define SOCK5_PROXY_VERSION         (u8)0x05
//�ͻ���֧�ּ�Ȩ����
#define SOCK5_PROXY_AUTHEN_NO_REQUIERD          (u8)0x00
#define SOCK5_PROXY_AUTHEN_USERNAME_PASSWORD    (u8)0x02
//�������
#define SOCK5_PROXY_SUCCESS                     (u8)0x00
#define SOCK5_PROXY_AUTHEN_NO_ACCEPTABLE        (u8)0xff
//��������
#define SOCK5_PROXY_CMD_TCP_CONNECT             (u8)0x01
#define SOCK5_PROXY_CMD_TCP_BIND                (u8)0x02
#define SOCK5_PROXY_CMD_UDP_ASSOCIATE           (u8)0x03
//�����ֶ�
#define SOCK5_PROXY_RESERVED_DATA               (u8)0x00
//��ַ����
#define SOCK5_PROXY_IPV4_ADDR                   (u8)0x01
#define SOCK5_PROXY_DOMAIN_NAME                 (u8)0x03
#define SOCK5_PROXY_IPV6_ADDR                   (u8)0x04


#define MAX_SOCK5PROXY_AUTHEN_NUM   (u8)0xff
#define MAX_SOCK5PROXY_NAME_PASS_LENGTH (u8)64
typedef struct {
	u32 m_dwProxyIP;
	u16 m_wProxyPort;
	u8 m_byAuthenNum;
	u8 m_abyAuthenMethod[MAX_SOCK5PROXY_AUTHEN_NUM];
	s8 m_achUseName[MAX_SOCK5PROXY_NAME_PASS_LENGTH + 1];
	s8 m_achPassword[MAX_SOCK5PROXY_NAME_PASS_LENGTH + 1];
} TPfcSock5Proxy;

/*=============================================================================
�� �� ����PfcConnectTcpNodeThroughSock5Proxy
��    �ܣ�TCP��Խsock5�������ӷ���ˣ���PfcConnectTcpNode������ͬ���ϲ㲻��Ҫ����PfcConnectToSock5Proxy���������
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����ptOspSock5Proxy : [in] �����������Ϣ�ṹ;
          dwServerIP : [in] ������IP
          wServerPort : [in] �������˿�
          wHb: [in] �����������(��)
          byHbNum: [in] byHbNum��δ�����Ӽ��Ӧ�����Ϊ��·�ѶϿ�
          dwTimeoutMs : [in] ������ʱʱ��
          pdwLocalIP: [in,out] ��TCP����ʹ�õı���IP
�� �� ֵ��ʧ�ܷ���INVALID_NODE��
          �ɹ�����һ����̬����Ľ���, �˺��û��ɽ���������ͨ��
          �ϲ��������������PfcDisconnectTcpNode���������޴���ʱ��������
-------------------------------------------------------------------------------
 �޸ļ�¼��
 ��      ��  �汾  �޸���  �޸�����
 2006/08/21  4.0   ��С��
=============================================================================*/
API int PfcConnectTcpNodeThroughSock5Proxy( TPfcSock5Proxy *ptOspSock5Proxy , u32 dwServerIP, u16 wServerPort,
		u16 wHb = 10, u8 byHbNum = 3 , u32 dwTimeoutMs = 0 , u32 *pdwLocalIP = NULL, u8 bySocksAuthVerion = SOCK5_PROXY_VERSION );

/*=============================================================================
�� �� ����PfcConnectToSock5Proxy
��    �ܣ���sock5�������������TCP��·��UDP��Խsock5��������Ƚ���һ��TCP��·��
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����ptOspSock5Proxy : [in] �����������Ϣ�ṹ
          dwTimeoutMs : [in] ������ʱʱ��
�� �� ֵ��ʧ�ܷ���INVALID_SOCKET��
          �ɹ����������ͨ�ŵ�TCP Socket���ɽ�һ������PfcUdpAssociateThroughSock5Proxy����UDP Associate��
          �ɸ��ã���Ҫ�ϲ�ά����TCP���ӣ���·����Чʱ��Udp AssociateҲӦ��Ϊ��Ч��
          �������������OspDisconnectFromSock5Proxy��
-------------------------------------------------------------------------------
 �޸ļ�¼��
 ��      ��  �汾  �޸���  �޸�����
 2006/08/21  4.0   ��С��
=============================================================================*/
API PFCSOCKHANDLE PfcConnectToSock5Proxy( TPfcSock5Proxy *ptOspSock5Proxy , u32 dwTimeoutMs = 0 , u8 bySocksAuthVerion = SOCK5_PROXY_VERSION);

/*=============================================================================
�� �� ����PfcUdpAssociateThroughSock5Proxy
��    �ܣ�UDP��Խsock5����
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����hSocket : [in] PfcConnectToSock5Proxy���ص�socket(�ɸ���);
          dwLocalIP : [in] �����շ�socket IP���Ա����������������ݴ�Խ��������
          wLocaPort : [in] �����շ�socket �˿ڣ��Ա����������������ݴ�Խ��������
          pdwProxyMapIP : [out] ���������ӳ��IP��������
          pwProxyMapPort : [out] ���������ӳ��˿ڣ�������
          dwTimeoutMs : [in] ������ʱʱ��
�� �� ֵ��ʧ�ܷ���FALSE��
          �ɹ�����TRUE
-------------------------------------------------------------------------------
 �޸ļ�¼��
 ��      ��  �汾  �޸���  �޸�����
 2006/08/21  4.0   ��С��
=============================================================================*/
API BOOL32 PfcUdpAssociateThroughSock5Proxy( PFCSOCKHANDLE hSocket , u32 dwLocalIP, u16 wLocalPort ,
		u32 *pdwProxyMapIP, u16 *pwProxyMapPort , u32 dwTimeoutMs = 0 );

/*=============================================================================
�� �� ����PfcDisConnectFromSock5Proxy
��    �ܣ��Ͽ���sock5������������UDP Associate��TCP����
ע    �⣺
�㷨ʵ�֣�
ȫ�ֱ�����
��    ����hSocket : [in] PfcConnectToSock5Proxy���ص�socket;
�� �� ֵ��ʧ�ܷ���FALSE��
          �ɹ�����TRUE
-------------------------------------------------------------------------------
 �޸ļ�¼��
 ��      ��  �汾  �޸���  �޸�����
 2006/08/21  4.0   ��С��
=============================================================================*/
API BOOL32 PfcDisConnectFromSock5Proxy( PFCSOCKHANDLE hSocket );

#endif //defined(_MSC_VER) || defined(_LINUX_)

#endif //#ifdef _ENABLE_SOCK5_API_
