#include "raylib.h"

void newDisplay() {
    InitWindow(800, 450, "Course Management System");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground((RAYWHITE));
            DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
        EndDrawing();
    }

    CloseWindow();
}