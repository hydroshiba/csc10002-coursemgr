#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
#include <cstring>

#include "raylib.h"
#include "Graphics.h"
#include "Text.h"

class TextBox {
private:
    Vector2 pos;
    Text content;
    Rectangle bound;
    Color color_box;

    void refresh();

public:
    TextBox();
    TextBox(Text content, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color);
    TextBox(std::string text, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color);
    TextBox(const char* text, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color);
    
    TextBox& operator=(Text content);
    TextBox& operator=(std::string text);
    TextBox& operator=(const char* text);

    void setX(float x);
    void setY(float y);

    void setPos(Vector2 pos);
    Vector2 getPos();

    void centerX();
    void centerY();

    void setSize(float size);
    void render();
};

#endif // TEXTBOX_H