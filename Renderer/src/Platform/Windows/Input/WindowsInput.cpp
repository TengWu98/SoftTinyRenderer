#include "pch.h"
#include "WindowsInput.h"

#include "GLFW/glfw3.h"
#include "Renderer/Core/Render/Render.h"

RENDERER_NAMESPACE_BEGIN

Ref<Input> Input::m_spInput = Ref<WindowsInput>(new WindowsInput());

bool WindowsInput::IsKeyPressedImpl(KeyCode keyCode)
{
	// 获取当前应用的窗口
	const auto& spWindow = Render::GetRender()->GetWindow();
	// 获取对应的glfw窗口
	auto glfwWindow = static_cast<GLFWwindow*>(spWindow->GetNativeWindow());

	// 调用GLFW的对应函数判断键盘是否按下
	auto state = glfwGetKey(glfwWindow, keyCode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(MouseCode mouseCode)
{
	const auto& upWindow = Render::GetRender()->GetWindow();
	auto glfwWindow = static_cast<GLFWwindow*>(upWindow->GetNativeWindow());

	auto state = glfwGetMouseButton(glfwWindow, mouseCode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

glm::vec2 WindowsInput::GetMousePosImpl()
{
	const auto& upWindow = Render::GetRender()->GetWindow();
	auto glfwWindow = static_cast<GLFWwindow*>(upWindow->GetNativeWindow());

	double dXPos(0.0), dYPos(0.0);
	glfwGetCursorPos(glfwWindow, &dXPos, &dYPos);
	return glm::vec2(dXPos, dYPos);
}

float WindowsInput::GetMouseXPosImpl()
{
	auto vec2Pos = GetMousePosImpl();
	return vec2Pos.x;
}

float WindowsInput::GetMouseYPosImpl()
{
	auto vec2Pos = GetMousePosImpl();
	return vec2Pos.y;
}


RENDERER_NAMESPACE_END