#include <iostream>
#include <stack> // call the stack from the STL ILO A

int main() {

    std::stack<int> newStack; // created an object

    // testing the empty() function to check if the stack is empty
    std::cout << "Is the stack empty? " << newStack.empty() << std::endl;

    // insert a 3 elements:
    newStack.push(3);
    std::cout << "Top of stack: " << newStack.top() << std::endl;
    newStack.push(2);
    std::cout << "Top of stack: " << newStack.top() << std::endl;
    newStack.push(1);
    std::cout << "Top of stack: " << newStack.top() << std::endl;

    std::cout << "Is the stack empty? " << newStack.empty() << std::endl;

    // emplace -> construct and insert element -> public member function
    std::cout << "===================EMPLACE===================" << std::endl;
    newStack.emplace(9);
    std::cout << "Top of the stack: " << newStack.top() << std::endl;
    std::cout << "Size of the stack: " << newStack.size() << std::endl;

    newStack.push(6);
    newStack.push(7);
    newStack.push(8);
    std::cout << "Size of the stack is: " << newStack.size() << std::endl;

    // swap? -> swap the content of the public member functions
    std::stack<int> swapStack;
    swapStack.push(10);
    swapStack.push(11);
    swapStack.push(12);
    swapStack.push(13);
    swapStack.push(14);

    newStack.swap(swapStack);

    std::cout << "===================SWAPPED===================" << std::endl;
    std::cout << "newStack swapped top: " << newStack.top() << std::endl;
    std::cout << "swapStack new top: " << swapStack.top() << std::endl;

    return 0;
}