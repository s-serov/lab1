#pragma once

#include <vector>
#include <memory>

struct InputData {
    double a{ 1.0 };
    double b{ 0.0 };
    double c{ 0.0 };
    double d{ 0.0 };
};

struct Result {
    std::vector<double> roots;
    std::vector<double> residuals;
    int iterations{ 0 };
};

// Прототипы функций студентов
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);