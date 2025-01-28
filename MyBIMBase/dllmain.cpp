// dllmain.cpp : 定义 DLL 的初始化例程。
//

#include "pch.h"
#include "framework.h"
#include <afxwin.h>
#include <afxdllx.h>
//平台库
#include <BPPluginManager/BPPluginManagerApi.h>
#include <PBBimCore/PBBimExtensionModule.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE MyBIMBaseDLL = { false, nullptr };

//入口插件注册
class ExamplesPluginEntry :public BIMBase::Plugin::BPPluginFactory
{
public:
	ExamplesPluginEntry() {};
	virtual ~ExamplesPluginEntry() {};
protected:
	//提供加载响应时机，重载但不⽤实现
	virtual void _onLoadPlugin(CWnd* curMainFrame) override
	{
		std::vector<std::wstring> vecAssembly = BIMBase::Plugin::BPPluginManager::getInstance().getCurPluginAssmebly();
		for (auto it : vecAssembly)
		{//模块加载
			loadPluginAssembly(it);
		}
	}
	//提供卸载响应时机，重载但不⽤实现
	virtual void _onUnLoadPlugin(::BIMBase::Core::BPProjectR curProject) override
	{

	}
	//返回插件的信息，重载但不⽤实现
	virtual void _initPluginInformation(::BIMBase::Plugin::PluginInformation& pluginInformation) override
	{
		pluginInformation.m_wsPluginDescribe = L"⼆次开发";
	}
};

static ExamplesPluginEntry _pluginEntry;
PBBIM_IMPLEMENT_EXTENSION_MODULE(entryDll);

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// 如果使⽤ lpReserved，请将此移除
	UNREFERENCED_PARAMETER(lpReserved);
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if (!entryDll.AttachInstance(hInstance))
			return 0;
		//插件注册
		BIMBase::Plugin::BPPluginManager::getInstance().registerPlugin(&_pluginEntry);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		//插件反注册
		BIMBase::Plugin::BPPluginManager::getInstance().unRegisterPlugin();
		entryDll.DetachInstance();
	}
	//注册运行时类型判断
	//BPObjectExtensionManager::getInstance().registerBPObjectExtension(PBM_SCHEMA_DEMO,PBM_CLASS_CUBE_DEMO, new CubeDemoExtension());
	return 1; // 确定
}
