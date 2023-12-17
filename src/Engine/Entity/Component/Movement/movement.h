#include "../../entity.h"
#include "../component.h"
#include <raylib.h>

class Movement : public Component {
public:
  Movement(Entity *parent) : Component(parent) {}
  ~Movement();

  Vector2 target = {0, 0};
  float speed = 20.0f;

  void update(float dt);
  void draw(){};
  void moveTowardsTarget(Vector2 target, float dt);
  bool isMoving();
};
