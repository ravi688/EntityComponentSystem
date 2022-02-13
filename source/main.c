
#include <stdio.h>
#include <ecs/assert.h>
#include <calltrace/calltrace.h>

#include <ecs/component.h>
#include <ecs/object.h>
#include <ecs/scene_manager.h>


#include <Ammo.h>

int main(int argc, char** argv)
{
	log_msg("Hello ECS!\n");

	scene_manager_t* scene_manager = scene_manager_create();
	scene_t* scene = scene_create("NewScene");
	object_t* ball = object_create("Ball");
	scene_add_object(scene, ball);
	object_attach_component(ball, Ammo);
	scene_manager_add_active_scene(scene_manager, scene);
	while(true)
	{
		scene_manager_for_each_objects_in_all_scenes(scene_manager, object_call_update);
	}
	scene_manager_destroy(scene_manager);
	return 0;
}
