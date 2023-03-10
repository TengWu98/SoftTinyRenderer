#pragma once
#include "Model/Model.h"
#include "Light/Light.h"
#include "Renderer/Core/Camera/Camera.h"

RENDERER_NAMESPACE_BEGIN

class Scene
{
public:
	// 构造函数
	Scene();
	// 析构函数
	~Scene();
	// 拷贝构造
	Scene(const Scene&);

	// 向场景中添加新的模型
	void AddModel(Model* model);
	// 向场景中添加新的光源
	void AddLight(Light* light);

	// 获取场景中所有的模型
	const std::vector<Model *> GetModels() const;
	// 获取场景中所有的灯光
	const std::vector<Light *> GetLights() const;
	// 获取场景宽度
	const unsigned int GetWidth() const;
	// 获取场景高度
	const unsigned int GetHeight() const;
	// 获取场景背景色
	const glm::vec3 GetBackgroundColor() const;
private:
	// 场景中的所有模型
	std::vector<Model *> m_vecModels;

	// 场景中所有的灯光
	std::vector<Light *> m_vecLights;

	// 场景的宽度
	unsigned int m_uiWidth;
	// 场景的高度
	unsigned int m_uiHeight;

	// 场景的背景色
	glm::vec3 m_vec3BackgroundColor;
};

RENDERER_NAMESPACE_END