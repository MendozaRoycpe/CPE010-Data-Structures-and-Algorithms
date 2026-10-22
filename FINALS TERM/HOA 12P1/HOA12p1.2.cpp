//
// Created by royga on 10/13/2026.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int getMinSteps(int n) {
    if (n <= 1) return 0;

    std::vector<int> dp(n + 1);
    dp[1] = 0; // base case

    for (int i = 2; i <= n; i++) {
        int res = dp[i - 1]; // option 1: subtract 1

        if (i % 2 == 0) {
            res = std::min(res, dp[i / 2]); // option 2: divide by 2
        }
        if (i % 3 == 0) {
            res = std::min(res, dp[i / 3]); // option 3: divide by 3
        }

        dp[i] = 1 + res; // add 1 step for the chosen operation
    }

    return dp[n];
}

int main() {
    int n = 148;
    std::cout << "Minimum steps to reach 1 for " << n << " is: " << getMinSteps(n) << std::endl;
    return 0;
}