#ifndef MULTIPLEREG_COMMON
#define MULTIPLEREG_COMMON

#define MULTIPLEREGSETTINGSBASE 0x1111
#define MULTIPLEREGBASE 0xf111

//user settings

/*
 * 登录
 * {"user":"Keda_User",
    "password":"Pwd_Change"}
*/
#define MULTIPLEREGSIGN             (MULTIPLEREGSETTINGSBASE+1) 

/*设置父级ip及port，连接父级
json:{
   "ParentIP" : "127.0.0.1",
   "ParentPort" : 6668
}
assert(OSP_OK == post(MAKEIID(AID_MULTIPLEREGSERVER_APP,CInstance::DAEMON),SETPARENTIP
        ,value_json.c_str(),strlen(value_json.c_str()+1),Node));
*/
#define SETPARENTIP                 (MULTIPLEREGSETTINGSBASE+2)

/*设置一条邻居信息
json:{
   "IP" : "127.0.0.1",
   "Port" : 6668,
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
   "ParentPort" : 6668,
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


/*以上消息的返回值，均为json字符*/
#define MULTIPLEREGSIGNACK          (MULTIPLEREGSETTINGSBASE+8)
#define SETPARENTIPACK              (MULTIPLEREGSETTINGSBASE+9)
#define SETNEIGHBORINFOACK          (MULTIPLEREGSETTINGSBASE+10)
#define SETLOCALAREACODEACK         (MULTIPLEREGSETTINGSBASE+11) 
#define SETLOCALINFOACK             (MULTIPLEREGSETTINGSBASE+12)
#define DELETENEIGHBORINFOACK       (MULTIPLEREGSETTINGSBASE+13) 
#define GETLOCALINFOACK             (MULTIPLEREGSETTINGSBASE+14)


/*internal messages*/
#define ALLREG2PARENT               (MULTIPLEREGBASE+1)
#define REG2PARENT                  (MULTIPLEREGBASE+2)
#define REG2PARENTACK               (MULTIPLEREGBASE+3)
#define UNREG2PARENT                (MULTIPLEREGBASE+4)
#define UNREG2PARENTACK             (MULTIPLEREGBASE+5)
#define DISCONNECT2PARENT           (MULTIPLEREGBASE+6) 
#define REG2MULTIPLESERVER          (MULTIPLEREGBASE+7)
#define ALLREG2USER                 (MULTIPLEREGBASE+8)
#define ALLREG2USERACK              (MULTIPLEREGBASE+9)
#define REGQUERY                    (MULTIPLEREGBASE+10)
#define UNREG2MULTIPLESERVER        (MULTIPLEREGBASE+11)
#define MULTIPLEREGOBJECTINIT       (MULTIPLEREGBASE+12)
#define SETNEIGHBOR                 (MULTIPLEREGBASE+13) //osp api
#define TIMER_RECONNECT             (MULTIPLEREGBASE+14)
#define TIMER_CONFIG_WRITE          (MULTIPLEREGBASE+15) 
#define ALLREG2PARENTACK            (MULTIPLEREGBASE+16) 
#define ALLREG2TEST                 (MULTIPLEREGBASE+17) 
#define ALLREG2TESTACK              (MULTIPLEREGBASE+18) 
#define CONNECTCONTROL              (MULTIPLEREGBASE+19) 
#define CONNECTCONTROLACK           (MULTIPLEREGBASE+20) 

#endif
