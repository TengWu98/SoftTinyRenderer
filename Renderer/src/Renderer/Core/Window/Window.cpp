#include "pch.h"
#include "Platform/Windows/Window/WindowsWindow.h"

RENDERER_NAMESPACE_BEGIN

// 创建窗口
Ref<Window> Window::Create(const WindowProps& windowPorps)
{
// 如果当前编译平台是Windows，则使用WindowsWindow创建窗口
#ifdef RENDERER_PLATFORM_WINDOWS
	return CreateRef<WindowsWindow>(windowPorps);
#else
	RENDERER_ASSERT(false, "暂不支持该平台！");
	return nullptr;
#endif // RENDERER_PLATFORM_WINDOWS
}

// 构造函数
Window::Window(const WindowProps& windowPorps) :
	m_WindowProps(windowPorps)
{
}

RENDERER_NAMESPACE_END