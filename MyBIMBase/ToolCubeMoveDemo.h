#pragma once
#include "pch.h"
using namespace std;
class ToolCubeMoveDemo : public IToolMove
{
public:
	ToolCubeMoveDemo();
	~ToolCubeMoveDemo();

	//选中需要移动的构件后响应
	virtual void ElementsSelected(vector<BPEntityPtr>& refps) override;
	//如果返回false则会调用自定义的Dynamic函数，调用自定义函数时最好不要是计算密集型操作
	virtual bool CacheDynamic() override { return true; };
	//动态移动物体时响应函数，需要CacheDynamic返回false时才会调用
	virtual void Dynamic(vector<BPEntityPtr> const & refps, GeTransformCR transform, BPRedrawEntitys& redrawElems) override;
	//移动完构件后点击布置时响应函数
	virtual void Move(vector<BPEntityPtr> const& refps, GeTransformCR transform) override;
};
