#include <iostream>
//Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.

bool lgxop(bool one, bool two);

int main(){ //driver code
    bool one, two;

    std::cout<<"Enter 2 Values to be Calculated: "<<std::endl;
    std::cout<<"Enter First Value: ";
    std::cin >> one;
    std::cout <<std::endl<<"Enter Second Value: ";
    std::cin >> two;

    lgxop(one, two);
    return 0;
}
bool lgxop(bool one, bool two){
    std::cout<<"For AND: "<< (one&&two)<< std::endl;
    std::cout<<"For OR: "<<(one||two)<<std::endl;
    std::cout<<"For NOT of Value 1: "<< (!one)<<std::endl;
    std::cout<<"For NOT of Value 2: "<< (!two)<<std::endl;
    return true;
}