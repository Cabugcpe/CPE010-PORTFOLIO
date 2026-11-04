
#include <iostream>
#include <algorithm>

int memo[1001];

int getMinSteps(int n)
{
    // Base case90
    if (n == 1)
        return 0;

    // Return the saved result
    if (memo[n] != -1)
        return memo[n];

    // Subtract 1
    int r = 1 + getMinSteps(n - 1);

    // Divide by 2 if divisible
    if (n % 2 == 0)
        r = std::min(r, 1 + getMinSteps(n / 2));

    // Divide by 3 if divisible
    if (n % 3 == 0)
        r = std::min(r, 1 + getMinSteps(n / 3));

    // Save the result
    memo[n] = r;

    return r;
}

int main()
{
    int n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1 || n > 1000)
    {
        std::cout << "Please enter a number from 1 to 1000.\n";
        return 0;
    }

    std::fill(memo, memo + 1001, -1);

    std::cout << "Minimum steps: "
              << getMinSteps(n) << '\n';

    return 0;
}