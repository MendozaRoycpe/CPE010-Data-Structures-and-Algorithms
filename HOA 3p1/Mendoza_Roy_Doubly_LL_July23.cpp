#include <iostream>
#include "Mendoza_Roy_Doubly_LL_July23.h"

int main() {
    //cpe101 node setting
    doubleList<char>* head = newNode('C');
    doubleList<char>* second = newNode('P');
    doubleList<char>* third = newNode('E');
    doubleList<char>* fourth = newNode('1');
    doubleList<char>* fifth = newNode('0');
    doubleList<char>* sixth = newNode('1');

    //link the nodes:
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    fifth->next = sixth;
    sixth->prev = fifth;


    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    std::cout << "Inserting at the Head" << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "General Insertion (after the head -> next -> next)"<< std::endl;
    dllGenInsertion('E', head->next->next);
    dllTraverse(head);

    std::cout<<"Deleting the C "<<std::endl;
    dllDelete('C', &head);
    dllTraverse(head);

    std::cout<<"Deleting the P "<<std::endl;
    dllDelete('P', &head);
    dllTraverse(head);

    std::cout << "Final Traversal" << std::endl;
    dllTraverse(head);

    return 0;
}