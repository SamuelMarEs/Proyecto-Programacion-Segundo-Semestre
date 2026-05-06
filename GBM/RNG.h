#ifndef RNG_H
#define RNG_H

#include <random>

class RNG {
private:
    std::mt19937 gen;
    std::normal_distribution<double> dist;

public:
    RNG();
    double normal();
};

#endif