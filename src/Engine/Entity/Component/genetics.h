#pragma once
#include "component.h"
#include <vector>
#include "../../Entity/entity.h"

class Genetics : public Component
{
  public:
    Genetics(Entity* parent) : Component(parent){}
    ~Genetics();

    std::vector<float> dna;

    void update(float dt) {};
    void draw() {};
};
