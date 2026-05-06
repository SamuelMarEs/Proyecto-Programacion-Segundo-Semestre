#include "AnalizadorPortafolio.h"
#include <cmath>
#include <iostream>
#include <iomanip>

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
        mean += Resultados[i].retorno();
    }
    mean = mean / Resultados.size();

    return mean;
};

double AnalizadorPortafolio::volatilidad() const {
    double mu = this->retornoMedio();           // Media
    double std;                                 // Desiación estándar
    for(int i = 0; i < Resultados.size(); i++){
        std += (Resultados[i].retorno() - mu)*(Resultados[i].vf() - mu);
    }
    std = sqrt(std/Resultados.size());

    return std;                                 // Volatilidad
};

double AnalizadorPortafolio::sharpeRatio() const {
    // Calcula y retorna el Sharpe Ratio PROMEDIO de todas las simulaciones
    double Rf = this->retornoMedio();           // Retorno final promedio de todas las simulaciones
    double sigma = this->volatilidad();         // Desviación estándar de los rendimientos (porcentuales)

    return (Rf - tasaLibreRiesgo) / sigma;      // (retorno final - tasa libre de riesgo) / volatilidad
};

//double AnalizadorPortafolio::var(double nivelConfianza) const{};

//double AnalizadorPortafolio::cvar(double nivelConfianza) const{};

void AnalizadorPortafolio::imprimirReporte() const {
    double vol = this->volatilidad() * 100;           // Volatilidad anual (%)
    double retorno = this->retornoMedio() * 100;      // Retorno medio anual (%)
    double s_ratio = this->sharpeRatio();             // Sharpe ratio anual

    cout << "===Resumen de resultados===" << endl;
    cout << "Retorno medio anual: " << retorno << "%" << endl;
    cout << "Volatilidad anual: " << vol << "%" << endl;
    cout << "Sharpe ratio anual: " << fixed << setprecision(2) << s_ratio << endl;
    
};