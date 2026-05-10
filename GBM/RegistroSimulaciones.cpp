#include "RegistroSimulaciones.h"

RegistroSimulaciones::RegistroSimulaciones(std::vector<double> Vi, std::vector<double> Vf){
    ValoresFinales = Vf;
    for (int i = 0; i < Vf.size(); i++){
        rendimiento.push_back((Vf[i]-Vi[i])/Vi[i]);
    }
    
};

RegistroSimulaciones::~RegistroSimulaciones(){};

std::vector<double> RegistroSimulaciones::retorno() const {
    return rendimiento;
};

std::vector<double> RegistroSimulaciones::vf() const {
    return ValoresFinales;
};