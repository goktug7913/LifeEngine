#include "entity.h"
#include "Component/Genetics/genetics.h"
#include "Component/Movement/movement.h"
#include "Component/StateMachine/stateMachine.h"
#include "raylib.h"
#include <iostream>

Entity::Entity() {
  addComponent<Genetics>(this);
  addComponent<Movement>(this);
  addComponent<StateMachine>(this);

  // Randomize sex
  sex = GetRandomValue(0, 1) ? Sex::MALE : Sex::FEMALE;

  std::cout << "Entity created.\n";
  return;
}

Entity::~Entity() { return; }

void Entity::update(float dt) {
  for (auto &component : this->components) {
    component->update(dt);
  }
}

void Entity::draw() {
  for (auto &component : this->components) {
    component->draw();
  }

  // Debug draw
  DrawRectangle(transform->translation.x, transform->translation.y, size.x,
                size.y, sex == Sex::MALE ? BLUE : PINK);
  return;
}

template <typename T, typename... Args>
T *Entity::addComponent(Args &&...args) {
  T *component = new T(std::forward<Args>(args)...);
  components.push_back(component);
  return component;
}
