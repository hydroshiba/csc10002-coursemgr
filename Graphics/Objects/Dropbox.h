#ifndef DROPBOX_H
#define DROPBOX_H

#include <cmath>

#include "raylib.h"
#include "Vector.h"

#include "Option.h"
#include "Equilateral.h"
#include "Scrollbar.h"

class DropBox {
private:
    float textSize;
    bool selected;
    int curIndex;
    Option current;
    Scrollbar bar;

    Vector2 pos;
    Vector2 size;

    Vector<Option> options;

public:
    float roundness = box_const::roundness;
    Color fill_color = box_const::fill_color, border_color = box_const::border_color;
    Color hover_color = button_const::hover_color, press_color = button_const::press_color;
    Color text_color = text_const::color;

    Equilateral arrow;

    DropBox();
    void refresh();

    void setLabel(std::string label);
    void setX(float x);
    void setY(float y);

    void setWidth(float width);
    void setHeight(float height);
    
    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    void add(std::string label);
    int getSelected();

    void render(const Vector2 &mouse);
    bool process(const Vector2 &mouse);
};

#endif //DROPBOX_H