#include "Dropbox.h"
#include "math.h"
#include <iostream>

Dropbox::Dropbox() {}

Dropbox::Dropbox(float x, float y, float length):
    pos({x, y}),
    length(length) {}

Dropbox::Dropbox(Vector2 pos, float length):
    pos(pos),
    length(length) {}

void Dropbox::RaiseTriangle() {
    p1 = {pos.x + length / 2, pos.y};
    p2 = {pos.x - length / 2, pos.y - length / 2};
    p3 = {pos.x - length / 2, pos.y + length / 2};
}

void Dropbox::DropTriangle() {
    p1 = {pos.x, pos.y + length / 2};
    p2 = {pos.x + length / 2, pos.y - length / 2};
    p3 = {pos.x - length / 2, pos.y - length / 2};
}

bool Dropbox::mouseInsideDropbox(const Vector2 &mouse) {
    return CheckCollisionPointTriangle(mouse, p1, p2, p3);
}

void Dropbox::render(const Vector2 &mouse) {
    //process
    
    //draw
    if (degree == 180) DropTriangle();
    else RaiseTriangle();
    DrawTriangle(p1, p2, p3, BLACK);
}