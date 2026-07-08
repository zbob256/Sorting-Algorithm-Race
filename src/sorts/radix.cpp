#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void countingSortByDigit(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;

        radixSort.operations++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];

        radixSort.operations++;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;

        radixSort.operations += 2;
    }

    arr = output;
}

void radix(std::vector<int> arr) {
    radixSort.id = std::this_thread::get_id();
    radixSort.startTime = std::chrono::steady_clock::now();
    radixSort.status = "Running";

    if (arr.empty()) return;

    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;

            radixSort.operations++;
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }

    radixSort.status = "Checking";
    radixSort.status = verify(arr) ? "Finished" : "Failed";
}