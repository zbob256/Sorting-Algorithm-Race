#include "dataset.hpp"
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

std::vector<int> createArray(int min, int max, int size, double neatness) {
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    std::cout << "Creating elements..." << std::endl;

    for (int& num : arr) {
        num = dist(gen);
    }

    if (neatness != 0) {
        std::sort(arr.begin(), arr.end());

        double disorder = 1.0 - std::clamp(neatness, 0.0, 1.0);
        int maxDistance = static_cast<int>(disorder * size);

        std::uniform_int_distribution<> indexDistance(0, size - 1);

        for (int i = 0; i < size; i++) {
            if (maxDistance > 0) {
                int offset = std::uniform_int_distribution<>(-maxDistance, maxDistance)(gen);
                int j = std::clamp(i + offset, 0, size - 1);

                std::swap(arr[i], arr[j]);
            }
        }
    }

    std::cout << "\033[2J\033[H";

    return arr;
}

std::vector<int> dataset = createArray(MIN, MAX, ELEMENTS, NEATNESS);
