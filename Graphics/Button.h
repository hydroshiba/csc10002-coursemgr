#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

namespace button_color {

const Color fill = SKYBLUE;
const Color border = GRAY;

const Color hover = BLUE;
const Color clicked = DARKBLUE;

}

const float wborder = 2;

class Button {
private:
    Vector2 pos = Vector2{0, 0};
    float width = 20, height = 10;

    Color fill = button_color::fill, border = button_color::border;
    Color hover = button_color::hover, press = button_color::clicked;

    Rectangle bounds = Rectangle{pos.x, pos.y, width, height};

public:
    Button() {}
    Button(Vector2 pos, float width, float height,
            Color fill = button_color::fill,
            Color border = button_color::border,
            Color hover = button_color::hover,
            Color press = button_color::clicked);

    void display(const Vector2 &mouse) const;
    void centerX();
    void centerY();

    bool clicked(const Vector2 &mouse) const;
    bool pressed(const Vector2 &mouse) const;
    bool hovering(const Vector2 &mouse) const;
};

#endif //BUTTON_H