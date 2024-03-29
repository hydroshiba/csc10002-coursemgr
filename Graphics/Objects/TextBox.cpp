#include "TextBox.h"

void TextBox::refresh() {
    Vector2 size = content.size();

    bound.x = pos.x - box_const::thickness;
    bound.y = pos.y - box_const::thickness;
    
    bound.width = size.x + 2 * box_const::thickness;
    bound.height = size.y + 2 * box_const::thickness;
}

TextBox::TextBox() : content(""),
					 pos({0, 0}),
					 color_box(box_const::fill_color) { refresh(); }

TextBox::TextBox(Text content, Vector2 pos, Color color_box) : 
    content(content),
    pos(pos),
    color_box(color_box) { refresh(); }

TextBox::TextBox(std::string text, Vector2 pos, Color color_box) :
    content(text),
    pos(pos),
    color_box(color_box) { refresh(); }

TextBox::TextBox(const char *text, Vector2 pos, Color color_box) :
    content(text),
    pos(pos),
    color_box(color_box) { refresh(); }

TextBox &TextBox::operator=(Text content) {
	this->content = content;
    refresh();
    return *this;
}

TextBox &TextBox::operator=(std::string text) {
	this->content = text;
    refresh();
    return *this;
}

TextBox &TextBox::operator=(const char *text) {
    this->content = text;
    refresh();
    return *this;
}

TextBox& TextBox::operator + (const std::string& text) {
    this->content = this->content.text + text;
    refresh();
    return *this;
}

void TextBox::setContent(const std::string& content) {
    this->content.text = content;
}
void TextBox::setContent(const Text& content) {
    this->content = content;
}

std::string& TextBox::getContent() {
    return this->content.text;
}


void TextBox::setX(float x) {
    pos.x = x;
    refresh();
}

void TextBox::setY(float y) {
    pos.y = y;
    refresh();
}

void TextBox::setPos(Vector2 pos) {
    this->pos = pos;
    refresh();
}

Vector2 TextBox::getPos() {
	return pos;
}

void TextBox::centerX() {
    pos.x = (GetScreenWidth() - bound.width) / 2.0f;
    refresh();
}

void TextBox::centerY() {
    pos.y = (GetScreenHeight() - bound.height) / 2.0f;
    refresh();
}

void TextBox::setSize(float size) {
    content.font_size = size;
    refresh();
}

void TextBox::setColor(Color color) {
    content.color = color;
}

void TextBox::render() {
	DrawTextEx(content.font, content.text.c_str(), pos, content.font_size, content.space, content.color);
    DrawRectangleRoundedLines(bound, box_const::roundness, box_const::segments, box_const::thickness, color_box);
}

void TextBox::clear() {
    content.text.clear();
}