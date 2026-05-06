#include "Portafolio.h"
#include <stdexcept>

// Portafolio (Activo, Peso)
Portafolio::Portafolio(
    const std::vector<Activo>& activos,
    const std::vector<double>& pesos)

    : activos(activos), pesos(pesos) {
    if (activos.size() != pesos.size()) {
        throw std::invalid_argument("Activos y pesos deben tener el mismo tamaño"); // Validar que el número de activos y pesos coincidan
    } 

    double suma = 0.0;
    for (double w : pesos) suma += w;

    if (std::abs(suma - 1.0) > 1e-6) {
        throw std::invalid_argument("Los pesos deben sumar 1.0"); // Validar que los pesos sumen 1.0
    }
}

const std::vector<Activo>& Portafolio::getActivos() const {
    return activos;
}

const std::vector<double>& Portafolio::getPesos() const {
    return pesos;
}

double Portafolio::calcularValor(const std::vector<double>& preciosFinales) const {

    if (preciosFinales.size() != activos.size()) {
        throw std::invalid_argument("Número de precios no coincide con activos"); // Validar que el número de precios coincida con el número de activos
    }

    double valor = 0.0;

    for (size_t i = 0; i < activos.size(); i++) {
        valor += pesos[i] * preciosFinales[i];
    }

    return valor;
}