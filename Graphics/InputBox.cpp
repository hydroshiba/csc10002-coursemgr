#include "raylib.h"
#include "InputBox.h"
#include "Constants.h"

InputBox::InputBox() {}

InputBox::InputBox(Vector2 pos, float sizeOfBox):
    pos(pos),
    sizeOfBox(sizeOfBox) {
        Text example = Text("Course Management System", sizeOfBox);
        dimension = MeasureTextEx(example.font, example.text.c_str(), example.font_size, example.space);
        inputBox = {pos.x, pos.y, dimension.x, dimension.y};
    }

void InputBox::render() {
    if (CheckCollisionPointRec(GetMousePosition(), inputBox)) mouseOnText = true;
    else mouseOnText = false;
    if (mouseOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        while (key > 0) {
            content.text.push_back((char)key);
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            content.text.pop_back();
        }
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    if (mouseOnText) framesCounter++;
    else framesCounter = 0;
    //Start of drawing
    DrawRectangleRounded(inputBox, box_const::roundness, box_const::segments, LIGHTGRAY);
    if (mouseOnText) {
        DrawRectangleRoundedLines(inputBox, box_const::roundness, box_const::segments, box_const::thickness, RED);
    }
    else {
        DrawRectangleRoundedLines(inputBox, box_const::roundness, box_const::segments, box_const::thickness, DARKGRAY);
    }
    DrawTextEx(font, content.text.c_str(), pos, sizeOfBox, text_const::space, MAROON);
    if (mouseOnText) {
        if (((framesCounter/20)%2) == 0) DrawText("_", (int)inputBox.x + 8 + MeasureText(content.text.c_str(), sizeOfBox), (int)inputBox.y + 12, sizeOfBox, MAROON);
    }
    //End of drawing
}