#include <vector>
#include "../Entity/entity.h"

class Engine
{
public:
  Engine();
  ~Engine();

  void run();

  void handleEvents();
  void update();
  void render();

  Entity &spawnEntity();
  Entity &spawnEntity(Transform transform);
  void destroyEntity(Entity &entity);
  int getEntityCount();

private:
  int width;
  int height;
  int targetFps;

  std::vector<Entity> entities;
};
