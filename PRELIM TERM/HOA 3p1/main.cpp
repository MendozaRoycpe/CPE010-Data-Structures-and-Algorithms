#include <iostream>
#include "main.h"

int main() {

    // Create an empty linked list
    Singlelist<char> *head = new Singlelist<char>;
    Singlelist<char> *second = new Singlelist<char>;
    Singlelist<char> *third = new Singlelist<char>;
    Singlelist<char> *fourth = new Singlelist<char>;
    Singlelist<char> *fifth = new Singlelist<char>;
    Singlelist<char> *sixth = new Singlelist<char>;

    // Store the data and link the nodes
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = sixth;

    sixth->data = '1';
    sixth->next = nullptr;

    // A. Traverse
    std::cout << "Traverse the List:\n";
    listTraversal(head);

    // B. Insert G at the beginning
    std::cout << "\nInsert G at the Head:\n";
    sllinsertHead('G', &head);
    listTraversal(head);

    // C. Insert E after P
    std::cout << "\nInsert E after P:\n";
    sllGeneralinsertion('E', head->next->next);
    listTraversal(head);

    // D. Delete C
    std::cout << "\nDelete C:\n";
    sllDelete('C', &head);
    listTraversal(head);

    // E. Delete P
    std::cout << "\nDelete P:\n";
    sllDelete('P', &head);
    listTraversal(head);

    // F. Final List
    std::cout << "\nFinal List:\n";
    listTraversal(head);

    return 0;
}