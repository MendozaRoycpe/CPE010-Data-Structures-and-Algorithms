//
// Created by royga on 8/27/2026.
//

#ifndef UNTITLED1_PALINDROME_H
#define UNTITLED1_PALINDROME_H
#include <iostream>
#include <string>

// Simple array-based stack of characters, used to check palindromes
class CharStack {
private:
    char* stackArr;
    int capacity;
    int top;

public:
    CharStack(int cap = 1000) {
        capacity = cap;
        stackArr = new char[capacity];
        top = -1;
    }

    ~CharStack() {
        delete[] stackArr;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(char c) {
        stackArr[++top] = c;
    }

    char pop() {
        return stackArr[top--];
    }
};

// Checks whether the given string is a palindrome, using a stack.
// Push every character on, then pop them off (comes out reversed)
// and compare against the original string read forward -- if every
// position matches, the string reads the same both ways.
inline bool isPalindrome(const std::string& input) {
    CharStack stack((int)input.length() + 1);

    for (int i = 0; i < (int)input.length(); i++) {
        stack.push(input[i]);
    }

    for (int i = 0; i < (int)input.length(); i++) {
        char popped = stack.pop();
        if (popped != input[i]) {
            return false;
        }
    }

    return true;
}

#endif //UNTITLED1_PALINDROME_H
