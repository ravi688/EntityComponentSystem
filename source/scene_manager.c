

#include <ecs/scene_manager.h>
#include <ecs/assert.h>
#include <ecs/defines.h>
#include <calltrace/calltrace.h>
#include <stdlib.h>

static bool comparer(void* ptr1, void* ptr2)
{
	return ((*(scene_t**)ptr1) == (*(scene_t**)ptr2));
}

scene_manager_t* scene_manager = NULL;

scene_manager_t* scene_manager_init()
{
	scene_manager_t* scene_manager = (scene_manager_t*)malloc(sizeof(scene_manager_t)); 
	scene_manager->active_scenes = LIST_NEW(void*, 0);
	return scene_manager;
}

void scene_manager_for_each_objects_in_all_scenes(scene_manager_t* scene_manager, void (*function)(object_t*))
{
	if(scene_manager->active_scenes != NULL)
	{
		LIST() list  = LIST_GET_BINDED();
		LIST_BIND(scene_manager->active_scenes);
		u32 scene_count = LIST_GET_COUNT();
		u32 object_count;
		u32 component_count;
		scene_t* scene;
		for(u64 i = 0; i < scene_count; i++)
		{
			LIST_GET(i, &scene);
			if(scene->objects != NULL)
			{
				
				LIST_BIND(scene->objects);
				for(u64 j = 0; j <  LIST_GET_COUNT(); j++)
				{
					object_t* object = (*LIST_GET_PTR(object_t*, j));
					function(object);
					LIST_BIND(scene->objects);
				}
				LIST_BIND(scene_manager->active_scenes);
			}
		}
		LIST_BIND(list);	
	}
}

LIST(scene_t*) scene_manager_get_active_scene_list(scene_manager_t* scene_manager) { return scene_manager->active_scenes; }

void scene_manager_destroy(scene_manager_t* scene_manager)
{
	if(scene_manager == NULL)
		return;
	if(scene_manager->active_scenes != NULL)
	{
		LIST() list = LIST_GET_BINDED();
		LIST_BIND(scene_manager->active_scenes);
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
			scene_destroy(*LIST_GET_PTR(scene_t*, i));
		LIST_DESTROY();
		LIST_BIND(list);
		scene_manager->active_scenes = NULL;
	}
	free(scene_manager);
	scene_manager = NULL;
}

void scene_manager_add_active_scene(scene_manager_t* scene_manager, scene_t* scene)
{
	if(scene_manager == NULL)
	{
		log_err("scene_manager_t is not initialized\n");
		return;
	}
	if(scene_manager->active_scenes != NULL)
	{
		if(scene == NULL)
		{	log_err("Passed scene_t* scene is NULL\n"); return; }
		LIST() list = LIST_GET_BINDED();
		LIST_BIND(scene_manager->active_scenes);
		LIST_ADD(&scene);
		LIST_BIND(list);
	}
	else 
		log_err("scene_manager->active_scens is NULL\n");
}

void scene_manager_remove_active_scene(scene_manager_t* scene_manager, scene_t* scene)
{
	if(scene_manager == NULL)
	{
		log_err("scene_manager_t is not initialized\n");
		return;
	}
	if(scene_manager->active_scenes != NULL)
	{
		if(scene == NULL)
		{	log_err("Passed scene_t* scene is NULL\n"); return; }
		LIST() list = LIST_GET_BINDED();
		LIST_BIND(scene_manager->active_scenes);
		if(!LIST_REMOVE(&scene, comparer))
			log_err("Passed scene_t* is not added active scene\n");
		LIST_BIND(list);
	}
	else 
		log_err("scene_manager->active_scens is NULL\n");	
}
