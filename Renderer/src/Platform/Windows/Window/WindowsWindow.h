#pragma once
#include <GLFW/glfw3.h>
#include "Renderer/Core/Window/Window.h"

RENDERER_NAMESPACE_BEGIN

// ���ڻص����������ݣ�
struct WindowCallBack
{
	std::string Title; // ���ڱ���
	int Width;         // ���ڿ��
	int Height;        // ���ڸ߶�

	EventCallbackFn EventCallback; // �¼��ص�����
};

// Windowsƽ̨ʵ�ֵĴ�����
class WindowsWindow : public Window
{
public:
	// ���캯��
	WindowsWindow(const WindowProps& windowPorps);

	// ��������
	virtual ~WindowsWindow();

	// ÿһ֡����
	void OnUpdate() override;

	/********************** �������� ************************/
	// ��ȡ���ڿ��
	inline unsigned int GetWindowWidth() const override;
	// ��ȡ���ڸ߶�
	inline unsigned int GetWindowHeight() const override;
	//���ô����¼��ص�����,ƽ̨����
	inline void SetEventCallback(const EventCallbackFn& eventCallBack) override;

	// 
	void* GetNativeWindow()const override;
private:
	// ���ڳ�ʼ��
	virtual void Init();
	// ��������
	virtual void Shutdown();
private:
	// GLFW����
	GLFWwindow* m_pGLFWWindow;
	// �����¼��ص�
	WindowCallBack m_windowCallBack;
};

RENDERER_NAMESPACE_END