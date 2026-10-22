//
// Created by royga on 9/21/2026.
//
#include <iostream>
#include "bst.h"

int main() {
    //Step 1: Implement a binary search tree that will take the following values: 2, 3, 9, 18, 0, 1, 4, 5.
    baiSerTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    //Step 3: Compare the different traversal methods. In-order traversal was performed with what function?
    std::cout << "In-order:   ";
    tree.inOrder();

    std::cout << "\nPre-order:  ";
    tree.preOrder();

    std::cout << "\nPost-order: ";
    tree.postOrder();
    std::cout << "\n";

    return 0;
}