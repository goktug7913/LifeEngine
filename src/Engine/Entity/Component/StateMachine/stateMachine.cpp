#include "stateMachine.h"

StateMachine::~StateMachine() = default;

void StateMachine::update(const float dt)
{
  if (!stateQueue.empty())
  {
    stateQueue.front()->update(dt);
  }
}
