#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"
#include "Text.h"
struct Dropbox {
    //triangle is placed based on the center of gravity
    Vector2 pos;
    float length; //length of edges
    Text content;

    Vector2 p1, p2, p3;
    float degree = 90;

    Dropbox();
    Dropbox(float x, float y, Text content = Text(""), float length = 25);
    Dropbox(Vector2 pos, Text content = Text(""), float length = 25);

    void RaiseTriangle();
    void DropTriangle();
    bool mouseInsideDropbox(const Vector2 &mouse);
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H