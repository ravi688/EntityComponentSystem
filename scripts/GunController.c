#include "GunController.h"
#include <ecs/object.h>
#include <stdio.h>

ECS_API void OnInstantiate(GunController)
{
	BindOnAwake(GunController);
	BindOnStart(GunController); 
	BindOnDestroy(GunController);
	puts("GunController component is Instantiated");
	printf("GunController component is Attached to Object \"%s\"\n", COMPONENT(this)->object->name);
}

ECS_API void OnDestroy(GunController)
{
	puts("GunController component is Destroyed");
}


ECS_API void OnAwake(GunController)
{
	puts("GunController awake is called");
}

ECS_API void OnStart(GunController)
{
	puts("GunController start is called");
}
