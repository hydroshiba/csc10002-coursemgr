#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float size;
    float length;

    float degree = 90;
    
    Dropbox();
    Dropbox(float x, float y, float size, float length);
    Dropbox(Vector2 pos, float size, float length);
    void drawButton();
};

#endif //DROPBOX_H