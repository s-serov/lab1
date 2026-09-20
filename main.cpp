#include <iostream>
#include <memory>
#include <iomanip>
#include "shared_types.h"

int main() {
    auto input = std::make_shared<InputData>();
    input->a = 1.0;
    input->b = -6.0;
    input->c = 11.0;
    input->d = -6.0;

    std::shared_ptr<const InputData> data = input;

    std::cout << "=== Student A: Cardano Method ===" << std::endl;
    std::cout << "Equation: " << data->a << "x^3 + (" 
              << data->b << ")x^2 + (" 
              << data->c << ")x + (" 
              << data->d << ") = 0\n" << std::endl;

    auto resultA = calculateA(data);
    auto [rootsA, residualsA, itersA] = *resultA;

    std::cout << "Iterations: " << itersA << std::endl;
    std::cout << "Found roots count: " << rootsA.size() << std::endl;

    for (size_t i = 0; i < rootsA.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(6) << rootsA[i] 
                  << " | Residual: " << std::scientific << residualsA[i] << std::endl;
    }

    return 0;
}