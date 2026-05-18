#ifndef PORTAFOLIO_H
#define PORTAFOLIO_H

#include <vector>
#include "Activo.h"

class Portafolio {
private:
    std::vector<Activo> activos; // Lista de activos en el portafolio
    std::vector<double> pesos; // Pesos de cada activo en el portafolio (deben sumar 1)
    double capitalTotal; // Capital total invertido en el portafolio

public:
    Portafolio(const std::vector<Activo>& activos,
               const std::vector<double>& pesos,
               double capitalTotal); // Constructor del portafolio

    const std::vector<Activo>& getActivos() const;
    const std::vector<double>& getPesos() const;
    double getCapitalTotal() const;

    std::vector<double> calcularCantidadesIniciales() const; // Calcula la cantidad inicial de cada activo a comprar según el capital total y los pesos
};

#endif