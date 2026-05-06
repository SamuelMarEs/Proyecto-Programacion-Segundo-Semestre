#include "Activo.h"

// Nombre del activo, precio inicial, rendimiento esperado anual (mu) y volatilidad anual (sigma)
Activo::Activo(const std::string& nombre, double precioInicial, double mu, double sigma)
    : nombre(nombre), precioInicial(precioInicial), mu(mu), sigma(sigma) {}

const std::string& Activo::getNombre() const {
    return nombre;
}

double Activo::getPrecioInicial() const {
    return precioInicial;
}

double Activo::getMu() const {
    return mu;
}

double Activo::getSigma() const {
    return sigma;
}