#include "stateMachine.h"

StateMachine::~StateMachine()
{
  return;
}

void StateMachine::update(float dt)
{
  if (!stateQueue.empty())
  {
    stateQueue.front()->update(dt);
  }
}
