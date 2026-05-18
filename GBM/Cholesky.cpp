/*
La clase Cholesky implementa la descomposición de Cholesky, 
una técnica matemática utilizada para generar variables 
aleatorias correlacionadas entre distintos activos financieros. 

El método descomponer() recibe una matriz cuadrada de 
tipo std::vector<std::vector<double>>, correspondiente a 
una matriz de correlación o covarianza, y calcula una 
matriz triangular inferior L tal que se cumple la relación A=LL^T

Durante este proceso, la clase verifica que la matriz sea definida positiva,
condición necesaria para que la descomposición sea válida. Posteriormente,
el método multiplicar() recibe la matriz triangular L y un vector de variables
aleatorias independientes z (std::vector<double>), realizando la multiplicación 
matricial LZ para producir variables aleatorias correlacionadas. 
   
Esto permite que los activos simulados presenten comportamientos más realistas,
reproduciendo relaciones de dependencia similares a las observadas en mercados financieros reales.
*/

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
    int n = A.size(); // Número de filas (y columnas, ya que A es cuadrada)

    // Validación básica de que A es cuadrada
    if (n == 0 || A[0].size() != n) {
        throw std::invalid_argument("La matriz debe ser cuadrada");
    }

    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));  // Matriz L inicializada con ceros
    for (int i = 0; i < n; i++) // Iteramos por cada fila de A para calcular L
    {
        for (int j = 0; j <= i; j++) // Solo calculamos la parte inferior de L (j <= i)
        {

            double suma = 0.0; // Suma de productos para calcular L[i][j]

            for (int k = 0; k < j; k++) // Suma de productos L[i][k] * L[j][k] 
            {
                suma += L[i][k] * L[j][k];
            }

            if (i == j) // Diagonal de L, calculamos la raíz cuadrada del valor ajustado de A[i][i] 
            {
                double valor = A[i][i] - suma; // Valor ajustado para la diagonal, debe ser positivo para que la raíz cuadrada sea válida

                // Validamos que el valor sea positivo para asegurar que la matriz es definida positiva
                if (valor <= 0.0) {
                    throw std::runtime_error(
                        "La matriz no es definida positiva (Cholesky falla)"
                    ); // Lanzamos una excepción si el valor no es positivo, lo que indica que la matriz no es adecuada para la descomposición de Cholesky
                }

                L[i][j] = std::sqrt(valor); // Calculamos la raíz cuadrada para la diagonal de L
            } else {
                L[i][j] = (A[i][j] - suma) / L[j][j];
            } // Para elementos fuera de la diagonal, calculamos el valor ajustado de A[i][j] y lo dividimos por L[j][j] para obtener L[i][j]
        }
    }

    return L;
}

// Multiplicación de la matriz L por el vector z
std::vector<double> Cholesky::multiplicar(
    const std::vector<std::vector<double>>& L,
    const std::vector<double>& z
) {
    int n = L.size(); // Número de filas de L (y también el tamaño del vector z)

    if (z.size() != n) {
        throw std::invalid_argument("Dimensiones incompatibles");
    } // Validamos que el tamaño del vector z sea compatible con el número de filas de L

    std::vector<double> resultado(n, 0.0); // Vector resultado inicializado con ceros

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            resultado[i] += L[i][j] * z[j];
        }// Para cada elemento del resultado, sumamos el producto de L[i][j] y z[j] para j <= i, lo que corresponde a la multiplicación de la matriz L por el vector z
    }// El resultado final es el vector que representa el producto de la matriz L por el vector z

    return resultado;
}