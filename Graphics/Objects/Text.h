#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "raylib.h"

#include "Constants.h"

class Text {
public:
	std::string text;
	float font_size;
	float space;
	
	Font font;
	Color color;

	Text();
	Text(const char* text, float fsize = text_const::size, Font font = LoadFontEx(text_const::font_path, 192, 0, 0), float space = text_const::space, Color color = text_const::color);
	Text(std::string text, float fsize = text_const::size, Font font = LoadFontEx(text_const::font_path, 192, 0, 0), float space = text_const::space, Color color = text_const::color);

	void operator=(std::string text);
	void operator=(const char* text);
	Vector2 size();
};

#endif