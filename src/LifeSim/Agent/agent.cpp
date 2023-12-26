#include "agent.h"
#include "Component/StateMachine/stateMachine.h"
#include "Components/Genetics/genetics.h"
#include "Components/Movement/movement.h"
#include "raylib.h"
#include <iostream>

Agent::~Agent() = default;

void Agent::update(const float dt) { Entity::update(dt); }

void Agent::draw() {
  // Debug draw
  DrawRectangle(transform->translation.x, transform->translation.y, size.x,
                size.y, color);
}