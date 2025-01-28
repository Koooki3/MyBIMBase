#include "pch.h"
#include "ToolCubeMoveDemo.h"
#include "CubeDemo.h"
using namespace std;
ToolCubeMoveDemo::ToolCubeMoveDemo()
{
}
ToolCubeMoveDemo::~ToolCubeMoveDemo()
{
}
void ToolCubeMoveDemo::Dynamic(vector<BPEntityPtr> const& refps, GeTransformCR transform, BPRedrawEntitys& redrawElems) 
{
}
void ToolCubeMoveDemo::Move(vector<BPEntityPtr> const& refps, GeTransformCR transform)
{
	for (BPEntityPtr refp : refps)
	{
		if (refp.isNull()) continue;
		BPDataPtr ptrData = BPDataUtil::getDataOnEntity(*refp);
		if (!ptrData.isValid()) continue;

		//DemoObject::CubeDemo pbCube;
		//pbCube.initFromData(*ptrData);

		//选中的目标乘以移动的转换矩阵，移动到新的位置
		//pbCube.onTransform(transform);

		//新位置替换原位置
		//pbCube.replaceInProject(*refp->getBPProject());
	}
}
void ToolCubeMoveDemo::ElementsSelected(vector<BPEntityPtr> & refps)
{
}

//注册移动
class CubeMoveDemoFactory : public IToolInterfaceFactory
{
public:
	virtual IToolInterface* CreateInterface() override
	{
		ToolCubeMoveDemo* p = new ToolCubeMoveDemo();
		p->AddRef();
		return p;
	}
};
static CubeMoveDemoFactory s_CubeMoveDemoFactory;

AutoDoRegisterFunctionsBegin
PBBimToolsInterfaceManager::RegisterFactory("CubeDemo", IToolNameMove, &s_CubeMoveDemoFactory);
AutoDoRegisterFunctionsEnd