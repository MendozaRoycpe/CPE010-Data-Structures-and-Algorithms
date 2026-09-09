//
// Created by royga on 9/8/2026.
//

#ifndef UNTITLED1_ALGO_H
#define UNTITLED1_ALGO_H

template <typename T>
void bubbleSort(T arr[], int arrSize) {
    for (int i=0; i<arrSize-1; i++) {
        for (int j=i+1; j<arrSize; j++) {
            if (arr[j] > arr[i]) {//here can change if descending or ascending depending if < or >
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize) {
    int k=0, j;
    T temp;

    while (k<arrSize){
        temp=arr[k];
        j = k-1;
        while (j>=0 && temp < arr[j]) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= temp;
        k++;
    }
}

template <typename T>
int routine_smallest(const T A[], int max_size, int k) {
    int position = k; // Initialize position to k in case A[k] is already the smallest
    T smallestElement = A[k];

    for (int j = k + 1; j < max_size; j++) {
        if (A[j] < smallestElement) {
            smallestElement = A[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        int pos = routine_smallest(arr, arrSize, i);

        // Clean swap using T instead of int
        std::swap(arr[i], arr[pos]);
    }
}
#endif //UNTITLED1_ALGO_H