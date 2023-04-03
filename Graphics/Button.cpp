#include "raylib.h"
#include "Button.h"

#include <iostream>

void Button::refreshText() {
    label.font_size = 25;

    // while(label.size().x < size.x && label.size().y < size.y) {
    //     ++label.font_size;
    // }

    // --label.font_size;
    textpos.x = fill_bound.x + (label.size().x) / 2;
    textpos.y = fill_bound.y + (label.size().y) / 2;

    //textpos = pos;
}

void Button::refreshBound() {
    border_bound = Rectangle{pos.x, pos.y, size.x, size.y};
    
    fill_bound.x = pos.x + button_const::border_width;
    fill_bound.y = pos.y + button_const::border_width;
    
    fill_bound.width = size.x - 2 * button_const::border_width;
    fill_bound.height = size.y - 2 * button_const::border_width;

    refreshText();
}

Button::Button() :
    pos({0, 0}),
    size({button_const::width, button_const::height}),
    label(""),
    fill_color(button_const::fill_color),
    hover_color(button_const::hover_color),
    press_color(button_const::press_color),
    border_color(button_const::border_color) { refreshBound(); }

Button::Button(float x, float y, float width, float height, std::string text, Color fill, Color hover, Color press, Color border) :
    pos({x, y}),
    size({width, height}),
    label(text),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refreshBound(); }

Button::Button(Vector2 pos, Vector2 size, std::string text, Color fill, Color hover, Color press, Color border) :
    pos(pos),
    size(size),
    label(text),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refreshBound(); }

void Button::display(const Vector2 &mouse) const {
    DrawRectangleRec(border_bound, border_color);
    Color color;

    if(hovering(mouse)) color = hover_color;
    else if(pressed(mouse)) color = press_color;
    else color = fill_color;

    DrawRectangleRec(fill_bound, color);
    DrawTextEx(label.font, label.text.c_str(), textpos, label.font_size, 2, label.color);
}

void Button::setX(float x) {
    pos.x = x;
    refreshBound();
}

void Button::setY(float y) {
    pos.y = y;
    refreshBound();
}

void Button::setWidth(float width) {
    size.x = width;
    refreshBound();
}

void Button::setHeight(float height) {
    size.y = height;
    refreshBound();
}

void Button::setPos(Vector2 pos) {
    this->pos = pos;
    refreshBound();
}

void Button::setSize(Vector2 size) {
    this->size = size;
    refreshBound();
}

void Button::centerX() {
    pos.x = (GetScreenWidth() - size.x) / 2.0f;
    refreshBound();
}

void Button::centerY() {
    pos.y = (GetScreenHeight() - size.y) / 2.0f;
    refreshBound();
}

bool Button::clicked(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Button::pressed(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Button::hovering(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonUp(MOUSE_BUTTON_LEFT);
}