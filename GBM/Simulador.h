#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include "Portafolio.h"
#include "RNG.h"

class SimuladorMonteCarlo {
private:
    RNG rng;

public:
    std::vector<std::vector<std::vector<double>>> simular(
        const Portafolio& portafolio,
        int numSimulaciones,
        double T,
        int steps
    );
};

#endif