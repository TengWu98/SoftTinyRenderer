#pragma once

RENDERER_NAMESPACE_BEGIN

// 相机的投影类型（透视投影或正交投影）
enum class ProjectionType
{
	Perspective = 0,
	Orthographic
};


// 相机类(抽象类，基类，可以继承实现正交相机和透视投影相机)
class Camera
{
public:
	// 构造函数
	Camera(float fAspectRatio, float fNear, float fFar, ProjectionType eProjectionType);
	// 析构函数
	~Camera() = default;

	// 设置缩放、获取缩放
	void SetScale(const glm::vec3& vec3Scale);
	const glm::vec3& GetScale()const;

	// 设置旋转、获取旋转
	void SetRotation(const glm::quat& quatRotation);
	const glm::quat& GetRotaion()const;
	
	// 设置相机位置、获取相机位置
	void SetPosition(const glm::vec3& vec3Position);
	const glm::vec3& GetPosition() const;

	// 设置View矩阵、获取View矩阵
	void SetViewMatrix(const glm::mat4& mat4ViewMatrix);
	const glm::mat4& GetViewMatrix() const;
	
	// 设置Projecion矩阵、获取Projection矩阵
	void SetProjectionMatrix(const glm::mat4& mat4ProjectionMatrix);
	const glm::mat4& GetProjectionMatrix() const;

	// 设置VP矩阵、获取VP矩阵
	void SetViewProjectionMatrix(const glm::mat4& mat4ViewProjectionMatrix);
	const glm::mat4& GetViewProjectionMatrix() const;

	// 设置相机投影类型、获取相机投影类型
	void SetProjectionType(const ProjectionType& eProjectionType);
	const ProjectionType GetProjectionType() const;

	// 设置近裁剪平面和远裁剪平面
	void SetNearAndFarClip(float fNear, float fFar);

	// 设置近裁剪平面、获取近裁剪平面
	void SetNearClip(float fNear);
	const float GetNearClip() const;
	// 设置远裁剪平面、获取远裁剪平面
	void SetFarClip(float fFar);
	const float GetFarClip() const;

	// 设置宽高比、获取宽高比
	void SetAspectRatio(float fAspectRatio);
	const float GetAspectRatio() const;

	// 设置视口大小
	void SetViewPortSize(unsigned int uiWidth, unsigned int uiHeight);
protected:
	// 重新计算Projection矩阵
	virtual void RecalculateProjectionMatrix() = 0;
	// 重新计算View矩阵
	void RecalculateViewMatrix();
	// 重新计算ViewProjection矩阵
	void RecalculateViewProjectionMatrix();
protected:
	// 相机投影类型
	ProjectionType m_eProjectionType;

	// View矩阵
	glm::mat4 m_mat4ViewMatrix;
	// Projection矩阵
	glm::mat4 m_mat4ProjectionMatrix;
	// ViewProjection矩阵
	glm::mat4 m_mat4ViewProjectionMatrix;

	// 相机位置
	glm::vec3 m_vec3Position;

	// 近裁剪平面
	float m_fNearClip;
	// 远裁剪平面
	float m_fFarClip;
	// 高宽比
	float m_fAspectRatio;

	// 相机缩放
	glm::vec3 m_vec3Scale;
	// 相机旋转
	glm::quat m_quatRotation;

	// 视口的宽高
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
};

RENDERER_NAMESPACE_END