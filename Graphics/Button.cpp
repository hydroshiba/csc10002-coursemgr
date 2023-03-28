#include "Button.h"
#include "raylib.h"

Button::Button(float x, float y, float width, float height, Color color) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
}
void Button::display() {
    DrawRectangle(x, y, width, height, color);
}