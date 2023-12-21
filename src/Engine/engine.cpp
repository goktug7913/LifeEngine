#include "engine.h"
#include "Engine/Entity/entity.h"
#include <algorithm>
#include <iostream>
#include <raylib.h>
#include <raymath.h>

#ifdef __EMSCRIPTEN__
// WASM specific includes.
#include "emscripten.h"
#endif

Engine::Engine() {
  width = 1600;
  height = 900;
  targetFps = 120;

  InitWindow(width, height, "LifeEngine");
  SetTargetFPS(targetFps);

  camera.zoom = 1.0f;
  camera.rotation = 0.0f;
  camera.offset = Vector2({0.0f, 0.0f});
  camera.target = (Vector2){0.0f, 0.0f};

  std::cout << "Engine initialized.\n";
}

Engine::~Engine() {
  this->entities.clear();
  CloseWindow();

  std::cout << "Engine destroyed.\n";
}

/**
 * @brief Engine starter function.
 */
void Engine::run() {
#ifdef __EMSCRIPTEN__
  // For WASM we give a pointer to the run function, a delay of 0, and a flag of
  // 1 to tell it to run the main loop repeatedly.
  emscripten_set_main_loop(&loop, 0, 1);
#else

  // For native we just call the run function.
  loop();

#endif
}

void Engine::loop() {
  while (!WindowShouldClose()) {
    handleEvents();
    update();
    render();
  }
  // We stop the engine here.
}

void Engine::render() {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  BeginMode2D(camera);

  for (auto &entity : this->entities) {
    entity.draw();
  }

  EndMode2D();

  // UI Rendering is done after the 2D mode is ended.
  // This is so that the UI is not world space.

  DrawText("LifeEngine running", 10, 10, 40, BLACK);

  const char *fps = ("FPS: " + std::to_string(GetFPS())).c_str();
  DrawText(fps, width - MeasureText(fps, 40) - 10, 10, 40, BLACK);

  const char *entityCount =
      ("Entities: " + std::to_string(getEntityCount())).c_str();
  DrawText(entityCount, width - MeasureText(entityCount, 40) - 10, 50, 40,
           BLACK);

  EndDrawing();
}

void Engine::update() {
  const float dt = GetFrameTime();

  for (auto &entity : this->entities) {
    entity.update(dt);
  }
}

void Engine::handleEvents() {
  if (IsKeyPressed(KEY_ESCAPE))
    CloseWindow();

  if (IsKeyDown(KEY_SPACE)) {
    for (auto i = 0; i < 5; i++) {
      auto transform = new Transform;
      transform->translation = Vector3{GetRandomValue(0, width) * 1.0f,
                                      GetRandomValue(0, height) * 1.0f, 0.0f};

      // whoa?
      spawnEntity<Entity>(transform);
    }
  }

  if (IsKeyDown(KEY_BACKSPACE))
    destroyEntity(this->entities.back());

  if (IsKeyDown(KEY_W)) {
    camera.offset = Vector2Add(camera.offset, Vector2{0.0f, 1.0f});
  }

  if (IsKeyDown(KEY_A)) {
    camera.offset = Vector2Add(camera.offset, Vector2{1.0f, 0.0f});
  }

  if (IsKeyDown(KEY_S)) {
    camera.offset = Vector2Add(camera.offset, Vector2{0.0f, -1.0f});
  }

  if (IsKeyDown(KEY_D)) {
    camera.offset = Vector2Add(camera.offset, Vector2{-1.0f, 0.0f});
  }
}

Entity &Engine::spawnEntity(Entity &entity) {
  return this->spawnEntity(entity, Transform());
}

Entity &Engine::spawnEntity(Entity &entity, const Transform& transform) {
  entity.transform = new Transform(transform);
  this->entities.push_back(std::move(entity));
  return this->entities.back();
}

void Engine::destroyEntity(Entity &entity) {
  if (const auto it = std::ranges::find_if(this->entities,
                                           [&entity](const Entity &e) { return &e == &entity; }); it != this->entities.end()) {
    this->entities.erase(it);
  }
}

int Engine::getEntityCount() const { return this->entities.size(); }
