#include "entity.h"
#include "Component/Genetics/genetics.h"
#include "Component/Movement/movement.h"
#include "Component/StateMachine/stateMachine.h"
#include "raylib.h"
#include <iostream>

Entity::Entity(const Transform *transform) {
  this->transform = new Transform(*transform);

  addComponent<Genetics>(this);
  addComponent<Movement>(this);
  addComponent<StateMachine>(this);

  // Randomize sex
  sex = getComponent<Genetics>()->getSex();
  size = getComponent<Genetics>()->getSize();
  color = getComponent<Genetics>()->getColor();

  std::cout << "Entity created.\n";
}

Entity::~Entity() = default;

void Entity::update(const float dt) {
  for (auto const &component : this->components) {
    component->update(dt);
  }
}

void Entity::draw() {
  for (const auto &component : this->components) {
    component->draw();
  }

  // Debug draw
  DrawRectangle(transform->translation.x, transform->translation.y, size.x,
                size.y, color);
}

template <typename T, typename... Args>
T *Entity::addComponent(Args &&...args) {
  T *component = new T(std::forward<Args>(args)...);
  components.push_back(component);
  return component;
}
