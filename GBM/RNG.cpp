/*
La clase RNG (Random Number Generator) se encarga de generar 
números aleatorios con distribución normal estándar, fundamentales 
para la simulación estocástica del mercado financiero. 

Internamente utiliza un generador pseudoaleatorio std::mt19937 
y una distribución normal std::normal_distribution<double> con media 0 
y desviación estándar 1. 

La semilla del generador se inicializa usando la hora actual mediante 
time(nullptr) para garantizar resultados distintos en cada ejecución. 
El método normal() devuelve valores aleatorios de tipo double que 
representan perturbaciones aleatorias del mercado, las cuales son utilizadas
posteriormente en el modelo de Movimiento Browniano Geométrico para simular
cambios de precio de los activos financieros.
*/

#include "RNG.h"
#include <ctime> // Para obtener una semilla basada en el tiempo actual

RNG::RNG()
    : gen(time(nullptr)), dist(0.0, 1.0) {} // Inicializa el generador con una semilla basada en el tiempo actual y la distribución normal con media 0 y desviación estándar 1

double RNG::normal() {
    return dist(gen); // Genera un número aleatorio con distribución normal utilizando el generador y la distribución
}