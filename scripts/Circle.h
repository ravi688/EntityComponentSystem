#pragma once

#include <ecs/component.h>

static const u64 TYPE_ID(Circle) = CREATE_COMPONENT_ID(9);

typedef struct Circle
{
	DERIVE_FROM_COMPONENT;
	float radius; 
	int divisons;
	float dangle;
	// vec3_t(float) position;
	// mesh_renderer_t* mesh_renderer; 
	// mesh_filter_t* mesh_filter;
	// material_t* material; 
	// mesh_t* mesh;
}Circle; 

