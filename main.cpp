#include "raylib.h"
#include "../grid.h"
#include "../blocks.cpp"

Color darkblue = {44,44,127,255};

int main() {
    InitWindow(300, 600, "Tetris 2.0");
    SetTargetFPS(60);

    Grid grid = Grid();
    OBlock block = OBlock();
    grid.print();
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkblue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
