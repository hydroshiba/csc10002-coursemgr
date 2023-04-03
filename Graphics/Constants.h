#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"

namespace text_const {
	const Font regular = GetFontDefault();
	const Font bold = GetFontDefault();
	
	const float space = 2;
	const float size = 24;
	const Color color = BLACK;
}

namespace button_const {
	const float width = 50;
	const float height = 10;
	const float border_width = 2;

	const Color fill_color = RAYWHITE;
	const Color border_color = GRAY;

	const Color hover_color = SKYBLUE;
	const Color press_color = BLUE;
}

#endif