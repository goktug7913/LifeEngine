#include "raylib.h"
#include <iostream>
#include <random>
#include <vector>

constexpr int gridSize = 60;
constexpr float gridSpacing = 0.75f;
constexpr int nborRadius = 2;

class LifeSimulation {
private:
    std::vector<std::vector<std::vector<bool>>> grid;
    float accumulatedTime;
    float updateInterval;

public:
    LifeSimulation() : grid(gridSize, std::vector<std::vector<bool>>(gridSize, std::vector<bool>(gridSize, false))), 
                       accumulatedTime(0.0f), updateInterval(0.1f) {
        InitGrid();
    }

    void InitGrid() {
        for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                for (int z = 0; z < gridSize; z++) {
                    grid[x][y][z] = rand() % 100 < 10;
                }
            }
        }
    }

    int CountLiveNeighbors(int x, int y, int z, int radius) {
      int count = 0;
      for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
          for (int dz = -radius; dz <= radius; dz++) {
            int nx = (x + dx + gridSize) % gridSize;
            int ny = (y + dy + gridSize) % gridSize;
            int nz = (z + dz + gridSize) % gridSize;
            count += grid[nx][ny][nz];
          }
        }
      }
      return count;
    }

    void Update(float deltaTime) {
        accumulatedTime += deltaTime;
        if (accumulatedTime < updateInterval) return;
        accumulatedTime -= updateInterval;

        auto newGrid = grid;
        for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                for (int z = 0; z < gridSize; z++) {
                    int liveNeighbors = CountLiveNeighbors(x, y, z, nborRadius);
                    if (grid[x][y][z]) {
                        if (liveNeighbors < 13 || liveNeighbors > 20) {
                            newGrid[x][y][z] = false;
                        }
                    } else {
                        if (liveNeighbors == 12) {
                            newGrid[x][y][z] = true;
                        }
                    }
                }
            }
        }
        grid = newGrid;
    }

    void Draw() {
        for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                for (int z = 0; z < gridSize; z++) {
                    if (grid[x][y][z]) {
                        DrawCube((Vector3){ x * gridSpacing, y * gridSpacing, z * gridSpacing }, 
                                 gridSpacing, gridSpacing, gridSpacing, (Color){ 50, 200, 0, 100 });
                    }
                }
            }
        }
    }

    void SetUpdateInterval(float interval) {
        updateInterval = interval;
    }

    float GetUpdateInterval() const {
        return updateInterval;
    }
};

struct properties
{
  int width = 1280;
  int height = 720;
  const char *title = "LifeEngine";
  int fpsTarget = 120;
};

properties props;
Camera3D camera;

int main(int argc, const char **argv)
{
  camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 60.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  LifeSimulation simulation;

  InitWindow(props.width, props.height, props.title);
  SetTargetFPS(props.fpsTarget);

  while (!WindowShouldClose())
  {
    float deltaTime = GetFrameTime();

    simulation.Update(deltaTime);

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);
    simulation.Draw();
    EndMode3D();
    EndDrawing();

    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    if (IsKeyDown(KEY_ESCAPE)) CloseWindow();
    if (IsKeyDown(KEY_R)) simulation.InitGrid();

    // Control simulation speed
    if (IsKeyPressed(KEY_UP)) simulation.SetUpdateInterval(simulation.GetUpdateInterval() * 0.5f);
    if (IsKeyPressed(KEY_DOWN)) simulation.SetUpdateInterval(simulation.GetUpdateInterval() * 2.0f);
  }

  CloseWindow();
  return 0;
}