#pragma once

RENDERER_NAMESPACE_BEGIN

class Triangle
{
public:
	// 构造函数
	Triangle();
	// 析构函数
	~Triangle() {};

	void SetVertex(const std::array<glm::vec4, 3>& vec4Vertex);
	const std::array<glm::vec4, 3>& GetVertex() const;

	void SetNormal(const std::array<glm::vec3, 3>& vec3Normal);
	const std::array<glm::vec3, 3>& GetNormal() const;

	void SetTexCoords(const std::array<glm::vec2, 3>& vec2TexCoords);
	const std::array<glm::vec2, 3>& GetTexCoords() const;

	void SetColor(const std::array<glm::vec3, 3>& vec3Color);
	const std::array<glm::vec3, 3>& GetColor() const;
private:
	// 顶点
	std::array<glm::vec4, 3> m_vec4Vertex;
	// 法线
	std::array<glm::vec3, 3> m_vec3Normal;
	// uv坐标
	std::array<glm::vec2, 3> m_vec2TexCoords;
	// 颜色值
	std::array<glm::vec3, 3> m_vec3Color;
};

RENDERER_NAMESPACE_END