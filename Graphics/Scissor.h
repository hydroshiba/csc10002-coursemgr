#ifndef SCISSOR_H
#define SCISSOR_H

#include "raylib.h"
#include "Stack.h"

extern Stack<Rectangle> scissorStack;

void StartScissor(Rectangle rect);
void StartScissor(Vector2 pos, Vector2 size);
void StartScissor(float x, float y, float width, float height);

void EndScissor();

#endif