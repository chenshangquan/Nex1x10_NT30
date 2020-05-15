#ifndef _h_tpadplatstruct_h__
#define _h_tpadplatstruct_h__

#include "ummessagestruct.h"
#include <winioctl.h>


enum emTPadSubType
{
    emTPad_none = 0,
    emTPad_cnc = 0x001,
    emTPad_centerctrl = 0x002,
};

//tpad子工程连接tpad的信息
typedef struct tagTPadSubInfo
{
    u32 dwIp;
    u32 dwPort;
    emTPadSubType emType;
    
    tagTPadSubInfo()
    {
        dwIp = 0;
        dwPort = 0;
        emType = emTPad_none;
    }
}TTPadSubInfo;

//连接到TPad的节点信息
typedef struct tagNodeInfo
{
    u32 dwNodeId;
    u32 dwInstId;
    emTPadSubType emSubType;
    
    tagNodeInfo()
    {
        dwNodeId = 0;
        dwInstId = 0;
        emSubType = emTPad_none;
    }

    BOOL operator ==( const tagNodeInfo &tInfo )
    {
        if ( dwNodeId == tInfo.dwNodeId && dwInstId == tInfo.dwInstId )
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
	}
}TNodeInfo;


//TPad登录信息
typedef struct tagPadLoginInfo
{
    u32     dwCnsIp;
    u32     dwLocalIp;
    CLoginRequest  cUserInfo;
      
    tagPadLoginInfo()
    {
        dwCnsIp = 0;
        dwLocalIp = 0;
    }
}TPadLoginInfo;


//TPad 主Item信息
typedef struct tagMainMenuInfo
{
	s8  achName[TP_MAX_ALIAS_LEN_CNC+1];	            //名称
	int nIndex;                 //条目索引
	s8  achItemFunc[TP_MAX_ALIAS_LEN_CNC+1];            //条目单击事件
	s8  achImgFolder[TP_MAX_ALIAS_LEN_CNC+1];           //条目图片路径
    CString strExePath;             //exe路径及名称
    DWORD   dwProcID;               //exe打开后的进程号，否则为无效的进程号
	s8  achExeClassName[TP_MAX_ALIAS_LEN_CNC+1];        //exe主窗口类名，用于找到主窗口显示
	s8  achExeCaption[TP_MAX_ALIAS_LEN_CNC+1];          //exe主窗口标题
	BOOL    bShow;                  //是否应该显示
	
	tagMainMenuInfo()
	{
		nIndex = 0;
        dwProcID = 0;
		bShow = TRUE;
		memset(&achName, 0, sizeof(achName));
		memset(&achItemFunc, 0, sizeof(achItemFunc));
		memset(&achImgFolder, 0, sizeof(achImgFolder));
		memset(&achExeClassName, 0, sizeof(achExeClassName));
		memset(&achExeCaption, 0, sizeof(achExeCaption));
	}

	void SetNull()
	{
		nIndex = 0;
        dwProcID = 0;
		bShow = TRUE;
		memset(&achName, 0, sizeof(achName));
		memset(&achItemFunc, 0, sizeof(achItemFunc));
		memset(&achImgFolder, 0, sizeof(achImgFolder));
		memset(&achExeClassName, 0, sizeof(achExeClassName));
		memset(&achExeCaption, 0, sizeof(achExeCaption));
	}
}TMainMenuInfo;


//对系统操作类型
enum EM_OSType
{
	emLogOff = 0,      //注销
	emShutDown,        //关机
	emReboot,          //重启
	emSleep,           //待机
};

//Wifi条目数据
typedef struct tagWiFiItem
{
    s8  achSSID[TP_MAX_ALIAS_LEN_CNC+1];       //网络名称
	BOOL     bConnect;      //是否连接
    BOOL     bEncrypt;      //是否加密
	s32      nAuthType;     //加密模式
    s32      nQuality;      //信号强度

	tagWiFiItem()
	{
		memset(&achSSID, 0, sizeof(achSSID));
		bConnect = FALSE;
		bEncrypt = FALSE;
		nAuthType = 1;
		nQuality = 0;
	}
}TWifiItem;


//图片轮换方案
enum Em_ImgSchm{ 
    emImgSchm0,
    emImgSchm1,
    emImgSchm2,
    emImgSchm3,
	emImgSchm4
};

//文件类型
enum EM_FileType
{
    emFileType_image = 0,    //image
    emFileType_pdf,          //pdf
    emFileType_ppt,          //ppt
    emFileType_txt,          //txt
    emFileType_doc,          //doc
    emFileType_xls,          //xls
    emFileType_unknown,      //unknown
};

//文件类型的枚举
enum EM_DeviceType
{
        emDevice_No = 0,      //未外接设备
        emDevice_HDD,           //移动硬盘
        emDevice_Udisk,         //U盘
};


//文件信息
typedef struct tagFileInfo 
{
    s8     achFileName[TP_MAX_ALIAS_LEN_CNC+1];    //文件名
    s8     achFilePath[TP_MAX_ALIAS_LEN_CNC+1];    // 文件路径
    BOOL        bIsFolder;      //是否是文件夹
    DWORD       dwFileCount;    //包含文档数目
    EM_FileType   em_fileType;  //文件类型 
    BOOL        bExtend;
    BOOL        bSel;           //标定选择状态
	BOOL        bHighLight;     //条目是否默认高亮
    EM_DeviceType  em_DeviceType;//移动设备类型
    tagFileInfo()
    {
        memset(&achFileName, 0, sizeof(achFileName));
        memset(&achFilePath, 0, sizeof(achFilePath));
        bIsFolder = FALSE;
        bExtend = TRUE;//dyy
        dwFileCount = 0;
        em_fileType = emFileType_unknown;//dyy
        bSel = FALSE;
        em_DeviceType = emDevice_No;
		bHighLight = FALSE;
    }
    
    void setNULL()
    {
		memset(&achFileName, 0, sizeof(achFileName));
		memset(&achFilePath, 0, sizeof(achFilePath));
        bIsFolder = FALSE;
        bExtend = TRUE;
        dwFileCount = 0;
        em_fileType = emFileType_unknown;
        bSel = FALSE;
        em_DeviceType = emDevice_No;
		bHighLight = FALSE;
    }
    
    void operator=(const tagFileInfo& tCopy )
    {
		sprintf_s(achFileName, sizeof(achFileName),tCopy.achFileName);
		sprintf_s(achFilePath, sizeof(achFilePath),tCopy.achFilePath);
        bIsFolder = tCopy.bIsFolder;
        bExtend = tCopy.bExtend;
        dwFileCount = tCopy.dwFileCount;
        em_fileType = tCopy.em_fileType;
        bSel = tCopy.bSel;
        em_DeviceType = tCopy.em_DeviceType;
		bHighLight = tCopy.bHighLight;
    }
    
}TFileItem;



//面包屑文件夹管理
typedef struct tagListPathDirInfo
{
    s8 achName[TP_MAX_ALIAS_LEN_CNC+1];	            //显示文件夹名称
    s8 achItemFunc[TP_MAX_ALIAS_LEN_CNC+1];            //条目单击事件
    s8 achFullPath[TP_MAX_ALIAS_LEN_CNC+1];            //对应文件夹全路径
    CRect   rcItemRect;             //条目大小
    int nListOffSet;
    
    tagListPathDirInfo()
    {
        memset(&achName, 0, sizeof(achName));
		memset(&achItemFunc, 0, sizeof(achItemFunc));
		memset(&achFullPath, 0, sizeof(achFullPath));
        rcItemRect = NULL;
    }
    
    void SetNull()
    {
		memset(&achName, 0, sizeof(achName));
		memset(&achItemFunc, 0, sizeof(achItemFunc));
		memset(&achFullPath, 0, sizeof(achFullPath));
        rcItemRect = NULL;
    }
}TListPathDirInfo;


//检测移动硬盘 dyy

#if _MSC_VER <= 1200

#define IOCTL_STORAGE_QUERY_PROPERTY   CTL_CODE(IOCTL_STORAGE_BASE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef enum _STORAGE_PROPERTY_ID {
    StorageDeviceProperty = 0,
        StorageAdapterProperty,
        StorageDeviceIdProperty
} STORAGE_PROPERTY_ID, *PSTORAGE_PROPERTY_ID;


typedef enum _STORAGE_QUERY_TYPE {
    PropertyStandardQuery = 0, 
        PropertyExistsQuery, 
        PropertyMaskQuery, 
        PropertyQueryMaxDefined 
} STORAGE_QUERY_TYPE, *PSTORAGE_QUERY_TYPE;




typedef struct _STORAGE_PROPERTY_QUERY {
    STORAGE_PROPERTY_ID  PropertyId;
    STORAGE_QUERY_TYPE  QueryType;
    UCHAR  AdditionalParameters[1];
} STORAGE_PROPERTY_QUERY, *PSTORAGE_PROPERTY_QUERY;


typedef struct _STORAGE_DEVICE_DESCRIPTOR {
    ULONG  Version;
    ULONG  Size;
    UCHAR  DeviceType;
    UCHAR  DeviceTypeModifier;
    BOOLEAN  RemovableMedia;
    BOOLEAN  CommandQueueing;
    ULONG  VendorIdOffset;
    ULONG  ProductIdOffset;
    ULONG  ProductRevisionOffset;
    ULONG  SerialNumberOffset;
    ULONG  BusType;
    ULONG  RawPropertiesLength;
    UCHAR  RawDeviceProperties[1];
} STORAGE_DEVICE_DESCRIPTOR, *PSTORAGE_DEVICE_DESCRIPTOR;

#endif



#endif
