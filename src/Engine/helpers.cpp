#include "helpers.h"

float getRandomFloat(float min, float max) {
  const float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
  const float range = max - min;
  return random * range + min;
}