#pragma once //Para que unicamente se incluya este header una sola vez durante la compilación
#include <string>

class Activo {
private:
    std::string nombre;
    double precioInicial;
    double mu;      // rendimiento esperado anual
    double sigma;   // volatilidad anual

public:
    // Nombre del activo, precio inicial, rendimiento esperado anual (mu) y volatilidad anual (sigma)
    Activo(const std::string& nombre, double precioInicial, double mu, double sigma);

    const std::string& getNombre() const;
    double getPrecioInicial() const;
    double getMu() const;
    double getSigma() const;
};