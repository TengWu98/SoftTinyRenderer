#pragma once
#include "Triangle/Triangle.h"
#include "Material/Material.h"

RENDERER_NAMESPACE_BEGIN

// 网格类
class Model
{
public:
	// 构造函数
	Model(const std::string& filePath);

	// 析构函数
	~Model() {};

	// 顶点数目
	inline int GetVertNum() { return m_iVertNum; };
	// 面片数目
	inline int GetFaceNum() { return m_iFaceNum; };
private:
	int m_iVertNum; // 模型顶点数
	int m_iFaceNum; // 模型面片数

	// 模型的所有三角形
	std::vector<Triangle> m_vecTriangleList;

	// 模型的材质
	Material* m_cMaterial;
};

RENDERER_NAMESPACE_END