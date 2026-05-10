#ifndef _REGISTROSIMULACIONES_H_
#define _REGISTROSIMULACIONES_H_
#include <vector>

class RegistroSimulaciones{
private:
    std::vector<double> ValoresFinales;
    std::vector<double> rendimiento;
public:
    RegistroSimulaciones(std::vector<double> Vi, std::vector<double> Vf);
    ~RegistroSimulaciones();

    std::vector<double> retorno() const;
    std::vector<double> vf() const;
};


#endif