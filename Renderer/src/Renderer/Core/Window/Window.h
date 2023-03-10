#pragma once
#include "Renderer/Events/Event.h"

#include "Renderer/Events/KeyEvent.h"
#include "Renderer/Events/MouseEvent.h"
#include "Renderer/Events/WindowEvent.h"

RENDERER_NAMESPACE_BEGIN

// ��������
struct WindowProps
{
	// ���ڱ���
	std::string Title;

	// ���ڿ�Ⱥ͸߶�
	int Width;
	int Height;

	// ���캯��
	WindowProps(const std::string& sTitle = "Renderer", int iWidth = 1280, int iHeight = 720)
		: Title(sTitle), Width(iWidth), Height(iHeight)
	{
	}
};

// �¼��ص�����
using EventCallbackFn = std::function<void(Event&)>;

// ���ڳ����ࣨ����ģʽ��
class Window
{
public:
	// �����������麯����
	virtual ~Window(){};

	// ÿһ֡���ã����麯����
	virtual void OnUpdate() = 0;

	/********************** �������� ************************/
	// ��ȡ���ڿ�ȣ����麯����
	virtual unsigned int GetWindowWidth() const = 0;
	// ��ȡ���ڸ߶ȣ����麯����
	virtual unsigned int GetWindowHeight() const = 0;
	// ���ô����¼��ص�����,ƽ̨���������麯����
	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

	// 
	virtual void* GetNativeWindow()const = 0;
	/********************** �������� ************************/
	static Ref<Window> Create(const WindowProps& windowPorps = WindowProps());
protected:
	// ���캯��
	Window(const WindowProps& windowPorps);
private:
	// ɾ��Ĭ�Ϲ��졢��������Ϳ�����ֵ����������ڵ���ģʽ��
	Window() = delete;
	Window(Window&) = delete;
	Window& operator=(const Window&) = delete;
protected:
	// ��������
	WindowProps m_WindowProps;
};

RENDERER_NAMESPACE_END
