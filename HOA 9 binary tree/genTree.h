//
// Created by royga on 9/19/2026.
//

#ifndef UNTITLED1_GENTREE_H
#define UNTITLED1_GENTREE_H

#include <iostream>
template <typename T>
class genTree {
private:
    T key;
    genTree<T>* firCld;
    genTree<T>* nxtSib;

    bool preOrder(T value);
    bool postOrder(T value);
    bool inOrder(T value);

public:
    // Constructor
    genTree(T value);

    // Destructor
    ~genTree();

    genTree<T>* insert(T value);
    genTree<T>* find(T value);


    void preOrder();
    void postOrder();
    void inOrder();

    void printTree(int depth = 0);
    void findData(int choice, T value);
};

template <typename T>
genTree<T>::genTree(T value) {
    key = value;
    firCld = nullptr;
    nxtSib = nullptr;
}

template <typename T>
genTree<T>::~genTree() {
    delete firCld;
    delete nxtSib;
}

template <typename T>
genTree<T>* genTree<T>::insert(T value) {
    genTree<T>* node = new genTree<T>(value);

    if (firCld == nullptr) {
        firCld = node;
    } else {
        genTree<T>* current = firCld;
        while (current->nxtSib != nullptr) {
            current = current->nxtSib;
        }
        current->nxtSib = node;
    }
    return node;
}

template <typename T>
genTree<T>* genTree<T>::find(T value) {
    if (key == value) {
        return this;
    }
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        genTree<T>* result = child->find(value);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

// Pre-order
template <typename T>
void genTree<T>::preOrder() {
    std::cout << key << " ";
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->preOrder();
    }
}

// Post-order
template <typename T>
void genTree<T>::postOrder() {
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->postOrder();
    }
    std::cout << key << " ";
}

// In-order
template <typename T>
void genTree<T>::inOrder() {
    if (firCld == nullptr) {
        std::cout << key << " ";
        return;
    }
    firCld->inOrder();
    std::cout << key << " ";
    for (genTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        child->inOrder();
    }
}

template <typename T>
void genTree<T>::printTree(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << key << "\n";
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->printTree(depth + 1);
    }
}

// Pre-order
template <typename T>
bool genTree<T>::preOrder(T value) {
    if (key == value) {
        return true;
    }
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->preOrder(value)) {
            return true;
        }
    }
    return false;
}

// Post-order
template <typename T>
bool genTree<T>::postOrder(T value) {
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->postOrder(value)) {
            return true;
        }
    }
    return key == value;
}

// In-order
template <typename T>
bool genTree<T>::inOrder(T value) {
    if (firCld == nullptr) {
        return key == value;
    }
    if (firCld->inOrder(value)) {
        return true;
    }
    if (key == value) {
        return true;
    }
    for (genTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        if (child->inOrder(value)) {
            return true;
        }
    }
    return false;
}

template <typename T>
void genTree<T>::findData(int choice, T value) {
    bool found = false;

    switch (choice) {
        case 1:found=preOrder(value);
            break;
        case 2:found=postOrder(value);
            break;
        case 3:found= inOrder(value);
            break;
        default:
            return;
    }
    if (found) {
        std::cout <<"["<< value << "]was found!" << "\n";
    }
}

#endif //UNTITLED1_GENTREE_H