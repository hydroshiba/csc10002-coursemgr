#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float size;
    Dropbox();
    Dropbox(float x, float y, float size);
    Dropbox(Vector2 pos, float size);
    void DrawRectangle();
};

#endif //DROPBOX_H