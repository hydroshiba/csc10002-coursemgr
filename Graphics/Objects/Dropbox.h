#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float length = 25; //length of edges

    Dropbox();
    Dropbox(float x, float y, float length = 25);
    Dropbox(Vector2 pos, float length = 25);
    void mouseNotOnDropbox();
    void mouseOnDropbox();
    void render();
};

#endif //DROPBOX_H