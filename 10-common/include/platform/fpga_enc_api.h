/******************************************************************************
ģ����  �� FPGA_ENC_DRV
�ļ���  �� fpga_enc_api.h
����ļ��� fpga_enc_api.c
�ļ�ʵ�ֹ��ܣ�
����    ���ŷ���
�汾    ��1.0.0.0.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
08/08/2007  1.0         �ŷ���      ����
03/13/2008  1.1         �ŷ���      ����downscale����
******************************************************************************/
#ifndef __FPGA_ENC_API_H
#define __FPGA_ENC_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "fpga_codec_def.h"


/* ����ֵ���� */
#define FPGA_ENC_DEV_MAX_NUM             1              /* Ŀǰһ�����������֧��1��FPGA����оƬ */
#define FPGA_ENC_CHNL_MAX_NUM            32             /* Ŀǰÿ��������оƬ���֧��32������ͨ�� */
#define FPGA_ENC_VP_MAX_NUM              4              /* Ŀǰÿ��������оƬ���֧��4��VP��Ƶ�ɼ��� */
#define FPGA_ENC_NALU_MAX_NUM            512            /* Ŀǰ1֡���������֧��512��NALU��Ԫ */

/* ��Ƶ����ӿں궨�� */
#define VIDIN_SHUT_DOWN             0x00000000
#define VIDIN_HDMI0                 0x00000001
#define VIDIN_VGA0                  0x00000010
#define VIDIN_YPbPr0                0x00000100
#define VIDIN_YPbPr1                0x00000200  /* ��KDV7810�ϸýӿں�VIDIN_VGA0��ͻ��ֻ��2ѡ1 */
#define VIDIN_SDI0                  0x00001000
#define VIDIN_C0                    0x00010000
#define VIDIN_S0                    0x00100000
#define VIDIN_DVI0                  0x01000000

#define VIDIN_DEC_VP0               0x80000000
#define VIDIN_DEC_VP1               0x80000001
#define VIDIN_DEC_VP2               0x80000002

/* FpgaEncChnlCtrl���������  */
#define FPGA_ENC_CTL_GET_STAT            0              /* ��ѯ������ͳ����Ϣ����TFpgaEncStat���ʹ�� */
#define FPGA_ENC_CTL_SET_OSD             1              /* ���ñ�����OSD����TFpgaEncOsdParam���ʹ�� */
#define FPGA_ENC_CTL_SET_BRIGHTNESS      2              /* �������ȣ�  ��TFpgaEncColorParam���ʹ�� */
#define FPGA_ENC_CTL_SET_CONTRAST        3              /* ���öԱȶȣ���TFpgaEncColorParam���ʹ�� */
#define FPGA_ENC_CTL_SET_HUE             4              /* ����ɫ�ȣ�  ��TFpgaEncColorParam���ʹ�� */
#define FPGA_ENC_CTL_SET_SATURATION      5              /* ���ñ��Ͷȣ���TFpgaEncColorParam���ʹ�� */
#define FPGA_ENC_CTL_SET_VUI_CFG         6              /* ��������VUI��Ϣ����TFpgaEncVuiParam���ʹ�� */
#define FPGA_ENC_CTL_DRAW_BLOCK          7              /* ����ͼ��ָ��λ�ô���һ���Ұ�ɫ���ο飬��TFpgaEncDrawBlk���ʹ�� */

/* IipCfg�Ĵ�������
    Motion estimation engine mode configuration
    31:20 - RESERVED
    19 - staticSearchEnable - Enables search of static (absolute (0,0)) motion vector.
    18 - RESERVED
    17 - fpEngine1Enable - Enables full-pel search engine 1.
    16 - fpEngine0Enable - Enables full-pel search engine 0.
    15 - inter16x16Enable - Enables inter 16x16 macro block type.
    14 - inter16x8Enable - Enables inter 16x8 macro block type.
    13 - inter8x16Enable - Enables inter 8x16 macro block type.
    12 - inter8x8Enable - Enables inter 8x8 macro block type.
    11 - inter8x8SubEnable - Enables inter 8x8 sub-macro block type.
    10 - inter8x4SubEnable - Enables inter 8x4 sub-macro block type.
    9 - inter4x8SubEnable - Enables inter 4x8 sub-macro block type.
    8 - inter4x4SubEnable - Enables inter 4x4 sub-macro block type.
    7 - skipEnable - Enables skip macro blocks.
    6 - spQpelEnable - Enables search of quarter-pel locations when doing sub-pel
    search.
    5 - spHpelEnable - Enables search of half-pel locations when doing sub-pel search.
    4 - spFpelEnable - Enables search of full-pel location when doing sub-pel search.
    3 - randomRefresh - If intra refresh is enabled, makes the refresh 'random' instead of
    contiguous.
    2 - intra4Enable - Enables intra4x4 macro-blocks.
    1 - intra16Enable - Enables intra16x16 macro-blocks.
    0 - pIntraEnable - Enables intra macro-blocks in P-frames
 */
#define FPGA_ENC_IIP_4x4_DISABLE    0xff0f80fa
#define FPGA_ENC_IIP_PINTRAENABLE   (1 << 0)

/* ����VUI��Ϣ���� */
#define FPGA_ENC_VUI_INC_FRAME_RATE 0x80000000  /* ��������sps�а���֡����Ϣ */

/* ���Ͷ��� */
typedef void * HFpgaEncEngine;
typedef void * HFpgaEncChnl;

/* ȫ�ֲ����ṹ���� */
typedef struct{
    s8  abyFirmwareName[FPGA_STR_MAX_LEN]; /* FPGA�������ļ������֣�֧�־���·����
                                              ��:"/usr/bin/fpga.bin",��ָ���Ļ��ڵ�ǰ·������ */
    u32 dwFrmBufMaxLen;             /* Ҫ��4�ֽڶ��룡һ��1֡����������ݳ������Ϊ�������ʵ�1/4�������Ҫ��
                                       ����Ϊ8Mbps,���ֵӦ����Ϊ8/8/4=250KBytes,Ŀǰ����512KBytes */
    u32 dwFrmBufCnt;                /* ֡����ĸ���������2�� */
} TFpgaEncGblParam;


/* ����ͨ���ص��������Ͷ��� */
typedef void (*TFpgaEncChnlCallBack)(HFpgaEncEngine hEngine, TFpgaFrameDesc *ptFrame, u8 *pbyContext);

/* ͼ�񴰿ڽṹ���� */
typedef struct{
//    u32     dwVPId;                         /* ռ�õ�VP�ڣ��������Ӧ��Ӳ����ƣ�0~FPGA_VP_MAX_NUM-1 */
    u32     dwPipId;                        /* �ӻ����������0~FPGA_PIP_MAX_NUM-1 */
    u32     dwPipLeft;                      /* �ӻ���X���꣬������16*8=128�������� */
    u32     dwPipTop;                       /* �ӻ���Y���꣬������16�������� */
    u32     dwPipWidth;                     /* �ӻ����ȣ�������16������������0��ʾȫ�� */
    u32     dwPipHight;                     /* �ӻ���߶ȣ�������16������������0��ʾȫ�� */
} TFpgaWinParam;

/* ����ͨ�������Ĳ����ṹ���� */
typedef struct{
    u32 dwChnlId;                       /* ����ͨ����������0~FPGA_ENC_CHNL_MAX_NUM-1 */
    u32 dwVPId;                         /* ռ�õ�VP��������0~FPGA_ENC_VP_MAX_NUM-1 */
    TFpgaEncChnlCallBack tFrmCallBack;  /* �ص�����ָ�� */
    u8 *pbyContext;                     /* �û�˽�в������ص������ص�ʱ����ֵԭ�����ظ��û� */
    u32 dwBytesPerSlice;                /* ����ÿ��slice���ֽ��������65535��Ĭ�����1400, �����Ϊ0��ʾʹ�õ�slice��ʽ
                                           ����1080i60��Ҫʹ�õ�slice���sliceʱ�赽4096���ϲ��ܱ�֤ͼ�񲻶� */
    TFpgaWinParam   tWin;                 /* ����ͼ�񴰿���Ϣ */
} TFpgaEncChnlCrtParam;


/* ����ͨ��VP�ڵĲ����ṹ���� */
typedef struct{
    TFpgaVidInfo tVidInfo;              /* ����ӿ���Ƶ�ź���Ϣ */
    TFpgaVidInfo tVpVidInfo;            /* ��������VP����Ƶ�ź���Ϣ�� �ṹ������һ��Ϊ0�ͱ�ʾ������ӿ���Ƶ�ź���Ϣ��ͬ */
    /* ע�⣺������������AD�ͽӿ�fpga���û�ֱ�ӵ��ã���������tVidInfo��tVpVidInfo������Ϊ��vp�ڵ���Ƶ��ʽ */

    u32          dwLogicVidIntf;        /* ���ӱ�����VP�ڵ��߼���Ƶ�ӿڣ�Ϊ0��ʾ��������Ƶ�ӿ�һ�£������ο���Ƶ����ӿں궨�� */
    u32          dwReqFrameRate;        /* ��Ҫ��֡�ʣ�����FPGA_ENC_VUI_INC_FRAME_RATE���ʾ����sps�а���֡����Ϣ */
    u16	         wDownScaledWidth;      /* DownScal�����Ƶ������Ϊ��λ,���ܴ�����Ƶ�ź�Դ�Ĵ�С,������Чֵʱ���Զ���ɺ���Ƶ�ź�Դһ�� */
    u16	         wDownScaledHeight;     /* DownScal�����Ƶ�ߣ���Ϊ��λ,���ܴ�����Ƶ�ź�Դ�Ĵ�С,������Чֵʱ���Զ���ɺ���Ƶ�ź�Դһ�� */
    u32          dwLipCfg;              /* 0��ʾʹ��Ĭ��ֵ ��0���ø�ֵ����Ĵ��� */
}TFpgaEncVPParam;

/* ����ͨ����������ṹ���� */
typedef struct{
    u32     dwGopSize;                   /* ����ÿdwGopSize֡����1��I֡����10��ʾI֡9P֡ */
    u32     dwIMaxQP;                    /*  I֡Max QP(0-51) */
    u32     dwIMinQP;                    /*  I֡Min QP(0-51) */
    u32     dwPMaxQP;                    /*  P֡Max QP(0-51) */
    u32     dwPMinQP;                    /*  P֡Min QP(0-51) */
    u32     dwBitRate;                   /*  ���������,��λ��Kbps */
    u32     dwKBitRatePeak;              /*  ��������ʼ���ֵ,��λ��Kbps���������dwBitRate�����60Mbps������ȡĬ��ֵ30M */
}TFpgaEncParam;

/* ����ͨ������ͳ�ƽṹ���� */
typedef struct{
    u32 dwEncFrames;           /* FPGA����֡������ */
    u32 dwEncIFrames;          /* FPGA����I֡������ */
    u32 dwSubmitFrames;        /* �ݽ����û���֡������ */     
    u32 dwEncBytes;            /* FPGA����BYTE���� */ 
    u32 dwEncKBytes;           /* FPGA����KBYTE����������1024���Ϸ���FPGA����BYTE������Ϊ�ܹ�������ֽ��� */ 
    u32 dwSubmitBytes;         /* �ݽ����û���BYTE���� */
    u32 dwSubmitKBytes;        /* �ݽ����û���KBYTE����������1024���ϵݽ����û���BYTE������Ϊ�ܹ��ݽ����ֽ��� */ 
    u32 dwNoBufErrCnt;         /* û�п���Buf���� */
    u32 dwErrFrames;           /* ����֡�� */ 
    u32 dwLenErrCnt;           /* ���ݳ��ȴ�������� */
    u32 dwNALUErrCnt;          /* NALU���ݴ������������ͷ����Ϊ0x00000001 */
}TFpgaEncStat;

/* ������OSD�ṹ���� */
typedef struct{
    BOOL32 bOSDEnable;         /* 0=disable 1=enable */
}TFpgaEncOsdParam;

/* ��������Ƶ����ӿ����ȶԱȶȵȲ����ṹ���� */
typedef struct{
     u32 dwVidInIntf;          /* �ο���Ƶ����ӿں궨�� */
     u32 dwVal;                /* ��Χ00~0x80~0xff */
}TFpgaEncColorParam;


/* VUI���ýṹ���� */
typedef struct{
    u32 dwVuiMsk;             /* VUI���룬��0ʱ�رոù���; ��0ʱ����
                                 ��: ����VUI��Ϣ���� FPGA_ENC_VUI_INC_FRAME_RATE */
}TFpgaEncVuiParam;

/* ����ͼ���л��Ұ�ɫ���ο�ṹ���� */
typedef struct{
    u32    dwBlkId;           /* ���ο��������ÿ������ͨ��֧��2�����ο飺0~1 */
    u32    dwBlkStartX;       /* ���ο����Ͻ�X����(��Ա���ͼ��)��������ż�� */
    u32    dwBlkStartY;       /* ���ο����Ͻ�Y����(��Ա���ͼ��)��������ż�� */
    u32    dwBlkEndX;         /* ���ο����½�X����(��Ա���ͼ��)��������ż�� */
    u32    dwBlkEndY;         /* ���ο����½�Y����(��Ա���ͼ��)��������ż�� */
}TFpgaEncDrawBlk;

/*====================================================================
    ������      : FpgaEncEngineOpen
    ����        ��FPGA����������򿪡�
    �������˵����dwDevId: 0~FPGA_ENC_DEV_MAX_NUM-1;
                 ptGblParam: Engine��ص�һЩȫ�ֲ���
    ����ֵ˵��  �����󷵻�NULL���ɹ�����FPGA Engine���ƾ��
---------------------------------------------------------------------*/
HFpgaEncEngine FpgaEncEngineOpen(u32 dwDevId, TFpgaEncGblParam *ptGblParam);

/*====================================================================
    ������      : FpgaEncEngineClose
    ����        ��FPGA����������رա�
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncEngineClose(HFpgaEncEngine hEngine);

/*====================================================================
    ������      : FpgaEncChnlCreate
    ����        ��FPGA����ͨ��������
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
                 ptChnlParam: ����ͨ�������Ĳ���
    ����ֵ˵��  �����󷵻�NULL���ɹ�����FPGA����ͨ�����ƾ��
---------------------------------------------------------------------*/
HFpgaEncChnl FpgaEncChnlCreate(HFpgaEncEngine hEngine, TFpgaEncChnlCrtParam *ptChnlParam);

/*====================================================================
    ������      : FpgaEncChnlDelete
    ����        ��FPGA����ͨ��ɾ����
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlDelete(HFpgaEncChnl hEncChnl);

/*====================================================================
    ������      : FpgaEncChnlVidSrcSel
    ����        ��FPGA����ͨ����ƵԴѡ��,���ɶ�̬���ã���Ҫֹͣ���롣
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
                 dwVidInIntf: �ο���Ƶ����ӿں궨��
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlVidInSel(HFpgaEncChnl hEncChnl, u32 dwVidInIntf);

/*====================================================================
    ������      : FpgaEncChnlVidStdGet
    ����        ��ͨ��hEncChnl��ѯָ����Ƶ�ӿڵ��ź���Ϣ��
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
                 dwVidInIntf: �ο���Ƶ����ӿں궨��
                 ptVidInfo: ���ص���Ƶ��Ϣ
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlVidStdGet(HFpgaEncChnl hEncChnl, u32 dwVidInIntf, TFpgaVidInfo *ptVidInfo);

/*====================================================================
    ������      : FpgaEncChnlVPParamSet
    ����        ��FPGA����ͨ��VP�ڲɼ��������ã���ƵԴ�źŷ����ı����Ҫ
                 �û�����ֹͣ���룬ʹ���µ���Ƶ�źŲ�������������VP�ڲɼ�
                 ������֮���ٿ�ʼ���롣
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
                 ptVPParam: VP�ڲɼ�����
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlVPParamSet(HFpgaEncChnl hEncChnl, TFpgaEncVPParam *ptVPParam);

/*====================================================================
    ������      : FpgaEncChnlEncParamSet
    ����        ��FPGA����ͨ�������������,�ɶ�̬���ã�����Ҫֹͣ���롣
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
                 ptEncParam: �������
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlEncParamSet(HFpgaEncChnl hEncChnl, TFpgaEncParam *ptEncParam);

/*====================================================================
    ������      : FpgaEncChnlEncStart
    ����        ��FPGA����ͨ�����뿪ʼ��
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlEncStart(HFpgaEncChnl hEncChnl);

/*====================================================================
    ������      : FpgaEncChnlEncStop
    ����        ��FPGA����ͨ������ֹͣ��
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlEncStop(HFpgaEncChnl hEncChnl);

/*====================================================================
    ������      : FpgaEncChnlForceI
    ����        ��FPGA����ͨ��ǿ��I֡��
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlForceI(HFpgaEncChnl hEncChnl);

/*====================================================================
    ������      : FpgaEncChnlCtrl
    ����        ��FPGA����ͨ�����ƣ�Ŀǰ��û�ж��壬�Ժ���Ҫʱ�������ӹ��ܡ�
    �������˵����hEncChnl: FpgaEncChnlCreate�������صľ��;
                 nCmd: �����룻pArgs: ����ָ��
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaEncChnlCtrl(HFpgaEncChnl hEncChnl, s32 nCmd, void *pArgs);

/*====================================================================
    ������      : FpgaDbgGetVidInStd
    ����        ������hEngine��ѯָ����Ƶ�ӿڵ��ź���Ϣ��
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
                 dwVidInIntf: �ο���Ƶ����ӿں궨��
                 ptVidInfo: ���ص���Ƶ��Ϣ
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgGetVidInStd(HFpgaEncEngine hEngine, u32 dwVidInIntf, TFpgaVidInfo *ptVidInfo);

/*====================================================================
    ������      : FpgaDbgSetVidInStd
    ����        �������ã�ǿ��ָ������ӿڵ���Ƶ��ʽ��
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
                 dwVidInIntf: ��Ƶ����ӿڣ�
                 ptVidInfo: ��Ƶ��ʽ;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgSetVidInStd(HFpgaEncEngine hEngine, u32 dwVidInIntf, TFpgaVidInfo *ptVidInfo);

/*====================================================================
    ������      : FpgaCodecGetVer
    ����        ��codecģ��汾�Ų�ѯ��
    �������˵����pchVer�� �����Ĵ�Ű汾��Ϣ��bufָ��
                 dwBufLen������buf�ĳ���
    ����ֵ˵��  ���汾��ʵ���ַ������ȡ�С��0Ϊ����;
                 ���ʵ���ַ������ȴ���dwBufLen����ֵΪ0
---------------------------------------------------------------------*/
s32 FpgaCodecGetVer(s8 *pchVer, u32 dwBufLen);

/*====================================================================
    ������      : FpgaEncIsDied
    ����        ����ѯ�������Ƿ��쳣������
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
    ����ֵ˵��  ���������쳣����������TRUE�����򷵻�FALSE
--------------------------------------------------------------------*/
BOOL32 FpgaEncIsDied(HFpgaEncEngine hEngine);

/*====================================================================
    ������      : FpgaDbgSetRange
    ����        �������˶�ʸ��
    �������˵��������u32ֱֵ��д��register;
    ����ֵ˵��  ���������쳣����������TRUE�����򷵻�FALSE
--------------------------------------------------------------------*/
s32 FpgaDbgSetRange(HFpgaEncEngine hEngine, u32 range);

/*====================================================================
    ������      : FpgaDbgSelVidInSrc
    ����        ��ָ������ӿڵ���ƵԴ��
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
                 dwToVP: ��Ƶ����ӿڣ�
                 dwFromVP: Ϊ0xffffffff��ʾ���������������,��ʱ���������Ч
                           ��dwVidInIntf����, Ϊ0~2��ʾ����Ӧ�Ľ�����
                           ��VP�ڻ�ȡ��Ƶ����,dwVidInIntf��Ч;
                 dwVidInIntf: ��������ӿں궨��
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgSelVidInSrc(HFpgaEncEngine hEngine, u32 dwToVP, u32 dwFromVP, u32 dwVidInIntf);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* __FPGA_ENC_API_H */
