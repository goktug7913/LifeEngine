#include "genetics.h"
#include "../../../helpers.h"
#include <iostream>

Genetics::~Genetics() {
  std::cout << "Genetics destroyed.\n";
  return;
};

void Genetics::mutate() {
  for (int i = 0; i < DNA_SIZE; i++) {
    if (getRandomFloat(0.0f, 1.0f) < MUTATION_RATE) {
      this->dna[i] += getRandomFloat(-MUTATION_RANGE, MUTATION_RANGE);
    }
  }
}

Sex Genetics::getSex() {
  // dna 0 and 1 determines sex
  if ((dna[0] + dna[1]) / 2 > 0.5f) {
    return Sex::MALE;
  } else {
    return Sex::FEMALE;
  }
}

Size Genetics::getSize() {
  // dna 2 and 3 determines size
  Size size;
  size.x = (dna[2] + dna[3]) / 2 * 10;
  size.y = (dna[2] + dna[3]) / 2 * 10;
  return size;
}

float Genetics::getSpeed() {
  // dna 4 and 5 determines speed
  // check if dna is initialized
  if (dna.size() == 0) {
    std::cout << "dna not initialized\n";
    return 0;
  }

  return (dna[4] + dna[5]) / 2 * 10;
}