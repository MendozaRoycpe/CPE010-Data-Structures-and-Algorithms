#include <iostream>
// Create a function that will return whether variable A is greater than variable B.

bool great(int first, int second);

int main(){ //driver code

    int first, second;
    bool result;

   std::cout<<"Enter 2 Values to be Compared: "<<std::endl;
   std::cout<<"Enter  Value A: ";
   std::cin >> first;
   std::cout <<std::endl<<"Enter Value B: ";
   std::cin >> second;
   result = first>second;
   if(result == true){
        std::cout<<"The Value A is Greater than B" ;
    } else{
        std::cout<<" Value B is Greater than Value A" ;
    }
    return 0;
}

bool great(int first, int second){
    bool result = first>second;
    return result;
}