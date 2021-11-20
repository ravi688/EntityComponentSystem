#include <ecs/scene.h>
#include <ecs/defines.h>
#include <calltrace/calltrace.h>
#include <stdlib.h>
#include <string.h>

static bool object_comparer(void* obj1, void* obj2) { return *((object_t**)obj1) == *((object_t**)obj2); }

void scene_add_object(scene_t* scene, object_t* object)
{
	ensure_scene_is_not_NULL();
	ensure_object_is_not_NULL();
	ensure_passed_value_is_object();
	if(scene->objects == NULL)
		scene->objects = LIST_NEW(object_t*, 1);
	LIST() list = LIST_GET_BINDED();
	LIST_BIND(scene->objects);
	if(BUFfind_index_of(&object, object_comparer) == BUF_INVALID_INDEX)
	{
		LIST_ADD(&object);
		log_msg("object_t \"%s\" is added to the scene_t \"%s\"\n", object->name, scene->name);
	}
	LIST_BIND(list);
}

void scene_remove_object(scene_t* scene, object_t* object)
{
	log_msg("scene_remove_object not defined\n");
}

scene_t* scene_new(char* name)
{
	scene_t* scene = (scene_t*)malloc(sizeof(scene_t)); 
	if(name == NULL)
		strcpy(scene->name, "NewScene");
	else
		strcpy(scene->name, name);
	scene->objects = NULL;
	log_msg("scene_t \"%s\" is created\n", scene->name);
	return scene;
}

void scene_clean(scene_t* scene)
{
	ensure_scene_is_not_NULL();
	if(scene->objects != NULL)
	{
		LIST() list = LIST_GET_BINDED();
		LIST_BIND(scene->objects);
		LIST_DESTROY();
		LIST_BIND(list);
		scene->objects = NULL;
	}
	log_msg("scene_t \"%s\" is cleaned\n", scene->name);
}

void scene_destroy(scene_t* scene)
{
	ensure_scene_is_not_NULL();
	char name[24];
	strcpy(name, scene->name);
	if(scene->objects != NULL)
	{
		LIST() list = LIST_GET_BINDED();
		LIST_BIND(scene->objects);
		for(int i = 0; i < LIST_GET_COUNT(); i++)
			object_destroy(*LIST_GET_PTR(object_t*, i));
		LIST_DESTROY();
		LIST_BIND(list);
		scene->objects = NULL;
	}
	free(scene);
	log_msg("scene_t \"%s\" is destroyed\n", name);
}

object_t* scene_create_object(scene_t* scene, char* name)
{
	if(scene == NULL) return NULL;
	object_t* object = object_new(name);
	if(scene->objects == NULL)
		scene->objects = LIST_NEW(object_t*, 1);
	LIST() list = LIST_GET_BINDED();
	LIST_BIND(scene->objects);
	LIST_ADD(&object);
	LIST_BIND(list);
	return object;
}