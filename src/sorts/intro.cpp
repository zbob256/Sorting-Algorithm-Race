#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

int introPartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            introSort.operations += 4;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    introSort.operations += 3;

    return i + 1;
}

void introHeapify(std::vector<int>& arr, int low, int high, int i) {
    int largest = i;
    int left = low + 2 * (i - low) + 1;
    int right = low + 2 * (i - low) + 2;

    if (left <= high && arr[left] > arr[largest]) {
        largest = left;

        introSort.operations += 2;
    }
    if (right <= high && arr[right] > arr[largest]) {
        largest = right;

        introSort.operations += 2;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        introHeapify(arr, low, high, largest);

        introSort.operations += 3;
    }
}

void introHeapSortRange(std::vector<int>& arr, int low, int high) {
    int n = high - low + 1;

    for (int i = low + n / 2 - 1; i >= low; i--) {
        introHeapify(arr, low, high, i);
    }

    for (int i = high; i > low; i--) {
        int temp = arr[low];
        arr[low] = arr[i];
        arr[i] = temp;
        introHeapify(arr, low, i - 1, low);

        introSort.operations += 4;
    }
}

void introInsertionSortRange(std::vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        introSort.operations++;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            introSort.operations += 3;
        }

        arr[j + 1] = key;

        introSort.operations++;
    }
}

void introSortUtil(std::vector<int>& arr, int low, int high, int depthLimit) {
    int size = high - low + 1;

    if (size < INSERTION_THRESHOLD) {
        insertionSortRange(arr, low, high);
        return;
    }

    if (depthLimit == 0) {
        introHeapSortRange(arr, low, high);
        return;
    }

    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        introSortUtil(arr, low, pivotIndex - 1, depthLimit - 1);
        introSortUtil(arr, pivotIndex + 1, high, depthLimit - 1);

        introSort.operations++;
    }
}

void intro(std::vector<int> arr) {
    introSort.id = std::this_thread::get_id();
    introSort.startTime = std::chrono::steady_clock::now();
    introSort.status = "Running";

    if (arr.empty()) return;

    int n = arr.size();

    int depthLimit = 2 * log(n);

    introSortUtil(arr, 0, n - 1, depthLimit);

    introSort.status = "Checking";
    introSort.status = verify(arr) ? "Finished" : "Failed";
}
