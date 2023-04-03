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
    float width = MeasureText(content.text.c_str(), content.font_size);
    Rectangle bounds{pos.x * 0.98, pos.y * 0.98, width * 0.93, width / 5.9 * 0.93};
    DrawRectangleRec(bounds, color_box);
    DrawTextEx(content.font, content.text.c_str(), pos, content.font_size, content.space, content.color);
}