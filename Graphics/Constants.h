#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstring>
#include <string>
#include "raylib.h"

namespace app_const {

const int width = 1280;
const int height = 720;
const int fps = 60;

const std::string title = "Course Management System";
const std::string path = GetApplicationDirectory();

}

namespace box_const {

const float width = 50;
const float height = 10;
const float thickness = 2;

const float roundness = 0.07;
const float segments = 2;

const Color fill_color = RAYWHITE;
const Color border_color = GRAY;

}

namespace button_const {

const Color hover_color = SKYBLUE;
const Color press_color = BLUE;

}

namespace text_const {

const std::string font_path = app_const::path + "/Graphics/Assets/GoogleSans.ttf";
const std::string bold_path = app_const::path + "/Graphics/Assets/GoogleBold.ttf";

const float space = 0;
const float size = 24;
const Color color = BLACK;

const float padding = 10;

}

#endif