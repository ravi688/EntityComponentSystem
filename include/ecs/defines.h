
#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

#ifdef BUF_STATIC_LIBRARY
#	define ECS_API
#elif BUF_DYNAMIC_LIBRARY
#	define ECS_API __declspec(dllimport)
#elif BUILD_DYNAMIC_LIBRARY
#	define ECS_API __declspec(dllexport)
#else
#	define ECS_API
#endif
