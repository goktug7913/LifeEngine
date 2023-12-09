#pragma once
#include "../../../entity.h"

class stateBase
{
  public:
    stateBase(Entity *owner) : owner(owner) {}
    virtual void enter() = 0;
    virtual void update(float dt) = 0;
    virtual void exit() = 0;

  // protected:
    Entity *owner;
};
