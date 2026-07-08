#include <vector>

bool verify(const std::vector<int>& dataset) {
    for (size_t i = 0; i + 1 < dataset.size(); i++) {
        if (dataset[i] > dataset[i + 1]) {
            return false;
        }
    }
    return true;
}