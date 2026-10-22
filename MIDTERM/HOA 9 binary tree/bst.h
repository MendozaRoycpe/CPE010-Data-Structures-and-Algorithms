//
// Created by royga on 9/17/2026.
//

#ifndef UNTITLED1_BST_H
#define UNTITLED1_BST_H

#include <iostream>

template <typename T>
class baiSerTree {
private:
    T key;
    baiSerTree<T>* left;
    baiSerTree<T>* right;

public:
    // Constructor
    baiSerTree(T value);

    // Destructor
    ~baiSerTree();

    // Insert function
    void insert(T value);

    // Traversing algorithms
    void preOrder();
    void inOrder();
    void postOrder();
};

template <typename T>
baiSerTree<T>::baiSerTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
baiSerTree<T>::~baiSerTree() {
    delete left;
    delete right;
}

template <typename T>
void baiSerTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new baiSerTree<T>(value);
        } else {
            left->insert(value);
        }
    } else if (value > key) {
        if (right == nullptr) {
            right = new baiSerTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

// Pre-order: Root -> Left -> Right
template <typename T>
void baiSerTree<T>::preOrder() {
    std::cout << key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

// In-order: Left -> Root -> Right
template <typename T>
void baiSerTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

// Post-order: Left -> Right -> Root
template <typename T>
void baiSerTree<T>::postOrder() {
    if (left != nullptr) {
        left->postOrder();
    }
    if (right != nullptr) {
        right->postOrder();
    }
    std::cout << key << " ";
}

#endif //UNTITLED1_BST_H