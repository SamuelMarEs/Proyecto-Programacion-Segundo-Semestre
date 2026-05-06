#include "Cholesky.h"
#include <cmath>
#include <stdexcept>

/*
 * Descomposición de Cholesky
 * A = L * L^T
 */
std::vector<std::vector<double>> Cholesky::descomponer(
    const std::vector<std::vector<double>>& A
) {
    int n = A.size();

    // Validación básica
    if (n == 0 || A[0].size() != n) {
        throw std::invalid_argument("La matriz debe ser cuadrada");
    }

    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            double suma = 0.0;

            for (int k = 0; k < j; k++) {
                suma += L[i][k] * L[j][k];
            }

            if (i == j) {
                double valor = A[i][i] - suma;

                // 🔴 Validación clave: definida positiva
                if (valor <= 0.0) {
                    throw std::runtime_error(
                        "La matriz no es definida positiva (Cholesky falla)"
                    );
                }

                L[i][j] = std::sqrt(valor);
            } else {
                L[i][j] = (A[i][j] - suma) / L[j][j];
            }
        }
    }

    return L;
}

/*
 * Multiplicación L * z
 */
std::vector<double> Cholesky::multiplicar(
    const std::vector<std::vector<double>>& L,
    const std::vector<double>& z
) {
    int n = L.size();

    if (z.size() != n) {
        throw std::invalid_argument("Dimensiones incompatibles");
    }

    std::vector<double> resultado(n, 0.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            resultado[i] += L[i][j] * z[j];
        }
    }

    return resultado;
}