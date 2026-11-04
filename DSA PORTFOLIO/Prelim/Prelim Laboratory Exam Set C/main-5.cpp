#include <iostream>
#include <string>
#include "Arr.h"
#include "queueLL.h"

bool isPalindrome(const std::string& number)
{
    Stack stack;
    Queue queue;

    for (char digit : number)
    {
        stack.push(digit);
        queue.enqueue(digit);
    }

    while (!stack.isEmpty())
    {
        char stackValue = stack.pop();
        char queueValue = queue.dequeue();

        if (stackValue != queueValue)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string number;
    std::cout << "Palindrome Number Checker:\n";
    std::cout << "Enter a integer: ";
    std::cin >> number;

    if (isPalindrome(number))
    {
        std::cout << number << " is a palindrome number.\n";
    }
    else
    {
        std::cout << number << " is not a palindrome number.\n";
    }

    return 0;
}
