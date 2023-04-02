#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "raylib.h"
#include "Text.h"
#include <string>
class TextBox {
private:
    Text content;
    Rectangle box;
    Color color;
public:
    TextBox();
    TextBox(Text content, Rectangle box, Color color);
    void display();
};

#endif // TEXTBOX_H