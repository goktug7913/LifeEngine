#pragma once
#include "../../../helpers.h"
#include "../../entity.h"
#include "../component.h"
#include <vector>

constexpr int DNA_SIZE = 10; // Must be bigger than 5
constexpr float MUTATION_RATE = 0.01f;
constexpr float MUTATION_RANGE = 0.1f;

class Genetics : public Component {
public:
  Genetics(Entity *parent) : Component(parent) {
    // Fill dna array with random values.
    for (int i = 0; i < DNA_SIZE; i++) {
      this->dna.push_back(getRandomFloat(0.0f, 1.0f));
    }
  }

  ~Genetics();

  std::vector<float> dna;

  void update(float dt){};
  void draw(){};

  void mutate();

  [[nodiscard]] Sex getSex() const;
  [[nodiscard]] Size getSize() const;
  [[nodiscard]] float getSpeed() const;
};
