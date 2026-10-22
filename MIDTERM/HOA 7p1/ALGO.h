//
// Created by royga on 9/8/2026.
//

#ifndef UNTITLED1_ALGO_H
#define UNTITLED1_ALGO_H
#include <bits/std_function.h>

template <typename T>
void bubbleSort(T arr[], int arrSize) {
    for (int i=0; i<arrSize-1; i++) {
        for (int j=i+1; j<arrSize; j++) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
#endif //UNTITLED1_ALGO_H
