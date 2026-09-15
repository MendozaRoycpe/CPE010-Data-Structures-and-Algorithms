//
// Created by royga on 9/15/2026.
//

#ifndef UNTITLED1_HEADER_H
#define UNTITLED1_HEADER_H

#include <iostream>
#include <string>

template <typename T>
class BinaryTree {
private:
    T key;                      // Stores the data/value of the node
    BinaryTree<T> *leftChild;   // Pointer to the left child subtree/node
    BinaryTree<T> *rightChild;  // Pointer to the right child subtree/node

public:
    // Constructor
    BinaryTree(T rootObj);

    // Destructor
    ~BinaryTree();

    // Insert childrens - Pushes any existing child down and inserts the new node above it
    void insertleft(T newNode);
    void insertright(T newNode);

    // Accessing the child
    BinaryTree<T> *getLeftChild();
    BinaryTree<T> *getRightChild();

    // Get and set node value
    void setRootVal(T obj);
    T getRootVal();

    // Checker for leaf
    bool isLeaf();
};

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj) {
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}

// Destructor implementation to clean up heap memory
template <typename T>
BinaryTree<T>::~BinaryTree() {
    delete leftChild;
    delete rightChild;
}

// Inserting left: Pushes existing left child down if one already exists
template <typename T>
void BinaryTree<T>::insertleft(T newNode) {
    if (leftChild == nullptr) {
        leftChild = new BinaryTree<T>(newNode);
    } else {
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
        newChild->leftChild = leftChild; // Moves the existing left child below the new node
        leftChild = newChild;            // Makes the new node the left child
    }
}

// Inserting right: Pushes existing right child down if one already exists
template <typename T>
void BinaryTree<T>::insertright(T newNode) {
    if (rightChild == nullptr) {
        rightChild = new BinaryTree<T>(newNode);
    } else {
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);
        newChild->rightChild = rightChild; // Moves the existing right child below the new node
        rightChild = newChild;             // Makes the new node the right child
    }
}

// Accessing the left child pointer
template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
    return leftChild;
}

// Accessing the right child pointer
template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
    return rightChild;
}

// Setting the value of the node's key
template <typename T>
void BinaryTree<T>::setRootVal(T obj) {
    key = obj;
}

// Getting the value of the node's key
template <typename T>
T BinaryTree<T>::getRootVal() {
    return key;
}

// Checking if the node is a leaf (has no left or right children)
template <typename T>
bool BinaryTree<T>::isLeaf() {
    return (leftChild == nullptr && rightChild == nullptr);
}

#endif // UNTITLED1_HEADER_H