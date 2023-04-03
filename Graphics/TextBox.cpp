#include "raylib.h"
#include "TextBox.h"
#include <string>
#include <cstring>
#include <iostream>
TextBox::TextBox() {}

TextBox::TextBox(Vector2 pos, Text content, Color color_box) 
    : pos(pos),
      content(content),
      color_box(color_box) {}

void TextBox::display() {
    Vector2 size = MeasureTextEx(content.font, content.text.c_str(), content.font_size, content.space);
    Rectangle bounds{pos.x - 2, pos.y - 2, size.x + 4, size.y + 4};
    DrawRectangleRec(bounds, color_box);
    DrawTextEx(content.font, content.text.c_str(), pos, content.font_size, content.space, content.color);
}