#include "Button.h"
#include "raylib.h"

Button::Button(float w, float h) {
    width = w;
    height = h;
}
void Button::display() {
    DrawRectangle((float)GetScreenWidth() / 2.0f - width / 2.0f, (float)GetScreenHeight() / 2.0f - height / 2.0f, width, height, RED);
}