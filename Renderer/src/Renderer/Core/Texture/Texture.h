#pragma once

RENDERER_NAMESPACE_BEGIN

// �����ࣨ�����ࣩ
class Texture
{
public:
	// ������������Ϊ�麯������̬��
	virtual ~Texture() = default;
	
	// ��ȡ����߶�
	virtual int GetWidth() const = 0;
	// ��ȡ������
	virtual int GetHeight() const = 0;
	// ��ȡ�����ļ�·��
	virtual const std::string& GetTexturePath() const = 0;
};

RENDERER_NAMESPACE_END