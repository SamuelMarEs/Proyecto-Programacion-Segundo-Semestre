#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
private:
    std::string nombre;
    double precioInicial;
    double mu;
    double sigma;

public:
    Activo(const std::string& nombre,
           double precioInicial,
           double mu,
           double sigma);

    std::string getNombre() const;
    double getPrecioInicial() const;
    double getMu() const;
    double getSigma() const;
};

#endif