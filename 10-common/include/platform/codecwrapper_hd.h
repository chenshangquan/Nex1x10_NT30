/*****************************************************************************
  模块名      : Codecwrapper.a
  文件名      : codecwrapper_hd.h
  相关文件    : codecwrapperdef_hd.h
  文件实现功能: 
  作者        : 朱允荣
  版本        : V4.0  Copyright(C) 2007-2008 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2007/11/28  4.0         朱允荣      创建
******************************************************************************/
#ifndef _CODECWRAPPER_HD_H_
#define _CODECWRAPPER_HD_H_

#if defined(_MEDIACTRL_DM816x_)||defined(_MEDIACTRL_GMPU_)

#include "dm816x/codecwrapper_hd.h"

#else

#include "codecwrapperdef_hd.h"


class CVideoEncoder;
class CAudioEncoder;
class CVideoDecoder;
class CAudioDecoder;
class CLogoAdd;


class CKdvVidEnc
{
public:
	CKdvVidEnc();
	~CKdvVidEnc();
public:
	//向下兼容，t300 不使用
	u16    CreateEncoder(TEncoder *pEncoder);                 /*HD1等使用*/
    u16    Create(TVidEncInit* pEnc, void* pReserve = NULL);  /*二代高清终端请使用这个接口*/
	u16    CreateHD3(TVidEncHD3RD* pEnc);							/*三代高清使用这个接口*/

	/************************************************************************/
	/* 函数名:  Create                                                      */  
	/* 函数参数:                                                            */
	/*          TNetraCodecInfo*   pEnc    描述编码器的实际位置以及序号     */
	/* 函数功能: 编码器的创建 创建成功返回0 								*/
	/************************************************************************/	
    u16    Create(TVidEncHDX500* pEnc); 

	/*获取编码器状态*/
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);

	/*获取编码器的统计信息*/
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis);

	/************************************************************************/
	/* 函数名:   SetVidDataCallback                                          */  
	/* 函数参数:                                                             */
	/*           FRAMECALLBACK fVidData     回调函数地址                     */
	/*           void* pContext             回调函数的参数					*/
	/*																		*/
	/* 函数功能:	设置视频编码数据回调									*/
	/************************************************************************/
	u16    SetVidDataCallback(FRAMECALLBACK fVidData, void* pContext); 

    /************************************************************************/
    /* 函数名:     SetEncQualityEnhance                                      */  
    /* 函数参数:                                                             */
    /*              BOOL32 bEnhance                                         */
    /* 函数功能:  追加编码清晰度接口，										*/
	/*				TRUE为提高清晰度，FALSE为关闭清晰度。会有性能损失	    */
    /************************************************************************/
	u16    SetEncQualityEnhance(BOOL32 bEnhance);
	
	/************************************************************************/
	/* 函数名:   SetVidCapPortType                                           */  
	/* 函数参数:                                                             */
	/*           u32 dwType                                                  */
	/* 函数功能:	设置采集接口											*/
	/************************************************************************/
	u16    SetVidCapPortType(u32 dwType);

	/************************************************************************/
	/* 函数名:  SetVideoEncParam                                             */  
	/* 函数参数:                                                             */
	/*             TVideoEncParam *ptVideoEncParam                          */
	/* 函数功能: 设置编码参数，可以运行中调用								*/
	/************************************************************************/
    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam); 

	/*得到视频编码参数*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );
	
	/*开始压缩图像*/
    u16    StartEnc();
	
	/*停止压缩图像*/
    u16    StopEnc(); 
	
	/************************************************************************/
	/* 函数名:         GetVideoSrcInfo                                       */  
	/* 函数参数:                                                             */
	/*                 TVidSrcInfo& tInfo                                    */
	/* 函数功能:	获取输入视频信号制式									*/
	/************************************************************************/
    u16    GetVideoSrcInfo(TVidSrcInfo& tInfo); /**/
	
	/************************************************************************/
	/* 函数名:      ScaleVideoCap											*/  
	/* 函数参数:															*/
	/*              u32 dwVidSrcPort :视频采集端子							 */
	/*              u8 byType        :调节类型 VIDCAP_SCALE_BRIGHTNESS 等	*/
	/*				u8 byValue       :调节数值 0~255; 0x80为默认值			*/
	/* 函数功能:	调节视频采集参数										*/
	/************************************************************************/
    u16    ScaleVideoCap(u32 dwVidSrcPort,u8 byType, u8 byValue); 
	
	/************************************************************************/
	/* 函数名:      SetFastUpata                                             */  
	/* 函数参数:                                                             */
	/*              BOOL32 bIsNeedProtect 是否开启1s内保护                   */
	/* 函数功能:	强制编一帧关键帧，调用间隔最少1s						*/
	/************************************************************************/
	u16    SetFastUpata(BOOL32 bIsNeedProtect = TRUE);   
	
	/************************************************************************/
	/* 函数名:      SetSendStaticPic                                         */  
	/* 函数参数:                                                             */
	/*              BOOL32  bSendStaticPic                                   */
	/* 函数功能:	发送静态图片											 */
	/************************************************************************/
	u16    SetSendStaticPic(BOOL32  bSendStaticPic);
	
	/************************************************************************/
	/* 函数名:         StartAddLogoInEncStream                              */  
	/* 函数参数:                                                            */
	/*                 TFullLogoParam &tLogoParm                            */
	/* 函数功能:	设置台标参数并开启台标									*/
	/************************************************************************/
    u16	   StartAddLogoInEncStream(TFullLogoParam &tLogoParm);
	
	/************************************************************************/
	/* 函数名:         StopAddLogoInEncStream                               */  
	/* 函数参数:                                                            */
	/* 函数功能:	关闭台标												*/
	/************************************************************************/
	u16    StopAddLogoInEncStream();

    u16 StartAddBannerInEncStream(TFullBannerParam &tBannerParam, BOOL32 bSpaceArea=TRUE/*图片前后是否带有空白区*/);

    //停止横幅融入码流
	u16 StopAddBannerInEncStream();
	
	/************************************************************************/
	/* 函数名:   SetVidEncResizeMode                                         */  
	/* 函数参数:                                                             */
	/*           s32 nMode    0-黑边， 1-裁边， 2-非等比拉伸                 */
	/* 函数功能: 设置编码前处理策略（加黑边，裁边等）						*/
	/************************************************************************/
    u16    SetVidEncResizeMode(s32 nMode);
	
	/************************************************************************/
	/* 函数名:   SetVidPlayPolicy                                            */  
	/* 函数参数:                                                             */
	/*           u32 dwTimeout     超时                                      */
	/*           u32 dwPlayType    无图像填充类型         					*/
	/* 函数功能: 设置本地播放策略，支持蓝屏和静态图							*/
	/************************************************************************/
    u16    SetVidPlayPolicy(u32 dwTimeout = 5, u32 dwPlayType = EN_PLAY_LAST);
	
	/************************************************************************/
	/* 函数名:      SetVidSrcCutLines                                       */  
	/* 函数参数:                                                             */
	/*             u32 dwLCutLine 左侧裁边像素数（16 倍数）                 */
	/*             u32 dwRCutline 右侧裁边像素数（16 倍数）					*/
	/* 函数功能: 采集图像左右裁边，主要用于采集图像左右边缘不正常情况		*/
	/************************************************************************/
	u16    SetVidSrcCutLines(u32 dwLCutLine, u32 dwRCutline);
protected:
private:
	CVideoEncoder *m_pCodec;
};

class CKdvAudEnc
{
public:
	CKdvAudEnc();
	~CKdvAudEnc();
public:
	u16    CreateEncoder(TEncoder *pEncoder, u32 dwDevVersion=en_X500_Board);

	u16    SetAudDataCallback(FRAMECALLBACK fAudData, void* pContext);/*设置音频数据回调*/
	/*获取输入音频功率*/
	u32    GetInputAudioPower();
	
    u16    GetEncoderStatus(TKdvEncStatus &tKdvEncStatus);/*获取编码器状态*/ 		
    u16    GetEncoderStatis(TKdvEncStatis &tKdvEncStatis );/*获取编码器的统计信息*/    
	
    u16    StartAudioCap();/*开始语音采集*/
    u16    StopAudioCap(); /*停止语音采集*/

    u16    SetAudioEncParam(u8 byMediaMode, 
                            u8 byMediaType=MEDIA_TYPE_PCMU,
                            u16 wAudioDuration = 30); /*设置语音压缩参数*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*得到语音压缩参数*/

	u16    StartAudioEnc();/*开始压缩语音*/
    u16    StopAudioEnc(); /*停止压缩语音*/

    u16    SetAudioMute( BOOL32 bMute );     //设置是否编静音码流

    u16    SetAudioVolume(u8 byVolume ); /*设置采集音量*/	
    u16    GetAudioVolume(u8 &byVolume );/*获取采集音量*/
    
    u16    SetAudInPort(u32 dwAudPort, u32 dwAudMasterMic);  /*设置音频采集端口（包括主麦，即所有音频口;第二个参数只设置主麦，用于AEC处理，其他接口不作AEC处理)*/	
	
    u16    StartAec();/*开始回声抵消*/
    u16    StopAec(); /*停止回声抵消*/

	u16	   StartAgcSmp(); /*开始smp增益*/
	u16	   StopAgcSmp(); /*停止smp增益*/
	u16	   StartAgcSin(); /*开始sin增益*/
	u16	   StopAgcSin(); /*停止sin增益*/		
protected:
private:
	CAudioEncoder *m_pCodec;
};

class CKdvVidDec
{
public:
	CKdvVidDec();
	~CKdvVidDec();
public:
	//向之前兼容，t300 ppc侧不使用
	u16	   CreateDecoder(TDecoder *pDecoer);   /*HDU, HD1等使用*/
    u16    Create(TVidDecInit* pDec, void* pReserve = NULL); /*二代高清终端请使用这个接口*/
	u16    CreateHD3(TVidDecHD3RD* pDec);


	/************************************************************************/
	/* 函数名:    Create                                                    */  
	/* 函数参数:                                                            */
	/*            TNetraCodecInfo* pDec    解码器创建参数                   */
	/* 函数功能:  解码器创建												*/
	/************************************************************************/
    u16    Create(TVidDecHDX500* pDec);

	/************************************************************************/
	/* 函数名:      SetData                                                 */  
	/* 函数参数:                                                             */
	/*              TFrameHeader& tFrameInfo                                */
	/* 函数功能:	设置视频码流数据										*/
	/************************************************************************/
	u16    SetData(const TFrameHeader& tFrameInfo);  
	
	/*开始图像解码*/
    u16    StartDec();

	/*停止图像解码*/
    u16    StopDec(); 

	/*获取解码器状态*/
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);

	/*获取解码器的统计信息*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);	


	/************************************************************************/
	/* 函数名:      SetVidPIPParam                                           */  
	/* 函数参数:                                                             */
	/*             enVideoPIPMode enMode 画中画风格                          */
	/*             enVideoPIPIndexEX enIndex[3] 子画面内容           		*/
	/* 函数功能:	设置视频画中画模式，最大支持3画面合成					*/
	/************************************************************************/
    u16 SetVidPIPParam(enVideoPIPMode enMode, enVideoPIPIndex enIndex[3]);
    

	/************************************************************************/
	/* 函数名:      SetPlayScale                                             */  
	/* 函数参数:                                                             */
	/*               u16 wWidth  :显示宽比例，0为自动                       */
	/*               u16 wHeight :显示高比例，0为自动						*/
	/* 函数功能:	设置播放设备的显示比例									*/
	/*               播放制式为16:9,设置4:3后图像上下加黑边                 */
	/*               播放制式为4:3,设置16:9后图像左右加黑边                 */
	/************************************************************************/
    u16    SetPlayScale(u16 wWidth, u16 wHeight);
    
	/************************************************************************/
	/* 函数名:      SetVidPlyPortType                                        */  
	/* 函数参数:                                                             */
	/*               u32 dwType   播放口                                    */
	/* 函数功能:	设置主解码播放口										*/
	/************************************************************************/
    u16    SetVidPlyPortType(u32* dwPortList, u32 dwNum);

	/************************************************************************/
	/* 函数名:      SetVideoPlyInfo                                          */  
	/* 函数参数:                                                             */
	/*               u32 dwOutType     视频制式枚举                          */
	/* 函数功能:	设置视频输出信号制式									 */
	/************************************************************************/
    u16    SetVideoPlyInfo(u32 dwOutType = VID_OUTTYPE_ORIGIN);

	/************************************************************************/
	/* 函数名:      SetVideoPlyInfo                                          */  
	/* 函数参数:                                                             */
	/*               TVidSrcInfo* ptInfo     视频制式                        */
	/* 函数功能:	设置视频输出信号制式									 */
	/************************************************************************/
    u16    SetVideoPlyInfo(TVidSrcInfo* ptInfo); 

	/*获取输出视频信号制式*/
    u16    GetVideoSrcInfo(TVidSrcInfo& tInfo);   

	/************************************************************************/
	/* 函数名:     SetVidDecResizeMode                                       */  
	/* 函数参数:                                                             */
	/*             s32 nMode     处理策略：0：加黑边；1：裁边; 2:非等比      */
	/* 函数功能:   设置解码后处理策略										*/
	/************************************************************************/
	u16	   SetVidDecResizeMode(s32 nMode);

	/************************************************************************/
	/* 函数名:     SetVidOutCallBack                                        */  
	/* 函数参数:                                                             */
	/*             VIDOUTTYPECALLBACK fVidOutType  回调函数地址             */
	/* 函数功能:	设置视频制式创建成功后回调函数							*/
	/************************************************************************/
	u16	   SetVidOutCallBack(VIDOUTTYPECALLBACK fVidOutType);

	/************************************************************************/
	/* 函数名:      TestImage                                               */  
	/* 函数参数:                                                            */
	/*              BOOL32 bSet                                             */
	/* 函数功能:	开启/关闭得带测试										*/
	/************************************************************************/
	u16	   TestImage(BOOL32 bSet);

	/************************************************************************/
	/* 函数名:     SnapShot                                                  */  
	/* 函数参数:                                                             */
	/*             s8* pFileName    文件的全路径                            */
	/* 函数功能:   保存一帧播放图像为jpeg文件								*/
	/************************************************************************/
	u16    SnapShot(s8* pFileName);

	/************************************************************************/
	/* 函数名:     SnapShotView                                              */  
	/* 函数参数:                                                             */
	/*             s8* pFileName    文件的全路径                             */
	/* 函数功能:	播放指定的jpeg图片，必须是快照图，停止					*/
	/************************************************************************/
	u16    SnapShotView(s8* pFileName);

	/************************************************************************/
	/* 函数名:     SetVidPlayPolicy                                          */  
	/* 函数参数:                                                             */
	/*           u32 dwTimeout     超时                                      */
	/*           u32 dwPlayType    无图像填充类型         					*/
	/* 函数功能:	设置解码播放无图像显示策略								*/
	/************************************************************************/
	u16    SetVidPlayPolicy(u32 dwTimeout = 5, u32 dwPlayType = EN_PLAY_LAST);
protected:
private:
	CVideoDecoder *m_pCodec;
};

class CKdvAudDec
{
public:
	CKdvAudDec();
	~CKdvAudDec();
public:
	u16	   CreateDecoder(TDecoder *pDecoer, u32 dwDevVersion=en_X500_Board);
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);/*获取解码器状态*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);/*获取解码器的统计信息*/	

    u16    SetData(const TFrameHeader& tFrameInfo); /*设置音频码流数据*/
    u16    SetAudioDecParam(const TAudioDecParam& tAudParam);/*音频解码参数，AAC有效*/ 
    
    u16    SetAudOutPort(u32 dwAudPort);  /*设置音频播放端口*/

    u16    StartDec();/*开始声音解码*/	
    u16    StopDec(); /*停止声音解码*/	
    u16    SetAudioVolume(u8 byVolume );  /*设置输出声音音量*/	
    u16    GetAudioVolume(u8 &pbyVolume );/*得到输出声音音量*/	
    u16    SetAudioMute(BOOL32 bMute);/*设置静音*/
		
	/*获取输出音频功率*/
	u32    GetOutputAudioPower();
	
	//播放铃声 ？？？
	u16   PlayRing(s8* pData = NULL);
	u16   StopRing();
protected:
private:
	CAudioDecoder *m_pCodec;
};

///Osd相关设置

//设置osd参数,若播放口制式发生变化，需要重新设置osd参数
/*
typedef struct
{
	TVidSrcInfo tVid0Std;      //主播放口制式
	TVidSrcInfo tOsd0Std;      //标清口制式
	u32  dwTransVal;       //透明度(0-255)，0:全透，255:不透,128:半透
	u32  dwTransKeyY;      //透明色
} TVidOsdParam;
*/
void SetOsdParam(TVideoOsdParam tOsdParam);

//osd显示
void StartOsd();

//关闭osd
void StopOsd();

//关闭与恢复视频显示
void SetVideoShow(BOOL32 bShow);

//设定当前*.bin,*.out路径，默认/usr/bin
void SetCodecAppDir(s8* szPath);
//注册OSP命令
void RegsterCommands();

//初始化DSP芯片
u16 HardCodecInitDSP(TDSPInit* pInit);
u16 HardCodecDestroyDSP(u32 dwDSPID);
//初始化FPGA
u16 HardCodecDevInit(u32 nDecDevNum, u32 nEncDevNum);
u16 HardCodecDestroy();

//接口FPGA设置
    /*函数名： SetVideoOutFromVidIn
    功    能： 切换输入口视频到指定输出接口输出。
    参    数： u32 dwFromVidIn：输入接口类型VIDIO_HDMI0等，只能指定一个接口
               u32 dwVidOut   ：输出接口类型VIDIO_HDMI0等，可指定多个接口
                                如（VIDIO_YPbPr0|VIDIO_HDMI0）
               TVidSrcInfo* ptOutInfo:输出视频格式，可为NULL
    返 回 值： u16 :0 成功，非零 失败。
    说    明： 可一对多，不能多对多或多对一*/
u16 SetVideoOutFromVidIn(u32 dwFromVidIn, u32 dwVidOut, TVidSrcInfo* ptOutInfo = NULL);
    /*函数名： SetVideoOutFromVidDec
    功    能： 切换解码器的输出内容到其他接口。
    参    数： u32 dwFromDecVP：作为输入的解码器的VPID (0 , 1, 2)
               u32 dwVidOut   ：输出接口类型VIDIO_HDMI0等，可指定多个接口
               TVidSrcInfo* ptOutInfo：输出视频格式，不能为NULL
    返 回 值： u16 
    说    明： */
u16 SetVideoOutFromVidDec(u32 dwFromDecVP, u32 dwVidOut, TVidSrcInfo* ptOutInfo);

API void SetMicVol(s32 dwVol);
API s32 GetMicVol();

/*函数名： SetCanonPowerOn
功    能： 卡农麦克风输入接口48v供电开关接口实现
参    数： BOOL32 bEnable=TRUE
返 回 值： 
说    明： */
void SetCanonPowerOn(u32 dwAudPort, BOOL32 bEnable=TRUE);

//获取数字麦插入状态
API BOOL32 GetDigitalMicStatus(u32 dwAudPort);

//获取3.5口插入状态  bIsAudIn = TRUE:采集口  FALSE:播放口
API BOOL32 Get35InOrOutStatus(BOOL32 bIsAudIn);

API BOOL32 GetTRS635Status(u32 dwAudPort);

//获取HDMI音频口状态
API BOOL32 GetAudHdmiStatus(u32 dwAudPort);

/*获取SDI接口类型 SDITYPE_ININ SDITYPE_INOUT*/
API u32 GetHDMtSDIIntType();
/*设置播放分辨率改变消息通知*/
API void SetNtscPalChangeCallBack(CHANGECALLBACK pChangeProc);

//设置芯片死机通知回调
API void SetCpuResetNotify(CpuResetNotify fNotify);

//是否启用全屏OSD
API void UseFullOSD(BOOL32 bFullOsd = TRUE);
//HDMI口输出HDMI、DVI信号选择
API void HDMIDVISwitch(BOOL32 bHDMI = TRUE);
//设置SD信号输出制式
API void SetSDOutType(u32 dwOutType = VID_OUTTYPE_ORIGIN);	   //参数参加codecwrapperdef_hd
//重启编解码设备
API void RebootCodecDev(u32 dwDevID = CODECDEV_VIDENC);	   //参数参加codecwrapperdef_hd

u16 HardEnvInitial(u32 dwHWtype);
s32 HardMPUInit(u32 nMode); //nMode:enInitMode
s32 HardMPUInitDev(u32 nEncTos, u32 nDecTos, u32 nDspNum);
s32 HardMPUDestroy();
#endif //MEDIACTRL_DM816x
#endif
