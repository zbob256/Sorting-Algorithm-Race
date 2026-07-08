#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            quickSort.operations += 4;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    quickSort.operations += 3;

    return i + 1;
}

void quick2(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        quickSort.operations += 4;
        
        return;
    }

    int pivotIndex = partition(arr, low, high);

    quick2(arr, low, pivotIndex - 1);
    quick2(arr, pivotIndex + 1, high);
}

void quick(std::vector<int> arr) {
    quickSort.id = std::this_thread::get_id();
    quickSort.startTime = std::chrono::steady_clock::now();
    quickSort.status = "Running";

    quick2(arr, 0, arr.size() - 1);

    quickSort.status = "Checking";
    quickSort.status = verify(arr) ? "Finished" : "Failed";
}