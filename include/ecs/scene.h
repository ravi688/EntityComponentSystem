#pragma once 

#include <ecs/object.h>
#include <bufferlib/buffer.h>

typedef struct scene_t
{
	char name[24];
	LIST(object_t*) objects;
} scene_t; 

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

ECS_API scene_t* scene_create(char* name);
ECS_API void scene_clean(scene_t* scene);
ECS_API void scene_destroy(scene_t* scene);

ECS_API void scene_add_object(scene_t* scene, object_t* object);
ECS_API void scene_remove_object(scene_t* scene, object_t* object);

/*Obsolete*/
ECS_API object_t* scene_create_object(scene_t* scene, char* name);

/*To be implemented*/
ECS_API scene_t* scene_merge(scene_t* scene1, scene_t* scene2);


#define ensure_scene_is_not_NULL(return_type)\
if(scene == NULL)\
{\
	log_err("scene_t is NULL");\
	return return_type;\
}

#ifdef __cplusplus
}
#endif // __cplusplus
