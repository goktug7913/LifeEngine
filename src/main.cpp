#include "raylib.h"

struct properties
{
  int width = 1280;
  int height = 720;
  const char *title = "LifeEngine";
  int fps = 120;
};

int main(int argc, const char **argv)
{
  properties properties;
  InitWindow(properties.width, properties.height, properties.title);
  SetTargetFPS(properties.fps);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  return 0;
}
