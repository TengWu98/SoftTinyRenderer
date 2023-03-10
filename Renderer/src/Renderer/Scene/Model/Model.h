#pragma once
#include "Triangle/Triangle.h"
#include "Material/Material.h"

RENDERER_NAMESPACE_BEGIN

// ������
class Model
{
public:
	// ���캯��
	Model(const std::string& filePath);

	// ��������
	~Model() {};

	// ������Ŀ
	inline int GetVertNum() { return m_iVertNum; };
	// ��Ƭ��Ŀ
	inline int GetFaceNum() { return m_iFaceNum; };
private:
	int m_iVertNum; // ģ�Ͷ�����
	int m_iFaceNum; // ģ����Ƭ��

	// ģ�͵�����������
	std::vector<Triangle> m_vecTriangleList;

	// ģ�͵Ĳ���
	Material* m_cMaterial;
};

RENDERER_NAMESPACE_END