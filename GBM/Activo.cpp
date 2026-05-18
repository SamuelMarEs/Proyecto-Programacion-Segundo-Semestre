/*
La clase Activo representa un instrumento financiero individual 
dentro del simulador de inversiones, como una acción, ETF o criptomoneda. 

Esta clase recibe cuatro variables principales: nombre de tipo std::string, 
que identifica el activo; precioInicial de tipo double, que representa 
el precio del activo al inicio de la simulación; mu de tipo double, 
correspondiente al rendimiento esperado o drift del activo; y sigma de tipo double, 
que representa la volatilidad o nivel de fluctuación esperado del precio. 

La clase almacena estos parámetros y proporciona métodos getter para 
acceder a ellos de forma segura. 

Estos datos son fundamentales para el modelo de Movimiento Browniano Geométrico,
ya que permiten calcular la evolución futura del precio del activo durante las simulaciones Monte Carlo.
*/

#include "Activo.h"

Activo::Activo(const std::string& nombre, //Nombre del activo
               double precioInicial, //Precio inicial del activo
               double mu, //Rendimiento esperado
               double sigma) //Volatilidad del activo
    : nombre(nombre), precioInicial(precioInicial), mu(mu), sigma(sigma) {} //Constructor de la clase Activo

std::string Activo::getNombre() const {
    return nombre;
}

double Activo::getPrecioInicial() const {
    return precioInicial;
}

double Activo::getMu() const {
    return mu;
}

double Activo::getSigma() const {
    return sigma;
}