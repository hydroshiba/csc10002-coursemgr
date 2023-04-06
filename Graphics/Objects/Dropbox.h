#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"

struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float length = 25; //length of edges
    
    Vector2 p1, p2, p3;

    Dropbox();
    Dropbox(float x, float y, float length = 25);
    Dropbox(Vector2 pos, float length = 25);

    void CreateTriangle();
    void DropboxNotClicked();
    void DropboxClicked();
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H