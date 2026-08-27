//
// Created by royga on 8/27/2026.
//

#ifndef UNTITLED1_ARRSTACK_H
#define UNTITLED1_ARRSTACK_H
#include <iostream>
#include <string>

//====================================================
// ARRAY-BASED STACK
/*
void push();  check
void pop(); check
void Top(); check
bool isEmpty(); check
bool isFull(); check
void prinAll(); check
*/
//====================================================
// A. STACK USING ARRAYS

template <typename T>
class arrStack {
private:
    T* stackArray;
    int cap;
    int top;

public:
    arrStack(int size = 10) {
        // setting the maximum size of the stack
        cap = size;
        stackArray = new T[cap];// Array that will store the symbols
        top = -1;// Indexing the top element
    }

//------------------------------------------------
// Check if the stack is empty
bool isEmpty(){
    return (top == -1);
}
//------------------------------------------------
// Checking if the stack is full
bool isFull(){
    return (top == cap - 1);
}
//------------------------------------------------
// Display the top element
T Top()const{
    if (isEmpty()){
        std::cout << "Stack is Empty.\n";
        return T();
    }
    return stackArray[top];
}
//------------------------------------------------
// Push a character onto the stack
void push(T value){
    // Prevent overflow
    if (isFull()){
        std::cout << "Stack Overflow!\n";
        return;
    }
    // Move top then insert the value
    stackArray[++top] = value;
}
//------------------------------------------------
// Remove the top/last inputted elemetn
T pop(){
    // Prevent underflow
    if (isEmpty()){
        std::cout << "Stack Underflow!\n";
        return T();
    }

    // Return current top then decrease top
    return stackArray[top--];
}
//------------------------------------------------
// Display all elements
void displayAll(){
    if (isEmpty()){
        std::cout << "Stack is Empty.\n";
        return;
    }
    std::cout << "Stack Contents (Top to Bottom)\n";

    for (int i = top; i >= 0; i--){
        std::cout << "|" << stackArray[i] << "|" << std::endl;
    }
}
//------------------------------------------------
// Reset the stack
void clear() {
        top = -1;
    }

//------------------------------------------------
    //Destructor
~arrStack() {
    // Release the dynamically allocated array
    delete[] stackArray;
}
};

#endif // UNTITLED1_ARRSTACK_H