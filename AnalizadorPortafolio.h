/*Clase Analizador Portafolio*/
#ifndef _ANALIZADORPORTAFOLIO_H_
#define _ANALIZADORPORTAFOLIO_H_

#include "RegistroSimulaciones.h"
#include <vector>

using namespace std;

class AnalizadorPortafolio{
private:
    vector<RegistroSimulaciones> Resultados;    // de todas las simulaciones
    double tasaLibreRiesgo;
public:
    AnalizadorPortafolio(const vector<RegistroSimulaciones>& results, double rf);
    ~AnalizadorPortafolio();

    double retornoMedio() const;
    double volatilidad() const;
    double sharpeRatio() const;
    //double var(double nivelConfianza) const;        // ej. 0.95
    //double cvar(double nivelConfianza) const;
    void imprimirReporte() const;
};

#endif