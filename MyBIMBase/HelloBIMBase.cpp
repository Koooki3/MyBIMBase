#include "pch.h"

void HelloBIMBase()
{
	AfxMessageBox(L"Hello BIMBase!");
}
AutoDoRegisterFunctionsBegin
BIMBase::BPToolsManager::registerFun(_T("HelloBIMBase"), &HelloBIMBase);
AutoDoRegisterFunctionsEnd

