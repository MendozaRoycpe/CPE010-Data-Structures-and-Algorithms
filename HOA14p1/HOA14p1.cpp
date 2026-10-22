//
// Created by royga on 10/20/2026.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

// MERGE SORT IMPLEMENTATION
template <typename T>
void merge(std::vector<T>& arr, int left, int middle, int right) {
    int size = right - left + 1;
    std::vector<T> temp(size);

    int i = left;
    int j = middle + 1;
    int temp_pos = 0;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[temp_pos++] = arr[i++];
        } else {
            temp[temp_pos++] = arr[j++];
        }
    }
    while (i <= middle) {
        temp[temp_pos++] = arr[i++];
    }
    while (j <= right) {
        temp[temp_pos++] = arr[j++];
    }
    for (int k = 0; k < size; ++k) {
        arr[left + k] = temp[k];
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

// QUICK SORT IMPLEMENTATION
template <typename T>
int quick(std::vector<T>& arr, int left, int right) {
    T pivot = arr[right];
    int low = left - 1;
    int high = right;

    while (true) {
        do {
            low++;
        } while (arr[low] < pivot);
        do {
            high--;
        } while (high > left && arr[high] > pivot);

        if (low >= high) {
            break;
        }
        std::swap(arr[low], arr[high]);
    }
    std::swap(arr[low], arr[right]);
    return low;
}

template <typename T>
void quickSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = quick(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

// STATIC chrono
std::vector<int> generate_static_vector(int size, unsigned int seed = 42) {
    std::mt19937 rand(seed);//for the static output content
    std::uniform_int_distribution<int> uniform_dist(1, size * 10);
    std::vector<int> vec;
    vec.reserve(size);
    for (int i = 0; i < size; ++i) {
        vec.push_back(uniform_dist(rand));
    }
    return vec;
}


//DRIVER USING chono
void run_sorting_tests() {
    std::vector<int> sizes = {100, 1000, 10000};

    // Adjust sizes for standard C++ vector notation
    std::vector<int> test_sizes = {100, 1000, 10000};

    for (int size : test_sizes) {
        // Generate static random data so both algorithms sort the exact same elements
        std::vector<int> original_data = generate_static_vector(size, 42);

        //Merge Sort
        std::vector<int> data_merge = original_data;
        std::chrono::steady_clock::time_point start_merge = std::chrono::steady_clock::now();

        mergeSort(data_merge, 0, size - 1);

        std::chrono::steady_clock::time_point end_merge = std::chrono::steady_clock::now();
        auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(end_merge - start_merge).count();

        //Quick Sort
        std::vector<int> data_quick = original_data;
        std::chrono::steady_clock::time_point start_quick = std::chrono::steady_clock::now();

        quickSort(data_quick, 0, size - 1);

        std::chrono::steady_clock::time_point end_quick = std::chrono::steady_clock::now();
        auto duration_quick = std::chrono::duration_cast<std::chrono::microseconds>(end_quick - start_quick).count();

        // Output Results
        std::cout << "----------------------------------------\n";
        std::cout << "Input Size (N) = " << size << "\n";
        std::cout << "  * Merge Sort Time : " << duration_merge << " microseconds\n";
        std::cout << "  * Quick Sort Time : " << duration_quick << " microseconds\n";
    }
    std::cout << "----------------------------------------\n";
}

int main() {
    std::cout << "Sorting Algorithm Experimental Analysis\n";
    run_sorting_tests();
    return 0;
}