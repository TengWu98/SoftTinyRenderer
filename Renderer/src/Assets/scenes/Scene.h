#pragma once
#include "pch.h"
// ����
#include "Platform/Windows/Win32.h"
// ���
#include "Renderer/Core/Camera/Camera.h"
// ��ɫ��
#include "Renderer/Core/Shader/Shader.h"
// ��������
#include "Renderer/Core/Sample/Sample.h"
// ����
#include "Renderer/Core/Pipeline/Pipeline.h"

RENDERER_NAMESPACE_BEGIN

typedef struct
{
	const char* scene_name;
	void (*build_scene)(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);
} scene_t;

TGAImage* texture_from_file(const char* file_name);
void load_ibl_map(payload_t& p, const char* env_path);

/*************************************** phong scene *****************************************/
void build_fuhua_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);
void build_xier_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);
void build_qiyana_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);

/*************************************** pbr scene *****************************************/
void build_yayi_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);
void build_helmet_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);
void build_gun_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera);

RENDERER_NAMESPACE_END