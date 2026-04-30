#ifndef _REGISTROSIMULACIONES_H_
#define _REGISTROSIMULACIONES_H_

class RegistroSimulaciones{
private:
    double ValorFinal;
    double rendimiento;
public:
    RegistroSimulaciones(double Vi, double Vf);
    ~RegistroSimulaciones();

    double retorno() const;
    double vf() const;
};


#endif