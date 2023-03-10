#pragma once
#include "Texture.h"
#include "stb_image.h"

RENDERER_NAMESPACE_BEGIN

// 2D�����ࣨ����ģʽ��
class Texture2D : public Texture
{
public:
	// ���캯�����������е������ļ�����
	Texture2D(const std::string& sPath);
	// ���캯�������ݿ�߹���
	Texture2D(int iWidth, int iHeight);

	virtual int GetWidth() const override;
	virtual int GetHeight() const override;
	virtual const std::string& GetTexturePath() const override;

	static Ref<Texture> Create(const std::string& sPath);
	static Ref<Texture> Create(int iWidth, int iHeight);
private:
	Texture2D() = delete;
	Texture2D(const Texture2D&) = delete;
	Texture2D& operator=(const Texture2D&) = delete;
private:
	int m_iWidth;	// ͼ����
	int m_iHeight;	// ͼ��߶�
	int m_iChannel;	// ͼ��ͨ����

	std::string m_sPath; // ͼ��·��
};

RENDERER_NAMESPACE_END