#include "wander.h"
#include "../../Movement/movement.h"

void Wander::enter() {
  // Set a random target around self
  target = GetRandomPositionAround(
      {owner->transform->translation.x, owner->transform->translation.y}, 100);

  timer = GetRandomValue(3, 10) * 1.0f;

  owner->getComponent<Movement>()->target = target;
}

void Wander::update(float dt) {
  elapsed += dt;
  if (elapsed >= timer) {
    // Set a random target around self
    target = GetRandomPositionAround(
        {owner->transform->translation.x, owner->transform->translation.y},
        100);

    elapsed = 0.0f;
    timer = GetRandomValue(3, 10) * 1.0f;

    // Move
    owner->getComponent<Movement>()->target = target;
  }
}

void Wander::exit() {}

Vector2 Wander::GetRandomPositionAround(Vector2 position, float radius) {
  return Vector2{
      GetRandomValue(position.x - radius, position.x + radius) * 1.0f,
      GetRandomValue(position.y - radius, position.y + radius) * 1.0f};
}
