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
    int framesCounter = 0;
    bool mouseOnText = false;
    Vector2 dimension;

    InputBox(Vector2 pos, float sizeOfBox = text_const::size);

    void refresh();
    // void display();
};

#endif //INPUTBOX_H