#include "Animator.h"
#include <stdio.h>
#include <ecs/object.h>

ECS_API void OnInstantiate(Animator)
{
	BindOnAwake(Animator);
	BindOnStart(Animator); 
	BindOnDestroy(Animator);
	puts("Animator component is Instantiated");
	printf("Animator component is Attached to Object \"%s\"\n", COMPONENT(this)->object->name);
}

ECS_API void OnDestroy(Animator)
{
	puts("Animator component is Destroyed");
}


ECS_API void OnAwake(Animator)
{
	puts("Animator awake is called");
}

ECS_API void OnStart(Animator)
{
	puts("Animator start is called");
}
