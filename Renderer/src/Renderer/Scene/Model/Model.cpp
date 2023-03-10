#include "pch.h"
#include "Model.h"

RENDERER_NAMESPACE_BEGIN

Model::Model(const std::string& filePath)
	: m_iVertNum(0), m_iFaceNum(0), m_cMaterial(new Material)
{
    std::vector<glm::vec4> verts_;
    std::vector<std::vector<glm::vec3>> faces_;
    std::vector<glm::vec3> norms_;
    std::vector<glm::vec2> uv_;

    std::ifstream in;
    in.open(filePath, std::ifstream::in);
    if (in.fail()) return;
    std::string line;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            glm::vec4 v;
            for (int i = 0; i < 3; i++) iss >> v[i];
            v[3] = 1.0f;
            verts_.push_back(v);
        }
        else if (!line.compare(0, 3, "vt ")) {
            iss >> trash >> trash;
            glm::vec2 uv;
            for (int i = 0; i < 2; i++) iss >> uv[i];
            uv_.push_back(uv);
        }
        else if (!line.compare(0, 3, "vn ")) {
            iss >> trash >> trash;
            glm::vec3 normal;
            for (int i = 0; i < 3; i++) iss >> normal[i];
            norms_.push_back(normal);
        }
        else if (!line.compare(0, 2, "f ")) {
            std::vector<glm::vec3> f;
            glm::vec3 tmp;
            iss >> trash;
            while (iss >> tmp[0] >> trash >> tmp[1] >> trash >> tmp[2]) {
                for (int i = 0; i < 3; i++) tmp[i]--;
                f.push_back(tmp);
            }
            faces_.push_back(f);
        }
    }

    m_vecTriangleList.resize(faces_.size());
    m_vecTriangleList.clear();

    for (int i = 0; i < faces_.size(); i++)
    {
        Triangle triangle;

        std::vector<glm::vec3> face = faces_[i];
        glm::vec3 face_vertex_1 = face[0];
        glm::vec3 face_vertex_2 = face[1];
        glm::vec3 face_vertex_3 = face[2];
        
        // 设置三角形顶点
        std::array<glm::vec4, 3> vec4Vectex({verts_[face_vertex_1.x], verts_[face_vertex_2.x], verts_[face_vertex_3.x]});
        triangle.SetVertex(vec4Vectex);

        // 设置三角形法线
        std::array<glm::vec3, 3> vec3Normal({norms_[face_vertex_1.z], norms_[face_vertex_2.z], norms_[face_vertex_3.z]});
        triangle.SetNormal(vec3Normal);

        // 设置三角形纹理坐标
        std::array<glm::vec2, 3> vec2TexCoords({uv_[face_vertex_1.y], uv_[face_vertex_2.y], uv_[face_vertex_3.y]});
        triangle.SetTexCoords(vec2TexCoords);

        m_vecTriangleList.push_back(triangle);
    }

    m_iVertNum = static_cast<int>(verts_.size());
    m_iFaceNum = static_cast<int>(faces_.size());
}

RENDERER_NAMESPACE_END