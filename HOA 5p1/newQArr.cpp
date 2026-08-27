//
// Created by royga on 8/11/2026.
//
#include <iostream>
#include <string>
#include "newQArr.h"

int main() {
    //create an object
    queueArr<int> q_array(10);

    //enqueuing
    std::cout << "\n================================ \n";
    q_array.Enqueue(50);
    q_array.Enqueue(40);
    q_array.Enqueue(10);
    q_array.Enqueue(20);
    q_array.Enqueue(30);
    std::cout<<"\n================================ \n";
    std::cout<<" Elements are added.\n";
    std::cout<<"\n================================ \n";

    //calling
    std::cout<<"\n================================ \n";
    std::cout<<"QUEUE INFO";

    std::cout << "\nFRONT: " << q_array.Front()<<"\nBACK: "<<q_array.Back()<<"\nSize: "<< q_array.Size()<<std::endl;

    //dequieing
    std::cout<<"\n================================ \n";
    std::cout<<" Dequeueing";
    q_array.Dequeue();
    std::cout << "\nFRONT: " << q_array.Front()<<"\nBACK: "<<q_array.Back()<<"\nSize: "<< q_array.Size()<<std::endl;

    //copy constructor
    std::cout<< " \n================================ \n";
    std::cout<<"Copy Constructor \n";
    queueArr<int> copyQ(q_array);
    std::cout<<"\n Copying Front: "<<copyQ.Front()<<std::endl;
    std::cout<<"\n Copying Back: "<<copyQ.Back()<<std::endl;
    std::cout<<"\n Copying Size: "<<copyQ.Size()<<std::endl;

    //copy assignment
    std::cout<< " \n================================ \n";
    std::cout<<" Copy Assignment Operator\n";
    queueArr<int> assignQ(10);
    assignQ = copyQ;
    std::cout<<"Copied Queue Front: "<<assignQ.Front()<<std::endl;
    std::cout<<"\n Copied Queue Back: "<<assignQ.Back()<<std::endl;
    std::cout<<"\n Copied Queue Size: "<<assignQ.Size()<<std::endl;

    //clear
    std::cout<<"\n================================ \n";
    std::cout<<"CLEARING";
    q_array.Clear();
    std::cout << "\nFRONT: " << q_array.Front()<<"\nBACK: "<<q_array.Back()<<"\nSize: "<< q_array.Size()<<std::endl;
    if (q_array.Empty()) {
        std::cout<<"\n Queue is empty.";
    }else {
        std::cout<<"\n Queue is not empty.";
    }

    std::cout<<"\n================================ \n";
    std::cout<<"Program End";

    return 0;
}
