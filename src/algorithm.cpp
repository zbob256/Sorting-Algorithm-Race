#include "algorithm.hpp"

Algorithm::Algorithm(
    int rank,
    std::string name,
    std::thread::id id,
    std::string status,
    std::function<void(std::vector<int>)> function
) : rank(rank), name(std::move(name)), id(std::thread::id()), status(std::move(status)), function(std::move(function)) {
    time = 0.0f;
    operations = 0L;
}