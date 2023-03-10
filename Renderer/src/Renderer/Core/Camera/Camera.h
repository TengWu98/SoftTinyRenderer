#pragma once

RENDERER_NAMESPACE_BEGIN

// �����ͶӰ���ͣ�͸��ͶӰ������ͶӰ��
enum class ProjectionType
{
	Perspective = 0,
	Orthographic
};


// �����(�����࣬���࣬���Լ̳�ʵ�����������͸��ͶӰ���)
class Camera
{
public:
	// ���캯��
	Camera(float fAspectRatio, float fNear, float fFar, ProjectionType eProjectionType);
	// ��������
	~Camera() = default;

	// �������š���ȡ����
	void SetScale(const glm::vec3& vec3Scale);
	const glm::vec3& GetScale()const;

	// ������ת����ȡ��ת
	void SetRotation(const glm::quat& quatRotation);
	const glm::quat& GetRotaion()const;
	
	// �������λ�á���ȡ���λ��
	void SetPosition(const glm::vec3& vec3Position);
	const glm::vec3& GetPosition() const;

	// ����View���󡢻�ȡView����
	void SetViewMatrix(const glm::mat4& mat4ViewMatrix);
	const glm::mat4& GetViewMatrix() const;
	
	// ����Projecion���󡢻�ȡProjection����
	void SetProjectionMatrix(const glm::mat4& mat4ProjectionMatrix);
	const glm::mat4& GetProjectionMatrix() const;

	// ����VP���󡢻�ȡVP����
	void SetViewProjectionMatrix(const glm::mat4& mat4ViewProjectionMatrix);
	const glm::mat4& GetViewProjectionMatrix() const;

	// �������ͶӰ���͡���ȡ���ͶӰ����
	void SetProjectionType(const ProjectionType& eProjectionType);
	const ProjectionType GetProjectionType() const;

	// ���ý��ü�ƽ���Զ�ü�ƽ��
	void SetNearAndFarClip(float fNear, float fFar);

	// ���ý��ü�ƽ�桢��ȡ���ü�ƽ��
	void SetNearClip(float fNear);
	const float GetNearClip() const;
	// ����Զ�ü�ƽ�桢��ȡԶ�ü�ƽ��
	void SetFarClip(float fFar);
	const float GetFarClip() const;

	// ���ÿ�߱ȡ���ȡ��߱�
	void SetAspectRatio(float fAspectRatio);
	const float GetAspectRatio() const;

	// �����ӿڴ�С
	void SetViewPortSize(unsigned int uiWidth, unsigned int uiHeight);
protected:
	// ���¼���Projection����
	virtual void RecalculateProjectionMatrix() = 0;
	// ���¼���View����
	void RecalculateViewMatrix();
	// ���¼���ViewProjection����
	void RecalculateViewProjectionMatrix();
protected:
	// ���ͶӰ����
	ProjectionType m_eProjectionType;

	// View����
	glm::mat4 m_mat4ViewMatrix;
	// Projection����
	glm::mat4 m_mat4ProjectionMatrix;
	// ViewProjection����
	glm::mat4 m_mat4ViewProjectionMatrix;

	// ���λ��
	glm::vec3 m_vec3Position;

	// ���ü�ƽ��
	float m_fNearClip;
	// Զ�ü�ƽ��
	float m_fFarClip;
	// �߿��
	float m_fAspectRatio;

	// �������
	glm::vec3 m_vec3Scale;
	// �����ת
	glm::quat m_quatRotation;

	// �ӿڵĿ��
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
};

RENDERER_NAMESPACE_END