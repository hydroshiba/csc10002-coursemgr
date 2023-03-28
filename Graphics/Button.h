#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
class Button {
public:
    float x, y;
    float width, height;
    Color color;
    Button() {}
    Button(float x, float y, float width, float height, Color color);
    void display();
};

#endif //BUTTON_H