#pragma once
#include <vector>
#include "Entity/entity.h"

class Engine
{
public:
  Engine();
  ~Engine();

  void run();

  void loop();
  void handleEvents();
  void update();
  void render();

  Entity &spawnEntity(Entity &entity);
  Entity &spawnEntity(Entity &entity, const Transform&transform);

  template <typename T, typename... Args> T* spawnEntity(
    Args &&...args) {
    T *entity = new T(std::forward<Args>(args)...);
    entities.push_back(std::move(*entity));
    return &entities.back();
  }

  void destroyEntity(Entity &entity);
  int getEntityCount() const;

private:
  int width;
  int height;
  int targetFps;
  
  Camera2D camera{};
  std::vector<Entity> entities;
};
