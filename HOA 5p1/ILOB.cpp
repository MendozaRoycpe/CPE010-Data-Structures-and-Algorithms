//
// Created by royga on 8/4/2026.
//
#include <iostream>
#include <queue>
#include "queuell.h"
template <typename T>
void dispaly(qNode<T>* frontPtr);


int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue(&front, &back, 'R');
    std::cout << "Front: " << front->data << " Back: " << back->data << "\n";
    std::cout<< " =============================== \n";
    enqueue(&front, &back, 'O');
    std::cout << "Front: " << front->data << " Back: " << back->data << "\n";
    std::cout<< " =============================== \n";
    enqueue(&front, &back, 'Y');
    std::cout << "Front: " << front->data << " Back: " << back->data << "\n";
    std::cout<< " =============================== \n";
    dequeue(&front, &back);
    std::cout << "After dequeue: ";
    display(front);
    std::cout<< " =============================== \n";
    std::cout << "Front element: " << top1st(front) << "\n";
    dequeue(&front, &back);
    std::cout<< " =============================== \n";
    std::cout << "The new front: " << top1st(front) << "\n";
    std::cout<< " =============================== \n";

    return 0;
}