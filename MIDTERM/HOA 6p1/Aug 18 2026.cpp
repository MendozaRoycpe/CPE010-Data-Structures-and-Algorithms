//
// Created by royga on 8/18/2026.
//
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "nodes.h"
#include "searchingalgo.h"

const int max_size = 10;
int main() {
    char charfind;

    //gen random vals:
    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }
    for(int i = 0; i<max_size; i++){
        std::cout<<dataset[i]<<" ";}

    //create a user input to ask what value to find:
    int toFind;
    std::cout<<"\nWhat value you want to search?: ";
    std::cin>>toFind;

    linearSearchArr(dataset,max_size, toFind);

    //linked list: R O Y G A B
    Node<char>* name1 = new_node<char>('R');
    Node<char>* name2 = new_node<char>('O');
    Node<char>* name3 = new_node<char>('Y');
    Node<char>* name4 = new_node<char>('G');
    Node<char>* name5 = new_node<char>('A');
    Node<char>* name6 = new_node<char>('B');
    Node<char>* name7 = new_node<char>('Z');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;

    while(true) {
        std::cout<<"\n == Performing Linear Search== \n"<<"Enter a character you want to find: ";
        std::cin>>charfind;

        //loop for finding character inside until break
        if (charfind == '!') {
            std::cout<<"\nProgram Termination";
            break;
        }
        linearsearchLL(name1, charfind);
    }

    std::cout << "\nNow sorting the array and performing binary search.\n";
    insertionSort(dataset, max_size);

    std::cout << "Sorted dataset:\n";
    for (int i = 0; i < max_size; ++i) {
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n";

    int finde;
    std::cout << "What value you want to search (binary search)?: ";
    std::cin >> finde;

    int numidx = binarySearch(dataset, max_size, finde);

    if (numidx >= 0) {
        std::cout << "\nReturned index: " << numidx << "\n";
    } else {
        std::cout << "\nReturned index: -1\n";
    }


    //-----------------------------------------------------------------------
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int> *temp = nullptr, *head = nullptr, *node = nullptr;

    while (choice == 'y') {
        std::cout << "\nEnter data (ordered): ";
        std::cin >> newData;

        if (count == 1) {
            head = new_node<int>(newData);
            head->next = nullptr;
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count == 2) {
            node = new_node<int>(newData);
            node->next = nullptr;
            head->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (temp->next != nullptr) temp = temp->next;
            node = new_node<int>(newData);
            node->next = nullptr;
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') break;
    }

    // display the integer list
    Node<int> *currNode = head;
    std::cout << "\nList contents: ";
    int nodeCount = 0;
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
        nodeCount++;
    }
    std::cout << "\nTotal nodes: " << nodeCount << "\n\n";

    // perform binary search on the linked list
    int key;
    std::cout << "Enter value to binary-search in the list: ";
    std::cin >> key;

    Node<int>* found = binarySearchLL<int>(head, key);
    if (found != nullptr) {
        std::cout << "Returned node value: " << found->data << "\n";
    } else {
        std::cout << "Returned node: nullptr (not found)\n";
    }

    // cleanup allocated nodes for the integer list
    currNode = head;
    while (currNode != nullptr) {
        Node<int>* next = currNode->next;
        delete currNode;
        currNode = next;
    }

    // cleanup allocated nodes for the char list
    Node<char>* curc = name1;
    while (curc != nullptr) {
        Node<char>* nextc = curc->next;
        delete curc;
        curc = nextc;
    }
    return 0;
}