#include "raylib.h"
#include "Button.h"

Button::Button(Vector2 pos, float width, float height, Color fill, Color border, Color hover, Color press) {
    this->pos = pos;

    this->width = width;
    this->height = height;
    bounds = Rectangle{pos.x, pos.y, width, height};

    this->fill = fill;
    this->border = border;
    this->hover = hover;
    this->press = press;
}

void Button::display(const Vector2 &mouse) const {
    DrawRectangle(pos.x, pos.y, width, height, border);

    if(hovering(mouse))
        DrawRectangle(pos.x + wborder, pos.y + wborder, width - wborder * 2, height - wborder * 2, hover);
    else if(pressed(mouse))
        DrawRectangle(pos.x + wborder, pos.y + wborder, width - wborder * 2, height - wborder * 2, press);
    else
        DrawRectangle(pos.x + wborder, pos.y + wborder, width - wborder * 2, height - wborder * 2, fill);
}

void Button::centerX() {
    pos.x = (GetScreenWidth() - width) / 2.0f;
}

void Button::centerY() {
    pos.y = (GetScreenHeight() - height) / 2.0f;
}

bool Button::clicked(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, bounds)) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Button::pressed(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, bounds)) return false;
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Button::hovering(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, bounds)) return false;
    return IsMouseButtonUp(MOUSE_BUTTON_LEFT);
}