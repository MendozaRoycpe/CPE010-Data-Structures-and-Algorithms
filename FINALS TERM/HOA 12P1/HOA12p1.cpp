//
// Created by royga on 10/13/2026.
//
#include <iostream>
#include <algorithm>
#include <vector>

// Using a global or dynamically resized vector for memoization to avoid fixed-size array errors
const int MAX = 10005;
std::vector<int> memo(MAX, -1);

int getMinSteps(int n) {
    // Base case: 1 requires 0 steps
    if (n == 1) return 0;

    // Check if we have already solved it
    if (memo[n] != -1) return memo[n];

    // Option 1
    int r = 1 + getMinSteps(n - 1);

    // Option 2: Divide by 2
    if (n % 2 == 0) {
        r = std::min(r, 1 + getMinSteps(n / 2));
    }

    // Option 3
    if (n % 3 == 0) {
        r = std::min(r, 1 + getMinSteps(n / 3));
    }

    // Save the result in memoization table and return
    memo[n] = r;
    return r;
}

int main() {
    int n = 195;

    // Clear/reset memo table if running multiple test casesS
    fill(memo.begin(), memo.end(), -1);

    std::cout << "Minimum steps to reach 1 for " << n << " is: " << getMinSteps(n) << std::endl;

    return 0;
}