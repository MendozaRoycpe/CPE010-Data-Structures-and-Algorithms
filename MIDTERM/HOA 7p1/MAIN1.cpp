//
// Created by royga on 9/8/2026.
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "ALGO.h"

//generate 100 rand elmts
//create a fx that will display random gen elmts
const int max_size = 100;
void showArr(int arr[], int size);

int main () {
    int elmt[max_size];

    //generate random values
    srand(time(0));

    for (int i=0; i<max_size; i++) {
        elmt[i] = rand()%100;
    }
    showArr(elmt, max_size);
    std::cout<<"==============BUBBLE SORT==============="<<std::endl;
    bubbleSort(elmt, max_size);
    showArr(elmt, max_size);
    return 0;
}

void showArr(int arr[], int size) {
    for (int i=0; i<size; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}