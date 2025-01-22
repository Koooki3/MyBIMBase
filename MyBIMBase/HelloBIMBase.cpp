#include "pch.h"

void HelloBIMBase()
{
	AfxMessageBox(L"Hello BIMBase! This is writer kooki3.");
}
AutoDoRegisterFunctionsBegin
BIMBase::BPToolsManager::registerFun(_T("kooki3"), &HelloBIMBase);
AutoDoRegisterFunctionsEnd
