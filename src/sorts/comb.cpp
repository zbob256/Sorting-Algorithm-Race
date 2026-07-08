#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void comb(std::vector<int> arr) {
    combSort.id = std::this_thread::get_id();
    combSort.startTime = std::chrono::steady_clock::now();
    combSort.status = "Running";

    int n = arr.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        combSort.operations += 3;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;

                combSort.operations += 4;
            }
        }
    }

    combSort.status = "Checking";
    combSort.status = verify(arr) ? "Finished" : "Failed";
}