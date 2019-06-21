/** @defgroup 常量定义 
 *  @version V1.0.0
 *  @author  陈上全
 *  @date    2019.5.20
 */
#pragma once

#if !defined(_CONSTDEF_H_)
#define _CONSTDEF_H_


#ifndef String 
typedef tstring String;	                            // String
#endif
#ifndef MbString                                    // MultiByteString 
typedef std::string MbString;
#endif

#define DEFAULT_TITLE_HEIGHT   79

#define WINDOW_MGR_PTR  IWindowManager::GetSingletonPtr()

#endif

#if !define(_SIPTOOL_CONSTDEF_H_)
#define _SIPTOOL_CONSTDEF_H_

#define NOTIFY_MSG	ISipToolCommonOp::NotifyMsg

#define REG_RCKTOOL_MSG_OB(ob) ISipToolMsgManager::GetSingletonPtr()->AddObserver(ob);
#define UNREG_RCKTOOL_MSG_OB(ob) ISipToolMsgManager::GetSingletonPtr()->RemoveObserver(ob);
#define REG_RCKTOOL_MSG_WND_OB(hwnd) ISipToolMsgManager::GetSingletonPtr()->AddWindowObserver(hwnd);
#define UNREG_RCKTOOL_MSG_WND_OB(hwnd) ISipToolMsgManager::GetSingletonPtr()->RemoveWindowObserver(hwnd);




#define CFG_FILE    _T("configure.ini")							//配置文件

#define  MAX_DEVICEVER_LEN   38                                 //版本号最大长度
#define  MAX_NAME_LEN        32                                 // 最大名字长

#define SIPTOOL_VERSION_ID	   "V1.0.0.0"

#endif
