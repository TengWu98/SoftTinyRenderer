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

// 构造函数
WindowsWindow::WindowsWindow(const WindowProps& m_WindowProps) : Window(m_WindowProps)
{
	// 初始化窗口
	Init();
}

// 析构函数
WindowsWindow::~WindowsWindow()
{
	// 结束窗口
	Shutdown();
}

// 窗口更新(渲染循环)
void WindowsWindow::OnUpdate()
{
	// 交换缓冲区
	glfwSwapBuffers(m_pGLFWWindow);

	// 轮询IO时间（键盘或鼠标）
	glfwPollEvents();
}

// 获取窗口宽度
inline unsigned int WindowsWindow::GetWindowWidth() const
{
	return m_windowCallBack.Width;
}

// 获取窗口高度
inline unsigned int WindowsWindow::GetWindowHeight() const
{
	return m_windowCallBack.Height;
}

// 设置窗口事件回调函数
inline void WindowsWindow::SetEventCallback(const EventCallbackFn& eventCallBack)
{
	m_windowCallBack.EventCallback = eventCallBack;
}

// 
void* WindowsWindow::GetNativeWindow() const
{
	return m_pGLFWWindow;
}

// 窗口初始化
void WindowsWindow::Init()
{
	// 日志输出：
	LOG_DEV_INFO("正在创建窗口 {0} ({1}, {2})",
		m_WindowProps.Title, m_WindowProps.Width, m_WindowProps.Height);

	// 初始化glfw
	bool bInit = glfwInit();
	RENDERER_ASSERT(bInit, "初始化GLFW失败！");

	// 设置窗口的宽度、高度
	m_windowCallBack.Width = m_WindowProps.Width;
	m_windowCallBack.Height = m_WindowProps.Height;

	// 创建窗口
	{
			m_pGLFWWindow = glfwCreateWindow(m_WindowProps.Width,
				m_WindowProps.Height, m_WindowProps.Title.c_str(), nullptr, nullptr);
	}
	// 判断窗口是否创建成功
	RENDERER_ASSERT(m_pGLFWWindow, "创建GLFW窗口失败！");

	// 日志输出
	LOG_DEV_INFO("窗口创建成功！");

	/************************** 设置GLFW回调函数 *****************************/
	// 错误回调函数
	glfwSetErrorCallback(GLFWErrorCallback);

	// 存储m_pGLFWWindow关联的回调数据指针
	glfwSetWindowUserPointer(m_pGLFWWindow, &m_windowCallBack);

	// 窗口大小改变的回调函数
	glfwSetWindowSizeCallback(m_pGLFWWindow, [](GLFWwindow* window, int width, int height)
	{
		// 获取m_pGLFWWindow关联的回调数据指针
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
		// 设置窗口宽度和高度
		pWindowCallBack.Width = width;
		pWindowCallBack.Height = height;

		// 创建改变窗口的事件
		WindowResizedEvent event(width, height);
		LOG_DEV_WARN("window resize {0},{1}", width, height);

		// 设置窗口的事件回调函数
		pWindowCallBack.EventCallback(event);
	});

	// 窗口关闭的回调函数
	glfwSetWindowCloseCallback(m_pGLFWWindow, [](GLFWwindow* window)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		pWindowCallBack.EventCallback(event);
	});

	// 键盘按键的回调函数
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

	// 打字时调用的Event
	glfwSetCharCallback(m_pGLFWWindow, [](GLFWwindow* window, unsigned int keycode)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		KeyTypedEvent event(keycode);
		pWindowCallBack.EventCallback(event);
	});

	// 鼠标按钮的回调函数
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

	// 鼠标滑轮的回调函数
	glfwSetScrollCallback(m_pGLFWWindow, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
		pWindowCallBack.EventCallback(event);
	});

	// 光标的回调函数（鼠标移动）
	glfwSetCursorPosCallback(m_pGLFWWindow, [](GLFWwindow* window, double xPos, double yPos)
	{
		auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

		MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
		pWindowCallBack.EventCallback(event);
	});
}

// 结束窗口
void WindowsWindow::Shutdown()
{
	glfwDestroyWindow(m_pGLFWWindow);
}

RENDERER_NAMESPACE_END