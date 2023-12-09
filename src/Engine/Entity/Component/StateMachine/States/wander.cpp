#include "wander.h"
#include <raylib.h>
#include "../../movement.h"

void Wander::enter()
{
}

void Wander::update(float dt)
{
    // If the entity is not moving, set a random direction and move
    if (!owner->getComponent<Movement>()->isMoving())
    {
        // Set a random target around self
        auto target = Vector2{
            GetRandomValue(owner->transform->translation.x - 500, 
            owner->transform->translation.x + 500),

            GetRandomValue(owner->transform->translation.y - 500, 
            owner->transform->translation.y + 500)
        };

        // Move
        owner->getComponent<Movement>()->moveTowardsTarget(target);
    }
}

void Wander::exit()
{}