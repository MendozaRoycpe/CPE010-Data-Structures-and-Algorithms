//
// Created by royga on 8/4/2026.
//
#include <iostream>
#include <queue>
#include <string>

//prototyping
void display(std::queue<char> r);

int main() {
    //pushing
    std::queue<char> q;
    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //display
    std::cout<< "\n The contents of the queue are: \n";
    display(q);
    std::cout<< " =============================== \n";

    //empty
    std::cout<<"\n is the queue empty? " << (q.empty() ? "Yes" : "No")<<"\n";
    std::cout<< " =============================== \n";

    //size
    std::cout<< "\n The size of the queue is " << (q.size())<<"\n";
    std::cout<< " =============================== \n";

    //front
    std::cout << "\n Front element: " << q.front() << "\n";
    std::cout<< " =============================== \n";

    //back
    std::cout << "\n Back element: " << q.back() << "\n";
    std::cout<< " =============================== \n";

    //pop
    q.pop();
    std::cout << "\n After one pop:";
    display(q);
    std::cout<< " =============================== \n";

    //push
    q.push('8');
    std::cout << "\n After pushing '8': ";
    display(q);
    std::cout<< " =============================== \n";

    //display
    std::cout << "\n Queue check: ";
    display(q);
    std::cout<< " =============================== \n";

    //deletion?
    while (!q.empty()) {
        display(q);
        q.pop();
    }
    std::cout << "\n Final queue check: ";
    display(q);
    std::cout<< " =============================== \n";
}

//function definitions
void display(std::queue<char> r) {
    // create a copy of the queue
    std::queue<char> c = r;

    while (!c.empty()) {
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << "\n";
}