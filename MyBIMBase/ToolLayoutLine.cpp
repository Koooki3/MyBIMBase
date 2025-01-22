#include "pch.h"
#include "ToolLayoutLine.h"

ToolLayoutLine::ToolLayoutLine()
{
	m_nStep = 0;
}

ToolLayoutLine::~ToolLayoutLine()
{

}

void ToolLayoutLine::_onPostInstall()
{
	T_Super::_onPostInstall();
	BPSnap::getInstance().enableLocate(false);
	BPSnap::getInstance().enableSnap(true);
}

void ToolLayoutLine::_onRestartTool()
{
	ToolLayoutLine* newTool = new ToolLayoutLine();
	newTool->installTool();
}

bool ToolLayoutLine::_onDataButton(BPBaseButtonEventCP ev)
{
	BPViewportP pViewport = ev->getViewport();
	if (NULL == pViewport)
		return false;
	BPModelP pModel = pViewport->getTargetModel();
	if (pModel == nullptr)
		return false;
	GePoint3d ptE = *ev->getPoint();
	if (m_nStep == 0)
	{
		m_ptC = *ev->getPoint();
		m_nStep = 1;
	}
	else if (m_nStep == 1)
	{
		if (m_ptrGraphic.isNull())
			return false;
		m_ptrGraphic->save();
		m_nStep = 0;
	}
	return true;
}

bool ToolLayoutLine::_onResetButton(BPBaseButtonEventCP)
{
	_exitTool();
	return true;
}

void ToolLayoutLine::_onDynamicFrame(BPBaseButtonEventCP ev)
{
	if (NULL == ev)
		return;
	if (m_nStep == 0)
		return;
	BPViewportP pViewport = ev->getViewport();
	if (NULL == pViewport)
		return;
	BPModelP pModel = pViewport->getTargetModel();
	if (pModel == nullptr)
		return;
	IGeCurveBasePtr Line = IGeCurveBase::createSegment(GeSegment3d::create(m_ptC, *ev->getPoint()));
	m_ptrGraphic = pModel->createPhysicalGraphics();
	m_ptrGraphic->addGeCurve(*Line.get());
	m_ptrGraphic->finish();

	BPRedrawEntitys redrawElems;
	redrawElems.setDrawMode(BPDrawMode::enTempDraw);
	redrawElems.setDrawPurpose(BPDrawPurpose::enDynamics);
	redrawElems.setDynamicsViews(pViewport);
	redrawElems.doRedraw(m_ptrGraphic->getEntityR());
}

bool ToolLayoutLine::_onModelMotion(BPBaseButtonEventCP ev)
{
	if (!getDynamicsStarted())
		_beginDynamics();
	return true;
}
//对工具进行注册
BPTool* CreateLineTool()
{
	ToolLayoutLine* tool = new ToolLayoutLine();
	return tool;
}
AutoDoRegisterFunctionsBegin
BPToolsManager::registerTool("layoutLineDemo", &CreateLineTool);
AutoDoRegisterFunctionsEnd
