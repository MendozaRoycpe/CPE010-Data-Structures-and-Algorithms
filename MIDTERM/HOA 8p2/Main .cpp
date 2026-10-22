//
// Created by royga on 9/10/2026.
//
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "sortAlgo.h"

const int max_size = 20;

void showArr(const int arr[], int size);
void resetArr(const int src[], int dest[], int size);

int main() {
    int original[max_size];
    int arr[max_size];

    // Seed the random number generator
    srand(time(0));

    // Generate random values once for the original array
    for (int i = 0; i < max_size; i++) {
        original[i] = (rand() % 10)+1;
    }

    // Display original unsorted array
    std::cout << "================ ORIGINAL ARRAY ================\n";
    showArr(original, max_size);
    std::cout << "\n";

    // --- SHELL SORT ---
    std::cout << "=================== SHELL SORT ===================\n";
    resetArr(original, arr, max_size);
    shellSort(arr, max_size);
    showArr(arr, max_size);
    std::cout << "\n";

    // --- MERGE SORT ---
    std::cout << "=================== MERGE SORT ===================\n";
    resetArr(original, arr, max_size);
    mergeSort(arr, 0, max_size - 1);
    showArr(arr, max_size);
    std::cout << "\n";

    // --- QUICK SORT ---
    std::cout << "=================== QUICK SORT ===================\n";
    resetArr(original, arr, max_size);
    quickSort(arr, max_size);
    showArr(arr, max_size);
    std::cout << "\n";

    return 0;
}

void showArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void resetArr(const int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}