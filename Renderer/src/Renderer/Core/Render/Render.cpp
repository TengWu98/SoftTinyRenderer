#include "pch.h"
#include "Render.h"

RENDERER_NAMESPACE_BEGIN

Ref<Render> Render::m_spRender = nullptr;

Render::Render()
{
	// 创建窗口
	m_spWindow = Window::Create();

	// 设置窗口的事件回调函数为此应用对象的OnEvent函数
	m_spWindow->SetEventCallback(BIND_EVENT_FUN(Render::OnEvent));
}

Ref<Render> Render::GetRender()
{
	if (m_spRender == nullptr)
	{
		m_spRender = Ref<Render>(new Render());
		m_spRender->Init();
	}
	return m_spRender;
}

void Render::Init()
{
	// 进行一些渲染设置
	LOG_DEV_INFO("渲染器初始化完成！");
}

void Render::Close()
{
	m_bRunning = false;
}

// 前向渲染一个场景
void Render::ForwordRender(const Ref<Scene>& scene)
{
	// 渲染循环
	while (!m_bRunning)
	{
		// 如果当前窗口没有最小化
		if (!m_bMinimized)
		{
			std::cout << "Hello World!" << std::endl;
		}

		// 更新窗口(渲染)
		m_spWindow->OnUpdate();
	}
}

// 
void Render::OnEvent(Event& event)
{
	// 定义事件分发器
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUN(Render::OnMouseButtonPressedEvent));
	dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FUN(Render::OnMouseButtonReleasedEvent));
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FUN(Render::OnMouseMovedEvent));
	dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUN(Render::OnMouseScrolledEvent));
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUN(Render::OnKeyPressedEvent));
	dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FUN(Render::OnKeyReleasedEvent));
	dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FUN(Render::OnKyeTypedEvent));
	dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FUN(Render::OnWindowResizedEvent));
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUN(Render::OnWindowClosedEvent));
}

bool Render::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
{
	return false;
}

bool Render::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
{
	return false;
}

bool Render::OnMouseMovedEvent(MouseMovedEvent& event)
{
	return false;
}

bool Render::OnMouseScrolledEvent(MouseScrolledEvent& event)
{
	return false;
}

bool Render::OnKeyPressedEvent(KeyPressedEvent& event)
{
	if (event.GetKeyCode() == Key::Escape)
	{
		m_bRunning = false;
	}
	return false;
}

bool Render::OnKeyReleasedEvent(KeyReleasedEvent& event)
{
	return false;
}

bool Render::OnKyeTypedEvent(KeyEvent& event)
{
	return false;
}

bool Render::OnWindowResizedEvent(WindowResizedEvent& event)
{
	if (event.GetWidth() == 0 || event.GetHeight() == 0)
	{
		m_bMinimized = true;
		return false;
	}
	m_bMinimized = false;
	// SetViewPort(event.GetWidth(), event.GetHeight());
	return false;
}

bool Render::OnWindowClosedEvent(WindowCloseEvent& /*event*/)
{
	m_bRunning = false;
	return true;
}

int Render::GetWindowWidth() const
{
	return m_spWindow->GetWindowWidth();
}

int Render::GetWindowHeight() const
{
	return m_spWindow->GetWindowHeight();
}

const Ref<Window>& Render::GetWindow() const
{
	return m_spWindow;
}

RENDERER_NAMESPACE_END


