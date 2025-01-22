#include "pch.h"

void HelloBIMBase()
{
	AfxMessageBox(L"Hello BIMBase! This is writer kooki3.");
}
AutoDoRegisterFunctionsBegin
BIMBase::BPToolsManager::registerFun(_T("KOOKI3"), &HelloBIMBase);
AutoDoRegisterFunctionsEnd

