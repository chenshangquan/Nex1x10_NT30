/******************************************************************************
ģ����  �� TAOS_CODEC_DRV
�ļ���  �� taos_codec_api.h
����ļ��� taos_dev_api.c taos_enc_api.c taos_dec_api.c
�ļ�ʵ�ֹ��ܣ�
����    ���ŷ���
�汾    ��1.0.0.0.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
12/04/2008  1.0         �ŷ���      ����
******************************************************************************/
#ifndef __TAOS_CODEC_API_H
#define __TAOS_CODEC_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "brdwrapper.h"         /* Ϊ�˰�����Ƶ��صĺ궨��ͽṹ���� */
#include "taos_codec_def.h"


/* ����ֵ���� */

/* TaosCtrl ���������  */
#define TAOS_CTL_GET_ENC_STAT            0x0000  /* ��ѯTAOS����ģ����Ϣ����TTaosEncStat���ʹ�� */
#define TAOS_CTL_GET_DEC_STAT            0x0001  /* ��ѯTAOS����ģ����Ϣ����TTaosDecStat���ʹ�� */
#define TAOS_CTL_SET_ENC_IIPCFG          0x0100  /* ���ñ�����IipCfg�Ĵ�����pArgsָ��(u32 *) */
#define TAOS_CTL_SET_OSD_CFG          	 0x0101  /* ����TAOS��OSD���ã���TTaosOsdCfg���ʹ�� */
#define TAOS_CTL_SET_VUI_CFG          	 0x0102  /* ����TAOS������VUI��Ϣ����TTaosVuiCfg���ʹ�� */
#define TAOS_CTL_DRAW_BLOCK              0x0103  /* ����ͼ��ָ��λ�ô���һ���Ұ�ɫ���ο飬��TTaosDrawBlk���ʹ�� */

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
#define TAOS_ENC_IIP_4x4_DISABLE    0xff0f80fa
#define TAOS_ENC_IIP_PINTRAENABLE   (1 << 0)


/*____________________________�������ֽṹ����_______________________*/

/* ���Ͷ��� */
typedef void * HTaosEngine;
typedef void * HTaosEncChnl;
typedef void * HTaosDecChnl;

/* ����ͨ���ص��������Ͷ��� */
typedef void (*TTaosEncChnlCallBack)(HTaosEngine hEngine, TTaosFrameDesc *ptFrame, u8 *pbyContext);


/* Buf�����ṹ���� */
typedef struct{
    u32     adwVidWidthMax[TAOS_CHNL_MAX_NUM];
    u32     adwVidHightMax[TAOS_CHNL_MAX_NUM];/* ��Ƶ����Ⱥ͸߶ȣ����ڷ���ÿ��ͨ���ڴ棬��0��ʾ��1080p(1920x1088)����Buf��С
                                               ���еı���ͽ���ͨ����ʹ�øò�����Ҫ�޸ı���ر�TAOS���´� */

    u32     adwFrmBufLen[TAOS_BUF_POOL_MAX];/* ÿ��POOL��֡buf���ȣ�����POOLʱҪ��Pool0~Poolx�ĳ��ȴ�С��������
                                               һ��1֡����������ݳ������Ϊ�������ʵ�1/4��
                                               �����Ҫ������Ϊ8Mbps,���ֵӦ����Ϊ8/8/4=250KBytes��Ŀǰ����512KBytes */
    u32     adwFrmBufCnt[TAOS_BUF_POOL_MAX];/* ÿ��POOL��֡buf��������Чֵ����2��, Ϊ0��ʾPOOL���� */

    u32     dwChnlMaxNum;                   /* ��ഴ����ͨ������ */
} TTaosBufParam;

/* ȫ�ֲ����ṹ���� */
typedef struct{
    BOOL32  bDoBist;                        /* �Ƿ���TAOS�����ڴ��Լ� */
    u32     dwIipCfg;                       /* 0��ʾʹ��Ĭ��ֵ ��0���ø�ֵ����Ĵ�������ο�:IipCfg�Ĵ������� */
    u32     dwCodecMode;                    /* ����빤��ģʽ��Ϊ0��ʾAUTO����ο�: TAOS����ģʽ���ͺ궨�� */

    TTaosBufParam   *ptEncBufParam;         /* ΪNULL��ʾû�б���Ӧ�ã���������������س�ʼ�����ڴ���䣬 */ 
    TTaosBufParam   *ptDecBufParam;         /* ΪNULL��ʾû�н���Ӧ�ã���������������س�ʼ�����ڴ���䣬 */ 
} TTaosGblParam;


/* VP�ڵĲ����ṹ���� */
typedef struct{
    u32     dwVPId;                         /* VP��������0~TAOS_VP_MAX_NUM-1 */
    u32     dwIoType;                       /* ����������򣬸��������: VP������������ͺ궨��
                                               ������ΪTAOS_VP_DISABLEʱ����������Ч;
                                               ������ΪTAOS_VP_CLONEʱdwInterface��tVidStd��Ч��
                                                    �����Զ�����VP0/4,֮ǰ���������ú�VP0/4 */
    u32     dwInterface;                    /* ��Ӧ����Ƶ�ӿ����ƣ���: ��Ƶ��������ӿ����ͺ궨�� */
    TVidStd tVidStd;                        /* ��Ƶ�ź���ʽ */

    u32     dwLeftCropPixs;                 /* Դͼ����е�n�����أ�����ͼ������ !ע�⣺������ż��! */
    u32     dwTopCropLines;                 /* Դͼ�����е�n�У�����ͼ������ */
    u32	    dwScaledWidth;                  /* Ŀǰ������ģʽʱ֧��DownScal������ģʽ��Ч������Ϊ��λ */
    u32	    dwScaledHeight;                 /* Ŀǰ������ģʽʱ֧��DownScal������ģʽ��Ч����Ϊ��λ */

    u32     dwDdrBankSel;                   /* ��VP�����ݴ�����ĸ��ڴ�Bank�У���: TAOS�ڴ�bank����
                                               ���û������Ҫ����� TAOS_DDR_BANK_AUTO�������Զ����� */
}TTaosVPParam;

/* ͼ�񴰿ڽṹ���� */
typedef struct{
    u32     dwVPId;                         /* ռ�õ�VP�ڣ��������Ӧ��Ӳ����ƣ�0~TAOS_VP_MAX_NUM-1 */
    u32     dwPipId;                        /* �ӻ����������0~TAOS_PIP_MAX_NUM-1 */
    u32     dwPipLeft;                      /* �ӻ���X���꣬������16*8=128�������� */
    u32     dwPipTop;                       /* �ӻ���Y���꣬������16�������� */
    u32     dwPipWidth;                     /* �ӻ����ȣ�������16������������0��ʾȫ�� */
    u32     dwPipHight;                     /* �ӻ���߶ȣ�������16������������0��ʾȫ�� */
} TTaosWinParam;

/* OSD�ṹ���� */
typedef struct{
    BOOL32  bEncoder;                       /* TRUE������ˣ�FALSE������� */
    u32     dwChnlId;                       /* ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    BOOL32  bOSDEnable;                     /* 0=disable 1=enable */
}TTaosOsdCfg;

/* VUI���ýṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwVuiMsk;                       /* VUI���룬��0ʱ�رոù���; ��0ʱ����
                                               ��: ����VUI��Ϣ���� TAOS_VUI_INC_FRAME_RATE */
}TTaosVuiCfg;

/* ����ͼ���л��Ұ�ɫ���ο�ṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwBlkId;                        /* ���ο��������ÿ������ͨ��֧��2�����ο飺0~1 */
    u32     dwBlkStartX;                    /* ���ο����Ͻ�X����(��Ա���ͼ��)��������ż�� */
    u32     dwBlkStartY;                    /* ���ο����Ͻ�Y����(��Ա���ͼ��)��������ż�� */
    u32     dwBlkEndX;                      /* ���ο����½�X����(��Ա���ͼ��)��������ż�� */
    u32     dwBlkEndY;                      /* ���ο����½�Y����(��Ա���ͼ��)��������ż�� */
}TTaosDrawBlk;

/*____________________________���벿�ֽṹ����_______________________*/


/* ����ͨ�������Ĳ����ṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */

    TTaosWinParam tWin;                     /* ����ͼ�񴰿���Ϣ,tWin.dwVPId������չ,��:����ͼ�񴰿���ϢtWin.dwVPId��չ���� */

    u32     dwReqFrameRate;                 /* ����֡�ʣ�����TAOS_VUI_INC_FRAME_RATE���ʾ����sps�а���֡����Ϣ */
    u32     dwBytesPerSlice;                /* ����ÿ��slice���ֽ��������65535��Ĭ�����1400, �����
                                               Ϊ0��ʾʹ�õ�slice��ʽ */
    TTaosEncChnlCallBack tFrmCallBack;      /* �ص�����ָ�� */
    u8      *pbyContext;                    /* �û�˽�в������ص������ص�ʱ����ֵԭ�����ظ��û� */
} TTaosEncChnlCrtParam;

/* ����ͨ����������ṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwGopSize;                      /* ����ÿdwGopSize֡����1��I֡����10��ʾI֡9P֡ */
    u32     dwIMaxQP;                       /*  I֡Max QP(0-51) */
    u32     dwIMinQP;                       /*  I֡Min QP(0-51) */
    u32     dwPMaxQP;                       /*  P֡Max QP(0-51) */
    u32     dwPMinQP;                       /*  P֡Min QP(0-51) */
    u32     dwBitRate;                      /*  ���������,��λ��Kbps */
    u32     dwKBitRatePeak;                 /*  ��������ʼ���ֵ,��λ��Kbps��
                                              # ���λ��0��ʾ�ٶ�����:
                                                I֡��ǰ��P֡�Ĵ�С��࣬���QPֵ�仯̫�󣬵��±�I֡
                                                ʱͼ�������أ��������ŵ������ʷǳ����ȣ��ʺ�������·�����ϸ����Ƶĳ��ϣ���E1��·
                                              # ���λ��1��ʾ��������:
                                                I֡��С������QPֵ��ǰ��P֡�仯С���Լ�����I֡ʱ
                                                ͼ�������ص����⣬�������ʻ���΢��Щͻ����������
                                                �岻��ͻ�ܶ�,�����ʼ���ֵ�������õ�40M����,ֵԽ����Խ�����ԣ�
                                                Ϊ��ֹfifo�����СQPֵ��ҪС��15 */
}TTaosEncParam;

/* ����ͨ������ͳ�ƽṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwEncFrames;                    /* TAOS����֡������ */
    u32     dwEncIFrames;                   /* TAOS����I֡������ */
    u32     dwSubmitFrames;                 /* �ݽ����û���֡������ */     
    u32     dwEncBytes;                     /* TAOS����BYTE���� */ 
    u32     dwEncKBytes;                    /* TAOS����KBYTE����������1024���Ϸ���TAOS����BYTE������Ϊ�ܹ�������ֽ��� */ 
    u32     dwSubmitBytes;                  /* �ݽ����û���BYTE���� */
    u32     dwSubmitKBytes;                 /* �ݽ����û���KBYTE����������1024���ϵݽ����û���BYTE������Ϊ�ܹ��ݽ����ֽ��� */ 
    u32     dwNoBufErrCnt;                  /* û�п���Buf���� */
    u32     dwErrFrames;                    /* ����֡�� */ 
    u32     dwLenErrCnt;                    /* ���ݳ��ȴ�������� */
    u32     dwFrameLenMax;                  /* �������֡�ĳ��� */
    u32     dwNALUErrCnt;                   /* NALU���ݴ������������ͷ����Ϊ0x00000001 */
}TTaosEncStat;


/*____________________________���벿�ֽṹ����_______________________*/

/* ����ͨ�������Ĳ����ṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */

    u32     dwWinNum;                       /* ����ͼ��������ڸ�������Χ0~TAOS_VP_MAX_NUM*TAOS_PIP_MAX_NUM-1 */
    TTaosWinParam atWin[TAOS_VP_MAX_NUM*TAOS_PIP_MAX_NUM]; /* ����ͼ�����������Ϣ */

    u32     dwSpeedMb;                      /* ���������ƣ���ֻ���ڽ�һ·����������¿��ƣ����ж�·����ʱ��������Ϊ0!
                                               0=��������һ֡��1~65535=�û�ָ�����굱ǰ֡��ȴ����ٺ��ʱ��
                                               ���ٽ���һ֡��TAOS_SPEEDMB_CAL_AUTO=�����Զ����㣻 */
}TTaosDecChnlCrtParam;

/* ����ͨ����������ṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwSpeedMb;                      /* ���������ƣ���ֻ���ڽ�һ·����������¿��ƣ����ж�·����ʱ��������Ϊ0!
                                                0=��������һ֡��1~65535=�û�ָ�����굱ǰ֡��ȴ����ٺ��ʱ��
                                                ���ٽ���һ֡��TAOS_SPEEDMB_CAL_AUTO=�����Զ����㣻 */
    TVidStd tDecVidStd;                     /* ����������Ƶ�ֱ��� */
}TTaosDecParam;

/* ����ͨ������ͳ�ƽṹ���� */
typedef struct{
    u32     dwChnlId;                       /* ����ͨ����������0~TAOS_CHNL_MAX_NUM-1 */
    u32     dwSendFrames;                   /* �û�����֡������ */     
    u32     dwDecFrames;                    /* ��������֡������ */
    u32     dwSendBytes;                    /* ����BYTE���� */ 
    u32     dwSendKBytes;                   /* ����KBYTE����������1024���Ϸ���BYTE������Ϊ�ܹ����͵��ֽ��� */ 
    u32     dwDecBytes;                     /* ��������BYTE���� */
    u32     dwDecKBytes;                    /* ��������KBYTE����������1024������������BYTE������Ϊ�ܹ�������ֽ��� */ 
    u32     dwNoBufErrCnt;                  /* û�п���Buf���� */
    u32     dwErrFrames;                    /* ����֡�� */
    u32     dwDropFrames;                   /* �������붪֡���� */
    u32     dwVldErrCnt;                    /* VLD������� */
    u32     dwNalErrCnt;                    /* Nal������� */
    u32     dwBufedFrames;                  /* ��������Ĵ�����֡�� */
}TTaosDecStat;



/*____________________________�������ֺ�������_______________________*/

/*====================================================================
    ������      : TaosEngineOpen
    ����        ��TAOS�豸����򿪡�
    �������˵����dwDevId: 0~TAOS_DEV_MAX_NUM-1;
                  ptGblParam: Engine��ص�һЩȫ�ֲ�����
    ����ֵ˵��  �����󷵻�NULL���ɹ������豸���ƾ��
---------------------------------------------------------------------*/
HTaosEngine TaosEngineOpen(u32 dwDevId, TTaosGblParam *ptGblParam);

/*====================================================================
    ������      : TaosEngineClose
    ����        ��TAOS�豸����رա�
    �������˵����hEngine: TaosEngineOpen�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEngineClose(HTaosEngine hEngine);

/*====================================================================
    ������      : TaosVPParamSet
    ����        ��TAOS��VP�ڲ�������,���ɶ�̬���ã���Ҫֹͣ��ͨ����
                  ����������������!
    �������˵����hEngine: TaosEngineOpen�������صľ��;
                  ptVPParam: VP�ڲ��Ų���
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosVPParamSet(HTaosEngine hEngine, TTaosVPParam *ptVPParam);

/*====================================================================
    ������      : TaosCtrl
    ����        ��TAOS���ܿ���
    �������˵����hDecChnl: TaosChnlCreate�������صľ��;
                  nCmd: �����룻pArgs: ����ָ��
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosCtrl(HTaosEngine hEngine, s32 nCmd, void *pArgs);

/*====================================================================
    ������      : TaosIsDied
    ����        ����ѯ�豸�Ƿ��쳣������
    �������˵����hEngine: TaosEncEngineOpen�������صľ��;
    ����ֵ˵��  ���豸�쳣����������TRUE�����򷵻�FALSE
--------------------------------------------------------------------*/
BOOL32 TaosIsDied(HTaosEngine hEngine);

/*====================================================================
    ������      : TaosGetDrvVer
    ����        ��Taosģ��汾�Ų�ѯ��
    �������˵����pchVer�� �����Ĵ�Ű汾��Ϣ��bufָ��
                 dwBufLen������buf�ĳ���
    ����ֵ˵��  ���汾��ʵ���ַ������ȡ�С��0Ϊ����;
                 ���ʵ���ַ������ȴ���dwBufLen����ֵΪ0
---------------------------------------------------------------------*/
s32 TaosGetDrvVer(s8 *pchVer, u32 dwBufLen);


/*____________________________���벿�ֺ�������_______________________*/

/*====================================================================
    ������      : TaosEncChnlCreate
    ����        ��TAOS����ͨ��������
    �������˵����hEngine: TaosEngineOpen�������صľ��;
                  ptChnlParam: ����ͨ�������Ĳ���
    ����ֵ˵��  �����󷵻�NULL���ɹ����ر���ͨ�����ƾ��
---------------------------------------------------------------------*/
HTaosEncChnl TaosEncChnlCreate(HTaosEngine hEngine, TTaosEncChnlCrtParam *ptChnlParam);

/*====================================================================
    ������      : TaosEncChnlDelete
    ����        ��TAOS����ͨ��ɾ����
    �������˵����hEncChnl: TaosEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEncChnlDelete(HTaosEncChnl hEncChnl);

/*====================================================================
    ������      : TaosEncChnlParamSet
    ����        ��TAOS����ͨ�������������,�ɶ�̬���ã�����Ҫֹͣ���롣
    �������˵����hEncChnl: TaosEncChnlCreate�������صľ��;
                  ptEncParam: �������
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEncChnlParamSet(HTaosEncChnl hEncChnl, TTaosEncParam *ptEncParam);

/*====================================================================
    ������      : TaosEncChnlStart
    ����        ��TAOS����ͨ�����뿪ʼ��
    �������˵����hEncChnl: TaosEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEncChnlStart(HTaosEncChnl hEncChnl);

/*====================================================================
    ������      : TaosEncChnlStop
    ����        ��TAOS����ͨ������ֹͣ��
    �������˵����hEncChnl: TaosEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEncChnlStop(HTaosEncChnl hEncChnl);

/*====================================================================
    ������      : TaosEncChnlForceI
    ����        ��TAOS����ͨ��ǿ��I֡��
    �������˵����hEncChnl: TaosEncChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosEncChnlForceI(HTaosEncChnl hEncChnl);


/*____________________________���벿�ֺ�������_______________________*/

/*====================================================================
    ������      : TaosDecChnlCreate
    ����        ��TAOS����ͨ��������
    �������˵����hEngine: TaosEngineOpen�������صľ��;
                  ptChnlParam: ����ͨ�������Ĳ���
    ����ֵ˵��  �����󷵻�NULL���ɹ����ؽ���ͨ�����ƾ��
---------------------------------------------------------------------*/
HTaosDecChnl TaosDecChnlCreate(HTaosEngine hEngine, TTaosDecChnlCrtParam *ptChnlParam);

/*====================================================================
    ������      : TaosDecChnlDelete
    ����        ��TAOS����ͨ��ɾ����
    �������˵����hDecChnl: TaosDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlDelete(HTaosDecChnl hDecChnl);

/*====================================================================
    ������      : TaosDecChnlParamSet
    ����        ��TAOS����ͨ�������������,�ɶ�̬���ã�����Ҫֹͣ���롣
    �������˵����hDecChnl: TaosDecChnlCreate�������صľ��;
                  ptDecParam: �������
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlParamSet(HTaosDecChnl hDecChnl, TTaosDecParam *ptDecParam);

/*====================================================================
    ������      : TaosDecChnlStart
    ����        ��TAOS����ͨ�����뿪ʼ��
    �������˵����hDecChnl: TaosDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlStart(HTaosDecChnl hDecChnl);

/*====================================================================
    ������      : TaosDecChnlStop
    ����        ��TAOS����ͨ������ֹͣ��
    �������˵����hDecChnl: TaosDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룻�ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlStop(HTaosDecChnl hDecChnl);

/*====================================================================
    ������      : TaosDecChnlBufGet
    ����        ��TAOS����Buf���롣
    �������˵����hDecChnl: TaosDecChnlCreate�������صľ��;
                  ptBufDesc : ָ����һ���յ�֡Buf�����ĵ�ַ���û�
                  ���䲢����ָ�롣
                  nTimeout: ��ʱֵ��0 = no wait, -1 = wait forever, 
                                   >0 = ����
    ����ֵ˵��  �����󷵻�TAOS_FAILURE������룬û�п���Bufʱ
                 ���� TAOS_NO_AVAILABLE_BUF, ������սṹ����
                 �ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlBufGet(HTaosDecChnl hDecChnl, TTaosFrameDesc *ptBufDesc, s32 nTimeout);

/*====================================================================
    ������      : TaosDecChnlBufPut
    ����        ��TAOS����Buf�ݽ���
    �������˵����hDecChnl: TaosChnlCreate�������صľ��;
                  ptBufDesc : ָ������֡���ݵ�֡Buf�����ĵ�ַ��
                  ��������TaosDecChnlBufGet��õġ�
    ����ֵ˵��  �����󷵻�TAOS_FAILURE�������
                 �ɹ�����TAOS_SUCCESS
---------------------------------------------------------------------*/
s32 TaosDecChnlBufPut(HTaosDecChnl hDecChnl, TTaosFrameDesc *ptBufDesc);


#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* __TAOS_CODEC_API_H */
