#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

#include "Constants.h"
#include "Text.h"

class Button {
private:
    Vector2 pos;
    Vector2 size;
    Vector2 textpos;
    
    Rectangle border_bound, fill_bound, text_bound;

    void refreshText();
    void refresh();

public:
    Text label;
    Color fill_color, border_color;
    Color hover_color, press_color;

    Button();

    Button(float x, float y, float width, float height,
            std::string text = "",
            Color fill = box_const::fill_color,
            Color hover = button_const::hover_color,
            Color press = button_const::press_color,
            Color border = box_const::border_color);

    Button(Vector2 pos, Vector2 size,
            std::string text = "",
            Color fill = box_const::fill_color,
            Color hover = button_const::hover_color,
            Color press = button_const::press_color,
            Color border = box_const::border_color);

    void render(const Vector2 &mouse) const;
    
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);

    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    Vector2 getPos();
    Vector2 getSize();

    void centerX();
    void centerY();

    bool clicked(const Vector2 &mouse) const;
    bool pressed(const Vector2 &mouse) const;
    bool hovering(const Vector2 &mouse) const;
};

#endif //BUTTON_H