#include "pch.h"
#include "WindowsWindow.h"

RENDERER_NAMESPACE_BEGIN

namespace
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		LOG_DEV_ERROR("GLFW Error ({0}): {1}", error, description);
	}
}

// ���캯��
WindowsWindow::WindowsWindow(const WindowProps& m_WindowProps) : Window(m_WindowProps)
{
	// ��ʼ������
	Init();
}

// ��������
WindowsWindow::~WindowsWindow()
{
	// ��������
	Shutdown();
}

// ���ڸ���(��Ⱦѭ��)
void WindowsWindow::OnUpdate()
{
	// ����������
	glfwSwapBuffers(m_pGLFWWindow);

	// ��ѯIOʱ�䣨���̻���꣩
	glfwPollEvents();
}

// ��ȡ���ڿ��
inline unsigned int WindowsWindow::GetWindowWidth() const
{
	return m_windowCallBack.Width;
}

// ��ȡ���ڸ߶�
inline unsigned int WindowsWindow::GetWindowHeight() const
{
	return m_windowCallBack.Height;
}

// ���ô����¼��ص�����
inline void WindowsWindow::SetEventCallback(const EventCallbackFn& eventCallBack)
{
	m_windowCallBack.EventCallback = eventCallBack;
}

// 
void* WindowsWindow::GetNativeWindow() const
{
	return m_pGLFWWindow;
}

// ���ڳ�ʼ��
void WindowsWindow::Init()
{
	// ��־�����
	LOG_DEV_INFO("���ڴ������� {0} ({1}, {2})",
		m_WindowProps.Title, m_WindowProps.Width, m_WindowProps.Height);

	// ��ʼ��glfw
	bool bInit = glfwInit();
	RENDERER_ASSERT(bInit, "��ʼ��GLFWʧ�ܣ�");

	// ���ô��ڵĿ�ȡ��߶�
	m_windowCallBack.Width = m_WindowProps.Width;
	m_windowCallBack.Height = m_WindowProps.Height;

	// ��������
	{
			m_pGLFWWindow = glfwCreateWindow(m_WindowProps.Width,
				m_WindowProps.Height, m_WindowProps.Title.c_str(), nullptr, nullptr);
	}
	// �жϴ����Ƿ񴴽��ɹ�
	RENDERER_ASSERT(m_pGLFWWindow, "����GLFW����ʧ�ܣ�");

	// ��־���
	LOG_DEV_INFO("���ڴ����ɹ���");

	/************************** ����GLFW�ص����� *****************************/
	// ����ص�����
	glfwSetErrorCallback(GLFWErrorCallback);

	// �洢m_pGLFWWindow�����Ļص�����ָ��
	glfwSetWindowUserPointer(m_pGLFWWindow, &m_windowCallBack);

	// ���ڴ�С�ı�Ļص�����
	glfwSetWindowSizeCallback(m_pGLFWWindow, [](GLFWwindow* window, int width, int height)
	{
		// ��ȡm_pGLFWWindow�����Ļص�����ָ��
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
		// ���ô��ڿ�Ⱥ͸߶�
		pWindowCallBack.Width = width;
		pWindowCallBack.Height = height;

		// �����ı䴰�ڵ��¼�
		WindowResizedEvent event(width, height);
		LOG_DEV_WARN("window resize {0},{1}", width, height);

		// ���ô��ڵ��¼��ص�����
		pWindowCallBack.EventCallback(event);
	});

	// ���ڹرյĻص�����
	glfwSetWindowCloseCallback(m_pGLFWWindow, [](GLFWwindow* window)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		pWindowCallBack.EventCallback(event);
	});

	// ���̰����Ļص�����
	glfwSetKeyCallback(m_pGLFWWindow, [](GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent event(key, false);
			pWindowCallBack.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent event(key);
			pWindowCallBack.EventCallback(event);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressedEvent event(key, true);
			pWindowCallBack.EventCallback(event);
			break;
		}
		}
	});

	// ����ʱ���õ�Event
	glfwSetCharCallback(m_pGLFWWindow, [](GLFWwindow* window, unsigned int keycode)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		KeyTypedEvent event(keycode);
		pWindowCallBack.EventCallback(event);
	});

	// ��갴ť�Ļص�����
	glfwSetMouseButtonCallback(m_pGLFWWindow, [](GLFWwindow* window, int button, int action, int mods)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent event(button);
			pWindowCallBack.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent event(button);
			pWindowCallBack.EventCallback(event);
			break;
		}
		}
	});

	// ��껬�ֵĻص�����
	glfwSetScrollCallback(m_pGLFWWindow, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
		pWindowCallBack.EventCallback(event);
	});

	// ���Ļص�����������ƶ���
	glfwSetCursorPosCallback(m_pGLFWWindow, [](GLFWwindow* window, double xPos, double yPos)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
		pWindowCallBack.EventCallback(event);
	});
}

// ��������
void WindowsWindow::Shutdown()
{
	glfwDestroyWindow(m_pGLFWWindow);
}

RENDERER_NAMESPACE_END