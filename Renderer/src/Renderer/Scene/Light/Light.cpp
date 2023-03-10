#include "pch.h"
#include "Light.h"

RENDERER_NAMESPACE_BEGIN

Light::Light(glm::vec3 vec3Position, glm::vec3 vec3Intensity) :
	m_vec3Position(vec3Position), m_vec3Intensity(vec3Intensity)
{
}


Light::Light(const Light& light) :
	m_vec3Position(light.GetPosition()),
	m_vec3Intensity(light.GetIntensity())
{
}

void Light::SetPosition(const glm::vec3& vec3Position)
{
	m_vec3Position = vec3Position;
}

const glm::vec3& Light::GetPosition() const
{
	return m_vec3Position;
}

void Light::SetIntensity(const glm::vec3& vec3Intensity)
{
	m_vec3Intensity = vec3Intensity;
}

const glm::vec3& Light::GetIntensity() const
{
	return m_vec3Intensity;
}

RENDERER_NAMESPACE_END


