//
// Created by royga on 10/15/2026.
//
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void print(int n, const std::string &str) {
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1(print, 10, "T.I.P.");
    t1.join();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\nExecution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}