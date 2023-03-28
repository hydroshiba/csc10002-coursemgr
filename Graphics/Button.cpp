#include "raylib.h"
#include "Button.h"

Button::Button(Vector2 pos, float width, float height, Color color) {
    this->pos = pos;
    this->width = width;
    this->height = height;

    bounds = {pos.x, pos.y, pos.x + width, pos.y + height};
    this->color = color;
}

void Button::display() const {
    DrawRectangle(pos.x, pos.y, width, height, color);
}

void Button::centerX() {
    pos.x = (GetScreenWidth() - width) / 2.0f;
}

void Button::centerY() {
    pos.y = (GetScreenHeight() - height) / 2.0f;
}

bool Button::clicked(const Vector2 &mouse) {
    if(!CheckCollisionPointRec(mouse, bounds)) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}