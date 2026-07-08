#pragma once

#include "dataset.hpp"
#include <vector>

#include <cmath>

const int INSERTION_THRESHOLD = 16;

int introPartition(std::vector<int>& arr, int low, int high);
void introHeapify(std::vector<int>& arr, int low, int high, int i);
void introHeapSortRange(std::vector<int>& arr, int low, int high);
void introInsertionSortRange(std::vector<int>& arr, int low, int high);
void introSortUtil(std::vector<int>& arr, int low, int high, int depthLimit);
void intro(std::vector<int> arr);