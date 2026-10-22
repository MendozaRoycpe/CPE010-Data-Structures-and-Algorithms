#include <iostream>
#include <cmath>

//Modify the code given in ILO B and add the following functions:
//a. A function to compute for the area of a triangle
//b. A function to compute for the perimeter of a triangle
//c. A function that determines whether the triangle is acute-angled, obtuse-angled or ‘others.’

class triangle {
    private:
    double sideA, sideB, sideC;
    double totANG,angA, angB, angC;

    public:
    triangle(double A, double B, double C, double sA, double sB, double sC);
    bool validateTriangle();
    double area();
    double pmtr();
    void trityp();
};

int main() {
    double angA, angB, angC;
    double sideA, sideB, sideC;
    int choys;

    std::cout<<"Enter Angle A: "<<std::endl;
    std::cin>>angA;
    std::cout<<"Enter Angle B: "<<std::endl;
    std::cin>>angB;
    std::cout<<"Enter Angle C: "<<std::endl;
    std::cin>>angC;
    std::cout<<"Enter Side A: "<<std::endl;
    std::cin>>sideA;
    std::cout<<"Enter Side B: "<<std::endl;
    std::cin>>sideB;
    std::cout<<"Enter Side C: "<<std::endl;
    std::cin>>sideC;

    triangle tri(angA, angB, angC, sideA, sideB, sideC);

    if (tri.validateTriangle()==false) {
        std::cout<<"This is not a Valid Triangle"<<std::endl;
        return 0;
    }

    std::cout<<"=====Menu Selection=====: "<<std::endl;
    std::cout << "\n1. Compute Area";
    std::cout << "\n2. Compute Perimeter";
    std::cout << "\n3. Determine Triangle Type";
    std::cout << "\nEnter Choice: ";
    std::cin >> choys;

    switch (choys) {
        case 1:
            std::cout<<"Area of Triangle: "<<tri.area()<<std::endl;
            break;
        case 2:
            std::cout<<"Perimeter of Triangle: "<<tri.pmtr()<<std::endl;
            break;
        case 3:
            tri.trityp();
            break;
        default:
            std::cout<<"Invalid Choice"<<std::endl;
    }
    return 0;
}
triangle::triangle(double A, double B, double C,
                   double sA, double sB, double sC) {
    angA = A;
    angB = B;
    angC = C;

    sideA = sA;
    sideB = sB;
    sideC = sC;

    totANG = angA + angB + angC;
}

// Validate Triangle
bool triangle::validateTriangle() {
    return (totANG == 180);
}

// Compute Area (Heron's Formula)
double triangle::area() {
    double s = (sideA + sideB + sideC) / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}
// Compute Perimeter
double triangle::pmtr() {
    return sideA + sideB + sideC;
}
// Determine Triangle Type
void triangle::trityp() {
    if (angA < 90 && angB < 90 && angC < 90) {
        std::cout << "The triangle is Acute-Angled." << std::endl;
    }
    else if (angA > 90 || angB > 90 || angC > 90) {
        std::cout << "The triangle is Obtuse-Angled." << std::endl;
    }
    else {
        std::cout << "The triangle is Others." << std::endl;
    }
}