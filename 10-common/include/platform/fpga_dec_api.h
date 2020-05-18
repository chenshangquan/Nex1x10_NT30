/******************************************************************************
ģ����  �� FPGA_DEC_DRV
�ļ���  �� fpga_dec_api.h
����ļ��� fpga_dec_api.c
�ļ�ʵ�ֹ��ܣ�
����    ���ŷ���
�汾    ��1.0.0.0.0
-------------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
08/13/2007  1.0         �ŷ���      ����
******************************************************************************/
#ifndef __FPGA_DEC_API_H
#define __FPGA_DEC_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "fpga_codec_def.h"


/* ����ֵ���� */
#define FPGA_DEC_DEV_MAX_NUM             1              /* Ŀǰһ�����������֧��1��FPGA����оƬ */
#define FPGA_DEC_CHNL_MAX_NUM            32             /* Ŀǰÿ��������оƬ���֧��32������ͨ�� */
#define FPGA_DEC_VP_MAX_NUM              4              /* Ŀǰÿ��������оƬ���֧��4��VP��Ƶ�� */
#define FPGA_DEC_NALU_MAX_NUM            512            /* Ŀǰ1֡���������֧��512��NALU��Ԫ */

/* ��Ƶ����ӿں궨�� */
#define VIDOUT_HDMI0                    0x00000001
#define VIDOUT_VGA0                     0x00000010
#define VIDOUT_YPbPr0                   0x00000100
#define VIDOUT_YPbPr1                   0x00000200      /* ��TS-7180�ϸýӿں�VIDOUT_VGA0��ͻ��ֻ��2ѡ1 */
#define VIDOUT_SDI0                     0x00001000
#define VIDOUT_C0                       0x00010000
#define VIDOUT_S0                       0x00100000
#define VIDOUT_DVI0                     0x01000000

/* ����Ƶ���VP�ں궨�� */
#define FPGA_DEC_SUB_NONE                   0      /* û�и���� */
#define FPGA_DEC_SUB_VP0                    1      /* ����Ƶ���ʹ��VP0 */
#define FPGA_DEC_SUB_VP1                    2      /* ����Ƶ���ʹ��VP1 */
#define FPGA_DEC_SUB_VP2                    3      /* ����Ƶ���ʹ��VP2 */
#define FPGA_DEC_SUB_VP3                    4      /* ����Ƶ���ʹ��VP3 */

/* FpgaDecChnlCtrl���������  */
#define FPGA_DEC_CTL_GET_STAT            0              /* ��ѯ������ͳ����Ϣ����TFpgaDecStat���ʹ�� */

/* ����SpeedMb���� */
#define FPGA_DEC_SPEEDMB_CAL_AUTO       0x00010000  /* �������Զ����� */

/* ���Ͷ��� */
typedef void * HFpgaDecEngine;
typedef void * HFpgaDecChnl;

/* ȫ�ֲ����ṹ���� */
typedef struct{
    s8  abyFirmwareName[FPGA_STR_MAX_LEN]; /* FPGA�������ļ������֣�֧�־���·����
                                              ��:"/usr/bin/fpga.bin",��ָ���Ļ��ڵ�ǰ·������ */
    u32 dwFrmBufMaxLen;             /* һ��1֡����������ݳ������Ϊ�������ʵ�1/4�������Ҫ��
                                       ����Ϊ8Mbps,���ֵӦ����Ϊ8/8/4=250KBytes��Ŀǰ����512KBytes */
    u32 dwFrmBufCnt;                /* ֡����ĸ���������2�� */
} TFpgaDecGblParam;

/* ����ͨ�������Ĳ����ṹ���� */
typedef struct{
    u32 dwChnlId;                       /* ����ͨ����������0~FPGA_DEC_CHNL_MAX_NUM-1 */
    u32 dwVPId;                         /* ռ�õ�VP�ڣ�һ��chnl���ͬʱ��4��VP�������
                                           32λ���Ϊ4��Byte,ÿ��byte��Ӧһ����Ƶ�����:
                                            Bit[ 7: 0]Ϊ����Ƶ���: ��Χ0~FPGA_DEC_VP_MAX_NUM-1,�ֱ��ӦVP0/1/2/3��
                                            Bit[15: 8]Ϊ����Ƶ���1��
                                            Bit[23:16]Ϊ����Ƶ���2��
                                            Bit[31:24]Ϊ����Ƶ���3��
                                           3������Ƶ����β��ú�[����Ƶ���VP�ں궨��]��ָʾ��Ӧ��VP�ţ�
                                           FPGA_DEC_SUB_NONE��ʾ��Ӧ����Ƶ����رգ�
                                           �����������ʾ�ø���Ƶ�������Ӧ��VP�ڳ� */
} TFpgaDecChnlCrtParam;


/* ����ͨ��VP�ڵĲ����ṹ���� */
typedef struct{
    TFpgaVidInfo tVidInfo;              /* ��Ƶ�ź���Ϣ */
    u32 dwPipId;                        /* С�����������0~3 */
    u32 dwPipLeft;                      /* С����X���꣬������16*8=128�������� */
    u32 dwPipTop;                       /* С����Y���꣬������16�������� */
    u32 dwPipWidth;                     /* С�����ȣ�������16������������0��ʾȫ�� */
    u32 dwPipHight;                     /* С����߶ȣ�������16������������0��ʾȫ�� */

    u32 dwWidthMax;
    u32 dwHightMax;                     /* VP��������Ⱥ͸߶ȣ�������16������������0��ʾ��1080p(1920x1088)����Buf��С
                                           �û����еĽ���ͨ������ʹ����ͬ�Ĳ�����Ҫ�޸ı���رս��������´� */
    int notSetDA;                       /* 0��ʾ��st_vp������DA��ʽ��1��ʾ��set_vp������DA */
}TFpgaDecVPParam;

/* ����ͨ����������ṹ���� */
typedef struct{
    u32             dwSpeedMb;          /* ���������ƣ���ֻ���ڽ�һ·����������¿��ƣ����ж�·����ʱ��������Ϊ0!
                                           0=��������һ֡��1~65535=�û�ָ�����굱ǰ֡��ȴ����ٺ��ʱ��
                                           ���ٽ���һ֡��FPGA_DEC_SPEEDMB_CAL_AUTO=�����Զ����㣻 */
    TFpgaVidInfo    tDecVidStd;         /* ����������Ƶ�ֱ��� */
}TFpgaDecParam;

/* ����ͨ������ͳ�ƽṹ���� */
typedef struct{
    u32 dwSendFrames;          /* �û�����֡������ */     
    u32 dwDecFrames;           /* ��������֡������ */
    u32 dwSendBytes;           /* ����BYTE���� */ 
    u32 dwSendKBytes;          /* ����KBYTE����������1024���Ϸ���BYTE������Ϊ�ܹ����͵��ֽ��� */ 
    u32 dwDecBytes;            /* ��������BYTE���� */
    u32 dwDecKBytes;           /* ��������KBYTE����������1024������������BYTE������Ϊ�ܹ�������ֽ��� */ 
    u32 dwNoBufErrCnt;         /* û�п���Buf���� */
    u32 dwErrFrames;           /* ����֡�� */
    u32 dwVldErrCnt;           /* VLD������� */
    u32 dwNalErrCnt;           /* Nal������� */
}TFpgaDecStat;


/*====================================================================
    ������      : FpgaDecEngineOpen
    ����        ��FPGA����������򿪡�
    �������˵����dwDevId: 0~FPGA_DEC_DEV_MAX_NUM-1;
                 ptGblParam: Engine��ص�һЩȫ�ֲ���
    ����ֵ˵��  �����󷵻�NULL���ɹ�����FPGA Engine���ƾ��
---------------------------------------------------------------------*/
HFpgaDecEngine FpgaDecEngineOpen(u32 dwDevId, TFpgaDecGblParam *ptGblParam);

/*====================================================================
    ������      : FpgaDecEngineClose
    ����        ��FPGA����������رա�
    �������˵����hEngine: FpgaDecEngineOpen�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecEngineClose(HFpgaDecEngine hEngine);

/*====================================================================
    ������      : FpgaDecChnlCreate
    ����        ��FPGA����ͨ��������
    �������˵����hEngine: FpgaDecEngineOpen�������صľ��;
                 ptChnlParam: ����ͨ�������Ĳ���
    ����ֵ˵��  �����󷵻�NULL���ɹ�����FPGA Engine���ƾ��
---------------------------------------------------------------------*/
HFpgaDecChnl FpgaDecChnlCreate(HFpgaDecEngine hEngine, TFpgaDecChnlCrtParam *ptChnlParam);

/*====================================================================
    ������      : FpgaDecChnlDelete
    ����        ��FPGA����ͨ��ɾ����
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlDelete(HFpgaDecChnl hDecChnl);

/*====================================================================
    ������      : FpgaDecChnlVidOutSel
    ����        ��FPGA����ͨ������Ƶ����ӿ�ѡ��,���ɶ�̬���ã���Ҫֹͣ���롣
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 dwVidOutIntf: �ο���Ƶ����ӿں궨��
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlVidOutSel(HFpgaDecChnl hDecChnl, u32 dwVidOutIntf);

/*====================================================================
    ������      : FpgaDecChnlVPParamSet
    ����        ��FPGA����ͨ��VP�ڲ��Ų�������,���ɶ�̬���ã���Ҫֹͣ���롣
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 ptVPParam: VP�ڲ��Ų���
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlVPParamSet(HFpgaDecChnl hDecChnl, TFpgaDecVPParam *ptVPParam);

/*====================================================================
    ������      : FpgaDecChnlDecParamSet
    ����        ��FPGA����ͨ�������������,�ɶ�̬���ã�����Ҫֹͣ���롣
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 ptDecParam: �������
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlDecParamSet(HFpgaDecChnl hDecChnl, TFpgaDecParam *ptDecParam);

/*====================================================================
    ������      : FpgaDecChnlDecStart
    ����        ��FPGA����ͨ�����뿪ʼ��
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlDecStart(HFpgaDecChnl hDecChnl);

/*====================================================================
    ������      : FpgaDecChnlDecStop
    ����        ��FPGA����ͨ������ֹͣ��
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlDecStop(HFpgaDecChnl hDecChnl);

/*====================================================================
    ������      : FpgaDecBufGet
    ����        ��FPGA����Buf���롣
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 ptBufDesc : ָ����һ���յ�֡Buf�����ĵ�ַ���û����䲢����ָ��
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룬û�п���Bufʱ
                    ����FPGA_NO_AVAILABLE_BUF��������ptFBufΪNULL
                 �ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecBufGet(HFpgaDecChnl hDecChnl, TFpgaFrameDesc *ptBufDesc);

/*====================================================================
    ������      : FpgaDecBufPut
    ����        ��FPGA����Buf�ݽ���
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 ptBufDesc : ָ������֡���ݵ�֡Buf�����ĵ�ַ����������FpgaDecBufGet��õ�
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE�������
                 �ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecBufPut(HFpgaDecChnl hDecChnl, TFpgaFrameDesc *ptBufDesc);

/*====================================================================
    ������      : FpgaDecChnlCtrl
    ����        ��FPGA����ͨ�����ƣ�Ŀǰ��û�ж��壬�Ժ���Ҫʱ�������ӹ��ܡ�
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
                 nCmd: �����룻pArgs: ����ָ��
    ����ֵ˵��  �����󷵻�FPGA_DEC_FAILURE������룻�ɹ�����FPGA_DEC_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecChnlCtrl(HFpgaDecChnl hDecChnl, s32 nCmd, void *pArgs);

/*====================================================================
    ������      : FpgaDbgSetVidOut
    ����        �������ã�ָ������ӿڵ���ƵԴ�����Խ�����Դֱ�ӽӸ�����ӿڻ��ء�
    �������˵����hEngine: FpgaDecEngineOpen�������صľ��;
                 dwVidOutIntf: ��Ƶ����ӿڣ�
                 dwFromVP: Ϊ0xffffffff��ʾ������ӿڻ���,��ʱ���������Ч
                           ��dwFromVidInIntf����, Ϊ0~2��ʾ����Ӧ�Ľ�����
                           ��VP�ڻ�ȡ��Ƶ����,dwFromVidInIntf��Ч;
                 dwFromVidInIntf: �ο���Ƶ����ӿں궨��
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgSelVidOutSrc(HFpgaDecEngine hEngine, u32 dwVidOutIntf, u32 dwFromVP, u32 dwFromVidInIntf);

/*====================================================================
    ������      : FpgaDbgSetVidOutStd
    ����        �������ã�����ָ������ӿڵ���Ƶ��ʽ��
    �������˵����hEngine: FpgaDecEngineOpen�������صľ��;
                 dwVidOutIntf: ��Ƶ����ӿڣ�
                 ptVidInfo: ��Ƶ��ʽ;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgSetVidOutStd(HFpgaDecEngine hEngine, u32 dwVidOutIntf, TFpgaVidInfo *ptVidInfo);

/*====================================================================
    ������      : FpgaDbgGetVidOutStd
    ����        �������ã����ָ������ӿڵ���Ƶ��ʽ��
    �������˵����hEngine: FpgaDecEngineOpen�������صľ��;
                 dwVidOutIntf: ��Ƶ����ӿڣ�
                 ptVidInfo: ��Ƶ��ʽ;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
--------------------------------------------------------------------*/
s32 FpgaDbgGetVidOutStd(HFpgaDecEngine hEngine, u32 dwVidOutIntf, TFpgaVidInfo *ptVidInfo);

/*====================================================================
    ������      : FpgaDecIsDied
    ����        ����ѯ�������Ƿ��쳣������
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
    ����ֵ˵��  ���������쳣����������TRUE�����򷵻�FALSE
--------------------------------------------------------------------*/
BOOL32 FpgaDecIsDied(HFpgaDecEngine hEngine);

/*====================================================================
    ������      : FpgaSetDviMode
    ����        ������sii9030������DVI����HDMI mode
    �������˵����hEngine: FpgaEncEngineOpen�������صľ��;
                  dwVidOutIntf: VIDOUT_DVI0, VIDOUT_HMDI0
    ����ֵ˵��  ����������TRUE�����򷵻�FALSE
--------------------------------------------------------------------*/
s32 FpgaSetDviMode(HFpgaDecEngine hEngine, u32 dwVidOutIntf);

/*====================================================================
    ������      : FpgaDecPpsSpsSync
    ����        ��FPGA��������PPSSPS���½�����������PIP������
    �������˵����hDecChnl: FpgaDecChnlCreate�������صľ��;
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecPpsSpsSync(HFpgaDecChnl hDecChnl);

/*====================================================================
    ������      : FpgaDecVidOutOffset
    ����        ������ͼ�������ƫ�ơ�
    �������˵����hEngine: �������豸����� dwVPId��VP��
                  left������Ϊ����left�����أ�����Ϊ����-left������
    ����ֵ˵��  �����󷵻�FPGA_FAILURE������룻�ɹ�����FPGA_SUCCESS
---------------------------------------------------------------------*/
s32 FpgaDecVidOutOffset(HFpgaDecEngine hEngine, u32 dwVPId, int left);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* __FPGA_DEC_API_H */
