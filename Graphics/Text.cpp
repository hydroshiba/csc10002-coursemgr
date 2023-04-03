#include "raylib.h"
#include "Text.h"

#include <cassert>
#include <iostream>

Text::Text() : 
	text(""),
	font_size(text_const::size),
	font(text_const::regular),
	space(text_const::space),
	color(text_const::color) {}

Text::Text(std::string text, float fsize, Font font, float space, Color color) : 
	text(text),
	font_size(fsize),
	font(font),
	space(space),
	color(color) {}

Text::Text(const char* text, float fsize, Font font, float space, Color color) :
	text(text),
	font_size(fsize),
	font(font),
	space(space),
	color(color) {}

void Text::operator=(std::string text) {
	this->text = text;
}

Vector2 Text::size() {
	Font newFont = GetFontDefault();
	font = newFont;
	
	Vector2 box = MeasureTextEx(font, text.c_str(), font_size, 2);
	return box;
}