//
// Created by royga on 9/17/2026.
//

#include <iostream>
#include "bst.h"

int main() {

//node
    baiSerTree<int> tree(20);

    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(15);

    //tree.preOrder();
    //tree.inOrder();
    tree.postOrder();
    return 0;
};