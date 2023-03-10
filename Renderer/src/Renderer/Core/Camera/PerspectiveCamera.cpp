#include "pch.h"
#include "PerspectiveCamera.h"

RENDERER_NAMESPACE_BEGIN

PerspectiveCamera::PerspectiveCamera(float fFOV, float fAspectRatio, float fNearClip, float fFarClip) :
	Camera(fAspectRatio, fNearClip, fFarClip, ProjectionType::Perspective),
	m_fFOV(fFOV)
{
	RecalculateProjectionMatrix();
}

PerspectiveCamera::PerspectiveCamera() :
	Camera(1.f, 0.1f, 1000.f, ProjectionType::Perspective),
	m_fFOV(45.f)
{
	RecalculateProjectionMatrix();
}

void PerspectiveCamera::SetPerspectiveFOV(float fFOV)
{
	m_fFOV = fFOV;
	RecalculateProjectionMatrix();
}

float PerspectiveCamera::GetPerspectiveFOV()
{
	return m_fFOV;
}

void PerspectiveCamera::RecalculateProjectionMatrix()
{
	// 这里自己实现透视相机矩阵
	m_mat4ProjectionMatrix = glm::perspective(glm::radians(m_fFOV), m_fAspectRatio, m_fNearClip, m_fFarClip);

	RecalculateViewProjectionMatrix();
}

RENDERER_NAMESPACE_END