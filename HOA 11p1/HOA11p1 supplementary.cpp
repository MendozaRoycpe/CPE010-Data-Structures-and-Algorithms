//
// Created by royga on 10/6/2026.
//
#include <iostream>     // std::cout, std::endl for console output
#include <vector>       // std::vector, the container used for the test array
#include <chrono>       // std::chrono clocks and durations for timing
#include <algorithm>    // not used in this file (would be needed for std::sort-based Unique)

// PROBLEM 1: Uniqueness Algorithm
bool Unique(const std::vector<int>& A) {           // takes the vector by const reference: no copy, no modification
    int n = A.size();                              // store the number of elements (n)
    for (int i = 0; i < n; i++) {                  // outer loop: pick each element A[i] as the reference value
        for (int j = i + 1; j < n; j++) {          // inner loop: compare only against elements AFTER i (avoids self/duplicate pair checks)
            if (A[i] == A[j]) {                    // two different positions hold the same value
                return false; // Duplicate found, not unique
            }
        }
    }
    return true; // All elements are unique        // no pair matched after all n(n-1)/2 comparisons -> O(n^2) worst case
}


// PROBLEM 2: Recursive Power Functions
// Standard Linear Recursive Power: O(n)
long long rpower(long long x, int n) {             // computes x^n; x is the base, n is the exponent
    if (n == 0) {                                  // base case: any number to the power 0 is 1
        return 1;
    } else {
        return x * rpower(x, n - 1);               // x^n = x * x^(n-1); exponent drops by 1 each call -> n + 1 calls total
    }
}
long long brpower(long long x, int n) {            // binary recursive power: halves the exponent each call -> O(log n)
    if (n == 0) {                                  // base case: x^0 = 1
        return 1;
    }
    if (n % 2 != 0) { // If n is odd               // remainder 1 means n is odd
        long long y = brpower(x, (n - 1) / 2);     // y = x^((n-1)/2), computed ONCE and stored
        return x * y * y;                          // x^n = x * (x^((n-1)/2))^2
    } else { // If n is even                       // n is even
        long long y = brpower(x, n / 2);           // y = x^(n/2), computed ONCE and stored
        return y * y;                              // x^n = (x^(n/2))^2
    }
}




int main() {
    //Problem 1: Unique
    std::cout << "PROBLEM 1: UNIQUE ALGORITHM" << std::endl;                  // print the section header
    std::vector<int> test_array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  // 10 distinct values -> expected result: True

    auto start1 = std::chrono::steady_clock::now();    // timestamp before the call (steady_clock is monotonic)
    bool is_unique = Unique(test_array);               // run the algorithm and store the result
    auto end1 = std::chrono::steady_clock::now();      // timestamp after the call

    std::cout << "Array is unique? " << (is_unique ? "True" : "False") << std::endl;   // convert bool to text and print
    std::cout << "Time taken for Unique: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count()   // elapsed time converted to microseconds
<< " microseconds\n" << std::endl;       // unit label, then a blank line to separate sections


    //Testing Problem 2: rpower vs brpower
    std::cout << "PROBLEM 2: POWER FUNCTIONS" << std::endl;                    // print the section header
    long long base = 2;                                // base x = 2
    int exponent = 20; // Using a safe exponent to prevent overflow for linear rpower   // 2^20 = 1048576 fits easily in long long

    // Test standard rpower
    auto start_r = std::chrono::steady_clock::now();   // timestamp before rpower
    long long result_r = rpower(base, exponent);       // linear recursion: 21 calls (n = 20 down to 0)
    auto end_r = std::chrono::steady_clock::now();     // timestamp after rpower

    std::cout << "rpower(" << base << ", " << exponent << ") = " << result_r << std::endl;   // prints rpower(2, 20) = 1048576
    std::cout << "Time taken by rpower: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_r - start_r).count()   // elapsed time in nanoseconds
              << " nanoseconds" << std::endl;

    // Test optimized brpower
    auto start_br = std::chrono::steady_clock::now();  // timestamp before brpower
    long long result_br = brpower(base, exponent);     // binary recursion: 6 calls (n = 20, 10, 5, 2, 1, 0)
    auto end_br = std::chrono::steady_clock::now();    // timestamp after brpower

    std::cout << "brpower(" << base << ", " << exponent << ") = " << result_br << std::endl;   // prints brpower(2, 20) = 1048576 (same as rpower)
    std::cout << "Time taken by brpower: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_br - start_br).count()   // elapsed time in nanoseconds
              << " nanoseconds" << std::endl;

    return 0;                                          // 0 = program ended successfully
}