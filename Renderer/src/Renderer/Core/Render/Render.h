#pragma once
// 场景
#include "Renderer/Scene/Scene.h"

#include "Renderer/Core/Window/Window.h"
#include "Renderer/Core/Camera/Camera.h"
#include "Renderer/Core/Input/Input.h"

RENDERER_NAMESPACE_BEGIN
// 缓冲
enum class Buffers
{
	Color = 1,
	Depth = 2
};

// 图元
enum class Primitive
{
	Line,
	Triangle
};


// 渲染器类（单例模式）
class Render
{
public:
	static Ref<Render> GetRender();

	// 构造函数
	Render();
	// 析构函数
	~Render() {};

	// 窗口相关
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	const Ref<Window>& GetWindow()const;

	// 事件相关
	void OnEvent(Event& event);

	// 关闭渲染器
	void Close();

	//// 清空ColorBuffer
	//void SetClearColor(const glm::vec4& vec4Color);

	//// 设置视口大小
	//void SetViewPort(unsigned int uiWidth, unsigned int uiHeight);

	//// 清空
	//void Clear();

	//// 绘制三角形
	//void DrawTriangles(unsigned int uiIndexCount);

	//// 绘制直线
	//void DrawLines(unsigned int uiIndexCount);

	//// 设置线宽
	//void SetLineWidth(float fWidth);

	/********************************** 渲染流程 **********************************/
	// 前向渲染
	void ForwordRender(const Ref<Scene>& scene);

	// 延迟渲染
	void DeferredRender(const Ref<Scene>& scene);
private:
	// 事件
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
	// 初始化
	void Init();
	// 删除拷贝构造函数和赋值运算符重载
	Render(Render&) = delete;
	Render& operator=(const Render&) = delete;
private:
	// 渲染器是否正在运行
	bool m_bRunning;

	// 是否最小化
	bool m_bMinimized;

	// 最后一帧的时间
	float m_fLastFrameTime;

	// 渲染器窗口
	Ref<Window> m_spWindow;

	// 渲染器
	static Ref<Render> m_spRender;
};

RENDERER_NAMESPACE_END