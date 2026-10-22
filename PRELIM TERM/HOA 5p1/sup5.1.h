//
// Created by royga on 8/11/2026.
//

#ifndef UNTITLED1_SUP5_1_H
#define UNTITLED1_SUP5_1_H
#include <iostream>
#include <string>

template <typename T>


class queueArr{
private:
    T* q_array;
    size_t q_size;
    size_t q_capacity;
    int q_front;
    int q_back;

public:
    //prototyping
    //constructor
    queueArr(size_t capacity);
    //destructor
    ~queueArr();
    //copy constructor
    queueArr(const queueArr& q);
    //copy operator
    queueArr& operator=(const queueArr& q);

    //basic operations
    bool empty();
    bool full();
    size_t size();
    void clear();
    T front();
    T back();
    void enqueue(T newData);
    T dequeue();
};

//CONSTUCTOR
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}
//empty
template <typename T>
bool queueArr<T>::empty(){
    return(q_size ==0);
}
//Size
template <typename T>
size_t queueArr<T>::size() {
    return q_size;
}
//Full
template <typename T>
bool queueArr<T>::full() {
    return (q_size == q_capacity);
}
//Clear
template <typename T>
void queueArr<T>::clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}
//Front
template <typename T>
T queueArr<T>::front() {
    if (empty()) {
        std::cout<<"Queue is empty"<<std::endl;
        return T();
    }
    return q_array[q_front];
}
//Back
template <typename T>
T queueArr<T>::back() {
    if (empty()) {
        std::cout<<"Queue is empty"<<std::endl;
        return T();
    }
    return q_array[q_back];
}
//enqueue
template <typename T>
void queueArr<T>::enqueue(T newData) {
    if (full()) {
        std::cout<<"Queue is full"<<std::endl;
        return;
    }
    q_back++;
    if (q_back == q_capacity) {
        q_back = 0;
    }
    q_array[q_back] = newData;
    q_size++;
}
//dequeue
template <typename T>
T queueArr<T>::dequeue() {
    if (empty()) {
        std::cout<<"Queue is empty"<<std::endl;
        return T();
    }
    T remData = q_array[q_front];
    q_front++;
    if (q_front == q_capacity) {
        q_front = 0;
    }
    q_size--;
    //reseting of index
    if (q_size == 0) {
        q_front = 0;
        q_back = -1;
    }
    return remData;
}
//Copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_size; i++) {
        q_array[i] = other.q_array[i];
    }
    std::cout<<"\n Copy constructor"<<std::endl;
}
//Copy Operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] q_array;

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_size; i++) {
        q_array[i] = other.q_array[i];
    }
    std::cout<<"\n Copy assignment"<<std::endl;
    return *this;
}
//Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
    std::cout<<"\n Destructor"<<std::endl;
}

#endif //UNTITLED1_SUP5_1_H