#include <Renderer.h>

int main(int argc, char** argv)
{
	LOG_DEV_INFO("��־��ʼ�����!");

    // ������Ⱦ������
    auto render = Renderer::Render::GetRender();
    
    // ����һ������
    auto scene = std::make_shared<Renderer::Scene>();

    scene->AddModel(new Renderer::Model("assets/models/bunny/bunny.obj"));

    // �򳡾��з����Դ
    scene->AddLight(new Renderer::Light(glm::vec3(-20, 70, 20), glm::vec3(0.5, 0.5, 0.5)));

    // �򳡾��з���ģ��

    // �Գ�������ǰ����Ⱦ
    render->ForwordRender(scene);

    EXIT_SUCCESS;
}