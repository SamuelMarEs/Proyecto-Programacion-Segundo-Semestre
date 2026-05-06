#include "Activo.h"

Activo::Activo(const std::string& nombre,
               double precioInicial,
               double mu,
               double sigma)
    : nombre(nombre), precioInicial(precioInicial), mu(mu), sigma(sigma) {}

std::string Activo::getNombre() const {
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