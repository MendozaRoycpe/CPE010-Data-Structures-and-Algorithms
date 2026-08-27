//
// Created by royga on 8/23/2026.
//
#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function

const int max_size = 50;
int main() {
    //generate random values
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }
    //show your datasets content
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }

}