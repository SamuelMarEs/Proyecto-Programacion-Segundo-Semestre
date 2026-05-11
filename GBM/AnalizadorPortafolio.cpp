#include "AnalizadorPortafolio.h"
#include <cmath>
#include <iostream>
#include <iomanip>


AnalizadorPortafolio::AnalizadorPortafolio(const std::vector<RegistroSimulaciones>& results, double rf /*Tasa libre de riesgo*/){
    Resultados = results;
    tasaLibreRiesgo = rf;
};

AnalizadorPortafolio::~AnalizadorPortafolio(){};

std::vector<double> AnalizadorPortafolio::retornoMedio() const {
    // Regresa la media de los retornos finales de todas las simulaciones (por activo)
    std::vector<double> mean(Resultados[0].retorno().size());
    for (int i = 0; i < Resultados.size(); i++){
        std::vector<double> rendimiento;
        rendimiento = Resultados[i].retorno();
        for (int k = 0; k < mean.size(); k++){
            mean[k] += rendimiento[k]/Resultados.size();
        }
    }
    
    return mean;
};

std::vector<double> AnalizadorPortafolio::volatilidad() const {
    std::vector<double> mu = retornoMedio();                         // Media por activo
    std::vector<double> std(mu.size());                                    // Desiación estándar
    for(int i = 0; i < mu.size(); i++){
        for (int k = 0; k < Resultados.size(); k++){
            std[i] += (Resultados[k].retorno()[i] - mu[i])*(Resultados[k].vf()[i] - mu[i]);
        }
        std[i] = sqrt(std[i]/Resultados.size());
    }

    return std;                                                             // Volatilidad promedio por activo
};

std::vector<double> AnalizadorPortafolio::sharpeRatio() const {
    // Calcula y retorna el Sharpe Ratio PROMEDIO de todas las simulaciones
    std::vector<double> Rf = retornoMedio();                 // Retorno final promedio de todas las simulaciones por activo
    std::vector<double> sigma = volatilidad();               // Desviación estándar de los rendimientos (porcentuales) por activo
    std::vector<double> shRatio(sigma.size());

    for (int i = 0; i < sigma.size(); i++){
        shRatio[i] = (Rf[i] - tasaLibreRiesgo) / sigma[i];         // (retorno final - tasa libre de riesgo) / volatilidad
    }

    return shRatio;                                                 
};

//double AnalizadorPortafolio::var(double nivelConfianza) const{};

//double AnalizadorPortafolio::cvar(double nivelConfianza) const{};

void AnalizadorPortafolio::imprimirReporte() const {
    // Volatilidad anual (%) por activo
    std::vector<double> sigma = volatilidad();            // Volatilidad por activo      
    std::vector<double> vol(sigma.size());
    for (int i = 0; i < vol.size(); i++){
        vol[i] = sigma[i] * 100;  
    }                         

    // Retorno medio anual (%)
    std::vector<double> mu = retornoMedio();
    std::vector<double> retorno(mu.size());
    for (int i = 0; i < retorno.size(); i++){
        retorno[i] = mu[i] * 100;
    }
     

    // Sharpe ratio anual
    std::vector<double> s_ratio = sharpeRatio();
            

    std::cout << "===Resumen de resultados===" << std::endl;
    std::cout << "Retorno medio anual: ";
    for (int i = 0; i < retorno.size(); i++){
        std::cout << retorno[i] << "%\n";
    }
    std::cout << std::endl;
    std::cout << "Volatilidad anual: ";
    for (int i = 0; i < vol.size(); i++){
        std::cout << vol[i] << "%\n";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Sharpe ratio anual: ";
    for (int i = 0; i < s_ratio.size(); i++){
        std::cout << s_ratio[i] << "%\n";
    }
    std::cout << std::endl;
    
};