#include <iostream>
#include <cmath>

double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

    std::cout << "Distance = "
              << calculateDistance(x1, y1, x2, y2) << std::endl;

    return 0;
}
// ANALYSIS: This program asks the user to enter the coordinates of two points 
// and uses the calculateDistance() function to find the distance between them.
// It then displays the calculated distance on the screen.

