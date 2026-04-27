# Proyecto-Programacion-Segundo-Semestre
### Emiliano Panuncio y Samuel Márquez

Sistema en C++ que permita simular la evolución de un portafolio de activos financieros usando movimiento browniano geométrico (GBM), calcular métricas de riesgo/retorno y comparar estrategias de inversión mediante una simulación Montecarlo.

Modelo de precios:

$$S_{t} = S_{0}\cdot e^{(\mu - \frac{\sigma^2}{2})t+\sigma W_{t}}$$

Metricas a calcular:
1. Retorno esperado anualizdo
2. Volatilidad
3. Sharpe ratio
4. Value at Risk (VaR) histórico
5. Conditional VaR (CVaR / Expected Shortfall)

Ejemplo de flujo de programa:
1. Usuario define 3 activos con parámetros realistas (ej. S&P500, bonos, oro).
2. Define pesos del portafolio (ej. 60% acciones, 30% bonos, 10%oro).
3. El sistema simula 10,000 trayectorias a 1 año con 252 pasos diarios.
4. Se calcula retorno final de cada simulación.
5. El "AnalizadorPortafolio" genera reporte:
   - Retorno esperado
   - Volatilidad
   - Sharpe ratio
   - VaR
   - CVar
  
## Estructura de clases sugerida:
~~~cpp
class Activo {
    string nombre;
    double precioInicial;
    double mu;      // rendimiento esperado anual
    double sigma;   // volatilidad anual
public:
    Activo(...);
    double getPrecioInicial() const;
    double getMu() const;
    double getSigma() const;
};

class Trayectoria {
    vector<double> precios;
    double tiempoTotal;   // años
    int pasos;            // discretización
public:
    Trayectoria(const Activo& a, double T, int steps, double semilla);
    double getPrecioFinal() const;
    const vector<double>& getPrecios() const;
};

class Portafolio {
    vector<Activo> activos;
    vector<double> pesos;   // suma = 1.0
    double matrizCorrelacion; // simplificado: podrían usar vector<vector<double>>
public:
    double valorFinal(const vector<double>& preciosFinales) const;
    vector<double> simularValores(int numSimulaciones, double T, int steps);
};

class AnalizadorPortafolio {
    vector<double> valoresFinales;  // de todas las simulaciones
    double tasaLibreRiesgo;
public:
    AnalizadorPortafolio(const vector<double>& vf, double rf);
    double retornoMedio() const;
    double volatilidad() const;
    double sharpeRatio() const;
    double var(double nivelConfianza) const;   // ej. 0.95
    double cvar(double nivelConfianza) const;
    void imprimirReporte() const;
};
~~~
