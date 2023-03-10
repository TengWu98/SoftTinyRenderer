#include <Renderer.h>

int main(int argc, char** argv)
{
	LOG_DEV_INFO("日志初始化完成!");

    // 定义渲染器对象
    auto render = Renderer::Render::GetRender();
    
    // 创建一个场景
    auto scene = std::make_shared<Renderer::Scene>();

    scene->AddModel(new Renderer::Model("assets/models/bunny/bunny.obj"));

    // 向场景中放入光源
    scene->AddLight(new Renderer::Light(glm::vec3(-20, 70, 20), glm::vec3(0.5, 0.5, 0.5)));

    // 向场景中放置模型

    // 对场景进行前向渲染
    render->ForwordRender(scene);

    EXIT_SUCCESS;
}