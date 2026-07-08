#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void gnome(std::vector<int> arr) {
    gnomeSort.id = std::this_thread::get_id();
    gnomeSort.startTime = std::chrono::steady_clock::now();
    gnomeSort.status = "Running";

    int n = arr.size();
    int i = 0;

    while (i < n) {
        if (i == 0 || arr[i - 1] <= arr[i]) {
            i++;

            gnomeSort.operations += 1;
        } else {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;

            i--;

            gnomeSort.operations += 3;
        }

        gnomeSort.operations++;
    }

    gnomeSort.status = "Checking";
    gnomeSort.status = verify(arr) ? "Finished" : "Failed";
}