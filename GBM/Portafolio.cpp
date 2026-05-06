#include "Portafolio.h"
#include <stdexcept>

Portafolio::Portafolio(const std::vector<Activo>& activos,
                       const std::vector<double>& pesos,
                       double capitalTotal)
    : activos(activos), pesos(pesos), capitalTotal(capitalTotal) {

    if (activos.size() != pesos.size()) {
        throw std::invalid_argument("Activos y pesos no coinciden");
    }
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
    std::vector<double> cantidades(n);

    for (int i = 0; i < n; i++) {
        double inversion = capitalTotal * pesos[i];
        cantidades[i] = inversion / activos[i].getPrecioInicial();
    }

    return cantidades;
}