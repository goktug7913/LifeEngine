#include "movement.h"
#include <math.h>

void Movement::update(float dt)
{
  moveTowardsTarget(target);
}

void Movement::moveInDirection(Vector2 direction)
{
  parent->transform->translation.x += direction.x;
  parent->transform->translation.y += direction.y;
}

void Movement::moveTowardsTarget(Vector2 target)
{
  Vector2 direction = {0, 0};
  direction.x = target.x - parent->transform->translation.x;
  direction.y = target.y - parent->transform->translation.y;
  float length = sqrt(direction.x * direction.x + direction.y * direction.y);
  direction.x /= length;
  direction.y /= length;
  moveInDirection(direction);
}

bool Movement::isMoving()
{
  return parent->transform->translation.x != target.x || parent->transform->translation.y != target.y;
}

Movement::~Movement()
{
  return;
}
