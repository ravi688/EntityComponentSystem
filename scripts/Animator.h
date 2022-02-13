#pragma once

#include <ecs/component.h>

#define Animator_TYPE_ID CREATE_COMPONENT_ID(2)

typedef struct Animator
{
	DERIVE_FROM_COMPONENT;
} Animator;


ECS_API void OnInstantiate(Animator);
ECS_API void OnDestroy(Animator);
ECS_API void OnAwake(Animator);
ECS_API void OnStart(Animator);

