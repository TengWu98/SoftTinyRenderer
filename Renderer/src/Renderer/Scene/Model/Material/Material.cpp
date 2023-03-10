#include "pch.h"
#include "Material.h"

RENDERER_NAMESPACE_BEGIN

Material::Material(MaterialType eMaterialType, glm::vec3 vec3Emission) :
	m_eMaterialType(eMaterialType), m_vec3Emission(vec3Emission)
{
}

void Material::SetMaterialType(const MaterialType& eMaterialType)
{
	m_eMaterialType = eMaterialType;
}

const MaterialType& Material::GetMaterialType() const
{
	return m_eMaterialType;
}

void Material::SetEmission(const glm::vec3& vec3Emission)
{
	m_vec3Emission = vec3Emission;
}

const glm::vec3& Material::GetEmission() const
{
	return m_vec3Emission;
}

bool Material::HasEmission()
{
	if (m_vec3Emission.length() <= EPSILON)
		return false;
	return true;
}

RENDERER_NAMESPACE_END


