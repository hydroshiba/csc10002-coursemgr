#include "Button.h"

#include <iostream>

void Button::refreshText() {
    label.font_size = 0;

    while(label.size().x * 3 < size.x * 2 && label.size().y * 3 < size.y * 2) {
        ++label.font_size;
    }

    --label.font_size;
    textPos.x = fill_bound.x + (fill_bound.width - (label.size().x)) / 2;
    textPos.y = fill_bound.y + (fill_bound.height - (label.size().y)) / 2;
}

void Button::refresh() {
    border_bound = Rectangle{pos.x, pos.y, size.x, size.y};
    
    fill_bound.x = pos.x + box_const::thickness;
    fill_bound.y = pos.y + box_const::thickness;
    
    fill_bound.width = size.x - 2 * box_const::thickness;
    fill_bound.height = size.y - 2 * box_const::thickness;

    refreshText();
}

Button::Button() :
    pos({0, 0}),
    size({box_const::width, box_const::height}),
    label(""),
    fill_color(box_const::fill_color),
    hover_color(button_const::hover_color),
    press_color(button_const::press_color),
    border_color(box_const::border_color) { refresh(); }

Button::Button(float x, float y, float width, float height, std::string text, Color fill, Color hover, Color press, Color border) :
    pos({x, y}),
    size({width, height}),
    label(text),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refresh(); }

Button::Button(Vector2 pos, Vector2 size, std::string text, Color fill, Color hover, Color press, Color border) :
    pos(pos),
    size(size),
    label(text),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refresh(); }

void Button::render(const Vector2 &mouse) const {
    Color color;

    if(hovering(mouse)) color = hover_color;
    else if(pressed(mouse)) color = press_color;
    else color = fill_color;

    DrawRectangleRounded(border_bound, box_const::roundness, box_const::segments, color);
    DrawRectangleRoundedLines(fill_bound, box_const::roundness, box_const::segments, box_const::thickness, border_color);
    DrawTextEx(label.font, label.text.c_str(), textPos, label.font_size, label.space, label.color);
}

void Button::setX(float x) {
    pos.x = x;
    refresh();
}

void Button::setY(float y) {
    pos.y = y;
    refresh();
}

void Button::setWidth(float width) {
    size.x = width;
    refresh();
}

void Button::setHeight(float height) {
    size.y = height;
    refresh();
}

void Button::setPos(Vector2 pos) {
    this->pos = pos;
    refresh();
}

void Button::setSize(Vector2 size) {
    this->size = size;
    refresh();
}

Vector2 Button::getPos() {
    return pos;
}

Vector2 Button::getSize() {
    return size;
}

void Button::centerX() {
    pos.x = (GetScreenWidth() - size.x) / 2.0f;
    refresh();
}

void Button::centerY() {
    pos.y = (GetScreenHeight() - size.y) / 2.0f;
    refresh();
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