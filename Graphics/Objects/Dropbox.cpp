#include "Dropbox.h"
#include "math.h"

Dropbox::Dropbox() {}

Dropbox::Dropbox(float x, float y, float size, float length):
    pos({x, y}),
    size(size),
    length(length) {}

Dropbox::Dropbox(Vector2 pos, float size, float length):
    pos(pos),
    size(size),
    length(length) {}

void Dropbox::drawButton() {
    float x = pos.x;
    float y = pos.y;
    Vector2 point1 = {x + (length * sqrt(3.0f) / 3), y};
    Vector2 point2 = {x - (length * sqrt(3.0f) / 6), y - (length / 2)};
    Vector2 point3 = {x - (length * sqrt(3.0f) / 6), y + (length / 2)};
    DrawTriangle(point1, point2, point3, BLACK);
}