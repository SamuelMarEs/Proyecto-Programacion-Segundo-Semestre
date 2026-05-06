#pragma once
#include <vector>

class Cholesky {
public:
    static std::vector<std::vector<double>> descomponer(
        const std::vector<std::vector<double>>& A
    );

    static std::vector<double> multiplicar(
        const std::vector<std::vector<double>>& L,
        const std::vector<double>& z
    );
};