/*
La clase SimuladorMonteCarlo es el núcleo principal del sistema de simulación financiera,
y se encarga de modelar la evolución temporal de los precios de los activos utilizando 
Movimiento Browniano Geométrico mediante simulación Monte Carlo. 

El método simular() recibe un objeto Portafolio, un horizonte temporal T de tipo double 
y un número de pasos steps de tipo int, que determina la discretización temporal de la simulación. 
A partir de los activos contenidos en el portafolio, el simulador obtiene sus precios iniciales, 
rendimientos esperados (mu) y volatilidades (sigma). Posteriormente genera números aleatorios 
normales utilizando la clase RNG, aplica correlación entre activos mediante la descomposición de Cholesky 
y utiliza la ecuación del Movimiento Browniano Geométrico para actualizar los precios en cada instante temporal. 
Como resultado, se obtiene una matriz std::vector<std::vector<double>> denominada trayectoria, 
que contiene la evolución simulada de todos los precios de los activos a lo largo del tiempo, 
permitiendo analizar posibles escenarios futuros del comportamiento del portafolio financiero.
*/

#include "Simulador.h"
#include "Cholesky.h"
#include <cmath>

std::vector<std::vector<double>>
SimuladorMonteCarlo::simular(
    const Portafolio& portafolio,
    double T,
    int steps
) // Simula la evolución del portafolio utilizando el método de Monte Carlo, devuelve una matriz con las simulaciones de los precios de los activos a lo largo del tiempo
{
    int numSimulaciones = 1; // Puedes ajustar el número de simulaciones si quieres generar más de una trayectoria
    

    double dt = T / steps; // Paso de tiempo

    const auto& activos = portafolio.getActivos(); // Obtener los activos del portafolio
    int n = activos.size(); // Número de activos

    // Matriz de correlación (en este caso, asumimos que todos los activos son independientes, por lo que la matriz es la identidad)
    std::vector<std::vector<double>> corr(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        corr[i][i] = 1.0;
    }

    // Descomposición de Cholesky para generar variables aleatorias correlacionadas
    auto L = Cholesky::descomponer(corr);

    // Vector para almacenar los precios de los activos en cada paso de tiempo
    std::vector<double> precios(n);

    // Inicializar los precios con los precios iniciales de los activos
    for (int i = 0; i < n; i++) {
            precios[i] = activos[i].getPrecioInicial();
        }

    // Matriz para almacenar las simulaciones de los precios de los activos a lo largo del tiempo
    std::vector<std::vector<double>> trayectoria;
    trayectoria.push_back(precios); 

    // Simulación de la evolución del portafolio a lo largo del tiempo
    for (int t = 0; t < steps; t++) {

        // Generar variables aleatorias normales independientes
        std::vector<double> Z(n);
        
        // Generar variables aleatorias normales independientes
        for (int i = 0; i < n; i++) {
                Z[i] = rng.normal();
            }
        
        // Generar variables aleatorias normales correlacionadas
        std::vector<double> Z_corr = Cholesky::multiplicar(L, Z);

        // Actualizar los precios de los activos utilizando el modelo de Black-Scholes
        for (int i = 0; i < n; i++) {

            double mu = activos[i].getMu();
            double sigma = activos[i].getSigma();

            double drift = (mu - 0.5 * sigma * sigma) * dt;
            double diffusion = sigma * std::sqrt(dt) * Z_corr[i];

            precios[i] *= std::exp(drift + diffusion);
            } // Guardar los precios de los activos en esta etapa de la simulación

            trayectoria.push_back(precios); 
        }

    return trayectoria;
}