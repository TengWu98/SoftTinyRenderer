#pragma once

RENDERER_NAMESPACE_BEGIN

// 材质类型
enum class MaterialType
{
	DIFFUSE = 0,
};

class Material
{
public:
	// 构造函数
	Material(MaterialType eMaterialType = MaterialType::DIFFUSE, glm::vec3 vec3Emission = glm::vec3(0, 0, 0));

	// 析构函数
	~Material() = default;

	// 设置材质类型、获取材质类型
	void SetMaterialType(const MaterialType& eMaterialType);
	const MaterialType& GetMaterialType() const;

	// 设置自发光、获取自发光、判断是否有自发光
	void SetEmission(const glm::vec3& vec3Emission);
	const glm::vec3& GetEmission() const;
	bool HasEmission();

	// 
private:
	// 材质类型
	MaterialType m_eMaterialType;
	// 自发光
	glm::vec3 m_vec3Emission;
	// ior
	float m_fIor;
	// 
	glm::vec3 m_Vec3Kd;
	glm::vec3 m_Vec3Ks;
	// 高光衰减因子
	float m_fSpecularExponent;
};


RENDERER_NAMESPACE_END