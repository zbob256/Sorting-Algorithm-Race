#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void insertionSortRange(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            timSort.operations += 2;
        }

        arr[j + 1] = key;
    }
}

void mergeRuns(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftHalf(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightHalf(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftHalf.size() && j < rightHalf.size()) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;

        timSort.operations += 2;
    }

    while (i < leftHalf.size()) {
        arr[k] = leftHalf[i];
        i++;
        k++;

        timSort.operations += 2;
    }

    while (j < rightHalf.size()) {
        arr[k] = rightHalf[j];
        j++;
        k++;

        timSort.operations += 2;
    }
}

void tim(std::vector<int> arr) {
    timSort.id = std::this_thread::get_id();
    timSort.startTime = std::chrono::steady_clock::now();
    timSort.status = "Running";

    int n = arr.size();

    for (int i = 0; i < n; i += RUN_SIZE) {
        int right = std::min(i + RUN_SIZE - 1, n - 1);
        insertionSortRange(arr, i, right);
    }

    for (int size = RUN_SIZE; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                mergeRuns(arr, left, mid, right);

                timSort.operations++;
            }
        }
    }

    timSort.status = "Checking";
    timSort.status = verify(arr) ? "Finished" : "Failed";
}