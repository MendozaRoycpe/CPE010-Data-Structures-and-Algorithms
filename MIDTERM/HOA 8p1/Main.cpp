//
// Created by royga on 9/8/2026.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ALGO.h"

const int max_size = 100;

void showArr(const int arr[], int size);

int main() {
    int original[max_size];
    int arrBubble[max_size];
    int arrInsertion[max_size];
    int arrSelection[max_size];

    // Seed the random number generator
    srand(time(0));

    // 1. Generate random values for the master array and copy them
    for (int i = 0; i < max_size; i++) {
        original[i] = rand() % 100;

        // Copy to separate the arrays
        arrBubble[i] = original[i];
        arrInsertion[i] = original[i];
        arrSelection[i] = original[i];
    }

    // Display original unsorted array
    std::cout << "================ ORIGINAL ARRAY ================\n";
    showArr(original, max_size);
    std::cout << "\n";

    // --- BUBBLE SORT ---
    std::cout << "=================== BUBBLE SORT ===================\n";
    bubbleSort(arrBubble, max_size);
    showArr(arrBubble, max_size);
    std::cout << "\n";

    // --- INSERTION SORT ---
    std::cout << "================= INSERTION SORT ==================\n";
    insertionSort(arrInsertion, max_size);
    showArr(arrInsertion, max_size);
    std::cout << "\n";

    // --- SELECTION SORT ---
    std::cout << "================= SELECTION SORT ==================\n";
    selectionSort(arrSelection, max_size);
    showArr(arrSelection, max_size);
    std::cout << "\n";

    return 0;
}

void showArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}