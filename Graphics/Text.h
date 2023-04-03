#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "raylib.h"

namespace text_const {

const Font regular = LoadFont("Resources/GlgSans.ttf");
const Font bold = LoadFont("Resources/GlgBold.ttf");

const float space = 1.0f;

const Color color = RED;

}

struct Text {
	std::string text;
	int font_size;
	Font font;
	float space;
	Color color;

	Text();
	Text(std::string text, int fsize = 24, Font font = text_const::regular, float space = text_const::space, Color color = text_const::color);

	void operator=(std::string text);
	Vector2 size();
};

#endif