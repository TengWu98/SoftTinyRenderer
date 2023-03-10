#pragma once

RENDERER_NAMESPACE_BEGIN

// 纹理类（抽象类）
class Texture
{
public:
	// 析构函数定义为虚函数（多态）
	virtual ~Texture() = default;
	
	// 获取纹理高度
	virtual int GetWidth() const = 0;
	// 获取纹理宽度
	virtual int GetHeight() const = 0;
	// 获取纹理文件路径
	virtual const std::string& GetTexturePath() const = 0;
};

RENDERER_NAMESPACE_END