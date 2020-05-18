#ifndef _VCCOMMON_040602_H_
#define _VCCOMMON_040602_H_

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "kdvtype.h"
#include "kdvdef.h"


#ifdef _LINUX_

#ifndef min
#define min(a,b) ((a)>(b)?(b):(a))
#endif
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#endif//!_LINUX_

///////////////////////////////// KDV �汾�� ///////////////////////////////////////
//
#define KDVVC_VERID                  (u8*)"9"
#define LEN_KDVVC_VERID              strlen((s8*)KDVVC_VERID)
//
////////////////////////////////////////////////////////////////////////////////////

//�豸���ඨ��
#define		TYPE_MCU                     	 1   //MCU
#define		TYPE_MCUPERI                     2   //MCU����
#define		TYPE_MT                          3   //�ն�

//MCU���Ͷ���
#define		MCU_TYPE_KDV8000                 1   //MCU����8000
#define		MCU_TYPE_KDV8000B                2   //MCU����8000B
#define		MCU_TYPE_WIN32                   3   //MCU����WIN32
#define		MCU_TYPE_KDV8000B_HD             4   //MCU����8000B-HD
#define     MCU_TYPE_KDV8000C                101 //MCU����8000C

//MCU��Ʒ����
#define		PRODUCT_MCU_STANDARD            (s8*)"KDC MCU"
#define		PRODUCT_MCU_8000C				(s8*)"KDC MCU-8000C"

//��Ƶ��ʽ����
#define     VIDEO_FORMAT_INVALID            255
#define		VIDEO_FORMAT_SQCIF				1   //SQCIF(128*96)
#define		VIDEO_FORMAT_QCIF				2   //SCIF(176*144)
#define		VIDEO_FORMAT_CIF                3   //CIF(352*288)  - P��
#define     VIDEO_FORMAT_2CIF               4   //2CIF(352*576) - p
#define		VIDEO_FORMAT_4CIF               5   //4CIF(704*576) - P��(H264�´˺�ָ��D1(720*576)   - P�ƣ�N��D1��720*480��)
#define		VIDEO_FORMAT_16CIF				6   //16CIF(1408*1152)
#define		VIDEO_FORMAT_AUTO				7   //����Ӧ��������MPEG4

#define		VIDEO_FORMAT_SIF                8   //SIF(352*240)  - N��
#define     VIDEO_FORMAT_2SIF               9   //2SIF
#define		VIDEO_FORMAT_4SIF               10  //4SIF(704*480) - N��

#define     VIDEO_FORMAT_VGA                11  //VGA(640*480)
#define		VIDEO_FORMAT_SVGA               12  //SVGA(800*600)
#define		VIDEO_FORMAT_XGA                13  //XGA(1024*768)
#define     VIDEO_FORMAT_WXGA               14  //WXGA(1280*768 | 1280*800)

                                                //�������ն˷ֱ��ʸı�
#define		VIDEO_FORMAT_SQCIF_112x96       21  //SQCIF(112*96)
#define		VIDEO_FORMAT_SQCIF_96x80        22  //SQCIF(96*80)

                                                // ����ֱ���
#define     VIDEO_FORMAT_W4CIF              31  //Wide 4CIF(1024*576)
#define     VIDEO_FORMAT_HD720              32  //720 1280*720
#define     VIDEO_FORMAT_SXGA               33  //SXGA 1280*1024
#define     VIDEO_FORMAT_UXGA               34  //UXGA 1600*1200
#define     VIDEO_FORMAT_HD1080             35  //1080  1920*1088(p) 1920*544(i)

                                                //�Ǳ�ֱ��ʣ�1080p��ͼ���������ն˷ֱ��ʸı�
#define     VIDEO_FORMAT_1440x816           41  //1440��816(3/4)
#define     VIDEO_FORMAT_1280x720           42  //1280��720(2/3)
#define     VIDEO_FORMAT_960x544            43  // 960��544(1/2)
#define     VIDEO_FORMAT_640x368            44  // 640��368(1/3)
#define     VIDEO_FORMAT_480x272            45  // 480��272(1/4)

                                                //�Ǳ�ֱ��ʣ�720p��ͼ�� �������ն˷ֱ��ʸı�
#define     VIDEO_FORMAT_720_960x544        51  //960��544(3/4)
#define     VIDEO_FORMAT_720_864x480        52  //864��480(2/3)
#define     VIDEO_FORMAT_720_640x368        53  //640��368(1/2)
#define     VIDEO_FORMAT_720_432x240        54  //432��240(1/3)
#define     VIDEO_FORMAT_720_320x192        55  //320��192(1/4)

//�ϲ���Ƶ֡�ʶ���(���ڷ�H.264��H.264ֱ����VIDEO_FPS_USRDEFINED+��ֵ��ʾ֡��)
#define     VIDEO_FPS_2997_1                1   //30 ֡/s
#define     VIDEO_FPS_25                    2   //25 ֡/s(�ײ㰴30֡����)
#define     VIDEO_FPS_2997_2                3   //15 ֡/s
#define     VIDEO_FPS_2997_3                4   //10 ֡/s
#define     VIDEO_FPS_2997_4                5   //7.5֡/s
#define     VIDEO_FPS_2997_5                6   //6  ֡/s
#define     VIDEO_FPS_2997_6                7   //5  ֡/s
#define     VIDEO_FPS_2997_30               8   //1  ֡/s
#define     VIDEO_FPS_2997_7P5              9   //4  ֡/s
#define     VIDEO_FPS_2997_10               10  //3  ֡/s
#define     VIDEO_FPS_2997_15               11  //2  ֡/s
#define     VIDEO_FPS_USRDEFINED            128 //�Զ���֡��(>=128,��ȥ128��Ϊʵ��֡��)

//��Ƶ˫�����Ͷ���
#define		VIDEO_DSTREAM_H263PLUS			0   //H263��
#define		VIDEO_DSTREAM_MAIN				1   //������Ƶ��ʽһ��
#define		VIDEO_DSTREAM_H263PLUS_H239     2   //H263����H239
#define		VIDEO_DSTREAM_H263_H239         3   //H263��H239
#define		VIDEO_DSTREAM_H264_H239         4   //H264��H239
#define     VIDEO_DSTREAM_H264              5   //H264
#define     VIDEO_DSTREAM_H264_H263PLUS_H239    6   //H264 & H263+ ��H239

//���鴴����ʽ
#define		CONF_CREATE_MT                  201 //�������ն˴���
#define		CONF_CREATE_SCH                 202 //������ԤԼ���鴴��
#define		CONF_CREATE_MCS                 0   //�����ɻ�ش���
#define     CONF_CREATE_NPLUS               203 //������N+1���ݴ������˱�ʶ��mcu����ʱ�����浽�ļ����������л���ָ�

//���鿪�ŷ�ʽ����
#define		CONF_OPENMODE_CLOSED             0  //������,�ܾ��б�������ն�
#define		CONF_OPENMODE_NEEDPWD            1  //�����������
#define		CONF_OPENMODE_OPEN               2  //��ȫ���� 

//������ܷ�ʽ����
#define     CONF_ENCRYPTMODE_NONE            0 //������
#define     CONF_ENCRYPTMODE_DES             1 //des����
#define     CONF_ENCRYPTMODE_AES             2 //aes����

//��������ת��ʱ�Ƿ�֧�ֹ�һ������ʽ����, �붪���ش���ʽ�Լ����ܷ�ʽ����
#define     CONF_UNIFORMMODE_NONE            0 //����һ������
#define     CONF_UNIFORMMODE_VALID           1 //  ��һ������

#define     SWITCHCHANNEL_UNIFORMMODE_NONE   0 //����һ������
#define     SWITCHCHANNEL_UNIFORMMODE_VALID  1 //  ��һ������

#define     INVALID_PAYLOAD                  0xFF


//���ݻ��鷽ʽ����
#define		CONF_DATAMODE_VAONLY             0  //���������ݵ�����Ƶ����
#define		CONF_DATAMODE_VAANDDATA          1  //�������ݵ�����Ƶ����
#define		CONF_DATAMODE_DATAONLY           2  //����������Ƶ�����ݻ���

//���������ʽ����
#define     CONF_RELEASEMODE_NONE            0  //�����Զ�����
#define     CONF_RELEASEMODE_NOMT            1  //���ն�ʱ�Զ�����

//������з�ʽ
#define     CONF_TAKEMODE_SCHEDULED          0  //ԤԼ����
#define     CONF_TAKEMODE_ONGOING            1  //��ʱ����
#define     CONF_TAKEMODE_TEMPLATE           2  //����ģ��

//���鱣����ʽ
#define		CONF_LOCKMODE_NONE               0  //δ����
#define		CONF_LOCKMODE_NEEDPWD            1  //�����������
#define		CONF_LOCKMODE_LOCK               2  //���� 

//�����˵�Դ�Ķ���
#define		CONF_SPEAKERSRC_SELF             0  //���Լ�
#define		CONF_SPEAKERSRC_CHAIR            1  //����ϯ
#define		CONF_SPEAKERSRC_LAST             2  //����һ�η�����

//�����ն˷�ʽ����
#define		CONF_CALLMODE_NONE               0  //�ֶ�����
#define		CONF_CALLMODE_TIMER              2  //��ʱ����

//��ʱ�����ն�ʱ��������
#define		DEFAULT_CONF_CALLINTERVAL        20 //ȱʡ�Ķ�ʱ���м�����룩
#define		MIN_CONF_CALLINTERVAL            10 //��С�Ķ�ʱ���м�����룩

//��ʱ�����ն˺��д�������
#define		DEFAULT_CONF_CALLTIMES           0  //����ζ�ʱ���д���
#define		MIN_CONF_CALLTIMES               2  //��С�Ķ�ʱ���д���

//����ϳɷ�ʽ����
#define		CONF_VMPMODE_NONE                0  //�����л���ϳ�
#define		CONF_VMPMODE_CTRL                1  //��ػ���ϯѡ���Ա�ϳ�
#define		CONF_VMPMODE_AUTO                2  //MCU�Զ�ѡ���Ա�ϳ�

//���ϵ���ǽ�ϳɷ�ʽ����
#define		CONF_VMPTWMODE_NONE              0  //�����л���ϳ�
#define		CONF_VMPTWMODE_CTRL              1  //��ػ���ϯѡ���Ա�ϳ�
#define		CONF_VMPTWMODE_AUTO              2  //MCU�Զ�ѡ���Ա�ϳ�

//����¼��ʽ���� 
#define		CONF_RECMODE_NONE                0  //��¼��
#define		CONF_RECMODE_REC                 1  //¼��
#define		CONF_RECMODE_PAUSE               2  //��ͣ

//�������ʽ����
#define		CONF_PLAYMODE_NONE               0  //������
#define		CONF_PLAYMODE_PLAY               1  //����
#define		CONF_PLAYMODE_PAUSE              2  //��ͣ
#define		CONF_PLAYMODE_FF                 3  //���
#define		CONF_PLAYMODE_FB                 4  //����
#define		CONF_PLAYMODE_PLAYREADY			 5	//׼������

//������ѯ��ʽ����
#define		CONF_POLLMODE_NONE               0  //����ѯ�㲥 
#define		CONF_POLLMODE_VIDEO              1  //��ͼ����ѯ�㲥
#define		CONF_POLLMODE_SPEAKER            2  //��������

//�������䷽ʽ���� -- modify bas 2
#define		CONF_BASMODE_NONE                0  //��������������
#define		CONF_BASMODE_AUD                 1  //��Ƶ����
#define		CONF_BASMODE_VID                 2  //��Ƶ����
#define		CONF_BASMODE_BR                  3  //��������
#define		CONF_BASMODE_CASDAUD             4  //�����ش���Ƶ����
#define		CONF_BASMODE_CASDVID             5  //�����ش���Ƶ����

//�������䷽ʽ����
#define		CONF_HDBASMODE_NONE                0  //�����и�����������
#define		CONF_HDBASMODE_VID                 1  //��������Ƶ����
#define		CONF_HDBASMODE_DOUBLEVID           2  //˫������
#define		CONF_HDBASMODE_CASDVID             3  //�����ش���Ƶ����

//���������ʽ�Ķ���
#define     CONF_MIXMODE_NONE                0  //������
#define     CONF_MIXMODE_DISC                1  //ȫ�����
#define     CONF_MIXMODE_SPEC                2  //���ƻ���
#define     CONF_MIXMODE_VAC                 3  //��������

//����˫������ʽ����
#define		CONF_DUALMODE_SPEAKERONLY		 0	//ֻ�ܷ����˷���
#define		CONF_DUALMODE_EACHMTATWILL		 1	//�����ն˶��ܷ���

//��ѯ״̬����
#define		POLL_STATE_NONE                  0  //δ��ѯ 
#define		POLL_STATE_NORMAL                1  //��ѯ����
#define		POLL_STATE_PAUSE                 2  //��ѯ��ͣ

//����ϳ�״̬����
#define     VMP_STATE_START                  1  //��ʼ
#define     VMP_STATE_CHANGE                 2  //�ı�
#define     VMP_STATE_STOP                   3  //ֹͣ

//���ϵ���ǽ�ϳ�״̬����
#define     VMPTW_STATE_START                1  //��ʼ
#define     VMPTW_STATE_CHANGE               2  //�ı�
#define     VMPTW_STATE_STOP                 3  //ֹͣ

//����ǽ״̬����
#define     TW_STATE_START                  1  //��ʼ
#define     TW_STATE_CHANGE                 2  //�ı�
#define     TW_STATE_STOP                   3  //ֹͣ

//����ǽ��Ա���Ͷ���
#define     TW_MEMBERTYPE_NULL               0  //VCSָ����ԱΪ�գ������ø�ͨ��
#define		TW_MEMBERTYPE_MCSSPEC            1  //���ָ�� 
#define		TW_MEMBERTYPE_SPEAKER            2  //�����˸���
#define		TW_MEMBERTYPE_CHAIRMAN           3  //��ϯ����
#define		TW_MEMBERTYPE_POLL               4  //��ѯ��Ƶ����
#define		TW_MEMBERTYPE_TWPOLL             5	//����ǽ��ѯ
#define     TW_MEMBERTYPE_SWITCHVMP          6  //ѡ��vmp
#define     TW_MEMBERTYPE_BATCHPOLL          7  //������ѯ
#define     TW_MEMBERTYPE_VCSAUTOSPEC        8  //VCS�Զ�ָ�� 

//����ϳɳ�Ա���Ͷ���
#define		VMP_MEMBERTYPE_MCSSPEC           1  //���ָ�� 
#define		VMP_MEMBERTYPE_SPEAKER           2  //�����˸���
#define		VMP_MEMBERTYPE_CHAIRMAN          3  //��ϯ����
#define		VMP_MEMBERTYPE_POLL              4  //��ѯ��Ƶ����
#define		VMP_MEMBERTYPE_VAC               5	//��������(��ز�Ҫ�ô�����)

//����ϳɷ����
#define		VMP_STYLE_DYNAMIC                0   //��̬����(���Զ��ϳ�ʱ��Ч)
#define		VMP_STYLE_ONE                    1   //һ����
#define		VMP_STYLE_VTWO                   2   //�����棺���ҷ� 
#define		VMP_STYLE_HTWO                   3   //������: һ��һС
#define		VMP_STYLE_THREE                  4   //������
#define		VMP_STYLE_FOUR                   5   //�Ļ���
#define		VMP_STYLE_SIX                    6   //������ 
#define		VMP_STYLE_EIGHT                  7   //�˻���
#define		VMP_STYLE_NINE                   8   //�Ż���
#define		VMP_STYLE_TEN                    9   //ʮ����
#define		VMP_STYLE_THIRTEEN               10  //ʮ������
#define		VMP_STYLE_SIXTEEN                11  //ʮ������
#define		VMP_STYLE_SPECFOUR               12  //�����Ļ��� 
#define		VMP_STYLE_SEVEN                  13  //�߻���
#define		VMP_STYLE_TWENTY				 14  //��ʮ����
#define     VMP_STYLE_NONE                  0xff //��֧�ֵĸ�ʽ

//���ϵ���ǽ�ϳɳ�Ա���Ͷ���
#define		VMPTW_MEMBERTYPE_MCSSPEC         1  //���ָ�� 
#define		VMPTW_MEMBERTYPE_SPEAKER         2  //�����˸���
#define		VMPTW_MEMBERTYPE_CHAIRMAN        3  //��ϯ����
#define		VMPTW_MEMBERTYPE_POLL            4  //��ѯ��Ƶ����
#define		VMPTW_MEMBERTYPE_VAC             5	//��������(��ز�Ҫ�ô�����)

//�߼�ͨ����ض���
#define      LOGCHL_VIDEO					1	//����Ƶ�߼�ͨ��
#define      LOGCHL_AUDIO					2	//��Ƶ�߼�ͨ��
#define      LOGCHL_SECVIDEO				3	//�ڶ���Ƶ�߼�ͨ��
#define      LOGCHL_T120DATA				4	//T120�����߼�ͨ��
#define      LOGCHL_H224DATA				5	//H224�����߼�ͨ��
#define      LOGCHL_MMCUDATA                6   //���������߼�ͨ��
#define      LOGCHL_VIDEO_BOTH              7   //����Ƶ+�ڶ���Ƶ�߼�ͨ��

#define		MAXLEN_ALIAS			        128  //MCU���ն˼������127����ĸ��63������
#define     VALIDLEN_ALIAS                  16   //��Ч��������
#define		MAXLEN_CONFNAME                 64   //��������󳤶�
#define		MAXLEN_PWD                      32   //������볤��  
 
#define		MAXLEN_E164                     16   //���E164���볤�� 
#define     MAXLEN_KEY                      16   //���ļ���key����
#define     MAXLEN_SW_VER                   32   //�������汾�ų���

//conf id len
#define     MAXLEN_CONFID                   16
#define     LOCAL_MCUID                     192  //����MCU ID 

#define     MAXNUM_PERIEQP_CHNNL			16	//����ǽͨ�������
#define     MAXNUM_MIXER_DEPTH				10  //���������������
#define     MAXNUM_MIXER_DEPTH_8000B        8   //8000B���������������
#define     MAXNUM_MIXER_DEPTH_8000B_G729   4   //8000B G.729���������������
#define     MAXNUM_VMP_MEMBER				20  //�����ϳɳ�Ա��
#define     MAXNUM_SDVMP_MEMBER             16
#define     MAXNUM_MPUSVMP_MEMBER			20  //SVMP�����ϳɳ�Ա��(��16���ӵ�20)
#define     MAXNUM_MPUDVMP_MEMBER			9 

//˫���ٷֱ������Сֵ
#define     MAXNUM_DSTREAM_SCALE            90
#define     MINNUM_DSTREAM_SCALE            10
#define     DEF_DSTREAM_SCALE               30

//�ն˰�����
//ע�⣺�ò��ֶ�����Զֻ�����ӣ��ұ��뱣����ҵ/��ҵ��һ��
#define     MT_BOARD_UNKNOW                 255
#define     MT_BOARD_WIN                    0

// KDVϵ���նˣ�1-49
#define     MT_BOARD_8010                   1
#define     MT_BOARD_8010A                  2
#define     MT_BOARD_8018                   3
#define     MT_BOARD_IMT                    4
#define     MT_BOARD_8010C                  5

#define     MT_BOARD_8010A_2                7
#define     MT_BOARD_8010A_4                8
#define     MT_BOARD_8010A_8                9

#define     MT_BOARD_7210                   10
#define     MT_BOARD_7610                   11
#define     MT_BOARD_7810                   12
#define     MT_BOARD_7910                   13

#define		MT_BOARD_5610_KDV				14
#define		MT_BOARD_6610_KDV				15

//KDV-��������ϵ��
// #define     MT_BOARD_7820_A                 18
// #define     MT_BOARD_7820_B                 19
// #define     MT_BOARD_7920_A                 20
// #define     MT_BOARD_7920_B                 21

#define     MT_BOARD_7820_A_NOSDI           18
#define     MT_BOARD_7820_B_NOSDI           19
#define     MT_BOARD_7920_A_NOSDI           20
#define     MT_BOARD_7920_B_NOSDI           21

#define     MT_BOARD_7820_A_SDIINOUT        22
#define     MT_BOARD_7820_B_SDIINOUT        23
#define     MT_BOARD_7920_A_SDIINOUT        24
#define     MT_BOARD_7920_B_SDIINOUT        25
#define     MT_BOARD_7820_A_SDIININ         26
#define     MT_BOARD_7820_B_SDIININ         27
#define     MT_BOARD_7920_A_SDIININ         28
#define     MT_BOARD_7920_B_SDIININ         29

#define     MT_BOARD_7920_L        30

//KDV-��������ϵ��
#define     MT_BOARD_H600_LB				31
#define     MT_BOARD_H600_B					32
#define     MT_BOARD_H600_C					33
#define     MT_BOARD_H700_A					34
#define     MT_BOARD_H700_B					35
#define     MT_BOARD_H700_C					36
#define     MT_BOARD_H900_A_NOSDI			37
#define     MT_BOARD_H900_A_SDIINOUT        38
#define     MT_BOARD_H900_A_SDIININ         39
#define     MT_BOARD_H900_B_NOSDI			40
#define     MT_BOARD_H900_B_SDIINOUT        41
#define     MT_BOARD_H900_B_SDIININ         42
#define     MT_BOARD_H900_C_NOSDI			43
#define     MT_BOARD_H900_C_SDIINOUT        44
#define     MT_BOARD_H900_C_SDIININ         45
#define     MT_BOARD_H600_LC				46
#define     MT_BOARD_H800_A					47
#define     MT_BOARD_H800_B					48
#define     MT_BOARD_H800_C					49


#define     MT_BOARD_KDVx_END               50



//KDV-T3ϵ��
#define     MT_BOARD_7620_A                 16
#define     MT_BOARD_7620_B                 17

#define     MT_BOARD_KDVx_END               50
// TSϵ�У��� 51-99 ��Χ��
#define     MT_BOARD_6610                   51
#define     MT_BOARD_6610E                  52
#define     MT_BOARD_6210                   53
#define     MT_BOARD_5210                   54
#define     MT_BOARD_3210                   55 
#define     MT_BOARD_V5                     56

#define     MT_BOARD_3610                   57
#define     MT_BOARD_5610                   58
#define     MT_BOARD_6210E                  59

#define     MT_BOARD_TSx_END                100

// Ϊ��֤���� Vϵ�к�TSϵ�в��ж���
// Vϵ�У��� 101-150 ��Χ��
// #define     MT_BOARD_V5                     101

#define     MT_BOARD_Vx_END                 150

// GK�û��������볤�Ⱥ궨��
#define     MAX_LEN_GK_USRNAME              (u8)16
#define     MAX_LEN_GK_PWD                  (u8)16

// �������ͺ궨��
#define     VOLUME_TYPE_OUT                 (u8)0   //�ն��������
#define     VOLUME_TYPE_IN                  (u8)1   //�ն���������

// MCUǰ���������������
#define		FECTYPE_NONE					(u8)(0x00)
#define		FECTYPE_RAID5					(u8)(0x01)
#define		FECTYPE_RAID6					(u8)(0x02)

//���鷢������
#define    MCS_CONF                         (u8)0   //MCS�ٿ��Ļ���
#define    VCS_CONF							(u8)1   //VCS�ٿ��Ļ���
#define    ALL_CONF							(u8)2   //���з��𷽵Ļ���

#define    MAX_VCSSOFTNAME_LEN          (u8)64

// ���س���
enum SwitchConstant
{
	turn_on,		//����
	turn_off		//�ر�
};

// ��ѯ����
enum PollType
{
	poll_none,		//û����ѯ
	poll_vcb,		//�����㲥
	poll_vcs		//����ѡ��
};

enum PollStatus
{
	poll_status_none,    //δ��ѯ
	poll_status_normal,  //��ѯ������
	poll_status_pause    //��ѯ��ͣ
};

//�������ͺ궨��
enum OprType
{
    opr_start,
    opr_stop
};

//MCU�����ն˵��Զ���֪ͨ��Ϣ ��Ϣ��Ŷ���
enum Mcu2MtNtfMsgType
{
    emNoneNtf           = 0,
    emBePolledNextNtf   = 1           //��������ѯ�� ֪ͨ
};

enum emMtSpeakerStatus
{
    emBgn               = 0,
        emWaiting       = 1,        //�ȴ�ͬ�⣻mcu���ᷢ�ʹ�״̬���ն��ڷ������� �� ��Ϊ������֪ͨ �� ֮ǰ���Զ������״̬
        emAgreed        = 2,        //�����ˣ�
        emDenid         = 3,        //���뱻�ܾ���
        enCanceled      = 4,        //��ȡ�����ԣ�
		enEnd
};

enum emConfSpeakMode
{
    emNormalSpeakMode   = 0,        //��ͨ����ģʽ����ϯָ��/���ָ��/һ����ն�����
		emAnswerInstantly   = 1         //����ģʽ
};

#ifdef WIN32
    #pragma comment( lib, "ws2_32.lib" ) 
    #pragma pack( push )
    #pragma pack( 1 )
    #define window( x )	x
    #define PACKED 
#else
    #include <netinet/in.h>
    #define window( x )
#if defined(__ETI_linux__)
    #define PACKED
#else
    #define PACKED __attribute__((__packed__))	// ȡ�����������Ż�����
#endif
#endif

// �ն�ID�Ŷ���
//////////////////////////////////////////////////////////////////////////
typedef struct tagMtLabel
{
	// ���úͻ�ȡ�ն�ID��
	void SetMtLabel( u8 byMcuNum, u8 byMtNum )
	{
		byMcuNo = byMcuNum;
		byMtNo = byMtNum;
	}

	u8 GetMcuNo( void ) { return byMcuNo; }
	u8 GetMtNo( void ) { return byMtNo; }
	tagMtLabel() : byMcuNo( 0 ), byMtNo( 0 ) {}
private :
	u8 byMcuNo;
	u8 byMtNo;
}PACKED TMTLABEL,*PTMTLABEL;



// �ն˹�����Ϣ����
//////////////////////////////////////////////////////////////////////////

// ������Ϣ����
#define ROLLMSG_TYPE_SMS		0	// ����Ϣ
#define ROLLMSG_TYPE_PAGETITLE	1	// ��ҳ��Ļ
#define ROLLMSG_TYPE_ROLLTITLE	2	// ������Ļ
#define ROLLMSG_TYPE_STATICTEXT	3	// ��̬�ı�

// ������Ϣ����
#define MAX_ROLLMSG_LEN		2048	// ���2K�ֽ�

// �����ٶ�
#define ROLL_SPEED_1	1	// ����
#define ROLL_SPEED_2	2	// ����
#define ROLL_SPEED_3	3	// ����
#define ROLL_SPEED_4	4	// �Կ�
#define ROLL_SPEED_5	5	// ���

// �����ƹ���
#define ROLL_INFINIT	0xFF

// ��Ϣͷ�ṹ: ��Ϣ����(1)+��������(1)+�����ٶ�(1)+Դ�ն�(2)+Ŀ���ն˸���(2)+������Ϣ����(2)+������Ϣ����(2)
// ��Ϣ��: �û�������Ŀ���ն��б�+������Ϣ����
#define ROLLMSG_MSGHEAD_LEN					11
#define ROLLMSG_MSGHEAD_ROLLTYPE_OFFSET		0
#define ROLLMSG_MSGHEAD_ROLLTYPE_LEN		1
#define ROLLMSG_MSGHEAD_ROLLTIME_OFFSET		(ROLLMSG_MSGHEAD_ROLLTYPE_OFFSET + ROLLMSG_MSGHEAD_ROLLTYPE_LEN)
#define ROLLMSG_MSGHEAD_ROLLTIME_LEN		1
#define ROLLMSG_MSGHEAD_ROLLRATE_OFFSET		(ROLLMSG_MSGHEAD_ROLLTIME_OFFSET + ROLLMSG_MSGHEAD_ROLLTIME_LEN)
#define ROLLMSG_MSGHEAD_ROLLRATE_LEN		1
#define ROLLMSG_MSGHEAD_SRCMT_OFFSET		(ROLLMSG_MSGHEAD_ROLLRATE_OFFSET + ROLLMSG_MSGHEAD_ROLLRATE_LEN)
#define ROLLMSG_MSGHEAD_SRCMT_LEN			2
#define ROLLMSG_MSGHEAD_DSTMTNUM_OFFSET		(ROLLMSG_MSGHEAD_SRCMT_OFFSET + ROLLMSG_MSGHEAD_SRCMT_LEN)
#define ROLLMSG_MSGHEAD_DSTMTNUM_LEN		2
#define ROLLMSG_MSGHEAD_ROLLMSGLEN_OFFSET	(ROLLMSG_MSGHEAD_DSTMTNUM_OFFSET + ROLLMSG_MSGHEAD_DSTMTNUM_LEN)
#define ROLLMSG_MSGHEAD_ROLLMSGLEN_LEN		2
#define ROLLMSG_MSGHEAD_MSGLEN_OFFSET		(ROLLMSG_MSGHEAD_ROLLMSGLEN_OFFSET + ROLLMSG_MSGHEAD_ROLLMSGLEN_LEN)
#define ROLLMSG_MSGHEAD_MSGLEN_LEN			2
#define ROLLMSG_MSGBODY_OFFSET				ROLLMSG_MSGHEAD_LEN
//
//  ������Ϣ
//

// ������Ϣ�ṹ
class CRollMsg
{
public :
	CRollMsg()
	{
		memset( m_abyBuffer, 0, sizeof( m_abyBuffer ) );
		u16 wLen = ROLLMSG_MSGHEAD_LEN;
		wLen = htons( wLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET,
			&wLen, ROLLMSG_MSGHEAD_MSGLEN_LEN );
	}

	/*
	====================================================================
	����        �����ù�����Ϣ����
	�������˵��������
	����ֵ˵��  ����
	====================================================================
	*/
	void SetType( u8 byMsgType ) 
	{
		if ( byMsgType != ROLLMSG_TYPE_SMS 
			&& byMsgType != ROLLMSG_TYPE_PAGETITLE 
			&& byMsgType != ROLLMSG_TYPE_ROLLTITLE
			&& byMsgType != ROLLMSG_TYPE_STATICTEXT )
			byMsgType = ROLLMSG_TYPE_SMS;

		*( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLTYPE_OFFSET ) = byMsgType;
		return;
	}

	/*
	====================================================================
	����        ����ȡ������Ϣ����
	�������˵������
	����ֵ˵��  ������
	====================================================================
	*/
	u8 GetType( void ) { return *( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLTYPE_OFFSET ); }

	/*
	====================================================================
	����        �����ù�������
	�������˵��������
	����ֵ˵��  ����
	====================================================================
	*/
	void SetRollTimes( u8 byTimes ) 
	{
		if ( byTimes == 0 )
			byTimes = 1;	// ��֤���ٹ���һ��
		*( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLTIME_OFFSET ) = byTimes; 
	}
	/*
	====================================================================
	����        ����ȡ��������
	�������˵������
	����ֵ˵��  ������
	====================================================================
	*/
	u8 GetRollTimes( void ) { return *( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLTIME_OFFSET ); }

	/*
	====================================================================
	����        �����ù����ٶ�
	�������˵�����ٶ�
	����ֵ˵��  ����
	====================================================================
	*/
	void SetRollRate( u8 byRate ) { *( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLRATE_OFFSET ) = byRate; }
	/*
	====================================================================
	����        ����ȡ�����ٶ�
	�������˵������
	����ֵ˵��  ���ٶ�
	====================================================================
	*/
	u8 GetRollRate( void ) { return *( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLRATE_OFFSET ); }

	/*
	====================================================================
	����        ��������Ϣ��Դ�ն�
	�������˵����TMTLABEL
	����ֵ˵��  ����
	====================================================================
	*/
	void SetMsgSrcMtId( TMTLABEL tMtId ) {	SetMsgSrcMtId( tMtId.GetMcuNo(), tMtId.GetMtNo() ); }
	/*
	====================================================================
	����        ��������Ϣ��Դ�ն�
	�������˵����<mcu,mt>
	����ֵ˵��  ����
	====================================================================
	*/
	void SetMsgSrcMtId( u8 byMcuNo, u8 byMtNo ) 
	{
		*( m_abyBuffer + ROLLMSG_MSGHEAD_SRCMT_OFFSET ) = byMcuNo;
		*( m_abyBuffer + ROLLMSG_MSGHEAD_SRCMT_OFFSET + 1 ) = byMtNo;
	}

	/*
	====================================================================
	����        ����ȡ��Ϣ��Դ�ն�ID
	�������˵������
	����ֵ˵��  ��TMTLABEL
	====================================================================
	*/
	TMTLABEL GetMsgSrcMtId( void ) 
	{
		TMTLABEL tMsgSrc;
		u8 byMcuNo = *( m_abyBuffer + ROLLMSG_MSGHEAD_SRCMT_OFFSET );
		u8 byMtNo = *( m_abyBuffer + ROLLMSG_MSGHEAD_SRCMT_OFFSET + 1 );
		tMsgSrc.SetMtLabel( byMcuNo, byMtNo );
		return tMsgSrc; 
	}

	/*
	====================================================================
	����        ����ȡĿ���ն˸���
	�������˵������
	����ֵ˵��  ���ն˸���
	====================================================================
	*/
	u16  GetDstMtNum( void ) 
	{ 
		u16 wMtNum = 0;
		memcpy( &wMtNum, m_abyBuffer + ROLLMSG_MSGHEAD_DSTMTNUM_OFFSET,
			ROLLMSG_MSGHEAD_DSTMTNUM_LEN );
		return ntohs( wMtNum ); 
	}

	/*
	====================================================================
	����        ������Ŀ���ն��б�(�������¸����ն��б�)
	�������˵�����б���ָ�� + Ŀ���ն˸���
	����ֵ˵��  ����
	====================================================================
	*/
	void SetDstMtList( const TMTLABEL *ptMtList = NULL, u16 wDstMtNum = 0 )
	{
		if ( ptMtList == NULL || wDstMtNum == 0 )
			return;


		// ������Ϣ����
		u16 wRollMsgLen = GetRollMsgContentLen();
		if ( wRollMsgLen != 0 )
		{
			u8 abyRollMsg[ MAX_ROLLMSG_LEN ] = { 0 };
			u16 wOffSet = ROLLMSG_MSGBODY_OFFSET + wDstMtNum * sizeof( TMTLABEL );
			memcpy( abyRollMsg,
					m_abyBuffer + ROLLMSG_MSGBODY_OFFSET, 
					min( MAX_ROLLMSG_LEN, wRollMsgLen ) );
			memcpy( m_abyBuffer + wOffSet, abyRollMsg, min( MAX_ROLLMSG_LEN, wRollMsgLen ) );
		}
		memcpy( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET, ptMtList, wDstMtNum * sizeof( TMTLABEL ) );

		// �ܵ���Ϣ����
		u16 wMsgLen = wRollMsgLen + wDstMtNum * sizeof( TMTLABEL ) + ROLLMSG_MSGHEAD_LEN;
		wMsgLen = htons( wMsgLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET, &wMsgLen,
				ROLLMSG_MSGHEAD_MSGLEN_LEN );

		// �ն��б���
		wDstMtNum = htons( wDstMtNum );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_DSTMTNUM_OFFSET, &wDstMtNum,
			ROLLMSG_MSGHEAD_DSTMTNUM_LEN );


	}

	/*
	====================================================================
	����        ����ǰ�ն��б�������һ���ն�
	�������˵����<mcu,mt>
	����ֵ˵��  ����
	====================================================================
	*/
	void AddDstMt( u8 byMcuNo, u8 byMtNo )
	{
		TMTLABEL tMt;
		tMt.SetMtLabel( byMcuNo, byMtNo );
		AddDstMt( tMt );
	}
	/*
	====================================================================
	����        ����ǰ�ն��б�������һ���ն�
	�������˵����TMTLABEL
	����ֵ˵��  ����
	====================================================================
	*/
	void AddDstMt( TMTLABEL tMt )
	{
		// ��ǰ�ն��б���
		u16 wDstMtNum = GetDstMtNum();
		// ������Ϣ����
		u16 wRollMsgLen = GetRollMsgContentLen();

		// �ܵ���Ϣ����
		u16 wMsgLen = wRollMsgLen + ( wDstMtNum + 1 )* sizeof( TMTLABEL ) + ROLLMSG_MSGHEAD_LEN;
		wMsgLen = htons( wMsgLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET, &wMsgLen,
			ROLLMSG_MSGHEAD_MSGLEN_LEN );

		// �����ն�
		u16 wOffSet = ROLLMSG_MSGBODY_OFFSET + wDstMtNum * sizeof( TMTLABEL );
		memmove( m_abyBuffer + wOffSet + sizeof( TMTLABEL ),
				m_abyBuffer + wOffSet,
				min( sizeof( m_abyBuffer ) - wOffSet - sizeof( TMTLABEL ), wRollMsgLen ) );
		*( m_abyBuffer + wOffSet ) = tMt.GetMcuNo();
		*( m_abyBuffer + wOffSet + 1 ) = tMt.GetMtNo();

		// �ն��б���
		wDstMtNum = htons( wDstMtNum + 1 );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_DSTMTNUM_OFFSET, &wDstMtNum,
			ROLLMSG_MSGHEAD_DSTMTNUM_LEN );


	}

	/*
	====================================================================
	����        ����ȡ��ǰĿ���ն��б���ָ��
	�������˵������
	����ֵ˵��  ��ָ��TMTLABEL��ָ��
	====================================================================
	*/
	TMTLABEL *GetDstMtList( void ) { return ( TMTLABEL* )( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET ); }

	/*
	====================================================================
	����        ����ȡ��һ��Ŀ���ն�
	�������˵����TMTLABEL*
	����ֵ˵��  ����ȷ����0,����-1;
	====================================================================
	*/
	int GetFirstDstMt( TMTLABEL *ptMt = NULL ) 
	{
		if ( ptMt == NULL )
			return -1;

		if ( GetDstMtNum() != 0 )
		{
			ptMt->SetMtLabel( *( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET ),
							*( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET + 1 ) );
		}

		return 0;
	}

	/*
	====================================================================
	����        ����ȡ��һ��Ŀ���ն��б�
	�������˵������ǰ�ն����� + TMTLABEL*
	����ֵ˵��  ����ȷ������һ��Ŀ���ն�����,����-1
	====================================================================
	*/
	int GetNextDstMt( u16 wIndex, TMTLABEL *ptMt = NULL )
	{
		if ( ptMt == NULL || wIndex >= ( GetDstMtNum() - 1 ) )
			return -1;

		u16 wOffSet = ROLLMSG_MSGBODY_OFFSET + ( wIndex + 1 ) * sizeof( TMTLABEL );
		ptMt->SetMtLabel( *( m_abyBuffer + wOffSet ),
						  *( m_abyBuffer + wOffSet + 1 ) );

		return ( wIndex + 1 );
	}


	/*
	====================================================================
	����        ����ȡ������Ϣ���ݳ���
	�������˵������
	����ֵ˵��  ������
	====================================================================
	*/
	u16 GetRollMsgContentLen( void )
	{
		u16 wMsgLen = 0;
		memcpy( &wMsgLen, m_abyBuffer + ROLLMSG_MSGHEAD_ROLLMSGLEN_OFFSET,
				ROLLMSG_MSGHEAD_ROLLMSGLEN_LEN );
		return ntohs( wMsgLen );
	}

	/*
	====================================================================
	����        �����ù�����Ϣ����
	�������˵������Ϣ���� + ���ݳ���
	����ֵ˵��  ����
	====================================================================
	*/
	void SetRollMsgContent( const u8* pbyRollMsgContent = NULL, u16 wRollMsgLen = 0 )
	{
		if ( pbyRollMsgContent == NULL || wRollMsgLen == 0 )
			return;

		// �ն��б�
		u16 wDstMtNum = GetDstMtNum();
		memcpy( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET + wDstMtNum * sizeof( TMTLABEL ),
				pbyRollMsgContent, wRollMsgLen );

		// �ܵ���Ϣ����
		u16 wMsgLen = wRollMsgLen + wDstMtNum * sizeof( TMTLABEL ) + ROLLMSG_MSGHEAD_LEN;
		wMsgLen = htons( wMsgLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET, &wMsgLen,
			ROLLMSG_MSGHEAD_MSGLEN_LEN );

		// ������Ϣ����
		wRollMsgLen = htons( wRollMsgLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_ROLLMSGLEN_OFFSET, &wRollMsgLen,
				ROLLMSG_MSGHEAD_ROLLMSGLEN_LEN );
	}

	/*
	====================================================================
	����        ����ȡ��ǰ������Ϣ������ָ��
	�������˵������
	����ֵ˵��  ����ָ��
	====================================================================
	*/
	u8* GetRollMsgContent( void ) 
	{
		u16 wDstMtNum = GetDstMtNum();
		return ( m_abyBuffer + ROLLMSG_MSGBODY_OFFSET + wDstMtNum * sizeof( TMTLABEL ) ); 
	}

	/*
	====================================================================
	����        ����ȡ�����ṹ��ʵ�ʳ���
	�������˵������
	����ֵ˵��  ������
	====================================================================
	*/
	u16 GetTotalMsgLen( void ) 
	{ 
		u16 wMsgLen = 0;
		memcpy( &wMsgLen, m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET,
				ROLLMSG_MSGHEAD_MSGLEN_LEN );

		return ntohs( wMsgLen ); 
	} 

	/*
	====================================================================
	����        �����õ�ǰ�ṹ
	�������˵������������ָ�� + ����������
	����ֵ˵��  ����ȷ���
	====================================================================
	*/
	BOOL SetRollMsg( const u8 *pbyMsg, u16 wMsgLen )
	{
		if ( wMsgLen < ROLLMSG_MSGHEAD_LEN )
			return FALSE;

		wMsgLen = min( wMsgLen, sizeof( m_abyBuffer ) );
		memcpy( m_abyBuffer, pbyMsg, wMsgLen );

		if ( GetTotalMsgLen() > sizeof( m_abyBuffer ) )
			return FALSE;


		return TRUE;
	}

	/*
	====================================================================
	����        ����ȡ����Buffer��ͷָ��
	�������˵������
	����ֵ˵��  ����
	====================================================================
	*/
	u8 *GetRollMsg( void ) { return m_abyBuffer; }


	/*
	====================================================================
	����        �����õ�ǰ�ṹ
	�������˵������
	����ֵ˵��  ����
	====================================================================
	*/
	void Reset( void ) 
	{
		memset( m_abyBuffer, 0, sizeof( m_abyBuffer ) );
		u16 wLen = ROLLMSG_MSGHEAD_LEN;
		wLen = htons( wLen );
		memcpy( m_abyBuffer + ROLLMSG_MSGHEAD_MSGLEN_OFFSET,
			    &wLen, ROLLMSG_MSGHEAD_MSGLEN_LEN );
	}


private :
	u8	m_abyBuffer[ 0x1000 ];			// buff
};

// ���󷽰�����
//////////////////////////////////////////////////////////////////////////
// ��������
/*#define MAX_SCHEMENAME_LEN	32	
// ��������
#define MATRIX_AUDIO	1	// ��Ƶ����
#define MATRIX_VIDEO	2	// ��Ƶ����
#define MATRIX_AV		3	// ��������

// ���󷽰��ṹ
typedef struct tagMatrixScheme
{
	// ���úͻ�ȡ��������
	void SetType( u8 byMatrixType )
	{
		if ( byMatrixType != MATRIX_VIDEO 
			&& byMatrixType != MATRIX_AUDIO
			&& byMatrixType != MATRIX_AV )
			byMatrixType = MATRIX_VIDEO;
		byType = byMatrixType;
	}

	u8 GetType( void ) { return byType; }

	// ���úͻ�ȡ����ID
	void SetIndex( u8 bySchemeId ) { byIndex = bySchemeId; }
	u8 GetIndex( void ) { return byIndex; }

	// ���úͻ�ȡ��Ƶ���󷽰�����
	void SetVideoName( const s8* pchSchemeName, u32 dwLen )
	{
		if ( pchSchemeName == NULL || dwLen == 0 )
			return;

		if ( dwLen > MAX_SCHEMENAME_LEN )
			dwLen = MAX_SCHEMENAME_LEN;

		memset( achVideoName, 0, sizeof( achVideoName ) );
		strncpy( achVideoName, pchSchemeName, dwLen );
		achVideoName[ MAX_SCHEMENAME_LEN ] = '\0';
	}
	
	void GetVideoName( s8* pchSchemeName, u32 dwLen )
	{
		if ( pchSchemeName == NULL || dwLen == 0 )
			return;
		memset( pchSchemeName, 0, dwLen );
		strncpy( pchSchemeName, achVideoName, dwLen );
		pchSchemeName[ dwLen - 1 ] = '\0';

	}

	// ���úͻ�ȡ��Ƶ���󷽰�����
	void SetAudioName( const s8* pchSchemeName, u32 dwLen )
	{
		if ( pchSchemeName == NULL || dwLen == 0 )
			return;

		if ( dwLen > MAX_SCHEMENAME_LEN )
			dwLen = MAX_SCHEMENAME_LEN;

		memset( achAudioName, 0, sizeof( achAudioName ) );
		strncpy( achAudioName, pchSchemeName, dwLen );
		achAudioName[ MAX_SCHEMENAME_LEN ] = '\0';
	}

	void GetAudioName( s8* pchSchemeName, u32 dwLen )
	{
		if ( pchSchemeName == NULL || dwLen == 0 )
			return;
		memset( pchSchemeName, 0, dwLen );
		strncpy( pchSchemeName, achAudioName, dwLen );
		pchSchemeName[ dwLen - 1 ] = '\0';

	}

	void Reset( void ) 
	{
		byType = MATRIX_VIDEO;
		byIndex = 0xFF;
		memset( achVideoName, 0, sizeof( achVideoName ) );
		memset( achAudioName, 0, sizeof( achAudioName ) );
	}

	tagMatrixScheme() : byType( MATRIX_VIDEO ), byIndex(0xFF)
	{
		memset( achVideoName, 0, sizeof( achVideoName ) );
		memset( achAudioName, 0, sizeof( achAudioName ) );
	}

private :
	u8 byType;									// ��������(��Ƶ,��Ƶ,����Ƶ����)
	u8 byIndex;									// ����ID,��ǰ��8��(0~7)
	s8 achVideoName[ MAX_SCHEMENAME_LEN + 1 ];	// ��Ƶ���󷽰�����
	s8 achAudioName[ MAX_SCHEMENAME_LEN + 1 ];	// ��Ƶ���󷽰�����
}PACKED TMATRIXSCHEME;


/************************************************************************/
/*     ��������                                                         */
/************************************************************************/
/*#define MAXLEN_MATRIX_MODEL_NAME     16
#define MAXNUM_MATRIXPORT            64
#define MAXLEN_MATRIXPORTNAME        16
#define MAXLEN_MATRIXSCHEMENAME      16
	  
	  
	  
//��������
typedef struct tagITMatrixCfg
{   
protected:
	s8 m_abyModel[MAXLEN_MATRIX_MODEL_NAME+1]; //�����ͺ�
    u8 m_byInPortNum;   //����˿���
    u8 m_byOutPortNum; //����˿���
    u8 m_byCtrlType;   //�������� 0=RS232 1=RS485 2=RS422 3=tcpip
	u32 m_dwIP;
	u16 m_wPort;
public:
	//��ȡ�����ͺ�
	void GetModel( s8 abyModel[] ,u16 wLen)
	{
		strncpy( abyModel ,m_abyModel ,min(wLen ,MAXLEN_MATRIX_MODEL_NAME));
		abyModel[min(wLen ,MAXLEN_MATRIX_MODEL_NAME)]=0;
	}
	//���þ����ͺ�
	void SetModel( s8 abyModel[])
	{
		strncpy( m_abyModel ,abyModel ,MAXLEN_MATRIX_MODEL_NAME);
		m_abyModel[MAXLEN_MATRIX_MODEL_NAME]=0;
	}

	//��ȡ��������˿���
	u8 GetInPortNum()	{return m_byInPortNum;	}
	//���þ�������˿���
	void SetInPortNum(u8 byPortNum ){ m_byInPortNum = byPortNum;	}

	//��ȡ��������˿���
	u8 GetOutPortNum()	{return m_byOutPortNum;	}
	//���þ�������˿���
	void SetOutPortNum(u8 byPortNum ){ m_byOutPortNum = byPortNum;	}

	//��ȡ������Ʒ�ʽ
	u8 GetCtrlType()	{return m_byCtrlType;	}
	//���þ�����Ʒ�ʽ
	void SetCtrlType(u8 byType ){ m_byCtrlType = byType;	}

	//��ȡTCP/IP�����ַ
	void GetIPAddr( u32& dwIP ,u16& wPort)
	{
		dwIP = m_dwIP;
		wPort = ntohs(m_wPort);
	}
	//����TCP/IP�����ַ
	void GetIPAddr( u32 dwIP ,u16 wPort)
	{
		m_dwIP = dwIP ;
		m_wPort = htons(wPort);
	}


}PACKED ITMatrixCfg;

//���󷽰�


struct ITMatrixScheme
{
protected:
	u8            m_byType;     //��������    0=�ڲ� 1=�ⲿ
	s8            m_abyName[MAXLEN_MATRIXSCHEMENAME];    //������
	u8            m_byIndex;                                   //��������
	u8            m_byInPortNum;//����˿ڸ���
	u8            m_byOutPortNum;//����˿ڸ���
	u8            m_abyPorts[MAXNUM_MATRIXPORT];//��������˿����ӵ�����˿�
                                                       //����˿�����Ϊ����˿���
	s8            m_abyPortName[MAXNUM_MATRIXPORT][MAXLEN_MATRIXPORTNAME+1];
public:
	//��ȡ��������
	u8 GettType(){ return m_byType;	}
	//���þ�������
	void SetType(u8 byType){ m_byType =byType ;	}

	//��ȡ��������
	u8 GetIndex(){return m_byIndex;	}
	void SetIndex(u8 byIndex){ m_byIndex = byIndex;	}

	//��ȡ��������˿���
	u8 GetInPortNum()	{return m_byInPortNum;	}
	//���þ�������˿���
	void SetInPortNum(u8 byPortNum ){ m_byInPortNum = byPortNum;	}

	//��ȡ��������˿���
	u8 GetOutPortNum()	{return m_byOutPortNum;	}
	//���þ�������˿���
	void SetOutPortNum(u8 byPortNum ){ m_byOutPortNum = byPortNum;	}

	//���þ������ӹ�ϵ
	BOOL SetConnection(u8 byInPort ,u8 byOutPort )
	{ 
		if( byOutPort > MAXNUM_MATRIXPORT )
			return FALSE;
		m_abyPorts[byOutPort ] = byInPort;
	}
	//��ȡ�������ӹ�ϵ
	u8 GetConnection(u8 byOutPort )
	{ 
		if( byOutPort > MAXNUM_MATRIXPORT )
			return 0;
		return m_abyPorts[byOutPort ];
	}

	//��ȡָ������˿�����
	BOOL GetInPortName( u8 byIndex ,s8 abyName[] ,u16 wLen )
	{
		if( byIndex > m_byInPortNum || byIndex >MAXNUM_MATRIXPORT )
		{
			memset(abyName ,0,wLen );
			return FALSE;
		}
		
		strncpy( abyName ,m_abyPortName[byIndex] ,min(wLen ,MAXLEN_MATRIXPORTNAME));
		abyName[min(wLen ,MAXLEN_MATRIXPORTNAME)]=0;
		return TRUE;
	}

	//����ָ������˿�����
	BOOL SetInPortName( u8 byIndex ,s8 abyName[] )
	{
		if( byIndex > m_byOutPortNum ||	byIndex >MAXNUM_MATRIXPORT)
		{
			return FALSE;
		}
		
		strncpy(m_abyPortName[byIndex] , abyName ,MAXLEN_MATRIXPORTNAME);
		m_abyPortName[byIndex][MAXLEN_MATRIXPORTNAME]=0;
		return TRUE;
	}


	//��ȡָ������˿�����
	BOOL GetOutPortName( u8 byIndex ,s8 abyName[] ,u16 wLen )
	{
		if( byIndex > m_byOutPortNum || 
			byIndex >MAXNUM_MATRIXPORT ||
			byIndex+m_byInPortNum >MAXNUM_MATRIXPORT)
		{
			memset(abyName ,0,wLen );
			return FALSE;
		}
		
		strncpy( abyName ,m_abyPortName[byIndex+m_byInPortNum] ,min(wLen ,MAXLEN_MATRIXPORTNAME));
		abyName[min(wLen ,MAXLEN_MATRIXPORTNAME)]=0;
		return TRUE;
	}

	//����ָ������˿�����
	BOOL SetOutPortName( u8 byIndex ,s8 abyName[] )
	{
		if( byIndex > m_byOutPortNum || 
			byIndex >MAXNUM_MATRIXPORT||
			byIndex+m_byInPortNum > MAXNUM_MATRIXPORT)
		{
			return FALSE;
		}
		
		strncpy(m_abyPortName[byIndex+m_byInPortNum] , abyName ,MAXLEN_MATRIXPORTNAME);
		m_abyPortName[byIndex+m_byInPortNum][MAXLEN_MATRIXPORTNAME]=0;
		return TRUE;
	}


};*/
// �ն˵�ַ��Ϣ

// ��ַ����
#define		ADDR_TYPE_IP		1
#define		ADDR_TYPE_ALIAS		2

// ��������
#define		ALIAS_H323ID		1
#define		ALIAS_E164			2
#define		ALIAS_EMAIL			3

typedef struct tagTerminalAddr
{
public :
	u8 GetAddrType( void ) { return byAddrType; }
	void SetAddrType( u8 byType ) { byAddrType = byType; }

	void SetIpAddr( u32 ip, u16 port )
	{
		dwIp = ip;
		wPort = htons( port );
	}
	u32 GetIpAddr( void ) { return dwIp; }
	u16 GetIpPort( void ) { return ntohs( wPort ); }

	u8 GetAliasType( void ) { return byAliasType; }
	s8* GetAliasName( void ) { return achAlias; }
	BOOL SetAlias( u8 byType, const s8* pchName, u8 byNameLen ) 
	{ 
		if ( pchName == NULL || byNameLen == 0 )
			return FALSE;

		byAliasType = byType; 
		memset( achAlias, 0, sizeof( achAlias ) );
		u8 byLen = min( byNameLen, VALIDLEN_ALIAS );
		memcpy( achAlias, pchName, byLen );
		achAlias[byLen] = '\0';
		return TRUE;
	}

	tagTerminalAddr() 
	{
		memset( this, 0, sizeof( tagTerminalAddr ) );
	}

	void Reset( void )
	{
		memset( this, 0, sizeof( tagTerminalAddr ) );
	}
	
private :
	u8	byAddrType;		// ��ַ����
	u32 dwIp;			// IP(������)
	u16	wPort;			// �˿ں�
	u8	byAliasType;	// ��������
	s8 achAlias[ VALIDLEN_ALIAS + 1 ];
}PACKED TTERADDR,*PTTERADDR;





//��ƵЭ������
#define VIDEO_FORMAT_H261      0
#define VIDEO_FORMAT_H262      1//MPEG2
#define VIDEO_FORMAT_H263      2
#define VIDEO_FORMAT_H263plus  3
#define VIDEO_FORMAT_H264      4
#define VIDEO_FORMAT_MPEG4     5


//��ƵЭ��
#define AUTIO_FORMAT_G711a   0
#define AUTIO_FORMAT_G711u   1
#define AUTIO_FORMAT_G722    2
#define AUTIO_FORMAT_G7231   3
#define AUTIO_FORMAT_G728    4
#define AUTIO_FORMAT_G729    5
#define AUTIO_FORMAT_MP3     6



//��Ƶ�ֱ��ʷֱ�������
#define   VIDEO_RES_AUTO     0
#define   VIDEO_RES_VQCIF    1
#define   VIDEO_RES_VCIF     2
#define   VIDEO_RES_2CIF     3
#define   VIDEO_RES_4CIF     4
#define   VIDEO_RES_16CIF    5


//�ն���ƵԴ
#define		VIDEO_SRC_S				0		//S����
#define 	VIDEO_SRC_VGA			7		//VGA

//�ն�����(��mcu���������ȡ)
typedef struct tagTerBitrate
{
protected:
    u16		m_awSendBitRate[2];			    //��Ƶ��������(��λ:kbps)
    u16		m_awRecvBitRate[2];			    //��Ƶ��������(��λ:kbps)
    u16		m_awSendAVBitRate[2];			//ƽ����������(��λ:kbps)    
    u16		m_awRecvAVBitRate[2];			//ƽ����������(��λ:kbps)

public:

    //��ȡ��������
    void    GetSendBitRate(u16 &wPrimo, u16 &wSecond )
    {  
        wPrimo  = ntohs(m_awSendBitRate[0]);
        wSecond = ntohs(m_awSendBitRate[1]);
    }
    
    //���÷�������
    void    SetSendBitRate(u16 wPrimo, u16 wSecond )
    {  
        m_awSendBitRate[0] = htons(wPrimo);
        m_awSendBitRate[1] = htons(wSecond);
    }
    
    //��ȡƽ����������
    void    GetSendAverageBitRate(u16 &wPrimo, u16 &wSecond )
    {  
        wPrimo  = ntohs(m_awSendAVBitRate[0]);
        wSecond = ntohs(m_awSendAVBitRate[1]);
    }
    
    //����ƽ����������
    void    SetSendAverageBitRate(u16 wPrimo, u16 wSecond )
    {  
        m_awSendAVBitRate[0] = htons(wPrimo);
        m_awSendAVBitRate[1] = htons(wSecond);
    }
    
    //��ȡ��������
    void    GetRecvBitRate(u16 &wPrimo, u16 &wSecond )
    {  
        wPrimo  = ntohs(m_awRecvBitRate[0]);
        wSecond = ntohs(m_awRecvBitRate[1]);
    }
    
    //���ý�������
    void    SetRecvBitRate(u16 wPrimo, u16 wSecond )
    {  
        m_awRecvBitRate[0] = htons(wPrimo);
        m_awRecvBitRate[1] = htons(wSecond);
    }
    
    //��ȡƽ����������
    void    GetRecvAverageBitRate(u16 &wPrimo, u16 &wSecond )
    {  
        wPrimo  = ntohs(m_awRecvAVBitRate[0]);
        wSecond = ntohs(m_awRecvAVBitRate[1]);
    }
    
    //����ƽ����������
    void    SetRecvAverageBitRate(u16 wPrimo, u16 wSecond )
    {  
        m_awRecvAVBitRate[0] = htons(wPrimo);
        m_awRecvAVBitRate[1] = htons(wSecond);
    }

}PACKED _TTERBITRATE;

//�ն�״̬(�����仯ʱ�ն������ϱ�)
typedef struct tagTerStatus
{
protected:		
	///////����״̬///////
    // guzh [3/7/2007] ���ֶδ�4.0R4��ʼȡ��������Ϊһ��8bit״̬����
	// u8		m_byPollStat;					//��ѯ״̬		(PollStatus)

    ///////�豸״̬///////
#ifndef SETBITSTATUS
#define SETBITSTATUS(StatusValue, StatusMask, bStatus)   if (bStatus) StatusValue |= StatusMask;   else StatusValue &= ~StatusMask;
#define GETBITSTATUS(StatusValue, StatusMask) (0 != (StatusValue&StatusMask))
#endif
    enum TTerStatusMask
    {
        Mask_VidLose    =   0x01            //�Ƿ���ƵԴ��ʧ�ź�
    };

    u8      m_byCommStatus;                 //�ն�״̬����
	
	u8		m_byMtBoardType;				//�ն˰忨����	MT_BOARD_WIN, MT_BOARD_8010, ...
	u8		m_byMatrixStatus;				//����״̬		(1 ok 0 err)
	u8		m_byVideoSrc;				    //��ǰ������ƵԴ(0:S����,1-6:C����)
	u8		m_bRemoteCtrl;				    //�Ƿ�����Զң	1 yes 0 no	
			
	u8		m_byEncVol;					    //��ǰ��������(��λ:�ȼ�)
    u8		m_byDecVol;					    //��ǰ��������(��λ:�ȼ�)
	u8		m_bMute;						//�Ƿ�����	1 yes 0 no	
	u8		m_bQuiet;						//�Ƿ���	1 yes 0 no
    u8      m_byExVideoSourceNum;           //�ն���չ��ƵԴ 0��ʾû��
public:
    // ��ƵԴ��ʧ
    BOOL    IsVideoLose() const {return GETBITSTATUS(m_byCommStatus, Mask_VidLose); }
    void    SetVideoLose(BOOL bIsVideoLose) { SETBITSTATUS(m_byCommStatus, Mask_VidLose, bIsVideoLose)  }    
	
	// ��ȡ�ն�����(�궨��)
	u8      GetBoardType() const {return m_byMtBoardType;	}
	void    SetBoardType(u8 byType){ m_byMtBoardType = byType;	}

	//�ⲿ�����Ƿ�����   (1 ok 0 err)
	u8    GetMatrixStatus() const { return m_byMatrixStatus;	}
	void    SetMatrixStatus(u8 byStatus ) { m_byMatrixStatus = byStatus;	}
	
	// ��ȡ��Ƶ
	u8      GetVideoSrc() const	{ return m_byVideoSrc;	}
	void    SetVideoSrc( u8 bySrc ){ m_byVideoSrc = bySrc;	}

	//�Ƿ�����Զҡ
	BOOL    IsRemoteCtrlEnalbe() const {return  (0 != m_bRemoteCtrl);	}
    void    SetRemoteCtrlEnalbe( BOOL bEnable) { m_bRemoteCtrl = bEnable ? 1:0;	}
		
	//��ȡ��������
	u8  GetInputVolume() const {return m_byEncVol;}
	void  SetInputVolume(u8 byInputVolume){  m_byEncVol = byInputVolume;}

	//��ȡ�������
	u8  GetOutputVolume() const {return m_byDecVol;}
	void  SetOutputVolume(u8 byOutputVolume){  m_byDecVol = byOutputVolume;}

    //�Ƿ�����
	BOOL IsMute() const {return (0 != m_bMute);}
	void SetMute(BOOL bMute ){ m_bMute = bMute ? 1:0;}
	
	//�Ƿ���
	BOOL IsQuiet() const {return (0 != m_bQuiet);}
	void SetQuiet(BOOL bQuiet ){ m_bQuiet = bQuiet ? 1:0;}

	//��չ��ƵԴ
	u8   GetExVidSrcNum() const { return m_byExVideoSourceNum;	}
	void SetExVidSrcNum(u8 byNum) { m_byExVideoSourceNum = byNum ;}
	
}PACKED _TTERSTATUS;

#define MAXLEN_MATRIXPORTNAME        16
#define MAX_SCHEMENAME_LEN	32
#define MAXNUM_INNERMATRIXPORT 6
typedef struct tagITInnerMatrixScheme
{
		s8 achName[ MAX_SCHEMENAME_LEN + 1 ]; //������
		u8 byIndex; //��������
		//
		// ����˿ں�( 1 - 6 )
		// ��������˿����ӵ�����˿�
		//
		u8 abyOutPort2InPort[ MAXNUM_INNERMATRIXPORT ]; //����˿ڶ�Ӧ������˿�
		                           //ע: abyOutPort2InPort[]=0 ��ʾָ���˿������һ·��Ƶ
		                           //    abyOutPort2InPort[]=7 ��ʾָ���˿�����ڶ�·��Ƶ
		                           //    abyOutPort2InPort[]=1~6 ��ʾָ���˿������Ӧ��C1��6

		//
		// �˿�( 1- 6 )����
		//
		s8 achOutPortName[MAXNUM_INNERMATRIXPORT][ MAX_SCHEMENAME_LEN + 1 ];
		s8 achInPortName [MAXNUM_INNERMATRIXPORT][ MAX_SCHEMENAME_LEN + 1 ];
}PACKED ITInnerMatrixScheme;

#define EX_VIDEOSOURCE_BASE     10    //��չ��ƵԴ��ֵ

typedef struct tagITVideoSourceInfo
{
protected:
	u8 m_byIndex;
	s8 m_achName[MAXLEN_MATRIXPORTNAME+1];
public:
	u8  GetIndex(){ return m_byIndex;	}
	void  SetIndex(u8 byIndex){ m_byIndex = byIndex;	}

	void SetName( s8* achName)
	{ 
		strncpy( m_achName ,achName ,sizeof(m_achName));
		m_achName[sizeof(m_achName)-1]=0;
	}

	void GetName( s8* achName ,u16 wSize)
	{ 
		strncpy( achName,m_achName ,wSize);
		achName[wSize-1]=0;
	}

}PACKED ITVideoSourceInfo;



//�����MCU���ն˻�����ṹ (len:6)
struct TMt
{

protected:
    u8          m_byMainType;   //�豸����
    u8  		m_bySubType;	//�豸����
	u8  		m_byMcuId;		//MCU��
	u8  		m_byEqpId;	    //�豸��	
	u8          m_byConfDriId;  //DRI���
    u8          m_byConfIdx;    //���������ţ�������ʵ���� 1 - MAXNUM_MCU_CONF

public:
	//�����������ͺ���
	void   SetType( u8   byType ){ m_byMainType = byType; }         //���ýṹ����
	u8     GetType( void ) const { return m_byMainType; }           //�õ��ṹ����
	void   SetMcuId( u8   byMcuId ){ m_byMcuId = byMcuId; }         //����McuId
	u8     GetMcuId( void ) const { return m_byMcuId; }             //�õ�McuId
	BOOL   operator ==( const TMt & tObj ) const;                  //�ж��Ƿ����

	//����MCU����
	void   SetMcu( u8   byMcuId );                         //����MCU
	void   SetMcuType( u8  byMcuType ){ m_byMainType = TYPE_MCU; m_bySubType = byMcuType; }
	u8     GetMcuType( void ) const { return m_bySubType; }

	//�������躯��
	void   SetMcuEqp( u8   byMcuId, u8   byEqpId, u8   byEqpType );            //����MCU����
	void   SetEqpType( u8   byEqpType ){ m_byMainType = TYPE_MCUPERI; m_bySubType = byEqpType; }                                       //����MCU��������
	u8     GetEqpType( void ) const { return m_bySubType; }
	void   SetEqpId( u8   byEqpId ){ m_byMainType = TYPE_MCUPERI; m_byEqpId = byEqpId; }
	u8     GetEqpId( void ) const { return m_byEqpId; }
	
	//�����ն˺���
	void   SetMt( u8   byMcuId, u8   byMtId, u8   m_byDriId = 0, u8   m_byConfIdx = 0);
	void   SetMt( TMt tMt);
	void   SetMtId( u8   byMtId ){ m_byMainType = TYPE_MT; m_byEqpId = byMtId; }
	u8     GetMtId( void ) const { return m_byEqpId; }//�����ն�
	void   SetMtType( u8   byMtType ) { m_byMainType = TYPE_MT; m_bySubType = byMtType; }
	u8     GetMtType( void ) const { return m_bySubType; }  	
    void   SetDriId(u8   byDriId){ m_byConfDriId = byDriId; }
    u8     GetDriId( void ) const { return m_byConfDriId; }
    void   SetConfIdx(u8   byConfIdx){ m_byConfIdx = byConfIdx; } 
    u8     GetConfIdx( void ) const { return m_byConfIdx; }
	void   SetNull( void ){ m_byMcuId = 0; m_byEqpId = 0; m_byConfDriId = 0; }
	BOOL   IsNull ( void ) const{ return m_byMcuId == 0 && m_byEqpId == 0; }
	BOOL   IsLocal() const {	return (m_byMcuId == LOCAL_MCUID );	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//�����ն˽ṹ
typedef TMt TEqp;

//�ն���ѯ���� (len:12)
struct TMtPollParam: public TMt
{
protected:
	u16   m_wKeepTime;        //�ն���ѯ�ı���ʱ�� ��λ:��(s)
    u32   m_dwPollNum;        //�ն���ѯ�Ĵ���
public:
	void  SetKeepTime(u16 wKeepTime) { m_wKeepTime = htons(wKeepTime); } 
	u16   GetKeepTime(void) const { return ntohs(m_wKeepTime); }
    void  SetPollNum(u32 dwPollNum) { m_dwPollNum = htonl(dwPollNum); } 
	u32   GetPollNum(void) const { return ntohl(m_dwPollNum); }
	TMt   GetTMt(void) const { return *(TMt *)this; }
	void  SetTMt(TMt tMt) { memcpy( this, &tMt, sizeof(tMt) ); }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//���廭��ϳɳ�Ա�ṹ (len:8)
struct TVMPMember: public TMt
{
protected:
    u8   m_byMemberType;     //����ϳɳ�Ա����,�μ�vccommon.h�л���ϳɳ�Ա���Ͷ���
    u8   m_byMemStatus;      //��Ա״̬(MT_STATUS_CHAIRMAN, MT_STATUS_SPEAKER, MT_STATUS_AUDIENCE)

public:
    void  SetMemberType(u8   byMemberType){ m_byMemberType = byMemberType;} 
    u8    GetMemberType( void ) const { return m_byMemberType; }
    void  SetMemStatus(u8 byStatus) { m_byMemStatus = byStatus; }
    u8    GetMemStatus(void) const { return m_byMemStatus; }
    void  SetMemberTMt( TMt tMt ){ memcpy( this, &tMt, sizeof(TMt) ); }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//���廭��ϳɲ����ṹ (len:136 + 4*8 = 168)
struct TVMPParam
{
protected:
	u8      m_byVMPAuto;      //�Ƿ����Զ�����ϳ� 0-�� 1-��
	u8      m_byVMPBrdst;     //�ϳ�ͼ���Ƿ����ն˹㲥 0-�� 1-�� 
	u8      m_byVMPStyle;     //����ϳɷ��,�μ�mcuconst.h�л���ϳɷ����
    u8      m_byVMPSchemeId;  //�ϳɷ�񷽰����,���֧��5�׷���,1-5
    u8      m_byVMPMode;      //ͼ�񸴺Ϸ�ʽ: 0-��ͼ�񸴺� 1-��ػ���ϯ����ͼ�񸴺� 2-�Զ�ͼ�񸴺�(��̬���������ó�Ա)
	u8		m_byRimEnabled;	  //�Ƿ�ʹ�ñ߿�: 0-��ʹ��(Ĭ��) 1-ʹ��;
							  //���ֶ�Ŀǰֻ�Է���0��Ч, ���������ݲ��漰���ֶε����ú��ж�
	//u8		m_byReserved1;	  //�����ֶ�
	//u8		m_byReserved2;	  //�����ֶ�
	u8		m_byVMPBatchPoll; // xliang [12/18/2008] �Ƿ���������ѯ 0-��
	u8		m_byVMPSeeByChairman;	// �Ƿ���ϯMTѡ��	0-��
	TVMPMember  m_atVMPMember[MAXNUM_MPUSVMP_MEMBER]; //����ϳɳ�Ա
public:
    void   SetVMPAuto(u8   byVMPAuto){ m_byVMPAuto = byVMPAuto;} 
    BOOL   IsVMPAuto( void ) const { return m_byVMPAuto == 0 ? FALSE : TRUE; }
    void   SetVMPBrdst(u8   byVMPBrdst){ m_byVMPBrdst = byVMPBrdst;} 
    BOOL   IsVMPBrdst( void ) const { return m_byVMPBrdst == 0 ? FALSE : TRUE; }
    void   SetVMPStyle(u8   byVMPStyle){ m_byVMPStyle = byVMPStyle;} 
    u8     GetVMPStyle( void ) const { return m_byVMPStyle; }
    void   SetVMPSchemeId(u8 bySchemeId) { m_byVMPSchemeId = bySchemeId; }
    u8     GetVMPSchemeId(void) const { return m_byVMPSchemeId; }
    void   SetVMPMode(u8   byVMPMode){ m_byVMPMode = byVMPMode;} 
    u8     GetVMPMode( void ) const { return m_byVMPMode; }
	void   SetIsRimEnabled(u8 byEnabled){ m_byRimEnabled = byEnabled; }
	BOOL32 GetIsRimEnabled(void) const { return m_byRimEnabled == 1 ? TRUE : FALSE; }
	void	SetVMPBatchPoll(u8 byVMPBatchPoll){m_byVMPBatchPoll = byVMPBatchPoll;} // xliang [12/22/2008] 
	BOOL	IsVMPBatchPoll( void ) const { return m_byVMPBatchPoll == 0 ? FALSE : TRUE;}
	void	SetVMPSeeByChairman(u8 byVMPSeeByMt) { m_byVMPSeeByChairman = byVMPSeeByMt;}
	BOOL	IsVMPSeeByChairman( void ) const {  return m_byVMPSeeByChairman == 0 ? FALSE : TRUE; }
    u8     GetMaxMemberNum( void ) const 
	{
		u8   byMaxMemNum = 1;

		switch( m_byVMPStyle ) 
		{
		case VMP_STYLE_ONE:
			byMaxMemNum = 1;
			break;
		case VMP_STYLE_VTWO:
		case VMP_STYLE_HTWO:
			byMaxMemNum = 2;
			break;
		case VMP_STYLE_THREE:
			byMaxMemNum = 3;
			break;
		case VMP_STYLE_FOUR:
			byMaxMemNum = 4;
			break;
		case VMP_STYLE_SIX:
			byMaxMemNum = 6;
			break;
		case VMP_STYLE_EIGHT:
			byMaxMemNum = 8;
			break;
		case VMP_STYLE_NINE:
			byMaxMemNum = 9;
			break;
		case VMP_STYLE_TEN:
			byMaxMemNum = 10;
			break;
		case VMP_STYLE_THIRTEEN:
			byMaxMemNum = 13;
			break;
		case VMP_STYLE_SIXTEEN:
			byMaxMemNum = 16;
			break;
		case VMP_STYLE_SPECFOUR:
			byMaxMemNum = 4;
			break;
		case VMP_STYLE_SEVEN:
			byMaxMemNum = 7;
			break;
		case VMP_STYLE_TWENTY:
			byMaxMemNum = 20;
			break;
		default:
			byMaxMemNum = 1;
			break;
		}
		return byMaxMemNum;
	}
	void   SetVmpMember( u8   byMemberId, TVMPMember tVMPMember )
	{
		if( byMemberId >= MAXNUM_MPUSVMP_MEMBER )return;
		m_atVMPMember[byMemberId] = tVMPMember;
	}
	void   ClearVmpMember( u8 byMemberId )
	{
		if( byMemberId >= MAXNUM_MPUSVMP_MEMBER )return;
		m_atVMPMember[byMemberId].SetNull();
        m_atVMPMember[byMemberId].SetMemberType(0);
	}
    TVMPMember *GetVmpMember( u8   byMemberId )
	{
		if( byMemberId >= MAXNUM_MPUSVMP_MEMBER )return NULL;
		return &m_atVMPMember[byMemberId];
	}
	BOOL IsMtInMember( TMt tMt )
	{
		u8 byLoop = 0;
		u8 byLoopCtrl = 0;
		while( byLoop < GetMaxMemberNum() && byLoopCtrl < MAXNUM_MPUSVMP_MEMBER )
		{
			if( tMt.GetMtId() == m_atVMPMember[byLoop].GetMtId() && 
				tMt.GetMcuId() == m_atVMPMember[byLoop].GetMcuId() )
			{
				return TRUE;
			}

			byLoop++;
			byLoopCtrl++;
		}

		return FALSE;
	}
    BOOL IsTypeInMember(u8 byType)
    {
        u8 byLoop = 0;
		while( byLoop < GetMaxMemberNum() )
		{
			if( byType == m_atVMPMember[byLoop].GetMemberType() )
			{
				return TRUE;
			}
			byLoop++;
		}

		return FALSE;
    }
	u8 GetChlOfMtInMember( TMt tMt )
	{
		u8 byLoop = 0;
		while( byLoop < GetMaxMemberNum() )
		{
//  [11/5/2009 pengjie] ������ش�֧��
// 			if (!m_atVMPMember[byLoop].IsLocal() &&
// 				tMt.GetMtId() == m_atVMPMember[byLoop].GetMcuId())
// 			{
// 				return byLoop;				 
// 			}
			if (!m_atVMPMember[byLoop].IsLocal() &&
				tMt.GetMtId() == m_atVMPMember[byLoop].GetMtId()&&
				tMt.GetMcuId() == m_atVMPMember[byLoop].GetMcuId() )
			{
				return byLoop;				 
			}
// endmodify
			if( tMt.GetMtId() == m_atVMPMember[byLoop].GetMtId() )
			{
				return byLoop;
			}
			byLoop++;
		}

		return MAXNUM_MPUSVMP_MEMBER;
	}
	u8 GetChlOfMemberType (u8 byMemberType) 
	{
		u8 byLoop = 0;
		while( byLoop < GetMaxMemberNum() )
		{
			if (byMemberType == m_atVMPMember[byLoop].GetMemberType())
			{
				return byLoop;
			}
			byLoop++;
		}

		return MAXNUM_MPUSVMP_MEMBER;
	}
	void   Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "\nVMPParam:\n" );
		OspPrintf( TRUE, FALSE, "m_byVMPAuto: %d\n", m_byVMPAuto);
		OspPrintf( TRUE, FALSE, "m_byVMPBrdst: %d\n", m_byVMPBrdst);
		OspPrintf( TRUE, FALSE, "m_byVMPStyle: %d\n", m_byVMPStyle);
        OspPrintf( TRUE, FALSE, "m_byVmpSchemeId: %d\n", m_byVMPSchemeId );
		OspPrintf( TRUE, FALSE, "m_byRimEnabled: %d\n", m_byRimEnabled );
        OspPrintf( TRUE, FALSE, "m_byVMPMode: %d\n", m_byVMPMode );
		OspPrintf( TRUE, FALSE, "m_byVMPBatchPoll :%d\n", m_byVMPBatchPoll );
		OspPrintf( TRUE, FALSE, "m_byVMPSeeByChairman : %d\n", m_byVMPSeeByChairman);
		for( int i = 0; i < GetMaxMemberNum(); i ++ )
		{
			OspPrintf( TRUE, FALSE, "VMP member %d: MtId-%d, Type-%d\n", 
				i,  m_atVMPMember[i].GetMtId(), m_atVMPMember[i].GetMemberType() );            
		}
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//����Žṹ (len:16)
struct CConfId
{
protected:
	u8  	m_abyConfId[MAXLEN_CONFID];

public:
	u8   GetConfId( u8   * pbyConfId, u8   byBufLen ) const; //��û��������
	void CreateConfId( u8 byUsrGrpId );                               //���������
	void GetConfIdString( LPSTR lpszConfId, u8   byBufLen ) const;//��û�����ַ���
	void SetConfId( const CConfId & cConfId );                  //���û����
	u8   SetConfId( const u8   * pbyConfId, u8   byBufLen );          //���û��������
	u8   SetConfId( LPCSTR lpszConfId );                          //���û��������	
	BOOL IsNull( void ) const;                                  //�жϻ�����Ƿ�Ϊ��
	void SetNull( void );                                       //���û����Ϊ��
	BOOL operator == ( const CConfId & cConfId ) const;         //����������
    // ���񻪣���CConfId�������û������Ϣ
    u8   GetUsrGrpId() const 
    {
        return m_abyConfId[MAXLEN_CONFID-1];
    }
    void SetUsrGrpId(u8 byGrpId)
    {
        m_abyConfId[MAXLEN_CONFID-1] = byGrpId;
    }

	//fuxiuhua,���ӻ��鷢����Ϣ
	//����ID����ɣ�MCU��(2Byte)/��������(1Byte)/��������ֵ(1Byte)/����Ų�������(4Byte)/
	//              δ��(6Byte)/��������(1Byte)/���(1Byte)
	void SetConfSource( u8 byConfSource )
	{
		m_abyConfId[MAXLEN_CONFID - 2] = byConfSource;
	}
	u8   GetConfSource()
	{
		return m_abyConfId[MAXLEN_CONFID - 2];
	}

	void Print( void ) const
	{
		s8 achBuf[MAXLEN_CONFID*2+1];
		memset(achBuf, 0, sizeof(achBuf));
		GetConfIdString( achBuf, sizeof(achBuf) );
		OspPrintf( TRUE, FALSE, "%s\n", achBuf);
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//���崫���ַ�ṹ(len:6)
struct TTransportAddr
{
public:
	u32   		m_dwIpAddr;		//IP��ַ, ������
	u16 		m_wPort;		//�˿ں�, ������
public:
	void   SetNull(void)
	{
		m_dwIpAddr = 0;
		m_wPort = 0;
	}
    void   SetNetSeqIpAddr(u32    dwIpAddr){ m_dwIpAddr = dwIpAddr; } 
    u32    GetNetSeqIpAddr( void ) const { return m_dwIpAddr; }
    void   SetIpAddr(u32    dwIpAddr){ m_dwIpAddr = htonl(dwIpAddr); } 
    u32    GetIpAddr( void ) const { return ntohl(m_dwIpAddr); }
    void   SetPort(u16  wPort){ m_wPort = htons(wPort); } 
    u16    GetPort( void ) const { return ntohs(m_wPort); }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//(len:22)
struct TMediaEncrypt
{
protected:
	u8  m_byEncryptMode;         //����ģʽ : CONF_ENCRYPTMODE_NONE,CONF_ENCRYPTMODE_DES, CONF_ENCRYPT_AES
    s32 m_nKeyLen;               //����key�ĳ���
	u8  m_abyEncKey[MAXLEN_KEY]; //����key
	u8  m_byReserve;             //����
public:
	TMediaEncrypt()
	{
		Reset();
	}
	void Reset()
	{
        memset( &m_abyEncKey, 0, MAXLEN_KEY );
		m_byEncryptMode = CONF_ENCRYPTMODE_NONE;
		m_nKeyLen = 0;
	}

	void SetEncryptMode(u8 byEncMode)
	{
		m_byEncryptMode = byEncMode;
	}
    u8  GetEncryptMode()
	{
		return m_byEncryptMode;
	}
	void SetEncryptKey(u8 *pbyKey, s32 nLen)
	{
		m_nKeyLen = (nLen > MAXLEN_KEY ? MAXLEN_KEY : nLen);
		if(m_nKeyLen > 0)
			memcpy(m_abyEncKey, pbyKey, m_nKeyLen); 
		m_nKeyLen = htonl(m_nKeyLen);
	}
	
	void GetEncryptKey(u8 *pbyKey, s32* pnLen)
	{
		if(pnLen != NULL) *pnLen = ntohl(m_nKeyLen);
		if(pbyKey != NULL) memcpy(pbyKey, m_abyEncKey, ntohl(m_nKeyLen));
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//��¼¼���������(��λ:��)
struct  TRecProg
{
protected:
	u32   		m_dwCurProg;	//��ǰ����
	u32   		m_dwTotalTime;	//�ܳ��ȣ����ڷ���ʱ��Ч

public:
	//���õ�ǰ����λ�ã���λ���룩
	void SetCurProg( u32    dwCurProg )	{ m_dwCurProg = htonl( dwCurProg ); }
	//��ȡ��ǰ����λ�ã���λ���룩
	u32    GetCurProg( void ) const	{ return ntohl( m_dwCurProg ); }
	//�����ܳ��ȣ����Է�����Ч����λ���룩
	void SetTotalTime( u32    dwTotalTime )	{ m_dwTotalTime = htonl( dwTotalTime ); }
	//��ȡ�ܳ��ȣ����Է�����Ч����λ���룩
	u32    GetTotalTime( void ) const	{ return ntohl( m_dwTotalTime ); }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//ʱ��ṹ���¶���
struct TKdvTime
{
protected:
	u16 		m_wYear;//��
	u8  		m_byMonth;//��
	u8  		m_byMDay;//��
	u8  		m_byHour;//ʱ
	u8  		m_byMinute;//��
	u8  		m_bySecond;//��

public:
    TKdvTime()
    {
        memset(this, 0, sizeof(TKdvTime));
    }
	void SetTime( const time_t * ptTime );//����ʱ��
	void GetTime( time_t & tTime ) const;//�õ�ʱ��ṹ
	BOOL operator == ( const TKdvTime & tTime );//����

	u16  GetYear( void ) const	{ return( ntohs( m_wYear ) ); }
	u8   GetMonth( void ) const	{ return( m_byMonth ); }
	u8   GetDay( void ) const	{ return( m_byMDay ); }
	u8   GetHour( void ) const	{ return( m_byHour ); }
	u8   GetMinute( void ) const	{ return( m_byMinute ); }
	u8   GetSecond( void ) const	{ return( m_bySecond ); }
	void SetYear( u16  wYear )	{ m_wYear = htons( wYear ); }
	void SetMonth( u8   byMonth )	{ m_byMonth = byMonth; }
	void SetDay( u8   byDay )	{ m_byMDay = byDay; }
	void SetHour( u8   byHour )	{ m_byHour = byHour; }
	void SetMinute( u8   byMinute )	{ m_byMinute = byMinute; }
	void SetSecond( u8   bySecond )	{ m_bySecond = bySecond; }
	void Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "%d-%d-%d %d:%d:%d", ntohs(m_wYear),m_byMonth,m_byMDay,m_byHour,m_byMinute,m_bySecond );
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//��ѯ��Ϣ(len: 18)
struct TPollInfo
{
protected:
    u8  m_byMediaMode;           //��ѯģʽ MODE_VIDEO ͼ��  MODE_BOTH ����ͼ��
    u8  m_byPollState;           //��ѯ״̬���μ���ѯ״̬����
    u32 m_dwPollNum;             //�ն���ѯ�Ĵ�����ע��hdu������ѯ�����ǽ��ѯ����
    TMtPollParam m_tMtPollParam; //��ǰ����ѯ�㲥���ն˼������
public:
    void SetMediaMode(u8 byMediaMode) { m_byMediaMode = byMediaMode; }
    u8   GetMediaMode(void) const { return m_byMediaMode; }
    void SetPollState(u8 byPollState) { m_byPollState = byPollState; }
    u8   GetPollState(void) const { return m_byPollState; }
    void SetPollNum(u32 dwPollNum) { m_dwPollNum = htonl(dwPollNum); }
    u32  GetPollNum(void) const { return ntohl(m_dwPollNum); }
    void SetMtPollParam(TMtPollParam tMtPollParam){ m_tMtPollParam = tMtPollParam; }
    TMtPollParam GetMtPollParam() const{ return m_tMtPollParam; }
    void Print(void) const
    {
        OspPrintf(TRUE, FALSE, "\nPollInfo:\n");
        OspPrintf(TRUE, FALSE, "m_byMediaMode: %d\n", m_byMediaMode);
        OspPrintf(TRUE, FALSE, "m_byPollState: %d\n", m_byPollState);
        OspPrintf(TRUE, FALSE, "m_dwPollNum: %d\n", m_dwPollNum);
        OspPrintf(TRUE, FALSE, "CurPollMt: %d,%d\n", m_tMtPollParam.GetMcuId(),m_tMtPollParam.GetMtId());
    }
}
/*
#ifndef WIN32
__attribute__((packed))
#endif
*/
PACKED
;

//����ǽ��ѯ��Ϣ(len:32)
struct TTvWallPollInfo : public TPollInfo
{
protected:
    TEqp    m_tTvWall;
    u8      m_byTWChnnl;
	u32     m_byKeepTime;
	u8      m_bySchemeIdx;
	u8      m_byReserved[2];
    
public:
	TTvWallPollInfo(void){ memset( this, 0x0, sizeof( TTvWallPollInfo ) ); }

    void SetTvWall(TEqp tTvWall) { m_tTvWall = tTvWall; }
    TEqp GetTvWall(void) const{ return m_tTvWall; } 
    
	void SetTWChnnl(u8 byChnnl) { m_byTWChnnl = byChnnl; }
    u8   GetTWChnnl(void) const { return m_byTWChnnl; }
	
    void SetKeepTime( u32 byKeepTime ){ m_byKeepTime = htonl(byKeepTime); }
	u32  GetKeepTime( void ){ return ntohl(m_byKeepTime); } 

	void SetSchemeIdx(u8 bySchemeIdx) { m_bySchemeIdx = bySchemeIdx; }
    u8   GetSchemeIdx(void) const { return m_bySchemeIdx; }
}
/*
#ifndef WIN32
__attribute__((packed))
#endif
*/
PACKED
;

//HDU��ѯ��Ϣ(len: 32)
typedef TTvWallPollInfo THduPollInfo;


//�����ն˱���ö������
typedef enum
{
	mtAliasTypeBegin = 0,
	mtAliasTypeTransportAddress = 1,  //�ն˱�������: �����ַ
	mtAliasTypeE164,              //�ն˱�������: E164����
	mtAliasTypeH323ID,            //�ն˱�������: H323 ID
	mtAliasTypeH320ID,            //�ն˱�������: H320 ID����
    mtAliasTypeH320Alias,         //�ն˱�������: H320 ��������, ����������Ϣ
	mtAliasTypeOthers,            //�ն˱�������: ����
	puAliasTypeIPPlusAlias        //����PU������Ϣ:����IP(u32������)+PU����(11�ֽ�)
} mtAliasType;

//�����ն˱����ṹ(len:135)
struct TMtAlias
{
public:
    u8				m_AliasType;               //��������
    s8			m_achAlias[MAXLEN_ALIAS];  //�����ַ���
    TTransportAddr	m_tTransportAddr;          //�����ַ
public:
	TMtAlias( void ){ memset( this, 0, sizeof(TMtAlias) ); }
	BOOL operator ==( const TMtAlias & tObj ) const;
	BOOL IsNull( void ) const { if( m_AliasType == 0 )return TRUE; return FALSE; }
	void SetNull( void ){ memset(this, 0, sizeof(TMtAlias)); }
	BOOL IsAliasNull( void ) const { return 0 == strlen(m_achAlias); }
	void SetE164Alias( LPCSTR lpzAlias )
	{
		if( lpzAlias != NULL )
		{
			m_AliasType = mtAliasTypeE164;
            memset( m_achAlias, 0, sizeof(m_achAlias));
			strncpy( m_achAlias, lpzAlias, MAXLEN_ALIAS-1 );
		}
	}
	void SetH323Alias( LPCSTR lpzAlias )
	{
		if( lpzAlias != NULL )
		{
			m_AliasType = mtAliasTypeH323ID;
            memset( m_achAlias, 0, sizeof(m_achAlias));
			strncpy( m_achAlias, lpzAlias, MAXLEN_ALIAS-1 );
		}
	}
	void SetH320Alias( u8 byLayer, u8 bySlot, u8 byChannel )
	{
		m_AliasType = mtAliasTypeH320ID;
		sprintf( m_achAlias, "��%d-��%d-ͨ��%d%c", byLayer, bySlot, byChannel, 0 );
	}
	BOOL GetH320Alias ( u8 &byLayer, u8 &bySlot, u8 &byChannel )
	{
		BOOL bRet = FALSE;
		byLayer   = 0;
		bySlot    = 0; 
		byChannel = 0; 
		if( mtAliasTypeH320ID != m_AliasType )
		{
			return bRet;
		}

		s8 *pachLayerPrefix   = "��";
		s8 *pachSlotPrefix    = "-��";
		s8 *pachChannelPrefix = "-ͨ��";
		s8 *pachAlias = m_achAlias;

		if( 0 == memcmp( pachAlias, pachLayerPrefix, strlen("��") ) )
		{
			s32  nPos = 0;
			s32  nMaxCHLen = 3; //һ�ֽڵ�����ִ�����
			s8 achLayer[4] = {0};

			//��ȡ���
			pachAlias += strlen("��");
			for( nPos = 0; nPos < nMaxCHLen; nPos++ )
			{
				if( '-' == pachAlias[nPos] )
				{
					break;
				}
				achLayer[nPos] = pachAlias[nPos];
			}
			if( 0 == nPos || nPos >= nMaxCHLen )
			{
				return bRet;
			}
			achLayer[nPos+1] = '\0';
			byLayer = atoi(achLayer);

			//��ȡ�ۺ�
			pachAlias += nPos;
			if( 0 == memcmp( pachAlias, pachSlotPrefix, strlen("-��") ) )
			{
				pachAlias += strlen("-��");
				for( nPos = 0; nPos < nMaxCHLen; nPos++ )
				{
					if( '-' == pachAlias[nPos] )
					{
						break;
					}
					achLayer[nPos] = pachAlias[nPos];
				}
				if( 0 == nPos || nPos >= nMaxCHLen )
				{
					return bRet;
				}
				achLayer[nPos+1] = '\0';
				bySlot = atoi(achLayer);
			
				//��ȡͨ����
				pachAlias += nPos;
				if( 0 == memcmp( pachAlias, pachChannelPrefix, strlen("-ͨ��") ) )
				{
					pachAlias += strlen("-ͨ��");
					memcpy( achLayer, pachAlias, nMaxCHLen );
					achLayer[nMaxCHLen] = '\0';
					byChannel = atoi(achLayer);
					bRet = TRUE;
				}
			}
		}
		return bRet;
	}
	void Print( void ) const
	{
		if( m_AliasType == 0 )
		{
			OspPrintf( TRUE, FALSE, "null alias" );
		}
		else if( m_AliasType == mtAliasTypeTransportAddress )
		{
			OspPrintf( TRUE, FALSE, "IP: 0x%x:%d", 
				     m_tTransportAddr.GetIpAddr(), m_tTransportAddr.GetPort() );
		}		
		else if( m_AliasType == mtAliasTypeE164 )
		{
			OspPrintf( TRUE, FALSE, "E164: %s", m_achAlias ); 
		}
		else if( m_AliasType == mtAliasTypeH323ID )
		{
			OspPrintf( TRUE, FALSE, "H323ID: %s", m_achAlias ); 
		}
		else if( m_AliasType == mtAliasTypeH320ID )
		{
			OspPrintf( TRUE, FALSE, "H320ID: %s", m_achAlias ); 
		}
        else if( m_AliasType == mtAliasTypeH320Alias )
        {
            OspPrintf( TRUE, FALSE, "H320Alias: %s", m_achAlias );
        }
		else
		{
			OspPrintf( TRUE, FALSE, "Other type alias!" ); 
		}
		OspPrintf( TRUE, FALSE, "\n" );
	}
}
/* 
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//�������ģʽ
typedef enum
{
	mcuNoMix = 0,
	mcuWholeMix,
	mcuPartMix,
    mcuVacMix,
	mcuVacWholeMix,
	mcuVacPartMix   // ���ֶ��ѷ�����VAC�붨�ƻ�����ͻ��
} emMcuMixMode;

#define  MAXNUM_MIXING_MEMBER        64
struct TMixParam
{
public:
    TMixParam(void)
    {
        Clear();
    }
    void Clear(void){ memset(this, 0, sizeof(TMixParam));    }

    void SetMode(u8 byMixMode){ m_byMixMode = byMixMode;    }
    u8   GetMode(void) const { return m_byMixMode;    }

    u8   GetMemberNum() const
    {
        return m_byMtNum;
    }
    void AddMember(u8 byMtId)
    {
        if (byMtId == 0)
            return;
        
        if (m_byMtNum < MAXNUM_MIXING_MEMBER)
        {
            m_abyMtList[m_byMtNum++] = byMtId;
        }        
    }
    void DelMember(u8 byMtId)
    {
        if (byMtId == 0)
            return;

        for (u8 byLoop = 0; byLoop < m_byMtNum; byLoop ++ )
        {
            if (m_abyMtList[byLoop] == byMtId)
            {
                for ( u8 byMove = byLoop+1; byMove < m_byMtNum; byMove ++ )
                {
                    m_abyMtList[byMove-1] =  m_abyMtList[byMove];
                }
                m_byMtNum --;
                break;
            }
        }
    }

    void ClearAllMembers()
    {
        m_byMtNum = 0;
    }

    u8 GetMemberByIdx(u8 byIdx)
    {
        if ( byIdx < m_byMtNum )
            return m_abyMtList[byIdx];
        else
            return 0;
    }

    BOOL32 IsMtInMember(u8 byMtId) const
    {
        for (u8 byLoop = 0; byLoop < m_byMtNum; byLoop ++ )
        {
            if (m_abyMtList[byLoop] == byMtId)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    void SetMtMaxNum(u8 byMtMaxNum){ m_byMtMaxNum = byMtMaxNum;    }
    u8   GetMtMaxNum(void) const { return m_byMtMaxNum;    }
protected:
    u8  m_byMixMode;    //����ģʽ��mcuNoMix - ������
                        //          mcuWholeMix - ȫ�����
                        //          mcuPartMix - ���ƻ���
                        //          mcuVacMix, - VAC 
                        //          mcuVacWholeMix - ��Vac��ȫ�����
    u8  m_byMtNum;
    u8  m_abyMtList[MAXNUM_MIXING_MEMBER];
    u8  m_byMtMaxNum;   //  ��¼ʹ�õĻ���������Ա��,�ָ�����������ʱ�õ�
private:
    u8  m_abyReserved[3];
}
PACKED
;

//¼��ʽ����
#define		 REC_MODE_NORMAL				0   /* ʵʱ¼�� */
#define	     REC_MODE_SKIPFRAME				1	/* ��֡¼�� */

//�йط�����ʽ����
#define      PUBLISH_MODE_NONE				0	//������
#define      PUBLISH_MODE_IMMED				1	//��������
#define      PUBLISH_MODE_FIN				2	//¼�����֮�󷢲�

//��������
#define      PUBLISH_LEVEL_NORMAL			0	//��������
#define      PUBLISH_LEVEL_SECRET			1	//���ܷ���

//¼���ļ�����
#define      RECFILE_NORMAL                 0   //����ʽ¼���ļ�
#define      RECFILE_DSTREAM                1   //˫��ʽ¼���ļ�

// size = 11
struct TRecStartPara
{
protected:
    u8   m_byRecMode;         //¼��ģʽ
    u8   m_byPublishMode;     //����ģʽ
    u8   m_byPublishLevel;    //�������
    u8   m_byIsRecLowStream;  //�Ƿ�¼��������
    u8   m_byIsRecMainVideo;  //�Ƿ�¼����ʽ��Ƶ����
    u8   m_byIsRecMainAudio;  //�Ƿ�¼����ʽ��Ƶ����
    u8   m_byIsRecDStream;    //�Ƿ�¼˫��
	u16  m_wRecBitrate;       //¼������
    u16  m_wRecBitrateSec;    //¼��˫������

public:
	TRecStartPara()
	{
		Reset();
	}
	void Reset(void)
	{
		m_byRecMode = REC_MODE_NORMAL;
		m_byPublishMode = PUBLISH_MODE_NONE;
		m_byPublishLevel = PUBLISH_LEVEL_NORMAL;
        m_byIsRecMainVideo = 1;
        m_byIsRecMainAudio = 1;
        m_byIsRecDStream   = 0;
        m_byIsRecLowStream = 0;
        m_wRecBitrate      = 0;
        m_wRecBitrateSec   = 0;
	}
	void SetRecMode(u8 byMode)
	{
		m_byRecMode = byMode;
	}
	u8 GetRecMode(void) const
	{
		return m_byRecMode;
	}
	void SetPublishMode(u8 byMode)
	{
		m_byPublishMode = byMode;
	}
	u8 GetPublishMode(void) const
	{
		return m_byPublishMode;
	}
    void SetPublishLevel(u8 byLevel)
	{
		m_byPublishLevel = byLevel;
	}
	u8  GetPublishLevel(void) const
	{
		return m_byPublishLevel;
	}
    void SetIsRecLowStream(BOOL32 bRecLowStream)
	{
		m_byIsRecLowStream = ( bRecLowStream ? 1:0);
	}
	BOOL32 IsRecLowStream(void) const 
	{
		return (m_byIsRecLowStream != 0);
	}

    void SetIsRecMainVideo(BOOL32 bRecMainVideo)
	{
		m_byIsRecMainVideo = (bRecMainVideo ? 1:0);
	}
	BOOL32 IsRecMainVideo(void) const
	{
		return (m_byIsRecMainVideo != 0);
	}

    void SetIsRecMainAudio(BOOL32 bRecMainAudio)
	{
		m_byIsRecMainAudio = (bRecMainAudio ? 1:0);
	}
	BOOL32 IsRecMainAudio(void) const
	{
		return (m_byIsRecMainAudio != 0);
	}

    void SetIsRecDStream(BOOL32 bRecDStream)
	{
		m_byIsRecDStream = (bRecDStream ? 1:0);
	}
	BOOL32 IsRecDStream(void) const
	{
		return (m_byIsRecDStream != 0);
	}

	void SetBitRate(u16 wBitRate)
	{
		m_wRecBitrate = htons(wBitRate);
	}
	u16 GetBitRate(void) const
	{
		return ntohs(m_wRecBitrate);
	}

    void SetSecBitRate(u16 wBitRate)
    {
        m_wRecBitrateSec = htons(wBitRate);
    }
    u16 GetSecBitRate(void) const
    {
        return ntohs(m_wRecBitrateSec);
    }

    void Print() const
    {
        
        OspPrintf(TRUE, FALSE, "m_byRecMode:        %d\n", GetRecMode());
        OspPrintf(TRUE, FALSE, "m_byPublishMode:    %d\n", GetPublishMode());
        OspPrintf(TRUE, FALSE, "m_byPublishLevel:   %d\n", GetPublishLevel());
        OspPrintf(TRUE, FALSE, "m_byIsRecMainVideo: %d\n", IsRecMainVideo());
        OspPrintf(TRUE, FALSE, "m_byIsRecMainAudio: %d\n", IsRecMainAudio());
        OspPrintf(TRUE, FALSE, "m_byIsRecLowStream: %d\n", IsRecLowStream());
        OspPrintf(TRUE, FALSE, "m_byIsRecDStream:   %d\n", IsRecDStream());
        OspPrintf(TRUE, FALSE, "m_wRecBitrate:      %d\n", GetBitRate());
        OspPrintf(TRUE, FALSE, "m_wSecRecBitrate:   %d\n", GetSecBitRate());

    }

}
/*
#ifndef WIN32
__attribute__((packed))
#endif
*/
PACKED
;


//����������Խṹ(�����в���ı�), sizeof = 32
struct TConfAttrb
{
protected:
	u8     m_byOpenMode;        //���鿪�ŷ�ʽ: 0-������,�ܾ��б�������ն� 1-����������� 2-��ȫ����
	u8     m_byEncryptMode;     //�������ģʽ: 0-������, 1-des����,2-aes����
	u8     m_byMulticastMode;   //�鲥���鷽ʽ: 0-�����鲥���� 1-�鲥����
	u8     m_byDataMode;        //���ݻ��鷽ʽ: 0-���������ݵ�����Ƶ���� 1-�������ݵ�����Ƶ���� 2-ֻ�����ݵĻ���
	u8     m_byReleaseMode;     //���������ʽ: 0-�����Զ����� 1-���ն�ʱ�Զ�����
    u8     m_byVideoMode;       //������Ƶģʽ: 0-�ٶ����� 1-��������
	u8     m_byCascadeMode;     //���鼶����ʽ: 0-��֧�ֺϲ�����, 1-֧�ֺϲ�����
	u8     m_byPrsMode;         //�����ش���ʽ: 0-���ش� 1-�ش�
    u8     m_byHasTvWallModule; //����ǽģ��:   0-�޵���ǽģ��  1-�е���ǽģ��
	u8     m_byHasVmpModule;    //����ϳ�ģ��: 0-�޻���ϳ�ģ��  1-�л���ϳ�ģ��
	u8     m_byDiscussConf;     //�Ƿ����ۻ���: 0-�������ۻ���(�ݽ�����) 1-���ۻ��� (��һ�ֶν��������ƻ��鿪ʼ���Ƿ���������)
	u8     m_byUseAdapter;		//�Ƿ���������: 0-�������κ����� 2-����Ҫ����(����������)���� 
	u8     m_bySpeakerSrc;		//�����˵�Դ:   0-���Լ� 1-����ϯ 2-����һ�η����� 
	u8     m_bySpeakerSrcMode;  //�����˵�Դ�ķ�ʽ: 0-��Чֵ 1-����Ƶ 2-����Ƶ 3-����Ƶ
	u8     m_byMulcastLowStream;//�Ƿ��鲥��������: 0-�����鲥��������(�鲥��������) 1-�鲥��������
	u8     m_byAllInitDumb;     //�ն������Ƿ��ʼ���� 0-������ 1-����
	u8	   m_byDualMode;		//�����˫������ʽ: 0-������ 1-�����ն�
	u8     m_byUniformMode;     //����ת��ʱ�Ƿ�֧�ֹ�һ������ʽ: CONF_UNIFORMMODE_NONE-������ CONF_UNIFORMMODE_valid-������
	                            //�������ʽ�붪���ش���ʽ����
    u16    m_wMulticastPort;    //�����鲥��ʼ�˿ڣ�����������鲥���飬��Ҫ��д�鲥��ַ
    u32    m_dwMulticastIp;     //�����鲥��ַ������������鲥���飬��Ҫ��д�鲥��ַ
    
    u32    m_dwSatDCastIp;      //���Ƿ�ɢ����Ip��ַ
    u16    m_wSatDCastPort;     //���Ƿ�ɢ����˿�
    u8     m_bySatDCastMode;    //�Ƿ�֧�����Ƿ�ɢ���飺0-��֧�֣�1-֧��
    u8     m_byEncKeyManual;    //������Կģʽ: 0-�Զ���Կ, 1-�ֶ���Կ    

public:
	TConfAttrb( void )
	{
		memset( this, 0, sizeof(TConfAttrb) );
		m_byOpenMode = CONF_OPENMODE_OPEN;
	}

    void   SetOpenMode(u8   byOpenMode){ m_byOpenMode = byOpenMode;} 
    u8     GetOpenMode( void ) const { return m_byOpenMode; }
	void   SetEncryptMode(u8   byEncryptMode){ m_byEncryptMode = byEncryptMode;} 
    u8     GetEncryptMode( void ) const { return m_byEncryptMode; }
    void   SetEncKeyManual(BOOL  bEncKeyManual){ m_byEncKeyManual = bEncKeyManual; }
    BOOL   IsEncKeyManual( void ) const { return m_byEncKeyManual == 0 ? FALSE : TRUE; }
    void   SetMulticastMode(BOOL bMulticastMode){ m_byMulticastMode = bMulticastMode;} 
    BOOL   IsMulticastMode( void ) const { return m_byMulticastMode == 0 ? FALSE : TRUE; }
    void   SetDataMode(u8   byDataMode){ m_byDataMode = byDataMode;} 
    u8     GetDataMode( void ) const { return m_byDataMode; }
    void   SetReleaseMode(BOOL bReleaseMode){ m_byReleaseMode = bReleaseMode;} 
    BOOL   IsReleaseNoMt( void ) const { return m_byReleaseMode == 0 ? FALSE : TRUE; }
    void   SetQualityPri(BOOL bQualityPri){ m_byVideoMode = bQualityPri;} 
    BOOL   IsQualityPri( void ) const { return m_byVideoMode == 0 ? FALSE : TRUE; }
	void   SetSupportCascade(BOOL bCascadeMode){ m_byCascadeMode = (bCascadeMode==TRUE?1:0); }
	BOOL   IsSupportCascade( void ) const { return (m_byCascadeMode != 0 );}
	void   SetPrsMode( BOOL bResendPack ){ m_byPrsMode = bResendPack; }
	BOOL   IsResendLosePack( void ){ return m_byPrsMode == 0 ? FALSE : TRUE; }
	void   SetHasTvWallModule( BOOL bHasTvWallModule ){ m_byHasTvWallModule = bHasTvWallModule; }
	BOOL   IsHasTvWallModule( void ){ return m_byHasTvWallModule == 0 ? FALSE : TRUE; }
	void   SetHasVmpModule( BOOL bHasVmpModule ){ m_byHasVmpModule = bHasVmpModule; }
	BOOL   IsHasVmpModule( void ){ return m_byHasVmpModule == 0 ? FALSE : TRUE; }
	void   SetDiscussConf( BOOL bDiscussConf ){ m_byDiscussConf = bDiscussConf; }
	BOOL   IsDiscussConf( void ){ return m_byDiscussConf == 0 ? FALSE : TRUE; }
    void   SetUseAdapter( BOOL bUseAdapter ){ m_byUseAdapter = bUseAdapter; } 
    BOOL   IsUseAdapter( void ) const { return m_byUseAdapter == 0 ? FALSE : TRUE; }
    void   SetSpeakerSrc( u8 bySpeakerSrc ){ m_bySpeakerSrc = bySpeakerSrc;} 
    u8     GetSpeakerSrc( void ) const { return m_bySpeakerSrc; }
    void   SetSpeakerSrcMode( u8 bySpeakerSrcMode ){ m_bySpeakerSrcMode = bySpeakerSrcMode;} 
    u8     GetSpeakerSrcMode( void ) const { return m_bySpeakerSrcMode; }
	void   SetMulcastLowStream( BOOL bMulcastLowStream ){ m_byMulcastLowStream = bMulcastLowStream;} 
    BOOL   IsMulcastLowStream( void ) const { return m_byMulcastLowStream == 0 ? FALSE : TRUE; }
	void   SetAllInitDumb( BOOL bAllInitDumb ){ m_byAllInitDumb = bAllInitDumb;} 
    BOOL   IsAllInitDumb( void ) const { return m_byAllInitDumb == 0 ? FALSE : TRUE; }
	void   SetUniformMode( BOOL bUniformMode ){ m_byUniformMode = bUniformMode; }
	u8     IsAdjustUniformPack( void ){ return m_byUniformMode; }
	void   SetDualMode(	u8 byDualMode ){ m_byDualMode = byDualMode;	}
	u8	   GetDualMode( void ) const { return m_byDualMode;	}
    void   SetMulticastIp (u32 dwIp) { m_dwMulticastIp = htonl(dwIp); }
    u32    GetMulticastIp ( void ) const { return ntohl(m_dwMulticastIp); }
    void   SetMulticastPort ( u16 wPort) { m_wMulticastPort = htons(wPort); }
    u16    GetMulticastPort ( void ) const { return ntohs(m_wMulticastPort); }
    void   SetSatDCastMode ( BOOL bSatDCastMode ) { m_bySatDCastMode = bSatDCastMode; }
    BOOL   IsSatDCastMode () const { return m_bySatDCastMode == 0 ? FALSE : TRUE;    }
    void   SetSatDCastIp (u32 dwIp) { m_dwSatDCastIp = htonl(dwIp); }
    u32    GetSatDCastIp () const { return ntohl(m_dwSatDCastIp) ; }
    void   SetSatDCastPort (u16 wPort) { m_wSatDCastPort = htons(wPort); }
    u16    GetSatDCastPort () const { return ntohs(m_wSatDCastPort); }

    void   Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "\nConfAttrb:\n" );
		OspPrintf( TRUE, FALSE, "m_byOpenMode: %d\n",   m_byOpenMode);
		OspPrintf( TRUE, FALSE, "m_byEncryptMode: %d\n", m_byEncryptMode);
		OspPrintf( TRUE, FALSE, "m_byMulticastMode: %d\n", m_byMulticastMode);
        OspPrintf( TRUE, FALSE, "m_dwMulticastIp: 0x%x\n", GetMulticastIp());
        OspPrintf( TRUE, FALSE, "m_wMulticastPort: %d\n", GetMulticastPort());
		OspPrintf( TRUE, FALSE, "m_byDataMode: %d\n", m_byDataMode);
		OspPrintf( TRUE, FALSE, "m_byReleaseMode: %d\n", m_byReleaseMode);
		OspPrintf( TRUE, FALSE, "m_byVideoMode: %d\n", m_byVideoMode);
		OspPrintf( TRUE, FALSE, "m_byCascadeMode: %d\n", m_byCascadeMode);
		OspPrintf( TRUE, FALSE, "m_byPrsMode: %d\n", m_byPrsMode);
		OspPrintf( TRUE, FALSE, "m_byHasTvWallModule: %d\n", m_byHasTvWallModule);
		OspPrintf( TRUE, FALSE, "m_byHasVmpModule: %d\n", m_byHasVmpModule);	
		OspPrintf( TRUE, FALSE, "m_byDiscussConf: %d\n", m_byDiscussConf);
		OspPrintf( TRUE, FALSE, "m_byUseAdapter: %d\n", m_byUseAdapter);
		OspPrintf( TRUE, FALSE, "m_bySpeakerSrc: %d\n", m_bySpeakerSrc);
		OspPrintf( TRUE, FALSE, "m_bySpeakerSrcMode: %d\n", m_bySpeakerSrcMode);
		OspPrintf( TRUE, FALSE, "m_byMulcastLowStream: %d\n", m_byMulcastLowStream);
		OspPrintf( TRUE, FALSE, "m_byAllInitDumb: %d\n", m_byAllInitDumb);
		OspPrintf( TRUE, FALSE, "m_byUniformMode: %d\n", m_byUniformMode);
		OspPrintf( TRUE, FALSE, "m_byDualMode: %d\n", m_byDualMode);
        OspPrintf( TRUE, FALSE, "m_bySatDCastMode: %d\n", m_bySatDCastMode);
        OspPrintf( TRUE, FALSE, "m_dwSatDCastIp: 0x%x\n", GetSatDCastIp());
        OspPrintf( TRUE, FALSE, "m_wSatDCastPort: %d\n", GetSatDCastPort());
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;


// ����ʱ�Զ�¼�����ԣ����ܵ���memset��գ�����Reset()�ӿ�, size = 28
struct TConfAutoRecAttrb
{    
protected:
    u8     m_byAutoRec;         //�Ƿ���鿪ʼ�Զ�¼��0-��֧�֣�1-֧��
    u8     m_byRecEqpId;    //�Զ�¼���¼���id        

    // ��ʼʱ��ͽ���ʱ�䶼��֧�ֿ��죬����ʱ������ڿ�ʼʱ��֮��
    TKdvTime m_tTimeStart;      //��ʼ¼�������ʱ��.ֻ���� ʱ/��/�룬year����Ϊ0������Ҫ����ʱ�䣬���鿪ʼ���Զ���ʼ
    TKdvTime m_tTimeEnd;        //�Զ�¼�������ʱ��.ֻ���� ʱ/��/�룬year����Ϊ0������Ҫ����ʱ�䣬��Ҫ�û��ֶ�ֹͣ

public:    
    TRecStartPara m_tRecParam;  //�Զ�¼�����

protected:
    u8     m_byWeekdays;        //��ʼ¼����������ͣ�bit0(Sunday)-6(Sat)��1��ʾ������Ҫ¼��

public:
    TConfAutoRecAttrb()
    {
        Reset();
    }

    void   Reset()
    {
        memset(this, 0, sizeof(TConfAutoRecAttrb));

        m_tRecParam.Reset();
        m_tRecParam.SetIsRecDStream(TRUE);  // Ĭ��¼˫��
        m_tRecParam.SetPublishMode(PUBLISH_MODE_IMMED); // Ĭ����������
        SetRecAnyDay(); // Ĭ��ÿ�춼¼
    }
    
    void     SetAutoRec(BOOL32 bEnableAuto) { m_byAutoRec = bEnableAuto ?  1 : 0; }
    BOOL32   IsAutoRec() const { return (m_byAutoRec == 1); }
    void     SetRecEqp(u8 byRecId) { m_byRecEqpId = byRecId; }
    u8       GetRecEqp() const { return m_byRecEqpId; }

    void     SetRecAnyDay()   //����ÿ�춼¼��
    {
        m_byWeekdays = 0x7F;
    }
    void     SetRecNoDay()    //����ÿ�춼��¼,ע�⣺���ָ����m_byAutoRec=1��m_byWeekdays = 0�ǲ��Ϸ���,��������ʱ���
    {
        m_byWeekdays = 0;
    }
    void     SetRecWeekDay(u8 byDay, BOOL32 bEnable)  // ָ��ĳ��¼�� 0 - Sunday, 1 - Monday,  6- Satday
    {
        if (bEnable)
            m_byWeekdays |= (1<<byDay);
        else
            m_byWeekdays &= ~(1<<byDay);
    }
    BOOL32 IsRecAnyDay() const  // �Ƿ�ÿ�춼¼��
    {
        return (m_byWeekdays == 0x7F);
    }
    BOOL32 IsRecNoDay() const   // �Ƿ�ÿ�춼��¼
    {
        return (m_byWeekdays == 0);
    }
    BOOL32 IsRecWeekDay(u8 byDay) const //�Ƿ��ض���¼��
    {
        return  ((m_byWeekdays & (1<<byDay)) >> byDay) ? TRUE : FALSE;
    }

    void     SetStartTime(const TKdvTime &tStartTime) { m_tTimeStart = tStartTime; }
    TKdvTime GetStartTime() const { return m_tTimeStart; }
    void     SetEndTime(const TKdvTime &tEndTime) { m_tTimeEnd = tEndTime; }
    TKdvTime GetEndTime() const { return m_tTimeEnd; }
    void     SetRecParam(const TRecStartPara &tParam) { m_tRecParam = tParam; }
    TRecStartPara GetRecParam() const { return m_tRecParam; }

    void     Print() const
    {   
        OspPrintf( TRUE, FALSE, "Conf Auto Rec Attrib:\n");
        OspPrintf( TRUE, FALSE, "m_byAutoRec: %d\n", IsAutoRec());
        if (IsAutoRec())
        {
            OspPrintf( TRUE, FALSE, "m_byRecEqpId: %d\n", m_byRecEqpId);
            OspPrintf( TRUE, FALSE, "m_byWeekdays: 0x%x\n", m_byWeekdays);        
            OspPrintf( TRUE, FALSE, "m_tTimeStart: ");
            m_tTimeStart.Print();
            OspPrintf( TRUE, FALSE, "\n");        
            OspPrintf( TRUE, FALSE, "m_tTimeEnd: ");
            m_tTimeEnd.Print();
            OspPrintf( TRUE, FALSE, "\n");
            //        OspPrintf( TRUE, FALSE, "m_szRecName: %s\n", GetRecName());
            OspPrintf( TRUE, FALSE, "m_tRecParam: \n");
            m_tRecParam.Print(); 
        }
    }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

// ����ʱ�������ԣ�4.0R3��չ, size = 76
struct TConfAttrbEx
{
    enum emMaskResEx
    {
        emRes1080 = 0x01,   //��ʱ���ã�������չ
        emRes720p = 0x02,
        emRes4Cif = 0x04,
        emResCif  = 0x08
    };

protected:
    u8                m_bySatDCastChnl;             //���ǻ����ϴ������ͨ����
    TConfAutoRecAttrb m_tAutoRecAttrb;              //�Զ�¼������
    u8                m_byVmpAutoAdapte;            //����ϳ��Զ������ֱ���
    s8                m_achGKUsrName[MAX_LEN_GK_USRNAME];         //GK�û���
    s8                m_achGKPwd[MAX_LEN_GK_PWD];                 //GK����
    u8                m_byOverrunPolicy;            //8000Bר�á�������������VMP/BASͬʱʹ�ã��������ն����ӵ����������������Ƿ��Զ�ֹͣ�� 1-�Զ�ֹͣ��0-�л������ƻ���
    u8                m_byMainResEx;                //����֧�ֵ�����Ƶ�ֱ�����չ
	u8                m_bySchemeIdxInBatchPoll;     //����hdu������ѯ��Ԥ��������
	u8                m_byConfLevel;                //���鼶��0-255
    u8                m_byRealSatConf;              //�Ƿ�Ϊ���������ǻ���

private:
    u8                m_abyReserved[9];            //�����ֶ�

public:
    TConfAttrbEx()
    {
        Reset();
    }
    void Reset()
    {
        memset(this, 0, sizeof(TConfAttrbEx));
        m_tAutoRecAttrb.Reset();
	    m_byConfLevel = 255;
    }

    void   SetSchemeIdxInBatchPoll(u8 bySchemeIdxInBatchPoll) { m_bySchemeIdxInBatchPoll = bySchemeIdxInBatchPoll; }
    u8     GetSchemeIdxInBatchPoll() const { return m_bySchemeIdxInBatchPoll; }


    void   SetSatDCastChnlNum(u8 byNum) { m_bySatDCastChnl = byNum; }
    u8     GetSatDCastChnlNum() const { return m_bySatDCastChnl; }

    void   SetAutoRecAttrb(const TConfAutoRecAttrb& tAttrb ) { m_tAutoRecAttrb = tAttrb; }
    TConfAutoRecAttrb GetAutoRecAttrb() const { return m_tAutoRecAttrb; }

    void   SetVmpAutoAdapt(BOOL32 bAutoAdapt) { m_byVmpAutoAdapte = bAutoAdapt ? 1 : 0; }
    BOOL32 IsVmpAutoAdapt() const { return m_byVmpAutoAdapte == 1 ? TRUE : FALSE;}

    void SetGKUsrName(LPCSTR pszName)
    {
        if ( pszName != NULL )
        {
            u16 wLen = min( MAX_LEN_GK_USRNAME-1, strlen(pszName) );
            strncpy( m_achGKUsrName, pszName, wLen );
            m_achGKUsrName[wLen] = '\0';
        }
        return;
    }
    LPCSTR GetGKUsrName() const { return m_achGKUsrName; }
    
    void SetGKPwd(LPCSTR pszPwd)
    {
        if ( pszPwd != NULL )
        {
            u16 wLen = min( MAX_LEN_GK_PWD-1, strlen(pszPwd) );
            strncpy( m_achGKPwd, pszPwd, wLen );
            m_achGKPwd[wLen] = '\0';
        }
        return;
    }
    LPCSTR GetGKPwd(void) const { return m_achGKPwd; }

    void SetDiscussAutoStop()
    {
        m_byOverrunPolicy = 1;
    }
    void SetDiscussAutoSwitch2Mix()
    {
        m_byOverrunPolicy = 0;
    }
    BOOL32 IsDiscussAutoStop() const
    {
        return (m_byOverrunPolicy == 1 ? TRUE : FALSE );
    }
    void SetResEx1080(BOOL32 bIsAdd = TRUE)
    {
        SETBITSTATUS(m_byMainResEx, emRes1080, bIsAdd)
    }
    BOOL32 IsResEx1080(void) const
    {
        return GETBITSTATUS(m_byMainResEx, emRes1080);
    }
    void SetResEx720(BOOL32 bIsAdd = TRUE)
    {
        SETBITSTATUS(m_byMainResEx, emRes720p, bIsAdd)
    }
    BOOL32 IsResEx720(void) const
    {
        return GETBITSTATUS(m_byMainResEx, emRes720p);
    }
    void SetResEx4Cif(BOOL32 bIsAdd = TRUE)
    {
        SETBITSTATUS(m_byMainResEx, emRes4Cif, bIsAdd)
    }
    BOOL32 IsResEx4Cif(void) const
    {
        return GETBITSTATUS(m_byMainResEx, emRes4Cif);
    }
    void SetResExCif(BOOL32 bIsAdd = TRUE)
    {
        SETBITSTATUS(m_byMainResEx, emResCif, bIsAdd)
    }
    BOOL32 IsResExCif(void) const
    {
        return GETBITSTATUS(m_byMainResEx, emResCif);
    }
	void SetConfLevel(u8 byLevel)
	{
		m_byConfLevel = byLevel;
	}
	u8   GetConfLevel()
	{
		return m_byConfLevel;
	}
    void SetConfRealSat(BOOL32 bSat)
    {
        m_byRealSatConf = bSat ? 1 : 0;
    }
    BOOL32 IsConfRealSat(void) const
    {
        return m_byRealSatConf == 0 ? FALSE : TRUE;
    }
    void Print() const
    {
        OspPrintf( TRUE, FALSE, "m_bySatDCastChnl: %d\n", GetSatDCastChnlNum());
        m_tAutoRecAttrb.Print();
        OspPrintf( TRUE, FALSE, "m_byVmpAutoAdapte:  %d\n", IsVmpAutoAdapt());        
        OspPrintf( TRUE, FALSE, "m_byOverrunPolicy:  %s\n", IsDiscussAutoStop() ? "Auto Stop" : "Switch to Mix");
        OspPrintf( TRUE, FALSE, "GK Charge User Name: %s, Pwd: %s\n", m_achGKUsrName, m_achGKPwd );
        OspPrintf( TRUE, FALSE, "ConfMainResEx: <1080:%d, 720:%d, 4Cif.%d, Cif.%d>\n", IsResEx1080(), IsResEx720(), IsResEx4Cif(), IsResExCif());
		OspPrintf( TRUE, FALSE, "m_byConfLevel:      %d\n", m_byConfLevel);
		OspPrintf( TRUE, FALSE, "m_byRealSatConf:    %d\n", m_byRealSatConf );
    }
}
PACKED
;



/*����ǽģ��ṹ�ͻ���ϳ�ģ��ṹ˵��:
Ŀǰ����ʱ����Ϣ��: TConfInfo + 2 byte(TMtAlias����������,�������n)
                  + n byte(TMtAlias������) + TMultiTvWallModule(��ѡ) + TVmpModule(��ѡ) */
//����ǽģ��ṹ
struct TTvWallModule
{
	TEqp m_tTvWall;                                     //���ָ���ĵ���ǽ
    u8   m_abyTvWallMember[MAXNUM_PERIEQP_CHNNL];       //���ָ���ĵ���ǽ��Ա������������ʱTMtAlias��������+1��
    u8   m_abyMemberType[MAXNUM_PERIEQP_CHNNL];         //����ǽ��Ա��������,TW_MEMBERTYPE_MCSSPEC,TW_MEMBERTYPE_SPEAKER...
  
public:
    TTvWallModule(void) { memset(this, 0, sizeof(TTvWallModule)); }

    TEqp GetTvEqp(void) const
    {
        return m_tTvWall;
    }
    
    void SetTvEqp(TEqp tTvWall)
    {
        m_tTvWall = tTvWall;
    }
    
    void EmptyTvMember(void)
    {
        memset((void*)m_abyTvWallMember, 0, sizeof(m_abyTvWallMember));
        memset((void*)m_abyMemberType, 0, sizeof(m_abyMemberType));
    }

    void SetTvChannel(u8 byTvChl, u8 byMtIdx, u8 byMemberType) // ����ָ��ͨ��
    {
        if(byTvChl < MAXNUM_PERIEQP_CHNNL)
        {
            m_abyTvWallMember[byTvChl] = byMtIdx;
            m_abyMemberType[byTvChl] = byMemberType;
        }
    }
    
    void RemoveTvMember(u8 byTvChl) // �Ƴ�����ǽָ��ͨ��
    {
        if(byTvChl < MAXNUM_PERIEQP_CHNNL)
        {
            m_abyTvWallMember[byTvChl] = 0;
            m_abyMemberType[byTvChl] = 0;
        }
    }
    
    void RemoveMtInTvMember(u8 byMtIdx) // �Ƴ�����ǽ�����и��ն�
    {
        for(u8 byTvChlLp = 0; byTvChlLp < MAXNUM_PERIEQP_CHNNL; byTvChlLp++)
        {
            if(m_abyTvWallMember[byTvChlLp] == byMtIdx)
            {
                m_abyTvWallMember[byTvChlLp] = 0;
				// ����TW_MEMBERTYPE_VCSAUTOSPEC���ͱ�ʶ����Ϊ�Զ�ģʽ�¸�ͨ�����ã����Զ��䲻���
				if (m_abyMemberType[byTvChlLp] != TW_MEMBERTYPE_VCSAUTOSPEC)
				{
					m_abyMemberType[byTvChlLp] = 0;
				}
                
            }
        }
    }

    void Clear(void)
    {
        memset(&m_tTvWall, 0, sizeof(m_tTvWall));
        memset(m_abyTvWallMember, 0, sizeof(m_abyTvWallMember) );
        memset(m_abyMemberType, 0, sizeof(m_abyMemberType));
    }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

// ����ģ����֧�ֶ����ǽ�ṹ
struct TMultiTvWallModule
{
    u8 m_byTvModuleNum; // ����ǽ��Ŀ
    TTvWallModule  m_atTvWallModule[MAXNUM_PERIEQP_CHNNL];

public:

    TMultiTvWallModule(void){ memset(this, 0, sizeof(TMultiTvWallModule));}

    void SetTvModuleNum( u8 byTvModuleNum ) { m_byTvModuleNum = (byTvModuleNum <= MAXNUM_PERIEQP_CHNNL) ? byTvModuleNum : m_byTvModuleNum;}
    u8     GetTvModuleNum( void ) const { return m_byTvModuleNum; }
    BOOL32 SetTvModule(u8 byTvModueIdx, TTvWallModule m_tTvWallModule)
    {
        BOOL32 bRet = TRUE;
        if( byTvModueIdx < MAXNUM_PERIEQP_CHNNL )
        {
            m_atTvWallModule[byTvModueIdx] = m_tTvWallModule;
        }
        else
        {
            bRet = FALSE;
        }
        return bRet;
    }

    BOOL32  GetTvModuleByIdx(u8 byTvIdx, TTvWallModule& tTvWallModule) const // �����ȡ����ǽģ��
    {
        BOOL32 bRet = TRUE;
        if( 0 != m_byTvModuleNum && byTvIdx < MAXNUM_PERIEQP_CHNNL)
        {
            tTvWallModule = m_atTvWallModule[byTvIdx];
        }
        else
        {
            bRet = FALSE;
        }
        return bRet;
    }

    BOOL32  GetTvModuleByTvId(u8 byTvId, TTvWallModule& tTvWallModule) const
    {
        BOOL32 bRet = TRUE;
        if( 0 != m_byTvModuleNum )
        {
            for(u8 byTvLp = 0; byTvLp < MAXNUM_PERIEQP_CHNNL; byTvLp++)
            {
                if( byTvId == m_atTvWallModule[byTvLp].m_tTvWall.GetEqpId() )
                {
                    tTvWallModule = m_atTvWallModule[byTvLp];
                    break;
                }
            }
        }
        else
        {
            bRet = FALSE;
        }
        return bRet;
    }

    void SetTvWallMember(u8 byTvId, u8 byTvChl, u8 byMtIdx, u8 byMemberType)
    {
        for(u8 byTvLp = 0; byTvLp < MAXNUM_PERIEQP_CHNNL; byTvLp++)
        {
            if(m_atTvWallModule[byTvLp].GetTvEqp().GetEqpId() == byTvId)
            {
                m_atTvWallModule[byTvLp].SetTvChannel(byTvChl, byMtIdx, byMemberType);
                break;
            }
        }
    }

    void RemoveMtByTvId(u8 byTvId, u8 byMtIdx )
    {
        for(u8 byTvLp = 0; byTvLp < MAXNUM_PERIEQP_CHNNL; byTvLp++)
        {
            if(m_atTvWallModule[byTvLp].GetTvEqp().GetEqpId() == byTvId)
            {
                m_atTvWallModule[byTvLp].RemoveMtInTvMember(byMtIdx);
                break;
            }
        }
    }

    void Clear(void)
    {
        m_byTvModuleNum = 0;
        memset(m_atTvWallModule, 0, sizeof(m_atTvWallModule) );
    }

}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//����ϳ�ģ��ṹ 
struct TVmpModule
{                        
	TVMPParam m_tVMPParam;                              //���ָ���Ļ���ϳɲ���
	u8        m_abyVmpMember[MAXNUM_MPUSVMP_MEMBER];        //���ָ���Ļ���ϳɳ�Ա������������ʱTMtAlias��������+1��
    u8        m_abyMemberType[MAXNUM_MPUSVMP_MEMBER];       //����ϳɳ�Ա�ĸ��淽ʽ, VMP_MEMBERTYPE_MCSSPEC, VMP_MEMBERTYPE_SPEAKER...

    TVmpModule(void) { EmptyMember(); }

    // ������г�Ա
    void EmptyMember()
    {
        memset(this, 0, sizeof(TVmpModule));    
    }

    // ����ĳ��ͨ��
    void SetVmpMember(u8 byChnlIdx, u8 byMtIdx, u8 byMemberType)
    {
        if (byChnlIdx < MAXNUM_VMP_MEMBER)
        {
            m_abyVmpMember[byChnlIdx]  = byMtIdx;
            m_abyMemberType[byChnlIdx] = byMemberType;
        }
    }

    // �Ƴ�ĳ��ͨ��
    void RemoveVmpMember(u8 byChnlIdx) 
    {
        if(byChnlIdx < MAXNUM_VMP_MEMBER)
        {
            m_abyVmpMember[byChnlIdx]  = 0;
            m_abyMemberType[byChnlIdx] = 0;
        }
    }

    // ���úϳɲ���
    void SetVmpParam(const TVMPParam &tParam)
    {
        m_tVMPParam = tParam;
    }

    // ȡ�úϳɲ���
    TVMPParam GetVmpParam()
    {
        return m_tVMPParam;
    }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//������Ϣ�����ṹ
struct TBasicConfInfo
{
    TMt m_tSpeaker;
	TMt m_tChairMan;

public:
    TBasicConfInfo(void) { memset(this, 0, sizeof(TBasicConfInfo)); }
    void    SetSpeaker(const TMt & tSpeaker) { m_tSpeaker = tSpeaker; }
    TMt     GetSpeaker(void) const { return m_tSpeaker; }
    void    SetChairman(const TMt & tChair) { m_tChairMan = tChair; }
    TMt     GetChairman(void) const { return m_tChairMan; }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//�򻯵Ļ�����Ϣ�ṹ
struct TSimConfInfo : public TBasicConfInfo
{
//[20100526]fxh ��R6-SP3���룬����������ʵ�ֻ���״̬��ͨ��
protected:
// 	u8  m_byVACMode;
// 	u8  m_byDiscussMode;
	u8  m_byReserved1;
	u8  m_byMixMode;
//[20100526]
	u8  m_byVMPMode;
	u8  m_byReserved;
public:
// 	void   SetVACMode(BOOL bVACMode){ m_byVACMode = bVACMode;} 
// 	BOOL   IsVACMode( void ) const { return m_byVACMode == 0 ? FALSE : TRUE; }
// 	void   SetDiscussMode(u8   byDiscussMode){ m_byDiscussMode = byDiscussMode;} 
// 	BOOL   IsDiscussMode( void ) const { return m_byDiscussMode == 0 ? FALSE : TRUE; }
	//���õ��ǻ���ģʽ
	void   SetMixMode(u8   byMixMode){ m_byMixMode = byMixMode;} 
	u8     GetMixerMode() const { return m_byMixMode; }

	//�ж��ǲ�����������
	BOOL   IsVACMode( void ) const { return (m_byMixMode == mcuVacMix) || (m_byMixMode == mcuVacWholeMix) || (m_byMixMode == mcuVacPartMix) ? TRUE : FALSE; }
	//�ж��ǲ��ǻ�������
	BOOL   IsDiscussMode( void ) const { return (m_byMixMode == mcuWholeMix) || (m_byMixMode == mcuVacWholeMix) ? TRUE : FALSE; }
	//�ж�ʱ���Ƕ��ƻ���
	BOOL   IsSpecMix( void ) const {return (m_byMixMode == mcuPartMix) || (m_byMixMode == mcuVacPartMix) ? TRUE : FALSE; }

	void   SetVMPMode(u8   byVMPMode){ m_byVMPMode = byVMPMode;} 
	u8     GetVMPMode( void ) const { return m_byVMPMode; }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;


//������鷽ʽ�ṹ(�����л�ı�), sizeof = 24
struct TConfMode
{
protected:
	u8     m_byTakeMode;        //������з�ʽ: 0-ԤԼ 1-��ʱ 2-����ģ�� 
	u8     m_byLockMode;        //����������ʽ: 0-������,���л�ؿɼ��ɲ��� 1-������������˻��� 2-ĳ���������̨����
    u8     m_byCallMode;        //�����ն˷�ʽ: 0-�������նˣ��ֶ����� 1-����һ�� 2-��ʱ����δ����ն�
    u8     m_byRollCallMode;    //���������ʽ��0-�ǵ���ģʽ��1-VMP����ģʽ��2-�����˵���ģʽ��3-�������˵���ģʽ.
    u8     m_byHduInBatchPoll;  //������hduԤ���Ƿ���������ѯ 0-����û�н���hdu������ѯ��1-����hdu������ѯ��2-��ͣ������ѯ

	//u8     m_byVACMode;       //����������ʽ: 0-�����������������Ʒ���(���ݿ��Ʒ���) 1-���������������Ʒ���
	//u8     m_byAudioMixMode;  //������ʽ:     0-������ 1-���ڽ���ĳ�ֻ���
	u8     m_byRecordMode;      //����¼��ʽ: (BIT:0-6)0-��¼�� 1-¼�� 2-¼����ͣ; BIT7 = 0 ʵʱ 1��֡¼��
	u8     m_byPlayMode;        //�������ʽ: 0-������ 1-���� 2-������ͣ 3-��� 4-����
	u8     m_byBasMode;         //�������䷽ʽ: BIT0-�Ƿ�RTPͷ���� BIT1-�Ƿ��������� BIT2-�Ƿ���������
	u8     m_byPollMode;        //������ѯ��ʽ: 0-����ѯ�㲥 1-��ͼ����ѯ�㲥 2-��������
    u8     m_byHDBasMode;       //�������䷽ʽ: BIT0-�Ƿ��������Ƶ���� BIT1-�Ƿ�˫������ BIT2-�Ƿ���弶������ // zgc, 2008-08-21
	//u8     m_byDiscussMode;   //��������ģʽ: 0-������ģʽ(�ݽ�ģʽ) 1-����ģʽ(���ƻ�������)
	u8     m_byForceRcvSpeaker; //ǿ���տ�����: 0-��ǿ���տ������� 1-ǿ���տ�������
	u8     m_byNoChairMode;     //������ϯģʽ: 0-��������ϯ��ʽ 1-����ϯ��ʽ
	u8     m_byRegToGK;         //����ע��GK���: 0-����δ��GK��ע�� 1-������GK�ϳɹ�ע��
    u8     m_byReserved6;
	//u8     m_byMixSpecMt;		//�Ƿ�ָ���ն˻���: 0-���Ƕ��ƻ���(���ܻ���) 1-ָ���ն˻���
	u8	   m_byGkCharge;		//gk�Ʒ���֤�Ƿ�ͨ�� 1��ͨ����0����֤ʧ��
	u8	   m_byReserved2;		//�����ֶ�
	u32    m_dwCallInterval;    //��ʱ����ʱ�ĺ��м����(��λ���룬��СΪ5��)��������
	u32    m_dwCallTimes;       //��ʱ����ʱ�ĺ��д�����������
	
public:
	TConfMode( void ){ memset( this, 0, sizeof(TConfMode) ); }
    void   SetTakeMode(u8 byTakeMode){ m_byTakeMode = byTakeMode | (m_byTakeMode&0x80); } 
    u8     GetTakeMode( void ) const { return (m_byTakeMode&0x0F); }

	u8     GetHduInBatchPoll( void ){ return m_byHduInBatchPoll; }
	void   SetHduInBatchPoll( u8 byHduInBatchPoll ){ m_byHduInBatchPoll = byHduInBatchPoll; }

    void   SetTakeFromFile(BOOL32 bFromFile) // MCU �ڲ�ʹ��
    {
        if (bFromFile)
            m_byTakeMode |= 0x80;
        else
            m_byTakeMode &= 0x0F;
    }
    BOOL32 IsTakeFromFile(void) const
    {
        return ((m_byTakeMode&0x80)==0x80);
    }
    void   SetLockMode(u8   byLockMode){ m_byLockMode = byLockMode;} 
    u8     GetLockMode( void ) const { return m_byLockMode; }
    void   SetCallMode(u8   byCallMode){ m_byCallMode = byCallMode;} 
    u8     GetCallMode( void ) const { return m_byCallMode; }
    void   SetRollCallMode( u8 byMode ) { m_byRollCallMode = byMode;    }
    u8     GetRollCallMode( void ) const { return m_byRollCallMode;    }
	void   SetCallInterval(u32 dwCallInterval){ m_dwCallInterval = htonl(dwCallInterval);} 
    u32    GetCallInterval( void ) const { return ntohl(m_dwCallInterval); }
	void   SetCallTimes(u32 dwCallTimes){ m_dwCallTimes = htonl(dwCallTimes);} 
    u32    GetCallTimes( void ) const { return ntohl(m_dwCallTimes); }
    //void   SetVACMode(BOOL bVACMode){ m_byVACMode = bVACMode;} 
    //BOOL   IsVACMode( void ) const { return m_byVACMode == 0 ? FALSE : TRUE; }
    //void   SetAudioMixMode(BOOL bAudioMixMode){ m_byAudioMixMode = bAudioMixMode;} 
    //BOOL   IsAudioMixMode( void ) const { return m_byAudioMixMode == 0 ? FALSE : TRUE; }
	void   SetRegToGK( BOOL bRegToGK ){ m_byRegToGK = bRegToGK; }
	BOOL   IsRegToGK( void ) const { return m_byRegToGK == 0 ? FALSE : TRUE; }
    void   SetGkCharge( BOOL bCharge ) { m_byGkCharge = bCharge ? 1 : 0; }
    BOOL   IsGkCharge( void ) const { return (1 == m_byGkCharge ? TRUE : FALSE); }
    void   SetRecordMode(u8   byRecordMode)
	{   byRecordMode   &= 0x7f ;
		m_byRecordMode &= 0x80 ;
		m_byRecordMode |= byRecordMode;
	} 
    u8     GetRecordMode( void ) const { return m_byRecordMode&0x7f; }
	
	//�жϵ�ǰ�Ƿ��ڳ�֡¼�����Ƿ���TRUE���򷵻�FALSE
	BOOL   IsRecSkipFrame() const{ return m_byRecordMode&0x80 ? TRUE:FALSE;}
	//bSkipFrame = TRUE ���õ�ǰΪ��֡¼��,����ʵʱ¼��
	void   SetRecSkipFrame(BOOL bSkipFrame)
	{
		if(bSkipFrame)
			m_byRecordMode |=0x80;
		else 
			m_byRecordMode &=0x7f;
	}
    void   SetPlayMode( u8  byPlayMode ){ m_byPlayMode = byPlayMode;} 
    u8     GetPlayMode( void ) const { return m_byPlayMode; }
    void   SetBasMode( u8  byBasMode, BOOL32 bHasBasMode )
	{ 
		if( bHasBasMode )
		{
			m_byBasMode |= (1<<(byBasMode-1)) ;
		}
		else
		{
			m_byBasMode &= ~(1<<(byBasMode-1));
		}
	} 
    BOOL   GetBasMode( u8  byBasMode ) const 
	{
        if ( CONF_BASMODE_NONE == byBasMode )
            return FALSE;
        else
		    return m_byBasMode & (1<<(byBasMode-1));
	}
    u8     GetBasModeValue() const
    {
        return m_byBasMode;
    }
    void   SetHDBasMode( u8  byHDBasMode, BOOL32 bHasHDBasMode )
    { 
        if( bHasHDBasMode )
        {
            m_byHDBasMode |= (1<<(byHDBasMode-1)) ;
        }
        else
        {
            m_byHDBasMode &= ~(1<<(byHDBasMode-1));
        }
    } 
    BOOL   GetHDBasMode( u8  byHDBasMode ) const 
    {
        if ( CONF_HDBASMODE_NONE == byHDBasMode )
            return FALSE;
        else
            return m_byHDBasMode & (1<<(byHDBasMode-1));
    }
    u8     GetHDBasModeValue() const
    {
        return m_byHDBasMode;
    }
    void   SetPollMode(u8   byPollMode){ m_byPollMode = byPollMode;} 
    u8     GetPollMode( void ) const { return m_byPollMode; }
    //void   SetDiscussMode(u8   byDiscussMode){ m_byDiscussMode = byDiscussMode;} 
    //BOOL   IsDiscussMode( void ) const { return m_byDiscussMode == 0 ? FALSE : TRUE; }  
    void   SetForceRcvSpeaker(u8   byForceRcvSpeaker){ m_byForceRcvSpeaker = byForceRcvSpeaker;} 
    BOOL   IsForceRcvSpeaker( void ) const { return m_byForceRcvSpeaker == 0 ? FALSE : TRUE; }
    void   SetNoChairMode(u8   byNoChairMode){ m_byNoChairMode = byNoChairMode;} 
    BOOL   IsNoChairMode( void ) const { return m_byNoChairMode == 0 ? FALSE : TRUE; }
    //void   SetMixSpecMt( BOOL bMixSpecMt ){ m_byMixSpecMt = bMixSpecMt;} 
    //BOOL   IsMixSpecMt( void ) const { return m_byMixSpecMt == 0 ? FALSE : TRUE; }
	void   Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "\nConfMode:\n" );
		OspPrintf( TRUE, FALSE, "m_byTakeMode: %d\n", m_byTakeMode);
		OspPrintf( TRUE, FALSE, "m_byLockMode: %d\n", m_byLockMode);
		OspPrintf( TRUE, FALSE, "m_byCallMode: %d\n", m_byCallMode);
		OspPrintf( TRUE, FALSE, "m_dwCallInterval: %d\n", GetCallInterval());
		OspPrintf( TRUE, FALSE, "m_dwCallTimes: %d\n", GetCallTimes());
		//OspPrintf( TRUE, FALSE, "m_byVACMode: %d\n", m_byVACMode);
		//OspPrintf( TRUE, FALSE, "m_byAudioMixMode: %d\n", m_byAudioMixMode);
		OspPrintf( TRUE, FALSE, "m_byRecordMode: %d\n", m_byRecordMode);
		OspPrintf( TRUE, FALSE, "m_byPlayMode: %d\n", m_byPlayMode);
		OspPrintf( TRUE, FALSE, "m_byBasMode: %d\n", m_byBasMode);
        OspPrintf( TRUE, FALSE, "m_byHDBasMode: %d\n", m_byHDBasMode);
		OspPrintf( TRUE, FALSE, "m_byPollMode: %d\n", m_byPollMode);
		//OspPrintf( TRUE, FALSE, "m_byDiscussMode: %d\n", m_byDiscussMode);
		OspPrintf( TRUE, FALSE, "m_byForceRcvSpeaker: %d\n", m_byForceRcvSpeaker);
		OspPrintf( TRUE, FALSE, "m_byNoChairMode: %d\n", m_byNoChairMode);
		OspPrintf( TRUE, FALSE, "m_byRegToGK: %d\n", m_byRegToGK);
        OspPrintf( TRUE, FALSE, "m_byGkCharge: %d\n", m_byGkCharge );
		//OspPrintf( TRUE, FALSE, "m_byMixSpecMt: %d\n", m_byMixSpecMt);
		OspPrintf( TRUE, FALSE, "m_byRollCallMode: %d\n", m_byRollCallMode );
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//�������״̬�ṹ, sizeof = 430
struct TConfStatus
{
public:
    TMt 	      m_tChairman;	      //��ϯ�նˣ�MCU��Ϊ0��ʾ����ϯ
    TMt		      m_tSpeaker;		  //�����նˣ�MCU��Ϊ0��ʾ�޷�����
    TConfMode     m_tConfMode;        //���鷽ʽ
    TRecProg	  m_tRecProg;		  //��ǰ¼�����,��¼��״̬ʱ��Ч
    TRecProg	  m_tPlayProg;	      //��ǰ�������,������״̬ʱ��Ч
    TPollInfo     m_tPollInfo;        //������ѯ����,����ѯʱ�н�
    TTvWallPollInfo     m_tTvWallPollInfo;  //����ǽ��ǰ��ѯ����������ѯʱ��Ч
	THduPollInfo  m_tHduPollInfo;     //hdu��ǰ��ѯ����������ѯʱ��Ч
    TMixParam     m_tMixParam;        //��ǰ��������
    TVMPParam     m_tVMPParam;        //��ǰ��Ƶ���ϲ���������Ƶ����ʱ��Ч
    TVMPParam     m_tVmpTwParam;      //��ǰVMPTW����
    u8            m_byPrs;            //��ǰ���ش�״̬


public:
    BOOL   HasChairman(void) const { return m_tChairman.GetMtId()==0 ? FALSE : TRUE; }	
	TMt    GetChairman(void) const { return m_tChairman; }
	void   SetNoChairman(void) { memset( &m_tChairman, 0, sizeof( TMt ) ); }
	void   SetChairman(TMt tChairman) { m_tChairman = tChairman; }
	BOOL   HasSpeaker(void) const { return m_tSpeaker.GetMtId()==0 ? FALSE : TRUE; }
    TMt    GetSpeaker(void) const { return m_tSpeaker; }
	void   SetNoSpeaker(void) { memset( &m_tSpeaker, 0, sizeof( TMt ) ); }
	void   SetSpeaker(TMt tSpeaker) { m_tSpeaker = tSpeaker; }
    void          SetConfMode(TConfMode tConfMode) { m_tConfMode = tConfMode; } 
    TConfMode     GetConfMode(void) const { return m_tConfMode; }
    void          SetRecProg(TRecProg tRecProg){ m_tRecProg = tRecProg; } 
    TRecProg      GetRecProg(void) const { return m_tRecProg; }
    void          SetPlayProg(TRecProg tPlayProg){ m_tPlayProg = tPlayProg; } 
    TRecProg      GetPlayProg(void) const { return m_tPlayProg; }
    void          SetVmpParam(TVMPParam tVMPParam){ m_tVMPParam = tVMPParam;} 
    TVMPParam     GetVmpParam(void) const { return m_tVMPParam; }

	//�������״̬
	BOOL IsScheduled( void ) const { return m_tConfMode.GetTakeMode() == CONF_TAKEMODE_SCHEDULED ? TRUE : FALSE; }
	void SetScheduled( void ){ m_tConfMode.SetTakeMode( CONF_TAKEMODE_SCHEDULED ); }
	BOOL IsOngoing( void ) const { return m_tConfMode.GetTakeMode() == CONF_TAKEMODE_ONGOING ? TRUE : FALSE; }
	void SetOngoing( void ){ m_tConfMode.SetTakeMode( CONF_TAKEMODE_ONGOING ); }
	BOOL IsTemplate( void ) const { return m_tConfMode.GetTakeMode() == CONF_TAKEMODE_TEMPLATE ? TRUE : FALSE; }
	void SetTemplate( void ){ m_tConfMode.SetTakeMode( CONF_TAKEMODE_TEMPLATE ); }
	u8   GetTakeMode( void ) const{ return m_tConfMode.GetTakeMode();	}
	void SetTakeMode( u8 byTakeMode ){ m_tConfMode.SetTakeMode( byTakeMode ); }
    void SetTakeFromFile(BOOL32 bTakeFromFile) { m_tConfMode.SetTakeFromFile(bTakeFromFile); }  // MCU �ڲ�ʹ��
    BOOL IsTakeFromFile(void) const{ return m_tConfMode.IsTakeFromFile(); }

	//���鱣��״̬
	u8   GetProtectMode( void ) const { return m_tConfMode.GetLockMode(); }
    void SetProtectMode( u8   byProtectMode ) { m_tConfMode.SetLockMode( byProtectMode ); }
	
	//������в���
	u8   GetCallMode( void ) const { return m_tConfMode.GetCallMode(); }
	void SetCallMode( u8   byCallMode ){ m_tConfMode.SetCallMode( byCallMode ); }
	void SetCallInterval(u32 dwCallInterval){ m_tConfMode.SetCallInterval( dwCallInterval ); } 
    u32  GetCallInterval( void ) const { return m_tConfMode.GetCallInterval( ); }
	void SetCallTimes(u32 dwCallTimes){ m_tConfMode.SetCallTimes( dwCallTimes ); } 
    u32  GetCallTimes( void ) const { return m_tConfMode.GetCallTimes( ); }

    //�������ģʽ
    u8   GetRollCallMode( void ) const { return m_tConfMode.GetRollCallMode();    }
    void SetRollCallMode( u8 byMode ) { m_tConfMode.SetRollCallMode(byMode);    }
    
    //������״̬(��ʶ�Ƿ���ʹ�û����������������ܻ��������ƻ���������������)    

    //ֱ�ӻ�ȡ������״̬����
    u8     GetMixerMode(void) const { return m_tMixParam.GetMode(); }
    void   SetMixerMode(u8 byMixMode) { m_tMixParam.SetMode(byMixMode); }
    
    TMixParam GetMixerParam(void) const { return m_tMixParam; }
    void   SetMixerParam(TMixParam tAudMixParam){ m_tMixParam = tAudMixParam; }     
    
    //�Ƿ��ڻ���(���ܻ���)
    BOOL32 IsNoMixing(void) const { return mcuNoMix == GetMixerMode() || mcuVacMix == GetMixerMode(); }
    BOOL32 IsMixing(void) const { return !IsNoMixing(); }
    void   SetNoMixing(void) { SetMixerMode( IsVACing() ? mcuVacMix :mcuNoMix );  }

    //�Ƿ����ܻ���
    BOOL32 IsAutoMixing(void) const 
    {
        return (mcuVacWholeMix == GetMixerMode() || mcuWholeMix == GetMixerMode());
    }
    void   SetAutoMixing(BOOL bAutoMix = TRUE)
    {
        u8 byMixMode = mcuNoMix;
        if ( bAutoMix )
        {
            byMixMode = IsVACing() ? mcuVacWholeMix : mcuWholeMix;
        }
        else
        {
            byMixMode = IsVACing() ? mcuVacMix : mcuNoMix;
        }
        SetMixerMode(byMixMode);
        return;
    }
    
    //�Ƿ��ڶ��ƻ���
    BOOL32 IsSpecMixing(void) const
    {
        return (mcuVacPartMix == GetMixerMode() || mcuPartMix == GetMixerMode());
    }
    void   SetSpecMixing(BOOL bMixSpecMt = TRUE)
    {
        u8 byMixMode = mcuNoMix;
        if ( bMixSpecMt )
        {
            byMixMode = IsVACing() ? mcuVacPartMix : mcuPartMix;
        }
        else
        {
            byMixMode = IsVACing() ? mcuVacMix : mcuNoMix;
        }
        SetMixerMode(byMixMode);
    }
    
    //�Ƿ�����������
    BOOL32 IsVACing(void) const
    {
        return ( mcuVacMix == GetMixerMode() ||
                 mcuVacPartMix == GetMixerMode() || 
                 mcuVacWholeMix == GetMixerMode() );
    }
    void   SetVACing(BOOL bVACMode = TRUE)
    {
        u8 byMixMode = mcuNoMix;
        if ( bVACMode )
        {
            switch(GetMixerMode())
            {
            case mcuNoMix:      byMixMode = mcuVacMix;      break;
            case mcuPartMix:    byMixMode = mcuVacPartMix;  break;
            case mcuWholeMix:   byMixMode = mcuVacWholeMix; break;
            default:            byMixMode = GetMixerMode();   break;
            }
        }
        else
        {
            switch(GetMixerMode())
            {
            case mcuVacMix:         byMixMode = mcuNoMix;       break;
            case mcuVacPartMix:     byMixMode = mcuPartMix;     break;
            case mcuVacWholeMix:    byMixMode = mcuWholeMix;    break;
            default:                byMixMode = GetMixerMode();   break;
            }
        }
        SetMixerMode(byMixMode);
        return;
    }
    
    //����ϳɷ�ʽ
	void   SetVMPMode(u8   byVMPMode){ m_tVMPParam.SetVMPMode(byVMPMode); } 
    u8     GetVMPMode( void ) const { return m_tVMPParam.GetVMPMode(); }
	BOOL   IsBrdstVMP( void ) const { return m_tVMPParam.GetVMPMode() != CONF_VMPMODE_NONE && m_tVMPParam.IsVMPBrdst(); }
	void   SetVmpBrdst( BOOL bBrdst ){ m_tVMPParam.SetVMPBrdst( bBrdst ); }
	u8     GetVmpStyle( void ){ return m_tVMPParam.GetVMPStyle(); }
	void   SetVmpStyle( u8 byVMPStyle ){ m_tVMPParam.SetVMPStyle( byVMPStyle ); }
	void   SetVmpSeebyChairman( BOOL bSeebyChair){ m_tVMPParam.SetVMPSeeByChairman(bSeebyChair); }
	BOOL   IsVmpSeeByChairman( void ) const {return m_tVMPParam.IsVMPSeeByChairman();}
    //vmp tvwall    
	void      SetVmpTwMode(u8 byVmpTwMode){ m_tVmpTwParam.SetVMPMode(byVmpTwMode); }
    u8        GetVmpTwMode(void) const { return m_tVmpTwParam.GetVMPMode(); }
    void      SetVmpTwParam(TVMPParam tVmpTwParam) { m_tVmpTwParam = tVmpTwParam; }
    TVMPParam GetVmpTwParam(void) const { return m_tVmpTwParam; }
    u8        GetVmpTwStyle(void) { return m_tVmpTwParam.GetVMPStyle(); }
	void      SetVmpTwStyle(u8 byVmpTwStyle) { m_tVmpTwParam.SetVMPStyle(byVmpTwStyle); }

	//ǿ�ƹ㲥(��ԭ��ǿ�Ʒ����˵ĸ��ͬ���ӿ�������ʱ���޸�)
	BOOL IsMustSeeSpeaker(void) const { return m_tConfMode.IsForceRcvSpeaker(); }
	void SetMustSeeSpeaker(BOOL bMustSeeSpeaker) { m_tConfMode.SetForceRcvSpeaker( bMustSeeSpeaker ); }

	//��������״̬ -- modify bas 2
    BOOL32 IsConfAdapting(void) const { return CONF_BASMODE_NONE != m_tConfMode.GetBasModeValue(); } 
    BOOL32 IsAudAdapting(void) const { return m_tConfMode.GetBasMode(CONF_BASMODE_AUD); }
    BOOL32 IsVidAdapting(void) const { return m_tConfMode.GetBasMode(CONF_BASMODE_VID); }
    BOOL32 IsBrAdapting(void) const { return m_tConfMode.GetBasMode(CONF_BASMODE_BR); }
    BOOL32 IsCasdAudAdapting(void) const { return m_tConfMode.GetBasMode(CONF_BASMODE_CASDAUD); }
    BOOL32 IsCasdVidAdapting(void) const { return m_tConfMode.GetBasMode(CONF_BASMODE_CASDVID); }
    void SetAdaptMode(u8 byBasMode, BOOL32 bAdapt)
    { 
        m_tConfMode.SetBasMode(byBasMode, bAdapt);
    }
    // ��������״̬
	BOOL32 IsConfHDAdapting(void) const { return CONF_HDBASMODE_NONE != m_tConfMode.GetHDBasModeValue(); }
    BOOL32 IsHdVidAdapting(void) const { return m_tConfMode.GetHDBasMode(CONF_HDBASMODE_VID); }
    BOOL32 IsHDDoubleVidAdapting(void) const { return m_tConfMode.GetHDBasMode( CONF_HDBASMODE_DOUBLEVID ) ;}
    BOOL32 IsHdCasdVidAdapting(void) const { return m_tConfMode.GetHDBasMode(CONF_HDBASMODE_CASDVID); }
    void SetHDAdaptMode(u8 byHDBasMode, BOOL32 bAdapt)
    { 
        m_tConfMode.SetHDBasMode(byHDBasMode, bAdapt);
    }

	//������ϯ״̬
	BOOL IsNoChairMode( void ) const { return m_tConfMode.IsNoChairMode(); }
    void SetNoChairMode( BOOL bNoChairMode ) { m_tConfMode.SetNoChairMode( bNoChairMode ); }

	//��ѯ��ʽ
	void   SetPollMode(u8   byPollMode){ m_tConfMode.SetPollMode( byPollMode ); } 
    u8     GetPollMode(){ return m_tConfMode.GetPollMode(); }
	
	//��ѯ����
    void   SetPollInfo(const TPollInfo &tPollInfo){ m_tPollInfo = tPollInfo;} 
    TPollInfo  *GetPollInfo( void ) { return &m_tPollInfo; }
	void   SetPollMedia(u8   byMediaMode){ m_tPollInfo.SetMediaMode( byMediaMode ); } 
    u8     GetPollMedia( void ) const{ return m_tPollInfo.GetMediaMode(); }
	void   SetPollState(u8   byPollState){ m_tPollInfo.SetPollState( byPollState );} 
    u8     GetPollState( void ) const { return m_tPollInfo.GetPollState(); }
    void   SetMtPollParam(TMtPollParam tMtPollParam){ m_tPollInfo.SetMtPollParam( tMtPollParam ); } 
    TMtPollParam  GetMtPollParam() const{ return m_tPollInfo.GetMtPollParam(); }

    //����ǽ��ѯ����
    void   SetTvWallPollInfo(const TTvWallPollInfo &tPollInfo){ m_tTvWallPollInfo = tPollInfo;} 
    TTvWallPollInfo  *GetTvWallPollInfo( void ) { return &m_tTvWallPollInfo; }    
    void   SetTvWallPollState(u8   byPollState){ m_tTvWallPollInfo.SetPollState( byPollState );} 
    u8     GetTvWallPollState( void ) const { return m_tTvWallPollInfo.GetPollState(); }
    void   SetTvWallMtPollParam(TMtPollParam tMtPollParam){ m_tTvWallPollInfo.SetMtPollParam( tMtPollParam ); } 
    TMtPollParam  GetTvWallMtPollParam(){ return m_tTvWallPollInfo.GetMtPollParam(); }

	//hdu��ѯ����
    void   SetHduPollInfo(const THduPollInfo &tPollInfo){ m_tHduPollInfo = tPollInfo; }
    THduPollInfo  *GetHduPollInfo( void ) { return &m_tHduPollInfo; }    
    void   SetHduPollState(u8   byPollState){ m_tHduPollInfo.SetPollState( byPollState ); } 
    u8     GethduPollState( void ) const { return m_tHduPollInfo.GetPollState(); }
    void   SetHduMtPollParam(TMtPollParam tMtPollParam){ m_tHduPollInfo.SetMtPollParam( tMtPollParam ); } 
    TMtPollParam  GetHduMtPollParam(){ return m_tHduPollInfo.GetMtPollParam(); }

	//����¼��״̬	
	BOOL IsNoRecording( void ) const{ return m_tConfMode.GetRecordMode() == CONF_RECMODE_NONE ? TRUE : FALSE; }
	void SetNoRecording( void ){ m_tConfMode.SetRecordMode( CONF_RECMODE_NONE ); }
	BOOL IsRecording( void ) const{ return m_tConfMode.GetRecordMode() == CONF_RECMODE_REC ? TRUE : FALSE; }
	void SetRecording( void ){ m_tConfMode.SetRecordMode( CONF_RECMODE_REC ); }
	BOOL IsRecPause( void ) const{ return m_tConfMode.GetRecordMode() == CONF_RECMODE_PAUSE ? TRUE : FALSE; }
	void SetRecPause( void ){ m_tConfMode.SetRecordMode( CONF_RECMODE_PAUSE ); }

	//�������״̬
	BOOL IsNoPlaying( void ) const{ return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_NONE ? TRUE : FALSE; }
	void SetNoPlaying( void ){ m_tConfMode.SetPlayMode( CONF_PLAYMODE_NONE ); }
	BOOL IsPlaying( void ) const { return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_PLAY ? TRUE : FALSE; }
	void SetPlaying( void ){ m_tConfMode.SetPlayMode( CONF_PLAYMODE_PLAY ); }
	BOOL IsPlayPause( void )const { return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_PAUSE ? TRUE : FALSE; }
	void SetPlayPause( void ){ m_tConfMode.SetPlayMode( CONF_PLAYMODE_PAUSE ); }
	BOOL IsPlayFF( void )const { return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_FF ? TRUE : FALSE; }
	void SetPlayFF( void ) { m_tConfMode.SetPlayMode( CONF_PLAYMODE_FF ); }
	BOOL IsPlayFB( void )const { return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_FB ? TRUE : FALSE; }
	void SetPlayFB( void ){ m_tConfMode.SetPlayMode( CONF_PLAYMODE_FB ); }
	// zgc, 2007-02-27, �������ؼ�֡�ӳ�����
	BOOL IsPlayReady( void ) const{ return m_tConfMode.GetPlayMode() == CONF_PLAYMODE_PLAYREADY ? TRUE : FALSE; }
	void SetPlayReady( void ){ m_tConfMode.SetPlayMode( CONF_PLAYMODE_PLAYREADY ); }
	// zgc, 2007-02-27, end

	//���ش�״̬
	void SetPrsing( BOOL bPrs ){ m_byPrs = bPrs; }
	BOOL IsPrsing( void ){ return m_byPrs; }

	//ע��GK���
	void SetRegToGK( BOOL bRegToGK ){ m_tConfMode.SetRegToGK( bRegToGK ); }
	BOOL IsRegToGK( void ) const{ return m_tConfMode.IsRegToGK(); }

    // xsl [11/16/2006] GK�Ʒ����
    void SetGkCharge( BOOL bCharge ) { m_tConfMode.SetGkCharge( bCharge ); }
    BOOL IsGkCharge( void ) const { return m_tConfMode.IsGkCharge(); }

	void Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "\nConfStatus:\n" );
        if(m_tChairman.IsNull())  
            OspPrintf( TRUE, FALSE, "Chairman: Null\n" );
        else 
            OspPrintf( TRUE, FALSE, "Chairman: Mcu%dMt%d\n", m_tChairman.GetMcuId(), m_tChairman.GetMtId() );
        if(m_tSpeaker.IsNull())
            OspPrintf( TRUE, FALSE, "Speaker: Null\n" );
        else
		    if (m_tSpeaker.GetType() == TYPE_MT)
                OspPrintf( TRUE, FALSE, "Speaker: Mcu%dMt%d\n", m_tSpeaker.GetMcuId(), m_tSpeaker.GetMtId() );
            else
                OspPrintf( TRUE, FALSE, "Speaker: Mcu%dEqp%d\n", m_tSpeaker.GetMcuId(), m_tSpeaker.GetEqpId() );
        OspPrintf( TRUE, FALSE, "VmpMode: %d\n", m_tVMPParam.GetVMPMode() );
        OspPrintf( TRUE, FALSE, "TWVmpMode: %d\n", m_tVmpTwParam.GetVMPMode() );
        OspPrintf( TRUE, FALSE, "MixerMode: %d\n", GetMixerMode() );
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

// zw [06/27/2008] ��m_byAudioMediaType��װΪTAudioStreamCap��������ΪTAudAACCap����
//������Ƶý���ʽ������(len:1)
struct TAudioStreamCap
{
protected:
	u8 m_byAudioMediaType;

public:
	TAudioStreamCap() { Clear(); }

	void Clear(void)
    {
        m_byAudioMediaType = MEDIA_TYPE_NULL;
    }

    void SetMediaType(u8 byAudioMediaType) { m_byAudioMediaType = byAudioMediaType; }	
    u8	 GetMediaType() const { return m_byAudioMediaType; }
}
PACKED
;

struct TAudAACCap : public TAudioStreamCap
{
protected:
	u8  m_bySampleFreq;
    u8  m_byChnlType ;
    u16 m_wBitrate;
    u8  m_byMaxFrameNum;        

public:
    TAudAACCap() { Clear(); }

	void Clear(void)
    {
        m_bySampleFreq  = 0;
        m_byChnlType    = 0;
        m_wBitrate      = 0;
        m_byMaxFrameNum = 0;
    }

    void	SetSampleFreq(u8 bySampleFreq)  { m_bySampleFreq = bySampleFreq; }	
    u8		GetSampleFreq() const { return m_bySampleFreq; } 
    
    void	SetChnlType(u8 byChnlType)  { m_byChnlType = byChnlType; }	
    u8		GetChnlType() const { return m_byChnlType; } 

    void	SetBitrate(u16 wBitrate)  { m_wBitrate = htons(wBitrate); }	
    u16		GetBitrate() const { return ntohs(m_wBitrate); } 

    void	SetMaxFrameNum(u8 byMaxFrameNum)  { m_byMaxFrameNum = byMaxFrameNum; }	
    u8		GetMaxFrameNum() const { return m_byMaxFrameNum; } 
}
PACKED
;

//������Ƶý���ʽ������(len:5)
struct TVideoStreamCap
{
protected:
    u16		m_wMaxBitRate;   
    u8		m_byMediaType;   
    u8      m_byResolution;	//�ֱ��� VIDEO_FORMAT_AUTO, ...
	u8      m_byFrameRate;  //֡�� MPI������ H.264 ���� FPS
    
public:
    TVideoStreamCap() { Clear(); }
    
    void    Clear(void)
    {
        m_wMaxBitRate = 0;
        m_byFrameRate = 0;
        m_byMediaType = MEDIA_TYPE_NULL;
        m_byResolution = VIDEO_FORMAT_CIF;
    }   
    
    void	SetMediaType(u8 byMediaType)  {  m_byMediaType = byMediaType; }	
    u8		GetMediaType() const { return m_byMediaType; }
    
    void    SetResolution(u8 byRes) {   m_byResolution = byRes;    }
    u8      GetResolution(void) const   {   return m_byResolution;    }

    void    SetFrameRate(u8 byFrameRate)
    {
        if ( MEDIA_TYPE_H264 == m_byMediaType )
        {
            OspPrintf( TRUE, FALSE, "Function has been preciated, try SetUserDefFrameRate\n" );
            return;
        }
        m_byFrameRate = byFrameRate;
    }
    u8      GetFrameRate(void) const
    {
        if ( MEDIA_TYPE_H264 == m_byMediaType )
        {
            OspPrintf( TRUE, FALSE, "Function has been preciated, try GetUserDefFrameRate\n" );
            return 0;
        }
        return m_byFrameRate;
    }

    // guzh [12/1/2007] �Զ���֡�ʵı���/��ȡ
    void    SetUserDefFrameRate(u8 byActFrameRate) { m_byFrameRate = VIDEO_FPS_USRDEFINED+byActFrameRate; }
    BOOL32  IsFrameRateUserDefined() const {return (m_byFrameRate>VIDEO_FPS_USRDEFINED); }
    u8      GetUserDefFrameRate(void) const { return IsFrameRateUserDefined() ? m_byFrameRate-VIDEO_FPS_USRDEFINED : m_byFrameRate; }
    
    void	SetMaxBitRate(u16 wMaxRate) {m_wMaxBitRate = htons(wMaxRate); }
    u16		GetMaxBitRate() const { return ntohs(m_wMaxBitRate); }


    BOOL32 IsResLower(u8 bySrcRes, u8 byDstRes)
    {
        if (!IsResMatched(bySrcRes, byDstRes))
        {
            return FALSE;
        }
        u16 wSrcWidth = 0;
        u16 wDstWidth = 0;
        u16 wSrcHeight = 0;
        u16 wDstHeight = 0;

        GetWHByRes(bySrcRes, wSrcWidth, wSrcHeight);
        GetWHByRes(byDstRes, wDstWidth, wDstHeight);
        
        if (wSrcWidth < wDstWidth &&
            wSrcHeight < wDstHeight)
        {
            return TRUE;
        }
        return FALSE;
    }

private:
    void GetWHByRes(u8 byRes, u16 &wWidth, u16 &wHeight)
    {
        wWidth = 0;
        wHeight = 0;
    
        switch(byRes)
        {
        case VIDEO_FORMAT_SQCIF_112x96:
            wWidth = 112;
            wHeight = 96;
            break;
        
        case VIDEO_FORMAT_SQCIF_96x80:
            wWidth = 96;
            wHeight = 80;
            break;
        
        case VIDEO_FORMAT_SQCIF:
            wWidth = 128;
            wHeight = 96;
            break;
        
        case VIDEO_FORMAT_QCIF:
            wWidth = 176;
            wHeight = 144;
            break;
        
        case VIDEO_FORMAT_CIF:
            wWidth = 352;
            wHeight = 288;
            break;
        
        case VIDEO_FORMAT_2CIF:
            wWidth = 352;
            wHeight = 576;
            break;
        
        case VIDEO_FORMAT_4CIF:
        
            //���ھ����ܲ��ſ��ǣ�����ȡ��ֵ
            wWidth = 704;
            wHeight = 576;
            break;
        
        case VIDEO_FORMAT_16CIF:
            wWidth = 1048;
            wHeight = 1152;
            break;
        
        case VIDEO_FORMAT_AUTO:
            //������
            break;
        
        case VIDEO_FORMAT_SIF:
            wWidth = 352;
            wHeight = 240;
            break;
        
        case VIDEO_FORMAT_2SIF:
            wWidth = 352;
            wHeight = 480;
            break;
        
        case VIDEO_FORMAT_4SIF:
            wWidth = 704;
            wHeight = 480;
            break;
        
        case VIDEO_FORMAT_VGA:
            wWidth = 640;
            wHeight = 480;
            break;
        
        case VIDEO_FORMAT_SVGA:
            wWidth = 800;
            wHeight = 600;
            break;
        
        case VIDEO_FORMAT_XGA:
            wWidth = 1024;
            wHeight = 768;
            break;

        case VIDEO_FORMAT_W4CIF:
            wWidth = 1024;
            wHeight = 576;
            break;

        case VIDEO_FORMAT_HD720:
            wWidth = 1280;
            wHeight = 720;
            break;

        case VIDEO_FORMAT_SXGA:
            wWidth = 1280;
            wHeight = 1024;
            break;

        case VIDEO_FORMAT_UXGA:
            wWidth = 1600;
            wHeight = 1200;
            break;

        case VIDEO_FORMAT_HD1080:
            wWidth = 1920;
            wHeight = 1088;
            break;
        default:
            break;
        }
        if ( 0 == wHeight || 0 == wWidth )
        {
            OspPrintf( TRUE, FALSE, "[TVideoStreamCap::GetWHByRes] unexpected res.%d, ignore it\n", byRes );
        }
        return;
    }

    BOOL32 IsResMatched(u8 bySrcRes, u8 byDstRes)
    {
        BOOL32 bMatched = FALSE;
        if (IsResPresentation(bySrcRes) && IsResPresentation(byDstRes))
        {
            bMatched = TRUE;
        }
        else if (IsResLive(bySrcRes) && IsResLive(byDstRes))
        {
            bMatched = TRUE;
        }
        return bMatched;
    }
    
    BOOL32 IsResPresentation(u8 byRes)
    {
        BOOL32 bPresentation = FALSE;
        
        switch(byRes)
        {
        case VIDEO_FORMAT_VGA:
        case VIDEO_FORMAT_SVGA:
        case VIDEO_FORMAT_XGA:
        case VIDEO_FORMAT_SXGA:
        case VIDEO_FORMAT_UXGA:
            bPresentation = TRUE;
            break;
        default:
            break;
        }
        return bPresentation;
    }
    
    BOOL32 IsResLive(u8 byRes)
    {
        BOOL32 bLive = FALSE;
        
        switch(byRes)
        {
        case VIDEO_FORMAT_CIF:
        case VIDEO_FORMAT_2CIF:
        case VIDEO_FORMAT_4CIF:
        case VIDEO_FORMAT_16CIF:
            
        case VIDEO_FORMAT_SIF:
        case VIDEO_FORMAT_2SIF:
        case VIDEO_FORMAT_4SIF:
            
        case VIDEO_FORMAT_W4CIF:
        case VIDEO_FORMAT_HD720:
        case VIDEO_FORMAT_HD1080:
            bLive = TRUE;
            break;
        //����������
        case VIDEO_FORMAT_AUTO:
        case VIDEO_FORMAT_SQCIF_112x96:
        case VIDEO_FORMAT_SQCIF_96x80:
            break;
        default:
            break;
        }
        return bLive;
    }
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//˫����������(len:6)
struct TDStreamCap : public TVideoStreamCap
{
protected:
    u8  m_byIsH239Type;    

public:
    TDStreamCap() { Reset(); }

    void SetSupportH239(BOOL32 bSupport) { m_byIsH239Type = (bSupport ? 1:0); }
    BOOL32   IsSupportH239(void) const { return (0 != m_byIsH239Type); }

    void Reset(void)
    {
        Clear();
        m_byIsH239Type = 0;
    }

    BOOL32 IsResolutionLower(u8 bySrcRes, u8 byDstRes)
    {
        return IsResLower(bySrcRes, byDstRes);
    }
    BOOL32 operator < (const TDStreamCap &tDsCap)
    {
        if (tDsCap.GetMediaType() != GetMediaType())
        {
            //�������䣺��ƥ����ΪС��
            return TRUE;
        }
        
        u8 bySrcFrmRate = MEDIA_TYPE_H264 == GetMediaType() ? GetUserDefFrameRate() : GetFrameRate();
        u8 byDstFrmRate = MEDIA_TYPE_H264 == tDsCap.GetMediaType() ? tDsCap.GetUserDefFrameRate() : tDsCap.GetFrameRate(); 
        
        if (IsResLower(GetResolution(), tDsCap.GetResolution()) ||
            GetMaxBitRate() < tDsCap.GetMaxBitRate() ||
            bySrcFrmRate < byDstFrmRate)
        {
            return TRUE;
        }
        return FALSE;
    }

    BOOL32 operator != (const TDStreamCap &tDsCap)
    {
        if (tDsCap.GetMediaType() != GetMediaType())
        {
            return TRUE;
        }
        
        u8 bySrcFrmRate = MEDIA_TYPE_H264 == GetMediaType() ? GetUserDefFrameRate() : GetFrameRate();
        u8 byDstFrmRate = MEDIA_TYPE_H264 == tDsCap.GetMediaType() ? tDsCap.GetUserDefFrameRate() : tDsCap.GetFrameRate(); 
        
        if (IsResLower(GetResolution(), tDsCap.GetResolution()) ||
            GetMaxBitRate() != tDsCap.GetMaxBitRate() ||
            bySrcFrmRate != byDstFrmRate)
        {
            return TRUE;
        }
        return FALSE;
    }
    BOOL32 IsNull()
    {
        return MEDIA_TYPE_NULL == GetMediaType();
    }
};

//ͬʱ�������ṹ(len:6)
struct TSimCapSet
{
protected:
	TVideoStreamCap  m_tVideoCap;
    TAudioStreamCap  m_tAudioCap;
//	u8  m_byAudioMediaType;  

public:
    TSimCapSet( void )	{ Clear(); }

	void SetVideoMediaType( u8 byMediaType ) { m_tVideoCap.SetMediaType(byMediaType); }
    u8   GetVideoMediaType( void ) const { return m_tVideoCap.GetMediaType(); }

	void SetVideoResolution( u8 byRes ) { m_tVideoCap.SetResolution(byRes); }
    u8   GetVideoResolution( void ) const { return m_tVideoCap.GetResolution(); }

	void SetVideoMaxBitRate( u16 wMaxRate ) { m_tVideoCap.SetMaxBitRate(wMaxRate); }
	u16  GetVideoMaxBitRate( void ) const { return m_tVideoCap.GetMaxBitRate(); }

    void SetVideoFrameRate(u8 byFrameRate) { m_tVideoCap.SetFrameRate(byFrameRate); }
    u8   GetVideoFrameRate(void) const { return m_tVideoCap.GetFrameRate(); }

    // guzh [12/1/2007] �Զ���֡�ʵı���/��ȡ
    void SetUserDefFrameRate(u8 byActFrameRate) { m_tVideoCap.SetUserDefFrameRate(byActFrameRate); }
    BOOL32 IsFrameRateUserDefined() const {return m_tVideoCap.IsFrameRateUserDefined(); }
    u8   GetUserDefFrameRate(void) const { return m_tVideoCap.GetUserDefFrameRate(); }
    
    void SetAudioMediaType( u8 byAudioMediaType ) { m_tAudioCap.SetMediaType(byAudioMediaType);}
    u8   GetAudioMediaType( void ) const { return m_tAudioCap.GetMediaType(); }

    void SetVideoCap( TVideoStreamCap &tVidCap ){ memcpy(&m_tVideoCap, &tVidCap, sizeof(TVideoStreamCap)); }
    TVideoStreamCap   GetVideoCap( void ) const { return m_tVideoCap; }

	BOOL32   operator ==( const TSimCapSet & tSimCapSet ) const  //�ж��Ƿ����(ֻ�ж�����ͼ��)
	{
		if( GetVideoMediaType() == tSimCapSet.GetVideoMediaType() && 
			GetAudioMediaType() == tSimCapSet.GetAudioMediaType() &&
            GetVideoMediaType() != MEDIA_TYPE_NULL && 
            GetAudioMediaType() != MEDIA_TYPE_NULL)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
    
    BOOL32 operator < (const TSimCapSet &tSimCapSet) //�ж�С��
    {
        if (tSimCapSet.IsNull())
        {
            return FALSE;
        }
        if (GetVideoMediaType() != tSimCapSet.GetVideoMediaType() /*&& 
			GetAudioMediaType() != tSimCapSet.GetAudioMediaType()*/)
        {
            //�������䣺��ƥ����ΪС��
            return TRUE;
        }
        
        u8 bySrcFrmRate = MEDIA_TYPE_H264 == GetVideoMediaType() ? GetUserDefFrameRate() : GetVideoFrameRate();
        u8 byDstFrmRate = MEDIA_TYPE_H264 == tSimCapSet.GetVideoMediaType() ? tSimCapSet.GetUserDefFrameRate() : tSimCapSet.GetVideoFrameRate(); 
        if (m_tVideoCap.IsResLower(GetVideoResolution(), tSimCapSet.GetVideoResolution()) ||
            GetVideoMaxBitRate() < tSimCapSet.GetVideoMaxBitRate())
        {
            return TRUE;
        }

        if((abs(bySrcFrmRate-byDstFrmRate) == 5) &&
            (bySrcFrmRate == 30 || byDstFrmRate == 30))
        {
            return FALSE;
        }

        if (bySrcFrmRate < byDstFrmRate)
        {
            return TRUE;
        }
        
        return FALSE;
    }
    
    BOOL32 operator != (const TSimCapSet &tSim)
    {
        if(tSim.IsNull())
        {
            return FALSE;
        }
        if(GetVideoMediaType() != tSim.GetVideoMediaType())
        {
            return TRUE;
        }
        if(m_tVideoCap.IsResLower(GetVideoResolution(), tSim.GetVideoResolution()) ||
           GetVideoMaxBitRate() < tSim.GetVideoMaxBitRate())
        {
            return TRUE;
        }
        u8 bySrcFrmRate = MEDIA_TYPE_H264 == GetVideoMediaType() ? GetUserDefFrameRate() : GetVideoFrameRate();
        u8 byDstFrmRate = MEDIA_TYPE_H264 == tSim.GetVideoMediaType() ? tSim.GetUserDefFrameRate() : tSim.GetVideoFrameRate(); 
        
        if((abs(bySrcFrmRate-byDstFrmRate) == 5) &&
           (bySrcFrmRate == 30 || byDstFrmRate == 30))
        {
            return FALSE;
        }
        if(bySrcFrmRate != byDstFrmRate)
        {
            return TRUE;
        }
        return FALSE;
    }
    
	BOOL32   IsNull( void ) const
	{
		if(	GetVideoMediaType() == MEDIA_TYPE_NULL && GetAudioMediaType() == MEDIA_TYPE_NULL )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	void  Clear( void )
	{
        m_tVideoCap.Clear();
        SetAudioMediaType(MEDIA_TYPE_NULL);
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//�������ṹ(len:23)
struct TCapSupport
{
protected:		
	u8          m_bySupportMMcu;        //�Ƿ�֧�ֺϲ�����
    u8          m_bySupportH224;	    //�Ƿ�֧��H224
    u8          m_bySupportT120;	    //�Ƿ�֧��T120  
    u8          m_byEncryptMode;        //����ģʽCONF_ENCRYPTMODE_NONE, CONF_ENCRYPTMODE_DES, CONF_ENCRYPTMODE_AES
    u8          m_byDStreamType;        //VIDEO_DSTREAM_H263PLUS,...

    //˫������
    TDStreamCap   m_tDStreamCap; 

	//ͬʱ������
	TSimCapSet  m_tMainSimCapSet;    //����ͬʱ������
	TSimCapSet  m_tSecondSimCapSet;  //����ͬʱ������

public:
	//���캯��
    TCapSupport( void ) { Clear(); }
           
	void    SetSupportMMcu( BOOL32 bMMcu) { m_bySupportMMcu = (bMMcu ? 1:0); }
	BOOL32  IsSupportMMcu() const { return (0 != m_bySupportMMcu); }

    void    SetEncryptMode(u8 byMode) { m_byEncryptMode = byMode; }
    u8      GetEncryptMode(void) const { return m_byEncryptMode; }
    
    void    SetSupportH224(BOOL32  bSupportH224){ m_bySupportH224 = (bSupportH224 ? 1:0); } 
    BOOL32  IsSupportH224( void ) const { return (0 != m_bySupportH224); }  
    
    void    SetSupportT120(BOOL32   bSupportT120) { m_bySupportT120 = (bSupportT120 ? 1:0);} 
    BOOL32  IsSupportT120(void) const { return (0 != m_bySupportT120); }   

	void    SetMainVideoType( u8 byMediaType ) { m_tMainSimCapSet.SetVideoMediaType(byMediaType);    }
    u8      GetMainVideoType(void) const { return m_tMainSimCapSet.GetVideoMediaType();    }
    u8      GetMainAudioType(void) const { return m_tMainSimCapSet.GetAudioMediaType();    }
    u8      GetSecVideoType(void) const { return m_tSecondSimCapSet.GetVideoMediaType();   }
	void    SetSecVideoType(u8 byType) { m_tSecondSimCapSet.SetVideoMediaType(byType); }
    u8      GetSecAudioType(void) const { return m_tSecondSimCapSet.GetAudioMediaType();   }

    void    SetMainVideoResolution(u8 byRes) { m_tMainSimCapSet.SetVideoResolution(byRes);    }
    u8      GetMainVideoResolution(void) const { return m_tMainSimCapSet.GetVideoResolution();    }

    void    SetSecVideoResolution(u8 byRes) { m_tSecondSimCapSet.SetVideoResolution(byRes);    }
    u8      GetSecVideoResolution(void) const { return m_tSecondSimCapSet.GetVideoResolution();    }

	//�ڶ�·��Ƶ��˫��������������
	void    SetDStreamResolution(u8 byRes) { m_tDStreamCap.SetResolution(byRes); }
	u8      GetDStreamResolution(void) const { return m_tDStreamCap.GetResolution(); }

    //֡��
    void    SetMainVidFrmRate(u8 byMPI) { m_tMainSimCapSet.SetVideoFrameRate(byMPI); }
    u8      GetMainVidFrmRate(void) const { return m_tMainSimCapSet.GetVideoFrameRate();    }

    void    SetSecVidFrmRate(u8 byMPI) { m_tSecondSimCapSet.SetVideoFrameRate(byMPI);    }
    u8      GetSecVidFrmRate(void) const { return m_tSecondSimCapSet.GetVideoFrameRate();    }

    void    SetDStreamFrmRate(u8 byMPI) { m_tDStreamCap.SetFrameRate(byMPI);    }
    u8      GetDStreamFrmRate(void) const { return m_tDStreamCap.GetFrameRate();    }

    //H264�Զ���֡��
    void    SetMainVidUsrDefFPS(u8 byFPS) { m_tMainSimCapSet.SetUserDefFrameRate(byFPS);    }
    u8      GetMainVidUsrDefFPS(void) const { return m_tMainSimCapSet.GetUserDefFrameRate();    }
    BOOL32  IsMainVidUsrDefFPS(void) const { return m_tMainSimCapSet.IsFrameRateUserDefined();    }

    void    SetSecVidUsrDefFPS(u8 byFPS) { m_tSecondSimCapSet.SetUserDefFrameRate(byFPS);    }
    u8      GetSecVidUsrDefFPS(void) const { return m_tSecondSimCapSet.GetUserDefFrameRate();    }
    BOOL32  IsSecVidUsrDefFPS(void) const { return m_tSecondSimCapSet.IsFrameRateUserDefined();    }

    void    SetDStreamUsrDefFPS(u8 byFPS) { m_tDStreamCap.SetUserDefFrameRate(byFPS);    }
    u8      GetDStreamUsrDefFPS(void) const { return m_tDStreamCap.GetUserDefFrameRate();    }
    BOOL32  IsDStreamUsrDefFPS(void) const { return m_tDStreamCap.IsFrameRateUserDefined();    }
	
    //��ʱ����
	void    SetDStreamMaxBitRate(u16 wMaxRate) { m_tDStreamCap.SetMaxBitRate(wMaxRate); }
	u16     GetDStreamMaxBitRate(void) const { return m_tDStreamCap.GetMaxBitRate(); }

    void    SetDStreamFrameRate(u8 byFrameRate) { m_tDStreamCap.SetFrameRate(byFrameRate); }
    u8      GetDStreamFrameRate(void) const { return m_tDStreamCap.GetFrameRate(); }

    void    SetDStreamType( u8 byDStreamType ); //�����ʹ��    
    u8      GetDStreamType( void ) const { return m_byDStreamType; } //�����ʹ��

	void    SetDStreamSupportH239( BOOL32 bSupport ) { m_tDStreamCap.SetSupportH239(bSupport); } //��MCU�ڲ�ʹ��
    BOOL32  IsDStreamSupportH239( void ) const { return m_tDStreamCap.IsSupportH239(); } //�ڶ�·��Ƶ�Ƿ�֧��H239

    void    SetDStreamMediaType( u8 byMediaType ) { m_tDStreamCap.SetMediaType(byMediaType); } //��MCU�ڲ�ʹ��
    u8      GetDStreamMediaType( void ) const { return m_tDStreamCap.GetMediaType(); }	

    TDStreamCap GetDStreamCapSet( void ) const { return m_tDStreamCap; }
	void    SetDStreamCapSet(TDStreamCap &tStreamCap) { m_tDStreamCap = tStreamCap;	}

	//��һ·����Ƶ����������
    void    SetMainSimCapSet( TSimCapSet &tSimCapSet ) { memcpy(&m_tMainSimCapSet, &tSimCapSet, sizeof(TSimCapSet)); }    
    TSimCapSet  GetMainSimCapSet( void ) const { return m_tMainSimCapSet; }

    void    SetSecondSimCapSet( TSimCapSet &tSimCapSet ) { memcpy(&m_tSecondSimCapSet, &tSimCapSet, sizeof(TSimCapSet)); }
    TSimCapSet  GetSecondSimCapSet( void ) const { return m_tSecondSimCapSet; }
   
	BOOL32  IsSupportMediaType( u8 byMediaType ) const; //��һ·����Ƶ�Ƿ�֧��ĳ��ý������	

	void Clear( void )
	{
        m_bySupportMMcu = 0;
        m_bySupportH224 = 0;
        m_bySupportT120 = 0;
        m_byEncryptMode = CONF_ENCRYPTMODE_NONE;
        m_byDStreamType = VIDEO_DSTREAM_MAIN;
        m_tMainSimCapSet.Clear(); 
        m_tSecondSimCapSet.Clear(); 
        m_tDStreamCap.Reset();
	}
	
	void Print( void ) const
	{
        OspPrintf( TRUE, FALSE, "Main simul support:\n");
        OspPrintf( TRUE, FALSE, "\tVideo\n\t\tType\t:%d\n\t\tRes\t:%d\n\t\tFps\t:%d\n\t\tMaxRate\t:%d\n", 
                                 m_tMainSimCapSet.GetVideoMediaType(),
                                 m_tMainSimCapSet.GetVideoResolution(),
                                 MEDIA_TYPE_H264 != m_tMainSimCapSet.GetVideoMediaType() ? m_tMainSimCapSet.GetVideoFrameRate() : m_tMainSimCapSet.GetUserDefFrameRate(),
                                 m_tMainSimCapSet.GetVideoMaxBitRate() );
        OspPrintf( TRUE, FALSE, "\tAudio\n\t\tType\t:%d\n", m_tMainSimCapSet.GetAudioMediaType() );
        OspPrintf( TRUE, FALSE, "Second simul support:\n");
        OspPrintf( TRUE, FALSE, "\tVideo\n\t\tType\t:%d\n\t\tRes\t:%d\n\t\tFps\t:%d\n\t\tMaxRate\t:%d\n",
                                 m_tSecondSimCapSet.GetVideoMediaType(),
                                 m_tSecondSimCapSet.GetVideoResolution(),
                                 MEDIA_TYPE_H264 != m_tSecondSimCapSet.GetVideoMediaType() ? m_tSecondSimCapSet.GetVideoFrameRate() : m_tSecondSimCapSet.GetUserDefFrameRate(),
                                 m_tSecondSimCapSet.GetVideoMaxBitRate() );
        OspPrintf( TRUE, FALSE, "\tAudio\n\t\tType\t:%d\n", m_tSecondSimCapSet.GetAudioMediaType() );
        OspPrintf( TRUE, FALSE, "Double stream support:\n" );
        OspPrintf( TRUE, FALSE, "\tVideo\n\t\tType\t:%d\n\t\tRes\t:%d\n\t\tFps\t:%d\n\t\tH.239\t:%d\n",
                                 m_tDStreamCap.GetMediaType(),
                                 m_tDStreamCap.GetResolution(),
                                 MEDIA_TYPE_H264 != m_tDStreamCap.GetMediaType() ? m_tDStreamCap.GetFrameRate() : m_tDStreamCap.GetUserDefFrameRate(),
                                 m_tDStreamCap.IsSupportH239() );
        OspPrintf( TRUE, FALSE, "Other feather support:\n" );
        OspPrintf( TRUE, FALSE, "\tMMcu\t\t:%d\n\tT120\t\t:%d\n\tH224\t\t:%d\n\tEncrypt\t\t:%d\n", 
                                 m_bySupportMMcu, m_bySupportT120, m_bySupportH224, m_byEncryptMode );        
        OspPrintf( TRUE, FALSE, "\n" );
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

//��������չ�ṹ
struct TCapSupportEx
{
protected:
	u8 m_byVideoFECType;
	u8 m_byAudioFECType;
	u8 m_byDVideoFECType;
    TVideoStreamCap tSecDSCap;      //�ڶ�˫��������H239�������һ˫����������
	
public:
    TCapSupportEx(): m_byVideoFECType(FECTYPE_NONE),
                     m_byAudioFECType(FECTYPE_NONE),
                     m_byDVideoFECType(FECTYPE_NONE)
	{
        tSecDSCap.Clear();
	}

public: //���ʹ�ã��ն������������ն˵�ʱ��ģ���̶ȵ�ͬ�ڻ�أ�Ҳ�øýӿ�.
	void	SetFECType(u8 byFECType)
	{
		m_byVideoFECType = byFECType; 
		m_byAudioFECType = FECTYPE_NONE;
		m_byDVideoFECType = byFECType;
	}

public: //MCUʹ��
	BOOL32	IsNoSupportFEC(void) const 
	        { return ( (FECTYPE_NONE == m_byVideoFECType) &&
                       (FECTYPE_NONE == m_byAudioFECType) &&
                       (FECTYPE_NONE == m_byDVideoFECType) ); }
	BOOL32	IsVideoSupportFEC(void) const { return ( FECTYPE_NONE != m_byVideoFECType ); }
	BOOL32	IsAudioSupportFEC(void) const { return ( FECTYPE_NONE != m_byAudioFECType ); }
	BOOL32	IsDVideoSupportFEC(void) const { return ( FECTYPE_NONE != m_byDVideoFECType ); }
	u8		GetVideoFECType(void) const { return m_byVideoFECType; }
	void	SetVideoFECType(u8 byFECType) { m_byVideoFECType = byFECType; }
	u8		GetAudioFECType(void) const { return m_byAudioFECType; }
	void	SetAudioFECType(u8 byFECType) { m_byAudioFECType = byFECType; }
	u8		GetDVideoFECType(void) const { return m_byDVideoFECType; }
	void	SetDVideoFECType(u8 byFECType) { m_byDVideoFECType = byFECType; }

public:
    void    SetSecDSType(u8 byType){ tSecDSCap.SetMediaType(byType); }
    u8      GetSecDSType(void) const { return tSecDSCap.GetMediaType(); };
    void    SetSecDSRes(u8 byRes) { tSecDSCap.SetResolution(byRes); }
    u8      GetSecDSRes(void) const { return tSecDSCap.GetResolution(); }
    void    SetSecDSBitRate(u16 wBitRate) { tSecDSCap.SetMaxBitRate(wBitRate);  }
    u16     GetSecDSBitRate(void) const { return tSecDSCap.GetMaxBitRate(); }

	BOOL32  IsDDStreamCap( void )const { return (MEDIA_TYPE_NULL != tSecDSCap.GetMediaType() && 0 != tSecDSCap.GetMediaType());  }

    void    SetSecDSFrmRate(u8 byFrmRate)
    {
        if (MEDIA_TYPE_H264 != tSecDSCap.GetMediaType())
        {
            tSecDSCap.SetFrameRate(byFrmRate);
        }
        else
        {
            tSecDSCap.SetUserDefFrameRate(byFrmRate);
        }
    }
    u8      GetSecDSFrmRate(void) const
    {
        if (MEDIA_TYPE_H264 != tSecDSCap.GetMediaType())
        {
            return tSecDSCap.GetFrameRate();
        }
        else
        {
            return tSecDSCap.GetUserDefFrameRate();
        }
    }

    void	FECType2Str( u8 byFECType, s8* pchStr ) const
	{
		switch( byFECType )
		{
		case FECTYPE_NONE:
			memcpy(pchStr, "NONE", sizeof("NONE"));
			break;
		case FECTYPE_RAID5:
			memcpy(pchStr, "RAID5", sizeof("RAID5"));
			break;
		case FECTYPE_RAID6:
			memcpy(pchStr, "RAID6", sizeof("RAID6"));
			break;
		default:
			sprintf(pchStr, "WRONG VALUE<%d>", byFECType );
			break;
		}
	}
	void	Print(void) const
	{
        OspPrintf(TRUE, FALSE, "FECType:\n" );
		s8 achStr[32];
		OspPrintf(TRUE, FALSE, "\tVideo\t\t:");
		memset(achStr, 0, sizeof(achStr));
		FECType2Str( m_byVideoFECType, achStr );
		OspPrintf( TRUE, FALSE, "%s\n", achStr );

		OspPrintf(TRUE, FALSE, "\tAudio\t\t:");
		memset(achStr, 0, sizeof(achStr));
		FECType2Str( m_byAudioFECType, achStr );
		OspPrintf(TRUE, FALSE, "%s\n", achStr );

		OspPrintf(TRUE, FALSE, "\tDVideo\t\t:");
		memset(achStr, 0, sizeof(achStr));
		FECType2Str( m_byDVideoFECType, achStr );
		OspPrintf(TRUE, FALSE, "%s\n", achStr );

        OspPrintf(TRUE, FALSE, "TSecDSCap:\n");
        OspPrintf(TRUE, FALSE, "\tMediaType\t:%d\n", GetSecDSType());
        OspPrintf(TRUE, FALSE, "\tBitRate\t\t:%d\n", GetSecDSBitRate());
        OspPrintf(TRUE, FALSE, "\tResolution\t:%d\n", GetSecDSRes());
        OspPrintf(TRUE, FALSE, "\tFrameRate\t:%d\n", GetSecDSFrmRate());

        OspPrintf(TRUE, FALSE, "\n");
	}
}
PACKED
;

//���������Ϣ�ṹ,�ýṹ�����˻��������Ϣ��״̬ (len:1004)
//���ڸ������ļ��������ļ�ͷ�����а���TConfInfo�Ľṹ�峤�ȣ�
//��˽���TConfInfo������ݳ�Ա��������������������ݳ�Ա��ĩβ������ᵼ�¶�ȡ�����ļ�����
//�ܹ�̣�2007-06-27
struct TConfInfo
{
protected:
    CConfId       m_cConfId;                        //����ţ�ȫ��Ψһ
    TKdvTime      m_tStartTime;                     //��ʼʱ�䣬����̨��0Ϊ������ʼ
    u16           m_wDuration;                      //����ʱ��(����)��0��ʾ���Զ�ֹͣ
    u16           m_wBitRate;                       //��������(��λ:Kbps,1K=1024)
    u16           m_wSecBitRate;                    //˫�ٻ���ĵ�2����(��λ:Kbps,Ϊ0��ʾ�ǵ��ٻ���)
	u16			  m_wDcsBitRate;					//���ݻ�������(��λ:Kbps,Ϊ0��ʾ��֧�����ݻ���)
    u8            m_byDStreamScale;                 //˫���ٷֱ�
    u8            m_byUsrGrpId;                     //�û���
    u8            m_byTalkHoldTime;                 //��С���Գ���ʱ��(��λ:��)
    u16            m_wMixDelayTime;                 //������ʱʱ��
    TCapSupport   m_tCapSupport;                    //����֧�ֵ�ý��
    s8            m_achConfPwd[MAXLEN_PWD+1];       //��������
    s8            m_achConfName[MAXLEN_CONFNAME+1]; //������
    s8            m_achConfE164[MAXLEN_E164+1];     //�����E164����
    TMtAlias      m_tChairAlias;                    //��������ϯ�ı���
    TMtAlias      m_tSpeakerAlias;                  //�����з����˵ı���
    TConfAttrb    m_tConfAttrb;                     //��������

    TMediaEncrypt m_tMediaKey;                      //��һ�汾������Կһ������֧�ָ���    
public:
    TConfStatus   m_tStatus;                        //����״̬

    // 4.0R3 �汾��չ�ֶ�
protected:
    TConfAttrbEx  m_tConfAttrbEx;                   //������չ����
	TCapSupportEx m_tCapSupportEx;					//������������չ����
    
public:	
    TConfInfo( void )
    { 
		Reset();
    }
    void Reset()
	{
        memset( this, 0, sizeof( TConfInfo ) ); 
        m_tCapSupport.Clear(); 
        m_tConfAttrbEx.Reset(); 
	}
    CConfId GetConfId( void ) const { return m_cConfId; }
    void    SetConfId( CConfId cConfId ){ m_cConfId = cConfId; }
    void    SetUsrGrpId(u8 byGrpId) { m_byUsrGrpId = byGrpId; }
    u8      GetUsrGrpId( void ) const { return m_byUsrGrpId; }
    TKdvTime GetKdvStartTime( void ) const { return( m_tStartTime ); }
    void   SetKdvStartTime( TKdvTime tStartTime ){ m_tStartTime = tStartTime; }
    void   SetDuration(u16  wDuration){ m_wDuration = htons(wDuration);} 
    u16    GetDuration( void ) const { return ntohs(m_wDuration); }
    void   SetBitRate(u16  wBitRate){ m_wBitRate = htons(wBitRate);} 
    u16    GetBitRate( void ) const { return ntohs(m_wBitRate); }
    void   SetSecBitRate(u16 wSecBitRate){ m_wSecBitRate = htons(wSecBitRate);} 
    u16    GetSecBitRate( void ) const { return ntohs(m_wSecBitRate); }
	void   SetDcsBitRate(u16 wDcsBitRate){ m_wDcsBitRate = htons(wDcsBitRate); }
	u16	   GetDcsBitRate( void ) const { return ntohs(m_wDcsBitRate); }

	// fuxiuhua���ø�������Ϣ������Դ(Ŀǰֻ��MCS_CONF, VCS_CONF)
	void   SetConfSource( u8 byConfSource )
	{
		m_cConfId.SetConfSource( byConfSource );
	}
	// fuxiuhua��ȡ��������Ϣ������Դ
	u8     GetConfSource()
	{
		return m_cConfId.GetConfSource();
	}

    void   SetMainVideoFormat(u8 byVideoFormat)
    { 
        TSimCapSet tSim = m_tCapSupport.GetMainSimCapSet();
        tSim.SetVideoResolution(byVideoFormat); 
        m_tCapSupport.SetMainSimCapSet(tSim);
    } 
    u8     GetMainVideoFormat( void ) const { return m_tCapSupport.GetMainSimCapSet().GetVideoResolution(); }
    void   SetSecVideoFormat(u8 byVideoFormat)
    { 
        TSimCapSet tSim = m_tCapSupport.GetSecondSimCapSet();
        tSim.SetVideoResolution(byVideoFormat);
        m_tCapSupport.SetSecondSimCapSet(tSim); 
    } 
    u8     GetSecVideoFormat(void) const { return m_tCapSupport.GetSecondSimCapSet().GetVideoResolution(); }
    void   SetDoubleVideoFormat(u8 byVideoFormat) { m_tCapSupport.SetDStreamResolution(byVideoFormat); } 
    u8     GetDoubleVideoFormat(void) const { return m_tCapSupport.GetDStreamResolution(); }
    u8     GetVideoFormat(u8 byVideoType, u8 byChanNo = LOGCHL_VIDEO);
    u8     GetDStreamScale(void) const 
    { 
        u8 byScale = m_byDStreamScale;
        if (byScale > MAXNUM_DSTREAM_SCALE || byScale < MINNUM_DSTREAM_SCALE)
        {
            byScale = DEF_DSTREAM_SCALE;
        }       
        
        return byScale; 
    }
    void   SetDStreamScale(u8 byDStreamScale) { m_byDStreamScale = byDStreamScale; }

    void   SetMixDelayTime(u16 wDelayTime) { m_wMixDelayTime = htons(wDelayTime); }
    u16    GetMixDelayTime(void) { return ntohs(m_wMixDelayTime); }
    void   SetTalkHoldTime(u8   byTalkHoldTime){ m_byTalkHoldTime = byTalkHoldTime;} 
    u8     GetTalkHoldTime( void ) const { return m_byTalkHoldTime; }
    void   SetCapSupport(TCapSupport tCapSupport){ m_tCapSupport = tCapSupport;} 
    TCapSupport GetCapSupport( void ) const { return m_tCapSupport; }
    void   SetConfPwd( LPCSTR lpszConfPwd );
    LPCSTR GetConfPwd( void ) const { return m_achConfPwd; }
    void   SetConfName( LPCSTR lpszConfName );
    LPCSTR GetConfName( void ) const { return m_achConfName; }
    void   SetConfE164( LPCSTR lpszConfE164 );
    LPCSTR GetConfE164( void ) const { return m_achConfE164; }
    void   SetChairAlias(TMtAlias tChairAlias){ m_tChairAlias = tChairAlias;} 
    TMtAlias  GetChairAlias( void ) const { return m_tChairAlias; }
    void   SetSpeakerAlias(TMtAlias tSpeakerAlias){ m_tSpeakerAlias = tSpeakerAlias;} 
    TMtAlias  GetSpeakerAlias( void ) const { return m_tSpeakerAlias; }
    void   SetConfAttrb(TConfAttrb tConfAttrb){ m_tConfAttrb = tConfAttrb;} 
    TConfAttrb  GetConfAttrb( void ) const { return m_tConfAttrb; }
    void   SetStatus(TConfStatus tStatus){ m_tStatus = tStatus;} 
    TConfStatus  GetStatus( void ) const { return m_tStatus; }	

    void    SetHasVmpModule(BOOL32 bHas) { m_tConfAttrb.SetHasVmpModule(bHas); }
    void    SetHasTvwallModule(BOOL32 bHas) { m_tConfAttrb.SetHasTvWallModule(bHas); }

	TMediaEncrypt& GetMediaKey(void) { return m_tMediaKey; };
	void SetMediaKey(TMediaEncrypt& tMediaEncrypt){ memcpy(&m_tMediaKey, &tMediaEncrypt, sizeof(tMediaEncrypt));}

	void   GetVideoScale(u8 byVideoType, u16 &wVideoWidth, u16 &wVideoHeight, u8* pbyVideoResolution = NULL);
	BOOL   HasChairman( void ) const{ if(m_tStatus.m_tChairman.GetMtId()==0)return FALSE; return TRUE; }	
	TMt    GetChairman( void ) const{ return m_tStatus.m_tChairman; }
	void   SetNoChairman( void ){ memset( &m_tStatus.m_tChairman, 0, sizeof( TMt ) ); }
	void   SetChairman( TMt tChairman ){ m_tStatus.m_tChairman = tChairman; }
	BOOL   HasSpeaker( void ) const{ if(m_tStatus.m_tSpeaker.GetMtId()==0)return FALSE; return TRUE; }
    TMt    GetSpeaker( void ) const{ return m_tStatus.m_tSpeaker; }
	void   SetNoSpeaker( void ){ memset( &m_tStatus.m_tSpeaker, 0, sizeof( TMt ) ); }
	void   SetSpeaker( TMt tSpeaker ){ m_tStatus.m_tSpeaker = tSpeaker; }
	time_t GetStartTime( void ) const;	
	void   SetStartTime( time_t dwStartTime );

    u8     GetMainVideoMediaType( void ) const { return m_tCapSupport.GetMainVideoType();   }
    u8     GetMainAudioMediaType( void ) const { return m_tCapSupport.GetMainAudioType();   }
    u8     GetSecVideoMediaType( void ) const { return m_tCapSupport.GetSecVideoType(); }
    u8     GetSecAudioMediaType( void ) const { return m_tCapSupport.GetSecAudioType(); }
    u8     GetDStreamMediaType( void ) const { return m_tCapSupport.GetDStreamMediaType(); }

    //֡��
    void   SetMainVidFrameRate(u8 byMPI) { m_tCapSupport.SetMainVidFrmRate(byMPI);    }
    u8     GetMainVidFrameRate(void) const { return m_tCapSupport.GetMainVidFrmRate();    }
    void   SetSecVidFrameRate(u8 byMPI) { m_tCapSupport.SetSecVidFrmRate(byMPI);    }
    u8     GetSecVidFrameRate(void) const { return m_tCapSupport.GetSecVidFrmRate();    }
    void   SetDStreamFrameRate(u8 byMPI) { m_tCapSupport.SetDStreamFrmRate(byMPI);    }
    u8     GetDStreamFrameRate(void) const { return m_tCapSupport.GetDStreamFrameRate();    }

    //H264 �Զ���֡��
    void   SetMainVidUsrDefFPS(u8 byFPS) { m_tCapSupport.SetMainVidUsrDefFPS(byFPS);    }
    u8     GetMainVidUsrDefFPS(void) const { return m_tCapSupport.GetMainVidUsrDefFPS();    }
    BOOL32 IsMainVidUsrDefFPS(void) const { return m_tCapSupport.IsMainVidUsrDefFPS();    }
    void   SetSecVidUsrDefFPS(u8 byFPS) { m_tCapSupport.SetSecVidUsrDefFPS(byFPS);    }
    u8     GetSecVidUsrDefFPS(void) const { return m_tCapSupport.GetSecVidUsrDefFPS();    }
    BOOL32 IsSecVidUsrDefFPS(void) const { return m_tCapSupport.IsSecVidUsrDefFPS();    }
    void   SetDStreamUsrDefFPS(u8 byFPS) { m_tCapSupport.SetDStreamUsrDefFPS(byFPS);    }
    u8     GetDStreamUsrDefFPS(void) const { return m_tCapSupport.GetDStreamUsrDefFPS();    }
    BOOL32 IsDStreamUsrDefFPS(void) const { return m_tCapSupport.IsDStreamUsrDefFPS();    }

    void         SetConfAttrbEx(TConfAttrbEx tAttrbEx) { m_tConfAttrbEx = tAttrbEx; }
    TConfAttrbEx GetConfAttrbEx() const {return m_tConfAttrbEx; }
    void   SetSatDCastChnlNum(u8 byNum) { m_tConfAttrbEx.SetSatDCastChnlNum(byNum); }
    u8     GetSatDCastChnlNum() const { return m_tConfAttrbEx.GetSatDCastChnlNum(); }
    void   SetAutoRecAttrb(const TConfAutoRecAttrb& tAttrb ) { m_tConfAttrbEx.SetAutoRecAttrb(tAttrb); }
    TConfAutoRecAttrb GetAutoRecAttrb() const { return m_tConfAttrbEx.GetAutoRecAttrb(); }
    void   SetVmpAutoAdapt(BOOL32 bAutoAdapt) { m_tConfAttrbEx.SetVmpAutoAdapt(bAutoAdapt); }
    BOOL   IsVmpAutoAdapt() const { return m_tConfAttrbEx.IsVmpAutoAdapt(); }
    BOOL   IsSupportGkCharge(void) const { return ( strlen(m_tConfAttrbEx.GetGKUsrName()) > 0 ? TRUE : FALSE ); }
    void   SetDiscussAutoStop() { m_tConfAttrbEx.SetDiscussAutoStop(); }
    void   SetDiscussAutoSwitch2Mix() { m_tConfAttrbEx.SetDiscussAutoSwitch2Mix(); }
    BOOL   IsDiscussAutoStop() const { return m_tConfAttrbEx.IsDiscussAutoStop(); }

	//������������չ����, zgc, 2007-09-26
	BOOL32	IsSupportFEC(void) const { return !m_tCapSupportEx.IsNoSupportFEC(); }
	TCapSupportEx GetCapSupportEx(void) const { return m_tCapSupportEx; }
	void	SetCapSupportEx(TCapSupportEx tCapSupportEx) { m_tCapSupportEx = tCapSupportEx; }

	// fxh VCS���û���ĵ��ȼ���
	void SetConfLevel(u8 byLevel)  { m_tConfAttrbEx.SetConfLevel(byLevel); }
	u8   GetConfLevel()            { return m_tConfAttrbEx.GetConfLevel(); }

	void SetConfRealSat(BOOL32 bSat) { m_tConfAttrbEx.SetConfRealSat(bSat);	}
	BOOL IsConfRealSat(void) {	return m_tConfAttrbEx.IsConfRealSat();	};

	void Print( void ) const
	{
		OspPrintf( TRUE, FALSE, "\nConfInfo:\n" );
		OspPrintf( TRUE, FALSE, "m_cConfId: " );
		m_cConfId.Print();
        OspPrintf( TRUE, FALSE, "m_byUsrGrpId: %d\n", GetUsrGrpId());
		OspPrintf( TRUE, FALSE, "\nm_tStartTime: " );
        m_tStartTime.Print();
		OspPrintf( TRUE, FALSE, "\nm_wDuration: %d\n", ntohs(m_wDuration) );
		OspPrintf( TRUE, FALSE, "m_wBitRate: %d\n", ntohs(m_wBitRate) );
        OspPrintf( TRUE, FALSE, "m_wSecBitRate: %d\n", ntohs(m_wSecBitRate) );
		OspPrintf( TRUE, FALSE, "m_wDcsBitRate: %d\n", ntohs(m_wDcsBitRate) );
		OspPrintf( TRUE, FALSE, "m_byVideoFormat: %d\n", GetMainVideoFormat() );
		OspPrintf( TRUE, FALSE, "m_byTalkHoldTime: %d\n", m_byTalkHoldTime );
        OspPrintf( TRUE, FALSE, "m_byDStreamScale: %d\n", m_byDStreamScale );
		OspPrintf( TRUE, FALSE, "m_tCapSupport:\n" );
	    m_tCapSupport.Print();
        OspPrintf( TRUE, FALSE, "m_tCapSupportEx: \n" );
        m_tCapSupportEx.Print();
		OspPrintf( TRUE, FALSE, "m_achConfName: %s\n", m_achConfName );
		OspPrintf( TRUE, FALSE, "m_achConfE164: %s\n", m_achConfE164 );
        OspPrintf( TRUE, FALSE, "m_achConfPwd: %s\n", m_achConfPwd );
        OspPrintf( TRUE, FALSE, "m_tChairAlias:" );
        m_tChairAlias.Print();
        OspPrintf( TRUE, FALSE, "m_tSpeakerAlias:" );
        m_tSpeakerAlias.Print();
		OspPrintf( TRUE, FALSE, "\n" );
        OspPrintf( TRUE, FALSE, "m_tConfAttrbEx: \n" );
        m_tConfAttrbEx.Print();
	}
}
/*
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

/*-------------------------------------------------------------------
                               TMt                                  
--------------------------------------------------------------------*/

/*====================================================================
    ������      ��operator==
    ����        ������ID�ж��Ƿ����
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const TMt & tObj, �ж϶���
    ����ֵ˵��  ��TRUE/FALSE
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/01/02    1.0         LI Yi         ����
	04/06/28    3.0         ������        �޸�
====================================================================*/
inline BOOL TMt::operator ==( const TMt & tObj ) const
{
	if( tObj.GetType() != GetType() )
	{
		return FALSE;
	}

	switch( tObj.GetType() ) 
	{
	case TYPE_MCU:
		if( tObj.GetMcuId() == GetMcuId() ) 
		{
			return TRUE;
		}
		break;
	case TYPE_MCUPERI:
		if( tObj.GetMcuId() == GetMcuId() && tObj.GetEqpType() == GetEqpType() 
			&& tObj.GetEqpId() ==  GetEqpId() )
		{
			return TRUE;
		}
		break;
	case TYPE_MT:
        if( tObj.GetMcuId() == GetMcuId() && tObj.GetMtId() ==  GetMtId() 
			&& tObj.GetConfIdx() == GetConfIdx() )
		{
			return TRUE;
		}
		break;
	default:
		break;
	}

	return FALSE;
}

/*====================================================================
    ������      ��SetMcu
    ����        ������MCU
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8 byMcuId, MCU��
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    2002/07/26  1.0         LI Yi         ����
    2003/10/28  3.0         ������        �޸�  
====================================================================*/
inline void TMt::SetMcu( u8 byMcuId )
{
	m_byMainType = TYPE_MCU;
	m_bySubType = 0;
	m_byMcuId = byMcuId;
	m_byEqpId = 0;	
	m_byConfDriId = 0;  
    m_byConfIdx = 0;    
}

/*====================================================================
    ������      ��SetMcuEqp
    ����        ������MCU����
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8 byMcuId, MCU��
				  u8 byEqpId, �����
				  u8 byEqpType, ��������
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    2002/07/26  1.0         LI Yi         ����
    2003/06/06  1.0         LI Yi         �����������Ͳ���
    2003/10/28  3.0         ������        �޸�  
====================================================================*/
inline void TMt::SetMcuEqp( u8 byMcuId, u8 byEqpId, u8 byEqpType )
{
	m_byMainType = TYPE_MCUPERI;
	m_bySubType = byEqpType;
	m_byMcuId = byMcuId;
	m_byEqpId = byEqpId;	
	m_byConfDriId = 0;  
    m_byConfIdx = 0; 
}

/*====================================================================
    ������      ��SetMt
    ����        �������ն�
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8 byMcuId, MCU��
				  u8 byMtId, �ն˺�
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    2002/07/26  1.0         LI Yi         ����
    2003/10/28  3.0         ������        �޸�  
====================================================================*/
inline void TMt::SetMt( u8 byMcuId, u8 byMtId, u8 byDriId, u8 byConfIdx )
{
	m_byMainType = TYPE_MT;
	m_bySubType = 0;
	m_byMcuId = byMcuId;
	m_byEqpId = byMtId;	
	m_byConfDriId = byDriId;  
    m_byConfIdx = byConfIdx; 
}

/*====================================================================
    ������      ��SetMt
    ����        �������ն�
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����TMt tMt 
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    2005/01/24  3.6         κ�α�        ����
====================================================================*/
inline void TMt::SetMt( TMt tMt )
{
	SetMt(tMt.GetMcuId(), tMt.GetMtId(), tMt.GetDriId(), tMt.GetConfIdx());
}

/*-------------------------------------------------------------------
                               CConfId                                  
--------------------------------------------------------------------*/

/*====================================================================
    ������      ��GetConfId
    ����        ����û��������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8 * pbyConfId, �����BUFFER����ָ�룬�������ػ����
			      u8 byBufLen, BUFFER��С
    ����ֵ˵��  ��ʵ�ʷ��������С
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline u8 CConfId::GetConfId( u8 * pbyConfId, u8 byBufLen ) const
{
	u8	byLen = min( sizeof( m_abyConfId ), byBufLen );
	memcpy( pbyConfId, m_abyConfId, byLen );

	return( byLen );
}

/*====================================================================
    ������      ��GetConfIdString
    ����        ����û�����ַ���
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����LPSTR lpszConfId, ������ַ���BUFFER����ָ�룬����
	                   ����0��β������ַ���
			      u8 byBufLen, BUFFER��С
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline void CConfId::GetConfIdString( LPSTR lpszConfId, u8 byBufLen ) const
{
	u8	byLoop;

	for( byLoop = 0; byLoop < sizeof( m_abyConfId ) && byLoop < ( byBufLen - 1 ) / 2; byLoop++ )
	{
		sprintf( lpszConfId + byLoop * 2, "%.2x", m_abyConfId[byLoop] );
	}
	lpszConfId[byLoop * 2] = '\0';
}

/*====================================================================
    ������      ��SetConfId
    ����        �����û��������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const CConfId & cConfId, ��������
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline void CConfId::SetConfId( const CConfId & cConfId )
{
	cConfId.GetConfId( m_abyConfId, sizeof( m_abyConfId ) );
}

/*====================================================================
    ������      ��SetConfId
    ����        �����û��������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const u8 * pbyConfId, ���������ָ��
			      u8 byBufLen, BUFFER��С
    ����ֵ˵��  ��ʵ�����������С
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline u8 CConfId::SetConfId( const u8 * pbyConfId, u8 byBufLen )
{
	u8	bySize = min( byBufLen, sizeof( m_abyConfId ) );
	
	memset( m_abyConfId, 0, sizeof( m_abyConfId ) );
	memcpy( m_abyConfId, pbyConfId, bySize );

	return( bySize );
}
	
/*====================================================================
    ������      ��SetConfId
    ����        �����û��������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����LPCSTR lpszConfId, ����Ļ�����ַ���
    ����ֵ˵��  ��ʵ�����������С
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline u8 CConfId::SetConfId( LPCSTR lpszConfId )
{
	LPCSTR	lpszTemp = lpszConfId;
	s8	achTemp[3], *lpszStop;
	u8	byCount = 0;

	memset( m_abyConfId, 0, sizeof( m_abyConfId ) );
	while( lpszTemp != NULL && lpszTemp + 1 != NULL && byCount < sizeof( m_abyConfId ) )
	{
		memcpy( achTemp, lpszTemp, 2 );
		achTemp[2] = '\0';
		m_abyConfId[byCount] = ( u8 )strtoul( achTemp, &lpszStop, 16 );
		byCount++;
		lpszTemp += 2;
	}

	return( byCount );
}

/*====================================================================
    ������      ��CreateConfId
    ����        �����������
    �㷨ʵ��    �����ݵ�ǰʱ������ֵ
    ����ȫ�ֱ�����
    �������˵������
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/06/06    1.0         LI Yi         ����
====================================================================*/
inline void CConfId::CreateConfId( u8 byUsrGrpId )
{
	struct tm	*ptmCurTime;
	time_t		tCurTime = time( NULL );
	u8	byTemp;
	u16	wTemp;

	memset( m_abyConfId, 0, sizeof( m_abyConfId ) );
	
	//get current time
	ptmCurTime = localtime( &tCurTime );
	//year
	wTemp = ptmCurTime->tm_year + 1900;
	memcpy( m_abyConfId, &wTemp, sizeof( u16 ) );
	//month
	byTemp = ptmCurTime->tm_mon + 1;
	memcpy( m_abyConfId + 2, &byTemp, sizeof( u8 ) );
	//day
	byTemp = ptmCurTime->tm_mday;
	memcpy( m_abyConfId + 3, &byTemp, sizeof( u8 ) );
	//hour
	byTemp = ptmCurTime->tm_hour;
	memcpy( m_abyConfId + 4, &byTemp, sizeof( u8 ) );
	//minute
	byTemp = ptmCurTime->tm_min;
	memcpy( m_abyConfId + 5, &byTemp, sizeof( u8 ) );
	//second
	byTemp = ptmCurTime->tm_sec;
	memcpy( m_abyConfId + 6, &byTemp, sizeof( u8 ) );
	//msec
	wTemp = 0;
	memcpy( m_abyConfId + 7, &wTemp, sizeof( u16 ) );

	//rand
	wTemp = rand();
	memcpy( m_abyConfId + 9, &wTemp, sizeof( u16 ) );

    // ���� [6/21/2006]
    // ���λ��ʾ��ID
    SetUsrGrpId( byUsrGrpId );
}

/*====================================================================
    ������      ��IsNull
    ����        ���жϻ�����Ƿ�Ϊ��
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵������
    ����ֵ˵��  ��TRUE/FALSE
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/03/31    1.0         LI Yi         ����
====================================================================*/
inline BOOL CConfId::IsNull( void ) const
{
	u8	abyNull[sizeof( m_abyConfId )];

	memset( abyNull, 0, sizeof( abyNull ) );
	if( memcmp( m_abyConfId, abyNull, sizeof( m_abyConfId ) ) == 0 )
		return( TRUE );
	else
		return( FALSE );
}

/*====================================================================
    ������      ��SetNull
    ����        �����û����Ϊ��
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵������
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/03/31    1.0         LI Yi         ����
====================================================================*/
inline void CConfId::SetNull( void )
{
	memset( m_abyConfId, 0, sizeof( m_abyConfId ) );
}

/*====================================================================
    ������      ��operator==
    ����        ������������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const CConfId & cConfId, ��������
    ����ֵ˵��  ����ȷ���TRUE�����򷵻�FALSE
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/12/31    1.0         LI Yi         ����
====================================================================*/
inline BOOL CConfId::operator == ( const CConfId & cConfId ) const
{
	u8	abyTemp[sizeof( m_abyConfId )];

	cConfId.GetConfId( abyTemp, sizeof( abyTemp ) );
	if( memcmp( abyTemp, m_abyConfId, sizeof( m_abyConfId ) ) == 0 )
		return( TRUE );
	else
		return( FALSE );
}

/*-------------------------------------------------------------------
                               TCapSupport                             
--------------------------------------------------------------------*/
/*=============================================================================
  �� �� ���� SetDStreamType
  ��    �ܣ� ����˫������
  �㷨ʵ�֣� 
  ȫ�ֱ����� 
  ��    ���� u8 byDStreamType
  �� �� ֵ�� inline void 
=============================================================================*/
inline void TCapSupport::SetDStreamType( u8 byDStreamType ) 
{ 
    m_byDStreamType = byDStreamType;
    
    switch(byDStreamType)
    {
    case VIDEO_DSTREAM_MAIN:
        m_tDStreamCap.SetMediaType(m_tMainSimCapSet.GetVideoMediaType());
        m_tDStreamCap.SetSupportH239(FALSE);
        break;
    case VIDEO_DSTREAM_H263PLUS:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H263PLUS);
        m_tDStreamCap.SetSupportH239(FALSE);
        break;
    case VIDEO_DSTREAM_H263PLUS_H239:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H263PLUS);
        m_tDStreamCap.SetSupportH239(TRUE);
        break;
    case VIDEO_DSTREAM_H263_H239:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H263);
        m_tDStreamCap.SetSupportH239(TRUE);
        break;
    case VIDEO_DSTREAM_H264_H239:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H264);
        m_tDStreamCap.SetSupportH239(TRUE);
        break;
    case VIDEO_DSTREAM_H264:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H264);
        m_tDStreamCap.SetSupportH239(FALSE);
        break;
    case VIDEO_DSTREAM_H264_H263PLUS_H239:
        m_tDStreamCap.SetMediaType(MEDIA_TYPE_H264);
        m_tDStreamCap.SetSupportH239(TRUE);
        break;
    default:
        break;
    }
}

/*====================================================================
    ������      ��IsSupportMediaType
    ����        ���жϵ�һ·����Ƶ�Ƿ�֧��ĳ��ý������
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8   byMediaType ý������       
    ����ֵ˵��  ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    04/03/18    3.0         ������          ����             
====================================================================*/
inline BOOL32  TCapSupport::IsSupportMediaType( u8 byMediaType ) const
{
    BOOL32  bSupport = FALSE;
	switch( byMediaType ) 
	{
	case MEDIA_TYPE_H261:		
	case MEDIA_TYPE_H262:		
	case MEDIA_TYPE_H263:
	case MEDIA_TYPE_H264:		
	case MEDIA_TYPE_MP4:
//  case MEDIA_TYPE_H263PLUS:	
        bSupport = (m_tMainSimCapSet.GetVideoMediaType() == byMediaType ||
                    m_tSecondSimCapSet.GetVideoMediaType() == byMediaType);
        break;   
		
	case MEDIA_TYPE_PCMA:	
	case MEDIA_TYPE_PCMU:	
	case MEDIA_TYPE_G722:	
	case MEDIA_TYPE_G7231:	
	case MEDIA_TYPE_G728:	
	case MEDIA_TYPE_G729:	
	case MEDIA_TYPE_MP3:
    case MEDIA_TYPE_G7221C:
    case MEDIA_TYPE_AACLC:
    case MEDIA_TYPE_AACLD:
        bSupport = (m_tMainSimCapSet.GetAudioMediaType() == byMediaType ||
                    m_tSecondSimCapSet.GetAudioMediaType() == byMediaType);
        break;
    default:
        break;	
	}

	return bSupport;
}

/*-------------------------------------------------------------------
                               TConfInfo                             
--------------------------------------------------------------------*/

/*====================================================================
    ������      ��GetVideoFormat
    ����        ����ȡͼ��ķֱ���
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u8 byVideoType,
                  u8 byChanNo
    ����ֵ˵��  ��ͼ��ķֱ���
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    05/09/21    4.0         libo          ����
====================================================================*/
inline u8 TConfInfo::GetVideoFormat(u8 byVideoType, u8 byChanNo)
{
    if (LOGCHL_VIDEO == byChanNo)
    {
        if (m_tCapSupport.GetMainSimCapSet().GetVideoMediaType() == byVideoType)
        {
            return m_tCapSupport.GetMainSimCapSet().GetVideoResolution();
        }
        else
        {
            return m_tCapSupport.GetSecondSimCapSet().GetVideoResolution();
        }
    }
    else
    {
        return m_tCapSupport.GetDStreamResolution();
    }
}

/*====================================================================
    ������      ��GetVideoScale
    ����        ���õ���Ƶ��ģ
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����u16 &wVideoWidth ��Ƶ���
                  u16 &wVideoHeight ��Ƶ�߶�	
                  ǿ��ָ������ĳ�ֱַ���
    ����ֵ˵��  ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/12/05    3.0         ������          ����             
====================================================================*/
inline void  TConfInfo::GetVideoScale(u8 byVideoType, u16 &wVideoWidth, u16 &wVideoHeight, u8* pbyVideoResolution/* = NULL */)
{
   
    u8 byVideoFormat;
    if (m_tCapSupport.GetMainSimCapSet().GetVideoMediaType() == byVideoType)
    {
        byVideoFormat = m_tCapSupport.GetMainSimCapSet().GetVideoResolution();
    }
    else
    {
        byVideoFormat = m_tCapSupport.GetSecondSimCapSet().GetVideoResolution();
    }
    if( NULL != pbyVideoResolution )
    {
        byVideoFormat = *pbyVideoResolution;
    }
    
    //  [4/24/2006] mpeg4 16cif ��auto����
    if (MEDIA_TYPE_MP4 == byVideoType && VIDEO_FORMAT_16CIF == byVideoFormat)
    {
        byVideoFormat = VIDEO_FORMAT_AUTO;
    }

    switch (byVideoFormat)
	{
    case VIDEO_FORMAT_SQCIF_112x96:
        wVideoWidth = 112;
        wVideoHeight = 96;
        break;
        
    case VIDEO_FORMAT_SQCIF_96x80:
        wVideoWidth = 96;
        wVideoHeight = 80;
        break;

    case VIDEO_FORMAT_SQCIF:
		wVideoWidth = 128;
        wVideoHeight = 96;
    	break;
		
    case VIDEO_FORMAT_QCIF:
		wVideoWidth = 176;
        wVideoHeight = 144;
    	break;

    case VIDEO_FORMAT_CIF:
		wVideoWidth = 352;
        wVideoHeight = 288;
    	break;

    case VIDEO_FORMAT_2CIF:
        wVideoWidth = 352;
        wVideoHeight = 576;
        break;

	case VIDEO_FORMAT_4CIF:
        // 4CIFͳһΪ704*576, zgc, 2008-09-05
        /*
        if ( MEDIA_TYPE_H264 == byVideoType)
        {
		    wVideoWidth = 720;
        }
        else*/
        {
            wVideoWidth = 704;
        }
        wVideoHeight = 576;
		break;

	case VIDEO_FORMAT_16CIF:
		wVideoWidth = 1408;
        wVideoHeight = 1152;
		break;

    case VIDEO_FORMAT_SIF:
        wVideoWidth = 352;
        wVideoHeight = 240;
        break;

    case VIDEO_FORMAT_4SIF:
        wVideoWidth = 704;
        wVideoHeight = 480;
        break;

    case VIDEO_FORMAT_VGA:
        wVideoWidth = 640;
        wVideoHeight = 480;
        break;

    case VIDEO_FORMAT_SVGA:
        wVideoWidth = 800;
        wVideoHeight = 600;
        break;

    case VIDEO_FORMAT_XGA:
        wVideoWidth = 1024;
        wVideoHeight = 768;
        break;        

    case VIDEO_FORMAT_W4CIF:
        wVideoWidth = 1024;
        wVideoHeight = 576;
        break;

    case VIDEO_FORMAT_HD720:
        wVideoWidth = 1280;
        wVideoHeight = 720;
        break;

    case VIDEO_FORMAT_SXGA:
        wVideoWidth = 1280;
        wVideoHeight = 1024;
        break;

    case VIDEO_FORMAT_UXGA:
        wVideoWidth = 1600;
        wVideoHeight = 1200;
        break;

    case VIDEO_FORMAT_HD1080:
        wVideoWidth = 1920;
        wVideoHeight = 1088;
        break;

	default:
		wVideoWidth = 352;
        wVideoHeight = 288;
		break;
    }

}

/*====================================================================
    ������      ��GetStartTime
    ����        ����øû��鿪ʼʱ��
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵������
    ����ֵ˵��  ��time_t����ʱ�䣨local Time��������̨��0Ϊ������ʼ
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/07/30    1.0         LI Yi         ����
    02/08/23    1.0         LI Yi         ��time_t��ʱ��ת��Ϊ�ַ����ͱ���
====================================================================*/
inline time_t TConfInfo::GetStartTime( void ) const
{
	time_t	dwStartTime;
	
	if( m_tStartTime.GetYear() != 0 )	//���Ǽ�ʱ����
		m_tStartTime.GetTime( dwStartTime );
	else
		dwStartTime = 0;

	return( dwStartTime );
}

/*====================================================================
    ������      ��SetStartTime
    ����        �����øû��鿪ʼʱ��
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����time_t dwStartTime, ��ʼʱ�䣬0Ϊ������ʼ
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/07/31    1.0         LI Yi         ����
    02/08/23    1.0         LI Yi         ��time_t��ʱ��ת��Ϊ�ַ����ͱ���
====================================================================*/
inline void TConfInfo::SetStartTime( time_t dwStartTime )
{
	if( dwStartTime != 0 )	//���Ǽ�ʱ����
		m_tStartTime.SetTime( &dwStartTime );
	else
		memset( &m_tStartTime, 0, sizeof( TKdvTime ) );
}


/*====================================================================
    ������      ��SetConfPwd
    ����        �����ñ���
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����LPCSTR lpszConfPwd, ����
    ����ֵ˵��  ���ַ���ָ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/07/26    1.0         LI Yi         ����
====================================================================*/
inline void TConfInfo::SetConfPwd( LPCSTR lpszConfPwd )
{
	if( lpszConfPwd != NULL )
	{
		strncpy( m_achConfPwd, lpszConfPwd, sizeof( m_achConfPwd ) );
		m_achConfPwd[sizeof( m_achConfPwd ) - 1] = '\0';
	}
	else
	{
		memset( m_achConfPwd, 0, sizeof( m_achConfPwd ) );
	}
}

/*====================================================================
    ������      ��SetConfName
    ����        �����ñ���
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����LPCSTR lpszConfName, ����
    ����ֵ˵��  ���ַ���ָ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/07/26    1.0         LI Yi         ����
====================================================================*/
inline void TConfInfo::SetConfName( LPCSTR lpszConfName )
{
	if( lpszConfName != NULL )
	{
		strncpy( m_achConfName, lpszConfName, sizeof( m_achConfName ) );
		m_achConfName[sizeof( m_achConfName ) - 1] = '\0';
	}
	else
	{
		memset( m_achConfName, 0, sizeof( m_achConfName ) );
	}
}

/*====================================================================
    ������      ��SetConfE164
    ����        �����ñ���
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����LPCSTR lpszConfE164, ����
    ����ֵ˵��  ���ַ���ָ��
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    02/07/26    1.0         LI Yi         ����
====================================================================*/
inline void TConfInfo::SetConfE164( LPCSTR lpszConfE164 )
{
	if( lpszConfE164 != NULL )
	{
		strncpy( m_achConfE164, lpszConfE164, sizeof( m_achConfE164 ) );
		m_achConfE164[sizeof( m_achConfE164 ) - 1] = '\0';
	}
	else
	{
		memset( m_achConfE164, 0, sizeof( m_achConfE164 ) );
	}
}

/*-------------------------------------------------------------------
                               TMtAlias                             
--------------------------------------------------------------------*/
/*====================================================================
    ������      ��operator ==
    ����        ���Ƚ������ն˱����Ƿ���� 
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����void
    ����ֵ˵��  ��TRUE - ��� FALSE - �����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    2003/11/13  3.0         ������         ����
====================================================================*/
inline  BOOL   TMtAlias::operator ==( const TMtAlias & tObj ) const
{
    if( tObj.m_AliasType == 0 || tObj.m_AliasType != m_AliasType ) 
	{
		return FALSE ;
	}

	if( tObj.m_AliasType == mtAliasTypeTransportAddress )
	{
		if( (tObj.m_tTransportAddr.GetIpAddr() == m_tTransportAddr.GetIpAddr()) && 
			(tObj.m_tTransportAddr.GetPort() == m_tTransportAddr.GetPort()) && 
			(tObj.m_tTransportAddr.GetIpAddr() != 0 ))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		if( (memcmp( tObj.m_achAlias, m_achAlias, sizeof( m_achAlias ) ) == 0) && 
			(m_achAlias[0] != 0) )
		{
            return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}

/*====================================================================
    ������      ��SetTime
    ����        ������ʱ��
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const time_t * ptTime, Ҫ���õ�ʱ��
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/02/07    1.0         ���ؾ�         ����
====================================================================*/
inline void TKdvTime::SetTime( const time_t * ptTime )
{
	tm *ptLocalTime;
	
	ptLocalTime = ::localtime( ptTime );

	m_wYear = htons( (u16)ptLocalTime->tm_year + 1900 );
	m_byMonth = (u8)ptLocalTime->tm_mon + 1;
	m_byMDay = (u8)ptLocalTime->tm_mday;
	m_byHour = (u8)ptLocalTime->tm_hour;
	m_byMinute = (u8)ptLocalTime->tm_min;
	m_bySecond = (u8)ptLocalTime->tm_sec;
}

/*====================================================================
    ������      ��GetTime
    ����        ���õ�ʱ��ṹ
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����time_t & tTime, ���ص�ʱ��
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/02/07    1.0         ���ؾ�         ����
====================================================================*/
inline void TKdvTime::GetTime( time_t & tTime ) const
{
	tm tTmCurTime;

	tTmCurTime.tm_year = ntohs( m_wYear ) - 1900;
	tTmCurTime.tm_mon = m_byMonth - 1;
	tTmCurTime.tm_mday = m_byMDay;
	tTmCurTime.tm_hour = m_byHour;
	tTmCurTime.tm_min = m_byMinute;
	tTmCurTime.tm_sec = m_bySecond;

	tTime = ::mktime( &tTmCurTime );
}

/*====================================================================
    ������      ��operator ==
    ����        ��==����
    �㷨ʵ��    ��
    ����ȫ�ֱ�����
    �������˵����const TKdvTime & tTime, �Ƚϵ�ʱ��
    ����ֵ˵��  ����
----------------------------------------------------------------------
    �޸ļ�¼    ��
    ��  ��      �汾        �޸���        �޸�����
    03/06/07    1.0         ����          ����
====================================================================*/
inline BOOL TKdvTime::operator == ( const TKdvTime & tTime )
{
	if( memcmp( this, &tTime, sizeof( TKdvTime ) ) == 0 )
		return( TRUE );
	else
		return( FALSE );
}

#ifdef WIN32
#pragma pack( pop )
#endif

#undef SETBITSTATUS
#undef GETBITSTATUS

#endif //_VCCOMMON_040602_H_


 
