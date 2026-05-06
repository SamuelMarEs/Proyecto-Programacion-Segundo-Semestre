#pragma once
#include <vector>
#include "Portafolio.h"
#include "Random.h"

class SimuladorMonteCarlo {
private:
    Random rng;

public:

    /*
     * simular(...)
     * -----------
     * Entrada:
     *   portafolio → contiene activos y pesos
     *   numSimulaciones → número de escenarios
     *   T → tiempo total (años)
     *   steps → pasos de tiempo (ej. 252 días)
     */
    std::vector<double> simular(
        const Portafolio& portafolio,
        int numSimulaciones,
        double T,
        int steps
    );
};