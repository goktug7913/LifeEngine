#include "component.h"
#include "../entity.h"
#include <raylib.h>

class Movement : public Component
{
public:
  Movement(Entity *parent) : Component(parent) {}
  ~Movement();

  Vector2 target = {0, 0};
  float speed = 1.0f;
  
  void update(float dt);
  void draw(){};
  void moveTowardsTarget(Vector2 target);
  void moveInDirection(Vector2 direction);
  bool isMoving();
};
