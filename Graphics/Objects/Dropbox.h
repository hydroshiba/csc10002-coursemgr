#ifndef DROPBOX_H
#define DROPBOX_H

#include "raylib.h"
#include "Vector.h"
#include "Button.h"
class Dropbox {
private:
    Vector2 position;
    Vector2 size;
public:
    Button select;
    Vector<Button> options;
    bool clicked;
    float total_height;
    Vector<bool> chosen;
    int option_chosen_before = 0;

    Dropbox();
    //changing position and size of dropbox
    void setLabel(std::string label);
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
    void setPos(Vector2 pos);
    void setSize(Vector2 sz);

    //changing content of dropbox
    void addNewButton(std::string label);
    void renderAllOptions(const Vector2 &mouse);
    int returnChosenButton();
    void render(const Vector2 &mouse);
};

#endif //DROPBOX_H