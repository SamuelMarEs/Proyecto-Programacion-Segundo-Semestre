#include "RegistroSimulaciones.h"

/*
Constructor
Guarda el valor final y calcula el retorno total de un cada activo en base al valor inicial
*/
RegistroSimulaciones::RegistroSimulaciones(std::vector<double> Vi, std::vector<double> Vf){
    ValoresFinales = Vf;
    for (int i = 0; i < Vf.size(); i++){
        rendimiento.push_back((Vf[i]-Vi[i])/Vi[i]);
    }
    
};

RegistroSimulaciones::~RegistroSimulaciones(){};

// Devuele el rendimiento de los activos
std::vector<double> RegistroSimulaciones::retorno() const {
    return rendimiento;
};

// Devuelve los valores finales de los activo
std::vector<double> RegistroSimulaciones::vf() const {
    return ValoresFinales;
};