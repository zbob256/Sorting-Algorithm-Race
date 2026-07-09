#pragma once

#include <vector>

const int MIN = 1;
const int MAX = 100000;
const int ELEMENTS = 10000;
const double NEATNESS = 0.0;

std::vector<int> createArray(int min, int max, int range, double neatness);
extern std::vector<int> dataset;
