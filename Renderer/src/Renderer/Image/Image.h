#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

RENDERER_NAMESPACE_BEGIN

class Image
{
public:
	// ���캯��
	Image(const std::string& filePath){}
	// ��������
	~Image(){}

private:
	int m_iWidth; // ͼ����
	int m_iHeight; // ͼ��߶�
	int m_iChannels; // ͼ��ͨ����
};

RENDERER_NAMESPACE_END