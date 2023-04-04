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
    // Vector2 size = MeasureTextEx(content.font, content.text.c_str(), content.font_size, content.space);
    Vector2 size = content.size();
    Rectangle bounds{pos.x - 4, pos.y - 4, size.x + 8, size.y + 8};
    // DrawRectangleLinesEx(bounds, 1, color_box);
    DrawTextEx(content.font, content.text.c_str(), pos, content.font_size, content.space, content.color);
    DrawRectangleRoundedLines(bounds, 0.1, 4, 2, color_box);
}

