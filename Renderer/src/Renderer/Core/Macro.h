#pragma once
#include <memory>

#define EPSILON 1e-5f

#define PI 3.1415927f

// �Ƕ�ת����
#define TO_RADIANS(degrees) ((PI / 180) * (degrees))
// ����ת�Ƕ�
#define TO_DEGREES(radians) ((180 / PI) * (radians))

// λ����
#define BIT(x) (1<<x)

// ���������ռ� Renderer
#ifndef RENDERER_NAMESPACE_BEGIN
#define RENDERER_NAMESPACE_BEGIN \
	namespace  Renderer{
#endif 

#ifndef RENDERER_NAMESPACE_END
#define RENDERER_NAMESPACE_END \
	}
#endif 

#define BIND_EVENT_FUN(x) std::bind(&x, this, std::placeholders::_1)

// ����
#ifdef RENDERER_ENABLE_ASSERTS
#define RENDERER_ASSERT(x,...) { if(!(x)) { LOG_DEV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#endif // RENDERER_ENABLE_ASSERTS

RENDERER_NAMESPACE_BEGIN
template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
};

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
};

RENDERER_NAMESPACE_END