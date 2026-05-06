#include "RNG.h"

RNG::RNG() : gen(42), dist(0.0, 1.0) {}

double RNG::normal() {
    return dist(gen);
}