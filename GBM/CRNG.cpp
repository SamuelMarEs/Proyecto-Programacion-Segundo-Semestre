#include <iostream>
#include "RNG.h"

int main() {

    RNG rng;

    std::cout << "Numeros aleatorios:\n";

    for (int i = 0; i < 10; i++) {
        std::cout << rng.normal() << std::endl;
    }

    return 0;
}