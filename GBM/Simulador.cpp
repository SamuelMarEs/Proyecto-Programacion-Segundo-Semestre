#include "Simulador.h"
#include "Cholesky.h"
#include <cmath>

std::vector<std::vector<double>>
SimuladorMonteCarlo::simular(
    const Portafolio& portafolio,
    double T,
    int steps
) {
    int numSimulaciones = 1;
    

    double dt = T / steps;

    const auto& activos = portafolio.getActivos();
    int n = activos.size();

    // 🔹 Matriz de correlación identidad (puedes cambiarla después)
    std::vector<std::vector<double>> corr(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        corr[i][i] = 1.0;
    }

    auto L = Cholesky::descomponer(corr);

    std::vector<double> precios(n);

    // Inicializar precios
    for (int i = 0; i < n; i++) {
            precios[i] = activos[i].getPrecioInicial();
        }

    std::vector<std::vector<double>> trayectoria;
    trayectoria.push_back(precios); // t = 0


    for (int t = 0; t < steps; t++) {

        std::vector<double> Z(n);
        for (int i = 0; i < n; i++) {
                Z[i] = rng.normal();
            }

        std::vector<double> Z_corr = Cholesky::multiplicar(L, Z);

        for (int i = 0; i < n; i++) {

            double mu = activos[i].getMu();
            double sigma = activos[i].getSigma();

            double drift = (mu - 0.5 * sigma * sigma) * dt;
            double diffusion = sigma * std::sqrt(dt) * Z_corr[i];

            precios[i] *= std::exp(drift + diffusion);
            }

            trayectoria.push_back(precios);
        }

    return trayectoria;
}