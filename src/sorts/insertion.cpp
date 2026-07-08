#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void insertion(std::vector<int> arr) {
    insertionSort.id = std::this_thread::get_id();
    insertionSort.startTime = std::chrono::steady_clock::now();
    insertionSort.status = "Running";

    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            insertionSort.operations += 3;
        }

        arr[j + 1] = key;
    }

    insertionSort.status = "Checking";
    insertionSort.status = verify(arr) ? "Finished" : "Failed";
}