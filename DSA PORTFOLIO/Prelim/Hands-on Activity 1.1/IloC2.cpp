#include <iostream>

double KelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main() {
    double kelvin;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "Temperature in Fahrenheit = "
              << KelvinToFahrenheit(kelvin) << std::endl;

    return 0;
}
// ANALYSIS: This program asks the user to enter a temperature in Kelvin
// and converts it to Fahrenheit using a function. It then displays the 
// converted temperature on the screen.

