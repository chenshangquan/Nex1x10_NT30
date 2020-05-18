#ifndef __DATA_SWITCH_H__
#define __DATA_SWITCH_H__

#include "osp.h"

#define DSVERSION       "Dataswitch 36.10.06.06.051209" 

/* DataSwitch ��� */
#define DSID    u32

/*DataSwitch ����ֵ*/
#define DSOK    1
#define DSERROR 0

#define INVALID_DSID  0xffffffff   /*��Ч�ľ��ֵ*/
#define DSERR_INVALIDID    INVALID_DSID          /*��Ч�ı�ʶ����ֵ��dsCreate����ʧ��ʱ����*/

typedef struct tagTDSSpyMsg
{
	unsigned long  dwSrcIP;    /*������*/
	unsigned long  dwDstIP;    /*������*/
	unsigned short wDstPort;  /*������*/
	unsigned short wSrcPort;  /*������*/
	char data[16];
}TDSSpyMsg;

typedef u32 (*FilterFunc)(u32 dwRecvIP, u16 wRecvPort, u32 dwSrcIP, u16 wSrcPort, u8* pData, u32 uLen);


#define SENDMEM_MAX_MODLEN        (u8)32        // ����ʱ���������޸ĳ���
    
/**
 * ���ݰ�ת��Ŀ�꣺ָ�������IP, port��
 * DS�����ƵĶ��IP���������ݰ���ת��Ӧ�ò�����Ӱ�졣Ҳ����˵�����
 * ������IP�����Խ�һ�����ݰ���ȷ�ĵ�ת����ȥ����ʹ����һ��IP��û��
 * ��ϵ�ġ����ԣ�ת������ӿ�IP�ǲ���Ҫ�ġ�
 */
typedef struct tagNetSndMember
{
	unsigned long   dwIP;        /* ת��Ŀ��IP��ַ   */
	unsigned short  wPort;       /* ת��Ŀ�Ķ˿ں�   */
	long            lIdx;        /* �ӿ����� */
	unsigned long   errNum;      /* �������*/
	long            errNo;       /* ����� */
    void *          lpuser;      /* user info */
    /* Ϊʵ�ַ���ʱ�޸����ݶ����ӵĲ��� */
    unsigned short  wOffset;        /* �޸Ĳ��ֵ���ʼλ��; Ŀǰδʹ�� */
    unsigned short  wLen;		/* �޸Ĳ��ֵĳ��ȣ�����Ϊ4�ı�����Ϊ���ʾ���޸� */
    char            pNewData[SENDMEM_MAX_MODLEN];/* Ҫ�޸ĵ����� */
    void *          pAppData;       /* �û��Զ���Ļص������Ĳ��� */
}TNetSndMember;

typedef void (*SendCallback)(u32 dwRecvIP, u16 wRecvPort,
                             u32 dwSrcIP,  u16 wSrcPort,
                             TNetSndMember *ptSends,            // ת��Ŀ���б�
                             u16* pwSendNum,                    // ת��Ŀ����� 
                             u8* pUdpData, u32 dwUdpLen);

/**********************************************************
 * ����: dsSetCapacity                                    *
 * ����: ��������(ֻ���ڴ�������ģ��֮ǰ����)             *
 * ����: dwMaxRcvGrp        - ����������                *
 *       dwMaxSndMmbPerRcvGrp  - ÿһ���������������   *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsSetCapacity( u32 dwMaxRcvGrp = 256 , u32 dwMaxSndMmbPerRcvGrp = 128 );

/**********************************************************
 * ����: dsCreate                                         *
 * ����: ��������ģ��                                     *
 * ����: num     - �ӿ�IP�������                         *
 *       dwIP[]  - �ӿ�IP����                             *
 * ���: ��                                               *
 * ����: �ɹ����ز�����INVALID_DSID��ֵ                   *
 *       ���򷵻� INVALID_DSID                            *
 **********************************************************/
API DSID dsCreate( u32 num ,u32 dwIP[]);

/**********************************************************
 * ����: dsDestroy                                        *
 * ����: ���ٽ���ģ��                                     *
 * ����: dsID    - ��������ģ��ʱ�ľ��                   *
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/
API void dsDestroy( DSID dsId );
 
/*********************************************************
 * ����: dsRegSpy                                         *
 * ����: ע�����ʵ��                                     *
 * ����: dsID     - ��������ģ��ʱ�ľ��                  *
 *       dwInstId - ʵ��ID                                *
 *       wEvent   - ֪ͨʵ������Ϣ                        *
 *       wUDPDataLen - ������UDP�����ݳ���(��С��16)      *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 *                                                        *
 * ע���ú���ֻ����һ��ʹ���ߵ���                         *
 **********************************************************/
API u32  dsRegSpy( DSID dsId , u32 dwInstId , u16 wEvent,u16 wUDPDataLen);
 
 
 /*********************************************************
 * ����: dsUnRegSpy                                       *
 * ����: �������ע��                                     *
 * ����: dsID     - ��������ģ��ʱ�ľ��                  *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 *                                                        *
 * ע���ú���ֻ����һ��ʹ���ߵ���                         *
 **********************************************************/
API u32  dsUnRegSpy( DSID dsId);


 /*********************************************************
 * ����: dsAddSpy                                         *
 * ����: ����һ·����                                     *
 * ����: dsId        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwLocalIfIP - ���ؽ��սӿ�IP                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/ 
API u32  dsAddSpy( DSID dsId ,u32 dwLocalIP ,u16 wLocalPort ,u32 dwIfIP);

 /*********************************************************
 * ����: dsRemvoeSpy                                      *
 * ����: ���һ·����                                     *
 * ����: dsId        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/ 
API u32  dsRemvoeSpy( DSID dsId , u32 dwLocalIP ,u16 wLocalPort );
 
     
/**********************************************************
 * ����: dsAddDump                                        *
 * ����: ���������ڵ�                                     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIp   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwLocalIfIP - ���ؽ��սӿ�IP                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/   
API u32 dsAddDump( DSID dsId ,u32 dwLocalIP ,u16 wLocalPort ,u32 dwLocalIfIP);

/**********************************************************
 * ����: dsRemoveDump                                     *
 * ����: ɾ�������ڵ�                                     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/   
API u32 dsRemoveDump( DSID dsId ,u32 dwLocalIP ,u16 wLocalPort);

/**********************************************************
 * ����: dsGetRecvPktCount                                *
 * ����: ��ѯ�����ܰ���                                   *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwRecvPktCount  - �����ܰ���                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/    
API u32 dsGetRecvPktCount( DSID dsId , u32 dwLocalIP , u16 wLocalPort ,
						  u32 dwSrcIP , u16 wSrcPort , u32& dwRecvPktCount );

/**********************************************************
 * ����: dsGetSendPktCount                                *
 * ����: ��ѯ�����ܰ���                                   *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 *       dwSendPktCount  - �����ܰ���                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/    
API u32 dsGetSendPktCount( DSID dsId , u32 dwLocalIP , u16 wLocalPort ,
						  u32 dwSrcIP , u16 wSrcPort ,
						  u32 dwDstIP, u16 wDstPort, u32& dwSendPktCount );

/**********************************************************
 * ����: dsGetRecvBytesCount	                          *
 * ����: ��ѯ�������ֽ���                                 *
 * ����:												  *
 * ���: ��                                               *
 * ����: ���ؼ�ʱ�����ֽ���								  *
 **********************************************************/
API u32 dsGetRecvBytesCount( );

/**********************************************************
 * ����: dsGetSendBytesCount	                          *
 * ����: ��ѯ�������ֽ���                                 *
 * ����:												  *
 * ���: ��                                               *
 * ����: ���ؼ�ʱ�ֽ���									  *
 **********************************************************/
API u32 dsGetSendBytesCount( );

/**********************************************************
 * ����: dsAdd                                            *
 * ����: ���ӽ����ڵ�                                     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwLocalIfIP - ���ؽ��սӿ�IP                     *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 *   	 dwDstIfIP   - ת��Ŀ�Ľӿ�IP                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/    
API u32 dsAdd(DSID dsId ,
               u32  dwLocalIP ,
               u16  wLocalPort,
               u32  dwLocalIfIP,
               u32  dwDstIP,
               u16  wDstPort,
    		   u32  dwDstOutIfIP);


/**********************************************************
 * ����: dsRemove                                         *
 * ����: ɾ�������ڵ�                                     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/    
API u32 dsRemove(DSID dsId,
                  u32  dwDstIP,
                  u16  wDstPort);

/**********************************************************
 * ����: dsRemoveAll                                      *
 * ����: ɾ�����н���                                     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/    
API u32 dsRemoveAll( DSID dsId );

/**********************************************************
 * ����: dsAddManyToOne                                   *
 * ����: ���ӽ�֧�ֶ�㽻����һ��Ľ���                   *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalP    - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwLocalIfIP - ���ؽ��սӿ�IP                     *
 *       dwDstIIP    - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 *   	 dwDstOutIfIP- ת��Ŀ�Ľӿ�IP                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/   
API u32 dsAddManyToOne(DSID dsId ,
                        u32  dwLocalIP,
                        u16  wLocalPort,
        	            u32  dwLocalIfIP,
                        u32  dwDstIP,
                        u16  wDstPort,
    		            u32  dwDstOutIfIP);
/**********************************************************
 * ����: dsRemoveAllManyToOne                             *
 * ����: ɾ�����н�����ָ��Ŀ�Ľڵ�Ľ���                 *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/        
API u32 dsRemoveAllManyToOne(DSID dsId ,
        	                 u32  dwDstIP,
    	                     u16  wDstPort);

/**********************************************************
 * ����: dsRemoveManyToOne                                *
 * ����: ɾ��ָ���Ľ����ڵ�                               *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIP   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/   
API u32 dsRemoveManyToOne(DSID dsId ,
    	                  u32  dwLocalIP,
                          u16  wLocalPort,
                          u32  dwDstIP,
                          u16  wDstPort  );

/**********************************************************
 * ����: dsAddSrcSwitch                                   *
 * ����: ���Ӹ���UDP����ԴIP��Port�����ĵ�                *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIp   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwLocalIfIP - ���ؽ��սӿ�IP                     *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwDstIP     - ת��Ŀ��IP��ַ                     *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 *   	 dwDstOutIfIP- ת��Ŀ�Ľӿ�IP                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 *                                                        *
 * ע: �÷�ʽΪ֧�ֶ�㵽һ�㽻��                         *
 *     �ú�����dwLocalIP@wLocalPort �յ���ԴIP/PORTΪ     *
 * dwSrcIP@wSrcPort��UDP���ݰ�ת����dwDstIP@wDstPort      *
 **********************************************************/        
API u32 dsAddSrcSwitch(DSID dsId ,
                       u32  dwLocalIP,
                       u16  wLocalPort,
        	           u32  dwLoalIfIP,
                       u32  dwSrcIP ,
                       u16  wSrcPort,
                       u32  dwDstIP,
                       u16  wDstPort,
    		           u32  dwDstOutIfIP);

/**********************************************************
 * ����: dsRemoveAllSrcSwitch                             *
 * ����: ɾ�����и���ԴIP��Port������Ŀ�Ľڵ�Ľ���       *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwLocalIp   - ���ؽ���IP                         *
 *       wLocalPort  - ���ؽ��ն˿ں�                     *
 *       dwSrcIP - ת��Ŀ��IP��ַ                         *
 *       wSrcPort    - ת��Ŀ�Ķ˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/            
API u32 dsRemoveAllSrcSwitch(DSID dsId,
                              u32  dwLocalIP,
                              u16  wLocalPort,
                              u32  dwSrcIP,
                              u16  wSrcPort);

/**********************************************************
 * ����: dsRemoveSrcSwitch                                *
 * ����: ɾ��ָ���ĸ���ԴIP��Port������Ŀ�Ľڵ�Ľ���     *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwDstIP - ת��Ŀ��IP��ַ                         *
 *       wDstPort    - ת��Ŀ�Ķ˿ں�                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/            
API u32 dsRemoveSrcSwitch(DSID dsId,
                          u32  dwLocalIP,
                          u16  wLocalPort,
      	                  u32  dwSrcIP,
    	                  u16  wSrcPort,
                          u32  dwDstIP,
                          u16  wDstPort);


/**********************************************************
 * ����: dsSpecifyFwdSrc                                  *
 * ����: Ϊָ�����յ�ַ����ת�����ݰ�������Դ��ַ       *
 * ����:
 * @param dsId          - DSID
 * @param OrigIP        - ԭʼIP
 * @param OrigPort      - ԭʼPort
 * @param MappedIP      - ӳ��IP
 * @param MappedPort    - ӳ��Port
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsSpecifyFwdSrc(DSID dsId, u32 OrigIP, u16 OrigPort, u32 MappedIP, u16 MappedPort);

/**********************************************************
 * ����: dsResetFwdSrc                                    *
 * ����: �ָ�ָ����ַת�����ݰ���Դ��ַ
 * ����:
 * @param dsId          - DSID
 * @param OrigIP        - ԭʼIP
 * @param OrigPort      - ԭʼPort
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsResetFwdSrc(DSID dsId, u32 OrigIP, u16 OrigPort);


 /**********************************************************
 * ����: dsSetSSRCChange                                  *
 * ����: ���ö�������SSRC���Ķ�                           *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwIP     - IP                                    *
 *       wPort    - �˿ں�                                *
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/    
 API u32 dsSetSSRCChange( DSID dsId, u32  dwIP, u16  wPort );

/**********************************************************
 * ����: dsCancelSSRCChange                                  *
 * ����: ȡ����������SSRC���Ķ�                           *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwIP     - IP                                    *
 *       wPort    - �˿ں�                                *
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/    
 API u32 dsCancelSSRCChange( DSID dsId, u32  dwIP, u16  wPort );

 /**********************************************************
 * ����: dsSetFilterFunc                                  *
 * ����: ���ù��˺���                                     *
 *       ȡ��ʱ�����ú���ָ��ΪNULL����
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwIP     - IP                                    *
 *       wPort    - �˿ں�                                *
 *       pfFilter - ����ָ��
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/    
API u32 dsSetFilterFunc( DSID dsId, u32  dwIP, u16  wPort , FilterFunc pfFilter);

 /**********************************************************
 * ����: dsSetSendCallback                                *
 * ����: ���÷��ͻص�����                                 *
 *       ȡ��ʱ�����ú���ָ��ΪNULL����
 * ����: dsID           - ��������ģ��ʱ�ľ��            *
 *       dwLocalIp      - ���ؽ���IP                      *
 *       wLocalPort     - ���ؽ��ն˿ں�                  *
 *       dwSrcIP        - ת��Ŀ��IP��ַ                  *
 *       wSrcPort       - ת��Ŀ�Ķ˿ں�                  *
 *       pfCallback     - �ص�����
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/    
API u32 dsSetSendCallback( DSID dsId, 
                u32 dwLocalIP, 
                u16 wLocalPort,
                u32 dwSrcIP,
                u16 wSrcPort,
                SendCallback pfCallback);

 /**********************************************************
 * ����: dsSetAppDataForSend                              *
 * ����: Ϊ����Ŀ������һ���Զ����ָ��                   *
 *       ȡ��ʱ�����ú���ָ��ΪNULL����
 * ����: dsID           - ��������ģ��ʱ�ľ��            *
 *       dwLocalIp      - ���ؽ���IP                      *
 *       wLocalPort     - ���ؽ��ն˿ں�                  *
 *       dwSrcIP        - ԴIP��ַ                  *
 *       wSrcPort       - Դ�˿ں�                  *
 *       dwDstIP        - ת��Ŀ��IP��ַ                  *
 *       wDstPort       - ת��Ŀ�Ķ˿ں�                  *
 *       pAppData       - �Զ���ָ��
 * ���: ��                                               *
 * ����: 
 *     DSOK:�ɹ� DSERROR:ʧ��                             *
 **********************************************************/    
API u32 dsSetAppDataForSend( DSID dsId, 
                u32 dwLocalIP, 
                u16 wLocalPort,
                u32 dwSrcIP,
                u16 wSrcPort,
                u32 dwDstIP,
                u16 wDstPort,
                void * pAppData);

 ////////////////////////////////////////
API void dsDbg();
API void dsver(void);
API void dshelp(void);

#endif/*!__DATA_SWITCH_H__*/
