#include <iostream>
#include <cmath>

double dstc(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2;

    std::cout<<"Enter the Coordinates of the First Point(x1,y1): ";
    std::cout<<std::endl<<"x1: ";
    std::cin>>x1;
    std::cout<<"y1: ";
    std::cin>>y1;
    std::cout<<"Enter the Coordinates of the Second Point(x1,y1): ";
    std::cout<<std::endl<<"x2: ";
    std::cin>>x2;
    std::cout<<"y2: ";
    std::cin>>y2;
    std::cout<<std::endl<<"The Distance between two Points is: " << dstc(x1,y1,x2,y2);

    return 0;
}

double dstc(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}