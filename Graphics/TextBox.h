#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "raylib.h"
#include "Text.h"
#include <string>
class TextBox {
private:
    Text content;
    Rectangle box;
    Color color_text;
    Color color_box;
public:
    TextBox();
    TextBox(Text content, Rectangle box, Color color_text = RED, Color color_box = WHITE);
    void display();
};

#endif // TEXTBOX_H