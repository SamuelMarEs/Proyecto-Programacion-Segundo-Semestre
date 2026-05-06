#ifndef PORTAFOLIO_H
#define PORTAFOLIO_H

#include <vector>
#include "Activo.h"

class Portafolio {
private:
    std::vector<Activo> activos;
    std::vector<double> pesos;
    double capitalTotal;

public:
    Portafolio(const std::vector<Activo>& activos,
               const std::vector<double>& pesos,
               double capitalTotal);

    const std::vector<Activo>& getActivos() const;
    const std::vector<double>& getPesos() const;
    double getCapitalTotal() const;

    std::vector<double> calcularCantidadesIniciales() const;
};

#endif