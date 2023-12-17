#include "movement.h"
#include "raylib.h"
#include "raymath.h"

void Movement::update(float dt)
{
  moveTowardsTarget(target, dt);
}

void Movement::moveTowardsTarget(Vector2 target, float dt)
{
  auto position = parent->transform->translation;
  // Get the direction to the target
  auto direction = Vector2({target.x - position.x, target.y - position.y});
  // Normalize the direction
  auto normalizedDirection = Vector2Normalize(direction);
  // Move towards the target
  auto movement = Vector2Scale(normalizedDirection, speed * dt);
  // Update the position
  parent->transform->translation = Vector3({position.x + movement.x, position.y + movement.y, 0});
}

bool Movement::isMoving()
{
  return parent->transform->translation.x != target.x || parent->transform->translation.y != target.y;
}

Movement::~Movement()
{
  return;
}
