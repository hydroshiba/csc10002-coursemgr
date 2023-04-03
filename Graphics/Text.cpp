#include "raylib.h"
#include "Text.h"

Text::Text() : 
	text(""),
	font_size(text_const::size),
	font(LoadFontEx(text_const::font_path, 96, 0, 0)),
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

void Text::operator=(const char *text) {
	this->text = text;
}

Vector2 Text::size() {
	return MeasureTextEx(font, text.c_str(), font_size, space);
}
