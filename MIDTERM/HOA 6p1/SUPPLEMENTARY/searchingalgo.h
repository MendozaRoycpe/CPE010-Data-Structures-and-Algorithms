//
// Created by royga on 8/23/2026.
//

#ifndef UNTITLED1_SEARCHINGALGO_H
#define UNTITLED1_SEARCHINGALGO_H
#include <iostream>
#include "nodes.h"

// Linear search arr
template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind) {
    for (int i = 0; i < arrSize; ++i) {
        if (dataFind == data[i]) {
            std::cout << "The search is success\n";
            return;
        }
    }
    std::cout << "The search has failed\n";
    return;
}

// Linear search linkedli
template <typename T>
void linearsearchLL(Node<T>* node, T dataFind) {
    Node<T>* cur = node;
    while (cur != nullptr) {
        if (cur->data == dataFind) {
            std::cout << "The search is success\n";
            return;
        }
        cur = cur->next;
    }
    std::cout << "The search has failed\n";
}

// Problem 1:
int seqARRcomp(int arr[],int n,int key) {
    int comparisons= 0;
    for (int i= 0; i< n; i++) {
        comparisons++;
        if (arr[i] == key) return comparisons;
    }
    return -1; // not found
}

template<typename T>
int seqLLcomp(Node<T>* head, T key) {
    int comparisons = 0;
    Node<T>* cur = head;
    while (cur != nullptr) {
        ++comparisons;
        if (cur->data == key) return comparisons;
        cur = cur->next;
    }
    return -1;
}

// Problem 2: count occurrences
int countOCarr(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) if (arr[i] == key) ++count;
    return count;
}

template<typename T>
int countOCll(Node<T>* head, T key) {
    int count = 0;
    Node<T> *cur = head;
    while (cur != nullptr) {
        if (cur->data == key) count++;
        cur = cur->next;
    }
    return count;
}

// Insertion sort for the arrays
template<typename T>
void insertionSort(T arr[], int n) {
    for (int i= 1; i< n; i++) {
        T key = arr[i];
        int j = i- 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int up  = n - 1;
    while (low <= up) {
        int mid = low + (up - low) / 2;
        std::cout << "Iteration: low=" << low << " mid=" << mid << " high=" << up
                  << " midValue=" << arr[mid] << "\n";
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

// Recursive binary search
int binary_search_recursive_impl(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (key < arr[mid]) return binary_search_recursive_impl(arr, low, mid - 1, key);
    return binary_search_recursive_impl(arr, mid + 1, high, key);
}

int binarySearchRecursive(int arr[], int n, int key) {
    return binary_search_recursive_impl(arr, 0, n - 1, key);
}

// getMiddle for linked-list binary search
template<typename T>
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

// Binary search on linked list (list must be sorted ascending)
template <typename T>
Node<T>* binarySearchLL(Node<T>* start, T findData) {
    Node<T>* last = nullptr;
    while (start != last) {
        Node<T>* mid = getMiddle(start, last);
        if (mid == nullptr) break;
        if (mid->data == findData) {
            std::cout << "The search is success\n";
            return mid;
        } else if (mid->data < findData) {
            start = mid->next;
        } else {
            last = mid;
        }
    }
    std::cout << "The search has failed\n";
    return nullptr;
}

int binarySearchIte(int arr[], int n, int key) {
    // Set the starting boundary.
    int low = 0;

    // Set the ending boundary.
    int up = n - 1;

    // Continue while the search range is valid.
    while (low <= up){
        // Calculate the middle index.
        int mid = (low + up) / 2;

        // Display the current iteration.
        std::cout << "\nIteration";
        std::cout << "\nLow = " << low;
        std::cout << "\nUp = " << up;
        std::cout << "\nMid = " << mid;
        std::cout << "\nMiddle Value = " << arr[mid];

        // Check if the middle value is the key.
        if (arr[mid] == key){
            // Display successful search.
            std::cout << "\nSearch element is found!";
            std::cout << "\nIndex = " << mid << std::endl;

            // Return the index.
            return mid;
        }

        // If the key is smaller, search the left side.
        if (key < arr[mid]){
            up = mid - 1;
        }else{
            // Otherwise, search the right side.
            low = mid + 1;
        }
    }

    // The key was not found.
    std::cout << "\nSearch element is not found.";
    return -1;
}

// Recursive binary search function
int binarySearchRecursive(int arr[], int low, int up, int key)
{
    // Check if the search range is still valid.
    if (low > up){
        // The search element was not found.
        return -1;
    }

    // Calculate the middle index.
    int mid = (low + up) / 2;

    // Display the current recursive step.
    std::cout << "\nLow = " << low;
    std::cout << "\nUp = " << up;
    std::cout << "\nMid = " << mid;
    std::cout << "\nMiddle Value = " << arr[mid] << "\n";

    // Check if the middle element is the search key.
    if (arr[mid] == key){
        // The search was successful.
        std::cout << "Search element is found!";
        std::cout << "\nIndex = " << mid << "\n";

        // Return the position of the key.
        return mid;
    }

    // If the key is smaller than the middle value,
    // recursively search the left half.
    if (key < arr[mid])
    {
        return binarySearchRecursive(arr, low, mid - 1, key);
    }

    // If the key is greater than the middle value,
    // recursively search the right half.
    return binarySearchRecursive(arr, mid + 1, up, key);
}
#endif //UNTITLED1_SEARCHINGALGO_H