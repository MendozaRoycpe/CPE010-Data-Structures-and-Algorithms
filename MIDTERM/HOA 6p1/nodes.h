//
// Created by royga on 8/18/2026.
//
#ifndef UNTITLED1_NODES_H
#define UNTITLED1_NODES_H

template <typename T>
class Node {
    public:
    T data;
    Node *next;
};

// CREATING NEW NODE
template <typename T>
Node<T> *new_node(T newData) {
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

#endif //UNTITLED1_NODES_H