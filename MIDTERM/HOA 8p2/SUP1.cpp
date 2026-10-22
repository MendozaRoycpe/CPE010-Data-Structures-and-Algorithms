//
// Created by royga on 9/15/2026.
//
#include <iostream>
#include <algorithm>

// Function to sort a specific range [left...right] using Insertion Sort
void insSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort partition scheme using the last element as pivot
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Hybrid Sort: Partition once, then sort sub-lists via Insertion Sort
void HYBRID(int arr[], int left, int right) {
    if (left >= right) return;

    // 1. Partition the array around the pivot
    int pivotIndex = partition(arr, left, right);

    // 2. Sort the left sub-list using Insertion Sort
    if (left < pivotIndex - 1) {
        insSort(arr, left, pivotIndex - 1);
    }

    // 3. Sort the right sub-list using Insertion Sort
    if (pivotIndex + 1 < right) {
        insSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    int arr[] = {48, 34, 29, 12, 53, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    HYBRID(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}