#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

class Button {
private:
    Rectangle bounds;
    bool pressed;

public:
    Vector2 pos;
    float width, height;
    
    Color color;

    Button() {}
    Button(Vector2 pos, float width, float height, Color color);

    void display() const;
    void centerX();
    void centerY();

    bool clicked(const Vector2 &mouse);
};

#endif //BUTTON_H