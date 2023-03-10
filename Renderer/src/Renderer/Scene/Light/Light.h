#pragma once

RENDERER_NAMESPACE_BEGIN

class Light
{
public:
    // 构造函数
    Light(glm::vec3 vec3Position, glm::vec3 vec3Intensity);

    // 拷贝构造函数
    Light(const Light& light);

    // 析构函数
    virtual ~Light() = default;

    void SetPosition(const glm::vec3& vec3Position);
    const glm::vec3& GetPosition() const;

    void SetIntensity(const glm::vec3& vec3Intensity);
    const glm::vec3& GetIntensity() const;
private:
    // 光源位置
    glm::vec3 m_vec3Position;
    // 光源强度
    glm::vec3 m_vec3Intensity;
};

RENDERER_NAMESPACE_END