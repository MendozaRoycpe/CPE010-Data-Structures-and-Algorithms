//
// Created by royga on 8/23/2026.
//
#include <iostream>
#include "nodes.h"
#include "searchingalgo.h"

const int max_size = 10;

// build linked list from int array
Node<int>* build_list_from_array(int arr[], int n) {
    if (n <= 0) return nullptr;
    Node<int>* head = new_node<int>(arr[0]);
    Node<int>* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new_node<int>(arr[i]);
        tail = tail->next;
    }
    return head;
}

// delete linked list
void delete_list(Node<int>* head) {
    while (head) {
        Node<int>* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// print array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i + 1 < n) std::cout << " ";
    }
    std::cout << "\n";
}

// print linked list
void print_list(Node<int>* head) {
    Node<int>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}
int main() {
    // Problem 1 list (exact values from the activity)
    int data[max_size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    // build linked list from the same array
    Node<int>* head = build_list_from_array(data, max_size);

    // print both representations
    std::cout << "Problem 1 list (array):\n";
    print_array(data, max_size);
    std::cout << "Linked list contents:\n";
    print_list(head);
    std::cout << "\n";

    int key = 18;

    // compute comparisons for array and linked list using functions from searchingalgo.h
    int compsArray = seqARRcomp(data, max_size, key);
    int compsList  = seqLLcomp<int>(head, key);

    // print results clearly labeled for screenshots/submission
    std::cout << "Problem 1: Sequential search for key " << key << "\n";
    if (compsArray >= 0)
        std::cout << "Array: comparisons to match = " << compsArray << "\n";
    else
        std::cout << "Array: key not found\n";

    if (compsList >= 0)
        std::cout << "Linked list: comparisons to match = " << compsList << "\n";
    else
        std::cout << "Linked list: key not found\n";

    // cleanup
    delete_list(head);
    return 0;
}

