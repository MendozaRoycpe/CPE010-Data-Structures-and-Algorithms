//
// Created by royga on 8/11/2026.
//
#ifndef UNTITLED1_NEWQARR_H
#define UNTITLED1_NEWQARR_H
#include <iostream>

//array based circular q
template <typename T>
class queueArr {
private:
    T* q_array; //dynamic array?
    size_t q_capacity; //maximum capacity of "nodes" of the array
    size_t q_size; // no. of elements
    int q_front; //1st element
    int q_back; //last element

    public:
    //prototype:
    queueArr(size_t capacity);
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    ~queueArr();

    queueArr(const queueArr& other);//copy constructor
    queueArr& operator=(const queueArr& other);//copy operator

};

//constructor:
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    //capacity of the array
    q_capacity = capacity;

    //size of the array
    q_size = 0;

    //initial front and back of the index
    q_front = 0;
    q_back = -1;

    //newly allocated array
    q_array = new T[q_capacity];
    std::cout<< "\nConstructor class was called";
}
//size()
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

//empty()
template <typename T>
bool queueArr<T>::Empty() {
    return (q_size == 0);
}

//full()
template <typename T>
bool queueArr<T>::Full() {
    return (q_size == q_capacity);
}

//clear()
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

//front()
template <typename T>
T queueArr<T>::Front() {
    //check and display if the queue is empty
    if (Empty()) {
        std::cout<< "\nQueue is empty";
        return T{};
    }
    //return the front item
    else {
        return q_array[q_front];
    }
}

//back()
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        std::cout<< "\nQueue is empty";
        return T{};
    }
    else {
        return q_array[q_back];
    }
}

//enqueue
template <typename T>
void queueArr<T>::Enqueue(T newData) {
    //check if the queue is full
    if (Full()) {
        std::cout<< "\nQueue is full";
        return;
    }
    //compute for the q_back to move it circularly
    q_back = (q_back + 1) % q_capacity;
    //assign the new value to the back of the queue array
    q_array[q_back] = newData;
    //increment the q_size
    q_size++;
}

//dequeue()
template <typename T>
void queueArr<T>::Dequeue() {
    //check if empty
    if (Empty()) {
        std::cout<< "\nQueue is empty";
        return;
    }
    //check for thr q_front to move it circularly
    q_front = (q_front + 1) % q_capacity;

    //decrement the queue size
    q_size--;
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    //copying the capcity of the original
    q_capacity = other.q_capacity;
    //copy size
    q_size = other.q_size;
    //copy the front index
    q_front = other.q_front;
    //copy the back index
    q_back = other.q_back;
    //create a new array for the copied queue
    q_array = new T[q_capacity];

    //loop to copy every position of the original array
    for (size_t i=0; i<q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
    std::cout<<"\nCopy Constructor class was called";
}

// copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] q_array; //deletion of the old array

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    //create a new array
    q_array = new T[q_capacity];
    for (size_t i=0; i<q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
    std::cout<<"\nCopy Operator class was called";
    return *this;
}

//destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete [] q_array;
    std::cout<< "\nDestructor class was called";
}
#endif //UNTITLED1_NEWQARR_H
