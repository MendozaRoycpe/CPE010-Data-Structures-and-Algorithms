//
// Created by royga on 9/10/2026.
//

#ifndef UNTITLED1_SORTALGO_H
#define UNTITLED1_SORTALGO_H
#include <iostream>

//=====================================================================================================================
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
        }}}

//=====================================================================================================================
//merge sort
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int size = right - left + 1;// number of elements in the full range [left, right]
    T* temp = new T[size];    // heap-allocated temp array sized to hold the merged result

    int i = left;             // i walks through the left half, starting at 'left'
    int j = middle + 1;       // j walks through the right half, starting right after 'middle'
    int temp_pos = 0;         // temp_pos tracks the next free slot in temp[]

    while (i <= middle && j <= right) { // loop while both halves still have unprocessed elements
        if (arr[i] < arr[j]) {          // if left half's front element is smaller
            temp[temp_pos] = arr[i];    // copy it into temp[]
            i++;                        // advance the left-half pointer
            temp_pos++;                 // advance the temp[] write position
        } else {                        // otherwise right half's front element is smaller or equal
            temp[temp_pos] = arr[j];    // copy it into temp[]
            j++;                       // advance the right-half pointer
            temp_pos++;                // advance the temp[] write position
        }
    }while (i <= middle) {             // if the right half ran out first, drain the rest of the left half
        temp[temp_pos] = arr[i];        // copy leftover left-half element into temp[]
        i++;                            // advance the left-half pointer
        temp_pos++;                     // advance the temp[] write position
    }while (j <= right) {                // if the left half ran out first, drain the rest of the right half
        temp[temp_pos] = arr[j];            // copy leftover right-half element into temp[]
        j++;                            // advance the right-half pointer
        temp_pos++;                     // advance the temp[] write position
    }
    int k = 0;                          // k indexes back through temp[] from the start
    for (int i = left; i <= right; i++) {// walk arr[] across the same range [left, right]
        arr[i] = temp[k];                // copy the merged, sorted value back into arr[]
        k++;                            // advance to the next value in temp[]
    }
    delete[] temp;                       // free the heap memory allocated for temp[], now that it's copied back
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left >= right) {
        return;                              // base case: a range with 0 or 1 element is already sorted
    }

    int middle = (left + right) / 2;             // midpoint of the current range
    mergeSort(arr, left, middle);         // recursively sort the left half
    mergeSort(arr, middle + 1, right);    // recursively sort the right half
    merge(arr, left, middle, right);         // merge the two now-sorted halves back together
}

//=====================================================================================================================
//quicksort
template <typename T>
int partition(T arr[], int left, int right) {
    T pivot = arr[right];               // choose the last element of the range as the pivot value
    int low = left - 1;             // 'low' starts just before the range, scans forward for elements >= pivot
    int high = right;               // 'high' starts just after the range, scans backward for elements <= pivot

    while (true) {
        do{
            low++;                          // advance low rightward
        } while(arr[low] < pivot);          // keep going while elements are already correctly placed (< pivot)
        do {
            high--;                         // advance high leftward
        } while (high > left && arr[high] > pivot); // keep going while elements are already correctly placed (> pivot), guarded so high can't pass left
        if (low >= high) {
            break;                              // low and high have crossed/met: partitioning is complete, nothing left to swap
        }
        T tempSwap = arr[low];                      // low is on an element that belongs on the right, high is on one that belongs on the left
        arr[low] = arr[high];                           // swap them so each lands on its correct side
        arr[high] = tempSwap;                       // complete the swap
    }
    T tempPivot = arr[low];                     // 'low' now points to the first element of the "greater than or equal" region
    arr[low] = arr[right];                      // move the pivot (still at arr[right]) into that spot — its final sorted position
    arr[right] = tempPivot;                     // complete the swap
    return low;                                 // return the pivot's final index so the caller knows where to split the array
}

// Recursively sorts arr[left..right] using the quicksort algorithm
template <typename T>
void quickSort(T arr[], int left, int right) {
    if (left >= right) {
        return;                                     // base case: a range with 0 or 1 element is already sorted
    }
    int pivotIndex = partition(arr, left, right);       // partition the range and get the pivot's final index
    quickSort(arr, left, pivotIndex - 1);           // recursively sort the sub-array left of the pivot (elements smaller than pivot)
    quickSort(arr, pivotIndex + 1, right);           // recursively sort the sub-array right of the pivot (elements greater than pivot)
}

// Overload so callers can write quickSort(arr, n) instead of quickSort(arr, 0, n - 1)
template <typename T>
void quickSort(T arr[], int n) {
    quickSort(arr, 0, n - 1);                   // delegate to the three-argument version, sorting the full array
}
#endif //UNTITLED1_SORTALGO_H