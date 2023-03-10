#pragma once
#include "Renderer/Core/Input/Input.h"

RENDERER_NAMESPACE_BEGIN

// Windowsƽ̨�µ�Input������
class WindowsInput :public Input
{
protected:
	virtual bool IsKeyPressedImpl(KeyCode keyCode) override;
	virtual bool IsMouseButtonPressedImpl(MouseCode mouseCode)override;
	virtual glm::vec2 GetMousePosImpl() override;
	virtual float GetMouseXPosImpl() override;
	virtual float GetMouseYPosImpl() override;
};


RENDERER_NAMESPACE_END