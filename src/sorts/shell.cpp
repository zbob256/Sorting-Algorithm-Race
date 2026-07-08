#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void shell(std::vector<int> arr) {
    shellSort.id = std::this_thread::get_id();
    shellSort.startTime = std::chrono::steady_clock::now();
    shellSort.status = "Running";

    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j = i - gap;

            shellSort.operations++;

            while (j >= 0 && arr[j] > key) {
                arr[j + gap] = arr[j];
                j -= gap;

                shellSort.operations += 2;
            }

            arr[j + gap] = key;

            shellSort.operations++;
        }
    }

    shellSort.status = "Checking";
    shellSort.status = verify(arr) ? "Finished" : "Failed";
}