//
// Created by royga on 8/4/2026.
//

#ifndef UNTITLED1_QUEUELL_H
#define UNTITLED1_QUEUELL_H

template<typename T>
class qNode {
public:
    T data;
    qNode<T> *next;
};

//creating a new node:
template <typename T>
qNode<T>* new_Node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

//pushing from the back
template <typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData) {
    //create a new node;
    qNode<T>* newNode = new_Node(newData);

    //inserting to an empty queue
    if ((*frontPtr) == nullptr&&(*backPtr) == nullptr ) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    //inserting an item into a non empty queue
    //point the backPtr next to the newNode
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {

 //create a temporary node to store the node to be deleted
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    //check if the queue is only 1 node
    if((*frontPtr)->next==nullptr && (*backPtr)->next==nullptr) {
        (*frontPtr)= nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    //deleting of the node
    (*frontPtr)= deleteNode->next;
    delete deleteNode;
}

//display all elements in the list
template <typename T>
void display(qNode<T>* frontPtr) {
    qNode<T>* current = frontPtr;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

//return the front element
template <typename T>
T top1st(qNode<T>* frontPtr) {
    if (frontPtr == nullptr) {
        throw std::runtime_error("Queue is empty");
    }
    return frontPtr->data;
}

#endif //UNTITLED1_QUEUELL_H
