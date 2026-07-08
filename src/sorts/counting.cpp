#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void counting(std::vector<int> arr) {
    countingSort.id = std::this_thread::get_id();
    countingSort.startTime = std::chrono::steady_clock::now();
    countingSort.status = "Running";

    if (arr.empty()) return;

    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;

            countingSort.operations++;
        }
    }

    std::vector<int> count(maxVal + 1, 0);
    for (int num : arr) {
        count[num]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int value = arr[i];
        output[count[value] - 1] = value;
        count[value]--;

        countingSort.operations += 2;
    }

    arr = output;

    countingSort.status = "Checking";
    countingSort.status = verify(arr) ? "Finished" : "Failed";
}