//
// Created by royga on 8/25/2026.
//
// Sorted list given in the activity.

#include <iostream>
#include "searchingalgo.h"
int main() {
    int data[10] ={3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    // Search element.
    int key = 8;
    // Display the sorted list.
    std::cout << "Sorted List:\n";

    for (int i = 0; i < 10; i++){
        std::cout << data[i] << " ";
    }

    std::cout << "\n\nSearching for: "<< key << "\n";

    // Call the recursive binary search.
    int result = binarySearchRecursive(data, 0, 9, key);

    // Check whether the search was unsuccessful.
    if (result == -1){
        std::cout << "\nSearch element is not found.\n";
    }

    return 0;
}