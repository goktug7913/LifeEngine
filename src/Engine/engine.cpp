#include "engine.h"
#include <iostream>
#include <raylib.h>

Engine::Engine() {
  width = 1920;
  height = 1080;
  targetFps = 120;

  InitWindow(width, height, "LifeEngine");
  SetTargetFPS(targetFps);
  
  std::cout << "Engine initialized.\n";
}

Engine::~Engine() {
  // Deinitialize the engine here.
  CloseWindow();
  std::cout << "Engine deinitialized.\n";
}

void Engine::run() {
  // Main engine loop
  while (!WindowShouldClose()) {
    handleEvents();
    update();
    render();
  }
  // We stop the engine here.
}

void Engine::render() {
  // Render the game here.
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("LifeEngine running", 10, 10, 20, BLACK);
    DrawText("Delta:" + GetFrameTime(), 10, 30, 20, BLACK);
    DrawFPS(width - 100, 10);
    DrawGrid(50,10);
    EndDrawing();
}

void Engine::update() {
  // Update the game here.
  float dt = GetFrameTime();
}

void Engine::handleEvents() {
  // Handle events here.
}
