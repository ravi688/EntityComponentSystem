#pragma once


#include <ecs/scene.h>
#include <bufferlib/buffer.h>
#include <stdlib.h>


typedef struct scene_manager_t scene_manager_t;


typedef struct scene_manager_t 
{
	LIST(scene_t*) active_scenes;
} scene_manager_t; 

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

ECS_API scene_manager_t* scene_manager_create();
ECS_API void scene_manager_destroy(scene_manager_t* scene_manager);
ECS_API void scene_manager_add_active_scene(scene_manager_t* scene_manager, scene_t* scene);
ECS_API LIST(scene_t*) scene_manager_get_active_scene_list(scene_manager_t* scene_manager); 
ECS_API void scene_manager_remove_active_scene(scene_manager_t* scene_manager, scene_t* scene);

ECS_API void scene_manager_for_each_objects_in_all_scenes(scene_manager_t* scene_manager, void (*function)(object_t*));

#define scene_manager_find_component_of_type(scene_manager, type) ((type*)__scene_manager_find_component_of_type(scene_manager, TYPE_ID(type)))
ECS_API component_t* __scene_manager_find_component_of_type(scene_manager_t* scene_manager, u64 type_id);

#ifdef __cplusplus
}
#endif // __cplusplus
