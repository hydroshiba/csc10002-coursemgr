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

void TextBox::centerX() {
    pos.x = (GetScreenWidth() - bound.width) / 2.0f;
    refresh();
}

void TextBox::centerY() {
    pos.y = (GetScreenHeight() - bound.height) / 2.0f;
    refresh();
}

void TextBox::display() {
    DrawTextEx(content.font, content.text.c_str(), pos, content.font_size, content.space, content.color);
    DrawRectangleRoundedLines(bound, box_const::roundness, box_const::segments, box_const::thickness, color_box);
}