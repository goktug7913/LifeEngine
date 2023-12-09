#pragma once
#include "States/stateBase.h"
#include "States/wander.h"
#include <queue>
#include "../component.h"
#include "../../entity.h"

class StateMachine : public Component
{
  public:
    StateMachine(Entity* parent) : Component(parent){
        // Create wander state
        stateQueue.push(new Wander(parent));
        //stateQueue.front()->enter();
    }
    ~StateMachine();

    void update(float dt);
    void draw() {};

    std::queue<stateBase*> stateQueue;
};
