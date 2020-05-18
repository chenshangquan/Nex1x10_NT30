/*****************************************************************************
ģ����      : GPS
�ļ���      : gpsLib.h
����ļ�    : 
�ļ�ʵ�ֹ���:  .
����        : �ŷ���
�汾        : V1.0  Copyright(C) 2005-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/11/15  01a         �ŷ���      ����	
******************************************************************************/
#ifndef __INC_GPS_LIB_H
#define __INC_GPS_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

/* ͷ�ļ� */
#include "kdvtype.h"

/* GPSЭ�����ģ��汾�궨�� */
#define GPS_LIB_VER            "GPS_LIB 40.01.01.01.051125"
#define GPS_VER_MAX_LEN                    255  /* �汾��Ϣ����󳤶� */


/* GPS ����ֵ���� */
#define GPS_OPT_SUCCESS                      0

#define GPS_UNDEF_ERR                       -1
#define GPS_ERR_BASE                         1
#define GPS_ERR_TIMEOUT        (GPS_ERR_BASE+0) /* ���ݽ��ճ�ʱ,Ĭ��3��,������GPS�豸û�нӻ����ʲ�ƥ�� */
#define GPS_ERR_LENERR         (GPS_ERR_BASE+1) /* ���ݳ��ȴ���һ��ָû�յ�������һ����Ϣ */
#define GPS_ERR_PARAMERR       (GPS_ERR_BASE+2) /* �������� */
#define GPS_ERR_DATAERR        (GPS_ERR_BASE+3) /* ���ݴ���һ��ָĳ�ֶ��������ݴ� */
#define GPS_ERR_CRCERR         (GPS_ERR_BASE+4) /* ChecksumУ����� */
#define GPS_ERR_NOT_OPENED     (GPS_ERR_BASE+5) /* GPS�豸û�д� */
#define GPS_ERR_OPEN_FAILED    (GPS_ERR_BASE+6) /* GPS�豸��ʧ�ܣ����򿪴���ʧ�� */
#define GPS_ERR_READ_FAILED    (GPS_ERR_BASE+7) /* GPS�豸������ʧ�� */
#define GPS_ERR_WRITE_FAILED   (GPS_ERR_BASE+8) /* GPS�豸д����ʧ�� */
#define GPS_ERR_CLOSE_FAILED   (GPS_ERR_BASE+9) /* GPS�豸�ش���ʧ�� */


/* �豸���Ʋ��ֺ궨�� */
#define GPS_MAX_DEVS                         1  /* ���֧�ֵ�GPS�豸�� */


/* Э����غ궨�� */
#define GPS_GSV_MAX_MSGS                     3  /* ����ϱ�3��GSV��Ϣ */
#define GPS_SEGMENT_MAX_LEN                 12  /* ��Ϣ���ֶ���󳤶� */
#define GPS_SAT_USED_MAX_NUM                12  /* GPS�����Ը��ٵ�������Ŀ */
#define GPS_SAT_GROUPS_PER_GSV               4  /* ÿ��GSV��Ϣ��������������Ϣ�����Ŀ */


/*------------------------------  GGA��Ϣ�ṹ���� ----------------------------
  $GPGGA,hhmmss.sss,ddmm.mmmm,t,ooonn.nnnn,e,q,ss,y.y,a.a,z,g.g,z,b.b,
   iiii*CC<CR><LF>
 ��:$GPGGA,091522.286,3111.3348,N,12125.8920,E,1,03,23.0,0.0,M,8.1,M,0.0,0000*70
 ----------------------------------------------------------------------------
    �ֶ�    | ���ܽ���                                 | ֵ�ķ�Χ,ȫ�����ַ�
    hh      | Hours (time stamp of position) ʱ         0 .. 23
    mm      | Minutes (time stamp of position) ��       0 .. 59
    ss.sss  | Seconds (time stamp of position) ��.����  0 .. 59.999
    dd      | Latitude degrees γ��,��                  0 .. 90
    mm.mmmm | Latitude minutes γ��,��                  00.0000 .. 59.9999
    t       | Latitude direction γ�ȷ���                N =	North ��γ
            |                                           S =	South ��γ
    ooo     | Longitude degrees ����,��                 0 .. 180
    nn.nnnn | Longitude minutes ����,��	                00.0000 .. 59.9999
    e       | Longitude direction ���ȷ���		        E =	East ����
            |                                           W =	West ����
    q       | GPS status indicator          0 = Fix not available or invalid
            | GPS״ָ̬ʾ                    1 = GPS SPS Mode, fix valid
            |                               2 =	Diferential GPS, SPS Mode, fix valid
            |                               3 =	GPS PPS Mode, fix valid
    ss      | Number of satellites used
            | ʹ�õ����Ǹ���                             0 .. 12
    y.y     | HDOP(Horizontal Dilution of Precision)    0.0 .. 99.9
    a.a     | GPS antenna height in meters              ע��:С����ǰ�泤�Ȳ���,���ܶ���ֽ�
            | ���ߵĸ߶ȣ�ָ���Σ���                      ��Ҫ4�ſ������ǣ�����Ϊ0.0
    z       | Units ��λ		                            M	=	meters
    g.g     | Geoid separation ���ˮ׼��
    z       | Units	                                    M	=	meters
    b.b     | Age of differential data      0.0 field when DGPS is not used
    iiii    | Differential reference station ID ΢�ֲο���ݺ�  0000 .. 1023
    UTCΪ��������ʱ��,��ΪT,���Ǿ���Ϊ0�ĵ����ľ���ʱ�䡣
    ����ʱ���㷨:����x��ʱ��=(T+12*x/180)%24; ����x��ʱ��=(24+T-12*x/180)%24
---------------------------------------------------------------------------*/
typedef struct{
    u8 abyUTC[GPS_SEGMENT_MAX_LEN];             /* hhmmss.sss ��������ʱ�� */
    u8 abyLatitude[GPS_SEGMENT_MAX_LEN];        /* ddmm.mmmm  γ�� */
    u8 abyLatitudeDir[GPS_SEGMENT_MAX_LEN];     /* t          γ�ȷ��� */
    u8 abyLongitude[GPS_SEGMENT_MAX_LEN];       /* ooonn.nnnn ���� */
    u8 abyLongitudeDir[GPS_SEGMENT_MAX_LEN];    /* e          ���ȷ��� */
    u8 abyGpsStatus[GPS_SEGMENT_MAX_LEN];       /* q          GPS״ָ̬ʾ */
    u8 abyUsedSats[GPS_SEGMENT_MAX_LEN];        /* ss         ʹ�õ����Ǹ��� */
    u8 abyHDOP[GPS_SEGMENT_MAX_LEN];            /* y.y              */
    u8 abyAltitude[GPS_SEGMENT_MAX_LEN];        /* a.a        ����*/
    u8 abyAltitudeUnit[GPS_SEGMENT_MAX_LEN];    /* z          ����ֵ��λ */
    u8 abyGeoid[GPS_SEGMENT_MAX_LEN];           /* g.g        ���ˮ׼�� */
    u8 abyGeoidUint[GPS_SEGMENT_MAX_LEN];       /* z          ���ˮ׼�浥λ*/
    u8 abyAgeofDiffData[GPS_SEGMENT_MAX_LEN];   /* b.b                      */
    u8 abyDifRefStationID[GPS_SEGMENT_MAX_LEN]; /* iiii       ΢�ֲο���ݺ� */
    BOOL32  bValid;                             /* TRUE/FALSE GGA��Ϣ��Ч��־  */
}TInfoGGA;


/*------------------------------  GSA��Ϣ�ṹ���� ----------------------------
  $GPGSA,a,b,cc,dd,ee,ff,gg,hh,ii,jj,kk,mm,nn,oo,p.p,q.q,r.r*CC<CR><LF>
 ��:$GPGSA,A,2,20,11,19,,,,,,,,,,30.5,23.0,20.0*0C
 ----------------------------------------------------------------------------
    �ֶ�    | ���ܽ���                                 | ֵ�ķ�Χ,ȫ�����ַ�
    a       | Satellite Acquisition Mode
            | ���ǻ�ȡ��ģʽ	   M = Manual (forced to operate in 2D or 3D mode)
            |                  A = Automatic (automatically switch between 2D and 3D)
    b       | Positioning Model	                        1 =	Fix not available
            | ��λģʽ                                   2 =	2D
            |                                           3 =	3D
    cc, dd, ee, ff, gg, hh, ii, jj, kk, mm, nn, oo |    ʹ�����ǵı�ţ����12��
            | Satellite PRNs used in solution (null for unused fields)
    p.p     | PDOP(Position dilution of precision)      00.0 .. 99.9
            | λ��֮����ǿ����
    q.q     | HDOP(Horizontal dilution of precision)
            | ˮƽ������ά������֮����ǿ����               00.0 .. 99.9
    r.r     | VDOP(Vertical dilution of precision)
            | ��ֱ�����߶ȣ�����֮����ǿ����               00.0 .. 99.9
---------------------------------------------------------------------------*/
typedef struct{
    u8 abySatMode1[GPS_SEGMENT_MAX_LEN];        /* a   ���ǻ�ȡ��ģʽ */
    u8 abySatMode2[GPS_SEGMENT_MAX_LEN];        /* b   ��λģʽ */
    u8 abySatIDUsed[GPS_SAT_USED_MAX_NUM][GPS_SEGMENT_MAX_LEN];/* cc..oo ʹ�����ǵı�� */
    u8 abyPDOP[GPS_SEGMENT_MAX_LEN];            /* p.p λ��֮����ǿ���� */
    u8 abyHDOP[GPS_SEGMENT_MAX_LEN];            /* q.q ˮƽ(����ά)����֮����ǿ���� */
    u8 abyVDOP[GPS_SEGMENT_MAX_LEN];            /* r.r ��ֱ(���߶�)����֮����ǿ���� */
    BOOL32  bValid;                             /* TRUE/FALSE GSA��Ϣ��Ч��־  */
}TInfoGSA;


/*------------------------------- GSV ��Ϣ�ṹ���� ---------------------------
  $GPGSV,t,m,nn,ii,ee,aaa,ss,ii,ee,aaa,ss,ii,ee,aaa,ss,ii,ce,aaa,ss*CC<CR><LF>
 ��:$GPGSV,3,1,09,11,59,040,42,28,55,322,00,24,48,223,00,08,41,239,00*79
    $GPGSV,3,2,09,20,35,136,43,27,27,208,29,07,20,287,00,19,20,069,00*7A
    $GPGSV,3,3,09,04,05,224,00*45
 ----------------------------------------------------------------------------
    �ֶ�    | ���ܽ���                                 | ֵ�ķ�Χ,ȫ�����ַ�
    t       | Number of Messages                        1 .. 3
            | �����ϱ��ܹ��м���GSV��Ϣ�������ϱ�
    m       | Message Number                            1 .. 3
            | ��ǰ����Ϣ�����
    nn      | Total number of satellites in view        0 .. 12
            | �������ǵ�����

[ For each visible satellite (four groups per message) ]:
    ii      | Satellite ID                              1 .. 32
    ee      | Elevation in degrees 
            | ���ǣ��Զ�Ϊ��λ                           0 .. 90 ��
    aaa     | Azimuth in degrees True ��λ��            0 .. 359 ��
    ss      | SNR in dB  �����                         0 .. 99
[ End each visible satellite (four groups per message) ]		
---------------------------------------------------------------------------*/
typedef struct{
    u8       abySatID[GPS_SEGMENT_MAX_LEN];        /* ii  ���Ǳ�� */
    u8       abyElevation[GPS_SEGMENT_MAX_LEN];    /* ee  ����,�Զ�Ϊ��λ */
    u8       abyAzimuth[GPS_SEGMENT_MAX_LEN];      /* aaa ��λ�� */
    u8       abySNR[GPS_SEGMENT_MAX_LEN];          /* ss  SNR����� */
}TSatInfo;

typedef struct{
    u8       abyMsgsNum[GPS_SEGMENT_MAX_LEN];      /* t   �����ϱ��ܹ��м���GSV��Ϣ */
    u8       abyMsgID[GPS_SEGMENT_MAX_LEN];        /* m   ��ǰ����Ϣ����� */
    u8       abySatNumInView[GPS_SEGMENT_MAX_LEN]; /* n   �������ǵ����� */
    TSatInfo atSatInfoGrp[GPS_SAT_GROUPS_PER_GSV]; /*  */
    BOOL32   bValid;                               /* TRUE/FALSE GSV��Ϣ��Ч��־  */
}TInfoGSV;


/*------------------------------  RMC��Ϣ�ṹ���� ----------------------------
  $GPRMC,hhuuss.sss,q,ddmm.mmmm,t,ooonn.nnnn,e,z.zz,g.g,aaxxyy,v,*CC<CR><LF>
 ��:$GPRMC,091431.289,A,3111.3360,N,12125.8905,E,0.00,,081105,,*18
 ----------------------------------------------------------------------------
    �ֶ�    | ���ܽ���                                 | ֵ�ķ�Χ,ȫ�����ַ�
    hh      | Hours (time stamp of position) ʱ	        0 .. 23
    uu      | Minutes (time stamp of position) ��       0 .. 59
    ss.sss  | Seconds (time stamp of position) ��.����  0 .. 59.999
    q       | Status                                    A = data valid
            | ����״ָ̬ʾ                              	V = data Invalid
    dd      | Latitude degrees γ��,��                   0 .. 90
    mm.mmmm | Latitude minutes γ��,��                  00.0000 .. 59.9999
    t       | Latitude direction                        N = North��γ
            | γ�ȷ���                                   S = South��γ
    ooo     | Longitude degrees ����,��                  0 .. 180
    nn.nnnn | Longitude minutes ����,��                  00.0000 .. 59.9999
    e       | Longitude direction                       E = East����
            | ���ȷ���                                   W = West����
    z.zz    | Speed Over Ground in knots �������ٶ�      ��λ���ڣ�����/Сʱ
            |                                           С����ǰ�泤�Ȳ���
    g.g     | Course Over Ground in degrees referenced  �ٶ�Ϊ0ʱ����Ϊ��
            | to true north ��������ʻ����ǣ�������Ϊ0��	0.0 .. 359.9
    aa      | Day (time stamp of position) ��           1 .. 31
    xx      | Month (time stamp of position) ��	        1 .. 12
    yy      | Year (time stamp of position) modulo 100��	00 .. 99
    v       | Magnetic Variation                        E = East ʵ����Ϣ�и���û��Ϊ��
            |                                           W = West
    UTCΪ��������ʱ��,��ΪT,���Ǿ���Ϊ0�ĵ����ľ���ʱ�䡣
    ����ʱ���㷨:����x��ʱ��=(T+12*x/180)%24; ����x��ʱ��=(24+T-12*x/180)%24
---------------------------------------------------------------------------*/
typedef struct{
    u8 abyUTC[GPS_SEGMENT_MAX_LEN];             /* hhuuss.sss ��������ʱ�� */
    u8 abyStatus[GPS_SEGMENT_MAX_LEN];          /* q          ����״ָ̬ʾ */
    u8 abyLatitude[GPS_SEGMENT_MAX_LEN];        /* ddmm.mmmm  γ�� */
    u8 abyLatitudeDir[GPS_SEGMENT_MAX_LEN];     /* t          γ�ȷ��� */
    u8 abyLongitude[GPS_SEGMENT_MAX_LEN];       /* ooonn.nnnn ���� */
    u8 abyLongitudeDir[GPS_SEGMENT_MAX_LEN];    /* e          ���ȷ��� */
    u8 abySpeedInKnots[GPS_SEGMENT_MAX_LEN];    /* z.zz       �ٶ�:����/Сʱ */
    u8 abyCourse[GPS_SEGMENT_MAX_LEN];          /* g.g        ��ʻ����� */
    u8 abyDate[GPS_SEGMENT_MAX_LEN];            /* aaxxyy     ������ */
    u8 abyMagneticVar[GPS_SEGMENT_MAX_LEN];     /* v          ���� */
    u8 abyReserved[GPS_SEGMENT_MAX_LEN];        /* NULL reserved */
    BOOL32  bValid;                             /* TRUE/FALSE RMC��Ϣ��Ч��־  */
}TInfoRMC;


/*------------------------------  VTG��Ϣ�ṹ���� ----------------------------
  $GPVTG,a.a,b,c.c,d,e.e,f,g.g,h*CC<CR><LF>
 ��:$GPVTG,,T,,M,0.00,N,0.0,K*7E
 ----------------------------------------------------------------------------
    �ֶ�    | ���ܽ���                                  | ֵ�ķ�Χ,ȫ�����ַ�
    a.a     | Course Over Ground in degrees True �����  0 .. 359.9 û��ʱΪ��
    b       | Units ��λ                                 T = degrees true
    c.c     | Course Over Ground in degrees magnetic     Always null
    d       | Units                                      M = degrees magnetic
    e.e     | Speed Over Ground in knots                 �����ٶ�
            |                                            ��λ���ڣ�����/Сʱ
    f       | Units                                      N = Knots ��λ���ڣ�����/Сʱ
    g.g     | Speed Over Ground in km/hr                 �����ٶ� ��λ������/Сʱ
    h       | Units                                      K = km/hr
---------------------------------------------------------------------------*/
typedef struct{
    u8 abyCourseTrue[GPS_SEGMENT_MAX_LEN];      /* a.a        ����� */
    u8 abyCourseTrueUnits[GPS_SEGMENT_MAX_LEN]; /* b          T = degrees */
    u8 abyCourseMag[GPS_SEGMENT_MAX_LEN];       /* c.c        Always null */
    u8 abyCourseMagUnits[GPS_SEGMENT_MAX_LEN];  /* d          M = degrees magnetic */
    u8 abySpeedInKnots[GPS_SEGMENT_MAX_LEN];    /* e.e        �ٶ�:����/Сʱ */
    u8 abySpeedKnotsUnit[GPS_SEGMENT_MAX_LEN];  /* f          N = Knots */
    u8 abySpeedInKmhr[GPS_SEGMENT_MAX_LEN];     /* g.g        �ٶ�:����/Сʱ */
    u8 abySpeedKmhrUnit[GPS_SEGMENT_MAX_LEN];   /* h          K = km/hr */
    BOOL32  bValid;                             /* TRUE/FALSE VTG��Ϣ��Ч��־  */
}TInfoVTG;


/*  GPS����NMEA0183Э���������Ϣ֡�Լ�����״̬�ṹ���� */
typedef struct{
    s32    nRtnStatus;                   /* �ص�ʱ���صĹ���״̬����GPS����ֵ����
                                            ֻ�и�ֵΪGPS_OPT_SUCCESSʱ�������ݲ���Ч */
    TInfoGGA tInfoGGA;                   /* GGA��Ϣ */
    TInfoGSA tInfoGSA;                   /* GSA��Ϣ */
    TInfoGSV tInfoGSV[GPS_GSV_MAX_MSGS]; /* GSV��Ϣ */
    TInfoRMC tInfoRMC;                   /* RMC��Ϣ */
    TInfoVTG tInfoVTG;                   /* VTG��Ϣ */
}TGpsOutInfo;


/* �ص��������Ͷ��� */
typedef void (*TGpsMsgCallBack)(u8 byGpsID, TGpsOutInfo *ptGpsOutInfo);


/* ����GPS�������Ĳ����ṹ���� */
typedef struct{
    u8           byComPort;           /* ���ںţ�һ���� #define BRD_SERIAL_RS232 0 */
    u32          dwBautrate;          /* ���ڲ����ʣ���0��ʹ��Ĭ��ֵ9600��
                                         ĿǰGPS�豸Ҫ��Ϊ9600,�������Ϊ38400 */
    TGpsMsgCallBack ptMsgCallBack;    /* �ص�����ָ�� */
}TGpsOpenParam;



/* �������� */
s32 GpsOpen(u8 byGpsID, TGpsOpenParam *ptGpsOpenParam);  /* ��GPSЭ�����ģ�� */
s32 GpsClose(u8 byGpsID);                                /* �ر�GPSЭ�����ģ�� */
s32 GpsVersion(u8 *pbyBuf, u32 dwBufLen, u32 *pdwVerLen);/* ��ѯGPSЭ�������汾�� */

#ifdef __cplusplus
}
#endif

#endif /* __INC_GPS_LIB_H */