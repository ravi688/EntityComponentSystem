
#pragma once

#include <ecs/component.h>

#define TestBehaviour_TYPE_ID CREATE_COMPONENT_ID(10)


typedef struct TestBehaviour
{
	DERIVE_FROM_COMPONENT;
} TestBehaviour;


ECS_API void OnInstantiate(TestBehaviour);
ECS_API void OnStart(TestBehaviour);
ECS_API void OnDestroy(TestBehaviour);
ECS_API void OnUpdate(TestBehaviour);
