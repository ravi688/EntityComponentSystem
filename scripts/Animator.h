#pragma once

#include <ecs/component.h>

static const u64 TYPE_ID(Animator) = CREATE_COMPONENT_ID(2);

typedef struct Animator
{
	DERIVE_FROM_COMPONENT;
} Animator;


ECS_API void OnInstantiate(Animator);
ECS_API void OnDestroy(Animator);
ECS_API void OnAwake(Animator);
ECS_API void OnStart(Animator);

