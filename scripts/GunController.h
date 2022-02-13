#pragma once

#include <ecs/component.h>

static const u64 TYPE_ID(GunController) = CREATE_COMPONENT_ID(4);

typedef struct GunController
{
	DERIVE_FROM_COMPONENT;
} GunController;


ECS_API void OnInstantiate(GunController);
ECS_API void OnDestroy(GunController);
ECS_API void OnAwake(GunController);
ECS_API void OnStart(GunController);
