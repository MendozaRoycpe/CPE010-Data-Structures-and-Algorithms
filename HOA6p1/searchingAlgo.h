//
// Created by royga on 8/18/2026.
//
#include <iostream>
#include "nodes.h"

#ifndef UNTITLED1_SEARCHINGALGO_H
#define UNTITLED1_SEARCHINGALGO_H

// lINEAR SEARCH ARRAY
template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind) {
    int i = 0;
    while (i < arrSize) {
        if (dataFind==data[i]) {
            std::cout<<"The search is success\n";
            return;
        }
        i++;
    }
    std::cout<<"The search has failed\n";
    return;
}

//linked list approach
//Nodes -> starting node
//temp that we are searching
template <typename T>
void linearsearchLL(Node<T>* node, T dataFind) {
    //repeat the loop until the current node is not null
    while (node != nullptr) {
        //if item = current node's data, then display searching is successful
        if (dataFind==node->data) {
            std::cout<<"The search is success\n";
            return;
        };
        //if not, move to the next node
        node = node->next;
    }
    //the searching reached nullptr
    std::cout<<"The search has failed\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {
    if (start == nullptr) return nullptr;

    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
/*
*1. Start node is set to head of the list and the last node is set to NULL.
2. Middle element is calculated using the two pointers approach discussed above.
3. If the middle element is same as the key to be searched, we return it.
4. Else if middle element is greater than the key to be searched, we have to search is the
right side of the singly linked list. So, we set start pointer to the next of middle
element.
5. Else if middle element is less than the key to be searched, we have to search is the left
side of the singly linked list. So, we set last pointer to the middle element.
6. If the key is found or the entire linked list gets traversed, we break the loop.
*/
template <typename T>
Node<T>* binarySearchLL(Node<T>* start, T findData) {
    Node<T>* last = nullptr; // exclusive end

    while (start != last) {
        Node<T>* mid = getMiddle(start, last);
        if (mid == nullptr) break;

        if (mid->data == findData) {
            std::cout << "The search is success\n";
            return mid;
        } else if (mid->data < findData) {
            start = mid->next;   // search right half
        } else {
            last = mid;          // search left half (exclusive)
        }
    }
    std::cout << "The search has failed\n";
    return nullptr;
}

template <typename T>
int binarySearch(T arr[], int n, T key) {
    int low = 0;
    int up  = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;
        if (arr[mid] == key) {
            std::cout << "Search element is found at index " << mid << "\n";
            return mid;
        } else if (key < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found\n";
    return -1;
}

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
#endif //UNTITLED1_SEARCHINGALGO_H
