#pragma once
#include <vector>
#include "Activo.h"

class Portafolio {
private:
    std::vector<Activo> activos;
    std::vector<double> pesos;

public:
    Portafolio(
        const std::vector<Activo>& activos,
        const std::vector<double>& pesos);

    const std::vector<Activo>& getActivos() const;
    const std::vector<double>& getPesos() const;

    // Calcular valor del portafolio
    double calcularValor(const std::vector<double>& preciosFinales) const;
};