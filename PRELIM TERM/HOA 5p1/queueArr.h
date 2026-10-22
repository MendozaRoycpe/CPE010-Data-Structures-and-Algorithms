//
// Created by royga on 8/4/2026.
//

#ifndef UNTITLED1_QUEUEARR_H
#define UNTITLED1_QUEUEARR_H
#include <iostream>
#include <string>

//QUEUE CLASs
//circular array - based on the module example
template <typename T>
class queueArr {
    private:
    T* q_array; // pointer for the dynamic allocation of array
    int q_size; // current number of elements stored
    int q_capacity;// maximum number of elements
    int q_front;//index the front element of the queue
    int q_back;//index the back element

    public:
    queueArr(int capacity = 10) {
        q_capacity = capacity;
        q_array = new T[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = -1;
        std::cout<<"Queue is created"<<std::endl;
        std::cout<<"Constructor was Called"<<std::endl;
    }

    // checker if queue is empty
    bool empty() const {
        return (q_size == 0);
    }

    //checker for the number of element in the queue
    int size() const {
        return q_size;
    }

    //removing of all the elements in the queue
    void clear() { //resetting the size, front, back, but does not affect the heap nor capacity
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    //showing of the front element
    T front() const {
        if (empty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return T();
        }
        return q_array[q_front];
    }

    //returns the last element in the queue
    T back() const {
        if (empty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return T();
        }
        return q_array[q_back];
    }

    // add a new element at the back of the last element
    void enqueue(T item) {
        if(q_size == q_capacity) {
            std::cout<<"Queue is full"<<std::endl;
            return;
        }
        q_back++;


        if(q_back == q_capacity) {
            q_back = 0;
        }
        q_array[q_back] = item;
        q_size++;
        std::cout<<"Queue is created"<<std::endl;
    }
    //removing of the front element
    T dequeue() {
        if (empty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return T();
        }
        T delValue = q_array[q_front];
        q_front++;

        if (q_front == q_capacity) {
            q_front = 0;
        }
        q_size--;
        std::cout<<"Queue is deleted"<<std::endl;
        return delValue;
    }

    //copy constructor
    queueArr(const queueArr& other) { //creates a new queue copying the old queue
        q_capacity = other.q_capacity; //copy capacity
        q_size = other.q_size; //copy the size
        q_front = other.q_front; // copy the front index
        q_back = other.q_back; // copy the back index
        q_array = new T[q_capacity]; //creates a new array

        for (int i = 0; i < q_capacity; i++) { //copy the entire array
            q_array[i] = other.q_array[i]; //copy each array positions
        }
        std::cout<<"Queue is created"<<std::endl;
        std::cout<<"Copy Constructor was Called"<<std::endl;
    }

    //copy assignment operator
    queueArr& operator=(const queueArr& other) {
        if (this == &other) {
            return *this;
        }
        delete[] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];

        //copying the entire array
        for (int i = 0; i < q_size; i++) {
            q_array[i] = other.q_array[i];
        }

        return *this;
    }

    //destructor
    ~queueArr() {
        delete [] q_array;
        std::cout<<"Queue is deleted"<<std::endl;
        std::cout<<"Destructor was called Successfully";
    }
};

#endif //UNTITLED1_QUEUEARR_H