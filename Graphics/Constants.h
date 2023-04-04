#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstring>
#include "raylib.h"

namespace text_const {

const char font_path[] = "Graphics/Resources/GoogleSans.ttf";
const char bold_path[] = "Graphics/Resources/GoogleSans.ttf";

const float space = 0;
const float size = 24;
const Color color = BLACK;

}

namespace box_const {

const float width = 50;
const float height = 10;
const float thickness = 1.5;

const float roundness = 0.07;
const float segments = 2;

const Color fill_color = RAYWHITE;
const Color border_color = GRAY;

}

namespace button_const {

const Color hover_color = SKYBLUE;
const Color press_color = BLUE;

}

#endif