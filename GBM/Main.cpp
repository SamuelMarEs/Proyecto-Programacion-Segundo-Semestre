#include <iostream>
#include <vector>
#include <iomanip>
#include "Activo.h"
#include "Portafolio.h"
#include "Simulador.h"
#include "RegistroSimulaciones.h"
#include "AnalizadorPortafolio.h"


using namespace std;

int main() {

    int n = 3;
    /*std::cout << "Numero de activos: ";
    std::cin >> n;*/

    vector<Activo> activos;
    vector<double> pesos(n);

    Activo Gold("Oro", 2000, 0.04, 0.15);
    Activo SP500("SP500", 7600, 0.06, 0.15);
    Activo NVIDIA("NVIDIA", 300, 0.2, 0.35);
    Activo Dolar("Dolar", 17.5, 0.01, 0.08);
    Activo Euro("Euro", 20.29, 0.05, 0.12);
    Activo Petro("Petroleo", 3000, 0.15, 0.4);
    // 🔹 Lectura de activos
    for (int i = 0; i < n; i++){
        cout << "==========Elija activos en los que desea invertir y precione ENTER==========" << endl;
        cout << "(1) Oro, $2000" << endl;
        cout << "(2) SP500, $7600" << endl;
        cout << "(3) NVIDIA, $300" << endl;
        cout << "(4) Dolar, $17.5" << endl;
        cout << "(5) Euro, $20.29" << endl;
        cout << "(6) Petroleo, $3000" << endl;
        int opcion;
        cin >> opcion;

        if (opcion == 1){
            activos.emplace_back(Gold);
        } else if (opcion == 2){
            activos.emplace_back(SP500);
        } else if (opcion == 3){
            activos.emplace_back(NVIDIA);
        } else if (opcion == 4){
            activos.emplace_back(Dolar);
        } else if (opcion == 5){
            activos.emplace_back(Euro);
        } else if (opcion == 6){
            activos.emplace_back(Petro);
        } else {
            cout << "Opcion no válida, elija otro activo porfavor" << endl;
            i -= 1;
        }
            
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

    // Número de simulaciones
    int numSim;
    std::cout << "Ingrese número de simulaciones: ";
    std::cin >> numSim;

    Portafolio portafolio(activos, pesos, capital);

    // 🔹 Parámetros simulación
    int steps = 252;
    double T = 1;

    /*
    std::cout << "\nNumero de simulaciones: ";
    std::cin >> numSim;

    std::cout << "Horizonte T: ";
    std::cin >> T;

    std::cout << "Numero de pasos: ";
    std::cin >> steps; */

    // 🔹 Simulación
    
    //SimuladorMonteCarlo simulador;
    //auto resultados = simulador.simular(portafolio, T, steps);

    std::cout << std::fixed << std::setprecision(4);
    
    
    // Simulaciones:
    std::vector<vector<double>> promediosDiarios(steps, std::vector<double>(n, 0));
    std::vector<RegistroSimulaciones> simulaciones;
    SimuladorMonteCarlo simulador;
    for (int i = 0; i < numSim; i++){
        auto trayectoria = simulador.simular(portafolio, T, steps);

        // Guardar un vector con el promedio diario de todas las simulaciones
        for (int t = 0; t < steps; t++){
            for (int k = 0; k < n; k++){
                promediosDiarios[t][k] += trayectoria[t][k]/numSim;
            }
        }

        simulaciones.push_back(RegistroSimulaciones(trayectoria[0], trayectoria.back()));
    }
        


    // =====================================================
    // 📈 Trayectoria completa (Promedios)
    // =====================================================

    std::cout << "\n=== Promedios diarios ===\n";

    for (int t = 0; t < promediosDiarios.size(); t++) {

        std::cout << "t=" << t << ": ";

        for (double p : promediosDiarios[t]) {
            std::cout << p << " ";
        }

        std::cout << "\n";
    }

    
    // =====================================================
    // 💰 Valor del portafolio en el tiempo
    // =====================================================
    auto cantidades = portafolio.calcularCantidadesIniciales();
    std::vector<double> evolucionPortafolio;

    std::cout << "\n=== Valor del portafolio ===\n";

    for (int t = 0; t < promediosDiarios.size(); t++) {

        double valor = 0.0;

        for (int i = 0; i < n; i++) {
            valor += cantidades[i] * promediosDiarios[t][i];
        }

        std::cout << "t=" << t << ": " << valor << "\n";
        evolucionPortafolio.push_back(valor);
    }
    double tasaLibreRiesgo = 0.08;
    AnalizadorPortafolio analisis(simulaciones, tasaLibreRiesgo);

    analisis.imprimirReporte();

    /*
    for (int i = 0; i < simulaciones.size(); i++){
        std::vector<double> retornos = simulaciones[i].vf();
        for (int k = 0; k < retornos.size(); k++){
            std::cout << retornos[k] << " ";
        }
        std::cout << std::endl;
    }
    */
    

    return 0;
}