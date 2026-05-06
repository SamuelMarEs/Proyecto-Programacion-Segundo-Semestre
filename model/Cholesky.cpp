#include "Cholesky.h"
#include <cmath>
#include <stdexcept>

std::vector<std::vector<double>> Cholesky::descomponer(
    const std::vector<std::vector<double>>& A
) {
    int n = A.size();

    // Matriz resultado (inicializada en 0)
    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            double suma = 0.0;

            // Producto acumulado
            for (int k = 0; k < j; k++) {
                suma += L[i][k] * L[j][k];
            }

            if (i == j) {
                // Elementos diagonales
                double val = A[i][i] - suma;

                // Validación: debe ser positiva
                if (val <= 0.0) {
                    throw std::runtime_error("Matriz no definida positiva");
                }

                L[i][j] = std::sqrt(val);
            }
            else {
                // Elementos fuera de la diagonal
                L[i][j] = (A[i][j] - suma) / L[j][j];
            }
        }
    }

    return L;
}

std::vector<double> Cholesky::multiplicar(
    const std::vector<std::vector<double>>& L,
    const std::vector<double>& z
) {
    int n = L.size();
    std::vector<double> resultado(n, 0.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            resultado[i] += L[i][j] * z[j];
        }
    }

    return resultado;
}