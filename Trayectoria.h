/*Clase Trayectoria*/
#ifndef _TRAYECTORIA_H_
#define _TRAYECTORIA_H_

#include "Activo.h"
#include <vector>

class Trayectoria{
private:
    vector<double> precios;
    double tiempoTotal;         // años
    int pasos;                  // discretización
public:
    Trayectoria(const Activo& a, double T, int steps, double semilla);
    ~Trayectoria();

    double getPrecioFinal() const;
    const vector<double>& getPrecios() const;

};

#endif