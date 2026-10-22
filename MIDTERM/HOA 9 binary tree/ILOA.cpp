//
// Created by royga on 9/19/2026.
//
#include <iostream>
#include "genTree.h"

int main() {
    genTree<char> tree('A');//ROOT

    //CHILDS OF A
    tree.insert('B');
    tree.insert('C');
    genTree<char>* D = tree.insert('D');
    genTree<char>* E = tree.insert('E');
    genTree<char>* F = tree.insert('F');
    genTree<char>* G = tree.insert('G');

    //grandchild of A
    D->insert('H');
    E->insert('I');
    genTree<char>* J = E->insert('J');
    F->insert('K');
    F->insert('L');
    F->insert('M');
    G->insert('N');

    // Greatgrand of A
    J->insert('P');
    J->insert('Q');
    tree.printTree();

    // TASK 3.2
    std::cout << "\nPre-order:  ";
    tree.preOrder();
    std::cout << "\nPost-order: ";
    tree.postOrder();
    std::cout << "\nIn-order:   ";
    tree.inOrder();
    std::cout << "\n";

    // TASK 3.3-find data: 1=pre:::: 2=post;;; 3=in
    std::cout << "\nfindData:\n";
    tree.findData(1, 'J');
    tree.findData(2, 'J');
    tree.findData(3, 'J');
    tree.findData(4, 'J');
    tree.findData(1, 'W');


    G->insert('O');

    // TASK 3.4 find O
    std::cout << "\nAfter adding O:\n";
    tree.findData(1, 'O');
    tree.findData(2, 'O');
    tree.findData(3, 'O');

    std::cout << "\nPre-order:  ";
    tree.preOrder();
    std::cout << "\nPost-order: ";
    tree.postOrder();
    std::cout << "\nIn-order:   ";
    tree.inOrder();
    std::cout << "\n";

    return 0;
}