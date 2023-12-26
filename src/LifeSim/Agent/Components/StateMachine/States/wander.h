#pragma once
#include "../../../../../Engine/Entity/entity.h"
#include "../../../../Engine/Entity/Component/StateMachine/States/stateBase.h"
#include <raylib.h>
class Wander : public stateBase {
public:
  Wander(Entity *owner) : stateBase(owner) {}
  void enter();
  void update(float dt);
  void exit();
  static Vector2 GetRandomPositionAround(Vector2 position, float radius);

private:
  float elapsed = 0.0f;
  float timer = 3.0f;
  Vector2 target;
};
