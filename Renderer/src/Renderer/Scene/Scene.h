#pragma once
#include "Model/Model.h"
#include "Light/Light.h"
#include "Renderer/Core/Camera/Camera.h"

RENDERER_NAMESPACE_BEGIN

class Scene
{
public:
	// ���캯��
	Scene();
	// ��������
	~Scene();
	// ��������
	Scene(const Scene&);

	// �򳡾�������µ�ģ��
	void AddModel(Model* model);
	// �򳡾�������µĹ�Դ
	void AddLight(Light* light);

	// ��ȡ���������е�ģ��
	const std::vector<Model *> GetModels() const;
	// ��ȡ���������еĵƹ�
	const std::vector<Light *> GetLights() const;
	// ��ȡ�������
	const unsigned int GetWidth() const;
	// ��ȡ�����߶�
	const unsigned int GetHeight() const;
	// ��ȡ��������ɫ
	const glm::vec3 GetBackgroundColor() const;
private:
	// �����е�����ģ��
	std::vector<Model *> m_vecModels;

	// ���������еĵƹ�
	std::vector<Light *> m_vecLights;

	// �����Ŀ��
	unsigned int m_uiWidth;
	// �����ĸ߶�
	unsigned int m_uiHeight;

	// �����ı���ɫ
	glm::vec3 m_vec3BackgroundColor;
};

RENDERER_NAMESPACE_END