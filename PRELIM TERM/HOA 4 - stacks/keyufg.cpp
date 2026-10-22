//
// Created by royga on 7/28/2026.
//
#include <iostream>
#include <string>
#include <stack> //calling stack from stl

int main() {
    //create object for the stack
    std::stack<int> newStack;

    std::cout<<"is stack empty? "<<newStack.empty()<<std::endl;

    //pushing the contents to the stacks
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    std::cout << "The top of the element is "<<newStack.top() << std::endl;

    std::cout<<"is stack empty? "<<newStack.empty()<<std::endl;

    std::cout<<"The size of the stack is "<<newStack.size()<<std::endl;

    std::cout<<"Removing elements from the stack \n";
    newStack.pop();

    std::cout << "The top of the element is "<<newStack.top() << std::endl;
    newStack.pop();
    std::cout << "The top of the element is "<<newStack.top() << std::endl;
    newStack.pop();
    std::cout << "The top of the element is "<<newStack.top() << std::endl;
    return 0;
}
