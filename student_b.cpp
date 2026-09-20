#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    auto result = std::make_unique<Result>();
    result->iterations = 0;
    return result;
}