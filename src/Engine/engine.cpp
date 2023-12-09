#include "engine.h"
#include <iostream>
#include <raylib.h>
#include <algorithm>

#ifdef __EMSCRIPTEN__
// WASM specific includes.
#include "emscripten.h"
#endif

Engine::Engine()
{
  width = 800;
  height = 600;
  targetFps = 60;

  InitWindow(width, height, "LifeEngine");
  SetTargetFPS(targetFps);

  std::cout << "Engine initialized.\n";
}

Engine::~Engine()
{
  this->entities.clear();
  CloseWindow();

  std::cout << "Engine destroyed.\n";
}

/**
 * @brief Engine starter function.
 */
void Engine::run()
{
#ifdef __EMSCRIPTEN__
  // For WASM we give a pointer to the run function, a delay of 0, and a flag of 1 to tell it to run the main loop repeatedly.
  emscripten_set_main_loop(&loop, 0, 1);
#else

  // For native we just call the run function.
  loop();

#endif
}

void Engine::loop()
{
  while (!WindowShouldClose())
  {
    handleEvents();
    update();
    render();
  }
  // We stop the engine here.
}

void Engine::render()
{
  BeginDrawing();
  ClearBackground(RAYWHITE);

  DrawText("LifeEngine running", 10, 10, 20, BLACK);

  const char *fps = ("FPS: " + std::to_string(GetFPS())).c_str();
  DrawText(fps, width - MeasureText(fps, 20) - 10, 10, 20, BLACK);

  const char *entityCount = ("Entities: " + std::to_string(getEntityCount())).c_str();
  DrawText(entityCount, width - MeasureText(entityCount, 20) - 10, 30, 20, BLACK);

  for (auto &entity : this->entities)
  {
    entity.draw();
  }

  EndDrawing();
}

void Engine::update()
{
  float dt = GetFrameTime();

  for (auto &entity : this->entities)
  {
    entity.update(dt);
  }
}

void Engine::handleEvents()
{
  // Handle events here.
  if (IsKeyPressed(KEY_ESCAPE))
    CloseWindow();

  if (IsKeyDown(KEY_SPACE))
  {
    auto transform = Transform();
    transform.translation = Vector3{
        GetRandomValue(0, width) * 1.0f,
        GetRandomValue(0, height) * 1.0f,
        0.0f};

    spawnEntity(transform);
  }

  if (IsKeyDown(KEY_BACKSPACE))
    destroyEntity(this->entities.back());
}

Entity &Engine::spawnEntity()
{
  return this->spawnEntity(Transform());
}

Entity &Engine::spawnEntity(Transform transform)
{
  Entity entity;
  entity.transform = transform;
  this->entities.push_back(std::move(entity));
  return this->entities.back();
}

void Engine::destroyEntity(Entity &entity)
{
  auto it = std::find_if(this->entities.begin(), this->entities.end(), [&entity](const Entity &e)
                         { return &e == &entity; });
  if (it != this->entities.end())
  {
    this->entities.erase(it);
  }
}

int Engine::getEntityCount()
{
  return this->entities.size();
}
