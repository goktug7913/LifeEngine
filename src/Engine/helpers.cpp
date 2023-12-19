#include "helpers.h"

float getRandomFloat(float min, float max) {
  float random = ((float)rand()) / (float)RAND_MAX;
  float range = max - min;
  return (random * range) + min;
}