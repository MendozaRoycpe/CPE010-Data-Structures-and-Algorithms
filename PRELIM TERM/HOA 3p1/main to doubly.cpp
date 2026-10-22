#include <iostream>
#include "main to doubly.h"

int main() {

    // Create an empty doubly linked list
    doubleList<int> *head = new doubleList<int>;
    doubleList<int> *second = new doubleList<int>;
    doubleList<int> *third = new doubleList<int>;

    // Store the data and link the nodes
    head->data = 1;
    head->next = second;
    head->prev = nullptr;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = nullptr;
    third->prev = second;

    std::cout << "Linked List Traversal:\n";
    dllTraverse(head);

    std::cout << "\nNewly inserted head of Linked List:\n";
    dllInsertHead(0, &head);
    dllTraverse(head);

    std::cout << "\nNewly inserted after a node of Linked List:\n";
    dllGenInsertion(3, head->next);
    dllTraverse(head);

    std::cout << "\nInsert another node:\n";
    dllGenInsertion(4, head->next->next);
    dllTraverse(head);

    std::cout << "\nInsert at the end:\n";
    dllInsertEnd(10, &head);
    dllTraverse(head);

    std::cout << "\nDeleting a node:\n";
    dllDelete(10, &head);
    dllTraverse(head);

    return 0;
}
