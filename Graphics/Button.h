#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include "Text.h"

namespace button_color {

const Color fill = RAYWHITE;
const Color border = GRAY;

const Color hover = SKYBLUE;
const Color press = BLUE;

}

const float wborder = 2;

class Button {
private:
    Vector2 pos;
    Vector2 size;
    Vector2 textpos;
    
    Rectangle border_bound, fill_bound, text_bound;

    void refreshText();
    void refreshBound();

public:
    Text label;
    Color fill_color, border_color;
    Color hover_color, press_color;

    Button();

    Button(float x, float y, float width, float height,
            std::string text = "",
            Color fill = button_color::fill,
            Color hover = button_color::hover,
            Color press = button_color::press,
            Color border = button_color::border);

    Button(Vector2 pos, Vector2 size,
            std::string text = "",
            Color fill = button_color::fill,
            Color hover = button_color::hover,
            Color press = button_color::press,
            Color border = button_color::border);

    void display(const Vector2 &mouse) const;
    
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);

    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    void centerX();
    void centerY();

    bool clicked(const Vector2 &mouse) const;
    bool pressed(const Vector2 &mouse) const;
    bool hovering(const Vector2 &mouse) const;
};

#endif //BUTTON_H