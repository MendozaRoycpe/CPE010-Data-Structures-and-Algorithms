//
// Created by royga on 10/15/2026.
//
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>

void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    std::cout << msg << std::endl;
}

int main() {
    std::vector<std::string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };

    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, i, s[i]));
    }

    for (auto &th : threads) {
        th.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nExecution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}