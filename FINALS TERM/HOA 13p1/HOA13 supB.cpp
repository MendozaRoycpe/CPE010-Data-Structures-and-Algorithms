//
// Created by royga on 10/19/2026.
//
#include <iostream>
#include <thread>

// GLobal variable
int globalVar = 0;

//Add function
void add(int value) {
    globalVar += value;
}

int main() {
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    // Display the value of global variable before joins
    std::cout << "Value before any join(): " << globalVar << std::endl;

    // T1.join()
    t1.join();
    // Display
    std::cout << "Value after T1.join(): " << globalVar << std::endl;

    // T2.join()
    t2.join();
    // Display
    std::cout << "Value after T2.join(): " << globalVar << std::endl;

    // T3.join()
    t3.join();
    // Display (final confirmation)
    std::cout << "Value after T3.join(): " << globalVar << std::endl;

    return 0;
}