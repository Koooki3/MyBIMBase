#include "pch.h"
#include "CubeDemo.h"

#define Property_Length "Length"
#define Property_Width "Width"
#define Property_Height "Height"

using namespace DemoObject;
using namespace p3d;

CubeDemo::CubeDemo()
{
	m_nLength = 1000;
	m_nWidth = 1000;
	m_nHeight = 1000;
}

CubeDemo::~CubeDemo()
{
}

int CubeDemo::getWidth() const {
	return m_nWidth;
}

void CubeDemo::setWidth(int nWidth) {
	m_nWidth = nWidth;
}

int CubeDemo::getLength() const {
	return m_nLength;
}

void CubeDemo::setLength(int nLength) {
	m_nLength = nLength;
}

int CubeDemo::getHeight() const {
	return m_nHeight;
}

void CubeDemo::setHeight(int nHeight) {
	m_nHeight = nHeight;
}

P3DStatus CubeDemo::_copyToData(BIMBase::Core::BPDataR instance, BIMBase::Core::BPProject& project) const
{
	if (T_Super::_copyToData(instance, project) != P3DStatus::SUCCESS) return ERROR;
	P3DStatus status;
	status = instance.setValue(Property_Length, BPValue(this->getLength()));
	if (P3DStatus::SUCCESS != status) return ERROR;
	status = instance.setValue(Property_Width, BPValue(this->getWidth()));
	if (P3DStatus::SUCCESS != status) return ERROR;
	status = instance.setValue(Property_Height, BPValue(this->getHeight()));
	if (P3DStatus::SUCCESS != status) return ERROR;
	return P3DStatus::SUCCESS;
}

P3DStatus CubeDemo::_initFromData(BIMBase::Core::BPDataCR instance)
{
	if (T_Super::_initFromData(instance) != P3DStatus::SUCCESS) return ERROR;
	BPValue value;
	P3DStatus status;
	status = instance.getValue(value, Property_Length);
	if (P3DStatus::SUCCESS != status) return ERROR;
	setLength(value.getInteger());
	status = instance.getValue(value, Property_Width);
	if (P3DStatus::SUCCESS != status) return ERROR;
	setWidth(value.getInteger());
	status = instance.getValue(value, Property_Height);
	if (P3DStatus::SUCCESS != status) return ERROR;
	setHeight(value.getInteger());
	return P3DStatus::SUCCESS;
}

BPGraphicsPtr CubeDemo::_createPhysicalGraphics(BPProjectR project, PModelIdCR modelId, bool isDynamics)
{
	BPModelPtr ptrModel = project.getModelById(modelId);
	if (ptrModel.isNull()) return nullptr;
	BPGraphicsPtr ptrGraphic = ptrModel->createPhysicalGraphics();
	if (ptrGraphic.isNull()) return nullptr;

	int nWidth = getWidth();
	int nLength = getLength();
	int nHeight = getHeight();

	//绘制底部外轮廓
	pvector<GePoint3d> pts;
	pts.push_back(GePoint3d::create(0, -nWidth / 2, 0));
	pts.push_back(GePoint3d::create(nLength, -nWidth / 2, 0));
	pts.push_back(GePoint3d::create(nLength, nWidth / 2, 0));
	pts.push_back(GePoint3d::create(0, nWidth / 2, 0));
	pts.push_back(GePoint3d::create(0, -nWidth / 2, 0));
	GeCurveArrayPtr ptrOutlines = GeCurveArray::createLinestringArray(pts, GeCurveArray::BOUNDARY_TYPE_Outer);

	//向z方向拉伸
	GeVec3d vec = GeVec3d::create(0, 0, nHeight);
	GeExtrusionInfo extrData(ptrOutlines, vec, true);
	IGeSolidBasePtr ptrExtrusion = IGeSolidBase::createGeExtrusion(extrData);
	ptrGraphic->addGeSolidBase(*ptrExtrusion);
	return ptrGraphic;
}

//void CubeDemoFun()
//{
//	BPProjectP pProject = BPApplication::getInstance().getProjectManager()->getMainProject();
//	if (pProject == nullptr) return;
//	BPModelBaseP pModel = pProject->getActiveModel();
//	if (pProject == nullptr) return;
//	PModelId modelId = pModel->getModelId();
//	DemoObject::CubeDemo pcube;
//	pcube.setLength(1000);
//	pcube.setWidth(1000);
//	pcube.setHeight(1000);
//	pcube.addToProject(*pProject, modelId);
//	BPViewportP pViewPort = BPViewManager::getInstance().getActivedViewport();
//	if (NULL == pViewPort) return;
//	if (pViewPort) pViewPort->updateView();
//}
//
//AutoDoRegisterFunctionsBegin
//BPToolsManager::registerFun(_T("CubeDemo"), &CubeDemoFun);
//AutoDoRegisterFunctionsEnd