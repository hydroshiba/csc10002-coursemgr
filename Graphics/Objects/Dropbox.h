#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float length; //length of edges

    float degree = 90;

    Dropbox();
    Dropbox(float x, float y, float length = 1);
    Dropbox(Vector2 pos, float length = 1);
    void drawButton();
};

#endif //DROPBOX_H