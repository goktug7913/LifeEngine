#include "entity.h"
#include <iostream>

Entity::Entity()
{
  std::cout << "Entity created.\n";
  return;
}

Entity::~Entity()
{
  return;
}

void Entity::update(float dt)
{
  std::cout << "Entity updated.\n";
  return;
}

void Entity::draw()
{
  std::cout << "Entity drawn.\n";
  return;
}
