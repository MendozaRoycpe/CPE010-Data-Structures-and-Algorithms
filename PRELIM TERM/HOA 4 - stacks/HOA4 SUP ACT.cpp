// HOA 4 Supplementary activity
// Created by royga on 7/30/2026.
//
#include <iostream>
#include <string>
#include <stack>
#include "HOA4sup.h"

//prototyping
int matching(char open, char close);
int balancing(std::string expression);
int llbalance(std::string expression);

int main() {

    int choice;
    std::string expression;

    std::cout << "EXPRESSION CHECKER\n";
    std::cout << "====================\n";

    std::cout << "Enter expression: ";
    std::getline(std::cin, expression);

    do {
        std::cout << "\nSelect Function:\n";
        std::cout << "[1] Array Stack\n";
        std::cout << "[2] Linked List Stack\n";
        std::cout << "[3] Terminate Program\n";
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch(choice) {

            case 1:
                std::cout << "\n===== ARRAY STACK =====\n";
                if (balancing(expression))
                    std::cout << "\n|| The Expression is Balanced ||\n";
                else
                    std::cout << "\n|| The Expression is Not Balanced ||\n";
                break;

            case 2:
                std::cout << "\n===== LINKED LIST STACK =====\n";
                if (llbalance(expression))
                    std::cout << "\n|| The Expression is Balanced ||\n";
                else
                    std::cout << "\n|| The Expression is Not Balanced ||\n";
                break;

            case 3:
                std::cout << "\n|| PROGRAM TERMINATION ||\n";
                break;

            default:
                std::cout << "\nInvalid Choice\n";
        }

    } while(choice != 3);

    return 0;
}

int matching(char open, char close) {

    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}
int balancing(std::string expression) {

    clear();

    for (int i = 0; i < expression.length(); i++) {

        char current = expression[i];

        // Pushing opening symbols.
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        }
        // Process for closing symbols.
        else if (current == ')' || current == ']' || current == '}') {

            if (isEmpty()) {
                return 0;
            }
            char open = pop();
            if (!matching(open, current)) {
                return 0;
            }
        }
    }

    if (isEmpty()) {
        return 1;
    }
    return 0;
}

int llbalance(std::string expression) {

    clearll<char>();

    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        // Push opening symbols.
        if (current == '(' || current == '{' || current == '[') {
            pushll<char>(current);
        }
        // Process closing symbols.
        else if (current == ')' || current == ']' || current == '}') {
            if (isEmptyll<char>()) {
                return 0;
            }
            char open = popll<char>();
            if (!matching(open, current)) {
                return 0;
            }
        }
    }
    if (isEmptyll<char>()) {
        return 1;
    }
    return 0;
}