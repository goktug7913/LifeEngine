#include "genetics.h"
#include "../../../../Engine/helpers.h"
#include "raymath.h"
#include <iostream>

Genetics::~Genetics() { std::cout << "Genetics destroyed.\n"; }

void Genetics::mutate() {
  for (int i = 0; i < DNA_SIZE; i++) {
    if (getRandomFloat(0.0f, 1.0f) < MUTATION_RATE) {
      this->dna[i] += getRandomFloat(-MUTATION_RANGE, MUTATION_RANGE);
    }
  }
}

Sex Genetics::getSex() const {
  // dna 0 and 1 determines sex
  if ((dna[0] + dna[1]) / 2 > 0.5f) {
    return Sex::MALE;
  }
  return Sex::FEMALE;
}

Size Genetics::getSize() const {
  // dna 0, 1, 2 and 3 determines size
  float val = (dna[0] + dna[1] + dna[2] + dna[3]) / 4;
  Size size = {val * 10, val * 10};
  return size;
}

float Genetics::getSpeed() const {
  // dna 4 and 5 determines speed
  // check if dna is initialized
  if (dna.empty()) {
    std::cout << "dna not initialized\n";
    return 0;
  }

  return (dna[4] + dna[5]) / 2 * 50;
}

Color Genetics::getColor() const {
  // dna 0, 1, 6 and 7 determines color
  Color color = {static_cast<unsigned char>(
                     Remap((dna[0] + dna[7]) / 2, 0.0f, 1.0f, 0.0f, 255.0f)),
                 static_cast<unsigned char>(
                     Remap((dna[1] + dna[7]) / 2, 0.0f, 1.0f, 0.0f, 255.0f)),
                 static_cast<unsigned char>(
                     Remap((dna[6] + dna[7]) / 2, 0.0f, 1.0f, 0.0f, 255.0f)),
                 255};

  return color;
}
