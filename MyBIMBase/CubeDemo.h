#pragma once
#include "pch.h"

namespace DemoObject
{
	class CubeDemo;
	typedef CubeDemo const&          CubeDemoCR;
	typedef CubeDemo&                CubeDemoR;
	typedef CubeDemo*                CubeDemoP;
	typedef RefCountedPtr<CubeDemo>  CubeDemoPtr;

	class CubeDemo : public BIMBase::Data::BPGraphicElement
	{
		DefineSuper(BIMBase::Data::BPGraphicElement)
	public:
		CubeDemo();
		~CubeDemo();
		int getWidth() const;
		void setWidth(int nWidth);
		int getLength() const;
		void setLength(int nLength);
		int getHeight() const;
		void setHeight(int nHeight);
	protected:
		//未注册Schema
		//virtual Utf8String _getSchemaName() const override { return PBM_SCHEMA_Demo; };
		//virtual Utf8String _getClassName() const override { return PBM_CLASS_CUBE_Demo; };
		//往数据库中写入数据
		virtual P3DStatus _copyToData(BPDataR instance, BPProject& project) const override;
		//从数据库中读取数据
		virtual P3DStatus _initFromData(BPDataCR instance) override;
		//创建几何造型
		virtual BPGraphicsPtr _createPhysicalGraphics(BPProjectR project, PModelIdCR modelId, bool isDynamics) override;
	private:
		int m_nWidth;
		int m_nLength;
		int m_nHeight;
		//Demo_CREATE(CubeDemo);
	};
	//Demo_EXTENSION(CubeDemo);
}