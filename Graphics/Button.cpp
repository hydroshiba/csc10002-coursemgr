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
    fill_bound = Rectangle{pos.x + wborder, pos.y + wborder, size.x - 2 * wborder, size.y - 2 * wborder};
    refreshText();
}

Button::Button() {
    pos = {0, 0};
    size = {20, 10};
    
    label = "";

    fill_color = button_color::fill;
    border_color = button_color::border;
    hover_color = button_color::hover;
    press_color = button_color::press;

    refreshBound();
}

Button::Button(float x, float y, float width, float height, std::string text, Color fill, Color hover, Color press, Color border) {
	this->pos = {x, y};
    this->size = {width, height};

    refreshBound();

    this->fill_color = fill;
    this->hover_color = hover;
    this->press_color = press;
    this->border_color = border;

    this->label = text;
}

Button::Button(Vector2 pos, Vector2 size, std::string text, Color fill, Color hover, Color press, Color border) {
	this->pos = pos;
    this->size = size;

    refreshBound();

    this->fill_color = fill;
    this->hover_color = hover;
    this->press_color = press;
    this->border_color = border;

    this->label = text;
}

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