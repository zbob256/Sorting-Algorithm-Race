#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void selection(std::vector<int> arr) {
    selectionSort.id = std::this_thread::get_id();
    selectionSort.startTime = std::chrono::steady_clock::now();
    selectionSort.status = "Running";

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }

            selectionSort.operations++;
        }

        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;

            selectionSort.operations += 3;
        }
    }

    selectionSort.status = "Checking";
    selectionSort.status = verify(arr) ? "Finished" : "Failed";
}