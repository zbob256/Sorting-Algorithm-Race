#pragma once

#include "dataset.hpp"
#include <vector>

const int RUN_SIZE = 32;

void insertionSortRange(std::vector<int>& arr, int left, int right);

void mergeRuns(std::vector<int>& arr, int left, int mid, int right);

void tim(std::vector<int> arr);