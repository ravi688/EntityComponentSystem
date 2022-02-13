#pragma once


#include <ecs/component.h>

static const u64 TYPE_ID(Square) = CREATE_COMPONENT_ID(8);

typedef struct Square
{
	DERIVE_FROM_COMPONENT;
	float side_length;
	// mesh_filter_t* mesh_filter; 
	// mesh_renderer_t* mesh_renderer;
	// mesh_t* mesh;
	// vec3_t(float) position;
	// material_t* material;
} Square;

