#include "raylib.h"
#include "TextBox.h"
#include <string>

TextBox::TextBox()
    : content(Text("")), 
      box(), 
      color(BLACK)
    {}

TextBox::TextBox(Text content, Rectangle box, Color color)
    : content(content), box(box), color(color) {}

void TextBox::display() {
    DrawRectangleRec(box, BLACK);
    DrawTextEx(content.font, content.text.c_str(), Vector2{box.x, box.y}, content.font_size, 0.5, color); 
    //void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
}