#include "raylib.h"
#include "Text.h"

Text::Text() {
	text = "";
	font = text_const::regular;
	space = text_const::space;
	color = text_const::color;
}

Text::Text(std::string text, int fsize, Font font, float space, Color color) {
	this->text = text;
	this->font_size = fsize;
	this->font = font;
	this->space = space;
	this->color = color;
}

void Text::operator=(std::string text) {
	this->text = text;
}

Vector2 Text::size() {
	return MeasureTextEx(font, text.c_str(), font_size, 0);
}
