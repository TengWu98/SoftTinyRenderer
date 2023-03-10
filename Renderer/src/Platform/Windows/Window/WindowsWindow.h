#pragma once
#include <GLFW/glfw3.h>
#include "Renderer/Core/Window/Window.h"

RENDERER_NAMESPACE_BEGIN

// 窗口回调（窗口数据）
struct WindowCallBack
{
	std::string Title; // 窗口标题
	int Width;         // 窗口宽度
	int Height;        // 窗口高度

	EventCallbackFn EventCallback; // 事件回调函数
};

// Windows平台实现的窗口类
class WindowsWindow : public Window
{
public:
	// 构造函数
	WindowsWindow(const WindowProps& windowPorps);

	// 析构函数
	virtual ~WindowsWindow();

	// 每一帧调用
	void OnUpdate() override;

	/********************** 窗口属性 ************************/
	// 获取窗口宽度
	inline unsigned int GetWindowWidth() const override;
	// 获取窗口高度
	inline unsigned int GetWindowHeight() const override;
	//设置窗口事件回调函数,平台触发
	inline void SetEventCallback(const EventCallbackFn& eventCallBack) override;

	// 
	void* GetNativeWindow()const override;
private:
	// 窗口初始化
	virtual void Init();
	// 结束窗口
	virtual void Shutdown();
private:
	// GLFW窗口
	GLFWwindow* m_pGLFWWindow;
	// 窗口事件回调
	WindowCallBack m_windowCallBack;
};

RENDERER_NAMESPACE_END