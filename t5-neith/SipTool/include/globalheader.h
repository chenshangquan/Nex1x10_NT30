#if !defined(GLOBALHEADER_H)
#define GLOBALHEADER_H

#pragma once

#pragma warning(disable : 4786)
#pragma warning(disable : 4503)
#pragma warning(disable : 4800)
#pragma warning(disable : 4996)

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>

#include "AppFrameHeader.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

#include "templateClass.h"
using namespace AutoUIFactory;

#include "unicode.h"

#include "constdef.h"

#include "system.h"
#include "siptoolevent.h"
#include "siptoolcommonop.h"
#include "siptoolmsgmanager.h"
#include "siptoolinterface.h"
//#include "UIDataMgr.h"

#pragma comment(lib, "osplib.lib")
#pragma comment(lib, "siptoollib.lib")

//wifi
//#include "wlandllcommon.h"
//#pragma comment(lib, "wlanapidll.lib")

//��������
//#pragma comment(lib, "iphlpapi.lib" )
//#pragma comment(lib, "SensAPI.Lib" )

#endif
