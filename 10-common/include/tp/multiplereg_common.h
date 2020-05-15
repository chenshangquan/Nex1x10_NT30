#ifndef MULTIPLEREG_COMMON
#define MULTIPLEREG_COMMON

#define MULTIPLEREGSETTINGSBASE     10000//UE信令
#define MULTIPLEREGBASEINNER        20000//内部信令
#define MULTIPLEREGBASECASCADE      30000//级联信令

///////////////////////////////////////////////////////////////
//Begin for siptool->AID_MULTIPLEREGSERVER_APP
//user settings
/*
 * 登录
 * {"user":"Keda_User",
    "password":"Pwd_Change"
	"ClientIP":"127.0.0.1"}
*/
#define MULTIPLEREGSIGN             (MULTIPLEREGSETTINGSBASE+1) 

/*设置父级ip及port，连接父级
json:{
   "ParentIP" : "127.0.0.1",
   "ParentPort" : 6060
}
assert(OSP_OK == post(MAKEIID(AID_MULTIPLEREGSERVER_APP,CInstance::DAEMON),SETPARENTIP
        ,value_json.c_str(),strlen(value_json.c_str()+1),Node));
*/
#define SETPARENTIP                 (MULTIPLEREGSETTINGSBASE+2)

/*设置一条邻居信息
json:{
   "IP" : "127.0.0.1",
   "Port" : 6060,
   "areacode" : "022"
}
*/
#define SETNEIGHBORINFO             (MULTIPLEREGSETTINGSBASE+3) //json

/*设置本地区号
json:{
   "LocalAreaCode" : "021"
}*/
#define SETLOCALAREACODE            (MULTIPLEREGSETTINGSBASE+4) 

/*设置本地信息
json:{
   "ParentIP" : "127.0.0.1",
   "ParentPort" : 6060,
   "LocalAreaCode" : "021"
}*/
#define SETLOCALINFO                (MULTIPLEREGSETTINGSBASE+5) 

/*删除一条邻居信息
json{
   "areacode" : "022"
}*/
#define DELETENEIGHBORINFO          (MULTIPLEREGSETTINGSBASE+6) 

/*获取本地信息，包含邻居,父级和本地区号,json格式*/
#define GETLOCALINFO                (MULTIPLEREGSETTINGSBASE+7)

//End for siptool->AID_MULTIPLEREGSERVER_APP
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Begin for AID_MULTIPLEREGSERVER_APP->siptool
/*上述set消息的回复，消息体均为json字符*/
#define MULTIPLEREGSIGNACK          (MULTIPLEREGSETTINGSBASE+100)
#define SETPARENTIPACK              (MULTIPLEREGSETTINGSBASE+101)
#define SETNEIGHBORINFOACK          (MULTIPLEREGSETTINGSBASE+102)
#define SETLOCALAREACODEACK         (MULTIPLEREGSETTINGSBASE+103) 
#define SETLOCALINFOACK             (MULTIPLEREGSETTINGSBASE+104)
#define DELETENEIGHBORINFOACK       (MULTIPLEREGSETTINGSBASE+105) 
#define GETLOCALINFOACK             (MULTIPLEREGSETTINGSBASE+106)
//消息体：
/*
{"ClientIP":"127.0.0.1"}
*/
//作用：  通知siptool被抢登下线
#define FORCELOGOUT                 (MULTIPLEREGSETTINGSBASE+107)
//End for AID_MULTIPLEREGSERVER_APP->siptool
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
/*internal messages*/
///////////////////////////////////////////////////////////////////////
//AID_MULTIPLEREGSERVER_APP初始化消息
#define MULTIPLEREGOBJECTINIT       (MULTIPLEREGBASEINNER+1)

//消息体：TCnsRegInfo
//方向：  AID_UMSDB_APP->AID_MULTIPLEREGSERVER_APP
//作用：  添加注册
#define REG2MULTIPLESERVER          (MULTIPLEREGBASEINNER+2)

//消息体：TCnsRegInfo(只用到callid)
//方向：  AID_UMSDB_APP->AID_MULTIPLEREGSERVER_APP
//作用：  删除注册
#define UNREG2MULTIPLESERVER        (MULTIPLEREGBASEINNER+3)

//消息体：CTpMsg（TUmsHandle+s32+EmGetRegInfoType）
//方向：  AID_UMSDB_APP->AID_MULTIPLEREGSERVER_APP
//作用：  获取在线地址簿
#define ALLREG2USER                 (MULTIPLEREGBASEINNER+4)

//消息体：CTpMsg（TUmsHandle+TTPAlias）
//方向：  AID_UMSDB_APP->AID_MULTIPLEREGSERVER_APP
//作用：  查询地址簿
#define REGQUERY                    (MULTIPLEREGBASEINNER+5)

//向上级级联定时重连消息
#define TIMER_RECONNECT             (MULTIPLEREGBASEINNER+100)

//延时写配置文件消息
#define TIMER_CONFIG_WRITE          (MULTIPLEREGBASEINNER+101)

//用于测试
#define DISCONNECT2PARENT           (MULTIPLEREGBASEINNER+200) 
#define ALLREG2TEST                 (MULTIPLEREGBASEINNER+201)
#define ALLREG2TESTACK              (MULTIPLEREGBASEINNER+202)
#define SETSERVERUNIQUE             (MULTIPLEREGBASEINNER+203)
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
/*cascade messages*/
///////////////////////////////////////////////////////////////////////
//级联消息：下级向上级连接成功后，下级向上级发送的第一条消息及回复
#define CONNECTCONTROL              (MULTIPLEREGBASECASCADE+1)
#define CONNECTCONTROLACK           (MULTIPLEREGBASECASCADE+2)

//级联消息：下级向上级成功级联后，发送所有注册信息到上级
#define ALLREG2PARENT               (MULTIPLEREGBASECASCADE+3)
#define ALLREG2PARENTACK            (MULTIPLEREGBASECASCADE+4)

//级联消息：下级向上级增加一条注册
#define REG2PARENT                  (MULTIPLEREGBASECASCADE+5)
#define REG2PARENTACK               (MULTIPLEREGBASECASCADE+6)

//级联消息：下级向上级删除一条注册
#define UNREG2PARENT                (MULTIPLEREGBASECASCADE+7)
#define UNREG2PARENTACK             (MULTIPLEREGBASECASCADE+8)
//////////////////////////////////////////////////////////////


#endif//MULTIPLEREG_COMMON
