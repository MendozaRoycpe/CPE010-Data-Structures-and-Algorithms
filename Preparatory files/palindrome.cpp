//
// Created by royga on 8/27/2026.
//
#include <iostream>
#include <string>
#include "palindrome.h"

int main() {
    std::string input;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        std::cout << "Enter a word or phrase to check: ";
        std::getline(std::cin, input);

        if (isPalindrome(input)) {
            std::cout << "\"" << input << "\" is a palindrome!\n";
        } else {
            std::cout << "\"" << input << "\" is NOT a palindrome.\n";
        }

        std::cout << "Check another? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();   // clear the leftover newline before the next getline
    }

    std::cout << "Goodbye!\n";
    return 0;
}