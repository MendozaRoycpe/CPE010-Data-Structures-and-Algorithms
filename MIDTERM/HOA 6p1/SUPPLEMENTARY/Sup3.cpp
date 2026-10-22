//
// Created by royga on 8/24/2026.
//
#include <iostream>
#include "searchingalgo.h"

int main()
{
    // Sorted list given in Problem 3.
    int data[10] ={3, 5, 6, 8, 11,12, 14, 15, 17, 18};

    // Search key.
    int key = 8;

    // Display the list.
    std::cout << "Sorted List:\n";

    for (int i = 0; i < 10; i++)
    {
        std::cout << data[i] << " ";
    }

    std::cout << "\n\nSearching for: "
              << key << "\n";

    // Call binary search.
    binarySearch(data, 10, key);

    return 0;
}