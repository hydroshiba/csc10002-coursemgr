#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float length; //length of edges
    
    Vector2 p1, p2, p3;
    float degree = 90;

    Dropbox();
    Dropbox(float x, float y, float length = 25);
    Dropbox(Vector2 pos, float length = 25);

    void RaiseTriangle();
    void DropTriangle();
    bool mouseInsideDropbox(const Vector2 &mouse);
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H