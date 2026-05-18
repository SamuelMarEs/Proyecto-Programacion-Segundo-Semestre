#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
private:
    std::string nombre; //Nombre del activo
    double precioInicial;  //Precio inicial del activo
    double mu; //Rendimiento esperado
    double sigma; //Volatilidad del activo

public:
    Activo(const std::string& nombre, //Nombre del activo
           double precioInicial, //Precio inicial del activo
           double mu, //Rendimiento esperado
           double sigma); //Volatilidad del activo

    std::string getNombre() const;
    double getPrecioInicial() const;
    double getMu() const;
    double getSigma() const;
};

#endif