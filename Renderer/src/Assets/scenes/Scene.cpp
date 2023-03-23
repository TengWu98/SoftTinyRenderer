#include "pch.h"
#include "Scene.h"

RENDERER_NAMESPACE_BEGIN

// 从文件中读取纹理
TGAImage* texture_from_file(const char* file_name)
{
	TGAImage* texture = new TGAImage();
	texture->read_tga_file(file_name);
	texture->flip_vertically();
	return texture;
}

// 从文件中读取立方体贴图
cubemap_t* cubemap_from_files(const char* positive_x, const char* negative_x,
	const char* positive_y, const char* negative_y,
	const char* positive_z, const char* negative_z)
{
	cubemap_t* cubemap = new cubemap_t();
	cubemap->faces[0] = texture_from_file(positive_x);
	cubemap->faces[1] = texture_from_file(negative_x);
	cubemap->faces[2] = texture_from_file(positive_y);
	cubemap->faces[3] = texture_from_file(negative_y);
	cubemap->faces[4] = texture_from_file(positive_z);
	cubemap->faces[5] = texture_from_file(negative_z);
	return cubemap;
}

// 从文件中读取IBL贴图
void load_ibl_map(payload_t& p, const char* env_path)
{
	int i, j;
	iblmap_t* iblmap = new iblmap_t();
	const char* faces[6] = { "px", "nx", "py", "ny", "pz", "nz" };
	char paths[6][256];

	iblmap->mip_levels = 10;

	/* diffuse environment map */
	for (j = 0; j < 6; j++) {
		sprintf_s(paths[j], "%s/i_%s.tga", env_path, faces[j]);
	}
	iblmap->irradiance_map = cubemap_from_files(paths[0], paths[1], paths[2],
		paths[3], paths[4], paths[5]);

	/* specular environment maps */
	for (i = 0; i < iblmap->mip_levels; i++) {
		for (j = 0; j < 6; j++) {
			sprintf_s(paths[j], "%s/m%d_%s.tga", env_path, i, faces[j]);
		}
		iblmap->prefilter_maps[i] = cubemap_from_files(paths[0], paths[1],
			paths[2], paths[3], paths[4], paths[5]);
	}

	/* brdf lookup texture */
	iblmap->brdf_lut = texture_from_file("assert/common/BRDF_LUT.tga");

	p.iblmap = iblmap;

}

// 
void build_fuhua_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	// 模型数量
	m = 4;
	const char* modelname[] =
	{
		"assert/fuhua/fuhuabody.obj",
		"assert/fuhua/fuhuahair.obj",
		"assert/fuhua/fuhuaface.obj",
		"assert/fuhua/fuhuacloak.obj",
	};

	int vertex = 0, face = 0;
	const char* scene_name = "fuhua";

	// phong着色器
	PhongShader* shader_phong = new PhongShader();

	// 创建场景中的所有模型
	for (int i = 0; i < m; i++)
	{
		model[i] = new Model(modelname[i], 0, 1);
		vertex += model[i]->nverts();
		face += model[i]->nfaces();
	}

	// 设置vp矩阵
	shader_phong->payload.camera_perp_matrix = perspective;
	shader_phong->payload.camera = camera;

	*shader_use = shader_phong;
	*shader_skybox = NULL;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}

void build_qiyana_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	m = 3;
	const char* modelname[] =
	{
		"assert/qiyana/qiyanabody.obj",
		"assert/qiyana/qiyanahair.obj",
		"assert/qiyana/qiyanaface.obj",
	};

	int vertex = 0, face = 0;
	const char* scene_name = "qiyana";
	PhongShader* shader_phong = new PhongShader();

	for (int i = 0; i < m; i++)
	{
		model[i] = new Model(modelname[i], 0, 1);
		vertex += model[i]->nverts();
		face += model[i]->nfaces();
	}

	shader_phong->payload.camera_perp_matrix = perspective;
	shader_phong->payload.camera = camera;

	*shader_use = shader_phong;
	*shader_skybox = NULL;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}


void build_xier_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	m = 5;
	const char* modelname[] =
	{
		"assert/xier/xierbody.obj",
		"assert/xier/xierhair.obj",
		"assert/xier/xierface.obj",
		"assert/xier/xiercloth.obj",
		"assert/xier/xierarm.obj",
	};

	int vertex = 0, face = 0;
	const char* scene_name = "xier";
	PhongShader* shader_phong = new PhongShader();

	for (int i = 0; i < m; i++)
	{
		model[i] = new Model(modelname[i], 0, 1);
		vertex += model[i]->nverts();
		face += model[i]->nfaces();
	}

	shader_phong->payload.camera_perp_matrix = perspective;
	shader_phong->payload.camera = camera;

	*shader_use = shader_phong;
	*shader_skybox = NULL;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}


void build_yayi_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	m = 7;
	const char* modelname[] = {
		"assert/yayi/yayiface.obj",
		"assert/yayi/yayibody.obj",
		"assert/yayi/yayihair.obj",
		"assert/yayi/yayiarmour1.obj",
		"assert/yayi/yayiarmour2.obj",
		"assert/yayi/yayidecoration.obj",
		"assert/yayi/yayisword.obj"
	};

	int vertex = 0, face = 0;
	const char* scene_name = "yayi";
	PhongShader* shader_phong = new PhongShader();

	for (int i = 0; i < m; i++)
	{
		model[i] = new Model(modelname[i], 0, 1);
		vertex += model[i]->nverts();
		face += model[i]->nfaces();
	}

	shader_phong->payload.camera_perp_matrix = perspective;
	shader_phong->payload.camera = camera;

	*shader_use = shader_phong;
	*shader_skybox = NULL;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}

void build_helmet_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	m = 2;
	const char* modelname[] =
	{
		"assert/helmet/helmet.obj",
		"assert/skybox4/box.obj",
	};

	PBRShader* shader_pbr = new PBRShader();
	SkyboxShader* shader_sky = new SkyboxShader();

	int vertex = 0, face = 0;
	const char* scene_name = "helmet";
	model[0] = new Model(modelname[0], 0, 0); vertex += model[0]->nverts(); face += model[0]->nfaces();
	model[1] = new Model(modelname[1], 1, 0); vertex += model[1]->nverts(); face += model[1]->nfaces();

	shader_pbr->payload.camera_perp_matrix = perspective;
	shader_pbr->payload.camera = camera;
	shader_sky->payload.camera_perp_matrix = perspective;
	shader_sky->payload.camera = camera;

	load_ibl_map(shader_pbr->payload, "../obj/common2");

	*shader_use = shader_pbr;
	*shader_skybox = shader_sky;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}

void build_gun_scene(Model** model, int& m, IShader** shader_use, IShader** shader_skybox, mat4 perspective, Camera* camera)
{
	m = 2;
	const char* modelname[] =
	{
		"assert/gun/Cerberus.obj",
		"assert/skybox4/box.obj",
	};

	PBRShader* shader_pbr = new PBRShader();
	SkyboxShader* shader_sky = new SkyboxShader();

	int vertex = 0, face = 0;
	const char* scene_name = "gun";
	model[0] = new Model(modelname[0], 0, 0); vertex += model[0]->nverts(); face += model[0]->nfaces();
	model[1] = new Model(modelname[1], 1, 0); vertex += model[1]->nverts(); face += model[1]->nfaces();

	shader_pbr->payload.camera_perp_matrix = perspective;
	shader_pbr->payload.camera = camera;
	shader_sky->payload.camera_perp_matrix = perspective;
	shader_sky->payload.camera = camera;

	load_ibl_map(shader_pbr->payload, "assert/common2");

	*shader_use = shader_pbr;
	*shader_skybox = shader_sky;

	std::cout << "scene name: " << scene_name << "\n";
	std::cout << "model number: " << m << "\n";
	std::cout << "vertex: " << vertex << ", face: " << face << "\n";
}


RENDERER_NAMESPACE_END