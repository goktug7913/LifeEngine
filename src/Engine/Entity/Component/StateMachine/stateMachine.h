#pragma once
#include "../../entity.h"
#include "../component.h"
#include "States/stateBase.h"
#include "src/LifeSim/Agent/Components/StateMachine/States/wander.h" // TODO: remove this
#include <queue>

class StateMachine : public Component {
public:
  StateMachine(Entity *parent) : Component(parent) {
    // Create wander state as the first thought... TODO: this might not work
    // well for plants...
    stateQueue.push(new Wander(parent));
    stateQueue.front()->enter();
  }
  ~StateMachine();

  void update(float dt);
  void draw(){};

  std::queue<stateBase *> stateQueue;
};
