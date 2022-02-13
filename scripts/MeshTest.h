#pragma once

#include <engine/engine.h>

static const u64 TYPE_ID(MeshTest) = CREATE_COMPONENT_ID(7);


typedef struct MeshTest
{
	DERIVE_FROM_COMPONENT;
	// mesh_t* mesh;
	// object_t* child;
	float width;
	float height;
	// scene_t* scene;
	// material_t* material;
	// mesh_renderer_t* mesh_renderer; 
	// mesh_filter_t* mesh_filter;
} MeshTest;


