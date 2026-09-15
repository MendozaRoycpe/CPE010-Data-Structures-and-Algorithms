//
// Created by royga on 9/10/2026.
//

#ifndef UNTITLED1_SORTALGO_H
#define UNTITLED1_SORTALGO_H
#include <iostream>

// print the array
template <typename t>
void printArr(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " \n";
    }
}

//shell sort
template <typename T>
void shellSort(T arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already
        // in gapped order, so we start from arr[gap].
        for (int i = gap; i < n; i++) {
            T temp = arr[i];  // element to be positioned
            int j = i;

            // Shift earlier gap-sorted elements up until the
            // correct location for arr[i] is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

//merge sort
template <typename T>


//quicksort
template <typename T>

#endif //UNTITLED1_SORTALGO_H
