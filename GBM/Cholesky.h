#ifndef CHOLESKY_H
#define CHOLESKY_H

#include <vector>

class Cholesky {
public:
    static std::vector<std::vector<double>> descomponer(
        const std::vector<std::vector<double>>& A
    ); // Descomposición de Cholesky, devuelve la matriz L tal que A = L * L^T 

    static std::vector<double> multiplicar(
        const std::vector<std::vector<double>>& L,
        const std::vector<double>& z
    ); // Multiplica la matriz L por el vector z
};

#endif