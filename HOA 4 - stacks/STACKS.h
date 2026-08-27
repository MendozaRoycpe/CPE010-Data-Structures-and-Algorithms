#ifndef UNTITLED1_STACKS_H
#define UNTITLED1_STACKS_H
#include <iostream>

template <typename T>
class Node {
    public:
    T data;             // value we need to store
    Node* next = nullptr;  // pointer to the next node, defaults to null
};

//create a global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;

//===================================
//operations for the stack
//===================================
//push
template <typename T>
void push(T newData) {
    //create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;

    //new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

//pop
template <typename T>
T pop() {
    //stopping if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack underflow!" << std::endl;
        return T();
    }

    //save the current top node
    Node<T>* temp = head<T>;

    //store its data
    T tempVal = temp->data;

    //move the head to the next node
    head<T> = head<T>->next;

    //free the removed node
    delete temp;

    //return the removed value
    return tempVal;
}

//isEmpty
template <typename T>
bool isEMPT() {
    return head<T> == nullptr;
}

//top
template <typename T>
void top() {
    //create error catching:
    if (isEMPT<T>()){
        std::cout << "Stack underflow" << std::endl;
        return;
    }
    //display the top node
    std::cout << "Top of stack is: "<< "|" << head<T>->data << "|"<< std::endl;
}

//displayAll
template <typename T>
void displayAll() {
    if (isEMPT<T>()) {
        std::cout <<"Stack is empty" <<std::endl;
        return;
    }
    std::cout <<"Stack contents (top to bottom): ";
    Node<T>* temp= head<T>;
    while (temp !=nullptr) {
        std::cout <<"\n|"<< temp->data<<"| ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif //UNTITLED1_STACKS_H