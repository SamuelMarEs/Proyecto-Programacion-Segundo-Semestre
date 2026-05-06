#pragma once
#include <random>

class Random {
private:
    std::mt19937 gen;
    std::normal_distribution<> dist;

public:
    Random();

    double normal();
};