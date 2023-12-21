#pragma once
#include "../../../entity.h"
#include <raylib.h>
#include "stateBase.h"

class Wander : public stateBase {
    public:
        Wander(Entity *owner) : stateBase(owner) {}
        void enter();
        void update(float dt);
        void exit();
        static Vector2 GetRandomPositionAround(Vector2 position, float radius);
    
    private:
        float elapsed = 0.0f;
        float timer = 3.0f;
        Vector2 target;
};
