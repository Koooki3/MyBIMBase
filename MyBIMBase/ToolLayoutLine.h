#pragma once
#include "pch.h"

class ToolLayoutLineDemo : public BPPrimitiveTool
{
	DefineSuper(BPPrimitiveTool)
public:
	ToolLayoutLineDemo();
	~ToolLayoutLineDemo();
protected:
	virtual p3d::Utf8CP _getToolName() const { return "layoutLineDemo"; }
	virtual void _onPostInstall() override;
	virtual void _onRestartTool() override;
	virtual bool _onDataButton(BPBaseButtonEventCP) override;
	virtual bool _onResetButton(BPBaseButtonEventCP) override;
	virtual void _onDynamicFrame(BPBaseButtonEventCP) override;
	virtual bool _onModelMotion(BPBaseButtonEventCP ev) override;
private:
	int m_nStep;
	GePoint3d m_ptC;
	BPGraphicsPtr m_ptrGraphic;
};