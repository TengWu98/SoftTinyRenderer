#pragma once

#include "pch.h"
#include "Renderer/Core/Camera/Camera.h"

RENDERER_NAMESPACE_BEGIN

// 光源
struct light
{
	vec3 pos;
	vec3 intensity;
};

// 立方体贴图
typedef struct cubemap
{
	TGAImage* faces[6];
}cubemap_t;

// IBL贴图
typedef struct iblmap
{
	int mip_levels;
	cubemap_t* irradiance_map;
	cubemap_t* prefilter_maps[15];
	TGAImage* brdf_lut;
} iblmap_t;

typedef struct
{
	// light_matrix:用于shadow mapping
	mat4 model_matrix;
	mat4 camera_view_matrix;
	mat4 light_view_matrix;
	mat4 camera_perp_matrix;
	mat4 light_perp_matrix;
	mat4 mvp_matrix;

	Camera* camera;
	Model* model;

	// 顶点属性
	vec3 normal_attri[3];		// 法线
	vec2 uv_attri[3];			// 纹理坐标
	vec3 worldcoord_attri[3];	
	vec4 clipcoord_attri[3];

	// 用于齐次裁剪
	vec3 in_normal[MAX_VERTEX];
	vec2 in_uv[MAX_VERTEX];
	vec3 in_worldcoord[MAX_VERTEX];
	vec4 in_clipcoord[MAX_VERTEX];
	vec3 out_normal[MAX_VERTEX];
	vec2 out_uv[MAX_VERTEX];
	vec3 out_worldcoord[MAX_VERTEX];
	vec4 out_clipcoord[MAX_VERTEX];

	//	用于IBL
	iblmap_t* iblmap;
}payload_t;

// Shader基类
class IShader
{
public:
	payload_t payload;
	virtual void vertex_shader(int nfaces, int nvertex) {}
	virtual vec3 fragment_shader(float alpha, float beta, float gamma) { return vec3(0, 0, 0); }
};

// Phong Shader
class PhongShader :public IShader
{
public:
	void vertex_shader(int nfaces, int nvertex);
	vec3 fragment_shader(float alpha, float beta, float gamma);

};

// PBRShader
class PBRShader :public IShader
{
public:
	void vertex_shader(int nfaces, int nvertex);
	vec3 fragment_shader(float alpha, float beta, float gamma);
	vec3 direct_fragment_shader(float alpha, float beta, float gamma);
};

// SkyboxShader
class SkyboxShader :public IShader
{
public:
	void vertex_shader(int nfaces, int nvertex);
	vec3 fragment_shader(float alpha, float beta, float gamma);
};

RENDERER_NAMESPACE_END