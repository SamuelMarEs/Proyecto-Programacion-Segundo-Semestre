#include "AnalizadorPortafolio.h"
#include <cmath>

using namespace std;

AnalizadorPortafolio::AnalizadorPortafolio(const vector<RegistroSimulaciones>& results, double rf /*Tasa libre de riesgo*/){
    Resultados = results;
    tasaLibreRiesgo = rf;
};

AnalizadorPortafolio::~AnalizadorPortafolio(){};

double AnalizadorPortafolio::retornoMedio() const {
    // Regresa la media de los retornos finales de todas las simulaciones
    double mean;
    for(int i = 0; i < Resultados.size(); i++){
        mean += Resultados[i].vf();
    }
    mean = mean / Resultados.size();

    return mean;
};

double AnalizadorPortafolio::volatilidad() const {
    double mu = this->retornoMedio();           // Media
    double std;                                 // Desiación estándar
    for(int i = 0; i < Resultados.size(); i++){
        std += (Resultados[i].vf() - mu)*(Resultados[i].vf() - mu);
    }
    std = sqrt(std/Resultados.size());

    return std;
};

double AnalizadorPortafolio::sharpeRatio() const {

};

//double AnalizadorPortafolio::var(double nivelConfianza) const{};

//double AnalizadorPortafolio::cvar(double nivelConfianza) const{};

void AnalizadorPortafolio::imprimirReporte() const {

};