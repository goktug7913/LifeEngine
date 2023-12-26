#include "stateMachine.h"

StateMachine::~StateMachine() = default;

void StateMachine::update(const float dt)
{
  // Execute the current state if there is one
  if (!stateQueue.empty())
  {
    stateQueue.front()->update(dt);
  }
}


