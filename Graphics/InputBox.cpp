#include "raylib.h"
#include "InputBox.h"
#include "Constants.h"

InputBox::InputBox(Vector2 pos, float sizeOfBox):
    pos(pos),
    sizeOfBox(sizeOfBox) {
        Text example = Text("Course Management System", sizeOfBox);
        dimension = MeasureTextEx(example.font, example.text.c_str(), example.font_size, example.space);
    }

void InputBox::refresh() {
    DrawRectangleLinesEx({pos.x, pos.y, dimension.x, dimension.y}, 1, RED);
}