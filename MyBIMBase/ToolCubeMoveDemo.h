#pragma once
#include "pch.h"
using namespace std;
class ToolCubeMoveDemo : public IToolMove
{
public:
	ToolCubeMoveDemo();
	~ToolCubeMoveDemo();

	//ѡ����Ҫ�ƶ��Ĺ�������Ӧ
	virtual void ElementsSelected(vector<BPEntityPtr>& refps) override;
	//�������false�������Զ����Dynamic�����������Զ��庯��ʱ��ò�Ҫ�Ǽ����ܼ��Ͳ���
	virtual bool CacheDynamic() override { return true; };
	//��̬�ƶ�����ʱ��Ӧ��������ҪCacheDynamic����falseʱ�Ż����
	virtual void Dynamic(vector<BPEntityPtr> const & refps, GeTransformCR transform, BPRedrawEntitys& redrawElems) override;
	//�ƶ��깹����������ʱ��Ӧ����
	virtual void Move(vector<BPEntityPtr> const& refps, GeTransformCR transform) override;
};
