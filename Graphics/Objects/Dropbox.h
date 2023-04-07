#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"
#include "Vector.h"
#include "Button.h"

struct Dropbox {
    Vector2 position;
    Vector2 size;
    std::string name;
    Button select;
    Vector<Button> options;

    Dropbox();
    void setLabel(std::string label);
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
    void setPos(Vector2 pos);
    void setSize(Vector2 sz);

    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H