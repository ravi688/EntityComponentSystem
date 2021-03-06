#include <ecs/object.h>
#include <calltrace/calltrace.h>
#include <stdlib.h>
#include <string.h>

static bool comparer(void* object1, void* object2) { return *(object_t**)object1 == *(object_t**)object2; }


ECS_API void object_call_awake(object_t* object)
{
	LIST() list = LIST_GET_BINDED();

	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components);
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component);
			if((component->m_OnAwake != NULL) &&  (!component_is_awake_called(component)))
			{
				component->m_OnAwake(component);
				component_set_awake_called(component, true);
			}
			LIST_BIND(object->components);
		}
	}
	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_awake(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}

ECS_API void object_call_start(object_t* object)
{
	if(!object_is_active(object))
		return;

	LIST() list = LIST_GET_BINDED();
	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components);; 
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if((component->m_OnStart != NULL) && component_is_enabled(component) &&  (!component_is_start_called(component)))
			{
				component->m_OnStart(component);
				component_set_start_called(component, true);
			}
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_start(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}
ECS_API void object_call_on_pre_render(object_t* object)
{
	if(!object_is_active(object))
		return;
	LIST() list = LIST_GET_BINDED();

	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components);
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if(component_is_enabled(component) && (component->m_OnPreRender != NULL))
					component->m_OnPreRender(component);
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_on_pre_render(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}
ECS_API void object_call_on_render(object_t* object)
{
	if(!object_is_active(object))
		return;

	LIST() list = LIST_GET_BINDED();
	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components); 
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if(component_is_enabled(component) && (component->m_OnRender != NULL))
					component->m_OnRender(component);
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_on_render(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}
ECS_API void object_call_on_post_render(object_t* object)
{
	if(!object_is_active(object))
		return;

	LIST() list = LIST_GET_BINDED();
	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components); 
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if(component_is_enabled(component) && (component->m_OnPostRender != NULL))
					component->m_OnPostRender(component);
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_on_post_render(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}
ECS_API void object_call_late_update(object_t* object)
{
	if(!object_is_active(object))
		return;
	LIST() list = LIST_GET_BINDED();
	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components);
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if(component_is_enabled(component) && (component->m_OnLateUpdate != NULL))
					component->m_OnLateUpdate(component);
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_late_update(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}

ECS_API void object_call_update(object_t* object)
{
	if(!object_is_active(object))
		return;
	LIST() list = LIST_GET_BINDED();
	if(object->components != NULL)
	{
		//loop through each component
		LIST_BIND(object->components);
		component_t* component;
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			LIST_GET(i, &component); 
			if(component_is_enabled(component))
			{
				if((component->m_OnStart != NULL) &&  (!component_is_start_called(component)))
				{
					component->m_OnStart(component);
					component_set_start_called(component, true);
				}
				else if(component->m_OnUpdate != NULL)
					component->m_OnUpdate(component);
			}
			LIST_BIND(object->components);
		}
	}

	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings);
		u64 sibling_count = LIST_GET_COUNT();
		for(u64 i = 0; i < sibling_count; i++)
			object_call_update(*LIST_GET_PTR(object_t*, i));
	}
	LIST_BIND(list);
}


ECS_API void object_set_parent(object_t* object, object_t* parent)
{
	ensure_object_is_not_NULL();
	ensure_passed_value_is_object();
	if(parent == NULL)
	{
		log_err("Parent object is NULL\n");
		return;
	}
	if(!IS_OBJECT(parent))
	{
		log_err("Passed parent value's typeid %llu is not of type object_t\n", parent->id);
		return;
	}
	
	if(parent->siblings == NULL)
		parent->siblings = LIST_NEW(object_t*, 1);

	LIST() list = LIST_GET_BINDED();
	LIST_BIND(parent->siblings);
//LIST is BUFFER*
	if(BUFcontains(object, comparer))
	{
		log_wrn("object_t \"%s\" is already a child of object_t \"%s\"\n", object->name, parent->name);
		return;
	}
	LIST_ADD(&object);
	object->parent = parent;
	LIST_BIND(list);
	log_msg("object_t \"%s\" is now child of object_t \"%s\"\n", object->name, parent->name);
}

ECS_API void object_unparent(object_t* object)
{
	ensure_object_is_not_NULL();
	ensure_passed_value_is_object();

	if(object->parent == NULL)
	{
		log_wrn("object_t \"%s\" doesn't have any parent\n", object->name);
		return;
	}

	object_t* parent = object->parent;
	if(parent->siblings == NULL)
	{
		log_wrn("object_t named as \"%s\" parent  of object_t \"%s\" doesn't have childs\n", parent->name, object->name);
		return;
	}
	LIST() list = LIST_GET_BINDED();
	LIST_BIND(parent->siblings);
	if(!BUFremove(&object, comparer))
	{
		log_wrn("object_t \"%s\" parent of object_t \"%s\" doesn't contain object_t \"%s\"\n", parent->name, object->name, object->name);
		return;
	}
	object->parent = NULL;
	LIST_BIND(list);
}

ECS_API void object_destroy(object_t* object)
{
	ensure_object_is_not_NULL();
	ensure_passed_value_is_object();

	char name[24]; 
	strcpy(name, object->name);
	//first destroy childs
	LIST() _list = LIST_GET_BINDED(); 
	if(object->siblings != NULL)
	{
		LIST_BIND(object->siblings); 
		u64 sibling_count = LIST_GET_COUNT(); 
		for(u64 i = 0; i < sibling_count; i++)
			object_destroy(*LIST_GET_PTR(object_t*, i));
	}
	if(object->components != NULL)
	{
		LIST_BIND(object->components);
		for(u64 i = 0; i < LIST_GET_COUNT(); i++)
		{
			component_t* component;
			LIST_GET(i, &component);
			if(component->m_OnDestroy != NULL)
				component->m_OnDestroy(component);
			component_destroy(component);
			LIST_BIND(object->components);
		}
		LIST_DESTROY();
	}
	LIST_BIND(_list);
	free(object);
	object = NULL;
	log_msg("object_t \"%s\" is destroyed\n", name);
}

ECS_API void object_set_active(object_t* object, bool value)
{
	ensure_object_is_not_NULL();
	ensure_passed_value_is_object();
	if(value)
		object->boolean_info |= OBJECT_ACTIVE;
	else
		object->boolean_info &= (~OBJECT_ACTIVE);
}

ECS_API object_t* object_create(const char* name)
{
	object_t* object = OBJECT(malloc(sizeof(object_t)));
	strcpy(object->name, name);
	object->components = NULL;
	object->siblings = NULL;
	object->parent = NULL;
	object->id = Object_TYPE_ID;
	object->boolean_info = 0;
	object_set_active(object, true);
	log_msg("object_t named as \"%s\" is instantiated\n", object->name);
	return object;	
}

ECS_API component_t* __object_attach_component(object_t* object, u64 size_of_component, u64 type_id)
{
	ensure_object_is_not_NULL(NULL);
	ensure_passed_value_is_object(NULL);
	LIST() list = LIST_GET_BINDED();
	if(object->components == NULL)
		object->components = LIST_NEW(component_t*, 1);
	LIST_BIND(object->components);
	component_t* component = __component_new(object, size_of_component, type_id);
	LIST_ADD(&component);
	LIST_BIND(list);
	return (void*)component;
}

ECS_API component_t* __object_get_component(object_t* object, u64 type_id)
{
	ensure_object_is_not_NULL(NULL);
	ensure_passed_value_is_object(NULL);

	if(object->components == NULL)
	{
		log_wrn("object_t \"%s\" doesn't have any components\n", object->name);
		return NULL;
	}
	if((type_id & Component_TYPE_ID) != Component_TYPE_ID)
	{
		log_err("Passed type_id %llu is not of component type\n", type_id);
	 	return NULL;
	}
	
	LIST() list = LIST_GET_BINDED();
	LIST_BIND(object->components); 
	u64 count = LIST_GET_COUNT();

	component_t* component;
	for(u64 i = 0; i < count; i++)
	{
		LIST_GET(i, &component); 
		if(component->id == type_id)
		{
			LIST_BIND(list);
			return (void*)component;
		}
	}
	LIST_BIND(list);
	log_wrn("Passed component's type_id %llu is not found on the object \"%s\"\n", type_id, object->name);
	return NULL;
}
