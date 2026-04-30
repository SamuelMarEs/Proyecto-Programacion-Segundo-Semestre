#include "RegistroSimulaciones.h"

RegistroSimulaciones::RegistroSimulaciones(double Vf){
    ValorFinal = Vf;
};

RegistroSimulaciones::~RegistroSimulaciones(){};

double RegistroSimulaciones::retorno(double Vi) const {
    return (ValorFinal/Vi)-1;
};

double RegistroSimulaciones::vf() const {
    return ValorFinal;
};