//
// Created by royga on 8/27/2026.
//
#include <iostream>
#include "arraycheckere.h"

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {7, 8, 9};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Array 1 has " << size1 << " elements.\n";
    std::cout << "Array 2 has " << size2 << " elements.\n";
    std::cout << "Array 3 has " << size3 << " elements.\n\n";

    std::cout << "Comparing Array 1 and Array 2:\n";
    checkArraySizes(size1, size2);

    std::cout << "\nComparing Array 1 and Array 3:\n";
    checkArraySizes(size1, size3);

    return 0;
}