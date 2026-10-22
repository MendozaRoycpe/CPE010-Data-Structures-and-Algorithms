#include <iostream>

double kTOf(double kelvin);

int main() {
    double kelvin;

    std::cout<<"Enter the Temperature in Kelvin: ";
    std::cin>>kelvin;

    std::cout<<" The Temperature of "<<kelvin<<"k in Fahrenheit is: "<<kTOf(kelvin)<<std::endl;
    return 0;
}

double kTOf(double kelvin) {
    return ((kelvin-273.15)*1.8)+32;
}