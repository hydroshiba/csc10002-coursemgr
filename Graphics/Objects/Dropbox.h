#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"
#include "Text.h"
#include "Vector.h"
#include "Button.h"
struct Dropbox {
    //for triangle button
    Vector2 pos; //center of gravity
    float length; //length of edges
    Text content;
    Vector2 p1, p2, p3;
    bool clicked;

    Vector2 optionStartPos;
    Vector<Button> options;

    //init
    Dropbox();
    Dropbox(float x, float y, Text content = Text(""), float length = 25);
    Dropbox(Vector2 pos, Text content = Text(""), float length = 25);

    //opening or closing options
    void Closed();
    void Opened();
    bool mouseInsideDropbox(const Vector2 &mouse);

    //adding options
    void AddButton(Text options);

    //rendering
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H