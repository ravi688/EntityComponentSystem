

#include "TestBehaviour.h"
#include <ecs/object.h>
#include <stdio.h>

ECS_API void OnInstantiate(TestBehaviour)
{
	BindOnStart(TestBehaviour);
	BindOnDestroy(TestBehaviour);
	BindOnUpdate(TestBehaviour);
	puts("TestBehaviour is instantiated");
}


ECS_API void OnStart(TestBehaviour)
{
	puts("TestBehaviour::OnStart is called");
}

ECS_API void OnDestroy(TestBehaviour)
{
	puts("TestBehaviour::OnUpdate is callled");
}

ECS_API void OnUpdate(TestBehaviour)
{
	
}
