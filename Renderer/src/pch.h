#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <algorithm>

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

// glm相关
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

// 全局宏定义
#include "Renderer/Core/Macro.h"

// 数学
#include "Renderer/Math/Math.h"

// 图像
#include "Renderer/TGAImage/TGAImage.h"

// 模型
#include "Renderer/Model/Model.h"
