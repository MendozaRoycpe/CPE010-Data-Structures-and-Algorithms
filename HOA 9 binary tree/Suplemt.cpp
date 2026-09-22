//
// Created by royga on 9/21/2026.
//
#include <iostream>
#include "genTree.h"
#include <string>

int main() {
    genTree<int> tree(2);

    // Children of
    genTree<int>* n3  = tree.insert(3);
    genTree<int>* n18 = tree.insert(18);

    // Children of 3
    n3->insert(9);

    // Children of 18
    n18->insert(0);
    n18->insert(1);
    n18->insert(4);
    n18->insert(5);

    tree.printTree();

    std::cout << "\nPre-order:  ";
    tree.preOrder();

    std::cout << "\nPost-order: ";
    tree.postOrder();

    std::cout << "\nIn-order:   ";
    tree.inOrder();

    return 0;
}