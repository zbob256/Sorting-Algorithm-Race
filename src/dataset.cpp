#include "dataset.hpp"
#include <vector>
#include <random>
#include <iostream>

std::vector<int> createArray(int min, int max, int size) {
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    std::cout << "Creating elements..." << std::endl;

    for (int& num : arr) {
        num = dist(gen);
    }

    std::cout << "\033[2J\033[H";

    return arr;
}

std::vector<int> dataset = createArray(MIN, MAX, ELEMENTS);