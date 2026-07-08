#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void cocktailShaker(std::vector<int> arr) {
    cocktailShakerSort.id = std::this_thread::get_id();
    cocktailShakerSort.startTime = std::chrono::steady_clock::now();
    cocktailShakerSort.status = "Running";

    int n = arr.size();
    int start = 0;
    int end = n - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];

                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                
                swapped = true;

                cocktailShakerSort.operations += 4;
            }
        }

        if (!swapped) break;

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                
                swapped = true;

                cocktailShakerSort.operations += 4;
            }
        }
    }

    cocktailShakerSort.status = "Checking";
    cocktailShakerSort.status = verify(arr) ? "Finished" : "Failed";
}