#include "Ammo.h"
#include <stdio.h>
#include <ecs/object.h>

ECS_API void OnInstantiate(Ammo)
{
	BindOnAwake(Ammo);
	BindOnStart(Ammo); 
	BindOnDestroy(Ammo);
	BindOnUpdate(Ammo);
	puts("Ammo component is Instantiated");
	printf("Ammo component is Attached to Object \"%s\"\n", COMPONENT(this)->object->name);
}

ECS_API void OnDestroy(Ammo)
{

	puts("Ammo component is Destroyed");
}

ECS_API void OnAwake(Ammo)
{
	puts("Ammo awake is called");
}

ECS_API void OnStart(Ammo)
{
	puts("Ammo start is called");
}

ECS_API void OnUpdate(Ammo)
{
	puts("Ammo Updated is called");
}
