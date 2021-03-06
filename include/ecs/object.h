#pragma once 

#include <ecs/defines.h>
#include <ecs/component.h>
#include <bufferlib/buffer.h>

#define Object_TYPE_ID ((u64)(1))

#define IS_OBJECT(object) (((object)->id & Object_TYPE_ID) == Object_TYPE_ID)

#define OBJECT(ptr) ((object_t*)(ptr))
 
#define object_attach_component(object, type) type##_OnInstantiate((type*)__object_attach_component(object, sizeof(type), type##_TYPE_ID))
#define object_remove_component(object, type) type##_OnDestroy((type*)__object_get_component(object, type##_TYPE_ID))
#define object_get_component(object, type) ((type*)__object_get_component(object, type##_TYPE_ID))

#define OBJECT_ACTIVE (1 << 7)

typedef struct object_t
{
	u64 id;
	char name[24];
	u8 boolean_info;
	LIST(component_t*) components;
	LIST(object_t*) siblings;
	object_t* parent;
} object_t;


#define object_is_active(object) ((OBJECT(object)->boolean_info & OBJECT_ACTIVE) == OBJECT_ACTIVE)

#define ensure_object_is_not_NULL(return_value)\
if(object == NULL)\
{\
	log_wrn("object_t is NULL");\
	return return_value;\
}
#define ensure_passed_value_is_object(return_value)\
if(!IS_OBJECT(object))\
{\
	log_err("Passed object's type_id %d is not of Object_TYPE_ID, object's name \"%s\"", object->id, object->name);\
	return return_value;\
}

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

ECS_API void object_call_awake(object_t* object);
ECS_API void object_call_start(object_t* object);
ECS_API void object_call_on_pre_render(object_t* object);
ECS_API void object_call_on_render(object_t* object);
ECS_API void object_call_on_post_render(object_t* object);
ECS_API void object_call_late_update(object_t* object);
ECS_API void object_call_update(object_t* object);
ECS_API object_t* object_create(const char* name);
ECS_API void object_destroy(object_t* object);
ECS_API void object_set_parent(object_t* this, object_t* parent);
ECS_API void object_unparent(object_t* this);
ECS_API void object_set_active(object_t* this, bool value);
ECS_API component_t* __object_attach_component(object_t* object, u64 sizeof_of_component, u64 type_id);
ECS_API component_t* __object_get_component(object_t* object, u64 type_id);

#ifdef __cplusplus
}
#endif // __cplusplus
