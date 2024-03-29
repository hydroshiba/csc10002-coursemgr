#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "raylib.h"
#include <string>

#include "Constants.h"
#include "Text.h"
#include "Scissor.h"

class InputBox {
private:
    int frameCount;
    float textSize;
    bool selected;

    Vector2 pos;
    Vector2 size;
    Vector2 textPos;
    
    Rectangle border_bound, fill_bound, text_bound;

    void refreshText();
    void refresh();

public:
    Text defaultText, content;
    Color fill_color, border_color;
    Color hover_color, press_color;
    
    InputBox();

    InputBox(float x, float y, float width, float height,
            std::string text = "Input text here",
            Color fill = box_const::fill_color,
            Color hover = button_const::hover_color,
            Color press = button_const::press_color,
            Color border = box_const::border_color);

    InputBox(Vector2 pos, Vector2 size,
            std::string text = "Input text here",
            Color fill = box_const::fill_color,
            Color hover = button_const::hover_color,
            Color press = button_const::press_color,
            Color border = box_const::border_color);

    void render(const Vector2 &mouse) const;
    void process(const Vector2 &mouse);

    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);

    void setPos(Vector2 pos);
    void setSize(Vector2 size);

    Vector2 getPos();
    Vector2 getSize();

    void clearContent();

    void centerX();
    void centerY();

    std::string getContent();

    bool clicked(const Vector2 &mouse) const;
    bool pressed(const Vector2 &mouse) const;
    bool hovering(const Vector2 &mouse) const;
};

#endif //INPUTBOX_H