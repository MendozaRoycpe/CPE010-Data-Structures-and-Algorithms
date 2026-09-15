//
// Created by royga on 9/15/2026.
//
#include <iostream>
#include "header .h"

int main() {
    // Create the root node 'A'
    BinaryTree<char>* root = new BinaryTree<char>('A');

    // Create children of A (using lowercase insertleft / insertright)
    root->insertleft('B');
    root->insertright('C');

    // Create children of B
    root->getLeftChild()->insertleft('D');
    root->getLeftChild()->insertright('E');

    // Create children of C (C has 'F' on the left, nullptr on the right)
    root->getRightChild()->insertleft('F');

    // Verification output
    std::cout << "Root: " << root->getRootVal() << '\n';
    std::cout << "Left child of A: " << root->getLeftChild()->getRootVal() << '\n';
    std::cout << "Right child of A: " << root->getRightChild()->getRootVal() << '\n';
    std::cout << "Left child of B: " << root->getLeftChild()->getLeftChild()->getRootVal() << '\n';
    std::cout << "Right child of B: " << root->getLeftChild()->getRightChild()->getRootVal() << '\n';
    std::cout << "Left child of C: " << root->getRightChild()->getLeftChild()->getRootVal() << '\n';

    // Optional: Clean up heap memory if you don't rely solely on scope
    delete root;

    return 0;
}