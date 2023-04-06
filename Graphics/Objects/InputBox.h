#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "raylib.h"
#include <string>

#include "Constants.h"
#include "Text.h"

class InputBox {
public:
    Vector2 pos;
    float sizeOfBox;
    Text content = Text("", sizeOfBox);

    int framesCounter = 0;
    bool mouseOnText = false;
    Vector2 dimension;
    Rectangle inputBox;
    Font font = LoadFontEx(text_const::font_path.c_str(), 192, 0, 0);

    InputBox();
    InputBox(Vector2 pos, float sizeOfBox = text_const::size);

    void render();
};

#endif //INPUTBOX_H