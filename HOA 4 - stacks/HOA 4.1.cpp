#include <iostream>
#include <string>
#include <stack> //calling stack from stl



int main() {
//create object for the stack
    std::stack<int> newStack;
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

std::cout << newStack.top() << std::endl;

    return 0;
}