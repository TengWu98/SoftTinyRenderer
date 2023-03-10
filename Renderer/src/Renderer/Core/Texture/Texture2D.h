#pragma once
#include "Texture.h"
#include "stb_image.h"

RENDERER_NAMESPACE_BEGIN

// 2D纹理类（单例模式）
class Texture2D : public Texture
{
public:
	// 构造函数：根据已有的纹理文件构造
	Texture2D(const std::string& sPath);
	// 构造函数：根据宽高构造
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
	int m_iWidth;	// 图像宽度
	int m_iHeight;	// 图像高度
	int m_iChannel;	// 图像通道数

	std::string m_sPath; // 图像路径
};

RENDERER_NAMESPACE_END