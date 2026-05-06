#include "Random.h"

Random::Random()
    : gen(std::random_device{}()), dist(0.0, 1.0) {}

double Random::normal() {
    return dist(gen);
}