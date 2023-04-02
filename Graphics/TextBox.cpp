#include "raylib.h"
#include "TextBox.h"
#include <string>

TextBox::TextBox() {}

TextBox::TextBox(Text content, Rectangle box, Color color_text, Color color_box)
    : content(content), 
      box(box), 
      color_text(color_text), 
      color_box(color_box) {}

void TextBox::display() {
    DrawRectangleRec(box, color_box);
    DrawTextEx(content.font, content.text.c_str(), Vector2{box.x, box.y}, content.font_size, 0.5, color_text); 
    //void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
}