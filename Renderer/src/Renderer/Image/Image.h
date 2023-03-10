#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

RENDERER_NAMESPACE_BEGIN

class Image
{
public:
	// 构造函数
	Image(const std::string& filePath){}
	// 析构函数
	~Image(){}

private:
	int m_iWidth; // 图像宽度
	int m_iHeight; // 图像高度
	int m_iChannels; // 图像通道数
};

RENDERER_NAMESPACE_END