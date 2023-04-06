#include "Dropbox.h"
#include "math.h"

Dropbox::Dropbox() {}

Dropbox::Dropbox(float x, float y, float length):
    pos({x, y}),
    length(length) {}

Dropbox::Dropbox(Vector2 pos, float length):
    pos(pos),
    length(length) {}

void Dropbox::DropboxNotClicked() {
    Vector2 point1, point2, point3;
    point1 = {pos.x + length / 2, pos.y};
    point2 = {pos.x - length / 2, pos.y - length / 2};
    point3 = {pos.x - length / 2, pos.y + length / 2};
    DrawTriangle(point1, point2, point3, BLACK);
}

void Dropbox::DropboxClicked() {
    Vector2 point1, point2, point3;
    point1 = {pos.x, pos.y + length / 2};
    point2 = {pos.x + length / 2, pos.y - length / 2};
    point3 = {pos.x - length / 2, pos.y - length / 2};
    DrawTriangle(point1, point2, point3, BLACK);
}

void Dropbox::render() {
    clicked = !IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    if (clicked) DropboxNotClicked();
    else DropboxClicked();
}