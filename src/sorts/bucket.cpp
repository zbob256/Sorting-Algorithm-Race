#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void bucket(std::vector<int> arr) {
    bucketSort.id = std::this_thread::get_id();
    bucketSort.startTime = std::chrono::steady_clock::now();
    bucketSort.status = "Running";

    if (arr.empty()) return;

    int n = arr.size();

    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;

            bucketSort.operations++;
        }
    }

    std::vector<std::vector<int>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = (long long)arr[i] * n / (maxVal + 1);
        buckets[bucketIndex].push_back(arr[i]);

        bucketSort.operations++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < buckets[i].size(); j++) {
            int key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;

                bucketSort.operations += 2;
            }

            buckets[i][k + 1] = key;

            bucketSort.operations++;
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int val : buckets[i]) {
            arr[index] = val;
            index++;

            bucketSort.operations++;
        }
    }

    bucketSort.status = "Checking";
    bucketSort.status = verify(arr) ? "Finished" : "Failed";
}