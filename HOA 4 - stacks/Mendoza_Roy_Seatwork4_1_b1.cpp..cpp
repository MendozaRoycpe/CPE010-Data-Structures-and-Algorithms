#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1;
int newData, choice, i;

void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void prinAll();

int main() {
    //====================================
    std::cout << "Enter the maximum number of elements (1-100): ";
    std::cin >> i;
    //====================================
    // Validate the user input
    if (i <= 0 || i > maxCap) {
        std::cout << "Invalid! Maximum allowed is " << maxCap << ".\n";
        return 0;
    }
    //====================================
    while (true) {
        std::cout << "\n===== STACK OPERATIONS =====\n";
        std::cout << "1. PUSH\n"<<"2. POP\n"<< "3. TOP\n"<<"4. isEMPTY\n"<< "5. PRINT CONTENTS\n"<< "6. EXIT\n"<< "Choose your choice: ";
        //====================================
        std::cin >> choice;
        switch (choice) {
            case 1:
                push();
                break;
                //====================================
            case 2:
                pop();
                break;
                //====================================
            case 3:
                Top();
                break;
                //====================================
            case 4:
                if (isEmpty())
                    std::cout << "Stack is Empty.\n";
                else
                    std::cout << "Stack is NOT Empty.\n";
                break;
                //====================================
            case 5:
                std::cout<<"Print out all the contents of the stack.\n";
                prinAll();
                break;
                //====================================
            case 6:
                std::cout << "Exiting program.\n";
                return 0;
                break;
                //====================================
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }
    return 0;
}
//====================================
//====================================
//====================================
//checks if the stack is empty
bool isEmpty() {
    if (top==-1)return true;
    return false;
}
//====================================
//adds new content to the very top
void push() {
    if (top==i-1) {
        std::cout << "Stack Overflow! Cannot push more elements.\n";
        return;
    }
    std::cout << "Enter value to push: ";
    std::cin >> newData;
    stack[++top] = newData;
    std::cout << newData << " pushed into the stack.\n";
}
//====================================
//removes the topmost content
void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}
//====================================
//shows the latest and last in
void Top() {
    if (isEmpty()) {
        std::cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    std::cout << "Top element: " << stack[top] << std::endl;
}
//====================================
// to print all the contents of the stack
//checking if the stack is empty
void prinAll() {
    if (isEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    //literal printing of the stack
    std::cout << "Stack elements (top to bottom):\n";
    for (int j = top; j >= 0; --j) {
        std::cout << "|"<<stack[j] << "|"<<std::endl;
    }
}