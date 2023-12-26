#include "entity.h"
#include "raylib.h"
#include <iostream>

Entity::Entity(const Transform *transform) {
  this->transform = new Transform(*transform);
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
}

template <typename T, typename... Args>
T *Entity::addComponent(Args &&...args) {
  T *component = new T(std::forward<Args>(args)...);
  components.push_back(component);
  return component;
}
