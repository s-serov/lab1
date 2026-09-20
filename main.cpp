#include <iostream>
#include "shared_types.h"

int main() {
    std::cout << "Project initialized successfully." << std::endl;
    return 0;
}

#include <iostream>
#include <memory>
#include <iomanip>
#include "shared_types.h"

int main() {
    auto data = std::make_shared<const InputData>(InputData{
        .a = 1.0,
        .b = -6.0,
        .c = 11.0,
        .d = -6.0
    });

    std::cout << "=== Student A: Cardano Method ===\n";
    std::cout << "Equation: " << data->a << "x^3 + (" 
              << data->b << ")x^2 + (" 
              << data->c << ")x + (" 
              << data->d << ") = 0\n\n";

    auto resultA = calculateA(data);
    auto [rootsA, residualsA, itersA] = *resultA;

    std::cout << "Iterations: " << itersA << "\n";
    std::cout << "Found roots count: " << rootsA.size() << "\n";

    for (size_t i = 0; i < rootsA.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(6) << rootsA[i] 
                  << " | Residual: " << std::scientific << residualsA[i] << "\n";
    }

    return 0;
}