#include "raylib.h"
#include <iostream>
#include <random>

constexpr int gridSize = 60;
constexpr float gridSpacing = 0.75f;
constexpr int nborRadius = 2;
struct properties
{
  int width = 1280;
  int height = 720;
  const char *title = "LifeEngine";
  int fpsTarget = 120;
};

properties props;
Camera3D camera;

int CountLiveNeighbors(bool grid[gridSize][gridSize][gridSize], int x, int y, int z, int radius)
{
  int count = 0;
  for (int dx = -radius; dx <= radius; dx++)
  {
    for (int dy = -radius; dy <= radius; dy++)
    {
      for (int dz = -radius; dz <= radius; dz++)
      {
        if (dx == 0 && dy == 0 && dz == 0)
          continue;
        int nx = (x + dx + gridSize) % gridSize;
        int ny = (y + dy + gridSize) % gridSize;
        int nz = (z + dz + gridSize) % gridSize;
        if (grid[nx][ny][nz])
          count++;
      }
    }
  }
  return count;
}

void InitGrid(bool grid[gridSize][gridSize][gridSize]) {
  for (int x = 0; x < gridSize; x++) {
    for (int y = 0; y < gridSize; y++) {
      for (int z = 0; z < gridSize; z++) {
        grid[x][y][z] = rand() % 100 < 10;
      }
    }
  }
}

int main(int argc, const char **argv)
{
  camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  // 3D Life Grid
  bool grid[gridSize][gridSize][gridSize];
  InitGrid(grid);

  // Print the grid
  for (int x = 0; x < gridSize; x++)
  {
    for (int y = 0; y < gridSize; y++)
    {
      for (int z = 0; z < gridSize; z++)
      {
        std::cout << grid[x][y][z] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  InitWindow(props.width, props.height, props.title);
  SetTargetFPS(props.fpsTarget);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);
    for (int x = 0; x < gridSize; x++)
    {
      for (int y = 0; y < gridSize; y++)
      {
        for (int z = 0; z < gridSize; z++)
        {
          if (grid[x][y][z])
            DrawCube((Vector3){ x * gridSpacing, y * gridSpacing, z * gridSpacing }, gridSpacing, gridSpacing, gridSpacing, (Color){ 50, 200, 0, 100 });
        }
      }
    }
    EndMode3D();
    EndDrawing();
    // Update state
    for (int x = 0; x < gridSize; x++)
    {
      for (int y = 0; y < gridSize; y++)
      {
        for (int z = 0; z < gridSize; z++)
        {
          int liveNeighbors = CountLiveNeighbors(grid, x, y, z, nborRadius);
          if (grid[x][y][z]) {
            // Cell is currently alive
            if (liveNeighbors < 13 || liveNeighbors > 20) {
              grid[x][y][z] = false; // Cell dies
            }
          } else {
            // Cell is currently dead
            if (liveNeighbors == 12) {
              grid[x][y][z] = true; // Cell becomes alive
            }
          }
        }
      }
    }
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    if (IsKeyDown(KEY_ESCAPE)) CloseWindow();
    if (IsKeyDown(KEY_R)) InitGrid(grid);
  }

  CloseWindow();
  return 0;
}