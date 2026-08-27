//
// Created by royga on 8/27/2026.
//

#ifndef UNTITLED1_ARRAYCHECKERE_H
#define UNTITLED1_ARRAYCHECKERE_H
#include <iostream>

// Checks whether two arrays have the same number of elements.
// Takes the sizes directly, since a plain array loses its size
// once it's passed into a function (it decays to a pointer).
inline bool checkArraySizes(int size1, int size2) {
    if (size1 == size2) {
        std::cout << "The arrays are equal! Both have " << size1 << " elements.\n";
        return true;
    } else {
        std::cout << "The arrays are NOT equal. Array 1 has " << size1
                   << " elements, Array 2 has " << size2 << " elements.\n";
        return false;
    }
}

#endif //UNTITLED1_ARRAYCHECKERE_H
