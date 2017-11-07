#ifndef _GUI_H_
#define _GUI_H_

#ifdef WINDOWS_BUILD
#pragma once
#endif

#include <stdint.h>
#include "vector.h"
#include "renderer.h"

void gui_init(int screenWidth, int screenHeight);
void gui_doFrame();
void gui_endFrame();

void gui_drawRect(int x, int y, int w, int h, vec4_t* color, float alpha);
void gui_drawTexture(int x, int y, vec4_t* color, texture_t* texture, float alpha);
void gui_drawText(const char* text, int x, int y, vec4_t* color, float alpha, font_t* font, float scale);

#endif // _GUI_H_