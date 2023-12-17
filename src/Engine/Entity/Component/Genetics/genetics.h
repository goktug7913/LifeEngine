#pragma once
#include "../../entity.h"
#include "../component.h"
#include <vector>

class Genetics : public Component {
public:
  Genetics(Entity *parent) : Component(parent) {}
  ~Genetics();

  std::vector<float> dna;

  void update(float dt){};
  void draw(){};
};
