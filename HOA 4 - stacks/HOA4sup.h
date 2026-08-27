//
// Created by royga on 7/30/2026.
//

#ifndef UNTITLED1_HOA4SUP_H
#define UNTITLED1_HOA4SUP_H
#include <iostream>
/*
void push();  check
void pop(); check
void Top(); check
bool isEmpty(); check
bool isFull(); check
void prinAll();
*/
//====================================================
// A. STACK USING ARRAYS
const int cap = 100; // setting the maximum size of the stack
char stack[cap];// Array that will store the symbols

int top = -1; // Indexing the top element
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
char Top(){
    if (isEmpty()){
        std::cout << "Stack is Empty.\n";
        return '\0';
    }
    return stack[top];
}
//------------------------------------------------
// Push a character onto the stack
void push(char value){
    // Prevent overflow
    if (isFull()){
        std::cout << "Stack Overflow!\n";
        return;
    }
    // Move top then insert the value
    stack[++top] = value;
}
//------------------------------------------------
// Remove the top/last inputted elemetn
char pop(){
    // Prevent underflow
    if (isEmpty()){
        std::cout << "Stack Underflow!\n";
        return '\0';
    }

    // Return current top then decrease top
    return stack[top--];
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
        std::cout << "|" << stack[i] << "|" << std::endl;
    }
}

//------------------------------------------------
// Reset the stack
void clear(){
    top = -1;
}
//====================================================
// B. STACK USING LINKED LIST

template <typename T>
class Node {
        public:
        T data;
        Node<T> *next= nullptr;
    };

//create a global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;

//checks if the stack is empty
template <typename T>
bool isEmptyll() {
    return head<T> == nullptr;
}

//push new value to the stakc
template <typename T>
void pushll(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}
//removing the top elemetn
template <typename T>
T popll() {
    if (isEmptyll<T>()) {
        std::cout << "Stack Underflow!\n";
        return T();
    }
    Node<T>* temp = head<T>;
    T tempValue=temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempValue;
}
//display the top element
template <typename T>
void Topll() {
    if (isEmptyll<T>()) {
        std::cout << "Stack Underflow!\n";
        return;
    }

    std::cout<< "Top of Stack: "<< head<T>->data<< std::endl;
}
//display the elements
template <typename T>
void displayll(){
    if (isEmptyll<T>()) {
        std::cout<<"Empty Stack\n";
        return;
    }
    std::cout<< "Stack Contents (Top to Bottom)\n";
    Node<T>* current = head<T>;

    while (current != nullptr) {
        std::cout<<current->data<<std::endl;
        current = current->next;
    }
}
//removal
template <typename T>
void clearll() {
    while (!isEmptyll<T>()) {
        popll<T>();
    }
}



#endif //UNTITLED1_STACKS_H