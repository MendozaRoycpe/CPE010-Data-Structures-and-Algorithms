//
// Created by royga on 10/20/2026.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

// Linear Search
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void benchmark(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = i * 2;
    int target = -1; // Worst-case: element does not exist

    auto startBS = std::chrono::high_resolution_clock::now();
    binarySearch(arr, target);
    auto endBS = std::chrono::high_resolution_clock::now();
    auto durationBS = std::chrono::duration_cast<std::chrono::microseconds>(endBS - startBS).count();

    // Benchmark Linear Search using microseconds
    auto startLS = std::chrono::high_resolution_clock::now();
    linearSearch(arr, target);
    auto endLS = std::chrono::high_resolution_clock::now();
    auto durationLS = std::chrono::duration_cast<std::chrono::microseconds>(endLS - startLS).count();

    std::cout << "Input Size N = " << n << "\n";
    std::cout << "Binary Search Execution time: " << durationBS << " microseconds\n";
    std::cout << "Linear Search Execution time: " << durationLS << " microseconds\n\n";
}

int main() {
    std::cout << "Worst-Case Benchmarking\n\n";
    benchmark(1000);
    benchmark(10000);
    benchmark(100000);
    return 0;
}