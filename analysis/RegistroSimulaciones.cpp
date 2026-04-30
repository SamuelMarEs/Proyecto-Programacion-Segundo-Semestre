#include "RegistroSimulaciones.h"

RegistroSimulaciones::RegistroSimulaciones(double Vi, double Vf){
    ValorFinal = Vf;
    rendimiento = (ValorFinal/Vi)-1;
};

RegistroSimulaciones::~RegistroSimulaciones(){};

double RegistroSimulaciones::retorno() const {
    return rendimiento;
};

double RegistroSimulaciones::vf() const {
    return ValorFinal;
};