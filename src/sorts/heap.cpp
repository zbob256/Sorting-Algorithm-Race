#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;

        heapSort.operations += 3;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;

        heapSort.operations += 3;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapSort.operations += 4;

        heapify(arr, n, largest);
    }
}

void heap(std::vector<int> arr) {
    heapSort.id = std::this_thread::get_id();
    heapSort.startTime = std::chrono::steady_clock::now();
    heapSort.status = "Running";

    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapSort.operations += 3;

        heapify(arr, i, 0);
    }

    heapSort.status = "Checking";
    heapSort.status = verify(arr) ? "Finished" : "Failed";
}