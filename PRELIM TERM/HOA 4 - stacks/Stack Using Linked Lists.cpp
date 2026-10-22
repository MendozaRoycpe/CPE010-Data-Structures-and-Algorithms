#include <iostream>
#include "STACKS.h"

int main() {
    std::cout << "Pushing 'c', 'p', 'e' ONTO THE STACK\n";

    // pushing characters
    push<char>('c');
    push<char>('p');
    push<char>('e');

    // display all the contents
    displayAll<char>();

    // display the current top
    top<char>();

    // popping
    std::cout << "Popping FROM THE STACK\n";

    while (!isEMPT<char>()) {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "Testing the Underflow \n";
    pop<char>();

    return 0;
}