#include <iostream>
//Create a function that will take two numbers and display the sum.

double sumTOTnum(double first, double second);

int main(){ //driver code

    double first, second;

    std::cout<<"Enter 2 Values to be Calculated: "<<std::endl;
    std::cout<<"Enter First Value: ";
    std::cin >> first;
    std::cout <<std::endl<<"Enter Second Value: ";
    std::cin >> second;
    std::cout <<std::endl<<"The Calculate Total is: " <<sumTOTnum(first, second)<<std::endl;

    return 0;
}
double sumTOTnum(double first,double second){
    double tot = first+second;

    return tot;
}