#include "../common/engine.h"


int main(int argc, char **argv)
{
	// Start the game engine
	engine_t engine;

	if (engine_init(&engine) < 0)
	{
		debug_error("[main.c] Couldn't start game engine");
	}
	else
	{
		engine.renderer.wireframe = 0;

		engine.scene.cameraFov = 45.0f;
		engine.scene.drawGizmos = 1;

		engine.scene.backgroundColor.m[0] = 0.f;
		engine.scene.backgroundColor.m[1] = 0.f;
		engine.scene.backgroundColor.m[2] = 0.f;
		
		engine.scene.cameraPosition.m[0] = 30.0f;
		engine.scene.cameraPosition.m[1] = 45.0f;
		engine.scene.cameraPosition.m[2] = 30.0f;

		engine.scene.cameraDirection.m[0] = 0.0f;
		engine.scene.cameraDirection.m[1] = 0.0f;
		engine.scene.cameraDirection.m[2] = 0.0f;
		
		while (!engine_doFrame())
		{
			
			gui_doFrame();
			gui_endFrame();
			engine_endFrame();
		}

		engine_destroy();
	}

	return 0;
}