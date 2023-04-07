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
    bool clicked;
    float total_height;

    Dropbox();
    void setLabel(std::string label);
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
    void setPos(Vector2 pos);
    void setSize(Vector2 sz);

    void addNewButton(std::string label);
    void renderAllOptions(const Vector2 &mouse);
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H