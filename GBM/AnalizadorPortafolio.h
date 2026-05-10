/*Clase Analizador Portafolio*/
#ifndef _ANALIZADORPORTAFOLIO_H_
#define _ANALIZADORPORTAFOLIO_H_

#include "RegistroSimulaciones.h"
#include <vector>


class AnalizadorPortafolio{
private:
    std::vector<RegistroSimulaciones> Resultados;    // de todas las simulaciones
    double tasaLibreRiesgo;
public:
    AnalizadorPortafolio(const std::vector<RegistroSimulaciones>& results, double rf);
    ~AnalizadorPortafolio();

    std::vector<double> retornoMedio() const;
    std::vector<double> volatilidad() const;
    std::vector<double> sharpeRatio() const;
    //double var(double nivelConfianza) const;        // ej. 0.95
    //double cvar(double nivelConfianza) const;
    void imprimirReporte() const;
};

#endif