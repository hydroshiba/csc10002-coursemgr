#include "Dropbox.h"
#include "math.h"
#include <iostream>

Dropbox::Dropbox() {}

void Dropbox::setLabel(std::string label) {
    select.label = label;
}

void Dropbox::setX(float x) {
    position.x = x;
    select.setX(x);
}

void Dropbox::setY(float y) {
    position.y = y;
    select.setY(y);
}

void Dropbox::setWidth(float width) {
    size.x = width;
    select.setWidth(width);
}

void Dropbox::setHeight(float height) {
    size.y = height;
    select.setHeight(height);
}

void Dropbox::setPos(Vector2 pos) {
    position = pos;
    select.setPos(pos);
}

void Dropbox::setSize(Vector2 sz) {
    size = sz;
    select.setSize(sz);
}

void Dropbox::render(const Vector2 &mouse) {
    select.render(mouse);
}
