/*Clase Portafolio*/
#ifndef _PORTAFOLIO_H_
#define _PORTAFOLIO_H_

#include "Activo.h"
#include <vector>

class Portafolio{
private:
    vector<Activo> activos;
    vector<double> pesos;                           // suma = 1
    vector<vector<double>> matrizCorrelacion;       
public:
    Portafolio(/* args */);
    ~Portafolio();

    double valorFInal(const vector<double>& preciosFInales) const;
    vector<double> simularValores(int numSImulaciones, double T, int steps);
};

#endif