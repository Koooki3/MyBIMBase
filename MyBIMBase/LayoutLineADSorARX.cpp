#include "pch.h"
#include "ToolLayoutLine.h"
//
//void AdsLineDemo()
//{
//	BPProjectP pProject = BPApplication::getInstance().getProjectManager()->getMainProject();
//	if (pProject == nullptr)
//		return;
//	BPModelBaseP pModel = pProject->getActiveModel();
//	if (pModel == nullptr)
//		return;
//	BPGraphicsPtr ptrGraphic = pModel->creatPhysicalGraphics();
//	if (ptrGraphic.isNull())
//		return;
//
//	double pFirst[3], pSecond[3];
//	getPoint(nullptr, "Select first point", pFirst);
//	getPoint(nullptr, "Select second point", pSecond);
//
//	GePoint3d ptFirst = GePoint3d::create(pFirst[0], pFirst[1], pFirst[2]);
//	GePoint3d ptSecond = GePoint3d::create(pSecond[0], pSecond[1], pSecond[2]);
//	ptrGraphic->addGeCurve(*IGeCurveBase::createSegment(GeSegment3d::create(ptFirst, ptSecond)));
//	ptrGraphic->save();
//}
//AutoDoRegisterFunctionsBegin
//BPToolsManager::registerFun(_T("AdsLineDemo"), &AdsLineDemo);
//AutoDoRegisterFunctionsEnd
