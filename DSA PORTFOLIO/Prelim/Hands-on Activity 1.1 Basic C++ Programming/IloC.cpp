#include <iostream>
#include <cmath>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C,
             double sA, double sB, double sC);

    void setAngles(double A, double B, double C);
    bool validateTriangle();

    double computePerimeter();
    double computeArea();
    void triangleType();
};

int main() {

    Triangle t1(40, 30, 110, 5, 6, 7);

    if (t1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";

        std::cout << "Perimeter: " << t1.computePerimeter() << std::endl;
        std::cout << "Area: " << t1.computeArea() << std::endl;

        std::cout << "Triangle Type: ";
        t1.triangleType();
    }
    else {
        std::cout << "The shape is not a valid triangle.\n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C,
                   double sA, double sB, double sC) {

    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

// B. Compute the perimeter of a triangle
double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}

// A. Compute the Area of the Triangle
double Triangle::computeArea() {
    double s = computePerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

// C. Determine Triangle if Acute, Obtuse or Other
void Triangle::triangleType() {

    if (angleA < 90 && angleB < 90 && angleC < 90)
        std::cout << "Acute Triangle";
    else if (angleA > 90 || angleB > 90 || angleC > 90)
        std::cout << "Obtuse Triangle";
    else
        std::cout << "Others (Right Triangle)";
}
