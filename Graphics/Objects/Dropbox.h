#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"
#include "Vector.h"
#include "Button.h"

struct Dropbox {
    Vector2 position;
    Vector2 size;

    Button select;
    Vector<Button> options;
    bool clicked;
    float total_height;
    Vector<bool> chosen;
    int option_chosen_before = 0;

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
    int returnChosenButton();
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H