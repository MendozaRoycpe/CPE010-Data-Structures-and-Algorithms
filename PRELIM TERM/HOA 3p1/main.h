#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

// Template class so the linked list can store any data type
template <typename T>
class Singlelist {
public:
    T data;                  // Stores the value of the node
    Singlelist<T>* next = nullptr; // Points to the next node
};

// Function to display all nodes in the linked list
template <typename T>
void listTraversal(Singlelist<T>* head)
{
    // Continue until we reach the end of the list
    while (head != nullptr){
        // Print the current node's data
        std::cout << head->data;

        // Print an arrow if another node follows
        if (head->next != nullptr)
        {
            std::cout << " --> ";
        }
        // Move to the next node
        head = head->next;
    }
    // Move to the next line after printing the list
    std::cout << std::endl;
}
// Insert a new node at the head of the linked list
template <typename T>
void sllinsertHead(T newData, Singlelist<T>** head)
{
    // Create a new node
    Singlelist<T>* newNode = new Singlelist<T>;
    // Store the data
    newNode->data = newData;
    // Point the new node to the current head
    newNode->next = *head;
    // Make the new node the new head
    *head = newNode;
}
// Insert a new node after a specified node
template <typename T>
void sllGeneralinsertion(T newData, Singlelist<T>* prevNode)
{
    // Make sure the previous node exists
    if (prevNode == nullptr)
    {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }
    // Create a new node
    Singlelist<T>* newNode = new Singlelist<T>;
    // Store the new data
    newNode->data = newData;
    // Connect the new node to the next node
    newNode->next = prevNode->next;
    // Connect the previous node to the new node
    prevNode->next = newNode;
}
// Insert a node at the end of the linked list
template <typename T>
void sllInsertEnd(T newData, Singlelist<T>** head)
{
    // Create a new node
    Singlelist<T>* newNode = new Singlelist<T>();
    // Start traversing from the head
    Singlelist<T>* currentNode = *head;
    // Store the data
    newNode->data = newData;

    // Since this will be the last node, point next to nullptr
    newNode->next = nullptr;
    // Check if the list is empty
    if (*head == nullptr)
    {
        // Make the new node the head of the list
        *head = newNode;
        return;
    }
    // Continue moving until the last node is reached
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    // Link the last node to the new node
    currentNode->next = newNode;
}
// Delete a node with a specific value
template <typename T>
void sllDelete(T findData, Singlelist<T>** head)
{
    // Stop if the list is empty
    if (*head == nullptr)
        return;

    // Start searching from the head
    Singlelist<T>* currNode = *head;

    // Previous node starts as nullptr
    Singlelist<T>* prevNode = nullptr;

    // Search until the value is found or end of list is reached
    while (currNode != nullptr && currNode->data != findData)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
    // Value not found
    if (currNode == nullptr)
        return;
    // If deleting the first node
    if (prevNode == nullptr)
    {
        // Move the head to the second node
        *head = currNode->next;
    }
    else
    {
        // Skip the current node
        prevNode->next = currNode->next;
    }
    // Free the memory of the deleted node
    delete currNode;
}

// Delete the entire linked list
template <typename T>
void sllDeleteList(Singlelist<T>** head)
{
    // Start from the first node
    Singlelist<T>* currentNode = *head;

    // Repeat until every node is deleted
    while (currentNode != nullptr)
    {
        // Save the current node
        Singlelist<T>* temp = currentNode;

        // Move to the next node
        currentNode = currentNode->next;

        // Delete the saved node
        delete temp;
    }
    // Set the head to nullptr because the list is now empty
    *head = nullptr;
}

#endif