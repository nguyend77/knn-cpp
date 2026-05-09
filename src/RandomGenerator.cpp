#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() : rd(), gen(rd()) {}

int RandomGenerator::getInt(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
