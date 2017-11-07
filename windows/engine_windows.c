#include "../common/engine.h"

engine_t* engineInstance = NULL;

int engine_init(engine_t* hndl, int argc, char* argv[])
{
	// Init the renderer and the scene manager
	renderer_init(&hndl->renderer, argc, argv);
	scene_init(&hndl->scene);
	resources_init();
	gui_init(hndl->renderer.renderResolutionX, hndl->renderer.renderResolutionY);

	hndl->deltaTime = 0.0f;
	hndl->lastTime = 0.0f;

	engineInstance = hndl;
	return 0;
}

void engine_destroy()
{
}

void engine_windows_main_function()
{
	engine_doFrame();
	gui_doFrame();
	gui_endFrame();
	engine_endFrame();
}

int engine_doFrame()
{
	engineInstance->deltaTime = 0.016f;
	
	// Propagate frame start
	renderer_doFrame(&engineInstance->scene);
	scene_doFrame();
	
	return 0;
}

void engine_endFrame()
{
	// Propagate frame finish
	renderer_endFrame();
}