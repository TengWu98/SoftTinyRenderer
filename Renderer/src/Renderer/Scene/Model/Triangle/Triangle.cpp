#include "pch.h"
#include "Triangle.h"

RENDERER_NAMESPACE_BEGIN

Triangle::Triangle()
{
	for (int i = 0; i < 3; i++)
	{
		m_vec4Vertex[i] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
		m_vec3Normal[i] = glm::vec3(0.0f, 0.0f, 0.0f);
		m_vec2TexCoords[i] = glm::vec2(0.0f, 0.0f);
		m_vec3Color[i] = glm::vec3(0.0f, 0.0f, 0.0f);
	}
}

void Triangle::SetVertex(const std::array<glm::vec4, 3>& vec4Vertex)
{
	for (int i = 0; i < 3; i++)
	{
		m_vec4Vertex[i] = vec4Vertex[i];
	}
}

const std::array<glm::vec4, 3>& Triangle::GetVertex() const
{
	return m_vec4Vertex;
}

void Triangle::SetNormal(const std::array<glm::vec3, 3>& vec3Normal)
{
	for (int i = 0; i < 3; i++)
	{
		m_vec3Normal[i] = vec3Normal[i];
	}
}

const std::array<glm::vec3, 3>& Triangle::GetNormal() const
{
	return m_vec3Normal;
}

void Triangle::SetTexCoords(const std::array<glm::vec2, 3>& vec2TexCoords)
{
	for (int i = 0; i < 3; i++)
	{
		m_vec2TexCoords[i] = vec2TexCoords[i];
	}
}

const std::array<glm::vec2, 3>& Triangle::GetTexCoords() const
{
	return m_vec2TexCoords;
}

void Triangle::SetColor(const std::array<glm::vec3, 3>& vec3Color)
{
	for (int i = 0; i < 3; i++)
	{
		m_vec3Color[i] = vec3Color[i];
	}
}

const std::array<glm::vec3, 3>& Triangle::GetColor() const
{
	return m_vec3Color;
}

RENDERER_NAMESPACE_END


