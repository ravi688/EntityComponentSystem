#pragma once

#include <ecs/component.h>

static const u64 TYPE_ID(Ammo) = CREATE_COMPONENT_ID(3);

typedef struct Ammo
{
	DERIVE_FROM_COMPONENT;
	float penetrating_power;
} Ammo;


ECS_API void OnInstantiate(Ammo);
ECS_API void OnDestroy(Ammo);
ECS_API void OnAwake(Ammo);
ECS_API void OnStart(Ammo);
ECS_API void OnUpdate(Ammo);

