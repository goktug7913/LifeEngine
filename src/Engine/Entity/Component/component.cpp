#include "component.h"
#include <iostream>

Component::Component(Entity *parent) {
  this->parent = parent;
  std::cout << "Component(base) created" << std::endl;
}

Component::~Component() { std::cout << "Component destroyed" << std::endl; }

void Component::update(float dt) { }

void Component::draw() { }