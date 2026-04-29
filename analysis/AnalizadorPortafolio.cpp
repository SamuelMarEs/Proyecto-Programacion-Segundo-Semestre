#include "AnalizadorPortafolio.h"

AnalizadorPortafolio::AnalizadorPortafolio(const vector<double>& vf, double rf /*Tasa libre de riesgo*/){
    valoresFinales = vf;
    tasaLibreRiesgo = rf;
};

AnalizadorPortafolio::~AnalizadorPortafolio(){};

double AnalizadorPortafolio::retornoMedio() const {
    return (valoresFinales.back() - valoresFinales[0])/valoresFinales[0];
};

double AnalizadorPortafolio::volatilidad() const {

};

double AnalizadorPortafolio::sharpeRatio() const {

};

double AnalizadorPortafolio::var(double nivelConfianza) const{

};

double AnalizadorPortafolio::cvar(double nivelConfianza) const{

};

void AnalizadorPortafolio::imprimirReporte() const {

};