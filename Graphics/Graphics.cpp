#include "raylib.h"

void newDisplay() {
    InitWindow(800, 450, "Fuck you!");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground((RAYWHITE));
            DrawText("Congrats! You created your second window!", 190, 200, 20, RED);
        EndDrawing();
    }

    CloseWindow();
}