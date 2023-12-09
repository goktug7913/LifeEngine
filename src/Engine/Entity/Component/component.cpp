#include "component.h"
#include <iostream>

Component::Component(Entity *parent)
{
    this->parent = parent;
}

Component::~Component()
{
    std::cout << "Component destroyed" << std::endl;
}

void Component::update(float dt)
{
    return;
}

void Component::draw()
{
    return;
}