#pragma once
// ����
#include "Renderer/Scene/Scene.h"

#include "Renderer/Core/Window/Window.h"
#include "Renderer/Core/Camera/Camera.h"
#include "Renderer/Core/Input/Input.h"

RENDERER_NAMESPACE_BEGIN
// ����
enum class Buffers
{
	Color = 1,
	Depth = 2
};

// ͼԪ
enum class Primitive
{
	Line,
	Triangle
};


// ��Ⱦ���ࣨ����ģʽ��
class Render
{
public:
	static Ref<Render> GetRender();

	// ���캯��
	Render();
	// ��������
	~Render() {};

	// �������
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	const Ref<Window>& GetWindow()const;

	// �¼����
	void OnEvent(Event& event);

	// �ر���Ⱦ��
	void Close();

	//// ���ColorBuffer
	//void SetClearColor(const glm::vec4& vec4Color);

	//// �����ӿڴ�С
	//void SetViewPort(unsigned int uiWidth, unsigned int uiHeight);

	//// ���
	//void Clear();

	//// ����������
	//void DrawTriangles(unsigned int uiIndexCount);

	//// ����ֱ��
	//void DrawLines(unsigned int uiIndexCount);

	//// �����߿�
	//void SetLineWidth(float fWidth);

	/********************************** ��Ⱦ���� **********************************/
	// ǰ����Ⱦ
	void ForwordRender(const Ref<Scene>& scene);

	// �ӳ���Ⱦ
	void DeferredRender(const Ref<Scene>& scene);
private:
	// �¼�
	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
	bool OnMouseMovedEvent(MouseMovedEvent& event);
	bool OnMouseScrolledEvent(MouseScrolledEvent& event);

	bool OnKeyPressedEvent(KeyPressedEvent& event);
	bool OnKeyReleasedEvent(KeyReleasedEvent& event);
	bool OnKyeTypedEvent(KeyEvent& event);

	bool OnWindowResizedEvent(WindowResizedEvent& event);
	bool OnWindowClosedEvent(WindowCloseEvent& e);
private:
	// ��ʼ��
	void Init();
	// ɾ���������캯���͸�ֵ���������
	Render(Render&) = delete;
	Render& operator=(const Render&) = delete;
private:
	// ��Ⱦ���Ƿ���������
	bool m_bRunning;

	// �Ƿ���С��
	bool m_bMinimized;

	// ���һ֡��ʱ��
	float m_fLastFrameTime;

	// ��Ⱦ������
	Ref<Window> m_spWindow;

	// ��Ⱦ��
	static Ref<Render> m_spRender;
};

RENDERER_NAMESPACE_END