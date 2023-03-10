#include "pch.h"
#include "Scene.h"

RENDERER_NAMESPACE_BEGIN

Scene::Scene():
	m_uiWidth(0),
	m_uiHeight(0),
	m_vec3BackgroundColor(glm::vec3(0.235294, 0.67451, 0.843137))
{
	LOG_DEV_INFO("场景创建成功！");
}

Scene::~Scene()
{
	LOG_DEV_INFO("场景销毁成功！");
}

Scene::Scene(const Scene& spScene) :
	m_uiHeight(spScene.GetHeight()),
	m_uiWidth(spScene.GetWidth()),
	m_vec3BackgroundColor(spScene.GetBackgroundColor()),
	m_vecModels(spScene.GetModels()),
	m_vecLights(spScene.GetLights())
{
}

void Scene::AddModel(Model* model)
{
	m_vecModels.push_back(std::move(model));
}

void Scene::AddLight(Light* light)
{
	m_vecLights.push_back(std::move(light));
}

const std::vector<Model*> Scene::GetModels() const
{
	return m_vecModels;
}

const std::vector<Light*> Scene::GetLights() const
{
	return m_vecLights;
}

const unsigned int Scene::GetWidth() const
{
	return m_uiWidth;
}

const unsigned int Scene::GetHeight() const
{
	return m_uiHeight;
}

const glm::vec3 Scene::GetBackgroundColor() const
{
	return m_vec3BackgroundColor;
}

RENDERER_NAMESPACE_END


