#include "raylib.h"
#include "Engine/engine.h"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

void frame() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("LifeEngine running with Raylib, built with Meson.", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

int main(int argc, const char **argv) {
    Engine engine;
    
    InitWindow(800, 450, "Raylib + Meson + C/C++");

    SetTargetFPS(60);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(&frame, 0, 1);
#else
    while(!WindowShouldClose()) {
        frame();
    }
#endif
    CloseWindow();

    return 0;
}
