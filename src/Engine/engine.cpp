#include "engine.h"
#include <iostream>
#include <raylib.h>
#include <algorithm>

Engine::Engine()
{
  width = 1920;
  height = 1080;
  targetFps = 120;

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

void Engine::run()
{
  // Main engine loop

  this->spawnEntity();

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
  // Render the game here.
  BeginDrawing();
  ClearBackground(RAYWHITE);

  DrawText("LifeEngine running", 10, 10, 20, BLACK);

  for (auto &entity : this->entities)
  {
    entity.draw();
  }

  EndDrawing();
}

void Engine::update()
{
  // Update the game here.
  float dt = GetFrameTime();

  for (auto &entity : this->entities)
  {
    entity.update(dt);
  }
}

void Engine::handleEvents()
{
  // Handle events here.
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
