#ifndef RNG_H
#define RNG_H

#include <random>

class RNG {
private:
    std::mt19937 gen; // Generador de números aleatorios Mersenne Twister
    std::normal_distribution<double> dist; // Distribución normal

public:
    RNG();
    double normal(); // Genera un número aleatorio con distribución normal
};

#endif