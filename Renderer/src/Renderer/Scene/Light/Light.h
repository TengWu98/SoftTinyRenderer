#pragma once

RENDERER_NAMESPACE_BEGIN

class Light
{
public:
    // ���캯��
    Light(glm::vec3 vec3Position, glm::vec3 vec3Intensity);

    // �������캯��
    Light(const Light& light);

    // ��������
    virtual ~Light() = default;

    void SetPosition(const glm::vec3& vec3Position);
    const glm::vec3& GetPosition() const;

    void SetIntensity(const glm::vec3& vec3Intensity);
    const glm::vec3& GetIntensity() const;
private:
    // ��Դλ��
    glm::vec3 m_vec3Position;
    // ��Դǿ��
    glm::vec3 m_vec3Intensity;
};

RENDERER_NAMESPACE_END