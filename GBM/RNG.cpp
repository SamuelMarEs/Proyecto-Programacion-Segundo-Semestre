#include "RNG.h"
#include <ctime>

RNG::RNG()
    : gen(time(nullptr)), dist(0.0, 1.0) {}

double RNG::normal() {
    return dist(gen);
}