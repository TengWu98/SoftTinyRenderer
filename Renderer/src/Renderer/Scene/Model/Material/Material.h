#pragma once

RENDERER_NAMESPACE_BEGIN

// ��������
enum class MaterialType
{
	DIFFUSE = 0,
};

class Material
{
public:
	// ���캯��
	Material(MaterialType eMaterialType = MaterialType::DIFFUSE, glm::vec3 vec3Emission = glm::vec3(0, 0, 0));

	// ��������
	~Material() = default;

	// ���ò������͡���ȡ��������
	void SetMaterialType(const MaterialType& eMaterialType);
	const MaterialType& GetMaterialType() const;

	// �����Է��⡢��ȡ�Է��⡢�ж��Ƿ����Է���
	void SetEmission(const glm::vec3& vec3Emission);
	const glm::vec3& GetEmission() const;
	bool HasEmission();

	// 
private:
	// ��������
	MaterialType m_eMaterialType;
	// �Է���
	glm::vec3 m_vec3Emission;
	// ior
	float m_fIor;
	// 
	glm::vec3 m_Vec3Kd;
	glm::vec3 m_Vec3Ks;
	// �߹�˥������
	float m_fSpecularExponent;
};


RENDERER_NAMESPACE_END