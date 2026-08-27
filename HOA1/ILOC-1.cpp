#include <iostream>

double swch(double &frst,double &scnd);
int main () {
    double frst, scnd;
    std::cout<<"Enter value for the First No.: ";
    std::cin>>frst;
    std::cout<<"Enter value for Second No.: ";
    std::cin>>scnd;
    std::cout<<("BEFORE SWAPPING: THESE ARE THE VALUES OF THE FIRST AND SECOND VARIABLE: ")<<std::endl;
    std::cout<<("FIRST VALUE: ")<<frst<<std::endl;
    std::cout<<("SECOND VALUE: ")<<scnd<<std::endl;

    swch(frst,scnd);
    std::cout<<("FIRST VALUE: ")<<frst<<std::endl;
    std::cout<<("SECOND VALUE: ")<<scnd<<std::endl;

    return 0;
}

double swch(double &frst,double &scnd) {
    std::swap(frst,scnd);
    return frst;
}