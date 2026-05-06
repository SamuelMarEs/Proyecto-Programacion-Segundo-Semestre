#include "Simulador.h"
#include "Cholesky.h"
#include <cmath>

/*
 * Implementación del motor de simulación Monte Carlo
 *
 * Flujo:
 * 1. Para cada simulación:
 *      - inicializar precios
 *      - simular evolución en el tiempo
 *      - calcular valor del portafolio
 *      - guardar resultado
 */
std::vector<double> SimuladorMonteCarlo::simular(
    const Portafolio& portafolio,
    int numSimulaciones,
    double T,
    int steps
) {
    std::vector<double> resultados;

    // Tamaño de paso temporal
    double dt = T / steps;

    const auto& activos = portafolio.getActivos();
    int n = activos.size();

    /*
     * MATRIZ DE CORRELACIÓN
     * ---------------------
     * Debe ser:
     * - tamaño n x n
     * - simétrica
     * - diagonal = 1
     */
    std::vector<std::vector<double>> corr = {
        {1.0, 0.8, 0.2},
        {0.8, 1.0, 0.3},
        {0.2, 0.3, 1.0}
    };

    // Descomposición de Cholesky (solo una vez)
    auto L = Cholesky::descomponer(corr);

    /*
     * LOOP MONTE CARLO
     */
    for (int sim = 0; sim < numSimulaciones; sim++) {

        // Precios iniciales
        std::vector<double> precios(n);
        for (int i = 0; i < n; i++) {
            precios[i] = activos[i].getPrecioInicial();
        }

        /*
         * EVOLUCIÓN TEMPORAL
         */
        for (int t = 0; t < steps; t++) {

            // 1. Generar normales independientes
            std::vector<double> Z(n);
            for (int i = 0; i < n; i++) {
                Z[i] = rng.normal();
            }

            // 2. Aplicar correlación
            std::vector<double> Z_corr = Cholesky::multiplicar(L, Z);

            // 3. Actualizar cada activo (GBM)
            for (int i = 0; i < n; i++) {

                double mu = activos[i].getMu();
                double sigma = activos[i].getSigma();

                // Parte determinista (drift)
                double drift = (mu - 0.5 * sigma * sigma) * dt;

                // Parte aleatoria (diffusion)
                double diffusion = sigma * std::sqrt(dt) * Z_corr[i];

                // Actualización del precio
                precios[i] *= std::exp(drift + diffusion);
            }
        }

        // Valor final del portafolio
        double valorFinal = portafolio.calcularValor(precios);

        resultados.push_back(valorFinal);
    }

    return resultados;
}