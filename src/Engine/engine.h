#include <vector>
#include "../Entity/entity.h"

class Engine {
public:
  Engine();
  ~Engine();
  
  void run();

  void handleEvents();
  void update();
  void render();

  Entity& spawnEntity(); // TODO: For now we just spawn the base class. We need to make this generic.
  void destroyEntity(Entity& entity);

private:
  int width;
  int height;
  int targetFps;

  std::vector<Entity> entities;
};
