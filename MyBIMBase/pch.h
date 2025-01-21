// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"

#include <vector>
#include <map>
#include <algorithm>
//平台相关
#include "BPExportMacros.h"
#include "PKPMExportMacros.h"
#include "P3DDC/P3DDCAPI.h"
#include "P3DGeomBase/P3DGeomBasePublicAPI.h"
#include "P3DGeomObject/P3DGeomObjectPublicAPI.h"
#include "JsonCpp/JsonCppAPI.h"
#include "BPBase/BPBaseAPI.h"
#include "BPData/BPDataAPI.h"
#include "BPDataCore/BPDataCoreDef.h"
#include "BPDataCore/BPDataCoreAPI.h"
#include "BPDataCore/BPPlacement.h"
#include "BPDataCore/BPDomainDataInitManager.h"
#include "BPDisplay/BPDisplayAPI.h"


#endif //PCH_H
