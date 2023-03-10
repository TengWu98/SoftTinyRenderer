#pragma once
#include "Camera.h"

RENDERER_NAMESPACE_BEGIN

// 透视相机类
class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera();
	PerspectiveCamera(float fFOV, float fAspectRatio, float fNearClip = 0.1f, float fFarClip = 1000.f);
	void SetPerspectiveFOV(float fFOV);
	float GetPerspectiveFOV();
private:
	void RecalculateProjectionMatrix() override;
private:
	float m_fFOV;
};

RENDERER_NAMESPACE_END