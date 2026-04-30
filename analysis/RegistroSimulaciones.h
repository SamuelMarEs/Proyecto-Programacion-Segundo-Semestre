#ifndef _REGISTROSIMULACIONES_H_
#define _REGISTROSIMULACIONES_H_

class RegistroSimulaciones{
private:
    double ValorFinal;
public:
    RegistroSimulaciones(double Vf);
    ~RegistroSimulaciones();

    double retorno(double Vi) const;
    double vf() const;
};


#endif