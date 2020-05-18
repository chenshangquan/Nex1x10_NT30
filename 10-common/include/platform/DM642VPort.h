/*******************************************************************************
 * ģ����      : TiVidDrv
 * �ļ���      : VPort.h
 * ����ļ�    : VPort.c
 * �ļ�ʵ�ֹ���: ��Ƶ�ɼ�/���ŵĽӿڶ���
 * ����        : ť���ҩI
 * �汾        : V1.0 Copyright(C) 1995-2006 KEDACOM, All rights reserved.
 * -----------------------------------------------------------------------------
 * �޸ļ�¼:
 * ��  ��       �汾        �޸���      �޸�����
 * 2006/05/08   1.0a        ť����      ����	
*******************************************************************************/
#ifndef VPORT_H
#define VPORT_H 1

enum 
{
    VPORT_OK = 0,
    VPORT_OOM,  /*Out Of Memory*/
    VPORT_BUSY,
    VPORT_CLOSED,
    VPORT_FAILED,
    VPORT_INV_PARAM,
    VPORT_SETUP_FAILED,   /*��ʼ��Ӳ���ӿ�ʧ��*/
    VPORT_ACQUEST_FAILED, /*����Ӳ����Դʧ��*/
    VPORT_NO_VALID_FRAME,
    VPORT_NO_VALID_SPACE
    
};

/*��Ƶ����Ŷ���*/
enum
{
    VPORT_PORT_0 = 0,   /*VP0*/
    VPORT_PORT_1,       /*VP1*/
    VPORT_PORT_2,       /*VP2*/
    VPORT_PORT_MAX_NUM
    
};

/*��Ƶͼ���С�Ķ���*/
enum
{
    VPORT_FRAME_SPEC_D1 = 0, /*D1*/
    VPORT_FRAME_SPEC_4CIF,   /*4CIF*/
    VPORT_FRAME_SPEC_2CIF,   /*2CIF*/
    VPORT_FRAME_SPEC_CIF,    /* CIF*/
    VPORT_FRAME_SPEC_MAX_NUM
    
};

/*VPControl ��֧�ֵĲ�������*/
enum
{
    VPORT_CMD_START = 0,            /*�����Ƶͨ��*/
    VPORT_CMD_PAUSE,                /*��ͣ��Ƶͨ��*/
    VPORT_CMD_GET_STAT,             /*ȡ��״̬ͳ��*/
    VPORT_CMD_RESET_STAT,           /*��λ״̬ͳ��*/
    VPORT_CMD_GET_READY_BUF_NUM,    /*ȡ����Ƶ����ģ����׼���õĻ�����*/
    VPORT_CMD_GET_AVAIL_BUF_NUM,    /*ȡ����Ƶ����ģ���п��кõĻ�����*/
    VPORT_CMD_MAX_NUM
    
};

/*��Ƶ A/D D/A оƬ*/
enum
{
    VPORT_CHIP_ADV7180 = 0,
    VPORT_CHIP_SAA7121,
    VPORT_CHIP_ADV7181,
    VPORT_CHIP_ADV7179,
    VPORT_CHIP_MAX_NUM
    
};

/*
 * ��Ƶ֡�ṹ�嶨�壨���� 128 �ֽڶ��� ���� L2 CACHE LINE SIZE��
 * �ýṹ���Ϊ�䳤�ṹ�塣������ָ��һ֡ͼ��� YUV ���ݺ���Щ�������׵�ַ��
 * �� MediaCtrl �Ľӿڶ���Ϊֱ�Ӵ��� YUV ���ݻ�����׵�ַ����������Ҫ������
 * ���׵�ַ��Ϊ�˷������ߵ�������Ҫ�� YUV ���ݻ�����׵�ַ����ýṹ���׵�ַ
 * ֮��ת����Ϊ�˷�������ת����Ҫ�� YUV ���ݻ�������� 128 �ֽڱ߽磻�ýṹ
 * ������ 128 �ֽڱ߽磻�ӽṹͷ�� abyYUVBuf ��ƫ����Ϊ 128 �ֽڡ�
 */
typedef struct
{
    #define TVFRAME_HEAD_SIZE 128
    
    union
    {
        struct 
        {
            u8 *pbyY; /*ָ�� Y ����*/
            u8 *pbyU; /*ָ�� U ����*/
            u8 *pbyV; /*ָ�� V ����*/
            
            /*ʱ�����������ɲɼ�ʱ��ʱ�䣨ϵͳ��ʼ�����ʵ������ʱ�䣩*/
            /*��λΪ���루ms��*/
            u64 qwTimeStamp; 
            
        } tHeadStruct;
        
        /*��֤ͷ�ṹ�Ĵ�СΪ TVFRAME_HEAD_SIZE �ֽ�*/
        /*��ʵ���У�VCFrameAlloc���Ը�ǰ���������ʱ���*/
        u8 _RESERVED[TVFRAME_HEAD_SIZE]; 
        
    } tHeadUnion;

    u8 abyYUVBuf[1]; /*���뱣֤�ó�Ա�� TVFRAME_HEAD_SIZE �ֽ�ƫ������*/
    
} TVFrame, *TVFrame_t;

#define pbyY        tHeadUnion.tHeadStruct.pbyY
#define pbyU        tHeadUnion.tHeadStruct.pbyU
#define pbyV        tHeadUnion.tHeadStruct.pbyV
#define qwTimeStamp tHeadUnion.tHeadStruct.qwTimeStamp

/* VP ��״̬ͳ��*/
typedef struct
{
    u32 dwFrameDropped;         /*��֡��*/
    
    /*��Բɼ���ͳ����Ϣ*/
	u32 dwCapComplete;
	u32 dwCapOverrun;           
	u32 dwCapSyncByteErr;
	u32 dwCapShortFieldDetect;
    u32 dwCapLongFieldDetect;
    
    /*��Բ��ŵ�ͳ����Ϣ*/
    u32 dwDisComplete;
    u32 dwDisUnderrun;
    u32 dwDisCompleteNack;

} TVPStat, *TVPStat_t;

/*��Ƶͨ������*/
typedef struct 
{       
    s32 nFrameNum;  /*�û�ָ����֡������������費���� TVPort ���ܱ�������ֵ*/
    s32 nAllocLen;  /*�û�ָ����һ֡��YUV�����ݵ��ֽ���*/
    s32 nFrameSpec; /*ָ����Ƶ֡�Ĺ��D1��4CIF��2CIF �� CIF �ȣ�*/
    
    s32 nChipName; /*A/D D/A оƬ�����֣�VPORT_CHIP_ADV7180 ... ��*/
    s32 nPortNum;  /*A/D D/A оƬ�ϵĶ˿ںţ�Ŀǰδʹ��*/
    s32 nAddrSel;  /*A/D D/A оƬ I2C ��ַѡ��0/1��*/
    
    BOOL bPAL;     /*PAL(TRUE); NTSC(FALSE)*/
    
} TVPortParam, *TVPortParam_t;

/*==============================================================================
    ������      : VCCreate
    ����        ����ʼ����Ƶͨ��������֡������Դ��
    �㷨ʵ��    ����
    ����ȫ�ֱ�����g_atVPorts
    �������˵����nVPNum(I):    VP ͨ����
                  bCapMode(I):  �ɼ�/����ģʽ���ɼ���TRUE��/���ţ�FALSE��
                  ptParam(I):   �û�ָ���Ĳ���
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCCreate(s32 nVPNum, BOOL bCapMode, TVPortParam_t ptParam);

/*==============================================================================
    ������      : VCDelete
    ����        ���ͷ���Ƶͨ�����ͷŷ������Դ��ֹͣ�ɼ�/����
    �㷨ʵ��    ����
    ����ȫ�ֱ�����g_atVPorts
    �������˵����nVPNum(I):    VP ͨ����
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCDelete(s32 nVPNum);

/*==============================================================================
    ������      : VCControl
    ����        �����òɼ�/���Ų���
    �㷨ʵ��    ����
    ����ȫ�ֱ�����g_atVPorts
    �������˵����ptVCHandle(I):    ͨ�����
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCControl(s32 nVPNum, u32 dwCmd, void *pvArgs);

/*==============================================================================
    ������      : VCAlloc
    ����        ���ϲ�����������һ֡��Ƶ���������Ȩ
    �㷨ʵ��    �������������ģ��ʱ��Ҫ���жϻ���
    ����ȫ�ֱ�����g_atVPorts
    �������˵����nVPNum(I):    VP ͨ����
                  pptFrame(O):  ����ָ��֡�����ָ��
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCAlloc(s32 nVPNum, TVFrame_t *pptFrame);

/*==============================================================================
    ������      : VCFree
    ����        ���ϲ��������黹һ֡��Ƶ���������Ȩ
    �㷨ʵ��    �������������ģ��ʱ��Ҫ���жϻ���
    ����ȫ�ֱ�����g_atVPorts
    �������˵����nVPNum(I):    VP ͨ����
                  ptFrame(I):   ����ָ��֡�����ָ��
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCFree(s32 nVPNum, TVFrame_t ptFrame);

/*==============================================================================
    ������      : VCExchange
    ����        ���ϲ�����������һ֡��Ƶ���������Ȩ
    �㷨ʵ��    ���������û��֡���Ժ�Ӧ�ó��򽻻�����û���κθı�
    ����ȫ�ֱ�����g_atVPorts
    �������˵����nVPNum(I):    VP ͨ����
                  pptFrame(O):  ����ָ��֡�����ָ��
    ����ֵ˵��  ���ɹ���VPORT_OK��
                  ʧ�ܣ�����ֵ��
==============================================================================*/
s32 VCExchange(s32 nVPNum, TVFrame_t *pptFrame);

#endif /*#ifndef VPORT_H*/
