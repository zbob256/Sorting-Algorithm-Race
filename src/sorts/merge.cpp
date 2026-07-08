#include "list.hpp"
#include <vector>
#include "sorts.hpp"
#include "sorts/verify.hpp"

void merge3(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftHalf(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightHalf(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftHalf.size() && j < rightHalf.size()) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;

            mergeSort.operations += 2;
        } else {
            arr[k] = rightHalf[j];
            j++;

            mergeSort.operations++;
        }
        k++;

        mergeSort.operations++;
    }

    while (i < leftHalf.size()) {
        arr[k] = leftHalf[i];
        i++;
        k++;

        mergeSort.operations += 2;
    }

    while (j < rightHalf.size()) {
        arr[k] = rightHalf[j];
        j++;
        k++;

        mergeSort.operations += 2;
    }
}

void merge2(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;

        mergeSort.operations++;
    }

    int mid = left + (right - left) / 2;

    merge2(arr, left, mid);
    merge2(arr, mid + 1, right);
    merge3(arr, left, mid, right);
}

void merge(std::vector<int> arr) {
    mergeSort.id = std::this_thread::get_id();
    mergeSort.startTime = std::chrono::steady_clock::now();
    mergeSort.status = "Running";


    if (arr.empty()) return;
    merge2(arr, 0, arr.size() - 1);

    mergeSort.status = "Checking";
    mergeSort.status = verify(arr) ? "Finished" : "Failed";
}