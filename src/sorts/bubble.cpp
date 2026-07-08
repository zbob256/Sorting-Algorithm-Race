#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void bubble(std::vector<int> arr) {
    bubbleSort.id = std::this_thread::get_id();
    bubbleSort.startTime = std::chrono::steady_clock::now();
    bubbleSort.status = "Running";

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;

                bubbleSort.operations += 4;
            }
        }

        if (!swapped) break;
    }

    bubbleSort.status = "Checking";
    bubbleSort.status = verify(arr) ? "Finished" : "Failed";
}