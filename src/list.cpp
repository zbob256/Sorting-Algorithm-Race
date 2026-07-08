#include "list.hpp"
#include "sorts.hpp"

Algorithm bubbleSort(-1, "Bubble Sort", std::this_thread::get_id(), "Ready",  bubble);
Algorithm bucketSort(-1, "Bucket Sort", std::this_thread::get_id(), "Ready", bucket);
Algorithm cocktailShakerSort(-1, "Cocktail Shaker Sort", std::this_thread::get_id(), "Ready", cocktailShaker);
Algorithm combSort(-1, "Comb Sort", std::this_thread::get_id(), "Ready", comb);
Algorithm countingSort(-1, "Counting Sort", std::this_thread::get_id(), "Ready", counting);
Algorithm gnomeSort(-1, "Gnome Sort", std::this_thread::get_id(), "Ready", gnome);
Algorithm heapSort(-1, "Heap Sort", std::this_thread::get_id(), "Ready", heap);
Algorithm insertionSort(-1, "Insertion Sort", std::this_thread::get_id(), "Ready", insertion);
Algorithm introSort(-1, "Intro Sort", std::this_thread::get_id(), "Ready", intro);
Algorithm mergeSort(-1, "Merge Sort", std::this_thread::get_id(), "Ready", merge);
Algorithm oddEvenSort(-1, "Odd Even Sort", std::this_thread::get_id(), "Ready", oddEven);
Algorithm quickSort(-1, "Quick Sort", std::this_thread::get_id(), "Ready", quick);
Algorithm radixSort(-1, "Radix Sort", std::this_thread::get_id(), "Ready", radix);
Algorithm selectionSort(-1, "Selection Sort", std::this_thread::get_id(), "Ready", selection);
Algorithm shellSort(-1, "Shell Sort", std::this_thread::get_id(), "Ready", shell);
Algorithm timSort(-1, "Tim Sort", std::this_thread::get_id(), "Ready", tim);


std::vector<std::reference_wrapper<Algorithm>> algorithms = {
    bubbleSort,
    bucketSort,
    cocktailShakerSort,
    combSort,
    countingSort,
    gnomeSort,
    heapSort,
    insertionSort,
    introSort,
    mergeSort,
    oddEvenSort,
    quickSort,
    radixSort,
    selectionSort,
    shellSort,
    timSort
};