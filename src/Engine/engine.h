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
  Entity &spawnEntity(Entity &entity, Transform transform);
  void destroyEntity(Entity &entity);
  int getEntityCount();

private:
  int width;
  int height;
  int targetFps;
  
  Camera2D camera;
  std::vector<Entity> entities;
};
