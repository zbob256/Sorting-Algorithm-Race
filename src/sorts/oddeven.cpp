#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void oddEven(std::vector<int> arr) {
    oddEvenSort.id = std::this_thread::get_id();
    oddEvenSort.startTime = std::chrono::steady_clock::now();
    oddEvenSort.status = "Running";

    int n = arr.size();
    bool sorted = false;

    while (!sorted) {
        sorted = true;

        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;

                oddEvenSort.operations += 4;
            }
        }

        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;

                oddEvenSort.operations += 4;
            }
        }
    }

    oddEvenSort.status = "Checking";
    oddEvenSort.status = verify(arr) ? "Finished" : "Failed";
}