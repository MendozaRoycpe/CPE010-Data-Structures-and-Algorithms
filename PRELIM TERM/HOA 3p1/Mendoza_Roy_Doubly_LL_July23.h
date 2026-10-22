//
// Created by royga on 7/23/2026.
//

#ifndef UNTITLED1_MENDOZA_ROY_DOUBLY_LL_JULY23_H
#define UNTITLED1_MENDOZA_ROY_DOUBLY_LL_JULY23_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data; //storing the value held by the node
    doubleList<T>* next = nullptr; // defaults the next node to null
    doubleList<T>* prev = nullptr;//defaults the prev node to null
};

// Creating a node function
template <typename T>
doubleList<T>* newNode(T newData) {
    // dynamically allocate a new node
    doubleList<T>* node = new doubleList<T>;
    // store the data in the node
    node->data = newData;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}
template <typename T>
void dllTraverse(doubleList<T>* currentNode) {
    doubleList<T>* tail = nullptr;

    //forward trvarsal
    std::cout<< "Forward Traversal \n";
    while (currentNode != nullptr) {
        std::cout<< currentNode->data << " ";
        tail=currentNode;
        currentNode = currentNode->next;
    }
    std::cout<< std::endl;

    // reverse traversal
    std::cout<< "Reverse Traversal \n";
    while (tail!= nullptr) {
        std::cout<<tail->data << " ";
        tail= tail->prev;
    }
    std::cout<< std::endl;
}

// insertion at the head
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {
    // create a new node
    doubleList<T>* node= newNode<T>(newData);

    // set the new node to point to the current head
    node->next= *currentHead;

    if (*currentHead != nullptr) {
        (*currentHead)->prev=node;
    }
    // update the head pointer
    *currentHead=node;
}

// insertion at the end
template <typename T>
void dllInsertEnd(T newData, doubleList<T>** head) {
    // create a new node
    doubleList<T>*node =newNode<T>(newData);

    // if the list is empty, the new node becomes the head
    if (*head==nullptr) {
        *head=node;
        return;
    }

    // traverse until reaching the last node
    doubleList<T>* currentNode=*head;
    while (currentNode->next!=nullptr) {
        currentNode=currentNode->next;
    }

    // connect the last node to the new node
    currentNode->next=node;

    // connect the prev node back to the last node
    node->prev=currentNode;
}
//====================
//general insertion
//====================
template <typename T>
void dllGenInsertion(T newData, doubleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout<< "Node does not exist"<<std::endl;
        return;
    }
    //create new node:
    doubleList<T>* node = newNode<T>(newData);
    //connecting new node to wahtever came after prenode
    node->next = prevNode->next;
    // connect new node to prevnode
    node->prev = prevNode;

    //if there was a node after prevNode, point its prev back to the new node
    if(prevNode-> next!=nullptr) {
        prevNode -> next -> prev =node;
    }
    prevNode-> next = node;
}

//====================
//deletion
//====================
template <typename T>
void dllDelete(T findData, doubleList<T>** head) {
    //stopping if the list is empty
    if(*head == nullptr)return;

    //start from the head
    doubleList<T>* currentNode = *head;

    //search until the value is found or end of list is reached
    while(currentNode != nullptr&&currentNode->data != findData) {
        currentNode = currentNode->next;
    }
    //when the value is not found
    if(currentNode == nullptr)return;

    // if there is a node before the one we're deleting, link it to the node after it
    if(currentNode->prev!=nullptr) {
        currentNode->prev->next = currentNode->next;
        } else{
            //updating the head pointer
            *head = currentNode->next;
    }
    //if there is a node after the one being deleted, link it tot he before to complete doubly
    if(currentNode->next!=nullptr) {
        currentNode-> next -> prev = currentNode->prev;
    }
//deletion proepr
    delete currentNode;
}

#endif //UNTITLED1_MENDOZA_ROY_DOUBLY_LL_JULY23_H