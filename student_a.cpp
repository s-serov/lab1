#include "shared_types.h"

// Заглушка для Студента А (Метод Кардано)
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    auto res = std::make_unique<Result>();
    return res;
}

#include "shared_types.h"
#include <cmath>
#include <numbers>
#include <algorithm>

static double cubeRoot(double val) {
    if (val > 0.0) return std::cbrt(val);
    if (val < 0.0) return -std::cbrt(-val);
    return 0.0;
}

static double evaluateCubic(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    auto result = std::make_unique<Result>();
    result->iterations = 1;

    const double a = data->a;
    const double b = data->b;
    const double c = data->c;
    const double d = data->d;

    if (std::abs(a) < 1e-12) {
        return result;
    }

    const double a1 = b / a;
    const double a2 = c / a;
    const double a3 = d / a;

    const double p = a2 - (a1 * a1) / 3.0;
    const double q = (2.0 * a1 * a1 * a1) / 27.0 - (a1 * a2) / 3.0 + a3;

    const double Q = std::pow(p / 3.0, 3) + std::pow(q / 2.0, 2);
    const double shift = a1 / 3.0;

    if (Q > 1e-12) {
        const double sqrtQ = std::sqrt(Q);
        const double u = cubeRoot(-q / 2.0 + sqrtQ);
        const double v = cubeRoot(-q / 2.0 - sqrtQ);
        result->roots.push_back((u + v) - shift);
    } else if (std::abs(Q) <= 1e-12) {
        const double u = cubeRoot(-q / 2.0);
        result->roots.push_back(2.0 * u - shift);
        result->roots.push_back(-u - shift);
    } else {
        const double r = std::sqrt(-std::pow(p / 3.0, 3));
        const double phi = std::acos(std::clamp(-q / (2.0 * r), -1.0, 1.0));
        const double factor = 2.0 * std::cbrt(r);

        result->roots.push_back(factor * std::cos(phi / 3.0) - shift);
        result->roots.push_back(factor * std::cos((phi + 2.0 * std::numbers::pi) / 3.0) - shift);
        result->roots.push_back(factor * std::cos((phi + 4.0 * std::numbers::pi) / 3.0) - shift);
    }

    std::sort(result->roots.begin(), result->roots.end());

    for (double r : result->roots) {
        result->residuals.push_back(std::abs(evaluateCubic(r, a, b, c, d)));
    }

    return result;
}