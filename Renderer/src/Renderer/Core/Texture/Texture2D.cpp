#include "pch.h"
#include "Texture2D.h"

RENDERER_NAMESPACE_BEGIN

Texture2D::Texture2D(const std::string& sPath) : 
    m_iWidth(0), m_iHeight(0), m_iChannel(0), m_sPath(sPath)
{
    stbi_set_flip_vertically_on_load(1);
    stbi_uc* pImageData = nullptr;
    {
        pImageData = stbi_load(m_sPath.c_str(), &m_iWidth, &m_iHeight, &m_iChannel, 0);
    }
}

Texture2D::Texture2D(int iWidth, int iHeight) : 
    m_iWidth(iWidth), m_iHeight(iHeight), m_iChannel(0), m_sPath("")
{
}

int Texture2D::GetWidth() const
{
    return m_iWidth;
}

int Texture2D::GetHeight() const
{
    return m_iHeight;
}

const std::string& Texture2D::GetTexturePath() const
{
    return m_sPath;
}

Ref<Texture> Texture2D::Create(const std::string& sPath)
{
    return Ref<Texture>();
}

Ref<Texture> Texture2D::Create(int iWidth, int iHeight)
{
    return Ref<Texture>();
}

RENDERER_NAMESPACE_END


