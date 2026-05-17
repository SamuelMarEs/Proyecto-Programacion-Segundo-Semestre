/*
Código main del proyecto de programación, segundo semestre.
Licenciatura en Matemáticas para el desarrollo, ENES Juriquilla
Samuel Márquez y Emiliano Almaráz
*/

// Librerias y clases
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Activo.h"
#include "Portafolio.h"
#include "Simulador.h"
#include "RegistroSimulaciones.h"
#include "AnalizadorPortafolio.h"

using namespace std;


// Función que exporta los datos de las simulaciones en un archivo .CSV
void exportarCSV(const vector<Activo> activos, const vector<vector<double>> promediosDiarios, const vector<double> evolucionPortafolio){
    /*
    activos: Vector que contiene los datos de cada activo ingresado por el usuario
    promediosDiarios: Matriz de 252 filas (1 por día) y n columnas con los promedios diarios de cada activo
    evolucionPortafolio: Vector con la evolución diaria del capital invertido en el portafolio
    */


    ofstream csv("Resultados.csv");                                     // Abre o crea el archivo csv
    csv << "Día,";                                                      // Llama "Día" a la primera columna
    for (int i = 0; i < activos.size(); i++){                           // LLama a cada columna con el nombre de un activo
        csv << activos[i].getNombre() << ",";
    }
    csv << "Portafolio";                                                // LLama la última columna "Portafolio"
    csv << endl;

    for (int i = 0; i < promediosDiarios.size(); i++){                  // Imprime datos en el csv
        csv << i << ",";                                                // Día de la simulación
        for (int k = 0; k < promediosDiarios[i].size(); k++){           // Imprime el promedio diario por activo
            csv << promediosDiarios[i][k] << ",";
        }
        csv << evolucionPortafolio[i];                                  // Imprime el valor del portafolio en el día dado
        csv << endl;
    }

    csv.close();                                                        // Cierra el archivo
};

int main() {
    // Variable para el número de activos
    int n;

    // Ciclo para ingresar activos
    int seguro1 = -1;
    while (seguro1 != 0){
        std::cout << "Numero de activos (máximo 6): ";
        std::cin >> n;

        // En caso de entrada de tipo incorrecto
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Entrada no válida" << endl;
        }

        // En caso de que se ingresen más de 6 activos
        if (n > 6){
            std::cout << "El número de activos no debe ser mayor a 6, volver a intentar porfavor" << std::endl;
        }
        // En caso de que se ingrese menos de 1 activo
        else if (n < 1){
            std::cout << "Debe ingresar al menos 1 activo. Volver a intentar porfavor" << std::endl;
        }
        // Si todo está corecto, acepta el número de activos
        else {
            seguro1 = 0;
        }
    }

    // Vectores para guardar los datos de cada activo y los pesos
    vector<Activo> activos;
    vector<double> pesos(n);

    // Creación de los activos predeterminados
    Activo Gold("Oro", 2000, 0.04, 0.15);
    Activo SP500("SP500", 7600, 0.06, 0.15);
    Activo NVIDIA("NVIDIA", 300, 0.2, 0.35);
    Activo Dolar("Dolar", 17.5, 0.01, 0.08);
    Activo Euro("Euro", 20.29, 0.05, 0.12);
    Activo Petro("Petroleo", 3000, 0.15, 0.4);
    
    // Lectura de activos

    // Vector para recordar que activos ya se ingresaron
    vector<int> historialActivos;

    // Ciclo para ingresar n activos
    for (int i = 0; i < n; i++){
        // Imprime las opciones de activos que el usuario puede elegir
        cout << "==========Elija uno de los activos en los que desea invertir y presione ENTER==========" << endl;
        cout << "(1) Oro, $2000" << endl;
        cout << "(2) SP500, $7600" << endl;
        cout << "(3) NVIDIA, $300" << endl;
        cout << "(4) Dolar, $17.5" << endl;
        cout << "(5) Euro, $20.29" << endl;
        cout << "(6) Petroleo, $3000" << endl;

        // Guarda la opcion ingresada por el usuario
        int opcion;
        cin >> opcion;

        // Si la opción ingresada ya se había elegido, la cambia por un cero
        for (int k = 0; k < historialActivos.size(); k++){
            if (historialActivos[k] == opcion){
                opcion = 0;
            }
        }
        // Guarda el historial de opciones
        historialActivos.push_back(opcion);

        // En caso de entrada de tipo incorrecto
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Entrada no válida" << endl;
        }

        // Dependiendo de la opcion ingresada, guarda el activo
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
        } // En caso de que se ingresara más de una vez el mismo activo 
        else if (opcion == 0){
            cout << "Opcion no válida. No puede ingresar el mismo activo más de una vez. Vuelva a intentar porfavor" << endl;
            i -= 1;
        } // En caso de la opcion no estuviera entre las pedidas 
        else {
            cout << "Opcion no válida, elija otro activo porfavor" << endl;
            i -= 1;
        }
            
    }

    // Lectura de pesos

    std::cout << "\nIngrese pesos por activo en decimal (suman 1):\n";

    // Ciclo que termina una vez se tengan todos los activos de forma correcta
    int seguro2 = -1;
    while (seguro2 != 0){
        // Suma de los pesos de los actios
        double sum;

        // Ciclo que pide pesos uno por uno
        for (int i = 0; i < n; i++) {
            // Pide el peso
            double peso;
            std::cout << "Peso activo " << i + 1 << ": ";
            std::cin >> peso;

            // En caso de entrada de tipo incorrecto
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Entrada no válida" << endl;
                i -= 1;
            } // Si el peso es válido, lo guarda
            if (peso < 1 && peso >= 0){
                pesos[i] = peso;
            } // Si el peso no es válido, lo vuelve a pedir
            else {
                std::cout << "El peso de un activo no puede sobrepasar 1 ni ser negativo. Vuelva a intentar porfavor" << std::endl;
                i -= 1;
            }

            // Revisa que la suma sea válida. En caso de no serlo, vuelve a pedir el peso
            sum += pesos[i];
            if (sum > 1) {
                std::cout << "La suma de los pesos de los activos no puede sobrepasar 1, vuelva a intentar porfavor" << std::endl;
                sum -= pesos[i];
                pesos[i] = 0;
                i -= 1;
            }
        }
        // Si la suma no completa la unidad, se vuelven a pedir todos los pesos
        if (sum != 1){
            std::cout << "Los pesos de los activos deben sumar 1, vuelva a intentar porfavor" << std::endl;
            sum = 0;
        } // Si está todo correcto, termina el ciclo 
        else {
            seguro2 = 0;
        }
    }
    

    // Capital
    double capital;
    while (true){
        std::cout << "\nCapital total que desea invertir, redondeado a dos decimales (pesos mexicanos): ";
        std::cin >> capital;

        // En caso de entrada de tipo incorrecto
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Entrada no válida" << endl;
        } // En caso de capital negativo 
        else if (capital <= 0){
            cout << "Entrada no valida. El capital debe ser positivo" << endl;
            continue;
        } // Si el número es válido, termina el bucle
        else if (capital > 0){
            cin.ignore(1000,'\n');
            break;
        }

    }
    // Muestra el capital ingresado redondeado a dos decimales
    cout << fixed << setprecision(2);
    cout << "Capital invertido: " << capital << endl;
    

    // Número de simulaciones
    int numSim;

    // Bucle para corroborar que sea un número válido
    while (true){
        std::cout << "Ingrese número de simulaciones (1-1000): ";
        cout << "(si ingresa sólo únicamente una simulación, los resultados podrían ser inconsistentes)" << endl;
        std::cin >> numSim;

        // En caso de entrada de tipo no válido
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Entrada no válida" << endl;
        } // En caso de cero simulaciones o negativas 
        else if (numSim <= 0){
            cout << "Entrada no valida. Debe de realizarse al menos una simulación" << endl;
            continue;
        } else {
            cin.ignore(1000,'\n');
            break;
        }
    }

    // Guarda los datos de los activos, pesos y capital invertido en un objeto de clase portafolio
    Portafolio portafolio(activos, pesos, capital);

    // Parámetros simulación
    int steps = 252;
    double T = 1;

    // Redondear a 4 decimales
    std::cout << std::fixed << std::setprecision(4);
    
    // Simulaciones:
    // Crea un vector para guardar el promedio diario del valor de los activos
    std::vector<vector<double>> promediosDiarios(steps, std::vector<double>(n, 0));
    // Crea un vector para guardar los registros de las simulaciones
    std::vector<RegistroSimulaciones> simulaciones;
    // Crea un simulador (Clase SimuladorMonteCarlo)
    SimuladorMonteCarlo simulador;

    // Ciclo para simular todas las trayectorias
    for (int i = 0; i < numSim; i++){
        // Crea una trayectoria temporal
        auto trayectoria = simulador.simular(portafolio, T, steps);

        // Guardar un vector con el promedio diario de todas las simulaciones
        for (int t = 0; t < steps; t++){
            for (int k = 0; k < n; k++){
                promediosDiarios[t][k] += trayectoria[t][k]/numSim;
            }
        }
        // Guarda el valor inicial y el valor inicial de cada activo en la simulación
        simulaciones.push_back(RegistroSimulaciones(trayectoria[0], trayectoria.back()));
    }


    // =====================================================
    //  Trayectoria completa (Promedios)
    // =====================================================
    // Imprime el promedio diario del valor de cada activo
    std::cout << "\n=== Promedios diarios ===\n";

    for (int t = 0; t < promediosDiarios.size(); t++) {
        // Día de la simulación
        std::cout << "t=" << t << ": ";
        // Promedio diario por activo
        for (double p : promediosDiarios[t]) {
            std::cout << p << " ";
        }
        std::cout << "\n";
    }
  
    // =====================================================
    //  Valor del portafolio en el tiempo
    // =====================================================
    // Imprime y guarda la evolución del portafolio
    auto cantidades = portafolio.calcularCantidadesIniciales();
    std::vector<double> evolucionPortafolio;

    std::cout << "\n=== Valor del portafolio ===\n";

    for (int t = 0; t < promediosDiarios.size(); t++) {
        // Valor temporal del día
        double valor = 0.0;
        // Calcula el valor en base a la cantidad invertida y el promedio diario del activo
        for (int i = 0; i < n; i++) {
            valor += cantidades[i] * promediosDiarios[t][i];
        }

        std::cout << "t=" << t << ": " << valor << "\n";
        // Guarda el valor del activo en ese día
        evolucionPortafolio.push_back(valor);
    }

    // Tasa libre de riesgo (retorno de CETES)
    double tasaLibreRiesgo = 0.08;

    // Analizador para imprimir el reporte de resultados
    AnalizadorPortafolio analisis(simulaciones, tasaLibreRiesgo);
    // Imprime el reporte de los resultados
    analisis.imprimirReporte();

    // Guarda los datos en el archivo CSV
    exportarCSV(activos, promediosDiarios, evolucionPortafolio);

    return 0;
}