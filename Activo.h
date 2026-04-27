/*Clase Activo*/
#ifndef _ACTIVO_H_
#define _ACTIVO_H_

#include <string>

using namespace std;

class Activo{
private:
    string nombre;
    double precioInicial;
    double mu;
    double sigma;
public:
    Activo(/* args */);
    ~Activo();

    double getPrecioInicial() const;
    double getMu() const;
    double getSigma() const;
};

#endif