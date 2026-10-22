//
// Created by royga on 8/11/2026.
//
#include "queueArr.h"
#include <iostream>
#include "string"

int main() {
    std::cout<< " \n================================ \n";
    std::cout<<" Circular Array Queueing\n";

    queueArr<std::string> queue(10);

    //checking for empty();
    if(queue.empty()) {
        std::cout<< " \n================================ \n";
        std::cout<< " Queue is empty \n";
    }
    else {
        std::cout<< " \n================================ \n";
        std::cout<< " Queue is not empty\n";
    }

    //enqueue
    std::cout<< " \n================================ \n";
    std::cout<< "Enqueue: ";
    queue.enqueue("C");
    std::cout<< "Enqueue: ";
    queue.enqueue("P");
    std::cout<< "Enqueue: ";
    queue.enqueue("E");
    std::cout<< "Enqueue: ";
    queue.enqueue("R");
    std::cout<< "Enqueue: ";
    queue.enqueue("O");
    std::cout<< "Enqueue: ";
    queue.enqueue("Y");

    //size checker
    std::cout<< " \n================================ \n";
    std::cout<<"Size :";
    std::cout<<queue.size()<<std::endl;

    // front output
    std::cout<< " \n================================ \n";
    std::cout<<"The front element is: "<<queue.front()<<std::endl;

    //back output
    std::cout<< " \n================================ \n";
    std::cout<< " The Back Element is: "<<queue.back()<<std::endl;

    //dequeue
    std::cout<< " \n================================ \n";
    std::cout<<"Dequeuing: "<<queue.dequeue()<<std::endl;
    std::cout<<"Dequeuing: "<<queue.dequeue()<<std::endl;

    //circular test
    std::cout<< " \n================================ \n";
    std::cout<<"Enqueuing: A\n";
    queue.enqueue("A");

    std::cout<< "Enqueuing: B\n";
    queue.enqueue("B");

    std::cout<<"Front element is: "<<queue.front()<<std::endl;

    std::cout<<"Back element is: "<<queue.back()<<std::endl;

    std::cout<<"Queue Size: "<<queue.size()<<std::endl;

    //copy constructor
    std::cout<< " \n================================ \n";
    std::cout<<" Copy Consructor \n";
    queueArr<std::string> copy(queue);

    std::cout<< " \n================================ \n";
    std::cout<<"Copied Queue Front: "<<copy.front()<<std::endl;

    std::cout<< " \n================================ \n";
    std::cout<< " Copued Queue Back: "<<copy.back()<<std::endl;

    std::cout<< " \n================================ \n";
    std::cout<<" Copied Queue Size: "<<copy.size()<<std::endl;

    //copy constructor test
    std::cout<< " \n================================ \n";
    std::cout<<"Copy Constructor \n";
    queueArr<std::string> copyQ(queue);
    std::cout<<"\n Copying Front: "<<copyQ.front()<<std::endl;
    std::cout<<"\n Copying Back: "<<copyQ.back()<<std::endl;
    std::cout<<"\n Copying Size: "<<copyQ.size()<<std::endl;

    //copy assignment
    std::cout<< " \n================================ \n";
    std::cout<<" Copy Assignment Operator\n";
    queueArr<std::string> assignQ(copyQ);
    std::cout<<"Copied Queue Front: "<<assignQ.front()<<std::endl;
    std::cout<<"\n Copied Queue Back: "<<assignQ.back()<<std::endl;
    std::cout<<"\n Copied Queue Size: "<<assignQ.size()<<std::endl;

    //testing clear
    queue.clear();

    if(queue.empty()) {
        std::cout<< " \n================================ \n";
        std::cout<< " Queue is cleared.\n";
        }
    else{
        std::cout<<"Queue does still have elements. \n";
    }
    std::cout<<"Queue size after the clear(): "<<queue.size()<<std::endl;


    return 0;
}