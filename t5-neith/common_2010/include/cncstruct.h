// cmsstruct.h: interface for the cmsstruct class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _h_cmsstruct_h__
#define _h_cmsstruct_h__

#include "tpstruct.h"
#include "addrbook.h"
#include "cncconst.h"
#include "eventoutcnsextend.h"

//会议类型
enum EM_ConfType
{
	emConfMulti = 0,      //多点会议
	emConfCascade,        //级联会议
	emConfP2P,            //点对点会议
	emConfOtherUms,       //跨UMS会议（被其它UMS呼走）
	emConfUnKnown
};


//会议信息
typedef struct tagCMSConf : public TTPConfInfo
{
    EmCallType         m_emConfType;//会议类型
    
	TplArray<TCnsInfo>	    m_tplCnsList;
	TAuxMixList	            m_tAudmixList;
	TplArray<u16>	        m_tplPollList;
    
	BOOL32		        m_bStartAudmix;//是否开启混音
    //BOOL32              m_bCascadeConf;//是否是级联会议
    TChairConfInfo      m_tCascadeConfInfo;  //级联会议信息
    
    TTPAlias	m_tChairName;		//主席名称

    u16  GetChairCnsID()
    {   
        if ( strlen(m_tChairName.m_abyAlias) > 0  )
        {
            return GetCnsIDByAlias( m_tChairName.m_abyAlias ) ;
        }
        return INVALID_WORD;
    }


    tagCMSConf& operator = (const TTPConfInfo &tConf)
    {
        if(this == &tConf)
         return *this;  

        TTPConfInfo::operator = (tConf); 
        return *this;
	}
	
 
	BOOL32 operator == (const tagCMSConf& tRhs)
	{	
		return TTPConfInfo::m_wConfID == tRhs.m_wConfID;
	}
	
	void Clear()
	{  
		m_emConfType = emCallType_Invalid;
		m_tplCnsList.Clear();
	//	m_tplAudmixList.Clear();
        m_tplPollList.Clear(); 
		m_bStartAudmix = FALSE;
        //m_bCascadeConf = FALSE;
		TTPConfInfo::Clear();
        m_tCascadeConfInfo.Clear();

        ZeroMemory( &m_tChairName,sizeof(TTPAlias ) );
	}


	tagCMSConf()
    {      
		tagCMSConf::Clear();
	}

    tagCMSConf( TTPConfInfo &tConf)
    {
        tagCMSConf::Clear();
		m_emConfType = emCallType_Invalid;
        m_tCascadeConfInfo.Clear();
		m_bStartAudmix = FALSE;
        //m_bCascadeConf = FALSE;
        TTPConfInfo::operator = (tConf);
        
	}

    void SetChairInfo( TTPAlias &tChair  )
    {
	   //memcpy( &m_tChairName, &tChair,sizeof(TTPAlias) ) ;

		m_tChairName = tChair;

		m_wDefaultChairMan = GetCnsIDByAlias( m_tChairName.m_abyAlias );
	 
    }
   
    void ClearCascadeInfo()
    {
        m_tCascadeConfInfo.Clear();
		m_emConfType = emCallType_Invalid;
        //m_bCascadeConf = FALSE;
    }
 
    s8 *GetSpeakerAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wSpeaker );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }

        return "";
    }


    s8 *GetChairManAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wDefaultChairMan );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }
        
        return "";
    }


    s8 *GetDualAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wDual );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }
        
        return "";
    }

    //根据cns的会场ID，获取具体的cns信息
    TCnsInfo* GetCnsInfoByID( u16 wCnsID )
    {
        s32 nCont = m_tplCnsList.Size();
        for ( s32 i = 0; i< nCont; i++ )
        {
            if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID ) 
            {
                return &(m_tplCnsList.GetAt(i));
            }
	   }
        return NULL;
    }

	//根据会场名，获取cns信息
	TCnsInfo* GetCnsInfoByAlias( s8* strAlias )
	{
		s32 nCont = m_tplCnsList.Size();
		for ( s32 i = 0; i< nCont; i++ )
		{
			if ( strcmp( m_tplCnsList.GetAt(i).m_achRoomName, strAlias) == 0 ) 
			{
				return &m_tplCnsList.GetAt(i);
			}
		}
		return NULL;
	}

   
	//根据cns的会场ID，查找其在会场列表的序列号
	s32 GetCnsIndexFrmCnsLst( u16 wCnsID )
	{
       s32 nCont = m_tplCnsList.Size();
	   for ( s32 i = 0; i< nCont; i++ )
	   {
		   if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID) 
		   {
			   return i;
		   }
	   }

	   return -1;
	}


    //根据cns别名获取cns的ID
    u16 GetCnsIDByAlias( s8* strAlias )
    {
        s32 nCont = m_tplCnsList.Size();
        for ( s32 i = 0; i< nCont; i++ )
        {
            if ( strcmp( m_tplCnsList.GetAt(i).m_achRoomName, strAlias) == 0 ) 
            {
                return m_tplCnsList.GetAt(i).m_wEpID;
            }
	   }
        
        return INVALID_WORD;
    }

 
   TCnsInfo *GetCnsInfoFrmCnsLst( u16 wCnsID )
   {
       s32 nCont = m_tplCnsList.Size();
       for ( s32 i = 0; i< nCont; i++ )
       {
           if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID) 
           {
               return &m_tplCnsList.GetAt(i);
           }
	   }
       return NULL;
   }
 

   //根据cns的会场ID，查找其在混音列表的序列号
	s32 GetCnsIndexFrmAuxLst( u16 wCnsID )
	{
		//s32 nCont = m_tplAudmixList.Size();
		for ( u16 i = 0; i< TP_CONF_MAX_AUDMIXNUM; i++ )
		{
			if ( m_tAudmixList.m_awList[i] == wCnsID) 
			{
				return i;
			}
		}
		
		return -1;
	}

	//根据cns的会场ID，查找其在轮询列表的序列号
	s32 GetCnsIndexFrmPollLst( u16 wCnsID )
	{
		s32 nCont = m_tplPollList.Size();
		for ( s32 i = 0; i< nCont; i++ )
		{
			if ( m_tplPollList.GetAt(i) == wCnsID) 
			{
				return i;
			}
		}
		
		return -1;
	}

	BOOL32 IsCnsInConf( s8* achRoomName )
	{
		for ( int i = 0; i < m_tplCnsList.Size(); i++ )
		{
			if ( strcmp( achRoomName, m_tplCnsList.GetAt(i).m_achRoomName ) == 0 )
			{
				if ( m_tplCnsList.GetAt(i).m_bOnline )
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
		return FALSE;
	}
	
	BOOL32 IsStartAudMix()
	{
		return m_bStartAudmix;
	}

}TCMSConf,*PTCMSConf;



//屏信息
typedef struct tagScreenInfo
{
	u8  byScreenID;
	s8  achCnsName[TP_MAX_ALIAS_LEN_CNC+1];
	EmTPPosStatus  emScreenState;
	EMPosPic emPosPic;    

	tagScreenInfo()
	{
		byScreenID = 0;		
		ZeroMemory( achCnsName, sizeof(achCnsName) );
		emScreenState = emPosInAcitve;
		emPosPic = emPic_Invalid;
	}
} TScreenInfo, *PTScreenInfo;
 

//坐席信息
typedef struct tagSeatInfo{
	u8 bySeatID;              
	BOOL32 bSpokesMan;
	
	tagSeatInfo()
	{
          bySeatID = 0;
          bSpokesMan = FALSE;
	}
} TSeatInfo, *PTSeatInfo;



 //会议中的会场状态 
enum EM_CnsState{
    emCnsStateMute = 0x1,         //哑音  ，二进制的第一位：0 表示非哑音，1表示哑音
    emCnsStateSilence = 0x2,      //  静音，二进制的第二位：0 表示非静音，1表示静音
    emCnsStateDbFolw = 0x4,     // 双流 ,   二进制的第三位：0 表示非 双流 ，1表示 双流 
};

//RoomInfo : CNS
typedef struct tagTCnsInfoEx :public TCnsInfo
{
    DWORD dwIndex;    //在commeninterface类中，该结构体的存储序号
    BOOL32 bMute;       //是否哑音 
    BOOL32 bSilence;   // 是否静音
    BOOL32 bDbFlow;  //是否双流 
   
    BOOL32 operator ==( tagTCnsInfoEx & cnsInfo )
    {   
        BOOL32 re = FALSE;
        if ( this->dwIndex == cnsInfo.dwIndex && 
               (TCnsInfo::operator == (cnsInfo) ) )
        {
            re = TRUE;
        }
        return re;
    }


    tagTCnsInfoEx()
    {
        TCnsInfo::Clear();
       dwIndex = 0;
       bMute = FALSE;
       bSilence = FALSE;
       bDbFlow = FALSE;
    }

}TCnsInfoEx, *PTCnsInfoEx;


typedef struct tagTPAddrInfo
{
	u32  dwEntryIdx;                               // 条目索引
	u32  dwInGroupIdx;                             // 所属分组 
	s8   achEntryName[TP_MAX_ALIAS_LEN_CNC+1];
	s8   achE164[TP_MAX_ALIAS_LEN_CNC+1];
    BOOL              bOnLine;                     // 是否在线
	EmTPEndpointType  m_emEndpointType;		       // 地址类型

	tagTPAddrInfo()
	{ 
		SetNull();
	}

	BOOL32 operator ==( const tagTPAddrInfo & tInfo )
    {   
		if ( strcmp( achEntryName, tInfo.achEntryName ) == 0 && dwEntryIdx == tInfo.dwEntryIdx &&  dwInGroupIdx == tInfo.dwInGroupIdx )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
    }

	void SetNull()
	{
		dwEntryIdx = INVALID_INDEX;
		dwInGroupIdx = INVALID_INDEX;
		memset( achEntryName, 0, sizeof(achEntryName) );
		memset( achE164, 0, sizeof(achE164) );
        bOnLine = FALSE;
		m_emEndpointType = emTPEndpointTypeUnknown;
	}

	BOOL32 IsNull()
	{
		if ( dwEntryIdx == INVALID_INDEX )
		{
			return TRUE;
		}
		return FALSE;
	}
}TAddrInfo;

typedef struct tagTPGroupInfo
{
	u32 dwGroupIdx;
	u32 dwInGroupIdx;                              // 所属分组 
	s8  achGroupName[TP_MAX_ALIAS_LEN_CNC+1];          // 组名
	s32 nEntryNum;                                 // 条目个数
	u32 adwEntryIdx[MAXNUM_ENTRY_TABLE];	       // 与会终端索引
	s32 nDownGroupNum;                             // 下级组个数
	tagTPGroupInfo()
	{ 
		SetNull();
	}

	BOOL operator ==( const tagTPGroupInfo & tInfo )
	{
		if ( strcmp( achGroupName, tInfo.achGroupName ) == 0 && dwGroupIdx == tInfo.dwGroupIdx )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	void SetNull()
	{
		dwGroupIdx = INVALID_INDEX;
		dwInGroupIdx = INVALID_INDEX;
		memset( achGroupName, 0, sizeof(achGroupName) );
		nEntryNum = 0;
		memset( adwEntryIdx, 0, sizeof(adwEntryIdx) );
		nDownGroupNum = 0;
	}
	BOOL32 IsNull()
	{
		if ( dwGroupIdx == INVALID_INDEX )
		{
			return TRUE;
		}
		return FALSE;
	}
}TGroupInfo;

enum EM_ItemType
{
	emEntryItem = 0,
	emGroupItem,
};

typedef struct tagAddrItem
{
	EM_ItemType emItemType;
	TAddrInfo   tAddrInfo;
	TGroupInfo  tGroupInfo;
	s8     achImg[TP_MAX_ALIAS_LEN_CNC+1];
	s8     achNameLetter[TP_MAX_ALIAS_LEN_CNC+1];
	
	tagAddrItem()
	{ 
		emItemType = emEntryItem;
		memset(achImg, 0, sizeof(achImg));
		memset(achNameLetter, 0, sizeof(achNameLetter));
	}

	BOOL operator ==( const tagAddrItem & tItem )
    {
		if ( emItemType == tItem.emItemType )
		{
			if ( emItemType == emEntryItem )
			{
				return tAddrInfo == tItem.tAddrInfo;
			}
			else
			{
				return tGroupInfo == tItem.tGroupInfo;
			}
		}
		else
		{
			return FALSE;
		}
	}

	BOOL32 IsNull()
	{
		if ( emItemType == emEntryItem )
		{
			return tAddrInfo.IsNull();
		}
		else
		{
			return tGroupInfo.IsNull();
		}
	}

	void SetNull()
	{
		emItemType = emEntryItem;
		tAddrInfo.SetNull();
		tGroupInfo.SetNull();
		memset(achImg, 0, sizeof(achImg));
		memset(achNameLetter, 0, sizeof(achNameLetter));
	}

	BOOL IsSameName( tagAddrItem& tItem )
	{
		if ( emItemType == tItem.emItemType )
		{
			if ( emItemType == emEntryItem )
			{
				//条目名称和E164号全部一样才相等
				if ( strcmp( tAddrInfo.achEntryName, tItem.tAddrInfo.achEntryName ) == 0 
					&& strcmp( tAddrInfo.achE164, tItem.tAddrInfo.achE164 ) == 0 )
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
				return strcmp( tGroupInfo.achGroupName, tItem.tGroupInfo.achGroupName ) == 0;
			}
		}
		else
		{
			return FALSE;
		}
	}
	
}TAddrItem;


enum EM_AddrShowState
{
    emShowAllAddr = 0,
    emShowGroup,
    emShowOnline,
    emShowOffline,
}; 

typedef struct tagConfCallEpAddrList 
{
    u16 m_wConfID;
    TEpAddrList m_tEpAdrLst;
    tagConfCallEpAddrList()
    { 
        m_wConfID = INVALID_WORD;
    }

    VOID Clear()
    {
        m_wConfID = INVALID_WORD;
        ZeroMemory( &m_tEpAdrLst, sizeof(TEpAddrList));
    }

} TConfCallEpAddrList;


//电视墙信息
typedef struct tagCmsTvwInfo: public TTPHduRegInfo
{  
    BOOL bCodeStream; 

    tagCmsTvwInfo():TTPHduRegInfo()
    { 
       bCodeStream = TRUE;
    }

    void ClearCnsInfo()
    { 
        ZeroMemory( m_achAlias, sizeof(m_achAlias) ) ;
        
    }

    u16 SetCnsInfo(const s8 *pCnsAliars  )
    {
        if ( pCnsAliars == NULL )
        {
            return ERR_CMS_CNS_ALIARS_EMPTY;
        }
       
        _snprintf( m_achAlias, sizeof(m_achAlias), "%s",pCnsAliars );  
        return NO_ERROR; 
    }

    tagCmsTvwInfo &operator = ( TTPHduRegInfo & tHdu)
    {
        TTPHduRegInfo::operator = (tHdu);
//         _snprintf( m_achAlias, sizeof(m_achAlias), "%s",tHdu.m_achAlias );
//          m_dwChannelHandle = tHdu.m_dwChannelHandle;
//          m_bIsOnline = tHdu.m_bIsOnline;	//HDU是否注册
//          m_dwIpAddr = tHdu.m_dwIpAddr;		//外设IP地址	,   网络序
//          m_wStartPort = tHdu.m_wStartPort;	//外设起始接收端口, 主机序  
 
         return *this;
    } 

   
   
    
    BOOL32 operator == (const tagCmsTvwInfo& tRhs)
    {	
        return  m_dwChannelHandle == tRhs.m_dwChannelHandle;
	}

}TCmsTvwInfo;

//登录信息
typedef struct tagLoginInfo
{
	u32     dwIp;
	u16     nPort;
	s8      achName[TP_MAX_ALIAS_LEN_CNC+1];
	s8      achPswd[TP_MAX_ALIAS_LEN_CNC+1];

	tagLoginInfo()
	{
		memset( this, 0, sizeof(tagLoginInfo) );
	}
}TLoginInfo;

//解锁密码信息,系统名称
typedef struct tagLockScreenInfo
{
	bool   bOpen;
	s8  achPswd[TP_MAX_ALIAS_LEN_CNC+1];
	s8  achSysName[TP_MAX_ALIAS_LEN_CNC+1];

	tagLockScreenInfo()
	{
		bOpen = false;
		memset( &achPswd, 0, sizeof(achPswd));
		memset( &achSysName, 0, sizeof(achSysName));
	}
}TLockScreenInfo;

//会议中MainMenu条目信息
typedef struct tagConfMenuInfo
{
	s8 achName[TP_MAX_ALIAS_LEN_CNC+1];	            //名称
	int     nIndex;                 //条目索引
	s8 achItemType[TP_MAX_ALIAS_LEN_CNC+1];            //条目类型
	s8 achItemFunc[TP_MAX_ALIAS_LEN_CNC+1];            //条目单击事件
	s8 achImgFolder[TP_MAX_ALIAS_LEN_CNC+1];           //条目图片路径
	BOOL    bShow;                  //是否应该显示
	BOOL    bSetShow;               //是否设置为显示

	tagConfMenuInfo()
	{
		nIndex = 0;
		bShow = TRUE;
		bSetShow = TRUE;
		memset(&achName, 0, sizeof(achName));
		memset(&achItemType, 0, sizeof(achItemType));
		memset(&achItemFunc, 0, sizeof(achItemFunc));
		memset(&achImgFolder, 0, sizeof(achImgFolder));
	}
}TConfMenuInfo;

/*
enum Em_ImgSchm{
    emImgSchm0,
	emImgSchm1,
	emImgSchm2,
	emImgSchm3,
	emImgSchm4
};
*/

typedef struct tagDualSrcInfo
{
    vector<TVgaInfo>  vctVgaInfo;
    EmVgaType         emDefaultType;
    EmVgaType         emCurrentType;

    tagDualSrcInfo()
    {
        Clear();
    }

    void Clear()
    {
        vctVgaInfo.clear();
        emDefaultType = emVgaType001;
        emCurrentType = emVgaType001;
    }

}TDualSrcInfo;

enum EM_BrdOptType
{
	em_UnKnow_Ret,
	em_Add_Ret,
	em_Modify_Ret,
	em_Del_Ret
};

enum EM_ShortcutType
{
	emShortcutSilence = 0,	//静音
	emShortcutMute,			//哑音
	emShortcutPanCam,		//全景摄像机
	emShortcutCofPoll,		//会议轮询
	emShortcutPicSynthesis, //画面合成
	emShortcutCofDiscuss,   //会议讨论
	emShortcutDulDisplay,   //双流演示
	emShortcutVoiceAct,     //语音激励
	emShortcutPIP,			//画中画
	emShortcutTVWall		//电视墙
}; 

typedef struct tagTBrdOptRet
{
	EM_BrdOptType emBrdOptType;
	EmTpBoardRet emTpBoardRet;

	tagTBrdOptRet()
	{
		Clear();
	}

	void Clear()
	{
		emBrdOptType = em_UnKnow_Ret;
		emTpBoardRet = emTP_Board_UnKonw;
	}

}TBrdOptRet;

typedef struct tagTTvwBrdOptRet
{
	EM_BrdOptType emBrdOptType;
	EmModifyHduRet emTvwModifyHduRet;
	
	tagTTvwBrdOptRet()
	{
		Clear();
	}
	
	void Clear()
	{
		emBrdOptType = em_UnKnow_Ret;
		emTvwModifyHduRet = em_hdu_brd_no_cfg;
	}
	
}TTvwBrdOptRet;


typedef struct tagTvwStyleInfo   //存放电视墙风格当前行列及数据
{
	s32 nCol;					//总列数
	s32 nRow;					//总行数
	s32 nKey;					//当前选中位置
	TTPName tChanName;			//通道名
	THduStyleUnit tHduStyleUnit;
	
	tagTvwStyleInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		nCol = 1;
		nRow = 1;
		nKey = -1;
		tChanName.Clear();
		memset( this, 0, sizeof( tagTvwStyleInfo ) );
		tHduStyleUnit.Clear();
	}
	
	tagTvwStyleInfo& operator =(const tagTvwStyleInfo& tTvwStyleInfo)
	{
		if ( this == &tTvwStyleInfo )
		{
			return *this;
		}
		
		nCol = tTvwStyleInfo.nCol;
		nRow = tTvwStyleInfo.nRow;
		nKey = tTvwStyleInfo.nKey;
		tChanName.SetAlias( tTvwStyleInfo.tChanName.m_abyAlias );
		tHduStyleUnit = tTvwStyleInfo.tHduStyleUnit;
		
		return *this;
	}
	
}TTvwStyleInfo,*PTTvwStyleInfo;

typedef struct tagUmsToolFile   //单板升级文件结构
{
	s8 chFileName[_MAX_FNAME];
	s8 chFileFullPath[MAX_PATH];
	u64 nFileSize;
	
	tagUmsToolFile()
	{
		Clear();
	}
	
	void Clear()
	{
		memset( this, 0, sizeof( tagUmsToolFile ) );
	}
	
	tagUmsToolFile& operator =(const tagUmsToolFile& tTvwStyleInfo)
	{
		if ( this == &tTvwStyleInfo )
		{
			return *this;
		}

		strncpy( chFileName, tTvwStyleInfo.chFileName, _MAX_FNAME );
		strncpy( chFileFullPath, tTvwStyleInfo.chFileFullPath, MAX_PATH );
		nFileSize = tTvwStyleInfo.nFileSize;
		
		return *this;
	}
	
}TUmsToolFile,*PTUmsToolFile;


//会场和会议的录像信息
typedef struct tagUmcRecInfo : public TConRecState
{
	s8  m_achName[TP_MAX_NAME_LEN+1];		//会议或会场名称

	tagUmcRecInfo& operator = (const TConRecState &tConRecState)
    {
        if(this == &tConRecState)
			return *this;  
		
        TConRecState::operator = (tConRecState); 
        return *this;
	}
	
	tagUmcRecInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		memset( m_achName, 0, TP_MAX_NAME_LEN+1 );
	}
	
}TUmcRecInfo;

//会议信息(包含录像放像信息)
typedef struct tagUmcConfInfo : public TCMSConf
{
	vector<TUmcRecInfo> m_vecTRecInfo;		//会场和会议的录像信息
	TConfPlayStatus m_tConfPlayStatus;		//放像信息

	tagUmcConfInfo( TCMSConf &tCMSConf )
    {
        tagUmcConfInfo::Clear();

        TCMSConf::operator = (tCMSConf);
	}

	tagUmcConfInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		m_vecTRecInfo.clear();
		m_tConfPlayStatus.Clear();
		TCMSConf::Clear();
	}

}TUmcConfInfo;

//码流格式
typedef struct tagTTPCallSerFormat
{
	u16         m_byFrameRate; 
	EmTpVideoResolution  emRes; 
	EmTpVideoQualityLevel emTpVideoQualityLevel; //HP,BP
	public:
		tagTTPCallSerFormat()
		{ 
			Clear();
		}
		void Clear()
		{
			memset( this ,0 ,sizeof( struct  tagTTPCallSerFormat ) );
			emTpVideoQualityLevel = emTPH264HP;
		}
		
}TTPCallSerFormat;

//别名定义(包含类型)
typedef struct tagRegAlias : public TTPAlias
{
	EmTPEndpointType	m_emEndpointType;

	tagRegAlias()
	{
		Clear();
	}
	void Clear()
	{
		m_emEndpointType = emTPEndpointTypeUnknown;
	}
	
	tagTTPAlias& operator = (const TTPAlias& tAlias)
	{
		if (this == &tAlias)
		{
			return *this;
		}
		TTPAlias::operator = (tAlias); 
		return *this;
	}
}TRegAlias;

//别名定义(包含类型)
typedef struct tagAliasEx
{
	EmTPEndpointType	m_emEndpointType;
	vector<TTPAlias>    m_vecTTPAlias;
	
	tagAliasEx()
	{
		Clear();
	}
	
	void Clear()
	{
		m_emEndpointType = emTPEndpointTypeUnknown;
		m_vecTTPAlias.clear();
	}
	
	//shishi
	BOOL32 operator == (tagAliasEx& tRhs)
    {	
		BOOL32 bFind = FALSE;
		
		vector<TTPAlias>::iterator it = m_vecTTPAlias.begin();
		for ( ; it != m_vecTTPAlias.end(); it++ )
		{
			vector<TTPAlias>::iterator itRhs = tRhs.m_vecTTPAlias.begin();
			for ( ; itRhs != tRhs.m_vecTTPAlias.end(); itRhs++ )
			{
				if ( it->m_byType == itRhs->m_byType
					&& ( strcmp( it->m_abyAlias, itRhs->m_abyAlias ) == 0 ) )
				{
					bFind = TRUE;
				}
			}
		}
		
        return  bFind;
	}
	
}TAliasEx;
#endif 
