#include <iostream>

void swapNumbers(int a, int b) {
    int temp;

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nAfter Swapping:\n";
    std::cout << "First Number = " << a << std::endl;
    std::cout << "Second Number = " << b << std::endl;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    swapNumbers(num1, num2);

    return 0;
}
// ANALYSIS: This program asks the user to enter two numbers and swaps them
//The swapped values are only shown inside the function
// because the original numbers in main() do not change.
