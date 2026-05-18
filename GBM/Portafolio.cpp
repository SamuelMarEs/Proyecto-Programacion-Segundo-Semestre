/*
La clase Portafolio modela una cartera de inversión compuesta 
por múltiples activos financieros. Recibe un vector de objetos 
Activo (std::vector<Activo>) que contiene todos los instrumentos 
financieros incluidos en la cartera, un vector de pesos (std::vector<double>) 
que indica qué proporción del capital total se asigna a cada activo,
y una variable capitalTotal de tipo double que representa 
el dinero total invertido. 

La clase valida que exista un peso correspondiente
para cada activo y posteriormente calcula cuántas unidades de cada instrumento
pueden adquirirse inicialmente utilizando la relación entre el capital asignado
y el precio inicial de cada activo. Como resultado, el portafolio permite 
organizar la distribución de capital y preparar la estructura necesaria para
ejecutar simulaciones financieras sobre múltiples activos simultáneamente.
*/

#include "Portafolio.h"
#include <stdexcept>

Portafolio::Portafolio(const std::vector<Activo>& activos,
                       const std::vector<double>& pesos,
                       double capitalTotal) // Constructor del portafolio

    : activos(activos), pesos(pesos), capitalTotal(capitalTotal) {

    if (activos.size() != pesos.size()) {
        throw std::invalid_argument("Activos y pesos no coinciden");
    } // Verificar que cada activo tenga un peso asignado
}

const std::vector<Activo>& Portafolio::getActivos() const {
    return activos;
}

const std::vector<double>& Portafolio::getPesos() const {
    return pesos;
}

double Portafolio::getCapitalTotal() const {
    return capitalTotal;
}

std::vector<double> Portafolio::calcularCantidadesIniciales() const {
    int n = activos.size();
    std::vector<double> cantidades(n); // Vector para almacenar la cantidad inicial de cada activo a comprar

    for (int i = 0; i < n; i++) {
        double inversion = capitalTotal * pesos[i];
        cantidades[i] = inversion / activos[i].getPrecioInicial();
    } // Calcular la cantidad inicial de cada activo a comprar según el capital total y los pesos

    return cantidades; // Retornar el vector con las cantidades iniciales de cada activo a comprar
}