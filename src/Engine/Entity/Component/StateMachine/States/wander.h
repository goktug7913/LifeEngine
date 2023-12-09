#pragma once
#include "../../../entity.h"
#include "stateBase.h"

class Wander : public stateBase {
    public:
        Wander(Entity *owner) : stateBase(owner) {}
        void enter();
        void update(float dt);
        void exit();
    
    private:
        float timer = 3;
};