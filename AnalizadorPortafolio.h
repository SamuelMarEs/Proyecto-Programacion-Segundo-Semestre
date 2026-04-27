/*Clase Analizador Portafolio*/
#ifndef _ANALIZADORPORTAFOLIO_H_
#define _ANALIZADORPORTAFOLIO_H_

#include <vector>

using namespace std;

class AnalizadorPortafolio{
private:
    vector<double> valoresFinales;    // de todas las simulaciones
    double tasaLibreRiesgo;
public:
    AnalizadorPortafolio(const vector<double>& vf, double rf);
    ~AnalizadorPortafolio();

    double retornoMedio() const;
    double volatilidad() const;
    double sharpeRatio() const;
    double var(double nivelConfianza) const;        // ej. 0.95
    double cvar(double nivelConfianza) const;
    void imprimirReporte() const;
};



#endif