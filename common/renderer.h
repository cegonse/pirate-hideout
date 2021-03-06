#ifndef _RENDERER_H_
#define _RENDERER_H_

#ifdef WINDOWS_BUILD
#pragma once
#include <Windows.h>
#include <gl\GL.h>
#include <GL\GLU.h>
#include <GL\freeglut.h>
#elif DREAMCAST_BUILD
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <stdint.h>

#include "vector.h"
#include "builtin_meshes.h"
#include "scene.h"

typedef struct renderer
{
	int renderResolutionX;
	int renderResolutionY;
	float aspect;

	mat44_t cameraMatrix;
	mat44_t projectionMatrix;

	unsigned char wireframe;
} renderer_t;

typedef struct texture
{
	unsigned int width;
	unsigned int height;
	unsigned int nativePtr;
} texture_t;

typedef struct mesh
{
	texture_t* texture;
	float* vertices;
	float* uv;
	float* normals;
	unsigned short* indices;
	
	vec4_t colorTint;
	unsigned int count;
} mesh_t;

typedef struct glyph
{
	uint8_t id;
	float x;
	float y;
	float h;
	float w;
} glyph_t;

typedef struct font
{
	texture_t texture;
	uint8_t count;
	
	glyph_t* glyphs;
} font_t;

#ifdef WINDOWS_BUILD
void renderer_init(renderer_t* rend, int argc, char* argv[]);
#elif DREAMCAST_BUILD
void renderer_init(renderer_t* rend);
#endif

void renderer_doFrame(scene_t* scene);
void renderer_endFrame();
void renderer_destroy();

void renderer_drawMesh(const transform_t* model, const mesh_t *mesh, const scene_t* scene);
void renderer_setCamera(scene_t* scene);
void renderer_drawAxes();

mesh_t* renderer_getPrimitiveCube();

#endif // _RENDERER_H_