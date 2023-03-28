#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
class Button {
public:
    float width;
    float height;
    Button(float w, float h);
    void display();
};

#endif //BUTTON_H