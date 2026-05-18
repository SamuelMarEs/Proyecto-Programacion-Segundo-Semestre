#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include "Portafolio.h"
#include "RNG.h"

class SimuladorMonteCarlo {
private:
    RNG rng; // Generador de números aleatorios

public:
    std::vector<std::vector<double>> simular(
        const Portafolio& portafolio,
        double T,
        int steps
    ); // Simula la evolución del portafolio utilizando el método de Monte Carlo, devuelve una matriz con las simulaciones de los precios de los activos a lo largo del tiempo
};

#endif