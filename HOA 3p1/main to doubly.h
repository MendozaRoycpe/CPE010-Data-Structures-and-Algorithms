#ifndef UNTITLED1_MAIN_TO_DOUBLY_H
#define UNTITLED1_MAIN_TO_DOUBLY_H
#include <iostream>

//========================
// Node Class
//========================
template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

//========================
// Create a New Node
//========================
template <typename T>
doubleList<T>* newNode(T newData)
{
    doubleList<T>* node = new doubleList<T>;

    node->data = newData;
    node->next = nullptr;
    node->prev = nullptr;

    return node;
}

//========================
// Traversal
//========================
template <typename T>
void dllTraverse(doubleList<T>* currentNode)
{
    doubleList<T>* tail = nullptr;

    std::cout << "Forward Traversal\n";

    while(currentNode != nullptr)
    {
        std::cout << currentNode->data;

        if(currentNode->next != nullptr)
            std::cout << " --> ";

        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    std::cout << "Reverse Traversal\n";

    while(tail != nullptr)
    {
        std::cout << tail->data;

        if(tail->prev != nullptr)
            std::cout << " --> ";

        tail = tail->prev;
    }

    std::cout << std::endl;
}

//========================
// Insert Head
//========================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** head)
{
    doubleList<T>* node = newNode<T>(newData);

    node->next = *head;

    if(*head != nullptr)
    {
        (*head)->prev = node;
    }

    *head = node;
}

//========================
// General Insertion
//========================
template <typename T>
void dllGenInsertion(T newData, doubleList<T>* prevNode)
{
    if(prevNode == nullptr)
    {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }

    doubleList<T>* node = newNode<T>(newData);

    node->next = prevNode->next;
    node->prev = prevNode;

    if(prevNode->next != nullptr)
    {
        prevNode->next->prev = node;
    }

    prevNode->next = node;
}

//========================
// Insert End
//========================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>** head)
{
    doubleList<T>* node = newNode<T>(newData);

    if(*head == nullptr)
    {
        *head = node;
        return;
    }

    doubleList<T>* currentNode = *head;

    while(currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = node;
    node->prev = currentNode;
}

//========================
// Delete Node
//========================
template <typename T>
void dllDelete(T findData, doubleList<T>** head)
{
    if(*head == nullptr)
        return;

    doubleList<T>* currentNode = *head;

    while(currentNode != nullptr && currentNode->data != findData)
    {
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr)
        return;

    if(currentNode->prev != nullptr)
    {
        currentNode->prev->next = currentNode->next;
    }
    else
    {
        *head = currentNode->next;
    }

    if(currentNode->next != nullptr)
    {
        currentNode->next->prev = currentNode->prev;
    }

    delete currentNode;
}


#endif //UNTITLED1_MAIN_TO_DOUBLY_H
