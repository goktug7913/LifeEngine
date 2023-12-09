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
  for (auto &component : this->components)
  {
    component->update(dt);
  }

  // Debug update
  transform.translation.x += 1 * dt;
  transform.translation.y += 1 * dt;

  std::cout << "Entity updated.\n";
  return;
}

void Entity::draw()
{
  for (auto &component : this->components)
  {
    component->draw();
  }

  // Debug draw
  DrawRectangle(transform.translation.x, transform.translation.y, 10, 10, RED);
  std::cout << "Entity drawn.\n";
  return;
}

template <typename T>
T *Entity::addComponent()
{
  T *component = new T();
  components.push_back(component);
  return component;
}