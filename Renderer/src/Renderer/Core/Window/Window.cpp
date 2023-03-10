#include "pch.h"
#include "Platform/Windows/Window/WindowsWindow.h"

RENDERER_NAMESPACE_BEGIN

// ��������
Ref<Window> Window::Create(const WindowProps& windowPorps)
{
// �����ǰ����ƽ̨��Windows����ʹ��WindowsWindow��������
#ifdef RENDERER_PLATFORM_WINDOWS
	return CreateRef<WindowsWindow>(windowPorps);
#else
	RENDERER_ASSERT(false, "�ݲ�֧�ָ�ƽ̨��");
	return nullptr;
#endif // RENDERER_PLATFORM_WINDOWS
}

// ���캯��
Window::Window(const WindowProps& windowPorps) :
	m_WindowProps(windowPorps)
{
}

RENDERER_NAMESPACE_END