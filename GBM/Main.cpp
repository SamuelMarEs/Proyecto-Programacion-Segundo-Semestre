#include <iostream>
#include <vector>
#include <iomanip>
#include "Activo.h"
#include "Portafolio.h"
#include "Simulador.h"

int main() {

    int n;
    std::cout << "Numero de activos: ";
    std::cin >> n;

    std::vector<Activo> activos;
    std::vector<double> pesos(n);

    // 🔹 Lectura de activos
    for (int i = 0; i < n; i++) {

        std::string nombre;
        double precio, mu, sigma;

        std::cout << "\nActivo " << i + 1 << ":\n";

        std::cout << "Nombre: ";
        std::cin >> nombre;

        std::cout << "Precio inicial: ";
        std::cin >> precio;

        std::cout << "Mu: ";
        std::cin >> mu;

        std::cout << "Sigma: ";
        std::cin >> sigma;

        activos.emplace_back(nombre, precio, mu, sigma);
    }

    // 🔹 Pesos
    std::cout << "\nPesos (suman 1):\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Peso activo " << i + 1 << ": ";
        std::cin >> pesos[i];
    }

    // 🔹 Capital
    double capital;
    std::cout << "\nCapital total: ";
    std::cin >> capital;

    Portafolio portafolio(activos, pesos, capital);

    // 🔹 Parámetros simulación
    int numSim, steps;
    double T;

    std::cout << "\nNumero de simulaciones: ";
    std::cin >> numSim;

    std::cout << "Horizonte T: ";
    std::cin >> T;

    std::cout << "Numero de pasos: ";
    std::cin >> steps;

    // 🔹 Simulación
    SimuladorMonteCarlo simulador;
    auto resultados = simulador.simular(portafolio, numSim, T, steps);

    std::cout << std::fixed << std::setprecision(4);

    // =====================================================
    // 📈 Trayectoria completa (simulación 0)
    // =====================================================
    std::cout << "\n=== Trayectoria (simulacion 0) ===\n";

    for (int t = 0; t < resultados[0].size(); t++) {

        std::cout << "t=" << t << ": ";

        for (double p : resultados[0][t]) {
            std::cout << p << " ";
        }

        std::cout << "\n";
    }

    // =====================================================
    // 💰 Valor del portafolio en el tiempo
    // =====================================================
    auto cantidades = portafolio.calcularCantidadesIniciales();

    std::cout << "\n=== Valor del portafolio ===\n";

    for (int t = 0; t < resultados[0].size(); t++) {

        double valor = 0.0;

        for (int i = 0; i < n; i++) {
            valor += cantidades[i] * resultados[0][t][i];
        }

        std::cout << "t=" << t << ": " << valor << "\n";
    }

    return 0;
}