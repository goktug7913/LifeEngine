#pragma once

class Entity;

class Component
{
public:
    Component(Entity* parent); 
    virtual ~Component() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
    
    Entity* parent;
};
