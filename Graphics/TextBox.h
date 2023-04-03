#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "raylib.h"
#include "Text.h"
#include <string>
class TextBox {
private:
    Vector2 pos;
    Text content;
    Color color_box;
public:
    TextBox();
    TextBox(Vector2 pos, Text content, Color color_box = BLACK);
    void display();
};

#endif // TEXTBOX_H