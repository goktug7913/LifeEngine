#include "entity.h"
#include <iostream>
#include "Component/genetics.h"
#include "Component/movement.h"
#include "Component/StateMachine/stateMachine.h"
#include "raylib.h"

Entity::Entity()
{
  addComponent<Genetics>(this);
  addComponent<Movement>(this);
  addComponent<StateMachine>(this);


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
}

void Entity::draw()
{
  for (auto &component : this->components)
  {
    component->draw();
  }

  // Debug draw
  DrawRectangle(transform->translation.x, transform->translation.y, 10, 10, RED);
  return;
}

template <typename T, typename... Args>
T* Entity::addComponent(Args&&... args)
{
  T* component = new T(std::forward<Args>(args)...);
  components.push_back(component);
  return component;
}


